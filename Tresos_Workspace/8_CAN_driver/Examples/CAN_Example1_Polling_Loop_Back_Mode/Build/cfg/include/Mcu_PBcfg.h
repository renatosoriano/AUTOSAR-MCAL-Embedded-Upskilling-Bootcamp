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

#ifndef MCU_PBCFG_H
#define MCU_PBCFG_H

/**
*   @file       Mcu_PBcfg.h
*   @implements Mcu_PBcfg.h_Artifact
*   @version    2.0.0
*
*   @brief      AUTOSAR Mcu - Data structures for the Mcu driver.
*   @details    Postbuild structure configurations for the driver initalization.
*
*   @addtogroup MCU
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif



/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_PBCFG_VENDOR_ID                     43
#define MCU_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define MCU_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define MCU_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define MCU_PBCFG_SW_MAJOR_VERSION              2
#define MCU_PBCFG_SW_MINOR_VERSION              0
#define MCU_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

#define MCU_CONFIG_PB \
 extern const Mcu_ConfigType Mcu_Config;

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef MCU_PBCFG_H */


