/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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

/**
*   @file
*
*   @addtogroup ECUM_MODULE EcuM Module
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

#ifdef TEST_CAN
#include "CanIf.h"
#endif
#include "EcuM.h"
#ifdef TEST_GPT
#include "Gpt.h"
#include "Gpt_TestNotifications.h"
#endif
#ifdef TEST_LIN
#include "LinIf.h"
#endif
#ifdef TEST_ICU
#include "Icu.h"
#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define ECUM_VENDOR_ID_C                        43
#define ECUM_AR_RELEASE_MAJOR_VERSION_C         4
#define ECUM_AR_RELEASE_MINOR_VERSION_C         7
#define ECUM_AR_RELEASE_REVISION_VERSION_C      0
#define ECUM_SW_MAJOR_VERSION_C                 2
#define ECUM_SW_MINOR_VERSION_C                 0
#define ECUM_SW_PATCH_VERSION_C                 0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ECUM header file are of the same vendor */
#if (ECUM_VENDOR_ID_C != ECUM_VENDOR_ID)
    #error "EcuM.c and EcuM.h have different vendor ids"
#endif

/* Check if source file and ECUM header file are of the same Autosar version */

#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) || \
     (ECUM_AR_RELEASE_REVISION_VERSION_C != ECUM_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of EcuM.c and EcuM.h are different"
#endif

/* Check if source file and ECUM header file are of the same Software version */
#if ((ECUM_SW_MAJOR_VERSION_C != ECUM_SW_MAJOR_VERSION) || \
     (ECUM_SW_MINOR_VERSION_C != ECUM_SW_MINOR_VERSION) || \
     (ECUM_SW_PATCH_VERSION_C != ECUM_SW_PATCH_VERSION))
    #error "Software Version Numbers of EcuM.c and EcuM.h are different"
#endif

#ifdef TEST_CAN
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Can header file are of the same version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C != CANIF_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != CANIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of EcuM.c and CanIf.h are different"
#endif
#endif
#endif

#ifdef TEST_GPT
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Gpt header file are of the same version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of EcuM.c and Gpt.h are different"
#endif
#endif
#endif

#ifdef TEST_LIN
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Lin header file are of the same version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C != LIN_IF_AR_RELEASE_MAJOR_VERSION_CBK) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != LIN_IF_AR_RELEASE_MINOR_VERSION_CBK))
    #error "AutoSar Version Numbers of EcuM.c and LinIf.h are different"
#endif
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types header file are of the same version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C  != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of EcuM.c and Std_Types.h are different"
#endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define ECUM_START_SEC_VAR_CLEARED_32
#include "Ecum_MemMap.h"

EcuM_WakeupSourceType EcuMLastWakeupEvent; /**< @brief last wakeup event to EcuM (source ID)*/

#define ECUM_STOP_SEC_VAR_CLEARED_32
#include "Ecum_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define ECUM_START_SEC_CODE
#include "Ecum_MemMap.h"

/**
* @brief   This function sets the last wakeup event of the ECUM.
* @details This is a function stub only.
* 
* @param[in]     events  last wakeup event
* 
*/
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType events)
{
    EcuMLastWakeupEvent = events;
}

/*================================================================================================*/
/**
* @brief   This function validates the wakeup event.
* @details This is a function stub only. Functionality is void in this implementation
* 
* @param[in]     events wakeup event to validate
*/
void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType events)
{
    (void)events;
}

/*================================================================================================*/
/**
* @brief   This function checks the wakeup source against possible sources of wakeup.
* @details This is a function stub only. It calls the wakeup interfaces of CANIf, GPT and LIN with the wakeupSource parameter.
* 
* @param[in]     wakeupSource  wakeup source ID
* 
*/
void EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource)
{
#ifdef TEST_CAN
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
    CanIf_CheckWakeup(wakeupSource);
#endif
#endif
#ifdef TEST_GPT
    Gpt_CheckWakeup(wakeupSource);
#endif
#ifdef TEST_LIN
    LinIf_CheckWakeup(wakeupSource);
#endif
#ifdef TEST_ICU
    Icu_CheckWakeup(wakeupSource);
#endif
    (void)wakeupSource;
}

#define ECUM_STOP_SEC_CODE
#include "Ecum_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
