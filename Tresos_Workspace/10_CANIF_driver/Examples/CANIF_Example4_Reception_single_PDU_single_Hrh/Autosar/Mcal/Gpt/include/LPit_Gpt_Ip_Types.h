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

#ifndef LPIT_GPT_IP_TYPES_H
#define LPIT_GPT_IP_TYPES_H
/**
*   @file        LPit_Gpt_Ip_Types.h
*
*   @addtogroup  lpit_ip LPit IPL
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
#include "LPit_Gpt_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPIT_GPT_IP_TYPES_VENDOR_ID                       43
#define LPIT_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define LPIT_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION        7
#define LPIT_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define LPIT_GPT_IP_TYPES_SW_MAJOR_VERSION                2
#define LPIT_GPT_IP_TYPES_SW_MINOR_VERSION                0
#define LPIT_GPT_IP_TYPES_SW_PATCH_VERSION                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (LPIT_GPT_IP_DEFINES_VENDOR_ID_CFG != LPIT_GPT_IP_TYPES_VENDOR_ID)
    #error "LPit_Gpt_Ip_Cfg_Defines.h and LPit_Gpt_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((LPIT_GPT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != LPIT_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPIT_GPT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != LPIT_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPIT_GPT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG != LPIT_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of LPit_Ip_Cfg_Defines.h and LPit_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((LPIT_GPT_IP_DEFINES_SW_MAJOR_VERSION_CFG != LPIT_GPT_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPIT_GPT_IP_DEFINES_SW_MINOR_VERSION_CFG != LPIT_GPT_IP_TYPES_SW_MINOR_VERSION) || \
     (LPIT_GPT_IP_DEFINES_SW_PATCH_VERSION_CFG != LPIT_GPT_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LPit_Gpt_Ip_Cfg_Defines.h and LPit_Gpt_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/



/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/**
 * @brief     LPit Status error
 * @details   Status error
 */
typedef enum
{
    LPIT_GPT_IP_SUCCESS = E_OK,      /**< @brief Status value is SUCCESS */
    LPIT_GPT_IP_ERROR = E_NOT_OK     /**< @brief Status value is ERROR */
} Lpit_Gpt_Ip_StatusType;

/**
* @brief    Channel mode type. Indicates of whether the channel mode is "CONTINUOUS" or "ONE SHOT".
* @details  ChannelModeType of channel.
*/
typedef enum
{
    LPIT_GPT_IP_CH_MODE_CONTINUOUS = 0U,      /**< @brief channel mode -  continuous mode */
    LPIT_GPT_IP_CH_MODE_ONESHOT    = 1U       /**< @brief channel mode -  one-shot mode.  */
} Lpit_Gpt_Ip_ChannelModeType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief    Callback type for each channel
 * @details  Pit_Ip_CallbackType
 *
 */
typedef void (*Lpit_Gpt_Ip_CallbackType)(uint8 callbackParam);

/**
 * @brief       Structure to configure the LPIT
 *
 * @details     This structure holds the configuration settings for the LPIT
 * Implements :
 */
typedef struct
{
#if (LPIT_GPT_IP_DOZE_MODE_SUPPORT == STD_ON)
    boolean runInDozeMode;          /**< @brief DOZE Mode Enable Bit             */
#endif
    boolean stopRunInDebug;         /**< @brief Stop timer running in debug mode */
} Lpit_Gpt_Ip_InstanceConfigType;

/**
 * @brief       Structure to configure the LPIT timer channel
 *
 * @details     This structure holds the configuration settings for the LPIT timer channel
 * Implements :
 */
typedef struct
{
    uint8                       hwChannel;           /**< @brief Timer channel number                   */
    Lpit_Gpt_Ip_CallbackType    callback;            /**< @brief callback                               */
    uint8                       callbackParam;       /**< @brief callbackParam                          */
#if (LPIT_GPT_IP_ENABLE_EXT_TRIGGERS == STD_ON)
    uint32                      triggerConfig;       /**<@brief Trigger source configure for LPIT Timer */
#endif
    Lpit_Gpt_Ip_ChannelModeType    channelMode;      /**< @brief channelMode                            */
} Lpit_Gpt_Ip_ChannelConfigType;

/**
 * @brief       internal context structure
 *
 * @details     This structure is used by the IPL driver for internal logic.
 *              The content is populated on Init
 */
typedef struct
{
    boolean                    chInit;               /**< @brief chInit        */
    Lpit_Gpt_Ip_CallbackType   callback;             /**< @brief callback      */
    uint8                      callbackParam;        /**< @brief callbackParam */
    Lpit_Gpt_Ip_ChannelModeType    channelMode;      /**< @brief channelMode   */
} Lpit_Gpt_Ip_State;

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
#endif /* LPIT_GPT_IP_TYPES_H*/

