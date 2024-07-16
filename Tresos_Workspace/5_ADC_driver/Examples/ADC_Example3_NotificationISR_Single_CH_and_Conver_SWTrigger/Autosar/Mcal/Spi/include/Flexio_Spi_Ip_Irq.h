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
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   Copyright 2020-2023 NXP Semiconductors NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXIO_SPI_IP_IRQ_H
#define FLEXIO_SPI_IP_IRQ_H

/**
*   @file     Flexio_Spi_Ip_Irq.h
*
*   @brief   FLEXIO_SPI_IP_IRQ IP driver header file.
*   @details FLEXIO_SPI_IP_IRQ IP driver header file.

*   @addtogroup FLEXIO_SPI_DRIVER  Flexio_Spi Driver
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
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_SPI_IP_IRQ_VENDOR_ID                       43
#define FLEXIO_SPI_IP_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define FLEXIO_SPI_IP_IRQ_AR_RELEASE_MINOR_VERSION        7
#define FLEXIO_SPI_IP_IRQ_AR_RELEASE_REVISION_VERSION     0
#define FLEXIO_SPI_IP_IRQ_SW_MAJOR_VERSION                2
#define FLEXIO_SPI_IP_IRQ_SW_MINOR_VERSION                0
#define FLEXIO_SPI_IP_IRQ_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

void Flexio_Spi_Ip_IrqHandler(
                                uint8 ShifterIndex,
                                uint8 ShifterMaskFlag,
                                uint8 ShifterErrMaskFlag
                              );

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
 
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_SPI_IP_IRQ_H */
