/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/**
*   @file    Can_43_FLEXCAN.c
*   @version 2.0.0
*   @file    Can_43_FLEXCAN.c
*
*   @brief   AUTOSAR Can_43_FLEXCAN - module interface
*   @details API implementation for CAN driver.
*
*   @addtogroup CAN_43_FLEXCAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, External identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 8.7, Functions and objects should not be defined with external linkage if they are referenced in only one translation unit.
* For API functions (<MA>.c): These functions represent the API of the driver. External linkage is needed to "export" the API.
*
* @section Can_43_FLEXCAN_c_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents
* of a header file being included more than once
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Can_43_FLEXCAN_c_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include directives should only be preceded by preprocessor
* directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Can_43_FLEXCAN_c_REF_3
* Violates MISRA 2012 Advisory Rule 4.9, A function should be used in preference to a function-like macro where they are interchangeable.
* Function like macro are used to reduce code complexity
*
* @section Can_43_FLEXCAN_c_REF_5
* Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block scope if its identifier only appears
* in a single function.
* These objects are used when Precompile is supported.
*
*/


/*
Driver Limitations:
    1. The maximum number of Can_DisableControllerInterrupts levels of nesting is 127. (variable "sint8" used for nesting level: -128 .. +127)
    2. This file contains 2 types of functions: first are the Autosar APIs and then are some user defined functions.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file           Can.c
*/
#include "Can_43_FLEXCAN.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "Can_43_FLEXCAN_Irq.h"
#include "Can_43_FLEXCAN_Ipw.h"
#include "CanIf_Can.h"

#if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
#include "Mcal.h"
#endif

#ifdef CAN_43_FLEXCAN_WAKEUP_SUPPORT
    #if (CAN_43_FLEXCAN_WAKEUP_SUPPORT == STD_ON)
        #include "EcuM.h"
    #endif
#endif
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
#if (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON)
    #include "CanCanXLShared.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*   Can.c shall check if the correct version of Can.h is included.
            This shall be done by a preprocessor check of the version numbers CAN_43_FLEXCAN_SW_MAJOR_VERSION, CAN_43_FLEXCAN_SW_MINOR_VERSION and CAN_43_FLEXCAN_SW_PATCH_VERSION.
*/
/**
* @file           Can.c
*/
#define CAN_43_FLEXCAN_VENDOR_ID_C                      43
#define CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C       4
#define CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_C       7
#define CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_C    0
#define CAN_43_FLEXCAN_SW_MAJOR_VERSION_C               2
#define CAN_43_FLEXCAN_SW_MINOR_VERSION_C               0
#define CAN_43_FLEXCAN_SW_PATCH_VERSION_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CAN header file are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID_C != CAN_43_FLEXCAN_VENDOR_ID)
    #error "Can_43_FLEXCAN.c and CAN_43_FLEXCAN.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C    != CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_C    != CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_C != CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN.c and CAN_43_FLEXCAN.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION_C != CAN_43_FLEXCAN_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_SW_MINOR_VERSION_C != CAN_43_FLEXCAN_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_SW_PATCH_VERSION_C != CAN_43_FLEXCAN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN.c and CAN_43_FLEXCAN.h are different"
#endif

/* Check if current file and Can_43_FLEXCAN_IPW header file are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID_C != CAN_43_FLEXCAN_IPW_VENDOR_ID_H)
    #error "Can_43_FLEXCAN.c and Can_43_FLEXCAN_IPW.h have different vendor ids"
#endif
/* Check if current file and Can_43_FLEXCAN_IPW header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C    != CAN_43_FLEXCAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_C    != CAN_43_FLEXCAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_C != CAN_43_FLEXCAN_IPW_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN.c and Can_43_FLEXCAN_IPW.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN_IPW header file are of the same Software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION_C != CAN_43_FLEXCAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_SW_MINOR_VERSION_C != CAN_43_FLEXCAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_SW_PATCH_VERSION_C != CAN_43_FLEXCAN_IPW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN.c and Can_43_FLEXCAN_IPW.h are different"
#endif

/* Check if current file and Can_43_FLEXCAN_Irq header file are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID_C != CAN_43_FLEXCAN_IRQ_VENDOR_ID)
    #error "Can_43_FLEXCAN.c and Can_43_FLEXCAN_Irq.h have different vendor ids"
#endif
/* Check if current file and Can_43_FLEXCAN_Irq header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C    != CAN_43_FLEXCAN_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_C    != CAN_43_FLEXCAN_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_C != CAN_43_FLEXCAN_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN.c and Can_43_FLEXCAN_Irq.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN_Irq header file are of the same Software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION_C != CAN_43_FLEXCAN_IRQ_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_SW_MINOR_VERSION_C != CAN_43_FLEXCAN_IRQ_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_SW_PATCH_VERSION_C != CAN_43_FLEXCAN_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN.c and Can_43_FLEXCAN_Irq.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and DET header file are of the same version */
    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        #if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Can_43_FLEXCAN.c and Det.h are different"
        #endif
    #endif

    /* Check if current file and CanIf_Can header file are of the same version */
    #if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C != CANIF_CAN_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_C != CANIF_CAN_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Can_43_FLEXCAN.c and CanIf_Can.h are different"
    #endif

    /* Check if current file and Mcal header file are of the same version */
    #if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Can_43_FLEXCAN.c and Mcal.h are different"
    #endif

    /* Check if current file and EcuM header file are of the same version */
    #ifdef CAN_43_FLEXCAN_WAKEUP_SUPPORT
        #if (CAN_43_FLEXCAN_WAKEUP_SUPPORT == STD_ON)
            #if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
                 (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) \
                )
                #error "AutoSar Version Numbers of Can_43_FLEXCAN.c and EcuM.h are different"
            #endif
        #endif
    #endif

    /* Check if current file and SchM_Flexcan header file are of the same Autosar version */
    #if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C   != SCHM_CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_C    != SCHM_CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Can.c and Schm_Can_43_FLEXCAN.h are different"
    #endif
#endif

#if (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON)
/* Check if current file and CanCanXLShared header file are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID_C != CAN_CANXLSHARED_VENDOR_ID)
    #error "Can_43_FLEXCAN.c and CanCanXLShared.h have different vendor ids"
#endif
/* Check if current file and CanCanXLShared header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_C !=    CAN_CANXLSHARED_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_C !=    CAN_CANXLSHARED_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_C != CAN_CANXLSHARED_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN.c and CanCanXLShared.h are different"
#endif
/* Check if current file and CanCanXLShared header file are of the same software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION_C != CAN_CANXLSHARED_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_SW_MINOR_VERSION_C != CAN_CANXLSHARED_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_SW_PATCH_VERSION_C != CAN_CANXLSHARED_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN.c and CanCanXLShared.h are different"
#endif
#endif /* Endif (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON) */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
    /* @violates @ref Can_43_FLEXCAN_c_REF_3 MISRA 2012 Advisory Rule 4.9 */
    #define Can_GetCoreID()       ((uint32)OsIf_GetCoreID())
#else
    /* @violates @ref Can_43_FLEXCAN_c_REF_3 MISRA 2012 Advisory Rule 4.9 */
    #define Can_GetCoreID()       ((uint32)0UL)
#endif

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
#else
#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_16
#endif /* (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON) */
/* @violates @ref Can_43_FLEXCAN_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"
#if ((CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON) || (CAN_43_FLEXCAN_DUAL_CLOCK_MODE == STD_ON))
    static uint16 Can_au16BaudrateIDConfig[CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT];
#endif

#if (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
#else
#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_16
#endif /* (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON) */
/* @violates @ref Can_43_FLEXCAN_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

#if (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_8
#endif /* (CAN_43_FLEXCAN_PRECOMPILE_SUPPORT == STD_ON) */
/* @violates @ref Can_43_FLEXCAN_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

static uint8 Can_au8DisableInterruptLevel[CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT];

#if (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_8
#endif /* (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON) */
/* @violates @ref Can_43_FLEXCAN_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

#if (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON) */
/* @violates @ref Can_43_FLEXCAN_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

#if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
    static const Can_43_FLEXCAN_IcomConfigsType * Can_apxCtrlConfigIcomIndex[CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT];
#endif

/**
* @brief          Store the state of Can Controller
*/
static Can_ControllerStateType Can_eControllerState[CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT];

/**
* @brief          This variable holds the state of the driver.
* @details        This variable holds the state of the driver. After reset is UNINIT. The output of Can_Init() function
*                 (only to first call) should set this variable into READY state.
*                  CAN_43_FLEXCAN_UNINIT = The CAN controller is not initialized. All registers belonging to the CAN module are in reset state, CAN interrupts are disabled.
*                  The CAN Controller is not participating on the CAN bus.
*                  The Can module must only implement a variable for the module state, when the development error tracing is switched on.
*                  When the development error tracing is switched off, the Can module does not need to implement this 'state machine',
*                  because the state information is only needed to check if Can_Init was called prior to any Can module function.
*/

/*
*   [SWS_Can_00103] After power-up/reset, the Can module shall be in the state CAN_UNINIT.
*/
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    static Can_43_FLEXCAN_DriverStatusType Can_eDriverStatus[CAN_43_FLEXCAN_MAX_PARTITIONS];
#endif
/* Pointer to the current Driver Configuration (passed to the driver during initialization). Initialized by Can_Init(). */
static const Can_43_FLEXCAN_ConfigType * Can_apxConfig[CAN_43_FLEXCAN_MAX_PARTITIONS];

#if (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON)
#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* (CAN_43_FLEXCAN_NO_CACHE_NEEDED == STD_ON) */
/* @violates @ref Can_43_FLEXCAN_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

#if (CAN_43_FLEXCAN_PRECOMPILE_SUPPORT == STD_ON)
    #define CAN_43_FLEXCAN_START_SEC_CONFIG_DATA_UNSPECIFIED
    /* @violates @ref Can_43_FLEXCAN_c_REF_1 MISRA 2012 Required Directive 4.10 */
    /* @violates @ref Can_43_FLEXCAN_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
    #include "Can_43_FLEXCAN_MemMap.h"
    #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
        /* @violates @ref Can_43_FLEXCAN_c_REF_5 MISRA 2012 Advisory Rule 8.9 */
        extern const Can_43_FLEXCAN_ConfigType * const Can_43_FLEXCAN_Config[CAN_43_FLEXCAN_MAX_PARTITIONS];
    #else
        /* @violates @ref Can_43_FLEXCAN_c_REF_5 MISRA 2012 Advisory Rule 8.9 */
        extern const Can_43_FLEXCAN_ConfigType Can_43_FLEXCAN_Config;
    #endif
    #define CAN_43_FLEXCAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /* @violates @ref Can_43_FLEXCAN_c_REF_1 MISRA 2012 Required Directive 4.10 */
    /* @violates @ref Can_43_FLEXCAN_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
    #include "Can_43_FLEXCAN_MemMap.h"
#endif

#define CAN_43_FLEXCAN_START_SEC_CODE
/* @violates @ref Can_43_FLEXCAN_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_WRITE == STD_ON)
    static void Can_MainFunction_MultipleWrite(uint8 u8WritePoll);
#endif
#if (CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_READ == STD_ON)
    static void Can_MainFunction_MultipleRead(uint8 u8ReadPoll);
#endif
static boolean Can_IsControllersBusy(uint32 u32CoreId);
static void Can_InitControllers(uint32 u32CoreId);

#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_ValidateController(uint32 u32CoreId, uint8 u8ControllerID, uint8 u8Sid);

static boolean Can_ValidateHth(uint32 u32CoreId, Can_HwHandleType Hth);

static boolean Can_ValidatePdu(const Can_43_FLEXCAN_ControllerConfigType * Can_pController, const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObject, const Can_PduType * PduInfo);
#endif

static void Can_DeInitControllers(uint32 u32CoreId);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_WRITE == STD_ON)
    /**
    *   @brief      This function performs polling all HTHs having same CanMainFunctionRWPeriods referred.
    *
    *   @param[in]      u8WritePoll: The id of CanMainFunctionRWPeriods.
    *
    */
    static void Can_MainFunction_MultipleWrite(uint8 u8WritePoll)
    {
        Can_HwHandleType HwObjectID = 0U;
        uint8 u8ControllerID = 0U;
        uint32 u32CoreId = 0U;
        const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

        u32CoreId = Can_GetCoreID();
        if (NULL_PTR != (Can_apxConfig[u32CoreId]))
        {
            HwObjectID = (Can_apxConfig[u32CoreId])->Can_uHthFirstIndex;
            while (HwObjectID < CAN_43_FLEXCAN_HWOBJECT_CONFIG_COUNT)
            {
                u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pHwObjIDToCtrlIDMap[HwObjectID];
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                if (NULL_PTR != Can_pController)
                {
                    if (TRUE == Can_pController->Can_bActivation)
                    {
                        if (u8WritePoll == (Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID].Can_MainFuncPeriodIndex)
                        {
                            Can_43_FLEXCAN_Ipw_MainFunction_Write(Can_pController, &((Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID]));
                        }
                    }
                }
                HwObjectID++;
            }
        #if (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON)
            HwObjectID = (Can_apxConfig[u32CoreId])->CanXL_uHthFirstIndex;
            while (HwObjectID < CAN_43_FLEXCAN_XL_HWOBJECT_CONFIG_COUNT)
            {
                u8ControllerID = (Can_apxConfig[u32CoreId])->CanXL_pHwObjIDToCtrlIDMap[HwObjectID];
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                if ((TRUE == Can_pController->Can_bActivation) && (u8WritePoll == (Can_apxConfig[u32CoreId])->CanXL_pHwObjectConfig[HwObjectID].Can_MainFuncPeriodIndex))
                {
                    CanXL_43_FLEXCAN_Ipw_MainFunction_Write(Can_pController, &((Can_apxConfig[u32CoreId])->CanXL_pHwObjectConfig[HwObjectID]));
                }
                HwObjectID++;
            }
        #endif /* (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON) */
        }
    }
#endif /* CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_WRITE == STD_ON */

#if (CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_READ == STD_ON)
    /**
    *   @brief      This function performs polling all HRHs having same CanMainFunctionRWPeriods referred.
    *
    *   @param[in]      u8ReadPoll: The id of CanMainFunctionRWPeriods.
    *
    */
    static void Can_MainFunction_MultipleRead(uint8 u8ReadPoll)
    {
        Can_HwHandleType HwObjectID = 0U;
        uint8 u8ControllerID = 0U;
        uint32 u32CoreId = 0U;
        const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

        u32CoreId = Can_GetCoreID();
        if (NULL_PTR != (Can_apxConfig[u32CoreId]))
        {
            while (HwObjectID < (Can_apxConfig[u32CoreId])->Can_uHthFirstIndex)
            {
                u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pHwObjIDToCtrlIDMap[HwObjectID];
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                if (NULL_PTR != Can_pController)
                {
                    if (TRUE == Can_pController->Can_bActivation)
                    {
                        if (u8ReadPoll == (Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID].Can_MainFuncPeriodIndex)
                        {
                            Can_43_FLEXCAN_Ipw_MainFunction_Read(Can_pController, &((Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID]));
                        }
                    }
                }
                HwObjectID++;
            }
    #if (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON)
            HwObjectID = 0U;
            while (HwObjectID < (Can_apxConfig[u32CoreId])->CanXL_uHthFirstIndex)
            {
                u8ControllerID = (Can_apxConfig[u32CoreId])->CanXL_pHwObjIDToCtrlIDMap[HwObjectID];
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                if ((TRUE == Can_pController->Can_bActivation) && (u8ReadPoll == (Can_apxConfig[u32CoreId])->CanXL_pHwObjectConfig[HwObjectID].Can_MainFuncPeriodIndex))
                {
                    CanXL_43_FLEXCAN_Ipw_MainFunction_Read(Can_pController, &((Can_apxConfig[u32CoreId])->CanXL_pHwObjectConfig[HwObjectID]));
                }
                HwObjectID++;
            }
    #endif /* (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON) */
        }
    }
#endif /* CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_READ == STD_ON */

static boolean Can_IsControllersBusy(uint32 u32CoreId)
{
    boolean bCtrlBusy = FALSE;
    uint8 u8ControllerID = 0U;

    for (u8ControllerID = 0U; u8ControllerID < CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
    {
        if (NULL_PTR != (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID])
        {
            if (CAN_CS_UNINIT != Can_eControllerState[u8ControllerID])
            {
            #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                /*
                *   [SWS_Can_00408] If development error detection for the Can module is enabled:
                *   The function Can_Init shall raise the error CAN_E_TRANSITION if the CAN
                *   controllers are not in state UNINIT.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_INIT, CAN_43_FLEXCAN_E_TRANSITION);
            #endif
                bCtrlBusy = TRUE;
                break;
            }
        }
    }

    return bCtrlBusy;
}

static void Can_InitControllers(uint32 u32CoreId)
{
    boolean bCtrlBusy = FALSE;
    uint8 u8ControllerID = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    /* Loop through all Can controllers configured based CanControllerId parameter. */
    for (u8ControllerID = 0U; u8ControllerID < CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
    {
        if (NULL_PTR != (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID])
        {
            Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
            /* The initialization is skipped for the controllers that are not enabled. */
            if (TRUE == Can_pController->Can_bActivation)
            {
                /*
                *   [SWS_Can_00250] The function Can_Init shall initialize: static variables, including flags,
                *   Common setting for the complete CAN HW unit, CAN controller specific settings for each CAN controller.
                *
                *   [SWS_Can_00245] The function Can_Init shall initialize all CAN controllers according to their configuration.
                *
                *   [SWS_Can_00053] Can_Init shall not change registers of CAN controller Hardware resources that are not used.
                */
            #if ((CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON) || (CAN_43_FLEXCAN_DUAL_CLOCK_MODE == STD_ON))
                Can_au16BaudrateIDConfig[u8ControllerID] = Can_pController->Can_u16DefaultBaudrateID;
            #endif
                /* Reset interrupt level to default value after re-init */
                Can_au8DisableInterruptLevel[u8ControllerID] = 0U;
            #if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                Can_apxCtrlConfigIcomIndex[u8ControllerID] = NULL_PTR;
            #endif
                /* Init the controller */
                if ((Std_ReturnType)E_OK == Can_43_FLEXCAN_Ipw_Init(Can_pController))
                {
                    Can_eControllerState[u8ControllerID] = CAN_CS_STOPPED;
                }
                else
                {
                    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_INIT, CAN_43_FLEXCAN_E_INIT_FAILED);
                    #endif
                    bCtrlBusy = TRUE;
                    break;
                }
            }
        }
    }
    /*
    *  [SWS_Can_00246] After initializing all controllers inside the HW Unit, the function Can_Init
    *   shall change the module state to CAN_READY.
    */
    if (TRUE == bCtrlBusy)
    {
        /* Init failed due to one or more controllers failed, reset status of all  core's current controllers */
        for (u8ControllerID = 0U; u8ControllerID < CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
        {
            if (NULL_PTR != (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID])
            {
                Can_eControllerState[u8ControllerID] = CAN_CS_UNINIT;
            }
        }
    }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    else
    {
        Can_eDriverStatus[u32CoreId] = CAN_43_FLEXCAN_READY;
    }
#endif
}

#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_ValidateController(uint32 u32CoreId, uint8 u8ControllerID, uint8 u8Sid)
{
    boolean bResult = FALSE;

    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        /*
        *   If development error detection for the Can module is enabled:
        *   The function shall raise the error CAN_E_UNINIT and return
        *   E_NOT_OK if the driver is not yet initialized.
        */
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, u8Sid, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if (u8ControllerID >= CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            /*
            *   If development error detection for the Can module is enabled:
            *   the function shall raise the error CAN_E_PARAM_CONTROLLER and
            *   return E_NOT_OK if the parameter Controller is out of range.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, u8Sid, CAN_43_FLEXCAN_E_PARAM_CONTROLLER);
        }
        else
        {
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (NULL_PTR == (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID])
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, u8Sid, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
            else
            {
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
                bResult = TRUE;
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }

    return bResult;
}

static boolean Can_ValidateHth(uint32 u32CoreId, Can_HwHandleType Hth)
{
    boolean bResult = FALSE;

    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        /*
        *   If development error detection for the Can module is enabled:
        *   The function shall raise the error CAN_E_UNINIT and shall return
        *   E_NOT_OK if the driver is not yet initialized.
        */
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_WRITE, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if ((Hth >= CAN_43_FLEXCAN_HWOBJECT_CONFIG_COUNT) || (Hth < (Can_apxConfig[u32CoreId])->Can_uHthFirstIndex))
        {
            /*
            *   If development error detection for the Can module is enabled:
            *   The function shall raise the error CAN_E_PARAM_HANDLE and shall
            *   return E_NOT_OK if the parameter Hth is not a configured Hardware Transmit Handle.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_WRITE, CAN_43_FLEXCAN_E_PARAM_HANDLE);
        }
        else
        {
            bResult = TRUE;
        }
    }

    return bResult;
}

static boolean Can_ValidatePdu(const Can_43_FLEXCAN_ControllerConfigType * Can_pController, const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObject, const Can_PduType * PduInfo)
{
    uint16 u16BaudrateID = 0U;
    boolean bResult = FALSE;
    boolean bInvalidDataLength = FALSE;

    u16BaudrateID = Can_au16BaudrateIDConfig[Can_pController->Can_u8ControllerID];
    /*
    *   [SWS_Can_00218]: The function Can_Write shall return E_NOT_OK and if
    *   development error detection for the CAN module is enabled shall raise the error
    *   CAN_E_PARAM_DATA_LENGTH:
    *       - If the length is more than 64 byte.
    *       - If the length is more than 8 byte and the CAN controller is not in CAN FD
    *           mode (no CanControllerFdBaudrateConfig).
    *       - If the length is more than 8 byte and the CAN controller is in CAN FD mode
    *           (valid CanControllerFdBaudrateConfig), but the CAN FD flag in Can_PduType->id is not set.
    */
    if (TRUE == Can_pController->Can_pBaudrateConfig[u16BaudrateID].Can_bFDFrame)
    {
        if ((PduInfo->length > Can_pHwObject->Can_u8PayloadLength) || ((PduInfo->length > 8U) && (CAN_43_FLEXCAN_FD_FRAME_U32 != (PduInfo->id & CAN_43_FLEXCAN_FD_FRAME_U32))))
        {
            bInvalidDataLength = TRUE;
        }
    }
    else
    {
        if (PduInfo->length > 8U)
        {
            bInvalidDataLength = TRUE;
        }
    }
    if (TRUE == bInvalidDataLength)
    {
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_WRITE, CAN_43_FLEXCAN_E_PARAM_DATA_LENGTH);
    }
    else
    {
        if ((NULL_PTR == PduInfo->sdu) && (FALSE == Can_pHwObject->Can_bTriggerTransmit))
        {
            /*
            *   [SWS_Can_00505]: If development error detection for CanDrv is enabled:
            *   Can_Write() shall raise CAN_E_PARAM_POINTER and shall return E_NOT_OK if the
            *   trigger transmit API is disabled for this hardware object (CanTriggerTransmitEnable = FALSE)
            *   and the SDU pointer inside PduInfo is a null pointer.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_WRITE, CAN_43_FLEXCAN_E_PARAM_POINTER);
        }
        else
        {
            bResult = TRUE;
        }
    }

    return bResult;
}
#endif

static void Can_DeInitControllers(uint32 u32CoreId)
{
    uint8 u8ControllerID = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    /* Loop through all Can controllers configured based CanControllerId parameter. */
    for (u8ControllerID = 0U; u8ControllerID < CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
    {
        if (NULL_PTR != (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID])
        {
            Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
            /* The initialization is skipped for the controllers that are not enabled. */
            if (TRUE == Can_pController->Can_bActivation)
            {
                Can_eControllerState[u8ControllerID] = CAN_CS_UNINIT;
                Can_43_FLEXCAN_Ipw_DeInit(Can_pController);
            }
        }
    }
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (CAN_43_FLEXCAN_VERSION_INFO_API == STD_ON)
    /**
    * @brief          Returns the version information of this module. SID is 0x07
    * @details        This routine is called by:
    *                - CanIf or an upper layer according to Autosar requirements.
    *
    * @param[in]      versioninfo A pointer to location to store version info
    *                             Must be omitted if the function does not have parameters.
    *
    * @return         void
    *
    *
    * @pre            The CAN_VERSION_INFO_API define must be configured on.
    * @post           The version information is return if the parameter versionInfo is not a null pointer.
    *
    * @api
    *
    */
    /* implements     Can_GetVersionInfo_Activity */
    void Can_43_FLEXCAN_GetVersionInfo(Std_VersionInfoType * versioninfo)
    {
    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        /*
        (SWS_Can_00177) If development error detection for the Can module is enabled: The function Can_GetVersionInfo shall
                    raise the error CAN_E_PARAM_POINTER if the parameter versionInfo is a null pointer.
        */
        if (NULL_PTR == versioninfo)
        {
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, (uint8)CAN_43_FLEXCAN_INSTANCE, (uint8)CAN_43_FLEXCAN_SID_GET_VERSION_INFO, (uint8)CAN_43_FLEXCAN_E_PARAM_POINTER);
        }
        else
        {
    #endif
            /*
                The function Can_GetVersionInfo shall return the version information of this module. The version information
                includes: Module Id, Vendor Id, Vendor specific version numbers.
            */
            versioninfo->vendorID         = (uint16)CAN_43_FLEXCAN_VENDOR_ID;
            versioninfo->moduleID         = (uint16)CAN_43_FLEXCAN_MODULE_ID;
            versioninfo->sw_major_version = (uint8)CAN_43_FLEXCAN_SW_MAJOR_VERSION;
            versioninfo->sw_minor_version = (uint8)CAN_43_FLEXCAN_SW_MINOR_VERSION;
            versioninfo->sw_patch_version = (uint8)CAN_43_FLEXCAN_SW_PATCH_VERSION;
    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        }
    #endif
    }
#endif /* CAN_43_FLEXCAN_VERSION_INFO_API == STD_ON */

/**
* @brief          Initialize the CAN driver. SID is 0x00.
* @details        Initialize all the controllers.
*                 The CAN module shall be initialized by Can_Init(<&Can_Configuration>) service call during the start-up.
*                 This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Config Pointer to driver configuration.
*
* @return         void
*
*
* @pre            Can_Init shall be called at most once during runtime.
* @post           Can_Init shall initialize all the controllers and set the driver in READY state.
*
* @api
*/

/* implements     Can_Init_Activity */
void Can_43_FLEXCAN_Init(const Can_43_FLEXCAN_ConfigType * Config)
{
    uint32 u32CoreId = 0U;
    boolean bCtrlBusy = FALSE;
#if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
    boolean bValidCoreID = FALSE;
#endif

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_READY == Can_eDriverStatus[u32CoreId])
    {
        /*
        *   [SWS_Can_00091] After return of the DET the Can module function that raised
        *   the development error shall return immediately.
        *
        *   [SWS_Can_00174] If development error detection for the Can module is enabled:
        *   The function Can_Init shall raise the error CAN_E_TRANSITION if the driver
        *   is not in state CAN_UNINIT.
        */
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_INIT, CAN_43_FLEXCAN_E_TRANSITION);
    }
    else
    {
    #if (CAN_43_FLEXCAN_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR != Config)
    #else
        if (NULL_PTR == Config)
    #endif
        {
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_INIT, CAN_43_FLEXCAN_E_INIT_FAILED);
        }
        else
        {
#endif
    #if (CAN_43_FLEXCAN_PRECOMPILE_SUPPORT == STD_ON)
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (NULL_PTR != Can_43_FLEXCAN_Config[u32CoreId])
            {
                /* Update config pointer with default configuration if precompile support on. */
                Can_apxConfig[u32CoreId] = Can_43_FLEXCAN_Config[u32CoreId];
                bValidCoreID = TRUE;
            }
        #else
            /* Update config pointer with default configuration if precompile support on. */
            Can_apxConfig[u32CoreId] = &Can_43_FLEXCAN_Config;
        #endif
            (void)Config; /* Prevent compiler warning */
    #else
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (u32CoreId == Config->Can_u32CoreID)
            {
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
                /* Copy pointer to current Can Driver configuration. */
                Can_apxConfig[u32CoreId] = Config;
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
                bValidCoreID = TRUE;
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
    #endif /* (CAN_43_FLEXCAN_PRECOMPILE_SUPPORT == STD_ON) */
#if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (TRUE == bValidCoreID)
            {
#endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
                /* Fault Injection point to allow to test SWS_Can_00408 */
                MCAL_FAULT_INJECTION_POINT(CAN_FIP_1_CHANGE_DRIVER_TO_UNINITIALIZED);
                bCtrlBusy = Can_IsControllersBusy(u32CoreId);
                if (FALSE == bCtrlBusy)
                {
                    Can_InitControllers(u32CoreId);
                }
#if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
            else
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_INIT, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
#endif /* (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON) */

#endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */

#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON) */
}

/**
* @brief          De-initialize the CAN driver. SID is 0x10.
* @details        De-initialize all the controllers.
*                 The CAN module shall be de-initialized by Can_DeInit() service call during the start-up.
*                 This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            Before controller de-initalization, the driver must be initialized and the controllers must be not in Start state.
* @post           Can_DeInit shall de-initialize all the controllers and set the driver in UNINIT state.
*
*/
/* implements     Can_DeInit_Activity */
void Can_43_FLEXCAN_DeInit(void)
{
    /* Variable for indexing the controllers. */
    uint8 u8ControllerID = 0U;
    boolean bCtrlBusy = FALSE;
    uint32 u32CoreId = 0U;

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_READY != Can_eDriverStatus[u32CoreId])
    {
        /*
        *   [SWS_Can_91011] If development error detection for the Can module is enabled:
        *   The function Can_DeInit shall raise the error CAN_E_TRANSITION
        *   if the driver is not in state CAN_READY.
        */
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_DEINIT, CAN_43_FLEXCAN_E_TRANSITION);
    }
    else
    {
#endif
        /* Loop through all Can controllers configured based CanControllerId parameter. */
        for (u8ControllerID = 0U; u8ControllerID < CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
        {
            if (NULL_PTR != (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID])
            {
                if (CAN_CS_STARTED == Can_eControllerState[u8ControllerID])
                {
                #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                    /*
                    *   [SWS_Can_91012] If development error detection for the Can module is enabled:
                    *   The function Can_DeInit shall raise the error CAN_E_TRANSITION
                    *   if any of the CAN controllers is in state STARTED.
                    */
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, (uint8)CAN_43_FLEXCAN_INSTANCE, (uint8)CAN_43_FLEXCAN_SID_DEINIT, (uint8)CAN_43_FLEXCAN_E_TRANSITION);
                #endif
                    /* Controller is busy */
                    bCtrlBusy =  TRUE;
                    /* Skipping the loop if any of Can Controller is in state STARTED */
                    break;
                }
            }
        }
        /* All Controllers are not busy */
        if (FALSE == bCtrlBusy)
        {
        #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
            /*
            *   [SWS_Can_91010] The function Can_DeInit shall change the module state to
            *   CAN_UNINIT before de-initializing all controllers inside the HW unit
            */
            Can_eDriverStatus[u32CoreId] = CAN_43_FLEXCAN_UNINIT;
        #endif
            Can_DeInitControllers(u32CoreId);
            Can_apxConfig[u32CoreId] = NULL_PTR;
        }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}


#if (CAN_43_FLEXCAN_SET_BAUDRATE_API == STD_ON)
    /**
    * @brief         This function set baudrate
    * @details       This routine is called by an upper layer.
    *
    * @param[in]     Controller controller ID
    * @param[in]     BaudRateConfigID baudrateID selection
    *
    * @return
    * @retval        E_OK  Switch baudrate operation was ok.
    * @retval        E_NOT_OK  Switch baudrate operation was not ok.
    *
    * @pre           Driver must be initialized.
    */
    /* implements    Can_SetBaudrate_Activity */
    Std_ReturnType Can_43_FLEXCAN_SetBaudrate
    (
        uint8 Controller,
        uint16 BaudRateConfigID
    )
    {
        /* Returns the result of CAN set baudrate */
        Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
        uint32 u32CoreId = 0U;
        const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

        u32CoreId = Can_GetCoreID();
    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        if (TRUE == Can_ValidateController(u32CoreId, Controller, CAN_43_FLEXCAN_SID_SET_BAUDRATE))
        {
    #endif
                    Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[Controller];
                #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                    if (BaudRateConfigID >= Can_pController->Can_u16BaudrateConfigCount)
                    {
                        /*
                        *   [SWS_Can_00493] If development error detection for the Can module is enabled:
                        *   The function Can_SetBaudrate shall raise the error CAN_E_PARAM_BAUDRATE
                        *   and return E_NOT_OK if the parameter BaudRateConfigID has an invalid value
                        */
                        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SET_BAUDRATE, CAN_43_FLEXCAN_E_PARAM_BAUDRATE);
                    }
                    else
                    {
                #endif
                        if (CAN_CS_STOPPED == Can_eControllerState[Controller])
                        {
                            eRetVal = Can_43_FLEXCAN_Ipw_SetBaudrate(Can_pController, BaudRateConfigID);
                        #if ((CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON) || (CAN_43_FLEXCAN_DUAL_CLOCK_MODE == STD_ON))
                            if ((Std_ReturnType)E_OK == eRetVal)
                            {
                                Can_au16BaudrateIDConfig[Controller] = BaudRateConfigID;
                            }
                        #endif
                        }
    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                    }
        }
    #endif
        return eRetVal;
    }
#endif /* CAN_43_FLEXCAN_SET_BAUDRATE_API == STD_ON */

/**
* @brief          Put the controller into a required state. SID is 0x03.
* @details        Switch the controller from one state to another.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller - Can controller for which the status shall be changed - based on configuration order list (CanControllerId).
* @param[in]      Transition - Possible transitions (CAN_CS_STOPPED , CAN_CS_STARTED , CAN_CS_SLEEP)
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK   request accepted.
* @retval         E_NOT_OK  request not accepted, a development error occurred.
*
*
* @pre            Before changing the controller state the driver must be initialized.
* @post           After the transition to the new state the interrupts required for that state must be enebaled.
*
*
* @api
*/
/* implements     Can_SetControllerMode_Activity */
Std_ReturnType Can_43_FLEXCAN_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition)
{
    Std_ReturnType eRetVal = E_NOT_OK;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_ValidateController(u32CoreId, Controller, CAN_43_FLEXCAN_SID_SET_CONTROLLER_MODE))
    {
#endif
                Can_pController = (const Can_43_FLEXCAN_ControllerConfigType *)(Can_apxConfig[u32CoreId])->Can_ppController[Controller];
                /*
                *   [SWS_Can_00017] The function Can_SetControllerMode shall perform software
                *   triggered state transitions of the CAN controller State machine.
                */
                switch (Transition)
                {
                    case CAN_CS_STARTED:
                    {
                        if (CAN_CS_STOPPED == Can_eControllerState[Controller])
                        {
                            /*
                            *   [SWS_Can_00261] The function Can_SetControllerMode(CAN_CS_STARTED) shall set the hardware
                            *   registers in a way that makes the CAN controller participating on the network.
                            *
                            *   [SWS_Can_00384] Each time the CAN controller state machine is triggered with the state
                            *   transition value CAN_CS_STARTED, the function Can_SetControllerMode shall re-initialize
                            *   the controller with the same controller configuration set previously used by
                            *   functions Can_SetBaudrate or Can_Init.
                            */
                            if ((Std_ReturnType)E_OK == Can_43_FLEXCAN_Ipw_SetControllerToStartMode(Can_pController))
                            {
                                Can_eControllerState[Controller] = CAN_CS_STARTED;
                                CanIf_ControllerModeIndication(Can_pController->Can_u8AbstControllerID, CAN_CS_STARTED);
                                eRetVal = E_OK;
                            #if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                                Can_apxCtrlConfigIcomIndex[Controller] = NULL_PTR;
                            #endif
                            }
                        }
                    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                        else
                        {
                            /*
                            *   [SWS_Can_00409] When the function Can_SetControllerMode (CAN_CS_STARTED) is entered and
                            *   the CAN controller is not in state STOPPED it shall detect a invalid state transition
                            */
                            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SET_CONTROLLER_MODE, CAN_43_FLEXCAN_E_TRANSITION);
                        }
                    #endif
                        break;
                    }
                    case CAN_CS_STOPPED:
                    {
                        switch (Can_eControllerState[Controller])
                        {
                            case CAN_CS_STARTED:
                            {
                                /*
                                *   [SWS_Can_00263] The function Can_SetControllerMode(CAN_CS_STOPPED) shall set
                                *   the bits inside the CAN hardware such that the CAN controller stops participating
                                *   on the network.
                                */
                                if ((Std_ReturnType)E_OK == Can_43_FLEXCAN_Ipw_SetControllerToStopMode(Can_pController))
                                {
                                    Can_eControllerState[Controller] = CAN_CS_STOPPED;
                                    CanIf_ControllerModeIndication(Can_pController->Can_u8AbstControllerID, CAN_CS_STOPPED);
                                    eRetVal = E_OK;
                                #if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                                    Can_apxCtrlConfigIcomIndex[Controller] = NULL_PTR;
                                #endif
                                }
                                break;
                            }
                            case CAN_CS_STOPPED:
                            case CAN_CS_SLEEP:
                            {
                                /*
                                *   [SWS_Can_00267] If the CAN HW does not support a sleep mode, the transition
                                *   from SLEEP to STOPPED shall return from the logical sleep mode, but have no
                                *   effect to the CAN controller state (as the controller is already in stopped state).
                                */
                                Can_eControllerState[Controller] = CAN_CS_STOPPED;
                                CanIf_ControllerModeIndication(Can_pController->Can_u8AbstControllerID, CAN_CS_STOPPED);
                                eRetVal = E_OK;
                                break;
                            }
                            default:
                            {
                                /* nothing to do */
                                break;
                            }
                        }
                        break;
                    }
                    case CAN_CS_SLEEP:
                    {
                        /*
                        *   [SWS_Can_00265] The function Can_SetControllerMode(CAN_CS_SLEEP) shall
                        *   set the controller into sleep mode.
                        */
                        switch (Can_eControllerState[Controller])
                        {
                            case CAN_CS_STOPPED:
                            case CAN_CS_SLEEP:
                            {
                                /*
                                *   [SWS_Can_00290] If the CAN HW does not support a sleep mode, the function
                                *   Can_SetControllerMode(CAN_CS_SLEEP) shall set the CAN controller to the
                                *   logical sleep mode.
                                *
                                *   [SWS_Can_00405] This logical sleep mode shall left only, if function
                                *   Can_SetControllerMode(CAN_CS_STOPPED) is called.
                                */
                                Can_eControllerState[Controller] = CAN_CS_SLEEP;
                                CanIf_ControllerModeIndication(Can_pController->Can_u8AbstControllerID, CAN_CS_SLEEP);
                                eRetVal = E_OK;
                                break;
                            }
                            default:
                            {
                            #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                                /*
                                *   [SWS_Can_00411] When the function Can_SetControllerMode(CAN_CS_SLEEP) s entered and
                                *   the CAN controller is neither in state STOPPED nor in state SLEEP, it shall detect
                                *   a invalid  state transition.
                                */
                                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SET_CONTROLLER_MODE, CAN_43_FLEXCAN_E_TRANSITION);
                            #endif
                                break;
                            }
                        }
                        break;
                    }
                    default:
                    {
                    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                        /*
                        *   [SWS_Can_00200] If development error detection for the Can module is enabled: if an invalid transition
                        *   has been requested, the function Can_SetControllerMode shall raise the error CAN_E_TRANSITION and
                        *   return E_NOT_OK
                        */
                        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SET_CONTROLLER_MODE, CAN_43_FLEXCAN_E_TRANSITION);
                    #endif
                        break;
                    }
                }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return eRetVal;
}

#if (CAN_43_FLEXCAN_LISTEN_ONLY_MODE  == STD_ON)
/**
* @brief          Enable or disable Listen Only Mode. SID is 0x32.
* @details        Enable or disable Listen Only Mode.
* @param[in]      Controller - Controller in which ListenOnlyMode will be enabled/disabled.
* @param[in]      State - Enable or Disable the feature (CAN_43_FLEXCAN_NORMAL_MODE , CAN_43_FLEXCAN_LISTEN_MODE )
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK   request accepted.
* @retval         E_NOT_OK  request not accepted, a development error occurred.
*
* @pre            By default when call Can_Init, all controllers are in normal mode.
* @post
*
*
* @api
*/
/* implements     Can_ListenOnlyMode_Activity */
Std_ReturnType Can_43_FLEXCAN_ListenOnlyMode(uint8 Controller, Can_43_FLEXCAN_ListenOnlyType State)
{
    Std_ReturnType eRetVal = E_NOT_OK;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        /*
        *   [SWS_Can_00198] If development error detection for the Can module is enabled:
        *   if the module is not yet initialized, the function Can_ListenOnlyMode shall
        *   raise development error CAN_E_UNINIT and return E_NOT_OK.
        */
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_LISTEN_ONLY_MODE, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if (Controller >= CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            /*
            *   [SWS_Can_00199] If development error detection for the Can module is enabled:
            *   if the parameter Controller is out of range, the function Can_ListenOnlyMode shall
            *   raise development error CAN_E_PARAM_CONTROLLER and return E_NOT_OK.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_LISTEN_ONLY_MODE, CAN_43_FLEXCAN_E_PARAM_CONTROLLER);
        }
        else
        {
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (NULL_PTR == (Can_apxConfig[u32CoreId])->Can_ppController[Controller])
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_LISTEN_ONLY_MODE, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
            else
            {
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
#endif
                Can_pController = (const Can_43_FLEXCAN_ControllerConfigType *)(Can_apxConfig[u32CoreId])->Can_ppController[Controller];
                if ((CAN_43_FLEXCAN_NORMAL_MODE == State) || (CAN_43_FLEXCAN_LISTEN_MODE  == State))
                {
                    if (CAN_CS_STOPPED == Can_eControllerState[Controller])
                    {
                        eRetVal = Can_43_FLEXCAN_Ipw_ListenOnlyMode(Can_pController, State);
                    }
                }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif
    return eRetVal;
}
#endif /* (CAN_43_FLEXCAN_LISTEN_ONLY_MODE == STD_ON) */

/**
* @brief          Disable INTs. SID is 0x04.
* @details        Switch OFF the controller's interrupts.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller for which interrupts shall be disabled - based on configuration order list (CanControllerId).
*
* @return         void
*
*
* @pre            Driver must be initalzied before changing the interrupts state (en or dis).
* @post           Controller must not respond to any interrupt assertion.
*
*
* @api
*/
/* implements     Can_DisableControllerInterrupts_Activity */
void Can_43_FLEXCAN_DisableControllerInterrupts(uint8 Controller)
{
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        /*
        *   [SWS_Can_00205] If development error detection for the Can module is enabled:
        *   The function Can_DisableControllerInterrupts shall raise the error CAN_E_UNINIT
        *   if the driver not yet initialized.
        */
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_DISABLE_CONTROLLER_INTERRUPTS, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if (Controller >= CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            /*
            *   [SWS_Can_00206] If development error detection for the Can module is enabled:
            *   The function Can_DisableControllerInterrupts shall raise the error
            *   CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_DISABLE_CONTROLLER_INTERRUPTS, CAN_43_FLEXCAN_E_PARAM_CONTROLLER);
        }
        else
        {
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (NULL_PTR == (Can_apxConfig[u32CoreId])->Can_ppController[Controller])
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_DISABLE_CONTROLLER_INTERRUPTS, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
            else
            {
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
#endif
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[Controller];
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_00();
                Can_au8DisableInterruptLevel[Controller] += 1U;
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_00();
                Can_43_FLEXCAN_Ipw_DisableControllerInterrupts(Can_pController);
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif
}

/**
* @brief          Enable INTs. SID is 0x05.
* @details        Switch ON the controller's interrupts.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller for which interrupts shall be disabled - based on configuration order list (CanControllerId).
*
* @return         void
*
*
* @pre            Driver must be initalzied before changing the interrupts state (en or dis).
* @post           Controller must respond to interrupt assertion.
*
* @api
*/
/* implements     Can_EnableControllerInterrupts_Activity */
void Can_43_FLEXCAN_EnableControllerInterrupts(uint8 Controller)
{
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        /*
        *   [SWS_Can_00209] If development error detection for the Can module is enabled:
        *   The function Can_EnableControllerInterrupts shall raise the error CAN_E_UNINIT
        *   if the driver not yet initialized.
        */
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_ENABLE_CONTROLLER_INTERRUPTS, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if (Controller >= CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            /*
            *   [SWS_Can_00210] If development error detection for the Can module is enabled:
            *   The function Can_EnableControllerInterrupts shall raise the error
            *   CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_ENABLE_CONTROLLER_INTERRUPTS, CAN_43_FLEXCAN_E_PARAM_CONTROLLER);
        }
        else
        {
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (NULL_PTR == (Can_apxConfig[u32CoreId])->Can_ppController[Controller])
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_ENABLE_CONTROLLER_INTERRUPTS, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
            else
            {
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
#endif
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[Controller];
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_01();
                if (Can_au8DisableInterruptLevel[Controller] > 0U)
                {
                    Can_au8DisableInterruptLevel[Controller] -= 1U;
                }
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_01();

                if (0U == Can_au8DisableInterruptLevel[Controller])
                {
                    Can_43_FLEXCAN_Ipw_EnableControllerInterrupts(Can_pController);
                }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif
}


#if (CAN_43_FLEXCAN_CHECK_WAKEUP_API == STD_ON)
    /**
    * @brief          Process check of WakeUp condition. SID is 0x0B.
    * @details        This service shall evaluate the WakeupSource parameter to get the information,
    *                 which dedicate wakeup source needs to be checked, either a CAN transceiver or controller device.
    *                 This routine is called by:
    *                 - CanIf or an upper layer according to Autosar requirements.
    *
    * @param[in]      controller Can controller ID - based on configuration order list (CanControllerId).
    * @return         Std_ReturnType Result of the wakeup verification.
    * @retval         E_OK  Wakeup was detected for the given controller.
    * @retval         E_NOT_OK  No wakeup was detected for the given controller.
    *
    *
    * @pre            Driver must be initialized.
    * @post           Return the Wakeup event occurence.
    *
    * Compiler_Warning: This warning is thrown because it doesn't exist hardware support for Wakeup, and parameter "controller" it is not used.
    * @api
    *
    */
    /* implements     Can_CheckWakeup_Activity */
    Std_ReturnType Can_43_FLEXCAN_CheckWakeup(uint8 Controller)
    {
        Std_ReturnType eRetVal = E_NOT_OK;

    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
        {
            /*
            *   [SWS_Can_00362] If development error detection for the Can module is enabled:
            *   The function Can_CheckWakeup shall raise the error CAN_E_UNINIT
            *   if the driver not yet initialized.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_CHECK_WAKEUP, CAN_43_FLEXCAN_E_UNINIT);
        }
        else
        {
            if (Controller >= CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
            {
                /*
                *   [SWS_Can_00363] If development error detection for the Can module is enabled:
                *   The function Can_CheckWakeup shall raise the error CAN_E_PARAM_CONTROLLER
                *   if the parameter Controller is out of range.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_CHECK_WAKEUP, CAN_43_FLEXCAN_E_PARAM_CONTROLLER);
            }
            else
            {
    #endif
                Can_43_FLEXCAN_Ipw_CheckWakeup(Controller);
    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
    #endif
        return eRetVal;
    }
#endif /* CAN_43_FLEXCAN_CHECK_WAKEUP_API == STD_ON */

/**
* @brief          Obtains the error state of the CAN controller.. SID is 0x11
* @details        This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      ControllerId: Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested for ErrorState.
*
* @param[out]     ErrorStatePtr: Pointer to a memory location, where the error state of the CAN controller will be stored.
*
* @retval         E_OK : Error state request has been accepted.
* @retval         E_NOT_OK : Error state request has not been accepted.
*
* @pre
* @post
*
* @api
*
*/
/* implements     Can_GetControllerErrorState_Activity */
Std_ReturnType Can_43_FLEXCAN_GetControllerErrorState
(
    uint8 ControllerId,
    Can_ErrorStateType * ErrorStatePtr
)
{
    Std_ReturnType eRetVal = E_NOT_OK;
    uint8 errorState = 0U;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_ValidateController(u32CoreId, ControllerId, CAN_43_FLEXCAN_SID_GET_CONTROLLER_ERROR_STATE))
    {
                if (NULL_PTR == ErrorStatePtr)
                {
                    /*
                    *   [SWS_Can_91007] If default error detection for the Can module is enabled:
                    *   if the parameter ErrorStatePtr is a null pointer, the function Can_GetControllerErrorState
                    *   shall raise default error CAN_E_PARAM_POINTER and return E_NOT_OK.
                    */
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_ERROR_STATE, CAN_43_FLEXCAN_E_PARAM_POINTER);
                }
                else
                {
#endif
                    Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[ControllerId];
                    eRetVal = Can_43_FLEXCAN_Ipw_GetControllerErrorState(Can_pController, &errorState);
                    if(eRetVal == (Std_ReturnType)E_OK)
                    {
                        switch (errorState)
                        {
                            case 0x00U:
                            {
                                *ErrorStatePtr = CAN_ERRORSTATE_ACTIVE;
                                break;
                            }
                            case 0x01U:
                            {
                                *ErrorStatePtr = CAN_ERRORSTATE_PASSIVE;
                                break;
                            }
                            default:
                            {
                                *ErrorStatePtr = CAN_ERRORSTATE_BUSOFF;
                                break;
                            }
                        }
                    }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                }
    }
#endif
    return eRetVal;
}

/**
* @brief          Reports about the current status of the requested CAN controller. SID is 0x12
* @details        This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller: CAN controller for which the status shall be requested.
*
* @param[out]     ControllerModePtr: Pointer to a memory location, where the current mode of the CAN controller will be stored.
*
* @retval         E_OK : Controller mode request has been accepted.
* @retval         E_NOT_OK : Controller mode request has not been accepted.
*
* @pre
* @post
*
* @api
*
*/
/* implements     Can_GetControllerMode_Activity */
Std_ReturnType Can_43_FLEXCAN_GetControllerMode
(
    uint8 Controller,
    Can_ControllerStateType * ControllerModePtr
)
{
    Std_ReturnType eRetVal = E_NOT_OK;
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    uint32 u32CoreId = 0U;
#endif

#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    u32CoreId = Can_GetCoreID();
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        /*
        *   [SWS_Can_91016] If default error detection for the Can module is enabled:
        *   The function Can_GetControllerMode shall raise the error CAN_E_UNINIT
        *   and return E_NOT_OK if the driver is not yet initialized.
        */
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_MODE, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if (Controller >= CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            /*
            *   [SWS_Can_91017] If parameter Controller of Can_GetControllerMode() has an invalid value,
            *   the CanDrv shall report development error code CAN_E_PARAM_CONTROLLER to the Det_ReportError
            *   service of the DET.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_MODE, CAN_43_FLEXCAN_E_PARAM_CONTROLLER);
        }
        else
        {
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (NULL_PTR == (Can_apxConfig[u32CoreId])->Can_ppController[Controller])
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_MODE, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
            else
            {
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
                if (NULL_PTR == ControllerModePtr)
                {
                    /*
                    *   [SWS_Can_91018] If parameter ControllerModePtr of Can_GetControllerMode() has an null pointer,
                    *   the CanDrv shall report development error code CAN_E_PARAM_POINTER to the Det_ReportError service of the DET.
                    */
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_MODE, CAN_43_FLEXCAN_E_PARAM_POINTER);
                }
                else
                {
#endif
                    *ControllerModePtr = Can_eControllerState[Controller];
                    eRetVal = E_OK;
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                }
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif
    return eRetVal;
}

/**
* @brief            Return the Rx error counter for a CAN controller
* @details          Return the Rx error counter for a CAN controller. This value might not be
*                   available for all CAN controller, in which case E_NOT_OK would be returned.
*                   Please note that the value of the counter might not be correct at the moment
*                   the API returns it, because the Rx counter is handled asynchronously in hardware.
*                   Applications should not trust this value for any assumption about the current bus state.
*
* @param[in]        ControllerId: CAN controller, whose current Rx error counter shall be acquired.
* @param[out]       RxErrorCounterPtr: Pointer to a memory location, where the current Rx error
*                       counter of the CAN controller will be stored.
*
* @return           Std_ReturnType
* @retval           E_OK:  Rx error counter available.
* @retval           E_NOT_OK: Wrong ControllerId, or Rx error counter not available.
*
* @pre
* @post
*
* @api
*/
/* implements       Can_GetControllerRxErrorCounter_Activity */
Std_ReturnType Can_43_FLEXCAN_GetControllerRxErrorCounter
(
    uint8 ControllerId,
    uint8 * RxErrorCounterPtr
)
{
    Std_ReturnType eRetVal = E_NOT_OK;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        /*
        *   [SWS_Can_00512]: If development error detection for the Can module is enabled:
        *   if the module is not yet initialized, the function Can_GetControllerRxErrorCounter shall
        *   raise development error CAN_E_UNINIT and return E_NOT_OK.
        */
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if (ControllerId >= CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            /*
            *   [SWS_Can_00513]: If development error detection for the Can module is enabled:
            *   if the parameter ControllerId is out of range, the function Can_GetControllerRxErrorCounter shall
            *   raise development error CAN_E_PARAM_CONTROLLER and return E_NOT_OK.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER, CAN_43_FLEXCAN_E_PARAM_CONTROLLER);
        }
        else
        {
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (NULL_PTR == (Can_apxConfig[u32CoreId])->Can_ppController[ControllerId])
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
            else
            {
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
                if (NULL_PTR == RxErrorCounterPtr)
                {
                    /*
                    *   [SWS_Can_00514]: If development error detection for the Can module is enabled:
                    *   if the parameter RxErrorCounterPtr is a null pointer, the function Can_GetControllerRxErrorCounter shall
                    *   raise development error CAN_E_PARAM_POINTER and return E_NOT_OK.
                    */
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER, CAN_43_FLEXCAN_E_PARAM_POINTER);
                }
                else
                {
#endif
                    Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[ControllerId];
                    /*
                    *   [SWS_Can_00515]: When the API Can_GetControllerRxErrorCounter is called with
                    *   Controller Id as input parameter then Can driver shall read the Rx error counter
                    *   register of Can Controller and shall return the Rx error count to upper layer.
                    */
                    eRetVal = Can_43_FLEXCAN_Ipw_GetControllerRxErrorCounter(Can_pController, RxErrorCounterPtr);
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                }
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif
    return eRetVal;
}

/**
* @brief            Return the Tx error counter for a CAN controller
* @details          Return the Tx error counter for a CAN controller. This value might not be
*                   available for all CAN controller, in which case E_NOT_OK would be returned.
*                   Please note that the value of the counter might not be correct at the moment
*                   the API returns it, because the Tx counter is handled asynchronously in hardware.
*                   Applications should not trust this value for any assumption about the current bus state.
*
* @param[in]        ControllerId: CAN controller, whose current Tx error counter shall be acquired.
* @param[out]       TxErrorCounterPtr: Pointer to a memory location, where the current Tx error
*                       counter of the CAN controller will be stored.
*
* @return           Std_ReturnType
* @retval           E_OK:  Tx error counter available.
* @retval           E_NOT_OK: Wrong ControllerId, or Tx error counter not available.
*
* @pre
* @post
*
* @api
*/
/* implements       Can_GetControllerTxErrorCounter_Activity */
Std_ReturnType Can_43_FLEXCAN_GetControllerTxErrorCounter
(
    uint8 ControllerId,
    uint8 * TxErrorCounterPtr
)
{
    Std_ReturnType eRetVal = E_NOT_OK;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        /*
        *   [SWS_Can_00517]: If development error detection for the Can module is enabled:
        *   if the module is not yet initialized, the function Can_GetControllerTxErrorCounter shall
        *   raise development error CAN_E_UNINIT and return E_NOT_OK.
        */
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if (ControllerId >= CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            /*
            *   [SWS_Can_00518]: If development error detection for the Can module is enabled:
            *   if the parameter ControllerId is out of range, the function Can_GetControllerTxErrorCounter shall
            *   raise development error CAN_E_PARAM_CONTROLLER and return E_NOT_OK.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER, CAN_43_FLEXCAN_E_PARAM_CONTROLLER);
        }
        else
        {
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (NULL_PTR == (Can_apxConfig[u32CoreId])->Can_ppController[ControllerId])
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
            else
            {
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
                if (NULL_PTR == TxErrorCounterPtr)
                {
                    /*
                    *   [SWS_Can_00519]: If development error detection for the Can module is enabled:
                    *   if the parameter TxErrorCounterPtr is a null pointer, the function Can_GetControllerTxErrorCounter shall
                    *   raise development error CAN_E_PARAM_POINTER and return E_NOT_OK.
                    */
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER, CAN_43_FLEXCAN_E_PARAM_POINTER);
                }
                else
                {
#endif /* CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON */
                    Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[ControllerId];
                    /*
                    *   [SWS_Can_00520]: When the API Can_GetControllerTxErrorCounter is called with
                    *   Controller Id as input parameter then Can driver shall read the Tx error counter
                    *   register of Can Controller and shall return the Tx error count to upper layer.
                    */
                    eRetVal = Can_43_FLEXCAN_Ipw_GetControllerTxErrorCounter(Can_pController, TxErrorCounterPtr);
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                }
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif
    return eRetVal;
}

/**
* @brief          Transmit information on CAN bus. SID is 0x06.
* @details        Can_Write checks if hardware transmit object that is identified by the HTH is free.
*                    Can_Write checks if another Can_Write is ongoing for the same HTH.
*                     a) hardware transmit object is free:
*                         The mutex for that HTH is set to 'signaled' the ID, DLC and SDU are put in a format appropriate for
*                           the hardware (if necessary) and copied in the appropriate hardware registers or buffers.
*                        All necessary control operations to initiate the transmit are done.
*                         The mutex for that HTH is released. The function returns with E_OK.
*                    b) hardware transmit object is busy with another transmit request.
*                         The function returns with CAN_BUSY.
*                     c) A preemptive call of Can_Write has been issued, that could not be handled reentrant (i.e. a call with the same HTH).
*                        The function returns with CAN_BUSY the function is non blocking
*                     d) The hardware transmit object is busy with another transmit request for an L-PDU that has lower priority than that for the current request
*                        The transmission of the previous L-PDU is cancelled (asynchronously).
*                        The function returns with CAN_BUSY.
*                   This routine is called by:
*                   - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Hth Information which HW-transmit handle shall be used for transmit.
*                 Implicitly this is also the information about the controller to use because the Hth numbers are unique inside one hardware unit.
* @param[in]      PduInfo Pointer to SDU user memory, DLC and Identifier.
* @return         Std_ReturnType   Result of the write operation.
* @retval         E_OK   Write command has been accepted.
* @retval         E_NOT_OK  Development error occured.
* @retval         CAN_BUSY   No of TX hardware buffer available or preemtive call of Can_Write() that can't be implemented reentrant.
*
*
* @pre            Driver must be initialized and MB must be configured for Tx.
* @post           The data can be transmitted or rejected because of another data with a higher priority.
*
*
* @api
*/
/* implements     Can_Write_Activity */
Std_ReturnType Can_43_FLEXCAN_Write
(
    Can_HwHandleType Hth,
    const Can_PduType * PduInfo
)
{
    Std_ReturnType eRetVal = E_NOT_OK;
    uint8 u8ControllerID = 0U;
    uint32 u32CoreId = 0U;
    Can_HwHandleType HwObjectID = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObject = NULL_PTR;

    u32CoreId = Can_GetCoreID();
    HwObjectID = Hth;
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_ValidateHth(u32CoreId, Hth))
    {
            if (NULL_PTR == PduInfo)
            {
                /*
                *   [SWS_Can_00219]: If development error detection for CanDrv is enabled:
                *   Can_Write() shall raise CAN_E_PARAM_POINTER and shall return E_NOT_OK if the
                *   parameter PduInfo is a null pointer.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_WRITE, CAN_43_FLEXCAN_E_PARAM_POINTER);
            }
            else
            {
#endif /* CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON */
                u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pHwObjIDToCtrlIDMap[HwObjectID];
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                if (NULL_PTR != Can_pController)
                {
                    Can_pHwObject = &((Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID]);
                #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                    if ((TRUE == Can_ValidatePdu(Can_pController, Can_pHwObject, PduInfo)) && (CAN_CS_STARTED == Can_eControllerState[u8ControllerID]))
                #else
                    /* avoid unexpected behaviour when accessing to RAM */
                    if (CAN_CS_STARTED == Can_eControllerState[u8ControllerID])
                #endif
                    {
                    #if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                        if (Can_apxCtrlConfigIcomIndex[u8ControllerID] != NULL_PTR)
                        {
                            eRetVal = CAN_BUSY;
                        }
                        else
                        {
                    #endif
                            eRetVal = Can_43_FLEXCAN_Ipw_Write(Can_pController, Can_pHwObject, PduInfo);
                    #if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                        }
                    #endif
                    }
                }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
            #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
                else
                {
                    /*
                    *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                    *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                    */
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_WRITE, CAN_43_FLEXCAN_E_PARAM_CONFIG);
                }
            #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
            }
    }
#endif
    return eRetVal;
}


#if (CAN_43_FLEXCAN_ABORT_MB_API == STD_ON)
    /**
    * @brief          Process a message buffer abort
    * @details        This function write a abort code (b'1001) to MBCS[CODE] field of the MB.
    *                This routine is called by:
    *                - CanIf or an upper layer according to Autosar requirements.
    *
    * @param[in]      Hth - HW-transmit handler
    *
    *
    * @pre            Driver must be initialized and the current MB transmission should be ready for transmit.
    *
    *
    * @note           Not AUTOSAR required. This is user implementation.
    */
    /* implements     Can_AbortMb_Activity */
    void Can_43_FLEXCAN_AbortMb(Can_HwHandleType Hth)
    {
        uint32 u32CoreId = 0U;
        uint8 u8ControllerID = 0U;
        Can_HwHandleType HwObjectID = 0U;
        const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;
        const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObject = NULL_PTR;

        u32CoreId = Can_GetCoreID();
        HwObjectID = Hth;
    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
        {
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_ABORT_MB, CAN_43_FLEXCAN_E_UNINIT);
        }
        else
        {
            if ((Hth >= CAN_43_FLEXCAN_HWOBJECT_CONFIG_COUNT) || (Hth < (Can_apxConfig[u32CoreId])->Can_uHthFirstIndex))
            {
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_ABORT_MB, CAN_43_FLEXCAN_E_PARAM_HANDLE);
            }
            else
            {
    #endif /* CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON */
                u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pHwObjIDToCtrlIDMap[HwObjectID];
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                if (NULL_PTR != Can_pController)
                {
                    Can_pHwObject = &((Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID]);
                    Can_43_FLEXCAN_Ipw_AbortMb(Can_pController, Can_pHwObject);
                }
    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
            #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
                else
                {
                    /*
                    *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                    *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                    */
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_ABORT_MB, CAN_43_FLEXCAN_E_PARAM_CONFIG);
                }
            #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
            }
        }
    #endif
    }
#endif /* CAN_43_FLEXCAN_ABORT_MB_API == STD_ON */

#if (CAN_43_FLEXCAN_DUAL_CLOCK_MODE == STD_ON)
    /**
    * @brief          Function switch between two prescaler that was configured when Clock Source value to driver changed to another one.
    * @details        Function sets all controllers' prescaller based on input parameter.
    *
    * @param[in]      eClkMode - prescaler setting ( NORMAL or ALTERNATE)
    *
    * @pre            Can_Init must be called before, all controllers must be in STOPPED.
    *
    */
    /* implements     Can_SetClockMode_Activity */
    void Can_43_FLEXCAN_SetClockMode(Can_43_FLEXCAN_ClockModeType eClkMode)
    {
        uint32 u32CoreId = 0U;
        uint8 u8ControllerID = 0U;
        boolean bCtrlBusy = FALSE;
        const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

        u32CoreId = Can_GetCoreID();
    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
        {
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SETCLOCKMODE, CAN_43_FLEXCAN_E_UNINIT);
        }
        else
        {
    #endif
            for (u8ControllerID = 0U; u8ControllerID < CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
            {
                if (NULL_PTR != (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID])
                {
                    if (CAN_CS_STARTED == Can_eControllerState[u8ControllerID])
                    {
                    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SETCLOCKMODE , CAN_43_FLEXCAN_E_TRANSITION);
                    #endif
                        bCtrlBusy = TRUE;
                        break;
                    }
                }
            }
            if (FALSE == bCtrlBusy)
            {
                for (u8ControllerID = 0U; u8ControllerID < CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT; u8ControllerID++)
                {
                    if (NULL_PTR != (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID])
                    {
                        Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                        /* Skip controller that is not enabled. */
                        if (TRUE == Can_pController->Can_bActivation)
                        {
                            Can_43_FLEXCAN_Ipw_SetClockMode(Can_pController, Can_au16BaudrateIDConfig[u8ControllerID], eClkMode);
                        }
                    }
                }
            }
    #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        }
    #endif
    }
#endif /* CAN_43_FLEXCAN_DUAL_CLOCK_MODE == STD_ON */

#if (CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_WRITE == STD_OFF)
    /**
    * @brief          Function called at fixed cyclic time. SID is 0x01.
    * @details        Service for performs the polling of TX confirmation and TX cancellation confirmation when CAN_TX_PROCESSING is set to POLLING.
    *                 This routine is called by:
    *                 - CanIf or an upper layer according to Autosar requirements.
    *
    *
    * @pre            Driver must be initialized.
    * @post           Send the data from that MB that is configured for Tx.
    *
    * @api
    */
    /* implements     Can_MainFunction_Write_Activity */
    void Can_43_FLEXCAN_MainFunction_Write(void)
    {
    #if (CAN_43_FLEXCAN_TX_POLLING_SUPPORT == STD_ON)
        Can_HwHandleType HwObjectID = 0U;
        uint8 u8ControllerID = 0U;
        uint32 u32CoreId = 0U;
        const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

        u32CoreId = Can_GetCoreID();
        if (NULL_PTR != (Can_apxConfig[u32CoreId]))
        {
            HwObjectID = (Can_apxConfig[u32CoreId])->Can_uHthFirstIndex;
            while (HwObjectID < CAN_43_FLEXCAN_HWOBJECT_CONFIG_COUNT)
            {
                u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pHwObjIDToCtrlIDMap[HwObjectID];
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                if (NULL_PTR != Can_pController)
                {
                    /* Check if the HwObject is config for polling */
                    if ((TRUE == Can_pController->Can_bActivation) && (TRUE == (Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID].Can_bHwObjectUsesPolling))
                    {
                        Can_43_FLEXCAN_Ipw_MainFunction_Write(Can_pController, &((Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID]));
                    }
                }
                HwObjectID++;
            }
#if (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON)
            HwObjectID = (Can_apxConfig[u32CoreId])->CanXL_uHthFirstIndex;
            while (HwObjectID < CAN_43_FLEXCAN_XL_HWOBJECT_CONFIG_COUNT)
            {
                u8ControllerID = (Can_apxConfig[u32CoreId])->CanXL_pHwObjIDToCtrlIDMap[HwObjectID];
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                if ((TRUE == Can_pController->Can_bActivation) && (TRUE == (Can_apxConfig[u32CoreId])->CanXL_pHwObjectConfig[HwObjectID].Can_bHwObjectUsesPolling))
                {
                    CanXL_43_FLEXCAN_Ipw_MainFunction_Write(Can_pController, &((Can_apxConfig[u32CoreId])->CanXL_pHwObjectConfig[HwObjectID]));
                }
                HwObjectID++;
            }
#endif /* (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON) */
        }
    #endif /* CAN_43_FLEXCAN_TX_POLLING_SUPPORT == STD_ON */
    }
#else
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_0
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_0.
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_0(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_0);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_1
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_1.
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_1(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_1);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_2
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_2.
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_2(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_2);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_3
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_3
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_3(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_3);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_4
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_4.
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_4(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_4);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_5
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_5.
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_5(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_5);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_6
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_6.
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_6(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_6);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_7
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_7.
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_7(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_7);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_8
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_8
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_8(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_8);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_9
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_9.
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_9(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_9);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_WRITE_PERIOD_CanMainFunctionRWPeriods_10
        /**
        *   @brief      This function performs polling all HTHs referring CanMainFunctionRWPeriods_10.
        */
        void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_10(void)
        {
            Can_MainFunction_MultipleWrite(CanMainFunctionRWPeriods_10);
        }
    #endif
#endif  /* End CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_WRITE */

#if (CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_READ == STD_OFF)
    /**
    * @brief          Function called at fixed cyclic time.  SID is 0x08.
    * @details        Service for performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
    *                 This routine is called by:
    *                 - CanIf or an upper layer according to Autosar requirements.
    *
    *
    * @pre            Driver must be initialized.
    * @post           Receive the data from that MB that is configured for Rx.
    *
    * @api
    */
    /* implements     Can_MainFunction_Read_Activity */
    void Can_43_FLEXCAN_MainFunction_Read(void)
    {
    #if (CAN_43_FLEXCAN_RX_POLLING_SUPPORT == STD_ON)
        Can_HwHandleType HwObjectID = 0U;
        uint8 u8ControllerID = 0U;
        uint32 u32CoreId = 0U;
        const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

        u32CoreId = Can_GetCoreID();
        if (NULL_PTR != (Can_apxConfig[u32CoreId]))
        {
            while (HwObjectID < (Can_apxConfig[u32CoreId])->Can_uHthFirstIndex)
            {
                u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pHwObjIDToCtrlIDMap[HwObjectID];
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                if (NULL_PTR != Can_pController)
                {
                    /* Check if the HwObject is config for polling */
                    if ((TRUE == Can_pController->Can_bActivation) && (TRUE == (Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID].Can_bHwObjectUsesPolling))
                    {
                        Can_43_FLEXCAN_Ipw_MainFunction_Read(Can_pController, &((Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID]));
                    }
                }
                HwObjectID++;
            }
#if (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON)
            HwObjectID = 0U;
            while (HwObjectID < (Can_apxConfig[u32CoreId])->CanXL_uHthFirstIndex)
            {
                u8ControllerID = (Can_apxConfig[u32CoreId])->CanXL_pHwObjIDToCtrlIDMap[HwObjectID];
                Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
                if ((TRUE == Can_pController->Can_bActivation) && (TRUE == (Can_apxConfig[u32CoreId])->CanXL_pHwObjectConfig[HwObjectID].Can_bHwObjectUsesPolling))
                {
                    CanXL_43_FLEXCAN_Ipw_MainFunction_Read(Can_pController, &((Can_apxConfig[u32CoreId])->CanXL_pHwObjectConfig[HwObjectID]));
                }
                HwObjectID++;
            }
#endif /* (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON) */
        }
    #endif /* CAN_43_FLEXCAN_RX_POLLING_SUPPORT == STD_ON */
    }
#else
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_0
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_0.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_0(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_0);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_1
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_1.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_1(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_1);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_2
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_2.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_2(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_2);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_3
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_3.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_3(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_3);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_4
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_4.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_4(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_4);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_5
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_5.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_5(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_5);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_6
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_6.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_6(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_6);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_7
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_7.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_7(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_7);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_8
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_8.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_8(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_8);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_9
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_9.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_9(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_9);
        }
    #endif
    #ifdef CAN_43_FLEXCAN_MAINFUNCTION_READ_PERIOD_CanMainFunctionRWPeriods_10
        /**
        *   @brief      This function performs polling all HRHs referring CanMainFunctionRWPeriods_10.
        */
        void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_10(void)
        {
            Can_MainFunction_MultipleRead(CanMainFunctionRWPeriods_10);
        }
    #endif
#endif /* End CAN_43_FLEXCANMAINFUNCTION_MULTIPLE_READ */
/**
* @brief          Function called at fixed cyclic time. SID is 0x09.
* @details        Service for performs the polling of BusOff events that are configured statically as 'to be polled'.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
*
* @pre            Driver must be initialized.
* @post           Handle the Busoff event.
*
* @api
*/
/* implements     Can_MainFunction_BusOff_Activity */
void Can_43_FLEXCAN_MainFunction_BusOff(void)
{
#if (CAN_43_FLEXCAN_BUSOFF_POLLING_SUPPORT == STD_ON)
    uint8 u8ControllerID = 0U;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
    if (NULL_PTR != (Can_apxConfig[u32CoreId]))
    {
        while (u8ControllerID < CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
            if (NULL_PTR != Can_pController)
            {
                if ((TRUE == Can_pController->Can_bActivation) && (TRUE == (Can_pController->Can_bBusOffUsesPolling)))
                {
                    Can_43_FLEXCAN_Ipw_MainFunction_BusOff(Can_pController);
                }
            }
            u8ControllerID++;
        }
    }
#endif /* CAN_43_FLEXCAN_BUSOFF_POLLING_SUPPORT == STD_ON */
}


#if (CAN_43_FLEXCAN_WAKEUP_SUPPORT == STD_ON)
    /**
    * @brief          Function called at fixed cyclic time. SIDis 0x0A.
    * @details        Service for performs performs the polling of CAN status register flags to detect Wakeup event of CAN Controller state
    *                 This routine is called by:
    *                 - CanIf or an upper layer according to Autosar requirements.
    *
    *
    * @pre            Driver must be initialized.
    * @post           Handle the wakeup event of Can Controller state.
    *
    * @api
    */
    void Can_43_FLEXCAN_MainFunction_Wakeup(void)
    {
    #if (CAN_43_FLEXCAN_WAKEUP_POLLING_SUPPORT == STD_ON)
        uint8 u8ControllerID = 0U;

        do
        {
            if (TRUE == Can_apxConfig->pCanControllerConfig[u8ControllerID].bCanWakeupUsesPolling)
            {
                if (E_OK == Can_43_FLEXCAN_Ipw_MainFunction_Wakeup(Can_apxConfig->pCanControllerConfig[u8ControllerID], Can_apxConfig->pCanHwObjectConfig))
                {
                    Can_eControllerState[u8ControllerID] = CAN_CS_STOPPED;
                }
            }
            u8ControllerID++;
        }while (u8ControllerID < Can_apxConfig->u8CanControllerConfigCount);
    #endif /* CAN_43_FLEXCAN_WAKEUP_POLLING_SUPPORT == STD_ON */
    }
#endif /* CAN_43_FLEXCAN_WAKEUP_SUPPORT == STD_ON */

/**
* @brief          Function called at fixed cyclic time. SIDis 0x0C.
* @details        Service for performs performs the polling of CAN status register flags to detect transition of CAN Controller state
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
*
* @pre            Driver must be initialized.
* @post           Handle the transition of Can Controller state.
*
* @api
*/
/* implements     Can_MainFunction_Mode_Activity */
void Can_43_FLEXCAN_MainFunction_Mode(void)
{
    uint8 u8ControllerID = 0U;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
    if (NULL_PTR != (Can_apxConfig[u32CoreId]))
    {
        while (u8ControllerID < CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
            if (NULL_PTR != Can_pController)
            {
                if (TRUE == Can_pController->Can_bActivation)
                {
                    Can_43_FLEXCAN_Ipw_MainFunction_Mode(Can_pController, &Can_eControllerState[u8ControllerID]);
                }
            }
            u8ControllerID++;
        }
    }
}

#if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/**
* @brief          Set controller into Pretended Networking mode with the ConfigurationID valid.
* @details        This function is API which support the Pretended Networking featrue. After this function is called,
*                 it will configure for controller with information in the configurationIDs (corresponding with ID valid)
*
* @param[in]      Controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      ConfigurationId the ID of CanIcomConfig
*
* @return        Std_ReturnType
* @retval        E_OK       PNET is Enabled/disabled successfully.
* @retval        E_NOT_OK   PNET is not Enabled/disabled successfully.
*
* @pre            Driver must be initialized
*
* @note           In order to activate PNET (ConfigurationId != 0) the controller must be in START mode.
* @implements    Can_SetIcomConfiguration_Activity
*/
Std_ReturnType Can_43_FLEXCAN_SetIcomConfiguration(uint8 Controller, IcomConfigIdType ConfigurationId)
{
    uint32 u32CoreId = 0U;
    Std_ReturnType eReturnValue = (Std_ReturnType)E_NOT_OK;
    uint8 u8ConfigIcomIndex = 0U;

    u32CoreId = Can_GetCoreID();

#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        if (Controller < CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            if (NULL_PTR == (Can_apxConfig[u32CoreId])->Can_ppController[Controller])
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SET_ICOM_CONFIG, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
            else
            {
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
#endif
                /* Check status of controller. only configure for PNET mode when controller into Freeze  mode. */
                /* [SWS_CAN_00471] Pretended Networking shall be deactivated (i.e. CanDrv shall behave as when it is configured without Pretended Networking support) by calling Can_SetIcomConfiguration() with a configuration ID = 0. */
                if (0U == ConfigurationId)
                {
                    eReturnValue = (Std_ReturnType)Can_43_FLEXCAN_Ipw_DeactivateIcomConfiguration((Can_apxConfig[u32CoreId])->Can_ppController[Controller]);
                }
                /* [SWS_CAN_00462] Pretended Networking shall be activated by calling Can_SetIcomConfiguration() with a configuration ID not set to 0. */
                /* [SWS_CAN_00481] If the requested ConfigurationId is not 0, the function Can_SetIcomConfiguration() shall reconfigure the controller with the ICOM configuration parameters of the CanIcomConfig container
                which CanIcomConfigId matches the requested ConfigurationId.
                */
                else
                {
                    for (u8ConfigIcomIndex = 0U; u8ConfigIcomIndex < (Can_apxConfig[u32CoreId]->u8NumCanIcomConfigs); u8ConfigIcomIndex++)
                    {
                        if (ConfigurationId == (uint8)(Can_apxConfig[u32CoreId]->pCanIcomConfigs[u8ConfigIcomIndex].u8CanIcomConfigId))
                        {
                            if (CAN_CS_STARTED == Can_eControllerState[Controller])
                            {
                                /* ConfigID is Valid */
                                eReturnValue = (Std_ReturnType)Can_43_FLEXCAN_Ipw_SetIcomConfiguration((Can_apxConfig[u32CoreId])->Can_ppController[Controller], &Can_apxConfig[u32CoreId]->pCanIcomConfigs[u8ConfigIcomIndex]);
                            }
                            break;
                        }
                    }
            #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                    if((Can_apxConfig[u32CoreId]->u8NumCanIcomConfigs) == u8ConfigIcomIndex)
                    {
                        (void)Det_ReportError( (uint16)CAN_43_FLEXCAN_MODULE_ID, (uint8)CAN_43_FLEXCAN_INSTANCE, (uint8)CAN_43_FLEXCAN_SID_SET_ICOM_CONFIG, (uint8)CAN_43_FLEXCAN_E_ICOM_CONFIG_INVALID);
                    }
            #endif /* (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON) */
                }

                /* Refer to [SWS_CAN_00467] and [SWS_CAN_00474] */
                if((Std_ReturnType)E_OK == eReturnValue)
                {
                    if (0U != ConfigurationId)
                    {
                        Can_apxCtrlConfigIcomIndex[Controller] = &Can_apxConfig[u32CoreId]->pCanIcomConfigs[u8ConfigIcomIndex];
                    }
                    else
                    {
                        Can_apxCtrlConfigIcomIndex[Controller] = NULL_PTR;
                    }
                    CanIf_CurrentIcomConfiguration((Can_apxConfig[u32CoreId])->Can_ppController[Controller]->Can_u8AbstControllerID, ConfigurationId, ICOM_SWITCH_E_OK);
                }
                else
                {
                    CanIf_CurrentIcomConfiguration((Can_apxConfig[u32CoreId])->Can_ppController[Controller]->Can_u8AbstControllerID, ConfigurationId, ICOM_SWITCH_E_FAILED);
                }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
#endif

    return (eReturnValue);
}

void Can_43_FLEXCAN_ProcessPNInterrupt(uint8 u8CtrlOffset)
{
    uint8 u8ControllerID = 0U;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
    if (NULL_PTR != Can_apxConfig[u32CoreId])
    {
        u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pCtrlOffsetToCtrlIDMap[u8CtrlOffset];
        Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
        /* Check if the configuration assigned for controller is valid */
        if ((NULL_PTR != Can_pController) && (Can_apxCtrlConfigIcomIndex[u8ControllerID] != NULL_PTR))
        {
            Can_43_FLEXCAN_Ipw_ProcessPN(Can_pController, Can_apxCtrlConfigIcomIndex[u8ControllerID]);
        }
    }
}
#endif /* (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_OFF) */

#if (CAN_43_FLEXCAN_TIMESTAMP_ENABLE == STD_ON)
/* Returns a time value out of the HW registers according to the capability of the Hardware. */
Std_ReturnType Can_43_FLEXCAN_GetCurrentTime(uint8 ControllerId, Can_TimeStampType* timeStampPtr)
{
    Std_ReturnType eRetVal = E_NOT_OK;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CURRENT_TIME, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if (ControllerId >= CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CURRENT_TIME, CAN_43_FLEXCAN_E_PARAM_CONTROLLER);
        }
        else
        {
#endif /* CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON */
        Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[ControllerId];
        if (NULL_PTR != Can_pController)
        {
            if (NULL_PTR != timeStampPtr)
            {
                if (TRUE == (Can_pController->Can_bTimestampEn))
                {
                    Can_43_FLEXCAN_Ipw_GetCurrentTime(timeStampPtr);
                    eRetVal = E_OK;
                }
            }
        #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
            else
            {
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CURRENT_TIME, CAN_43_FLEXCAN_E_PARAM_POINTER);
            }
        #endif
        }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
        else
        {
            /*
            *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
            *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_CURRENT_TIME, CAN_43_FLEXCAN_E_PARAM_CONFIG);
        }
    #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif
    return eRetVal;
}

#if (CAN_43_FLEXCAN_TS_EXTERNAL_TIMER_USED == STD_ON)
/* This function will set a new global time(second part only). */
Std_ReturnType Can_43_FLEXCAN_SetCurrentTime(uint8 ControllerId, const Can_TimeStampType* timeStampPtr)
{
    Std_ReturnType eRetVal = E_NOT_OK;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SET_CURRENT_TIME, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if (ControllerId >= CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT)
        {
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SET_CURRENT_TIME, CAN_43_FLEXCAN_E_PARAM_CONTROLLER);
        }
        else
        {
#endif /* CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON */
        Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[ControllerId];
        if (NULL_PTR != Can_pController)
        {
            if (NULL_PTR != timeStampPtr)
            {
                if (TRUE == (Can_pController->Can_bTimestampEn))
                {
                    Can_43_FLEXCAN_Ipw_SetCurrentTime(timeStampPtr);
                    eRetVal = E_OK;
                }
            }
        #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
            else
            {
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SET_CURRENT_TIME, CAN_43_FLEXCAN_E_PARAM_POINTER);
            }
        #endif
        }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
        else
        {
            /*
            *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
            *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
            */
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_SET_CURRENT_TIME, CAN_43_FLEXCAN_E_PARAM_CONFIG);
        }
    #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif
    return eRetVal;
}
#endif /* (CAN_43_FLEXCAN_TS_EXTERNAL_TIMER_USED == STD_ON) */

/* Activates egress time stamping on a dedicated HTH. */
void Can_43_FLEXCAN_EnableEgressTimeStamp(Can_HwHandleType Hth)
{
    uint32 u32CoreId = 0U;
    uint8 u8ControllerID = 0U;
    Can_HwHandleType HwObjectID = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObject = NULL_PTR;

    u32CoreId = Can_GetCoreID();
    HwObjectID = Hth;
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_ENABLE_EGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if ((Hth >= CAN_43_FLEXCAN_HWOBJECT_CONFIG_COUNT) || (Hth < (Can_apxConfig[u32CoreId])->Can_uHthFirstIndex))
        {
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_ENABLE_EGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_PARAM_HANDLE);
        }
        else
        {
#endif /* CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON */
            u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pHwObjIDToCtrlIDMap[HwObjectID];
            Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
            if (NULL_PTR != Can_pController)
            {
                if  (TRUE == (Can_pController->Can_bTimestampEn))
                {
                    Can_pHwObject = &((Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID]);
                    Can_43_FLEXCAN_Ipw_EnableEgressTimeStamp(Can_pController, Can_pHwObject);
                }
            }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
                else
                {
                    /*
                    *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                    *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                    */
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_ENABLE_EGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_PARAM_CONFIG);
                }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif /* End (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON) */
}

/* Reads back the egress time stamp on a dedicated message object. It needs to be called within the TxConfirmation() function.*/
Std_ReturnType Can_43_FLEXCAN_GetEgressTimeStamp
(
    PduIdType TxPduId,
    Can_HwHandleType Hth,
    Can_TimeStampType* timeStampPtr
)
{
    Std_ReturnType eRetVal = E_NOT_OK;
    uint32 u32CoreId = 0U;
    uint8 u8ControllerID = 0U;
    Can_HwHandleType HwObjectID = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObject = NULL_PTR;

    u32CoreId = Can_GetCoreID();
    HwObjectID = Hth;
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_EGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if ((Hth >= CAN_43_FLEXCAN_HWOBJECT_CONFIG_COUNT) || (Hth < (Can_apxConfig[u32CoreId])->Can_uHthFirstIndex))
        {
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_EGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_PARAM_HANDLE);
        }
        else
        {
#endif /* CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON */
            u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pHwObjIDToCtrlIDMap[HwObjectID];
            Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
            if (NULL_PTR != Can_pController)
            {
                if (NULL_PTR != timeStampPtr)
                {
                    if (TRUE == (Can_pController->Can_bTimestampEn))
                    {
                        Can_pHwObject = &((Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID]);
                        eRetVal = Can_43_FLEXCAN_Ipw_GetEgressTimeStamp(Can_pController, Can_pHwObject, TxPduId, timeStampPtr);
                    }
                }
            #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                else
                {
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_EGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_PARAM_POINTER);
                }
            #endif
            }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            else
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_EGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif
    return eRetVal;
}

/* Reads back the ingress time stamp on a dedicated message object. It needs to be called within the RxIndication() function. */
Std_ReturnType Can_43_FLEXCAN_GetIngressTimeStamp
(
    Can_HwHandleType Hrh,
    Can_TimeStampType* timeStampPtr
)
{
    Std_ReturnType eRetVal = E_NOT_OK;
    uint32 u32CoreId = 0U;
    uint8 u8ControllerID = 0U;
    Can_HwHandleType HwObjectID = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObject = NULL_PTR;

    u32CoreId = Can_GetCoreID();
    HwObjectID = Hrh;
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    if (CAN_43_FLEXCAN_UNINIT == Can_eDriverStatus[u32CoreId])
    {
        (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_INGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_UNINIT);
    }
    else
    {
        if ((Hrh >= CAN_43_FLEXCAN_HWOBJECT_CONFIG_COUNT) || (Hrh >= (Can_apxConfig[u32CoreId])->Can_uHthFirstIndex))
        {
            (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_INGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_PARAM_HANDLE);
        }
        else
        {
#endif /* CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON */
            u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pHwObjIDToCtrlIDMap[HwObjectID];
            Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
            if (NULL_PTR != Can_pController)
            {
                if (NULL_PTR != timeStampPtr)
                {
                    if (TRUE == (Can_pController->Can_bTimestampEn))
                    {
                        Can_pHwObject = &((Can_apxConfig[u32CoreId])->Can_pHwObjectConfig[HwObjectID]);
                        Can_43_FLEXCAN_Ipw_GetIngressTimeStamp(Can_pController, Can_pHwObject, timeStampPtr);
                        eRetVal = E_OK;
                    }
                }
            #if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
                else
                {
                    (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_INGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_PARAM_POINTER);
                }
            #endif
            }
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
        #if (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON)
            else
            {
                /*
                *   [CPR_RTD_00420.can] If DET error reporting is enabled, the <MDL> will check upon each API call if the requested resource is configured
                *   to be available on the current core, and in case of error will return <MDL>_E_PARAM_CONFIG.
                */
                (void)Det_ReportError((uint16)CAN_43_FLEXCAN_MODULE_ID, CAN_43_FLEXCAN_INSTANCE, CAN_43_FLEXCAN_SID_GET_INGRESS_TIMESTAMP, CAN_43_FLEXCAN_E_PARAM_CONFIG);
            }
        #endif /* (CAN_43_FLEXCAN_MULTICORE_ENABLED == STD_ON) */
        }
    }
#endif
    return eRetVal;
}
#endif /* (CAN_43_FLEXCAN_TIMESTAMP_ENABLE == STD_ON) */

#if (CAN_43_FLEXCAN_MB_INTERRUPT_SUPPORT == STD_ON)
/**
*   @brief      Function process Message Buffer Interrupt
*
*   @param[in]      u8CtrlOffset: The hardware offset of Controller
*                   u8MbIdx: The index of Message Buffer
*/
void Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt
(
    uint8 u8CtrlOffset,
    uint8 u8MbIdx,
    Can_43_FLEXCAN_MbType mbType
)
{
    uint8 u8ControllerID = 0U;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    MCAL_FAULT_INJECTION_POINT(CAN_FIP_2_CHANGE_DRIVER_TO_UNINITIALIZED);
    u32CoreId = Can_GetCoreID();
    if (NULL_PTR != Can_apxConfig[u32CoreId])
    {
        u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pCtrlOffsetToCtrlIDMap[u8CtrlOffset];
        Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
        if (NULL_PTR != Can_pController)
        {
            Can_43_FLEXCAN_Ipw_ProcessHwObject(Can_pController, (Can_apxConfig[u32CoreId]), u8MbIdx, mbType);
        }

    }
}
#endif /* CAN_43_FLEXCAN_MB_INTERRUPT_SUPPORT == STD_ON */

/**
*   @brief      Function process Bus Off Interrupt/Polling
*               This function is invoked when busOff occurred.
*
*   @param[in]      u8CtrlOffset: The hardware offset of Controller
*
*/
void Can_43_FLEXCAN_ProcessBusOffInterrupt
(
    uint8 u8CtrlOffset
)
{
    uint8 u8ControllerID = 0U;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
    if (NULL_PTR != Can_apxConfig[u32CoreId])
    {
        u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pCtrlOffsetToCtrlIDMap[u8CtrlOffset];
        Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
        if (NULL_PTR != Can_pController)
        {
            if ((Std_ReturnType)E_OK == Can_43_FLEXCAN_Ipw_SetControllerToStopMode(Can_pController))
            {
                Can_eControllerState[u8ControllerID] = CAN_CS_STOPPED;
                CanIf_ControllerBusOff(Can_pController->Can_u8AbstControllerID);
            }
        }
    }
}

#if (CAN_43_FLEXCAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
/**
*   @brief      Function process Error Interrupt
*
*   @param[in]      u8CtrlOffset: The hardware offset of Controller
*   @param[in]      u32ErrStatus: The error status of Controller
*
*/
void Can_43_FLEXCAN_ProcessErrorInterrupt
(
    uint8 u8CtrlOffset,
    uint32 u32ErrStatus
)
{
    uint8 u8ControllerID = 0U;
    uint32 u32CoreId = 0U;
    const Can_43_FLEXCAN_ControllerConfigType * Can_pController = NULL_PTR;

    u32CoreId = Can_GetCoreID();
    if (NULL_PTR != Can_apxConfig[u32CoreId])
    {
        u8ControllerID = (Can_apxConfig[u32CoreId])->Can_pCtrlOffsetToCtrlIDMap[u8CtrlOffset];

        Can_pController = (Can_apxConfig[u32CoreId])->Can_ppController[u8ControllerID];
        if (NULL_PTR != Can_pController)
        {
            Can_43_FLEXCAN_Ipw_ErrorHandling(Can_pController, u32ErrStatus);
        }
    }
}
#endif /* (CAN_43_FLEXCAN_ERROR_INTERRUPT_SUPPORT == STD_ON) */

#if (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON)
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
/**
*   @brief      Function Get Driver Status
*
*   @param[in]      instance: A FlexCAN instance number
*   @return         Can_43_FLEXCAN_DriverStatusType  Status of CAN Driver.
*
*/
Can_43_FLEXCAN_DriverStatusType Can_43_FLEXCAN_GetDriverStatus(uint32 instance)
{
    return Can_eDriverStatus[instance];
}
#endif /* (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON) */
/**
*   @brief      Function Get Controller State
*
*   @param[in]      instance: A FlexCAN instance number
*   @return         Can_ControllerStateType  Status of State Modes Operation.
*
*/
Can_ControllerStateType Can_43_FLEXCAN_GetControllerState(uint8 instance)
{
    return Can_eControllerState[instance];
}
/**
*   @brief      Function Get Driver Config
*
*   @param[in]      instance: A FlexCAN instance number
*   @return         Can_43_FLEXCAN_ConfigType  Status of the current Driver Configuration.
*
*/
const Can_43_FLEXCAN_ConfigType * Can_43_FLEXCAN_GetDriverConfig(uint32 instance)
{
    return Can_apxConfig[instance];
}
#endif /* (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON) */
#define CAN_43_FLEXCAN_STOP_SEC_CODE
/* @violates @ref Can_43_FLEXCAN_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
