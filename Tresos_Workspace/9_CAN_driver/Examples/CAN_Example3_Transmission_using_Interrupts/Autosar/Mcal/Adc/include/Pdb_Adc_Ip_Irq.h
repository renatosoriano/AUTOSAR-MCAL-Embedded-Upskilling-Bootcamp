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

#ifndef PDB_ADC_IP_IRQ_H
#define PDB_ADC_IP_IRQ_H

/**
*   @file
*
*   @addtogroup pdb_adc_ip Pdb Adc IPL
*   @{
*/
#if defined (__cplusplus)
extern "C" {
#endif

#include "StandardTypes.h"
#include "Pdb_Adc_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PDB_ADC_IP_VENDOR_ID_IRQ                      43
#define PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ       4
#define PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ       7
#define PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_IRQ    0
#define PDB_ADC_IP_SW_MAJOR_VERSION_IRQ               2
#define PDB_ADC_IP_SW_MINOR_VERSION_IRQ               0
#define PDB_ADC_IP_SW_PATCH_VERSION_IRQ               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Pdb_Adc_Ip_Irq.h file and StandardTypes.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ != STD_AR_RELEASE_MAJOR_VERSION) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip_Irq.h and StandardTypes.h are different"
#endif
#endif

/* Check if Pdb_Adc_Ip_Irq.h file and Pdb_Adc_Ip_CfgDefines.h file are of the same vendor */
#if (PDB_ADC_IP_VENDOR_ID_IRQ != PDB_ADC_IP_VENDOR_ID_CFGDEFINES)
    #error "Pdb_Adc_Ip_Irq.h and Pdb_Adc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip_Irq.h file and Pdb_Adc_Ip_CfgDefines.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_IRQ != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip_Irq.h and Pdb_Adc_Ip_CfgDefines.h are different"
#endif

/* Check if Pdb_Adc_Ip_Irq.h file and Pdb_Adc_Ip_CfgDefines.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION_IRQ != PDB_ADC_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_SW_MINOR_VERSION_IRQ != PDB_ADC_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_SW_PATCH_VERSION_IRQ != PDB_ADC_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip_Irq.h and Pdb_Adc_Ip_CfgDefines.h are different"
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
ISR(Pdb_0_Isr);
#if (PDB_INSTANCE_COUNT >= 1)
ISR(Pdb_1_Isr);
#endif /* (PDB_INSTANCE_COUNT >= 1) */

void Pdb_Adc_Ip_IRQHandler(const uint32 Instance);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if defined (__cplusplus)
}
#endif

/** @} */

#endif /* PDB_ADC_IP_IRQ_H */
