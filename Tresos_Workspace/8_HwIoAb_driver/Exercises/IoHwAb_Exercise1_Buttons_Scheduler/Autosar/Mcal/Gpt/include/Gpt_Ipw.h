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

#ifndef GPT_IPW_H
#define GPT_IPW_H

/**
*   @file       Gpt_Ipw.h
*
*   @internal
*   @addtogroup gpt gpt_ipw
*
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
#include "Gpt.h"
#include "Gpt_Ipw_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_IPW_VENDOR_ID                      43
#define GPT_IPW_AR_RELEASE_MAJOR_VERSION       4
#define GPT_IPW_AR_RELEASE_MINOR_VERSION       7
#define GPT_IPW_AR_RELEASE_REVISION_VERSION    0
#define GPT_IPW_SW_MAJOR_VERSION               2
#define GPT_IPW_SW_MINOR_VERSION               0
#define GPT_IPW_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_VENDOR_ID != GPT_IPW_VENDOR_ID)
    #error "Gpt.h and Gpt_Ipw.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != GPT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION != GPT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION != GPT_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt.h and Gpt_Ipw.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION != GPT_IPW_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION != GPT_IPW_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION != GPT_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt.h and Gpt_Ipw.h are different"
#endif

#if (GPT_IPW_TYPES_VENDOR_ID != GPT_IPW_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and Gpt_Ipw.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Gpt_Ipw.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_IPW_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_IPW_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Gpt_Ipw.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
* @internal
* @brief    Gpt channel hardware runtime information.
* @details  This is the type of the data structure used by the Autosar layer to
*           receive runtime information specific to hardware IP
*/
typedef struct
{
    boolean bChannelRollover;                 /**< @brief GPT channel rollover information*/
    Gpt_ValueType uTargetTime;                /**< @brief GPT channel target value*/
} Gpt_HwChannelInfoType;
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/*================================================================================================*/
/**
* @internal
* @brief        Gpt driver Autosar independent and IP dependent initialization function.
* @details      This function Gpt_Ipw_Init is called once for each channel in the used configuration.
*               It determines the type of the HW channel and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return       void
* @pre          The driver needs to be initialized.
*/
void Gpt_Ipw_Init(const Gpt_Ipw_HwChannelConfigType *pHwChannelConfig);
/*================================================================================================*/
/**
* @internal
* @brief        Gpt driver Autosar independent and IP dependent initialization function.
* @details      This Gpt_Ipw_InitInstances is called once for each channel in the used configuration.
*               It determines the type of the HW channel and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    configPtr    Pointer to the channel configuration structure dependent by platform
*
* @return       void
* @pre          The driver needs to be initialized.
*/
void Gpt_Ipw_InitInstances(const Gpt_ConfigType * configPtr);
/*================================================================================================*/
/**
* @internal
* @brief         Gpt driver Autosar independent and IP dependent function for fetching the elapsed timer value.
* @details       It determines the type of the HW channel and calls the
*                appropriate IP function for reading the elapsed timer value from the HW.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     uTargetTime         Target time value
* @param[out]    pReturnHwChannelInfo  Rollover status flag value of the hardware timer channel
* @return        returnValue         The elapsed time
* @pre           The driver needs to be initialized.Call GetTimeElapsed before.
*
*/
Gpt_ValueType Gpt_Ipw_GetTimeElapsed
(
    const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig,
    Gpt_HwChannelInfoType * pReturnHwChannelInfo
);
/*================================================================================================*/
/**
* @internal
* @brief         Gpt driver Autosar independent and platform dependent function for starting the timer channel.
* @details       It checks the type of the HW module and calls the appropriate
*                IP function for starting the timer channel.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     uValue              Timeout period (in ticks) after which a notification shall occur (if enabled).
* @return        void
* @pre           The driver needs to be initialized.Call Gpt_StartTimer before.
*/
Std_ReturnType Gpt_Ipw_StartTimer(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_ValueType uValue);
/*================================================================================================*/
/**
* @internal
* @brief         Gpt driver Autosar independent and platform dependent function for stopping the timer channel.
* @details       It checks the type of the HW module, and calls the appropriate
*                IP function for stopping the timer channel.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized.Call StopTimer before.
*/
void Gpt_Ipw_StopTimer(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig);
/*================================================================================================*/
/**
* @internal
* @brief         Gpt driver Autosar independent and platform dependent function for enabling hardware timer interrupts.
* @details       It checks the type of the HW module and calls the appropriate
*                IP function for enabling hardware timer interrupts.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized.
*/
void Gpt_Ipw_EnableInterrupt(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig);
/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @internal
* @brief         Gpt driver Autosar independent and IP dependent de-initialization function.
* @details       This function is called for each  channel from the current configuration.
*                It determines the type of the HW channel and calls the
*                appropriate IP function in order to de-initializes the hardware timer.
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized. On/Off by the configuration parameter: GPT_DEINIT_API
*/
void Gpt_Ipw_DeInit(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig);
#endif
/*================================================================================================*/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)|| (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
* @internal
* @brief         Gpt driver Autosar independent and platform dependent function for disabling hardware timer interrupts.
* @details       It checks the type of the HW module and calls the appropriate
*                IP function for disabling hardware timer interrupts.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized.On/Off by the configuration parameter: GPT_ENABLE_DISABLE_NOTIFICATION_API
*/
void Gpt_Ipw_DisableInterrupt(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig);
#endif
/*================================================================================================*/
#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @internal
* @brief        Gpt driver Autosar independent and IP dependent function to change compare register value.
* @details      This function:
*                - Write next timeout to local variable
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent
*                                       by platform
* @param[in]     value               New Timeout period (in ticks) after which a notification
*                                       shall occur (if enabled).
* @return        void
* @pre           The driver needs to be initialized.On/Off by the configuration parameter: GPT_CHANGE_NEXT_TIMEOUT_VALUE
*
*/
Std_ReturnType Gpt_Ipw_ChangeNextTimeoutValue
(
    const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig,
    Gpt_ValueType value
);
#endif
/*================================================================================================*/
#if (GPT_SET_CLOCK_MODE == STD_ON)
/**
* @internal
* @brief         Gpt driver Autosar independent and IP dependent function to change FTM prescaler value.
* @details       Calls the FTM function to change the FTM prescaler.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     clkMode             Clock mode for configuration channel
*
* @return        void
* @pre           The driver needs to be initialized.On/Off by the configuration parameter: GPT_SET_CLOCK_MODE
*/
void Gpt_Ipw_SetClockModeInStance(const Gpt_Ipw_HwInstanceConfigType * pHwInstanceConfig,
                                            Gpt_ClockModeType clkMode);
#endif
/*================================================================================================*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @internal
* @brief        Gpt driver Autosar start predeftimer hw.
* @details      This function to start channel, which using predeftimer feature in the used configuration.
*               It determines the type of the HW channel and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return       void
* @pre          The driver needs to be initialized. On/Off GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON
*
*/
void Gpt_Ipw_StartPredefTimer
(
    const Gpt_ConfigType * configPtr
);
/**
* @internal
* @brief        Gpt driver Autosar get value of predeftimer hw.
* @details      This function to start channel, which using predeftimer feature in the used configuration.
*               It determines the type of the HW channel and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]    TimeValuePtr        The pointer using for save current value of hardware channel
* @param[in]    PredefTimer         Gpt_PredefTimerType
* @return       void
* @pre          The driver needs to be initialized. On/Off GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON
*
*/
void Gpt_Ipw_GetPredefTimerValue
(
    const Gpt_HwPredefChannelConfigType * pHwChannelConfig,
    Gpt_PredefTimerType PredefTimer,
    uint32 * TimeValuePtr
);
/**
* @internal
* @brief        Gpt driver Autosar stop predeftimer hw.
* @details      This function to start channel, which using predeftimer feature in the used configuration.
*               It determines the type of the HW channel and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return       void
* @pre          The driver needs to be initialized. GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON
*/
void Gpt_Ipw_StopPredefTimer
(
    const Gpt_ConfigType * configPtr
);
#endif
/*================================================================================================*/
#if (GPT_CHAIN_MODE == STD_ON)
/**
* @internal
* @brief         The function Gpt_Ipw_EnableChainMode.
* @details       This function:
*               - Chain the timer.
*
* @param[in]     pHwChannelConfig        Pointer to the channel configuration structure dependent by platform
* @return        returnValue
* @pre           The driver needs to be initialized. CHAIN_MODE == STD_ON
*/
Std_ReturnType Gpt_Ipw_EnableChainMode(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig);
/**
* @internal
* @brief         The function Gpt_Ipw_DisableChainMode.
* @details       This function:
*               - Chain the timer.
*
* @param[in]     pHwChannelConfig        Pointer to the channel configuration structure dependent by platform
* @return        returnValue
* @pre           The driver needs to be initialized. CHAIN_MODE == STD_ON
*/
Std_ReturnType Gpt_Ipw_DisableChainMode(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig);
#endif
/*================================================================================================*/

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
#endif /*GPT_IPW_H*/

