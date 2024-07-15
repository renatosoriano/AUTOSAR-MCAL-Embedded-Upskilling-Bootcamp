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

#ifndef LPTMR_GPT_IP_TYPES_H
#define LPTMR_GPT_IP_TYPES_H

/**
*   @file       Lptmr_Gpt_Ip_Types.h
*
*   @addtogroup Lptmr_Gpt_Ip Lptmr IPL
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
#include "Lptmr_Gpt_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPTMR_GPT_IP_TYPES_VENDOR_ID                       43
#define LPTMR_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define LPTMR_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION        7
#define LPTMR_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define LPTMR_GPT_IP_TYPES_SW_MAJOR_VERSION                2
#define LPTMR_GPT_IP_TYPES_SW_MINOR_VERSION                0
#define LPTMR_GPT_IP_TYPES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (LPTMR_GPT_IP_TYPES_VENDOR_ID != LPTMR_GPT_IP_DEFINES_VENDOR_ID_CFG)
    #error "Lptmr_Gpt_Ip_Types.h and Lptmr_Gpt_Ip_Cfg_Defines.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((LPTMR_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION != LPTMR_GPT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (LPTMR_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION != LPTMR_GPT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (LPTMR_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION != LPTMR_GPT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Lptmr_Gpt_Ip_Types.h and Lptmr_Gpt_Ip_Cfg_Defines.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((LPTMR_GPT_IP_TYPES_SW_MAJOR_VERSION != LPTMR_GPT_IP_DEFINES_SW_MAJOR_VERSION_CFG) || \
     (LPTMR_GPT_IP_TYPES_SW_MINOR_VERSION != LPTMR_GPT_IP_DEFINES_SW_MINOR_VERSION_CFG) || \
     (LPTMR_GPT_IP_TYPES_SW_PATCH_VERSION != LPTMR_GPT_IP_DEFINES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Lptmr_Gpt_Ip_Types.h and Lptmr_Gpt_Ip_Cfg_Defines.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief LPTMR E_TIMEOUT
*/
#define E_TIMEOUT    0x03

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/**
 * @brief     Enum containing the LPTMR module clock sources
 * @details   Lptmr_Gpt_Ip_ClockSelectType
 */
typedef enum
{
    LPTMR_GPT_IP_CLOCK_SIRCDIV2     = 0x00U,      /**< @brief LPTMR clock source SIRCDIV2_CLK */
    LPTMR_GPT_IP_CLOCK_LPO1K        = 0x01U,      /**< @brief LPTMR clock source LPO1K */
    LPTMR_GPT_IP_CLOCK_RTC_CLK      = 0x02U,      /**< @brief LPTMR clock source RTC_CLK */
    LPTMR_GPT_IP_CLOCK_PCC_LPTMR0   = 0x03U       /**< @brief LPTMR clock source PCC_LPTMR0 */
} Lptmr_Gpt_Ip_ClockSelectType;

/**
 * @brief     LPTMR Status error
 * @details   Status error
 */
typedef enum
{
    LPTMR_GPT_IP_SUCCESS = E_OK,            /**< @brief Status value is SUCCESS */
    LPTMR_GPT_IP_ERROR   = E_NOT_OK,        /**< @brief Status value is ERROR */
    LPTMR_GPT_IP_TIMEOUT = E_TIMEOUT        /**< @brief Status value is TIMEOUT */
} Lptmr_Gpt_Ip_StatusType;

/**
* @brief    Channel mode type. Indicates of whether the channel mode is "CONTINUOUS" or "ONE SHOT".
* @details  ChannelModeType of channel.
*/
typedef enum
{
    LPTMR_GPT_IP_CH_MODE_CONTINUOUS = 0U,      /**< @brief channel mode -  continuous mode */
    LPTMR_GPT_IP_CH_MODE_ONESHOT    = 1U       /**< @brief channel mode -  one-shot mode.  */
} Lptmr_Gpt_Ip_ChannelModeType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief    Callback type for each channel
* @details  Lptmr_Gpt_Ip_CallbackType
*
*/
typedef void (*Lptmr_Gpt_Ip_CallbackType)(uint8 callbackParam);
/**
 * @internal
 * @brief       Structure to configure the LPTMR
 * @details     This structure holds the configuration settings for the LPTMR
 */
typedef struct
{
    boolean                            prescalerEnable;         /**< @brief On/Off prescalerEnable                        */
#if(LPTMR_GPT_IP_SET_CLOCK_MODE == STD_ON)
    uint8                              clockAlternatePrescaler; /**< @brief Clock divide value for the AlternatePrescaler */
#endif
    uint8                              clockPrescaler;          /**< @brief Clock divide value for the clockPrescaler     */
    Lptmr_Gpt_Ip_ClockSelectType       clocksource;             /**< @brief LPTMR Clock Select                            */
    Lptmr_Gpt_Ip_CallbackType          callback;                /**< @brief Periodic interrupt callback                   */
    uint8                              callbackParam;           /**< @brief Pointer to callback parameters                */
    Lptmr_Gpt_Ip_ChannelModeType       channelMode;      /**< @brief channelMode                                          */
} Lptmr_Gpt_Ip_ConfigType;


/**
 * @brief       Internal context structure Lptmr_Gpt_Ip_State
 * @details     This structure is used by the IPL driver for internal logic.
 *              The content is populated on Init.
 */
typedef struct
{
    boolean                             chInit;              /**< @brief chInit         */
    Lptmr_Gpt_Ip_CallbackType           callback;            /**< @brief callback       */
    uint8                               callbackParam;       /**< @brief callbackParam  */
    Lptmr_Gpt_Ip_ChannelModeType        channelMode;         /**< @brief channelMode    */
} Lptmr_Gpt_Ip_State;

/**
* @brief    Prescaler type. Indicates of whether the clock channel mode is "NORMAL" or "ALTERNATE".
* @details  This enumeration specifies the possible types of prescalers used to configure base-clock timers
*/
#if (LPTMR_GPT_IP_SET_CLOCK_MODE == STD_ON)
typedef enum
{
    LPTMR_GPT_IP_CLOCKMODE_NORMAL    = 0x0U,  /**< @brief Selected value is the NORMAL configured prescaler    */
    LPTMR_GPT_IP_CLOCKMODE_ALTERNATE = 0x1U   /**< @brief Selected value is the ALTERNATE configured prescaler */
} Lptmr_Gpt_Ip_ClockModeType;
#endif /* LPTMR_GPT_IP_SET_CLOCK_MODE */


/**
 * @brief       internal context structure
 *
 * @details     This structure is used by the IPL driver for internal logic.
 *              The content is populated on Init
 */
typedef struct
{
    uint8       clockPrescaler;              /**< @brief Clock divide value for the NormalPrescaler */
    uint8       clockAlternatePrescaler;     /**< @brief Clock divide value for the AlternatePrescaler */
} Lptmr_Gpt_Ip_InstanceState;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* LPTMR_GPT_IP_TYPES_H */
