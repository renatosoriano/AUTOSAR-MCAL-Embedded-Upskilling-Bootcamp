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

#ifndef I2S_IPW_VS_0_PBCFG_H
#define I2S_IPW_VS_0_PBCFG_H

/**
*   @file
*
*   @addtogroup i2s_ipw_config I2s IPW Configuration
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
#include "StandardTypes.h"
#include "I2s_Ipw_Types.h"
#include "Flexio_I2s_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define  I2S_IPW_VS_0_PBCFG_VENDOR_ID                    43
#define  I2S_IPW_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define  I2S_IPW_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION     7
#define  I2S_IPW_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define  I2S_IPW_VS_0_PBCFG_SW_MAJOR_VERSION             2
#define  I2S_IPW_VS_0_PBCFG_SW_MINOR_VERSION             0
#define  I2S_IPW_VS_0_PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes header file are of the same Autosar version */
#if ((I2S_IPW_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of I2s_Ipw_VS_0_PBcfg.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if current file and I2s_Ipw_Types header file are of the same vendor */
#if (I2S_IPW_VS_0_PBCFG_VENDOR_ID != I2S_IPW_TYPES_VENDOR_ID)
#error "I2s_Ipw_VS_0_PBcfg.h and I2s_Ipw_Types.h have different vendor ids"
#endif

/* Check if current file and I2s_Ipw_Types header file are of the same Autosar version */
#if ((I2S_IPW_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION     != I2S_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION     != I2S_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION  != I2S_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw_VS_0_PBcfg.h and I2s_Ipw_Types.h are different"
#endif

/* Check if current file and I2s_Ipw_Types header file are of the same software version */
#if ((I2S_IPW_VS_0_PBCFG_SW_MAJOR_VERSION != I2S_IPW_TYPES_SW_MAJOR_VERSION) || \
     (I2S_IPW_VS_0_PBCFG_SW_MINOR_VERSION != I2S_IPW_TYPES_SW_MINOR_VERSION) || \
     (I2S_IPW_VS_0_PBCFG_SW_PATCH_VERSION != I2S_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw_VS_0_PBcfg.h and I2s_Ipw_Types.h are different"
#endif

/* Check if current file and Flexio_I2s_Ip_Cfg header file are of the same vendor */
#if (I2S_IPW_VS_0_PBCFG_VENDOR_ID != FLEXIO_I2S_IP_CFG_VENDOR_ID)
#error "I2s_Ipw_VS_0_PBcfg.h and Flexio_I2s_Ip_Cfg.h have different vendor ids"
#endif

/* Check if current file and Flexio_I2s_Ip_Cfg header file are of the same Autosar version */
#if ((I2S_IPW_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION     != FLEXIO_I2S_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION     != FLEXIO_I2S_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION  != FLEXIO_I2S_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw_VS_0_PBcfg.h and Flexio_I2s_Ip_Cfg.h are different"
#endif

/* Check if current file and Flexio_I2s_Ip_Cfg header file are of the same software version */
#if ((I2S_IPW_VS_0_PBCFG_SW_MAJOR_VERSION != FLEXIO_I2S_IP_CFG_SW_MAJOR_VERSION) || \
     (I2S_IPW_VS_0_PBCFG_SW_MINOR_VERSION != FLEXIO_I2S_IP_CFG_SW_MINOR_VERSION) || \
     (I2S_IPW_VS_0_PBCFG_SW_PATCH_VERSION != FLEXIO_I2S_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw_VS_0_PBcfg.h and Flexio_I2s_Ip_Cfg.h are different"
#endif


/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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

#define I2S_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2s_MemMap.h"


/**
* @brief          I2s Hw configuration array.
*/
extern const I2s_HwConfigType * const I2s_Ipw_apxHwConfigArr_VS_0[I2S_IPW_CONFIG_COUNT];



#define I2S_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2s_MemMap.h"

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I2S_IPW_VS_0_PBCFG_H */
