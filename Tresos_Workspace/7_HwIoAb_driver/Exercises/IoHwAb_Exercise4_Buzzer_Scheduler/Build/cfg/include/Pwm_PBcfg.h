/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Flexio
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

#ifndef PWM_PB_CFG_H
#define PWM_PB_CFG_H

/**
*   @file       Pwm_PBcfg.h
*
*   @addtogroup pwm_driver Pwm Driver
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
#include "Std_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_PB_CFG_VENDOR_ID                    43
#define PWM_PB_CFG_MODULE_ID                    121
#define PWM_PB_CFG_AR_RELEASE_MAJOR_VERSION     4
#define PWM_PB_CFG_AR_RELEASE_MINOR_VERSION     7
#define PWM_PB_CFG_AR_RELEASE_REVISION_VERSION  0
#define PWM_PB_CFG_SW_MAJOR_VERSION             2
#define PWM_PB_CFG_SW_MINOR_VERSION             0
#define PWM_PB_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM_PB_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_PB_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm_PBcfg.h and Std_Types.h are different."
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief        Total number of configured PWM channels
*/
#define PWM_PB_CFG_CHANNELS_COUNT           ((uint8)1U)

/**
* @brief        Total number of configured PWM instances
*/
#define PWM_PB_CFG_INSTANCES_COUNT          ((uint8)1U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_CONFIG_PB \
        extern const Pwm_ConfigType Pwm_Config;

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PWM_PB_CFG_H */

