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

#ifndef POWER_IP_PMC_H
#define POWER_IP_PMC_H

/**
*   @file       Power_Ip_PMC.h
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
#include "Power_Ip.h"
#include "Power_Ip_PMC_Types.h"
#include "StandardTypes.h"
#include "Mcal.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_PMC_VENDOR_ID                       43
#define POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_PMC_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_PMC_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_PMC_SW_MAJOR_VERSION                2
#define POWER_IP_PMC_SW_MINOR_VERSION                0
#define POWER_IP_PMC_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_PMC.h file and Power_Ip.h file are of the same vendor */
#if (POWER_IP_PMC_VENDOR_ID != POWER_IP_VENDOR_ID)
    #error "Power_Ip_PMC.h and Power_Ip.h have different vendor ids"
#endif

/* Check if Power_Ip_PMC.h file and Power_Ip.h file are of the same Autosar version */
#if ((POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION != POWER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_AR_RELEASE_MINOR_VERSION != POWER_IP_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PMC_AR_RELEASE_REVISION_VERSION != POWER_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_PMC.h and Power_Ip.h are different"
#endif

/* Check if Power_Ip_PMC.h file and Power_Ip.h file are of the same Software version */
#if ((POWER_IP_PMC_SW_MAJOR_VERSION != POWER_IP_SW_MAJOR_VERSION) || \
     (POWER_IP_PMC_SW_MINOR_VERSION != POWER_IP_SW_MINOR_VERSION) || \
     (POWER_IP_PMC_SW_PATCH_VERSION != POWER_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_PMC.h and Power_Ip.h are different"
#endif

/* Check if Power_Ip_PMC.h file and Power_Ip_PMC_Types.h file are of the same vendor */
#if (POWER_IP_PMC_VENDOR_ID != POWER_IP_PMC_TYPES_VENDOR_ID)
    #error "Power_Ip_PMC.h and Power_Ip_PMC_Types.h have different vendor ids"
#endif

/* Check if Power_Ip_PMC.h file and Power_Ip_PMC_Types.h file are of the same Autosar version */
#if ((POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION != POWER_IP_PMC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_AR_RELEASE_MINOR_VERSION != POWER_IP_PMC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PMC_AR_RELEASE_REVISION_VERSION != POWER_IP_PMC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_PMC.h and Power_Ip_PMC_Types.h are different"
#endif

/* Check if Power_Ip_PMC.h file and Power_Ip_PMC_Types.h file are of the same Software version */
#if ((POWER_IP_PMC_SW_MAJOR_VERSION != POWER_IP_PMC_TYPES_SW_MAJOR_VERSION) || \
     (POWER_IP_PMC_SW_MINOR_VERSION != POWER_IP_PMC_TYPES_SW_MINOR_VERSION) || \
     (POWER_IP_PMC_SW_PATCH_VERSION != POWER_IP_PMC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_PMC.h and Power_Ip_PMC_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_PMC.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_PMC.h and StandardTypes.h are different"
#endif

/* Check if Power_Ip_PMC.h file and Mcal.h file are of the same Autosar version */
#if ((POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_PMC.h and Mcal.h are different"
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

#if (defined(POWER_IP_DISABLE_PMC_INIT) && (STD_OFF == POWER_IP_DISABLE_PMC_INIT))
#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#define  Call_Power_Ip_PMC_PowerInit(PMC_pConfigPtr) \
    OsIf_Trusted_Call1param(Power_Ip_PMC_PowerInit,(PMC_pConfigPtr))
  #else

#define  Call_Power_Ip_PMC_PowerInit(PMC_pConfigPtr) \
    Power_Ip_PMC_PowerInit(PMC_pConfigPtr)
  #endif  /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* #ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT */

void Power_Ip_PMC_PowerInit(const Power_Ip_PMC_ConfigType * ConfigPtr);
#endif

#if (defined(POWER_IP_PMCAECONFIG_API) && (STD_ON == POWER_IP_PMCAECONFIG_API))
void Power_Ip_PMC_AE_PowerInit(const Power_Ip_PMC_ConfigType * ConfigPtr);
#endif

#if (defined(POWER_IP_VOLTAGE_ERROR_ISR_USED))
  #if(POWER_IP_VOLTAGE_ERROR_ISR_USED == STD_ON)
void Power_Ip_PMC_VoltageErrorIsr(void);
uint8 Power_Ip_PMC_GetInterruptStatus(void);

#if (defined(POWER_IP_PMCAECONFIG_API) && (STD_ON == POWER_IP_PMCAECONFIG_API))
void Power_Ip_PMC_AE_VoltageDetectHvdOnVddintVdd15Isr(void);
void Power_Ip_PMC_AE_VoltageDetectHvdOnVddIsr(void);
void Power_Ip_PMC_AE_VoltageDetectLvdOnVddcIsr(void);
void Power_Ip_PMC_AE_VoltageDetectLvdOnVlsIsr(void);
#endif

  #endif /* (POWER_IP_VOLTAGE_ERROR_ISR_USED == STD_ON) */
#endif


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_PMC_H */


