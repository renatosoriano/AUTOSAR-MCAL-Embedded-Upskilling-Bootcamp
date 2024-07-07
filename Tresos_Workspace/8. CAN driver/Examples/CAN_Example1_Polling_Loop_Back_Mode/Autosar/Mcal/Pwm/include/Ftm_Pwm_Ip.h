/*==================================================================================================
* Project              : RTD AUTOSAR 4.7
* Platform             : CORTEXM
* Peripheral           : Ftm Flexio
* Dependencies         : none
*
* Autosar Version      : 4.7.0
* Autosar Revision     : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version           : 2.0.0
* Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef FTM_PWM_IP_H
#define FTM_PWM_IP_H

/**
*   @file       Ftm_Pwm_Ip.h
*
*   @addtogroup ftm_pwm_ip Ftm Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Std_Types.h"
#include "Ftm_Pwm_Ip_Cfg.h"
#include "Ftm_Pwm_Ip_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FTM_PWM_IP_VENDOR_ID                       43
#define FTM_PWM_IP_MODULE_ID                       121
#define FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION        4
#define FTM_PWM_IP_AR_RELEASE_MINOR_VERSION        7
#define FTM_PWM_IP_AR_RELEASE_REVISION_VERSION     0
#define FTM_PWM_IP_SW_MAJOR_VERSION                2
#define FTM_PWM_IP_SW_MINOR_VERSION                0
#define FTM_PWM_IP_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip.h and Std_Types.h are different."
    #endif
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (FTM_PWM_IP_VENDOR_ID != FTM_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((FTM_PWM_IP_SW_MAJOR_VERSION != FTM_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_SW_MINOR_VERSION != FTM_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_SW_PATCH_VERSION != FTM_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same vendor */
#if (FTM_PWM_IP_VENDOR_ID != FTM_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same software version */
#if ((FTM_PWM_IP_SW_MAJOR_VERSION != FTM_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_SW_MINOR_VERSION != FTM_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_SW_PATCH_VERSION != FTM_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip.h and Ftm_Pwm_Ip_Types.h are different."
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*! @brief Maximum value for PWM duty cycle */
#define FTM_PWM_IP_MAX_DUTY_CYCLE      (0x8000U)

#define FTM_PWM_IP_INSTANCE_COUNT  (FTM_PWM_IP_IRQS_ARR_COUNT)


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/*!
 * @brief Initializes the FTM driver.
 * The clock sources depend on the specified hardware. So that needs to check the
 * external clock or the fixed frequency clock is available on device or not.
 *
 * @param[in] Instance The FTM peripheral instance number.
 * @param[in] info The FTM user configuration structure, see #Ftm_Pwm_Ip_UserConfigType.
 * @param[out] state The FTM state structure of the driver.
 * @return void

 */
void Ftm_Pwm_Ip_Init(uint8 Instance,
                     const Ftm_Pwm_Ip_UserCfgType * UserCfg);

/*!
 * @brief Shuts down the FTM driver.
 *
 * @param[in] Instance The FTM peripheral instance number.
 * @return    void
 *
 */
void Ftm_Pwm_Ip_DeInit(uint8 Instance);

/*!
 * @brief This function updates the waveform output in PWM mode (duty cycle and phase).
 *
 * @Note: Regarding the type of updating PWM in the duty cycle, if the expected duty
 * is 100% then the value that is to be written to hardware will be exceed value of period.
 * It means that the FTM counter will not match the value of the CV register in this case.
 *
 * @param [in] Instance The FTM peripheral instance number.
 * @param [in] Channel The channel number. In combined mode, the code finds the channel.
 * @param [in] FirstEdge  Duty cycle or first edge time for PWM mode. Can take value between
 *                       0 - FTM_PWM_IP_MAX_DUTY_CYCLE(0 = 0% from period  and FTM_PWM_IP_MAX_DUTY_CYCLE = 100% from period)
 *                       Or value in ticks for the first of the PWM mode in which can have value between 0
 *                       and ftmPeriod is stored in the state structure.
 * @param [in] SecondEdge Second edge time - only for combined mode. Can take value
 *                       between 0 - FTM_PWM_IP_MAX_DUTY_CYCLE(0 = 0% from period  and FTM_PWM_IP_MAX_DUTY_CYCLE = 100% from period).
 *                       Or value in ticks for the second of the PWM mode in which can have value between 0
 *                       and ftmPeriod is stored in the state structure.
 * @param [in] SoftwareTrigger If true a software trigger is generate to update PWM parameters.
 * @return success
 *        - FTM_PWM_STATUS_SUCCESS : Completed successfully.
 *        - FTM_PWM_STATUS_ERROR : Error occurred.
 */
Ftm_Pwm_Ip_StatusType Ftm_Pwm_Ip_UpdatePwmChannel(uint8 Instance,
                                                   uint8 Channel,
                                                   uint16 FirstEdge,
                                                   uint16 SecondEdge,
                                                   boolean SoftwareTrigger);

/*!
 * @brief This function will update the duty cycle of PWM output for multiple channels.
 *
 * @param [in] Instance The FTM peripheral instance number.
 * @param [in] NumberOfChannels The number of channels which should be updated.
 * @param [in] Channels The list of channels which should be updated.
 * @param [in] Duty The list of duty cycles for selected channels.
 * @param [in] SoftwareTrigger If true a software trigger is generate to update PWM parameters.
 * @return success
 *        - FTM_PWM_STATUS_SUCCESS : Completed successfully.
 *        - FTM_PWM_STATUS_ERROR : Error occurred.
 */
void Ftm_Pwm_Ip_FastUpdatePwmDuty(uint8 Instance,
                                  uint8 NumberOfChannels,
                                  const uint8 * Channels,
                                  const uint16 * Duty,
                                  boolean SoftwareTrigger);

/*!
 * @brief This function will update the new period in the frequency or
 * in the counter value into mode register which modify the period of PWM signal
 * on the Channel output
 *
 * @param [in] Instance The FTM peripheral instance number.
 * @param [in] NewValue The frequency or the counter value which will select with modified value for PWM signal.
 *                      If the type of update in the duty cycle, the newValue parameter must be value
 *                      between 1U and maximum is the frequency of the FTM counter.
 *                      If the type of update in ticks, the newValue parameter must be value between 1U and 0xFFFFU.
 * @param [in] SoftwareTrigger If true a software trigger is generate to update PWM parameters.
 * @return operation status
 *        - FTM_PWM_STATUS_SUCCESS : Completed successfully.
 *        - FTM_PWM_STATUS_ERROR : Error occurred.
 */
Ftm_Pwm_Ip_StatusType Ftm_Pwm_Ip_UpdatePwmPeriod(uint8 Instance,
                                                 uint32 NewValue,
                                                 boolean SoftwareTrigger);

/**
* @brief        This function performs the update of the SWOCTRL register on request to set/clear
*               output state of channel in idle state or output-forced
* @details      This function can be called from Pwm_Ftm_SetOutputToIdle, Pwm_Ftm_DeInit and
*               Pwm_Ftm_ForceOutputToZero functions
*
* @param[in]    Instance       FTM hardware module index
* @param[in]    Channel        FTM hardware channel index
* @param[in]    OutputState    PWM output level
* @param[in]    ActiveState    Activation state of the SW Output Control
*                              TRUE  - Enable SW Output Control
*                              FALSE - Disable SW Output Control
*
* @return       void
*
*/
void Ftm_Pwm_Ip_SwOutputControl(uint8 Instance,
                                uint8 Channel,
                                Ftm_Pwm_Ip_OutputStateType OutputState,
                                boolean ActiveState);
/**
* @brief        Ftm_Pwm_Ip_SyncUpdate
* @details      This function will allow synchronized loading
*               of the duty registers for all the channels of a given FTM module
*
* @param[in]    Instance  The FTM peripheral instance number.
*
* @return       void
*
*/
void Ftm_Pwm_Ip_SyncUpdate(uint8 Instance);

/**
* @brief        This function disables the user notifications
* @details      This function disables the user notifications for the corresponding type of notification
*
* @param[in]    Instance       FTM hardware module index
* @param[in]    NotifType      The type of notification
*
* @return       void
*
*/
void Ftm_Pwm_Ip_DisableNotification(uint8 Instance,
                                    Ftm_Pwm_Ip_NotifType NotifType);

/**
* @brief        This function enables the user notifications
* @details      This function enables the user notifications for the corresponding type of notification
*
* @param[in]    Instance       FTM hardware module index
* @param[in]    NotifType      The type of notification
*
* @return       void
*
*/
void Ftm_Pwm_Ip_EnableNotification(uint8 Instance,
                                   Ftm_Pwm_Ip_NotifType NotifType);

/**
* @brief        This function sets the value of the prescaler on all FTM modules
* @details      This function sets the prescaler depending on the value ePrescaler parameter.
*
* @param[in]    Instance         FTM hardware module index
* @param[in]    Prescaler        Prescaler values
*
* @return       void
*
*/
void Ftm_Pwm_Ip_SetClockMode(uint8 Instance,
                             Ftm_Pwm_Ip_PrescalerType Prescaler);

/**
* @brief        This function enabel/disabled counter reset by Pwm_SyncUpdate() call
*
* @param[in]    Instance      FTM hardware module index
* @param[in]    IsResetCnt    Reset counter or not
*
* @return       void
*
*/
void Ftm_Pwm_Ip_ResetCounter(uint8 Instance,
                             boolean IsResetCnt);

/*!
 * @brief This function will mask the output of the channels and at match events will be ignored
 * by the masked channels.
 *
 * @param [in] Instance The FTM peripheral instance number.
 * @param [in] ChannelsMask The mask which will select which channels will ignore match events.
 * @param [in] SoftwareTrigger If true a software trigger is generate to update PWM parameters.
 * @return success
 *        - FTM_PWM_STATUS_SUCCESS : Completed successfully.
 */
void Ftm_Pwm_Ip_MaskOutputChannels(uint8 Instance,
                                   uint32 ChannelsMask,
                                   boolean SoftwareTrigger);

/**
* @brief        This function sets the duty cycle for the specified PWM channel.
*
* @param[in]    Instance     The FTM peripheral instance number.
* @param[in]    Channel      The FTM peripheral channel number.
* @param[in]    DutyCycle    PWM duty cycle value [0-0x8000]
* @param[in]    SoftwareTrigger If true a software trigger is generate to update PWM parameters.
*
* @return       void
*
*/
void Ftm_Pwm_Ip_UpdatePwmDutyCycleChannel(uint8 Instance,
                                          uint8 Channel,
                                          uint16 DutyCycle,
                                          boolean SoftwareTrigger);

/**
* @brief        This function sets the duty cycle and period for the specified PWM channel.
*
* @param[in]    Instance        The FTM peripheral instance number.
* @param[in]    Channel         The FTM peripheral channel number.
* @param[in]    Period          The period will be updated
* @param[in]    DutyCycle       PWM duty cycle value [0-0x8000]
* @param[in]    SoftwareTrigger If true a software trigger is generate to update PWM parameters.
*
* @return       void
*
*/
void Ftm_Pwm_Ip_UpdatePwmPeriodAndDuty(uint8 Instance,
                                       uint8 Channel,
                                       uint16 Period,
                                       uint16 DutyCycle,
                                       boolean SoftwareTrigger);

/**
* @brief        This function used to get the current output state of the PWM channel
*
* @param[in]    Instance   FTM hardware module index
* @param[in]    Channel    FTM hardware channel index
*
* @return       Pwm_Ftm_OutputStateType
*               FTM_PWM_OUTPUT_STATE_LOW    The output pin is in LOW logic level
*               FTM_PWM_OUTPUT_STATE_HIGH   The output pin is in HIGH logic level
*
*/
Ftm_Pwm_Ip_OutputStateType Ftm_Pwm_Ip_GetOutputState(uint8 Instance,
                                                     uint8 Channel);

/**
* @brief        Put PWM channel based on FTM to target power mode.
* @details      This function will disable clock if target power mode is Low power, and enable clock
*               if target power mode is full power
*               - nPowerState value is either PWM_LOW_POWER or PWM_FULL_POWER
*               - the values associated to either types are configured by tooling and the physical values
*                  associated are written to hardware registry.
*
* @param[in]    Instance         FTM hardware module index
* @param[in]    PowerState       Target mode value
*
* @return       none
*
*
*
*/
void Ftm_Pwm_Ip_SetPowerState(uint8 Instance,
                              Ftm_Pwm_Ip_PowerStateType PowerState);

/**
* @brief        This function read the duty cycle value from the duty cycle array
*               and returns this value.
*
* @param[in]    Instance         FTM hardware module index
* @param[in]    Channel          FTM hardware channel index
*
* @return       uint16           Duty cycle value
*/
uint16 Ftm_Pwm_Ip_GetChannelState(uint8 Instance,
                                  uint8 Channel);

/**
* @brief        This function set phase shift value and also force duty cycle to 50%
* @details      In order to have Phase-Shifted Full-Bridge controller, Pwm_SetPhaseShift is introduced.
*               This function bases on FTM Combine mode with C(n) and C(n+1) combine to generate leading
*               edge and trailing edge. Pwm_SetPhaseShift allows to set both phase shift value and period,
*               the duty value is fixed to 50%.
*
* @param[in]    Instance         FTM hardware module index
* @param[in]    Channel          FTM hardware channel index
* @param[in]    Period           PWM signal period value
* @param[in]    PhaseShift       Phase shift value
* @param[in]    SoftwareTrigger  Buffer value be loaded or not
*
* @return       void
*
*/
void Ftm_Pwm_Ip_SetPhaseShift(uint8 Instance,
                              uint8 Channel,
                              uint16 Period,
                              uint16 PhaseShift,
                              boolean SoftwareTrigger);

/**
* @brief        This function set phase shift and duty cycle value (as immediate or synchronized base on API parameter SyncUpdate)
*
* @details      Ftm_Pwm_Ip_SetDutyPhaseShift allows to set both phase shift and duty cycle value,
*               The phase shift is the offset of the leading edge of the signal in respect to period starting point.
*
* @param[in]    Instance       FTM hardware module index
* @param[in]    Channel        FTM hardware channel index
* @param[in]    DutyCycle      Pwm duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    PhaseShift     Phase shift value (in ticks)
* @param[in]    SyncUpdate     TRUE  Set the phase shift and duty cycle value base on the synchronization when calling Pwm_SyncUpdate.
*                              FALSE Set phase shift and duty cycle value immediately
*
* @return       void
*
*/
void Ftm_Pwm_Ip_SetDutyPhaseShift(uint8 Instance,
                                  uint8 Channel,
                                  uint16 DutyCycle,
                                  uint16 PhaseShift,
                                  boolean SyncUpdate);

/*!
 * @brief This function will unmask the output of the channels and at match events will be ignored
 * by the masked channels.
 *
 * @param [in] Instance The FTM peripheral instance number.
 * @param [in] ChannelsMask The mask which will select which channels will ignore match events.
 * @param [in] SoftwareTrigger If true a software trigger is generate to update PWM parameters.
 * @return success
 *        - FTM_PWM_STATUS_SUCCESS : Completed successfully.
 */
void Ftm_Pwm_Ip_UnMaskOutputChannels(uint8 Instance,
                                     uint32 ChannelsMask,
                                     boolean SoftwareTrigger);

/**
* @brief        This function enables trigger generation for specific source
* @details      Corresponding bits with trigger source as bellow:
*                   Bit 0   Channel 2 Trigger Enable
*                   Bit 1   Channel 3 Trigger Enable
*                   Bit 2   Channel 4 Trigger Enable
*                   Bit 3   Channel 5 Trigger Enable
*                   Bit 4   Channel 0 Trigger Enable
*                   Bit 5   Channel 1 Trigger Enable
*                   Bit 6   Initialization Trigger Enable
*
* @param        Instance         FTM hardware module index
*               TriggerMask      Bit mask will be clear for FTM_EXTTRIG.
*
* @return       void
*
*/
void  Ftm_Pwm_Ip_EnableTrigger(uint8 Instance,
                               uint32 TriggerMask);

/**
* @brief        This function disables trigger generation for specific source
* @details      Corresponding bits with trigger source as bellow:
*                   Bit 0   Channel 2 Trigger Enable
*                   Bit 1   Channel 3 Trigger Enable
*                   Bit 2   Channel 4 Trigger Enable
*                   Bit 3   Channel 5 Trigger Enable
*                   Bit 4   Channel 0 Trigger Enable
*                   Bit 5   Channel 1 Trigger Enable
*                   Bit 6   Initialization Trigger Enable
*
* @param        Instance         FTM hardware module index
*               TriggerMask      Bit mask will be clear for FTM_EXTTRIG.
*
* @return       void
*
*/
void  Ftm_Pwm_Ip_DisableTrigger(uint8 Instance,
                                uint32 TriggerMask);

/*!
 * @brief This function is used to update the deadtime at runtime for Pwm channels.
 *
 * @param[in]  Instance     The FTM peripheral instance number.
 * @param[in]  Channel      The FTM hardware channel index
 * @param [in] DeadTimeVal  Deadtime value
 *
 * @return void
 */
void Ftm_Pwm_Ip_SetChannelDeadTime(uint8 Instance,
                                   uint8 Channel,
                                   uint16 DeadTimeVal);


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_PWM_IP_H */
