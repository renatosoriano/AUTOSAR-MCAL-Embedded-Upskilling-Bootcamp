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

/**   
*   @file     Flexio_Spi_Ip_PBcfg.c
*   @version 2.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
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
#include "Flexio_Spi_Ip.h"

#if (FLEXIO_SPI_IP_ENABLE == STD_ON)
#if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
#include "Dma_Ip.h"
#endif
#endif

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_SPI_IP_VENDOR_ID_PBCFG_C                        43
#define FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C         7
#define FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define FLEXIO_SPI_IP_SW_MAJOR_VERSION_PBCFG_C                 2
#define FLEXIO_SPI_IP_SW_MINOR_VERSION_PBCFG_C                 0
#define FLEXIO_SPI_IP_SW_PATCH_VERSION_PBCFG_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Flexio_Spi_Ip__PBcfg source file and Spi configuration header file are of the same vendor */
#if (FLEXIO_SPI_IP_VENDOR_ID_PBCFG_C != FLEXIO_SPI_IP_VENDOR_ID)
    #error "Flexio_Spi_Ip_PBcfg.c and Flexio_Spi_Ip.h have different vendor IDs"
#endif

#if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C    != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C != FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexio_Spi_Ip_PBcfg.h and Flexio_Spi_Ip.h are different"
#endif
/* Check if Flexio_Spi_Ip__PBcfg header file and Spi configuration header file are of the same software version */
#if ((FLEXIO_SPI_IP_SW_MAJOR_VERSION_PBCFG_C != FLEXIO_SPI_IP_SW_MAJOR_VERSION) || \
     (FLEXIO_SPI_IP_SW_MINOR_VERSION_PBCFG_C != FLEXIO_SPI_IP_SW_MINOR_VERSION) || \
     (FLEXIO_SPI_IP_SW_PATCH_VERSION_PBCFG_C != FLEXIO_SPI_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_Spi_Ip_PBcfg.h and Flexio_Spi_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (FLEXIO_SPI_IP_ENABLE == STD_ON)
    #if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
        #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
             (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C != DMA_IP_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Flexio_Spi_Ip_PBcfg.h and Dma_Ip.h are different"
        #endif
    #endif /* (FLEXIO_SPI_IP_DMA_USED == STD_ON) */
    #endif /* (FLEXIO_SPI_IP_ENABLE == STD_ON) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */


/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#if (FLEXIO_SPI_IP_ENABLE == STD_ON)

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#endif /*(FLEXIO_SPI_IP_ENABLE == STD_ON)*/
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
