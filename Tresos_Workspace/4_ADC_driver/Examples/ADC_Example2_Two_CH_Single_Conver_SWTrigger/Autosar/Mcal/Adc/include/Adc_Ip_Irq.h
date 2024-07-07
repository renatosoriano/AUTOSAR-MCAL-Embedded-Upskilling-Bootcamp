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

#ifndef ADC_IP_IRQ_H
#define ADC_IP_IRQ_H

/**
*   @file
*
*   @addtogroup adc_ip
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
#include "StandardTypes.h"
#include "Adc_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID_IRQ                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ       7
#define ADC_IP_AR_RELEASE_REVISION_VERSION_IRQ    0
#define ADC_IP_SW_MAJOR_VERSION_IRQ               2
#define ADC_IP_SW_MINOR_VERSION_IRQ               0
#define ADC_IP_SW_PATCH_VERSION_IRQ               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Ip_Irq.h file and StandardTypes.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Ip_Irq.h and StandardTypes.h are different"
#endif
#endif

/* Check if Adc_Ip_Irq.h file and Adc_Ip_CfgDefines.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_IRQ != ADC_IP_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ip_Irq.h and Adc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ip_Irq.h file and Adc_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ != ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ != ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_IRQ != ADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ip_Irq.h and Adc_Ip_CfgDefines.h are different"
#endif

/* Check if Adc_Ip_Irq.h file and Adc_Ip_CfgDefines.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_IRQ != ADC_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IP_SW_MINOR_VERSION_IRQ != ADC_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IP_SW_PATCH_VERSION_IRQ != ADC_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ip_Irq.h and Adc_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/* ISR prototypes required by IAR compiler */
ISR(Adc_0_Isr);
#if (ADC_INSTANCE_COUNT > 1)
ISR(Adc_1_Isr);
#endif /* (ADC_INSTANCE_COUNT > 1) */

void Adc_Ip_IRQHandler(const uint32 Instance);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if defined (__cplusplus)
}
#endif

/** @} */

#endif /* ADC_IP_IRQ_H */
