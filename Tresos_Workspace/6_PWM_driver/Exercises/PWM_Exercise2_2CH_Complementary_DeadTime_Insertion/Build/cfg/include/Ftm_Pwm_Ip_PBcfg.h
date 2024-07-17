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

#ifndef FTM_PWM_IP_PBCFG_H
#define FTM_PWM_IP_PBCFG_H

/**
*   @file       Ftm_Pwm_Ip_PBcfg.h
*
*   @addtogroup ftm_pwm_ip Ftm Pwm IPL
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

#include "Ftm_Pwm_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_PWM_IP_PB_CFG_VENDOR_ID                       43
#define FTM_PWM_IP_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define FTM_PWM_IP_PB_CFG_AR_RELEASE_MINOR_VERSION        7
#define FTM_PWM_IP_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define FTM_PWM_IP_PB_CFG_SW_MAJOR_VERSION                2
#define FTM_PWM_IP_PB_CFG_SW_MINOR_VERSION                0
#define FTM_PWM_IP_PB_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same vendor */
#if (FTM_PWM_IP_PB_CFG_VENDOR_ID != FTM_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_PB_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_PB_CFG_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_PB_CFG_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same software version */
#if ((FTM_PWM_IP_PB_CFG_SW_MAJOR_VERSION != FTM_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_PB_CFG_SW_MINOR_VERSION != FTM_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_PB_CFG_SW_PATCH_VERSION != FTM_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* Ftm instance index for configuration PwmFtmCh_0 */
#define FTM_PWM_IP_I0_CH0_CFG      (0U)

/*==================================================================================================
*                                      DEFINES AND MACROS
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
#ifndef FTM_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*================================================================================================*/
/* Ftm instance 0 User configuration structure */
extern const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip_UserCfg0;

/* Ftm instance 0 configuration structure */
extern const Ftm_Pwm_Ip_InstanceCfgType Ftm_Pwm_Ip_InstCfg0;

/* Ftm instance 0 synchronization configuration structure */
extern const Ftm_Pwm_Ip_SyncCfgType Ftm_Pwm_Ip_SyncCfg0;

/* Channel configurations for Ftm instance 0 */
/* Ftm channel 0 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_I0_Ch0;


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* FTM_PWM_IP_PRECOMPILE_SUPPORT */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_PWM_IP_PBCFG_H */

