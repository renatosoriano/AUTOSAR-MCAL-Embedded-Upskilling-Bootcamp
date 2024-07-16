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

#ifndef ADC_IP_HW_ACCESS_H
#define ADC_IP_HW_ACCESS_H

/**
*   @file
*
*   @internal
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
#include "StandardTypes.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID_HWACCESS                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_HWACCESS       7
#define ADC_IP_AR_RELEASE_REVISION_VERSION_HWACCESS    0
#define ADC_IP_SW_MAJOR_VERSION_HWACCESS               2
#define ADC_IP_SW_MINOR_VERSION_HWACCESS               0
#define ADC_IP_SW_PATCH_VERSION_HWACCESS               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Ip_HwAccess.h file and StandardTypes.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_HWACCESS != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Ip_HwAccess.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
                                     FUNCTION DEFINITIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

static inline void Adc_HwAcc_SetSC2Reg(ADC_Type * const Base,
                                       const uint32 ClearMask,
                                       const uint32 Value)
{
    /* Clear and set SC2 register based on ClearMask and Value */
    uint32 Sc2Reg = Base->SC2;
    Sc2Reg &= ~(ClearMask);
    Sc2Reg |= Value;
    Base->SC2 = Sc2Reg;
}

static inline void Adc_HwAcc_SetClock(ADC_Type * const Base,
                                      const Adc_Ip_ClockSelType ClockDivide,
                                      const Adc_Ip_ClkSourceType InputClock)
{
    /* Update ClockDivide and InputClock values found in CFG1 register */
    uint32 Cfg1Reg = Base->CFG1;
    Cfg1Reg &= ~(ADC_CFG1_ADIV_MASK | ADC_CFG1_ADICLK_MASK);
    Cfg1Reg |= ADC_CFG1_ADIV(ClockDivide);
    Cfg1Reg |= ADC_CFG1_ADICLK(InputClock);
    Base->CFG1 = Cfg1Reg;
}

static inline Adc_Ip_ClockSelType Adc_HwAcc_GetClockDivide(const uint32 Reg)
{
    /*
     * Retrieve ClockDivide value found in CFG1 register
     * Note: Reg should be the value of CFG1 register
     */
    Adc_Ip_ClockSelType ReturnValue = ADC_IP_CLK_FULL_BUS;
    switch ((Reg & ADC_CFG1_ADIV_MASK) >> ADC_CFG1_ADIV_SHIFT)
    {
        case 1u:
            ReturnValue = ADC_IP_CLK_HALF_BUS;
            break;
        case 2u:
            ReturnValue = ADC_IP_CLK_QUARTER_BUS;
            break;
        case 3u:
            ReturnValue = ADC_IP_CLK_EIGHTH_BUS;
            break;
        default:
            ; /* no-op */
            break;
    }
    return ReturnValue;
}

static inline Adc_Ip_ClkSourceType Adc_HwAcc_GetInputClock(const uint32 Reg)
{
    /*
     * Retrieve InputClock value found in CFG1 register
     * Note: Reg should be the value of CFG1 register
     */
    Adc_Ip_ClkSourceType ReturnValue = ADC_IP_CLK_ALT_1;
    switch ((Reg & ADC_CFG1_ADICLK_MASK) >> ADC_CFG1_ADICLK_SHIFT)
    {
        case 1u:
            ReturnValue = ADC_IP_CLK_ALT_2;
            break;
        case 2u:
            ReturnValue = ADC_IP_CLK_ALT_3;
            break;
        case 3u:
            ReturnValue = ADC_IP_CLK_ALT_4;
            break;
        default:
            ; /* no-op */
            break;
    }
    return ReturnValue;
}

static inline void Adc_HwAcc_SetSampleTime(ADC_Type * const Base,
                                           const uint8 SampleTime)
{
    /* Clip sample time to minimum value */
    uint8 ClippedSampleTime = (uint8)((SampleTime > 0U) ? SampleTime : 1U);
    /* Update SampleTime values found in SC3 register */
    uint32 Cfg2Reg = Base->CFG2;
    Cfg2Reg &= ~(ADC_CFG2_SMPLTS_MASK);
    Cfg2Reg |= ADC_CFG2_SMPLTS(ClippedSampleTime);
    Base->CFG2 = Cfg2Reg;
}

static inline void Adc_HwAcc_SetAveraging(ADC_Type * const Base,
                                          const boolean AvgEn,
                                          const Adc_Ip_AvgSelectType AvgSel)
{
    /* Update AvgEn and AvgSel values found in SC3 register */
    uint32 Sc3Reg = Base->SC3;
    Sc3Reg &= ~(ADC_SC3_AVGE_MASK | ADC_SC3_AVGS_MASK);
    Sc3Reg |= ADC_SC3_AVGE(AvgEn ? 1u : 0u);
    Sc3Reg |= ADC_SC3_AVGS(AvgSel);
    Base->SC3 = Sc3Reg;
}

static inline Adc_Ip_AvgSelectType Adc_HwAcc_GetAverageSelect(const uint32 Reg)
{
    /*
     * Retrieve AvgSelect value found in SC3 register
     * Note: Reg should be the value of SC3 register
     */
    Adc_Ip_AvgSelectType ReturnValue = ADC_IP_AVG_4_CONV;
    switch ((Reg & ADC_SC3_AVGS_MASK) >> ADC_SC3_AVGS_SHIFT)
    {
        case 1u:
            ReturnValue = ADC_IP_AVG_8_CONV;
            break;
        case 2u:
            ReturnValue = ADC_IP_AVG_16_CONV;
            break;
        case 3u:
            ReturnValue = ADC_IP_AVG_32_CONV;
            break;
        default:
            ; /* no-op */
            break;
    }
    return ReturnValue;
}

static inline void Adc_HwAcc_SetTriggerMode(ADC_Type * const Base,
                                            const Adc_Ip_TrigType TriggerMode)
{
    /* Update TriggerMode value found in SC2 register */
    uint32 Sc2Reg = Base->SC2;
    Sc2Reg &= ~(ADC_SC2_ADTRG_MASK);
    Sc2Reg |= ADC_SC2_ADTRG(TriggerMode);
    Base->SC2 = Sc2Reg;
}

static inline Adc_Ip_TrigType Adc_HwAcc_GetTriggerMode(const uint32 Reg)
{
    /* Retrieve TriggerMode value found in SC2 register */
    Adc_Ip_TrigType ReturnValue = ADC_IP_TRIGGER_SOFTWARE;
    if (((Reg & ADC_SC2_ADTRG_MASK) >> ADC_SC2_ADTRG_SHIFT) == 1u)
    {
        ReturnValue = ADC_IP_TRIGGER_HARDWARE;
    }
    return ReturnValue;
}

static inline void Adc_HwAcc_SetChannel(ADC_Type * const Base,
                                        const uint8 ChnIdx,
                                        const Adc_Ip_InputChannelType InputChannel,
                                        const boolean InterruptEnable)
{
    /* Configure channel by writing all SC1n register fields */
    uint32 Sc1Reg = SC1(Base, ChnIdx);
    Sc1Reg &= ~(ADC_SC1_ADCH_MASK | ADC_SC1_AIEN_MASK);
    Sc1Reg |= ADC_SC1_ADCH(InputChannel);
    Sc1Reg |= ADC_SC1_AIEN(InterruptEnable ? 1u : 0u);
    SC1(Base, ChnIdx) = Sc1Reg;
}

static inline void Adc_HwAcc_SetUserGainAndOffset(ADC_Type * const Base,
                                                  const uint16 UsrGain,
                                                  const uint16 UsrOffset)
{
    /*
     * Currently, user gain and user offset values are set at config time.
     * If user gain is to be changed at runtime (e.g. after a calibration was
     * already executed) then the G register should also be updated.
     * To calculate the new value of this register, it is necessary execute
     * the following algorithm:
     * 1. Sum <- UsrGain + Clp0 + Clp1 + Clp2 + Clp3 + ClpS
     * 2. RegVal <- Sum & 0xF800U
     * 3. if RegVal != 0x0000U then RegVal <- 0xFFFFU
     * 4. Base->G <- RegVal
     */

    Base->USR_OFS = ADC_USR_OFS_USR_OFS(UsrOffset);
    Base->UG = ADC_UG_UG(UsrGain);
}

#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
static inline boolean Adc_HwAcc_GetAIEN(const uint32 Reg)
{
    /* Retrive AIEN flag from given SC1 register */
    return (((Reg & ADC_SC1_AIEN_MASK) >> ADC_SC1_AIEN_SHIFT) != 0u) ? TRUE : FALSE;
}
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */

static inline boolean Adc_HwAcc_GetCOCO(const uint32 Reg)
{
    /* Retrive COCO flag from given SC1 register */
    return (((Reg & ADC_SC1_COCO_MASK) >> ADC_SC1_COCO_SHIFT) != 0u) ? TRUE : FALSE;
}

static inline uint16 Adc_HwAcc_GetData(const ADC_Type * const Base,
                                       const uint8 ChnIdx)
{
    /* Retrieve the conversion result of a given channel */
    uint16 Result = (uint16) R(Base, ChnIdx);
    Result = (uint16) ((Result & ADC_R_D_MASK) >> ADC_R_D_SHIFT);
    return Result;
}

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IP_HW_ACCESS_H */
