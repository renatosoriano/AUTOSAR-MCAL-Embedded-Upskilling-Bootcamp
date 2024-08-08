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

#ifndef FLEXIO_UART_IP_CFG_DEFINES_H
#define FLEXIO_UART_IP_CFG_DEFINES_H

/**
*   @file
*   @defgroup flexio_uart_ip Flexio UART IPL
*   @addtogroup  flexio_uart_ip Flexio UART IPL
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
* 4) user callback header files
==================================================================================================*/
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_UART_IP_CFG_DEFINES_VENDOR_ID                     43
#define FLEXIO_UART_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION      4
#define FLEXIO_UART_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION      7
#define FLEXIO_UART_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION   0
#define FLEXIO_UART_IP_CFG_DEFINES_SW_MAJOR_VERSION              2
#define FLEXIO_UART_IP_CFG_DEFINES_SW_MINOR_VERSION              0
#define FLEXIO_UART_IP_CFG_DEFINES_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((FLEXIO_UART_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_UART_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Flexio_Uart_Ip_CfgDefines.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/
/* Macros that indicate FLEXIO channels used by UART */
#ifndef FLEXIO_0_CH_0_USED
    #define FLEXIO_0_CH_0_USED
#else
    #error "CHANNEL_0 cannot be used by UART driver. Channel locked by another driver!"
#endif

#ifndef FLEXIO_0_CH_1_USED
    #define FLEXIO_0_CH_1_USED
#else
    #error "CHANNEL_1 cannot be used by UART driver. Channel locked by another driver!"
#endif


/* Macros that indicate FLEXIO pins used by UART */
#ifndef FLEXIO_0_PIN_6_USED
    #define FLEXIO_0_PIN_6_USED
#else
    #error "PIN_6 cannot be used by UART driver. Pin used by another driver!"
#endif

#ifndef FLEXIO_0_PIN_7_USED
    #define FLEXIO_0_PIN_7_USED
#else
    #error "PIN_7 cannot be used by UART driver. Pin used by another driver!"
#endif


/* Macros that indicate FLEXIO channels used by UART */
#ifdef FLEXIO_0_CH_0_USED
    #define UART_CHANNEL_0_USED
#else
    #error "CHANNEL_0 cannot be used by UART driver. Channel locked by other driver!"
#endif

#ifdef FLEXIO_0_CH_1_USED
    #define UART_CHANNEL_1_USED
#else
    #error "CHANNEL_1 cannot be used by UART driver. Channel locked by other driver!"
#endif


/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_UART_IP_CFG_DEFINES_H */
