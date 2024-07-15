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
#include "Pdb_Adc_Ip.h"
#include "Pdb_Adc_Ip_Irq.h"
#include "Pdb_Adc_Ip_HwAccess.h"
#include "Pdb_Adc_Ip_TrustedFunctions.h"
#include "SchM_Adc.h"
#include "OsIf.h"

#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

#if (STD_ON == PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT)
    /* USER_MODE_REG_PROT_ENABLED is defined for Base sanity check in RegLockMacros.h */
    #define USER_MODE_REG_PROT_ENABLED      (PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT)
    #include "RegLockMacros.h"
#endif /* (STD_ON == PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PDB_ADC_IP_VENDOR_ID_C                      43
#define PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_C       7
#define PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_C    0
#define PDB_ADC_IP_SW_MAJOR_VERSION_C               2
#define PDB_ADC_IP_SW_MINOR_VERSION_C               0
#define PDB_ADC_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pdb_Adc_Ip.c file and Pdb_Adc_Ip.h file are of the same vendor */
#if (PDB_ADC_IP_VENDOR_ID_C != PDB_ADC_IP_VENDOR_ID)
    #error "Pdb_Adc_Ip.c and Pdb_Adc_Ip.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip.c file and Pdb_Adc_Ip.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_C != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_C != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_C != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip.c and Pdb_Adc_Ip.h are different"
#endif

/* Check if Pdb_Adc_Ip.c file and Pdb_Adc_Ip.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION_C != PDB_ADC_IP_SW_MAJOR_VERSION) || \
     (PDB_ADC_IP_SW_MINOR_VERSION_C != PDB_ADC_IP_SW_MINOR_VERSION) || \
     (PDB_ADC_IP_SW_PATCH_VERSION_C != PDB_ADC_IP_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip.c and Pdb_Adc_Ip.h are different"
#endif

/* Check if Pdb_Adc_Ip.c file and Pdb_Adc_Ip_Irq.h file are of the same vendor */
#if (PDB_ADC_IP_VENDOR_ID_C != PDB_ADC_IP_VENDOR_ID_IRQ)
    #error "Pdb_Adc_Ip.c and Pdb_Adc_Ip_Irq.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip.c file and Pdb_Adc_Ip_Irq.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_C != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_C != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_C != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip.c and Pdb_Adc_Ip_Irq.h are different"
#endif

/* Check if Pdb_Adc_Ip.c file and Pdb_Adc_Ip_Irq.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION_C != PDB_ADC_IP_SW_MAJOR_VERSION_IRQ) || \
     (PDB_ADC_IP_SW_MINOR_VERSION_C != PDB_ADC_IP_SW_MINOR_VERSION_IRQ) || \
     (PDB_ADC_IP_SW_PATCH_VERSION_C != PDB_ADC_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip.c and Pdb_Adc_Ip_Irq.h are different"
#endif

#if (PDB_ADC_IP_VENDOR_ID_C != PDB_ADC_IP_VENDOR_ID_HWACCESS)
    #error "Pdb_Adc_Ip.c and Pdb_Adc_Ip_HwAccess.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip.c file and Pdb_Adc_Ip_HwAccess.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_C != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_C != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_HWACCESS) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_C != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_HWACCESS) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip.c and Pdb_Adc_Ip_HwAccess.h are different"
#endif

/* Check if Pdb_Adc_Ip.c file and Pdb_Adc_Ip_HwAccess.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION_C != PDB_ADC_IP_SW_MAJOR_VERSION_HWACCESS) || \
     (PDB_ADC_IP_SW_MINOR_VERSION_C != PDB_ADC_IP_SW_MINOR_VERSION_HWACCESS) || \
     (PDB_ADC_IP_SW_PATCH_VERSION_C != PDB_ADC_IP_SW_PATCH_VERSION_HWACCESS) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip.c and Pdb_Adc_Ip_HwAccess.h are different"
#endif

#if (PDB_ADC_IP_VENDOR_ID_C != PDB_ADC_IP_VENDOR_ID_TRUSTEDFUNCTIONS)
    #error "Pdb_Adc_Ip.c and Pdb_Adc_Ip_HwAccess.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip.c file and Pdb_Adc_Ip_HwAccess.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_C != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_C != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_C != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip.c and Pdb_Adc_Ip_HwAccess.h are different"
#endif

/* Check if Pdb_Adc_Ip.c file and Pdb_Adc_Ip_HwAccess.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION_C != PDB_ADC_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS) || \
     (PDB_ADC_IP_SW_MINOR_VERSION_C != PDB_ADC_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS) || \
     (PDB_ADC_IP_SW_PATCH_VERSION_C != PDB_ADC_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip.c and Pdb_Adc_Ip_HwAccess.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Pdb_Adc_Ip.c file and OsIf.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip.c and OsIf.h are different"
#endif

#if (STD_ON == PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT)
    /* Checks against RegLockMacros.h */
    #if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Pdb_Adc_Ip.c and RegLockMacros.h are different"
    #endif
#endif /* (STD_ON == PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT) */

/* Check if Pdb_Adc_Ip.c and SchM_Adc.h are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_ADC_AR_RELEASE_MAJOR_VERSION) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_ADC_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Pdb_Adc_Ip.c and SchM_Adc.h are different"
#endif

#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
 /* Check if Pdb_Adc_Ip.c and Devassert.h are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip.c and Devassert.h are different"
#endif
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                     PRE-CHECK
==================================================================================================*/
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running PDB in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

/* Table of Base addresses for PDB instances. */
static PDB_Type * const Pdb_Adc_Ip_apxBase[PDB_INSTANCE_COUNT] = IP_PDB_BASE_PTRS;

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
/* Global state structure */
static Pdb_Adc_Ip_StateStructType Pdb_Adc_Ip_axState[PDB_INSTANCE_COUNT];

#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

static inline void PDB_ADC_ResetChannel(PDB_Type * const Base,
                                        const uint8 ChanIdx,
                                        const Pdb_Adc_Ip_PretriggersConfigType * PdbPretriggsConfig);

#if  (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK)
static void PDB_ADC_ConfigInstanceBackToBack(const boolean InstanceBackToBackEnable);
#endif /* (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK) */

#if  (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK)
static void PDB_ADC_ConfigInterChannelBackToBack(const uint32 Instance,
                                                 const boolean InterChannelBackToBackEnable);
#endif /* (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK) */

/*==================================================================================================
*                                       FUNCTIONS DEFINITION
==================================================================================================*/
/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_Init
* Description   : This function initializes the PDB counter, input triggers and
* general pretrigger settings.
* It resets PDB registers and enables the PDB clock. Therefore, it should be
* called before any other operation. After it is initialized, the PDB can
* act as a triggered timer, which enables other features in PDB module.
*
* @implements     Pdb_Adc_Ip_Init_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_Init(const uint32 Instance,
                     const Pdb_Adc_Ip_ConfigType * const Config)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
    DevAssert(Config != NULL_PTR);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];
    uint8 ChannelIndex;
    uint8 PretriggerIndex;
    uint32 Reg = 0u;

    Reg |= PDB_SC_LDMOD(Config->LoadValueMode);
    Reg |= PDB_SC_PRESCALER(Config->PrescalerDiv);
    Reg |= PDB_SC_MULT(Config->ClkPreMultFactor);
    Reg |= PDB_SC_TRGSEL(Config->TriggerSource);

    if (Config->ContinuousModeEnable == TRUE)
    {
        Reg |= PDB_SC_CONT_MASK;
    }
    if (Config->DmaEnable == TRUE)
    {
        Reg |= PDB_SC_DMAEN_MASK;
    }
    if (Config->SeqErrNotification != NULL_PTR)
    {
        Reg |= PDB_SC_PDBEIE_MASK;
    }

    Base->SC = Reg;

#if  (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK)
    PDB_ADC_ConfigInstanceBackToBack(Config->InstanceBackToBackEnable);
#endif /* (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK) */
#if  (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK)
    PDB_ADC_ConfigInterChannelBackToBack(Instance, Config->InterChannelBackToBackEnable);
#endif /* (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK) */

    Pdb_Adc_Ip_SetModulus(Instance, Config->ModValue);

    if ((Config->NumChans > 0u) && (Config->ChanConfigs != NULL_PTR))
    {
        for (ChannelIndex = 0u; ChannelIndex < Config->NumChans; ChannelIndex++)
        {
            const Pdb_Adc_Ip_ChanConfigType * ChanConfig = &(Config->ChanConfigs[ChannelIndex]);
            Pdb_Adc_HwAcc_ConfigAdcPretriggers(Base, ChanConfig->ChnIdx, &(ChanConfig->PretriggersConfig));
            for (PretriggerIndex = 0u; PretriggerIndex < PDB_DLY_COUNT; PretriggerIndex++)
            {
                Pdb_Adc_Ip_SetAdcPretriggerDelayValue(Instance, ChanConfig->ChnIdx, PretriggerIndex, ChanConfig->PretriggerDelays[PretriggerIndex]);
            }
        }
    }

    Pdb_Adc_Ip_Enable(Instance);

    /* Modulus and pretrigger delay values require call to LoadRegValues */
    Pdb_Adc_Ip_LoadRegValues(Instance);

    Pdb_Adc_Ip_axState[Instance].SeqErrNotification = Config->SeqErrNotification;
    Pdb_Adc_Ip_axState[Instance].Init = TRUE;
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_DeInit
* Description   : This function resets the PDB internal registers to default values.
*
* When the PDB module is not used. Calling this function would shut down the
* PDB module and reduce the power consumption.
*
* Note: instance back to back configuration is common between PDB instances 0 and 1
* (configures the same register even if configured for either PDB instance)
* This function disables it, so affects all other instances.
*
* @implements     Pdb_Adc_Ip_Deinit_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_DeInit(const uint32 Instance)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    Pdb_Adc_Ip_ConfigType DefaultConfig;
    Pdb_Adc_Ip_ChanConfigType ChanConfigs[PDB_CH_COUNT];
    uint8 ChannelIndex, PretriggerIndex;

    DefaultConfig.LoadValueMode = PDB_ADC_IP_LOAD_VAL_IMMEDIATELY;
    DefaultConfig.PrescalerDiv = PDB_ADC_IP_CLK_PREDIV_BY_1;
    DefaultConfig.ClkPreMultFactor = PDB_ADC_IP_CLK_PREMULT_FACT_AS_1;
    DefaultConfig.TriggerSource = PDB_ADC_IP_TRIGGER_IN0;
    DefaultConfig.ContinuousModeEnable = FALSE;
    DefaultConfig.DmaEnable = FALSE;
    DefaultConfig.ModValue = 0u;
#if  (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK)
    DefaultConfig.InstanceBackToBackEnable = FALSE;
    PDB_ADC_ConfigInstanceBackToBack(DefaultConfig.InstanceBackToBackEnable);
#endif /* (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK) */
#if  (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK)
    DefaultConfig.InterChannelBackToBackEnable = FALSE;
    PDB_ADC_ConfigInterChannelBackToBack(Instance, DefaultConfig.InterChannelBackToBackEnable);
#endif /* (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK) */

    DefaultConfig.NumChans = PDB_CH_COUNT;
    for (ChannelIndex = 0u; ChannelIndex < PDB_CH_COUNT; ChannelIndex++)
    {
        ChanConfigs[ChannelIndex].ChnIdx = ChannelIndex;
        ChanConfigs[ChannelIndex].PretriggersConfig.EnableMask = 0u;
        ChanConfigs[ChannelIndex].PretriggersConfig.EnableDelayMask = 0u;
        ChanConfigs[ChannelIndex].PretriggersConfig.BackToBackEnableMask = 0u;
        for (PretriggerIndex = 0u; PretriggerIndex < PDB_DLY_COUNT; PretriggerIndex++)
        {
            ChanConfigs[ChannelIndex].PretriggerDelays[PretriggerIndex] = 0u;
        }
    }
    DefaultConfig.ChanConfigs = ChanConfigs;
    DefaultConfig.SeqErrNotification = NULL_PTR;

    Pdb_Adc_Ip_Init(Instance, &DefaultConfig);

    Pdb_Adc_Ip_Disable(Instance);

    Pdb_Adc_Ip_axState[Instance].Init = FALSE;
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_Enable
* Description   : This function enables the PDB module, counter is on.
*
* @implements     Pdb_Adc_Ip_Enable_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_Enable(const uint32 Instance)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_34();
    Base->SC |= PDB_SC_PDBEN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_34();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_Disable
* Description   : This function disables the PDB module, counter is off.
*
* @implements     Pdb_Adc_Ip_Disable_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_Disable(const uint32 Instance)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35();
    Pdb_Adc_HwAcc_DisablePdb(Base);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_SetTriggerInput
* Description   : This function sets the PDB trigger source.
*
* @implements     Pdb_Adc_Ip_SetTriggerInput_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_SetTriggerInput(const uint32 Instance,
                                const Pdb_Adc_Ip_TriggerSrcType TriggerSource)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];
    uint32 SCReg;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_36();
    SCReg = Base->SC;
    SCReg &= ~(PDB_SC_TRGSEL_MASK);
    SCReg |= PDB_SC_TRGSEL(TriggerSource);
    Base->SC = SCReg;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_36();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_SetContinuousMode
* Description   : This function sets the PDB mode to continuous or one shot.
*
* @implements     Pdb_Adc_Ip_SetContinuousMode_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_SetContinuousMode(const uint32 Instance,
                                  const boolean State)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_37();
    Pdb_Adc_HwAcc_SetContinuousMode(Base, State);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_37();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_SwTrigger
* Description   : This function triggers the PDB with a software trigger.
* When the PDB is set to use the software trigger as input, calling this function
* triggers the PDB.
*
* @implements     Pdb_Adc_Ip_SwTrigger_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_SwTrigger(const uint32 Instance)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_38();
    Base->SC |= PDB_SC_SWTRIG_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_38();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_GetTimerValue
* Description   : This function gets the current counter value.
*
* @implements     Pdb_Adc_Ip_GetTimerValue_Activity
* END**************************************************************************/
uint32 Pdb_Adc_Ip_GetTimerValue(const uint32 Instance)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    const PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];

    return ((Base->CNT & PDB_CNT_CNT_MASK) >> PDB_CNT_CNT_SHIFT);
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_LoadRegValues
* Description   : This function sets the LDOK bit.
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
* @implements     Pdb_Adc_Ip_LoadRegValues_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_LoadRegValues(const uint32 Instance)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];

#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    /* PDB must be enabled in order to load register values */
    DevAssert((Base->SC & PDB_SC_PDBEN_MASK) != 0u);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_39();
    Base->SC |= PDB_SC_LDOK_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_39();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_SetModulus
* Description   : This function sets the PDB Modulus value.
* When the counter reaches the setting value, it is automatically reset to zero.
* When in continuous mode, the counter begins to increase again.
* Note: This function writes in an internal buffer. Depending on the
* value of the LDMOD register, it might be necessary to call
* Pdb_Adc_Ip_LoadRegValues in order to update the value of the register.
* The value of the register can be changed only when the PDB module is enabled.
*
* @implements     Pdb_Adc_Ip_SetModulus_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_SetModulus(const uint32 Instance,
                           const uint16 ModVal)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];
    uint32 ModReg;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_48();
    ModReg = Base->MOD;
    ModReg &= ~(PDB_MOD_MOD_MASK);
    ModReg |= PDB_MOD_MOD(ModVal);
    Base->MOD = ModReg;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_48();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_ConfigAdcPretriggers
* Description   : This function configures the back to back modes, delay enable
* and output enable settings for all pretriggers on the selected channel.
*
* @implements     Pdb_Adc_Ip_ConfigAdcPretriggers_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_ConfigAdcPretriggers(const uint32 Instance,
                                     const uint8 ChanIdx,
                                     const Pdb_Adc_Ip_PretriggersConfigType * const Config)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
    DevAssert(ChanIdx < PDB_CH_COUNT);
    DevAssert(Config != NULL_PTR);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */
    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_41();
    Pdb_Adc_HwAcc_ConfigAdcPretriggers(Base, ChanIdx, Config);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_41();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_GetAdcPretriggerFlags
* Description   : This function gets all ADC pretrigger flags from the selected channel.
*
* @implements     Pdb_Adc_Ip_GetAdcPretriggerFlags_Activity
* END**************************************************************************/
uint32 Pdb_Adc_Ip_GetAdcPretriggerFlags(const uint32 Instance,
                                        const uint8 ChanIdx)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
    DevAssert(ChanIdx < PDB_CH_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    const PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];
    uint32 Result;

    Result = Base->CH[ChanIdx].S;
    Result = (Result & PDB_S_CF_MASK) >> PDB_S_CF_SHIFT;

    return Result;
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_ClearAdcPretriggerFlags
* Description   : This function clears the ADC pretrigger channel flags selected
* by pretriggMask from channel channel.
*
* @implements     Pdb_Adc_Ip_ClearAdcPretriggerFlags_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_ClearAdcPretriggerFlags(const uint32 Instance,
                                        const uint8 ChanIdx,
                                        const uint16 PretriggMask)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
    DevAssert(ChanIdx < PDB_CH_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_46();
    /* Write 0 to clear */
    Pdb_Adc_HwAcc_ClearAdcPretriggerFlags(Base, ChanIdx, PretriggMask);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_46();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_SetAdcPretriggerBackToBack
* Description   : This function sets back to back mode for the selected
* pretrigger on the given channel.
*
* @implements     Pdb_Adc_Ip_SetAdcPretriggerBackToBack_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_SetAdcPretriggerBackToBack(const uint32 Instance,
                                           const uint8 ChanIdx,
                                           const uint8 PretriggIdx,
                                           const boolean Value)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
    DevAssert(ChanIdx < PDB_CH_COUNT);
    DevAssert(PretriggIdx < PDB_DLY_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];
    uint32 Mask = (uint32)1u << PretriggIdx;

    Mask = PDB_C1_BB(Mask);
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_42();
    Pdb_Adc_HwAcc_SetAdcPretriggerMask(Base, ChanIdx, Mask, Value);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_42();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_SetAdcPretriggerEnable
* Description   : This function enables or disables the selected pretrigger on
* the given channel.
*
* @implements     Pdb_Adc_Ip_SetAdcPretriggerEnable_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_SetAdcPretriggerEnable(const uint32 Instance,
                                       const uint8 ChanIdx,
                                       const uint8 PretriggIdx,
                                       const boolean Value)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
    DevAssert(ChanIdx < PDB_CH_COUNT);
    DevAssert(PretriggIdx < PDB_DLY_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];
    uint32 Mask = (uint32)1u << PretriggIdx;

    Mask = PDB_C1_EN(Mask);
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_43();
    Pdb_Adc_HwAcc_SetAdcPretriggerMask(Base, ChanIdx, Mask, Value);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_43();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_SetAdcPretriggerDelayEnable
* Description   : This function sets the delay enable value for the selected
* pretrigger on the given channel.
*
* @implements     Pdb_Adc_Ip_SetAdcPretriggerDelayEnable_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_SetAdcPretriggerDelayEnable(const uint32 Instance,
                                            const uint8 ChanIdx,
                                            const uint8 PretriggIdx,
                                            const boolean Value)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
    DevAssert(ChanIdx < PDB_CH_COUNT);
    DevAssert(PretriggIdx < PDB_DLY_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];
    uint32 Mask = (uint32)1u << PretriggIdx;

    Mask = PDB_C1_TOS(Mask);
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_44();
    Pdb_Adc_HwAcc_SetAdcPretriggerMask(Base, ChanIdx, Mask, Value);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_44();
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_SetAdcPretriggerDelayValue
* Description   : This function sets the pretrigger delay value.
* Note: This function writes in an internal buffer. Depending on the
* value of the LDMOD register, it might be necessary to call
* Pdb_Adc_Ip_LoadRegValues in order to update the value of the register.
* The value of the register can be changed only when the PDB module is enabled.
*
* @implements     Pdb_Adc_Ip_SetAdcPretriggerDelayValue_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_SetAdcPretriggerDelayValue(const uint32 Instance,
                                           const uint8 ChanIdx,
                                           const uint8 PretriggIdx,
                                           const uint16 DelayValue)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
    DevAssert(ChanIdx < PDB_CH_COUNT);
    DevAssert(PretriggIdx < PDB_DLY_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];

    Base->CH[ChanIdx].DLY[PretriggIdx] = PDB_DLY_DLY(DelayValue);
}

/*FUNCTION**********************************************************************
*
* Function Name : Pdb_Adc_Ip_DisableAndClearPdb
* Description   : This function disables PDB module and clears all channels
* configuration and status registers.
*
* @implements     Pdb_Adc_Ip_DisableAndClearPdb_Activity
* END**************************************************************************/
void Pdb_Adc_Ip_DisableAndClearPdb(const uint32 Instance)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];
    uint8 ChanIdx;
    const Pdb_Adc_Ip_PretriggersConfigType PdbPretriggsConfig = { 0u, 0u, 0u };

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_40();
    Pdb_Adc_HwAcc_DisablePdb(Base);
    Pdb_Adc_HwAcc_SetContinuousMode(Base, FALSE);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_40();

    for (ChanIdx = 0U; ChanIdx < PDB_CH_COUNT; ChanIdx++)
    {
        PDB_ADC_ResetChannel(Base, ChanIdx, &PdbPretriggsConfig);
    }
}

/*FUNCTION*********************************************************************
 *
 * Function Name : Pdb_Adc_Ip_IRQHandler
 * Description   : Handles Pdb sequence error interrupt.
 *
 * @implements     Pdb_Adc_Ip_IRQHandler_Activity
 *END*************************************************************************/
void Pdb_Adc_Ip_IRQHandler(const uint32 Instance)
{
#if (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < PDB_INSTANCE_COUNT);
#endif /* (PDB_ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    PDB_Type * const Base = Pdb_Adc_Ip_apxBase[Instance];
    uint8 ChanIdx;
    uint16 SeqErrMask;

    /* Check whether the respective driver is initialized */
    if (TRUE == Pdb_Adc_Ip_axState[Instance].Init)
    {
        /* CPR_RTD_00664
         * Check if the callback is not NULL since all channels use the same one (to avoid checking inside the loop).
         * Check if the interrupt not spurious (sequence error interrupt is enabled and sequence error flag is set).
         */
        if ( ((Base->SC & PDB_SC_PDBEIE_MASK) != 0u) && (Pdb_Adc_Ip_axState[Instance].SeqErrNotification != NULL_PTR) )
        {
            for (ChanIdx = 0u; ChanIdx < PDB_CH_COUNT; ChanIdx++)
            {
                SeqErrMask = (uint16) ((Base->CH[ChanIdx].S & PDB_S_ERR_MASK) >> PDB_S_ERR_SHIFT);
                if (SeqErrMask != 0u)
                {
                    /* Clear the sequence error flag triggered from the current channel (W0C).
                     * And call the associated callback.
                     */
                    Base->CH[ChanIdx].S &= ~(PDB_S_ERR_MASK);
                    Pdb_Adc_Ip_axState[Instance].SeqErrNotification(ChanIdx, SeqErrMask);
                }
            }
        }
    }
    else
    {
        /* CPR_RTD_00011 */
        for (ChanIdx = 0u; ChanIdx < PDB_CH_COUNT; ChanIdx++)
        {
            /* Clear all sequence error flags triggered from the current channel
            * by writing 0 to raised bits. */
            Base->CH[ChanIdx].S &= ~(PDB_S_ERR_MASK);
        }
    }
}

static inline void PDB_ADC_ResetChannel(PDB_Type * const Base,
                                        const uint8 ChanIdx,
                                        const Pdb_Adc_Ip_PretriggersConfigType * PdbPretriggsConfig)
{
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_45();
    Pdb_Adc_HwAcc_ConfigAdcPretriggers(Base, ChanIdx, PdbPretriggsConfig);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_45();

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_47();
    Pdb_Adc_HwAcc_ClearAdcPretriggerFlags(Base, ChanIdx, 0xFFu);

    /* Clear all sequence error flags. */
    Base->CH[ChanIdx].S &= ~(PDB_S_ERR_MASK);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_47();
}

#if  (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK)
void Pdb_Adc_Ip_ConfigInstanceBackToBack_TrustedCall(const boolean InstanceBackToBackEnable)
{
    if(InstanceBackToBackEnable == TRUE)
    {
        IP_SIM->CHIPCTL |= SIM_CHIPCTL_PDB_BB_SEL_MASK;
    }
    else
    {
        IP_SIM->CHIPCTL &= ~SIM_CHIPCTL_PDB_BB_SEL_MASK;
    }
}

static void PDB_ADC_ConfigInstanceBackToBack(const boolean InstanceBackToBackEnable)
{
#if (STD_ON == PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(Pdb_Adc_Ip_ConfigInstanceBackToBack_TrustedCall,(InstanceBackToBackEnable));
#else
    Pdb_Adc_Ip_ConfigInstanceBackToBack_TrustedCall(InstanceBackToBackEnable);
#endif
}
#endif /* (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK) */

#if  (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK)
void Pdb_Adc_Ip_ConfigInterChannelBackToBack_TrustedCall(const uint32 Instance,
                                                         const boolean InterChannelBackToBackEnable)
{
    /* Check if BackToBack mode is enabled */
    if(InterChannelBackToBackEnable == TRUE)
    {
        /* Check the instance */
        if (0U == Instance)
        {
            IP_SIM->CHIPCTL |= SIM_CHIPCTL_PDB_BB_SEL_1_MASK;
        }
        else
        {
            IP_SIM->CHIPCTL |= SIM_CHIPCTL_PDB_BB_SEL_2_MASK;
        }
    }
    else
    {
        /* Check the instance */
        if (0U == Instance)
        {
            IP_SIM->CHIPCTL &= ~(SIM_CHIPCTL_PDB_BB_SEL_1_MASK);
        }
        else
        {
            IP_SIM->CHIPCTL &= ~(SIM_CHIPCTL_PDB_BB_SEL_2_MASK);
        }

    }
}

static void PDB_ADC_ConfigInterChannelBackToBack(const uint32 Instance,
                                                 const boolean InterChannelBackToBackEnable)
{
#if (STD_ON == PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call2params(Pdb_Adc_Ip_ConfigInterChannelBackToBack_TrustedCall,(Instance),(InterChannelBackToBackEnable));
#else
    Pdb_Adc_Ip_ConfigInterChannelBackToBack_TrustedCall(Instance, InterChannelBackToBackEnable);
#endif /* (STD_ON == PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT) */
}
#endif /* (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
