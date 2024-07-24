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

#ifndef ADC_IP_HEADERWRAPPER_S32K1XX_H
#define ADC_IP_HEADERWRAPPER_S32K1XX_H

/**
*   @file
*
*   @addtogroup adc_ip Adc IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/* Important Note: This file cannot be used independently.
*  It depends on platform header files to be included before including it */

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID_HEADERWRAPPER_S32K1XX                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_HEADERWRAPPER_S32K1XX       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_HEADERWRAPPER_S32K1XX       7
#define ADC_IP_AR_RELEASE_REVISION_VERSION_HEADERWRAPPER_S32K1XX    0
#define ADC_IP_SW_MAJOR_VERSION_HEADERWRAPPER_S32K1XX               2
#define ADC_IP_SW_MINOR_VERSION_HEADERWRAPPER_S32K1XX               0
#define ADC_IP_SW_PATCH_VERSION_HEADERWRAPPER_S32K1XX               0

/*==================================================================================================
*                                     DEFINITIONS
==================================================================================================*/

#define ADC_MAX_CHAN_COUNT      ADC_SC1_COUNT

/* Register access defines */
#define SC1(Base, RegIndex)     ((Base)->SC1[(RegIndex)])
#define R(Base, RegIndex)       ((Base)->R[(RegIndex)])

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* ADC_IP_HEADERWRAPPER_S32K1XX_H */
