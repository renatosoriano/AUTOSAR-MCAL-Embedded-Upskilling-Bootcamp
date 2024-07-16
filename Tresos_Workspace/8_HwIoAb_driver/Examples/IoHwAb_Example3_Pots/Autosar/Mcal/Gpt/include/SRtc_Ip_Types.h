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

#ifndef SRTC_IP_TYPES_H
#define SRTC_IP_TYPES_H

/**
*   @file       SRtc_Ip_Types.h
*
*   @addtogroup srtc_ip Rtc IPL
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
#include "SRtc_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SRTC_IP_TYPES_VENDOR_ID                       43
#define SRTC_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define SRTC_IP_TYPES_AR_RELEASE_MINOR_VERSION        7
#define SRTC_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define SRTC_IP_TYPES_SW_MAJOR_VERSION                2
#define SRTC_IP_TYPES_SW_MINOR_VERSION                0
#define SRTC_IP_TYPES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (SRTC_IP_TYPES_VENDOR_ID != SRTC_IP_DEFINES_VENDOR_ID_CFG)
    #error "SRtc_Ip_Types.h and SRtc_Ip_Cfg_Defines.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((SRTC_IP_TYPES_AR_RELEASE_MAJOR_VERSION != SRTC_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SRTC_IP_TYPES_AR_RELEASE_MINOR_VERSION != SRTC_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SRTC_IP_TYPES_AR_RELEASE_REVISION_VERSION != SRTC_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of SRtc_Ip_Types.h and SRtc_Ip_Cfg_Defines.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((SRTC_IP_TYPES_SW_MAJOR_VERSION != SRTC_IP_DEFINES_SW_MAJOR_VERSION_CFG) || \
     (SRTC_IP_TYPES_SW_MINOR_VERSION != SRTC_IP_DEFINES_SW_MINOR_VERSION_CFG) || \
     (SRTC_IP_TYPES_SW_PATCH_VERSION != SRTC_IP_DEFINES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of SRtc_Ip_Types.h and SRtc_Ip_Cfg_Defines.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (SRTC_IP_USED == STD_ON)
/**
* @brief SRTC Channels defines
*/
#define     SECONDS_IN_A_DAY           (86400UL)
#define     SECONDS_IN_A_HOUR          (3600U)
#define     SECONDS_IN_A_MIN           (60U)
#define     MINS_IN_A_HOUR             (60U)
#define     HOURS_IN_A_DAY             (24U)
#define     DAYS_IN_A_YEAR             (365U)
#define     DAYS_IN_A_LEAP_YEAR        (366U)
#define     YEAR_RANGE_START           (1970U)
#define     YEAR_RANGE_END             (2099U)
#define     MAX_32BIT                  (0xFFFFFFFFUL)

#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
 * @brief     Enum containing the SRTC module clock sources
 * @details   Srtc_Ip_ClockSelectType
 */
typedef enum
{
    SRTC_IP_CLK_SRC_OSC_32KHZ = 0x00U,  /**< SRTC Prescaler increments using 32 KHz crystal  */
    SRTC_IP_CLK_SRC_LPO_1KHZ  = 0x01U   /**< SRTC Prescaler increments using 1KHz LPO        */
} Srtc_Ip_ClockSelectType;

/**
 * @brief SRTC CLKOUT pin configuration
 */
typedef enum
{
    SRTC_IP_CLKOUT_DISABLED  = 0x00U,   /**< Clock out pin is disabled                                    */
    SRTC_IP_CLKOUT_SRC_TSIC  = 0x01U,   /**< Output on RTC_CLKOUT as configured on Time seconds interrupt */
    SRTC_IP_CLKOUT_SRC_32KHZ = 0x02U    /**< Output on RTC_CLKOUT of the 32KHz clock                      */
} Srtc_Ip_ClockOutType;

/**
 * @brief     Enum containing SRTC interrupt flags
 * @details   SRtc_Ip_InterruptType
 */
typedef enum
{
    SRTC_IP_INVALID_INTERRUPT  = 0x00U,     /**< @brief RTC_TIME_INVALID_INTERRUPT  */
    SRTC_IP_OVERFLOW_INTERRUPT = 0x01U,     /**< @brief RTC_TIME_OVERFLOW_INTERRUPT */
    SRTC_IP_ALARM_INTERRUPT    = 0x02U,     /**< @brief RTC_TIME_ALARM_INTERRUPT    */
    SRTC_IP_SECONDS_INTERRUPT  = 0x03U      /**< @brief RTC_TIME_SECONDS_INTERRUPT  */
} Srtc_Ip_InterruptType;

/**
 * @brief     SRtc Status error
 * @details   Status error
 */
typedef enum
{
    SRTC_IP_SUCCESS = E_OK,      /**< @brief Status value is SUCCESS */
    SRTC_IP_ERROR = E_NOT_OK     /**< @brief Status value is ERROR   */
} Srtc_Ip_StatusType;

/**
 * @brief SRTC Seconds interrupt configuration
 */
typedef enum
{
    SRTC_IP_INT_1HZ   = 0x00U,     /**< SRTC seconds interrupt occurs at 1 Hz      */
    SRTC_IP_INT_2HZ   = 0x01U,     /**< SRTC seconds interrupt occurs at 2 Hz      */
    SRTC_IP_INT_4HZ   = 0x02U,     /**< SRTC seconds interrupt occurs at 4 Hz      */
    SRTC_IP_INT_8HZ   = 0x03U,     /**< SRTC seconds interrupt occurs at 8 Hz      */
    SRTC_IP_INT_16HZ  = 0x04U,     /**< SRTC seconds interrupt occurs at 16 Hz     */
    SRTC_IP_INT_32HZ  = 0x05U,     /**< SRTC seconds interrupt occurs at 32 Hz     */
    SRTC_IP_INT_64HZ  = 0x06U,     /**< SRTC seconds interrupt occurs at 64 Hz     */
    SRTC_IP_INT_128HZ = 0x07U      /**< SRTC seconds interrupt occurs at 128 Hz    */
} Srtc_Ip_SecIntFreqType;

#if (STD_ON == SRTC_IP_ENABLE_LOCK_REGISTER_API)
/**
 * @brief SRTC register lock
 */
typedef enum
{
    SRTC_IP_LOCK_REG_LOCK   = 0x00U,   /**< SRTC Lock Register lock         */
    SRTC_IP_STATUS_REG_LOCK = 0x01U,   /**< SRTC Status Register lock       */
    SRTC_IP_CTRL_REG_LOCK   = 0x02U,   /**< SRTC Control Register lock      */
    SRTC_IP_TCL_REG_LOCK    = 0x03U    /**< SRTC Time Compensation Reg lock */
} Srtc_Ip_LockRegSelectType;
#endif

/**
* @brief    Channel mode type. Indicates of whether the channel mode is "CONTINUOUS" or "ONE SHOT".
* @details  ChannelModeType of channel.
*/
typedef enum
{
    SRTC_IP_CH_MODE_CONTINUOUS = 0U,      /**< @brief channel mode -  continuous mode */
    SRTC_IP_CH_MODE_ONESHOT    = 1U       /**< @brief channel mode -  one-shot mode.  */
} Srtc_Ip_ChannelModeType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief    Callback type for each channel
* @details  Srtc_Ip_CallbackType
*
*/
typedef void (*Srtc_Ip_CallbackType)(uint8 callbackParam);

/**
 * @brief       Structure to configure the SRTC
 * @details     This structure holds the configuration settings for the SRTC
 */
typedef struct
{
    Srtc_Ip_ClockSelectType     clockSelect;                /**< @brief SRTC Clock Select                   */
    Srtc_Ip_ClockOutType        clockOutSelect;             /**< @brief SRTC Clock Pin select - RTC_CLKOUT  */
#if (defined (SRTC_IP_ENABLE_COMPENSATION_SUPPORT) && (SRTC_IP_ENABLE_COMPENSATION_SUPPORT == STD_ON))
    uint8                       compensationInterval;       /**< @brief SRTC Compensation Interval          */
    uint8                       compensation;               /**< @brief SRTC Compensation Value             */
#endif
    Srtc_Ip_CallbackType        callback;                   /**< @brief Periodic interrupt callback         */
    uint8                       callbackParam;              /**< @brief Pointer to callback parameters      */
    Srtc_Ip_ChannelModeType     channelMode;                /**< @brief channelMode                         */
} Srtc_Ip_ConfigType;

/**
 * @brief   SRTC Time Date structure
 * @details Srtc_Ip_TimedateType
 */
typedef struct
{
    uint16                  year;           /**< @brief Year       */
    uint16                  month;          /**< @brief Month      */
    uint16                  day;            /**< @brief Day        */
    uint16                  hour;           /**< @brief Hour       */
    uint16                  minutes;        /**< @brief Minutes    */
    uint8                   seconds;        /**< @brief Seconds    */
} Srtc_Ip_TimedateType;

/**
 * @brief   SRTC alarm configuration
 * @details Srtc_Ip_AlarmConfigType
 */
typedef struct
{
    Srtc_Ip_TimedateType    alarmTime;              /**< @brief Alarm time                                       */
    uint32                  repetitionInterval;     /**< @brief Interval of repetition in seconds                */
    uint32                  numberOfRepeats;        /**< @brief Number of alarm repeats                          */
    boolean                 repeatForever;          /**< @brief Repeat forever if set, discard number of repeats */
    boolean                 alarmIntEnable;         /**< @brief Enable alarm interrupt                           */
    Srtc_Ip_CallbackType    alarmCallback;          /**< @brief Pointer to the user callback method.             */
    uint8                   callbackParams;         /**< @brief Pointer to the callback parameters.              */
} Srtc_Ip_AlarmConfigType;

#if (STD_ON == SRTC_IP_ENABLE_LOCK_REGISTER_API)
/**
 * @brief SRTC Register Lock Configuration
 */
typedef struct
{
    boolean     lockRegisterLock;                   /**< Lock state of the Lock Register              */
    boolean     statusRegisterLock;                 /**< Lock state of the Status Register            */
    boolean     controlRegisterLock;                /**< Lock state of the Control Register           */
    boolean     timeCompensationRegisterLock;       /**< Lock state of the Time Compensation Register */
} Srtc_Ip_LockRegConfigType;
#endif
/**
 * @brief       Internal context structure Srtc_Ip_State
 * @details     This structure is used by the IPL driver for internal logic.
 *              The content is populated on Init.
 */
typedef struct
{
    boolean                 alarmInit;           /**< @brief alarmInit                                        */
    uint32                  repetitionInterval;  /**< @brief Interval of repetition in seconds                */
    volatile uint32         numberOfRepeats;     /**< @brief Number of alarm repeats                          */
    boolean                 repeatForever;       /**< @brief Repeat forever if set, discard number of repeats */
    boolean                 alarmIntEnable;      /**< @brief Enable alarm interrupt                           */
    Srtc_Ip_CallbackType    alarmCallback;       /**< @brief Pointer to the user callback method.             */
    uint8                   callbackParams;      /**< @brief Pointer to the callback parameters.              */
    volatile boolean        isAlarmTimeNew;      /**< @brief Check if there is a new alarm                    */
    boolean                 chInit;              /**< @brief chInit                                           */
    Srtc_Ip_CallbackType    callback;            /**< @brief callback                                         */
    uint8                   callbackParam;       /**< @brief callbackParam                                    */
    Srtc_Ip_ChannelModeType channelMode;         /**< @brief channelMode                                      */
} Srtc_Ip_State;

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
#endif /* SRTC_IP_TYPES_H */
