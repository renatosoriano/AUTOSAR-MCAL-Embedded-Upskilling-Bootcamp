/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Ftm_Srtc_Lptmr_LPit
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 2.0.0
* Build Version : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
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

#ifndef GPT_H
#define GPT_H

/**
*   @file       Gpt.h
*
*   @addtogroup gpt Gpt Driver
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
#include "Gpt_Ipw_Types.h"
#include "Gpt_EnvCfg.h"
#include "Mcal.h"
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    #include "EcuM_Externals.h"
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @internal
* @brief Defines used for file version checks
*/
#define GPT_VENDOR_ID                       43
#define GPT_MODULE_ID                       100
#define GPT_AR_RELEASE_MAJOR_VERSION        4
#define GPT_AR_RELEASE_MINOR_VERSION        7
#define GPT_AR_RELEASE_REVISION_VERSION     0
#define GPT_SW_MAJOR_VERSION                2
#define GPT_SW_MINOR_VERSION                0
#define GPT_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Mcal.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Gpt.h file and Mcal.h header file are of the same Autosar version */
    #if ((GPT_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt.h and Mcal.h are different"
    #endif
#endif
/* Check if header file and EcuM_Cbk.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        #if ((GPT_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
             (GPT_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Gpt.h and EcuM_Externals.h are different"
        #endif
    #endif
#endif

#if (GPT_VENDOR_ID != GPT_IPW_TYPES_VENDOR_ID)
    #error "Gpt.h and Gpt_Ipw_Types.h have different vendor ids"
#endif
/* Check if this header file and GPT IPW header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION != GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION != GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt.h and Gpt_Ipw_Types.h are different"
#endif
/* Check if this header file and GPT IPW header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION != GPT_IPW_TYPES_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION != GPT_IPW_TYPES_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION != GPT_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt.h and Gpt_Ipw_Types.h are different"
#endif

#if ( GPT_VENDOR_ID!= GPT_ENVCFG_VENDOR_ID)
    #error "Gpt.h and Gpt_EnvCfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != GPT_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION != GPT_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION != GPT_ENVCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt.h and Gpt_EnvCfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION != GPT_ENVCFG_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION != GPT_ENVCFG_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION != GPT_ENVCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt.h and Gpt_EnvCfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/

/*==================================================================================================*/
/**
* @brief        Function Gpt_StartTimer is called when the driver is in sleep mode for a channel which is not wakeup enabled.
* @details      Errors and exceptions that will be detected by the GPT driver.
*
* Gpt_Det_ErrorCodes_define
*/
#if(GPT_VALIDATE_STATE == STD_ON)
    #if(((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) || (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON))
        #define GPT_E_INVALID_CALL    ((uint8)0xA0U)
    #endif
#endif

/**
* @brief        Function called without module initialization.
* @details      Errors and exceptions that will be detected by the GPT driver.
*
* Gpt_Det_ErrorCodes_define
*/
#if((GPT_VALIDATE_CHANNEL_CALL == STD_ON) || (GPT_VALIDATE_GLOBAL_CALL == STD_ON))
    #define GPT_E_UNINIT        ((uint8)0x0AU)
#endif

/**
* @brief        Initialization called when already initialized.
* @details      Errors and exceptions that will be detected by the GPT driver.
*
* Gpt_Det_ErrorCodes_define
*/
#if(GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    #define GPT_E_ALREADY_INITIALIZED   ((uint8)0x0DU)
#endif

/**
* @brief        Function called for invalid channel.
* @details      Errors and exceptions that will be detected by the GPT driver.
*
* Gpt_Det_ErrorCodes_define
*/
#define GPT_E_PARAM_CHANNEL ((uint8)0x14U)

/**
* @brief        Function called with parameter value out of range
* @details      Errors and exceptions that will be detected by the GPT driver
*
* Gpt_Det_ErrorCodes_define
*/
#if (GPT_VALIDATE_PARAM == STD_ON)
    #define GPT_E_PARAM_VALUE   ((uint8)0x15U)
#endif

#if(((GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON) && (GPT_VALIDATE_PARAM == STD_ON)) ||\
    ((GPT_VERSION_INFO_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)))
/**
* @brief        Function called with NULL pointer
* @details      Errors and exceptions that will be detected by the GPT driver
*
* Gpt_Det_ErrorCodes_define
*/
#define GPT_E_PARAM_POINTER  ((uint8)0x16U)
#endif

#if((GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON) && (GPT_VALIDATE_PARAM == STD_ON))
/**
* @brief        Function called with invalid the parameter in function Gpt_GetPredefTimerValue
* @details      Errors and exceptions that will be detected by the GPT driver
*
* Gpt_Det_ErrorCodes_define
*/
#define GPT_E_PARAM_PREDEF_TIMER                  ((uint8)0x17)
#endif /* (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON) && (GPT_VALIDATE_PARAM == STD_ON) */

/**
* @brief        Function called when timer channel is still running.
* @details      Errors and exceptions that will be detected by the GPT driver.
*
* Gpt_Det_ErrorCodes_define
*/
    #define GPT_E_BUSY          ((uint8)0x0BU)
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief        Function called with invalid the parameter in function Gpt_GetPredefTimerValue
* @details      Errors and exceptions that will be detected by the GPT driver
*
* Gpt_Det_ErrorCodes_define
*/
    #define GPT_E_MODE                          ((uint8)0x0C)

#endif /* (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON) */
/**
* @brief        Function called when a timeout is occurred.
* @details      Errors and exceptions that will be detected by the GPT driver.
*
* Gpt_Det_ErrorCodes_define
*/
    #define GPT_E_TIMEOUT         ((uint8)0x2BU)
/**
* @brief        Function called with invalid the parameter in function Gpt_Init
* @details      Errors and exceptions that will be detected by the GPT driver
*
* Gpt_Det_ErrorCodes_define
*/
#if((GPT_VALIDATE_PARAM == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON))
    #define GPT_E_INIT_FAILED                  ((uint8)0x0E)
#endif

/**
* @brief        API Gpt_SetClockMode service called with wrong parameter.
* @details      Parameters used when raising an error/exception
* @implements
*/
#if((GPT_SET_CLOCK_MODE == STD_ON) && (GPT_VALIDATE_PARAM == STD_ON))
    #define GPT_E_PARAM_CLOCK_MODE                    ((uint8)0x17U)
#endif

/**
* @brief        Function  called with invalid mode param.
* @details      Errors and exceptions that will be detected by the GPT driver
*
* Gpt_Det_ErrorCodes_define
*/
#if ((GPT_VALIDATE_PARAM == STD_ON) &&(GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
    #define GPT_E_PARAM_MODE    ((uint8)0x1FU)
#endif

/**
* @brief function called for invalid channel on the current core
* @details Errors and exceptions that will be detected by the GPT driver
*
* Gpt_Det_ErrorCodes_define
*/
#define GPT_E_PARAM_CONFIG  ((uint8)0x18U)

/** API SERVICE IDs */

/**
* @brief        API service ID for Gpt_GetVersionInfo  function
* @details      Parameters used when raising an error/exception
*/
#if ((GPT_VERSION_INFO_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON))
    #define GPT_GETVERSIONINFO_ID       ((uint8)0x00U)
#endif
/**
* @brief        API service ID for Gpt_Init function
* @details      Parameters used when raising an error/exception
*/
#if ((GPT_VALIDATE_GLOBAL_CALL == STD_ON) || ((GPT_VALIDATE_PARAM == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)))
    #define GPT_INIT_ID                 ((uint8)0x01U)
#endif

/**
* @brief        API service ID for Gpt_DeInit function
* @details      Parameters used when raising an error/exception
*/
#if (GPT_DEINIT_API == STD_ON)
        #define GPT_DEINIT_ID               ((uint8)0x02U)
#endif

/**
* @brief        API service ID for Gpt_GetTimeElapsed function
* @details      Parameters used when raising an error/exception
*/
#if ((GPT_TIME_ELAPSED_API == STD_ON) && (GPT_VALIDATE_CHANNEL_CALL == STD_ON))
    #define GPT_TIMEELAPSED_ID          ((uint8)0x03U)
#endif

/**
* @brief        API service ID for Gpt_GetTimeRemaining function
* @details      Parameters used when raising an error/exception
*/
#if ((GPT_TIME_REMAINING_API == STD_ON) && (GPT_VALIDATE_CHANNEL_CALL == STD_ON))
    #define GPT_TIMEREMAINING_ID        ((uint8)0x04U)
#endif

/**
* @brief        API service ID for Gpt_StartTimer function
* @details      Parameters used when raising an error/exception
*/
#define GPT_STARTTIMER_ID           ((uint8)0x05U)

/**
* @brief        API service ID for Gpt_StopTimer function
* @details      Parameters used when raising an error/exception
*/
#if(GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    #define GPT_STOPTIMER_ID            ((uint8)0x06U)
#endif

#if((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) && ((GPT_VALIDATE_CHANNEL_CALL == STD_ON) || (GPT_VALIDATE_PARAM == STD_ON)))
/**
* @brief        API service ID for Gpt_EnableNotification function
* @details      Parameters used when raising an error/exception
*/
#define GPT_ENABLENOTIFICATION_ID   ((uint8)0x07U)

/**
* @brief        API service ID for Gpt_DisableNotification function
* @details      Parameters used when raising an error/exception
*/
#define GPT_DISABLENOTIFICATION_ID  ((uint8)0x08U)
#endif

/**
* @brief        API service ID for Gpt_SetMode function
* @details      Parameters used when raising an error/exception
*/
#if(((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_VALIDATE_GLOBAL_CALL == STD_ON)) ||\
    ((GPT_VALIDATE_PARAM == STD_ON) &&(GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)))
    #define GPT_SETMODE_ID              ((uint8)0x09U)
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))

#if((GPT_VALIDATE_CHANNEL_CALL == STD_ON) || (GPT_VALIDATE_PARAM == STD_ON))
/**
* @brief        API service ID for Gpt_DisableWakeup function
* @details      Parameters used when raising an error/exception
*/
#define GPT_DISABLEWAKEUP_ID        ((uint8)0x0AU)

/**
* @brief        API service ID for Gpt_EnableWakeup function
* @details      Parameters used when raising an error/exception
*/
#define GPT_ENABLEWAKEUP_ID         ((uint8)0x0BU)
#endif

/**
* @brief        API service ID for Gpt_CheckWakeup function
* @details      Parameters used when raising an error/exception
*/
#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    #define GPT_CHECKWAKEUP_ID          ((uint8)0x0CU)
#endif
#endif /* ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) */
/**
* @brief        API service ID for Gpt_ProcessCommonInterrupt generic ISR handler
* @details      Parameters used when raising an error/exception
*/
#define GPT_PROCESSCOMMONINTERRUPT_ID          ((uint8)0x11U)

/**
* @brief        API service ID for Gpt_ChangeNextTimeoutValue function
* @details      Parameters used when raising an error/exception
*/
#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
        #define GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID         ((uint8)0x0FU)
#endif

/**
* @brief        API service ID for Gpt_SetClockMode function
* @details      Parameters used when raising an error/exception
*/
#if((GPT_VALIDATE_GLOBAL_CALL == STD_ON) && (GPT_SET_CLOCK_MODE == STD_ON))
    #define GPT_SET_CLOCK_MODE_ID                       ((uint8)0x10U)
#endif

/**
* @brief        API service ID for Gpt_GetPredefTimerValue function
* @details      Parameters used when raising an error/exception
*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    #define GPT_GET_PREDEF_TIMERVALUE_ID                ((uint8)0x0DU)
#endif

/**
* @brief        API service ID for Gpt_Channel_EnableChainMode function
* @details      Parameters used when raising an error/exception
*/
#if(GPT_CHAIN_MODE == STD_ON)
    #define GPT_ENABLE_CHAIN_MODE_ID               ((uint8)0x21U)
    #define GPT_DISABLE_CHAIN_MODE_ID              ((uint8)0x22U)
#endif

/**
* @brief Instance ID of this GPT driver.
*
*/
#define GPT_INSTANCE_ID   ((uint8)0U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief   This enumerated type allows the selection of different power modes.
* @details Modes of the GPT driver.
*
* @implements Gpt_ModeType_enumeration
*/
typedef enum
{
    GPT_MODE_NORMAL = 0U,             /**< @brief GPT Normal operation mode of the GPT */
    GPT_MODE_SLEEP = 1U               /**< @brief GPT Sleep mode */
} Gpt_ModeType;

/**
* @brief    Gpt channel mode type. Indicates of whether the channel mode is "CONTINUOUS" or "ONE SHOT".
* @details  ChannelModeType of channel.
*/
typedef enum
{
    GPT_CH_MODE_CONTINUOUS = 0U,      /**< @brief GPT channel mode -  continuous mode */
    GPT_CH_MODE_ONESHOT    = 1U       /**< @brief GPT channel mode -  one-shot mode. */
} Gpt_ChannelModeType;

/**
* @brief    Prescaler type. Indicates of whether the clock channel mode is "GPT_NORMAL" or "GPT_ALTERNATE".
* @details  This enumeration specifies the possible types of prescalers used to configure base-clock timers
*/
#if (GPT_SET_CLOCK_MODE == STD_ON)
typedef enum
{
    GPT_CLOCKMODE_NORMAL    = 0x0U,  /**< @brief Selected value is the NORMAL configured prescaler */
    GPT_CLOCKMODE_ALTERNATE = 0x1U   /**< @brief Selected value is the ALTERNATE configured prescaler */
} Gpt_ClockModeType;
#endif /* GPT_SET_CLOCK_MODE */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @internal
* @brief    Gpt channel ID data type
* @details  Gpt channel type
* @implements Gpt_ChannelType_typedef
*/
typedef uint8 Gpt_ChannelType;

/**
* @internal
* @brief    Used for reading and setting the timer value in number of ticks.
* @details  Gpt timeout value type
* @implements Gpt_ValueType_typedef
*/
typedef uint32 Gpt_ValueType;

/**
* @internal
* @brief    The callback notifications shall be configurable as pointers to
*           user defined functions within the configuration structure.
* @details  Gpt channel notification type.
*
*/
typedef void (*Gpt_NotificationType)(void);

/**
* @internal
* @brief    Gpt channel configuration type.
* @details  Configuration structure
*
*/
typedef struct
{
    /** @brief GPT ch WakeUp enable */
    boolean Gpt_bEnableWakeup;
    /** @brief Pointer to external callback */
    Gpt_NotificationType Gpt_pfNotification;

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
    /** @brief EcuM wake up source Id */
    EcuM_WakeupSourceType Gpt_uWakeupSource;
#endif
    /** @brief Channel max tick value */
    Gpt_ValueType Gpt_uChannelTickValueMax;
    /** @brief GPT channel mode */
    Gpt_ChannelModeType Gpt_eChannelMode;
    /** @brief Hardware dependent channel configuration */
    Gpt_Ipw_HwChannelConfigType *Gpt_Ipw_HwChannelConfig;
} Gpt_ChannelConfigType;

/**
* @internal
* @brief        Gpt configuration type.
* @details      This is the type of the data structure including the configuration
*               set required for initializing the GPT driver.
*
* @implements   Gpt_ConfigType_structure
*/
typedef struct
{
    /** @brief Number of GPT channels (configured in tresos plugin builder) */
    Gpt_ChannelType              channelCount;
    /** @brief Pointer to the GPT channel configuration */
    const Gpt_ChannelConfigType        (*Gpt_pChannelConfig)[];
    /** @brief Number of GPT instances (configured in tresos plugin builder) */
    uint8 instanceCount;
    /** @brief Pointer to the GPT instance configuration */
    Gpt_Ipw_HwInstanceConfigType (*Gpt_Ipw_HwInstanceConfig)[];
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    /** @brief Pointer to the GPT channel predef timer configuration */
    const Gpt_HwPredefChannelConfigType * const (*Gpt_pChannelPredefConfigType);
#endif
    /** @brief channel index in each partition map table*/
    const uint8                  (*u8GptChannelIdToIndexMap)[];
} Gpt_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)
/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if header file and MemMap.h file are of the same Autosar version */
 #if ((GPT_AR_RELEASE_MAJOR_VERSION != GPT_MEMMAP_AR_RELEASE_MAJOR_VERSION) || \
      (GPT_AR_RELEASE_MINOR_VERSION != GPT_MEMMAP_AR_RELEASE_MINOR_VERSION))
     #error "AutoSar Version Numbers of Gpt.h and Gpt_MemMap.h are different"
 #endif
#endif

GPT_CONFIG_EXT

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

#else

/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if header file and MemMap.h file are of the same Autosar version */
 #if ((GPT_AR_RELEASE_MAJOR_VERSION != GPT_MEMMAP_AR_RELEASE_MAJOR_VERSION) || \
      (GPT_AR_RELEASE_MINOR_VERSION != GPT_MEMMAP_AR_RELEASE_MINOR_VERSION))
     #error "AutoSar Version Numbers of Gpt.h and Gpt_MemMap.h are different"
 #endif
#endif
/* Extern declarations of GPT Pre compile configuration from Gpt_PBCfg.c */
#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
    #if(GPT_MULTICORE_ENABLED == STD_ON)
extern const Gpt_ConfigType* const Gpt_Config[GPT_MAX_PARTITIONS];
    #else
extern const Gpt_ConfigType Gpt_Config;
    #endif
#endif

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

#endif

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/*================================================================================================*/
#if (GPT_VERSION_INFO_API == STD_ON)
/**
* @brief       This function returns the version information of this module.
* @details     This service returns the version information of this module. The version information
*              includes:
*                    - Module Id
*                    - Vendor Id
*                    - Vendor specific version numbers
*              If source code for caller and callee of this function is available this function should
*              be realized as a macro. The macro should be defined in the modules header file.
* @param[out]  versioninfo - pointer to location to store version info
*
* @return       void
* @api
*
* @pre          Gpt_Init must be called before.
* @implements   Gpt_GetVersionInfo_Activity
*/
void Gpt_GetVersionInfo(Std_VersionInfoType * VersionInfoPtr);
#endif

/*================================================================================================*/
/**
* @brief        GPT driver initialization function.
* @details      This service is a non reentrant function used for driver initialization.
*               The Initialization function shall initialize all relevant registers of
*               the configured hardware with the values of the structure referenced by the parameter ConfigPtr.
*               All time units used within the API services of the GPT driver shall be of the unit ticks.
*               This function shall only initialize the configured resources. Resources that are
*               not configured in the configuration file shall not be touched.
*               The following rules regarding initialization of controller registers shall apply
*               to the GPT Driver implementation:
*           [1] If the hardware allows for only one usage of the register, the driver
*               module implementing that functionality is responsible for initializing the register
*           [2] If the register can affect several hardware modules and if it is an IO register it
*               shall be initialized by the PORT driver
*           [3] If the register can affect several hardware modules and if it is not an IO register
*               it shall be initialized by the MCU driver
*           [4] One-time writable registers that require initialization directly after reset shall be
*               initialized by the startup code
*           [5] All other registers shall be initialized by the startup code
*
* @param[in]    configPtr    Pointer to a selected configuration structure
*
* @return       void
* @api
*
* @pre          The data structure including the configuration set required for initializing the GPT driver..
* @implements   Gpt_Init_Activity
*/
void Gpt_Init (const Gpt_ConfigType * configPtr);

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief        GPT driver de-initialization function.
* @details      Service for de initializing all hardware timer channels to their power on reset state.
*               The state of the peripheral after DeInit shall be the same as after power on reset.
*               The service influences only the peripherals, which are allocated by static
*               configuration and the runtime configuration set passed by the previous call of Gpt_Init()
*               The driver needs to be initialized before calling Gpt_DeInit(). Otherwise, the
*               function Gpt_DeInit shall raise the development error GPT_E_UNINIT and leave the desired
*               de initialization functionality without any action.
*
* @api
* @return       void
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_DeInit_Activity
*/
void Gpt_DeInit(void);
#endif

/*================================================================================================*/
#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
* @brief        GPT driver function for fetching the elapsed timer value.
* @details      Service for querying the time already elapsed.
*               In one shot mode, this is the value relative to the point in time, the channel has been
*               started with Gpt_StartTimer (calculated by the normal operation function by subtracting
*               the current minus the initial timer value and returning the absolute value).
*               In continuous mode, the function returns the timer value relative to the last timeout or
*               the start of the channel.
*               All time units used within the API services of the GPT driver shall be of the unit ticks.
*               Usage of re-entrant capability is only allowed if the callers take care that
*               there is no simultaneous usage of the same channel.
*               To get times out of register values it is necessary to know the oscillator frequency, pre
*               prescalers and so on. Since these settings are made in MCU and(or) in other modules it is
*               not possible to calculate such times. Hence the conversions between time and ticks shall
*               be part of an upper layer.
*               The driver needs to be initialized before calling Gpt_GetTimeElapsed(). Otherwise, the
*               function shall raise the development error GPT_E_UNINIT and return 0.
*
* @param[in]    channel - channel id
*
* @return       Gpt_ValueType - Elapsed Time in number of ticks
*
* @api
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_GetTimeElapsed_Activity
*/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType channel);
#endif

/*================================================================================================*/
#if (GPT_TIME_REMAINING_API == STD_ON)
/**
* @brief        GPT driver function for fetching the remaining timer value.
* @details      This function returns the timer value remaining until the next timeout period will
*               expire (calculated by the normal operation function by subtracting the timeout minus
*               the current timer value and returning the absolute value)
*               All time units used within the API services of the GPT driver shall be of the unit ticks.
*               Usage of re-entrant capability is only allowed if the callers take care that there is no
*               simultaneous usage of the same channel.
*               To get times out of register values it is necessary to know the oscillator frequency,
*               pre-scalers and so on. Since these settings are made in MCU and(or) in other modules it is
*               not possible to calculate such times. Hence the conversions between time and ticks shall
*               be part of an upper layer.
*               The driver needs to be initialized before calling Gpt_GetTimeRemaining(). Otherwise, the
*               function shall raise the development error GPT_E_UNINIT and return 0.
*
*
* @param[in]    channel - channel id
*
* @return       Gpt_ValueType - Returns the time remaining until the target time is reached in number of ticks.
*
* @api
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_GetTimeRemaining_Activity
*/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType channel);
#endif
/*================================================================================================*/
/**
* @brief        GPT driver function for starting a timer channel.
* @details      The function Gpt_StartTimer shall start the selected timer channel with a defined
*               time-out period.
*               The function Gpt_StartTimer shall invoke the configured notification for that channel
*               (see also GPT292) after the time-out period referenced via the parameter value (if
*               enabled).
*               All time units used within the API services of the GPT driver shall be of the unit ticks.
*               In production mode no error is generated. The rational is that it adds no
*               additional functionality to the driver. In this case the timer will be restarted with the
*               time-out value, given as a parameter to the service.
*               Usage of re-entrant capability is only allowed if the callers take care that
*               there is no simultaneous usage of the same channel.
*               To get times out of register values it is necessary to know the oscillator
*               frequency, pre-scalers and so on. Since these settings are made in MCU and(or) in other
*               modules it is not possible to calculate such times. Hence the conversions between time
*               and ticks shall be part of an upper layer.
*               The driver needs to be initialized before calling Gpt_StartTimer(). Otherwise, the
*               function Gpt_StartTimer shall raise the development error GPT_E_UNINIT.
*
* @param[in]    channel channel id
* @param[in]    value   time-out period (in number of ticks) after a notification or a wakeup event shall occur.
*
* @return       void
* @api
* @pre          The driver needs to be initialized.
* @implements   Gpt_StartTimer_Activity
*/
void Gpt_StartTimer(Gpt_ChannelType channel,Gpt_ValueType value);

/*================================================================================================*/
/**
* @brief        GPT driver function for stopping a timer channel.
* @details      Service for stopping the selected timer channel
*               Stopping a timer channel, not been started before will not return a development error
*               Timer channels configured in one shot mode are stopped automatically, when the
*               time-out period has expired.
*               Usage of re-entrant capability is only allowed if the callers take care that
*               there is no simultaneous usage of the same channel.
*               The driver needs to be initialized before calling Gpt_StopTimer(). Otherwise,
*               the function shall raise the development error GPT_E_UNINIT.
*
* @param[in]    channel   channel id
* @return       void
*
* @api
* @pre          The driver needs to be initialized. Gpt_StartTimer must be called before.
* @implements   Gpt_StopTimer_Activity
*/
void Gpt_StopTimer(Gpt_ChannelType channel);

/*================================================================================================*/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
* @brief        GPT driver function for enabling the notification for a timer channel.
* @details      Service for enabling the notification for a channel during runtime.
*               This function can be called, while the timer is already running.
*               Usage of re-entrant capability is only allowed if the callers take care that
*               there is no simultaneous usage of the same channel.
*               The driver needs to be initialized before calling Gpt_EnableNotification(). Otherwise,
*               the function Gpt_EnableNotification shall raise the development error GPT_E_UNINIT.
*
* @param[in]    channel     channel id
* @return       void
* @api
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_EnableNotification_Activity
*/
void Gpt_EnableNotification(Gpt_ChannelType channel);
/*================================================================================================*/
/**
* @brief        GPT driver function for disabling the notification for a timer channel.
* @details      Service for disabling the notification for a channel during runtime.
*               This function can be called, while the timer is already running
*               When disabled, no notification will be sent. When re-enabled again, the user
*               will not be notified of events, occurred while notifications have been disabled.
*               Usage of re-entrant capability is only allowed if the callers take care that
*               there is no simultaneous usage of the same channel.
*               The driver needs to be initialized before calling Gpt_DisableNotification().
*               Otherwise, the function shall raise the development error GPT_E_UNINIT.
*
* @param[in]    channel        channel id
* @return       void
* @api
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_DisableNotification_Activity
*/
void Gpt_DisableNotification(Gpt_ChannelType channel);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/**
* @brief        GPT driver function for setting the operation mode.
* @details      Service for GPT mode selection. This service shall set the operation mode to the given
*               mode parameter .
*               When sleep mode is requested, the ECU State Manager calls Gpt_SetMode with mode
*               parameter "GPT_MODE_SLEEP" and prepares the GPT for sleep mode. The MCU Driver is then
*               putting the controller into SLEEP mode
*               The driver needs to be initialized before calling Gpt_SetMode(). Otherwise, the
*               function Gpt_SetMode shall raise the development error GPT_E_UNINIT.
*
* @param[in]    eMode        operation mode :
*                           - GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
*                           - GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable)
* @return       void
* @api
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_SetMode_Activity
*/
void Gpt_SetMode(Gpt_ModeType Mode);
/*================================================================================================*/
/**
* @brief        GPT driver function for disabling the wakeup interrupt invocation for a timer channel.
* @details      This service shall disable the wakeup interrupt invocation of a single GPT
*               channel.
*               Usage of re-entrant capability is only allowed if the callers take care that
*               there is no simultaneous usage of the same channel.
*               The driver needs to be initialized before calling Gpt_DisableWakeup(). Otherwise, the
*               function Gpt_DisableWakeup shall raise the development error GPT_E_UNINIT.
*
* @param[in]    channel        channel id
* @return       void
* @api
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_DisableWakeup_Activity
*/
void Gpt_DisableWakeup(Gpt_ChannelType channel);

/*================================================================================================*/
/**
* @brief        GPT driver function for enabling the wakeup interrupt invocation for a timer channel.
* @details      This service shall re-enable the wakeup interrupt invocation of a single GPT
*               channel.
*               If supported by hardware and enabled, an internal hardware timer can serve as a
*               wakeup source
*               Usage of re-entrant capability is only allowed if the callers take care that
*               there is no simultaneous usage of the same channel.
*
* @param[in]    channel        channel id
* @return       void
* @api
*
* @pre          The driver needs to be initialized. The channel must be configured as wakeup capable.
* @implements   Gpt_EnableWakeup_Activity
*/
void Gpt_EnableWakeup(Gpt_ChannelType channel);

/*================================================================================================*/
/**
* @brief        GPT driver function for checking if a wakeup capable GPT channel is the source for a
*               wakeup event.
* @details      Checks if a wakeup capable GPT channel is the source for a wakeup event and calls the ECU
*               state manager service EcuM_SetWakeupEvent in case of a valid GPT channel wakeup event.
*               The driver needs to be initialized before calling Gpt_CheckWakeup(). Otherwise, the
*               function Gpt_CheckWakeup shall raise the development error GPT_E_UNINIT.
*
* @param[in]    wakeupSource        wakeup source
* @return       void
* @api
*
* @pre          The driver needs to be initialized. The channel must be configured as wakeup capable.
* @implements   Gpt_CheckWakeup_Activity
*/
void Gpt_CheckWakeup(EcuM_WakeupSourceType wakeupSource);
#endif

/*================================================================================================*/
#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief        The function changes the time out period value of the requested running channel.
* @details      The function changes the time out period (in number of ticks) of the channel is
*               running which will be used after the first compare matching.
*               This is a non-autosar function.
* @param[in]    channel        channel id
* @param[in]    value          time out period (in number of ticks) after a notification shall occur
* @return       void
* @pre          Gpt_Init and Gpt_StartTimer must be called before.
* @implements   Gpt_ChangeNextTimeoutValue_Activity
*/
void Gpt_ChangeNextTimeoutValue
(
    Gpt_ChannelType channel,
    Gpt_ValueType value
);
#endif

/*================================================================================================*/
#if (GPT_SET_CLOCK_MODE == STD_ON)
/**
* @brief        This function changes the channel pre scaler.
* @details      This function sets all channels pre scalers based on the input mode.
*
* @param[in]    eClkMode   pre scaler setting ( NORMAL or ALTERNATE )
* @return       void
* @pre          Gpt_Init must be called before.
*
*
*
*
*/
void Gpt_SetClockMode(Gpt_ClockModeType eClkMode);
#endif

/*================================================================================================*/
#if (GPT_CHAIN_MODE == STD_ON)
/**
* @brief        The function enables the chain functionality for timer.
* @details      The function enables the chain functionality for timer. Timer will be chained with timer n-1.
                Channel 0 cannot be chained.
*               This is a non-autosar function.
* @param[in]    channel        channel id
* @return       void
* @pre          Gpt_Init must be called before.
*
* @implements   Gpt_Channel_EnableChainMode_Activity
*/
void Gpt_Channel_EnableChainMode(Gpt_ChannelType channel);

/*================================================================================================*/
/**
* @brief        The function disables the chain functionality for timer.
* @details      The function disables the chain functionality for timer. Timer will not be chained with timer n-1.
                Channel 0 cannot be chained or unchained.
*               This is a non-autosar function.
* @param[in]    channel        channel id
* @return       void
* @pre          Gpt_Init must be called before.
*
* @implements   Gpt_Channel_DisableChainMode_Activity
*/
void Gpt_Channel_DisableChainMode(Gpt_ChannelType channel);
#endif

/*================================================================================================*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief        Provides the current value of the given predefined free-running timer
* @details      This function provides the current value of the given predefined free-running timer.
*
* @param[in]    PredefTimer: Gpt_PredefTimerType ( GPT_PREDEF_TIMER_1US_16BIT,
*                                               GPT_PREDEF_TIMER_1US_24BIT,
*                                               GPT_PREDEF_TIMER_1US_32BIT
*                                               GPT_PREDEF_TIMER_100US_32BIT)
* @param[out]   TimeValuePtr: Pointer to time value destination data in RAM
* @pre          Gpt_Init must be called before.
* @return       returnValue  - E_OK: no error has been detected.
*                            - E_NOT_OK: aborted due to errors.
*
*
* @implements   Gpt_GetPredefTimerValue_Activity
*/
Std_ReturnType Gpt_GetPredefTimerValue
(
    Gpt_PredefTimerType PredefTimer,
    uint32 * TimeValuePtr
);
#endif

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
#endif /* GPT_H */
