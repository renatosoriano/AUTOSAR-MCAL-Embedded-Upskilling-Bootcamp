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

#ifndef ADC_IP_TRUSTEDFUNCTIONS_H
#define ADC_IP_TRUSTEDFUNCTIONS_H

/**
*   @file
*
*   @addtogroup adc_ip Adc IPL
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
#include "Adc_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID_TRUSTEDFUNCTIONS                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS       7
#define ADC_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS    0
#define ADC_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS               2
#define ADC_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS               0
#define ADC_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Ip_TrustedFunctions.h file and Adc_Ip_CfgDefines.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_TRUSTEDFUNCTIONS != ADC_IP_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ip_TrustedFunctions.h and Adc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ip_TrustedFunctions.h file and Adc_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS != ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS != ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS != ADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ip_TrustedFunctions.h and Adc_Ip_CfgDefines.h are different"
#endif

/* Check if Adc_Ip_TrustedFunctions.h file and Adc_Ip_CfgDefines.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS != ADC_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS != ADC_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS != ADC_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ip_TrustedFunctions.h and Adc_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
/**
* @brief        This function enable supply monitoring for the internal channels on SIM registers
* @details      This function enable supply monitoring for the internal channels on SIM registers
*
* @param[in]    SupplyEnable       Enable (TRUE) or Disable (FALSE) supply monitoring
*
*/
extern void Adc_Ip_SetSupplyMonitoringEnable_TrustedCall(const boolean SupplyEnable);

/**
* @brief        This function configures the internal channels on on SIM registers
* @details      This function configures the internal channels on on SIM registers
*
* @param[in]    SupplyChannel       Selected supply channel
*
*/
extern void Adc_Ip_ConfigSupplyMonitoringChannel_TrustedCall(const uint32 SupplyChannel);

/**
* @brief        This function resets the muxing for ADC channel on SIM register to reset value
* @details      This function resets the muxing for ADC channel on SIM register to reset value
*
* @param[in]    none
*
*/
extern void Adc_Ip_ResetSupplyMonitoringChannel_TrustedCall(void);
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */

#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
/**
* @brief        This function selects trigger source for an ADC instance
* @details      This function selects trigger source for an ADC instance
*
* @param[in]    Instance            Adc instance
* @param[in]    TriggerSource       Trigger source selection
*
*/
extern void Adc_Ip_SetTriggerSourceSelect_TrustedCall(const uint32 Instance,
                                                      const uint8 TriggerSource);

/**
* @brief        This function selects pretrigger source for an ADC instance
* @details      This function selects pretrigger source for an ADC instance
*
* @param[in]    Instance                Adc instance
* @param[in]    PretriggerSource        Pre-trigger source selection
*
*/
extern void Adc_Ip_SetPretriggerSourceSelect_TrustedCall(const uint32 Instance,
                                                         const uint8 PretriggerSource);

/**
* @brief        This function writes the software pretrigger source to be configured for an ADC instance
* @details      This function writes the software pretrigger source to be configured for an ADC instance
*
* @param[in]    Instance                Adc instance
* @param[in]    SoftwarePretrigger      Pre-trigger source selection
*
*/
extern void Adc_Ip_SetSoftwarePretrigger_TrustedCall(const uint32 Instance,
                                                     const uint8 SoftwarePretrigger);
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IP_TRUSTEDFUNCTIONS_H */
