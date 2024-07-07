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
#include "Adc_Ip.h"
#include "Adc_Ip_Irq.h"
#include "Adc_Ip_HwAccess.h"
#include "Adc_Ip_TrustedFunctions.h"
#include "SchM_Adc.h"
#include "OsIf.h"

#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

#if (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT)
/* USER_MODE_REG_PROT_ENABLED is defined for Base sanity check in RegLockMacros.h */
#define USER_MODE_REG_PROT_ENABLED      (ADC_IP_ENABLE_USER_MODE_SUPPORT)
#include "RegLockMacros.h"
#endif /* (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID_C                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_C       7
#define ADC_IP_AR_RELEASE_REVISION_VERSION_C    0
#define ADC_IP_SW_MAJOR_VERSION_C               2
#define ADC_IP_SW_MINOR_VERSION_C               0
#define ADC_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Ip.c file and Adc_Ip.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_C != ADC_IP_VENDOR_ID)
    #error "Adc_Ip.c and Adc_Ip.h have different vendor ids"
#endif

/* Check if Adc_Ip.c file and Adc_Ip.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_C != ADC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_C != ADC_IP_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_C != ADC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Ip.c and Adc_Ip.h are different"
#endif

/* Check if Adc_Ip.c file and Adc_Ip.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_C != ADC_IP_SW_MAJOR_VERSION) || \
     (ADC_IP_SW_MINOR_VERSION_C != ADC_IP_SW_MINOR_VERSION) || \
     (ADC_IP_SW_PATCH_VERSION_C != ADC_IP_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Adc_Ip.c and Adc_Ip.h are different"
#endif

/* Check if Adc_Ip.c file and Adc_Ip_Irq.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_C != ADC_IP_VENDOR_ID_IRQ)
    #error "Adc_Ip.c and Adc_Ip_Irq.h have different vendor ids"
#endif

/* Check if Adc_Ip.c file and Adc_Ip_Irq.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_C != ADC_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_C != ADC_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_C != ADC_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Adc_Ip.c and Adc_Ip_Irq.h are different"
#endif

/* Check if Adc_Ip.c file and Adc_Ip_Irq.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_C != ADC_IP_SW_MAJOR_VERSION_IRQ) || \
     (ADC_IP_SW_MINOR_VERSION_C != ADC_IP_SW_MINOR_VERSION_IRQ) || \
     (ADC_IP_SW_PATCH_VERSION_C != ADC_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Adc_Ip.c and Adc_Ip_Irq.h are different"
#endif

/* Check if Adc_Ip.c file and Adc_Ip_HwAccess.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_C != ADC_IP_VENDOR_ID_HWACCESS)
    #error "Adc_Ip.c and Adc_Ip_HwAccess.h have different vendor ids"
#endif

/* Check if Adc_Ip.c file and Adc_Ip_HwAccess.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_C != ADC_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_C != ADC_IP_AR_RELEASE_MINOR_VERSION_HWACCESS) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_C != ADC_IP_AR_RELEASE_REVISION_VERSION_HWACCESS) \
    )
    #error "AutoSar Version Numbers of Adc_Ip.c and Adc_Ip_HwAccess.h are different"
#endif

/* Check if Adc_Ip.c file and Adc_Ip_HwAccess.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_C != ADC_IP_SW_MAJOR_VERSION_HWACCESS) || \
     (ADC_IP_SW_MINOR_VERSION_C != ADC_IP_SW_MINOR_VERSION_HWACCESS) || \
     (ADC_IP_SW_PATCH_VERSION_C != ADC_IP_SW_PATCH_VERSION_HWACCESS) \
    )
  #error "Software Version Numbers of Adc_Ip.c and Adc_Ip_HwAccess.h are different"
#endif

/* Check if Adc_Ip.c file and Adc_Ip_TrustedFunctions.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_C != ADC_IP_VENDOR_ID_TRUSTEDFUNCTIONS)
    #error "Adc_Ip.c and Adc_Ip_TrustedFunctions.h have different vendor ids"
#endif

/* Check if Adc_Ip.c file and Adc_Ip_TrustedFunctions.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_C != ADC_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_C != ADC_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_C != ADC_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS) \
    )
    #error "AutoSar Version Numbers of Adc_Ip.c and Adc_Ip_TrustedFunctions.h are different"
#endif

/* Check if Adc_Ip.c file and Adc_Ip_TrustedFunctions.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_C != ADC_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS) || \
     (ADC_IP_SW_MINOR_VERSION_C != ADC_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS) || \
     (ADC_IP_SW_PATCH_VERSION_C != ADC_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS) \
    )
  #error "Software Version Numbers of Adc_Ip.c and Adc_Ip_TrustedFunctions.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Ip.c file and OsIf.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (ADC_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Ip.c and OsIf.h are different"
#endif

#if (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT)
    /* Checks against RegLockMacros.h */
    #if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ADC_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Adc_Ip.c and RegLockMacros.h are different"
    #endif
#endif /* (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT) */

/* Check if Adc_Ip.c and SchM_Adc.h are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_ADC_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Adc_Ip.c and SchM_Adc.h are different"
#endif

#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
/* Check if Adc_Ip.c and Devassert.h are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Ip.c and Devassert.h are different"
#endif
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                     PRE-CHECK
==================================================================================================*/
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running ADC in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

/* Table of Base addresses for ADC instances. */
static ADC_Type * const Adc_Ip_apxBase[ADC_INSTANCE_COUNT] = IP_ADC_BASE_PTRS;

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
/* Global state structure */
static Adc_Ip_StateStructType Adc_Ip_axState[ADC_INSTANCE_COUNT];

#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
static void ADC_SetSupplyMonitoringEnable(const boolean SupplyEnable);
static void ADC_ConfigSupplyMonitoringChannel(const uint32 SupplyChannel);
static void ADC_ResetSupplyMonitoringChannel(void);
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */
#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
static void ADC_SetTriggerSourceSelect(const uint32 Instance,
                                       const uint8 TriggerSource);
static void ADC_SetPretriggerSourceSelect(const uint32 Instance,
                                          const uint8 PretriggerSource);
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */
static inline void ADC_DoCalibration_SetParams(ADC_Type * const Base,
                                               const Adc_Ip_ClockConfigType * const Config,
                                               const Adc_Ip_TrigType TriggerMode);

/*==================================================================================================
*                                       FUNCTIONS DEFINITION
==================================================================================================*/
/*FUNCTION**********************************************************************
*
* Function Name : ADC_DoCalibration_SetParams
* Description   : This function configures averaging, sample time, input clock and trigger
* mode for Adc_Ip_DoCalibration service.
*
* END**************************************************************************/
static inline void ADC_DoCalibration_SetParams(ADC_Type * const Base,
                                               const Adc_Ip_ClockConfigType * const Config,
                                               const Adc_Ip_TrigType TriggerMode)
{
    /* Configure averaging */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_29();
    Adc_HwAcc_SetAveraging(Base, Config->AvgEn, Config->AvgSel);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_29();

    /* Configure trigger mode */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_24();
    Adc_HwAcc_SetTriggerMode(Base, TriggerMode);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24();

    /* Configure sample time */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15();
    Adc_HwAcc_SetSampleTime(Base, Config->SampleTime);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15();

    /* Configure input clock */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13();
    Adc_HwAcc_SetClock(Base, Config->ClockDivide, Config->InputClock);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_Init
* Description   : This function initializes the ADC module by configuring all
* available features.
*
* @implements     Adc_Ip_Init_Activity
* END**************************************************************************/
void Adc_Ip_Init(const uint32 Instance,
                 const Adc_Ip_ConfigType * const Config)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(Config != NULL_PTR);
    DevAssert(Config->NumChannels <= ADC_MAX_CHAN_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];
    uint32 SC2Reg = 0u;
    uint32 SC2ClearMask = 0u;
    uint8 Index;

    Adc_HwAcc_SetClock(Base, Config->ClockDivide, Config->InputClock);
    Adc_HwAcc_SetSampleTime(Base, Config->SampleTime);
    Adc_HwAcc_SetAveraging(Base, Config->AvgEn, Config->AvgSel);

    Adc_Ip_SetResolution(Instance, Config->Resolution);

#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
    ADC_SetTriggerSourceSelect(Instance, Config->TriggerSel);
    ADC_SetPretriggerSourceSelect(Instance, Config->PretriggerSel);
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */

#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
    if (Instance == 0U)
    {
        ADC_SetSupplyMonitoringEnable(Config->SupplyMonitoringEnable);
    }
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */

    /* Configure trigger mode */
    SC2ClearMask |= ADC_SC2_ADTRG_MASK;
    SC2Reg |= ADC_SC2_ADTRG(Config->TriggerMode);

    /* Configure DMA enable */
    if (Config->DmaEnable)
    {
        SC2Reg |= ADC_SC2_DMAEN_MASK;
    }
    else
    {
        SC2ClearMask |= ADC_SC2_DMAEN_MASK;
    }

    /* Configure voltage reference selector */
    SC2ClearMask |= ADC_SC2_REFSEL_MASK;
    SC2Reg |= ADC_SC2_REFSEL(Config->VoltageRef);

    /* Configure compare enables and values */
    SC2ClearMask |= ADC_SC2_ACFE_MASK | ADC_SC2_ACFGT_MASK | ADC_SC2_ACREN_MASK;
    SC2Reg |= ADC_SC2_ACFE(Config->CompareEnable ? 1u : 0u);
    SC2Reg |= ADC_SC2_ACFGT(Config->CompareGreaterThanEnable ? 1u : 0u);
    SC2Reg |= ADC_SC2_ACREN(Config->CompareRangeFuncEnable ? 1u : 0u);
    Base->CV[0u] = ADC_CV_CV(Config->CompVal1);
    Base->CV[1u] = ADC_CV_CV(Config->CompVal2);

    Adc_HwAcc_SetSC2Reg(Base, SC2ClearMask, SC2Reg);

    Adc_HwAcc_SetUserGainAndOffset(Base, Config->UsrGain, Config->UsrOffset);

    Adc_Ip_SetContinuousMode(Instance, Config->ContinuousConvEnable);

    if (Config->ChannelConfigs != NULL_PTR)
    {
        for (Index = 0u; Index < Config->NumChannels; Index++)
        {
            Adc_Ip_ConfigChannel(Instance, &(Config->ChannelConfigs[Index]));
        }
    }

#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
    Adc_Ip_axState[Instance].ConversionCompleteNotification = Config->ConversionCompleteNotification;
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
    Adc_Ip_axState[Instance].CalibrationClockDivide = Config->CalibrationClockDivide;
    Adc_Ip_axState[Instance].Init = TRUE;
#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
    Adc_Ip_axState[Instance].PretriggerSel = Config->PretriggerSel;
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_DeInit
* Description   : This function resets the ADC internal registers to default values.
*
* @implements     Adc_Ip_Deinit_Activity
* END**************************************************************************/
void Adc_Ip_DeInit(const uint32 Instance)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    Adc_Ip_ConfigType DefaultConfig;
    Adc_Ip_ChanConfigType ChannelConfigs[ADC_MAX_CHAN_COUNT];
    uint8 Index;

    DefaultConfig.ClockDivide = ADC_IP_CLK_FULL_BUS;
    DefaultConfig.CalibrationClockDivide = ADC_IP_CLK_EIGHTH_BUS;
    DefaultConfig.InputClock = ADC_IP_CLK_ALT_1;
    DefaultConfig.SampleTime = ADC_IP_DEFAULT_SAMPLE_TIME;
    DefaultConfig.AvgEn = FALSE;
    DefaultConfig.AvgSel = ADC_IP_AVG_4_CONV;
    DefaultConfig.Resolution = ADC_IP_RESOLUTION_8BIT;
    DefaultConfig.TriggerMode = ADC_IP_TRIGGER_SOFTWARE;
#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
    DefaultConfig.PretriggerSel = ADC_IP_PRETRIGGER_SEL_PDB;
    DefaultConfig.TriggerSel = ADC_IP_TRIGGER_SEL_PDB;
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */
    DefaultConfig.DmaEnable = FALSE;
    DefaultConfig.VoltageRef = ADC_IP_VOLTAGEREF_VREF;
    DefaultConfig.ContinuousConvEnable = FALSE;
#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
    DefaultConfig.SupplyMonitoringEnable = FALSE;
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */
    DefaultConfig.CompareEnable = FALSE;
    DefaultConfig.CompareGreaterThanEnable = FALSE;
    DefaultConfig.CompareRangeFuncEnable = FALSE;
    DefaultConfig.CompVal1 = 0u;
    DefaultConfig.CompVal2 = 0u;
    DefaultConfig.UsrGain = ADC_IP_DEFAULT_USER_GAIN;
    DefaultConfig.UsrOffset = 0u;
    DefaultConfig.NumChannels = ADC_MAX_CHAN_COUNT;
    for (Index = 0u; Index < ADC_MAX_CHAN_COUNT; Index++)
    {
        ChannelConfigs[Index].ChnIdx = Index;
        ChannelConfigs[Index].Channel = ADC_IP_INPUTCHAN_DISABLED;
#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
        ChannelConfigs[Index].InterruptEnable = FALSE;
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
    }
    DefaultConfig.ChannelConfigs = ChannelConfigs;
#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
    DefaultConfig.ConversionCompleteNotification = NULL_PTR;
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */

    Adc_Ip_Init(Instance, &DefaultConfig);
#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
    if (Instance == 0U)
    {
        ADC_ResetSupplyMonitoringChannel();
    }
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */

    Adc_Ip_axState[Instance].Init = FALSE;
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_SetAveraging
* Description   : This function enables averaging and selects the number of
* conversions to average.
* The mask parameter should be set using the Adc_Ip_AvgSelectType enum elements
* that have the pattern ADC_IP_AVG_... e.g. ADC_IP_AVG_4_CONV.
*
* @implements     Adc_Ip_SetAveraging_Activity
* END**************************************************************************/
void Adc_Ip_SetAveraging(const uint32 Instance,
                         const boolean AvgEn,
                         const Adc_Ip_AvgSelectType AvgSel)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_27();
    Adc_HwAcc_SetAveraging(Base, AvgEn, AvgSel);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_27();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_SetSampleTime
* Description   : This function sets the sample time for selected ADC instance.
*
* @implements     Adc_Ip_SetSampleTime_Activity
* END**************************************************************************/
void Adc_Ip_SetSampleTime(const uint32 Instance,
                          const uint8 SampleTime)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16();
    Adc_HwAcc_SetSampleTime(Base, SampleTime);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_EnableDma
* Description   : This function enables DMA.
*
* @implements     Adc_Ip_EnableDma_Activity
* END**************************************************************************/
void Adc_Ip_EnableDma(const uint32 Instance)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26();
    Base->SC2 |= ADC_SC2_DMAEN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_DisableDma
* Description   : This function disables DMA.
*
* @implements     Adc_Ip_DisableDma_Activity
* END**************************************************************************/
void Adc_Ip_DisableDma(const uint32 Instance)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_22();
    Base->SC2 &= ~(ADC_SC2_DMAEN_MASK);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_22();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_SetTriggerMode
* Description   : This function enables either hardware or software trigger.
*
* @implements     Adc_Ip_SetTriggerMode_Activity
* END**************************************************************************/
void Adc_Ip_SetTriggerMode(const uint32 Instance,
                           const Adc_Ip_TrigType TriggerMode)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23();
    Adc_HwAcc_SetTriggerMode(Base, TriggerMode);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_SetContinuousMode
* Description   : This function switches between ADC continuous conversion mode
* and one shot mode.
*
* @implements     Adc_Ip_SetContinuousMode_Activity
* END**************************************************************************/
void Adc_Ip_SetContinuousMode(const uint32 Instance,
                              const boolean ContinuousModeEnable)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_30();
    uint32 Sc3Reg = Base->SC3;
    Sc3Reg &= ~(ADC_SC3_ADCO_MASK);
    Sc3Reg |= ADC_SC3_ADCO(ContinuousModeEnable ? 1u : 0u);
    Base->SC3 = Sc3Reg;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_30();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_SetResolution
* Description   : This function sets ADC module resolution.
*
* @implements     Adc_Ip_SetResolution_Activity
* END**************************************************************************/
void Adc_Ip_SetResolution(const uint32 Instance,
                          const Adc_Ip_ResolutionType Resolution)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10();
    uint32 Cfg1Reg = Base->CFG1;
    Cfg1Reg &= ~(ADC_CFG1_MODE_MASK);
    Cfg1Reg |= ADC_CFG1_MODE(Resolution);
    Base->CFG1 = Cfg1Reg;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_SetClockMode
* Description   : This function initializes the ADC clock configuration.
*
* @implements     Adc_Ip_SetClockMode_Activity
* END**************************************************************************/
void Adc_Ip_SetClockMode(const uint32 Instance,
                         const Adc_Ip_ClockConfigType * const Config)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(Config != NULL_PTR);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11();
    Adc_HwAcc_SetClock(Base, Config->ClockDivide, Config->InputClock);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11();

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14();
    Adc_HwAcc_SetSampleTime(Base, Config->SampleTime);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_28();
    Adc_HwAcc_SetAveraging(Base, Config->AvgEn, Config->AvgSel);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_28();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_ConfigChannel
* Description   : Configures the selected control channel with the given
* configuration structure.
*
* When Software Trigger mode is enabled, configuring control channel index 0,
* implicitly triggers a new conversion on the selected ADC input channel.
* Therefore, Adc_Ip_ConfigChannel can be used for sw-triggering conversions.
*
* Configuring any control channel while it is actively controlling a conversion
* (sw or hw triggered) will implicitly abort the on-going conversion.
*
* @implements     Adc_Ip_ConfigChannel_Activity
* END**************************************************************************/
void Adc_Ip_ConfigChannel(const uint32 Instance,
                          const Adc_Ip_ChanConfigType * const ChanConfig)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(ChanConfig != NULL_PTR);
#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
    DevAssert((Instance == 0u) || ((uint32)ChanConfig->Channel < (uint32)ADC_IP_INPUTCHAN_SUPPLY_VDD));
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];
    Adc_Ip_InputChannelType InputChanDemapped;

#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
    /* Internal supply monitor channels need special configuration */
    if (ChanConfig->Channel >= ADC_IP_INPUTCHAN_SUPPLY_VDD)
    {
        /* De-map ADC_IP_INPUTCHAN_SUPPLY_ into actual index. */
        const uint32 SupplyChannel = (uint32)ChanConfig->Channel - (uint32)ADC_IP_INPUTCHAN_SUPPLY_VDD;
        ADC_ConfigSupplyMonitoringChannel(SupplyChannel);
        /* Supply monitor channels are measured on ADC internal input channel 0 */
        InputChanDemapped = ADC_IP_INPUTCHAN_INT0;
    }
    else
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */
    {
        InputChanDemapped = ChanConfig->Channel;
    }

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21();
#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
    Adc_HwAcc_SetChannel(Base, ChanConfig->ChnIdx, InputChanDemapped, ChanConfig->InterruptEnable);
#else
    Adc_HwAcc_SetChannel(Base, ChanConfig->ChnIdx, InputChanDemapped, FALSE);
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21();

    /* Also update in state structure */
    Adc_Ip_axState[Instance].ChannelConfig[ChanConfig->ChnIdx] = ChanConfig->Channel;
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_SetDisabledChannel
* Description   : This function sets the input channel of the selected control
* channel to ADC_IP_INPUTCHAN_DISABLED. If WithTimeout is TRUE then the
* function will also wait for the register to be updated.
* Note: the control channel index is the numeric index of SC1x
* (e.g. SC1A has index 0), not the input channel.
*
* @implements     Adc_Ip_SetDisabledChannel_Activity
* END**************************************************************************/
Adc_Ip_StatusType Adc_Ip_SetDisabledChannel(const uint32 Instance,
                                            const uint8 ControlChanIdx,
                                            const boolean WithTimeout)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(ControlChanIdx < ADC_MAX_CHAN_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];
    Adc_Ip_StatusType Status = ADC_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(ADC_IP_TIMEOUT_VAL, ADC_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(ADC_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0u;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17();
    /* Set input channel select to disabled */
    SC1(Base, ControlChanIdx) |= ADC_SC1_ADCH_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17();

    if (WithTimeout == TRUE)
    {
        while (((SC1(Base, ControlChanIdx) & ADC_SC1_ADCH_MASK) != ADC_SC1_ADCH_MASK) && (ElapsedTicks < TimeoutTicks))
        {
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, ADC_IP_TIMEOUT_TYPE);
        }
        if (ElapsedTicks >= TimeoutTicks)
        {
            Status = ADC_IP_STATUS_TIMEOUT;
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_StartConversion
* Description   : This function starts a software conversion on the selected
* input channel by writing the given values to the SC1A register.
* The result can be read with Adc_Ip_GetConvData with index 0.
* Note: hardware configuration on the control channel with index 0 will be
* overwritten.
* Note: this will not work if hardware triggered mode is selected.
*
* @implements     Adc_Ip_StartConversion_Activity
* END**************************************************************************/
void Adc_Ip_StartConversion(const uint32 Instance,
                            Adc_Ip_InputChannelType InputChannel,
                            const boolean InterruptEnable)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18();
    /* Configure SC1A register */
#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
    Adc_HwAcc_SetChannel(Base, 0u, InputChannel, InterruptEnable);
#else
    Adc_HwAcc_SetChannel(Base, 0u, InputChannel, FALSE);
    (void)InterruptEnable;
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_GetConvActiveFlag
* Description   : Reads and return conversion active flag status.
*
* @implements     Adc_Ip_GetConvActiveFlag_Activity
* END**************************************************************************/
boolean Adc_Ip_GetConvActiveFlag(const uint32 Instance)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    const ADC_Type * const Base = Adc_Ip_apxBase[Instance];
    uint32 Sc2Reg = Base->SC2;

    Sc2Reg = (Sc2Reg & ADC_SC2_ADACT_MASK) >> ADC_SC2_ADACT_SHIFT;

    return (Sc2Reg != 0u) ? TRUE : FALSE;
}

#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_GetChanInterrupt
* Description   :  This function checks and returns if the selected control
* channel has the interrupt flag set.
*
* @implements     Adc_Ip_GetChanInterrupt_Activity
* END**************************************************************************/
boolean Adc_Ip_GetChanInterrupt(const uint32 Instance,
                                const uint8 ControlChanIdx)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(ControlChanIdx < ADC_MAX_CHAN_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    const uint32 Sc1Reg = SC1(Adc_Ip_apxBase[Instance], ControlChanIdx);

    return Adc_HwAcc_GetAIEN(Sc1Reg);
}
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_GetConvCompleteFlag
* Description   :  This function returns the value of the conversion
* complete(COCO) flag of a given channel.
*
* @implements     Adc_Ip_GetConvCompleteFlag_Activity
* END**************************************************************************/
boolean Adc_Ip_GetConvCompleteFlag(const uint32 Instance,
                                   const uint8 ControlChanIdx)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(ControlChanIdx < ADC_MAX_CHAN_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    const uint32 Sc1Reg = SC1(Adc_Ip_apxBase[Instance], ControlChanIdx);

    return Adc_HwAcc_GetCOCO(Sc1Reg);
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_GetConvData
* Description   : This function retrieves the last conversion result for the
* selected control channel. This function does no validity check on the result.
* In order to check if the result is valid, the user must call
* Adc_Ip_GetConvCompleteFlag function before this one.
*
* @implements     Adc_Ip_GetConvData_Activity
* END**************************************************************************/
uint16 Adc_Ip_GetConvData(const uint32 Instance,
                          const uint8 ControlChanIdx)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(ControlChanIdx < ADC_MAX_CHAN_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    const ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    return Adc_HwAcc_GetData(Base, ControlChanIdx);
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_DoCalibration
* Description   : This function performs a calibration of the ADC. The input
* clock frequency for calibration must be less than or equal to half of the maximum
* specified frequency (50Mhz) and greater than minimum specified frequency (20Mhz).
*
* @implements     Adc_Ip_DoCalibration_Activity
* END**************************************************************************/
Adc_Ip_StatusType Adc_Ip_DoCalibration(const uint32 Instance)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];
    Adc_Ip_StatusType Status = ADC_IP_STATUS_SUCCESS;
    Adc_Ip_TrigType TriggerMode;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(ADC_IP_TIMEOUT_VAL, ADC_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(ADC_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0u;
    uint32 Reg;
    Adc_Ip_ClockConfigType PreClockConfig;
    Adc_Ip_ClockConfigType CalClockConfig;

    /* Store settings before calibration */
    Reg = Base->SC3;
    PreClockConfig.AvgEn = ((Reg & ADC_SC3_AVGE_MASK) != 0u) ? TRUE : FALSE;
    PreClockConfig.AvgSel = Adc_HwAcc_GetAverageSelect(Reg);

    Reg = Base->CFG2;
    PreClockConfig.SampleTime = (uint8) ((Reg & ADC_CFG2_SMPLTS_MASK) >> ADC_CFG2_SMPLTS_SHIFT);
    TriggerMode = Adc_HwAcc_GetTriggerMode(Base->SC2);

    Reg = Base->CFG1;
    PreClockConfig.ClockDivide = Adc_HwAcc_GetClockDivide(Reg);
    PreClockConfig.InputClock = Adc_HwAcc_GetInputClock(Reg);

    CalClockConfig.AvgEn = TRUE;
    CalClockConfig.AvgSel = ADC_IP_AVG_32_CONV;
    CalClockConfig.SampleTime = ADC_IP_DEFAULT_SAMPLE_TIME;
    CalClockConfig.ClockDivide = Adc_Ip_axState[Instance].CalibrationClockDivide;
    CalClockConfig.InputClock = PreClockConfig.InputClock;

    /* Prepare required settings for calibration. */
    ADC_DoCalibration_SetParams(Base, &CalClockConfig, ADC_IP_TRIGGER_SOFTWARE);

    Base->CLPS = 0u;
    Base->CLP3 = 0u;
    Base->CLP2 = 0u;
    Base->CLP1 = 0u;
    Base->CLP0 = 0u;
    Base->CLPX = 0u;
    Base->CLP9 = 0u;

    /* Start calibration by writing to the calibration field */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_29();
    Reg = Base->SC3;
    Reg &= ~(ADC_SC3_CAL_MASK);
    Reg |= ADC_SC3_CAL(1u);
    Base->SC3 = Reg;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_29();

    /* Wait for the calibration to finish */
    while (((Base->SC3 & ADC_SC3_CAL_MASK) != 0u) && (ElapsedTicks < TimeoutTicks))
    {
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, ADC_IP_TIMEOUT_TYPE);
    }
    if (ElapsedTicks >= TimeoutTicks)
    {
        Status = ADC_IP_STATUS_TIMEOUT;
    }

    /* Revert settings as same as before calibration. */
    ADC_DoCalibration_SetParams(Base, &PreClockConfig, TriggerMode);

    /* Clear COCO flag */
    (void) R(Base, 0u);

    return Status;
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_ClearLatchedTriggers
* Description   : This function clears all trigger latched flags of the ADC instance.
* This function must be called after the hardware trigger source for the ADC
* has been deactivated.
*
* @implements     Adc_Ip_ClearLatchedTriggers_Activity
* END**************************************************************************/
Adc_Ip_StatusType Adc_Ip_ClearLatchedTriggers(const uint32 Instance)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(Instance != 0u);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];
    Adc_Ip_StatusType Status = ADC_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(ADC_IP_TIMEOUT_VAL, ADC_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(ADC_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0u;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12();
    /* Write bit to clear latched triggers */
    Base->CFG1 |= ADC_CFG1_CLRLTRG(0x01u);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12();

    /* Wait for latched triggers to be cleared */
    while (((Base->SC2 & ADC_SC2_TRGSTLAT_MASK) != 0u) && (ElapsedTicks < TimeoutTicks))
    {
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, ADC_IP_TIMEOUT_TYPE);
    }
    if (ElapsedTicks >= TimeoutTicks)
    {
        Status = ADC_IP_STATUS_TIMEOUT;
    }

    return Status;
}

#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_EnableChannelNotification
* Description   : This function enables the notification for the selected channel.
* Note          : It's required to read result data in user notification in order to clear the COCO flags and avoid ISR getting invoked repeatedly
*
* @implements     Adc_Ip_EnableChannelNotification_Activity
* END**************************************************************************/
void Adc_Ip_EnableChannelNotification(const uint32 Instance,
                                      const uint8 ControlChanIdx)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(ControlChanIdx < ADC_MAX_CHAN_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19();
    SC1(Base, ControlChanIdx) |= ADC_SC1_AIEN_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_DisableChannelNotification
* Description   : This function disables the notification for the selected channel.
*
* @implements     Adc_Ip_DisableChannelNotification_Activity
* END**************************************************************************/
void Adc_Ip_DisableChannelNotification(const uint32 Instance,
                                       const uint8 ControlChanIdx)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(ControlChanIdx < ADC_MAX_CHAN_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20();
    SC1(Base, ControlChanIdx) &= ~(ADC_SC1_AIEN_MASK);
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20();
}
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_ClearTrigErrReg
* Description   : This function clears all trigger error flags of the ADC instance.
*
* @implements     Adc_Ip_ClearTrigErrReg_Activity
* END**************************************************************************/
void Adc_Ip_ClearTrigErrReg(const uint32 Instance)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(Instance != 0u);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25();
    Base->SC2 |= ADC_SC2_TRGSTERR_MASK;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25();
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_GetTrigErrReg
* Description   : This function returns all trigger error flags of the ADC instance.
*
* @implements     Adc_Ip_GetTrigErrReg_Activity
* END**************************************************************************/
uint32 Adc_Ip_GetTrigErrReg(const uint32 Instance)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    DevAssert(Instance != 0u);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    const ADC_Type * const Base = Adc_Ip_apxBase[Instance];

    return (Base->SC2 & ADC_SC2_TRGSTERR_MASK) >> ADC_SC2_TRGSTERR_SHIFT;
}

/*FUNCTION*********************************************************************
 *
 * Function Name : Adc_Ip_GetDataAddress
 * Description   : Returns the address of the specified Rn register.
 *
 * @implements     Adc_Ip_GetDataAddress_Activity
 *END*************************************************************************/
uint32 Adc_Ip_GetDataAddress(const uint32 Instance,
                             const uint8 Index)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */
    return (uint32)&(R(Adc_Ip_apxBase[Instance], Index));
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_GetChanData
* Description   : This function retrieves the last conversion result for the
* selected input channel, by looking which control channel was configured
* with it. If multiple control channels are configured simultaneously with
* the same requested input channel, the result of the first control channel
* found will be returned. If no control channel is configured with the given
* input channel then ADC_IP_STATUS_ERROR will be returned.
* This function does no validity check on the result.
* In order to check if the result is valid, the user must call
* Adc_Ip_GetConvCompleteFlag function before this one.
*
* @implements     Adc_Ip_GetChanData_Activity
* END**************************************************************************/
Adc_Ip_StatusType Adc_Ip_GetChanData(const uint32 Instance,
                                     const Adc_Ip_InputChannelType Channel,
                                     uint16 * const Result)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
    DevAssert((Instance == 0u) || ((uint32)Channel < (uint32)ADC_IP_INPUTCHAN_SUPPLY_VDD));
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    const ADC_Type * const Base = Adc_Ip_apxBase[Instance];
    Adc_Ip_StatusType Status = ADC_IP_STATUS_SUCCESS;
    uint16 Temp = 0u;
    uint8 ControlChanIdx;
    boolean Found = FALSE;

    for (ControlChanIdx = 0u; ControlChanIdx < ADC_MAX_CHAN_COUNT; ControlChanIdx++)
    {
        if (Adc_Ip_axState[Instance].ChannelConfig[ControlChanIdx] == Channel)
        {
            Found = TRUE;
            break;
        }
    }

    if (Found == TRUE)
    {
        Temp = (uint16) R(Base, ControlChanIdx);
        Temp = (uint16) ((Temp & ADC_R_D_MASK) >> ADC_R_D_SHIFT);
    }
    else
    {
        Status = ADC_IP_STATUS_ERROR;
    }

    *Result = Temp;

    return Status;
}

#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_SetSoftwarePretrigger
* Description   : This function sets the software pretrigger source for
* an ADC instance.
*
* @implements     Adc_Ip_SetSoftwarePretrigger_Activity
* END**************************************************************************/
void Adc_Ip_SetSoftwarePretrigger(const uint32 Instance,
                                  const Adc_Ip_SoftwarePretriggerType SoftwarePretrigger)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
    /* If SW Pretrigger Select is not enabled, the SW pretriggers will be ignored by ADC. */
    DevAssert(Adc_Ip_axState[Instance].PretriggerSel == ADC_IP_PRETRIGGER_SEL_SW);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

#if (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call2params(Adc_Ip_SetSoftwarePretrigger_TrustedCall, Instance, (uint8)SoftwarePretrigger);
#else
    Adc_Ip_SetSoftwarePretrigger_TrustedCall(Instance, (uint8)SoftwarePretrigger);
#endif /* (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT) */
}
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */

/*FUNCTION*********************************************************************
 *
 * Function Name : Adc_Ip_IRQHandler
 * Description   : Handles Adc interrupts.
 * Note          : It's required to read result data in user notification in order to clear the COCO flags and avoid ISR getting invoked repeatedly
 *
 * @implements     Adc_Ip_IRQHandler_Activity
 *END*************************************************************************/
void Adc_Ip_IRQHandler(const uint32 Instance)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < ADC_INSTANCE_COUNT);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    uint8 ControlChanIdx;
#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
    uint32 Sc1Reg;
    boolean ChanIntFlag = FALSE;
    boolean ChanCocoFlag = FALSE;

    /* Check whether the respective driver is initialized */
    if (TRUE == Adc_Ip_axState[Instance].Init)
    {
        /* Check if the callback is not NULL since all channels use the same one (to avoid checking inside the loop) */
        if (Adc_Ip_axState[Instance].ConversionCompleteNotification != NULL_PTR)
        {
            for (ControlChanIdx = 0u; ControlChanIdx < ADC_MAX_CHAN_COUNT; ControlChanIdx++)
            {
                Sc1Reg = SC1(Adc_Ip_apxBase[Instance], ControlChanIdx);
                ChanIntFlag = Adc_HwAcc_GetAIEN(Sc1Reg);
                ChanCocoFlag = Adc_HwAcc_GetCOCO(Sc1Reg);
                /* CPR_RTD_00664
                 * Check if the interrupt not spurious (the interrupt is enabled and equivalent conversion has finished)
                 * Ignore spurious ones (return immediately from ISR)
                 */
                if ((TRUE == ChanIntFlag) && (TRUE == ChanCocoFlag))
                {
                    /* Call the associated callback.
                     * The COCO flag will be cleared by reading the respective result data register in the callback
                     */
                    Adc_Ip_axState[Instance].ConversionCompleteNotification(ControlChanIdx);
                }
            }
        }
    }
    else
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
    {
        /* CPR_RTD_00011 */
        for (ControlChanIdx = 0u; ControlChanIdx < ADC_MAX_CHAN_COUNT; ControlChanIdx++)
        {
            /* Do a dummy read to clear the COCO flags */
            (void)Adc_HwAcc_GetData(Adc_Ip_apxBase[Instance], ControlChanIdx);
        }
    }
}

#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
void Adc_Ip_SetSupplyMonitoringEnable_TrustedCall(const boolean SupplyEnable)
{
    /* Set or clear ADC_SUPPLY field of CHIPCTL register from SIM based on SupplyEnable */
    if (SupplyEnable == TRUE)
    {
        IP_SIM->CHIPCTL |= SIM_CHIPCTL_ADC_SUPPLYEN_MASK;
    }
    else
    {
        IP_SIM->CHIPCTL &= ~SIM_CHIPCTL_ADC_SUPPLYEN_MASK;
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : ADC_SetSupplyMonitoringEnable
* Description   : This function enable supply monitoring for the internal channels
* on SIM registers
*
* END**************************************************************************/
static void ADC_SetSupplyMonitoringEnable(const boolean SupplyEnable)
{
#if (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(Adc_Ip_SetSupplyMonitoringEnable_TrustedCall, SupplyEnable);
#else
    Adc_Ip_SetSupplyMonitoringEnable_TrustedCall(SupplyEnable);
#endif /* (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT) */
}

void Adc_Ip_ConfigSupplyMonitoringChannel_TrustedCall(const uint32 SupplyChannel)
{
#if (ADC_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((IP_SIM->CHIPCTL & SIM_CHIPCTL_ADC_SUPPLYEN_MASK) != 0UL);
#endif /* (ADC_IP_DEV_ERROR_DETECT == STD_ON) */

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_32();
    uint32 Reg = IP_SIM->CHIPCTL;
    Reg &= ~SIM_CHIPCTL_ADC_SUPPLY_MASK;
    Reg |= SIM_CHIPCTL_ADC_SUPPLY(SupplyChannel);
    IP_SIM->CHIPCTL = Reg;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_32();
}

/*FUNCTION**********************************************************************
*
* Function Name : ADC_ConfigSupplyMonitoringChannel
* Description   : This function configures the internal channels on on SIM registers
*
* END**************************************************************************/
static void ADC_ConfigSupplyMonitoringChannel(const uint32 SupplyChannel)
{
#if (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(Adc_Ip_ConfigSupplyMonitoringChannel_TrustedCall, SupplyChannel);
#else
    Adc_Ip_ConfigSupplyMonitoringChannel_TrustedCall(SupplyChannel);
#endif /* (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT) */
}

void Adc_Ip_ResetSupplyMonitoringChannel_TrustedCall(void)
{
    /* Clear ADC supply mask from CHIPCTL of SIM register */
    IP_SIM->CHIPCTL &= ~SIM_CHIPCTL_ADC_SUPPLY_MASK;
}

/*FUNCTION**********************************************************************
*
* Function Name : ADC_ResetSupplyMonitoringChannel
* Description   : This function resets the muxing for ADC channel on SIM register to reset value
*
* END**************************************************************************/
static void ADC_ResetSupplyMonitoringChannel(void)
{
#if (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call(Adc_Ip_ResetSupplyMonitoringChannel_TrustedCall);
#else
    Adc_Ip_ResetSupplyMonitoringChannel_TrustedCall();
#endif /* (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT) */
}
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */

#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
/*FUNCTION**********************************************************************
*
* Function Name : ADC_SetTriggerSourceSelect
* Description   : This function selects trigger source for an ADC instance
*
* END**************************************************************************/
static void ADC_SetTriggerSourceSelect(const uint32 Instance,
                                       const uint8 TriggerSource)
{
#if (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call2params(Adc_Ip_SetTriggerSourceSelect_TrustedCall, Instance, TriggerSource);
#else
    Adc_Ip_SetTriggerSourceSelect_TrustedCall(Instance, TriggerSource);
#endif /* (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT) */
}

void Adc_Ip_SetTriggerSourceSelect_TrustedCall(const uint32 Instance,
                                               const uint8 TriggerSource)
{
    uint32 Reg = (uint32)IP_SIM->ADCOPT;

#if (ADC_INSTANCE_COUNT > 1u)
    switch (Instance)
    {
        case 0u:
        {
#endif /* (ADC_INSTANCE_COUNT > 1u) */
            Reg &= ~SIM_ADCOPT_ADC0TRGSEL_MASK;
            Reg |= SIM_ADCOPT_ADC0TRGSEL(TriggerSource);
#if (ADC_INSTANCE_COUNT > 1u)
            break;
        }
        case 1u:
        {
            Reg &= ~SIM_ADCOPT_ADC1TRGSEL_MASK;
            Reg |= SIM_ADCOPT_ADC1TRGSEL(TriggerSource);
            break;
        }
        default:
        {
            ; /* no-op */
            break;
        }
    }
#else
    (void)Instance;
#endif /* (ADC_INSTANCE_COUNT > 1u) */
    IP_SIM->ADCOPT = Reg;
}

/*FUNCTION**********************************************************************
*
* Function Name : ADC_SetPretriggerSourceSelect
* Description   : This function selects pretrigger source for an ADC instance
*
* END**************************************************************************/
static void ADC_SetPretriggerSourceSelect(const uint32 Instance,
                                          const uint8 PretriggerSource)
{
#if (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call2params(Adc_Ip_SetPretriggerSourceSelect_TrustedCall, Instance, PretriggerSource);
#else
    Adc_Ip_SetPretriggerSourceSelect_TrustedCall(Instance, PretriggerSource);
#endif /* (STD_ON == ADC_IP_ENABLE_USER_MODE_SUPPORT) */
}

void Adc_Ip_SetPretriggerSourceSelect_TrustedCall(const uint32 Instance,
                                                  const uint8 PretriggerSource)
{
    uint32 Reg = (uint32)IP_SIM->ADCOPT;

#if (ADC_INSTANCE_COUNT > 1u)
    switch (Instance)
    {
        case 0u:
        {
#endif /* (ADC_INSTANCE_COUNT > 1u) */
            Reg &= ~SIM_ADCOPT_ADC0PRETRGSEL_MASK;
            Reg |= SIM_ADCOPT_ADC0PRETRGSEL(PretriggerSource);
#if (ADC_INSTANCE_COUNT > 1u)
            break;
        }
        case 1u:
        {
            Reg &= ~SIM_ADCOPT_ADC1PRETRGSEL_MASK;
            Reg |= SIM_ADCOPT_ADC1PRETRGSEL(PretriggerSource);
            break;
        }
        default:
        {
            ; /* no-op */
            break;
        }
    }
#else
    (void)Instance;
#endif /* (ADC_INSTANCE_COUNT > 1u) */
    IP_SIM->ADCOPT = Reg;
}

/*FUNCTION**********************************************************************
*
* Function Name : Adc_Ip_SetSoftwarePretrigger_TrustedCall
* Description   : This function writes the software pretrigger source to be
* configured for an ADC instance
*
* END**************************************************************************/
void Adc_Ip_SetSoftwarePretrigger_TrustedCall(const uint32 Instance,
                                              const uint8 SoftwarePretrigger)
{
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_31();
    uint32 Reg = (uint32)IP_SIM->ADCOPT;

#if (ADC_INSTANCE_COUNT > 1u)
    switch (Instance)
    {
        case 0u:
        {
#endif /* (ADC_INSTANCE_COUNT > 1u) */
            Reg &= ~SIM_ADCOPT_ADC0SWPRETRG_MASK;
            Reg |= SIM_ADCOPT_ADC0SWPRETRG(SoftwarePretrigger);
#if (ADC_INSTANCE_COUNT > 1u)
            break;
        }
        case 1u:
        {
            Reg &= ~SIM_ADCOPT_ADC1SWPRETRG_MASK;
            Reg |= SIM_ADCOPT_ADC1SWPRETRG(SoftwarePretrigger);
            break;
        }
        default:
        {
            ; /* no-op */
            break;
        }
    }
#else
    (void)Instance;
#endif /* (ADC_INSTANCE_COUNT > 1u) */
    IP_SIM->ADCOPT = Reg;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_31();
}
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
