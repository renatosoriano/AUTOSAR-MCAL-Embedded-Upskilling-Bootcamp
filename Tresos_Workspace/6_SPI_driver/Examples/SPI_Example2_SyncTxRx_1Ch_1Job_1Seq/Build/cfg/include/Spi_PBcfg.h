/**
*   @file    Spi_PBcfg.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the extern declaration for SPI
*            module configuration(s).
*   @addtogroup SPI_DRIVER_CONFIGURATION Spi Driver Configuration
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/


#ifndef SPI_PBCFG_H
#define SPI_PBCFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
* 4) user callback header files
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VENDOR_ID_PBCFG_H                    43
#define SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_H     4
#define SPI_AR_RELEASE_MINOR_VERSION_PBCFG_H     7
#define SPI_AR_RELEASE_REVISION_VERSION_PBCFG_H  0
#define SPI_SW_MAJOR_VERSION_PBCFG_H             2
#define SPI_SW_MINOR_VERSION_PBCFG_H             0
#define SPI_SW_PATCH_VERSION_PBCFG_H             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define SPI_CONFIG_PB \
 extern const Spi_ConfigType Spi_Config;
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif

/** @} */
