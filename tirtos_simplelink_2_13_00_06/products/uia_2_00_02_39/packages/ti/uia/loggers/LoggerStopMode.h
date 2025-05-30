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

#ifndef ti_uia_loggers_LoggerStopMode__include
#define ti_uia_loggers_LoggerStopMode__include

#ifndef __nested__
#define __nested__
#define ti_uia_loggers_LoggerStopMode__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_uia_loggers_LoggerStopMode___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/uia/loggers/LoggerStopMode__prologue.h>
#include <ti/uia/loggers/package/package.defs.h>

#include <xdc/runtime/ILogger.h>
#include <ti/uia/runtime/ILoggerSnapshot.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Error.h>
#include <ti/uia/runtime/EventHdr.h>
#include <xdc/runtime/IFilterLogger.h>
#include <xdc/runtime/IHeap.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* TransferType */
typedef ti_uia_runtime_IUIATransfer_TransferType ti_uia_loggers_LoggerStopMode_TransferType;

/* Priority */
typedef ti_uia_runtime_IUIATransfer_Priority ti_uia_loggers_LoggerStopMode_Priority;

/* TransferType_RELIABLE */
#define ti_uia_loggers_LoggerStopMode_TransferType_RELIABLE ti_uia_runtime_IUIATransfer_TransferType_RELIABLE

/* TransferType_LOSSY */
#define ti_uia_loggers_LoggerStopMode_TransferType_LOSSY ti_uia_runtime_IUIATransfer_TransferType_LOSSY

/* Priority_LOW */
#define ti_uia_loggers_LoggerStopMode_Priority_LOW ti_uia_runtime_IUIATransfer_Priority_LOW

/* Priority_STANDARD */
#define ti_uia_loggers_LoggerStopMode_Priority_STANDARD ti_uia_runtime_IUIATransfer_Priority_STANDARD

/* Priority_HIGH */
#define ti_uia_loggers_LoggerStopMode_Priority_HIGH ti_uia_runtime_IUIATransfer_Priority_HIGH

/* Priority_SYNC */
#define ti_uia_loggers_LoggerStopMode_Priority_SYNC ti_uia_runtime_IUIATransfer_Priority_SYNC


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* Instance_State */
typedef xdc_Char __T1_ti_uia_loggers_LoggerStopMode_Instance_State__hdr;
typedef xdc_Char *__ARRAY1_ti_uia_loggers_LoggerStopMode_Instance_State__hdr;
typedef __ARRAY1_ti_uia_loggers_LoggerStopMode_Instance_State__hdr __TA_ti_uia_loggers_LoggerStopMode_Instance_State__hdr;
typedef xdc_Char __T1_ti_uia_loggers_LoggerStopMode_Instance_State__packetArray;
typedef xdc_Char *__ARRAY1_ti_uia_loggers_LoggerStopMode_Instance_State__packetArray;
typedef __ARRAY1_ti_uia_loggers_LoggerStopMode_Instance_State__packetArray __TA_ti_uia_loggers_LoggerStopMode_Instance_State__packetArray;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_uia_loggers_LoggerStopMode_Module__diagsEnabled;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__diagsEnabled ti_uia_loggers_LoggerStopMode_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_uia_loggers_LoggerStopMode_Module__diagsIncluded;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__diagsIncluded ti_uia_loggers_LoggerStopMode_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_uia_loggers_LoggerStopMode_Module__diagsMask;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__diagsMask ti_uia_loggers_LoggerStopMode_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_uia_loggers_LoggerStopMode_Module__gateObj;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__gateObj ti_uia_loggers_LoggerStopMode_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_uia_loggers_LoggerStopMode_Module__gatePrms;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__gatePrms ti_uia_loggers_LoggerStopMode_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_uia_loggers_LoggerStopMode_Module__id;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__id ti_uia_loggers_LoggerStopMode_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_uia_loggers_LoggerStopMode_Module__loggerDefined;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__loggerDefined ti_uia_loggers_LoggerStopMode_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_uia_loggers_LoggerStopMode_Module__loggerObj;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__loggerObj ti_uia_loggers_LoggerStopMode_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_uia_loggers_LoggerStopMode_Module__loggerFxn0;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__loggerFxn0 ti_uia_loggers_LoggerStopMode_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_uia_loggers_LoggerStopMode_Module__loggerFxn1;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__loggerFxn1 ti_uia_loggers_LoggerStopMode_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_uia_loggers_LoggerStopMode_Module__loggerFxn2;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__loggerFxn2 ti_uia_loggers_LoggerStopMode_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_uia_loggers_LoggerStopMode_Module__loggerFxn4;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__loggerFxn4 ti_uia_loggers_LoggerStopMode_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_uia_loggers_LoggerStopMode_Module__loggerFxn8;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__loggerFxn8 ti_uia_loggers_LoggerStopMode_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_uia_loggers_LoggerStopMode_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Module__startupDoneFxn ti_uia_loggers_LoggerStopMode_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_uia_loggers_LoggerStopMode_Object__count;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Object__count ti_uia_loggers_LoggerStopMode_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_uia_loggers_LoggerStopMode_Object__heap;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Object__heap ti_uia_loggers_LoggerStopMode_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_uia_loggers_LoggerStopMode_Object__sizeof;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Object__sizeof ti_uia_loggers_LoggerStopMode_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_uia_loggers_LoggerStopMode_Object__table;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_Object__table ti_uia_loggers_LoggerStopMode_Object__table__C;

/* filterByLevel */
#ifdef ti_uia_loggers_LoggerStopMode_filterByLevel__D
#define ti_uia_loggers_LoggerStopMode_filterByLevel (ti_uia_loggers_LoggerStopMode_filterByLevel__D)
#else
#define ti_uia_loggers_LoggerStopMode_filterByLevel (ti_uia_loggers_LoggerStopMode_filterByLevel__C)
typedef xdc_Bool CT__ti_uia_loggers_LoggerStopMode_filterByLevel;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_filterByLevel ti_uia_loggers_LoggerStopMode_filterByLevel__C;
#endif

/* isTimestampEnabled */
#ifdef ti_uia_loggers_LoggerStopMode_isTimestampEnabled__D
#define ti_uia_loggers_LoggerStopMode_isTimestampEnabled (ti_uia_loggers_LoggerStopMode_isTimestampEnabled__D)
#else
#define ti_uia_loggers_LoggerStopMode_isTimestampEnabled (ti_uia_loggers_LoggerStopMode_isTimestampEnabled__C)
typedef xdc_Bool CT__ti_uia_loggers_LoggerStopMode_isTimestampEnabled;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_isTimestampEnabled ti_uia_loggers_LoggerStopMode_isTimestampEnabled__C;
#endif

/* supportLoggerDisable */
#ifdef ti_uia_loggers_LoggerStopMode_supportLoggerDisable__D
#define ti_uia_loggers_LoggerStopMode_supportLoggerDisable (ti_uia_loggers_LoggerStopMode_supportLoggerDisable__D)
#else
#define ti_uia_loggers_LoggerStopMode_supportLoggerDisable (ti_uia_loggers_LoggerStopMode_supportLoggerDisable__C)
typedef xdc_Bool CT__ti_uia_loggers_LoggerStopMode_supportLoggerDisable;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_supportLoggerDisable ti_uia_loggers_LoggerStopMode_supportLoggerDisable__C;
#endif

/* level1Mask */
#ifdef ti_uia_loggers_LoggerStopMode_level1Mask__D
#define ti_uia_loggers_LoggerStopMode_level1Mask (ti_uia_loggers_LoggerStopMode_level1Mask__D)
#else
#define ti_uia_loggers_LoggerStopMode_level1Mask (ti_uia_loggers_LoggerStopMode_level1Mask__C)
typedef xdc_runtime_Diags_Mask CT__ti_uia_loggers_LoggerStopMode_level1Mask;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_level1Mask ti_uia_loggers_LoggerStopMode_level1Mask__C;
#endif

/* level2Mask */
#ifdef ti_uia_loggers_LoggerStopMode_level2Mask__D
#define ti_uia_loggers_LoggerStopMode_level2Mask (ti_uia_loggers_LoggerStopMode_level2Mask__D)
#else
#define ti_uia_loggers_LoggerStopMode_level2Mask (ti_uia_loggers_LoggerStopMode_level2Mask__C)
typedef xdc_runtime_Diags_Mask CT__ti_uia_loggers_LoggerStopMode_level2Mask;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_level2Mask ti_uia_loggers_LoggerStopMode_level2Mask__C;
#endif

/* level3Mask */
#ifdef ti_uia_loggers_LoggerStopMode_level3Mask__D
#define ti_uia_loggers_LoggerStopMode_level3Mask (ti_uia_loggers_LoggerStopMode_level3Mask__D)
#else
#define ti_uia_loggers_LoggerStopMode_level3Mask (ti_uia_loggers_LoggerStopMode_level3Mask__C)
typedef xdc_runtime_Diags_Mask CT__ti_uia_loggers_LoggerStopMode_level3Mask;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_level3Mask ti_uia_loggers_LoggerStopMode_level3Mask__C;
#endif

/* level4Mask */
#ifdef ti_uia_loggers_LoggerStopMode_level4Mask__D
#define ti_uia_loggers_LoggerStopMode_level4Mask (ti_uia_loggers_LoggerStopMode_level4Mask__D)
#else
#define ti_uia_loggers_LoggerStopMode_level4Mask (ti_uia_loggers_LoggerStopMode_level4Mask__C)
typedef xdc_runtime_Diags_Mask CT__ti_uia_loggers_LoggerStopMode_level4Mask;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_level4Mask ti_uia_loggers_LoggerStopMode_level4Mask__C;
#endif

/* L_test */
#define ti_uia_loggers_LoggerStopMode_L_test (ti_uia_loggers_LoggerStopMode_L_test__C)
typedef xdc_runtime_Log_Event CT__ti_uia_loggers_LoggerStopMode_L_test;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_L_test ti_uia_loggers_LoggerStopMode_L_test__C;

/* E_badLevel */
#define ti_uia_loggers_LoggerStopMode_E_badLevel (ti_uia_loggers_LoggerStopMode_E_badLevel__C)
typedef xdc_runtime_Error_Id CT__ti_uia_loggers_LoggerStopMode_E_badLevel;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_E_badLevel ti_uia_loggers_LoggerStopMode_E_badLevel__C;

/* numCores */
#ifdef ti_uia_loggers_LoggerStopMode_numCores__D
#define ti_uia_loggers_LoggerStopMode_numCores (ti_uia_loggers_LoggerStopMode_numCores__D)
#else
#define ti_uia_loggers_LoggerStopMode_numCores (ti_uia_loggers_LoggerStopMode_numCores__C)
typedef xdc_Int CT__ti_uia_loggers_LoggerStopMode_numCores;
__extern __FAR__ const CT__ti_uia_loggers_LoggerStopMode_numCores ti_uia_loggers_LoggerStopMode_numCores__C;
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_uia_loggers_LoggerStopMode_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    ti_uia_runtime_IUIATransfer_TransferType transferType;
    ti_uia_runtime_IUIATransfer_Priority priority;
    xdc_Int16 instanceId;
    xdc_SizeT transferBufSize;
    xdc_SizeT maxEventSize;
    xdc_SizeT bufSize;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_uia_loggers_LoggerStopMode_Struct {
    const ti_uia_loggers_LoggerStopMode_Fxns__ *__fxns;
    xdc_Bool __f0;
    xdc_Int16 __f1;
    xdc_UInt32 __f2;
    xdc_UInt32 *__f3;
    xdc_UInt32 *__f4;
    xdc_UInt32 *__f5;
    xdc_SizeT __f6;
    xdc_SizeT __f7;
    xdc_UInt16 __f8;
    xdc_Bits32 __f9;
    xdc_UInt16 __f10;
    xdc_UInt16 __f11;
    __TA_ti_uia_loggers_LoggerStopMode_Instance_State__hdr __f12;
    __TA_ti_uia_loggers_LoggerStopMode_Instance_State__packetArray __f13;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_uia_loggers_LoggerStopMode_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bool (*enable)(ti_uia_loggers_LoggerStopMode_Handle);
    xdc_Bool (*disable)(ti_uia_loggers_LoggerStopMode_Handle);
    xdc_Void (*write0)(ti_uia_loggers_LoggerStopMode_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId);
    xdc_Void (*write1)(ti_uia_loggers_LoggerStopMode_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg);
    xdc_Void (*write2)(ti_uia_loggers_LoggerStopMode_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg);
    xdc_Void (*write4)(ti_uia_loggers_LoggerStopMode_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg);
    xdc_Void (*write8)(ti_uia_loggers_LoggerStopMode_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg);
    xdc_Void (*setFilterLevel)(ti_uia_loggers_LoggerStopMode_Handle, xdc_runtime_Diags_Mask, xdc_runtime_Diags_EventLevel);
    xdc_runtime_Diags_Mask (*getFilterLevel)(ti_uia_loggers_LoggerStopMode_Handle, xdc_runtime_Diags_EventLevel);
    ti_uia_runtime_IUIATransfer_TransferType (*getTransferType)(ti_uia_loggers_LoggerStopMode_Handle);
    xdc_Bool (*getContents)(ti_uia_loggers_LoggerStopMode_Handle, xdc_Ptr, xdc_SizeT, xdc_SizeT*);
    xdc_Bool (*isEmpty)(ti_uia_loggers_LoggerStopMode_Handle);
    xdc_SizeT (*getMaxLength)(ti_uia_loggers_LoggerStopMode_Handle);
    xdc_UInt16 (*getInstanceId)(ti_uia_loggers_LoggerStopMode_Handle);
    ti_uia_runtime_IUIATransfer_Priority (*getPriority)(ti_uia_loggers_LoggerStopMode_Handle);
    xdc_Void (*setPriority)(ti_uia_loggers_LoggerStopMode_Handle, ti_uia_runtime_IUIATransfer_Priority);
    xdc_Void (*reset)(ti_uia_loggers_LoggerStopMode_Handle);
    xdc_Void (*writeMemoryRange)(ti_uia_loggers_LoggerStopMode_Handle, xdc_runtime_Log_Event, xdc_runtime_Types_ModuleId, xdc_UInt32, xdc_IArg, xdc_IArg, xdc_IArg, xdc_IArg, xdc_UInt32);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_uia_loggers_LoggerStopMode_Fxns__ ti_uia_loggers_LoggerStopMode_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_uia_loggers_LoggerStopMode_Module_startup ti_uia_loggers_LoggerStopMode_Module_startup__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Module_startup__E, "ti_uia_loggers_LoggerStopMode_Module_startup")
__extern xdc_Int ti_uia_loggers_LoggerStopMode_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Module_startup__F, "ti_uia_loggers_LoggerStopMode_Module_startup")
__extern xdc_Int ti_uia_loggers_LoggerStopMode_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Instance_init__E, "ti_uia_loggers_LoggerStopMode_Instance_init")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_Instance_init__E(ti_uia_loggers_LoggerStopMode_Object *, const ti_uia_loggers_LoggerStopMode_Params *);

/* Handle__label__S */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Handle__label__S, "ti_uia_loggers_LoggerStopMode_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_uia_loggers_LoggerStopMode_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Module__startupDone__S, "ti_uia_loggers_LoggerStopMode_Module__startupDone__S")
__extern xdc_Bool ti_uia_loggers_LoggerStopMode_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Object__create__S, "ti_uia_loggers_LoggerStopMode_Object__create__S")
__extern xdc_Ptr ti_uia_loggers_LoggerStopMode_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_create, "ti_uia_loggers_LoggerStopMode_create")
__extern ti_uia_loggers_LoggerStopMode_Handle ti_uia_loggers_LoggerStopMode_create( const ti_uia_loggers_LoggerStopMode_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_construct, "ti_uia_loggers_LoggerStopMode_construct")
__extern void ti_uia_loggers_LoggerStopMode_construct( ti_uia_loggers_LoggerStopMode_Struct *__obj, const ti_uia_loggers_LoggerStopMode_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Object__delete__S, "ti_uia_loggers_LoggerStopMode_Object__delete__S")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_delete, "ti_uia_loggers_LoggerStopMode_delete")
__extern void ti_uia_loggers_LoggerStopMode_delete(ti_uia_loggers_LoggerStopMode_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Object__destruct__S, "ti_uia_loggers_LoggerStopMode_Object__destruct__S")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_destruct, "ti_uia_loggers_LoggerStopMode_destruct")
__extern void ti_uia_loggers_LoggerStopMode_destruct(ti_uia_loggers_LoggerStopMode_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Object__get__S, "ti_uia_loggers_LoggerStopMode_Object__get__S")
__extern xdc_Ptr ti_uia_loggers_LoggerStopMode_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Object__first__S, "ti_uia_loggers_LoggerStopMode_Object__first__S")
__extern xdc_Ptr ti_uia_loggers_LoggerStopMode_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Object__next__S, "ti_uia_loggers_LoggerStopMode_Object__next__S")
__extern xdc_Ptr ti_uia_loggers_LoggerStopMode_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_Params__init__S, "ti_uia_loggers_LoggerStopMode_Params__init__S")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* enable__E */
#define ti_uia_loggers_LoggerStopMode_enable ti_uia_loggers_LoggerStopMode_enable__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_enable__E, "ti_uia_loggers_LoggerStopMode_enable")
__extern xdc_Bool ti_uia_loggers_LoggerStopMode_enable__E( ti_uia_loggers_LoggerStopMode_Handle __inst );

/* disable__E */
#define ti_uia_loggers_LoggerStopMode_disable ti_uia_loggers_LoggerStopMode_disable__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_disable__E, "ti_uia_loggers_LoggerStopMode_disable")
__extern xdc_Bool ti_uia_loggers_LoggerStopMode_disable__E( ti_uia_loggers_LoggerStopMode_Handle __inst );

/* getTransferType__E */
#define ti_uia_loggers_LoggerStopMode_getTransferType ti_uia_loggers_LoggerStopMode_getTransferType__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_getTransferType__E, "ti_uia_loggers_LoggerStopMode_getTransferType")
__extern ti_uia_runtime_IUIATransfer_TransferType ti_uia_loggers_LoggerStopMode_getTransferType__E( ti_uia_loggers_LoggerStopMode_Handle __inst );

/* getContents__E */
#define ti_uia_loggers_LoggerStopMode_getContents ti_uia_loggers_LoggerStopMode_getContents__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_getContents__E, "ti_uia_loggers_LoggerStopMode_getContents")
__extern xdc_Bool ti_uia_loggers_LoggerStopMode_getContents__E( ti_uia_loggers_LoggerStopMode_Handle __inst, xdc_Ptr hdrBuf, xdc_SizeT size, xdc_SizeT *cpSize );

/* isEmpty__E */
#define ti_uia_loggers_LoggerStopMode_isEmpty ti_uia_loggers_LoggerStopMode_isEmpty__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_isEmpty__E, "ti_uia_loggers_LoggerStopMode_isEmpty")
__extern xdc_Bool ti_uia_loggers_LoggerStopMode_isEmpty__E( ti_uia_loggers_LoggerStopMode_Handle __inst );

/* getMaxLength__E */
#define ti_uia_loggers_LoggerStopMode_getMaxLength ti_uia_loggers_LoggerStopMode_getMaxLength__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_getMaxLength__E, "ti_uia_loggers_LoggerStopMode_getMaxLength")
__extern xdc_SizeT ti_uia_loggers_LoggerStopMode_getMaxLength__E( ti_uia_loggers_LoggerStopMode_Handle __inst );

/* getInstanceId__E */
#define ti_uia_loggers_LoggerStopMode_getInstanceId ti_uia_loggers_LoggerStopMode_getInstanceId__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_getInstanceId__E, "ti_uia_loggers_LoggerStopMode_getInstanceId")
__extern xdc_UInt16 ti_uia_loggers_LoggerStopMode_getInstanceId__E( ti_uia_loggers_LoggerStopMode_Handle __inst );

/* getPriority__E */
#define ti_uia_loggers_LoggerStopMode_getPriority ti_uia_loggers_LoggerStopMode_getPriority__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_getPriority__E, "ti_uia_loggers_LoggerStopMode_getPriority")
__extern ti_uia_runtime_IUIATransfer_Priority ti_uia_loggers_LoggerStopMode_getPriority__E( ti_uia_loggers_LoggerStopMode_Handle __inst );

/* setPriority__E */
#define ti_uia_loggers_LoggerStopMode_setPriority ti_uia_loggers_LoggerStopMode_setPriority__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_setPriority__E, "ti_uia_loggers_LoggerStopMode_setPriority")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_setPriority__E( ti_uia_loggers_LoggerStopMode_Handle __inst, ti_uia_runtime_IUIATransfer_Priority priority );

/* reset__E */
#define ti_uia_loggers_LoggerStopMode_reset ti_uia_loggers_LoggerStopMode_reset__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_reset__E, "ti_uia_loggers_LoggerStopMode_reset")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_reset__E( ti_uia_loggers_LoggerStopMode_Handle __inst );

/* writeMemoryRange__E */
#define ti_uia_loggers_LoggerStopMode_writeMemoryRange ti_uia_loggers_LoggerStopMode_writeMemoryRange__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_writeMemoryRange__E, "ti_uia_loggers_LoggerStopMode_writeMemoryRange")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_writeMemoryRange__E( ti_uia_loggers_LoggerStopMode_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_UInt32 snapshotId, xdc_IArg fileName, xdc_IArg LineNum, xdc_IArg fmt, xdc_IArg startAdrs, xdc_UInt32 lengthInMAUs );

/* flush__E */
#define ti_uia_loggers_LoggerStopMode_flush ti_uia_loggers_LoggerStopMode_flush__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_flush__E, "ti_uia_loggers_LoggerStopMode_flush")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_flush__E( ti_uia_loggers_LoggerStopMode_Handle __inst );

/* initQueueDescriptor__E */
#define ti_uia_loggers_LoggerStopMode_initQueueDescriptor ti_uia_loggers_LoggerStopMode_initQueueDescriptor__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_initQueueDescriptor__E, "ti_uia_loggers_LoggerStopMode_initQueueDescriptor")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_initQueueDescriptor__E( ti_uia_loggers_LoggerStopMode_Handle __inst, xdc_runtime_Types_ModuleId mid );

/* write0__E */
#define ti_uia_loggers_LoggerStopMode_write0 ti_uia_loggers_LoggerStopMode_write0__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_write0__E, "ti_uia_loggers_LoggerStopMode_write0")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_write0__E( ti_uia_loggers_LoggerStopMode_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid );

/* write1__E */
#define ti_uia_loggers_LoggerStopMode_write1 ti_uia_loggers_LoggerStopMode_write1__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_write1__E, "ti_uia_loggers_LoggerStopMode_write1")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_write1__E( ti_uia_loggers_LoggerStopMode_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1 );

/* write2__E */
#define ti_uia_loggers_LoggerStopMode_write2 ti_uia_loggers_LoggerStopMode_write2__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_write2__E, "ti_uia_loggers_LoggerStopMode_write2")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_write2__E( ti_uia_loggers_LoggerStopMode_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1, xdc_IArg a2 );

/* write4__E */
#define ti_uia_loggers_LoggerStopMode_write4 ti_uia_loggers_LoggerStopMode_write4__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_write4__E, "ti_uia_loggers_LoggerStopMode_write4")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_write4__E( ti_uia_loggers_LoggerStopMode_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4 );

/* write8__E */
#define ti_uia_loggers_LoggerStopMode_write8 ti_uia_loggers_LoggerStopMode_write8__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_write8__E, "ti_uia_loggers_LoggerStopMode_write8")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_write8__E( ti_uia_loggers_LoggerStopMode_Handle __inst, xdc_runtime_Log_Event evt, xdc_runtime_Types_ModuleId mid, xdc_IArg a1, xdc_IArg a2, xdc_IArg a3, xdc_IArg a4, xdc_IArg a5, xdc_IArg a6, xdc_IArg a7, xdc_IArg a8 );

/* setFilterLevel__E */
#define ti_uia_loggers_LoggerStopMode_setFilterLevel ti_uia_loggers_LoggerStopMode_setFilterLevel__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_setFilterLevel__E, "ti_uia_loggers_LoggerStopMode_setFilterLevel")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_setFilterLevel__E( ti_uia_loggers_LoggerStopMode_Handle __inst, xdc_runtime_Diags_Mask mask, xdc_runtime_Diags_EventLevel filterLevel );

/* getFilterLevel__E */
#define ti_uia_loggers_LoggerStopMode_getFilterLevel ti_uia_loggers_LoggerStopMode_getFilterLevel__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_getFilterLevel__E, "ti_uia_loggers_LoggerStopMode_getFilterLevel")
__extern xdc_runtime_Diags_Mask ti_uia_loggers_LoggerStopMode_getFilterLevel__E( ti_uia_loggers_LoggerStopMode_Handle __inst, xdc_runtime_Diags_EventLevel level );

/* getBufSize__E */
#define ti_uia_loggers_LoggerStopMode_getBufSize ti_uia_loggers_LoggerStopMode_getBufSize__E
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_getBufSize__E, "ti_uia_loggers_LoggerStopMode_getBufSize")
__extern xdc_SizeT ti_uia_loggers_LoggerStopMode_getBufSize__E( ti_uia_loggers_LoggerStopMode_Handle __inst );

/* initBuffer__I */
#define ti_uia_loggers_LoggerStopMode_initBuffer ti_uia_loggers_LoggerStopMode_initBuffer__I
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_initBuffer__I, "ti_uia_loggers_LoggerStopMode_initBuffer")
__extern xdc_Void ti_uia_loggers_LoggerStopMode_initBuffer__I( ti_uia_loggers_LoggerStopMode_Object *obj, xdc_Ptr buffer, xdc_UInt16 src );

/* filterOutEvent__I */
#define ti_uia_loggers_LoggerStopMode_filterOutEvent ti_uia_loggers_LoggerStopMode_filterOutEvent__I
xdc__CODESECT(ti_uia_loggers_LoggerStopMode_filterOutEvent__I, "ti_uia_loggers_LoggerStopMode_filterOutEvent")
__extern xdc_Bool ti_uia_loggers_LoggerStopMode_filterOutEvent__I( xdc_runtime_Diags_Mask mask );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_uia_runtime_ILoggerSnapshot_Module ti_uia_loggers_LoggerStopMode_Module_upCast( void )
{
    return (ti_uia_runtime_ILoggerSnapshot_Module)&ti_uia_loggers_LoggerStopMode_Module__FXNS__C;
}

/* Module_to_ti_uia_runtime_ILoggerSnapshot */
#define ti_uia_loggers_LoggerStopMode_Module_to_ti_uia_runtime_ILoggerSnapshot ti_uia_loggers_LoggerStopMode_Module_upCast

/* Handle_upCast */
static inline ti_uia_runtime_ILoggerSnapshot_Handle ti_uia_loggers_LoggerStopMode_Handle_upCast( ti_uia_loggers_LoggerStopMode_Handle i )
{
    return (ti_uia_runtime_ILoggerSnapshot_Handle)i;
}

/* Handle_to_ti_uia_runtime_ILoggerSnapshot */
#define ti_uia_loggers_LoggerStopMode_Handle_to_ti_uia_runtime_ILoggerSnapshot ti_uia_loggers_LoggerStopMode_Handle_upCast

/* Handle_downCast */
static inline ti_uia_loggers_LoggerStopMode_Handle ti_uia_loggers_LoggerStopMode_Handle_downCast( ti_uia_runtime_ILoggerSnapshot_Handle i )
{
    ti_uia_runtime_ILoggerSnapshot_Handle i2 = (ti_uia_runtime_ILoggerSnapshot_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_uia_loggers_LoggerStopMode_Module__FXNS__C ? (ti_uia_loggers_LoggerStopMode_Handle)i : 0;
}

/* Handle_from_ti_uia_runtime_ILoggerSnapshot */
#define ti_uia_loggers_LoggerStopMode_Handle_from_ti_uia_runtime_ILoggerSnapshot ti_uia_loggers_LoggerStopMode_Handle_downCast

/* Module_upCast2 */
static inline ti_uia_runtime_IUIATransfer_Module ti_uia_loggers_LoggerStopMode_Module_upCast2( void )
{
    return (ti_uia_runtime_IUIATransfer_Module)&ti_uia_loggers_LoggerStopMode_Module__FXNS__C;
}

/* Module_to_ti_uia_runtime_IUIATransfer */
#define ti_uia_loggers_LoggerStopMode_Module_to_ti_uia_runtime_IUIATransfer ti_uia_loggers_LoggerStopMode_Module_upCast2

/* Handle_upCast2 */
static inline ti_uia_runtime_IUIATransfer_Handle ti_uia_loggers_LoggerStopMode_Handle_upCast2( ti_uia_loggers_LoggerStopMode_Handle i )
{
    return (ti_uia_runtime_IUIATransfer_Handle)i;
}

/* Handle_to_ti_uia_runtime_IUIATransfer */
#define ti_uia_loggers_LoggerStopMode_Handle_to_ti_uia_runtime_IUIATransfer ti_uia_loggers_LoggerStopMode_Handle_upCast2

/* Handle_downCast2 */
static inline ti_uia_loggers_LoggerStopMode_Handle ti_uia_loggers_LoggerStopMode_Handle_downCast2( ti_uia_runtime_IUIATransfer_Handle i )
{
    ti_uia_runtime_IUIATransfer_Handle i2 = (ti_uia_runtime_IUIATransfer_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_uia_loggers_LoggerStopMode_Module__FXNS__C ? (ti_uia_loggers_LoggerStopMode_Handle)i : 0;
}

/* Handle_from_ti_uia_runtime_IUIATransfer */
#define ti_uia_loggers_LoggerStopMode_Handle_from_ti_uia_runtime_IUIATransfer ti_uia_loggers_LoggerStopMode_Handle_downCast2

/* Module_upCast3 */
static inline xdc_runtime_IFilterLogger_Module ti_uia_loggers_LoggerStopMode_Module_upCast3( void )
{
    return (xdc_runtime_IFilterLogger_Module)&ti_uia_loggers_LoggerStopMode_Module__FXNS__C;
}

/* Module_to_xdc_runtime_IFilterLogger */
#define ti_uia_loggers_LoggerStopMode_Module_to_xdc_runtime_IFilterLogger ti_uia_loggers_LoggerStopMode_Module_upCast3

/* Handle_upCast3 */
static inline xdc_runtime_IFilterLogger_Handle ti_uia_loggers_LoggerStopMode_Handle_upCast3( ti_uia_loggers_LoggerStopMode_Handle i )
{
    return (xdc_runtime_IFilterLogger_Handle)i;
}

/* Handle_to_xdc_runtime_IFilterLogger */
#define ti_uia_loggers_LoggerStopMode_Handle_to_xdc_runtime_IFilterLogger ti_uia_loggers_LoggerStopMode_Handle_upCast3

/* Handle_downCast3 */
static inline ti_uia_loggers_LoggerStopMode_Handle ti_uia_loggers_LoggerStopMode_Handle_downCast3( xdc_runtime_IFilterLogger_Handle i )
{
    xdc_runtime_IFilterLogger_Handle i2 = (xdc_runtime_IFilterLogger_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_uia_loggers_LoggerStopMode_Module__FXNS__C ? (ti_uia_loggers_LoggerStopMode_Handle)i : 0;
}

/* Handle_from_xdc_runtime_IFilterLogger */
#define ti_uia_loggers_LoggerStopMode_Handle_from_xdc_runtime_IFilterLogger ti_uia_loggers_LoggerStopMode_Handle_downCast3

/* Module_upCast4 */
static inline xdc_runtime_ILogger_Module ti_uia_loggers_LoggerStopMode_Module_upCast4( void )
{
    return (xdc_runtime_ILogger_Module)&ti_uia_loggers_LoggerStopMode_Module__FXNS__C;
}

/* Module_to_xdc_runtime_ILogger */
#define ti_uia_loggers_LoggerStopMode_Module_to_xdc_runtime_ILogger ti_uia_loggers_LoggerStopMode_Module_upCast4

/* Handle_upCast4 */
static inline xdc_runtime_ILogger_Handle ti_uia_loggers_LoggerStopMode_Handle_upCast4( ti_uia_loggers_LoggerStopMode_Handle i )
{
    return (xdc_runtime_ILogger_Handle)i;
}

/* Handle_to_xdc_runtime_ILogger */
#define ti_uia_loggers_LoggerStopMode_Handle_to_xdc_runtime_ILogger ti_uia_loggers_LoggerStopMode_Handle_upCast4

/* Handle_downCast4 */
static inline ti_uia_loggers_LoggerStopMode_Handle ti_uia_loggers_LoggerStopMode_Handle_downCast4( xdc_runtime_ILogger_Handle i )
{
    xdc_runtime_ILogger_Handle i2 = (xdc_runtime_ILogger_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_uia_loggers_LoggerStopMode_Module__FXNS__C ? (ti_uia_loggers_LoggerStopMode_Handle)i : 0;
}

/* Handle_from_xdc_runtime_ILogger */
#define ti_uia_loggers_LoggerStopMode_Handle_from_xdc_runtime_ILogger ti_uia_loggers_LoggerStopMode_Handle_downCast4


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_uia_loggers_LoggerStopMode_Module_startupDone() ti_uia_loggers_LoggerStopMode_Module__startupDone__S()

/* Object_heap */
#define ti_uia_loggers_LoggerStopMode_Object_heap() ti_uia_loggers_LoggerStopMode_Object__heap__C

/* Module_heap */
#define ti_uia_loggers_LoggerStopMode_Module_heap() ti_uia_loggers_LoggerStopMode_Object__heap__C

/* Module_id */
static inline CT__ti_uia_loggers_LoggerStopMode_Module__id ti_uia_loggers_LoggerStopMode_Module_id( void ) 
{
    return ti_uia_loggers_LoggerStopMode_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_uia_loggers_LoggerStopMode_Module_hasMask( void ) 
{
    return ti_uia_loggers_LoggerStopMode_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_uia_loggers_LoggerStopMode_Module_getMask( void ) 
{
    return ti_uia_loggers_LoggerStopMode_Module__diagsMask__C != NULL ? *ti_uia_loggers_LoggerStopMode_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_uia_loggers_LoggerStopMode_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_uia_loggers_LoggerStopMode_Module__diagsMask__C != NULL) *ti_uia_loggers_LoggerStopMode_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_uia_loggers_LoggerStopMode_Params_init( ti_uia_loggers_LoggerStopMode_Params *prms ) 
{
    if (prms) {
        ti_uia_loggers_LoggerStopMode_Params__init__S(prms, 0, sizeof(ti_uia_loggers_LoggerStopMode_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_uia_loggers_LoggerStopMode_Params_copy(ti_uia_loggers_LoggerStopMode_Params *dst, const ti_uia_loggers_LoggerStopMode_Params *src) 
{
    if (dst) {
        ti_uia_loggers_LoggerStopMode_Params__init__S(dst, (const void *)src, sizeof(ti_uia_loggers_LoggerStopMode_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_uia_loggers_LoggerStopMode_Object_count() ti_uia_loggers_LoggerStopMode_Object__count__C

/* Object_sizeof */
#define ti_uia_loggers_LoggerStopMode_Object_sizeof() ti_uia_loggers_LoggerStopMode_Object__sizeof__C

/* Object_get */
static inline ti_uia_loggers_LoggerStopMode_Handle ti_uia_loggers_LoggerStopMode_Object_get(ti_uia_loggers_LoggerStopMode_Instance_State *oarr, int i) 
{
    return (ti_uia_loggers_LoggerStopMode_Handle)ti_uia_loggers_LoggerStopMode_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_uia_loggers_LoggerStopMode_Handle ti_uia_loggers_LoggerStopMode_Object_first( void )
{
    return (ti_uia_loggers_LoggerStopMode_Handle)ti_uia_loggers_LoggerStopMode_Object__first__S();
}

/* Object_next */
static inline ti_uia_loggers_LoggerStopMode_Handle ti_uia_loggers_LoggerStopMode_Object_next( ti_uia_loggers_LoggerStopMode_Object *obj )
{
    return (ti_uia_loggers_LoggerStopMode_Handle)ti_uia_loggers_LoggerStopMode_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_uia_loggers_LoggerStopMode_Handle_label( ti_uia_loggers_LoggerStopMode_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_uia_loggers_LoggerStopMode_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_uia_loggers_LoggerStopMode_Handle_name( ti_uia_loggers_LoggerStopMode_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_uia_loggers_LoggerStopMode_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_uia_loggers_LoggerStopMode_Handle ti_uia_loggers_LoggerStopMode_handle( ti_uia_loggers_LoggerStopMode_Struct *str )
{
    return (ti_uia_loggers_LoggerStopMode_Handle)str;
}

/* struct */
static inline ti_uia_loggers_LoggerStopMode_Struct *ti_uia_loggers_LoggerStopMode_struct( ti_uia_loggers_LoggerStopMode_Handle inst )
{
    return (ti_uia_loggers_LoggerStopMode_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#include <ti/uia/loggers/LoggerStopMode__epilogue.h>

#ifdef ti_uia_loggers_LoggerStopMode__top__
#undef __nested__
#endif

#endif /* ti_uia_loggers_LoggerStopMode__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_uia_loggers_LoggerStopMode__internalaccess))

#ifndef ti_uia_loggers_LoggerStopMode__include_state
#define ti_uia_loggers_LoggerStopMode__include_state

/* Module_State */
struct ti_uia_loggers_LoggerStopMode_Module_State {
    xdc_Bool enabled;
    xdc_runtime_Diags_Mask level1;
    xdc_runtime_Diags_Mask level2;
    xdc_runtime_Diags_Mask level3;
};

/* Module__state__V */
extern struct ti_uia_loggers_LoggerStopMode_Module_State__ ti_uia_loggers_LoggerStopMode_Module__state__V;

/* Object */
struct ti_uia_loggers_LoggerStopMode_Object {
    const ti_uia_loggers_LoggerStopMode_Fxns__ *__fxns;
    xdc_Bool enabled;
    xdc_Int16 instanceId;
    xdc_UInt32 bufSize;
    xdc_UInt32 *buffer;
    xdc_UInt32 *write;
    xdc_UInt32 *end;
    xdc_SizeT maxEventSizeInBits32;
    xdc_SizeT maxEventSize;
    xdc_UInt16 numBytesInPrevEvent;
    xdc_Bits32 droppedEvents;
    xdc_UInt16 eventSequenceNum;
    xdc_UInt16 pktSequenceNum;
    __TA_ti_uia_loggers_LoggerStopMode_Instance_State__hdr hdr;
    __TA_ti_uia_loggers_LoggerStopMode_Instance_State__packetArray packetArray;
};

#endif /* ti_uia_loggers_LoggerStopMode__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_uia_loggers_LoggerStopMode__nolocalnames)

#ifndef ti_uia_loggers_LoggerStopMode__localnames__done
#define ti_uia_loggers_LoggerStopMode__localnames__done

/* module prefix */
#define LoggerStopMode_Instance ti_uia_loggers_LoggerStopMode_Instance
#define LoggerStopMode_Handle ti_uia_loggers_LoggerStopMode_Handle
#define LoggerStopMode_Module ti_uia_loggers_LoggerStopMode_Module
#define LoggerStopMode_Object ti_uia_loggers_LoggerStopMode_Object
#define LoggerStopMode_Struct ti_uia_loggers_LoggerStopMode_Struct
#define LoggerStopMode_TransferType ti_uia_loggers_LoggerStopMode_TransferType
#define LoggerStopMode_Priority ti_uia_loggers_LoggerStopMode_Priority
#define LoggerStopMode_Module_State ti_uia_loggers_LoggerStopMode_Module_State
#define LoggerStopMode_Instance_State ti_uia_loggers_LoggerStopMode_Instance_State
#define LoggerStopMode_TransferType_RELIABLE ti_uia_loggers_LoggerStopMode_TransferType_RELIABLE
#define LoggerStopMode_TransferType_LOSSY ti_uia_loggers_LoggerStopMode_TransferType_LOSSY
#define LoggerStopMode_Priority_LOW ti_uia_loggers_LoggerStopMode_Priority_LOW
#define LoggerStopMode_Priority_STANDARD ti_uia_loggers_LoggerStopMode_Priority_STANDARD
#define LoggerStopMode_Priority_HIGH ti_uia_loggers_LoggerStopMode_Priority_HIGH
#define LoggerStopMode_Priority_SYNC ti_uia_loggers_LoggerStopMode_Priority_SYNC
#define LoggerStopMode_filterByLevel ti_uia_loggers_LoggerStopMode_filterByLevel
#define LoggerStopMode_isTimestampEnabled ti_uia_loggers_LoggerStopMode_isTimestampEnabled
#define LoggerStopMode_supportLoggerDisable ti_uia_loggers_LoggerStopMode_supportLoggerDisable
#define LoggerStopMode_level1Mask ti_uia_loggers_LoggerStopMode_level1Mask
#define LoggerStopMode_level2Mask ti_uia_loggers_LoggerStopMode_level2Mask
#define LoggerStopMode_level3Mask ti_uia_loggers_LoggerStopMode_level3Mask
#define LoggerStopMode_level4Mask ti_uia_loggers_LoggerStopMode_level4Mask
#define LoggerStopMode_L_test ti_uia_loggers_LoggerStopMode_L_test
#define LoggerStopMode_E_badLevel ti_uia_loggers_LoggerStopMode_E_badLevel
#define LoggerStopMode_numCores ti_uia_loggers_LoggerStopMode_numCores
#define LoggerStopMode_Params ti_uia_loggers_LoggerStopMode_Params
#define LoggerStopMode_enable ti_uia_loggers_LoggerStopMode_enable
#define LoggerStopMode_disable ti_uia_loggers_LoggerStopMode_disable
#define LoggerStopMode_getTransferType ti_uia_loggers_LoggerStopMode_getTransferType
#define LoggerStopMode_getContents ti_uia_loggers_LoggerStopMode_getContents
#define LoggerStopMode_isEmpty ti_uia_loggers_LoggerStopMode_isEmpty
#define LoggerStopMode_getMaxLength ti_uia_loggers_LoggerStopMode_getMaxLength
#define LoggerStopMode_getInstanceId ti_uia_loggers_LoggerStopMode_getInstanceId
#define LoggerStopMode_getPriority ti_uia_loggers_LoggerStopMode_getPriority
#define LoggerStopMode_setPriority ti_uia_loggers_LoggerStopMode_setPriority
#define LoggerStopMode_reset ti_uia_loggers_LoggerStopMode_reset
#define LoggerStopMode_writeMemoryRange ti_uia_loggers_LoggerStopMode_writeMemoryRange
#define LoggerStopMode_flush ti_uia_loggers_LoggerStopMode_flush
#define LoggerStopMode_initQueueDescriptor ti_uia_loggers_LoggerStopMode_initQueueDescriptor
#define LoggerStopMode_write0 ti_uia_loggers_LoggerStopMode_write0
#define LoggerStopMode_write1 ti_uia_loggers_LoggerStopMode_write1
#define LoggerStopMode_write2 ti_uia_loggers_LoggerStopMode_write2
#define LoggerStopMode_write4 ti_uia_loggers_LoggerStopMode_write4
#define LoggerStopMode_write8 ti_uia_loggers_LoggerStopMode_write8
#define LoggerStopMode_setFilterLevel ti_uia_loggers_LoggerStopMode_setFilterLevel
#define LoggerStopMode_getFilterLevel ti_uia_loggers_LoggerStopMode_getFilterLevel
#define LoggerStopMode_getBufSize ti_uia_loggers_LoggerStopMode_getBufSize
#define LoggerStopMode_Module_name ti_uia_loggers_LoggerStopMode_Module_name
#define LoggerStopMode_Module_id ti_uia_loggers_LoggerStopMode_Module_id
#define LoggerStopMode_Module_startup ti_uia_loggers_LoggerStopMode_Module_startup
#define LoggerStopMode_Module_startupDone ti_uia_loggers_LoggerStopMode_Module_startupDone
#define LoggerStopMode_Module_hasMask ti_uia_loggers_LoggerStopMode_Module_hasMask
#define LoggerStopMode_Module_getMask ti_uia_loggers_LoggerStopMode_Module_getMask
#define LoggerStopMode_Module_setMask ti_uia_loggers_LoggerStopMode_Module_setMask
#define LoggerStopMode_Object_heap ti_uia_loggers_LoggerStopMode_Object_heap
#define LoggerStopMode_Module_heap ti_uia_loggers_LoggerStopMode_Module_heap
#define LoggerStopMode_construct ti_uia_loggers_LoggerStopMode_construct
#define LoggerStopMode_create ti_uia_loggers_LoggerStopMode_create
#define LoggerStopMode_handle ti_uia_loggers_LoggerStopMode_handle
#define LoggerStopMode_struct ti_uia_loggers_LoggerStopMode_struct
#define LoggerStopMode_Handle_label ti_uia_loggers_LoggerStopMode_Handle_label
#define LoggerStopMode_Handle_name ti_uia_loggers_LoggerStopMode_Handle_name
#define LoggerStopMode_Instance_init ti_uia_loggers_LoggerStopMode_Instance_init
#define LoggerStopMode_Object_count ti_uia_loggers_LoggerStopMode_Object_count
#define LoggerStopMode_Object_get ti_uia_loggers_LoggerStopMode_Object_get
#define LoggerStopMode_Object_first ti_uia_loggers_LoggerStopMode_Object_first
#define LoggerStopMode_Object_next ti_uia_loggers_LoggerStopMode_Object_next
#define LoggerStopMode_Object_sizeof ti_uia_loggers_LoggerStopMode_Object_sizeof
#define LoggerStopMode_Params_copy ti_uia_loggers_LoggerStopMode_Params_copy
#define LoggerStopMode_Params_init ti_uia_loggers_LoggerStopMode_Params_init
#define LoggerStopMode_delete ti_uia_loggers_LoggerStopMode_delete
#define LoggerStopMode_destruct ti_uia_loggers_LoggerStopMode_destruct
#define LoggerStopMode_Module_upCast ti_uia_loggers_LoggerStopMode_Module_upCast
#define LoggerStopMode_Module_to_ti_uia_runtime_ILoggerSnapshot ti_uia_loggers_LoggerStopMode_Module_to_ti_uia_runtime_ILoggerSnapshot
#define LoggerStopMode_Handle_upCast ti_uia_loggers_LoggerStopMode_Handle_upCast
#define LoggerStopMode_Handle_to_ti_uia_runtime_ILoggerSnapshot ti_uia_loggers_LoggerStopMode_Handle_to_ti_uia_runtime_ILoggerSnapshot
#define LoggerStopMode_Handle_downCast ti_uia_loggers_LoggerStopMode_Handle_downCast
#define LoggerStopMode_Handle_from_ti_uia_runtime_ILoggerSnapshot ti_uia_loggers_LoggerStopMode_Handle_from_ti_uia_runtime_ILoggerSnapshot
#define LoggerStopMode_Module_upCast2 ti_uia_loggers_LoggerStopMode_Module_upCast2
#define LoggerStopMode_Module_to_ti_uia_runtime_IUIATransfer ti_uia_loggers_LoggerStopMode_Module_to_ti_uia_runtime_IUIATransfer
#define LoggerStopMode_Handle_upCast2 ti_uia_loggers_LoggerStopMode_Handle_upCast2
#define LoggerStopMode_Handle_to_ti_uia_runtime_IUIATransfer ti_uia_loggers_LoggerStopMode_Handle_to_ti_uia_runtime_IUIATransfer
#define LoggerStopMode_Handle_downCast2 ti_uia_loggers_LoggerStopMode_Handle_downCast2
#define LoggerStopMode_Handle_from_ti_uia_runtime_IUIATransfer ti_uia_loggers_LoggerStopMode_Handle_from_ti_uia_runtime_IUIATransfer
#define LoggerStopMode_Module_upCast3 ti_uia_loggers_LoggerStopMode_Module_upCast3
#define LoggerStopMode_Module_to_xdc_runtime_IFilterLogger ti_uia_loggers_LoggerStopMode_Module_to_xdc_runtime_IFilterLogger
#define LoggerStopMode_Handle_upCast3 ti_uia_loggers_LoggerStopMode_Handle_upCast3
#define LoggerStopMode_Handle_to_xdc_runtime_IFilterLogger ti_uia_loggers_LoggerStopMode_Handle_to_xdc_runtime_IFilterLogger
#define LoggerStopMode_Handle_downCast3 ti_uia_loggers_LoggerStopMode_Handle_downCast3
#define LoggerStopMode_Handle_from_xdc_runtime_IFilterLogger ti_uia_loggers_LoggerStopMode_Handle_from_xdc_runtime_IFilterLogger
#define LoggerStopMode_Module_upCast4 ti_uia_loggers_LoggerStopMode_Module_upCast4
#define LoggerStopMode_Module_to_xdc_runtime_ILogger ti_uia_loggers_LoggerStopMode_Module_to_xdc_runtime_ILogger
#define LoggerStopMode_Handle_upCast4 ti_uia_loggers_LoggerStopMode_Handle_upCast4
#define LoggerStopMode_Handle_to_xdc_runtime_ILogger ti_uia_loggers_LoggerStopMode_Handle_to_xdc_runtime_ILogger
#define LoggerStopMode_Handle_downCast4 ti_uia_loggers_LoggerStopMode_Handle_downCast4
#define LoggerStopMode_Handle_from_xdc_runtime_ILogger ti_uia_loggers_LoggerStopMode_Handle_from_xdc_runtime_ILogger

#endif /* ti_uia_loggers_LoggerStopMode__localnames__done */
#endif
