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

#ifndef PWM_IPW_H
#define PWM_IPW_H

/**
*   @file       Pwm_Ipw.h
*
*   @internal
*   @addtogroup pwm_driver Pwm Driver
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Pwm_Ipw_Types.h"

#include "Pwm.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define PWM_IPW_VENDOR_ID                         43
#define PWM_IPW_AR_RELEASE_MAJOR_VERSION          4
#define PWM_IPW_AR_RELEASE_MINOR_VERSION          7
#define PWM_IPW_AR_RELEASE_REVISION_VERSION       0
#define PWM_IPW_SW_MAJOR_VERSION                  2
#define PWM_IPW_SW_MINOR_VERSION                  0
#define PWM_IPW_SW_PATCH_VERSION                  0

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if header file and Pwm_Ipw_Types header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID != PWM_IPW_TYPES_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw.h and Pwm_Ipw_Types.h are different."
#endif

/* Check if header file and Pwm_Ipw_Types header file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.h and Pwm_Ipw_Types.h are different."
#endif

/* Check if header file and Pwm_Ipw_Types header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION != PWM_IPW_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION != PWM_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.h and Pwm_Ipw_Types.h are different."
#endif



/* Check if header file and Pwm header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID != PWM_VENDOR_ID)
    #error "Pwm_Ipw.h and Pwm.h have different vendor ids"
#endif

/* Check if header file and Pwm header file are of the same AUTOSAR version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.h and Pwm.h are different"
#endif

/* Check if header file and Pwm header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.h and Pwm.h are different"
#endif

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"


/**
* @brief        Pwm_Ipw_Init
* @details      This function call the supported IP initialization functions.
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_Init(const Pwm_IpwChannelConfigType * const IpConfig);

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm driver Autosar independent and IP dependent initialization function.
* @details      This Pwm_Ipw_InitInstance is called once for each channel in the used configuration.
*               It determines the type of the HW channel (e.g. Ftm,etc...) and calls the
*               appropriate IP function in order to initializes the hardware timer.
*
* @param[in]    IpConfig    Pointer to the channel configuration structure dependent by platform
*
* @return       void
*
*/
void Pwm_Ipw_InitInstance(const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_HW_INSTANCE_USED == STD_ON */


#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief        Pwm_Ipw_DeInit
* @details      This function call the supported IP de-initialization functions.
*
* @param[in]    IpConfig            Pointer to PWM top configuration structure
* @param[in]    ChannelIdleState    The state of the channel output in idle mode
*
* @return       void
*
*/
void Pwm_Ipw_DeInit(const Pwm_IpwChannelConfigType * const IpConfig, Pwm_OutputStateType ChannelIdleState);

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm_Ipw_DeInitInstance
* @details      This function call the supported IP de-initialization functions.
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_DeInitInstance(const Pwm_IpwInstanceConfigType * const IpConfig);
#endif

#endif /* PWM_DE_INIT_API */


#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetDutyCycle
* @details      This function will call SetDutyCycle function for the corresponding IP of PwmChannel
*
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
Std_ReturnType Pwm_Ipw_SetDutyCycle(uint16                           DutyCycle,
                                    const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_SET_DUTY_CYCLE_API */


#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetPeriodAndDuty
* @details      This function will call SetPeriodAndDuty function for the corresponding IP of PwmChannel
*
* @param[in]    Period         Period value for this channel
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetPeriodAndDuty(Pwm_PeriodType                   Period,
                              uint16                           DutyCycle,
                              const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetOutputToIdle
* @details      This function will call SetOutputToIdle function for the corresponding IP of PwmChannel
*
* @param[in]    IdleState      The state of output channel when entering Idle mode
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetOutputToIdle(const Pwm_OutputStateType IdleState, const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        Pwm_Ipw_GetOutputState
* @details      This function will call GetOutputState function for the corresponding IP of PwmChannel
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Pwm_OutputStateType
*
*/
Pwm_OutputStateType Pwm_Ipw_GetOutputState(const Pwm_IpwChannelConfigType * const IpConfig);

#endif /* PWM_GET_OUTPUT_STATE_API */


#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_DisableNotification
* @details      This function will call DisableNotification function for the corresponding IP of PwmChannel
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_DisableNotification(const Pwm_IpwChannelConfigType * const IpConfig);

#endif /* PWM_NOTIFICATION_SUPPORTED */


#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_EnableNotification
* @details      This function will call EnableNotification function for the corresponding IP of PwmChannel
*
* @param[in]    Notification   Notification edge type to be enabled
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_EnableNotification(Pwm_EdgeNotificationType         Notification,
                                const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_NOTIFICATION_SUPPORTED */

#if (PWM_RELOAD_NOTIF_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_DisableReloadNotification
* @details      This function will call DisableReloadNotification function for the corresponding IP of a given FTM module
*
* @param[in]    ModuleId      Instance Id of FTM
*                              Ex:  PWM_FTM_INSTANCE_0
*                                   PWM_FTM_INSTANCE_1
*                                   ....
*
* @return       void
*
*/
void Pwm_Ipw_DisableReloadNotification(uint8 ModuleId);
#endif /* PWM_RELOAD_NOTIF_SUPPORTED */

#if (PWM_RELOAD_NOTIF_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_EnableReloadNotification
* @details      This function will call EnableReloadNotification function for the corresponding IP of a given FTM module
*
* @param[in]    ModuleId      Instance Id of FTM
*                              Ex:  PWM_FTM_INSTANCE_0
*                                   PWM_FTM_INSTANCE_1
*                                   ....
*
* @return       void
*
*/
void Pwm_Ipw_EnableReloadNotification(uint8 ModuleId);
#endif /* PWM_RELOAD_NOTIF_SUPPORTED */

#if (PWM_FAULT_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_DisableFaultNotification
* @details      This function will call DisableFaultNotification function for the corresponding IP of a given FTM module
*
* @param[in]    ModuleId      Instance Id of FTM
*                              Ex:  PWM_FTM_INSTANCE_0
*                                   PWM_FTM_INSTANCE_1
*                                   ....
*
* @return       void
*
*/
void Pwm_Ipw_DisableFaultNotification(uint8 ModuleId);
#endif /* PWM_FAULT_SUPPORTED */

#if (PWM_FAULT_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_EnableFaultNotification
* @details      This function will call EnableFaultNotification function for the corresponding IP of a given FTM module
*
* @param[in]    ModuleId      Instance Id of FTM
*                              Ex:  PWM_FTM_INSTANCE_0
*                                   PWM_FTM_INSTANCE_1
*                                   ....
*
* @return       void
*
*/
void Pwm_Ipw_EnableFaultNotification(uint8 ModuleId);
#endif /* PWM_FAULT_SUPPORTED */

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/**
* @brief        Pwm_Ipw_GetChannelState
* @details      This function will call GetChannelState function for the corresponding IP of PwmChannel
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       uint16
*
*/
uint16 Pwm_Ipw_GetChannelState(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_GET_CHANNEL_STATE_API */


#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
/**
* @brief        Pwm_Ipw_ForceOutputToZero
* @details      This function will call ForceOutputToZero function only if then channel is a
*               FTM channel
*
* @param[in]    Force          Flag to state if force to zero should be applied or not
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_ForceOutputToZero(boolean                        Force,
                               const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_FORCE_OUTPUT_TO_ZERO_API */


#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        Pwm_Ipw_SetClockModeChannel
* @details      This function will call SetClockMode function of all configured hardware channels.
*
* @param[in]    Prescaler      Pre-scaler type
* @param[in]    IpConfig       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetClockModeChannel(Pwm_PrescalerType              Prescaler,
                                 const Pwm_IpwChannelConfigType * const IpConfig);

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm_Ipw_SetClockModeInstance
* @details      This function will call SetClockMode function of all configured hardware modules.
*
* @param[in]    Prescaler      Pre-scaler type
* @param[in]    IpConfig       Pointer to PWM instance configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetClockModeInstance(Pwm_PrescalerType              Prescaler,
                                  const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_HW_INSTANCE_USED */
#endif /* PWM_SET_CLOCK_MODE_API */


#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief        
* @details      This function is used to update the deadtime at runtime for Pwm channels.
*
* @param[in]    DeadTimeTicks       Dead Time value in ticks unit.
* @param[in]    IpConfig            Pointer to PWM top configuration structure
*
* @return       void
*
*
*/
void Pwm_Ipw_SetChannelDeadTime(uint16                           DeadTimeTicks,
                                const Pwm_IpwChannelConfigType * const IpConfig);
#endif /*PWM_SET_CHANNEL_DEAD_TIME_API*/
                                
                                
#if (PWM_ENABLE_TRIGGER_API == STD_ON)
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
* @param[in]        TriggerHostId  FTM module ID
* @param[in]        TriggerMask    Bit mask will be clear for FTM_EXTTRIG.
* @param[in]        IpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*/
void Pwm_Ipw_EnableTrigger(uint8                             TriggerHostId,
                           uint16                            TriggerMask,
                           const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_ENABLE_TRIGGER_API */


#if (PWM_DISABLE_TRIGGER_API == STD_ON)
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
* @param[in]        TriggerHostId  FTM module ID
* @param[in]        TriggerMask    Bit mask will be clear for FTM_EXTTRIG.
* @param[in]        IpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*/
void Pwm_Ipw_DisableTrigger(uint8                             TriggerHostId,
                            uint16                            TriggerMask,
                            const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_DISABLE_TRIGGER_API */


#if (PWM_RESET_COUNTER_API == STD_ON)
/**
* @brief        Pwm_Ipw_ResetCounterEnable
* @details      This function enables counter reset by Pwm_SyncUpdate() call
*
* @param[in]    ModuleId      FTM module ID
* @param[in]    IpConfig      Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_ResetCounterEnable(uint8                             ModuleId,
                                const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_RESET_COUNTER_API */


#if (PWM_RESET_COUNTER_API == STD_ON)
/**
* @brief        Pwm_Ipw_ResetCounterDisable
* @details      This function disables counter reset by Pwm_SyncUpdate() call
*
* @param[in]    ModuleId      FTM module ID
* @param[in]    IpConfig      Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_ResetCounterDisable(uint8                             ModuleId,
                                 const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_RESET_COUNTER_API */


#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function force channels output to their inactive state
* @details      Corresponding bits with channel will be masked:
*                   Bit 0   Channel 0 Output Mask
*                   Bit 1   Channel 1 Output Mask
*                   Bit 2   Channel 2 Output Mask
*                   Bit 3   Channel 3 Output Mask
*                   Bit 4   Channel 4 Output Mask
*                   Bit 5   Channel 5 Output Mask
*
* @param[in]        ModuleId      FTM module ID
* @param[in]        ChannelMask   Bit mask will be set for FTM_OUTMASK.
* @param[in]        IpConfig      Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_MaskOutputs(uint8                             ModuleId,
                         uint8                             ChannelMask,
                         const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_ENABLE_MASKING_OPERATIONS */


#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function puts channels output to normal operation state
* @details      Corresponding bits with channel will be masked:
*                   Bit 0   Channel 0 Output Mask
*                   Bit 1   Channel 1 Output Mask
*                   Bit 2   Channel 2 Output Mask
*                   Bit 3   Channel 3 Output Mask
*                   Bit 4   Channel 4 Output Mask
*                   Bit 5   Channel 5 Output Mask
*
* @param[in]        ModuleId      FTM module ID
* @param[in]        ChannelMask   Bit mask will be set for FTM_OUTMASK.
* @param[in]        IpConfig      Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_UnMaskOutputs(uint8                            ModuleId,
                           uint8                            ChannelMask,
                           const Pwm_IpwInstanceConfigType * const IpConfig);
#endif /* PWM_ENABLE_MASKING_OPERATIONS */


#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
/**
* @brief        This function set phase shift and duty cycle value (as immediate or synchronized base on API parameter SyncUpdate)
*
* @details      Pwm_Ipw_SetDutyPhaseShift allows to set both phase shift and duty cycle value,
*               The phase shift is the offset of the leading edge of the signal in respect to period starting point.
*
* @param[in]    DutyCycle               Pwm duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    PhaseShift              Phase shift value (in ticks)
* @param[in]    IpConfig                Pointer to PWM top configuration structure
* @param[in]    SyncUpdate              Update the value immediately or not
*                                       TRUE   Set the phase shift and duty cycle value base on the synchronization when calling Pwm_SyncUpdate.
*                                       FALSE  Set phase shift and duty cycle value immediately
*
* @return       void
*
*/
void Pwm_Ipw_SetDutyPhaseShift(uint16                           DutyCycle,
                               uint16                           PhaseShift,
                               const Pwm_IpwChannelConfigType * const IpConfig,
                               boolean                          SyncUpdate);
#endif /*PWM_SET_DUTY_PHASE_SHIFT_API*/


#if ((PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON) && (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_SetDutyCycle_NoUpdate
* @details      This function will call Ftm_Pwm_Ip_SetDutyCycle (synchronous mode) if
*               the given channel is a FTM channel
*
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
Std_ReturnType Pwm_Ipw_SetDutyCycle_NoUpdate(uint16                           DutyCycle,
                                             const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SET_DUTY_CYCLE_NO_UPDATE_API */


#if ((PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON) && (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_SetPeriodAndDuty_NoUpdate
* @details      This function will call Ftm_Pwm_Ip_SetPeriodAndDuty (synchronous mode)
*               if the given channel is a FTM channel
*
* @param[in]    Period         Period value for this channel
* @param[in]    DutyCycle      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetPeriodAndDuty_NoUpdate(Pwm_PeriodType                   Period,
                                       uint16                           DutyCycle,
                                       const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API */


#if ((PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON) && (PWM_SYNC_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_SyncUpdate
* @details      This function will call Ftm_Pwm_Ip_SyncUpdate to allow synchronized loading
*               of the duty registers for all the channels of a given FTM module
*
* @param[in]    ModuleId      Instance Id of FTM
*                              Ex:  PWM_FTM_INSTANCE_0
*                                   PWM_FTM_INSTANCE_1
*                                   ....
*
* @return       void
*
*/
void Pwm_Ipw_SyncUpdate(uint8 ModuleId);
#endif /* PWM_UPDATE_DUTY_SYNCHRONOUS && PWM_SYNC_UPDATE_API */


#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateDeadTime
* @details      This function will check validate operation mode of current channel to use
*               trigger delay feature.
*
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        Current channel mode is invalid
*               E_OK            Current channel mode is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateDeadTime(const Pwm_IpwChannelConfigType * const IpConfig);

/**
* @brief        Pwm_Ipw_ValidateParamDeadTime
* @details      This function will check validate operation mode of current channel to use
*               trigger delay feature.
*
* @param[in]    DeadTimeTicks      Dead Time value in ticks unit that need to be verified.
* @param[in]    IpConfig           Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        Current channel mode is invalid
*               E_OK            Current channel mode is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateParamDeadTime(uint16                           DeadTimeTicks,
                                             const Pwm_IpwChannelConfigType * const IpConfig);

#endif /* ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)) */


#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_NOTIFICATION_SUPPORTED == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateNotification
* @details      This function will check given channel with Notification supported
*
* @param[in]    channelNumber  PWM logical channel ID in top configuration structure
* @param[in]    Notification   Notification edge type
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK      Notification handler is not valid
*               E_OK          Notification handler is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateNotification(Pwm_EdgeNotificationType       Notification,
                                            const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_DEV_ERROR_DETECT && PWM_NOTIFICATION_SUPPORTED */


#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateForceOutputToZero
* @details      This function will check validate of force zero output feature
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @retval       Std_ReturnType
*               E_NOT_OK        Force zero output not support
*               E_OK            Force zero output is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateForceOutputToZero(const Pwm_IpwChannelConfigType * const IpConfig);

#endif  /* ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)) */


#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateSetPhaseShift
* @details      This function will check given channel with phase shift supported
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        Phase shift is not supported this channel
*               E_OK            Phase shift is supported this channel
*
*/
Std_ReturnType Pwm_Ipw_ValidateSetPhaseShift(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_DEV_ERROR_DETECT && PWM_SET_DUTY_PHASE_SHIFT_API */


#if ((PWM_DEV_ERROR_DETECT == STD_ON) && (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateSetDutyPhaseShiftParams
* @details      This function will check phase shift and duty cycle value
*
* @param[in]    PhaseShift   Phase shift value
* @param[in]    DutyCycle    Duty Cycle value
* @param[in]    IpConfig     Pointer to PWM top configuration structure
*
* @return       Std_ReturnType  
*               E_NOT_OK    Phase shift or duty cycle value is invalid
*               E_OK        Phase shift and duty cycle is valid
*
*/
Std_ReturnType Pwm_Ipw_ValidateSetDutyPhaseShiftParams(uint16                           PhaseShift,
                                                       uint16                           DutyCycle,
                                                       const Pwm_IpwChannelConfigType * const IpConfig);
#endif


#if ((PWM_DEV_ERROR_DETECT == STD_ON) && ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || (PWM_SYNC_UPDATE_API == STD_ON)))
/**
* @brief        Pwm_Ipw_ValidateUpdateSynchronous
* @details      This function will check given channel with synchronization supported
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType  
*               E_NOT_OK   synchronization is not supported this channel
*               E_OK       synchronization is supported this channel
*
*/
Std_ReturnType Pwm_Ipw_ValidateUpdateSynchronous(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_DEV_ERROR_DETECT && (PWM_SET_DUTY_CYCLE_NO_UPDATE_API || PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API) */


#if ((PWM_DEV_ERROR_DETECT == STD_ON) && ((PWM_ENABLE_TRIGGER_API == STD_ON) || (PWM_DISABLE_TRIGGER_API == STD_ON)))
/**
* @brief        This function will check bit mask.
* @details      Bit mask will be process at lower layer has to be compatible with hardware register
*
* @param[in]    TriggerMask    Trigger mask value
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       Std_ReturnType  
*               E_NOT_OK  Bit mask is not compatible.
*               E_OK      Bit mask is compatible.
*/
Std_ReturnType Pwm_Ipw_ValidateTriggerMask(uint32                            TriggerMask,
                                            const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_DEV_ERROR_DETECT && (PWM_ENABLE_TRIGGER_API || PWM_DISABLE_TRIGGER_API) */


#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON))
#if (defined(PWM_SETOUTPUTTOIDLE_PLAUSABILITY) && (PWM_SETOUTPUTTOIDLE_PLAUSABILITY == STD_ON))
/**
* @brief            Pwm_Ipw_ValidateSetOutPutToIdle
* @details          This function will check the validation when calling the Pwm_SetOutputToIdle api.
*
* @param[in]        IpConfig        Pointer to PWM top configuration structure
*
* @retVal           RetVal          E_NOT_OK  Set output to idle is not valid
                                    E_OK      Set output to idle is valid
*/
Std_ReturnType Pwm_Ipw_ValidateSetOutPutToIdle(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* (defined(PWM_SETOUTPUTTOIDLE_PLAUSABILITY) && (PWM_SETOUTPUTTOIDLE_PLAUSABILITY == STD_ON)) */
#endif /* (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON) */


#if (PWM_DEV_ERROR_DETECT == STD_ON)
    #if ((PWM_SYNC_UPDATE_API            == STD_ON) || \
         (PWM_ENABLE_TRIGGER_API         == STD_ON) || \
         (PWM_DISABLE_TRIGGER_API        == STD_ON) || \
         (PWM_RESET_COUNTER_API          == STD_ON) || \
         (PWM_ENABLE_MASKING_OPERATIONS  == STD_ON) || \
         (PWM_RELOAD_NOTIF_SUPPORTED     == STD_ON) || \
         (PWM_FAULT_SUPPORTED            == STD_ON))
/**
* @brief        Pwm_Ipw_ValidateModuleId
* @details      Validate the module id.
*               In order to be valid, the module id should less than number of module that supported
*
* @param[in]    ModuleId        The Id of the ipv module
*
* @return       Std_ReturnType
*               E_NOT_OK        The ModuleId is invalid
*               E_OK            The ModuleId is valid
*
*/     
Std_ReturnType  Pwm_Ipw_ValidateModuleId(uint8 ModuleId);
    #endif
#endif


#if (PWM_MAX_PERIOD_PLAUSABILITY == STD_ON)
    #if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
/**
* @brief        Pwm_Ipw_GetMaxPeriodValue
* @details      Get the maximum Period in specific hardware module.
*
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       uint32
*
*/  
uint32 Pwm_Ipw_GetMaxPeriodValue(const Pwm_IpwChannelConfigType * const IpConfig);

    #endif /* ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON)) */
#endif


#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_ValidateIdleState
* @details      This function will call ValidateIdleState function of all configured hardware modules
*
* @param[in]    IpConfig        Pointer to PWM top configuration structure
*
* @return       Std_ReturnType
*               E_NOT_OK        The Idle state is not ready
*               E_OK            The Idle state is ready
*
*/
Std_ReturnType Pwm_Ipw_ValidateIdleState(const Pwm_IpwChannelConfigType * const IpConfig);
#endif /* PWM_POWER_STATE_SUPPORTED */


#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_SetPowerStateChannel
* @details      This function will call SetPowerState function of all configured hardware channels
*
* @param[in]    PowerState     Target power mode
* @param[in]    IpConfig       Pointer to PWM top configuration structure
*
* @return       void
*
*/
void Pwm_Ipw_SetPowerStateChannel(Pwm_PowerStateType                  PowerState,
                                  const Pwm_IpwChannelConfigType * const IpConfig);

#if (PWM_HW_INSTANCE_USED == STD_ON)
/**
* @brief        Pwm_Ipw_SetPowerStateInstance
* @details      This function will call SetPowerState function of all configured hardware modules
*
* @param[in]    IpConfig       Pointer to PWM top configuration structure
* @param[in]    PowerState     Target power mode
*
* @return       void
*
*/
void Pwm_Ipw_SetPowerStateInstance(const Pwm_IpwInstanceConfigType * const IpConfig,
                                   Pwm_PowerStateType       PowerState);
#endif /* PWM_HW_INSTANCE_USED */
#endif /* PWM_POWER_STATE_SUPPORTED */


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PWM_IPW_H */
