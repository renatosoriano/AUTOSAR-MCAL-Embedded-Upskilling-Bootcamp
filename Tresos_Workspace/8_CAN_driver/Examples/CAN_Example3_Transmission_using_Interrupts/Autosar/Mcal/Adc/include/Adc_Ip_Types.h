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

#ifndef ADC_IP_TYPES_H
#define ADC_IP_TYPES_H

/**
*   @file
*
*   @addtogroup adc_ip Adc IPL
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
#include "StandardTypes.h"
#include "Adc_Ip_CfgDefines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID_TYPES                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES       7
#define ADC_IP_AR_RELEASE_REVISION_VERSION_TYPES    0
#define ADC_IP_SW_MAJOR_VERSION_TYPES               2
#define ADC_IP_SW_MINOR_VERSION_TYPES               0
#define ADC_IP_SW_PATCH_VERSION_TYPES               0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if Adc_Ip_Types.h file and Adc_Ip_CfgDefines.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_TYPES != ADC_IP_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ip_Types.h and Adc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ip_Types.h file and Adc_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES != ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_TYPES != ADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ip_Types.h and Adc_Ip_CfgDefines.h are different"
#endif

/* Check if Adc_Ip_Types.h file and Adc_Ip_CfgDefines.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_TYPES != ADC_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IP_SW_MINOR_VERSION_TYPES != ADC_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IP_SW_PATCH_VERSION_TYPES != ADC_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ip_Types.h and Adc_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Ip_Types.h file and StandardTypes.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Ip_Types.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief ADC IP status return type
 *
 * This structure is used as return type
 *
 * Implements : Adc_Ip_StatusType_Class
 */
typedef enum
{
    ADC_IP_STATUS_SUCCESS = 0x00U,      /*!< Function completed successfully */
    ADC_IP_STATUS_ERROR   = 0x01U,      /*!< Function didn't complete successfully */
    ADC_IP_STATUS_TIMEOUT = 0x02U       /*!< Function operation timed out */
} Adc_Ip_StatusType;

/*!
 * @brief Clock divider selection
 *
 * This structure is used to configure the converter input clock
 *
 * Implements : Adc_Ip_ClockSelType_Class
 */
typedef enum
{
    ADC_IP_CLK_FULL_BUS    = 0x00U,     /*!< Input clock divided by 1. */
    ADC_IP_CLK_HALF_BUS    = 0x01U,     /*!< Input clock divided by 2. */
    ADC_IP_CLK_QUARTER_BUS = 0x02U,     /*!< Input clock divided by 4. */
    ADC_IP_CLK_EIGHTH_BUS  = 0x03U,     /*!< Input clock divided by 8. */
} Adc_Ip_ClockSelType;

/*!
 * @brief Conversion resolution selection
 *
 * Implements : Adc_Ip_ResolutionType_Class
 */
typedef enum
{
    ADC_IP_RESOLUTION_8BIT  = 0x00U,    /*!< 8-bit resolution mode */
    ADC_IP_RESOLUTION_12BIT = 0x01U,    /*!< 12-bit resolution mode */
    ADC_IP_RESOLUTION_10BIT = 0x02U     /*!< 10-bit resolution mode */
} Adc_Ip_ResolutionType;

/*!
 * @brief Input clock source selection
 *
 * This structure is used to select the input clock source
 *
 * Implements : Adc_Ip_ClkSourceType_Class
 */
typedef enum
{
    ADC_IP_CLK_ALT_1 = 0x00U,       /*!< Input clock alternative 1. */
    ADC_IP_CLK_ALT_2 = 0x01U,       /*!< Input clock alternative 2. */
    ADC_IP_CLK_ALT_3 = 0x02U,       /*!< Input clock alternative 3. */
    ADC_IP_CLK_ALT_4 = 0x03U        /*!< Input clock alternative 4. */
} Adc_Ip_ClkSourceType;

/*!
 * @brief Hardware average selection
 *
 * This structure is used to select the number of conversions to average
 * in order to get the conversion data.
 *
 * Implements : Adc_Ip_AvgSelectType_Class
 */
typedef enum {
    ADC_IP_AVG_4_CONV  = 0x00U,       /*!< 4 conversions per conversion data */
    ADC_IP_AVG_8_CONV  = 0x01U,       /*!< 8 conversions per conversion data */
    ADC_IP_AVG_16_CONV = 0x02U,       /*!< 16 conversions per conversion data */
    ADC_IP_AVG_32_CONV = 0x03U,       /*!< 32 conversions per conversion data */
} Adc_Ip_AvgSelectType;

/*!
 * @brief Trigger type selection
 *
 * Implements : Adc_Ip_TrigType_Class
 */
typedef enum
{
    ADC_IP_TRIGGER_SOFTWARE = 0x00U,        /*!< Software trigger. */
    ADC_IP_TRIGGER_HARDWARE = 0x01U         /*!< Hardware trigger. */
} Adc_Ip_TrigType;

#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
/*!
 * @brief Pretrigger source selection
 *
 * This structure provides the pretrigger source options for the ADCxPRETRGSEL
 * field found in SIM[ADCOPT] register
 *
 * Implements : Adc_Ip_PretriggerSelType_Class
 */
typedef enum
{
    ADC_IP_PRETRIGGER_SEL_PDB     = 0x00U,      /*!< PDB pretrigger selected. */
    ADC_IP_PRETRIGGER_SEL_TRGMUX  = 0x01U,      /*!< TRGMUX pretrigger selected. */
    ADC_IP_PRETRIGGER_SEL_SW      = 0x02U       /*!< Software pretrigger selected. */
} Adc_Ip_PretriggerSelType;

/*!
 * @brief Software pretrigger type
 *
 * This structure provides the software pretrigger options for the ADCxSWPRETRG
 * field found in SIM[ADCOPT] register
 *
 * Implements : Adc_Ip_PretriggerSelType_Class
 */
typedef enum
{
    ADC_IP_SOFTWARE_PRETRIGGER_DISABLED = 0x00U,
    ADC_IP_SOFTWARE_PRETRIGGER_0        = 0x04U,
    ADC_IP_SOFTWARE_PRETRIGGER_1        = 0x05U,
    ADC_IP_SOFTWARE_PRETRIGGER_2        = 0x06U,
    ADC_IP_SOFTWARE_PRETRIGGER_3        = 0x07U
} Adc_Ip_SoftwarePretriggerType;

/*!
 * @brief Trigger source selection
 *
 * This structure provides the trigger source options for the ADCxTRGSEL
 * field found in SIM[ADCOPT] register
 *
 * Implements : Adc_Ip_TrigSelType_Class
 */
typedef enum
{
    ADC_IP_TRIGGER_SEL_PDB        = 0x00U,      /*!< PDB trigger selected. */
    ADC_IP_TRIGGER_SEL_TRGMUX     = 0x01U       /*!< TRGMUX trigger selected. */
} Adc_Ip_TrigSelType;
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */

/*!
 * @brief Voltage reference selection
 *
 * Implements : Adc_Ip_VoltageReferenceType_Class
 */
typedef enum
{
    ADC_IP_VOLTAGEREF_VREF = 0x00U,        /*!< VrefH and VrefL as Voltage reference. */
    ADC_IP_VOLTAGEREF_VALT = 0x01U         /*!< ValtH and ValtL as Voltage reference. */
} Adc_Ip_VoltageReferenceType;

/*!
 * @brief Enumeration of input channels assignable to a control channel.
 * \n <b>Note 0</b>: entries in this enum are affected by ::FEATURE_ADC_NUM_EXT_CHANS, which is device dependent
 * and controlled from <i>"device_name"_features.h</i> file.
 *
 * \n <b>Note 1</b>: the actual number of external channels may differ between device packages
 * and ADC instances. Reading a channel that is not connected externally, will return a random value within the range.
 * Please refer to the Reference Manual for the maximum number of external channels for each device variant and ADC instance.
 *
 * \n <b>Note 2</b>: ADC_IP_INPUTCHAN_SUPPLY_ select which internal supply channel to be measured.
 * They are only available for ADC0 and measured internally via internal input channel 0.
 * Please note that supply monitoring needs to be enabled separately via dedicated flag in adc_converter_config_t.
 *
 * Implements : Adc_Ip_InputChannelType_Class
 */
typedef enum
{
    ADC_IP_INPUTCHAN_EXT0      = 0x00U,                 /*!< External input channel 0 */
    ADC_IP_INPUTCHAN_EXT1      = 0x01U,                 /*!< External input channel 1 */
#if (FEATURE_ADC_HAS_CHANNEL_2)
    ADC_IP_INPUTCHAN_EXT2      = 0x02U,                 /*!< External input channel 2 */
#endif /* (FEATURE_ADC_HAS_CHANNEL_2) */
    ADC_IP_INPUTCHAN_EXT3      = 0x03U,                 /*!< External input channel 3 */
    ADC_IP_INPUTCHAN_EXT4      = 0x04U,                 /*!< External input channel 4 */
    ADC_IP_INPUTCHAN_EXT5      = 0x05U,                 /*!< External input channel 5 */
    ADC_IP_INPUTCHAN_EXT6      = 0x06U,                 /*!< External input channel 6 */
    ADC_IP_INPUTCHAN_EXT7      = 0x07U,                 /*!< External input channel 7 */
#if (FEATURE_ADC_HAS_CHANNEL_8)
    ADC_IP_INPUTCHAN_EXT8      = 0x08U,                 /*!< External input channel 8 */
#endif /* (FEATURE_ADC_HAS_CHANNEL_8) */
#if (FEATURE_ADC_HAS_CHANNEL_9)
    ADC_IP_INPUTCHAN_EXT9      = 0x09U,                 /*!< External input channel 9 */
#endif /* (FEATURE_ADC_HAS_CHANNEL_9) */
    ADC_IP_INPUTCHAN_EXT10     = 0x0AU,                 /*!< External input channel 10 */
    ADC_IP_INPUTCHAN_EXT11     = 0x0BU,                 /*!< External input channel 11 */
#if (FEATURE_ADC_MAX_EXT_CHAN_ID > 11u)
    ADC_IP_INPUTCHAN_EXT12     = 0x0CU,                 /*!< External input channel 12 */
    ADC_IP_INPUTCHAN_EXT13     = 0x0DU,                 /*!< External input channel 13 */
    ADC_IP_INPUTCHAN_EXT14     = 0x0EU,                 /*!< External input channel 14 */
#if (FEATURE_ADC_MAX_EXT_CHAN_ID > 14u)
    ADC_IP_INPUTCHAN_EXT15     = 0x0FU,                 /*!< External input channel 15 */
#if (FEATURE_ADC_MAX_EXT_CHAN_ID > 15u)
    ADC_IP_INPUTCHAN_EXT16     = 0x20U,                 /*!< External input channel 16 */
    ADC_IP_INPUTCHAN_EXT17     = 0x21U,                 /*!< External input channel 17 */
    ADC_IP_INPUTCHAN_EXT18     = 0x22U,                 /*!< External input channel 18 */
    ADC_IP_INPUTCHAN_EXT19     = 0x23U,                 /*!< External input channel 19 */
    ADC_IP_INPUTCHAN_EXT20     = 0x24U,                 /*!< External input channel 20 */
    ADC_IP_INPUTCHAN_EXT21     = 0x25U,                 /*!< External input channel 21 */
    ADC_IP_INPUTCHAN_EXT22     = 0x26U,                 /*!< External input channel 22 */
    ADC_IP_INPUTCHAN_EXT23     = 0x27U,                 /*!< External input channel 23 */
#if (FEATURE_ADC_MAX_EXT_CHAN_ID > 23u)
    ADC_IP_INPUTCHAN_EXT24     = 0x28U,                 /*!< External input channel 24 */
    ADC_IP_INPUTCHAN_EXT25     = 0x29U,                 /*!< External input channel 25 */
    ADC_IP_INPUTCHAN_EXT26     = 0x2AU,                 /*!< External input channel 26 */
    ADC_IP_INPUTCHAN_EXT27     = 0x2BU,                 /*!< External input channel 27 */
    ADC_IP_INPUTCHAN_EXT28     = 0x2CU,                 /*!< External input channel 28 */
    ADC_IP_INPUTCHAN_EXT29     = 0x2DU,                 /*!< External input channel 29 */
    ADC_IP_INPUTCHAN_EXT30     = 0x2EU,                 /*!< External input channel 30 */
    ADC_IP_INPUTCHAN_EXT31     = 0x2FU,                 /*!< External input channel 31 */
#endif /* (FEATURE_ADC_MAX_EXT_CHAN_ID > 23u) */
#endif /* (FEATURE_ADC_MAX_EXT_CHAN_ID > 15u) */
#endif /* (FEATURE_ADC_MAX_EXT_CHAN_ID > 14u) */
#endif /* (FEATURE_ADC_MAX_EXT_CHAN_ID > 11u) */

    ADC_IP_INPUTCHAN_DISABLED  = ADC_SC1_ADCH_MASK,     /*!< Channel disabled          */

    ADC_IP_INPUTCHAN_INT0      = 0x15,                  /*!< Internal input channel 0  */
    ADC_IP_INPUTCHAN_INT1      = 0x16,                  /*!< Internal input channel 1  */
    ADC_IP_INPUTCHAN_INT2      = 0x17,                  /*!< Internal input channel 2  */
    ADC_IP_INPUTCHAN_INT3      = 0x1C,                  /*!< Internal input channel 3  */

    ADC_IP_INPUTCHAN_TEMP      = 0x1A,                  /*!< Temperature Sensor            */
    ADC_IP_INPUTCHAN_BANDGAP   = 0x1B,                  /*!< Band Gap                      */
    ADC_IP_INPUTCHAN_VREFH     = 0x1D,                  /*!< Voltage Reference Select High */
    ADC_IP_INPUTCHAN_VREFL     = 0x1E,                  /*!< Voltage Reference Select Low  */

#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
                                                        /*!< The following channels are measured via internal input channel 0 */
    ADC_IP_INPUTCHAN_SUPPLY_VDD            = 0xF00U,    /*!< Monitor internal supply 5 V input VDD supply.              */
    ADC_IP_INPUTCHAN_SUPPLY_VDDA           = 0xF01U,    /*!< Monitor internal supply 5 V input analog supply.           */
    ADC_IP_INPUTCHAN_SUPPLY_VREFH          = 0xF02U,    /*!< Monitor internal supply ADC reference supply.              */
    ADC_IP_INPUTCHAN_SUPPLY_VDD_3V         = 0xF03U,    /*!< Monitor internal supply 3.3 V oscillator regulator output. */
    ADC_IP_INPUTCHAN_SUPPLY_VDD_FLASH_3V   = 0xF04U,    /*!< Monitor internal supply 3.3 V flash regulator output.      */
    ADC_IP_INPUTCHAN_SUPPLY_VDD_LV         = 0xF05U     /*!< Monitor internal supply 1.2 V core regulator output.       */
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */
} Adc_Ip_InputChannelType;

#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
/*!
 * @brief Defines the channel notification header
 *
 * This header is used for channel notification callbacks.
 * Note: the return paramter is the index of the control channel(numeric index
 * of SC1x e.g. SC1A has index 0), not the input channel.
 *
 * Implements : Adc_Ip_ChanNotificationType_Class
 */
typedef void Adc_Ip_ChanNotificationType(const uint8 ControlChanIdx);
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */

/*!
 * @brief Defines the channel configuration
 *
 * This structure is used to configure channels
 *
 * Implements : Adc_Ip_ChanConfigType_Class
 */
typedef struct
{
    uint8 ChnIdx;                           /*!< Control channel 0 */
    Adc_Ip_InputChannelType Channel;        /*!< Selection of input channel for measurement */
#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
    boolean InterruptEnable;                /*!< Enable interrupts for this channel */
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
} Adc_Ip_ChanConfigType;

/*!
 * @brief Defines the ADC clock configuration
 *
 * This structure is used to configure ADC clock
 *
 * Implements : Adc_Ip_ClockConfigType_Class
 */
typedef struct
{
    Adc_Ip_ClockSelType ClockDivide;    /*!< Selected clock */
    Adc_Ip_ClkSourceType InputClock;    /*!< Input clock source */
    uint8 SampleTime;                   /*!< Sample time in AD Clocks */
    boolean AvgEn;                      /*!< Enable averaging functionality */
    Adc_Ip_AvgSelectType AvgSel;        /*!< Selection for number of samples used for averaging */
} Adc_Ip_ClockConfigType;

/*!
 * @brief Defines the module configuration
 *
 * This structure is used to configure the ADC module
 *
 * Implements : Adc_Ip_ConfigType_Class
 */
typedef struct
{
    Adc_Ip_ClockSelType ClockDivide;            /*!< Divider of the input clock for the ADC */
    Adc_Ip_ClockSelType CalibrationClockDivide; /*!< Divider of the input clock for Calibration */
    Adc_Ip_ClkSourceType InputClock;            /*!< Input clock source */
    uint8 SampleTime;                           /*!< Sample time in AD Clocks */
    boolean AvgEn;                              /*!< Enable averaging functionality */
    Adc_Ip_AvgSelectType AvgSel;                /*!< Selection for number of samples used for averaging */
    Adc_Ip_ResolutionType Resolution;           /*!< ADC resolution (8,10,12 bit) */
    Adc_Ip_TrigType TriggerMode;                /*!< ADC trigger mode (software, hardware) - affects only the first control channel */
#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
    Adc_Ip_PretriggerSelType PretriggerSel;     /*!< Pretrigger source selected for Trigger Latching and Arbitration Unit - affects only the first 4 control channels */
    Adc_Ip_TrigSelType TriggerSel;              /*!< Trigger source selected for Trigger Latching and Arbitration Unit */
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */
    boolean DmaEnable;                          /*!< Enable DMA for the ADC */
    Adc_Ip_VoltageReferenceType VoltageRef;     /*!< Voltage reference used */
    boolean ContinuousConvEnable;               /*!< Enable Continuous conversions */
#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
    boolean SupplyMonitoringEnable;             /*!< Only available for ADC 0. Enable internal supply monitoring - enables measurement of ADC_IP_INPUTCHAN_SUPPLY_ sources. */
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */

    boolean CompareEnable;                      /*!< Enable the compare feature */
    boolean CompareGreaterThanEnable;           /*!< Enable Greater-Than functionality */
    boolean CompareRangeFuncEnable;             /*!< Enable Range functionality */
    uint16 CompVal1;                            /*!< First Compare Value */
    uint16 CompVal2;                            /*!< Second Compare Value */

    uint16 UsrGain;                             /*!< User-configurable gain */
    uint16 UsrOffset;                           /*!< User-configurable Offset (2's complement, subtracted from result) */

    uint8 NumChannels;                          /*!< User-configurable Number of Channels */
    const Adc_Ip_ChanConfigType * ChannelConfigs;                   /*!< User-configurable channel configuration */

#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
    Adc_Ip_ChanNotificationType * ConversionCompleteNotification;   /*!< Individual channel notification */
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
} Adc_Ip_ConfigType;

/*!
 * @brief Structure used to store runtime info
 *
 * This structure is used to store ADC runtime info
 *
 * Implements : Adc_Ip_StateStructType_Class
 */
typedef struct
{
    boolean Init;                               /*!< Check if the driver was initialized. */
    Adc_Ip_ClockSelType CalibrationClockDivide; /*!< Divider of the input clock for Calibration */
#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
    Adc_Ip_PretriggerSelType PretriggerSel;     /*!< Pretrigger source selected for Trigger Latching and Arbitration Unit - affects only the first 4 control channels */
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */

    /* Individual channel notification */
#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
    Adc_Ip_ChanNotificationType * ConversionCompleteNotification;   /*!< Individual channel notification */
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */

    /* Current hardware channel config */
    Adc_Ip_InputChannelType ChannelConfig[ADC_MAX_CHAN_COUNT];      /*!< Current hardware channel config */
} Adc_Ip_StateStructType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IP_TYPES_H */
