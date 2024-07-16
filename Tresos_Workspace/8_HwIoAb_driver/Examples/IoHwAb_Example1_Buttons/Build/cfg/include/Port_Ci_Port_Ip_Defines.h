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

#ifndef PORT_CI_PORT_IP_DEFINES_H
#define PORT_CI_PORT_IP_DEFINES_H

/**
*   @file    Port_Ci_Port_Ip_Defines.h
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
#include "S32K144_GPIO.h"
#include "S32K144_PORT.h"
#include "S32K144_SIM.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_CI_PORT_IP_VENDOR_ID_DEFINES_H                       43
#define PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_DEFINES_H        4
#define PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_DEFINES_H        7
#define PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_DEFINES_H     0
#define PORT_CI_PORT_IP_SW_MAJOR_VERSION_DEFINES_H                2
#define PORT_CI_PORT_IP_SW_MINOR_VERSION_DEFINES_H                0
#define PORT_CI_PORT_IP_SW_PATCH_VERSION_DEFINES_H                0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*! @brief PORT_CI module has DSE bit */
#define FEATURE_PORT_CI_PORT_IP_HAS_DRIVE_STRENGTH

/*! @brief PORT_CI module has LK bit */
#define FEATURE_PORT_CI_PORT_IP_HAS_LOCK_REGISTER

/*! @brief PORT_CI module has PIDR register */
#define FEATURE_PORT_CI_PORT_IP_HAS_PIDR_REGISTER

/*! @brief PORT_CI module has interleave */
#define FEATURE_PORT_CI_PORT_IP_HAS_ADC_INTERLEAVE


#define PORT_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef PORT_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Port in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
        #endif /* (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifdef PORT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/* Pre-processor switch to enable/disable development error detection for Port_Ci Ip API */
#define PORT_CI_PORT_IP_DEV_ERROR_DETECT         (STD_OFF)

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

#endif /* PORT_CI_PORT_IP_DEFINES_H */
