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

#ifndef PDB_PDB_ADC_IP_HW_ACCESS_H
#define PDB_PDB_ADC_IP_HW_ACCESS_H

/**
*   @file
*
*   @internal
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
#include "StandardTypes.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PDB_ADC_IP_VENDOR_ID_HWACCESS                      43
#define PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS       4
#define PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_HWACCESS       7
#define PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_HWACCESS    0
#define PDB_ADC_IP_SW_MAJOR_VERSION_HWACCESS               2
#define PDB_ADC_IP_SW_MINOR_VERSION_HWACCESS               0
#define PDB_ADC_IP_SW_PATCH_VERSION_HWACCESS               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Pdb_Adc_Ip_HwAccess.h file and StandardTypes.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS != STD_AR_RELEASE_MAJOR_VERSION) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_HWACCESS != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip_HwAccess.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
                                     FUNCTION DEFINITIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

static inline void Pdb_Adc_HwAcc_SetAdcPretriggerMask(PDB_Type * const Base,
                                                      const uint8 ChanIdx,
                                                      const uint32 Mask,
                                                      const boolean Value)
{
    /* Set C1 register of a channel based on mask */
    if (Value == TRUE)
    {
        Base->CH[ChanIdx].C1 |= Mask;
    }
    else
    {
        Base->CH[ChanIdx].C1 &= ~(Mask);
    }
}

static inline void Pdb_Adc_HwAcc_DisablePdb(PDB_Type * const Base)
{
    /* Disable PDB by clearing PDBEN bit of SC register */
    Base->SC &= ~(PDB_SC_PDBEN_MASK);
}

static inline void Pdb_Adc_HwAcc_SetContinuousMode(PDB_Type * const Base,
                                                   const boolean State)
{
    /* Update ContinuousMode value found in SC register */
    if (State == TRUE)
    {
        Base->SC |= PDB_SC_CONT_MASK;
    }
    else
    {
        Base->SC &= ~(PDB_SC_CONT_MASK);
    }
}

static inline void Pdb_Adc_HwAcc_ConfigAdcPretriggers(PDB_Type * const Base,
                                                      const uint8 ChanIdx,
                                                      const Pdb_Adc_Ip_PretriggersConfigType * const Config)
{
    /* Configure all channel's pretriggers by updating all fields of the C1 register */
    uint32 C1Reg = Base->CH[ChanIdx].C1;
    C1Reg &= ~(PDB_C1_EN_MASK | PDB_C1_TOS_MASK | PDB_C1_BB_MASK);
    C1Reg |= PDB_C1_EN(Config->EnableMask);
    C1Reg |= PDB_C1_TOS(Config->EnableDelayMask);
    C1Reg |= PDB_C1_BB(Config->BackToBackEnableMask);
    Base->CH[ChanIdx].C1 = C1Reg;
}

static inline void Pdb_Adc_HwAcc_ClearAdcPretriggerFlags(PDB_Type * const Base,
                                                         const uint8 ChanIdx,
                                                         const uint16 PretriggMask)
{
    /* Clear pretrigger status flags found in S register based on PretriggMask */
    Base->CH[ChanIdx].S &= ~PDB_S_CF(PretriggMask);
}

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if defined (__cplusplus)
}
#endif

/** @} */

#endif /* PDB_PDB_ADC_IP_HW_ACCESS_H */
