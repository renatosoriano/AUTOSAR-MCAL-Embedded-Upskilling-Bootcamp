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
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef PWM_ENV_CFG_H
#define PWM_ENV_CFG_H

/**
*   @file       Pwm_EnvCfg.h
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
#include "Pwm_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_ENVCFG_VENDOR_ID                       43
#define PWM_ENVCFG_MODULE_ID                       121
#define PWM_ENVCFG_AR_RELEASE_MAJOR_VERSION        4
#define PWM_ENVCFG_AR_RELEASE_MINOR_VERSION        7
#define PWM_ENVCFG_AR_RELEASE_REVISION_VERSION     0
#define PWM_ENVCFG_SW_MAJOR_VERSION                2
#define PWM_ENVCFG_SW_MINOR_VERSION                0
#define PWM_ENVCFG_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#if ((PWM_ENVCFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_ENVCFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR version numbers of Pwm_EnvCfg.h and Std_Types.h are different."
#endif
#endif

/* Check if header file and Pwm_Cfg.h header file are of the same vendor */
#if (PWM_ENVCFG_VENDOR_ID != PWM_CFG_VENDOR_ID)
    #error "Pwm_EnvCfg.h and Pwm_Cfg.h have different vendor ids."
#endif

/* Check if header file and Pwm_Cfg.h header file are of the same AUTOSAR version */
#if ((PWM_ENVCFG_AR_RELEASE_MAJOR_VERSION    != PWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_ENVCFG_AR_RELEASE_MINOR_VERSION    != PWM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_ENVCFG_AR_RELEASE_REVISION_VERSION != PWM_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_EnvCfg.h and Pwm_Cfg.h are different."
#endif

/* Check if header file and Pwm_Cfg.h header file are of the same software version */
#if ((PWM_ENVCFG_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION) || \
     (PWM_ENVCFG_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION) || \
     (PWM_ENVCFG_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_EnvCfg.h and Pwm_Cfg.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* External environment the Pwm driver currently supports */
#define PWM_ENV_QM                              (STD_OFF)

#define PWM_ENV_FTE                             (STD_ON)

#define PWM_ENV_GTE                             (STD_OFF)

#define PWM_ENV_NTE                             (STD_OFF)

#if (PWM_ENV_FTE == STD_ON)
    /* FTE environment */
    #define PWM_PARAM_CHECK                     (PWM_DEV_ERROR_DETECT)
    #define PWM_REPORT_UNEXPECTED_ISR           (STD_ON)
    #define PWM_VALIDATE_GLOBAL_CONFIG_CALL     (PWM_DEV_ERROR_DETECT)
    #define PWM_VALIDATE_CHANNEL_CONFIG_CALL    (PWM_DEV_ERROR_DETECT)
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

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

#endif /* PWM_ENV_CFG_H */
