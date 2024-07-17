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

#ifndef PWM_CFG_H
#define PWM_CFG_H

/**
*   @file       Pwm_Cfg.h
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

/* Include IPW Cfg header file */
#include "Pwm_Ipw_Cfg.h"

/* Include all variants header files. */

#include "Pwm_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_CFG_VENDOR_ID                         43
#define PWM_CFG_MODULE_ID                         121
#define PWM_CFG_AR_RELEASE_MAJOR_VERSION          4
#define PWM_CFG_AR_RELEASE_MINOR_VERSION          7
#define PWM_CFG_AR_RELEASE_REVISION_VERSION       0
#define PWM_CFG_SW_MAJOR_VERSION                  2
#define PWM_CFG_SW_MINOR_VERSION                  0
#define PWM_CFG_SW_PATCH_VERSION                  0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PWM_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm_Cfg.h and Std_Types.h are different."
    #endif
#endif

/* Check if header file and PWM configuration header file are of the same vendor */
#if (PWM_CFG_VENDOR_ID != PWM_IPW_CFG_VENDOR_ID)
    #error "Pwm_Cfg.h and Pwm_Ipw_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and Pwm configuration header file are of the same Autosar version */
#if ((PWM_CFG_AR_RELEASE_MAJOR_VERSION != PWM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_CFG_AR_RELEASE_MINOR_VERSION != PWM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_CFG_AR_RELEASE_REVISION_VERSION != PWM_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pwm_Cfg.h and Pwm_Ipw_Cfg.h are different"
#endif
/* Check if header file and Pwm configuration header file are of the same software version */
#if ((PWM_CFG_SW_MAJOR_VERSION != PWM_IPW_CFG_SW_MAJOR_VERSION) || \
     (PWM_CFG_SW_MINOR_VERSION != PWM_IPW_CFG_SW_MINOR_VERSION) || \
     (PWM_CFG_SW_PATCH_VERSION != PWM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pwm_Cfg.h and Pwm_Ipw_Cfg.h are different"
#endif


/* Check if header file and PWM configuration header file are of the same vendor */
#if (PWM_CFG_VENDOR_ID != PWM_PB_CFG_VENDOR_ID)
    #error "Pwm_Cfg.h and Pwm_PBcfg.h have different vendor IDs"
#endif
    /* Check if header file and Pwm configuration header file are of the same Autosar version */
#if ((PWM_CFG_AR_RELEASE_MAJOR_VERSION != PWM_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_CFG_AR_RELEASE_MINOR_VERSION != PWM_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_CFG_AR_RELEASE_REVISION_VERSION != PWM_PB_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pwm_Cfg.h and Pwm_PBcfg.h are different"
#endif
/* Check if header file and Pwm configuration header file are of the same software version */
#if ((PWM_CFG_SW_MAJOR_VERSION != PWM_PB_CFG_SW_MAJOR_VERSION) || \
     (PWM_CFG_SW_MINOR_VERSION != PWM_PB_CFG_SW_MINOR_VERSION) || \
     (PWM_CFG_SW_PATCH_VERSION != PWM_PB_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pwm_Cfg.h and Pwm_PBcfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
/**
* @brief        Specifies the InstanceId of this module instance.
*               If only one instance is present it shall have the Id 0.
* @note         Not used in the current implementation
*/
#define PWM_INDEX                               (0U)

/** @brief      Total number of Pwm logic channels configured. */
#define PWM_CONFIG_LOGIC_CHANNELS               (2U)

#define PWM_HW_CHANNEL_NO                       (36U)

/** @brief        Maximum number of partitions declared in Os. */
#define PWM_MAX_PARTITION_NO                    (1U)

/** @brief      Macro used to initialize the driver state structure */
#define PWM_DRIVER_STATE_INITIALIZATION         {\
                                                    {\
                                                        NULL_PTR,\
                                                        PWM_NODEFINE_POWER,\
                                                        PWM_NODEFINE_POWER,\
                                                        {\
                                                            NULL_PTR,\
                                                            NULL_PTR\
                                                        },\
                                                        {\
                                                            (boolean)FALSE,\
                                                            (boolean)FALSE\
                                                        }\
                                                    }\
                                                }

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief        Pre-compile configuration constants
*
*/
#define PWM_PRECOMPILE_SUPPORT                  (STD_OFF)

/** @brief        Switch to indicate that Pwm_SetClockMode API is supported */
#define PWM_VERSION_INFO_API                    (STD_OFF)

/**
* @brief        Switch to indicate that Pwm_ForceOutputToZero API is supported
* @note         In current implementation, this option is not supported
*/
#define PWM_FORCE_OUTPUT_TO_ZERO_API            (STD_OFF)

/** @brief        Switch to indicate that Pwm_SetDutyPhaseShift API is supported */
#define PWM_SET_DUTY_PHASE_SHIFT_API            (STD_OFF)

/** @brief        Switch to indicate that Pwm_SyncUpdate API is supported */
#define PWM_SYNC_UPDATE_API                     (STD_OFF)

/** @brief        Switch to indicate that Pwm_SetDutyCycle_NoUpdate API is supported */
#define PWM_SET_DUTY_CYCLE_NO_UPDATE_API        (STD_OFF)

/** @brief        Switch to indicate that Pwm_SetPeriodAndDuty_NoUpdate API is supported */
#define PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API   (STD_OFF)

/** @brief        Switch to indicate that Pwm_EnableTrigger API is supported */
#define PWM_ENABLE_TRIGGER_API                  (STD_OFF)

/** @brief        Switch to indicate that Pwm_DisableTrigger API is supported */
#define PWM_DISABLE_TRIGGER_API                 (STD_OFF)

/** @brief        Switch to indicate that Pwm_SwResetCounter API is supported */
#define PWM_RESET_COUNTER_API                   (STD_OFF)

/**
* @brief        Switch to indicate that Pwm_SetChannelForceOut API is supported
* @note         In current implementation, this function is not supported for FTM
*/
#define PWM_SET_CHANNEL_FORCE_OUT_API           (STD_OFF)

/* @brief Add/remove the service Pwm_SetChannelDeadTime() from the code.*/
#define PWM_SET_CHANNEL_DEAD_TIME_API           (STD_OFF)

/** @brief        Switch to enable the update of the duty cycle parameter at the end of the current period. */
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD         (STD_OFF)

/** @brief        Switch to enable the update of the period parameter at the end of the current period */
#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD       (STD_ON)

/** @brief        Switch to enable the mask output feature (Pwm_MaskOutput and Pwm_UnMaskOutput API) */
#define PWM_ENABLE_MASKING_OPERATIONS           (STD_OFF)

/** @brief        Switch to enable update synchronization feature */
#define PWM_UPDATE_DUTY_SYNCHRONOUS             (STD_OFF)


/**
* @brief        Support for User mode.
*               If this parameter has been configured to 'TRUE' the PWM driver code can be executed from both supervisor and user mode.
*/
#define PWM_ENABLE_USER_MODE_SUPPORT            (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef PWM_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == PWM_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running PWM in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
        #endif
    #endif
#endif

/**
* @brief        Switch to indicate that Pwm_SelectCommonTimebase API is supported
* @note         In current implementation, this option is not supported
*/
#define PWM_SELECT_COMMON_TIMEBASE_API          (STD_OFF)

/** @brief        Enable/Disable multicore feature for PWM driver */
#define PWM_MULTICORE_ENABLED                   (STD_OFF)



/**
* @brief        Symbolic Names for configured channels - legacy
*
*/
#define PwmChannel_0                            ((Pwm_ChannelType)0U)
#define PwmChannel_1                            ((Pwm_ChannelType)1U)

/**
* @brief        Symbolic name for configured channels - TPS_ECUC_02108 compliant.
*
*/
#define PwmConf_PwmChannel_PwmChannel_0          ((Pwm_ChannelType)0U)
#define PwmConf_PwmChannel_PwmChannel_1          ((Pwm_ChannelType)1U)

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

/** @brief          Post Build configuration constants */
#define PWM_CONFIG_EXTERNAL \
                PWM_CONFIG_PB

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

#endif /* PWM_CFG_H */

