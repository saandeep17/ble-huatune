/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== Task.c ========
 */

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Startup.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Assert.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/knl/Idle.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Intrinsics.h>

#include "package/internal/Task.xdc.h"

#ifdef __ti__
/* disable unused local variable warning during optimized compile */
#pragma diag_suppress=179
#endif

/*
 *  ======== Task_schedule ========
 *  Find highest priority task and invoke it.
 *
 *  Must be called with interrupts disabled.
 */
Void Task_schedule()
{
    Queue_Handle maxQ;
    Task_Object *prevTask;
    Task_Object *curTask;
#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    Int i;
#endif

    do {
        Task_module->workFlag = 0;

        /* stall until a task is ready */
        while (Task_module->curSet == 0) {
            Task_allBlockedFunction();
        }

        /* Determine current max ready Task priority */
        maxQ = (Queue_Handle)((UInt8 *)(Task_module->readyQ) +
                (UInt)(Intrinsics_maxbit(Task_module->curSet)*(2*sizeof(Ptr))));

        /* if a higher priority task is ready - switch to it */
        if (maxQ > Task_module->curQ) {
            prevTask = Task_module->curTask;
            Task_module->curQ = maxQ;
            Task_module->curTask = Queue_head(maxQ);
            curTask = Task_module->curTask;

            if (Task_checkStackFlag) {
                Task_checkStacks(prevTask, curTask);
            }
	
#if !defined(ti_sysbios_knl_Task_DISABLE_ALL_HOOKS) \
    || (xdc_runtime_Log_DISABLE_ALL == 0)
            /* It's safe to enable intrs here */
            Hwi_enable();

#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
            for (i = 0; i < Task_hooks.length; i++) {
                if (Task_hooks.elem[i].switchFxn != NULL) {
                    Task_hooks.elem[i].switchFxn(prevTask, curTask);
                }
            }
#endif

            Log_write4(Task_LM_switch, (UArg)prevTask, (UArg)prevTask->fxn,
                       (UArg)curTask, (UArg)curTask->fxn);

            /* Hard-disable intrs - this fxn is called with them disabled */
            Hwi_disable();
#endif
            Task_SupportProxy_swap((Ptr)&prevTask->context,
                            (Ptr)&curTask->context);
        }
    } while (Task_module->workFlag);
}

/*
 *  ======== Task_enter ========
 *  Here on task's first invocation.
 *
 *  Unlock the Task Scheduler to enter task as though we
 *  returned through Task_restore()
 */
Void Task_enter()
{
    if (Task_module->workFlag) {
        Task_schedule();
    }
    Task_module->locked = FALSE;
    Hwi_enable();
}

/*
 *************************************************************************
 *                      Module wide functions
 *************************************************************************
 */

/*
 *  ======== Task_Module_startup ========
 *  Initialize and start the Task Module.
 *  Called at system init time before main().
 */
Int Task_Module_startup (Int phase)
{
    /*
     * Need to wait for SupportProxy. Other modules safe.
     */
    if (BIOS_taskEnabled) {  /* minimize code foot print if Task is disabled */
        Int i;
        UInt j;

        /* The TaskSupport delegate cannnot depend on Task during Startup */
        /*
         * Startup_rtsDone() is called because we do Error_check() in
         * instanceStartup
         */
        if (Task_SupportProxy_Module_startupDone() ) {

#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
            for (i = 0; i < Task_hooks.length; i++) {
                if (Task_hooks.elem[i].registerFxn != NULL) {
                    Task_hooks.elem[i].registerFxn(i);
                }
            }
#endif

            /* do post init on all statically Created tasks */
            for (i = 0; i < Task_Object_count(); i++) {
                Task_postInit(Task_Object_get(NULL, i), NULL);
            }

            /* do post init on all statically Constructed tasks */
            for (j = 0; j < Task_numConstructedTasks; j++) {
                Task_postInit(Task_module->constructedTasks[j], NULL);
            }

            return (Startup_DONE);
        }
        else {
            return (Startup_NOTDONE);
        }
    }
    else {
        return (Startup_DONE);
    }
}

/*
 *  ======== Task_startup ========
 */
Void Task_startup()
{
    Task_startCore(0);
}

/*
 *  ======== Task_startCore ========
 */
Void Task_startCore(UInt coreId)
{
    Queue_Handle maxQ;
    Task_Object *prevTask;
    Task_Struct dummyTask;
#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    Int i;
#endif

    Hwi_disable();      /* re-enabled in Task_enter of first task */

    /* Use dummyTask as initial task to swap from */
    prevTask = Task_handle(&dummyTask);

    /* stall until a task is ready */
    while (Task_module->curSet == 0) {
        Task_allBlockedFunction();
    }

    /* Determine current max ready Task priority */
    maxQ = (Queue_Handle)((UInt8 *)(Task_module->readyQ) +
                (UInt)(Intrinsics_maxbit(Task_module->curSet)*(2*sizeof(Ptr))));

    Task_module->curQ = maxQ;
    Task_module->curTask = Queue_head(maxQ);

    /* we've done the scheduler's work */
    Task_module->workFlag = 0;

    /* Signal that we are entering task thread mode */
    BIOS_setThreadType(BIOS_ThreadType_Task);

    if (Task_checkStackFlag) {
        Task_checkStacks(NULL, Task_module->curTask);
    }

    /* should be safe to enable intrs here */
    Hwi_enable();

#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    /* Run switch hooks for first real Task */
    for (i = 0; i < Task_hooks.length; i++) {
        if (Task_hooks.elem[i].switchFxn != NULL) {
            Task_hooks.elem[i].switchFxn(NULL, Task_module->curTask);
        }
    }
#endif

    Log_write4(Task_LM_switch, (UArg)0, (UArg)0,
               (UArg)Task_module->curTask,
               (UArg)Task_module->curTask->fxn);

    /* must leave this function with ints disabled */
    Hwi_disable();

    /* inform dispatcher that we're running on task stack */
    Hwi_switchFromBootStack();

    /* start first task by way of enter() */
    Task_SupportProxy_swap((Ptr)&prevTask->context,
                (Ptr)&Task_module->curTask->context);
}

/*
 *  ======== Task_unlockSched ========
 */
Void Task_unlockSched()
{
    Task_module->locked = FALSE;
}

/*
 *  ======== Task_enabled ========
 */
Bool Task_enabled()
{
    if (BIOS_swiEnabled == FALSE) {
        return (Task_module->locked == FALSE);
    }
    else {
        return ((Task_module->locked == FALSE) && Swi_enabled());
    }
}

/*
 *  ======== Task_disable ========
 */
UInt Task_disable()
{
    UInt key = Task_module->locked;

    Task_module->locked = TRUE;
    return (key);
}

/*
 *  ======== Task_enable ========
 */
Void Task_enable()
{
    Task_restore(0);
}

/*
 *  ======== Task_restore ========
 */
Void Task_restore(UInt tskKey)
{
    if (tskKey == FALSE) {
        Hwi_disable();
        if (Task_module->workFlag
            && (!BIOS_swiEnabled || (BIOS_swiEnabled && Swi_enabled()))) {
            Task_schedule();
        }
        Task_module->locked = FALSE;
        Hwi_enable();
    }
}

/*
 *  ======== Task_restoreHwi ========
 *  Task_restore for Hwi dispatcher.
 *
 *  Called with interrupts disabled from dispatcher.
 *
 *  Returns with interrupts still disabled.
 *
 *  @param(key) key to restore previous Task scheduler state
 */
Void Task_restoreHwi(UInt tskKey)
{
    if (tskKey == FALSE) {
        if (Task_module->workFlag
            && (!BIOS_swiEnabled || (BIOS_swiEnabled && Swi_enabled()))) {
            Task_schedule();
        }
        Task_module->locked = FALSE;
    }
}

/*
 *  ======== Task_self ========
 */
Task_Handle Task_self()
{
    return (Task_module->curTask);
}

/*
 *  ======== Task_checkStacks ========
 */
Void Task_checkStacks(Task_Handle oldTask, Task_Handle newTask)
{
    UInt oldTaskStack; /* used to obtain current (oldTask) stack address */

    /*
     * oldTask is NULL for the very first stack switch, skip it
     */
    if (oldTask == NULL) {
        return;
    }

    /* check top of stacks for 0xbe */
    if (!Task_SupportProxy_checkStack(oldTask->stack, oldTask->stackSize)) {
        Error_raise(NULL, Task_E_stackOverflow, oldTask, 0);
    }

    if (!Task_SupportProxy_checkStack(newTask->stack, newTask->stackSize)) {
        Error_raise(NULL, Task_E_stackOverflow, newTask, 0);
    }

    /* check sp's for being in bounds */
    if (((UArg)&oldTaskStack < (UArg)oldTask->stack) ||
        ((UArg)&oldTaskStack > (UArg)(oldTask->stack+oldTask->stackSize))) {
        Error_raise(NULL, Task_E_spOutOfBounds, oldTask, oldTask->context);
    }

    if ((newTask->context < (Ptr)newTask->stack) ||
        (newTask->context > (Ptr)(newTask->stack+newTask->stackSize))) {
        Error_raise(NULL, Task_E_spOutOfBounds, newTask, newTask->context);
    }
}

/*
 *  ======== Task_processVitalTasks ========
 *  Call BIOS_exit() when last vitalTask exits or is
 *  deleted.
 */
Void Task_processVitalTaskFlag(Task_Object *tsk)
{
    UInt hwiKey;
    if (tsk->vitalTaskFlag == TRUE) {
        hwiKey = Hwi_disable();
        if (--Task_module->vitalTasks == 0) {
            Hwi_restore(hwiKey);
            BIOS_exit(0);
        }
        Hwi_restore(hwiKey);
    }
}

/*
 *  ======== Task_exit ========
 */
Void Task_exit()
{
    UInt tskKey, hwiKey;
    Task_Object *tsk;
#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    Int i;
#endif

    tsk = Task_self();

#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    /*
     * Process Task_exit hooks.  Should be called outside the Task kernel.
     */
    for (i = 0; i < Task_hooks.length; i++) {
        if (Task_hooks.elem[i].exitFxn != NULL) {
            Task_hooks.elem[i].exitFxn(tsk);
        }
    }
#endif

    Log_write2(Task_LD_exit, (UArg)tsk, (UArg)tsk->fxn);

    tskKey = Task_disable();
    hwiKey = Hwi_disable();

    Task_blockI(tsk);

    tsk->mode = Task_Mode_TERMINATED;

    Task_processVitalTaskFlag(tsk);

    Hwi_restore(hwiKey);

    Queue_elemClear((Queue_Elem *)tsk);

    /* add to terminated task list if it was dynamically created */
    if (Task_deleteTerminatedTasks == TRUE) {
        Task_Handle dynTask;

        dynTask = Task_Object_first();

        while (dynTask) {
            if (tsk == dynTask) {
                tsk->readyQ = Task_Module_State_terminatedQ();
                Queue_put(tsk->readyQ, (Queue_Elem *)tsk);
                break;
            }
            else {
                dynTask = Task_Object_next(dynTask);
            }
        }
    }

    Task_restore(tskKey);
}

/*
 *  ======== Task_sleepTimeout ========
 *  called by Clock when timeout for a Task_sleep() expires
 */
Void Task_sleepTimeout(UArg arg)
{
    UInt hwiKey;
    Task_PendElem *elem = (Task_PendElem *)xdc_uargToPtr(arg);

    hwiKey = Hwi_disable();

    /*
     * put tsk back into readyQ
     * No need for Task_disable/restore sandwich since this
     * is called within Swi (or Hwi) thread
     */
    Task_unblockI(elem->task, hwiKey);

    Hwi_restore(hwiKey);
}

/*
 *  ======== Task_sleep ========
 */
Void Task_sleep(UInt32 timeout)
{
    Task_PendElem elem;
    UInt hwiKey, tskKey;
    Clock_Struct clockStruct;

    if (timeout == BIOS_NO_WAIT) {
        return;
    }

    Assert_isTrue((timeout != BIOS_WAIT_FOREVER),
                    Task_A_badTimeout);

    /*
     * BIOS_clockEnabled check is here to eliminate Clock module 
     * references in the custom library
     */
    if (BIOS_clockEnabled) {
        /* add Clock event */
        Clock_addI(Clock_handle(&clockStruct), (Clock_FuncPtr)Task_sleepTimeout, timeout, (UArg)&elem);
        elem.clock = Clock_handle(&clockStruct);
    }

    hwiKey = Hwi_disable();

    /*
     * Verify that THIS core hasn't already disabled the scheduler
     * so that the Task_restore() call below will indeed block
     */
    Assert_isTrue((Task_enabled()),
                    Task_A_sleepTaskDisabled);

    /* lock scheduler */
    tskKey = Task_disable();

    /* get task handle and block tsk */
    elem.task = Task_self();

    Task_blockI(elem.task);

    /*
     * BIOS_clockEnabled check is here to eliminate Clock module 
     * references in the custom library
     */
    if (BIOS_clockEnabled) {
        Clock_startI(elem.clock);
    }

    /* Only needed for Task_delete() */
    Queue_elemClear(&elem.qElem);

    elem.task->pendElem = (Ptr)(&elem);

    Hwi_restore(hwiKey);

    Log_write3(Task_LM_sleep, (UArg)elem.task, (UArg)elem.task->fxn,
               (UArg)timeout);

    /* unlock task scheduler and block */
    Task_restore(tskKey);       /* the calling task will block here */

    /*
     * BIOS_clockEnabled check is here to eliminate Clock module 
     * references in the custom library
     */
    if (BIOS_clockEnabled) {
        hwiKey = Hwi_disable();
        /* remove Clock object from Clock Q */
        Clock_removeI(elem.clock);
        elem.clock = NULL;
        Hwi_restore(hwiKey);
    }

    elem.task->pendElem = NULL;
}


/*
 *  ======== Task_yield ========
 */
Void Task_yield()
{
    UInt tskKey, hwiKey;

    tskKey = Task_disable();
    hwiKey = Hwi_disable();

    if (Task_module->curQ) {
        /* move current task to end of curQ */
        Queue_enqueue(Task_module->curQ,
            Queue_dequeue(Task_module->curQ));
    }
    Task_module->curQ = NULL;  /* force a Task_switch() */
    Task_module->workFlag = 1;

    Hwi_restore(hwiKey);

    Log_write3(Task_LM_yield, (UArg)Task_module->curTask, (UArg)(Task_module->curTask->fxn), (UArg)(BIOS_getThreadType()));

    Task_restore(tskKey);
}


/*
 *  ======== Task_getIdleTask ========
 */
Task_Handle Task_getIdleTask()
{
    return(Task_module->idleTask[0]);
}

/*
 *  ======== Task_getIdleTaskHandle ========
 */
Task_Handle Task_getIdleTaskHandle(UInt coreId)
{
    Assert_isTrue((coreId == 0), Task_A_invalidCoreId);

    return(Task_module->idleTask[coreId]);
}

/*
 *************************************************************************
 *                       Instance functions
 *************************************************************************
 */


/*
 *  ======== Task_Instance_init ========
 */
Int Task_Instance_init(Task_Object *tsk, Task_FuncPtr fxn,
                const Task_Params *params, Error_Block *eb)
{
    Int align;
    Int status;
    SizeT stackSize;

    Assert_isTrue((BIOS_taskEnabled == TRUE), Task_A_taskDisabled);

    Assert_isTrue(((BIOS_getThreadType() != BIOS_ThreadType_Hwi) &&
                   (BIOS_getThreadType() != BIOS_ThreadType_Swi)), Task_A_badThreadType);

    Assert_isTrue((((params->priority == -1) || (params->priority > 0)) &&
                   (params->priority < (Int)Task_numPriorities)),
                   Task_A_badPriority);

    tsk->priority = params->priority;

    /* deal with undefined Task_Params defaults */
    if (params->stackHeap == NULL) {
        tsk->stackHeap = Task_defaultStackHeap;
    }
    else {
        tsk->stackHeap = params->stackHeap;
    }

    if (params->stackSize == 0) {
        stackSize = Task_defaultStackSize;
    }
    else {
        stackSize = params->stackSize;
    }

    align = Task_SupportProxy_getStackAlignment();

    if (params->stack != NULL) {
        if (align != 0) {
            UArg stackTemp;
            /* align low address to stackAlignment */
            stackTemp = (UArg)params->stack;
            stackTemp += align - 1;
            stackTemp &= -align;
            tsk->stack = (Ptr)xdc_uargToPtr(stackTemp);

            /* subtract what we removed from the low address from stackSize */
            tsk->stackSize = stackSize - (stackTemp - (UArg)params->stack);

            /* lower the high address as necessary */
            tsk->stackSize &= -align;
        }
        else {
            tsk->stack = params->stack;
            tsk->stackSize = stackSize;
        }
        /* tell Task_delete that stack was provided */
        tsk->stackHeap = (xdc_runtime_IHeap_Handle)(-1);
    }
    else {
        if (BIOS_runtimeCreatesEnabled) {
            if (align != 0) {
                /*
                 * round stackSize up to the nearest multiple of the alignment.
                 */
                tsk->stackSize = (stackSize + align - 1) & -align;
            }
            else {
                tsk->stackSize = stackSize;
            }

            tsk->stack = Memory_alloc(tsk->stackHeap, tsk->stackSize,
                                      align, eb);

            if (tsk->stack == NULL) {
                return (1);
            }
        }
    }

    tsk->fxn = fxn;
    tsk->arg0 = params->arg0;
    tsk->arg1 = params->arg1;

    tsk->env = params->env;

    tsk->vitalTaskFlag = params->vitalTaskFlag;
    if (tsk->vitalTaskFlag == TRUE) {
        Task_module->vitalTasks += 1;
    }

#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    if (Task_hooks.length > 0) {
        tsk->hookEnv = Memory_calloc(Task_Object_heap(),
                Task_hooks.length * sizeof (Ptr), 0, eb);

        if (tsk->hookEnv == NULL) {
            return (2);
        }
    }
#endif

    status = Task_postInit(tsk, eb);

    if (Error_check(eb)) {
        return (3 + status);
    }

    return (0);   /* no failure states */
}

/*
 *  ======== Task_postInit ========
 *  Function to be called during module startup to complete the
 *  initialization of any statically created or constructed task.
 *  Initialize stack.
 *  Build Initial stack image.
 *  Add task to corresponding ready Queue.
 *
 *  returns (0) and clean 'eb' on success
 *  returns (0) and 'eb' if Task_SupportProxy_start() fails.
 *  returns (n) and 'eb' for number of successful createFxn() calls iff
 *     one of the createFxn() calls fails
 */
Int Task_postInit(Task_Object *tsk, Error_Block *eb)
{
    UInt tskKey, hwiKey;
    Queue_Handle readyQ;
#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    Int i;
#endif

    tsk->context = Task_SupportProxy_start(tsk,
                (Task_SupportProxy_FuncPtr)Task_enter,
                (Task_SupportProxy_FuncPtr)Task_exit,
                eb);

    if (Error_check(eb)) {
        return (0);
    }

    tsk->mode = Task_Mode_READY;

    tsk->pendElem = NULL;

#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    for (i = 0; i < Task_hooks.length; i++) {
        tsk->hookEnv[i] = (Ptr)0;
        if (Task_hooks.elem[i].createFxn != NULL) {
            Task_hooks.elem[i].createFxn(tsk, eb);

            if (Error_check(eb)) {
                return (i);
            }
        }
    }
#endif

    if (tsk->priority < 0) {
        tsk->mask = 0;
        tsk->readyQ = Task_Module_State_inactiveQ();
        Queue_put(tsk->readyQ, (Queue_Elem *)tsk);
    }
    else {
        tsk->mask = 1 << tsk->priority;
        readyQ = Queue_Object_get(Task_module->readyQ, tsk->priority);
        tsk->readyQ = readyQ;

        tskKey = Task_disable();
        hwiKey = Hwi_disable();
        Task_unblock(tsk);
        Hwi_restore(hwiKey);
        Task_restore(tskKey);
    }

    return (0);
}

/*
 *  ======== Task_Instance_finalize ========
 */
Void Task_Instance_finalize(Task_Object *tsk, Int status)
{
#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    Int i, cnt;
#endif
    UInt taskKey, hwiKey;

    /*
     * Task's can only be deleted from main and task threads.
     * Running Tasks can not be deleted.
     */
    if (status == 0) {
        taskKey = Task_disable();

        /*
         * Bar users from calling Task_delete() on terminated tasks
         * if deleteTerminatedTasks is enabled.
         */
        if ((Task_deleteTerminatedTasks == TRUE)
             && (Task_getMode(tsk) == Task_Mode_TERMINATED)
             && (tsk->readyQ == Task_Module_State_terminatedQ())) {
            Error_raise(NULL, Task_E_deleteNotAllowed, tsk, 0);
        }

        Assert_isTrue((Task_getMode(tsk) != Task_Mode_RUNNING),
                        Task_A_badTaskState);

        Assert_isTrue((BIOS_getThreadType() == BIOS_ThreadType_Main) ||
                      (BIOS_getThreadType() == BIOS_ThreadType_Task),
                        Task_A_badThreadType);

        hwiKey = Hwi_disable();

        if (tsk->mode == Task_Mode_READY) {
            /* remove task from its ready list */
            Queue_remove((Queue_Elem *)tsk);
            /* if last task in readyQ, remove corresponding bit in curSet */
            if (Queue_empty(tsk->readyQ)) {
                Task_module->curSet &= ~tsk->mask;
            }
            
            /* 
             * if task was made ready by a pend timeout but hasn't run yet
             * then its clock object is still on the Clock service Q.
             */
            if (tsk->pendElem != NULL) {
                if (BIOS_clockEnabled && tsk->pendElem->clock) {
                    Clock_removeI(tsk->pendElem->clock);
                }
            }
        }

        if (tsk->mode == Task_Mode_BLOCKED) {
            Assert_isTrue(tsk->pendElem != NULL, Task_A_noPendElem);

            /* Seemingly redundant test in case Asserts are disabled */
            if (tsk->pendElem != NULL) {
                Queue_remove(&(tsk->pendElem->qElem));
                if (BIOS_clockEnabled && tsk->pendElem->clock) {
                    Clock_removeI(tsk->pendElem->clock);
                }
            }
        }

        if (tsk->mode == Task_Mode_TERMINATED) {
            /* remove task from terminated task list */
            Queue_remove((Queue_Elem *)tsk);
        }
        else {
            Task_processVitalTaskFlag(tsk);
        }

        Hwi_restore(hwiKey);

        Task_restore(taskKey);
    }

    /* return if failed before allocating stack */
    if (status == 1) {
        return;
    }

    if (BIOS_runtimeCreatesEnabled) {
        /* free stack if it was allocated dynamically */
        if (tsk->stackHeap != (xdc_runtime_IHeap_Handle)(-1)) {
            Memory_free(tsk->stackHeap, tsk->stack, tsk->stackSize);
        }
    }

    /* return if failed to allocate Hook Env */
    if (status == 2) {
        return;
    }

    /* status == 0 or status == 3 - in both cases create hook was called */

#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    /* free any allocated Hook Envs */
    if (Task_hooks.length > 0) {
        if (status == 0) {
            cnt = Task_hooks.length;
        }
        else {
            cnt = status - 3;   /* # successful createFxn() calls */
        }

        /*
         * only call deleteFxn() if createFxn() was successful
         */
        for (i = 0; i < cnt; i++) {
            if (Task_hooks.elem[i].deleteFxn != NULL) {
                Task_hooks.elem[i].deleteFxn(tsk);
            }
        }

        Memory_free(Task_Object_heap(), tsk->hookEnv,
                Task_hooks.length * sizeof (Ptr));
    }
#endif
}

/*
 *  ======== Task_getArg0 ========
 */
UArg Task_getArg0(Task_Object *tsk)
{
    return (tsk->arg0);
}

/*
 *  ======== Task_getArg1 ========
 */
UArg Task_getArg1(Task_Object *tsk)
{
    return (tsk->arg1);
}

/*
 *  ======== Task_getEnv ========
 */
Ptr Task_getEnv(Task_Object *tsk)
{
    return (tsk->env);
}

/*
 *  ======== Task_FuncPtr ========
 */
Task_FuncPtr Task_getFunc(Task_Object *task, UArg *arg0, UArg *arg1)
{
    if (arg0 != NULL) {
        *arg0 = task->arg0;
    }

    if (arg1 != NULL) {
        *arg1 = task->arg1;
    }

    return (task->fxn);
}

/*
 *  ======== Task_getHookContext ========
 */
Ptr Task_getHookContext(Task_Object *tsk, Int id)
{
    return tsk->hookEnv[id];
}

/*
 *  ======== Task_setHookContext ========
 */
Void Task_setHookContext(Task_Object *tsk, Int id, Ptr hookContext)
{
    tsk->hookEnv[id] = hookContext;
}

/*
 *  ======== Task_getPri ========
 */
Int Task_getPri(Task_Object *tsk)
{
   return tsk->priority;
}

/*
 *  ======== Task_setArg0 ========
 */
Void Task_setArg0(Task_Object *tsk, UArg arg)
{
    tsk->arg0 = arg;
}

/*
 *  ======== Task_setArg1 ========
 */
Void Task_setArg1(Task_Object *tsk, UArg arg)
{
    tsk->arg1 = arg;
}

/*
 *  ======== Task_setEnv ========
 */
Void Task_setEnv(Task_Object *tsk, Ptr env)
{
    tsk->env = env;
}

/*
 *  ======== Task_setPri ========
 */
UInt Task_setPri(Task_Object *tsk, Int priority)
{
    Int oldPri;
    UInt newMask, tskKey, hwiKey;
    Queue_Handle newQ;

    Assert_isTrue((((priority == -1) || (priority > 0) ||
                  ((priority == 0 && Task_module->idleTask == NULL))) &&
                   (priority < (Int)Task_numPriorities)),
                   Task_A_badPriority);

    Log_write4(Task_LM_setPri, (UArg)tsk, (UArg)tsk->fxn,
                       (UArg)tsk->priority, (UArg)priority);

    tskKey = Task_disable();
    hwiKey = Hwi_disable();

    oldPri = tsk->priority;

    if (oldPri == priority) {
        Hwi_restore(hwiKey);
        Task_restore(tskKey);
        return (oldPri);
    }

    if (priority < 0) {
        newMask = 0;
        newQ = Task_Module_State_inactiveQ();
    }
    else {
        newMask = 1 << priority;
        newQ = (Queue_Handle)((UInt8 *)(Task_module->readyQ) +
                (UInt)(priority*(2*sizeof(Ptr))));
    }

    if (tsk->mode == Task_Mode_READY) {
        Queue_remove((Queue_Elem *)tsk);

        /* if last task in readyQ, remove corresponding bit in curSet */
        if (Queue_empty(tsk->readyQ)) {
            Task_module->curSet &= ~tsk->mask;
        }

        if (Task_module->curTask == tsk) {
            Task_module->curQ = newQ;   /* force a Task_switch() */
                                        /* if no longer maxQ */
            /* Put current task at front of its new readyQ */
            Queue_insert(((Queue_Elem *)(newQ))->next, (Queue_Elem *)tsk);
        }
        else {
            /* place task at end of its readyQ */
            Queue_enqueue(newQ, (Queue_Elem *)tsk);
        }

        Task_module->curSet |= newMask;
    }

    tsk->priority = priority;
    tsk->mask = newMask;
    tsk->readyQ = newQ;

    if (priority < 0) {
        Task_module->curQ = NULL;   /* force a Task_switch() */
    }

    Task_module->workFlag = 1;

    Hwi_restore(hwiKey);
    Task_restore(tskKey);

    return oldPri;
}

/*
 *  ======== Task_getMode ========
 */
Task_Mode Task_getMode(Task_Object *tsk)
{
    if (tsk->mode == Task_Mode_READY && tsk == Task_self()) {
        return (Task_Mode_RUNNING);
    }
    else if (tsk->priority == -1) {
        return (Task_Mode_INACTIVE);
    }
    else {
        return (tsk->mode);
    }
}

/*
 *  ======== Task_stat ========
 */
Void Task_stat(Task_Object *tsk, Task_Stat *statbuf)
{
    statbuf->priority = tsk->priority;
    statbuf->stack = tsk->stack;
    statbuf->stackSize = tsk->stackSize;
    statbuf->stackHeap = tsk->stackHeap;
    statbuf->env = tsk->env;
    statbuf->mode = Task_getMode(tsk);
    statbuf->sp = tsk->context;

    statbuf->used = Task_SupportProxy_stackUsed((Char *)tsk->stack,
        tsk->stackSize);
}

/*
 *  ======== Task_block ========
 */
Void Task_block(Task_Object *tsk)
{
    UInt hwiKey;

    hwiKey = Hwi_disable();

    Task_blockI(tsk);

    Hwi_restore(hwiKey);
}

/*
 *  ======== Task_blockI ========
 *  Block a task.
 *
 *  Remove a task from its ready list.
 *  Must be called within Task_disable/Task_restore block
 *  and with interrupts disabled
 */
Void Task_blockI(Task_Object *tsk)
{
    Queue_Object *readyQ = tsk->readyQ;
    UInt curset = Task_module->curSet;
    UInt mask = tsk->mask;

    Log_write2(Task_LD_block, (UArg)tsk, (UArg)tsk->fxn);

    Queue_remove((Queue_Elem *)tsk);

    /* if last task in readyQ, remove corresponding bit in curSet */
    if (Queue_empty(readyQ)) {
        Task_module->curSet = curset & ~mask;
    }
    if (Task_module->curTask == tsk) {
        Task_module->curQ = NULL;  /* force a Task_switch() */
    }
    tsk->mode = Task_Mode_BLOCKED;

    Task_module->workFlag = 1;
}

/*
 *  ======== Task_unblock ========
 */
Void Task_unblock(Task_Object *tsk)
{
    UInt hwiKey;

    hwiKey = Hwi_disable();

    Task_unblockI(tsk, hwiKey);

    Hwi_restore(hwiKey);
}

/*
 *  ======== Task_unblockI ========
 *  Unblock a task.
 *
 *  Place task in its ready list.
 *  Must be called within Task_disable/Task_restore block
 *  and with interrupts disabled
 */
Void Task_unblockI(Task_Object *tsk, UInt hwiKey)
{
#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    Int i;
#endif
    UInt curset = Task_module->curSet;
    UInt mask = tsk->mask;

    Queue_enqueue(tsk->readyQ, (Queue_Elem *)tsk);

    Task_module->curSet = curset | mask;
    tsk->mode = Task_Mode_READY;
    Task_module->workFlag = 1;

    /* It's safe to enable intrs here */
    Hwi_restore(hwiKey);

#ifndef ti_sysbios_knl_Task_DISABLE_ALL_HOOKS
    for (i = 0; i < Task_hooks.length; i++) {
        if (Task_hooks.elem[i].readyFxn != NULL) {
            Task_hooks.elem[i].readyFxn(tsk);
        }
    }
#endif

    Log_write3(Task_LD_ready, (UArg)tsk, (UArg)tsk->fxn, (UArg)tsk->priority);

    /* Hard-disable intrs - this fxn is called with them disabled */
    Hwi_disable();
}

/*
 *  ======== Task_allBlockedFunction ========
 */
Void Task_allBlockedFunction()
{
    volatile UInt delay;

    if (Task_allBlockedFunc == Idle_run) {
        Hwi_enable();
        Idle_run();
        Hwi_disable();
    }
    else if (Task_allBlockedFunc == NULL) {
        Hwi_enable();
        /* Guarantee that interrupts are enabled briefly */
        for (delay = 0; delay < 1; delay++) {
           ;
        }
        Hwi_disable();
    }
    else {
        Task_allBlockedFunc();
        /*
         * disable ints just in case the
         * allBlockedFunc left them enabled
         */
        Hwi_disable();
    }
}

/*
 *  ======== Task_deleteTerminatedTasksFunc ========
 */
Void Task_deleteTerminatedTasksFunc()
{
    UInt hwiKey, taskKey;
    Task_Handle tsk;

    taskKey = Task_disable();

    hwiKey = Hwi_disable();

    if (!Queue_empty(Task_Module_State_terminatedQ())) {
        tsk = Queue_head(Task_Module_State_terminatedQ());
        Hwi_restore(hwiKey);
        tsk->readyQ = NULL;
        Task_delete(&tsk);
    }
    else {
        Hwi_restore(hwiKey);
    }

    Task_restore(taskKey);
}
