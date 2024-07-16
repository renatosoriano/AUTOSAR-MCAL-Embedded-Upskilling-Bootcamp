/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC
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

#ifndef ADC_TYPES_H
#define ADC_TYPES_H

/**
*   @file
*
*   @addtogroup adc_driver
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
#include "Adc_Ipw_Types.h"
#include "Adc_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_TYPES                         43
#define ADC_AR_RELEASE_MAJOR_VERSION_TYPES          4
#define ADC_AR_RELEASE_MINOR_VERSION_TYPES          7
#define ADC_AR_RELEASE_REVISION_VERSION_TYPES       0
#define ADC_SW_MAJOR_VERSION_TYPES                  2
#define ADC_SW_MINOR_VERSION_TYPES                  0
#define ADC_SW_PATCH_VERSION_TYPES                  0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Types.h file and Adc_Ipw_Types.h file are of the same vendor */
#if (ADC_VENDOR_ID_TYPES != ADC_IPW_VENDOR_ID_TYPES)
    #error "Adc_Types.h and Adc_Ipw_Types.h have different vendor ids"
#endif

/* Check if Adc_Types.h file and Adc_Ipw_Types.h file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_MINOR_VERSION_TYPES != ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_REVISION_VERSION_TYPES != ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Types.h and Adc_Ipw_Types.h are different"
#endif

/* Check if Adc_Types.h file and Adc_Ipw_Types.h file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_TYPES != ADC_IPW_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SW_MINOR_VERSION_TYPES != ADC_IPW_SW_MINOR_VERSION_TYPES) || \
     (ADC_SW_PATCH_VERSION_TYPES != ADC_IPW_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Types.h and Adc_Ipw_Types.h are different"
#endif

/* Check if Adc_Types.h file and Adc_CfgDefines.h file are of the same vendor */
#if (ADC_VENDOR_ID_TYPES != ADC_VENDOR_ID_CFGDEFINES)
    #error "Adc_Types.h and Adc_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Types.h file and Adc_CfgDefines.h file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_AR_RELEASE_MINOR_VERSION_TYPES != ADC_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_AR_RELEASE_REVISION_VERSION_TYPES != ADC_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Types.h and Adc_CfgDefines.h are different"
#endif

/* Check if Adc_Types.h file and Adc_CfgDefines.h file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_TYPES != ADC_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SW_MINOR_VERSION_TYPES != ADC_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SW_PATCH_VERSION_TYPES != ADC_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Types.h and Adc_CfgDefines.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          ADC driver status
* @details        Used to differentiate if ADC driver is already uninit, during init or already
*                 initialized or not.
*
*/
typedef enum
{
    ADC_STATE_UNINIT = 0x00U,   /**< @brief Adc driver uninitialized */
    ADC_STATE_BUSY   = 0x01U,   /**< @brief Adc driver busy */
    ADC_STATE_IDLE   = 0x02U    /**< @brief Adc driver idle */
} Adc_GlobalStateType;


/**
* @brief          ADC group already converted type.
* @details        Used to differentiate if group is already converted or not.
*
*/
typedef enum
{
    ADC_NOT_YET_CONVERTED = 0x00U, /**< @brief Group not yet converted */
    ADC_ALREADY_CONVERTED = 0x01U  /**< @brief Group is already converted */
} Adc_GroupConversionStateType;

/**
* @brief          Adc group access Mode.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_GroupAccessModeType_enum
* SWS_Adc_00528
*/
typedef enum
{
    ADC_ACCESS_MODE_SINGLE    = 0x00U,  /**< @brief Single access mode */
    ADC_ACCESS_MODE_STREAMING = 0x01U   /**< @brief Streaming access mode */
} Adc_GroupAccessModeType;

/**
* @brief          Adc group replacement.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_GroupReplacementType_enum
* SWS_Adc_00523
*/
typedef enum
{
    ADC_GROUP_REPL_ABORT_RESTART  = 0x00U,  /**< @brief Abort and restart of group*/
    ADC_GROUP_REPL_SUSPEND_RESUME = 0x01U   /**< @brief Suspend and resuming of group*/
} Adc_GroupReplacementType;

/**
* @brief          Adc group streaming buffer mode.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_StreamBufferModeType_enum
* SWS_Adc_00519
*/
typedef enum
{
    ADC_STREAM_BUFFER_LINEAR   = 0x00U, /**< @brief Linear streaming*/
    ADC_STREAM_BUFFER_CIRCULAR = 0x01U  /**< @brief Circular streaming*/
} Adc_StreamBufferModeType;

/**
* @brief          ADC group status.
* @details        ADC group enumeration type.
*
* @implements     Adc_StatusType_enum
* SWS_Adc_00513
*/
typedef enum
{
    ADC_IDLE             = 0x00U,   /**< @brief Group is in IDLE state*/
    ADC_BUSY             = 0x01U,   /**< @brief Group is in BUSY state */
    ADC_COMPLETED        = 0x02U,   /**< @brief Group is in COMPLETED state*/
    ADC_STREAM_COMPLETED = 0x03U    /**< @brief Group is in STREAM_COMPLETED state*/
} Adc_StatusType;

/**
* @brief          ADC group notification.
* @details        Indicates if notification is enabled for the group.
*
*/
typedef enum
{
    ADC_NOTIFICATION_DISABLED = 0x00U,  /**< @brief Notification is disabled */
    ADC_NOTIFICATION_ENABLED  = 0x01U   /**< @brief Notification is enabled */
} Adc_NotificationType;

/**
* @brief          Adc hardware trigger edge.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_HwTriggerSignalType_enum
* SWS_Adc_00520
*/

typedef enum
{
    ADC_HW_TRIG_RISING_EDGE  = 0x00U,   /**< @brief Rising edge */
    ADC_HW_TRIG_FALLING_EDGE = 0x01U,   /**< @brief Falling edge */
    ADC_HW_TRIG_BOTH_EDGES   = 0x02U    /**< @brief falling and rising edge */
} Adc_HwTriggerSignalType;

/**
* @brief          Adc hardware trigger source.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_TriggerSourceType_enum
* SWS_Adc_00514
*/
typedef enum
{
    ADC_TRIGG_SRC_SW = 0x00U    /**< @brief Software triggered */
#if (ADC_HW_TRIGGER_API == STD_ON)
,
    ADC_TRIGG_SRC_HW = 0x01U    /**< @brief Hardware triggered */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
} Adc_TriggerSourceType;

#if (STD_ON == ADC_HW_TRIGGER_API)
/**
* @brief          Adc Hardware trigger.
* @details        Indicates if hardware trigger is enabled for group.
*
*/
typedef enum
{
    ADC_HWTRIGGER_DISABLED = 0x00U, /**< @brief Hardware trigger is disabled */
    ADC_HWTRIGGER_ENABLED  = 0x01U  /**< @brief Hardware trigger is enabled */
} Adc_HwTriggeringType;

#endif /* (STD_ON==ADC_HW_TRIGGER_API) */


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef void (*Adc_NotifyType)(void);     /**< @brief Notification function pointer definition */

/* SWS_Adc_00512 */
/** @implements     Adc_ResolutionType_uint */
typedef uint8 Adc_ResolutionType;         /**< @brief channel resolution in number of bits */

#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
/* SWS_Adc_00516 */
/** @implements     Adc_GroupPriorityType_uint */
typedef uint8 Adc_GroupPriorityType;      /**< @brief ADC Channel group priority */
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */

/* SWS_Adc_00517 */
/** @implements     Adc_GroupDefType_uint */
typedef Adc_ChannelType Adc_GroupDefType; /**< @brief definition of channels in a group */

/* SWS_Adc_00509 */
/** @implements     Adc_PrescaleType_uint */
typedef uint8 Adc_PrescaleType;           /**< @brief clock prescaler factor */

/* SWS_Adc_00511 */
/** @implements     Adc_SamplingTimeType_uint */
typedef uint8 Adc_SamplingTimeType;       /**< @brief sampling time */

/* SWS_Adc_00518 */
/** @implements     Adc_StreamNumSampleType_uint */
typedef uint16 Adc_StreamNumSampleType;   /**< @brief Number of samples of a streaming conversion buffer */

/**
* @brief          Structure for validation results
* @details        This structure contains the validation information
*
*/
typedef struct
{
    boolean EndValidations; /**< @brief Signal if validation ended */
    Std_ReturnType ValidParams; /**< @brief Return status */
} Adc_ValidationResultType;

/**
* @brief          Structure for group status.
* @details        This structure contains the group status information.
*
*/
typedef struct
{
    volatile Adc_StatusType Conversion;                     /**< @brief Group status */
    volatile Adc_GroupConversionStateType AlreadyConverted; /**< @brief Group was previously converted or not */
#if (ADC_HW_TRIGGER_API == STD_ON)
    Adc_HwTriggeringType HwTriggering;                      /**< @brief hw trigger enabled/disabled */
#endif /* ADC_HW_TRIGGER_API == STD_ON */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    Adc_NotificationType Notification;                      /**< @brief notification enabled/disabled */
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
    volatile Adc_StreamNumSampleType ResultIndex;            /**< @brief index into streaming buffer that is currently being filled */
    /* SWS_Adc_00319, SWS_Adc_00318 */
    Adc_ValueGroupType * ResultsBufferPtr;                  /**< @brief Pointer to user result buffer array */
#ifdef ADC_CURRENT_CHANNEL_USED
    Adc_ChannelIndexType CurrentChannel;                     /**< @brief Current channel in use */
#endif /* ADC_CURRENT_CHANNEL_USED */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    volatile boolean LimitCheckFailed;                      /**< @brief check limit check fail */
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
} Adc_GroupStatusType;

/**
* @brief          Structure for hardware unit status.
* @details        This structure contains the HW unit status information.
*
*/
typedef struct
{
    /** @brief Filled slots in the queue */
    volatile Adc_QueueIndexType SwNormalQueueIndex;
    /** @brief Queued groups indexes, always executing Queue[0] */
    volatile Adc_GroupType SwNormalQueue[ADC_QUEUE_MAX_DEPTH_MAX];
#if (ADC_HW_TRIGGER_API == STD_ON)
    /** @brief Ongoing hardware group ID */
    volatile Adc_GroupType OngoingHwGroup;
#endif /* ADC_HW_TRIGGER_API == STD_ON */
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
    /** @brief The depth of the software injected queue */
    volatile Adc_GroupType SwInjectedQueue[1U];
    /** @brief Filled slots in the Sw injected queue */
    volatile Adc_QueueIndexType SwInjectedQueueIndex;
#endif /* (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON) */
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
    /** @brief Indicates Ctu control mode is ongoing */
    boolean CtuControlOngoing;
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */
#if (ADC_IPW_PDB_AVAILABLE == STD_ON)
    uint8 Sc1Used;
#endif /* (ADC_IPW_PDB_AVAILABLE == STD_ON) */
} Adc_UnitStatusType;

#if (ADC_SETCHANNEL_API == STD_ON)
typedef struct
{
    /** @brief Run time assigned channels to group */
    const Adc_GroupDefType * ChannelPtr;
    /** @brief Run time number of channels */
    Adc_ChannelIndexType ChannelCount;
    /** @brief Indicates whether the configuration has been updated or not */
    boolean RuntimeUpdated;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* @brief Indicates whether ChannelPtr has channel with limit checking enabled */
    boolean AdcRuntimeGroupLimitcheck;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#if (ADC_IPW_PDB_AVAILABLE == STD_ON)
    /** @brief Run time assigned delay of channels group */
    const uint16 * DelaysPtr;
    /** @brief Mask per channel - to be updated or not */
    uint32 RuntimeChanMask;
#endif /* (ADC_IPW_PDB_AVAILABLE == STD_ON) */
} Adc_RuntimeGroupChannelType;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

typedef struct
{
    const Adc_GroupType GroupId;                               /**< @brief Index of group */
    const Adc_HwUnitType AdcLogicalUnitId;                     /**< @brief The ADC Logical Unit Id that the group belongs to */
    const Adc_GroupAccessModeType AccessMode;                 /**< @brief Access Mode */
    const Adc_GroupConvModeType Mode;                         /**< @brief Conversion Mode (OneShot/Continuous) */
    const Adc_GroupConvType Type;                             /**< @brief Conversion type (Normal/Injected) */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    const Adc_GroupPriorityType Priority;                      /**< @brief Priority of group */
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
    const Adc_GroupReplacementType ReplacementMode;           /**< @brief Replacement Mode */
    const Adc_TriggerSourceType TriggerSource;                /**< @brief Hw/Sw trigger */
#if (STD_ON == ADC_HW_TRIGGER_API)
    const Adc_HwTriggerTimerType HwTriggerSource;              /**< @brief Hardware trigger source for the group */
    const Adc_HwTriggerSignalType TriggerEdge;                /**< @brief Hardware trigger edge */
    #if (ADC_IPW_CTU_AVAILABLE == STD_ON)
    const Adc_HwTriggerTimerType HwTriggerCompareValue;        /**< @brief Counter Compare Value to reload CTU Trigger */
    #endif /* (ADC_IPW_CTU_AVAILABLE == STD_ON) */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    /* SWS_Adc_00104 */
    const Adc_NotifyType Notification;                         /**< @brief Pointer to notification function */
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
    /* CPR-MCAL-797.adc */
    const Adc_NotifyType ExtraNotification;                    /**< @brief Pointer to extra notification function */
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

    const Adc_StreamBufferModeType BufferMode;                /**< @brief Buffer Mode */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    const Adc_GroupType EnableChDisableChGroupIndex;           /**< @brief Group's index if it has the support to enable/disable channel */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    const Adc_StreamNumSampleType NumSamples;                  /**< @brief Number of samples */
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    const boolean StreamResultGroupMultiSets;                 /**< @brief Arrange the results as multiple sets of group result buffer */
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
    const Adc_GroupDefType * AssignmentPtr;                      /**< @brief Assigned channels to group */
    const Adc_ChannelIndexType AssignedChannelCount;           /**< @brief Number of channels */

    const Adc_ChannelType LastCh;                              /**< @brief Last channel configured */
    const Adc_ChannelType FirstCh;                             /**< @brief First channel configured */
    /* PR-MCAL-3229.adc */
    const uint8 AdcWithoutInterrupt;                         /**< @brief Enables or Disables the ADC and DMA interrupts */
    const uint8 AdcExtDMAChanEnable;                         /**< @brief Enables or Disables configuring external DMA channel in the group */
    const boolean AdcWithoutDma;                             /**< @brief When true, disables completely DMA configuration done by ADC driver for the group */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    const boolean AdcOptimizeDmaStream;                       /**< @brief Enables or Disables the ADC optimize DMA streaming groups feature */
    const boolean HalfInterrupt;                              /**< @brief Enable half interrupt for optimize DMA streaming groups feature */
#endif
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    const boolean AdcGroupLimitcheck;                         /**< @brief Enables or disables the usage of limit checking for an ADC group. */
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#ifndef ADC_CMR_REGISTER_NOT_SUPPORTED
    Adc_ChansIdxMaskType AssignedChannelMask;
#endif /* ADC_CMR_REGISTER_NOT_SUPPORTED */
#if (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON)
    const uint8 CtuTrigListPos;                              /**< @brief First position of channel in BCTU channel list or CTU command list. */
#endif /* (ADC_CTU_HW_TRIGGER_OPTIMIZATION == STD_ON) */
#if ((ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) || (ADC_IPW_PDB_AVAILABLE == STD_ON))
    Adc_Ipw_GroupConfig const * AdcIpwGroupConfigPtr;
#endif /* ((ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) || (ADC_IPW_PDB_AVAILABLE == STD_ON)) */
} Adc_GroupConfigurationType;


/**
* @brief          Structure for ADC configuration.
* @details        Data structure containing the set of configuration parameters required
*                 for initializing the ADC Driver.
* @api
* @implements     Adc_ConfigType_struct
* SWS_Adc_00505
*/
typedef struct
{
    Adc_Ipw_Config const * AdcIpwConfigPtr;

    /** @brief Group configurations */
    const Adc_GroupConfigurationType * GroupsPtr;
    /** @brief Total number of groups */
    Adc_GroupType GroupCount;
    /** @brief Miscellaneous configuration parameters */
    const uint16 * GroupIdToIndexMapPtr;
    /** @brief Configuration CoreID */
    uint8 CoreId;
    /**< @brief Assigned Partition*/
    const uint8 * AssignmentPartitionPtr; /* generated from ECUC partition reference. */
    /**< @brief Number of Partition */
    const uint8 AssignedPartitionCount; /* remove if AssignmentPartitionPtr is removed */
} Adc_ConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_TYPES_H */
