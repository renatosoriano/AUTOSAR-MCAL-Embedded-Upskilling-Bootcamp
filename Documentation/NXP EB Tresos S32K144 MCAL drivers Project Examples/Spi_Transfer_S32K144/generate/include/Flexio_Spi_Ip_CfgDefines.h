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

#ifndef FLEXIO_SPI_IP_CFG_DEFINES_H
#define FLEXIO_SPI_IP_CFG_DEFINES_H

/**
*   @file     Flexio_Spi_Ip_CfgDefines.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the necessary information for SPI
*            module configuration(s).
*   @addtogroup FLEXIO_DRIVER_CONFIGURATION  Flexio_Spi Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_SPI_IP_CFG_DEFINES_VENDOR_ID                    43
#define FLEXIO_SPI_IP_CFG_DEFINES_MODULE_ID                    83
#define FLEXIO_SPI_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_SPI_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_SPI_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_SPI_IP_CFG_DEFINES_SW_MAJOR_VERSION             2
#define FLEXIO_SPI_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define FLEXIO_SPI_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/



/* Macros that indicate FLEXIO channels used by SPI */
#ifndef FLEXIO_0_CH_0_USED
    #define FLEXIO_0_CH_0_USED
#else
    #error "CHANNEL_0 cannot be used by SPI driver to configure as TX and CLK channels. Channel locked by another driver!"
#endif

#ifndef FLEXIO_0_CH_1_USED
    #define FLEXIO_0_CH_1_USED
#else
    #error "CHANNEL_1 cannot be used by SPI driver to configure as RX and CS channels. Channel locked by another driver!"
#endif


/* Macros that indicate FLEXIO pins used by SPI */
#ifndef FLEXIO_0_PIN_2_USED
    #define FLEXIO_0_PIN_2_USED
#else
    #error "PIN_2 cannot be used by SPI driver to configure for TX channel. PIN locked by another driver!"
#endif

#ifndef FLEXIO_0_PIN_1_USED
    #define FLEXIO_0_PIN_1_USED
#else
    #error "PIN_1 cannot be used by SPI driver to configure for RX channel. PIN locked by another driver!"
#endif

#ifndef FLEXIO_0_PIN_0_USED
    #define FLEXIO_0_PIN_0_USED
#else
    #error "PIN_0 cannot be used by SPI driver to configure for Clk channel. PIN locked by another driver!"
#endif

#ifndef FLEXIO_0_PIN_3_USED
    #define FLEXIO_0_PIN_3_USED
#else
    #error "PIN_3 cannot be used by SPI driver to configure as for channel. PIN locked by another driver!"
#endif


/* Macros that indicate FLEXIO channels used by SPI */
#ifdef FLEXIO_0_CH_0_USED
    #define SPI_CHANNEL_0_USED
#else
    #error "CHANNEL_0 cannot be used by SPI driver to configure as TX and CLK channels. Channel locked by another driver!"
#endif

#ifdef FLEXIO_0_CH_1_USED
    #define SPI_CHANNEL_1_USED
#else
    #error "CHANNEL_1 cannot be used by SPI driver to configure as RX and CS channels. Channel locked by another driver!"
#endif


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* FLEXIO_SPI_IP_CFG_DEFINES_H */
