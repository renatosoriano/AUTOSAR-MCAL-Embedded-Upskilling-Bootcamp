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

/**
*   @file       Pwm_PBcfg.c
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
#include "Pwm.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_PB_CFG_VENDOR_ID_C                       43
#define PWM_PB_CFG_MODULE_ID_C                       121
#define PWM_PB_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define PWM_PB_CFG_AR_RELEASE_MINOR_VERSION_C        7
#define PWM_PB_CFG_AR_RELEASE_REVISION_VERSION_C     0
#define PWM_PB_CFG_SW_MAJOR_VERSION_C                2
#define PWM_PB_CFG_SW_MINOR_VERSION_C                0
#define PWM_PB_CFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM_PB_CFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_PB_CFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm_PBcfg.c and Std_Types.h are different."
    #endif
#endif

#if (PWM_PB_CFG_VENDOR_ID_C != PWM_VENDOR_ID)
    #error "Pwm_PBcfg.c and Pwm.h have different vendor ids"
#endif

#if ((PWM_PB_CFG_AR_RELEASE_MAJOR_VERSION_C    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_PB_CFG_AR_RELEASE_MINOR_VERSION_C    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_PB_CFG_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_PBcfg.c and Pwm.h are different"
#endif

#if ((PWM_PB_CFG_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION) || \
     (PWM_PB_CFG_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION) || \
     (PWM_PB_CFG_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_PBcfg.c and Pwm.h are different"
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

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*============================== Channels configuration ===================================*/
/**
* @brief        Array of configured PWM channels
*
*/
const Pwm_ChannelConfigType Pwm_Channels_PB[PWM_PB_CFG_CHANNELS_COUNT] =
{
    /* PwmChannel7 */
    {
        /** @brief  Channel Id */
        (Pwm_ChannelType)0U,
        /** @brief  Channel class */
        PWM_VARIABLE_PERIOD,
        /** @brief  Ip channel configuration */
        {
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_FTM,
            /** @brief  Hardware Channel Configuration Pointer */
            (const void *)(&Ftm_Pwm_Ip_I1_Ch7),
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            NULL_PTR,
        #endif
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)FTM_PWM_IP_I1_CH7_CFG,
            /** @brief The duty cycle of this channel */
            0U
        },
        /** @brief  The state of the channel output in idle mode */
        PWM_LOW
    }
};
/*============================== Instances configuration ===================================*/


#if (PWM_HW_INSTANCE_USED == STD_ON)
/** @brief        Array of configured Pwm instances */
const Pwm_IpwInstanceConfigType Pwm_Instances_PB[PWM_PB_CFG_INSTANCES_COUNT] =
{
    {
        /** @brief  The Id instance configured */
        1U,
        /** @brief  The type of ip instance configured */
        PWM_INSTANCE_FTM,
        /** @brief  Pointer to the ip instance configuration structure */
        (const void *)(&Ftm_Pwm_Ip_UserCfg1)
    }
};
#endif

/*============================== High level configuration ===================================*/
const Pwm_ConfigType Pwm_Config=
{
    /** @brief  Number of configured PWM channels */
    (Pwm_ChannelType)PWM_PB_CFG_CHANNELS_COUNT,
    /** @brief  Pointer to array of PWM channels */
    &Pwm_Channels_PB,
#if (PWM_HW_INSTANCE_USED == STD_ON)
    /** @brief  Number of Pwm configured instances */
    (Pwm_InstanceType)PWM_PB_CFG_INSTANCES_COUNT,
    /** @brief  Pointer to the list of Pwm configured channels */
    &Pwm_Instances_PB,
#endif
};
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

