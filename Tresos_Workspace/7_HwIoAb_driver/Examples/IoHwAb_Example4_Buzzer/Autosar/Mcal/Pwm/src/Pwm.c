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

/**
*   @file           Pwm.c
*   @implements     Pwm.c_Artifact
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
#include "Pwm_Notif.h"
#include "Pwm_Ipw.h"
#include "SchM_Pwm.h"

#if ((PWM_POWER_STATE_SUPPORTED == STD_ON) || (PWM_DEV_ERROR_DETECT == STD_ON))
    #include "Det.h"
#endif

#if (PWM_MULTICORE_ENABLED == STD_ON)
    #include "OsIf.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_VENDOR_ID_C                         43
#define PWM_AR_RELEASE_MAJOR_VERSION_C          4
#define PWM_AR_RELEASE_MINOR_VERSION_C          7
#define PWM_AR_RELEASE_REVISION_VERSION_C       0
#define PWM_SW_MAJOR_VERSION_C                  2
#define PWM_SW_MINOR_VERSION_C                  0
#define PWM_SW_PATCH_VERSION_C                  0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm.c and Std_Types.h are different."
    #endif

    #if ((PWM_DEV_ERROR_DETECT == STD_ON) || (PWM_POWER_STATE_SUPPORTED == STD_ON))
        /* Check if source file and DET header file are of the same version */
        #if ((PWM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (PWM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR version numbers of Pwm.c and Det.h are different."
        #endif
    #endif

    /* Check if source file and SchM_Pwm.h header file are of the same version */
    #if ((PWM_AR_RELEASE_MAJOR_VERSION_C != SCHM_PWM_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_AR_RELEASE_MINOR_VERSION_C != SCHM_PWM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR version numbers of Pwm.c and SchM_Pwm.h are different."
    #endif

    #if (PWM_MULTICORE_ENABLED == STD_ON)
        /* Check if source file and OsIf header file are of the same version */
        #if ((PWM_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
             (PWM_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR version numbers of Pwm.c and OsIf.h are different."
        #endif
    #endif
#endif

/* Check if source file and PWM header file are of the same vendor */
#if (PWM_VENDOR_ID_C != PWM_VENDOR_ID)
    #error "Vendor IDs of Pwm.c and Pwm.h are different."
#endif

/* Check if source file and PWM header file are of the same AUTOSAR version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION_C    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION_C    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm.c and Pwm.h are different."
#endif

/* Check if source file and PWM header file are of the same Software version */
#if ((PWM_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION)  || \
     (PWM_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION)  || \
     (PWM_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm.c and Pwm.h are different."
#endif

/* Check if source file and Pwm_Ipw.h file are of the same vendor */
#if (PWM_VENDOR_ID_C != PWM_IPW_VENDOR_ID)
    #error "Vendor IDs of Pwm.c and Pwm_Ipw.h are different."
#endif

/* Check if source file and Pwm_Ipw.h file are of the same AUTOSAR version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm.c and Pwm_Ipw.h are different."
#endif

/* Check if source file and Pwm_Ipw.h file are of the same Software version */
#if ((PWM_SW_MAJOR_VERSION_C != PWM_IPW_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION_C != PWM_IPW_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION_C != PWM_IPW_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm.c and Pwm_Ipw.h are different."
#endif

/* Check if source file and Pwm_Notif.h file are of the same vendor */
#if (PWM_VENDOR_ID_C != PWM_NOTIF_VENDOR_ID)
    #error "Vendor IDs of Pwm.c and Pwm_Notif.h are different."
#endif

/* Check if source file and Pwm_Notif.h file are of the same AUTOSAR version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION_C    != PWM_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION_C    != PWM_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION_C != PWM_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm.c and Pwm_Notif.h are different."
#endif

/* Check if source file and Pwm_Notif.h file are of the same Software version */
#if ((PWM_SW_MAJOR_VERSION_C != PWM_NOTIF_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION_C != PWM_NOTIF_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION_C != PWM_NOTIF_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm.c and Pwm_Notif.h are different."
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#if ((PWM_VALIDATE_GLOBAL_CONFIG_CALL  == STD_ON) || (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON))
/**
* @brief        Enumeration containing the possible states of the PWM driver
*/
typedef enum
{
    /** @brief  Pwm driver is not initialized */
    PWM_STATE_UNINIT = 0x00U,
    /** @brief  Pwm driver is initialized and running */
    PWM_STATE_IDLE   = 0x01U
} Pwm_GlobalStateType;
#endif

/**
* @brief        State structure for the PWM driver
*/
typedef struct
{
#if ((PWM_VALIDATE_GLOBAL_CONFIG_CALL  == STD_ON) || (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON))
    /** @brief       Variable storing the current state of the Pwm driver */
    Pwm_GlobalStateType            PwmDriverState;
#endif
    /** @brief        Pointer to the top level configuration structure - valid only when the driver is in the initialized state */
    const Pwm_ConfigType         * PwmConfig;
    /** @brief       Variable storing the current power state of the PWM driver */
    Pwm_PowerStateType             PwmCurrentPowerState;
    /** @brief       Variable storing the target power state of the PWM driver */
    Pwm_PowerStateType             PwmTargetPowerState;
    /** @brief       Array holding all channel configured for this partition */
    const Pwm_ChannelConfigType  * PwmChannelConfigs[PWM_CONFIG_LOGIC_CHANNELS];
    /** @brief       Array holding all channel configured for this partition */
    boolean                        PwmChannelIdleState[PWM_CONFIG_LOGIC_CHANNELS];
} Pwm_DriverStateType;

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (PWM_MULTICORE_ENABLED == STD_ON)
    #define Pwm_GetCoreID()           (uint32)OsIf_GetCoreID()
#else
    #define Pwm_GetCoreID()           (uint32)0U
#endif

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define PWM_START_SEC_VAR_INIT_UNSPECIFIED

#include "Pwm_MemMap.h"


#if (PWM_MULTICORE_ENABLED == STD_ON)
    static Pwm_DriverStateType Pwm_aState[PWM_MAX_PARTITION_NO] = PWM_DRIVER_STATE_INITIALIZATION;
#else
    static Pwm_DriverStateType Pwm_aState[1U] = PWM_DRIVER_STATE_INITIALIZATION;
#endif

#define PWM_STOP_SEC_VAR_INIT_UNSPECIFIED

#include "Pwm_MemMap.h"



#if (PWM_POWER_STATE_SUPPORTED == STD_ON)

#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED

#include "Pwm_MemMap.h"

/**
* @brief        Variable storing the current power state of the PWM driver
*
*/
static Pwm_PowerStateType Pwm_eCurrentPowerState[PWM_MAX_PARTITION_NO];

/**
* @brief        Variable storing the target power state of the PWM driver
*
*/
static Pwm_PowerStateType Pwm_eTargetPowerState[PWM_MAX_PARTITION_NO];

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED

#include "Pwm_MemMap.h"

#endif /* PWM_POWER_STATE_SUPPORTED */

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#if (PWM_PRECOMPILE_SUPPORT == STD_ON)

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Pwm_MemMap.h"

#if (PWM_MULTICORE_ENABLED == STD_ON)
extern const Pwm_ConfigType * const Pwm_Config[PWM_MAX_PARTITION_NO];
#else
extern const Pwm_ConfigType Pwm_Config;
#endif

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Pwm_MemMap.h"

#endif /* PWM_PRECOMPILE_SUPPORT */

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE

#include "Pwm_MemMap.h"

#if ((PWM_SET_DUTY_CYCLE_API                == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API           == STD_ON) || \
     (PWM_SET_OUTPUT_TO_IDLE_API            == STD_ON) || \
     (PWM_GET_OUTPUT_STATE_API              == STD_ON) || \
     (PWM_GET_CHANNEL_STATE_API             == STD_ON) || \
     (PWM_FORCE_OUTPUT_TO_ZERO_API          == STD_ON) || \
     (PWM_NOTIFICATION_SUPPORTED            == STD_ON) || \
     (PWM_SET_COUNTER_BUS_API               == STD_ON) || \
     (PWM_SET_CHANNEL_OUTPUT_API            == STD_ON) || \
     (PWM_SET_TRIGGER_DELAY_API             == STD_ON) || \
     (PWM_SET_CHANNEL_FORCE_OUT_API         == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_CYCLE_NO_UPDATE_API      == STD_ON) || \
     (PWM_SYNC_UPDATE_API                   == STD_ON) || \
     (PWM_SET_CHANNEL_DEAD_TIME_API         == STD_ON) || \
     (PWM_FAST_UPDATE_API                   == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API          == STD_ON))
/*=============================================================================================*/
static inline uint8 Pwm_GetPartitionChannelIdx(uint32              CoreId,
                                               Pwm_ChannelType     ChannelNumber);
#endif


#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
/*=============================================================================================*/
static Std_ReturnType Pwm_ValidateGlobalConfigCall(uint32   CoreId,
                                                   uint8    ServiceId);


/*=============================================================================================*/
static inline void Pwm_EndValidateGlobalConfigCall(uint32           CoreId,
                                                   Std_ReturnType   ValidCall,
                                                   uint8            ServiceId);
#endif /* PWM_VALIDATE_GLOBAL_CONFIG_CALL */


#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
#if ((PWM_SET_DUTY_CYCLE_API                == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API           == STD_ON) || \
     (PWM_SET_OUTPUT_TO_IDLE_API            == STD_ON) || \
     (PWM_GET_OUTPUT_STATE_API              == STD_ON) || \
     (PWM_GET_CHANNEL_STATE_API             == STD_ON) || \
     (PWM_FORCE_OUTPUT_TO_ZERO_API          == STD_ON) || \
     (PWM_NOTIFICATION_SUPPORTED            == STD_ON) || \
     (PWM_SET_COUNTER_BUS_API               == STD_ON) || \
     (PWM_SET_CHANNEL_OUTPUT_API            == STD_ON) || \
     (PWM_SET_TRIGGER_DELAY_API             == STD_ON) || \
     (PWM_SET_CHANNEL_FORCE_OUT_API         == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_CYCLE_NO_UPDATE_API      == STD_ON) || \
     (PWM_SYNC_UPDATE_API                   == STD_ON) || \
     (PWM_SET_CHANNEL_DEAD_TIME_API         == STD_ON) || \
     (PWM_FAST_UPDATE_API                   == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API          == STD_ON))
/*=============================================================================================*/
static inline Std_ReturnType Pwm_ValidateChannelConfigCall(uint32              CoreId,
                                                           Pwm_ChannelType     ChannelNumber,
                                                           uint8               ServiceId);


/*=============================================================================================*/
static inline void Pwm_EndValidateChannelConfigCall(Pwm_ChannelType     ChannelNumber);
#endif
#endif /* PWM_VALIDATE_CHANNEL_CONFIG_CALL */


/*=============================================================================================*/
#if (PWM_PARAM_CHECK == STD_ON)

/*=============================================================================================*/
static inline Std_ReturnType Pwm_ValidateParamPtrInit(uint32                  CoreId,
                                                      const Pwm_ConfigType *  ConfigPtr);

/*=============================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON))
static inline Std_ReturnType Pwm_ValidateParamDuty(uint16   DutyCycle,
                                                   uint8    ServiceId);
#endif


/*=============================================================================================*/
#if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
static inline Std_ReturnType Pwm_ValidateParamsPeriodClass(uint32                CoreId,
                                                           Pwm_ChannelType       ChannelNumber,
                                                           Pwm_ChannelClassType  ChannelClass,
                                                           Pwm_PeriodType        Period,
                                                           uint8                 ServiceId);
#endif


/*=============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
static inline Std_ReturnType Pwm_ValidateParamNotification(uint32                      CoreId,
                                                           Pwm_ChannelType             ChannelNumber,
                                                           Pwm_EdgeNotificationType    Notification);
#endif


/*=============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateParamTriggerDelay(uint32           CoreId,
                                                           Pwm_ChannelType  ChannelNumber,
                                                           Pwm_PeriodType   TriggerDelay);
#endif


/*=============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateTriggerDelay(uint32            CoreId,
                                                      Pwm_ChannelType   ChannelNumber);
#endif


/*=============================================================================================*/
#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateDeadTime(uint32           CoreId,
                                                  Pwm_ChannelType  ChannelNumber);


static inline Std_ReturnType Pwm_ValidateParamDeadTime(uint32           CoreId,
                                                       Pwm_ChannelType  ChannelNumber,
                                                       Pwm_PeriodType   DeadTimeTicks);
#endif

/*=============================================================================================*/
#if ((PWM_SYNC_UPDATE_API            == STD_ON) || \
     (PWM_ENABLE_TRIGGER_API         == STD_ON) || \
     (PWM_DISABLE_TRIGGER_API        == STD_ON) || \
     (PWM_RESET_COUNTER_API          == STD_ON) || \
     (PWM_ENABLE_MASKING_OPERATIONS  == STD_ON) || \
     (PWM_FAST_UPDATE_API            == STD_ON) || \
     (PWM_RELOAD_NOTIF_SUPPORTED     == STD_ON) || \
     (PWM_FAULT_SUPPORTED            == STD_ON))
static inline Std_ReturnType Pwm_ValidateModuleId(uint8 ModuleId,
                                                  uint8 ServiceId);
#endif


/*=============================================================================================*/
#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateForceOutputToZero(uint32           CoreId,
                                                           Pwm_ChannelType  ChannelNumber);
#endif


/*=============================================================================================*/
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateCounterBus(uint32          CoreId,
                                                    Pwm_ChannelType ChannelNumber,
                                                    uint32          Bus);
#endif


/*=============================================================================================*/
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateSetChannelOutput(uint32            CoreId,
                                                          Pwm_ChannelType   ChannelNumber,
                                                          Pwm_StateType     State);
#endif


/*=============================================================================================*/
#if (PWM_SET_CHANNEL_FORCE_OUT_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateSetChannelForceOut(uint32                  CoreId,
                                                            Pwm_ChannelType         ChannelNumber,
                                                            Pwm_ForceOutStateType   State);
#endif

/*=============================================================================================*/
#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
static inline Std_ReturnType Pwm_ValidateParamsDutyPhaseShift(uint32            CoreId,
                                                              Pwm_DutyType      PhaseShift,
                                                              uint16            DutyCycle,
                                                              Pwm_ChannelType   ChannelNumber,
                                                              uint8             ServiceId);
#endif

/*=============================================================================================*/
#if ((PWM_DISABLE_TRIGGER_API == STD_ON) || (PWM_ENABLE_TRIGGER_API == STD_ON))
static inline Std_ReturnType Pwm_ValidateBitMask(uint32 CoreId,
                                                 uint32 TriggerMask,
                                                 uint8  ServiceId);
#endif

/*=============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
#if (defined(PWM_SETOUTPUTTOIDLE_PLAUSABILITY) && (PWM_SETOUTPUTTOIDLE_PLAUSABILITY == STD_ON))
static inline Std_ReturnType Pwm_ValidateSetOutPutToIdle(uint32            CoreId,
                                                         Pwm_ChannelType   ChannelNumber);
#endif /* (defined(PWM_SETOUTPUTTOIDLE_PLAUSABILITY) && (PWM_SETOUTPUTTOIDLE_PLAUSABILITY == STD_ON)) */
#endif /* (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) */

#endif /* PWM_PARAM_CHECK */

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API                == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API           == STD_ON) || \
     (PWM_SET_OUTPUT_TO_IDLE_API            == STD_ON) || \
     (PWM_GET_OUTPUT_STATE_API              == STD_ON) || \
     (PWM_GET_CHANNEL_STATE_API             == STD_ON) || \
     (PWM_FORCE_OUTPUT_TO_ZERO_API          == STD_ON) || \
     (PWM_NOTIFICATION_SUPPORTED            == STD_ON) || \
     (PWM_SET_COUNTER_BUS_API               == STD_ON) || \
     (PWM_SET_CHANNEL_OUTPUT_API            == STD_ON) || \
     (PWM_SET_TRIGGER_DELAY_API             == STD_ON) || \
     (PWM_SET_CHANNEL_FORCE_OUT_API         == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_CYCLE_NO_UPDATE_API      == STD_ON) || \
     (PWM_SYNC_UPDATE_API                   == STD_ON) || \
     (PWM_SET_CHANNEL_DEAD_TIME_API         == STD_ON) || \
     (PWM_FAST_UPDATE_API                   == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API          == STD_ON))

static inline uint8 Pwm_GetPartitionChannelIdx(uint32          CoreId,
                                               Pwm_ChannelType ChannelNumber)
{
#if (PWM_MULTICORE_ENABLED == STD_ON)
    return (*(Pwm_aState[CoreId].PwmConfig)->PwmLogicalToPartitionMap)[ChannelNumber];
#else
    /* Avoid compiler warning */
    (void)CoreId;

    return ChannelNumber;
#endif
}
#endif



/*=============================================================================================*/
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
/**
* @brief        Validate the call of a function impacting the configuration of the entire driver.
* @details      Before executing, a function which changes the configuration of the entire driver
*               shall check if:
*               1. It is not preempting itself
*               2. It is not preempting another function that changes the configuration of the
*                  entire driver
*               3. It is not preempting a function that changes the configuration of one of the
*                  driver's channels
*               In any of the above cases, the function will report an error to Det or Serr,
*               depending on the environment the driver is run in.
*
* @param[in]    CoreId              The number of current core ID
* @param[in]    ServiceId           Id of the service calling this function
*
* @return       Std_ReturnType      Call is valid or not
* @retval       E_OK                Caller of the function can continue its execution
* @retval       E_NOT_OK            Caller of the function should drop execution
*
*/
static Std_ReturnType Pwm_ValidateGlobalConfigCall(uint32   CoreId,
                                                   uint8    ServiceId)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    if (PWM_STATE_UNINIT == Pwm_aState[CoreId].PwmDriverState)
    {
        if (PWM_INIT_ID != ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  ServiceId,
                (uint8)  PWM_E_UNINIT
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        if (PWM_INIT_ID == ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  ServiceId,
                (uint8)  PWM_E_ALREADY_INITIALIZED
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    return RetVal;
}
#endif /* PWM_VALIDATE_GLOBAL_CONFIG_CALL */



/*=============================================================================================*/
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
/**
* @brief        Completes the execution of a function impacting the configuration of the entire driver.
* @details      Performs actions in order to ensure that after it's caller has completed the execution
*               the driver will remain in a state allowing execution of other functions updating the
*               configuration of the entire driver or of a single channel
*
* @param[in]    CoreId     The number of current core ID
* @param[in]    ValidCall  The function call was previously validated
* @param[in]    ServiceId  The service id of the caller function
*
* @return       void
*
*/
static inline void Pwm_EndValidateGlobalConfigCall(uint32           CoreId,
                                                   Std_ReturnType   ValidCall,
                                                   uint8            ServiceId)
{
    /* Change the state of the driver only if the previous call to
    Pwm_ValidateGlobalConfigCall() stated that the API call is valid */
    if ((Std_ReturnType)E_OK == ValidCall)
    {
        if (PWM_DEINIT_ID == ServiceId)
        {
            Pwm_aState[CoreId].PwmDriverState = PWM_STATE_UNINIT;
        }
        else
        {
            Pwm_aState[CoreId].PwmDriverState = PWM_STATE_IDLE;
        }
    }
}
#endif /* PWM_VALIDATE_GLOBAL_CONFIG_CALL */



/*=============================================================================================*/
#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
#if ((PWM_SET_DUTY_CYCLE_API                == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API           == STD_ON) || \
     (PWM_SET_OUTPUT_TO_IDLE_API            == STD_ON) || \
     (PWM_GET_OUTPUT_STATE_API              == STD_ON) || \
     (PWM_GET_CHANNEL_STATE_API             == STD_ON) || \
     (PWM_FORCE_OUTPUT_TO_ZERO_API          == STD_ON) || \
     (PWM_NOTIFICATION_SUPPORTED            == STD_ON) || \
     (PWM_SET_COUNTER_BUS_API               == STD_ON) || \
     (PWM_SET_CHANNEL_OUTPUT_API            == STD_ON) || \
     (PWM_SET_TRIGGER_DELAY_API             == STD_ON) || \
     (PWM_SET_CHANNEL_FORCE_OUT_API         == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_CYCLE_NO_UPDATE_API      == STD_ON) || \
     (PWM_SYNC_UPDATE_API                   == STD_ON) || \
     (PWM_SET_CHANNEL_DEAD_TIME_API         == STD_ON) || \
     (PWM_FAST_UPDATE_API                   == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API          == STD_ON))
/**
* @brief        Validate the call of a function impacting the configuration of one of the driver's
* @details      channels. Before executing, a function which changes the configuration of a
*               channel shall check if:
*               1. It is not preempting itself
*               2. It is not preempting a function that changes the configuration of the
*                  entire driver
*               In any of the above cases, the function will report an error to Det or Serr,
*               depending on the environment the driver is run in.
*
* @param[in]    CoreId         The number of current core ID
* @param[in]    ChannelNumber  Id of the channel the caller tries to update
* @param[in]    ServiceId      Id of the service calling this function
*
* @return       Std_ReturnType  Call is valid or not
* @retval       E_OK            Caller of the function can continue its execution
* @retval       E_NOT_OK        Caller of the function should drop execution
*
*/
static inline Std_ReturnType Pwm_ValidateChannelConfigCall(uint32          CoreId,
                                                           Pwm_ChannelType ChannelNumber,
                                                           uint8           ServiceId)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType          RetVal = (Std_ReturnType)E_OK;
    Pwm_ChannelType         PartitionChannelIdx;

    /* Check if the driver is initialized */
    if (PWM_STATE_UNINIT == Pwm_aState[CoreId].PwmDriverState)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

        /* Driver not initialized yet */
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  ServiceId,
            (uint8)  PWM_E_UNINIT
        );
    }
    else
    {
        /* Check that the channel is in valid range */
        if (PWM_CONFIG_LOGIC_CHANNELS <= ChannelNumber)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;

            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  ServiceId,
                (uint8)  PWM_E_PARAM_CHANNEL
            );
        }
        else
        {
            PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

            /* Check that the channel is not in current partition */
            if (PartitionChannelIdx >= Pwm_aState[CoreId].PwmConfig->NumChannels)
            {
                RetVal = (Std_ReturnType)E_NOT_OK;

                (void)Det_ReportError
                (
                    (uint16) PWM_MODULE_ID,
                    (uint8)  PWM_INDEX,
                    (uint8)  ServiceId,
                    (uint8)  PWM_E_PARAM_CONFIG
                );
            }
            else
            {
#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
                if (PWM_SETDUTYPHASESHIFT_ID == ServiceId)
                {
                    if ((Std_ReturnType)E_OK != Pwm_Ipw_ValidateSetPhaseShift(&((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg)))
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;

                        (void)Det_ReportError
                        (
                            (uint16) PWM_MODULE_ID,
                            (uint8)  PWM_INDEX,
                            (uint8)  ServiceId,
                            (uint8)  PWM_E_CHANNEL_PHASE_SHIFT_NOT_SUPPORTED
                        );
                    }
                }
#endif

#if ((PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SYNC_UPDATE_API == STD_ON))
                if ((PWM_SETPERIODANDDUTY_NO_UPDATE_ID == ServiceId) || (PWM_SETDUTYCYCLE_NO_UPDATE_ID == ServiceId) || (PWM_SYNCUPDATE_ID == ServiceId))
                {
                    if ((Std_ReturnType)E_OK != Pwm_Ipw_ValidateUpdateSynchronous(&((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg)))
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;

                        (void)Det_ReportError
                        (
                            (uint16) PWM_MODULE_ID,
                            (uint8)  PWM_INDEX,
                            (uint8)  ServiceId,
                            (uint8)  PWM_E_DUTY_SYNCHRONOUS_NOT_SUPPORTED
                        );
                    }
                }
#endif
            /* Do nothing */
            }
        }
    }

    return RetVal;
}



/*=============================================================================================*/
/**
* @brief        Completes the execution of a function impacting the configuration of a driver channel.
* @details      Performs actions in order to ensure that after it's caller has completed the execution
*               the driver will remain in a state allowing execution of other functions updating the
*               configuration of the entire driver or of a single channel.
*
* @param[in]    ChannelNumber  Id of the Pwm channel.
*
* @return       void
*
*/
static inline void Pwm_EndValidateChannelConfigCall(Pwm_ChannelType ChannelNumber)
{
    /* Avoid compiler warning */
    (void)ChannelNumber;
}
#endif
#endif /* PWM_VALIDATE_CHANNEL_CONFIG_CALL */



/*=============================================================================================*/
#if (PWM_PARAM_CHECK == STD_ON)


/*=============================================================================================*/
/**
* @brief        Validate the configuration parameter of the Pwm_Init API. In case an
*               error is detected, the function will report an error to Det or Serr,
*               depending on the environment the driver is run in.
*
* @param[in]    CoreId          The number of current core ID
* @param[in]    ConfigPtr       Pointer to the configuration of Pwm driver
*
* @return       Std_ReturnType  Validity of the pointer
* @retval       E_OK            Pointer is valid
* @retval       E_NOT_OK        Pointer is invalid
*
*/
static inline Std_ReturnType Pwm_ValidateParamPtrInit(uint32                 CoreId,
                                                      const Pwm_ConfigType * ConfigPtr)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType      RetVal = (Std_ReturnType)E_OK;

#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
    /* For pre-compile, check DET error if the received config pointer is not NULL_PTR */
    if (NULL_PTR != ConfigPtr)
    {
#else
    /* For post build, check DET error if the received config pointer is NULL_PTR */
    if (NULL_PTR == ConfigPtr)
    {
#endif
        /* Avoid compiler warning */
        (void)CoreId;

        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_INIT_ID,
            (uint8)  PWM_E_INIT_FAILED
        );

        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (PWM_PRECOMPILE_SUPPORT == STD_OFF)
    #if (PWM_MULTICORE_ENABLED == STD_ON)
    else if (CoreId != ConfigPtr->CoreId)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_INIT_ID,
            (uint8)  PWM_E_PARAM_CONFIG
        );

        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    #endif
    else
    {
        /* Do nothing */
    }
#else
    else
    {
    #if (PWM_MULTICORE_ENABLED == STD_ON)
        if (NULL_PTR == Pwm_Config[CoreId])
        {
            /* Avoid compiler warning */
            (void)CoreId;

            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  PWM_INIT_ID,
                (uint8)  PWM_E_INIT_FAILED
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }

        else if (CoreId != Pwm_Config[CoreId]->CoreId)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  PWM_INIT_ID,
                (uint8)  PWM_E_PARAM_CONFIG
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }

        else
        {
            /* Do nothing */
        }
    #endif
        /* Do nothing */
    }
#endif

    return RetVal;
}



/*=============================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || \
     (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON))
/**
* @brief        Validate the DutyCycle parameter of the Pwm_SetDutyCycle API.In case an
*               error is detected, the function will report it to Det or Serr,
*               depending on the environment the driver is run in.
*
* @param[in]    DutyCycle         DutyCycle value to be validated
* @param[in]    ServiceId         Id of calling API
*
* @return       Std_ReturnType    Validity of the DutyCycle parameter
* @retval       E_OK              Duty Cycle is valid
* @retval       E_NOT_OK          Duty Cycle is invalid
*
*/
static inline Std_ReturnType Pwm_ValidateParamDuty(uint16   DutyCycle,
                                                   uint8    ServiceId)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    /* Check if the DutyCycle is in valid range */
    if (DutyCycle > PWM_DUTY_CYCLE_100)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  ServiceId,
            (uint8)  PWM_E_DUTYCYCLE_RANGE
        );

        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return RetVal;
}
#endif /* PWM_SET_DUTY_CYCLE_API || PWM_SET_DUTY_CYCLE_NO_UPDATE_API */



/*=============================================================================================*/
#if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
/**
* @brief        Validate the Period and channel class parameters for Pwm_SetPeriodAndDuty API.
*               The Period is validated in the sense that it can be updated only for channels having
*               Variable Period class. Also it may be possible (when hardware allows it)
*               for the PWM period that would be written to hardware, to be constructed taking into
*               consideration some initial value. In such case the total value (maximum value)
*               should not exceed the maximum value supported by the hardware .
*               In case any of the parameters is invalid, the function will report an error to
*               DET or SERR, depending on the environment the driver is run in.
*
* @param[in]    CoreId          The number of current core ID
* @param[in]    ChannelNumber   PWM channel ID in top configuration structure
* @param[in]    ChannelClass    PWM channel class
* @param[in]    Period          Period in ticks
* @param[in]    ServiceId       API service ID
*
* @return       Std_ReturnType  Validity of Channel Class, DutyCycle, Period parameters
* @retval       E_OK            Channel Class, Period are all valid
* @retval       E_NOT_OK        One of Channel Class, Period is invalid
*
*/
static inline Std_ReturnType Pwm_ValidateParamsPeriodClass(uint32                CoreId,
                                                           Pwm_ChannelType       ChannelNumber,
                                                           Pwm_ChannelClassType  ChannelClass,
                                                           Pwm_PeriodType        Period,
                                                           uint8                 ServiceId)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType              RetVal = (Std_ReturnType)E_OK;
#if (PWM_MAX_PERIOD_PLAUSABILITY == STD_ON)
    uint32                      PeriodMaxValue = (uint32)0U;
#else
    (void)Period;
    (void)ChannelNumber;
    (void)CoreId;
#endif

    /* Check if channel supports updates of the period */
    if (PWM_VARIABLE_PERIOD != ChannelClass)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  ServiceId,
            (uint8)  PWM_E_PERIOD_UNCHANGEABLE
        );

        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#if (PWM_MAX_PERIOD_PLAUSABILITY == STD_ON)
        PeriodMaxValue = (uint32)Pwm_Ipw_GetMaxPeriodValue(&((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

        /* Check if period is in range */
        if ((uint32)Period > PeriodMaxValue)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  ServiceId,
                (uint8)  PWM_E_PERIODVALUE
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Nothing to do in this branch */
        }
#else
        /* Nothing to do in this branch */
#endif
    }

    return RetVal;
}


#endif /*PWM_SET_PERIOD_AND_DUTY_API || PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API */



/*=============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Validate the notification handler of a PWM channel.
*               In order to be valid, the notification handler should not be
*               NULL_PTR. In case it is NULL_PTR, the function will report an error to
*               DET or SERR, depending on the environment the driver is run in.
*
* @param[in]    CoreId          The number of current core ID
* @param[in]    ChannelNumber   PWM channel ID in top configuration structure
* @param[in]    Notification    Notification edge type
*
* @return       Std_ReturnType  Validity of notification handler
* @retval       E_OK            Notification handler is valid
* @retval       E_NOT_OK        Notification handler is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateParamNotification(uint32                   CoreId,
                                                           Pwm_ChannelType          ChannelNumber,
                                                           Pwm_EdgeNotificationType Notification)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;
    /** @brief  Notification pointer */
    Pwm_NotifyType                      PwmChannelNotification;

#if (PWM_NOTIFICATION_PLAUSABILITY == STD_OFF)
    (void) Notification;
#endif

    /* Get Notification handler pointer */
    PwmChannelNotification = (*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].PwmChannelNotification;

    /* Check if Notification is NULL_PTR */
    if (NULL_PTR == PwmChannelNotification)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_ENABLENOTIFICATION_ID,
            (uint8)  PWM_E_PARAM_NOTIFICATION_NULL
        );

        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_NOTIFICATION_PLAUSABILITY == STD_ON)
    }
    else
    {
        RetVal = Pwm_Ipw_ValidateNotification(Notification, &((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

        /* Check if Notification can support for specific mode */
        if ((Std_ReturnType)E_OK != RetVal)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  PWM_ENABLENOTIFICATION_ID,
                (uint8)  PWM_E_PARAM_NOTIFICATION
            );
        }
#endif
    }

    return RetVal;
}
#endif /* PWM_NOTIFICATION_SUPPORTED */



/*=============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/**
* @brief        Validate the trigger delay with current period of PWM channel.
*               In order to be valid, the trigger value should less than current period. In this
*               case the function will report an error to DET or SERR, depending on the environment
*               the driver is run in.
*
* @param[in]    CoreId          The number of current core ID
* @param[in]    ChannelNumber   PWM channel ID in top configuration structure
* @param[in]    TriggerDelay    Trigger delay value
*
* @return       Std_ReturnType  Validity of trigger delay parameter
* @retval       E_OK            The trigger delay parameter is valid
* @retval       E_NOT_OK        The trigger delay parameter is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateParamTriggerDelay(uint32           CoreId,
                                                           Pwm_ChannelType  ChannelNumber,
                                                           Pwm_PeriodType   TriggerDelay)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;
    /** @brief  Period value */
    Pwm_PeriodType                      PeriodCurValue = (Pwm_PeriodType)0U;


    PeriodCurValue = Pwm_Ipw_GetCurrentPeriodValue(&((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if (TriggerDelay >= PeriodCurValue)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETTRIGGERDELAY_ID,
            (uint8)  PWM_E_OPWMT_CHANNEL_TRIGGER_RANGE
        );
    }

    return RetVal;
}
#endif /* PWM_SET_TRIGGER_DELAY_API */



/*=============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/**
* @brief        Validate the mode of current channel.
*               In order to be valid, the mode of current channel must be OPWMT
*               case the function will report an error to Det or Serr, depending on the environment
*               the driver is run in.
*
* @param[in]    CoreId          The number of current core ID
* @param[in]    ChannelNumber   The Id of the given channel
*
* @return       Std_ReturnType  Validity of a channel when setting trigger delay 
* @retval       E_OK            The mode of current channel is valid
* @retval       E_NOT_OK        The mode of current channel is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateTriggerDelay(uint32           CoreId,
                                                      Pwm_ChannelType  ChannelNumber)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateTriggerMode(&((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETTRIGGERDELAY_ID,
            (uint8)  PWM_E_PARAM_CHANNEL
        );
    }

    return RetVal;
}
#endif /* PWM_SET_TRIGGER_DELAY_API */


/*=============================================================================================*/
#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief        Validate the mode of current channel.
*               In order to be valid, the mode of current channel must be OPWMCB
*               case the function will report an error to Det or Serr, depending on the environment
*               the driver is run in.
*
* @param[in]    CoreId          The number of current core ID
* @param[in]    ChannelNumber   The Id of the given channel
*
* @return       Std_ReturnType  Validity of channel when setting the dead time
* @retval       E_OK            The mode of current channel is valid
* @retval       E_NOT_OK        The mode of current channel is not valid
* 
*/
static inline Std_ReturnType Pwm_ValidateDeadTime(uint32           CoreId,
                                                  Pwm_ChannelType  ChannelNumber)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateDeadTime(&((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETCHANNELDEADTIME_ID,
            (uint8)  PWM_E_PARAM_CHANNEL
        );
    }

    return RetVal;
}
#endif /* PWM_SET_CHANNEL_DEAD_TIME_API */

/*=============================================================================================*/
#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief        Validate the dead time value of current channel.
*               In order to be valid, the mode of current channel must be OPWMCB
*               case the function will report an error to Det or Serr, depending on the environment
*               the driver is run in.
*
* @param[in]    CoreId          The number of current core ID
* @param[in]    ChannelNumber   The Id of the given channel
* @param[in]    DeadTimeTicks   The dead time value in ticks
*
* @return       Std_ReturnType  Validity of dead time value
* @retval       E_OK            The mode of current channel is valid
* @retval       E_NOT_OK        The mode of current channel is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateParamDeadTime(uint32           CoreId,
                                                       Pwm_ChannelType  ChannelNumber,
                                                       Pwm_PeriodType   DeadTimeTicks)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateParamDeadTime(DeadTimeTicks, &((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETCHANNELDEADTIME_ID,
            (uint8)  PWM_E_DEADTIME_RANGE
        );
    }

    return RetVal;
}
#endif /* PWM_SET_CHANNEL_DEAD_TIME_API */

/*=============================================================================================*/
#if ((PWM_SYNC_UPDATE_API            == STD_ON) || \
     (PWM_ENABLE_TRIGGER_API         == STD_ON) || \
     (PWM_DISABLE_TRIGGER_API        == STD_ON) || \
     (PWM_RESET_COUNTER_API          == STD_ON) || \
     (PWM_ENABLE_MASKING_OPERATIONS  == STD_ON) || \
     (PWM_FAST_UPDATE_API            == STD_ON) || \
     (PWM_RELOAD_NOTIF_SUPPORTED     == STD_ON) || \
     (PWM_FAULT_SUPPORTED            == STD_ON))
/**
* @brief        Validate the module id.
*               In order to be valid, the module id should less than number of module that supported
*
* @param[in]    ModuleId        The Id of the ipv module
* @param[in]    ServiceId       Id of the service calling this function
*
* @return       Std_ReturnType  Validity of the module id
* @retval       E_OK            The module id is valid
* @retval       E_NOT_OK        The module id is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateModuleId(uint8 ModuleId,
                                                  uint8 ServiceId)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    if ((PWM_HW_MODULE_NO <= ModuleId) || ((Std_ReturnType)E_NOT_OK == Pwm_Ipw_ValidateModuleId(ModuleId)))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  ServiceId,
            (uint8)  PWM_E_PARAM_INSTANCE
        );
    }

    return RetVal;
}
#endif



/*=============================================================================================*/
#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
/**
* @brief        Validate the force output to zero.
*               In order to be valid, only call for channel in FlexPWM or FTM . In this
*               case the function will report an error to Det or Serr, depending on the environment
*               the driver is run in.
*
* @param[in]    CoreId          The number of current core ID
* @param[in]    ChannelNumber   The id of channel number
*
* @return       Std_ReturnType  Validity of force output to zero feature
* @retval       E_OK            Force output to zero feature is valid
* @retval       E_NOT_OK        Force output to zero feature is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateForceOutputToZero(uint32           CoreId,
                                                           Pwm_ChannelType  ChannelNumber)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateForceOutputToZero(&((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_FORCEOUTPUTTOZERO_ID,
            (uint8)  PWM_E_FORCE_OUTPUT_NOT_SUPPORTED
        );
    }

    return RetVal;
}
#endif /* PWM_FORCE_OUTPUT_TO_ZERO_API */



/*=============================================================================================*/
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
/**
* @brief        Validate the counter bus.
*               In order to be valid, the trigger value should less than current default. In this
*               case the function will report an error to Det or Serr, depending on the environment
*               the driver is run in.
*
* @param[in]    CoreId          The number of current core ID
* @param[in]    ChannelNumber   PWM channel ID in top configuration structure
* @param[in]    Bus             The Id current counter bus
*
* @return       Std_ReturnType  Validity of the counter bus.
* @retval       E_OK            Counter bus parameter is valid
* @retval       E_NOT_OK        Counter bus parameter is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateCounterBus(uint32          CoreId,
                                                    Pwm_ChannelType ChannelNumber,
                                                    uint32          Bus)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateCounterBus(Bus, &((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETCOUNTERBUS_ID,
            (uint8)  PWM_E_COUNTERBUS
        );
    }

    return RetVal;
}
#endif /* PWM_SET_COUNTER_BUS_API */



/*=============================================================================================*/
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/**
* @brief        Validate the set channel output feature. This validate function only applies for eMIOS.
*
* @param[in]    CoreId          The number of current core ID.
* @param[in]    ChannelNumber   The id of channel number.
* @param[in]    State           The state of output.
*
* @return       Std_ReturnType  Validity of the channel in the set channel output feature.
* @retval       E_OK            Set channel output parameter is valid.
* @retval       E_NOT_OK        Set channel output parameter is not valid.
*
*/
static inline Std_ReturnType Pwm_ValidateSetChannelOutput(uint32            CoreId,
                                                          Pwm_ChannelType   ChannelNumber,
                                                          Pwm_StateType     State)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateSetChannelOutput(State, &((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETCHANNELOUTPUT_ID,
            (uint8)  PWM_E_SET_CHANNEL_OUTPUT
        );
    }

    return RetVal;
}
#endif /* PWM_SET_CHANNEL_OUTPUT_API */



/*=============================================================================================*/
#if (PWM_SET_CHANNEL_FORCE_OUT_API == STD_ON)
/**
* @brief        Validate the force out feature. This validate function only applies for FlexPWM.
*               In order to be valid, the output state is only PWM_STATE_LOW or PWM_STATE_HIGH if
*               the hardware channel is PWM_X.
*
* @param[in]    CoreId          The number of current core ID
* @param[in]    ChannelNumber   The id of channel number
* @param[in]    State           The state of output
*
* @return       Std_ReturnType  Validity of the force out feature.
* @retval       E_OK            Force out parameter is valid
* @retval       E_NOT_OK        Force out parameter is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateSetChannelForceOut(uint32                  CoreId,
                                                            Pwm_ChannelType         ChannelNumber,
                                                            Pwm_ForceOutStateType   State)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateSetChannelForceOut(ChannelNumber, State, &Pwm_pConfig[CoreId]->IpConfig);

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETCHANNELFORCEOUT_ID,
            (uint8)  PWM_E_FORCE_OUT
        );
    }

    return RetVal;
}
#endif /* PWM_SET_CHANNEL_FORCE_OUT_API */



#if (PWM_SET_DUTY_PHASE_SHIFT_API == STD_ON)
/**
* @brief        Pwm_ValidateParamsDutyPhaseShift
* @details      This function will check phase shift  and duty parameter .
*
* @param[in]    CoreId               The number of current core ID
* @param[in]    PhaseShift           Phase shift value
* @param[in]    DutyCycle            Duty Cycle value
* @param[in]    ChannelNumber        PWM channel ID in top configuration structure
* @param[in]    ServiceId            Service ID
*
* @return       Std_ReturnType       Validity of the phase shift feature.
* @retval       E_OK                 Parameter is valid
* @retval       E_NOT_OK             Parameter is not valid
*
*/
static inline Std_ReturnType Pwm_ValidateParamsDutyPhaseShift(uint32            CoreId,
                                                              Pwm_DutyType      PhaseShift,
                                                              uint16            DutyCycle,
                                                              Pwm_ChannelType   ChannelNumber,
                                                              uint8             ServiceId)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateSetDutyPhaseShiftParams(PhaseShift,
                                                     DutyCycle,
                                                     &((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  ServiceId,
            (uint8)  PWM_E_PARAM_PHASESHIFT_RANGE
        );
    }

    return RetVal;
}
#endif



/*=============================================================================================*/
#if ((PWM_ENABLE_TRIGGER_API == STD_ON) || (PWM_DISABLE_TRIGGER_API == STD_ON))
/**
* @brief        This function will check bit mask.
* @details      Bit mask will be process at lower layer has to be compatible with  hardware register
*
* @param[in]    CoreId             The number of current core ID
* @param[in]    TriggerMask        Trigger mask value
* @param[in]    ServiceId          Id of the service calling this function
*
* @return       Std_ReturnType     Validity of the bit mask
* @retval       E_OK               Bit mask is compatible
* @retval       E_NOT_OK           Bit mask is not compatible
*
*/
static inline Std_ReturnType Pwm_ValidateBitMask(uint32 CoreId,
                                                 uint32 TriggerMask,
                                                 uint8  ServiceId)
{
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    if((PWM_ENABLETRIGGER_ID == ServiceId) || (PWM_DISABLETRIGGER_ID == ServiceId))
    {
        RetVal = Pwm_Ipw_ValidateTriggerMask(TriggerMask, &((*Pwm_aState[CoreId].PwmChannelConfigs)[CoreId].IpwChannelCfg));

        if((Std_ReturnType)E_OK != RetVal)
        {
            (void)Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8)  PWM_INDEX,
                (uint8)  ServiceId,
                (uint8)  PWM_E_TRIGGER_MASK
            );
        }
    }

    return RetVal;
}
#endif /* PWM_ENABLE_TRIGGER_API || PWM_DISABLE_TRIGGER_API */



/*=============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
#if (defined(PWM_SETOUTPUTTOIDLE_PLAUSABILITY) && (PWM_SETOUTPUTTOIDLE_PLAUSABILITY == STD_ON))
/**
* @brief            Pwm_ValidateSetOutPutToIdle
* @details          This function will check the validation when calling the Pwm_SetOutputToIdle api.
*
* @param[in]        CoreId           The Index of core
* @param[in]        ChannelNumber    The id of channel number
*
* @retval           RetVal          E_NOT_OK  Set output to idle is not valid
                                    E_OK      Set output to idle is valid
*/
static inline Std_ReturnType Pwm_ValidateSetOutPutToIdle(uint32            CoreId,
                                                         Pwm_ChannelType   ChannelNumber)
{
    
    /** @brief  Variable to store the value returned by the function */
    Std_ReturnType                      RetVal = (Std_ReturnType)E_OK;

    RetVal = Pwm_Ipw_ValidateSetOutPutToIdle(&((*Pwm_aState[CoreId].PwmChannelConfigs)[ChannelNumber].IpwChannelCfg));

    if((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETOUTPUTTOIDLE_ID,
            (uint8)  PWM_E_SETOUTPUTTOIDLE_NOT_SUPPORTED
        );
    }

    return RetVal;
}
#endif /* (defined(PWM_SETOUTPUTTOIDLE_PLAUSABILITY) && (PWM_SETOUTPUTTOIDLE_PLAUSABILITY == STD_ON)) */
#endif /* (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) */

#endif /* PWM_PARAM_CHECK */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        This function initializes the Pwm driver.
* @details      The function Pwm_Init shall initialize all internals variables and the used
*               PWM structure of the microcontroller according to the parameters
*               specified in ConfigPtr.
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
*               shall check the parameter ChannelNumber and raise development error PWM_E_PARAM_CHANNEL
*               if the parameter ChannelNumber is invalid.
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
*               For pre-compile and link time configuration variants, a NULL_PTR pointer shall be passed
*               to the initialization routine. In this case the check for this NULL_PTR pointer
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
* @implements   Pwm_Init_Activity
*
*/
void Pwm_Init(const Pwm_ConfigType * ConfigPtr)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON) || (PWM_PARAM_CHECK == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      CoreId;
    uint8                       Index;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_INIT_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        CallIsValid = Pwm_ValidateParamPtrInit(CoreId, ConfigPtr);

        if ((Std_ReturnType)E_OK == CallIsValid)
        {
#endif

#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
            /* Save configuration pointer in global variable */
#if (PWM_MULTICORE_ENABLED == STD_ON)
            Pwm_aState[CoreId].PwmConfig = Pwm_Config[CoreId];
#else
            Pwm_aState[CoreId].PwmConfig = &Pwm_Config;
#endif
            (void)ConfigPtr;
#else
            Pwm_aState[CoreId].PwmConfig = ConfigPtr;
#endif

#if (PWM_HW_INSTANCE_USED == STD_ON)
            /* IPW call to hw instance initialization when PWM controls the entire hw instance */
            for (Index = 0; Index < Pwm_aState[CoreId].PwmConfig->NumInstances; Index++)
            {
                Pwm_Ipw_InitInstance(&((*Pwm_aState[CoreId].PwmConfig->PwmInstancesConfig)[Index]));
            }
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            for(Index = 0; Index < Pwm_aState[CoreId].PwmConfig->NumChannels; Index++)
            {
                Pwm_aState[CoreId].PwmChannelConfigs[Index] = &((*Pwm_aState[CoreId].PwmConfig->PwmChannelsConfig)[Index]);
                /* Continue to hw channel initialization */
                Pwm_Ipw_Init(&((*Pwm_aState[CoreId].PwmConfig->PwmChannelsConfig)[Index].IpwChannelCfg));
            }

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
            Pwm_aState[CoreId].PwmCurrentPowerState = PWM_FULL_POWER;
            Pwm_aState[CoreId].PwmTargetPowerState = PWM_NODEFINE_POWER;
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_INIT_ID);
#endif
}



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
* @param[in]    None
*
* @return       void
*
* @implements   Pwm_DeInit_Activity
*
*/
void Pwm_DeInit(void)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
#if (PWM_HW_INSTANCE_USED == STD_ON)
    const Pwm_ConfigType      * ConfigPtr;
#endif
    uint32                      CoreId;
    uint8                       Index;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_DEINIT_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

        /* All validations passed. Here starts the actual functional code of the function */
        /* Deinitialize all channels */
        for(Index = 0; Index < Pwm_aState[CoreId].PwmConfig->NumChannels; Index++)
        {
            Pwm_Ipw_DeInit(&((*Pwm_aState[CoreId].PwmChannelConfigs)[Index].IpwChannelCfg), (*Pwm_aState[CoreId].PwmChannelConfigs)[Index].ChannelIdleState);
        }

#if (PWM_HW_INSTANCE_USED == STD_ON)
        ConfigPtr =  Pwm_aState[CoreId].PwmConfig;
        /* IPW call to hw instance initialization when PWM controls the entire hw instance */
        for (Index = 0; Index < Pwm_aState[CoreId].PwmConfig->NumInstances; Index++)
        {
            Pwm_Ipw_DeInitInstance(&((*ConfigPtr->PwmInstancesConfig)[Index]));
        }
#endif
        /* Set global configuration pointer back to NULL_PTR */
        Pwm_aState[CoreId].PwmConfig = NULL_PTR;

        /* Set all channels config to NULL_PTR */
        for(Index = 0; Index < PWM_CONFIG_LOGIC_CHANNELS; Index++)
        {
            Pwm_aState[CoreId].PwmChannelConfigs[Index] = NULL_PTR;
        }
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
        /* Reset Power State */
        Pwm_aState[CoreId].PwmCurrentPowerState = PWM_NODEFINE_POWER;
        Pwm_aState[CoreId].PwmTargetPowerState = PWM_NODEFINE_POWER;
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_DEINIT_ID);
#endif

}
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
*               the PWM functions shall check the parameter ChannelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
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
* @param[in]    ChannelNumber       Pwm channel id
* @param[in]    DutyCycle           Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
* @implements   Pwm_SetDutyCycle_Activity
*
*/
void Pwm_SetDutyCycle(Pwm_ChannelType   ChannelNumber,
                      uint16            DutyCycle)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_SETDUTYCYCLE_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamDuty(DutyCycle, PWM_SETDUTYCYCLE_ID))
        {
#endif
            /* All validations passed. Here starts the actual functional code of the function */
            RetVal = Pwm_Ipw_SetDutyCycle(DutyCycle, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

            /* Avoid compiler warning */
            (void)RetVal;

#if (PWM_PARAM_CHECK == STD_ON)
            if ((Std_ReturnType)E_OK != RetVal)
            {
                (void)Det_ReportError
                (
                    (uint16) PWM_MODULE_ID,
                    (uint8)  PWM_INDEX,
                    (uint8)  PWM_SETDUTYCYCLE_ID,
                    (uint8)  PWM_E_CHANNEL_OFFSET_VALUE
                );
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
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
*               the PWM functions shall check the parameter ChannelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
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
* @param[in]    ChannelNumber   Pwm channel id
* @param[in]    Period          Pwm signal period value
* @param[in]    DutyCycle       Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
* @implements   Pwm_SetPeriodAndDuty_Activity
*
*/
void Pwm_SetPeriodAndDuty(Pwm_ChannelType   ChannelNumber,
                          Pwm_PeriodType    Period,
                          uint16            DutyCycle)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_SETPERIODANDDUTY_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamsPeriodClass(CoreId, PartitionChannelIdx, (*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].PwmChannelClass, Period, PWM_SETPERIODANDDUTY_ID))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateParamDuty(DutyCycle, PWM_SETPERIODANDDUTY_ID))
            {
#endif

                /* All validations passed. Here starts the actual functional code of the function */
                (void)Pwm_Ipw_SetPeriodAndDuty(Period, DutyCycle, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */



/*===============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief        This function sets the generated pwm signal to the idle value configured.
* @details      The function Pwm_SetOutputToIdle shall set immediately the
*               PWM output to the configured Idle state.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the parameter ChannelNumber and raise development error PWM_E_PARAM_CHANNEL
*               if the parameter ChannelNumber is invalid.
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
* @param[in]    ChannelNumber   Pwm channel id
*
* @return       void
*
* @implements   Pwm_SetOutputToIdle_Activity
*
*/
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_SETOUTPUTTOIDLE_ID))
    {
#endif

        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (defined(PWM_SETOUTPUTTOIDLE_PLAUSABILITY) && (PWM_SETOUTPUTTOIDLE_PLAUSABILITY == STD_ON) && (PWM_PARAM_CHECK == STD_ON))
        if((Std_ReturnType)E_OK == Pwm_ValidateSetOutPutToIdle(CoreId, PartitionChannelIdx))
        {
#endif /* PWM_SETOUTPUTTOIDLE_PLAUSABILITY && PWM_PARAM_CHECK */

            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_SetOutputToIdle((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].ChannelIdleState, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

            /* Mark the channel in idle output mode */
            Pwm_aState[CoreId].PwmChannelIdleState[PartitionChannelIdx] = TRUE;
            
#if (defined(PWM_SETOUTPUTTOIDLE_PLAUSABILITY) && (PWM_SETOUTPUTTOIDLE_PLAUSABILITY == STD_ON) && (PWM_PARAM_CHECK == STD_ON))
        }
#endif /* PWM_SETOUTPUTTOIDLE_PLAUSABILITY && PWM_PARAM_CHECK */

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */



/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        This function returns the signal output state.
* @details      The function Pwm_GetOutputState shall read the internal state of
*               the PWM output signal and return it as defined in the diagram below (see PWM_SWS).
*
*               If development error detection for the Pwm module is enabled,
*               the PWM functions shall check the parameter ChannelNumber and
*               raise development error PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
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
* @param[in]    ChannelNumber        Pwm channel id
*
* @return       Pwm_OutputStateType  Pwm signal output logic value
* @retval       PWM_LOW              The output state of PWM channel is low
* @retval       PWM_HIGH             The output state of PWM channel is high
*
* @implements   Pwm_GetOutputState_Activity
*
*/
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber)
{

    uint32                  CoreId;
    Pwm_ChannelType         PartitionChannelIdx;
    /** @brief  Variable to store the value returned by the function */
    Pwm_OutputStateType     RetVal = PWM_LOW;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_GETOUTPUTSTATE_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

        /* All validations passed. Here starts the actual functional code of the function */
        RetVal = Pwm_Ipw_GetOutputState(&((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

    return RetVal;
}
#endif /* PWM_GET_OUTPUT_STATE_API */



/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        This function disables the user notifications.
* @details      If development error detection for the Pwm module is enabled:
*               - The PWM functions shall check the parameter ChannelNumber and raise
*               development error PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
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
* @param[in]    ChannelNumber    Pwm channel id
*
* @return       void
*
* @implements   Pwm_DisableNotification_Activity
*
*/
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_DISABLENOTIFICATION_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

        /* All validations passed. Here starts the actual functional code of the function */
        Pwm_Ipw_DisableNotification(&((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_NOTIFICATION_SUPPORTED */



/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        This function enables the user notifications.
* @details      The function Pwm_EnableNotification shall enable the PWM signal edge notification
*               according to notification parameter.
*               If development error detection for the Pwm module is enabled:
*               - The PWM functions shall check the parameter ChannelNumber and raise
*               development error PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
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
* @param[in]    ChannelNumber   Pwm channel id
* @param[in]    Notification    Notification type to be enabled
*
* @return       void
*
* @implements   Pwm_EnableNotification_Activity
*
*/
void Pwm_EnableNotification(Pwm_ChannelType           ChannelNumber,
                            Pwm_EdgeNotificationType  Notification)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_ENABLENOTIFICATION_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamNotification(CoreId, PartitionChannelIdx, Notification))
        {
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_EnableNotification(Notification, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_NOTIFICATION_SUPPORTED */



/*===============================================================================================*/
#if (PWM_VERSION_INFO_API == STD_ON)
/**
* @brief        This function returns Pwm driver version details
* @details      The function Pwm_GetVersionInfo shall return the version information of this module.
*               The version information includes: Module Id, Vendor Id, Vendor specific version number.
*
* @param[out]   versioninfo   Pointer to Std_VersionInfoType output variable
*
* @return       void
*
* @implements   Pwm_GetVersionInfo_Activity
*
*/
void Pwm_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != versioninfo)
    {
#endif

        (versioninfo)->vendorID         = (uint16)PWM_VENDOR_ID;
        (versioninfo)->moduleID         = (uint16)PWM_MODULE_ID;

        (versioninfo)->sw_major_version = (uint8)PWM_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)PWM_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)PWM_SW_PATCH_VERSION;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        /* if the parameter versionInfo is NULL_PTR then report the error */
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_GETVERSIONINFO_ID,
            (uint8)  PWM_E_PARAM_POINTER
        );
    }
#endif

}
#endif /* PWM_VERSION_INFO_API */



/*===============================================================================================*/
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/**
* @brief        This function returns the duty cycle of the channel passed as parameter
* @details      The function Pwm_GetChannelState shall return the DutyCycle of the channel.
*               In case the channel is idle, the returned value will be zero.
*
* @param[in]    ChannelNumber   Pwm channel id
*
* @return       uint16          DutyCycle of the requested channel
*
* @implements   Pwm_GetChannelState_Activity
*
*/
uint16 Pwm_GetChannelState(Pwm_ChannelType ChannelNumber)
{
    uint32            CoreId;
    Pwm_ChannelType   PartitionChannelIdx;
    /** @brief  Duty cycle value */
    uint16            DutyCycle = (uint16)0U;


    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_GETCHANNELSTATE_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

        /* All validations passed. Here starts the actual functional code of the function */
        DutyCycle = Pwm_Ipw_GetChannelState(&((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

    return DutyCycle;
}
#endif /* PWM_GET_CHANNEL_STATE_API */



/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Notification
* @details      This function is called from Pwm_Ipw.c file in order to forward a
*               channel notification call from the IP configuration.
*
* @param[in]    Channel   Hw channel for which notification should be called
*
* @return       void
*
* @implements   Pwm_Notification_Activity
*
*/
void Pwm_Notification(uint8 Channel)
{
    uint8            LogicChannel;
    uint32           CoreId;
    Pwm_ChannelType  PartitionChannelIdx;
    Pwm_NotifyType   Notify;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

    if (NULL_PTR != Pwm_aState[CoreId].PwmConfig)
    {
        LogicChannel = Pwm_aState[CoreId].PwmConfig->HwToLogicChannelMap[Channel];

        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, LogicChannel);

        /* Check that there is a logic channel associated with the Hw one */
        Notify = (*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].PwmChannelNotification;

        /* Check that a notification is defined for the associated
        logic channel. This is a double check not necessarily needed because if notification were
        enabled in IP layer for the channel that generated the interrupt causing this notify to
        be called, it means that this channel cannot have a null notification, otherwise notification
        could not have been enabled */
        if (NULL_PTR != Notify)
        {
            Notify();
        }
    }
}
#endif /* PWM_NOTIFICATION_SUPPORTED */



/*===============================================================================================*/
#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
/**
* @brief        This function enables-disables the forcing of the output of a given channel to logic 0.
*
* @param[in]    ChannelNumber   Pwm channel id
* @param[in]    Force           Boolean value to state if the output of the channel will be forced
*                               to zero logic or not
*
* @return       void
*
*/
void Pwm_ForceOutputToZero(Pwm_ChannelType  ChannelNumber,
                           boolean          Force)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_FORCEOUTPUTTOZERO_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateForceOutputToZero(CoreId, PartitionChannelIdx))
        {
#endif
            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_ForceOutputToZero(Force, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_FORCE_OUTPUT_TO_ZERO_API */



/*===============================================================================================*/
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
/**
* @brief        This function will change the bus of pwm channels running.
* @details      This function is useful to change the frequency of the output PWM signal between
*               two counter buses frequency
*
* @param[in]    ChannelNumber    Pwm channel id
* @param[in]    Bus              The bus need to be changed
*
* @return       void
*
*/
void Pwm_SetCounterBus(Pwm_ChannelType  ChannelNumber,
                       uint32           Bus)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_SETCOUNTERBUS_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateCounterBus(CoreId, PartitionChannelIdx, Bus))
        {
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_SetCounterBus(Bus, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_COUNTER_BUS_API */



/*===============================================================================================*/
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/**
* @brief        function to set the state of the PWM pin as requested for the current cycle
* @details      This function is useful to set the state of the PWM pin as requested
*               for the current cycle and continues with normal PWM operation from the next cycle
*
* @param[in]    ChannelNumber   Pwm channel id
* @param[in]    State           Active-Inactive state of the channel
*
* @return       void
*
*/
void Pwm_SetChannelOutput(Pwm_ChannelType   ChannelNumber,
                          Pwm_StateType     State)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_SETCHANNELOUTPUT_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateSetChannelOutput(CoreId, PartitionChannelIdx, State))
        {
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_SetChannelOutput(State, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_CHANNEL_OUTPUT_API */





/*===============================================================================================*/
#if (PWM_SET_CHANNEL_FORCE_OUT_API == STD_ON)
/**
* @brief        Function to control the PWM output when force out events occurred
* @details      When force out events occurred, the PWM output will change to configured output state.
*
* @param[in]    ChannelNumber    Pwm channel id
* @param[in]    State            Channel state changed when force out
*
* @return       void
*/
void Pwm_SetChannelForceOut(Pwm_ChannelType         ChannelNumber,
                            Pwm_ForceOutStateType   State)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_SETCHANNELFORCEOUT_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateSetChannelForceOut(CoreId, PartitionChannelIdx, State))
        {
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_SetChannelForceOut(PartitionChannelIdx, State, &Pwm_pConfig[CoreId]->IpConfig);

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_CHANNEL_FORCE_OUT_API */



/*===============================================================================================*/
#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        Implementation specific function to change the peripheral clock frequency.
* @details      This function is useful to set the prescalers that divide the PWM channels
*               clock frequency.
*
* @param[in]    Prescaler   Pwm prescaler type
*
* @return       void
*
* @implements   Pwm_SetClockMode_Activity
*
*/
void Pwm_SetClockMode(Pwm_PrescalerType Prescaler)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      CoreId;
    uint8                       Index;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_SETCLOCKMODE_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_HW_INSTANCE_USED == STD_ON)
    for (Index = 0; Index < Pwm_aState[CoreId].PwmConfig->NumInstances; Index++)
    {
        Pwm_Ipw_SetClockModeInstance(Prescaler, &((*Pwm_aState[CoreId].PwmConfig->PwmInstancesConfig)[Index]));
    }
#endif
    for(Index = 0; Index < Pwm_aState[CoreId].PwmConfig->NumChannels; Index++)
    {
        Pwm_Ipw_SetClockModeChannel(Prescaler, &((*Pwm_aState[CoreId].PwmChannelConfigs)[Index].IpwChannelCfg));
    }


#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_SETCLOCKMODE_ID);
#endif

}
#endif /* PWM_SET_CLOCK_MODE_API */



/*===============================================================================================*/
#if (PWM_SET_CHANNEL_DEAD_TIME_API == STD_ON)
/**
* @brief
* @details      This function is used to update the deadtime at runtime for Pwm channels.
*
* @param[in]    ChannelNumber       Pwm channel id
* @param[in]    DeadTimeTicks       Dead Time value
*
* @return       void
*
* @implements   Pwm_SetChannelDeadTime_Activity
*/
void Pwm_SetChannelDeadTime(Pwm_ChannelType  ChannelNumber,
                            Pwm_PeriodType   DeadTimeTicks)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_SETCHANNELDEADTIME_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);
#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateDeadTime(CoreId, PartitionChannelIdx))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateParamDeadTime(CoreId, PartitionChannelIdx, DeadTimeTicks))
            {
#endif
                Pwm_Ipw_SetChannelDeadTime(DeadTimeTicks, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_DEAD_TIME_CHANNEL_API */



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
*               the PWM functions shall check the parameter ChannelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
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
*
* @param[in]    ChannelNumber       Pwm channel id
* @param[in]    DutyCycle           Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
* @implements   Pwm_SetDutyCycle_NoUpdate_Activity
*
*/
void Pwm_SetDutyCycle_NoUpdate(Pwm_ChannelType  ChannelNumber,
                               uint16           DutyCycle)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_SETDUTYCYCLE_NO_UPDATE_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamDuty(DutyCycle, PWM_SETDUTYCYCLE_NO_UPDATE_ID))
        {
#endif
            /* All validations passed. Here starts the actual functional code of the function */
            RetVal = Pwm_Ipw_SetDutyCycle_NoUpdate(DutyCycle, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

            /* Avoid compiler warning */
            (void)RetVal;

#if (PWM_PARAM_CHECK == STD_ON)
            if ((Std_ReturnType)E_OK != RetVal)
            {
                (void)Det_ReportError
                (
                    (uint16) PWM_MODULE_ID,
                    (uint8)  PWM_INDEX,
                    (uint8)  PWM_SETDUTYCYCLE_NO_UPDATE_ID,
                    (uint8)  PWM_E_CHANNEL_OFFSET_VALUE
                );
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
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
*               the PWM functions shall check the parameter ChannelNumber and raise development error
*               PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
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
* @param[in]    ChannelNumber    Pwm channel id
* @param[in]    Period           Pwm signal period value
* @param[in]    DutyCycle        Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*
* @implements   Pwm_SetPeriodAndDuty_NoUpdate_Activity
*
*/
void Pwm_SetPeriodAndDuty_NoUpdate(Pwm_ChannelType  ChannelNumber,
                                   Pwm_PeriodType   Period,
                                   uint16           DutyCycle)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_SETPERIODANDDUTY_NO_UPDATE_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamsPeriodClass(CoreId, PartitionChannelIdx, (*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].PwmChannelClass, Period, PWM_SETPERIODANDDUTY_NO_UPDATE_ID))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateParamDuty(DutyCycle, PWM_SETPERIODANDDUTY_NO_UPDATE_ID))
            {
#endif

                /* All validations passed. Here starts the actual functional code of the function */
                Pwm_Ipw_SetPeriodAndDuty_NoUpdate(Period, DutyCycle, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg));

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
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
* @param[in]    ModuleId             pwm module id
*                                    Ex : PWM_EMIOS_INSTANCE_0
*                                         PWM_EMIOS_INSTANCE_1
*                                         ...
*                                         PWM_FLEXPWM_INSTANCE_0
*                                         ...
*                                         PWM_FTM_INSTANCE_0
*
* @return       void
*
* @implements   Pwm_SyncUpdate_Activity
*
*/
void Pwm_SyncUpdate(uint8 ModuleId)
{

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType                      CallIsValid;
    uint32                              CoreId;
    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_SYNCUPDATE_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_SYNCUPDATE_ID))
        {
#endif
            Pwm_Ipw_SyncUpdate(ModuleId);

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }
    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_SYNCUPDATE_ID);
#endif

}
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
* @implements Pwm_SetDutyPhaseShift_Activity
*/
void Pwm_SetDutyPhaseShift(Pwm_ChannelType  ChannelNumber,
                           uint16           DutyCycle,
                           Pwm_DutyType     PhaseShift,
                           boolean          SyncUpdate)
{
    uint32          CoreId;
    Pwm_ChannelType PartitionChannelIdx;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if ((Std_ReturnType)E_OK == Pwm_ValidateChannelConfigCall(CoreId, ChannelNumber, PWM_SETDUTYPHASESHIFT_ID))
    {
#endif
        PartitionChannelIdx = Pwm_GetPartitionChannelIdx(CoreId, ChannelNumber);

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateParamDuty(DutyCycle, PWM_SETDUTYPHASESHIFT_ID))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateParamsDutyPhaseShift(CoreId, PhaseShift, DutyCycle, PartitionChannelIdx, PWM_SETDUTYPHASESHIFT_ID))
            {
#endif
                /* All validations passed. Here starts the actual functional code of the function */
                Pwm_Ipw_SetDutyPhaseShift(DutyCycle, PhaseShift, &((*Pwm_aState[CoreId].PwmChannelConfigs)[PartitionChannelIdx].IpwChannelCfg), SyncUpdate);

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateChannelConfigCall(ChannelNumber);
#endif

}
#endif /* PWM_SET_DUTY_PHASE_SHIFT_API */



/*=======================================================================================*/
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
* @param[in]    TriggerHostId    Pwm Hardware module Id.
* @param[in]    TriggerMask      Bit mask will be set to enable trigger with corresponding sources.
*
* @return       void
*
*/
void Pwm_EnableTrigger(uint8    TriggerHostId,
                       uint16   TriggerMask)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      CoreId;
    uint8                       Index;
    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_ENABLETRIGGER_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId(TriggerHostId, PWM_ENABLETRIGGER_ID))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateBitMask(CoreId, (uint32)TriggerMask, PWM_ENABLETRIGGER_ID))
            {
#endif
                for (Index = 0 ; Index < Pwm_aState[CoreId].PwmConfig->NumInstances; Index++)
                {
                    Pwm_Ipw_EnableTrigger(TriggerHostId, TriggerMask, &((*Pwm_aState[CoreId].PwmConfig->PwmInstancesConfig)[Index]));
                }

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_ENABLETRIGGER_ID);
#endif

}
#endif



/*=======================================================================================*/
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
* @param[in]    TriggerHostId    Pwm Hardware module Id.
* @param[in]    TriggerMask      Bit mask will be cleared to disable trigger with corresponding sources.
*
* @return       void
*
*/
void Pwm_DisableTrigger(uint8   TriggerHostId,
                        uint16  TriggerMask)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType          CallIsValid;
#endif
    uint32                  CoreId;
    uint8                   Index;
    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_DISABLETRIGGER_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId(TriggerHostId, PWM_DISABLETRIGGER_ID))
        {
            if ((Std_ReturnType)E_OK == Pwm_ValidateBitMask(CoreId, (uint32)TriggerMask, PWM_DISABLETRIGGER_ID))
            {
#endif
                for (Index = 0 ; Index < Pwm_aState[CoreId].PwmConfig->NumInstances; Index++)
                {
                    Pwm_Ipw_DisableTrigger(TriggerHostId, TriggerMask, &((*Pwm_aState[CoreId].PwmConfig->PwmInstancesConfig)[Index]));
                }

#if (PWM_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_DISABLETRIGGER_ID);
#endif

}
#endif /* PWM_DISABLE_TRIGGER_API */



/*=======================================================================================*/
#if (PWM_RESET_COUNTER_API == STD_ON)
/**
* @brief        This function shall enable the PWM timer HW counter reset
*               by Pwm_SyncUpdate() function.
* @details
*
* @param[in]    ModuleId     Pwm Hardware module Id.
*
* @return       void
*
*/
void Pwm_ResetCounterEnable(uint8   ModuleId)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      CoreId;
    uint8                       Index;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_RESETCOUNTERENABLE_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_RESETCOUNTERENABLE_ID))
        {
#endif
            for (Index = 0 ; Index < Pwm_aState[CoreId].PwmConfig->NumInstances; Index++)
            {
                Pwm_Ipw_ResetCounterEnable(ModuleId,  &((*Pwm_aState[CoreId].PwmConfig->PwmInstancesConfig)[Index]));
            }

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_RESETCOUNTERENABLE_ID);
#endif

}
#endif /* PWM_RESET_COUNTER_API */



/*=======================================================================================*/
#if (PWM_RESET_COUNTER_API == STD_ON)
/**
* @brief        This function shall disable the PWM timer HW counter reset
*               by Pwm_SyncUpdate() function.
* @details
*
*
* @param[in]    ModuleId   Pwm Hardware module Id.
*
* @return       void
*
*/
void Pwm_ResetCounterDisable(uint8  ModuleId)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      CoreId;
    uint8                       Index;
    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_RESETCOUNTERDISABLE_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_RESETCOUNTERDISABLE_ID))
        {
#endif
            for (Index = 0 ; Index < Pwm_aState[CoreId].PwmConfig->NumInstances; Index++)
            {
                Pwm_Ipw_ResetCounterDisable(ModuleId,  &((*Pwm_aState[CoreId].PwmConfig->PwmInstancesConfig)[Index]));
            }
#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_RESETCOUNTERDISABLE_ID);
#endif

}
#endif /* PWM_RESET_COUNTER_API */




/*=======================================================================================*/
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
* @param[in]    ModuleId      Pwm Hardware module id.
* @param[in]    ChannelMask   Bit mask will be set to mask corresponding channel.
*
* @return       void
*
*/
void Pwm_MaskOutputs(uint8  ModuleId,
                     uint8  ChannelMask)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType          CallIsValid;
#endif
    uint32                  CoreId;
    uint8                   Index;
    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_MASKOUTPUT_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId(ModuleId, PWM_MASKOUTPUT_ID))
        {
#endif
            for (Index = 0 ; Index < Pwm_aState[CoreId].PwmConfig->NumInstances; Index++)
            {
                Pwm_Ipw_MaskOutputs(ModuleId, ChannelMask, &((*Pwm_aState[CoreId].PwmConfig->PwmInstancesConfig)[Index]));
            }

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_MASKOUTPUT_ID);
#endif

}
#endif /* PWM_ENABLE_MASKING_OPERATIONS */



/*=======================================================================================*/
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
* @param[in]    ModuleId      Pwm Hardware module Id
* @param[in]    ChannelMask   Bit mask will be cleared to unmask corresponding channel.
*
* @return       void
*
*/
void Pwm_UnMaskOutputs(uint8    ModuleId,
                       uint8    ChannelMask)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      CoreId;
    uint8                       Index;
    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_UNMASKOUTPUT_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_UNMASKOUTPUT_ID))
        {
#endif
            for (Index = 0 ; Index < Pwm_aState[CoreId].PwmConfig->NumInstances; Index++)
            {
                Pwm_Ipw_UnMaskOutputs(ModuleId, ChannelMask, &((*Pwm_aState[CoreId].PwmConfig->PwmInstancesConfig)[Index]));
            }

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_UNMASKOUTPUT_ID);
#endif

}
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
* @param[in]    ModuleId   Pwm hardware module id
*
* @return       void
*
*/
void Pwm_EnableReloadNotification(uint8 ModuleId)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
    uint32                      CoreId;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_ENABLERELOADNOTIF_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_ENABLERELOADNOTIF_ID))
        {
#endif
            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_EnableReloadNotification(ModuleId);

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_ENABLERELOADNOTIF_ID);
#endif

}
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
void Pwm_DisableReloadNotification(uint8    ModuleId)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
    uint32                      CoreId;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_DISABLERELOADNOTIF_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_DISABLERELOADNOTIF_ID))
        {
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_DisableReloadNotification(ModuleId);

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_DISABLERELOADNOTIF_ID);
#endif

}
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
* @param[in]    ModuleId   Pwm hardware module id
*
* @return       void
*
*/
void Pwm_EnableFaultNotification(uint8 ModuleId)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
    uint32                      CoreId;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_ENABLEFAULTNOTIF_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_ENABLEFAULTNOTIF_ID))
        {
#endif
            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_EnableFaultNotification(ModuleId);

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_ENABLEFAULTNOTIF_ID);
#endif

}
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
void Pwm_DisableFaultNotification(uint8    ModuleId)
{
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
    uint32                      CoreId;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();
    CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_DISABLEFAULTNOTIF_ID);

    if ((Std_ReturnType)E_OK == CallIsValid)
    {
#endif

#if (PWM_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Pwm_ValidateModuleId((uint8)ModuleId, PWM_DISABLEFAULTNOTIF_ID))
        {
#endif

            /* All validations passed. Here starts the actual functional code of the function */
            Pwm_Ipw_DisableFaultNotification(ModuleId);

#if (PWM_PARAM_CHECK == STD_ON)
        }
#endif

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }

    Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_DISABLEFAULTNOTIF_ID);
#endif

}
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
* @retval       E_OK            Power Mode changed.
* @retval       E_NOT_OK        Request rejected.
*
* @implements   Pwm_SetPowerState_Activity
*
*/
Std_ReturnType Pwm_SetPowerState(Pwm_PowerStateRequestResultType * Result)
{
    Std_ReturnType              RetVal = (Std_ReturnType)E_OK;
    uint32                      CoreId;
    uint8                       Index;
    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

    if (NULL_PTR == Result)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_PARAM_CHECK == STD_ON)
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_SETPOWERSTATE_ID,
            (uint8)  PWM_E_PARAM_POINTER
        );
#endif

    }
    else
    {
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        RetVal = Pwm_ValidateGlobalConfigCall(CoreId, PWM_SETPOWERSTATE_ID);

        if ((Std_ReturnType)E_OK == RetVal)
        {
#endif
            if (Pwm_eCurrentPowerState[CoreId] == Pwm_eTargetPowerState[CoreId])
            {
                *Result = PWM_SERVICE_ACCEPTED;
            }
            else
            {
                switch(Pwm_eTargetPowerState[CoreId])
                {
                    case PWM_NODEFINE_POWER:
#if (PWM_PARAM_CHECK == STD_ON)
                        (void)Det_ReportError
                        (
                            (uint16) PWM_MODULE_ID,
                            (uint8)  PWM_INDEX,
                            (uint8)  PWM_SETPOWERSTATE_ID,
                            (uint8)  PWM_E_PERIPHERAL_NOT_PREPARED
                        );
#endif
                        *Result = PWM_SEQUENCE_ERROR;
                        RetVal = (Std_ReturnType)E_NOT_OK;
                        break;
                    case PWM_LOW_POWER:
                    case PWM_FULL_POWER:
                        for(Index = 0; Index < Pwm_aState[CoreId].PwmConfig->NumChannels; Index++)
                        {
                            RetVal = Pwm_Ipw_ValidateIdleState(&((*Pwm_aState[CoreId].PwmConfig->PwmChannelsConfig)[Index].IpwChannelCfg));
                            if (RetVal == (Std_ReturnType)E_NOT_OK)
                            {
                                break;
                            }
                        }

                        if((Std_ReturnType)E_OK == RetVal)
                        {
#if (PWM_HW_INSTANCE_USED == STD_ON)
                            for (Index = 0; Index < Pwm_aState[CoreId].PwmConfig->NumInstances; Index ++)
                            {
                                Pwm_Ipw_SetPowerStateInstance(&((*Pwm_aState[CoreId].PwmConfig->PwmInstancesConfig)[Index]), Pwm_eTargetPowerState[CoreId]);
                            }
#endif
                            for(Index = 0; Index < Pwm_aState[CoreId].PwmConfig->NumChannels; Index++)
                            {
                                Pwm_Ipw_SetPowerStateChannel(Pwm_eTargetPowerState[CoreId], &((*Pwm_aState[CoreId].PwmChannelConfigs)[Index].IpwChannelCfg));
                            }

                            *Result = PWM_SERVICE_ACCEPTED;
                            Pwm_eCurrentPowerState[CoreId] = Pwm_eTargetPowerState[CoreId];
                            Pwm_eTargetPowerState[CoreId] = PWM_NODEFINE_POWER;
                        }
                        else
                        {
                            (void)Det_ReportRuntimeError
                            (
                                (uint16) PWM_MODULE_ID,
                                (uint8)  PWM_INDEX,
                                (uint8)  PWM_SETPOWERSTATE_ID,
                                (uint8)  PWM_E_NOT_DISENGAGED
                            );

                            *Result = PWM_HW_FAILURE;
                        }
                        break;
                    default:
#if (PWM_PARAM_CHECK == STD_ON)
                        (void)Det_ReportError
                        (
                            (uint16) PWM_MODULE_ID,
                            (uint8)  PWM_INDEX,
                            (uint8)  PWM_SETPOWERSTATE_ID,
                            (uint8)  PWM_E_POWER_STATE_NOT_SUPPORTED
                        );
#endif
                        *Result = PWM_POWER_STATE_NOT_SUPP;
                        RetVal = (Std_ReturnType)E_NOT_OK;
                        break;
                }   
            }
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        }
        else
        {
            *Result = PWM_NOT_INIT;
        }

        Pwm_EndValidateGlobalConfigCall(CoreId, RetVal, PWM_SETPOWERSTATE_ID);
#endif
    }

    return RetVal;

}
#endif /* PWM_POWER_STATE_SUPPORTED */



/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Get the current power state of the Pwm HW unit.
* @details      This API returns the current power state of the Pwm HW unit.
*
* @param[out]   CurrentPowerState    The current power mode of the Pwm HW Unit is returned in this parameter
* @param[out]   Result               Pointer to a variable to store the result of this function
*
* @return       Std_ReturnType       Standard return type.
* @retval       E_OK                 Mode could be read.
* @retval       E_NOT_OK             Service is rejected.
*
* @implements   Pwm_GetCurrentPowerState_Activity
*
*/
Std_ReturnType Pwm_GetCurrentPowerState(Pwm_PowerStateType *              CurrentPowerState,
                                        Pwm_PowerStateRequestResultType * Result)
{
    Std_ReturnType  RetVal = (Std_ReturnType)E_OK;
    uint32          CoreId;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

    if ((NULL_PTR == Result) || (NULL_PTR == CurrentPowerState))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_PARAM_CHECK == STD_ON)
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_GETCURRENTPOWERSTATE_ID,
            (uint8)  PWM_E_PARAM_POINTER
        );
#endif
    }
    else
    {
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        RetVal = Pwm_ValidateGlobalConfigCall(CoreId, PWM_GETCURRENTPOWERSTATE_ID);

        if ((Std_ReturnType)E_OK == RetVal)
        {
#endif
            *CurrentPowerState = Pwm_eCurrentPowerState[CoreId];
            *Result = PWM_SERVICE_ACCEPTED;

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        }
        else
        {
            *Result = PWM_NOT_INIT;
        }

        Pwm_EndValidateGlobalConfigCall(CoreId, RetVal, PWM_GETCURRENTPOWERSTATE_ID);
#endif
    }

    return RetVal;

}
#endif /* PWM_POWER_STATE_SUPPORTED */



/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Get the target power state of the Pwm HW unit.
* @details      This API returns the target power state of the Pwm HW unit.
*
* @param[out]   TargetPowerState     The Target power mode of the Pwm HW Unit is returned in this parameter.
* @param[out]   Result               Pointer to a variable to store the result of this function.
*
* @return       Std_ReturnType       Standard return type.
* @retval       E_OK                 Mode could be read.
* @retval       E_NOT_OK             Service is rejected.
*
* @implements   Pwm_GetTargetPowerState_Activity
*
*/
Std_ReturnType Pwm_GetTargetPowerState(Pwm_PowerStateType *              TargetPowerState,
                                       Pwm_PowerStateRequestResultType * Result)
{
    Std_ReturnType              RetVal = (Std_ReturnType)E_OK;
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    Std_ReturnType              CallIsValid;
#endif
    uint32                      CoreId;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

    if ((NULL_PTR == Result) || (NULL_PTR == TargetPowerState))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_PARAM_CHECK == STD_ON)
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_GETTARGETPOWERSTATE_ID,
            (uint8)  PWM_E_PARAM_POINTER
        );
#endif
    }
    else
    {
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        CallIsValid = Pwm_ValidateGlobalConfigCall(CoreId, PWM_GETTARGETPOWERSTATE_ID);

        if ((Std_ReturnType)E_OK == CallIsValid)
        {
#endif
            *TargetPowerState = Pwm_eTargetPowerState[CoreId];
            *Result = PWM_SERVICE_ACCEPTED;

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
            *Result = PWM_NOT_INIT;
        }

        Pwm_EndValidateGlobalConfigCall(CoreId, CallIsValid, PWM_GETTARGETPOWERSTATE_ID);
#endif
    }

    return RetVal;

}
#endif /* PWM_POWER_STATE_SUPPORTED */



/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        Starts the needed process to allow the Pwm HW module to enter the requested power state.
* @details      This API starts the needed process to allow the Pwm HW module to enter the requested power state.
*
* @param[in]    PowerState      The target power state intended to be attained.
* @param[out]   Result          Pointer to a variable to store the Result of this function.
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK            Mode could be read.
* @retval       E_NOT_OK        Service is rejected.
*
* @implements   Pwm_PreparePowerState_Activity
*
*/
Std_ReturnType Pwm_PreparePowerState(Pwm_PowerStateType                PowerState,
                                     Pwm_PowerStateRequestResultType * Result)
{
    Std_ReturnType              RetVal = (Std_ReturnType)E_OK;
    uint32                      CoreId;

    /* Get core ID of current processor */
    CoreId = Pwm_GetCoreID();

    if (NULL_PTR == Result)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_PARAM_CHECK == STD_ON)
        (void)Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8)  PWM_INDEX,
            (uint8)  PWM_PREPAREPOWERSTATE_ID,
            (uint8)  PWM_E_PARAM_POINTER
        );
#endif
    }
    else
    {
#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        RetVal = Pwm_ValidateGlobalConfigCall(CoreId, PWM_PREPAREPOWERSTATE_ID);

        if ((Std_ReturnType)E_OK == RetVal)
        {
#endif
            if (Pwm_eCurrentPowerState[CoreId] != PowerState)
            {
                if ((PWM_LOW_POWER != PowerState) && (PWM_FULL_POWER != PowerState))
                {
                    *Result = PWM_POWER_STATE_NOT_SUPP;
                    RetVal = (Std_ReturnType)E_NOT_OK;

#if (PWM_PARAM_CHECK == STD_ON)
                    (void)Det_ReportError
                    (
                        (uint16) PWM_MODULE_ID,
                        (uint8)  PWM_INDEX,
                        (uint8)  PWM_PREPAREPOWERSTATE_ID,
                        (uint8)  PWM_E_POWER_STATE_NOT_SUPPORTED
                    );
#endif
                }
                else
                {
                    *Result = PWM_SERVICE_ACCEPTED;
                    Pwm_eTargetPowerState[CoreId] = PowerState;
                }
            }
            else
            {
                *Result = PWM_SEQUENCE_ERROR;
                RetVal = (Std_ReturnType)E_NOT_OK;
            }

#if (PWM_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
        }
        else
        {
            *Result = PWM_NOT_INIT;
        }

        Pwm_EndValidateGlobalConfigCall(CoreId, RetVal, PWM_PREPAREPOWERSTATE_ID);
#endif
    }

    return RetVal;
}
#endif /* PWM_POWER_STATE_SUPPORTED */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
