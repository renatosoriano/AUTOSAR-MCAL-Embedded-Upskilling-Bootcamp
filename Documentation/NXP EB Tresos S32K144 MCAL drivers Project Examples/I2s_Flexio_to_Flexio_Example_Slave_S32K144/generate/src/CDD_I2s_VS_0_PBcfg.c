/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : I2S
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
*   @addtogroup i2s_driver_config I2s Driver Configuration
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
#include "CDD_I2s_VS_0_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2S_VS_0_PBCFG_VENDOR_ID_C                       43
#define I2S_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define I2S_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C        7
#define I2S_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define I2S_VS_0_PBCFG_SW_MAJOR_VERSION_C                2
#define I2S_VS_0_PBCFG_SW_MINOR_VERSION_C                0
#define I2S_VS_0_PBCFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_I2s_VS_0_PBcfg header file are of the same vendor */
#if (I2S_VS_0_PBCFG_VENDOR_ID_C != I2S_VS_0_PBCFG_VENDOR_ID)
#error "CDD_I2s_VS_0_PBcfg.c and CDD_I2s_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if current file and CDD_I2s_VS_0_PBcfg header file are of the same Autosar version */
#if ((I2S_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C     != I2S_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C     != I2S_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (I2S_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C  != I2S_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_I2s_VS_0_PBcfg.c and CDD_I2s_VS_0_PBcfg.h are different"
#endif

/* Check if current file and CDD_I2s_VS_0_PBcfg header file are of the same software version */
#if ((I2S_VS_0_PBCFG_SW_MAJOR_VERSION_C != I2S_VS_0_PBCFG_SW_MAJOR_VERSION) || \
     (I2S_VS_0_PBCFG_SW_MINOR_VERSION_C != I2S_VS_0_PBCFG_SW_MINOR_VERSION) || \
     (I2S_VS_0_PBCFG_SW_PATCH_VERSION_C != I2S_VS_0_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_I2s_VS_0_PBcfg.c and CDD_I2s_VS_0_PBcfg.h are different"
#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

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
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define I2S_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2s_MemMap.h"


/**
* @brief          I2s driver Configuration structure _VS_0.
*/
const I2s_ConfigType I2s_xConfig =
{
    (I2s_HwUnitCount)I2S_IPW_CONFIG_COUNT,  /*.cfgCount*/
    I2s_Ipw_apxHwConfigArr_VS_0,    /*.pHwConfig*/
};

const I2s_ConfigType * const I2s_pxConfigVariantPredefined =
{
    &I2s_xConfig
};


#define I2S_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2s_MemMap.h"

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
