/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : PORT_CI
*   Dependencies         : none
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

#ifndef PORT_CI_PORT_IP_CFG_H
#define PORT_CI_PORT_IP_CFG_H

/**
*   @file    Port_Ci_Port_Ip_Cfg.h
*
*   @addtogroup Port_CFG
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
#include "Port_Ci_Port_Ip_Types.h"

#include "Port_Ci_Port_Ip_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_CI_PORT_IP_VENDOR_ID_CFG_H                       43
#define PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H        4
#define PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H        7
#define PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H     0
#define PORT_CI_PORT_IP_SW_MAJOR_VERSION_CFG_H                2
#define PORT_CI_PORT_IP_SW_MINOR_VERSION_CFG_H                0
#define PORT_CI_PORT_IP_SW_PATCH_VERSION_CFG_H                0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_Types.h are of the same vendor */
#if (PORT_CI_PORT_IP_VENDOR_ID_CFG_H != PORT_CI_PORT_IP_VENDOR_ID_TYPES_H)
    #error "Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_Types.h have different vendor ids"
#endif
/* Check if the files Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_Types.h are of the same Autosar version */
#if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H    != PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_TYPES_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H    != PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_TYPES_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_TYPES_H)  \
    )
    #error "AutoSar Version Numbers of Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_Types.h are different"
#endif
/* Check if the files Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_Types.h are of the same software version */
#if ((PORT_CI_PORT_IP_SW_MAJOR_VERSION_CFG_H != PORT_CI_PORT_IP_SW_MAJOR_VERSION_TYPES_H) || \
     (PORT_CI_PORT_IP_SW_MINOR_VERSION_CFG_H != PORT_CI_PORT_IP_SW_MINOR_VERSION_TYPES_H) || \
     (PORT_CI_PORT_IP_SW_PATCH_VERSION_CFG_H != PORT_CI_PORT_IP_SW_PATCH_VERSION_TYPES_H)    \
    )
    #error "Software Version Numbers of Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_Types.h are different"
#endif


/* Check if the files Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_PBcfg.h are of the same vendor */
#if (PORT_CI_PORT_IP_VENDOR_ID_CFG_H != PORT_CI_PORT_IP_VENDOR_ID_PBCFG_H)
    #error "Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_PBcfg.h have different vendor ids"
#endif
/* Check if the files Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_PBcfg.h are of the same Autosar version */
#if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H    != PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H    != PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H)  \
    )
    #error "AutoSar Version Numbers of Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_PBcfg.h are different"
#endif
/* Check if the files Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_PBcfg.h are of the same software version */
#if ((PORT_CI_PORT_IP_SW_MAJOR_VERSION_CFG_H != PORT_CI_PORT_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (PORT_CI_PORT_IP_SW_MINOR_VERSION_CFG_H != PORT_CI_PORT_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (PORT_CI_PORT_IP_SW_PATCH_VERSION_CFG_H != PORT_CI_PORT_IP_SW_PATCH_VERSION_PBCFG_H)    \
    )
    #error "Software Version Numbers of Port_Ci_Port_Ip_Cfg.h and Port_Ci_Port_Ip_PBcfg.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*! @brief Definitions for BOARD_InitPins Functional Group */

/*! @brief User number of configured pins */
#define NUM_OF_CONFIGURED_PINS 5

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

PORT_CI_PORT_CONFIG_PB


#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
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


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PORT_CI_PORT_IP_CFG_H */
