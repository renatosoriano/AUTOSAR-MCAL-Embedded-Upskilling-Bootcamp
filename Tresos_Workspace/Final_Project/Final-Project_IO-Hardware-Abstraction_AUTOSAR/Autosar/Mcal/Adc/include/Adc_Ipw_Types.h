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

#ifndef ADC_IPW_TYPES_H
#define ADC_IPW_TYPES_H

/**
*   @file
*
*   @internal
*   @addtogroup adc_ipw Adc Ipw
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

#include "Adc_Ipw_CfgDefines.h"
#include "Adc_Ip_Types.h"
#include "Pdb_Adc_Ip_Types.h"
#include "Adc_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IPW_VENDOR_ID_TYPES                       43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES        4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES        7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES     0
#define ADC_IPW_SW_MAJOR_VERSION_TYPES                2
#define ADC_IPW_SW_MINOR_VERSION_TYPES                0
#define ADC_IPW_SW_PATCH_VERSION_TYPES                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Ipw_Types.h file and Adc_Ipw_CfgDefines.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TYPES != ADC_IPW_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ipw_Types.h and Adc_Ipw_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_Ipw_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_IPW_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES != ADC_IPW_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES != ADC_IPW_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Types.h and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_Ipw_CfgDefines.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TYPES != ADC_IPW_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_MINOR_VERSION_TYPES != ADC_IPW_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_PATCH_VERSION_TYPES != ADC_IPW_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Types.h and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_Ip_Types.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TYPES != ADC_IP_VENDOR_ID_TYPES)
    #error "Adc_Ipw_Types.h and Adc_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_Ip_Types.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES != ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES != ADC_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Types.h and Adc_Ip_Types.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_Ip_Types.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TYPES != ADC_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_TYPES != ADC_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_TYPES != ADC_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Types.h and Adc_Ip_Types.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Pdb_Adc_Ip_Types.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TYPES != PDB_ADC_IP_VENDOR_ID_TYPES)
    #error "Adc_Ipw_Types.h and Pdb_Adc_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Types.h file and Pdb_Adc_Ip_Types.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Types.h and Pdb_Adc_Ip_Types.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Pdb_Adc_Ip_Types.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TYPES != PDB_ADC_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_TYPES != PDB_ADC_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_TYPES != PDB_ADC_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Types.h and Pdb_Adc_Ip_Types.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_CfgDefines.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_TYPES != ADC_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ipw_Types.h and Adc_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES != ADC_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES != ADC_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Types.h and Adc_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_Types.h file and Adc_CfgDefines.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_TYPES != ADC_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_MINOR_VERSION_TYPES != ADC_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_PATCH_VERSION_TYPES != ADC_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Types.h and Adc_CfgDefines.h are different"
#endif
/*==================================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef uint8 Adc_HwUnitType;             /**< @brief Numeric ID of an ADC Hw Unit */

/* SWS_Adc_00506 */
/** @implements     Adc_ChannelType_uint */
typedef uint16 Adc_ChannelType;           /**< @brief Numeric ID of an ADC channel */

/* SWS_Adc_00507 */
/** @implements     Adc_GroupType_uint */
typedef uint16 Adc_GroupType;             /**< @brief Numeric ID of an ADC channel group. No uC dependent */
typedef uint16 Adc_QueueIndexType;        /**< @brief Index for the queue of groups */

/* SWS_Adc_00510 */
/** @implements     Adc_ConversionTimeType_uint */
typedef uint8 Adc_ConversionTimeType;     /**< @brief conversion time */

/* SWS_Adc_00508 */
/** @implements     Adc_ValueGroupType_int */
typedef uint16 Adc_ValueGroupType;        /**< @brief type for ADC result of one channel */

/* SWS_Adc_00521 */
/** @implements     Adc_HwTriggerTimerType_uint */
typedef Pdb_Adc_Ip_TriggerSrcType Adc_HwTriggerTimerType;    /**< @brief Type for the reload value of the ADC embedded timer */
typedef uint8 Adc_ChannelIndexType;                   /**< @brief Number of channels */

/**
* @brief          Adc group conversion.
* @details        Used for value received by Tressos interface configuration.
*
*/
typedef enum
{
    ADC_CONV_TYPE_NORMAL   = 0U,    /**< @brief Normal conversion mode */
    ADC_CONV_TYPE_INJECTED = 1U     /**< @brief Injected conversion mode */
} Adc_GroupConvType;

#if (ADC_CALIBRATION == STD_ON)
typedef struct
{
    Std_ReturnType AdcUnitSelfTestStatus;                       /**< @brief Unit calibration result status */
#if (ADC_IPW_CALSTAT_AVAILABLE == STD_ON)
    uint8 AdcCalibrateFailedSteps[ADC_MAX_CALIBRATION_STEPS];   /**< @brief List of failed tests */
#endif /* (ADC_IPW_CALSTAT_AVAILABLE == STD_ON) */
} Adc_CalibrationStatusType;
#endif /* ADC_CALIBRATION == STD_ON */


#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          Group Access Mode type.
* @details        Used for value received by Tressos interface configuration.
*/
typedef enum
{
    ADC_NORMAL = 0U, /**< @brief Normal mode */
    ADC_ALTERNATE    /**< @brief Alternate mode */
} Adc_SelectPrescalerType;
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

/**
* @brief          Adc Group conversion mode.
* @details        Used for value received by Tressos interface configuration.
*
* SWS_Adc_00515, SWS_Adc_00380, SWS_Adc_00381
* @implements     Adc_GroupConvModeType_enum
*/
typedef enum
{
    ADC_CONV_MODE_ONESHOT    = 0U,  /*!< One-shot conversion mode */
    ADC_CONV_MODE_CONTINUOUS = 1U   /*!< Scan conversion mode */
} Adc_GroupConvModeType;


#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Range select values.
* @details        Indicates which range select is used.
*
* @implements  Adc_ChannelRangeSelectType_enum
* SWS_Adc_00524
*/
typedef enum
{
    ADC_RANGE_ALWAYS = 0U,   /**< @brief Complete range - independent from channel limit settings */
    ADC_RANGE_BETWEEN,       /**< @brief Range between low limit and high limit - high limit value included */
    ADC_RANGE_NOT_BETWEEN,   /**< @brief Range above high limit or below low limit - low limit value included */
    ADC_RANGE_NOT_OVER_HIGH, /**< @brief Range below high limit - high limit value included */
    ADC_RANGE_NOT_UNDER_LOW, /**< @brief Range above low limit */
    ADC_RANGE_OVER_HIGH,     /**< @brief Range above high limit */
    ADC_RANGE_UNDER_LOW      /**< @briefRange below low limit - low limit value included */
} Adc_ChannelRangeSelectType;

typedef struct
{
    const boolean ChannelLimitCheckEnabled;        /**< @brief Channel limit checking enabled */
    const Adc_ChannelRangeSelectType ChannelRange; /**< @brief Range conversion */
    const uint16 ChannelHighLimit;                  /**< @brief High limit channel conversion value */
    const uint16 ChannelLowLimit;                   /**< @brief Low limit channel conversion value */
} Adc_ChannelLimitCheckingType;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

typedef struct
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    const uint8 GroupAvgEnable;
    /**< @brief Main Average selection of group */
    const Adc_Ip_AvgSelectType GroupAvgSelect;
    Adc_ConversionTimeType ConvTime;
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    const uint8 GroupAvgEnableAlternate;
    /**< @brief Alternate Average selection of group */
    const Adc_Ip_AvgSelectType GroupAvgSelectAlternate;
    Adc_ConversionTimeType AlternateConvTime;
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    /**< @brief The period PDB for continuous mode */
    const uint16 PdbPeriod;
    /**< @brief The delay for next PDB */
    const uint16 PdbDelay;
    /**< @brief Enables or Disables the ADC Back to Back configuration for Group Channels */
    const boolean AdcGroupEnableBackToBack;
    /**< @brief Enables or Disables the ADC pre-trigger delay configuration for each Group Channel */
    const boolean AdcGroupEnableChannelDelays;
    /**< @brief Channel delays */
    const uint16 * DelayPtr;
} Adc_Ipw_GroupConfig;

typedef struct
{
    const uint8 AdcDmaInterruptSoftware[ADC_IPW_MAX_HW_UNITS];              /**< @brief DMA or Interrupt driven */
    const Adc_GroupType AdcGroups[ADC_IPW_MAX_HW_UNITS];                     /**< @brief Number of groups configured for each unit */
    const Adc_ChannelType AdcChannels[ADC_IPW_MAX_HW_UNITS];                 /**< @brief Number of channels of the hw unit x */
    const uint8 AdcDmaChannelLogicId[ADC_IPW_MAX_HW_UNITS];                       /**< @brief If dma driven then indicates the dma channel number for HW UNITS */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    const uint8 AdcCountingDmaChanLogicId[ADC_IPW_MAX_HW_UNITS];               /**< @brief If dma driven then indicates the dma linked channel number for HW UNITS in optimize DMA streaming groups multiple channels feature*/
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
    const uint8 AdcHwUnitArr[ADC_IPW_MAX_HW_UNITS];                           /**< @brief If unit x is active STD_ON/STD_OFF on current partition. Indexed by Physical Hw Index */
    const Adc_HwUnitType HwLogicalId[ADC_IPW_MAX_HW_UNITS];                   /**< Mapping between Physical Id and Logical Id */
} Adc_Ipw_MultiConfigType;

typedef struct
{
    const Adc_Ip_ConfigType * AdcConfigPtrArr[ADC_IPW_MAX_HW_UNITS];
    const Pdb_Adc_Ip_ConfigType * PdbConfig[ADC_IPW_MAX_HW_UNITS];
    Adc_HwUnitType AdcPhysicalIdArr[ADC_IPW_MAX_HW_UNITS];
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    const Adc_Ip_ClockConfigType * AdcAltClockConfig[ADC_IPW_MAX_HW_UNITS];
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    const Adc_ChannelLimitCheckingType * ChannelLimitCheckingConfigs[ADC_IPW_MAX_HW_UNITS];
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    /** @brief Miscellaneous configuration parameters */
    const Adc_Ipw_MultiConfigType Mapping;
} Adc_Ipw_Config;

#if (ADC_ENABLE_READ_RAW_DATA_API == STD_ON)
/**
* @brief           Number of ADC result registers
*/
#define ADC_IPW_RES_REG_NUM     (ADC_MAX_CHAN_COUNT)
/**
* @brief           Max channel index
*/
#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
    #define ADC_IPW_MAX_CHN_ID      (ADC_IP_INPUTCHAN_SUPPLY_VDD_LV)
#elif (FEATURE_ADC_MAX_EXT_CHAN_ID <= 15u)
    #define ADC_IPW_MAX_CHN_ID      (ADC_IP_INPUTCHAN_VREFL)
#elif (FEATURE_ADC_MAX_EXT_CHAN_ID <= 23u)
    #define ADC_IPW_MAX_CHN_ID      (ADC_IP_INPUTCHAN_EXT23)
#else
    #define ADC_IPW_MAX_CHN_ID      (ADC_IP_INPUTCHAN_EXT31)
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */
#endif /* (ADC_ENABLE_READ_RAW_DATA_API == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IPW_TYPES_H */
