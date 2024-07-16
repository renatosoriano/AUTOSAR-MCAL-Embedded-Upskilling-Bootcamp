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

#ifndef PWM_H
#define PWM_H

/**
*   @file       Pwm.h
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
#include "Pwm_Ipw_Types.h"
#include "Pwm_EnvCfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_VENDOR_ID                       43
#define PWM_MODULE_ID                       121
#define PWM_AR_RELEASE_MAJOR_VERSION        4
#define PWM_AR_RELEASE_MINOR_VERSION        7
#define PWM_AR_RELEASE_REVISION_VERSION     0
#define PWM_SW_MAJOR_VERSION                2
#define PWM_SW_MINOR_VERSION                0
#define PWM_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm.h and Std_Types.h are different."
    #endif
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same vendor */
#if (PWM_VENDOR_ID != PWM_ENVCFG_VENDOR_ID)
    #error "Vendor IDs of Pwm.h and Pwm_EnvCfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same AUTOSAR version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION    != PWM_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION    != PWM_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION != PWM_ENVCFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm.h and Pwm_EnvCfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same software version */
#if ((PWM_SW_MAJOR_VERSION != PWM_ENVCFG_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION != PWM_ENVCFG_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION != PWM_ENVCFG_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm.h and Pwm_EnvCfg.h are different."
#endif

/* Check if header file and Pwm_Ipw_Types header file are of the same vendor */
#if (PWM_VENDOR_ID != PWM_IPW_TYPES_VENDOR_ID)
    #error "Vendor IDs of Pwm.h and Pwm_Ipw_Types.h are different."
#endif

/* Check if header file and Pwm_Ipw_Types header file are of the same AUTOSAR version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm.h and Pwm_Ipw_Types.h are different."
#endif

/* Check if header file and Pwm_Ipw_Types header file are of the same software version */
#if ((PWM_SW_MAJOR_VERSION != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION != PWM_IPW_TYPES_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION != PWM_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm.h and Pwm_Ipw_Types.h are different."
#endif

/* Check if header file and Pwm_Cfg.h header file are of the same vendor */
#if (PWM_VENDOR_ID != PWM_CFG_VENDOR_ID)
    #error "Vendor IDs of Pwm.h and Pwm_Cfg.h are different."
#endif

/* Check if header file and Pwm_Cfg.h header file are of the same AUTOSAR version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION    != PWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION    != PWM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION != PWM_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm.h and Pwm_Cfg.h are different."
#endif

/* Check if header file and Pwm_Cfg.h header file are of the same software version */
#if ((PWM_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm.h and Pwm_Cfg.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief            100% duty cycle
* @details          Errors and exceptions that will be detected by the PWM driver generated when
*                   Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty are called with a value for duty cycle
*                   out of valid range [0x0000, 0x8000]
*/
#define PWM_DUTY_CYCLE_100                          ((uint16)0x8000U)

/**
* @brief            API Pwm_Init service called with wrong parameter
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define
*/
#define PWM_E_INIT_FAILED                           (0x10U)

/**
* @brief            API service used without module initialization
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_UNINIT                                (0x11U)

/**
* @brief            API service used with an invalid channel Identifier
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_PARAM_CHANNEL                         (0x12U)

/**
* @brief            Usage of unauthorized PWM service on PWM channel configured a fixed period
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_PERIOD_UNCHANGEABLE                   (0x13U)

/**
* @brief            API Pwm_Init service called while the PWM driver has already been initialized
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_ALREADY_INITIALIZED                   (0x14U)

/**
* @brief            Generated when a NULL_PTR pointer is passed to Pwm_GetVersionInfo function
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_PARAM_POINTER                         (0x15U)

/**
* @brief            Generated when Pwm_SetPowerState is called while the PWM module is still in use.
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_NOT_DISENGAGED                        (0x16U)

/**
* @brief            The requested power state is not supported by the PWM module.
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_POWER_STATE_NOT_SUPPORTED             (0x17U)

/**
* @brief            Generated The requested power state is not reachable from the current one.
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_TRANSITION_NOT_POSSIBLE               (0x18U)

/**
* @brief            Generated when Pwm_SetPowerState has been called without having called the API
*                   Pwm_PreparePowerState before.
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_PERIPHERAL_NOT_PREPARED               (0x19U)

/**
* @brief            Pwm_SetPeriodAndDuty called with invalid period range
* @details          Generated when Pwm_SetPeriodAndDuty is called with a value
*                   for period out of valid range [0x0000, PWM_MAX_PERIOD]
*/
#define PWM_E_PERIODVALUE                           (0x1AU)

/**
* @brief            Invalid polarity selected for edge notification
* @details          Will be generated when an invalid polarity, edge notification is requested for one PWM channel.
*                   Due to the limitations that are present in the eMIOS implementation not all
*                   the polarity notifications combinations can be supported.
*/
#define PWM_E_PARAM_NOTIFICATION                    (0x30U)

/**
* @brief            NULL_PTR function is configured as notification callback
* @details          Will be generated when a NULL_PTR function is configured as notification callback for
*                   one PWM channel and Pwm_EnableNotification is called for that channel
*/
#define PWM_E_PARAM_NOTIFICATION_NULL               (0x31U)

/**
* @brief            Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty called with invalid duty cycle range
* @details          Generated when Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty are called with a value
*                   for duty cycle out of valid range [0x0000, 0x8000]
*/
#define PWM_E_DUTYCYCLE_RANGE                       (0x32U)

/**
* @brief            Generated when Pwm_SetCounterBus is called with an invalid Bus
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_COUNTERBUS                            (0x33U)

/**
* @brief            Generated when the configured offset for the OPWMB channel is more than the period
*                   of the associated MCB channel
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_CHANNEL_OFFSET_VALUE                  (0x34U)

/**
* @brief            Generated when the requested offset value plus the current requested duty cycle leads to
*                   programming event B over the Period value leading to unexpected behavior of the PWM signal
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_OPWMB_CHANNEL_OFFSET_DUTYCYCLE_RANGE  (0x35U)

/**
* @brief            Generated when the module id is more than the number of module that supported by
*                   this platform
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_PARAM_INSTANCE                        (0x36U)

/**
* @brief            Generated when the configured trigger value for the OPWMT channel is equal or
*                   greater than the period of the channel
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_OPWMT_CHANNEL_TRIGGER_RANGE           (0x37U)

/**
* @brief            Generated when the output state value for the SetChannelOutput
*                   of the channel
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_SET_CHANNEL_OUTPUT                    (0x38U)

/**
* @brief            Generated when an ISR has been triggered
*                    1. when the driver is not initialized
*                    2. for a HW channel that is not used by any logic channel
*                    3. for a logic channel that has no notification configured
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_UNEXPECTED_ISR                        (0x39U)

/**
* @brief            Generated when requested phase shift value greater than 0x4000 (50%)
* @details          Pwm_SetPhaseShift only works with Combine channel (COMBINED_SYNCED or COMBINED_COMPLEMENTARY)
*                   Which do not support matching at next cycle.
*                   The duty cycle is always fixed value at 50%, so Phase Shift cannot greater than 50%
*/
#define PWM_E_PARAM_PHASESHIFT_RANGE                (0x3AU)

/**
* @brief            Generated when given channel does not support phase shift feature.
* @details          For FTM, only combine mode (COMBINED_SYNCED and COMBINED_COMPLEMENTARY) is supported.
*                   For eMIOS, only OPWMB, OPWM and OPWMT mode is supported.
*/
#define PWM_E_CHANNEL_PHASE_SHIFT_NOT_SUPPORTED     (0x3BU)

/**
* @brief            Generated when given channel does not support duty synchronous feature.
*                   (PHASE_SHIFTED_SYNCED and PHASE_SHIFTED_COMPLEMENTARY)
* @details          For FTM, please note that Modified Combine mode does not support synchronous update Cn
*                   Therefore Pwm_SetDutyCycle_NoUpdate and Pwm_SetPeriodAndDuty_NoUpdate should not
*                   be called in this case.
*                   For eMIOS, please note that channels using DAOC mode or channels in idle state
*                   does not support.
*/
#define PWM_E_DUTY_SYNCHRONOUS_NOT_SUPPORTED        (0x3CU)

/**
* @brief            Generated when bit mask is not compatible with  hardware register
* @details
*/
#define PWM_E_TRIGGER_MASK                          (0x3DU)

/**
* @brief            Generated when given channel does not support force output to zero feature.
* @details          Only channels in FlexPWM and FTM module are supported.
*/
#define PWM_E_FORCE_OUTPUT_NOT_SUPPORTED            (0x3EU)

/**
* @brief            Generated when given channel does not support set force out feature.
* @details          Only channels in FlexPWM is supported.
*/
#define PWM_E_FORCE_OUT                             (0x3FU)

/**
* @brief            Generated when the requested resource is configured to be unavailable on the current core.
* @details          Only multi-core configuration is available.
*/
#define PWM_E_PARAM_CONFIG                          (0x40U)

/**
* @brief            Generated when the configured dead time value is not valid
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_DEADTIME_RANGE                        (0x41U)

/**
* @brief            Generated when the configured dead time value is not valid
* @details          Errors and exceptions that will be detected by the PWM driver
*/
#define PWM_E_SETOUTPUTTOIDLE_NOT_SUPPORTED         (0x42U)

/**
* @brief            API service ID of Pwm_Init function
* @details          Parameters used when raising an error/exception
*/
#define PWM_INIT_ID                                 (0x00U)

/**
* @brief            API service ID of Pwm_DeInit function
* @details          Parameters used when raising an error/exception
*/
#define PWM_DEINIT_ID                               (0x01U)

/**
* @brief            API service ID of Pwm_SetDutyCycle function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETDUTYCYCLE_ID                         (0x02U)

/**
* @brief            API service ID of Pwm_SetPeriodAndDuty function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETPERIODANDDUTY_ID                     (0x03U)

/**
* @brief            API service ID of Pwm_SetOutputToIdle function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETOUTPUTTOIDLE_ID                      (0x04U)

/**
* @brief            API service ID of Pwm_GetOutputState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_GETOUTPUTSTATE_ID                       (0x05U)

/**
* @brief            API service ID of Pwm_DisableNotification function
* @details          Parameters used when raising an error/exception
*/
#define PWM_DISABLENOTIFICATION_ID                  (0x06U)

/**
* @brief            API service ID of Pwm_EnableNotification function
* @details          Parameters used when raising an error/exception
*/
#define PWM_ENABLENOTIFICATION_ID                   (0x07U)

/**
* @brief            API service ID of Pwm_GetVersionInfo function
* @details          Parameters used when raising an error/exception
*/
#define PWM_GETVERSIONINFO_ID                       (0x08U)

/**
* @brief            API service ID of Pwm_SetPowerState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETPOWERSTATE_ID                        (0x09U)

/**
* @brief            API service ID of Pwm_GetCurrentPowerState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_GETCURRENTPOWERSTATE_ID                 (0x0AU)

/**
* @brief            API service ID of Pwm_GetTargetPowerState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_GETTARGETPOWERSTATE_ID                  (0x0BU)

/**
* @brief            API service ID of Pwm_PreparePowerState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_PREPAREPOWERSTATE_ID                    (0x0CU)

/**
* @brief            API service ID of Pwm_Main_PowerTransitionManager function
* @details          Parameters used when raising an error/exception
*/
#define PWM_MAIN_POWERTRANSITIONMANAGER_ID          (0x0DU)

/**
* @brief            API service ID of Pwm_GetChannelState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_GETCHANNELSTATE_ID                      (0x20U)

/**
* @brief            API service ID of Pwm_ForceOutputToZero function
* @details          Parameters used when raising an error/exception
*/
#define PWM_FORCEOUTPUTTOZERO_ID                    (0x21U)

/**
* @brief            API service ID of Pwm_SetCounterBus function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETCOUNTERBUS_ID                        (0x22U)

/**
* @brief            API service ID of Pwm_SetChannelOutput function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETCHANNELOUTPUT_ID                     (0x23U)

/**
* @brief            API service ID of Pwm_SetTriggerDelay function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETTRIGGERDELAY_ID                      (0x24U)

/**
* @brief            API service ID of Pwm_SetClockMode function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETCLOCKMODE_ID                         (0x27U)

/**
* @brief            API service ID of Pwm_SyncUpdate function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SYNCUPDATE_ID                           (0x28U)

/**
* @brief            API service ID of Pwm_SetPeriodAndDuty_NoUpdate function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETPERIODANDDUTY_NO_UPDATE_ID           (0x29U)

/**
* @brief            API service ID of Pwm_SetDutyCycle_NoUpdate function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETDUTYCYCLE_NO_UPDATE_ID               (0x2AU)

/**
* @brief            API service ID of Pwm_SetChannelDeadTime function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETCHANNELDEADTIME_ID                   (0x2BU)

/**
* @brief            API service ID of Pwm_EnableTrigger function
* @details          Parameters used when raising an error/exception
*/
#define PWM_ENABLETRIGGER_ID                        (0x2EU)

/**
* @brief            API service ID of Pwm_DisableTrigger function
* @details          Parameters used when raising an error/exception
*/
#define PWM_DISABLETRIGGER_ID                       (0x2FU)

/**
* @brief            API service ID of Pwm_ResetCounterEnable function
* @details          Parameters used when raising an error/exception
*/
#define PWM_RESETCOUNTERENABLE_ID                   (0x30U)

/**
* @brief            API service ID of Pwm_ResetCounterDisable function
* @details          Parameters used when raising an error/exception
*/
#define PWM_RESETCOUNTERDISABLE_ID                  (0x31U)

/**
* @brief            API service ID of Pwm_MaskOutputs function
* @details          Parameters used when raising an error/exception
*/
#define PWM_MASKOUTPUT_ID                           (0x32U)

/**
* @brief            API service ID of Pwm_UnMaskOutputs function
* @details          Parameters used when raising an error/exception
*/
#define PWM_UNMASKOUTPUT_ID                         (0x33U)

/**
* @brief            API service ID of Pwm_DisableReloadNotification function
* @details          Parameters used when raising an error/exception
*/
#define PWM_DISABLERELOADNOTIF_ID                   (0x34U)

/**
* @brief            API service ID of Pwm_EnableReloadNotification function
* @details          Parameters used when raising an error/exception
*/
#define PWM_ENABLERELOADNOTIF_ID                    (0x35U)

/**
* @brief            API service ID of Pwm_SetChannelForceOut function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETCHANNELFORCEOUT_ID                   (0x36U)

/**
* @brief            API service ID of Pwm_SetDutyPhaseShift function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETDUTYPHASESHIFT_ID                    (0x37U)

/**
* @brief            API service ID of Pwm_FastUpdateSetUCRegA function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETUCREGA_ID                            (0x38U)

/**
* @brief            API service ID of Pwm_FastUpdateSetUCRegB function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETUCREGB_ID                            (0x39U)

/**
* @brief            API service ID of Pwm_FastUpdateDisableOU function
* @details          Parameters used when raising an error/exception
*/
#define PWM_DISABLEOU_ID                            (0x40U)

/**
* @brief            API service ID of Pwm_FastUpdateEnableOU function
* @details          Parameters used when raising an error/exception
*/
#define PWM_ENABLEOU_ID                             (0x41U)

/**
* @brief            API service ID of Pwm_DisableFaultNotification function
* @details          Parameters used when raising an error/exception
*/
#define PWM_DISABLEFAULTNOTIF_ID                   (0x42U)

/**
* @brief            API service ID of Pwm_EnableFaultNotification function
* @details          Parameters used when raising an error/exception
*/
#define PWM_ENABLEFAULTNOTIF_ID                    (0x43U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
* @brief        Output signal level
* @details      This enumeration specifies the return type of Pwm_GetOutputState
*
* @implements   Pwm_OutputStateType_enumeration
*/
typedef enum
{
    /** @brief  PWM level is logic high */
    PWM_HIGH     = 0x00U,
    /** @brief  PWM level is logic low */
    PWM_LOW      = 0x01U
} Pwm_OutputStateType;

/**
* @brief        Edge notification type
* @details      This enumeration defines the type of edge transition that can generate a notification
*
* @implements   Pwm_EdgeNotificationType_enumeration
*/
typedef enum
{
    /** @brief  A notification will be generated on the rising edge */
    PWM_RISING_EDGE     = 0x00U,
    /** @brief  A notification will be generated on the falling edge */
    PWM_FALLING_EDGE    = 0x1U,
    /** @brief  A notification will be generated on any state transition */
    PWM_BOTH_EDGES      = 0x02U
} Pwm_EdgeNotificationType;

/**
* @brief        PWM channel class type
* @details      This field will specify what parameters can be altered for the selected channel
*
* @implements   Pwm_ChannelClassType_enumeration
*/
typedef enum
{
    /** @brief  The period and duty cycle can be altered */
    PWM_VARIABLE_PERIOD         = 0x00U,
    /** @brief  Only the duty cycle can be altered */
    PWM_FIXED_PERIOD            = 0x01U,
    /** @brief  Only the duty cycle can be altered */
    PWM_FIXED_PERIOD_SHIFTED    = 0x02U
} Pwm_ChannelClassType;

/**
* @brief        Power state type
* @details      Power state currently active or set as target power state.
*
* @implements   Pwm_PowerStateType_enumeration
*/
typedef enum
{
    /** @brief  PWM full power mode */
    PWM_FULL_POWER      = 0x00U,
    /** @brief  PWM low power mode */
    PWM_LOW_POWER       = 0x01U,
    /** @brief  PWM no define power mode */
    PWM_NODEFINE_POWER  = 0x02U
} Pwm_PowerStateType;

/**
* @brief        Result of power state type
* @details      Result of the requests related to power state transitions.
*
* @implements   Pwm_PowerStateRequestResultType_enumeration
*/
typedef enum
{
    /** @brief  Power state change executed. */
    PWM_SERVICE_ACCEPTED        = 0x00U,
    /** @brief  Module not initialized. */
    PWM_NOT_INIT                = 0x01U,
    /** @brief  Wrong API call sequence. */
    PWM_SEQUENCE_ERROR          = 0x02U,
    /** @brief  The HW module has a failure which prevents it to enter the required power state. */
    PWM_HW_FAILURE              = 0x03U,
    /** @brief  Module does not support the requested power state. */
    PWM_POWER_STATE_NOT_SUPP    = 0x04U,
    /** @brief  Module cannot transition directly from the current power state to the requested power state */
    PWM_TRANS_NOT_POSSIBLE      = 0x05U
} Pwm_PowerStateRequestResultType;

/**
* @brief        Prescaler type
* @details      This enumeration specifies the possible types of prescalers used to configure base-clock timers
*
*/
typedef enum
{
    /** @brief  Selected value is the default/primary prescaler */
    PWM_PRIMARY_PRESCALER       = 0x00U,
    /** @brief  Selected value is the alternative configured prescaler */
    PWM_ALTERNATIVE_PRESCALER   = 0x01U
} Pwm_PrescalerType;

#if (PWM_SET_CHANNEL_FORCE_OUT_API == STD_ON)
/**
* @brief        Output state of FlexPWM during force out event
* @details      Defines input parameter for output state of FlexPWM channel when force out event occurred
*               by calling Pwm_SetChannelForceOut function
*/
typedef enum
{
    /** @brief  The PWM pin will be into logic 0. */
    PWM_FORCE_OUT_STATE_LOW         = 0x00U,
    /** @brief  The PWM pin will be into logic 1. */
    PWM_FORCE_OUT_STATE_HIGH        = 0x01U,
    /** @brief  The PWM pin will be into normal. */
    PWM_FORCE_OUT_STATE_NORMALOUT   = 0x02U,
    /** @brief  The PWM pin will inverted. */
    PWM_FORCE_OUT_STATE_INVERTED    = 0x04U,
    /** @brief  The PWM pin will be masked (disable). */
    PWM_FORCE_OUT_STATE_MASKEDOUT   = 0x08U
} Pwm_ForceOutStateType;
#endif

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief        PWM channel type
* @implements   Pwm_ChannelType_typedef
*/
typedef uint8 Pwm_ChannelType;

/**
* @brief        PWM channel type
* @implements   Pwm_ChannelType_typedef
*/
typedef uint8 Pwm_InstanceType;

/**
* @brief        PWM period type
* @implements   Pwm_PeriodType_typedef
*/
typedef Pwm_Ipw_PeriodType Pwm_PeriodType;

#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
/**
* @brief        PWM duty type
* @implements   Pwm_DutyType_typedef
*/
typedef Pwm_Ipw_DutyType Pwm_DutyType;
#endif /* PWM_SET_DUTY_PHASE_SHIFT_API */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Channel notification typedef
*
*/
typedef void (*Pwm_NotifyType)(void);
#endif /* PWM_NOTIFICATION_SUPPORTED */

/**
* @brief        Pwm channel high level configuration structure
* @implements   Pwm_ChannelConfigType_struct
*/
typedef struct
{
    /** @brief  Id for the logical channel */
    const Pwm_ChannelType           ChannelId;
    /** @brief  Channel class type: Variable/Fixed period */
    const Pwm_ChannelClassType      PwmChannelClass;
    /** @brief  The type of ip channel configured */
    const Pwm_IpwChannelConfigType  IpwChannelCfg;
    /** @brief  The state of the channel output in idle mode */
    const Pwm_OutputStateType       ChannelIdleState;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    const Pwm_NotifyType            PwmChannelNotification;
#endif
} Pwm_ChannelConfigType;

/**
* @brief        Pwm high level configuration structure
* @implements   Pwm_ConfigType_struct
*/
typedef struct
{
#if (PWM_MULTICORE_ENABLED == STD_ON)
    /** @brief  Core ID */
    const uint32                    CoreId;
#endif
    /** @brief  Number of Pwm configured channels */
    const Pwm_ChannelType           NumChannels;
    /** @brief  Pointer to the list of Pwm configured channels */
    const Pwm_ChannelConfigType     (*PwmChannelsConfig)[];
#if (PWM_HW_INSTANCE_USED == STD_ON)
    /** @brief  Number of Pwm configured instances */
    const Pwm_InstanceType          NumInstances;
    /** @brief  Pointer to the list of Pwm configured channels */
    const Pwm_IpwInstanceConfigType (*PwmInstancesConfig)[];
#endif
#if (PWM_MULTICORE_ENABLED == STD_ON)
    /** @brief  Pointer to array of global-logical to partition-logical map */
    const uint8                     (*PwmLogicalToPartitionMap)[];
#endif
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /** @brief  Index table to translate HW channels to logical used to process interrupts for notifications */
    const Pwm_ChannelType           HwToLogicChannelMap[PWM_HW_CHANNEL_NO];
#endif
} Pwm_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (PWM_PRECOMPILE_SUPPORT == STD_OFF)
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

PWM_CONFIG_EXTERNAL

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#endif /* #ifndef PWM_PRECOMPILE_SUPPORT*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/*===============================================================================================*/
/**
* @brief        This function initializes the Pwm driver.
* @details      The function Pwm_Init shall initialize all internals variables and the used
*               PWM structure of the microcontroller according to the parameters
*               specified in configPtr.
*               If the duty cycle parameter equals:
*
*                   - 0% or 100% : Then the PWM output signal shall be in the state according
*                       to the configured polarity parameter;
*
*                   - >0% and <100%: Then the PWM output signal shall be modulated according
*                       to parameters period, duty cycle and configured polarity.
*
*               The function Pwm_SetDutyCycle shall update the duty cycle always at the end
*               of the period if supported by the implementation and configured
*               with PwmDutycycleUpdatedEndperiod.
*
*               The driver shall avoid spikes on the PWM output signal when updating
*               the PWM period and duty.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the channel class type and raise development error PWM_E_PERIOD_UNCHANGEABLE
*               if the PWM channel is not declared as a variable period type.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the parameter channelNumber and raise development error PWM_E_PARAM_CHANNEL
*               if the parameter channelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled, when a development
*               error occurs, the corresponding PWM function shall:
*
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The function Pwm_Init shall disable all notifications. The reason is that the users
*               of these notifications may not be ready. They can call Pwm_EnableNotification
*               to start notifications.
*
*               The function Pwm_Init shall only initialize the configured resources and shall not touch
*               resources that are not configured in the configuration file.
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection is enabled, calling the routine Pwm_Init
*               while the PWM driver and hardware are already initialized will cause a
*               development error PWM_E_ALREADY_INITIALIZED.
*               The desired functionality shall be left without any action.
*
*               For pre-compile and link time configuration variants, a NULL pointer shall be passed
*               to the initialization routine. In this case the check for this NULL pointer
*               has to be omitted.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ConfigPtr       Pointer to PWM top configuration structure
*
* @return       void
*
*
*/
void Pwm_Init(const Pwm_ConfigType *ConfigPtr);

/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief        This function deinitializes the Pwm driver.
* @details      The function Pwm_DeInit shall deinitialize the PWM module.
*
*               The function Pwm_DeInit shall set the state of the PWM output signals
*               to the idle state.
*               The function Pwm_DeInit shall disable PWM interrupts and PWM signal edge notifications.
*               The function Pwm_DeInit shall be pre-compile time configurable On-Off by the
*               configuration parameter PwmDeInitApi function prototype.
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @return       void
*
*
*/
void Pwm_DeInit(void);
#endif /* PWM_DE_INIT_API */

/*===============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief        This function sets the dutycycle for the specified Pwm channel.
* @details      The function Pwm_SetDutyCycle shall set the duty cycle of the PWM channel.
*
*               The function Pwm_SetDutyCycle shall set the PWM output state according
*               to the configured polarity parameter, when the duty cycle = 0% or 100%.
*               The function Pwm_SetDutyCycle shall modulate the PWM output signal according
*               to parameters period, duty cycle and configured polarity,
*               when the duty cycle > 0 % and < 100%.
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter channelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter channelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The Pwm module shall comply with the following scaling scheme for the duty cycle:
*                   - 0x0000 means 0%.
*                   - 0x8000 means 100%.
*                   - 0x8000 gives the highest resolution while allowing 100% duty cycle to be
*                       represented with a 16 bit value.
*                       As an implementation guide, the following source code example is given:
*                       AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
* @param[in]    ChannelNumber       Pwm Channel Id in the configuration
* @param[in]    DutyCycle           Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
*
*/
void Pwm_SetDutyCycle(Pwm_ChannelType   ChannelNumber,
                      uint16            DutyCycle);
#endif /* PWM_SET_DUTY_CYCLE_API */

/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief        This function sets the period and the dutycycle for the specified Pwm channel.
* @details      The function Pwm_SetPeriodAndDuty shall set the duty cycle of the PWM channel.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the channel class type and raise development error PWM_E_PERIOD_UNCHANGEABLE
*               if the PWM channel is not declared as a variable period type.
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter channelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter channelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The Pwm module shall comply with the following scaling scheme for the duty cycle:
*                   - 0x0000 means 0%.
*                   - 0x8000 means 100%.
*                   - 0x8000 gives the highest resolution while allowing 100% duty cycle to be
*                       represented with a 16 bit value.
*                       As an implementation guide, the following source code example is given:
*                       AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function shall
*               raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber   Pwm Channel Id in the configuration
* @param[in]    Period          Pwm signal period value
* @param[in]    DutyCycle       Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
*
*/
void Pwm_SetPeriodAndDuty(Pwm_ChannelType   ChannelNumber,
                          Pwm_PeriodType    Period,
                          uint16            DutyCycle);
#endif /* PWM_SET_PERIOD_AND_DUTY_API */

/*===============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief        This function sets the generated pwm signal to the idle value configured.
* @details      The function Pwm_SetOutputToIdle shall set immediately the
*               PWM output to the configured Idle state.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the parameter channelNumber and raise development error PWM_E_PARAM_CHANNEL
*               if the parameter channelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled, when a
*               development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of data
*                       or hardware registers (this means leave the function without any actions).
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               After the call of the function Pwm_SetOutputToIdle, variable period type channels
*               shall be reactivated either using the Api Pwm_SetPeriodAndDuty() to activate
*               the PWM channel with the new passed period or Api Pwm_SetDutyCycle() to activate
*               the PWM channel with the old period.
*
*               After the call of the function Pwm_SetOutputToIdle, fixed period type channels
*               shall be reactivated using only the API Api Pwm_SetDutyCycle() to activate
*               the PWM channel with the old period.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber    Pwm Channel Id in the configuration
*
* @return       void
*
*
*/
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber);
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */

/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        This function returns the signal output state.
* @details      The function Pwm_GetOutputState shall read the internal state of
*               the PWM output signal and return it as defined in the diagram below (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter channelNumber and
*               raise development error PWM_E_PARAM_CHANNEL if the parameter channelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled, when a
*               development error occurs, the corresponding PWM function shall:
*                  - Report the error to the Development Error Tracer.
*                  - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*                  - Return pwm level low for the function Pwm_GetOutputState.
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               Due to real time constraint and setting of the PWM channel (project dependant),
*               the output state can be modified just after the call of the service Pwm_GetOutputState.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber    Pwm Channel Id in the configuration
*
* @return       Pwm_OutputStateType  Pwm signal output logic value
* @retval       PWM_LOW              The output state of PWM channel is low
* @retval       PWM_HIGH             The output state of PWM channel is high
*
*
*/
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber);
#endif /* PWM_GET_OUTPUT_STATE_API */

/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        This function enables the user notifications.
* @details      The function Pwm_EnableNotification shall enable the PWM signal edge notification
*               according to notification parameter.
*               If development error detection for the Pwm module is enabled:
*               - The PWM functions shall check the parameter channelNumber and raise
*               development error PWM_E_PARAM_CHANNEL if the parameter channelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled, when a development error
*               occurs, the corresponding PWM function shall:
*
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber   Pwm Channel Id in the configuration
* @param[in]    Notification    Notification type to be enabled
*
* @return       void
*
*
*/
void Pwm_EnableNotification(Pwm_ChannelType           ChannelNumber,
                            Pwm_EdgeNotificationType  Notification);
#endif /* PWM_NOTIFICATION_SUPPORTED */

/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        This function disables the user notifications.
* @details      If development error detection for the Pwm module is enabled:
*               - The PWM functions shall check the parameter channelNumber and raise
*               development error PWM_E_PARAM_CHANNEL if the parameter channelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*               - Report the error to the Development Error Tracer.
*               - Skip the desired functionality in order to avoid any corruptions of
*                  data or hardware registers (this means leave the function without any actions).
*               - Return pwm level low for the function Pwm_GetOutputState.
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*                All functions from the PWM module except Pwm_Init, Pwm_DeInit and Pwm_GetVersionInfo
*               shall be re-entrant for different PWM channel numbers. In order to keep a simple module
*               implementation, no check of PWM088 must be performed by the module.
*               The function Pwm_DisableNotification shall be pre compile time configurable On-Off by the
*               configuration parameter: PwmNotificationSupported.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function shall
*               raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber     Pwm Channel Id in the configuration
*
* @return       void
*
*
*/
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber);
#endif /* PWM_NOTIFICATION_SUPPORTED */

/*===============================================================================================*/
#if (PWM_VERSION_INFO_API == STD_ON)
/**
* @brief        This function returns Pwm driver version details
* @details      The function Pwm_GetVersionInfo shall return the version information of this module.
*               The version information includes: Module Id, Vendor Id, Vendor specific version number.
*
* @param[out]   versioninfo     Pointer to Std_VersionInfoType output variable
*
* @return       void
*
*
*/
void Pwm_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /* PWM_VERSION_INFO_API */

/*===============================================================================================*/
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/**
* @brief        This function returns the duty cycle of the channel passed as parameter
* @details      The function Pwm_GetChannelState shall return the DutyCycle of the channel.
*               In case the channel is idle, the returned value will be zero.
*
* @param[in]    ChannelNumber   Pwm Channel Id in the configuration
*
* @return       uint16          DutyCycle of the requested channel
*
*
*/
uint16 Pwm_GetChannelState(Pwm_ChannelType ChannelNumber);
#endif /* PWM_GET_CHANNEL_STATE_API */

/*===============================================================================================*/
#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
/**
* @brief        This function enables-disables the forcing of the output of a given channel to logic 0.
* @details      The function Pwm_GetChannelState shall return the DutyCycle of the channel.
*               In case the channel is idle, the returned value will be zero.
*
* @param[in]    ChannelNumber   Pwm Channel Id in the configuration
* @param[in]    Force           Boolean value to state if the output of the channel will be forced
*                               to zero logic or not
*
* @return       void
*
*/
void Pwm_ForceOutputToZero(Pwm_ChannelType  ChannelNumber,
                           boolean          Force);
#endif /* PWM_FORCE_OUTPUT_TO_ZERO_API */

/*===============================================================================================*/
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
/**
* @brief        This function will change the bus of pwm channels running.
* @details      This function is useful to change the frequency of the output PWM signal between
*               two counter buses frequency
*
* @param[in]    ChannelNumber  Pwm Channel Id in the configuration
* @param[in]    Bus            The eMIOS bus will be selected to change
*
* @return       void
*
*/
void Pwm_SetCounterBus(Pwm_ChannelType  ChannelNumber,
                       uint32           Bus);
#endif /* PWM_SET_COUNTER_BUS_API */

/*===============================================================================================*/
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/**
* @brief        function to set the state of the PWM pin as requested for the current cycle
* @details      This function is useful to set the state of the PWM pin as requested
*               for the current cycle and continues with normal PWM operation from the next cycle
*
* @param[in]    ChannelNumber       Pwm Channel Id in the configuration
* @param[in]    State               Active-Inactive state of the channel
*
* @return       void
*
*/
void Pwm_SetChannelOutput(Pwm_ChannelType   ChannelNumber,
                          Pwm_StateType     State);
#endif /* PWM_SET_CHANNEL_OUTPUT_API */

/*===============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/**
* @brief        Implementation specific function to change the trigger delay
* @details      This function is useful to set the trigger delay to opwmt mode. If no DET error
*               reported then the trigger delay for  the PWM channels will be set. If development
*               error detection for the Pwm module is enabled:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of data
*               or hardware registers: This means leave the function without any actions.
*
* @param[in]    ChannelNumber    Pwm Channel Id in the configuration
* @param[in]    TriggerDelay     Trigger delay value will be updated
*
* @return       void
*
*/
void Pwm_SetTriggerDelay(Pwm_ChannelType    ChannelNumber,
                         Pwm_PeriodType     TriggerDelay);
#endif /* PWM_SET_TRIGGER_DELAY_API */

/*===============================================================================================*/
#if (PWM_SET_CHANNEL_FORCE_OUT_API == STD_ON)
/**
* @brief        Function to control the PWM output when force out events occurred
* @details      When force out events occurred, the PWM output will change to configured output state.
*
* @param[in]    ChannelNumber   Pwm Channel Id in the configuration
* @param[in]    State           Channel state changed when force out
*
* @return       void
*/
void Pwm_SetChannelForceOut(Pwm_ChannelType         ChannelNumber,
                            Pwm_ForceOutStateType   State);
#endif /* PWM_SET_CHANNEL_FORCE_OUT_API */

/*===============================================================================================*/
#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        Implementation specific function to change the peripheral clock frequency.
* @details      This function is useful to set the prescalers that divide the PWM channels
*               clock frequency.
*
* @param[in]    Prescaler   Prescaler type
*
* @return       void
*
*
*/
void Pwm_SetClockMode(Pwm_PrescalerType Prescaler);
#endif /* PWM_SET_CLOCK_MODE_API */

/*===============================================================================================*/
#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief
* @details      This function is used to update the deadtime at runtime for Pwm channels.
*
* @param[in]    ChannelNumber       Pwm channel id
* @param[in]    DeadTimeTicks       Dead Time value in ticks
*
* @return       void
*
*
*/
void Pwm_SetChannelDeadTime(Pwm_ChannelType  ChannelNumber,
                            Pwm_PeriodType   DeadTimeTicks);
#endif /* PWM_SET_CHANNEL_DEAD_TIME_API */

/*===============================================================================================*/
#if (PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON)

/*===============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON)
/**
* @brief        This function sets the values of dutycycle for the specified Pwm channel but without
*               updating the PWM output.
* @details      The function Pwm_SetDutyCycle_NoUpdate shall set the duty cycle of the PWM channel to the
*               coresponding hardware buffers without updating the wave form on the output pin.
*               This feature will allow a pre-buffering of new PWM duty cycle values for several channel,
*               which can all be updated synchronos by calling Pwm_SyncUpdate.
*
*               The function Pwm_SetDutyCycle_NoUpdate shall set the PWM output state according
*               to the configured polarity parameter, when the duty cycle = 0% or 100%.
*               The function Pwm_SetDutyCycle_NoUpdate shall modulate the PWM output signal according
*               to parameters period, duty cycle and configured polarity,
*               when the duty cycle > 0 % and < 100%.
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter channelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter channelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The Pwm module shall comply with the following scaling scheme for the duty cycle:
*                   - 0x0000 means 0%.
*                   - 0x8000 means 100%.
*                   - 0x8000 gives the highest resolution while allowing 100% duty cycle to be
*                       represented with a 16 bit value.
*                       As an implementation guide, the following source code example is given:
*                       AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
* @param[in]    ChannelNumber       Pwm Channel Id in the configuration
* @param[in]    DutyCycle           Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
*
*/
void Pwm_SetDutyCycle_NoUpdate(Pwm_ChannelType  ChannelNumber,
                               uint16           DutyCycle);
#endif /* PWM_SET_DUTY_CYCLE_NO_UPDATE_API */

/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON)
/**
* @brief        This function sets the values of the period and the dutycycle for the specified Pwm channel
*               into the hardware buffers but without updating the PWM output..
* @details      The function Pwm_SetPeriodAndDuty_NoUpdate shall set the period and duty cycle of the PWM
*               channel to the coresponding hardware buffers without updating the wave form on the output pin.
*               This feature will allow a pre-buffering of new PWM duty cycle values for several channel,
*               which can all be updated synchronos by calling Pwm_SyncUpdate.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the channel class type and raise development error PWM_E_PERIOD_UNCHANGEABLE
*               if the PWM channel is not declared as a variable period type.
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter channelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter channelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The Pwm module shall comply with the following scaling scheme for the duty cycle:
*                   - 0x0000 means 0%.
*                   - 0x8000 means 100%.
*                   - 0x8000 gives the highest resolution while allowing 100% duty cycle to be
*                       represented with a 16 bit value.
*                       As an implementation guide, the following source code example is given:
*                       AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function shall
*               raise development error PWM_E_UNINIT.
*
* @param[in]    ChannelNumber   Pwm Channel Id in the configuration
* @param[in]    Period          Pwm signal period value
* @param[in]    DutyCycle       Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
*
*/
void Pwm_SetPeriodAndDuty_NoUpdate(Pwm_ChannelType  ChannelNumber,
                                   Pwm_PeriodType   Period,
                                   uint16           DutyCycle);
#endif /* PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API */

/*===============================================================================================*/
#if (PWM_SYNC_UPDATE_API == STD_ON)
/**
* @brief        Implementation specific function to updates duty synchronization.
*
* @details      This function is used to update duty synchronization for channels in given module,
*               this should be called after calling Pwm_SetPeriodAndDuty_NoUpdate() or
*               Pwm_SetDutyCycle_NoUpdate() API.
*
* @param[in]    ModuleId     pwm module id(instance ID)
*                            Ex : PWM_EMIOS_INSTANCE_0
*                                 PWM_EMIOS_INSTANCE_1
*                                 ...
*                                 PWM_FTM_INSTANCE_0
*
* @return       void
*
*
*/
void Pwm_SyncUpdate(uint8 ModuleId);
#endif /* PWM_SYNC_UPDATE_API */

#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS */

/*===============================================================================================*/
#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
/**
* @brief        This function set phase shift and duty cycle value (as immediate or synchronized base on API parameter SyncUpdate)
*
* @details      Pwm_SetDutyPhaseShift allows to set both phase shift and duty cycle value,
*               The phase shift is the offset of the leading edge of the signal in respect to period starting point.
*
* @param[in]    ChannelNumber           Pwm Channel Id in the configuration
* @param[in]    DutyCycle               Pwm duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    PhaseShift              Phase shift value (in ticks)
* @param[in]    SyncUpdate              Update duty and phases shift value synchronization for channels in given module or not
*                                       TRUE     Set the phase shift and duty cycle value base on the synchronization when calling Pwm_SyncUpdate.
*                                       FALSE    Set phase shift and duty cycle value immediately
*
* @return       void
*
*
*/
void Pwm_SetDutyPhaseShift(Pwm_ChannelType  ChannelNumber,
                           uint16           DutyCycle,
                           Pwm_DutyType     PhaseShift,
                           boolean          SyncUpdate);
#endif /* PWM_SET_DUTY_PHASE_SHIFT_API */

/*===============================================================================================*/
#if (PWM_ENABLE_TRIGGER_API == STD_ON)
/**
* @brief        This function enable trigger generation for specific source
* @details      Corresponding bits with trigger source as bellow:
*               Bit 0   Channel 2 Trigger Enable
*               Bit 1   Channel 3 Trigger Enable
*               Bit 2   Channel 4 Trigger Enable
*               Bit 3   Channel 5 Trigger Enable
*               Bit 4   Channel 0 Trigger Enable
*               Bit 5   Channel 1 Trigger Enable
*               Bit 6   Initialization Trigger Enable
*
* @param[in]    TriggerHostId    Pwm hardware module id
* @param[in]    TriggerMask      Bit mask will be set to enable trigger with corresponding sources.
*
* @return       void
*
*/
void Pwm_EnableTrigger(uint8    TriggerHostId,
                       uint16   TriggerMask);
#endif /* PWM_ENABLE_TRIGGER_API */

/*===============================================================================================*/
#if (PWM_DISABLE_TRIGGER_API == STD_ON)
/**
* @brief        This function disable trigger generation for specific source
* @details      Corresponding bits with trigger source as bellow:
*               Bit 0   Channel 2 Trigger Enable
*               Bit 1   Channel 3 Trigger Enable
*               Bit 2   Channel 4 Trigger Enable
*               Bit 3   Channel 5 Trigger Enable
*               Bit 4   Channel 0 Trigger Enable
*               Bit 5   Channel 1 Trigger Enable
*               Bit 6   Initialization Trigger Enable
*
* @param[in]    TriggerHostId    Pwm hardware module id
* @param[in]    TriggerMask      Bit mask will be cleared to disable trigger with corresponding sources.
*
* @return       void
*
*/
void Pwm_DisableTrigger(uint8   TriggerHostId,
                        uint16  TriggerMask);
#endif /* PWM_DISABLE_TRIGGER_API */

/*===============================================================================================*/
#if (PWM_RESET_COUNTER_API == STD_ON)
/**
* @brief        This function shall enable the PWM timer HW counter reset
*               by Pwm_SyncUpdate() function.
* @details
*
* @param[in]    ModuleId    Pwm hardware module id
*
* @return       void
*
*/
void Pwm_ResetCounterEnable(uint8 ModuleId);
#endif /* PWM_RESET_COUNTER_API */

/*===============================================================================================*/
#if (PWM_RESET_COUNTER_API == STD_ON)
/**
* @brief        This function shall disable the PWM timer HW counter reset
*               by Pwm_SyncUpdate() function.
* @details
*
*
* @param[in]    ModuleId    Pwm hardware module id
*
* @return       void
*
*/
void Pwm_ResetCounterDisable(uint8 ModuleId);
#endif /* PWM_RESET_COUNTER_API */

/*===============================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        This function shall be used to change duty cycle or phase shift 
*               with minimum overhead
* @details      Fast update API is only supported for Emios Ip
*
*
* @param[in]    ChannelNumber    Pwm logic channel id
* @param[in]    Value            Value to write in register
*
* @return       void
*
*/
void Pwm_FastUpdateSetUCRegA(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Value);
#endif /* PWM_FAST_UPDATE_API */

/*===============================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        This function shall be used to change duty cycle, phase shift or
*               inserted dead time buffer with minimum overhead
* @details      Fast update API is only supported for Emios Ip
*
*
* @param[in]    ChannelNumber    Pwm logic channel id
* @param[in]    Value            Value to write in register
*
* @return       void
*
*/
void Pwm_FastUpdateSetUCRegB(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Value);
#endif /* PWM_FAST_UPDATE_API */

/*===============================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        This function shall be used to disable output update for selected Emios channels
* @details      Fast update API is only supported for Emios Ip
*
* @param[in]    ModuleId       Pwm hardware module id
* @param[in]    ChannelMask    Bit mask of Emios hardware channels
*
* @return       void
*
*/
void Pwm_FastUpdateDisableOU(uint8 ModuleId, uint32 ChannelMask);
#endif /* PWM_FAST_UPDATE_API */

/*===============================================================================================*/
#if (PWM_FAST_UPDATE_API == STD_ON)
/**
* @brief        This function shall be used to enable output update for selected Emios channels
* @details      Fast update API is only supported for Emios Ip
*
*
* @param[in]    ModuleId       Pwm hardware module id
* @param[in]    ChannelMask    Bit mask of Emios hardware channels
*
* @return       void
*
*/
void Pwm_FastUpdateEnableOU(uint8 ModuleId, uint32 ChannelMask);
#endif /* PWM_FAST_UPDATE_API */

/*===============================================================================================*/
#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function force channels output to their inactive state
* @details      Corresponding bits with channel will be masked:
*               Bit 0   Channel 0 Output Mask
*               Bit 1   Channel 1 Output Mask
*               Bit 2   Channel 2 Output Mask
*               Bit 3   Channel 3 Output Mask
*               Bit 4   Channel 4 Output Mask
*               Bit 5   Channel 5 Output Mask
*
* @param[in]    ModuleId        Pwm hardware module id
* @param[in]    ChannelMask     Bit mask will be set to mask corresponding channel.
*
* @return       void
*
*/
void Pwm_MaskOutputs(uint8 ModuleId,
                     uint8 ChannelMask);
#endif /* PWM_ENABLE_MASKING_OPERATIONS */

/*===============================================================================================*/
#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function puts channels output to normal operation state
* @details      Corresponding bits with channel will be masked:
*               Bit 0   Channel 0 Output Mask
*               Bit 1   Channel 1 Output Mask
*               Bit 2   Channel 2 Output Mask
*               Bit 3   Channel 3 Output Mask
*               Bit 4   Channel 4 Output Mask
*               Bit 5   Channel 5 Output Mask
*
* @param[in]    ModuleId      Pwm hardware module id
* @param[in]    ChannelMask   Bit mask will be cleared to unmask corresponding channel.
*
* @return       void
*
*/
void Pwm_UnMaskOutputs(uint8 ModuleId,
                       uint8 ChannelMask);
#endif /* PWM_ENABLE_MASKING_OPERATIONS */

/*===============================================================================================*/
#if (PWM_RELOAD_NOTIF_SUPPORTED == STD_ON)
/**
* @brief        This function enables the user reload notifications.
* @details      The function Pwm_EnableReloadNotification shall enable the PWM reload notification
*               If development error detection for the Pwm module is enabled:
*               - The PWM functions shall check the parameter ModuleId and raise
*               development error PWM_E_PARAM_INSTANCE if the parameter ModuleId is invalid.
*
*               If development error detection for the Pwm module is enabled, when a development error
*               occurs, the corresponding PWM function shall:
*
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ModuleId    Pwm hardware module id
*
* @return       void
*
*/
void Pwm_EnableReloadNotification(uint8 ModuleId);
#endif /* PWM_RELOAD_NOTIF_SUPPORTED */

/*===============================================================================================*/
#if (PWM_RELOAD_NOTIF_SUPPORTED == STD_ON)
/**
* @brief        This function disables the user reload notifications.
* @details      The function Pwm_DisableReloadNotification shall disable the PWM reload notification
*               If development error detection for the Pwm module is enabled:
*               - The PWM functions shall check the parameter ModuleId and raise
*               development error PWM_E_PARAM_INSTANCE if the parameter ModuleId is invalid.
*
*               If development error detection for the Pwm module is enabled, when a development error
*               occurs, the corresponding PWM function shall:
*
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ModuleId    Pwm hardware module id
*
* @return       void
*
*/
void Pwm_DisableReloadNotification(uint8 ModuleId);
#endif /* PWM_RELOAD_NOTIF_SUPPORTED */

/*===============================================================================================*/
#if (PWM_FAULT_SUPPORTED == STD_ON)
/**
* @brief        This function enables the user fault notifications.
* @details      The function Pwm_EnableFaultNotification shall enable the PWM fault notification
*               If development error detection for the Pwm module is enabled:
*               - The PWM functions shall check the parameter ModuleId and raise
*               development error PWM_E_PARAM_INSTANCE if the parameter ModuleId is invalid.
*
*               If development error detection for the Pwm module is enabled, when a development error
*               occurs, the corresponding PWM function shall:
*
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ModuleId    Pwm hardware module id
*
* @return       void
*
*/
void Pwm_EnableFaultNotification(uint8 ModuleId);
#endif /* PWM_FAULT_SUPPORTED */

/*===============================================================================================*/
#if (PWM_FAULT_SUPPORTED == STD_ON)
/**
* @brief        This function disables the user fault notifications.
* @details      The function Pwm_DisableFaultNotification shall disable the PWM fault notification
*               If development error detection for the Pwm module is enabled:
*               - The PWM functions shall check the parameter ModuleId and raise
*               development error PWM_E_PARAM_INSTANCE if the parameter ModuleId is invalid.
*
*               If development error detection for the Pwm module is enabled, when a development error
*               occurs, the corresponding PWM function shall:
*
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ModuleId    Pwm hardware module id
*
* @return       void
*
*/
void Pwm_DisableFaultNotification(uint8 ModuleId);
#endif /* PWM_FAULT_SUPPORTED */

/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Enters the already prepared power state.
* @details      This API configures the Pwm module so that it enters the already prepared power
*               state, chosen between a predefined set of configured ones.
*
* @param[out]   Result          Pointer to a variable to store the result of this function
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK:           Power Mode changed.
* @retval       E_NOT_OK:       Request rejected.
*
*
*/
Std_ReturnType Pwm_SetPowerState(Pwm_PowerStateRequestResultType *Result);
#endif /* PWM_POWER_STATE_SUPPORTED */

/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Get the current power state of the Pwm HW unit.
* @details      This API returns the current power state of the Pwm HW unit.
*
* @param[out]   CurrentPowerState     The current power mode of the Pwm HW Unit is returned in this parameter
* @param[out]   Result                Pointer to a variable to store the result of this function
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK:           Mode could be read.
* @retval       E_NOT_OK:       Service is rejected.
*
*
*/
Std_ReturnType Pwm_GetCurrentPowerState(Pwm_PowerStateType *              CurrentPowerState,
                                        Pwm_PowerStateRequestResultType * Result);
#endif /* PWM_POWER_STATE_SUPPORTED */

/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Get the target power state of the Pwm HW unit.
* @details      This API returns the target power state of the Pwm HW unit.
*
* @param[out]   TargetPowerState      The Target power mode of the Pwm HW Unit is returned in this parameter.
* @param[out]   Result                Pointer to a variable to store the result of this function.
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK:           Mode could be read.
* @retval       E_NOT_OK:       Service is rejected.
*
*
*/
Std_ReturnType Pwm_GetTargetPowerState(Pwm_PowerStateType *              TargetPowerState,
                                       Pwm_PowerStateRequestResultType * Result);
#endif /* PWM_POWER_STATE_SUPPORTED */

/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Starts the needed process to allow the Pwm HW module to enter the requested power state.
* @details      This API starts the needed process to allow the Pwm HW module to enter the requested power state.
*
* @param[in]    PowerState      The target power state intended to be attained.
* @param[out]   Result          Pointer to a variable to store the result of this function.
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK:           Mode could be read.
* @retval       E_NOT_OK:       Service is rejected.
*
*
*/
Std_ReturnType Pwm_PreparePowerState(Pwm_PowerStateType                PowerState,
                                     Pwm_PowerStateRequestResultType * Result);
#endif /* PWM_POWER_STATE_SUPPORTED */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PWM_H */
