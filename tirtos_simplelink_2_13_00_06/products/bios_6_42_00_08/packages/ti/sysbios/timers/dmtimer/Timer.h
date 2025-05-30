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
 *     CREATE ARGS
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     PER-INSTANCE TYPES
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

#ifndef ti_sysbios_timers_dmtimer_Timer__include
#define ti_sysbios_timers_dmtimer_Timer__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_timers_dmtimer_Timer__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_timers_dmtimer_Timer___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/timers/dmtimer/package/package.defs.h>

#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/interfaces/ITimer.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/interfaces/ITimerSupport.h>
#include <ti/sysbios/timers/dmtimer/package/Timer_TimerSupportProxy.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_timers_dmtimer_Timer_FuncPtr;

/* ANY */
#define ti_sysbios_timers_dmtimer_Timer_ANY (~0)

/* StartMode */
typedef ti_sysbios_interfaces_ITimer_StartMode ti_sysbios_timers_dmtimer_Timer_StartMode;

/* RunMode */
typedef ti_sysbios_interfaces_ITimer_RunMode ti_sysbios_timers_dmtimer_Timer_RunMode;

/* Status */
typedef ti_sysbios_interfaces_ITimer_Status ti_sysbios_timers_dmtimer_Timer_Status;

/* PeriodType */
typedef ti_sysbios_interfaces_ITimer_PeriodType ti_sysbios_timers_dmtimer_Timer_PeriodType;

/* MAX_PERIOD */
#define ti_sysbios_timers_dmtimer_Timer_MAX_PERIOD (0xffffffff)

/* TiocpCfg */
struct ti_sysbios_timers_dmtimer_Timer_TiocpCfg {
    xdc_Bits8 idlemode;
    xdc_Bits8 emufree;
    xdc_Bits8 softreset;
};

/* Tier */
struct ti_sysbios_timers_dmtimer_Timer_Tier {
    xdc_Bits8 mat_it_ena;
    xdc_Bits8 ovf_it_ena;
    xdc_Bits8 tcar_it_ena;
};

/* Twer */
struct ti_sysbios_timers_dmtimer_Timer_Twer {
    xdc_Bits8 mat_wup_ena;
    xdc_Bits8 ovf_wup_ena;
    xdc_Bits8 tcar_wup_ena;
};

/* Tclr */
struct ti_sysbios_timers_dmtimer_Timer_Tclr {
    xdc_Bits32 ptv;
    xdc_Bits8 pre;
    xdc_Bits8 ce;
    xdc_Bits8 scpwm;
    xdc_Bits16 tcm;
    xdc_Bits16 trg;
    xdc_Bits8 pt;
    xdc_Bits8 captmode;
    xdc_Bits8 gpocfg;
};

/* Tsicr */
struct ti_sysbios_timers_dmtimer_Timer_Tsicr {
    xdc_Bits8 sft;
    xdc_Bits8 posted;
};

/* StartMode_AUTO */
#define ti_sysbios_timers_dmtimer_Timer_StartMode_AUTO ti_sysbios_interfaces_ITimer_StartMode_AUTO

/* StartMode_USER */
#define ti_sysbios_timers_dmtimer_Timer_StartMode_USER ti_sysbios_interfaces_ITimer_StartMode_USER

/* RunMode_CONTINUOUS */
#define ti_sysbios_timers_dmtimer_Timer_RunMode_CONTINUOUS ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS

/* RunMode_ONESHOT */
#define ti_sysbios_timers_dmtimer_Timer_RunMode_ONESHOT ti_sysbios_interfaces_ITimer_RunMode_ONESHOT

/* RunMode_DYNAMIC */
#define ti_sysbios_timers_dmtimer_Timer_RunMode_DYNAMIC ti_sysbios_interfaces_ITimer_RunMode_DYNAMIC

/* Status_INUSE */
#define ti_sysbios_timers_dmtimer_Timer_Status_INUSE ti_sysbios_interfaces_ITimer_Status_INUSE

/* Status_FREE */
#define ti_sysbios_timers_dmtimer_Timer_Status_FREE ti_sysbios_interfaces_ITimer_Status_FREE

/* PeriodType_MICROSECS */
#define ti_sysbios_timers_dmtimer_Timer_PeriodType_MICROSECS ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS

/* PeriodType_COUNTS */
#define ti_sysbios_timers_dmtimer_Timer_PeriodType_COUNTS ti_sysbios_interfaces_ITimer_PeriodType_COUNTS


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_timers_dmtimer_Timer_Args__create {
    xdc_Int id;
    ti_sysbios_interfaces_ITimer_FuncPtr tickFxn;
} ti_sysbios_timers_dmtimer_Timer_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* TimerDevice */
struct ti_sysbios_timers_dmtimer_Timer_TimerDevice {
    xdc_Int intNum;
    xdc_Int eventId;
    xdc_Ptr baseAddr;
};

/* Module_State */
typedef xdc_runtime_Types_FreqHz __T1_ti_sysbios_timers_dmtimer_Timer_Module_State__intFreqs;
typedef xdc_runtime_Types_FreqHz *__ARRAY1_ti_sysbios_timers_dmtimer_Timer_Module_State__intFreqs;
typedef __ARRAY1_ti_sysbios_timers_dmtimer_Timer_Module_State__intFreqs __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__intFreqs;
typedef ti_sysbios_timers_dmtimer_Timer_TimerDevice __T1_ti_sysbios_timers_dmtimer_Timer_Module_State__device;
typedef ti_sysbios_timers_dmtimer_Timer_TimerDevice *__ARRAY1_ti_sysbios_timers_dmtimer_Timer_Module_State__device;
typedef __ARRAY1_ti_sysbios_timers_dmtimer_Timer_Module_State__device __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__device;
typedef ti_sysbios_timers_dmtimer_Timer_Handle __T1_ti_sysbios_timers_dmtimer_Timer_Module_State__handles;
typedef ti_sysbios_timers_dmtimer_Timer_Handle *__ARRAY1_ti_sysbios_timers_dmtimer_Timer_Module_State__handles;
typedef __ARRAY1_ti_sysbios_timers_dmtimer_Timer_Module_State__handles __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__handles;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsMask ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_timers_dmtimer_Timer_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__gateObj ti_sysbios_timers_dmtimer_Timer_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_timers_dmtimer_Timer_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__gatePrms ti_sysbios_timers_dmtimer_Timer_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_timers_dmtimer_Timer_Module__id;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__id ti_sysbios_timers_dmtimer_Timer_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerObj ti_sysbios_timers_dmtimer_Timer_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_timers_dmtimer_Timer_Object__count;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__count ti_sysbios_timers_dmtimer_Timer_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_timers_dmtimer_Timer_Object__heap;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__heap ti_sysbios_timers_dmtimer_Timer_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_timers_dmtimer_Timer_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__sizeof ti_sysbios_timers_dmtimer_Timer_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_timers_dmtimer_Timer_Object__table;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__table ti_sysbios_timers_dmtimer_Timer_Object__table__C;

/* A_notAvailable */
#define ti_sysbios_timers_dmtimer_Timer_A_notAvailable (ti_sysbios_timers_dmtimer_Timer_A_notAvailable__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_timers_dmtimer_Timer_A_notAvailable;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_A_notAvailable ti_sysbios_timers_dmtimer_Timer_A_notAvailable__C;

/* E_invalidTimer */
#define ti_sysbios_timers_dmtimer_Timer_E_invalidTimer (ti_sysbios_timers_dmtimer_Timer_E_invalidTimer__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_timers_dmtimer_Timer_E_invalidTimer;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_invalidTimer ti_sysbios_timers_dmtimer_Timer_E_invalidTimer__C;

/* E_notAvailable */
#define ti_sysbios_timers_dmtimer_Timer_E_notAvailable (ti_sysbios_timers_dmtimer_Timer_E_notAvailable__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_timers_dmtimer_Timer_E_notAvailable;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_notAvailable ti_sysbios_timers_dmtimer_Timer_E_notAvailable__C;

/* E_cannotSupport */
#define ti_sysbios_timers_dmtimer_Timer_E_cannotSupport (ti_sysbios_timers_dmtimer_Timer_E_cannotSupport__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_timers_dmtimer_Timer_E_cannotSupport;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_cannotSupport ti_sysbios_timers_dmtimer_Timer_E_cannotSupport__C;

/* E_freqMismatch */
#define ti_sysbios_timers_dmtimer_Timer_E_freqMismatch (ti_sysbios_timers_dmtimer_Timer_E_freqMismatch__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_timers_dmtimer_Timer_E_freqMismatch;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_freqMismatch ti_sysbios_timers_dmtimer_Timer_E_freqMismatch__C;

/* E_badIntNum */
#define ti_sysbios_timers_dmtimer_Timer_E_badIntNum (ti_sysbios_timers_dmtimer_Timer_E_badIntNum__C)
typedef xdc_runtime_Error_Id CT__ti_sysbios_timers_dmtimer_Timer_E_badIntNum;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_badIntNum ti_sysbios_timers_dmtimer_Timer_E_badIntNum__C;

/* anyMask */
#ifdef ti_sysbios_timers_dmtimer_Timer_anyMask__D
#define ti_sysbios_timers_dmtimer_Timer_anyMask (ti_sysbios_timers_dmtimer_Timer_anyMask__D)
#else
#define ti_sysbios_timers_dmtimer_Timer_anyMask (ti_sysbios_timers_dmtimer_Timer_anyMask__C)
typedef xdc_Bits32 CT__ti_sysbios_timers_dmtimer_Timer_anyMask;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_anyMask ti_sysbios_timers_dmtimer_Timer_anyMask__C;
#endif

/* checkFrequency */
#ifdef ti_sysbios_timers_dmtimer_Timer_checkFrequency__D
#define ti_sysbios_timers_dmtimer_Timer_checkFrequency (ti_sysbios_timers_dmtimer_Timer_checkFrequency__D)
#else
#define ti_sysbios_timers_dmtimer_Timer_checkFrequency (ti_sysbios_timers_dmtimer_Timer_checkFrequency__C)
typedef xdc_Bool CT__ti_sysbios_timers_dmtimer_Timer_checkFrequency;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_checkFrequency ti_sysbios_timers_dmtimer_Timer_checkFrequency__C;
#endif

/* startupNeeded */
#ifdef ti_sysbios_timers_dmtimer_Timer_startupNeeded__D
#define ti_sysbios_timers_dmtimer_Timer_startupNeeded (ti_sysbios_timers_dmtimer_Timer_startupNeeded__D)
#else
#define ti_sysbios_timers_dmtimer_Timer_startupNeeded (ti_sysbios_timers_dmtimer_Timer_startupNeeded__C)
typedef xdc_Bool CT__ti_sysbios_timers_dmtimer_Timer_startupNeeded;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_startupNeeded ti_sysbios_timers_dmtimer_Timer_startupNeeded__C;
#endif

/* numTimerDevices */
#ifdef ti_sysbios_timers_dmtimer_Timer_numTimerDevices__D
#define ti_sysbios_timers_dmtimer_Timer_numTimerDevices (ti_sysbios_timers_dmtimer_Timer_numTimerDevices__D)
#else
#define ti_sysbios_timers_dmtimer_Timer_numTimerDevices (ti_sysbios_timers_dmtimer_Timer_numTimerDevices__C)
typedef xdc_Int CT__ti_sysbios_timers_dmtimer_Timer_numTimerDevices;
__extern __FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_numTimerDevices ti_sysbios_timers_dmtimer_Timer_numTimerDevices__C;
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_timers_dmtimer_Timer_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    ti_sysbios_interfaces_ITimer_RunMode runMode;
    ti_sysbios_interfaces_ITimer_StartMode startMode;
    xdc_UArg arg;
    xdc_UInt32 period;
    ti_sysbios_interfaces_ITimer_PeriodType periodType;
    xdc_runtime_Types_FreqHz extFreq;
    ti_sysbios_timers_dmtimer_Timer_TiocpCfg tiocpCfg;
    ti_sysbios_timers_dmtimer_Timer_Tier tier;
    ti_sysbios_timers_dmtimer_Timer_Twer twer;
    ti_sysbios_timers_dmtimer_Timer_Tclr tclr;
    ti_sysbios_timers_dmtimer_Timer_Tsicr tsicr;
    xdc_UInt32 tmar;
    xdc_Int intNum;
    xdc_Int eventId;
    ti_sysbios_hal_Hwi_Params *hwiParams;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_timers_dmtimer_Timer_Struct {
    const ti_sysbios_timers_dmtimer_Timer_Fxns__ *__fxns;
    xdc_Bool __f0;
    xdc_Int __f1;
    xdc_UInt __f2;
    xdc_UInt __f3;
    xdc_UInt __f4;
    xdc_UInt __f5;
    xdc_UInt __f6;
    xdc_UInt __f7;
    ti_sysbios_interfaces_ITimer_RunMode __f8;
    ti_sysbios_interfaces_ITimer_StartMode __f9;
    xdc_UInt __f10;
    ti_sysbios_interfaces_ITimer_PeriodType __f11;
    xdc_UInt __f12;
    xdc_Int __f13;
    xdc_UArg __f14;
    ti_sysbios_hal_Hwi_FuncPtr __f15;
    xdc_runtime_Types_FreqHz __f16;
    ti_sysbios_hal_Hwi_Handle __f17;
    xdc_UInt __f18;
    xdc_UInt __f19;
    xdc_UInt __f20;
    xdc_Bool __f21;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_timers_dmtimer_Timer_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_UInt (*getNumTimers)(void);
    ti_sysbios_interfaces_ITimer_Status (*getStatus)(xdc_UInt);
    xdc_Void (*startup)(void);
    xdc_UInt32 (*getMaxTicks)(ti_sysbios_timers_dmtimer_Timer_Handle);
    xdc_Void (*setNextTick)(ti_sysbios_timers_dmtimer_Timer_Handle, xdc_UInt32);
    xdc_Void (*start)(ti_sysbios_timers_dmtimer_Timer_Handle);
    xdc_Void (*stop)(ti_sysbios_timers_dmtimer_Timer_Handle);
    xdc_Void (*setPeriod)(ti_sysbios_timers_dmtimer_Timer_Handle, xdc_UInt32);
    xdc_Bool (*setPeriodMicroSecs)(ti_sysbios_timers_dmtimer_Timer_Handle, xdc_UInt32);
    xdc_UInt32 (*getPeriod)(ti_sysbios_timers_dmtimer_Timer_Handle);
    xdc_UInt32 (*getCount)(ti_sysbios_timers_dmtimer_Timer_Handle);
    xdc_Void (*getFreq)(ti_sysbios_timers_dmtimer_Timer_Handle, xdc_runtime_Types_FreqHz*);
    ti_sysbios_interfaces_ITimer_FuncPtr (*getFunc)(ti_sysbios_timers_dmtimer_Timer_Handle, xdc_UArg*);
    xdc_Void (*setFunc)(ti_sysbios_timers_dmtimer_Timer_Handle, ti_sysbios_interfaces_ITimer_FuncPtr, xdc_UArg);
    xdc_Void (*trigger)(ti_sysbios_timers_dmtimer_Timer_Handle, xdc_UInt32);
    xdc_UInt32 (*getExpiredCounts)(ti_sysbios_timers_dmtimer_Timer_Handle);
    xdc_UInt32 (*getExpiredTicks)(ti_sysbios_timers_dmtimer_Timer_Handle, xdc_UInt32);
    xdc_UInt32 (*getCurrentTick)(ti_sysbios_timers_dmtimer_Timer_Handle, xdc_Bool);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_timers_dmtimer_Timer_Fxns__ ti_sysbios_timers_dmtimer_Timer_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_timers_dmtimer_Timer_Module_startup ti_sysbios_timers_dmtimer_Timer_Module_startup__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Module_startup__E, "ti_sysbios_timers_dmtimer_Timer_Module_startup")
__extern xdc_Int ti_sysbios_timers_dmtimer_Timer_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Module_startup__F, "ti_sysbios_timers_dmtimer_Timer_Module_startup")
__extern xdc_Int ti_sysbios_timers_dmtimer_Timer_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Instance_init__E, "ti_sysbios_timers_dmtimer_Timer_Instance_init")
__extern xdc_Int ti_sysbios_timers_dmtimer_Timer_Instance_init__E(ti_sysbios_timers_dmtimer_Timer_Object *, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_timers_dmtimer_Timer_Params *, xdc_runtime_Error_Block *);

/* Instance_finalize__E */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Instance_finalize__E, "ti_sysbios_timers_dmtimer_Timer_Instance_finalize")
__extern void ti_sysbios_timers_dmtimer_Timer_Instance_finalize__E( ti_sysbios_timers_dmtimer_Timer_Object* , int );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Handle__label__S, "ti_sysbios_timers_dmtimer_Timer_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_timers_dmtimer_Timer_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Module__startupDone__S, "ti_sysbios_timers_dmtimer_Timer_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_timers_dmtimer_Timer_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Object__create__S, "ti_sysbios_timers_dmtimer_Timer_Object__create__S")
__extern xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_create, "ti_sysbios_timers_dmtimer_Timer_create")
__extern ti_sysbios_timers_dmtimer_Timer_Handle ti_sysbios_timers_dmtimer_Timer_create( xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_timers_dmtimer_Timer_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_construct, "ti_sysbios_timers_dmtimer_Timer_construct")
__extern void ti_sysbios_timers_dmtimer_Timer_construct( ti_sysbios_timers_dmtimer_Timer_Struct *__obj, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_timers_dmtimer_Timer_Params *__prms, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Object__delete__S, "ti_sysbios_timers_dmtimer_Timer_Object__delete__S")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_delete, "ti_sysbios_timers_dmtimer_Timer_delete")
__extern void ti_sysbios_timers_dmtimer_Timer_delete(ti_sysbios_timers_dmtimer_Timer_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Object__destruct__S, "ti_sysbios_timers_dmtimer_Timer_Object__destruct__S")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_destruct, "ti_sysbios_timers_dmtimer_Timer_destruct")
__extern void ti_sysbios_timers_dmtimer_Timer_destruct(ti_sysbios_timers_dmtimer_Timer_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Object__get__S, "ti_sysbios_timers_dmtimer_Timer_Object__get__S")
__extern xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Object__first__S, "ti_sysbios_timers_dmtimer_Timer_Object__first__S")
__extern xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Object__next__S, "ti_sysbios_timers_dmtimer_Timer_Object__next__S")
__extern xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_Params__init__S, "ti_sysbios_timers_dmtimer_Timer_Params__init__S")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* getNumTimers__E */
#define ti_sysbios_timers_dmtimer_Timer_getNumTimers ti_sysbios_timers_dmtimer_Timer_getNumTimers__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getNumTimers__E, "ti_sysbios_timers_dmtimer_Timer_getNumTimers")
__extern xdc_UInt ti_sysbios_timers_dmtimer_Timer_getNumTimers__E( void );

/* getStatus__E */
#define ti_sysbios_timers_dmtimer_Timer_getStatus ti_sysbios_timers_dmtimer_Timer_getStatus__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getStatus__E, "ti_sysbios_timers_dmtimer_Timer_getStatus")
__extern ti_sysbios_interfaces_ITimer_Status ti_sysbios_timers_dmtimer_Timer_getStatus__E( xdc_UInt id );

/* startup__E */
#define ti_sysbios_timers_dmtimer_Timer_startup ti_sysbios_timers_dmtimer_Timer_startup__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_startup__E, "ti_sysbios_timers_dmtimer_Timer_startup")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_startup__E( void );

/* getMaxTicks__E */
#define ti_sysbios_timers_dmtimer_Timer_getMaxTicks ti_sysbios_timers_dmtimer_Timer_getMaxTicks__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getMaxTicks__E, "ti_sysbios_timers_dmtimer_Timer_getMaxTicks")
__extern xdc_UInt32 ti_sysbios_timers_dmtimer_Timer_getMaxTicks__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst );

/* setNextTick__E */
#define ti_sysbios_timers_dmtimer_Timer_setNextTick ti_sysbios_timers_dmtimer_Timer_setNextTick__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_setNextTick__E, "ti_sysbios_timers_dmtimer_Timer_setNextTick")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_setNextTick__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, xdc_UInt32 ticks );

/* start__E */
#define ti_sysbios_timers_dmtimer_Timer_start ti_sysbios_timers_dmtimer_Timer_start__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_start__E, "ti_sysbios_timers_dmtimer_Timer_start")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_start__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst );

/* stop__E */
#define ti_sysbios_timers_dmtimer_Timer_stop ti_sysbios_timers_dmtimer_Timer_stop__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_stop__E, "ti_sysbios_timers_dmtimer_Timer_stop")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_stop__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst );

/* setPeriod__E */
#define ti_sysbios_timers_dmtimer_Timer_setPeriod ti_sysbios_timers_dmtimer_Timer_setPeriod__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_setPeriod__E, "ti_sysbios_timers_dmtimer_Timer_setPeriod")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_setPeriod__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, xdc_UInt32 period );

/* setPeriodMicroSecs__E */
#define ti_sysbios_timers_dmtimer_Timer_setPeriodMicroSecs ti_sysbios_timers_dmtimer_Timer_setPeriodMicroSecs__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_setPeriodMicroSecs__E, "ti_sysbios_timers_dmtimer_Timer_setPeriodMicroSecs")
__extern xdc_Bool ti_sysbios_timers_dmtimer_Timer_setPeriodMicroSecs__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, xdc_UInt32 microsecs );

/* getPeriod__E */
#define ti_sysbios_timers_dmtimer_Timer_getPeriod ti_sysbios_timers_dmtimer_Timer_getPeriod__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getPeriod__E, "ti_sysbios_timers_dmtimer_Timer_getPeriod")
__extern xdc_UInt32 ti_sysbios_timers_dmtimer_Timer_getPeriod__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst );

/* getCount__E */
#define ti_sysbios_timers_dmtimer_Timer_getCount ti_sysbios_timers_dmtimer_Timer_getCount__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getCount__E, "ti_sysbios_timers_dmtimer_Timer_getCount")
__extern xdc_UInt32 ti_sysbios_timers_dmtimer_Timer_getCount__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst );

/* getFreq__E */
#define ti_sysbios_timers_dmtimer_Timer_getFreq ti_sysbios_timers_dmtimer_Timer_getFreq__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getFreq__E, "ti_sysbios_timers_dmtimer_Timer_getFreq")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_getFreq__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, xdc_runtime_Types_FreqHz *freq );

/* getFunc__E */
#define ti_sysbios_timers_dmtimer_Timer_getFunc ti_sysbios_timers_dmtimer_Timer_getFunc__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getFunc__E, "ti_sysbios_timers_dmtimer_Timer_getFunc")
__extern ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_timers_dmtimer_Timer_getFunc__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, xdc_UArg *arg );

/* setFunc__E */
#define ti_sysbios_timers_dmtimer_Timer_setFunc ti_sysbios_timers_dmtimer_Timer_setFunc__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_setFunc__E, "ti_sysbios_timers_dmtimer_Timer_setFunc")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_setFunc__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg );

/* trigger__E */
#define ti_sysbios_timers_dmtimer_Timer_trigger ti_sysbios_timers_dmtimer_Timer_trigger__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_trigger__E, "ti_sysbios_timers_dmtimer_Timer_trigger")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_trigger__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, xdc_UInt32 cycles );

/* getExpiredCounts__E */
#define ti_sysbios_timers_dmtimer_Timer_getExpiredCounts ti_sysbios_timers_dmtimer_Timer_getExpiredCounts__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getExpiredCounts__E, "ti_sysbios_timers_dmtimer_Timer_getExpiredCounts")
__extern xdc_UInt32 ti_sysbios_timers_dmtimer_Timer_getExpiredCounts__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst );

/* getExpiredTicks__E */
#define ti_sysbios_timers_dmtimer_Timer_getExpiredTicks ti_sysbios_timers_dmtimer_Timer_getExpiredTicks__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getExpiredTicks__E, "ti_sysbios_timers_dmtimer_Timer_getExpiredTicks")
__extern xdc_UInt32 ti_sysbios_timers_dmtimer_Timer_getExpiredTicks__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, xdc_UInt32 tickPeriod );

/* getCurrentTick__E */
#define ti_sysbios_timers_dmtimer_Timer_getCurrentTick ti_sysbios_timers_dmtimer_Timer_getCurrentTick__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getCurrentTick__E, "ti_sysbios_timers_dmtimer_Timer_getCurrentTick")
__extern xdc_UInt32 ti_sysbios_timers_dmtimer_Timer_getCurrentTick__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, xdc_Bool save );

/* stub__E */
#define ti_sysbios_timers_dmtimer_Timer_stub ti_sysbios_timers_dmtimer_Timer_stub__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_stub__E, "ti_sysbios_timers_dmtimer_Timer_stub")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_stub__E( xdc_UArg arg );

/* dynStub__E */
#define ti_sysbios_timers_dmtimer_Timer_dynStub ti_sysbios_timers_dmtimer_Timer_dynStub__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_dynStub__E, "ti_sysbios_timers_dmtimer_Timer_dynStub")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_dynStub__E( xdc_UArg arg );

/* getHandle__E */
#define ti_sysbios_timers_dmtimer_Timer_getHandle ti_sysbios_timers_dmtimer_Timer_getHandle__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getHandle__E, "ti_sysbios_timers_dmtimer_Timer_getHandle")
__extern ti_sysbios_timers_dmtimer_Timer_Handle ti_sysbios_timers_dmtimer_Timer_getHandle__E( xdc_UInt id );

/* reconfig__E */
#define ti_sysbios_timers_dmtimer_Timer_reconfig ti_sysbios_timers_dmtimer_Timer_reconfig__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_reconfig__E, "ti_sysbios_timers_dmtimer_Timer_reconfig")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_reconfig__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, ti_sysbios_timers_dmtimer_Timer_FuncPtr tickFxn, const ti_sysbios_timers_dmtimer_Timer_Params *timerParams, xdc_runtime_Error_Block *eb );

/* getRollovers__E */
#define ti_sysbios_timers_dmtimer_Timer_getRollovers ti_sysbios_timers_dmtimer_Timer_getRollovers__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getRollovers__E, "ti_sysbios_timers_dmtimer_Timer_getRollovers")
__extern xdc_UInt32 ti_sysbios_timers_dmtimer_Timer_getRollovers__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst );

/* enableTimestamping__E */
#define ti_sysbios_timers_dmtimer_Timer_enableTimestamping ti_sysbios_timers_dmtimer_Timer_enableTimestamping__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_enableTimestamping__E, "ti_sysbios_timers_dmtimer_Timer_enableTimestamping")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_enableTimestamping__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst );

/* restoreRegisters__E */
#define ti_sysbios_timers_dmtimer_Timer_restoreRegisters ti_sysbios_timers_dmtimer_Timer_restoreRegisters__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_restoreRegisters__E, "ti_sysbios_timers_dmtimer_Timer_restoreRegisters")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_restoreRegisters__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst, xdc_runtime_Error_Block *eb );

/* getIntNum__E */
#define ti_sysbios_timers_dmtimer_Timer_getIntNum ti_sysbios_timers_dmtimer_Timer_getIntNum__E
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getIntNum__E, "ti_sysbios_timers_dmtimer_Timer_getIntNum")
__extern xdc_Int ti_sysbios_timers_dmtimer_Timer_getIntNum__E( ti_sysbios_timers_dmtimer_Timer_Handle __inst );

/* deviceConfig__I */
#define ti_sysbios_timers_dmtimer_Timer_deviceConfig ti_sysbios_timers_dmtimer_Timer_deviceConfig__I
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_deviceConfig__I, "ti_sysbios_timers_dmtimer_Timer_deviceConfig")
__extern xdc_Int ti_sysbios_timers_dmtimer_Timer_deviceConfig__I( ti_sysbios_timers_dmtimer_Timer_Object *timer, xdc_runtime_Error_Block *eb );

/* initDevice__I */
#define ti_sysbios_timers_dmtimer_Timer_initDevice ti_sysbios_timers_dmtimer_Timer_initDevice__I
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_initDevice__I, "ti_sysbios_timers_dmtimer_Timer_initDevice")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_initDevice__I( ti_sysbios_timers_dmtimer_Timer_Object *timer, xdc_runtime_Error_Block *eb );

/* initObj__I */
#define ti_sysbios_timers_dmtimer_Timer_initObj ti_sysbios_timers_dmtimer_Timer_initObj__I
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_initObj__I, "ti_sysbios_timers_dmtimer_Timer_initObj")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_initObj__I( ti_sysbios_timers_dmtimer_Timer_Object *timer, ti_sysbios_timers_dmtimer_Timer_FuncPtr tickFxn, const ti_sysbios_timers_dmtimer_Timer_Params *timerParams );

/* postInit__I */
#define ti_sysbios_timers_dmtimer_Timer_postInit ti_sysbios_timers_dmtimer_Timer_postInit__I
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_postInit__I, "ti_sysbios_timers_dmtimer_Timer_postInit")
__extern xdc_Int ti_sysbios_timers_dmtimer_Timer_postInit__I( ti_sysbios_timers_dmtimer_Timer_Object *timer, xdc_runtime_Error_Block *eb );

/* checkOverflow__I */
#define ti_sysbios_timers_dmtimer_Timer_checkOverflow ti_sysbios_timers_dmtimer_Timer_checkOverflow__I
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_checkOverflow__I, "ti_sysbios_timers_dmtimer_Timer_checkOverflow")
__extern xdc_Bool ti_sysbios_timers_dmtimer_Timer_checkOverflow__I( xdc_UInt32 a, xdc_UInt32 b );

/* getNextAvailableTimerId__I */
#define ti_sysbios_timers_dmtimer_Timer_getNextAvailableTimerId ti_sysbios_timers_dmtimer_Timer_getNextAvailableTimerId__I
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_getNextAvailableTimerId__I, "ti_sysbios_timers_dmtimer_Timer_getNextAvailableTimerId")
__extern xdc_UInt ti_sysbios_timers_dmtimer_Timer_getNextAvailableTimerId__I( ti_sysbios_timers_dmtimer_Timer_Object *timer );

/* spinLoop__I */
#define ti_sysbios_timers_dmtimer_Timer_spinLoop ti_sysbios_timers_dmtimer_Timer_spinLoop__I
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_spinLoop__I, "ti_sysbios_timers_dmtimer_Timer_spinLoop")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_spinLoop__I( xdc_UInt count );

/* checkFreq__I */
#define ti_sysbios_timers_dmtimer_Timer_checkFreq ti_sysbios_timers_dmtimer_Timer_checkFreq__I
xdc__CODESECT(ti_sysbios_timers_dmtimer_Timer_checkFreq__I, "ti_sysbios_timers_dmtimer_Timer_checkFreq")
__extern xdc_Void ti_sysbios_timers_dmtimer_Timer_checkFreq__I( ti_sysbios_timers_dmtimer_Timer_Object *obj );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_ITimer_Module ti_sysbios_timers_dmtimer_Timer_Module_upCast( void )
{
    return (ti_sysbios_interfaces_ITimer_Module)&ti_sysbios_timers_dmtimer_Timer_Module__FXNS__C;
}

/* Module_to_ti_sysbios_interfaces_ITimer */
#define ti_sysbios_timers_dmtimer_Timer_Module_to_ti_sysbios_interfaces_ITimer ti_sysbios_timers_dmtimer_Timer_Module_upCast

/* Handle_upCast */
static inline ti_sysbios_interfaces_ITimer_Handle ti_sysbios_timers_dmtimer_Timer_Handle_upCast( ti_sysbios_timers_dmtimer_Timer_Handle i )
{
    return (ti_sysbios_interfaces_ITimer_Handle)i;
}

/* Handle_to_ti_sysbios_interfaces_ITimer */
#define ti_sysbios_timers_dmtimer_Timer_Handle_to_ti_sysbios_interfaces_ITimer ti_sysbios_timers_dmtimer_Timer_Handle_upCast

/* Handle_downCast */
static inline ti_sysbios_timers_dmtimer_Timer_Handle ti_sysbios_timers_dmtimer_Timer_Handle_downCast( ti_sysbios_interfaces_ITimer_Handle i )
{
    ti_sysbios_interfaces_ITimer_Handle i2 = (ti_sysbios_interfaces_ITimer_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sysbios_timers_dmtimer_Timer_Module__FXNS__C ? (ti_sysbios_timers_dmtimer_Timer_Handle)i : 0;
}

/* Handle_from_ti_sysbios_interfaces_ITimer */
#define ti_sysbios_timers_dmtimer_Timer_Handle_from_ti_sysbios_interfaces_ITimer ti_sysbios_timers_dmtimer_Timer_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_timers_dmtimer_Timer_Module_startupDone() ti_sysbios_timers_dmtimer_Timer_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_timers_dmtimer_Timer_Object_heap() ti_sysbios_timers_dmtimer_Timer_Object__heap__C

/* Module_heap */
#define ti_sysbios_timers_dmtimer_Timer_Module_heap() ti_sysbios_timers_dmtimer_Timer_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_timers_dmtimer_Timer_Module__id ti_sysbios_timers_dmtimer_Timer_Module_id( void ) 
{
    return ti_sysbios_timers_dmtimer_Timer_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_timers_dmtimer_Timer_Module_hasMask( void ) 
{
    return ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_timers_dmtimer_Timer_Module_getMask( void ) 
{
    return ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C != NULL ? *ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_timers_dmtimer_Timer_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C != NULL) *ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_timers_dmtimer_Timer_Params_init( ti_sysbios_timers_dmtimer_Timer_Params *prms ) 
{
    if (prms) {
        ti_sysbios_timers_dmtimer_Timer_Params__init__S(prms, 0, sizeof(ti_sysbios_timers_dmtimer_Timer_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_timers_dmtimer_Timer_Params_copy(ti_sysbios_timers_dmtimer_Timer_Params *dst, const ti_sysbios_timers_dmtimer_Timer_Params *src) 
{
    if (dst) {
        ti_sysbios_timers_dmtimer_Timer_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_timers_dmtimer_Timer_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_timers_dmtimer_Timer_Object_count() ti_sysbios_timers_dmtimer_Timer_Object__count__C

/* Object_sizeof */
#define ti_sysbios_timers_dmtimer_Timer_Object_sizeof() ti_sysbios_timers_dmtimer_Timer_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_timers_dmtimer_Timer_Handle ti_sysbios_timers_dmtimer_Timer_Object_get(ti_sysbios_timers_dmtimer_Timer_Instance_State *oarr, int i) 
{
    return (ti_sysbios_timers_dmtimer_Timer_Handle)ti_sysbios_timers_dmtimer_Timer_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_timers_dmtimer_Timer_Handle ti_sysbios_timers_dmtimer_Timer_Object_first( void )
{
    return (ti_sysbios_timers_dmtimer_Timer_Handle)ti_sysbios_timers_dmtimer_Timer_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_timers_dmtimer_Timer_Handle ti_sysbios_timers_dmtimer_Timer_Object_next( ti_sysbios_timers_dmtimer_Timer_Object *obj )
{
    return (ti_sysbios_timers_dmtimer_Timer_Handle)ti_sysbios_timers_dmtimer_Timer_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_timers_dmtimer_Timer_Handle_label( ti_sysbios_timers_dmtimer_Timer_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_timers_dmtimer_Timer_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_timers_dmtimer_Timer_Handle_name( ti_sysbios_timers_dmtimer_Timer_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_timers_dmtimer_Timer_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_timers_dmtimer_Timer_Handle ti_sysbios_timers_dmtimer_Timer_handle( ti_sysbios_timers_dmtimer_Timer_Struct *str )
{
    return (ti_sysbios_timers_dmtimer_Timer_Handle)str;
}

/* struct */
static inline ti_sysbios_timers_dmtimer_Timer_Struct *ti_sysbios_timers_dmtimer_Timer_struct( ti_sysbios_timers_dmtimer_Timer_Handle inst )
{
    return (ti_sysbios_timers_dmtimer_Timer_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_timers_dmtimer_Timer__top__
#undef __nested__
#endif

#endif /* ti_sysbios_timers_dmtimer_Timer__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_timers_dmtimer_Timer__internalaccess))

#ifndef ti_sysbios_timers_dmtimer_Timer__include_state
#define ti_sysbios_timers_dmtimer_Timer__include_state

/* Module_State */
struct ti_sysbios_timers_dmtimer_Timer_Module_State {
    xdc_Bits32 availMask;
    __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__intFreqs intFreqs;
    __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__device device;
    __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__handles handles;
    xdc_Bool firstInit;
};

/* Module__state__V */
extern struct ti_sysbios_timers_dmtimer_Timer_Module_State__ ti_sysbios_timers_dmtimer_Timer_Module__state__V;

/* Object */
struct ti_sysbios_timers_dmtimer_Timer_Object {
    const ti_sysbios_timers_dmtimer_Timer_Fxns__ *__fxns;
    xdc_Bool staticInst;
    xdc_Int id;
    xdc_UInt tiocpCfg;
    xdc_UInt tmar;
    xdc_UInt tier;
    xdc_UInt twer;
    xdc_UInt tclr;
    xdc_UInt tsicr;
    ti_sysbios_interfaces_ITimer_RunMode runMode;
    ti_sysbios_interfaces_ITimer_StartMode startMode;
    xdc_UInt period;
    ti_sysbios_interfaces_ITimer_PeriodType periodType;
    xdc_UInt intNum;
    xdc_Int eventId;
    xdc_UArg arg;
    ti_sysbios_hal_Hwi_FuncPtr tickFxn;
    xdc_runtime_Types_FreqHz extFreq;
    ti_sysbios_hal_Hwi_Handle hwi;
    xdc_UInt prevThreshold;
    xdc_UInt rollovers;
    xdc_UInt savedCurrCount;
    xdc_Bool useDefaultEventId;
};

#endif /* ti_sysbios_timers_dmtimer_Timer__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_timers_dmtimer_Timer__nolocalnames)

#ifndef ti_sysbios_timers_dmtimer_Timer__localnames__done
#define ti_sysbios_timers_dmtimer_Timer__localnames__done

/* module prefix */
#define Timer_Instance ti_sysbios_timers_dmtimer_Timer_Instance
#define Timer_Handle ti_sysbios_timers_dmtimer_Timer_Handle
#define Timer_Module ti_sysbios_timers_dmtimer_Timer_Module
#define Timer_Object ti_sysbios_timers_dmtimer_Timer_Object
#define Timer_Struct ti_sysbios_timers_dmtimer_Timer_Struct
#define Timer_FuncPtr ti_sysbios_timers_dmtimer_Timer_FuncPtr
#define Timer_ANY ti_sysbios_timers_dmtimer_Timer_ANY
#define Timer_StartMode ti_sysbios_timers_dmtimer_Timer_StartMode
#define Timer_RunMode ti_sysbios_timers_dmtimer_Timer_RunMode
#define Timer_Status ti_sysbios_timers_dmtimer_Timer_Status
#define Timer_PeriodType ti_sysbios_timers_dmtimer_Timer_PeriodType
#define Timer_MAX_PERIOD ti_sysbios_timers_dmtimer_Timer_MAX_PERIOD
#define Timer_TiocpCfg ti_sysbios_timers_dmtimer_Timer_TiocpCfg
#define Timer_Tier ti_sysbios_timers_dmtimer_Timer_Tier
#define Timer_Twer ti_sysbios_timers_dmtimer_Timer_Twer
#define Timer_Tclr ti_sysbios_timers_dmtimer_Timer_Tclr
#define Timer_Tsicr ti_sysbios_timers_dmtimer_Timer_Tsicr
#define Timer_TimerDevice ti_sysbios_timers_dmtimer_Timer_TimerDevice
#define Timer_Instance_State ti_sysbios_timers_dmtimer_Timer_Instance_State
#define Timer_Module_State ti_sysbios_timers_dmtimer_Timer_Module_State
#define Timer_StartMode_AUTO ti_sysbios_timers_dmtimer_Timer_StartMode_AUTO
#define Timer_StartMode_USER ti_sysbios_timers_dmtimer_Timer_StartMode_USER
#define Timer_RunMode_CONTINUOUS ti_sysbios_timers_dmtimer_Timer_RunMode_CONTINUOUS
#define Timer_RunMode_ONESHOT ti_sysbios_timers_dmtimer_Timer_RunMode_ONESHOT
#define Timer_RunMode_DYNAMIC ti_sysbios_timers_dmtimer_Timer_RunMode_DYNAMIC
#define Timer_Status_INUSE ti_sysbios_timers_dmtimer_Timer_Status_INUSE
#define Timer_Status_FREE ti_sysbios_timers_dmtimer_Timer_Status_FREE
#define Timer_PeriodType_MICROSECS ti_sysbios_timers_dmtimer_Timer_PeriodType_MICROSECS
#define Timer_PeriodType_COUNTS ti_sysbios_timers_dmtimer_Timer_PeriodType_COUNTS
#define Timer_A_notAvailable ti_sysbios_timers_dmtimer_Timer_A_notAvailable
#define Timer_E_invalidTimer ti_sysbios_timers_dmtimer_Timer_E_invalidTimer
#define Timer_E_notAvailable ti_sysbios_timers_dmtimer_Timer_E_notAvailable
#define Timer_E_cannotSupport ti_sysbios_timers_dmtimer_Timer_E_cannotSupport
#define Timer_E_freqMismatch ti_sysbios_timers_dmtimer_Timer_E_freqMismatch
#define Timer_E_badIntNum ti_sysbios_timers_dmtimer_Timer_E_badIntNum
#define Timer_anyMask ti_sysbios_timers_dmtimer_Timer_anyMask
#define Timer_checkFrequency ti_sysbios_timers_dmtimer_Timer_checkFrequency
#define Timer_startupNeeded ti_sysbios_timers_dmtimer_Timer_startupNeeded
#define Timer_numTimerDevices ti_sysbios_timers_dmtimer_Timer_numTimerDevices
#define Timer_Params ti_sysbios_timers_dmtimer_Timer_Params
#define Timer_getNumTimers ti_sysbios_timers_dmtimer_Timer_getNumTimers
#define Timer_getStatus ti_sysbios_timers_dmtimer_Timer_getStatus
#define Timer_startup ti_sysbios_timers_dmtimer_Timer_startup
#define Timer_getMaxTicks ti_sysbios_timers_dmtimer_Timer_getMaxTicks
#define Timer_setNextTick ti_sysbios_timers_dmtimer_Timer_setNextTick
#define Timer_start ti_sysbios_timers_dmtimer_Timer_start
#define Timer_stop ti_sysbios_timers_dmtimer_Timer_stop
#define Timer_setPeriod ti_sysbios_timers_dmtimer_Timer_setPeriod
#define Timer_setPeriodMicroSecs ti_sysbios_timers_dmtimer_Timer_setPeriodMicroSecs
#define Timer_getPeriod ti_sysbios_timers_dmtimer_Timer_getPeriod
#define Timer_getCount ti_sysbios_timers_dmtimer_Timer_getCount
#define Timer_getFreq ti_sysbios_timers_dmtimer_Timer_getFreq
#define Timer_getFunc ti_sysbios_timers_dmtimer_Timer_getFunc
#define Timer_setFunc ti_sysbios_timers_dmtimer_Timer_setFunc
#define Timer_trigger ti_sysbios_timers_dmtimer_Timer_trigger
#define Timer_getExpiredCounts ti_sysbios_timers_dmtimer_Timer_getExpiredCounts
#define Timer_getExpiredTicks ti_sysbios_timers_dmtimer_Timer_getExpiredTicks
#define Timer_getCurrentTick ti_sysbios_timers_dmtimer_Timer_getCurrentTick
#define Timer_stub ti_sysbios_timers_dmtimer_Timer_stub
#define Timer_dynStub ti_sysbios_timers_dmtimer_Timer_dynStub
#define Timer_getHandle ti_sysbios_timers_dmtimer_Timer_getHandle
#define Timer_reconfig ti_sysbios_timers_dmtimer_Timer_reconfig
#define Timer_getRollovers ti_sysbios_timers_dmtimer_Timer_getRollovers
#define Timer_enableTimestamping ti_sysbios_timers_dmtimer_Timer_enableTimestamping
#define Timer_restoreRegisters ti_sysbios_timers_dmtimer_Timer_restoreRegisters
#define Timer_getIntNum ti_sysbios_timers_dmtimer_Timer_getIntNum
#define Timer_Module_name ti_sysbios_timers_dmtimer_Timer_Module_name
#define Timer_Module_id ti_sysbios_timers_dmtimer_Timer_Module_id
#define Timer_Module_startup ti_sysbios_timers_dmtimer_Timer_Module_startup
#define Timer_Module_startupDone ti_sysbios_timers_dmtimer_Timer_Module_startupDone
#define Timer_Module_hasMask ti_sysbios_timers_dmtimer_Timer_Module_hasMask
#define Timer_Module_getMask ti_sysbios_timers_dmtimer_Timer_Module_getMask
#define Timer_Module_setMask ti_sysbios_timers_dmtimer_Timer_Module_setMask
#define Timer_Object_heap ti_sysbios_timers_dmtimer_Timer_Object_heap
#define Timer_Module_heap ti_sysbios_timers_dmtimer_Timer_Module_heap
#define Timer_construct ti_sysbios_timers_dmtimer_Timer_construct
#define Timer_create ti_sysbios_timers_dmtimer_Timer_create
#define Timer_handle ti_sysbios_timers_dmtimer_Timer_handle
#define Timer_struct ti_sysbios_timers_dmtimer_Timer_struct
#define Timer_Handle_label ti_sysbios_timers_dmtimer_Timer_Handle_label
#define Timer_Handle_name ti_sysbios_timers_dmtimer_Timer_Handle_name
#define Timer_Instance_init ti_sysbios_timers_dmtimer_Timer_Instance_init
#define Timer_Object_count ti_sysbios_timers_dmtimer_Timer_Object_count
#define Timer_Object_get ti_sysbios_timers_dmtimer_Timer_Object_get
#define Timer_Object_first ti_sysbios_timers_dmtimer_Timer_Object_first
#define Timer_Object_next ti_sysbios_timers_dmtimer_Timer_Object_next
#define Timer_Object_sizeof ti_sysbios_timers_dmtimer_Timer_Object_sizeof
#define Timer_Params_copy ti_sysbios_timers_dmtimer_Timer_Params_copy
#define Timer_Params_init ti_sysbios_timers_dmtimer_Timer_Params_init
#define Timer_Instance_finalize ti_sysbios_timers_dmtimer_Timer_Instance_finalize
#define Timer_delete ti_sysbios_timers_dmtimer_Timer_delete
#define Timer_destruct ti_sysbios_timers_dmtimer_Timer_destruct
#define Timer_Module_upCast ti_sysbios_timers_dmtimer_Timer_Module_upCast
#define Timer_Module_to_ti_sysbios_interfaces_ITimer ti_sysbios_timers_dmtimer_Timer_Module_to_ti_sysbios_interfaces_ITimer
#define Timer_Handle_upCast ti_sysbios_timers_dmtimer_Timer_Handle_upCast
#define Timer_Handle_to_ti_sysbios_interfaces_ITimer ti_sysbios_timers_dmtimer_Timer_Handle_to_ti_sysbios_interfaces_ITimer
#define Timer_Handle_downCast ti_sysbios_timers_dmtimer_Timer_Handle_downCast
#define Timer_Handle_from_ti_sysbios_interfaces_ITimer ti_sysbios_timers_dmtimer_Timer_Handle_from_ti_sysbios_interfaces_ITimer

/* proxies */
#include <ti/sysbios/timers/dmtimer/package/Timer_TimerSupportProxy.h>

#endif /* ti_sysbios_timers_dmtimer_Timer__localnames__done */
#endif
