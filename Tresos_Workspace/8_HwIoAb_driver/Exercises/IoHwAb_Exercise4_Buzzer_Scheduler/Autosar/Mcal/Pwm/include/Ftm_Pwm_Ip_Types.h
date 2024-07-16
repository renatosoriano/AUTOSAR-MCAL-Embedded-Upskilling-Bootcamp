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

#ifndef FTM_PWM_IP_TYPES_H
#define FTM_PWM_IP_TYPES_H

/**
*   @file       Ftm_Pwm_Ip_Types.h
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
#include "Ftm_Pwm_Ip_CfgDefines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_PWM_IP_TYPES_VENDOR_ID                             43
#define FTM_PWM_IP_TYPES_MODULE_ID                             121
#define FTM_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION              4
#define FTM_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION              7
#define FTM_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION           0
#define FTM_PWM_IP_TYPES_SW_MAJOR_VERSION                      2
#define FTM_PWM_IP_TYPES_SW_MINOR_VERSION                      0
#define FTM_PWM_IP_TYPES_SW_PATCH_VERSION                      0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Types.h and Std_Types.h are different."
    #endif
#endif

/* Check if header file and Ftm_Pwm_Ip_CfgDefines.h header file are of the same vendor */
#if (FTM_PWM_IP_TYPES_VENDOR_ID != FTM_PWM_IP_CFGDEFINES_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Types.h and Ftm_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_CfgDefines.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Types.h and Ftm_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_CfgDefines.h header file are of the same software version */
#if ((FTM_PWM_IP_TYPES_SW_MAJOR_VERSION != FTM_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_TYPES_SW_MINOR_VERSION != FTM_PWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_TYPES_SW_PATCH_VERSION != FTM_PWM_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Types.h and Ftm_Pwm_Ip_CfgDefines.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

typedef uint8 Ftm_Pwm_Ip_EdgeInterruptType;

 /*! @brief FlexTimer edge interrupt */
#define FTM_PWM_IP_NO_EDGE                ((Ftm_Pwm_Ip_EdgeInterruptType)0U)
#define FTM_PWM_IP_CHF_IRQ_EDGE           ((Ftm_Pwm_Ip_EdgeInterruptType)1U)
#define FTM_PWM_IP_TOF_IRQ_EDGE           ((Ftm_Pwm_Ip_EdgeInterruptType)2U)
#define FTM_PWM_IP_IRQ_NO_EDGE_NOTIF      ((Ftm_Pwm_Ip_EdgeInterruptType)4U)
#define FTM_PWM_IP_TOF_FAULT_DETECT       ((Ftm_Pwm_Ip_EdgeInterruptType)8U)

/*! @brief Status return codes */
typedef enum
{
    /* Generic error codes */
    FTM_PWM_IP_STATUS_SUCCESS      = E_OK,     /*!< Generic operation success status */
    FTM_PWM_IP_STATUS_ERROR        = E_NOT_OK, /*!< Generic operation failure status */
    FTM_PWM_IP_STATUS_BUSY         = 0x002U,   /*!< Generic operation busy status */
    FTM_PWM_IP_STATUS_TIMEOUT      = 0x003U,   /*!< Generic operation timeout status */
    FTM_PWM_IP_STATUS_UNSUPPORTED  = 0x004U,   /*!< Generic operation unsupported status */
} Ftm_Pwm_Ip_StatusType;

/*! @brief FlexTimer operation mode */
typedef enum
{
    FTM_PWM_IP_MODE_EDGE_ALIGNED_HIGH      = 0x0AU,    /*!< Edge aligned PWM High-true pulses (clear on match) */
    FTM_PWM_IP_MODE_EDGE_ALIGNED_LOW       = 0x09U,    /*!< Edge aligned PWM Low-true pulses (set on match) */
    FTM_PWM_IP_MODE_CENTER_ALIGNED_HIGH    = 0x12U,    /*!< Center aligned PWM High-true pulses (clear on match) */
    FTM_PWM_IP_MODE_CENTER_ALIGNED_LOW     = 0x11U,    /*!< Center aligned PWM Low-true pulses (set on match) */
    FTM_PWM_IP_MODE_COMBINE_HIGH           = 0x22U,    /*!< Combined channels PWM High-true pulses (set on channel (n) match, and clear on channel (n+1) match) */
    FTM_PWM_IP_MODE_COMBINE_LOW            = 0x21U,    /*!< Combined channels PWM Low-true pulses (clear on channel (n) match, and set on channel (n+1) match) */
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
    FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH  = 0x62U,    /*!< Modified combined channel PWM High-true pulses (set on channel (n) match, and clear on channel (n+1) match) */
    FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW   = 0x61U,    /*!< Modified combined channel PWM Low-true pulses (clear on channel (n) match, and set on channel (n+1) match) */
#endif
    FTM_PWM_IP_MODE_NODEFINED                 = 0xFFU,    /*!< Non defined Mode*/
} Ftm_Pwm_Ip_ChannelModeType;


/*! @brief FlexTimer channel state */
typedef enum
{
    FTM_PWM_IP_CHANNEL_UNINIT        = 0x00U,    /*!< The state's channel before initialization */
    FTM_PWM_IP_CHANNEL_RUNNING       = 0x01U,    /*!< The state's channel is running */
    FTM_PWM_IP_CHANNEL_IDLE          = 0x02U,    /*!< The state's channel is idle */
    FTM_PWM_IP_CHANNEL_OUTPUT_FORCED = 0x03U     /*!< The state's channel in force output channel mode*/
} Ftm_Pwm_Ip_ChannelStateType;

/**
* @brief        Prescaler type
* @details      This enumeration specifies the possible types of prescalers used to configure base-clock timers
*/
typedef enum
{
    /** @brief  Selected value is the default/primary prescaler */
    FTM_PWM_IP_PRIMARY_PRESCALER     = 0x00U,
    /** @brief  Selected value is the alternative configured prescaler */
    FTM_PWM_IP_ALTERNATIVE_PRESCALER = 0X01U
} Ftm_Pwm_Ip_PrescalerType;


/**
* @brief        Power state type
* @details      Power state currently active or set as target power state.
*/
typedef enum
{
    /** @brief  PWM full power mode */
    FTM_PWM_IP_FULL_POWER     = 0x00U,
    /** @brief  PWM low power mode */
    FTM_PWM_IP_LOW_POWER      = 0x01U,
    /** @brief  PWM no define power mode */
    FTM_PWM_IP_NODEFINE_POWER = 0x02U
} Ftm_Pwm_Ip_PowerStateType;


/**
* @brief        Notification type
* @details      This enumeration defines the type of notification
*/
typedef enum
{
    /** @brief  A notification will be generated when an event occurs on the channel 0 */
    FTM_PWM_IP_CHANNEL_0_NOTIFICATION     = 0X00U,
    /** @brief  A notification will be generated when an event occurs on the channel 1 */
    FTM_PWM_IP_CHANNEL_1_NOTIFICATION     = 0X01U,
    /** @brief  A notification will be generated when an event occurs on the channel 2 */
    FTM_PWM_IP_CHANNEL_2_NOTIFICATION     = 0X02U,
    /** @brief  A notification will be generated when an event occurs on the channel 3 */
    FTM_PWM_IP_CHANNEL_3_NOTIFICATION     = 0X03U,
    /** @brief  A notification will be generated when an event occurs on the channel 4 */
    FTM_PWM_IP_CHANNEL_4_NOTIFICATION     = 0X04U,
    /** @brief  A notification will be generated when an event occurs on the channel 5 */
    FTM_PWM_IP_CHANNEL_5_NOTIFICATION     = 0X05U,
    /** @brief  A notification will be generated when an event occurs on the channel 6 */
    FTM_PWM_IP_CHANNEL_6_NOTIFICATION     = 0X06U,
    /** @brief  A notification will be generated when an event occurs on the channel 7 */
    FTM_PWM_IP_CHANNEL_7_NOTIFICATION     = 0X07U,
    /** @brief  A notification will be generated when the FTM counter passes the value in the MOD register */
    FTM_PWM_IP_OVERFLOW_NOTIFICATION      = 0X08U,
    /** @brief  A notification will be generated when a selected reload point happened */
    FTM_PWM_IP_RELOAD_POINT_NOTIFICATION  = 0X09U,
    /** @brief  A notification will be generated when an event for the FTM peripheral fault channel has occurred. */
    FTM_PWM_IP_FAULT_NOTIFICATION         = 0X0AU
} Ftm_Pwm_Ip_NotifType;

/*! @brief FlexTimer operation mode */
typedef enum
{
    FTM_PWM_IP_EDGE_ALIGNED        = 0x00U,    /*!< The FTM Counter is in UP Counting mode */
    FTM_PWM_IP_CENTER_ALIGNED      = 0x01U     /*!< The FTM Counter is in UP-DOWN Counting mode */
} Ftm_Pwm_Ip_CounterModeType;

/*! @brief FlexTimer clock source selection */
typedef enum
{
    FTM_PWM_IP_CLOCK_SOURCE_NONE           = 0x00U,    /*!< None use clock for FTM  */
    FTM_PWM_IP_CLOCK_SOURCE_SYSTEMCLK      = 0x01U,    /*!< System clock            */
#if (defined(FTM_PWM_IP_HAS_FIXED_CLOCK_SOURCE) && (FTM_PWM_IP_HAS_FIXED_CLOCK_SOURCE== STD_ON))
    FTM_PWM_IP_CLOCK_SOURCE_FIXEDCLK       = 0x02U,    /*!< Fixed clock             */
#endif
#if (defined(FTM_PWM_IP_HAS_EXTERNAL_CLOCK) && (FTM_PWM_IP_HAS_EXTERNAL_CLOCK== STD_ON))
    FTM_PWM_IP_CLOCK_SOURCE_EXTERNALCLK    = 0x03U     /*!< External clock          */
#endif
} Ftm_Pwm_Ip_ClkSourceType;

/*! @brief The polarity of the channel output is configured in PWM signal */
typedef enum
{
    FTM_PWM_IP_POLARITY_LOW  = 0x01U,  /*!< The channel polarity is active LOW */
    FTM_PWM_IP_POLARITY_HIGH = 0x00U   /*!< The channel polarity is active HIGH */
} Ftm_Pwm_Ip_PolarityType;

/*! @brief The initial state of the channel output is configured in PWM signal */
typedef enum
{
    FTM_PWM_IP_OUTPUT_STATE_LOW  = 0x00U,  /*!< The channel output is LOW */
    FTM_PWM_IP_OUTPUT_STATE_HIGH = 0x01U   /*!< The channel output is HIGH */
} Ftm_Pwm_Ip_OutputStateType;

/*! @brief FlexTimer pre-scaler factor selection for the clock source */
typedef enum
{
    FTM_PWM_IP_CLOCK_DIV_1    = 0x00U,    /*!< Divide by 1   */
    FTM_PWM_IP_CLOCK_DIV_2    = 0x01U,    /*!< Divide by 2   */
    FTM_PWM_IP_CLOCK_DIV_4    = 0x02U,    /*!< Divide by 4   */
    FTM_PWM_IP_CLOCK_DIV_8    = 0x03U,    /*!< Divide by 8   */
    FTM_PWM_IP_CLOCK_DIV_16   = 0x04U,    /*!< Divide by 16  */
    FTM_PWM_IP_CLOCK_DIV_32   = 0x05U,    /*!< Divide by 32  */
    FTM_PWM_IP_CLOCK_DIV_64   = 0x06U,    /*!< Divide by 64  */
    FTM_PWM_IP_CLOCK_DIV_128  = 0x07U     /*!< Divide by 128 */
} Ftm_Pwm_Ip_ClkPrescalerType;

/*! @brief FTM sync source */
typedef enum
{
    FTM_PWM_IP_SYNC_DISABLED   = 0x00U,    /*!< synchronization for the FTM register is disabled */
    FTM_PWM_IP_SYNC_ON_CLK     = 0x02U,    /*!< synchronization for the FTM register is done on each FTM Clock rising edge */
    FTM_PWM_IP_SYNC_ON_TRIGGER = 0x03U     /*!< synchronization for the FTM register is done on each FTM Sync Trigger */
} Ftm_Pwm_Ip_SyncType;

/*! @brief FTM sync mode */
typedef enum
{
    FTM_PWM_IP_SYNC_SWTRIGGER  = 0x00U,    /*!< synchronization trigger for FTM is generated by software */
    FTM_PWM_IP_SYNC_HWTRIGGER  = 0x01U     /*!< synchronization trigger for FTM is generated by hardware */
} Ftm_Pwm_Ip_SyncModeType;

/*! @brief FlexTimer pre-scaler factor for the dead-time insertion */
typedef enum
{
    FTM_PWM_IP_DEADTIME_DIV_1  = 0x01U, /*!< Divide by 1   */
    FTM_PWM_IP_DEADTIME_DIV_4  = 0x02U, /*!< Divide by 4   */
    FTM_PWM_IP_DEADTIME_DIV_16 = 0x03U  /*!< Divide by 16  */
} Ftm_Pwm_Ip_DeadtimePrescalerType;

/*! @brief Options for the FlexTimer behavior in BDM Mode */
typedef enum
{
    FTM_PWM_IP_BDM_MODE_00 = 0x00U,    /*!< FTM counter stopped, CH(n)F bit can be set, FTM channels
                                 *   in functional mode, writes to MOD,CNTIN and C(n)V registers bypass
                                 *   the register buffers */
    FTM_PWM_IP_BDM_MODE_01 = 0x01U,    /*!< FTM counter stopped, CH(n)F bit is not set, FTM channels
                                 *   outputs are forced to their safe value , writes to MOD,CNTIN and
                                 *   C(n)V registers bypass the register buffers */
    FTM_PWM_IP_BDM_MODE_10 = 0x02U,    /*!< FTM counter stopped, CH(n)F bit is not set, FTM channels
                                *    outputs are frozen when chip enters in BDM mode, writes to MOD,
                                *    CNTIN and C(n)V registers bypass the register buffers */
    FTM_PWM_IP_BDM_MODE_11 = 0x03U     /*!< FTM counter in functional mode, CH(n)F bit can be set,
                                 *   FTM channels in functional mode, writes to MOD,CNTIN and C(n)V
                                 *   registers is in fully functional mode */
} Ftm_Pwm_Ip_DebugModeType;

/*! @brief FlexTimer PWM initialization trigger generation mode */
typedef enum
{
    FTM_PWM_IP_INIT_TRIGG_RELOAD_POINT     = 0x00U,  /*!< Initialization trigger is generated when FTM counter reaches a reload point */
    FTM_PWM_IP_INIT_TRIGG_CNT_UPDATE       = 0x01U   /*!< Initialization trigger is generated when FTM counter is updated */
} Ftm_Pwm_Ip_InitTriggModeType;

/*! @brief FlexTimer PWM channel (n+1) polarity for combine mode */
typedef enum
{
    FTM_PWM_IP_MAIN_INVERTED       = 0x00U,  /*!< The channel (n+1) output is the inverse of the channel (n) output  */
    FTM_PWM_IP_MAIN_DUPLICATED     = 0x01U   /*!< The channel (n+1) output is the same as the channel (n) output */
} Ftm_Pwm_Ip_PairChPolarityType;

/*! @brief FlexTimer PWM Pair Edge Dithering for combine/mcombine modes */
typedef enum
{
    FTM_PWM_IP_DITHER_LEADING_EDGE         = 0x00U,  /*!< The channel (n) dithering is used */
    FTM_PWM_IP_DITHER_TRAILING_EDGE        = 0x01U   /*!< The channel (n+1) dithering is used */
} Ftm_Pwm_Ip_PairDitherEdgeType;

#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
/*! @brief Defines the FTM fault control mode */
typedef enum
{
    FTM_PWM_IP_FAULT_DISABLED                    = 0x00U,  /*!< Fault control disabled for all channels. */
    FTM_PWM_IP_FAULT_EVEN_CHANNELS_MANUAL_CLEAR  = 0x01U,   /*!< Fault control enabled for even channels (0, 2, 4..) with manual fault clearing. */
    FTM_PWM_IP_FAULT_ALL_CHANNELS_MANUAL_CLEAR   = 0x02U,   /*!< Fault control enabled for all channels with manual fault clearing. */
    FTM_PWM_IP_FAULT_ALL_CHANNELS_AUTO_CLEAR     = 0x03U   /*!< Fault control enabled for all channels with automatic fault clearing. */
} Ftm_Pwm_Ip_FaultControlModeType;

/*! @brief FlexTimer PWM Fault output state */
typedef enum
{
    FTM_PWM_IP_OUT_SAFE_VALUE         = 0x00U,  /*!< FTM outputs will be placed into safe values */
    FTM_PWM_IP_OUT_TRI_STATE          = 0x01U   /*!< FTM outputs will be tri-stated  */
} Ftm_Pwm_Ip_FaultOutputStateType;
#endif

#if (defined (FTM_PWM_IP_NOTIFICATION_SUPPORT) && (FTM_PWM_IP_NOTIFICATION_SUPPORT == STD_ON))
/**
 *
 * @brief       Notification function callback type.
 */
typedef void (*Ftm_Pwm_Ip_CallbackType)(uint8 CbParam);

/**
 *
 * @brief       Structure for notification
 * @details     The structure used to notification
 */
typedef struct {
    Ftm_Pwm_Ip_CallbackType FunctionCallback;
    uint8 CbParam;
} Ftm_Pwm_Ip_CallbackCfgType;
#else
/* Callback for all ftm supported IRQs */
typedef void (*Ftm_Pwm_Ip_CallbackType)(void *UserData);

typedef struct {
    Ftm_Pwm_Ip_CallbackType FunctionCallback;
    void * CbParam;
} Ftm_Pwm_Ip_CallbackCfgType;
#endif

#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
/* Callback for all ftm supported IRQs */
typedef void (*Ftm_Pwm_Ip_ReloadCallbackType)(void *UserData);

typedef struct {
    Ftm_Pwm_Ip_ReloadCallbackType FunctionCallback;
    void * CbParam;
} Ftm_Pwm_Ip_ReloadCallbackCfgType;
#endif

/**
*
* @brief     Ftm configuration parameters structure
* @details   FlexTimer Sync and Load parameters
*/
typedef struct
{
    Ftm_Pwm_Ip_SyncModeType SyncMode;       /*!< Configure FTM Sync to use Software or Hardware trigger modes */
    boolean HwSync0;                        /*!< Enable/disable hardware 0 sync */
    boolean HwSync1;                        /*!< Enable/disable hardware 1 sync */
    boolean HwSync2;                        /*!< Enable/disable hardware 2 sync */
    boolean HwTriggerAutoClear;             /*!< Enable/disable auto clear of triggers in hardware trigger mode */
    boolean MaxLoadPoint;                   /*!< Enable/disable maximum loading point */
    boolean MinLoadPoint;                   /*!< Enable/disable minimum loading point */
#if (defined(FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD) && (FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD == STD_ON))
    boolean HalfCycleLoadPoint;             /*!< Enable/disable half cycle loading point */
    uint16 HalfCycleLoadPointValue;        /*!< The match value of FTM half cycle reload feature */
#endif
#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
    uint8 LoadPointFreq;                    /*!< Value of how many reload points must happen before reloading. */
#endif
    Ftm_Pwm_Ip_SyncType InverterSync;       /*!< Configures INVCTRL sync */
    Ftm_Pwm_Ip_SyncType OutRegSync;         /*!< Configures SWOCTRL sync */
    Ftm_Pwm_Ip_SyncType OutMaskSync;        /*!< Configures OUTMASK sync */
    Ftm_Pwm_Ip_SyncType InitCounterSync;    /*!< Configures CNTIN sync */
    Ftm_Pwm_Ip_SyncType CounterSync;        /*!< Configures FTM Counter sync */
} Ftm_Pwm_Ip_SyncCfgType;

/**
*
* @brief     Ftm configuration parameters structure
* @details   Ftm IP specific instance configuration structure type
*/
typedef struct
{
    Ftm_Pwm_Ip_ClkSourceType ClkSrc;                  /*!< Clock source for Ftm instances */
    Ftm_Pwm_Ip_ClkPrescalerType ClkPs;                /*!< Pre-scaler for Ftm instances */
    Ftm_Pwm_Ip_ClkPrescalerType AlternateClkPs;       /*!< Alternative pre-scaler for Ftm instances */
    Ftm_Pwm_Ip_CounterModeType CntMode;               /*!< Mode of the counter */
    boolean OverflowIrqEn;                            /*!< Selected the overflow interrupt */
    Ftm_Pwm_Ip_CallbackCfgType OverflowCb;            /*!< overflow callback */
#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
    boolean ReloadIrqEn;                              /*!< Selected the reload interrupt */
    Ftm_Pwm_Ip_ReloadCallbackCfgType ReloadCb;        /*!< Reload callback */
#endif
    Ftm_Pwm_Ip_DebugModeType DebugMode;               /*!< Debug Mode */
    boolean WriteProtection;                          /*!< Selected write protection */
    boolean InitTriggerEn;                            /*!< Selected trigger */
    Ftm_Pwm_Ip_InitTriggModeType InitTrigMode;        /*!< Chose generation of initialization trigger mode */
    uint16 PwmPeriod;                                 /*!< Period of Ftm instances */
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    uint8 PwmPeriodDither;                            /*!< Period Dither */
#endif
    uint16 DeadTimeValue;                             /*!< Deadtime Value */
    Ftm_Pwm_Ip_DeadtimePrescalerType DeadTimePs;      /*!< Deadtime pre-scaler Value */
#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    Ftm_Pwm_Ip_FaultControlModeType  FaultCtrMode;    /*!< Defines the FTM fault control mode */
    Ftm_Pwm_Ip_FaultOutputStateType  FaultOutState;   /*!< Fault output state */
    uint8 FaultInFilter;                              /*!< Fault Input Filter Value */
    boolean FaultIrqEn;                               /*!< Fault interrupt enable */
#endif
    const Ftm_Pwm_Ip_SyncCfgType* SyncCfg;            /*!< Pointer to the configured channels for the FTM sync */
} Ftm_Pwm_Ip_InstanceCfgType;

/**
*
* @brief     Ftm configuration parameters structure
* @details   FlexTimer Channel Pair configuration parameters
*/
typedef struct
{
    /** @brief  FTM pair id channel */
    uint8 PairId;
    /** @brief  Selected dead-time for pair channel */
    boolean DeadtimeEn;
    /** @brief  Selected Complementary mode for pair channel */
    boolean ComplementaryModeEn;
    /** @brief  Polarity of pair channel */
    Ftm_Pwm_Ip_PairChPolarityType PairChPolarity;
    /** @brief  Selected external trigger of pair channel */
    boolean PairExtTrigEn;
    /** @brief  Selected sync of pair channel */
    boolean PairSyncEn;
    /** @brief  the phase Shift Value */
    uint16 PhaseShiftValue;
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    Ftm_Pwm_Ip_PairDitherEdgeType DitherEdge;
#endif
} Ftm_Pwm_Ip_PairCfgType;

/**
*
* @brief     Ftm configuration parameters structure
* @details   FlexTimer Channel configuration parameters
*/
typedef struct
{
    /** @brief  FTM channel ID */
    uint8 ChannelId;
    /** @brief  Mode of Ftm channel */
    Ftm_Pwm_Ip_ChannelModeType ChannelMode;
    /** @brief  Selected for interrupt */
    boolean ChIrqEn;
    /** @brief Callback for the ftm channels */
    Ftm_Pwm_Ip_CallbackCfgType ChannelCb;
    /** @brief  Enable/Disable the output of the PWM signal on the channel pin.*/
    boolean ChOutputEn;
    /** @brief  Enable/Disable the software control for this channels output.*/
    boolean SwControlEn;
    /** @brief  Channel Software Output Control Value */
    boolean SwControlVal;
    /** @brief  Selected for external trigger */
    boolean ExtTrigEn;
#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
    /** @brief  Selected for external trigger */
    boolean ChMatchLoadEn;
#endif
    /** @brief  Duty cycle value */
    uint16 DutyCycle;
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    /** @brief  Duty cycle value in Dither */
    uint8 DutyCycleDither;
#endif
    /** @brief  Output state of Ftm channel */
    Ftm_Pwm_Ip_OutputStateType InitOut;
    /** @brief  Polarity of Ftm channel */
    Ftm_Pwm_Ip_PolarityType Polarity;
    /** @brief  The configuration of pair channel */
    const Ftm_Pwm_Ip_PairCfgType* PairCfg;
} Ftm_Pwm_Ip_ChannelConfigType;

#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
/**
* @brief      Fault channel notification typedef
*/
typedef void (*Ftm_Pwm_Ip_FaultCallbackType)(void);

/**
*
* @brief     Ftm configuration parameters structure
* @details   FlexTimer fault configuration parameters
*/
typedef struct
{
    /** @brief  FTM fault ID is actived */
    uint8 FaultId;
    /** @brief  Defines the polarity of the fault input. */
    Ftm_Pwm_Ip_PolarityType FaultPol;
    /** Fault Input Filter Enable */
    boolean  FaultFilEn;
    /** @brief Pointer to fault notification function */
    Ftm_Pwm_Ip_FaultCallbackType FaultCb;
} Ftm_Pwm_Ip_FaultChCfgType;
#endif

/**
*
* @brief     Ftm configuration parameters structure
* @details   FlexTimer User Configuration structure
*/
typedef struct
{
    /** @brief  Pointer to the configured channels for the FTM instance */
    const Ftm_Pwm_Ip_InstanceCfgType* InstanceCfg;
    /** @brief  Pointer to the configured channels array for the FTM channel */
    const Ftm_Pwm_Ip_ChannelConfigType* const * ConfiguredChArray;
    /** @brief  Number of the configured channels for the FTM channel */
    uint8 NoOfConfiguredCh;
#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    /** @brief  Pointer to the configured channels array for the FTM channel */
    const Ftm_Pwm_Ip_FaultChCfgType* const * ConfiguredFaultArray;
    /** @brief  Number of the configured channels for fault */
    uint8 NoOfFaultCfg;
#endif
} Ftm_Pwm_Ip_UserCfgType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_PWM_IP_TYPES_H */
