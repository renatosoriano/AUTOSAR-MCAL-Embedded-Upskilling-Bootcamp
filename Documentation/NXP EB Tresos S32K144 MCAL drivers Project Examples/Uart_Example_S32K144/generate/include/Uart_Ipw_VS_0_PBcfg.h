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


#ifndef UART_IPW_VS_0_PBCFG_H
#define UART_IPW_VS_0_PBCFG_H


/**
*   @file
*   @internal
*   @addtogroup UART_IPW_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Uart_Ipw_Types.h"
/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define UART_IPW_VS_0_PBCFG_VENDOR_ID                     43
#define UART_IPW_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define UART_IPW_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define UART_IPW_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define UART_IPW_VS_0_PBCFG_SW_MAJOR_VERSION              2
#define UART_IPW_VS_0_PBCFG_SW_MINOR_VERSION              0
#define UART_IPW_VS_0_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/*Checks against Uart_Ipw_Types.h */
#if (UART_IPW_VS_0_PBCFG_VENDOR_ID!= UART_IPW_TYPES_VENDOR_ID)
    #error "Uart_Ipw__VS_0_PBcfg.h and Uart_Ipw_Types.h have different vendor ids"
#endif
#if ((UART_IPW_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION   != UART_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (UART_IPW_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION   != UART_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (UART_IPW_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION!= UART_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Uart_Ipw__VS_0_PBcfg.h and Uart_Ipw_Types.h are different"
#endif
#if ((UART_IPW_VS_0_PBCFG_SW_MAJOR_VERSION!= UART_IPW_TYPES_SW_MAJOR_VERSION) || \
     (UART_IPW_VS_0_PBCFG_SW_MINOR_VERSION!= UART_IPW_TYPES_SW_MINOR_VERSION) || \
     (UART_IPW_VS_0_PBCFG_SW_PATCH_VERSION!= UART_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Uart_Ipw__VS_0_PBcfg.h and Uart_Ipw_Types.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#define UART_IPW_CONFIG_VS_0_PB \
    extern const Uart_Ipw_HwConfigType Uart_Ipw_xHwConfigPB_0_VS_0; \
    extern const Uart_Ipw_HwConfigType Uart_Ipw_xHwConfigPB_1_VS_0; \
    extern const Uart_Ipw_HwConfigType Uart_Ipw_xHwConfigPB_2_VS_0; \


#ifndef UART_IPW_LPUART_HW_USING
    #define UART_IPW_LPUART_HW_USING
#endif

#ifndef UART_IPW_FLEXIO_HW_USING
    #define UART_IPW_FLEXIO_HW_USING
#endif

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* UART_IPW_VS_0_PBCFG_H */
