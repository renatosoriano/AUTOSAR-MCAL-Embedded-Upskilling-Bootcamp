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
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef ADC_IPW_CFGDEFINES_H
#define ADC_IPW_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup adc_ipw_config Adc Ipw Configuration
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_IPW_VENDOR_ID_CFGDEFINES                     43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_CFGDEFINES      4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_CFGDEFINES      7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_CFGDEFINES   0
#define ADC_IPW_SW_MAJOR_VERSION_CFGDEFINES              2
#define ADC_IPW_SW_MINOR_VERSION_CFGDEFINES              0
#define ADC_IPW_SW_PATCH_VERSION_CFGDEFINES              0

/*==================================================================================================
*                              DEFINES AND MACROS
==================================================================================================*/
#define ADC_IPW_INVALID_LOGICAL_UNIT_ID     (0xFFU)

#define ADC_IPW_INVALID_DMA_CHANNEL_ID      (0xFFU)

#define ADC_IPW_INVALID_TRANSFER_TYPE       (0xFFU)

/**
 * @brief          Max number of ADC Hw units.
 */
#define ADC_IPW_MAX_HW_UNITS                    (2U)

/**
 * @brief   Define the number of maximum hardware unit configured
 */
#define ADC_IPW_MAX_HW_UNITS_CFG                (2U)


/**
* @brief           PDB available/unavailable (STD_ON/STD_OFF).
*/
#define ADC_IPW_PDB_AVAILABLE                   (STD_ON)

/**
* @brief           BCTU available/unavailable (STD_ON/STD_OFF).
*/
#define ADC_IPW_BCTU_AVAILABLE                  (STD_OFF)

/**
* @brief           CTU available/unavailable (STD_ON/STD_OFF).
*/
#define ADC_IPW_CTU_AVAILABLE                   (STD_OFF)

/**
* @brief           ADC hardware is supported CALSTAT register
*/
#define ADC_IPW_CALSTAT_AVAILABLE               (STD_OFF)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IPW_CFGDEFINES_H */
