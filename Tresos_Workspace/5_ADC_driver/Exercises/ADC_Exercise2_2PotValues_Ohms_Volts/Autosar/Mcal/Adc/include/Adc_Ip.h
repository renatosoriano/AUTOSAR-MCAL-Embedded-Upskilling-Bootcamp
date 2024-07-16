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

#ifndef ADC_IP_H
#define ADC_IP_H

/**
*   @file
*
*   @addtogroup adc_ip Adc IPL
*   @{
*/

#if defined (__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc_Ip_Types.h"
#include "Adc_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION       7
#define ADC_IP_AR_RELEASE_REVISION_VERSION    0
#define ADC_IP_SW_MAJOR_VERSION               2
#define ADC_IP_SW_MINOR_VERSION               0
#define ADC_IP_SW_PATCH_VERSION               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Ip.h file and Adc_Ip_Types.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID != ADC_IP_VENDOR_ID_TYPES)
    #error "Adc_Ip.h and Adc_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Ip.h file and Adc_Ip_Types.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION != ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION != ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION != ADC_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ip.h and Adc_Ip_Types.h are different"
#endif

/* Check if Adc_Ip.h file and Adc_Ip_Types.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION != ADC_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IP_SW_MINOR_VERSION != ADC_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_IP_SW_PATCH_VERSION != ADC_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ip.h and Adc_Ip_Types.h are different"
#endif

/* Check if Adc_Ip.h file and Adc_Ip_Cfg.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID != ADC_IP_VENDOR_ID_CFG)
    #error "Adc_Ip.h and Adc_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Adc_Ip.h file and Adc_Ip_Cfg.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION != ADC_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION != ADC_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION != ADC_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ip.h and Adc_Ip_Cfg.h are different"
#endif

/* Check if Adc_Ip.h file and Adc_Ip_Cfg.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION != ADC_IP_SW_MAJOR_VERSION_CFG) || \
     (ADC_IP_SW_MINOR_VERSION != ADC_IP_SW_MINOR_VERSION_CFG) || \
     (ADC_IP_SW_PATCH_VERSION != ADC_IP_SW_PATCH_VERSION_CFG) \
    )
  #error "Software Version Numbers of Adc_Ip.h and Adc_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                     DEFINITIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/*!
 * @brief Initialize ADC module
 *
 * This function initializes the ADC module by configuring all
 * available features.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] config - configuration struct pointer
 * @return void
 */
void Adc_Ip_Init(const uint32 Instance,
                 const Adc_Ip_ConfigType * const Config);

/*!
 * @brief Deinitialize ADC module
 *
 * This function resets the ADC internal registers to default values.
 *
 * @param[in] Instance - ADC instance number
 * @return void
 */
void Adc_Ip_DeInit(const uint32 Instance);

/*!
 * @brief Configure averaging
 *
 * This function enables averaging and selects the number of conversions to average.
 * The mask parameter should be set using the Adc_Ip_AvgSelectType enum elements
 * that have the pattern ADC_IP_AVG_... e.g. ADC_IP_AVG_4_CONV.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] AvgEn - enable or disable averaging
 * @param[in] AvgSel - selects number of conversions to average
 * @return void
 */
void Adc_Ip_SetAveraging(const uint32 Instance,
                         const boolean AvgEn,
                         const Adc_Ip_AvgSelectType AvgSel);

/*!
 * @brief Configure sample time
 *
 * This function sets the sample time for selected ADC instance.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] SampleTime - sample time
 * @return void
 */
void Adc_Ip_SetSampleTime(const uint32 Instance,
                          const uint8 SampleTime);

/*!
 * @brief Enable DMA
 *
 * This function enables DMA.
 *
 * @param[in] Instance - ADC instance number
 * @return void
 */
void Adc_Ip_EnableDma(const uint32 Instance);

/*!
 * @brief Disable DMA
 *
 * This function disables DMA.
 *
 * @param[in] Instance - ADC instance number
 * @return void
 */
void Adc_Ip_DisableDma(const uint32 Instance);

/*!
 * @brief Switch between hardware and software trigger
 *
 * This function enables either hardware or software trigger.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] TriggerMode - selected trigger mode(sw/hw)
 * @return void
 */
void Adc_Ip_SetTriggerMode(const uint32 Instance,
                           const Adc_Ip_TrigType TriggerMode);

/*!
 * @brief Switch between continuous and one shot conversion mode
 *
 * This function switches between ADC continuous conversion mode and one shot mode.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] ContinuousModeEnable - mode to set: continuous(TRUE) or one shot(FALSE)
 * @return void
 */
void Adc_Ip_SetContinuousMode(const uint32 Instance,
                              const boolean ContinuousModeEnable);

/*!
 * @brief Set ADC module resolution
 *
 * This function sets ADC module resolution.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] Resolution - resolution value
 * @return void
 */
void Adc_Ip_SetResolution(const uint32 Instance,
                          const Adc_Ip_ResolutionType Resolution);

/*!
 * @brief Set the ADC clock values
 *
 * This function initializes the ADC clock configuration.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] Config - the clock configuration
 * @return void
 */
void Adc_Ip_SetClockMode(const uint32 Instance,
                         const Adc_Ip_ClockConfigType * const Config);

/*!
 * @brief Configure the selected control channel with the given
 * configuration structure
 *
 * When Software Trigger mode is enabled, configuring control channel index 0,
 * implicitly triggers a new conversion on the selected ADC input channel.
 * Therefore, Adc_Ip_ConfigChannel can be used for sw-triggering conversions.
 *
 * Configuring any control channel while it is actively controlling a conversion
 * (sw or hw triggered) will implicitly abort the on-going conversion.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] ChanConfig - configuration structure
 * @return void
 */
void Adc_Ip_ConfigChannel(const uint32 Instance,
                          const Adc_Ip_ChanConfigType * const ChanConfig);

/*!
 * @brief Disable selected channel
 *
 * This function sets the input channel of the selected control channel to
 * ADC_IP_INPUTCHAN_DISABLED. If WithTimeout is TRUE then the function will
 * also wait for the register to be updated.
 * Note: the control channel index is the numeric index of SC1x
 * (e.g. SC1A has index 0), not the input channel.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] ControlChanIdx - control channel index
 * @param[in] WithTimeout - enables loop that checks if the register was updated
 * @return Adc_Ip_StatusType
 */
Adc_Ip_StatusType Adc_Ip_SetDisabledChannel(const uint32 Instance,
                                            const uint8 ControlChanIdx,
                                            const boolean WithTimeout);

/*!
 * @brief Start a software triggered conversion
 *
 * This function starts a software conversion on the selected input channel by
 * writing the values given to the SC1A register.
 * Note: hardware configuration on the control channel with index 0 will be
 * overwritten.
 * Note: This will not work if hardware triggered mode is selected.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] InputChannel - channel index
 * @param[in] InterruptEnable - enables end of conversion interrupt. No effect if ADC_IP_AIEN_INTERRUPT_ENABLE = STD_OFF
 * @return void
 */
void Adc_Ip_StartConversion(const uint32 Instance,
                            Adc_Ip_InputChannelType InputChannel,
                            const boolean InterruptEnable);

/*!
 * @brief Read and return conversion active flag status.
 *
 * @param[in] Instance - ADC instance number
 * @return conversion active flag status
 */
boolean Adc_Ip_GetConvActiveFlag(const uint32 Instance);

#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
/*!
 * @brief Check if selected channel has interrupt set
 *
 * This function checks and returns if the selected control channel has the
 * interrupt flag set.
 * Note: the control channel index is the numeric index of SC1x
 * (e.g. SC1A has index 0), not the input channel.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] ControlChanIdx - control channel index
 * @return TRUE if channel has interrupt set or FALSE otherwise
 */
boolean Adc_Ip_GetChanInterrupt(const uint32 Instance,
                                const uint8 ControlChanIdx);
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */

/*!
 * @brief Get the value of conversion complete flag of a channel
 *
 * This function returns the value of the conversion complete(COCO) flag of a
 * given channel.
 * Note: the control channel index is the numeric index of SC1x
 * (e.g. SC1A has index 0), not the input channel.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] ControlChanIdx - control channel index
 * @return value of conversion complete flag
 */
boolean Adc_Ip_GetConvCompleteFlag(const uint32 Instance,
                                   const uint8 ControlChanIdx);

/*!
 * @brief Get the last result for the selected control channel
 *
 * This function retrieves the last conversion result for the selected control
 * channel. This function does no validity check on the result. In order to
 * check if the result is valid, the user must call Adc_Ip_GetConvCompleteFlag
 * function before this one.
 * Note: the control channel index is the numeric index of SC1x
 * (e.g. SC1A has index 0), not the input channel.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] ControlChanIdx - control channel index
 * @return conversion result
 */
uint16 Adc_Ip_GetConvData(const uint32 Instance,
                          const uint8 ControlChanIdx);

/*!
 * @brief Perform calibration of the ADC module
 *
 * This function performs a calibration of the ADC module. The input clock frequency
 * for calibration must be less than or equal to half of the maximum specified
 * frequency (50Mhz) and greater than minimum specified frequency (20Mhz).
 * Please refer to Datasheet for more details
 *
 * @param[in] Instance - ADC instance number
 * @return the calibration result
 *  - ADC_IP_STATUS_SUCCESS: calibration successful
 *  - ADC_IP_STATUS_TIMEOUT: calibration step timed out
 */
Adc_Ip_StatusType Adc_Ip_DoCalibration(const uint32 Instance);

/*!
 * @brief Clear latched triggers under processing
 *
 * This function clears all trigger latched flags of the ADC instance.
 * This function must be called after the hardware trigger source for the ADC has been deactivated.
 *
 * @param[in] Instance - ADC instance number
 * @return clearing status
 *  - ADC_IP_STATUS_SUCCESS: operation successful
 *  - ADC_IP_STATUS_TIMEOUT: operation timed out
 */
Adc_Ip_StatusType Adc_Ip_ClearLatchedTriggers(const uint32 Instance);

#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
/*!
 * @brief Enable channel notification
 *
 * This function enables the notification for the selected channel.
 * Note: the control channel index is the numeric index of SC1x
 * (e.g. SC1A has index 0), not the input channel.
 * Note: It's required to read result data in user notification in order to clear the COCO flags and avoid ISR getting invoked repeatedly
 *
 * @param[in] Instance - ADC instance number
 * @param[in] ControlChanIdx - control channel index
 * @return void
 */
void Adc_Ip_EnableChannelNotification(const uint32 Instance,
                                      const uint8 ControlChanIdx);

/*!
 * @brief Disable channel notification
 *
 * This function disables the notification for the selected channel.
 * Note: the control channel index is the numeric index of SC1x
 * (e.g. SC1A has index 0), not the input channel.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] ControlChanIdx - control channel index
 * @return void
 */
void Adc_Ip_DisableChannelNotification(const uint32 Instance,
                                       const uint8 ControlChanIdx);
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */

/*!
 * @brief Clear all trigger error flags
 *
 * This function clears all trigger error flags of the ADC instance.
 *
 * @param[in] Instance - ADC instance number
 * @return void
 */
void Adc_Ip_ClearTrigErrReg(const uint32 Instance);

/*!
 * @brief Get all trigger error flags
 *
 * This function returns all trigger error flags of the ADC instance.
 *
 * @param[in] Instance - ADC instance number
 * @return trigger error flags bit-mask
 */
uint32 Adc_Ip_GetTrigErrReg(const uint32 Instance);

/*!
* @brief Return the address of the specified data register
*
* This function returns the address of the specified data register
*
* @param[in] Instance - ADC instance number
* @param[in] Index - ADC channel of the Hw unit
* @return status:
*  - value of the address of the data for the specified channel
*/
uint32 Adc_Ip_GetDataAddress(const uint32 Instance,
                             const uint8 Index);

/*!
 * @brief Get the last result for the selected control channel
 *
 * This function retrieves the last conversion result for the selected input
 * channel, by looking which control channel was configured with it. If multiple
 * control channels are configured simultaneously with the same requested input
 * channel, the result of the first control channel found will be returned.
 * If no control channel is configured with the given input channel then
 * ADC_IP_STATUS_ERROR will be returned.
 * This function does no validity check on the result. In order to check if
 * the result is valid, the user must call Adc_Ip_GetConvCompleteFlag function
 * before this one.
 *
 * @param[in] Instance - ADC instance number
 * @param[in] Channel - input channel
 * @param[out] Result - pointer to the buffer where the result will be written
 * @return status
 */
Adc_Ip_StatusType Adc_Ip_GetChanData(const uint32 Instance,
                                     const Adc_Ip_InputChannelType Channel,
                                     uint16 * const Result);

#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
/*!
* @brief Set software pretrigger source
*
* This function sets the software pretrigger source for an ADC instance.
* Note: Pretrigger source must be set to software in order to use this.
* Note: Software pretriggering is available only for ADC control channels 0-3(A-D).
*
* @param[in] Instance - ADC instance number
* @param[in] SoftwarePretrigger - selected software pretrigger
*/
void Adc_Ip_SetSoftwarePretrigger(const uint32 Instance,
                                  const Adc_Ip_SoftwarePretriggerType SoftwarePretrigger);
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if defined (__cplusplus)
}
#endif

/** @} */

#endif /* ADC_IP_H */
