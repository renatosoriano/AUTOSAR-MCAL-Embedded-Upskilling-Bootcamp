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

#ifndef UART_CFG_DEFINES_H
#define UART_CFG_DEFINES_H

/**
*   @file
*
*   @defgroup uart_driver UART Driver
*   @addtogroup  uart_driver UART Driver
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
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define UART_DEFINES_VENDOR_ID_CFG                     43
#define UART_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG      4
#define UART_DEFINES_AR_RELEASE_MINOR_VERSION_CFG      7
#define UART_DEFINES_AR_RELEASE_REVISION_VERSION_CFG   0
#define UART_DEFINES_SW_MAJOR_VERSION_CFG              2
#define UART_DEFINES_SW_MINOR_VERSION_CFG              0
#define UART_DEFINES_SW_PATCH_VERSION_CFG              0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((UART_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (UART_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of CDD_Uart_Defines.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                     DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* @brief Enables / Disables multicore support */
#define UART_MULTICORE_SUPPORT          (STD_OFF)

/* @brief Enables / Disables PreCompile support when there is a single configuration */
#define UART_PRECOMPILE_SUPPORT         (STD_ON)

/* @brief Enables / Disables DET development errors detection and reporting */
#define UART_DEV_ERROR_DETECT           (STD_ON)

/* @brief Enables / Disables Runtime errors detection and reporting */
#define UART_RUNTIME_ERROR_DETECT       (STD_ON)

/* @brief Number of Channels configured. */
#define UART_CH_MAX_CONFIG              (3U)

/* @brief UART Osif source counter. This parameter is used to select between different OsIf counter implementation */
#define UART_TIMEOUT_TYPE               (OSIF_COUNTER_DUMMY)

/* @brief Number of loops before returning Timeout status */
#define UART_TIMEOUT_VALUE_US           (10000000U)

/* @brief Switches the Uart_GetVersionInfo() API ON or OFF. Support for version info API. */
#define UART_VERSION_INFO_API           (STD_ON)

/* @brief Uart has feature DMA enable. */
#define UART_HAS_DMA_ENABLED            (STD_OFF)

/* @brief Uart has feature DMA enable. */
#define UART_HAS_TIMEOUT_INTERRUPT_ENABLED            (STD_OFF)

/* @brief Number of available hardware instances */
#define UART_NUMBER_OF_INSTANCES             (7U)

/* @brief UART Hardware instances mapping initialize value */
#define UART_HW_CHANNELS_MAPPING_FOR_INIT       {-1, -1, -1, -1, -1, -1, -1}

/* @brief Declare callback parameters if any */
#define UART_CALLBACK_DECLARED            (STD_OFF)

/**
* @brief        All CoreIDs are supported by Uart driver.
*/

#define UART_MAX_PARTITIONS             (1U)

/* Api to retrieve the core id */
#if (STD_ON == UART_MULTICORE_SUPPORT)
    #define Uart_GetCoreID() (OsIf_GetCoreID())
#else
    #define Uart_GetCoreID() ((uint32)0x0U)
#endif /* (STD_ON == UART_MULTICORE_SUPPORT) */

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
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

/*==================================================================================================
*                                  EXTERNAL CONSTANTS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* UART_CFG_DEFINES_H */
