/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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

#ifndef ICU_CFG_H
#define ICU_CFG_H

/**
*   @file Icu_Cfg.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Icu - contains the configuration data of the ICU driver
*   @details Contains the configuration data of the ICU driver
*
*   @addtogroup icu Icu Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_EnvCfg.h"
#include "Std_Types.h"
#include "Icu_VS_0_PBcfg.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_CFG_VENDOR_ID                       43
#define ICU_CFG_AR_RELEASE_MAJOR_VERSION        4
#define ICU_CFG_AR_RELEASE_MINOR_VERSION        7
#define ICU_CFG_AR_RELEASE_REVISION_VERSION     0
#define ICU_CFG_SW_MAJOR_VERSION                2
#define ICU_CFG_SW_MINOR_VERSION                0
#define ICU_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Icu_EnvCfg header file are of the same vendor */
#if (ICU_CFG_VENDOR_ID != ICU_ENVCFG_VENDOR_ID)
    #error "Icu_Cfg.h and Icu_EnvCfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_EnvCfg header file are of the same AutoSar version */
#if ((ICU_CFG_AR_RELEASE_MAJOR_VERSION != ICU_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_CFG_AR_RELEASE_MINOR_VERSION != ICU_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_CFG_AR_RELEASE_REVISION_VERSION != ICU_ENVCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_EnvCfg.h are different"
#endif
/* Check if source file and Icu_EnvCfg header file are of the same Software version */
#if ((ICU_CFG_SW_MAJOR_VERSION != ICU_ENVCFG_SW_MAJOR_VERSION) || \
     (ICU_CFG_SW_MINOR_VERSION != ICU_ENVCFG_SW_MINOR_VERSION) || \
     (ICU_CFG_SW_PATCH_VERSION != ICU_ENVCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Cfg.h and Icu_EnvCfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Cfg.h and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU configuration header file are of the same vendor */
#if (ICU_VS_0_PBCFG_VENDOR_ID != ICU_CFG_VENDOR_ID)
    #error "Icu_VS_0_PBcfg.h and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if header file and Icu configuration header file are of the same Autosar version */
#if ((ICU_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION != ICU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION != ICU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION != ICU_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_VS_0_PBcfg.h and Icu_Cfg.h are different"
#endif
/* Check if header file and Icu configuration header file are of the same software version */
#if ((ICU_VS_0_PBCFG_SW_MAJOR_VERSION != ICU_CFG_SW_MAJOR_VERSION) || \
     (ICU_VS_0_PBCFG_SW_MINOR_VERSION != ICU_CFG_SW_MINOR_VERSION) || \
     (ICU_VS_0_PBCFG_SW_PATCH_VERSION != ICU_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_VS_0_PBcfg.h and Icu_Cfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define ICU_CONFIG_EXT \
        ICU_CONFIG_VS_0_PB \


/** @brief Maximum number of ICU channels configured. */
#define ICU_MAX_CHANNEL                 ((Icu_ChannelType)2U)

/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*        STD_ON: Enabled.
*        STD_OFF: Disabled.
*   @implements ICU_DEV_ERROR_DETECT_define
*/
#define ICU_DEV_ERROR_DETECT            (STD_OFF)

/**
*   @brief  Switch for enabling Wakeup source reporting.
*        STD_ON: Report Wakeup source.
*        STD_OFF: Do not report Wakeup source.
*
*/
#define ICU_REPORT_WAKEUP_SOURCE        (STD_OFF)

/**
* @brief Support for User mode.
*        If this parameter has been configured to STD_ON, the ICU driver code can be executed from both supervisor and user mode.
*/
#define ICU_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef ICU_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == ICU_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == ICU_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef ICU_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/** @brief Configuration of Optional APIs. */
/**
*   @brief  Adds or removes the service Icu_GetVersionInfo() from the code.
*        STD_ON: Icu_GetVersionInfo() can be used.
*        STD_OFF: Icu_GetVersionInfo() can not be used.
*
*/
#define ICU_GET_VERSION_INFO_API          (STD_OFF)

/**
*   @brief  Adds or removes the service Icu_DeInit() from the code.
*        STD_ON: Icu_DeInit() can be used. STD_OFF: Icu_DeInit() can not be used.
*   @implements ICU_DE_INIT_API_define
*/
#define ICU_DE_INIT_API                   (STD_ON)

/**
*   @brief  Adds or removes the service Icu_SetMode() from the code.
*        STD_ON: Icu_SetMode() can be used.
*        STD_OFF: Icu_SetMode() can not be used.
*   @implements ICU_SET_MODE_API_define
*/
#define ICU_SET_MODE_API                  (STD_OFF)

/**
*   @brief  Adds or removes the service Icu_DisableWakeup() from the code.
*        STD_ON: Icu_DisableWakeup() can be used.
*        STD_OFF: Icu_DisableWakeup() can not be used.
*   @implements ICU_DISABLE_WAKEUP_API_define
*/
#define ICU_DISABLE_WAKEUP_API            (STD_OFF)

/**
*   @brief  Adds or removes the service Icu_EnableWakeup() from the code.
*        STD_ON: Icu_EnableWakeup() can be used.
*        STD_OFF: Icu_EnableWakeup() can not be used.
*   @implements ICU_ENABLE_WAKEUP_API_define
*/
#define ICU_ENABLE_WAKEUP_API             (STD_OFF)

/**
*   @brief  Adds or removes all services related to the timestamping functionality as listed
*        below from the code: Icu_StartTimestamp(), Icu_StopTimestamp(), Icu_GetTimestampIndex().
*        STD_ON: The services listed above can be used.
*        STD_OFF: The services listed above can not be used.
*   @implements ICU_TIMESTAMP_API_define
*/
#define ICU_TIMESTAMP_API                 (STD_OFF)

/**
*   @brief  Adds or removes all services related to the edge counting functionality as listed below,
*           from the code: Icu_ResetEdgeCount(), Icu_EnableEdgeCount(), Icu_DisableEdgeCount(),
*           Icu_GetEdgeNumbers().
*        STD_ON: The services listed above can be used.
*        STD_OFF: The services listed above can not be used.
*   @implements ICU_EDGE_COUNT_API_define
*/
#define ICU_EDGE_COUNT_API                (STD_OFF)

/**
*   @brief  Adds or removes the service Icu_GetTimeElapsed() from the code.
*        STD_ON: Icu_GetTimeElapsed() can be used.
*        STD_OFF: Icu_GetTimeElapsed() can not be used.
*   @implements ICU_GET_TIME_ELAPSED_API_define
*/
#define ICU_GET_TIME_ELAPSED_API          (STD_OFF)

/**
*   @brief  Adds or removes the service Icu_GetDutyCycleValues() from the code.
*        STD_ON: Icu_GetDutyCycleValues() can be used.
*        STD_OFF: Icu_GetDutyCycleValues() can not be used.
*   @implements ICU_GET_DUTY_CYCLE_VALUES_API_define
*/
#define ICU_GET_DUTY_CYCLE_VALUES_API     (STD_OFF)

/**
*   @brief  Adds or removes the service Icu_GetInputState() from the code.
*        STD_ON: Icu_GetInputState() can be used.
*        STD_OFF: Icu_GetInputState() can not be used.
*   @implements ICU_GET_INPUT_STATE_API_define
*/
#define ICU_GET_INPUT_STATE_API           (STD_OFF)

/**
*   @brief  Adds or removes the services Icu_StartSignalMeasurement() and
*          Icu_StopSignalMeasurement() from the code.
*        STD_ON: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can be used.
*        STD_OFF: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can not be used.
*   @implements ICU_SIGNAL_MEASUREMENT_API_define
*/
#define ICU_SIGNAL_MEASUREMENT_API        (STD_OFF)

/**
*   @brief  Adds or removes the service Icu_CheckWakeup() from the code.
*        STD_ON: Icu_CheckWakeup() can be used.
*        STD_OFF: Icu_CheckWakeup() can not be used.
*   @implements ICU_WAKEUP_FUNCTIONALITY_API_define
*/
#define ICU_WAKEUP_FUNCTIONALITY_API      (STD_OFF)

/**
*   @brief  Adds or removes the services Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection()
*           from the code.
*        STD_ON: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() can be used.
*        STD_OFF: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() can not be used.
*
*   @implements  ICU_EDGE_DETECT_API_define
*/
#define ICU_EDGE_DETECT_API               (STD_ON)

/**
*   @brief  Implementation specific parameter
*        Adds or Removes the code related to overflow notification
*        STD_ON: Overflow notification function will be called if overflow occurs
*        STD_OFF: Overflow notification function will not be called though overflow occurs
*
*/
#define ICU_OVERFLOW_NOTIFICATION_API     (STD_OFF)

/**
 * @brief Adds or removes the service Icu_GetInputLevel() from the code.
 *         STD_ON:  Icu_GetInputLevel() can be used.
 *         STD_OFF: Icu_GetInputLevel() can not be used.
 */
#define ICU_GET_INPUT_LEVEL_API           (STD_ON)

/**
*   @brief   Adds / removes the service Icu_GetPulseWidth() from the code.
*         STD_ON:  Icu_GetPulseWidth() can be used.
*         STD_OFF: Icu_GetPulseWidth() can not be used.
*/
#define ICU_GET_PULSE_WIDTH_API           (STD_OFF)

/**
 * @brief Adds or removes the for support Signal Measurement with DMA.
 *        STD_ON:  DMA in Signal Measurement can be used.
 *        STD_OFF: DMA in Signal Measurement can not be used.
 */
#define ICU_SIGNALMEASUREMENT_USES_DMA    (STD_OFF)

/**
 * @brief Adds or removes the support for TimeStamp Measurement with DMA.
 *        STD_ON:  DMA in TimeStamp Measurement can be used.
 *        STD_OFF: DMA in TimeStamp Measurement can not be used.
 */
#define ICU_TIMESTAMP_USES_DMA            (STD_OFF)

#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
/**
 * @brief Implementation specific.
 *        Each channel provides a subset of the functionality available in the unified channel,
 *        at a resolution of 32 bits.
 */
#define ICU_CAPTURE_REGISTER_MASK(value)  (value)
#endif

#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
/**
 * @brief Implementation specific.
 *        Each channel provides a DMA resolution of 32 bits.
 */
#define ICU_DMA_SIZE                (DMA_IP_TRANSFER_SIZE_4_BYTE)

/**
 * @brief Implementation specific.
 *        DMA number of bytes transfer on a minor loop is 4 bytes - for 32 bits hw registers.
 */
#define ICU_DMA_NUM_BYTES           (4U)

/**
 * @brief Implementation specific.
 *        DMA offset is 32 bits HW registers.
 */
#define ICU_DMA_OFFSET              (4U)

/** @brief Define when no MCL DMA channel is used. */
#define NoMclDmaChannel             ((Mcl_ChannelType)0xFF)

#endif /* ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON)) */

/**
*   @brief   Adds / removes the service Icu_SetClockMode() from the code.
*         STD_ON:  Icu_SetClockMode() can be used.
*         STD_OFF: Icu_SetClockMode() can not be used.
*
*/
#define ICU_DUAL_CLOCK_MODE_API     (STD_ON)

/**
*   @brief   Adds / removes the service Icu_GetCaptureRegisterValue() from the code.
*         STD_ON:  Icu_GetCaptureRegisterValue() can be used.
*         STD_OFF: Icu_GetCaptureRegisterValue() can not be used.
*/
#define ICU_CAPTURERGISTER_API      (STD_ON)

#define IcuChannel_0                     (IcuConf_IcuChannel_IcuChannel_0)
#define IcuConf_IcuChannel_IcuChannel_0  ((Icu_ChannelType)0U)
#define IcuChannel_1                     (IcuConf_IcuChannel_IcuChannel_1)
#define IcuConf_IcuChannel_IcuChannel_1  ((Icu_ChannelType)1U)

/**
* @brief          Number of configured partitions.
*/
#define ICU_MAX_PARTITIONS                    (1U)

#define ICU_MULTICORE_SUPPORT             (STD_OFF)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific micro-controller platform.
*       Range: 0  to width of the timer register.
*       Description: Width of the buffer for timestamps ticks and measured elapsed time ticks
*/
typedef uint32 Icu_TimerRegisterWidthType;

#if (STD_ON == ICU_TIMESTAMP_API)
/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific micro-controller platform.
*       Description: Type, to abstract the return value of the service Icu_GetTimestampIndex().
*/
typedef uint16 Icu_HwSpecificIndexType;
#endif /* (STD_ON == ICU_TIMESTAMP_API) */

#if (STD_ON == ICU_EDGE_COUNT_API)
/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific micro-controller platform.
*       Description: Type, to abstract the return value of the service Icu_GetEdgeNumbers().
*/
typedef uint32 Icu_HwSpecificEdgeNumberType;
#endif /* (STD_ON == ICU_EDGE_COUNT_API) */

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif    /* ICU_CFG_H */

/** @} */
