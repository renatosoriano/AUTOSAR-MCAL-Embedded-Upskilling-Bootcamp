/*==================================================================================================
* Project :             RTD AUTOSAR 4.7
* Platform :            CORTEXM
* Peripheral :          Ftm_Srtc_Lptmr_LPit
* Dependencies :        none
*
* Autosar Version :     4.7.0
* Autosar Revision :    ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version :          2.0.0
* Build Version :       S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
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

#ifndef FTM_GPT_IP_TYPES_H
#define FTM_GPT_IP_TYPES_H

/**
*   @file       Ftm_Gpt_Ip_Types.h
*
*   @addtogroup ftm_ip Ftm IPL
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
#include "Ftm_Gpt_Ip_Cfg_Defines.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @internal
* @brief Defines used for file version checks
*/
#define FTM_GPT_IP_TYPES_VENDOR_ID                       43
#define FTM_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define FTM_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION        7
#define FTM_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define FTM_GPT_IP_TYPES_SW_MAJOR_VERSION                2
#define FTM_GPT_IP_TYPES_SW_MINOR_VERSION                0
#define FTM_GPT_IP_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (FTM_GPT_IP_DEFINES_VENDOR_ID_CFG != FTM_GPT_IP_TYPES_VENDOR_ID)
    #error "Ftm_Gpt_Ip_Cfg_Defines.h and Ftm_Gpt_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((FTM_GPT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != FTM_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_GPT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != FTM_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_GPT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG != FTM_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip_Cfg_Defines.h and Ftm_Gpt_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((FTM_GPT_IP_DEFINES_SW_MAJOR_VERSION_CFG != FTM_GPT_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_GPT_IP_DEFINES_SW_MINOR_VERSION_CFG != FTM_GPT_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_GPT_IP_DEFINES_SW_PATCH_VERSION_CFG != FTM_GPT_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ftm_Gpt_Ip_Cfg_Defines.h and Ftm_Gpt_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                      CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/
#if (FTM_GPT_IP_USED == STD_ON)

/**
* @internal
* @brief STM Channels defines
*
*/
#define PREDEF                ((uint8)0)

#endif /*FTM_GPT_IP_USED == STD_ON */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
* @brief      Unit options for counting mode
* @details    This is used to choose how the timer is counting
*
* @implements
*/
typedef enum
{
    FTM_GPT_IP_MODE_UP_TIMER           = 0x01U,    /**< @brief Timer with up counter */
    FTM_GPT_IP_MODE_UP_DOWN_TIMER      = 0x02U     /**< @brief timer with up-down counter */
}
Ftm_Gpt_Ip_CountingMode;

/**
 * @brief     Enum containing the FTM module clock sources
 * @details   This is used to choose the FTM clock sources.
 */
typedef enum
{
    FTM_GPT_IP_CLOCK_SOURCE_NONE                 = 0x00U,    /**< @brief None use clock for FTM  */
    FTM_GPT_IP_CLOCK_SOURCE_SYSTEMCLK            = 0x01U,    /**< @brief System clock            */
    FTM_GPT_IP_CLOCK_SOURCE_FIXED_FREQUENCY      = 0x02U,    /**< @brief Fixed frequency         */
    FTM_GPT_IP_CLOCK_SOURCE_EXTERNALCLK          = 0x03U     /**< @brief External clock          */
}
Ftm_Gpt_Ip_ClockSource;

/**
* @brief    Prescaler type. Indicates of whether the clock channel mode is "NORMAL" or "ALTERNATE".
* @details  This enumeration specifies the possible types of prescalers used to configure base-clock timers
*/
#if (FTM_GPT_IP_SET_CLOCK_MODE == STD_ON)
typedef enum
{
    FTM_GPT_IP_CLOCKMODE_NORMAL    = 0x0U,  /**< @brief Selected value is the NORMAL configured prescaler */
    FTM_GPT_IP_CLOCKMODE_ALTERNATE = 0x1U   /**< @brief Selected value is the ALTERNATE configured prescaler */
} Ftm_Gpt_Ip_ClockModeType;
#endif /* FTM_GPT_IP_SET_CLOCK_MODE */

/**
* @brief    Channel mode type. Indicates of whether the channel mode is "CONTINUOUS" or "ONE SHOT".
* @details  ChannelModeType of channel.
*/
typedef enum
{
    FTM_GPT_IP_CH_MODE_CONTINUOUS = 0U,      /**< @brief channel mode -  continuous mode */
    FTM_GPT_IP_CH_MODE_ONESHOT    = 1U       /**< @brief channel mode -  one-shot mode.  */
} Ftm_Gpt_Ip_ChannelModeType;
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief    Callback type for each channel
* @details  Ftm_Gpt_Ip_CallbackType
*
*/
typedef void (*Ftm_Gpt_Ip_CallbackType)(uint8 callbackParam);

/**
* @brief       Structure to configure the FTM instance
* @details     This structure holds the configuration settings for InstanceConfigType
*
* Implements   Ftm_Gpt_Ip_InstanceConfigType
*/
typedef struct
{
    boolean                       freezeBits;                /**< @brief Enable/Disable freeze bits */
    Ftm_Gpt_Ip_ClockSource        clocksource;              /**< @brief Select FTM clocksource */
#if (FTM_GPT_IP_SET_CLOCK_MODE == STD_ON)
    uint8                         clockAlternatePrescaler;  /**< @brief Select AlternatePrescaler */
#endif
    uint8                         clockPrescaler;           /**< @brief Select prescalerValue */
    Ftm_Gpt_Ip_CountingMode       mode;                     /**< @brief Select mode */
} Ftm_Gpt_Ip_InstanceConfigType;

/**
* @brief       Structure to configure the FTM channels
* @details     This structure holds the configuration settings for the ChannelConfigType
*
* Implements   Ftm_Gpt_Ip_ChannelConfigType
*/
typedef struct
{
    uint8                          hwChannel;        /**< @brief hwChannel     */
    Ftm_Gpt_Ip_CallbackType        callback;         /**< @brief callback      */
    uint8                          callbackParam;    /**< @brief callbackParam */
    Ftm_Gpt_Ip_ChannelModeType     channelMode;      /**< @brief channelMode   */
} Ftm_Gpt_Ip_ChannelConfigType;

/**
* @brief       internal context structure
* @details     This structure is used by the IPL driver for internal logic.
*              The content is populated on InitChannel
*
*/
typedef struct
{
    boolean                       chInit;           /**< @brief chInit        */
    Ftm_Gpt_Ip_CallbackType       callback;         /**< @brief callback      */
    uint8                         callbackParam;    /**< @brief callbackParam */
    Ftm_Gpt_Ip_ChannelModeType    channelMode;      /**< @brief channelMode   */
} Ftm_Gpt_Ip_ChState;

/**
* @brief       internal context structure
* @details     This structure is used by the IPL driver for internal logic.
*              The content is populated on Init
*
*/
typedef struct
{
    uint8       clockPrescaler;              /**< @brief Clock divide value for the NormalPrescaler */
    uint8       clockAlternatePrescaler;     /**< @brief Clock divide value for the AlternatePrescaler */
} Ftm_Gpt_Ip_InstancePrescalerType;
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif/*FTM_GPT_IP_TYPES_H*/
