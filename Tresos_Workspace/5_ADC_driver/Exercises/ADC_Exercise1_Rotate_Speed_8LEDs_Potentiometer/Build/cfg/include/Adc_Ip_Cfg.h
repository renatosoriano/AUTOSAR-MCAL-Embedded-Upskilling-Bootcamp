/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef ADC_IP_CFG_H
#define ADC_IP_CFG_H

/**
*   @file
*
*   @addtogroup adc_ip_config Adc IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc_Ip_Types.h"
#include "Adc_Ip_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_IP_VENDOR_ID_CFG                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_CFG       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_CFG       7
#define ADC_IP_AR_RELEASE_REVISION_VERSION_CFG    0
#define ADC_IP_SW_MAJOR_VERSION_CFG               2
#define ADC_IP_SW_MINOR_VERSION_CFG               0
#define ADC_IP_SW_PATCH_VERSION_CFG               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Ip_Cfg.h file and Adc_Ip_Types.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_CFG != ADC_IP_VENDOR_ID_TYPES)
    #error "Adc_Ip_Cfg.h and Adc_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Ip_Cfg.h file and Adc_Ip_Types.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_CFG != ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_CFG != ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_CFG != ADC_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ip_Cfg.h and Adc_Ip_Types.h are different"
#endif

/* Check if Adc_Ip_Cfg.h file and Adc_Ip_Types.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_CFG != ADC_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IP_SW_MINOR_VERSION_CFG != ADC_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_IP_SW_PATCH_VERSION_CFG != ADC_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ip_Cfg.h and Adc_Ip_Types.h are different"
#endif

/* Check if Adc_Ip_Cfg.h file and Adc_Ip_PBcfg.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_CFG != ADC_IP_VENDOR_ID_PBCFG)
    #error "Adc_Ip_Cfg.h and Adc_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ip_Cfg.h file and Adc_Ip_PBcfg.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_CFG != ADC_IP_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_CFG != ADC_IP_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_CFG != ADC_IP_AR_RELEASE_REVISION_VERSION_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ip_Cfg.h and Adc_Ip_PBcfg.h are different"
#endif

/* Check if Adc_Ip_Cfg.h file and Adc_Ip_PBcfg.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_CFG != ADC_IP_SW_MAJOR_VERSION_PBCFG) || \
     (ADC_IP_SW_MINOR_VERSION_CFG != ADC_IP_SW_MINOR_VERSION_PBCFG) || \
     (ADC_IP_SW_PATCH_VERSION_CFG != ADC_IP_SW_PATCH_VERSION_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ip_Cfg.h and Adc_Ip_PBcfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
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
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IP_CFG_H */

