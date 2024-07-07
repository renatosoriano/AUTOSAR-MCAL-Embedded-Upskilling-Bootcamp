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

/**
*   @file    Flexio_Spi_Ip_Irq.c
*   @implements     Flexio_Spi_Ip_Irq.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file.
*   @details Generated Post-Build(PB) configuration file.
*
*   @addtogroup FLEXIO_SPI_IP_DRIVER Flexio_Spi Driver
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

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_SPI_IP_IRQ_VENDOR_ID_C                      43
#define FLEXIO_SPI_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_SPI_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_SPI_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_SPI_IP_IRQ_SW_MAJOR_VERSION_C               2
#define FLEXIO_SPI_IP_IRQ_SW_MINOR_VERSION_C               0
#define FLEXIO_SPI_IP_IRQ_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Flexio_Spi_Ip_Irq.h and Flexio_Spi_Ip.c are of the same vendor */
#if (FLEXIO_SPI_IP_IRQ_VENDOR_ID_C != FLEXIO_SPI_IP_VENDOR_ID)
    #error "Flexio_Spi_Ip_Irq.h and Flexio_Spi_Ip.h have different vendor ids"
#endif

/* Check if Flexio_Spi_Ip_Irq.h file and Flexio_Spi_Ip.h file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_SPI_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_SPI_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexio_Spi_Ip_Irq.h and Flexio_Spi_Ip.h are different"
#endif

#if ((FLEXIO_SPI_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_SPI_IP_SW_MAJOR_VERSION) || \
     (FLEXIO_SPI_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_SPI_IP_SW_MINOR_VERSION) || \
     (FLEXIO_SPI_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_SPI_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_Spi_Ip_Irq.h and Flexio_Spi_Ip.h are different"
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
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (FLEXIO_SPI_IP_ENABLE == STD_ON)
    
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#ifdef FLEXIO_SPI_IP_0_ENABLED
    #if (FLEXIO_SPI_IP_0_ENABLED == STD_ON)
        #if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
void Flexio_Spi_Ip_FLEXIO_SPI_0_IrqTxDmaHandler(void);
void Flexio_Spi_Ip_FLEXIO_SPI_0_IrqRxDmaHandler(void);
        #endif
    #endif
#endif
#ifdef FLEXIO_SPI_IP_1_ENABLED
    #if (FLEXIO_SPI_IP_1_ENABLED == STD_ON)
        #if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
void Flexio_Spi_Ip_FLEXIO_SPI_1_IrqTxDmaHandler(void);
void Flexio_Spi_Ip_FLEXIO_SPI_1_IrqRxDmaHandler(void);
        #endif
    #endif
#endif
#ifdef FLEXIO_SPI_IP_2_ENABLED
    #if (FLEXIO_SPI_IP_2_ENABLED == STD_ON)
        #if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
void Flexio_Spi_Ip_FLEXIO_SPI_2_IrqTxDmaHandler(void);
void Flexio_Spi_Ip_FLEXIO_SPI_2_IrqRxDmaHandler(void);
        #endif
    #endif
#endif
#ifdef FLEXIO_SPI_IP_3_ENABLED
    #if (FLEXIO_SPI_IP_3_ENABLED == STD_ON)
        #if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
void Flexio_Spi_Ip_FLEXIO_SPI_3_IrqTxDmaHandler(void);
void Flexio_Spi_Ip_FLEXIO_SPI_3_IrqRxDmaHandler(void);
        #endif
    #endif
#endif

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef FLEXIO_SPI_IP_0_ENABLED
    #if (FLEXIO_SPI_IP_0_ENABLED == STD_ON)
        #if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
void Flexio_Spi_Ip_FLEXIO_SPI_0_IrqTxDmaHandler(void)
{
    Flexio_Spi_Ip_IrqTxDmaHandler(0u); /* Call Flexio_Spi_Ip_IrqTxDmaHandler for FLEXIO_SPI_0 */
}
void Flexio_Spi_Ip_FLEXIO_SPI_0_IrqRxDmaHandler(void)
{
    Flexio_Spi_Ip_IrqRxDmaHandler(0u); /* Call Flexio_Spi_Ip_IrqRxDmaHandler for FLEXIO_SPI_0 */
}
        #endif
    #endif
#endif
#ifdef FLEXIO_SPI_IP_1_ENABLED
    #if (FLEXIO_SPI_IP_1_ENABLED == STD_ON)
        #if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
void Flexio_Spi_Ip_FLEXIO_SPI_1_IrqTxDmaHandler(void)
{
    Flexio_Spi_Ip_IrqTxDmaHandler(1u); /* Call Flexio_Spi_Ip_IrqTxDmaHandler for FLEXIO_SPI_1 */
}
void Flexio_Spi_Ip_FLEXIO_SPI_1_IrqRxDmaHandler(void)
{
    Flexio_Spi_Ip_IrqRxDmaHandler(1u); /* Call Flexio_Spi_Ip_IrqRxDmaHandler for FLEXIO_SPI_1 */
}
        #endif
    #endif
#endif
#ifdef FLEXIO_SPI_IP_2_ENABLED
    #if (FLEXIO_SPI_IP_2_ENABLED == STD_ON)
        #if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
void Flexio_Spi_Ip_FLEXIO_SPI_2_IrqTxDmaHandler(void)
{
    Flexio_Spi_Ip_IrqTxDmaHandler(2u); /* Call Flexio_Spi_Ip_IrqTxDmaHandler for FLEXIO_SPI_2 */
}
void Flexio_Spi_Ip_FLEXIO_SPI_2_IrqRxDmaHandler(void)
{
    Flexio_Spi_Ip_IrqRxDmaHandler(2u); /* Call Flexio_Spi_Ip_IrqRxDmaHandler for FLEXIO_SPI_2 */
}
        #endif
    #endif
#endif
#ifdef FLEXIO_SPI_IP_3_ENABLED
    #if (FLEXIO_SPI_IP_3_ENABLED == STD_ON)
        #if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
void Flexio_Spi_Ip_FLEXIO_SPI_3_IrqTxDmaHandler(void)
{
    Flexio_Spi_Ip_IrqTxDmaHandler(3u); /* Call Flexio_Spi_Ip_IrqTxDmaHandler for FLEXIO_SPI_3 */
}
void Flexio_Spi_Ip_FLEXIO_SPI_3_IrqRxDmaHandler(void)
{
    Flexio_Spi_Ip_IrqRxDmaHandler(3u); /* Call Flexio_Spi_Ip_IrqRxDmaHandler for FLEXIO_SPI_3 */
}
        #endif
    #endif
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#endif /*(FLEXIO_SPI_IP_ENABLE == STD_ON)*/

#ifdef __cplusplus
}
#endif

/** @} */
