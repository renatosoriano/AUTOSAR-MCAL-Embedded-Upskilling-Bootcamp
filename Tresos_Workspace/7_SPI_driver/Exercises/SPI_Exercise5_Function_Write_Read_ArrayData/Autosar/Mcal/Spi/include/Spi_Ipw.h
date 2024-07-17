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

#ifndef SPI_IPW_H
#define SPI_IPW_H

/**
*   @file    Spi_Ipw.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Spi middle level driver header file.
*   @details This file is the header containing all the necessary information for SPI
*            LLD.
*   @addtogroup SPI_DRIVER Spi Driver
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

#include "Spi.h"
#include "Lpspi_Ip.h"
#include "Flexio_Spi_Ip.h"
#include "Spi_Ipw_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_VENDOR_ID                       43
#define SPI_IPW_AR_RELEASE_MAJOR_VERSION        4
#define SPI_IPW_AR_RELEASE_MINOR_VERSION        7
#define SPI_IPW_AR_RELEASE_REVISION_VERSION     0
#define SPI_IPW_SW_MAJOR_VERSION                2
#define SPI_IPW_SW_MINOR_VERSION                0
#define SPI_IPW_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi.h and Spi_Ipw.h are of the same vendor */
#if (SPI_VENDOR_ID != SPI_IPW_VENDOR_ID)
    #error "Spi.h and Spi_Ipw.h have different vendor ids"
#endif
/* Check if Spi.h file and Spi_Ipw.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION != SPI_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi.h and Spi_Ipw.h are different"
#endif
#if ((SPI_SW_MAJOR_VERSION != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION != SPI_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi.h and Spi_Ipw.h are different"
#endif

/* Check if Spi_Ipw.h and Flexio_Spi_Ip.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID != FLEXIO_SPI_IP_VENDOR_ID)
    #error "Spi_Ipw.h and Flexio_Spi_Ip.h have different vendor ids"
#endif
/* Check if Spi_Ipw.h file and Flexio_Spi_Ip.h file are of the same Autosar version */
#if ((SPI_IPW_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_MINOR_VERSION    != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_AR_RELEASE_REVISION_VERSION != FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_Ipw.h and Flexio_Spi_Ip.h are different"
#endif
#if ((SPI_IPW_SW_MAJOR_VERSION != FLEXIO_SPI_IP_SW_MAJOR_VERSION) || \
     (SPI_IPW_SW_MINOR_VERSION != FLEXIO_SPI_IP_SW_MINOR_VERSION) || \
     (SPI_IPW_SW_PATCH_VERSION != FLEXIO_SPI_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_Ipw.h and Flexio_Spi_Ip.h are different"
#endif

/* Check if Lpspi_Ip.h and Spi_Ipw.h are of the same vendor */
#if (LPSPI_IP_VENDOR_ID != SPI_IPW_VENDOR_ID)
    #error "Lpspi_Ip.h and Spi_Ipw.h have different vendor ids"
#endif
/* Check if Lpspi_Ip.h file and Spi_Ipw.h file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Lpspi_Ip.h and Spi_Ipw.h are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION != SPI_IPW_SW_MAJOR_VERSION) || \
     (LPSPI_IP_SW_MINOR_VERSION != SPI_IPW_SW_MINOR_VERSION) || \
     (LPSPI_IP_SW_PATCH_VERSION != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Lpspi_Ip.h and Spi_Ipw.h are different"
#endif

/* Check if Spi_Ipw_Types.h and Spi_Ipw.h are of the same vendor */
#if (SPI_IPW_TYPES_VENDOR_ID != SPI_IPW_VENDOR_ID)
    #error "Spi_Ipw_Types.h and Spi_Ipw.h have different vendor ids"
#endif
/* Check if Spi_Ipw_Types.h file and Spi_Ipw.h file are of the same Autosar version */
#if ((SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Ipw_Types.h and Spi_Ipw.h are different"
#endif
#if ((SPI_IPW_TYPES_SW_MAJOR_VERSION != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_IPW_TYPES_SW_MINOR_VERSION != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_IPW_TYPES_SW_PATCH_VERSION != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Ipw_Types.h and Spi_Ipw.h are different"
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

void Spi_Ipw_Init(const Spi_HWUnitType HWUnitId, const Spi_HWUnitConfigType * HWUnit);

void Spi_Ipw_DeInit(Spi_HWUnitType HWUnit, uint32 SpiCoreID);

#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0))
Std_ReturnType Spi_Ipw_SyncTransmit(const Spi_JobConfigType *JobConfig, uint32 SpiCoreID);
#endif /* #if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) ) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
void Spi_Ipw_JobTransfer(const Spi_JobConfigType *JobConfig);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
void Spi_Ipw_IrqPoll(Spi_HWUnitType HWUnit, uint32 SpiCoreID);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
void Spi_Ipw_IrqConfig(Spi_HWUnitType HWUnit, Spi_AsyncModeType Mode, uint32 SpiCoreID);
#endif

#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_CANCEL_API == STD_ON))
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
void Spi_Ipw_SlaveCancel(const Spi_JobConfigType *JobConfig);
    #endif
#endif

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
void Spi_Ipw_SetClockMode(Spi_DualClockModeType ClockMode, const Spi_HWUnitConfigType * HWUnitConfig);
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*SPI_IPW_H*/
