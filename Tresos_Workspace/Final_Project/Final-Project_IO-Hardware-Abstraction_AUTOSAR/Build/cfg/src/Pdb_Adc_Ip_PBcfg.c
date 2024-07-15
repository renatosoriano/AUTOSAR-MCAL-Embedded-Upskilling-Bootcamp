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

/**
*   @file
*
*   @addtogroup pdb_adc_ip_config Pdb Adc IPL Configuration
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
#include "Pdb_Adc_Ip_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PDB_ADC_IP_VENDOR_ID_PBCFG_C                     43
#define PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C      4
#define PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C      7
#define PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C   0
#define PDB_ADC_IP_SW_MAJOR_VERSION_PBCFG_C              2
#define PDB_ADC_IP_SW_MINOR_VERSION_PBCFG_C              0
#define PDB_ADC_IP_SW_PATCH_VERSION_PBCFG_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pdb_Adc_Ip_PBcfg.c file and Pdb_Adc_Ip_PBcfg.h file are of the same vendor */
#if (PDB_ADC_IP_VENDOR_ID_PBCFG_C != PDB_ADC_IP_VENDOR_ID_PBCFG)
    #error "Pdb_Adc_Ip_PBcfg.c and Pdb_Adc_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip_PBcfg.c file and Pdb_Adc_Ip_PBcfg.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_PBCFG) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip_PBcfg.c and Pdb_Adc_Ip_PBcfg.h are different"
#endif

/* Check if Pdb_Adc_Ip_PBcfg.c file and Pdb_Adc_Ip_PBcfg.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION_PBCFG_C != PDB_ADC_IP_SW_MAJOR_VERSION_PBCFG) || \
     (PDB_ADC_IP_SW_MINOR_VERSION_PBCFG_C != PDB_ADC_IP_SW_MINOR_VERSION_PBCFG) || \
     (PDB_ADC_IP_SW_PATCH_VERSION_PBCFG_C != PDB_ADC_IP_SW_PATCH_VERSION_PBCFG) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip_PBcfg.c and Pdb_Adc_Ip_PBcfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

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

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          PDB Ip Config for Hardware Unit ADC0 for configuration variant .
*/
const Pdb_Adc_Ip_ConfigType PdbAdcIpConfig_0 =
{
    PDB_ADC_IP_LOAD_VAL_IMMEDIATELY, /* LoadValueMode */
    (Pdb_Adc_Ip_ClkPrescalerDivType) 0U, /* PrescalerDiv */
    (Pdb_Adc_Ip_ClkPrescalerMultFactType) 0U, /* ClkPreMultFactor */
    PDB_ADC_IP_SOFTWARE_TRIGGER, /* TriggerSource */
    (boolean)FALSE, /* ContinuousModeEnable */
    (boolean)FALSE, /* DmaEnable */
    65535U, /* ModValue */
#if  (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK)
    (boolean)FALSE, /* InstanceBackToBackEnable */
#endif /* (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK) */
#if  (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK)
    (boolean)FALSE, /* InterChannelBackToBackEnable */
#endif /* (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK) */
    0u, /* NumChans */
    NULL_PTR, /* ChanConfigs */
    NULL_PTR /* SeqErrNotification */
};

/**
* @brief          PDB Ip Config for Hardware Unit ADC1 for configuration variant .
*/
const Pdb_Adc_Ip_ConfigType PdbAdcIpConfig_1 =
{
    PDB_ADC_IP_LOAD_VAL_IMMEDIATELY, /* LoadValueMode */
    (Pdb_Adc_Ip_ClkPrescalerDivType) 0U, /* PrescalerDiv */
    (Pdb_Adc_Ip_ClkPrescalerMultFactType) 0U, /* ClkPreMultFactor */
    PDB_ADC_IP_SOFTWARE_TRIGGER, /* TriggerSource */
    (boolean)FALSE, /* ContinuousModeEnable */
    (boolean)FALSE, /* DmaEnable */
    65535U, /* ModValue */
#if  (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK)
    (boolean)FALSE, /* InstanceBackToBackEnable */
#endif /* (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK) */
#if  (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK)
    (boolean)FALSE, /* InterChannelBackToBackEnable */
#endif /* (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK) */
    0u, /* NumChans */
    NULL_PTR, /* ChanConfigs */
    NULL_PTR /* SeqErrNotification */
};



#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

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

