/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     PROLOGUE
 *     INCLUDES
 *     
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_family_arm_cc26xx_Power__include
#define ti_sysbios_family_arm_cc26xx_Power__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_family_arm_cc26xx_Power__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_family_arm_cc26xx_Power___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/family/arm/cc26xx/package/package.defs.h>

#include <xdc/runtime/Assert.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/interfaces/IPower.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef xdc_Void (*ti_sysbios_family_arm_cc26xx_Power_FuncPtr)(void);

/* Constraint */
enum ti_sysbios_family_arm_cc26xx_Power_Constraint {
    ti_sysbios_family_arm_cc26xx_Power_SB_VIMS_CACHE_RETAIN = 0x1,
    ti_sysbios_family_arm_cc26xx_Power_SD_DISALLOW = 0x2,
    ti_sysbios_family_arm_cc26xx_Power_SB_DISALLOW = 0x4,
    ti_sysbios_family_arm_cc26xx_Power_IDLE_PD_DISALLOW = 0x8,
    ti_sysbios_family_arm_cc26xx_Power_NEED_FLASH_IN_IDLE = 0x10,
    ti_sysbios_family_arm_cc26xx_Power_NUMCONSTRAINTS = 5
};
typedef enum ti_sysbios_family_arm_cc26xx_Power_Constraint ti_sysbios_family_arm_cc26xx_Power_Constraint;

/* LatencyType */
enum ti_sysbios_family_arm_cc26xx_Power_LatencyType {
    ti_sysbios_family_arm_cc26xx_Power_TOTAL,
    ti_sysbios_family_arm_cc26xx_Power_RESUME
};
typedef enum ti_sysbios_family_arm_cc26xx_Power_LatencyType ti_sysbios_family_arm_cc26xx_Power_LatencyType;

/* SleepState */
enum ti_sysbios_family_arm_cc26xx_Power_SleepState {
    ti_sysbios_family_arm_cc26xx_Power_STANDBY = 0x1
};
typedef enum ti_sysbios_family_arm_cc26xx_Power_SleepState ti_sysbios_family_arm_cc26xx_Power_SleepState;

/* Event */
enum ti_sysbios_family_arm_cc26xx_Power_Event {
    ti_sysbios_family_arm_cc26xx_Power_ENTERING_STANDBY = 0x1,
    ti_sysbios_family_arm_cc26xx_Power_ENTERING_SHUTDOWN = 0x2,
    ti_sysbios_family_arm_cc26xx_Power_AWAKE_STANDBY = 0x4,
    ti_sysbios_family_arm_cc26xx_Power_AWAKE_STANDBY_LATE = 0x8,
    ti_sysbios_family_arm_cc26xx_Power_XOSC_HF_SWITCHED = 0x10,
    ti_sysbios_family_arm_cc26xx_Power_NUMEVENTS = 5
};
typedef enum ti_sysbios_family_arm_cc26xx_Power_Event ti_sysbios_family_arm_cc26xx_Power_Event;

/* NotifyResponse */
enum ti_sysbios_family_arm_cc26xx_Power_NotifyResponse {
    ti_sysbios_family_arm_cc26xx_Power_NOTIFYDONE = 0,
    ti_sysbios_family_arm_cc26xx_Power_NOTIFYERROR
};
typedef enum ti_sysbios_family_arm_cc26xx_Power_NotifyResponse ti_sysbios_family_arm_cc26xx_Power_NotifyResponse;

/* Status */
enum ti_sysbios_family_arm_cc26xx_Power_Status {
    ti_sysbios_family_arm_cc26xx_Power_SOK = 0,
    ti_sysbios_family_arm_cc26xx_Power_SOK_STATE_RESTORED = 1,
    ti_sysbios_family_arm_cc26xx_Power_EFAIL = 2,
    ti_sysbios_family_arm_cc26xx_Power_EINVALIDPOINTER = 3,
    ti_sysbios_family_arm_cc26xx_Power_ECHANGE_NOT_ALLOWED = 4,
    ti_sysbios_family_arm_cc26xx_Power_ETIMEOUT = 5,
    ti_sysbios_family_arm_cc26xx_Power_EBUSY = 6
};
typedef enum ti_sysbios_family_arm_cc26xx_Power_Status ti_sysbios_family_arm_cc26xx_Power_Status;

/* TransitionState */
enum ti_sysbios_family_arm_cc26xx_Power_TransitionState {
    ti_sysbios_family_arm_cc26xx_Power_ACTIVE = 0x1,
    ti_sysbios_family_arm_cc26xx_Power_ENTERING_SLEEP = 0x2,
    ti_sysbios_family_arm_cc26xx_Power_EXITING_SLEEP = 0x3,
    ti_sysbios_family_arm_cc26xx_Power_SHUTDOWN = 0x4
};
typedef enum ti_sysbios_family_arm_cc26xx_Power_TransitionState ti_sysbios_family_arm_cc26xx_Power_TransitionState;

/* NotifyObj */
struct ti_sysbios_family_arm_cc26xx_Power_NotifyObj {
    ti_sysbios_knl_Queue_Elem link;
    xdc_UInt32 eventTypes;
    xdc_Fxn notifyFxn;
    xdc_UArg clientArg;
};


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_cc26xx_Power_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__diagsEnabled ti_sysbios_family_arm_cc26xx_Power_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_cc26xx_Power_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__diagsIncluded ti_sysbios_family_arm_cc26xx_Power_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_family_arm_cc26xx_Power_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__diagsMask ti_sysbios_family_arm_cc26xx_Power_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_cc26xx_Power_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__gateObj ti_sysbios_family_arm_cc26xx_Power_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_family_arm_cc26xx_Power_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__gatePrms ti_sysbios_family_arm_cc26xx_Power_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_family_arm_cc26xx_Power_Module__id;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__id ti_sysbios_family_arm_cc26xx_Power_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerDefined ti_sysbios_family_arm_cc26xx_Power_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerObj ti_sysbios_family_arm_cc26xx_Power_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn0 ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn1 ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn2 ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn4 ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn8 ti_sysbios_family_arm_cc26xx_Power_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_family_arm_cc26xx_Power_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Module__startupDoneFxn ti_sysbios_family_arm_cc26xx_Power_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_family_arm_cc26xx_Power_Object__count;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Object__count ti_sysbios_family_arm_cc26xx_Power_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_family_arm_cc26xx_Power_Object__heap;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Object__heap ti_sysbios_family_arm_cc26xx_Power_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_family_arm_cc26xx_Power_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Object__sizeof ti_sysbios_family_arm_cc26xx_Power_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_family_arm_cc26xx_Power_Object__table;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_Object__table ti_sysbios_family_arm_cc26xx_Power_Object__table__C;

/* A_tooManyCallsReleaseConstraint */
#define ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseConstraint (ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseConstraint__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseConstraint;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseConstraint ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseConstraint__C;

/* A_tooManyCallsReleaseDependency */
#define ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseDependency (ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseDependency__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseDependency;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseDependency ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseDependency__C;

/* idle */
#ifdef ti_sysbios_family_arm_cc26xx_Power_idle__D
#define ti_sysbios_family_arm_cc26xx_Power_idle (ti_sysbios_family_arm_cc26xx_Power_idle__D)
#else
#define ti_sysbios_family_arm_cc26xx_Power_idle (ti_sysbios_family_arm_cc26xx_Power_idle__C)
typedef xdc_Bool CT__ti_sysbios_family_arm_cc26xx_Power_idle;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_idle ti_sysbios_family_arm_cc26xx_Power_idle__C;
#endif

/* resumeTicksSTANDBY */
#ifdef ti_sysbios_family_arm_cc26xx_Power_resumeTicksSTANDBY__D
#define ti_sysbios_family_arm_cc26xx_Power_resumeTicksSTANDBY (ti_sysbios_family_arm_cc26xx_Power_resumeTicksSTANDBY__D)
#else
#define ti_sysbios_family_arm_cc26xx_Power_resumeTicksSTANDBY (ti_sysbios_family_arm_cc26xx_Power_resumeTicksSTANDBY__C)
typedef xdc_UInt CT__ti_sysbios_family_arm_cc26xx_Power_resumeTicksSTANDBY;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_resumeTicksSTANDBY ti_sysbios_family_arm_cc26xx_Power_resumeTicksSTANDBY__C;
#endif

/* totalTicksSTANDBY */
#ifdef ti_sysbios_family_arm_cc26xx_Power_totalTicksSTANDBY__D
#define ti_sysbios_family_arm_cc26xx_Power_totalTicksSTANDBY (ti_sysbios_family_arm_cc26xx_Power_totalTicksSTANDBY__D)
#else
#define ti_sysbios_family_arm_cc26xx_Power_totalTicksSTANDBY (ti_sysbios_family_arm_cc26xx_Power_totalTicksSTANDBY__C)
typedef xdc_UInt CT__ti_sysbios_family_arm_cc26xx_Power_totalTicksSTANDBY;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_totalTicksSTANDBY ti_sysbios_family_arm_cc26xx_Power_totalTicksSTANDBY__C;
#endif

/* wakeDelaySTANDBY */
#ifdef ti_sysbios_family_arm_cc26xx_Power_wakeDelaySTANDBY__D
#define ti_sysbios_family_arm_cc26xx_Power_wakeDelaySTANDBY (ti_sysbios_family_arm_cc26xx_Power_wakeDelaySTANDBY__D)
#else
#define ti_sysbios_family_arm_cc26xx_Power_wakeDelaySTANDBY (ti_sysbios_family_arm_cc26xx_Power_wakeDelaySTANDBY__C)
typedef xdc_UInt CT__ti_sysbios_family_arm_cc26xx_Power_wakeDelaySTANDBY;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_wakeDelaySTANDBY ti_sysbios_family_arm_cc26xx_Power_wakeDelaySTANDBY__C;
#endif

/* initialWaitXOSC_HF */
#ifdef ti_sysbios_family_arm_cc26xx_Power_initialWaitXOSC_HF__D
#define ti_sysbios_family_arm_cc26xx_Power_initialWaitXOSC_HF (ti_sysbios_family_arm_cc26xx_Power_initialWaitXOSC_HF__D)
#else
#define ti_sysbios_family_arm_cc26xx_Power_initialWaitXOSC_HF (ti_sysbios_family_arm_cc26xx_Power_initialWaitXOSC_HF__C)
typedef xdc_UInt CT__ti_sysbios_family_arm_cc26xx_Power_initialWaitXOSC_HF;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_initialWaitXOSC_HF ti_sysbios_family_arm_cc26xx_Power_initialWaitXOSC_HF__C;
#endif

/* retryWaitXOSC_HF */
#ifdef ti_sysbios_family_arm_cc26xx_Power_retryWaitXOSC_HF__D
#define ti_sysbios_family_arm_cc26xx_Power_retryWaitXOSC_HF (ti_sysbios_family_arm_cc26xx_Power_retryWaitXOSC_HF__D)
#else
#define ti_sysbios_family_arm_cc26xx_Power_retryWaitXOSC_HF (ti_sysbios_family_arm_cc26xx_Power_retryWaitXOSC_HF__C)
typedef xdc_UInt CT__ti_sysbios_family_arm_cc26xx_Power_retryWaitXOSC_HF;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_retryWaitXOSC_HF ti_sysbios_family_arm_cc26xx_Power_retryWaitXOSC_HF__C;
#endif

/* calibrateRCOSC */
#ifdef ti_sysbios_family_arm_cc26xx_Power_calibrateRCOSC__D
#define ti_sysbios_family_arm_cc26xx_Power_calibrateRCOSC (ti_sysbios_family_arm_cc26xx_Power_calibrateRCOSC__D)
#else
#define ti_sysbios_family_arm_cc26xx_Power_calibrateRCOSC (ti_sysbios_family_arm_cc26xx_Power_calibrateRCOSC__C)
typedef xdc_Bool CT__ti_sysbios_family_arm_cc26xx_Power_calibrateRCOSC;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_calibrateRCOSC ti_sysbios_family_arm_cc26xx_Power_calibrateRCOSC__C;
#endif

/* clockFunc */
#define ti_sysbios_family_arm_cc26xx_Power_clockFunc (ti_sysbios_family_arm_cc26xx_Power_clockFunc__C)
typedef ti_sysbios_knl_Clock_FuncPtr CT__ti_sysbios_family_arm_cc26xx_Power_clockFunc;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_clockFunc ti_sysbios_family_arm_cc26xx_Power_clockFunc__C;

/* lfClockFunc */
#define ti_sysbios_family_arm_cc26xx_Power_lfClockFunc (ti_sysbios_family_arm_cc26xx_Power_lfClockFunc__C)
typedef ti_sysbios_knl_Clock_FuncPtr CT__ti_sysbios_family_arm_cc26xx_Power_lfClockFunc;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_lfClockFunc ti_sysbios_family_arm_cc26xx_Power_lfClockFunc__C;

/* xoscClockFunc */
#define ti_sysbios_family_arm_cc26xx_Power_xoscClockFunc (ti_sysbios_family_arm_cc26xx_Power_xoscClockFunc__C)
typedef ti_sysbios_knl_Clock_FuncPtr CT__ti_sysbios_family_arm_cc26xx_Power_xoscClockFunc;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_xoscClockFunc ti_sysbios_family_arm_cc26xx_Power_xoscClockFunc__C;

/* notifyTrapFunc */
#define ti_sysbios_family_arm_cc26xx_Power_notifyTrapFunc (ti_sysbios_family_arm_cc26xx_Power_notifyTrapFunc__C)
typedef ti_sysbios_family_arm_cc26xx_Power_FuncPtr CT__ti_sysbios_family_arm_cc26xx_Power_notifyTrapFunc;
__extern __FAR__ const CT__ti_sysbios_family_arm_cc26xx_Power_notifyTrapFunc ti_sysbios_family_arm_cc26xx_Power_notifyTrapFunc__C;


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_family_arm_cc26xx_Power_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_family_arm_cc26xx_Power_Fxns__ ti_sysbios_family_arm_cc26xx_Power_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_family_arm_cc26xx_Power_Module_startup ti_sysbios_family_arm_cc26xx_Power_Module_startup__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_Module_startup__E, "ti_sysbios_family_arm_cc26xx_Power_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_cc26xx_Power_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_Module_startup__F, "ti_sysbios_family_arm_cc26xx_Power_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_cc26xx_Power_Module_startup__F( xdc_Int state );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_Module__startupDone__S, "ti_sysbios_family_arm_cc26xx_Power_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_family_arm_cc26xx_Power_Module__startupDone__S( void );

/* standbyPolicy__E */
#define ti_sysbios_family_arm_cc26xx_Power_standbyPolicy ti_sysbios_family_arm_cc26xx_Power_standbyPolicy__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_standbyPolicy__E, "ti_sysbios_family_arm_cc26xx_Power_standbyPolicy")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_standbyPolicy__E( void );

/* defaultClockFunc__E */
#define ti_sysbios_family_arm_cc26xx_Power_defaultClockFunc ti_sysbios_family_arm_cc26xx_Power_defaultClockFunc__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_defaultClockFunc__E, "ti_sysbios_family_arm_cc26xx_Power_defaultClockFunc")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_defaultClockFunc__E( xdc_UArg arg );

/* defaultNotifyTrapFunc__E */
#define ti_sysbios_family_arm_cc26xx_Power_defaultNotifyTrapFunc ti_sysbios_family_arm_cc26xx_Power_defaultNotifyTrapFunc__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_defaultNotifyTrapFunc__E, "ti_sysbios_family_arm_cc26xx_Power_defaultNotifyTrapFunc")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_defaultNotifyTrapFunc__E( void );

/* LF_clockFunc__E */
#define ti_sysbios_family_arm_cc26xx_Power_LF_clockFunc ti_sysbios_family_arm_cc26xx_Power_LF_clockFunc__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_LF_clockFunc__E, "ti_sysbios_family_arm_cc26xx_Power_LF_clockFunc")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_LF_clockFunc__E( xdc_UArg arg );

/* XOSC_HF_clockFunc__E */
#define ti_sysbios_family_arm_cc26xx_Power_XOSC_HF_clockFunc ti_sysbios_family_arm_cc26xx_Power_XOSC_HF_clockFunc__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_XOSC_HF_clockFunc__E, "ti_sysbios_family_arm_cc26xx_Power_XOSC_HF_clockFunc")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_XOSC_HF_clockFunc__E( xdc_UArg arg );

/* initiateCalibration__E */
#define ti_sysbios_family_arm_cc26xx_Power_initiateCalibration ti_sysbios_family_arm_cc26xx_Power_initiateCalibration__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_initiateCalibration__E, "ti_sysbios_family_arm_cc26xx_Power_initiateCalibration")
__extern xdc_Bool ti_sysbios_family_arm_cc26xx_Power_initiateCalibration__E( void );

/* startFirstMeasurement__E */
#define ti_sysbios_family_arm_cc26xx_Power_startFirstMeasurement ti_sysbios_family_arm_cc26xx_Power_startFirstMeasurement__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_startFirstMeasurement__E, "ti_sysbios_family_arm_cc26xx_Power_startFirstMeasurement")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_startFirstMeasurement__E( void );

/* auxISR__E */
#define ti_sysbios_family_arm_cc26xx_Power_auxISR ti_sysbios_family_arm_cc26xx_Power_auxISR__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_auxISR__E, "ti_sysbios_family_arm_cc26xx_Power_auxISR")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_auxISR__E( xdc_UArg arg );

/* getClockHandle__E */
#define ti_sysbios_family_arm_cc26xx_Power_getClockHandle ti_sysbios_family_arm_cc26xx_Power_getClockHandle__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_getClockHandle__E, "ti_sysbios_family_arm_cc26xx_Power_getClockHandle")
__extern ti_sysbios_knl_Clock_Handle ti_sysbios_family_arm_cc26xx_Power_getClockHandle__E( void );

/* doWFI__E */
#define ti_sysbios_family_arm_cc26xx_Power_doWFI ti_sysbios_family_arm_cc26xx_Power_doWFI__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_doWFI__E, "ti_sysbios_family_arm_cc26xx_Power_doWFI")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_doWFI__E( void );

/* getConstraintInfo__E */
#define ti_sysbios_family_arm_cc26xx_Power_getConstraintInfo ti_sysbios_family_arm_cc26xx_Power_getConstraintInfo__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_getConstraintInfo__E, "ti_sysbios_family_arm_cc26xx_Power_getConstraintInfo")
__extern xdc_UInt32 ti_sysbios_family_arm_cc26xx_Power_getConstraintInfo__E( void );

/* getDependencyCount__E */
#define ti_sysbios_family_arm_cc26xx_Power_getDependencyCount ti_sysbios_family_arm_cc26xx_Power_getDependencyCount__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_getDependencyCount__E, "ti_sysbios_family_arm_cc26xx_Power_getDependencyCount")
__extern xdc_UInt32 ti_sysbios_family_arm_cc26xx_Power_getDependencyCount__E( xdc_UInt8 resourceID );

/* getTransitionState__E */
#define ti_sysbios_family_arm_cc26xx_Power_getTransitionState ti_sysbios_family_arm_cc26xx_Power_getTransitionState__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_getTransitionState__E, "ti_sysbios_family_arm_cc26xx_Power_getTransitionState")
__extern ti_sysbios_family_arm_cc26xx_Power_TransitionState ti_sysbios_family_arm_cc26xx_Power_getTransitionState__E( void );

/* getTicksUntilWakeup__E */
#define ti_sysbios_family_arm_cc26xx_Power_getTicksUntilWakeup ti_sysbios_family_arm_cc26xx_Power_getTicksUntilWakeup__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_getTicksUntilWakeup__E, "ti_sysbios_family_arm_cc26xx_Power_getTicksUntilWakeup")
__extern xdc_UInt32 ti_sysbios_family_arm_cc26xx_Power_getTicksUntilWakeup__E( void );

/* getTransitionLatency__E */
#define ti_sysbios_family_arm_cc26xx_Power_getTransitionLatency ti_sysbios_family_arm_cc26xx_Power_getTransitionLatency__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_getTransitionLatency__E, "ti_sysbios_family_arm_cc26xx_Power_getTransitionLatency")
__extern xdc_UInt32 ti_sysbios_family_arm_cc26xx_Power_getTransitionLatency__E( ti_sysbios_family_arm_cc26xx_Power_SleepState sleepState, ti_sysbios_family_arm_cc26xx_Power_LatencyType type );

/* getXoscStartupTime__E */
#define ti_sysbios_family_arm_cc26xx_Power_getXoscStartupTime ti_sysbios_family_arm_cc26xx_Power_getXoscStartupTime__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_getXoscStartupTime__E, "ti_sysbios_family_arm_cc26xx_Power_getXoscStartupTime")
__extern xdc_UInt32 ti_sysbios_family_arm_cc26xx_Power_getXoscStartupTime__E( xdc_UInt32 timeUntilWakeupInMs );

/* isStableXOSC_HF__E */
#define ti_sysbios_family_arm_cc26xx_Power_isStableXOSC_HF ti_sysbios_family_arm_cc26xx_Power_isStableXOSC_HF__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_isStableXOSC_HF__E, "ti_sysbios_family_arm_cc26xx_Power_isStableXOSC_HF")
__extern xdc_Bool ti_sysbios_family_arm_cc26xx_Power_isStableXOSC_HF__E( void );

/* releaseConstraint__E */
#define ti_sysbios_family_arm_cc26xx_Power_releaseConstraint ti_sysbios_family_arm_cc26xx_Power_releaseConstraint__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_releaseConstraint__E, "ti_sysbios_family_arm_cc26xx_Power_releaseConstraint")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_releaseConstraint__E( ti_sysbios_family_arm_cc26xx_Power_Constraint constraint );

/* releaseDependency__E */
#define ti_sysbios_family_arm_cc26xx_Power_releaseDependency ti_sysbios_family_arm_cc26xx_Power_releaseDependency__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_releaseDependency__E, "ti_sysbios_family_arm_cc26xx_Power_releaseDependency")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_releaseDependency__E( xdc_UInt8 resourceID );

/* registerNotify__E */
#define ti_sysbios_family_arm_cc26xx_Power_registerNotify ti_sysbios_family_arm_cc26xx_Power_registerNotify__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_registerNotify__E, "ti_sysbios_family_arm_cc26xx_Power_registerNotify")
__extern ti_sysbios_family_arm_cc26xx_Power_Status ti_sysbios_family_arm_cc26xx_Power_registerNotify__E( ti_sysbios_family_arm_cc26xx_Power_NotifyObj *pNotifyObj, xdc_UInt32 eventTypes, xdc_Fxn notifyFxn, xdc_UArg clientArg, xdc_UArg arg );

/* setConstraint__E */
#define ti_sysbios_family_arm_cc26xx_Power_setConstraint ti_sysbios_family_arm_cc26xx_Power_setConstraint__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_setConstraint__E, "ti_sysbios_family_arm_cc26xx_Power_setConstraint")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_setConstraint__E( ti_sysbios_family_arm_cc26xx_Power_Constraint constraint );

/* setDependency__E */
#define ti_sysbios_family_arm_cc26xx_Power_setDependency ti_sysbios_family_arm_cc26xx_Power_setDependency__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_setDependency__E, "ti_sysbios_family_arm_cc26xx_Power_setDependency")
__extern xdc_Bool ti_sysbios_family_arm_cc26xx_Power_setDependency__E( xdc_UInt8 resourceID );

/* shutdown__E */
#define ti_sysbios_family_arm_cc26xx_Power_shutdown ti_sysbios_family_arm_cc26xx_Power_shutdown__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_shutdown__E, "ti_sysbios_family_arm_cc26xx_Power_shutdown")
__extern ti_sysbios_family_arm_cc26xx_Power_Status ti_sysbios_family_arm_cc26xx_Power_shutdown__E( xdc_UArg arg );

/* sleep__E */
#define ti_sysbios_family_arm_cc26xx_Power_sleep ti_sysbios_family_arm_cc26xx_Power_sleep__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_sleep__E, "ti_sysbios_family_arm_cc26xx_Power_sleep")
__extern ti_sysbios_family_arm_cc26xx_Power_Status ti_sysbios_family_arm_cc26xx_Power_sleep__E( ti_sysbios_family_arm_cc26xx_Power_SleepState sleepState, xdc_UArg arg0, xdc_UArg arg1 );

/* switchXOSC_HF__E */
#define ti_sysbios_family_arm_cc26xx_Power_switchXOSC_HF ti_sysbios_family_arm_cc26xx_Power_switchXOSC_HF__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_switchXOSC_HF__E, "ti_sysbios_family_arm_cc26xx_Power_switchXOSC_HF")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_switchXOSC_HF__E( void );

/* unregisterNotify__E */
#define ti_sysbios_family_arm_cc26xx_Power_unregisterNotify ti_sysbios_family_arm_cc26xx_Power_unregisterNotify__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_unregisterNotify__E, "ti_sysbios_family_arm_cc26xx_Power_unregisterNotify")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_unregisterNotify__E( ti_sysbios_family_arm_cc26xx_Power_NotifyObj *pNotifyObj );

/* idleCPU__E */
#define ti_sysbios_family_arm_cc26xx_Power_idleCPU ti_sysbios_family_arm_cc26xx_Power_idleCPU__E
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_idleCPU__E, "ti_sysbios_family_arm_cc26xx_Power_idleCPU")
__extern xdc_Void ti_sysbios_family_arm_cc26xx_Power_idleCPU__E( void );

/* notify__I */
#define ti_sysbios_family_arm_cc26xx_Power_notify ti_sysbios_family_arm_cc26xx_Power_notify__I
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_notify__I, "ti_sysbios_family_arm_cc26xx_Power_notify")
__extern ti_sysbios_family_arm_cc26xx_Power_Status ti_sysbios_family_arm_cc26xx_Power_notify__I( ti_sysbios_family_arm_cc26xx_Power_Event eventType );

/* serviceNotifyQ__I */
#define ti_sysbios_family_arm_cc26xx_Power_serviceNotifyQ ti_sysbios_family_arm_cc26xx_Power_serviceNotifyQ__I
xdc__CODESECT(ti_sysbios_family_arm_cc26xx_Power_serviceNotifyQ__I, "ti_sysbios_family_arm_cc26xx_Power_serviceNotifyQ")
__extern ti_sysbios_family_arm_cc26xx_Power_NotifyResponse ti_sysbios_family_arm_cc26xx_Power_serviceNotifyQ__I( ti_sysbios_family_arm_cc26xx_Power_Event eventType );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_IPower_Module ti_sysbios_family_arm_cc26xx_Power_Module_upCast( void )
{
    return (ti_sysbios_interfaces_IPower_Module)&ti_sysbios_family_arm_cc26xx_Power_Module__FXNS__C;
}

/* Module_to_ti_sysbios_interfaces_IPower */
#define ti_sysbios_family_arm_cc26xx_Power_Module_to_ti_sysbios_interfaces_IPower ti_sysbios_family_arm_cc26xx_Power_Module_upCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_family_arm_cc26xx_Power_Module_startupDone() ti_sysbios_family_arm_cc26xx_Power_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_family_arm_cc26xx_Power_Object_heap() ti_sysbios_family_arm_cc26xx_Power_Object__heap__C

/* Module_heap */
#define ti_sysbios_family_arm_cc26xx_Power_Module_heap() ti_sysbios_family_arm_cc26xx_Power_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_family_arm_cc26xx_Power_Module__id ti_sysbios_family_arm_cc26xx_Power_Module_id( void ) 
{
    return ti_sysbios_family_arm_cc26xx_Power_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_family_arm_cc26xx_Power_Module_hasMask( void ) 
{
    return ti_sysbios_family_arm_cc26xx_Power_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_family_arm_cc26xx_Power_Module_getMask( void ) 
{
    return ti_sysbios_family_arm_cc26xx_Power_Module__diagsMask__C != NULL ? *ti_sysbios_family_arm_cc26xx_Power_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_family_arm_cc26xx_Power_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_family_arm_cc26xx_Power_Module__diagsMask__C != NULL) *ti_sysbios_family_arm_cc26xx_Power_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_family_arm_cc26xx_Power__top__
#undef __nested__
#endif

#endif /* ti_sysbios_family_arm_cc26xx_Power__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_family_arm_cc26xx_Power__internalaccess))

#ifndef ti_sysbios_family_arm_cc26xx_Power__include_state
#define ti_sysbios_family_arm_cc26xx_Power__include_state

/* Module_State */
struct ti_sysbios_family_arm_cc26xx_Power_Module_State {
    xdc_UInt32 constraintsMask;
    ti_sysbios_family_arm_cc26xx_Power_TransitionState state;
    xdc_Bool xoscPending;
    char __dummy;
};

/* Module__state__V */
extern struct ti_sysbios_family_arm_cc26xx_Power_Module_State__ ti_sysbios_family_arm_cc26xx_Power_Module__state__V;

/* Module_State_notifyQ */
__extern __FAR__ const xdc_SizeT ti_sysbios_family_arm_cc26xx_Power_Module_State_notifyQ__O;
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_family_arm_cc26xx_Power_Module_State_notifyQ()
{
    return (ti_sysbios_knl_Queue_Handle)(((char*)&ti_sysbios_family_arm_cc26xx_Power_Module__state__V) + ti_sysbios_family_arm_cc26xx_Power_Module_State_notifyQ__O);
}

/* Module_State_clockObj */
__extern __FAR__ const xdc_SizeT ti_sysbios_family_arm_cc26xx_Power_Module_State_clockObj__O;
static inline ti_sysbios_knl_Clock_Handle ti_sysbios_family_arm_cc26xx_Power_Module_State_clockObj()
{
    return (ti_sysbios_knl_Clock_Handle)(((char*)&ti_sysbios_family_arm_cc26xx_Power_Module__state__V) + ti_sysbios_family_arm_cc26xx_Power_Module_State_clockObj__O);
}

/* Module_State_xoscClockObj */
__extern __FAR__ const xdc_SizeT ti_sysbios_family_arm_cc26xx_Power_Module_State_xoscClockObj__O;
static inline ti_sysbios_knl_Clock_Handle ti_sysbios_family_arm_cc26xx_Power_Module_State_xoscClockObj()
{
    return (ti_sysbios_knl_Clock_Handle)(((char*)&ti_sysbios_family_arm_cc26xx_Power_Module__state__V) + ti_sysbios_family_arm_cc26xx_Power_Module_State_xoscClockObj__O);
}

/* Module_State_lfClockObj */
__extern __FAR__ const xdc_SizeT ti_sysbios_family_arm_cc26xx_Power_Module_State_lfClockObj__O;
static inline ti_sysbios_knl_Clock_Handle ti_sysbios_family_arm_cc26xx_Power_Module_State_lfClockObj()
{
    return (ti_sysbios_knl_Clock_Handle)(((char*)&ti_sysbios_family_arm_cc26xx_Power_Module__state__V) + ti_sysbios_family_arm_cc26xx_Power_Module_State_lfClockObj__O);
}

#endif /* ti_sysbios_family_arm_cc26xx_Power__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_family_arm_cc26xx_Power__nolocalnames)

#ifndef ti_sysbios_family_arm_cc26xx_Power__localnames__done
#define ti_sysbios_family_arm_cc26xx_Power__localnames__done

/* module prefix */
#define Power_FuncPtr ti_sysbios_family_arm_cc26xx_Power_FuncPtr
#define Power_Constraint ti_sysbios_family_arm_cc26xx_Power_Constraint
#define Power_LatencyType ti_sysbios_family_arm_cc26xx_Power_LatencyType
#define Power_SleepState ti_sysbios_family_arm_cc26xx_Power_SleepState
#define Power_Event ti_sysbios_family_arm_cc26xx_Power_Event
#define Power_NotifyResponse ti_sysbios_family_arm_cc26xx_Power_NotifyResponse
#define Power_Status ti_sysbios_family_arm_cc26xx_Power_Status
#define Power_TransitionState ti_sysbios_family_arm_cc26xx_Power_TransitionState
#define Power_NotifyObj ti_sysbios_family_arm_cc26xx_Power_NotifyObj
#define Power_Module_State ti_sysbios_family_arm_cc26xx_Power_Module_State
#define Power_SB_VIMS_CACHE_RETAIN ti_sysbios_family_arm_cc26xx_Power_SB_VIMS_CACHE_RETAIN
#define Power_SD_DISALLOW ti_sysbios_family_arm_cc26xx_Power_SD_DISALLOW
#define Power_SB_DISALLOW ti_sysbios_family_arm_cc26xx_Power_SB_DISALLOW
#define Power_IDLE_PD_DISALLOW ti_sysbios_family_arm_cc26xx_Power_IDLE_PD_DISALLOW
#define Power_NEED_FLASH_IN_IDLE ti_sysbios_family_arm_cc26xx_Power_NEED_FLASH_IN_IDLE
#define Power_NUMCONSTRAINTS ti_sysbios_family_arm_cc26xx_Power_NUMCONSTRAINTS
#define Power_TOTAL ti_sysbios_family_arm_cc26xx_Power_TOTAL
#define Power_RESUME ti_sysbios_family_arm_cc26xx_Power_RESUME
#define Power_STANDBY ti_sysbios_family_arm_cc26xx_Power_STANDBY
#define Power_ENTERING_STANDBY ti_sysbios_family_arm_cc26xx_Power_ENTERING_STANDBY
#define Power_ENTERING_SHUTDOWN ti_sysbios_family_arm_cc26xx_Power_ENTERING_SHUTDOWN
#define Power_AWAKE_STANDBY ti_sysbios_family_arm_cc26xx_Power_AWAKE_STANDBY
#define Power_AWAKE_STANDBY_LATE ti_sysbios_family_arm_cc26xx_Power_AWAKE_STANDBY_LATE
#define Power_XOSC_HF_SWITCHED ti_sysbios_family_arm_cc26xx_Power_XOSC_HF_SWITCHED
#define Power_NUMEVENTS ti_sysbios_family_arm_cc26xx_Power_NUMEVENTS
#define Power_NOTIFYDONE ti_sysbios_family_arm_cc26xx_Power_NOTIFYDONE
#define Power_NOTIFYERROR ti_sysbios_family_arm_cc26xx_Power_NOTIFYERROR
#define Power_SOK ti_sysbios_family_arm_cc26xx_Power_SOK
#define Power_SOK_STATE_RESTORED ti_sysbios_family_arm_cc26xx_Power_SOK_STATE_RESTORED
#define Power_EFAIL ti_sysbios_family_arm_cc26xx_Power_EFAIL
#define Power_EINVALIDPOINTER ti_sysbios_family_arm_cc26xx_Power_EINVALIDPOINTER
#define Power_ECHANGE_NOT_ALLOWED ti_sysbios_family_arm_cc26xx_Power_ECHANGE_NOT_ALLOWED
#define Power_ETIMEOUT ti_sysbios_family_arm_cc26xx_Power_ETIMEOUT
#define Power_EBUSY ti_sysbios_family_arm_cc26xx_Power_EBUSY
#define Power_ACTIVE ti_sysbios_family_arm_cc26xx_Power_ACTIVE
#define Power_ENTERING_SLEEP ti_sysbios_family_arm_cc26xx_Power_ENTERING_SLEEP
#define Power_EXITING_SLEEP ti_sysbios_family_arm_cc26xx_Power_EXITING_SLEEP
#define Power_SHUTDOWN ti_sysbios_family_arm_cc26xx_Power_SHUTDOWN
#define Power_A_tooManyCallsReleaseConstraint ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseConstraint
#define Power_A_tooManyCallsReleaseDependency ti_sysbios_family_arm_cc26xx_Power_A_tooManyCallsReleaseDependency
#define Power_idle ti_sysbios_family_arm_cc26xx_Power_idle
#define Power_resumeTicksSTANDBY ti_sysbios_family_arm_cc26xx_Power_resumeTicksSTANDBY
#define Power_totalTicksSTANDBY ti_sysbios_family_arm_cc26xx_Power_totalTicksSTANDBY
#define Power_wakeDelaySTANDBY ti_sysbios_family_arm_cc26xx_Power_wakeDelaySTANDBY
#define Power_initialWaitXOSC_HF ti_sysbios_family_arm_cc26xx_Power_initialWaitXOSC_HF
#define Power_retryWaitXOSC_HF ti_sysbios_family_arm_cc26xx_Power_retryWaitXOSC_HF
#define Power_calibrateRCOSC ti_sysbios_family_arm_cc26xx_Power_calibrateRCOSC
#define Power_clockFunc ti_sysbios_family_arm_cc26xx_Power_clockFunc
#define Power_lfClockFunc ti_sysbios_family_arm_cc26xx_Power_lfClockFunc
#define Power_xoscClockFunc ti_sysbios_family_arm_cc26xx_Power_xoscClockFunc
#define Power_notifyTrapFunc ti_sysbios_family_arm_cc26xx_Power_notifyTrapFunc
#define Power_Module_State_notifyQ ti_sysbios_family_arm_cc26xx_Power_Module_State_notifyQ
#define Power_Module_State_clockObj ti_sysbios_family_arm_cc26xx_Power_Module_State_clockObj
#define Power_Module_State_xoscClockObj ti_sysbios_family_arm_cc26xx_Power_Module_State_xoscClockObj
#define Power_Module_State_lfClockObj ti_sysbios_family_arm_cc26xx_Power_Module_State_lfClockObj
#define Power_standbyPolicy ti_sysbios_family_arm_cc26xx_Power_standbyPolicy
#define Power_defaultClockFunc ti_sysbios_family_arm_cc26xx_Power_defaultClockFunc
#define Power_defaultNotifyTrapFunc ti_sysbios_family_arm_cc26xx_Power_defaultNotifyTrapFunc
#define Power_LF_clockFunc ti_sysbios_family_arm_cc26xx_Power_LF_clockFunc
#define Power_XOSC_HF_clockFunc ti_sysbios_family_arm_cc26xx_Power_XOSC_HF_clockFunc
#define Power_initiateCalibration ti_sysbios_family_arm_cc26xx_Power_initiateCalibration
#define Power_startFirstMeasurement ti_sysbios_family_arm_cc26xx_Power_startFirstMeasurement
#define Power_auxISR ti_sysbios_family_arm_cc26xx_Power_auxISR
#define Power_getClockHandle ti_sysbios_family_arm_cc26xx_Power_getClockHandle
#define Power_doWFI ti_sysbios_family_arm_cc26xx_Power_doWFI
#define Power_getConstraintInfo ti_sysbios_family_arm_cc26xx_Power_getConstraintInfo
#define Power_getDependencyCount ti_sysbios_family_arm_cc26xx_Power_getDependencyCount
#define Power_getTransitionState ti_sysbios_family_arm_cc26xx_Power_getTransitionState
#define Power_getTicksUntilWakeup ti_sysbios_family_arm_cc26xx_Power_getTicksUntilWakeup
#define Power_getTransitionLatency ti_sysbios_family_arm_cc26xx_Power_getTransitionLatency
#define Power_getXoscStartupTime ti_sysbios_family_arm_cc26xx_Power_getXoscStartupTime
#define Power_isStableXOSC_HF ti_sysbios_family_arm_cc26xx_Power_isStableXOSC_HF
#define Power_releaseConstraint ti_sysbios_family_arm_cc26xx_Power_releaseConstraint
#define Power_releaseDependency ti_sysbios_family_arm_cc26xx_Power_releaseDependency
#define Power_registerNotify ti_sysbios_family_arm_cc26xx_Power_registerNotify
#define Power_setConstraint ti_sysbios_family_arm_cc26xx_Power_setConstraint
#define Power_setDependency ti_sysbios_family_arm_cc26xx_Power_setDependency
#define Power_shutdown ti_sysbios_family_arm_cc26xx_Power_shutdown
#define Power_sleep ti_sysbios_family_arm_cc26xx_Power_sleep
#define Power_switchXOSC_HF ti_sysbios_family_arm_cc26xx_Power_switchXOSC_HF
#define Power_unregisterNotify ti_sysbios_family_arm_cc26xx_Power_unregisterNotify
#define Power_idleCPU ti_sysbios_family_arm_cc26xx_Power_idleCPU
#define Power_Module_name ti_sysbios_family_arm_cc26xx_Power_Module_name
#define Power_Module_id ti_sysbios_family_arm_cc26xx_Power_Module_id
#define Power_Module_startup ti_sysbios_family_arm_cc26xx_Power_Module_startup
#define Power_Module_startupDone ti_sysbios_family_arm_cc26xx_Power_Module_startupDone
#define Power_Module_hasMask ti_sysbios_family_arm_cc26xx_Power_Module_hasMask
#define Power_Module_getMask ti_sysbios_family_arm_cc26xx_Power_Module_getMask
#define Power_Module_setMask ti_sysbios_family_arm_cc26xx_Power_Module_setMask
#define Power_Object_heap ti_sysbios_family_arm_cc26xx_Power_Object_heap
#define Power_Module_heap ti_sysbios_family_arm_cc26xx_Power_Module_heap
#define Power_Module_upCast ti_sysbios_family_arm_cc26xx_Power_Module_upCast
#define Power_Module_to_ti_sysbios_interfaces_IPower ti_sysbios_family_arm_cc26xx_Power_Module_to_ti_sysbios_interfaces_IPower

#endif /* ti_sysbios_family_arm_cc26xx_Power__localnames__done */
#endif
