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

/**
*   @file    Port_Ci_Port_Ip__PBcfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Port_Ci_Port_Ip.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_CI_PORT_IP_VENDOR_ID_PBCFG_C                       43
#define PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C        4
#define PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C        7
#define PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C     0
#define PORT_CI_PORT_IP_SW_MAJOR_VERSION_PBCFG_C                2
#define PORT_CI_PORT_IP_SW_MINOR_VERSION_PBCFG_C                0
#define PORT_CI_PORT_IP_SW_PATCH_VERSION_PBCFG_C                0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Port_Ci_Port_Ip_PBcfg.c and Port_Ci_Port_Ip.h are of the same vendor */
#if (PORT_CI_PORT_IP_VENDOR_ID_PBCFG_C != PORT_CI_PORT_IP_VENDOR_ID_H)
    #error "Port_Ci_Port_Ip_PBcfg.c and Port_Ci_Port_Ip.h have different vendor ids"
#endif
/* Check if the files Port_Ci_Port_Ip_PBcfg.c and Port_Ci_Port_Ip.h are of the same Autosar version */
#if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C    != PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C != PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_H)  \
    )
    #error "AutoSar Version Numbers of Port_Ci_Port_Ip_PBcfg.c and Port_Ci_Port_Ip.h are different"
#endif
/* Check if the files Port_Ci_Port_Ip_PBcfg.c and Port_Ci_Port_Ip.h are of the same software version */
#if ((PORT_CI_PORT_IP_SW_MAJOR_VERSION_PBCFG_C != PORT_CI_PORT_IP_SW_MAJOR_VERSION_H) || \
     (PORT_CI_PORT_IP_SW_MINOR_VERSION_PBCFG_C != PORT_CI_PORT_IP_SW_MINOR_VERSION_H) || \
     (PORT_CI_PORT_IP_SW_PATCH_VERSION_PBCFG_C != PORT_CI_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Port_Ci_Port_Ip_PBcfg.c and Port_Ci_Port_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

const Port_Ci_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr[NUM_OF_CONFIGURED_PINS] =
{
    {
        .portBase                    = IP_PORTC,
        .gpioBase                    = IP_PTC,
        .pinPortIdx                  = 8,
        .mux                         = PORT_MUX_AS_GPIO,
        .direction                   = PORT_CI_PORT_PIN_OUT,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENGTH_LOW,
        .passiveFilter               = (boolean)FALSE,
        .lockRegister                = PORT_LOCK_REGISTER_DISABLED,
        .digitalFilter               = (boolean)FALSE,
        .initValue                   = 0
    },
    {
        .portBase                    = IP_PORTC,
        .gpioBase                    = IP_PTC,
        .pinPortIdx                  = 9,
        .mux                         = PORT_MUX_AS_GPIO,
        .direction                   = PORT_CI_PORT_PIN_OUT,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENGTH_LOW,
        .passiveFilter               = (boolean)FALSE,
        .lockRegister                = PORT_LOCK_REGISTER_DISABLED,
        .digitalFilter               = (boolean)FALSE,
        .initValue                   = 0
    },
    {
        .portBase                    = IP_PORTC,
        .gpioBase                    = IP_PTC,
        .pinPortIdx                  = 10,
        .mux                         = PORT_MUX_AS_GPIO,
        .direction                   = PORT_CI_PORT_PIN_OUT,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENGTH_LOW,
        .passiveFilter               = (boolean)FALSE,
        .lockRegister                = PORT_LOCK_REGISTER_DISABLED,
        .digitalFilter               = (boolean)FALSE,
        .initValue                   = 0
    },
    {
        .portBase                    = IP_PORTC,
        .gpioBase                    = IP_PTC,
        .pinPortIdx                  = 11,
        .mux                         = PORT_MUX_AS_GPIO,
        .direction                   = PORT_CI_PORT_PIN_OUT,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength               = PORT_DRIVE_STRENGTH_LOW,
        .passiveFilter               = (boolean)FALSE,
        .lockRegister                = PORT_LOCK_REGISTER_DISABLED,
        .digitalFilter               = (boolean)FALSE,
        .initValue                   = 0
    }
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
