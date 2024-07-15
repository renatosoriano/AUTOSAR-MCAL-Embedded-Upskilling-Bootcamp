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

#ifndef ADC_IPW_PBCFG_H
#define ADC_IPW_PBCFG_H

/**
*   @file
*
*   @addtogroup adc_ipw_config Adc Ipw Configuration
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

#include "Adc_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_IPW_VENDOR_ID_PBCFG                       43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG        4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_PBCFG        7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_PBCFG     0
#define ADC_IPW_SW_MAJOR_VERSION_PBCFG                2
#define ADC_IPW_SW_MINOR_VERSION_PBCFG                0
#define ADC_IPW_SW_PATCH_VERSION_PBCFG                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check vendor id */
#if (ADC_IPW_VENDOR_ID_PBCFG != ADC_IPW_VENDOR_ID_TYPES)
    #error "Adc_Ipw_PBcfg.h and Adc_Ipw_Types.h have different vendor ids"
#endif

/* Check Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG != ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_PBCFG != ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_PBCFG != ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_PBcfg.h and Adc_Ipw_Types.h are different"
#endif

/* Check Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_PBCFG != ADC_IPW_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_PBCFG != ADC_IPW_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_PBCFG != ADC_IPW_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_PBcfg.h and Adc_Ipw_Types.h are different"
#endif

/*==================================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          Adc Ipw Config configuration variant .
*/
extern const Adc_Ipw_Config AdcIpwCfg;

/**
* @brief          ADC Ipw Group 0 Config .
*/
extern const Adc_Ipw_GroupConfig AdcIpwGroupConfig_0;

/**
* @brief          ADC Ipw Group 1 Config .
*/
extern const Adc_Ipw_GroupConfig AdcIpwGroupConfig_1;


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IPW_PBCFG_H */

