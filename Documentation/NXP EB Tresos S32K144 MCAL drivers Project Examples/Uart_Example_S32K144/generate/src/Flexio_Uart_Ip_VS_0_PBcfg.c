/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO
*   Dependencies         : 
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
*   @defgroup flexio_uart_tx_ip Flexio UART IPL
*   @addtogroup  flexio_uart_tx_ip Flexio UART IPL
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

#include "Flexio_Uart_Ip_Cfg.h"
#include "StandardTypes.h"
#if (FLEXIO_UART_IP_HAS_DMA_ENABLED == STD_ON)
#include "Dma_Ip.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_UART_IP_VS_0_PBCFG_VENDOR_ID_C                     43
#define FLEXIO_UART_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define FLEXIO_UART_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define FLEXIO_UART_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define FLEXIO_UART_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C              2
#define FLEXIO_UART_IP_VS_0_PBCFG_SW_MINOR_VERSION_C              0
#define FLEXIO_UART_IP_VS_0_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Flexio_Uart_Ip_Cfg.h */
#if (FLEXIO_UART_IP_VS_0_PBCFG_VENDOR_ID_C != FLEXIO_UART_IP_CFG_VENDOR_ID)
    #error "Flexio_Uart_Ip_VS_0_PBcfg.c and Flexio_Uart_Ip_Cfg.h have different vendor ids"
#endif
#if ((FLEXIO_UART_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_UART_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_UART_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_UART_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_UART_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXIO_UART_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Flexio_Uart_Ip_VS_0_PBcfg.c and Flexio_Uart_Ip_Cfg.h are different"
#endif
#if ((FLEXIO_UART_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C != FLEXIO_UART_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_UART_IP_VS_0_PBCFG_SW_MINOR_VERSION_C != FLEXIO_UART_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_UART_IP_VS_0_PBCFG_SW_PATCH_VERSION_C != FLEXIO_UART_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Uart_Ip_VS_0_PBcfg.c and Flexio_Uart_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((FLEXIO_UART_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_UART_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexio_Uart_Ip_VS_0_PBcfg.c and StandardTypes.h are different"
    #endif
    /* Checks against Dma_Ip.h */
    #if (FLEXIO_UART_IP_HAS_DMA_ENABLED == STD_ON)
        #if ((FLEXIO_UART_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
             (FLEXIO_UART_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Flexio_Uart_Ip_VS_0_PBcfg.c and Dma_Ip.h are different"
        #endif
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                   STATE STRUCTURE DECLARATIONS
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
#define UART_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"
extern Flexio_Uart_Ip_StateStructureType Flexio_Uart_Ip_apStateStructure[FLEXIO_UART_IP_NUMBER_OF_INSTANCES];
#define UART_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"

#define UART_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"




/**
* @brief          Hardware configuration for Uart Hardware - Configuration:
*
* @api
*/
const Flexio_Uart_Ip_UserConfigType Flexio_Uart_Ip_xHwConfigPB_1_VS_0 =
{

    /*!< Flexio Uart Channel has been configured */
    0U,
    /*!< Driver type: interrupts/DMA */
    FLEXIO_UART_IP_DRIVER_TYPE_INTERRUPTS,
    /*!< Baudrate divider */
    207U,
    /*!< The source of the Timer decrement and the source of the Shift clock */
    FLEXIO_TIMER_DECREMENT_FXIO_CLK_SHIFT_TMR,
    /*!< Baud rate in hertz */
    9615U,
    /*!< Number of bits per word */
    FLEXIO_UART_IP_8_BITS_PER_CHAR,
    /*!< Driver direction: Tx or Rx */
    FLEXIO_UART_IP_DIRECTION_RX,
    /*!< Flexio pin to use as Tx or Rx pin */
    6U,
    /*!< User callback function. Note that this function will be
        called from the interrupt service routine, so itsexecution time
        should be as small as possible. It can be NULL if it is not needed */
    NULL_PTR,
    /* Callback parameter pointer.*/
    NULL_PTR,
#if (FLEXIO_UART_IP_HAS_DMA_ENABLED == STD_ON)
    /* DMA channel number for DMA-based Rx or DMA-based Tx. */
    255,

#endif
    &Flexio_Uart_Ip_apStateStructure[0]

};

/**
* @brief          Hardware configuration for Uart Hardware - Configuration:
*
* @api
*/
const Flexio_Uart_Ip_UserConfigType Flexio_Uart_Ip_xHwConfigPB_2_VS_0 =
{

    /*!< Flexio Uart Channel has been configured */
    1U,
    /*!< Driver type: interrupts/DMA */
    FLEXIO_UART_IP_DRIVER_TYPE_INTERRUPTS,
    /*!< Baudrate divider */
    207U,
    /*!< The source of the Timer decrement and the source of the Shift clock */
    FLEXIO_TIMER_DECREMENT_FXIO_CLK_SHIFT_TMR,
    /*!< Baud rate in hertz */
    9615U,
    /*!< Number of bits per word */
    FLEXIO_UART_IP_8_BITS_PER_CHAR,
    /*!< Driver direction: Tx or Rx */
    FLEXIO_UART_IP_DIRECTION_TX,
    /*!< Flexio pin to use as Tx or Rx pin */
    7U,
    /*!< User callback function. Note that this function will be
        called from the interrupt service routine, so itsexecution time
        should be as small as possible. It can be NULL if it is not needed */
    NULL_PTR,
    /* Callback parameter pointer.*/
    NULL_PTR,
#if (FLEXIO_UART_IP_HAS_DMA_ENABLED == STD_ON)
    /* DMA channel number for DMA-based Rx or DMA-based Tx. */
    255,

#endif
    &Flexio_Uart_Ip_apStateStructure[1]

};

#define UART_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"
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

/** @} */

#endif
