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

#ifndef ti_uia_family_c64p_TimestampC64XLocal__include
#define ti_uia_family_c64p_TimestampC64XLocal__include

#ifndef __nested__
#define __nested__
#define ti_uia_family_c64p_TimestampC64XLocal__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_uia_family_c64p_TimestampC64XLocal___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/uia/family/c64p/package/package.defs.h>

#include <xdc/runtime/Types.h>
#include <ti/uia/runtime/IUIATimestampProvider.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_uia_family_c64p_TimestampC64XLocal_Module__diagsEnabled;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__diagsEnabled ti_uia_family_c64p_TimestampC64XLocal_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_uia_family_c64p_TimestampC64XLocal_Module__diagsIncluded;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__diagsIncluded ti_uia_family_c64p_TimestampC64XLocal_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_uia_family_c64p_TimestampC64XLocal_Module__diagsMask;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__diagsMask ti_uia_family_c64p_TimestampC64XLocal_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_uia_family_c64p_TimestampC64XLocal_Module__gateObj;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__gateObj ti_uia_family_c64p_TimestampC64XLocal_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_uia_family_c64p_TimestampC64XLocal_Module__gatePrms;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__gatePrms ti_uia_family_c64p_TimestampC64XLocal_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_uia_family_c64p_TimestampC64XLocal_Module__id;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__id ti_uia_family_c64p_TimestampC64XLocal_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerDefined;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerDefined ti_uia_family_c64p_TimestampC64XLocal_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerObj;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerObj ti_uia_family_c64p_TimestampC64XLocal_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn0;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn0 ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn1;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn1 ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn2;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn2 ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn4;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn4 ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn8;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn8 ti_uia_family_c64p_TimestampC64XLocal_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_uia_family_c64p_TimestampC64XLocal_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Module__startupDoneFxn ti_uia_family_c64p_TimestampC64XLocal_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_uia_family_c64p_TimestampC64XLocal_Object__count;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Object__count ti_uia_family_c64p_TimestampC64XLocal_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_uia_family_c64p_TimestampC64XLocal_Object__heap;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Object__heap ti_uia_family_c64p_TimestampC64XLocal_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_uia_family_c64p_TimestampC64XLocal_Object__sizeof;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Object__sizeof ti_uia_family_c64p_TimestampC64XLocal_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_uia_family_c64p_TimestampC64XLocal_Object__table;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_Object__table ti_uia_family_c64p_TimestampC64XLocal_Object__table__C;

/* maxTimerClockFreq */
#define ti_uia_family_c64p_TimestampC64XLocal_maxTimerClockFreq (ti_uia_family_c64p_TimestampC64XLocal_maxTimerClockFreq__C)
typedef xdc_runtime_Types_FreqHz CT__ti_uia_family_c64p_TimestampC64XLocal_maxTimerClockFreq;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_maxTimerClockFreq ti_uia_family_c64p_TimestampC64XLocal_maxTimerClockFreq__C;

/* maxBusClockFreq */
#define ti_uia_family_c64p_TimestampC64XLocal_maxBusClockFreq (ti_uia_family_c64p_TimestampC64XLocal_maxBusClockFreq__C)
typedef xdc_runtime_Types_FreqHz CT__ti_uia_family_c64p_TimestampC64XLocal_maxBusClockFreq;
__extern __FAR__ const CT__ti_uia_family_c64p_TimestampC64XLocal_maxBusClockFreq ti_uia_family_c64p_TimestampC64XLocal_maxBusClockFreq__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_uia_family_c64p_TimestampC64XLocal_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_uia_family_c64p_TimestampC64XLocal_Struct {
    const ti_uia_family_c64p_TimestampC64XLocal_Fxns__ *__fxns;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_uia_family_c64p_TimestampC64XLocal_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bits32 (*get32)(void);
    xdc_Void (*get64)(xdc_runtime_Types_Timestamp64*);
    xdc_Void (*getFreq)(xdc_runtime_Types_FreqHz*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_uia_family_c64p_TimestampC64XLocal_Fxns__ ti_uia_family_c64p_TimestampC64XLocal_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_uia_family_c64p_TimestampC64XLocal_Module_startup ti_uia_family_c64p_TimestampC64XLocal_Module_startup__E
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Module_startup__E, "ti_uia_family_c64p_TimestampC64XLocal_Module_startup")
__extern xdc_Int ti_uia_family_c64p_TimestampC64XLocal_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Module_startup__F, "ti_uia_family_c64p_TimestampC64XLocal_Module_startup")
__extern xdc_Int ti_uia_family_c64p_TimestampC64XLocal_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Instance_init__E, "ti_uia_family_c64p_TimestampC64XLocal_Instance_init")
__extern xdc_Void ti_uia_family_c64p_TimestampC64XLocal_Instance_init__E(ti_uia_family_c64p_TimestampC64XLocal_Object *, const ti_uia_family_c64p_TimestampC64XLocal_Params *);

/* Handle__label__S */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Handle__label__S, "ti_uia_family_c64p_TimestampC64XLocal_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_uia_family_c64p_TimestampC64XLocal_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Module__startupDone__S, "ti_uia_family_c64p_TimestampC64XLocal_Module__startupDone__S")
__extern xdc_Bool ti_uia_family_c64p_TimestampC64XLocal_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Object__create__S, "ti_uia_family_c64p_TimestampC64XLocal_Object__create__S")
__extern xdc_Ptr ti_uia_family_c64p_TimestampC64XLocal_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_create, "ti_uia_family_c64p_TimestampC64XLocal_create")
__extern ti_uia_family_c64p_TimestampC64XLocal_Handle ti_uia_family_c64p_TimestampC64XLocal_create( const ti_uia_family_c64p_TimestampC64XLocal_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_construct, "ti_uia_family_c64p_TimestampC64XLocal_construct")
__extern void ti_uia_family_c64p_TimestampC64XLocal_construct( ti_uia_family_c64p_TimestampC64XLocal_Struct *__obj, const ti_uia_family_c64p_TimestampC64XLocal_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Object__delete__S, "ti_uia_family_c64p_TimestampC64XLocal_Object__delete__S")
__extern xdc_Void ti_uia_family_c64p_TimestampC64XLocal_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_delete, "ti_uia_family_c64p_TimestampC64XLocal_delete")
__extern void ti_uia_family_c64p_TimestampC64XLocal_delete(ti_uia_family_c64p_TimestampC64XLocal_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Object__destruct__S, "ti_uia_family_c64p_TimestampC64XLocal_Object__destruct__S")
__extern xdc_Void ti_uia_family_c64p_TimestampC64XLocal_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_destruct, "ti_uia_family_c64p_TimestampC64XLocal_destruct")
__extern void ti_uia_family_c64p_TimestampC64XLocal_destruct(ti_uia_family_c64p_TimestampC64XLocal_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Object__get__S, "ti_uia_family_c64p_TimestampC64XLocal_Object__get__S")
__extern xdc_Ptr ti_uia_family_c64p_TimestampC64XLocal_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Object__first__S, "ti_uia_family_c64p_TimestampC64XLocal_Object__first__S")
__extern xdc_Ptr ti_uia_family_c64p_TimestampC64XLocal_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Object__next__S, "ti_uia_family_c64p_TimestampC64XLocal_Object__next__S")
__extern xdc_Ptr ti_uia_family_c64p_TimestampC64XLocal_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_Params__init__S, "ti_uia_family_c64p_TimestampC64XLocal_Params__init__S")
__extern xdc_Void ti_uia_family_c64p_TimestampC64XLocal_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* get32__E */
#define ti_uia_family_c64p_TimestampC64XLocal_get32 ti_uia_family_c64p_TimestampC64XLocal_get32__E
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_get32__E, "ti_uia_family_c64p_TimestampC64XLocal_get32")
__extern xdc_Bits32 ti_uia_family_c64p_TimestampC64XLocal_get32__E( void );

/* get64__E */
#define ti_uia_family_c64p_TimestampC64XLocal_get64 ti_uia_family_c64p_TimestampC64XLocal_get64__E
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_get64__E, "ti_uia_family_c64p_TimestampC64XLocal_get64")
__extern xdc_Void ti_uia_family_c64p_TimestampC64XLocal_get64__E( xdc_runtime_Types_Timestamp64 *result );

/* getFreq__E */
#define ti_uia_family_c64p_TimestampC64XLocal_getFreq ti_uia_family_c64p_TimestampC64XLocal_getFreq__E
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_getFreq__E, "ti_uia_family_c64p_TimestampC64XLocal_getFreq")
__extern xdc_Void ti_uia_family_c64p_TimestampC64XLocal_getFreq__E( xdc_runtime_Types_FreqHz *freq );

/* setFreq__E */
#define ti_uia_family_c64p_TimestampC64XLocal_setFreq ti_uia_family_c64p_TimestampC64XLocal_setFreq__E
xdc__CODESECT(ti_uia_family_c64p_TimestampC64XLocal_setFreq__E, "ti_uia_family_c64p_TimestampC64XLocal_setFreq")
__extern xdc_Void ti_uia_family_c64p_TimestampC64XLocal_setFreq__E( xdc_runtime_Types_FreqHz *freq );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_uia_runtime_IUIATimestampProvider_Module ti_uia_family_c64p_TimestampC64XLocal_Module_upCast( void )
{
    return (ti_uia_runtime_IUIATimestampProvider_Module)&ti_uia_family_c64p_TimestampC64XLocal_Module__FXNS__C;
}

/* Module_to_ti_uia_runtime_IUIATimestampProvider */
#define ti_uia_family_c64p_TimestampC64XLocal_Module_to_ti_uia_runtime_IUIATimestampProvider ti_uia_family_c64p_TimestampC64XLocal_Module_upCast

/* Module_upCast2 */
static inline xdc_runtime_ITimestampProvider_Module ti_uia_family_c64p_TimestampC64XLocal_Module_upCast2( void )
{
    return (xdc_runtime_ITimestampProvider_Module)&ti_uia_family_c64p_TimestampC64XLocal_Module__FXNS__C;
}

/* Module_to_xdc_runtime_ITimestampProvider */
#define ti_uia_family_c64p_TimestampC64XLocal_Module_to_xdc_runtime_ITimestampProvider ti_uia_family_c64p_TimestampC64XLocal_Module_upCast2

/* Module_upCast3 */
static inline xdc_runtime_ITimestampClient_Module ti_uia_family_c64p_TimestampC64XLocal_Module_upCast3( void )
{
    return (xdc_runtime_ITimestampClient_Module)&ti_uia_family_c64p_TimestampC64XLocal_Module__FXNS__C;
}

/* Module_to_xdc_runtime_ITimestampClient */
#define ti_uia_family_c64p_TimestampC64XLocal_Module_to_xdc_runtime_ITimestampClient ti_uia_family_c64p_TimestampC64XLocal_Module_upCast3


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_uia_family_c64p_TimestampC64XLocal_Module_startupDone() ti_uia_family_c64p_TimestampC64XLocal_Module__startupDone__S()

/* Object_heap */
#define ti_uia_family_c64p_TimestampC64XLocal_Object_heap() ti_uia_family_c64p_TimestampC64XLocal_Object__heap__C

/* Module_heap */
#define ti_uia_family_c64p_TimestampC64XLocal_Module_heap() ti_uia_family_c64p_TimestampC64XLocal_Object__heap__C

/* Module_id */
static inline CT__ti_uia_family_c64p_TimestampC64XLocal_Module__id ti_uia_family_c64p_TimestampC64XLocal_Module_id( void ) 
{
    return ti_uia_family_c64p_TimestampC64XLocal_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_uia_family_c64p_TimestampC64XLocal_Module_hasMask( void ) 
{
    return ti_uia_family_c64p_TimestampC64XLocal_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_uia_family_c64p_TimestampC64XLocal_Module_getMask( void ) 
{
    return ti_uia_family_c64p_TimestampC64XLocal_Module__diagsMask__C != NULL ? *ti_uia_family_c64p_TimestampC64XLocal_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_uia_family_c64p_TimestampC64XLocal_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_uia_family_c64p_TimestampC64XLocal_Module__diagsMask__C != NULL) *ti_uia_family_c64p_TimestampC64XLocal_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_uia_family_c64p_TimestampC64XLocal_Params_init( ti_uia_family_c64p_TimestampC64XLocal_Params *prms ) 
{
    if (prms) {
        ti_uia_family_c64p_TimestampC64XLocal_Params__init__S(prms, 0, sizeof(ti_uia_family_c64p_TimestampC64XLocal_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_uia_family_c64p_TimestampC64XLocal_Params_copy(ti_uia_family_c64p_TimestampC64XLocal_Params *dst, const ti_uia_family_c64p_TimestampC64XLocal_Params *src) 
{
    if (dst) {
        ti_uia_family_c64p_TimestampC64XLocal_Params__init__S(dst, (const void *)src, sizeof(ti_uia_family_c64p_TimestampC64XLocal_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_uia_family_c64p_TimestampC64XLocal_Object_count() ti_uia_family_c64p_TimestampC64XLocal_Object__count__C

/* Object_sizeof */
#define ti_uia_family_c64p_TimestampC64XLocal_Object_sizeof() ti_uia_family_c64p_TimestampC64XLocal_Object__sizeof__C

/* Object_get */
static inline ti_uia_family_c64p_TimestampC64XLocal_Handle ti_uia_family_c64p_TimestampC64XLocal_Object_get(ti_uia_family_c64p_TimestampC64XLocal_Instance_State *oarr, int i) 
{
    return (ti_uia_family_c64p_TimestampC64XLocal_Handle)ti_uia_family_c64p_TimestampC64XLocal_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_uia_family_c64p_TimestampC64XLocal_Handle ti_uia_family_c64p_TimestampC64XLocal_Object_first( void )
{
    return (ti_uia_family_c64p_TimestampC64XLocal_Handle)ti_uia_family_c64p_TimestampC64XLocal_Object__first__S();
}

/* Object_next */
static inline ti_uia_family_c64p_TimestampC64XLocal_Handle ti_uia_family_c64p_TimestampC64XLocal_Object_next( ti_uia_family_c64p_TimestampC64XLocal_Object *obj )
{
    return (ti_uia_family_c64p_TimestampC64XLocal_Handle)ti_uia_family_c64p_TimestampC64XLocal_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_uia_family_c64p_TimestampC64XLocal_Handle_label( ti_uia_family_c64p_TimestampC64XLocal_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_uia_family_c64p_TimestampC64XLocal_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_uia_family_c64p_TimestampC64XLocal_Handle_name( ti_uia_family_c64p_TimestampC64XLocal_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_uia_family_c64p_TimestampC64XLocal_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_uia_family_c64p_TimestampC64XLocal_Handle ti_uia_family_c64p_TimestampC64XLocal_handle( ti_uia_family_c64p_TimestampC64XLocal_Struct *str )
{
    return (ti_uia_family_c64p_TimestampC64XLocal_Handle)str;
}

/* struct */
static inline ti_uia_family_c64p_TimestampC64XLocal_Struct *ti_uia_family_c64p_TimestampC64XLocal_struct( ti_uia_family_c64p_TimestampC64XLocal_Handle inst )
{
    return (ti_uia_family_c64p_TimestampC64XLocal_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_uia_family_c64p_TimestampC64XLocal__top__
#undef __nested__
#endif

#endif /* ti_uia_family_c64p_TimestampC64XLocal__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_uia_family_c64p_TimestampC64XLocal__internalaccess))

#ifndef ti_uia_family_c64p_TimestampC64XLocal__include_state
#define ti_uia_family_c64p_TimestampC64XLocal__include_state

/* Module_State */
struct ti_uia_family_c64p_TimestampC64XLocal_Module_State {
    xdc_runtime_Types_FreqHz freq;
};

/* Module__state__V */
extern struct ti_uia_family_c64p_TimestampC64XLocal_Module_State__ ti_uia_family_c64p_TimestampC64XLocal_Module__state__V;

/* Object */
struct ti_uia_family_c64p_TimestampC64XLocal_Object {
    const ti_uia_family_c64p_TimestampC64XLocal_Fxns__ *__fxns;
};

#endif /* ti_uia_family_c64p_TimestampC64XLocal__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_uia_family_c64p_TimestampC64XLocal__nolocalnames)

#ifndef ti_uia_family_c64p_TimestampC64XLocal__localnames__done
#define ti_uia_family_c64p_TimestampC64XLocal__localnames__done

/* module prefix */
#define TimestampC64XLocal_Instance ti_uia_family_c64p_TimestampC64XLocal_Instance
#define TimestampC64XLocal_Handle ti_uia_family_c64p_TimestampC64XLocal_Handle
#define TimestampC64XLocal_Module ti_uia_family_c64p_TimestampC64XLocal_Module
#define TimestampC64XLocal_Object ti_uia_family_c64p_TimestampC64XLocal_Object
#define TimestampC64XLocal_Struct ti_uia_family_c64p_TimestampC64XLocal_Struct
#define TimestampC64XLocal_Module_State ti_uia_family_c64p_TimestampC64XLocal_Module_State
#define TimestampC64XLocal_Instance_State ti_uia_family_c64p_TimestampC64XLocal_Instance_State
#define TimestampC64XLocal_maxTimerClockFreq ti_uia_family_c64p_TimestampC64XLocal_maxTimerClockFreq
#define TimestampC64XLocal_maxBusClockFreq ti_uia_family_c64p_TimestampC64XLocal_maxBusClockFreq
#define TimestampC64XLocal_Params ti_uia_family_c64p_TimestampC64XLocal_Params
#define TimestampC64XLocal_get32 ti_uia_family_c64p_TimestampC64XLocal_get32
#define TimestampC64XLocal_get64 ti_uia_family_c64p_TimestampC64XLocal_get64
#define TimestampC64XLocal_getFreq ti_uia_family_c64p_TimestampC64XLocal_getFreq
#define TimestampC64XLocal_setFreq ti_uia_family_c64p_TimestampC64XLocal_setFreq
#define TimestampC64XLocal_Module_name ti_uia_family_c64p_TimestampC64XLocal_Module_name
#define TimestampC64XLocal_Module_id ti_uia_family_c64p_TimestampC64XLocal_Module_id
#define TimestampC64XLocal_Module_startup ti_uia_family_c64p_TimestampC64XLocal_Module_startup
#define TimestampC64XLocal_Module_startupDone ti_uia_family_c64p_TimestampC64XLocal_Module_startupDone
#define TimestampC64XLocal_Module_hasMask ti_uia_family_c64p_TimestampC64XLocal_Module_hasMask
#define TimestampC64XLocal_Module_getMask ti_uia_family_c64p_TimestampC64XLocal_Module_getMask
#define TimestampC64XLocal_Module_setMask ti_uia_family_c64p_TimestampC64XLocal_Module_setMask
#define TimestampC64XLocal_Object_heap ti_uia_family_c64p_TimestampC64XLocal_Object_heap
#define TimestampC64XLocal_Module_heap ti_uia_family_c64p_TimestampC64XLocal_Module_heap
#define TimestampC64XLocal_construct ti_uia_family_c64p_TimestampC64XLocal_construct
#define TimestampC64XLocal_create ti_uia_family_c64p_TimestampC64XLocal_create
#define TimestampC64XLocal_handle ti_uia_family_c64p_TimestampC64XLocal_handle
#define TimestampC64XLocal_struct ti_uia_family_c64p_TimestampC64XLocal_struct
#define TimestampC64XLocal_Handle_label ti_uia_family_c64p_TimestampC64XLocal_Handle_label
#define TimestampC64XLocal_Handle_name ti_uia_family_c64p_TimestampC64XLocal_Handle_name
#define TimestampC64XLocal_Instance_init ti_uia_family_c64p_TimestampC64XLocal_Instance_init
#define TimestampC64XLocal_Object_count ti_uia_family_c64p_TimestampC64XLocal_Object_count
#define TimestampC64XLocal_Object_get ti_uia_family_c64p_TimestampC64XLocal_Object_get
#define TimestampC64XLocal_Object_first ti_uia_family_c64p_TimestampC64XLocal_Object_first
#define TimestampC64XLocal_Object_next ti_uia_family_c64p_TimestampC64XLocal_Object_next
#define TimestampC64XLocal_Object_sizeof ti_uia_family_c64p_TimestampC64XLocal_Object_sizeof
#define TimestampC64XLocal_Params_copy ti_uia_family_c64p_TimestampC64XLocal_Params_copy
#define TimestampC64XLocal_Params_init ti_uia_family_c64p_TimestampC64XLocal_Params_init
#define TimestampC64XLocal_Instance_State ti_uia_family_c64p_TimestampC64XLocal_Instance_State
#define TimestampC64XLocal_delete ti_uia_family_c64p_TimestampC64XLocal_delete
#define TimestampC64XLocal_destruct ti_uia_family_c64p_TimestampC64XLocal_destruct
#define TimestampC64XLocal_Module_upCast ti_uia_family_c64p_TimestampC64XLocal_Module_upCast
#define TimestampC64XLocal_Module_to_ti_uia_runtime_IUIATimestampProvider ti_uia_family_c64p_TimestampC64XLocal_Module_to_ti_uia_runtime_IUIATimestampProvider
#define TimestampC64XLocal_Module_upCast2 ti_uia_family_c64p_TimestampC64XLocal_Module_upCast2
#define TimestampC64XLocal_Module_to_xdc_runtime_ITimestampProvider ti_uia_family_c64p_TimestampC64XLocal_Module_to_xdc_runtime_ITimestampProvider
#define TimestampC64XLocal_Module_upCast3 ti_uia_family_c64p_TimestampC64XLocal_Module_upCast3
#define TimestampC64XLocal_Module_to_xdc_runtime_ITimestampClient ti_uia_family_c64p_TimestampC64XLocal_Module_to_xdc_runtime_ITimestampClient

#endif /* ti_uia_family_c64p_TimestampC64XLocal__localnames__done */
#endif
