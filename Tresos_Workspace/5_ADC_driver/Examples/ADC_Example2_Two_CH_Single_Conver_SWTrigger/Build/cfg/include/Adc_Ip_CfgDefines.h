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

#ifndef ADC_IP_CFGDEFINES_H
#define ADC_IP_CFGDEFINES_H

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
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/* Important Note: The header warapper file depends on header platform and can not be used independently.
*  Do not change #include order in this file */
#include "S32K144_ADC.h"
#include "S32K144_SIM.h"
#include "Adc_Ip_HeaderWrapper_S32K1xx.h"
#include "OsIf.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID_CFGDEFINES                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES       7
#define ADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES    0
#define ADC_IP_SW_MAJOR_VERSION_CFGDEFINES               2
#define ADC_IP_SW_MINOR_VERSION_CFGDEFINES               0
#define ADC_IP_SW_PATCH_VERSION_CFGDEFINES               0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if Adc_Ip_CfgDefines.h file and Adc_Ip_HeaderWrapper_S32K1xx.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_CFGDEFINES != ADC_IP_VENDOR_ID_HEADERWRAPPER_S32K1XX)
    #error "Adc_Ip_CfgDefines.h and Adc_Ip_HeaderWrapper_S32K1xx.h have different vendor ids"
#endif

/* Check if Adc_Ip_CfgDefines.h file and Adc_Ip_HeaderWrapper_S32K1xx.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != ADC_IP_AR_RELEASE_MAJOR_VERSION_HEADERWRAPPER_S32K1XX) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != ADC_IP_AR_RELEASE_MINOR_VERSION_HEADERWRAPPER_S32K1XX) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES != ADC_IP_AR_RELEASE_REVISION_VERSION_HEADERWRAPPER_S32K1XX) \
    )
    #error "AutoSar Version Numbers of Adc_Ip_CfgDefines.h and Adc_Ip_HeaderWrapper_S32K1xx.h are different"
#endif

/* Check if Adc_Ip_CfgDefines.h file and Adc_Ip_HeaderWrapper_S32K1xx.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_CFGDEFINES != ADC_IP_SW_MAJOR_VERSION_HEADERWRAPPER_S32K1XX) || \
     (ADC_IP_SW_MINOR_VERSION_CFGDEFINES != ADC_IP_SW_MINOR_VERSION_HEADERWRAPPER_S32K1XX) || \
     (ADC_IP_SW_PATCH_VERSION_CFGDEFINES != ADC_IP_SW_PATCH_VERSION_HEADERWRAPPER_S32K1XX) \
    )
  #error "Software Version Numbers of Adc_Ip_CfgDefines.h and Adc_Ip_HeaderWrapper_S32K1xx.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check AutoSar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Ip_CfgDefines.h and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

#define ADC_IP_DEV_ERROR_DETECT                (STD_OFF)
#define ADC_IP_TIMEOUT_TYPE                    (OSIF_COUNTER_DUMMY)
#define ADC_IP_TIMEOUT_VAL                     (100000UL)
#define ADC_IP_AIEN_INTERRUPT_ENABLE           (STD_ON)
#define ADC_IP_ENABLE_USER_MODE_SUPPORT        (STD_OFF)
#define ADC_IP_SUPPLY_MONITORING_ENABLED       (STD_OFF)
#define ADC_IP_ENABLE_SIM_SOURCE_SELECTION     (STD_OFF)

/*! @brief ADC default Sample Time from RM */
#define ADC_IP_DEFAULT_SAMPLE_TIME             (0x0CU)
/*! @brief ADC default User Gain from RM */
#define ADC_IP_DEFAULT_USER_GAIN               (0x04U)

/*! @brief ADC Max external channel ID */
#define FEATURE_ADC_MAX_EXT_CHAN_ID            (15U)
/*! @brief ADC has external channels */
#define FEATURE_ADC_HAS_CHANNEL_2              (1U)
#define FEATURE_ADC_HAS_CHANNEL_8              (1U)
#define FEATURE_ADC_HAS_CHANNEL_9              (1U)


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IP_CFGDEFINES_H */

