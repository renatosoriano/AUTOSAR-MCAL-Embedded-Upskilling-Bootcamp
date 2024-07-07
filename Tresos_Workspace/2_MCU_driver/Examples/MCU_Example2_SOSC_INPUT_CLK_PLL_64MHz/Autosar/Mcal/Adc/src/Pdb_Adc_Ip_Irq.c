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

/**
*   @file
*
*   @addtogroup pdb_adc_ip Pdb Adc IPL
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
#include "OsIf.h"
#include "Mcal.h"
#include "Pdb_Adc_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PDB_ADC_IP_VENDOR_ID_IRQ_C                      43
#define PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       7
#define PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define PDB_ADC_IP_SW_MAJOR_VERSION_IRQ_C               2
#define PDB_ADC_IP_SW_MINOR_VERSION_IRQ_C               0
#define PDB_ADC_IP_SW_PATCH_VERSION_IRQ_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Pdb_Adc_Ip_Irq.c file and OsIf.h file are of the same Autosar version */
    #if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Pdb_Adc_Ip_Irq.c and OsIf.h are different"
    #endif

    /* Check if Pdb_Adc_Ip_Irq.c file and Mcal.h file are of the same Autosar version */
    #if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Pdb_Adc_Ip_Irq.c and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Pdb_Adc_Ip_Irq.c file and Pdb_Adc_Ip_Irq.h file are of the same vendor */
#if (PDB_ADC_IP_VENDOR_ID_IRQ_C != PDB_ADC_IP_VENDOR_ID_IRQ)
    #error "Pdb_Adc_Ip_Irq.c and Pdb_Adc_Ip_Irq.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip_Irq.c file and Pdb_Adc_Ip_Irq.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ_C != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_IRQ_C != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip_Irq.c and Pdb_Adc_Ip_Irq.h are different"
#endif

/* Check if Pdb_Adc_Ip_Irq.c file and Pdb_Adc_Ip_Irq.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION_IRQ_C != PDB_ADC_IP_SW_MAJOR_VERSION_IRQ) || \
     (PDB_ADC_IP_SW_MINOR_VERSION_IRQ_C != PDB_ADC_IP_SW_MINOR_VERSION_IRQ) || \
     (PDB_ADC_IP_SW_PATCH_VERSION_IRQ_C != PDB_ADC_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip_Irq.c and Pdb_Adc_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

ISR(Pdb_0_Isr)
{
    /* Call IRQ handler with the correct instance */
    Pdb_Adc_Ip_IRQHandler(0UL);

    EXIT_INTERRUPT();
}

#if (PDB_INSTANCE_COUNT >= 1)
ISR(Pdb_1_Isr)
{
    /* Call IRQ handler with the correct instance */
    Pdb_Adc_Ip_IRQHandler(1UL);

    EXIT_INTERRUPT();
}
#endif /* (PDB_INSTANCE_COUNT >= 1) */

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
