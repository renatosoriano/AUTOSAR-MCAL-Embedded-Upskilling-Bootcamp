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

#ifndef FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_H
#define FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Flexio_Spi_Ip_TrustedFunctions.h
*   
*
*   @brief   FLEXIO_SPI IP driver header file.
*   @details FLEXIO_SPI IP driver header file.

*   @addtogroup FLEXIO_SPI_DRIVER Flexio_Spi Driver
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
#include "Flexio_Spi_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                2
#define FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Flexio_Spi_Ip_TrustedFunctions.h and Flexio_Spi_Ip_Cfg.h are of the same vendor */
#if (FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID != FLEXIO_SPI_IP_VENDOR_ID_CFG)
    #error "Flexio_Spi_Ip_TrustedFunctions.h and Flexio_Spi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Flexio_Spi_Ip_TrustedFunctions.h file and Flexio_Spi_Ip_Cfg.h file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Flexio_Spi_Ip_TrustedFunctions.h and Flexio_Spi_Ip_Cfg.h are different"
#endif
#if ((FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != FLEXIO_SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != FLEXIO_SPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSIONs != FLEXIO_SPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Flexio_Spi_Ip_TrustedFunctions.h and Flexio_Spi_Ip_Cfg.h are different"
#endif
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

#if (STD_ON == FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT)
/**
* @brief            This function will enable writing all FLEXIO_SPI registers under protection in User mode by configuring REG_PROT
* @details          This function will enable writing all FLEXIO_SPI registers under protection in User mode by configuring REG_PROT
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return           void.
*/
extern void Flexio_Spi_Ip_SetUserAccess(uint8 Instance);
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_SPI_IP_TRUSTEDFUNCTIONS_H */
