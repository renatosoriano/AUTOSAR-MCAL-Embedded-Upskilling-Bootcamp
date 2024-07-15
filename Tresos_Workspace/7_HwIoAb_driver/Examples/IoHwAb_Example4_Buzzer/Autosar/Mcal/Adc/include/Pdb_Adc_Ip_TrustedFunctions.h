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

#ifndef PDB_ADC_IP_TRUSTEDFUNCTIONS_H
#define PDB_ADC_IP_TRUSTEDFUNCTIONS_H

/**
*   @file
*
*   @addtogroup pdb_adc_ip Pdb Adc IPL
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
#include "Pdb_Adc_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PDB_ADC_IP_VENDOR_ID_TRUSTEDFUNCTIONS                      43
#define PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS       4
#define PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS       7
#define PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS    0
#define PDB_ADC_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS               2
#define PDB_ADC_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS               0
#define PDB_ADC_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pdb_Adc_Ip_TrustedFunctions.h file and Pdb_Adc_Ip_CfgDefines.h file are of the same vendor */
#if (PDB_ADC_IP_VENDOR_ID_TRUSTEDFUNCTIONS != PDB_ADC_IP_VENDOR_ID_CFGDEFINES)
    #error "Pdb_Adc_Ip_TrustedFunctions.h and Pdb_Adc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip_TrustedFunctions.h file and Pdb_Adc_Ip_CfgDefines.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip_TrustedFunctions.h and Pdb_Adc_Ip_CfgDefines.h are different"
#endif

/* Check if Pdb_Adc_Ip_TrustedFunctions.h file and Pdb_Adc_Ip_CfgDefines.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS != PDB_ADC_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS != PDB_ADC_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS != PDB_ADC_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip_TrustedFunctions.h and Pdb_Adc_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if  (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK)
/**
* @brief        This function enables the instance back to back mode.
* @details      This function enables the instance back to back mode between PDB0 CH0 and PDB1 CH0 pre-triggers,
* forming a ring (PDB0_CH0_pretrigger7 -> PDB1_CH0_pretrigger0 and PDB1_CH0_pretrigger7 -> PDB0_CH0_pretrigger0)
*
* @param[in]    Instance                Adc instance
* @param[in]    SoftwarePretrigger      Pre-trigger source selection
*
*/
extern void Pdb_Adc_Ip_ConfigInstanceBackToBack_TrustedCall(const boolean InstanceBackToBackEnable);

#endif /* (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK) */

#if  (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK)
/**
* @brief        This function enables the inter-channel back to back mode.
* @details      This function enables the inter-channel back to back mode between PDBx CH0 and PDBx CH1 pre-triggers,
* forming a ring (PDBx_CH0_pretrigger7 -> PDBx_CH1_pretrigger0 and PDBx_CH1_pretrigger7 -> PDBx_CH0_pretrigger0).
*
* @param[in]    Instance                Adc instance
* @param[in]    SoftwarePretrigger      Pre-trigger source selection
*
*/
extern void Pdb_Adc_Ip_ConfigInterChannelBackToBack_TrustedCall(const uint32 Instance,
                                                                const boolean InterChannelBackToBackEnable);

#endif /* (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PDB_ADC_IP_TRUSTEDFUNCTIONS_H */
