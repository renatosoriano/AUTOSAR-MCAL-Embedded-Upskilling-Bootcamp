/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef POWER_IP_RCM_H
#define POWER_IP_RCM_H

/**
*   @file       Power_Ip_RCM.h
*   @version    2.0.0
*
*   @brief   POWER IP driver header file.
*   @details POWER IP driver header file.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_RCM_Types.h"
#include "Power_Ip_Cfg.h"
#include "StandardTypes.h"
#include "Mcal.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_RCM_VENDOR_ID                       43
#define POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_RCM_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_RCM_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_RCM_SW_MAJOR_VERSION                2
#define POWER_IP_RCM_SW_MINOR_VERSION                0
#define POWER_IP_RCM_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_RCM.h file and Power_Ip_RCM_Types.h file are of the same vendor */
#if (POWER_IP_RCM_VENDOR_ID != POWER_IP_RCM_TYPES_VENDOR_ID)
    #error "Power_Ip_RCM.h and Power_Ip_RCM_Types.h have different vendor ids"
#endif

/* Check if Power_Ip_RCM.h file and Power_Ip_RCM_Types.h file are of the same Autosar version */
#if ((POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION != POWER_IP_RCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RCM_AR_RELEASE_MINOR_VERSION != POWER_IP_RCM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_RCM_AR_RELEASE_REVISION_VERSION != POWER_IP_RCM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_RCM.h and Power_Ip_RCM_Types.h are different"
#endif

/* Check if Power_Ip_RCM.h file and Power_Ip_RCM_Types.h file are of the same Software version */
#if ((POWER_IP_RCM_SW_MAJOR_VERSION != POWER_IP_RCM_TYPES_SW_MAJOR_VERSION) || \
     (POWER_IP_RCM_SW_MINOR_VERSION != POWER_IP_RCM_TYPES_SW_MINOR_VERSION) || \
     (POWER_IP_RCM_SW_PATCH_VERSION != POWER_IP_RCM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_RCM.h and Power_Ip_RCM_Types.h are different"
#endif

/* Check if Power_Ip_RCM.h file and Power_Ip_Cfg.h file are of the same vendor */
#if (POWER_IP_RCM_VENDOR_ID != POWER_IP_CFG_VENDOR_ID)
    #error "Power_Ip_RCM.h and Power_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Power_Ip_RCM.h file and Power_Ip_Cfg.h file are of the same Autosar version */
#if ((POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION != POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RCM_AR_RELEASE_MINOR_VERSION != POWER_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_RCM_AR_RELEASE_REVISION_VERSION != POWER_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_RCM.h and Power_Ip_Cfg.h are different"
#endif

/* Check if Power_Ip_RCM.h file and Power_Ip_Cfg.h file are of the same Software version */
#if ((POWER_IP_RCM_SW_MAJOR_VERSION != POWER_IP_CFG_SW_MAJOR_VERSION) || \
     (POWER_IP_RCM_SW_MINOR_VERSION != POWER_IP_CFG_SW_MINOR_VERSION) || \
     (POWER_IP_RCM_SW_PATCH_VERSION != POWER_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_RCM.h and Power_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_RCM.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RCM_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_RCM.h and StandardTypes.h are different"
#endif

/* Check if Power_Ip_RCM.h file and Mcal.h file are of the same Autosar version */
#if ((POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RCM_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_RCM.h and Mcal.h are different"
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

#if (defined(POWER_IP_DISABLE_RCM_INIT) && (STD_OFF == POWER_IP_DISABLE_RCM_INIT))
#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#define Call_Power_Ip_RCM_ResetInit(RCM_pResetConfigPtr) \
    OsIf_Trusted_Call1param(Power_Ip_RCM_ResetInit,(RCM_pResetConfigPtr))
  #else

#define Call_Power_Ip_RCM_ResetInit(RCM_pResetConfigPtr) \
    Power_Ip_RCM_ResetInit(RCM_pResetConfigPtr)
  #endif
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */
#endif

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#define  Call_Power_Ip_RCM_GetResetReason() \
    OsIf_Trusted_Call_Return(Power_Ip_RCM_GetResetReason)
  #else

#define  Call_Power_Ip_RCM_GetResetReason() \
    Power_Ip_RCM_GetResetReason()
  #endif
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#define  Call_Power_Ip_RCM_GetResetRawValue() \
    OsIf_Trusted_Call_Return(Power_Ip_RCM_GetResetRawValue)
  #else

#define  Call_Power_Ip_RCM_GetResetRawValue() \
    Power_Ip_RCM_GetResetRawValue()
  #endif
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */

#if (defined(POWER_IP_DISABLE_RCM_INIT) && (STD_OFF == POWER_IP_DISABLE_RCM_INIT))
void Power_Ip_RCM_ResetInit(const Power_Ip_RCM_ConfigType * ConfigPtr);
#endif

uint32 Power_Ip_RCM_GetResetReason(void);

Power_Ip_RawResetType Power_Ip_RCM_GetResetRawValue(void);

#if (defined(POWER_IP_RESET_ALTERNATE_ISR_USED))
  #if (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON)
  void Power_Ip_RCM_ResetAltInt(void);
  #endif /* (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON) */
#endif


#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_RCM_H */

