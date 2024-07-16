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

#ifndef PDB_ADC_IP_H
#define PDB_ADC_IP_H

/**
*   @file
*
*   @addtogroup pdb_adc_ip Pdb Adc IPL
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
#include "Pdb_Adc_Ip_Types.h"
#include "Pdb_Adc_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PDB_ADC_IP_VENDOR_ID                      43
#define PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION       4
#define PDB_ADC_IP_AR_RELEASE_MINOR_VERSION       7
#define PDB_ADC_IP_AR_RELEASE_REVISION_VERSION    0
#define PDB_ADC_IP_SW_MAJOR_VERSION               2
#define PDB_ADC_IP_SW_MINOR_VERSION               0
#define PDB_ADC_IP_SW_PATCH_VERSION               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pdb_Adc_Ip.h file and Pdb_Adc_Ip_Types.h file are of the same vendor */
#if (PDB_ADC_IP_VENDOR_ID != PDB_ADC_IP_VENDOR_ID_TYPES)
    #error "Pdb_Adc_Ip.h and Pdb_Adc_Ip_Types.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip.h file and Pdb_Adc_Ip_Types.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip.h and Pdb_Adc_Ip_Types.h are different"
#endif

/* Check if Pdb_Adc_Ip.h file and Pdb_Adc_Ip_Types.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION != PDB_ADC_IP_SW_MAJOR_VERSION_TYPES) || \
     (PDB_ADC_IP_SW_MINOR_VERSION != PDB_ADC_IP_SW_MINOR_VERSION_TYPES) || \
     (PDB_ADC_IP_SW_PATCH_VERSION != PDB_ADC_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip.h and Pdb_Adc_Ip_Types.h are different"
#endif

/* Check if Pdb_Adc_Ip.h file and Pdb_Adc_Ip_Cfg.h file are of the same vendor */
#if (PDB_ADC_IP_VENDOR_ID != PDB_ADC_IP_VENDOR_ID_CFG)
    #error "Pdb_Adc_Ip.h and Pdb_Adc_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip.h file and Pdb_Adc_Ip_Cfg.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip.h and Pdb_Adc_Ip_Cfg.h are different"
#endif

/* Check if Pdb_Adc_Ip.h file and Pdb_Adc_Ip_Cfg.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION != PDB_ADC_IP_SW_MAJOR_VERSION_CFG) || \
     (PDB_ADC_IP_SW_MINOR_VERSION != PDB_ADC_IP_SW_MINOR_VERSION_CFG) || \
     (PDB_ADC_IP_SW_PATCH_VERSION != PDB_ADC_IP_SW_PATCH_VERSION_CFG) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip.h and Pdb_Adc_Ip_Cfg.h are different"
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
 * @brief Initialize PDB module
 *
 * This function initializes the PDB counter, input triggers and general pretrigger settings.
 * It resets PDB registers and enables the PDB clock. Therefore, it should be
 * called before any other operation. After it is initialized, the PDB can
 * act as a triggered timer, which enables other features in PDB module.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] Config - configuration struct pointer
 * @return void
 */
void Pdb_Adc_Ip_Init(const uint32 Instance,
                     const Pdb_Adc_Ip_ConfigType * const Config);

/*!
 * @brief Deinitialize PDB module
 *
 * This function resets the PDB internal registers to default values.
 *
 * When the PDB module is not used. Calling this function would shut down the
 * PDB module and reduce the power consumption.
 *
 * Note: instance back to back configuration is common between PDB instances 0 and 1
 * (configures the same register even if configured for either PDB instance)
 * This function disables it, so affects all other instances.
 *
 * @param[in] Instance - PDB instance number
 * @return void
 */
void Pdb_Adc_Ip_DeInit(const uint32 Instance);

/*!
 * @brief Enable the PDB module
 *
 * This function enables the PDB module, counter is on.
 *
 * @param[in] Instance - PDB instance number
 * @return void
 */
void Pdb_Adc_Ip_Enable(const uint32 Instance);

/*!
 * @brief Disable the PDB module
 *
 * This function disables the PDB module, counter is off.
 *
 * @param[in] Instance - PDB instance number
 */
void Pdb_Adc_Ip_Disable(const uint32 Instance);

/*!
 * @brief Set PDB trigger source
 *
 * This function sets the PDB trigger source.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] TriggerSource - trigger source
 * @return void
 */
void Pdb_Adc_Ip_SetTriggerInput(const uint32 Instance,
                                const Pdb_Adc_Ip_TriggerSrcType TriggerSource);

/*!
 * @brief Set PDB mode
 *
 * This function sets the PDB mode to continuous or one shot.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] State - mode to set: continuous(true) or one shot(FALSE)
 * @return void
 */
void Pdb_Adc_Ip_SetContinuousMode(const uint32 Instance,
                                  const boolean State);

/*!
 * @brief Trigger the PDB with a software trigger
 *
 * This function triggers the PDB with a software trigger.
 * When the PDB is set to use the software trigger as input, calling this function
 * triggers the PDB.
 *
 * @param[in] Instance - PDB instance number
 * @return void
 */
void Pdb_Adc_Ip_SwTrigger(const uint32 Instance);

/*!
 * @brief Get the current value of the PDB counter
 *
 * This function gets the current counter value.
 *
 * @param[in] Instance - PDB instance number
 * @return Current PDB counter value.
 */
uint32 Pdb_Adc_Ip_GetTimerValue(const uint32 Instance);

/*!
 * @brief Load buffered register values.
 *
 * This function sets the LDOK bit.
 * Writing one to this bit updates the internal registers MOD, IDLY, CHnDLYm and
 * POyDLY with the values written to their buffers. The MOD, IDLY,
 * CHnDLYm and POyDLY take effect according to the load mode settings.
 *
 * After one is written to the LDOK bit, the values in the buffers of above mentioned
 * registers are not effective and cannot be written until the values in the
 * buffers are loaded into their internal registers. The moment when this happens
 * depends on the value of the LDMOD register. Only when this register is in it's
 * default state(0), the load operation will happen immediately. Please check the
 * reference manual for more information.
 * The LDOK can be written only when the the PDB is enabled or as alone with it. It is
 * automatically cleared either when the values in the buffers are loaded into the
 * internal registers or when the PDB is disabled.
 *
 * @param[in] Instance - PDB instance number
 * @return void
 */
void Pdb_Adc_Ip_LoadRegValues(const uint32 Instance);

/*!
 * @brief Set the period of the counter
 *
 * This function sets the PDB Modulus value.
 * Note: This function writes in an internal buffer. Depending on the
 * value of the LDMOD register, it might be necessary to call
 * Pdb_Adc_Ip_LoadRegValues in order to update the value of the register.
 * The value of the register can be changed only when the PDB module is enabled.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] ModVal - modulus value
 * @return void
 */
void Pdb_Adc_Ip_SetModulus(const uint32 Instance,
                           const uint16 ModVal);

/*!
 * @brief Configure all pretriggers on the selected channel
 *
 * This function configures the back to back modes, delay enable and output
 * enable settings for all pretriggers on the selected channel.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] ChanIdx - PDB channel
 * @param[in] Config - pretriggers config
 * @return void
 */
void Pdb_Adc_Ip_ConfigAdcPretriggers(const uint32 Instance,
                                     const uint8 ChanIdx,
                                     const Pdb_Adc_Ip_PretriggersConfigType * const Config);

/*!
 * @brief Get ADC pretrigger channel flags from the PDB module
 *
 * This function gets all ADC pretrigger flags from the selected channel.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] ChanIdx - PDB channel
 * @return bitmask of channel flags selected by pretriggMask
 */
uint32 Pdb_Adc_Ip_GetAdcPretriggerFlags(const uint32 Instance,
                                        const uint8 ChanIdx);

/*!
 * @brief Clear ADC pretrigger channel flags from the PDB module
 *
 * This function clears the ADC pretrigger channel flags selected by pretriggMask
 * from channel channel.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] ChanIdx - PDB channel
 * @param[in] PretriggMask - ADC pretriggers mask
 */
void Pdb_Adc_Ip_ClearAdcPretriggerFlags(const uint32 Instance,
                                        const uint8 ChanIdx,
                                        const uint16 PretriggMask);

/*!
 * @brief Set back to back mode for the selected pretrigger
 *
 * This function sets back to back mode for the selected pretrigger on
 * the given channel.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] ChanIdx - PDB channel
 * @param[in] PretriggIdx - ADC pretrigger index
 * @param[in] Value - enable(true) or disable(FALSE)
 */
void Pdb_Adc_Ip_SetAdcPretriggerBackToBack(const uint32 Instance,
                                           const uint8 ChanIdx,
                                           const uint8 PretriggIdx,
                                           const boolean Value);

/*!
 * @brief Enable or disable the selected pretrigger
 *
 * This function enables or disables the selected pretrigger on the given channel.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] ChanIdx - PDB channel
 * @param[in] PretriggIdx - ADC pretrigger mask
 * @param[in] Value - enable(true) or disable(FALSE)
 */
void Pdb_Adc_Ip_SetAdcPretriggerEnable(const uint32 Instance,
                                       const uint8 ChanIdx,
                                       const uint8 PretriggIdx,
                                       const boolean Value);

/*!
 * @brief Set the delay enable for the selected pretrigger
 *
 * This function sets the delay enable value for the selected pretrigger on
 * the given channel.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] ChanIdx - PDB channel
 * @param[in] PretriggIdx - ADC pretrigger index
 * @param[in] Value - enable(true) or disable(FALSE)
 */
void Pdb_Adc_Ip_SetAdcPretriggerDelayEnable(const uint32 Instance,
                                            const uint8 ChanIdx,
                                            const uint8 PretriggIdx,
                                            const boolean Value);

/*!
 * @brief Set the pretrigger delay value.
 *
 * This function sets the pretrigger delay value
 * Note: This function writes in an internal buffer. Depending on the
 * value of the LDMOD register, it might be necessary to call
 * Pdb_Adc_Ip_LoadRegValues in order to update the value of the register.
 * The value of the register can be changed only when the PDB module is enabled.
 *
 * @param[in] Instance - PDB instance number
 * @param[in] ChanIdx - PDB channel
 * @param[in] PretriggIdx - ADC pretrigger index
 * @param[in] DelayValue - pretrigger delay value
 */
void Pdb_Adc_Ip_SetAdcPretriggerDelayValue(const uint32 Instance,
                                           const uint8 ChanIdx,
                                           const uint8 PretriggIdx,
                                           const uint16 DelayValue);

/*!
 * @brief Disable and clear PDB module
 *
 * This function disables PDB module and clears all channels
 * configuration and status registers.
 * Note: This function does not deinitialize the module.
 *
 * @param[in] Instance - PDB instance number
 */
void Pdb_Adc_Ip_DisableAndClearPdb(const uint32 Instance);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if defined (__cplusplus)
}
#endif

/** @} */

#endif /* PDB_ADC_IP_H */
