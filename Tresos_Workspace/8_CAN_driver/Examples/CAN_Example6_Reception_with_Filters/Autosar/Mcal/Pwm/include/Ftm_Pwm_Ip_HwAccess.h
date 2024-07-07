/*==================================================================================================
* Project              : RTD AUTOSAR 4.7
* Platform             : CORTEXM
* Peripheral           : Ftm Flexio
* Dependencies         : none
*
* Autosar Version      : 4.7.0
* Autosar Revision     : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version           : 2.0.0
* Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef FTM_PWM_IP_HWACCESS_H
#define FTM_PWM_IP_HWACCESS_H

/**
*   @file       Ftm_Pwm_Ip_HwAccess.h
*
*   @internal
*   @addtogroup ftm_pwm_ip Ftm Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Std_Types.h"
#include "Ftm_Pwm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_PWM_IP_HWACCESS_VENDOR_ID                    43
#define FTM_PWM_IP_HWACCESS_MODULE_ID                    121
#define FTM_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION     4
#define FTM_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION     7
#define FTM_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION  0
#define FTM_PWM_IP_HWACCESS_SW_MAJOR_VERSION             2
#define FTM_PWM_IP_HWACCESS_SW_MINOR_VERSION             0
#define FTM_PWM_IP_HWACCESS_SW_PATCH_VERSION             0


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_HwAccess.h and Std_Types.h are different."
    #endif
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (FTM_PWM_IP_HWACCESS_VENDOR_ID != FTM_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_HwAccess.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_HwAccess.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((FTM_PWM_IP_HWACCESS_SW_MAJOR_VERSION != FTM_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_HWACCESS_SW_MINOR_VERSION != FTM_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_HWACCESS_SW_PATCH_VERSION != FTM_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_HwAccess.h and Ftm_Pwm_Ip_Cfg.h are different."
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
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/*! @brief Arrays of base addresses for FTM instances. */
extern Ftm_Pwm_Ip_HwAddrType * const Ftm_Pwm_Ip_aFtmBase[FTM_PWM_IP_IRQS_ARR_COUNT];

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTION
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/*!
 * @brief Sets the FTM clock divider.
 *
 * @param[in] FtmBase    The FTM base address pointer
 * @param[in] Prescaler  The FTM peripheral clock pre-scale divider
 */
static inline void Ftm_Pwm_Ip_SetClockPs(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                         Ftm_Pwm_Ip_ClkPrescalerType   Prescaler)
{
    FtmBase->SC = (FtmBase->SC & ~FTM_SC_PS_MASK) | FTM_SC_PS(Prescaler);
}

/*!
 * @brief Reads the FTM clock divider.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return The FTM clock pre-scale divider
 */
static inline uint8 Ftm_Pwm_Ip_GetClockPs(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint8)((FtmBase->SC & FTM_SC_PS_MASK) >> FTM_SC_PS_SHIFT);
}

/*!
 * @brief Sets the FTM clock source.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] ClockSrc The FTM peripheral clock selection
 *            - 00: No clock
 *            - 01: System clock
 *            - 10: Fixed clock
 *            - 11: External clock
 */
static inline void Ftm_Pwm_Ip_SetClockSource(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                             Ftm_Pwm_Ip_ClkSourceType      ClockSrc)
{
    FtmBase->SC = (FtmBase->SC & ~FTM_SC_CLKS_MASK) | FTM_SC_CLKS(ClockSrc);
}

/*!
 * @brief Reads the FTM clock source. The intent of this function is only gotten
 * the clock source which used in FTM counter.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return The FTM clock source selection
 *          - 00: No clock
 *          - 01: System clock
 *          - 10: Fixed clock
 *          - 11: External clock
 */
static inline uint8 Ftm_Pwm_Ip_GetClockSource(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint8)((FtmBase->SC & FTM_SC_CLKS_MASK) >> FTM_SC_CLKS_SHIFT);
}

/*!
 * @brief Sets the FTM count direction bit.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Mode     The Center-Aligned PWM selection
 *                     - 0U: Up counting mode
 *                     - 1U: Up down counting mode
 */
static inline void Ftm_Pwm_Ip_SetCpwms(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                       boolean                       Mode)
{
    FtmBase->SC = (FtmBase->SC & ~FTM_SC_CPWMS_MASK) | FTM_SC_CPWMS((Mode == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Gets the FTM count direction bit.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return The Center-Aligned PWM selection
 *         - 0U: Up counting mode
 *         - 1U: Up down counting mode
 */
static inline Ftm_Pwm_Ip_CounterModeType Ftm_Pwm_Ip_GetCpwms(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return  (((FtmBase->SC & FTM_SC_CPWMS_MASK) >> FTM_SC_CPWMS_SHIFT) == 0U)? FTM_PWM_IP_EDGE_ALIGNED : FTM_PWM_IP_CENTER_ALIGNED;
}

#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
/*!
 * @brief Set the FTM reload interrupt enable.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Enable - TRUE : Reload interrupt is  enabled
 *                   - FALSE: Reload interrupt is disabled
 */
static inline void Ftm_Pwm_Ip_SetReIntEnabledCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                 boolean                       Enable)
{
    FtmBase->SC = (FtmBase->SC & ~FTM_SC_RIE_MASK) | FTM_SC_RIE((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Return TRUE/FALSE whether the reload interrupt was enabled or not
 *
 * @param[in] FtmBase The FTM base address pointer
 */
static inline boolean Ftm_Pwm_Ip_IsReloadIntEnabled(const Ftm_Pwm_Ip_HwAddrType * FtmBase)
{
    return ((FtmBase->SC & FTM_SC_RIE_MASK) >> FTM_SC_RIE_SHIFT) != 0U;
}

/*!
 * @brief Get the state whether the FTM counter reached a reload point.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return State of reload point
 *         - TRUE : FTM counter reached a reload point
 *         - FALSE: FTM counter did not reach a reload point
 */
static inline boolean Ftm_Pwm_Ip_GetReloadFlag(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return ((FtmBase->SC & FTM_SC_RF_MASK) >> FTM_SC_RF_SHIFT) != 0U;
}

/*!
 * @brief Clears the reload flag bit.
 *
 * @param[in] FtmBase The FTM base address pointer
 */
static inline void Ftm_Pwm_Ip_ClearReloadFlag(Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    FtmBase->SC = (FtmBase->SC & ~FTM_SC_RF_MASK) | FTM_SC_RF(0U);
#ifdef ERRATA_E9005
    /* Read-after-write sequence to guarantee required serialization of memory operations */
    FtmBase->SC;
#endif
}
#endif

/*!
 * @brief  Enables the FTM peripheral timer overflow interrupt.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] State - TRUE : Overflow interrupt enabled
 *                  - FALSE: Overflow interrupt disabled
 */
static inline void Ftm_Pwm_Ip_SetTimerOverflowInt(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  boolean                       State)
{
    FtmBase->SC = (FtmBase->SC & ~FTM_SC_TOIE_MASK) | FTM_SC_TOIE((State == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Reads the bit that controls enabling the FTM timer overflow interrupt.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return State of Timer Overflow Interrupt
 *         - TRUE : Overflow interrupt is enabled
 *         - FALSE: Overflow interrupt is disabled
 */
static inline boolean Ftm_Pwm_Ip_IsOverflowIntEnabled(const Ftm_Pwm_Ip_HwAddrType * FtmBase)
{
    return ((FtmBase->SC & FTM_SC_TOIE_MASK) >> FTM_SC_TOIE_SHIFT) != 0U;
}

/*!
 * @brief Returns the FTM peripheral timer overflow interrupt flag.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return State of Timer Overflow Flag
 *         - TRUE : FTM counter has overflowed
 *         - FALSE: FTM counter has not overflowed
 */
static inline boolean Ftm_Pwm_Ip_GetTimerOverflow(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return ((FtmBase->SC & FTM_SC_TOF_MASK) >> FTM_SC_TOF_SHIFT) != 0U;
}

/*!
 * @brief Clears the timer overflow interrupt flag.
 *
 * @param[in] FtmBase The FTM base address pointer
 */
static inline void Ftm_Pwm_Ip_ClearTimerOverflow(Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    FtmBase->SC = (FtmBase->SC & ~FTM_SC_TOF_MASK) | FTM_SC_TOF(0U);
#ifdef ERRATA_E9005
    /* Read-after-write sequence to guarantee required serialization of memory operations */
    FtmBase->SC;
#endif
}

#if (defined(FTM_PWM_IP_HAS_CHANNEL_PWM_ENABLE) && (FTM_PWM_IP_HAS_CHANNEL_PWM_ENABLE == STD_ON))
/*!
 * @brief Enable PWM channel Outputs.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM channel

 */
static inline void Ftm_Pwm_Ip_EnablePwmChannelOutputs(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                      uint8                         Channel)
{
    FtmBase->SC = (FtmBase->SC & ~(1UL << (Channel + FTM_SC_PWMEN0_SHIFT))) | (1UL << (Channel + FTM_SC_PWMEN0_SHIFT));
}

/*!
 * @brief Disable PWM channel Outputs.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM channel
 */
static inline void Ftm_Pwm_Ip_DisablePwmChannelOutputs(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                       uint8                         Channel)
{
    uint32 RegValue = FtmBase->SC;
    RegValue = RegValue & (~(1UL << (Channel + FTM_SC_PWMEN0_SHIFT)));
    FtmBase->SC = RegValue;
}
#endif

/* FTM Counter (CNT) */

/*!
 * @brief Sets the FTM peripheral current counter value.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Value    The FTM timer counter value to be set
 */
static inline void Ftm_Pwm_Ip_SetCounter(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                         uint16                        Value)
{
    FtmBase->CNT = (FtmBase->CNT & ~FTM_CNT_COUNT_MASK) | FTM_CNT_COUNT(Value);
}

/*!
 * @brief Returns the FTM peripheral current counter value.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return The current FTM timer counter value
 *
 * Implements : Ftm_Pwm_Ip_GetCounter_Activity
 */
static inline uint16 Ftm_Pwm_Ip_GetCounter(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint16)((FtmBase->CNT & FTM_CNT_COUNT_MASK) >> FTM_CNT_COUNT_SHIFT);
}

/* FTM Modulo (MOD) */

/*!
 * @brief Sets the FTM peripheral timer modulo value.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Value    The value to be set to the timer modulo
 */
static inline void Ftm_Pwm_Ip_SetMod(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                     uint16                        Value)
{
    FtmBase->MOD = (FtmBase->MOD & ~FTM_MOD_MOD_MASK) | FTM_MOD_MOD(Value);
}

/*!
 * @brief Returns the FTM peripheral counter modulo value.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return FTM timer modulo value
 *
 * Implements : Ftm_Pwm_Ip_GetMod_Activity
 */
static inline uint16 Ftm_Pwm_Ip_GetMod(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint16)((FtmBase->MOD & FTM_MOD_MOD_MASK) >> FTM_MOD_MOD_SHIFT);
}

/* FTM Channel Status and Control (CnSC) */

/*!
 * @brief Enables or disables the FTM peripheral timer channel DMA.
 * @Note: The channel DMA transfer request is not available on S32S247 platform.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Channel  The FTM peripheral channel number
 * @param[in] Enable   Enable DMA transfers for the channel
 *                     - TRUE : Enabled DMA transfers
 *                     - FALSE: Disabled DMA transfers
 *
 * Implements : Ftm_Pwm_Ip_SetChnDmaCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetChnDmaCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                           uint8                         Channel,
                                           boolean                       Enable)
{
    /* Write DMA bit */
    FtmBase->CONTROLS[Channel].CSC = (FtmBase->CONTROLS[Channel].CSC & ~FTM_CSC_DMA_MASK) | FTM_CSC_DMA((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Returns whether the FTM peripheral timer channel DMA is enabled.
 * @Note: The channel DMA transfer request is not available on S32S247 platform.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Channel  The FTM peripheral channel number
 * @return State of the FTM peripheral timer channel DMA
 *         - TRUE : Enabled DMA transfers
 *         - FALSE: Disabled DMA transfers
 *
 * Implements : Ftm_Pwm_Ip_IsChnDma_Activity
 */
static inline boolean Ftm_Pwm_Ip_IsChnDma(const Ftm_Pwm_Ip_HwAddrType * FtmBase,
                                          uint8                         Channel)
{
    return (FtmBase->CONTROLS[Channel].CSC & FTM_CSC_DMA_MASK) != 0U;
}

/*!
 * @brief Gets the FTM peripheral timer channel edge level.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 *
 * @return The ELSnB:ELSnA mode value, will be 00, 01, 10, 11
 *
 * Implements : Ftm_Pwm_Ip_GetChnEdgeLevel_Activity
 */
static inline uint8 Ftm_Pwm_Ip_GetChnEdgeLevel(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               uint8                               Channel)
{
    uint8 RetValue;

    RetValue = (uint8)((FtmBase->CONTROLS[Channel].CSC & FTM_CSC_ELSA_MASK) >> FTM_CSC_ELSA_SHIFT);

    RetValue |= (uint8)(((FtmBase->CONTROLS[Channel].CSC & FTM_CSC_ELSB_MASK) >> FTM_CSC_ELSB_SHIFT) << 1U);

    return RetValue;
}

/*!
 * @brief Sets the FTM peripheral timer channel edge level.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Channel  The FTM peripheral channel number
 * @param[in] Level    ELSnB:ELSnA :00, 01, 10, 11
 */
static inline void Ftm_Pwm_Ip_SetChnEdgeLevel(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                              uint8                         Channel,
                                              Ftm_Pwm_Ip_ChannelModeType    Level)
{
    uint32 LevelA = (uint32)(((uint32)(Level) << FTM_CSC_ELSA_SHIFT) & FTM_CSC_ELSA_MASK);

    uint32 LevelB = (uint32)(((uint32)(Level) << FTM_CSC_ELSA_SHIFT) & FTM_CSC_ELSB_MASK);

    /* write ELSA bit */
    FtmBase->CONTROLS[Channel].CSC = (FtmBase->CONTROLS[Channel].CSC & ~FTM_CSC_ELSA_MASK) | LevelA;

    /* write ELSB bit */
    FtmBase->CONTROLS[Channel].CSC = (FtmBase->CONTROLS[Channel].CSC & ~FTM_CSC_ELSB_MASK) | LevelB;
}

/*!
 * @brief Sets the FTM peripheral timer channel mode.
 *
 * @param[in] FtmBase    The FTM base address pointer
 * @param[in] Channel    The FTM peripheral channel number
 * @param[in] Selection  The mode to be set valid value MSnB:MSnA :00, 01, 10, 11
 */
static inline void Ftm_Pwm_Ip_SetChnMSBAMode(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                             uint8                         Channel,
                                             Ftm_Pwm_Ip_ChannelModeType    Selection)
{
    uint32 SelectionA = (uint32)(((uint32)(Selection) << FTM_CSC_ELSA_SHIFT) & FTM_CSC_MSA_MASK);

    uint32 SelectionB = (uint32)(((uint32)(Selection) << FTM_CSC_ELSA_SHIFT) & FTM_CSC_MSB_MASK);

    /* write MSA bit */
    FtmBase->CONTROLS[Channel].CSC = (FtmBase->CONTROLS[Channel].CSC & ~FTM_CSC_MSA_MASK) | SelectionA;

    /* write MSB bit */
    FtmBase->CONTROLS[Channel].CSC = (FtmBase->CONTROLS[Channel].CSC & ~FTM_CSC_MSB_MASK) | SelectionB;
}

/*!
 * @brief Gets the FTM peripheral timer channel mode.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 *
 * @return The MSnB:MSnA mode value, will be 00, 01, 10, 11
 *
 */
static inline uint8 Ftm_Pwm_Ip_GetChnMode(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                          uint8                               Channel)
{
    uint8 RetValue;

    RetValue = (uint8)(((FtmBase->CONTROLS[Channel].CSC) & FTM_CSC_MSA_MASK) >> FTM_CSC_MSA_SHIFT);

    RetValue |= (uint8)((((FtmBase->CONTROLS[Channel].CSC) & FTM_CSC_MSB_MASK) >> FTM_CSC_MSB_SHIFT) << 1U);

    return RetValue;
}

/*!
 * @brief Enable/Disable the FTM peripheral timer channel(n) interrupt.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 * @param[in] Enable  Enable or Disable the FTM peripheral timer channel(n) interrupt.
 */
static inline void Ftm_Pwm_Ip_UpdateChnInt(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                           uint8                         Channel,
                                           boolean                       Enable)
{
    FtmBase->CONTROLS[Channel].CSC = (FtmBase->CONTROLS[Channel].CSC & ~FTM_CSC_CHIE_MASK) | FTM_CSC_CHIE((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Get FTM channel(n) interrupt enabled or not.
 * @param[in] FtmBase FTM module base address
 * @param[in] Channel The FTM peripheral channel number
 */
static inline boolean Ftm_Pwm_Ip_IsChnIntEnabled(const Ftm_Pwm_Ip_HwAddrType * FtmBase,
                                                 uint8                         Channel)
{
    return (FtmBase->CONTROLS[Channel].CSC & FTM_CSC_CHIE_MASK) != 0U;
}

/*!
 * @brief Clear the channel flag by writing a 0 to the CHF bit.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 */
static inline void Ftm_Pwm_Ip_ClearChnEventFlag(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                uint8                         Channel)
{
    FtmBase->CONTROLS[Channel].CSC = (FtmBase->CONTROLS[Channel].CSC & ~FTM_CSC_CHF_MASK) | FTM_CSC_CHF(0U);
#ifdef ERRATA_E9005
    /* Read-after-write sequence to guarantee required serialization of memory operations */
    FtmBase->CONTROLS[Channel].CSC;
#endif
}

/*!
 * @brief Returns whether any event for the FTM peripheral timer channel has occurred.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 *
 * @return State of channel flag
 *         - TRUE : Event occurred
 *         - FALSE: No event occurred.
 */
static inline boolean Ftm_Pwm_Ip_HasChnEventOccurred(const Ftm_Pwm_Ip_HwAddrType * FtmBase,
                                                     uint8                         Channel)
{
    return (FtmBase->CONTROLS[Channel].CSC & FTM_CSC_CHF_MASK) != 0U;
}

/*!
 * @brief Get the value of channel output.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 * @return Value of the channel outputs
 *         - TRUE : The channel output is one
 *         - FALSE: The channel output is zero
 *
 * Implements : Ftm_Pwm_Ip_GetChOutputValue_Activity
 */
static inline boolean Ftm_Pwm_Ip_GetChOutputValue(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  uint8                               Channel)
{
    return (FtmBase->CONTROLS[Channel].CSC & FTM_CSC_CHOV_MASK) != 0U;
}

/* FTM Channel Value (CnV) */

/*!
 * @brief Sets the FTM peripheral timer channel counter value.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 * @param[in] Value Counter value to be set
 */
static inline void Ftm_Pwm_Ip_SetChnCountVal(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                             uint8                         Channel,
                                             uint16                        Value)
{
    FtmBase->CONTROLS[Channel].CV = Value;
}

/*!
 * @brief Gets the FTM peripheral timer channel counter value.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 *
 * @return Channel counter value
 *
 * Implements : Ftm_Pwm_Ip_GetChnCountVal_Activity
 */
static inline uint16 Ftm_Pwm_Ip_GetChnCountVal(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               uint8                               Channel)
{
    return (uint16)(FtmBase->CONTROLS[Channel].CV);
}

/* FTM Counter Initial Value (CNTIN) */

/*!
 * @brief Sets the FTM peripheral timer counter initial value.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Value    Initial value to be set
 */
static inline void Ftm_Pwm_Ip_SetCounterInitVal(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                uint16                        Value)
{
    FtmBase->CNTIN = (FtmBase->CNTIN & ~FTM_CNTIN_INIT_MASK) | FTM_CNTIN_INIT(Value);
}

/*!
 * @brief Returns the FTM peripheral counter initial value.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return FTM timer counter initial value
 *
 * Implements : Ftm_Pwm_Ip_GetCounterInitVal_Activity
 */
static inline uint16 Ftm_Pwm_Ip_GetCounterInitVal(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint16)((FtmBase->CNTIN & FTM_CNTIN_INIT_MASK) >> FTM_CNTIN_INIT_SHIFT);
}

/* FTM Capture And Compare Status (STATUS) */

/*!
 * @brief Gets the FTM peripheral timer channel event status.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 *
 * @return Channel event status
 *         - TRUE  : A channel event has occurred
 *         - FALSE : No channel event has occurred
 *
 * Implements : Ftm_Pwm_Ip_GetChnEventStatus_Activity
 */
static inline boolean Ftm_Pwm_Ip_GetChnEventStatus(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                   uint8                               Channel)
{
    return (FtmBase->STATUS & (1UL << Channel)) != 0U;
}

/*!
 * @brief Clears the FTM peripheral timer all channel event status.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 *
 * Implements : Ftm_Pwm_Ip_ClearChnEventStatus_Activity
 */
static inline void Ftm_Pwm_Ip_ClearChnEventStatus(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  uint8                         Channel)
{
    FtmBase->STATUS &= ~(1UL << Channel);
#ifdef ERRATA_E9005
    /* Read-after-write sequence to guarantee required serialization of memory operations */
    FtmBase->STATUS;
#endif
}

/* FTM Features Mode Selection (MODE) */

/*!
 * @brief Enables the FTM peripheral timer group.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   FTM mode selection
 *                     - TRUE : All registers including FTM-specific registers are available
 *                     - FALSE: Only the TPM-compatible registers are available
 */
static inline void Ftm_Pwm_Ip_Enable(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                     boolean                       Enable)
{
    FtmBase->MODE = (FtmBase->MODE & ~FTM_MODE_FTMEN_MASK) | FTM_MODE_FTMEN((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Get status of the FTMEN bit in the FTM_MODE register.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return The FTM Enable status
 *         - TRUE : TPM compatibility. Free running counter and synchronization compatible with TPM
 *         - FALSE: Free running counter and synchronization are different from TPM behavior
 *
 * Implements : Ftm_Pwm_Ip_IsFtmEnable_Activity
 */
static inline boolean Ftm_Pwm_Ip_IsFtmEnable(const Ftm_Pwm_Ip_HwAddrType * FtmBase)
{
    return ((FtmBase->MODE & FTM_MODE_FTMEN_MASK) >> FTM_MODE_FTMEN_SHIFT) != 0U;
}

/*!
 * @brief Initializes the channels output.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   Initialize the channels output
 *                     - TRUE : The channels output is initialized according to the state of OUTINIT reg
 *                     - FALSE: No effect
 */
static inline void Ftm_Pwm_Ip_SetInitChnOutputCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  boolean                       Enable)
{
    FtmBase->MODE = (FtmBase->MODE & ~FTM_MODE_INIT_MASK) | FTM_MODE_INIT((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets the FTM peripheral timer sync mode.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   PWM synchronization mode
 *                     - FALSE: No restriction both software and hardware triggers can be used
 *                     - TRUE : Software trigger can only be used for MOD and CV synchronization,
 *                            hardware trigger only for OUTMASK and FTM counter synchronization.
 */
static inline void Ftm_Pwm_Ip_SetPwmSyncMode(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                             boolean                       Enable)
{
    FtmBase->MODE = (FtmBase->MODE & ~FTM_MODE_PWMSYNC_MASK) | FTM_MODE_PWMSYNC((Enable == TRUE) ? 0x01U : 0x00U);
}

/* FTM Synchronization (SYNC) */

/*!
 * @brief Enables or disables the FTM peripheral timer minimum loading points.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   Minimum loading point selection
 *                     - TRUE : To enable minimum loading point
 *                     - FALSE: To disable
 */
static inline void Ftm_Pwm_Ip_SetMinLoadingCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               boolean                       Enable)
{
    FtmBase->SYNC = (FtmBase->SYNC & ~FTM_SYNC_CNTMIN_MASK) | FTM_SYNC_CNTMIN((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Enables or disables the FTM peripheral timer maximum loading points.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   Maximum loading point selection
 *                     - TRUE : To enable maximum loading point
 *                     - FALSE: To disable
 */
static inline void Ftm_Pwm_Ip_SetMaxLoadingCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               boolean                       Enable)
{
    FtmBase->SYNC = (FtmBase->SYNC & ~FTM_SYNC_CNTMAX_MASK) | FTM_SYNC_CNTMAX((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Determines if the FTM counter is re-initialized when the selected trigger for
 * synchronization is detected.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   FTM counter re-initialization selection
 *                     - TRUE : To update FTM counter when triggered
 *                     - FALSE: To count normally
 *
 * Implements : Ftm_Pwm_Ip_SetCountReinitSyncCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetCountReinitSyncCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                    boolean                       Enable)
{
    FtmBase->SYNC = (FtmBase->SYNC & ~FTM_SYNC_REINIT_MASK) | FTM_SYNC_REINIT((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Determines when the OUTMASK register is updated with the value of its buffer.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   Output Mask synchronization selection
 *                     - TRUE : OUTMASK register is updated only by PWM synchronization
 *                     - FALSE: OUTMASK register is updated in all rising edges of the system clock
 */
static inline void Ftm_Pwm_Ip_SetOutmaskPwmSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                       boolean                       Enable)
{
    FtmBase->SYNC = (FtmBase->SYNC & ~FTM_SYNC_SYNCHOM_MASK) | FTM_SYNC_SYNCHOM((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets the FTM hardware synchronization trigger.
 *
 * @param[in] FtmBase        The FTM base address pointer
 * @param[in] TriggerNumber  Number of trigger
 *                           - 0U: trigger 0
 *                           - 1U: trigger 1
 *                           - 2U: trigger 2
 * @param[in] Enable         State of trigger
 *                           - TRUE : Enable hardware trigger from field TriggerNumber for PWM synchronization
 *                           - FALSE: Disable hardware trigger from field TriggerNumber for PWM synchronization
 */
static inline void Ftm_Pwm_Ip_SetHardwareSyncTriggerSrc(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                        uint8                         TriggerNumber,
                                                        boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->SYNC |= (uint32)FTM_SYNC_TRIG0_MASK << TriggerNumber;
    }
    else
    {
        FtmBase->SYNC &= ~((uint32)FTM_SYNC_TRIG0_MASK << TriggerNumber);
    }
}

/*!
 * @brief Enables or disables the FTM peripheral timer software trigger.
 *
 * @param[in] FtmBase  The FTM base address pointer.
 * @param[in] Enable   Software trigger selection
 *                     - TRUE : Software trigger is selected
 *                     - FALSE: Software trigger is not selected
 */
static inline void Ftm_Pwm_Ip_SetSoftwareTriggerCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                    boolean                       Enable)
{
    FtmBase->SYNC = (FtmBase->SYNC & ~FTM_SYNC_SWSYNC_MASK) | FTM_SYNC_SWSYNC((Enable == TRUE) ? 0x01U : 0x00U);
}

/* FTM Initial State For Channels Output (OUTINIT) */

/*!
 * @brief Sets the FTM peripheral timer channel output initial state 0 or 1.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Channel  The FTM peripheral channel number
 * @param[in] State    Initial state for channels output
 *                     - TRUE : The initialization value is 1
 *                     - FALSE: The initialization value is 0
 *
 * Implements : Ftm_Pwm_Ip_SetChnOutputInitStateCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetChnOutputInitStateCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                       uint8                         Channel,
                                                       Ftm_Pwm_Ip_OutputStateType    State)
{
    if (FTM_PWM_IP_OUTPUT_STATE_HIGH == State)
    {
        FtmBase->OUTINIT |= (1UL << Channel);
    }
    else
    {
        FtmBase->OUTINIT &= ~(1UL << Channel);
    }
}

/* FTM Output Mask (OUTMASK) */

/*!
 * @brief Sets the FTM peripheral timer channel output mask.
 *
 * @param[in] FtmBase     The FTM base address pointer
 * @param[in] Channel     The FTM peripheral channel number
 * @param[in] EnableMask  Value to set Output Mask
 *                        - TRUE : Channel output is masked
 *                        - FALSE: Channel output is not masked
 *
 * Implements : Ftm_Pwm_Ip_SetChnOutputMask_Activity
 */
static inline void Ftm_Pwm_Ip_SetChnOutputMask(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               uint8                         Channel,
                                               boolean                       EnableMask)
{
    if (EnableMask)
    {
        FtmBase->OUTMASK |= 1UL << Channel;
    }
    else
    {
        FtmBase->OUTMASK &= ~(1UL << Channel);
    }
}

/*!
 * @brief Writes the provided value to the OUTMASK register.
 *
 * This function will mask multiple channels.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] RegVal   Value to be written to the register
 */
static inline void Ftm_Pwm_Ip_SetOutmaskReg(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                            uint32                        RegVal)
{
    FtmBase->OUTMASK = ((FtmBase->OUTMASK & (uint32)(~RegVal))| RegVal);
}


/*!
 * @brief Writes the provided value to the OUTMASK register.
 *
 * This function will unmask multiple channels.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] RegVal   Value to be written to the register
 */
static inline void Ftm_Pwm_Ip_ClearOutmaskReg(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                              uint32                        RegVal)
{
    FtmBase->OUTMASK = ((FtmBase->OUTMASK & (uint32)(~RegVal))|0U);
}

/*!
 * @brief Returns the FTM Output Mask value.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return the FTM Output Mask
 *
 * Implements : Ftm_Pwm_Ip_GetOutputMask
 */
static inline uint32 Ftm_Pwm_Ip_GetOutputMask(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint32)(FtmBase->OUTMASK);
}


/* FTM Function For Linked Channels (COMBINE) */

/*!
 * @brief Enables or disables the FTM peripheral timer channel pair output combine mode.
 *
 * @param[in] FtmBase   The FTM base address pointer
 * @param[in] ChPairId  The FTM peripheral channel pair number
 * @param[in] Enable    State of channel pair output combine mode
 *                      - TRUE : Channels pair are combined
 *                      - FALSE: Channels pair are independent
 */
static inline void Ftm_Pwm_Ip_SetDualChnCombineCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                   uint8                         ChPairId,
                                                   boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->COMBINE |= (uint32)FTM_COMBINE_COMBINE0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH);
    }
    else
    {
        FtmBase->COMBINE &= ~((uint32)FTM_COMBINE_COMBINE0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH));
    }
}

/*!
 * @brief Verify if an channels pair is used in combine mode or not.
 *
 * @param[in] FtmBase   The FTM base address pointer
 * @param[in] ChPairId  The FTM peripheral channel pair number
 *
 * @return Channel pair output combine mode status
 *         - TRUE : Channels pair are combined
 *         - FALSE: Channels pair are independent
 */
static inline boolean Ftm_Pwm_Ip_GetDualChnCombineCmd(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                      uint8 ChPairId)
{
    return (FtmBase->COMBINE & ((uint32)FTM_COMBINE_COMBINE0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH))) != 0U;
}

/*!
 * @brief Enables or disables the FTM peripheral timer channel pair output complement mode.
 *
 * @param[in] FtmBase   The FTM base address pointer
 * @param[in] ChPairId  The FTM peripheral channel pair number
 * @param[in] Enable    State of channel pair output complement mode
 *                      - TRUE : The channel (n+1) output is the complement of the channel (n) output
 *                      - FALSE: The channel (n+1) output is the same as the channel (n) output
 */
static inline void Ftm_Pwm_Ip_SetDualChnCompCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                uint8                         ChPairId,
                                                boolean                       Enable)
{
    if (Enable == TRUE)
    {
        FtmBase->COMBINE |= (uint32)FTM_COMBINE_COMP0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH);
    }
    else
    {
        FtmBase->COMBINE &= ~((uint32)FTM_COMBINE_COMP0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH));
    }
}

/*!
 * @brief Enables or disabled the FTM peripheral timer channel pair deadtime insertion.
 *
 * @param[in] FtmBase   The FTM base address pointer
 * @param[in] ChPairId  The FTM peripheral channel pair number
 * @param[in] Enable    State of channel pair deadtime insertion
 *                      - TRUE : To enable deadtime insertion
 *                      - FALSE: To disable
 */
static inline void Ftm_Pwm_Ip_SetDualChnDeadtimeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                    uint8                         ChPairId,
                                                    boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->COMBINE |= (uint32)FTM_COMBINE_DTEN0_MASK << (ChPairId * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH);
    }
    else
    {
        FtmBase->COMBINE &= ~((uint32)FTM_COMBINE_DTEN0_MASK << (ChPairId * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH));
    }
}

/*!
 * @brief Enables or disables the FTM peripheral timer channel pair counter PWM sync.
 *
 * @param[in] FtmBase   The FTM base address pointer
 * @param[in] ChPairId  The FTM peripheral channel pair number
 * @param[in] Enable    State of channel pair counter PWM sync
 *                      - TRUE : To enable PWM synchronization
 *                      - FALSE: To disable
 */
static inline void Ftm_Pwm_Ip_SetDualChnPwmSyncCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                   uint8                         ChPairId,
                                                   boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->COMBINE |= (uint32)FTM_COMBINE_SYNCEN0_MASK << (ChPairId * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH);
    }
    else
    {
        FtmBase->COMBINE &= ~((uint32)FTM_COMBINE_SYNCEN0_MASK << (ChPairId * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH));
    }
}

#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
/*!
 * @brief Enables the FTM peripheral timer channel modified combine mode.
 *
 * @param[in] FtmBase   The FTM base address pointer
 * @param[in] ChPairId  The FTM peripheral channel pair number
 * @param[in] Enable    State of channel pair outputs modified combine
 *                      - TRUE : To enable modified combine
 *                      - FALSE: To disable modified combine
 */
static inline void Ftm_Pwm_Ip_SetDualChnMCombineCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                    uint8                         ChPairId,
                                                    boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->COMBINE |= (uint32)FTM_COMBINE_MCOMBINE0_MASK << (ChPairId * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH);
    }
    else
    {
        FtmBase->COMBINE &= ~((uint32)FTM_COMBINE_MCOMBINE0_MASK << (ChPairId * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH));
    }
}

/*!
 * @brief Verify if an channels pair is used in the modified combine mode or not.
 *
 * @param[in] FtmBase   The FTM base address pointer
 * @param[in] ChPairId  The FTM peripheral channel pair number
 *
 * @return Channel pair output combine mode status
 *         - TRUE : Channels pair are combined
 *         - FALSE: Channels pair are independent
 */
static inline boolean Ftm_Pwm_Ip_GetDualChnMCombineCmd(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                       uint8                               ChPairId)
{
    return (FtmBase->COMBINE & ((uint32)FTM_COMBINE_MCOMBINE0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH))) != 0U;
}
#endif

/* FTM Deadtime Configuration (DEADTIME) */

/*!
 * @brief Sets the FTM deadtime value.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Count    The FTM peripheral pre-scaler divider
 *                     - 0U : no counts inserted
 *                     - 1U : 1 count is inserted
 *                     - 2U : 2 count is inserted
 *                     - ... up to a possible 63 counts
 */
static inline void Ftm_Pwm_Ip_SetDeadtimeCount(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               uint8                         Count)
{
    FtmBase->DEADTIME = (FtmBase->DEADTIME & ~FTM_DEADTIME_DTVAL_MASK) | FTM_DEADTIME_DTVAL(Count);
}

/*!
 * @brief Sets the FTM dead time divider.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Divider The FTM peripheral pre-scaler divider
 *                    - FTM_DEADTIME_DIV_1 : Divide by 1
 *                    - FTM_DEADTIME_DIV_4 : Divide by 4
 *                    - FTM_DEADTIME_DIV_16: Divide by 16
 */
static inline void Ftm_Pwm_Ip_SetDeadtimePrescaler(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                   Ftm_Pwm_Ip_DeadtimePrescalerType Divider)
{
    FtmBase->DEADTIME = (FtmBase->DEADTIME & ~FTM_DEADTIME_DTPS_MASK) | FTM_DEADTIME_DTPS((uint8)Divider);
}

/*!
 * @brief Get the FTM dead time divider.
 *
 * @param[in] FtmBase The FTM base address pointer
 */
static inline uint8 Ftm_Pwm_Ip_GetDeadtimePrescaler(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint8)(FtmBase->DEADTIME & FTM_DEADTIME_DTPS_MASK)>>FTM_DEADTIME_DTPS_SHIFT;
}

/*!
 * @brief Sets the FTM extended dead-time value.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Value The FTM peripheral extend pre-scale divider
 */
static inline void Ftm_Pwm_Ip_SetExtDeadtimeValue(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  uint8                         Value)
{
    FtmBase->DEADTIME = (FtmBase->DEADTIME & ~FTM_DEADTIME_DTVALEX_MASK) | FTM_DEADTIME_DTVALEX(Value);
}

/* FTM External Trigger (EXTTRIG) */

/*!
 * @brief Enables or disables the generation of the trigger according to i
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of initialization trigger
 *                     - TRUE : To enable
 *                     - FALSE: To disable
 */
static inline void Ftm_Pwm_Ip_SetInitTriggerCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                boolean Enable)
{
    FtmBase->EXTTRIG = (FtmBase->EXTTRIG & ~FTM_EXTTRIG_INITTRIGEN_MASK) | FTM_EXTTRIG_INITTRIGEN((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Checks whether any channel trigger event has occurred.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @return Channel trigger status
 *         - TRUE : If there is a channel trigger event
 *         - FALSE: If not.
 */
static inline boolean Ftm_Pwm_Ip_IsChnTriggerGenerated(const Ftm_Pwm_Ip_HwAddrType * FtmBase)
{
    return (FtmBase->EXTTRIG & FTM_EXTTRIG_TRIGF_MASK) != 0U;
}

/*!
 * @brief Clear the channel trigger flag.
 *
 * @param[in] FtmBase The FTM base address pointer
 */
static inline void Ftm_Pwm_Ip_ClearChnTriggerFlag(Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    FtmBase->EXTTRIG = (FtmBase->EXTTRIG & ~FTM_EXTTRIG_TRIGF_MASK) | FTM_EXTTRIG_TRIGF(0UL);
}

/*!
 * @brief Disables trigger generation for specific source
 *
 * @param[in] FtmBase The FTM base address pointer
 */
static inline void Ftm_Pwm_Ip_DisableTriggerMask(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                 uint32                        TriggerMask)
{
    FtmBase->EXTTRIG = ((FtmBase->EXTTRIG & ~TriggerMask) | (0U));
}

/*!
 * @brief Enables trigger generation for specific source
 *
 * @param[in] FtmBase The FTM base address pointer
 */
static inline void Ftm_Pwm_Ip_EnableTriggerMask(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                uint32                        TriggerMask)
{
    FtmBase->EXTTRIG = ((FtmBase->EXTTRIG & ~TriggerMask) | TriggerMask);
}

/* FTM Channels Polarity (POL) */

/*!
 * @brief Sets the FTM peripheral timer channel output polarity.
 *
 * @param[in] FtmBase   The FTM base address pointer
 * @param[in] Channel   The FTM peripheral channel number
 * @param[in] Polarity  The polarity to be set
 *                      - TRUE : The channel polarity is active low
 *                      - FALSE  : The channel polarity is active high
 */
static inline void Ftm_Pwm_Ip_SetChnOutputPolarityCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                      uint8                         Channel,
                                                      Ftm_Pwm_Ip_PolarityType       Polarity)
{
    if (FTM_PWM_IP_POLARITY_HIGH == Polarity)
    {
        FtmBase->POL &= ~(1UL << Channel);
    }
    else
    {
        FtmBase->POL |= 1UL << Channel;
    }
}

/*!
 * @brief Gets the FTM peripheral timer channel output polarity.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel number
 * @return The polarity to be set
 *            - FTM_PWM_IP_POLARITY_LOW : The channel polarity is active low
 *            - FTM_PWM_IP_POLARITY_HIGH  : The channel polarity is active high
 */
static inline Ftm_Pwm_Ip_PolarityType Ftm_Pwm_Ip_GetChnOutputPolarity(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                                      uint8                               Channel)
{
    return (((FtmBase->POL >> Channel) & 1U) == 1U)? FTM_PWM_IP_POLARITY_LOW : FTM_PWM_IP_POLARITY_HIGH;
}

/* FTM Fault Mode Status (FMS) */

/*!
 * @brief Checks whether the write protection is enabled.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return Write-protection status
 *         - TRUE : If enabled
 *         - FALSE: If not
 *
 * Implements : Ftm_Pwm_Ip_IsWriteProtectionEnabled_Activity
 */
static inline boolean Ftm_Pwm_Ip_IsWriteProtectionEnabled(const Ftm_Pwm_Ip_HwAddrType * FtmBase)
{
    return (FtmBase->FMS & FTM_FMS_WPEN_MASK) != 0U;
}

/* FTM Configuration (CONF) */

#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
/*!
 * @brief Sets the frequency of reload points
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Val      Value of the TOF bit set frequency
 *
 * Implements : Ftm_Pwm_Ip_SetLoadFreq_Activity
 */
static inline void Ftm_Pwm_Ip_SetLoadFreq(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                          uint8                         Val)
{
    FtmBase->CONF = (FtmBase->CONF & ~FTM_CONF_LDFQ_MASK) | FTM_CONF_LDFQ(Val);
}
#endif

/*!
 * @brief Sets the BDM mode.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Val      The FTM behavior in BDM mode
 *                     - FTM_BDM_MODE_00: FTM counter stopped, CH(n)F bit can be set, FTM channels
 *                                        in functional mode, writes to MOD,CNTIN and C(n)V registers bypass
 *                                        the register buffers
 *                     - FTM_BDM_MODE_01: FTM counter stopped, CH(n)F bit is not set, FTM channels
 *                                        outputs are forced to their safe value , writes to MOD,CNTIN and
 *                                        C(n)V registers bypass the register buffers
 *                     - FTM_BDM_MODE_10: FTM counter stopped, CH(n)F bit is not set, FTM channels
 *                                        outputs are frozen when chip enters in BDM mode, writes to MOD,
 *                                        CNTIN and C(n)V registers bypass the register buffers
 *                     - FTM_BDM_MODE_11: FTM counter in functional mode, CH(n)F bit can be set,
 *                                        FTM channels in functional mode, writes to MOD,CNTIN and C(n)V
 *                                        registers is in fully functional mode
 */
static inline void Ftm_Pwm_Ip_SetBdmMode(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                         Ftm_Pwm_Ip_DebugModeType      Val)
{
    FtmBase->CONF = (FtmBase->CONF & ~FTM_CONF_BDMMODE_MASK) | FTM_CONF_BDMMODE(Val);
}

/*!
 * @brief Enables or disables the FTM timer global time base.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of global time base
 *                     - TRUE : To enable an external global time base signal
 *                     - FALSE: To disable an external global time base signal
 *
 * Implements : Ftm_Pwm_Ip_SetGlobalTimeBaseCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetGlobalTimeBaseCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                   boolean                       Enable)
{
    FtmBase->CONF = (FtmBase->CONF & ~FTM_CONF_GTBEEN_MASK) | FTM_CONF_GTBEEN((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Enables or disables the FTM global time base signal generation to other FTM's.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of global time base signal
 *                     - TRUE : To enable the golobal time base generation to other FTM instances
 *                     - FALSE: To disable the golobal time base generation to other FTM instances
 *
 * Implements : Ftm_Pwm_Ip_SetGlobalTimeBaseOutputCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetGlobalTimeBaseOutputCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                         boolean Enable)
{
    FtmBase->CONF = (FtmBase->CONF & ~FTM_CONF_GTBEOUT_MASK) | FTM_CONF_GTBEOUT((Enable == TRUE) ? 0x01U : 0x00U);
}

#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
/*!
 * @brief Choses the FTM initialization trigger generation.
 *
 * @param[in] FtmBase       The FTM base address pointer
 * @param[in] InitTrigMode  Enable bit controls whether an initialization trigger is generated
 *                          - FTM_PWM_IP_INIT_TRIGG_RELOAD_POINT  : Trigger is generated when a reload point is reached
 *                          - FTM_PWM_IP_INIT_TRIGG_CNT_UPDATE    : Trigger is generated on counter wrap event
 *
 * Implements : Ftm_Pwm_Ip_SetInitTrigOnReloadCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetInitTriggerMode(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                 Ftm_Pwm_Ip_InitTriggModeType  InitTrigMode)
{
    FtmBase->CONF = (FtmBase->CONF & ~FTM_CONF_ITRIGR_MASK) | FTM_CONF_ITRIGR(InitTrigMode);
}
#endif

/* FTM Synchronization configuration (SYNCONF) */

/*!
 * @brief Sets hardware trigger mode.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of hardware trigger mode
 *                     - TRUE : FTM does not clear the TRIGx bit when the hardware trigger j is detected
 *                     - FALSE: FTM clears the TRIGx bit when the hardware trigger j is detected
 */
static inline void Ftm_Pwm_Ip_SetHwTriggerSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                      boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_HWTRIGMODE_MASK) | FTM_SYNCONF_HWTRIGMODE((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets the CNTIN register PWM synchronization mode.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of register synchronization
 *                     - TRUE : CNTIN register is updated by PWM sync
 *                     - FALSE: CNTIN register is updated at all rising edges of system clock
 */
static inline void Ftm_Pwm_Ip_SetCntinPwmSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                     boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_CNTINC_MASK) | FTM_SYNCONF_CNTINC((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets the INVCTRL register PWM synchronization mode.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of register synchronization
 *                     - TRUE : INVCTRL register is updated by PWM sync
 *                     - FALSE: INVCTRL register is updated at all rising edges of system clock
 */
static inline void Ftm_Pwm_Ip_SetInvctrlPwmSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                       boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_INVC_MASK) | FTM_SYNCONF_INVC((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets the SWOCTRL register PWM synchronization mode.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of register synchronization
 *                     - TRUE : SWOCTRL register is updated by PWM sync
 *                     - FALSE: SWOCTRL register is updated at all rising edges of system clock
 */
static inline void Ftm_Pwm_Ip_SetSwoctrlPwmSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                       boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_SWOC_MASK) | FTM_SYNCONF_SWOC((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets the PWM synchronization mode to enhanced or legacy.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Mode     State of synchronization mode
 *                     - TRUE : Enhanced PWM synchronization is selected
 *                     - FALSE: Legacy PWM synchronization is selected
 */
static inline void Ftm_Pwm_Ip_SetPwmSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                boolean                       Mode)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_SYNCMODE_MASK) | FTM_SYNCONF_SYNCMODE((Mode == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets sync mode for FTM counter register when using a software trigger.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of FTM counter synchronization
 *                     - TRUE : The software trigger activates FTM counter sync
 *                     - FALSE: The software trigger does not activate FTM counter sync
 */
static inline void Ftm_Pwm_Ip_SetCounterSoftwareSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                            boolean Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_SWRSTCNT_MASK) | FTM_SYNCONF_SWRSTCNT((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets sync mode for FTM MOD, CNTIN and CV registers when using a software trigger.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of registers synchronization
 *                     - TRUE : The software trigger activates FTM MOD, CNTIN and CV registers sync
 *                     - FALSE: The software trigger does not activate FTM MOD, CNTIN and CV registers sync
 */
static inline void Ftm_Pwm_Ip_SetModCntinCvSoftwareSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                               boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_SWWRBUF_MASK) | FTM_SYNCONF_SWWRBUF((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets sync mode for FTM OUTMASK register when using a software trigger.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of output mask synchronization
 *                     - TRUE : The software trigger activates OUTMASK register sync
 *                     - FALSE: The software trigger does not activate OUTMASK register sync
 */
static inline void Ftm_Pwm_Ip_SetOutmaskSoftwareSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                            boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_SWOM_MASK) | FTM_SYNCONF_SWOM((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets sync mode for FTM INVCTRL register when using a software trigger.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of State of inverting control synchronization
 *                     - TRUE : The software trigger activates INVCTRL register sync
 *                     - FALSE: The software trigger does not activate INVCTRL register sync
 */
static inline void Ftm_Pwm_Ip_SetInvctrlSoftwareSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                            boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_SWINVC_MASK) | FTM_SYNCONF_SWINVC((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets sync mode for FTM SWOCTRL register when using a software trigger.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Enable  State of software output control synchronization
 *                    - TRUE : The software trigger activates SWOCTRL register sync
 *                    - FALSE: The software trigger does not activate SWOCTRL register sync
 */
static inline void Ftm_Pwm_Ip_SetSwoctrlSoftwareSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                            boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_SWSOC_MASK) | FTM_SYNCONF_SWSOC((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets sync mode for FTM counter register when using a hardware trigger.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of FTM counter synchronization
 *                     - TRUE : The hardware trigger activates FTM counter sync
 *                     - FALSE: The hardware trigger does not activate FTM counter sync
 */
static inline void Ftm_Pwm_Ip_SetCounterHardwareSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                            boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_HWRSTCNT_MASK) | FTM_SYNCONF_HWRSTCNT((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets sync mode for FTM MOD, CNTIN and CV registers when using a hardware trigger.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of registers synchronization
 *                     - TRUE : The hardware trigger activates  MOD, HCR, CNTIN, and CV registers sync
 *                     - FALSE: The hardware trigger does not activate MOD, HCR, CNTIN, and CV registers sync
 */
static inline void Ftm_Pwm_Ip_SetModCntinCvHardwareSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                               boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_HWWRBUF_MASK) | FTM_SYNCONF_HWWRBUF((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets sync mode for FTM OUTMASK register when using a hardware trigger.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of output mask synchronization
 *                     - TRUE : The hardware trigger activates OUTMASK register sync
 *                     - FALSE: The hardware trigger does not activate OUTMASK register sync
 */
static inline void Ftm_Pwm_Ip_SetOutmaskHardwareSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                            boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_HWOM_MASK) | FTM_SYNCONF_HWOM((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets sync mode for FTM INVCTRL register when using a hardware trigger.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of inverting control synchronization
 *                     - TRUE : The hardware trigger activates INVCTRL register sync
 *                     - FALSE: The hardware trigger does not activate INVCTRL register sync
 */
static inline void Ftm_Pwm_Ip_SetInvctrlHardwareSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                            boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_HWINVC_MASK) | FTM_SYNCONF_HWINVC((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * @brief Sets the sync mode for the FTM SWOCTRL register when using a hardware trigger.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of software output control synchronization
 *                     - TRUE : The hardware trigger activates SWOCTRL register sync
 *                     - FALSE: The hardware trigger does not activate SWOCTRL register sync
 */
static inline void Ftm_Pwm_Ip_SetSwoctrlHardwareSyncModeCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                            boolean                       Enable)
{
    FtmBase->SYNCONF = (FtmBase->SYNCONF & ~FTM_SYNCONF_HWSOC_MASK) | FTM_SYNCONF_HWSOC((Enable == TRUE) ? 0x01U : 0x00U);
}

/* FTM Synchronization configuration (INVCTRL) */

/*!
 * @brief Writes the provided value to the Inverting control register.
 *
 * This function is enable/disable inverting control on multiple channel pairs.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] RegVal   Value to be written to the register
 */
static inline void Ftm_Pwm_Ip_SetInvctrlReg(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                            uint32                        RegVal)
{
    FtmBase->INVCTRL = RegVal;
}

/*!
 * @brief Enables or disables the channel invert for a channel pair.
 *
 * @param[in] FtmBase   The FTM base address pointer
 * @param[in] ChPairId  The FTM peripheral channel pair number
 * @param[in] Enable    State of channel invert for a channel pair
 *                      - TRUE : To enable channel inverting
 *                      - FALSE: To disable channel inversion
 *
 * Implements : Ftm_Pwm_Ip_SetDualChnInvertCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetDualChnInvertCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  uint8                         ChPairId,
                                                  boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->INVCTRL |= 1UL << ChPairId;
    }
    else
    {
        FtmBase->INVCTRL &= ~(1UL << ChPairId);
    }
}

/* FTM Software Output Control (SWOCTRL) */

/*!
 * @brief Sets the channel software output control value.
 *
 * @param[in] FtmBase  The FTM base address pointer.
 * @param[in] Values   The values which will overwrite the output channels
 */
static inline void Ftm_Pwm_Ip_SetAllChnSoftwareCtrlVal(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                       uint8                         Values)
{
   FtmBase->SWOCTRL = (FtmBase->SWOCTRL & (~FTM_PWM_IP_SWOCTRL_CHOCV_MASK)) | ((uint32)Values << FTM_SWOCTRL_CH0OCV_SHIFT);
}

/*!
 * @brief Sets the channel software output control value.
 * Despite the odd channels are configured as HIGH/LOW, they will be inverted in the following
 * configuration: COMP bit = 1 and CH(n)OCV and CH(n+1)OCV are HIGH. Please check Software
 * output control behavior chapter from RM.
 *
 * @param[in] FtmBase  The FTM base address pointer.
 * @param[in] Channel  Channel to be configured
 * @param[in] Enable   State of software output control value
 *                     - TRUE : to force 1 to the channel output
 *                     - FALSE: to force 0 to the channel output
 *
 * Implements : Ftm_Pwm_Ip_SetChnSoftwareCtrlVal_Activity
 */
static inline void Ftm_Pwm_Ip_SetChnSoftwareCtrlVal(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                    uint8                         Channel,
                                                    boolean                       Enable)
{
    uint8 ChPol = (uint8)(((uint32)FtmBase->POL >> (uint32)Channel) & (uint32)1U);
    boolean StatusPol = (ChPol == 0x00U)? FALSE : TRUE;
    if (Enable != StatusPol)
    {
        FtmBase->SWOCTRL |= 1UL << (Channel + FTM_SWOCTRL_CH0OCV_SHIFT);
    }
    else
    {
        FtmBase->SWOCTRL &= ~(1UL << (Channel + FTM_SWOCTRL_CH0OCV_SHIFT));
    }
}

/*!
 * @brief Enables or disables the channel software output control.The
 * main difference between this function and FTM_HAL_SetChnSoftwareCtrlCmd
 * is that this can configure all the channels in the same time.
 * @param[in] FtmBase       The FTM base address pointer
 * @param[in] ChannelsMask  Channels to be enabled or disabled
 */
static inline void Ftm_Pwm_Ip_SetAllChnSoftwareCtrlCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                       uint8                         ChannelsMask)
{
    FtmBase->SWOCTRL = (FtmBase->SWOCTRL & (~FTM_PWM_IP_SWOCTRL_CHOC_MASK)) | ChannelsMask;
}

/*!
 * @brief Enables or disables the channel software output control.
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Channel  Channel to be enabled or disabled
 * @param[in] Enable   State of channel software output control
 *                     - TRUE : To enable the channel output will be affected by software output control
 *                     - FALSE: To disable the channel output is unaffected
 *
 * Implements : Ftm_Pwm_Ip_SetChnSoftwareCtrlCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetChnSoftwareCtrlCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                    uint8                         Channel,
                                                    boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->SWOCTRL |= 1UL << Channel;
    }
    else
    {
        FtmBase->SWOCTRL &= ~(1UL << Channel);
    }
}

/*!
 * @brief Enable and Force the software control of channels output at once.
 *
 * @param[in] FtmBase  The FTM base address pointer.
 * @param[in] Value    The values which enables and force the software control of channels output
 */
static inline void Ftm_Pwm_Ip_SoftwareOutputControl(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                    uint16                        Value)
{
   FtmBase->SWOCTRL = Value;
}

/* FTM PWM Load (PWMLOAD) */

/*!
 * @brief Includes or excludes the channel in the matching process.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Channel  Channel to be configured
 * @param[in] Enable   State of channel
 *                     - TRUE : means include the channel in the matching process
 *                     - FALSE: means do not include channel in the matching process
 *
 * Implements : Ftm_Pwm_Ip_SetPwmLoadChnSelCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetPwmLoadChnSelCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  uint8                         Channel,
                                                  boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->PWMLOAD |= 1UL << Channel;
    }
    else
    {
        FtmBase->PWMLOAD &= ~(1UL << Channel);
    }
}

#if (defined(FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD) && (FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD == STD_ON))
/*!
 * @brief Enable the half cycle reload.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of the half cycle match as a reload opportunity
 *                     - TRUE : Half cycle reload is enabled
 *                     - FALSE: Half cycle reload is disabled
 *
 * Implements : Ftm_Pwm_Ip_SetHalfCycleCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetHalfCycleCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                              boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->PWMLOAD |= 1UL << FTM_PWMLOAD_HCSEL_SHIFT;
    }
    else
    {
        FtmBase->PWMLOAD &= ~(1UL << FTM_PWMLOAD_HCSEL_SHIFT);
    }
}
#endif

/*!
 * @brief Enables or disables the loading of MOD, CNTIN and CV with values of their write buffer.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of loading updated values
 *                     - TRUE : To enable the loading of value of their buffer
 *                     - FALSE: To disable the loading of value of their buffer
 *
 * Implements : Ftm_Pwm_Ip_SetPwmLoadCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetPwmLoadCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                            boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->PWMLOAD |= 1UL << FTM_PWMLOAD_LDOK_SHIFT;
    }
    else
    {
        FtmBase->PWMLOAD &= ~(1UL << FTM_PWMLOAD_LDOK_SHIFT);
    }
}

#if (defined(FTM_PWM_IP_HAS_GLOBAL_LOAD_MECHANISM) && (FTM_PWM_IP_HAS_GLOBAL_LOAD_MECHANISM == STD_ON))
/*!
 * @brief Enable the global load.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Enable   State of the global load mechanism
 *                     - TRUE : Global Load OK enabled
 *                     - FALSE: Global Load OK disabled
 *
 * Implements : Ftm_Pwm_Ip_SetLoadCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetLoadCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                         boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->PWMLOAD |= 1UL << FTM_PWMLOAD_GLEN_SHIFT;
    }
    else
    {
        FtmBase->PWMLOAD &= ~(1UL << FTM_PWMLOAD_GLEN_SHIFT);
    }
}

/*!
 * @brief Set the global load mechanism.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * Implements : Ftm_Pwm_Ip_SetGlobalLoadCmd_Activity
 */
static inline void Ftm_Pwm_Ip_SetGlobalLoadCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    FtmBase->PWMLOAD |= 1UL << FTM_PWMLOAD_GLDOK_SHIFT;
}
#endif

/* FTM Half Cycle Register (HCR) */

#if (defined(FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD) && (FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD == STD_ON))
/*!
 * @brief Sets the value for the half cycle reload register.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Value    The 16 bit counter value
 */
static inline void Ftm_Pwm_Ip_SetHalfCycleValue(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                uint16                        Value)
{
    FtmBase->HCR = Value;
}
#endif

/* FTM Mirror of Modulo Value (MOD_MIRROR) */

#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
/*!
 * @brief Sets the modulo fractional value in the PWM dithering.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Value    The value to be set to the fractional value for the modulo
 */
static inline void Ftm_Pwm_Ip_SetModFracVal(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                            uint8                         Value)
{
#if (FTM_INSTANCE_COUNT > 2U)
    if ((FtmBase == Ftm_Pwm_Ip_aFtmBase[1]) || (FtmBase == Ftm_Pwm_Ip_aFtmBase[2]))
#else
    #if (defined(FTM_PWM_IP_HAS_DITHERING_INSTANCE0) && (FTM_PWM_IP_HAS_DITHERING_INSTANCE0 == STD_ON))
        #if (FTM_INSTANCE_COUNT == 1U)
            if (FtmBase == Ftm_Pwm_Ip_aFtmBase[0])
        #else
            if ((FtmBase == Ftm_Pwm_Ip_aFtmBase[0]) || (FtmBase == Ftm_Pwm_Ip_aFtmBase[1]))
        #endif
    #else
        if (FtmBase == Ftm_Pwm_Ip_aFtmBase[1])
    #endif
#endif
    {
       FtmBase->MOD_MIRROR = (FtmBase->MOD_MIRROR & ~FTM_MOD_MIRROR_FRACMOD_MASK) | FTM_MOD_MIRROR_FRACMOD(Value);
    }
}

/*!
 * @brief Returns The modulo fractional value is used in the PWM period dithering.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return the modulo fractional value
 *
 * Implements : Ftm_Pwm_Ip_GetModFracVal_Activity
 */
static inline uint8 Ftm_Pwm_Ip_GetModFracVal(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint8)((FtmBase->MOD_MIRROR & FTM_MOD_MIRROR_FRACMOD_MASK) >> FTM_MOD_MIRROR_FRACMOD_SHIFT);
}

/*!
 * @brief Sets the mirror of the modulo integer value.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Value    The value to be set to the timer modulo
 *
 * Implements : Ftm_Pwm_Ip_SetMirrorMod_Activity
 */
static inline void Ftm_Pwm_Ip_SetMirrorMod(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                           uint16                        Value)
{
    FtmBase->MOD_MIRROR = (FtmBase->MOD_MIRROR & ~FTM_MOD_MIRROR_MOD_MASK) | FTM_MOD_MIRROR_MOD(Value);
}

/*!
 * @brief Returns the mirror of the FTM peripheral counter modulo value.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return the mirror of the FTM timer modulo value
 *
 * Implements : Ftm_Pwm_Ip_GetMirrorMod_Activity
 */
static inline uint16 Ftm_Pwm_Ip_GetMirrorMod(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint16)((FtmBase->MOD_MIRROR & FTM_MOD_MIRROR_MOD_MASK) >> FTM_MOD_MIRROR_MOD_SHIFT);
}

/* FTM Mirror of Channel (n) Match Value (CnV_MIRROR) */

/*!
 * @brief Sets the channel (n) match fractional value.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Channel  The FTM peripheral channel (n)
 * @param[in] Value    The value to be set to the channel (n) match fractional value
 */
static inline void Ftm_Pwm_Ip_SetChnMatchFracVal(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                 uint8                         Channel,
                                                 uint8                         Value)
{
#if (FTM_INSTANCE_COUNT > 2U)
    if ((FtmBase == Ftm_Pwm_Ip_aFtmBase[1]) || (FtmBase == Ftm_Pwm_Ip_aFtmBase[2]))
#else
    #if (defined(FTM_PWM_IP_HAS_DITHERING_INSTANCE0) && (FTM_PWM_IP_HAS_DITHERING_INSTANCE0 == STD_ON))
        #if (FTM_INSTANCE_COUNT == 1U)
            if (FtmBase == Ftm_Pwm_Ip_aFtmBase[0])
        #else
            if ((FtmBase == Ftm_Pwm_Ip_aFtmBase[0]) || (FtmBase == Ftm_Pwm_Ip_aFtmBase[1]))
        #endif
    #else
        if (FtmBase == Ftm_Pwm_Ip_aFtmBase[1])
    #endif
#endif
    {
        FtmBase->CV_MIRROR[Channel] = (FtmBase->CV_MIRROR[Channel] & ~FTM_CV_MIRROR_FRACVAL_MASK) | FTM_CV_MIRROR_FRACVAL(Value);
    }
}

/*!
 * @brief Returns the channel (n) match fractional value.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel (n)
 *
 * @return The channel (n) match fractional value is used in the PWM edge dithering
 *
 * Implements : Ftm_Pwm_Ip_GetChnMatchFracVal_Activity
 */
static inline uint8 Ftm_Pwm_Ip_GetChnMatchFracVal(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  uint8                               Channel)
{
    return (uint8)((FtmBase->CV_MIRROR[Channel] & FTM_CV_MIRROR_FRACVAL_MASK) >> FTM_CV_MIRROR_FRACVAL_SHIFT);
}

/*!
 * @brief Sets the mirror of the channel (n) match integer value.
 *
 * @param[in] FtmBase  The FTM base address pointer
 * @param[in] Channel  The FTM peripheral channel (n)
 * @param[in] Value    The value to be set to the mirror of the channel (n) match integer value
 *
 * Implements : Ftm_Pwm_Ip_SetMirrorChnMatchVal_Activity
 */
static inline void Ftm_Pwm_Ip_SetMirrorChnMatchVal(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                   uint8                         Channel,
                                                   uint16                        Value)
{
    FtmBase->CV_MIRROR[Channel] = (FtmBase->CV_MIRROR[Channel] & ~FTM_CV_MIRROR_VAL_MASK) | FTM_CV_MIRROR_VAL(Value);
}

/*!
 * @brief Returns the mirror of the channel (n) match integer value.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM peripheral channel (n)
 *
 * @return the mirror of the channel (n) match value
 *
 * Implements : Ftm_Pwm_Ip_GetMirrorChnMatchVal_Activity
 */
static inline uint16 Ftm_Pwm_Ip_GetMirrorChnMatchVal(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                     uint8                               Channel)
{
    return (uint16)((FtmBase->CV_MIRROR[Channel] & FTM_CV_MIRROR_VAL_MASK) >> FTM_CV_MIRROR_VAL_SHIFT);
}
#endif

/*!
 * @brief Returns the FTM Software Output Control value.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return the FTM software Output Control.
 *
 * Implements : Ftm_Pwm_Ip_GetSoftwareOutputControl
 */
static inline uint16 Ftm_Pwm_Ip_GetSoftwareOutputControl(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint16)(FtmBase->SWOCTRL);
}

/*!
 * @brief Returns the polatity value of all channels.
 *
 * @param[in] FtmBase The FTM base address pointer
 *
 * @return the polarity value of all channel
 *
 * Implements : Ftm_Pwm_Ip_GetPolInstance
 */
static inline uint16 Ftm_Pwm_Ip_GetPolInstance(const Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    return (uint16)(FtmBase->POL);
}

/*!
 * @brief Get the FTM channel in complement mode or not.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM channel Id
 *
 * @return    boolean
 *            - TRUE : The channel (n+1) output is the complement of the channel (n) output
 *            - FALSE: The channel (n+1) output is the same as the channel (n) output
 */
static inline boolean Ftm_Pwm_Ip_GetDualChnCompCmd(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                   uint8                               Channel)
{
    uint8 ChPairId = Channel >> 1U;
    uint8 Comp = (uint8)((uint32)(FtmBase->COMBINE & ((uint32)FTM_COMBINE_COMP0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH))) >>  ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH));
    return ((Comp == FTM_COMBINE_COMP0_MASK)? TRUE : FALSE);
}

/*!
 * @brief Get the FTM channel in deadtime insertion or not.
 *
 * @param[in] FtmBase The FTM base address pointer
 * @param[in] Channel The FTM channel Id
 *
 * @return    boolean
 *            - TRUE : The deadtime insertion in this pair of channels is disabled.
 *            - FALSE: The deadtime insertion in this pair of channels is enabled.
 */
static inline boolean Ftm_Pwm_Ip_GetDualChnDeadtimeCmd(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                       uint8                               Channel)
{
    uint8 ChPairId = Channel >> 1U;
    uint8 DetEnable = (uint8)((uint32)(FtmBase->COMBINE & ((uint32)FTM_COMBINE_DTEN0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH))) >>  ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH));
    return ((DetEnable == FTM_COMBINE_DTEN0_MASK)? TRUE : FALSE);
}

/*!
 * @brief Get the channel Mode
 */
static inline Ftm_Pwm_Ip_ChannelModeType Ftm_Pwm_Ip_GetChannelMode(const Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                                   uint8                               Channel)
{
    Ftm_Pwm_Ip_ChannelModeType ChMode;
    uint8 RetValue;
    uint8 Combine;
    uint8 Mcombine;
    uint8 ChPairId = Channel >> 1U;

    Combine = (uint8)((FtmBase->COMBINE & ((uint32)FTM_COMBINE_COMBINE0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH))) >>  ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH));
    Mcombine = (uint8)((FtmBase->COMBINE & ((uint32)FTM_COMBINE_MCOMBINE0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH))) >> ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH));
    Mcombine = (Mcombine == (uint8)FTM_COMBINE_MCOMBINE0_MASK)? 0x01U : 0x00U;
    RetValue = (uint8)Ftm_Pwm_Ip_GetChnEdgeLevel(FtmBase, Channel);
    RetValue |= (uint8)(Ftm_Pwm_Ip_GetChnMode(FtmBase, Channel) << 2U);
    RetValue |= (uint8)((uint8)Ftm_Pwm_Ip_GetCpwms(FtmBase) << 4U);
    RetValue |= (uint8)(Combine << 5U);
    RetValue |= (uint8)(Mcombine << 6U);

    switch (RetValue)
    {
        case 0x0AU:
            ChMode = (Ftm_Pwm_Ip_ChannelModeType)FTM_PWM_IP_MODE_EDGE_ALIGNED_HIGH;
            break;
        case 0x09U:
            ChMode = (Ftm_Pwm_Ip_ChannelModeType)FTM_PWM_IP_MODE_EDGE_ALIGNED_LOW;
            break;
        case 0x12U:
            ChMode = (Ftm_Pwm_Ip_ChannelModeType)FTM_PWM_IP_MODE_CENTER_ALIGNED_HIGH;
            break;
        case 0x11U:
            ChMode = (Ftm_Pwm_Ip_ChannelModeType)FTM_PWM_IP_MODE_CENTER_ALIGNED_LOW;
            break;
        case 0x22U:
            ChMode = (Ftm_Pwm_Ip_ChannelModeType)FTM_PWM_IP_MODE_COMBINE_HIGH;
            break;
        case 0x21U:
            ChMode = (Ftm_Pwm_Ip_ChannelModeType)FTM_PWM_IP_MODE_COMBINE_LOW;
            break;
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
        case 0x62U:
            ChMode = (Ftm_Pwm_Ip_ChannelModeType)FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH;
            break;
        case 0x61U:
            ChMode = (Ftm_Pwm_Ip_ChannelModeType)FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW;
            break;
#endif
        default:
            ChMode = (Ftm_Pwm_Ip_ChannelModeType)FTM_PWM_IP_MODE_NODEFINED;
            break;
    }

    return ChMode; 
}
/*!
 *
 * Function Name : Ftm_Pwm_Ip_UpdateWriteProtection
 * Description   : Enables or disables the FTM write protection.
 */
static inline void Ftm_Pwm_Ip_UpdateWriteProtection(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                    boolean                       Enable)
{
    if (Enable == TRUE)
    {/* Enable write protection */
        /* WPEN is set when 1 is written to it. */
        FtmBase->FMS = (FtmBase->FMS & ~FTM_FMS_WPEN_MASK) | FTM_FMS_WPEN(1U);
    }
    else if ((FtmBase->FMS & FTM_FMS_WPEN_MASK) != 0U)
    {/* Disable write protection */
        /* WPDIS is set when WPEN bit is read as a 1 and then 1 is written to WPDIS */
        FtmBase->MODE |= FTM_MODE_WPDIS(TRUE);
    }
    else
    {
        /* MISRA Rule 15.7 All if...else if constructs shall be terminated with an else statement */
    }
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_Reset
 * Description   : Resets the FTM registers. All the register use in the driver should be
 * reset to default value of each register.
 */
static inline void Ftm_Pwm_Ip_Reset(Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    uint8 ChnIndex;

    /* Disable the write protection mechanism */
    Ftm_Pwm_Ip_UpdateWriteProtection(FtmBase, FALSE);

    /* Reset all registers to the default value */
    REG_RMW32(&(FtmBase->SC), 0U, 0U);
    FtmBase->CNT        = 0U;
    FtmBase->MOD        = 0U;
    FtmBase->CNTIN      = 0U;
    REG_RMW32(&(FtmBase->STATUS), 0U, 0U);
    FtmBase->MODE       = 4U;
    FtmBase->SYNC       = 0U;
    FtmBase->OUTINIT    = 0U;
    FtmBase->OUTMASK    = 0U;
    FtmBase->COMBINE    = 0U;
    FtmBase->DEADTIME   = 0U;
    REG_RMW32(&(FtmBase->EXTTRIG), 0U, 0U);
    FtmBase->POL        = 0U;
    FtmBase->FMS        = 0U;
    FtmBase->FILTER     = 0U;
    FtmBase->QDCTRL     = 0U;
    FtmBase->CONF       = 0U;
    FtmBase->SYNCONF    = 0U;
    FtmBase->INVCTRL    = 0U;
    FtmBase->SWOCTRL    = 0U;
    FtmBase->PWMLOAD    = 0U;
#if (defined(FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD) && (FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD == STD_ON))
    FtmBase->HCR        = 0U;
#endif

#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    #if (FTM_INSTANCE_COUNT > 2U)
        if ((FtmBase == Ftm_Pwm_Ip_aFtmBase[1]) || (FtmBase == Ftm_Pwm_Ip_aFtmBase[2]))
    #else
        #if (defined(FTM_PWM_IP_HAS_DITHERING_INSTANCE0) && (FTM_PWM_IP_HAS_DITHERING_INSTANCE0 == STD_ON))
            #if (FTM_INSTANCE_COUNT == 1U)
                if (FtmBase == Ftm_Pwm_Ip_aFtmBase[0])
            #else
                if ((FtmBase == Ftm_Pwm_Ip_aFtmBase[0]) || (FtmBase == Ftm_Pwm_Ip_aFtmBase[1]))
            #endif
        #else
            if (FtmBase == Ftm_Pwm_Ip_aFtmBase[1])
        #endif
    #endif
    {
        FtmBase->MOD_MIRROR = 0U;
    }
#endif

    /* Reset values of all CV and CSC registers */
    for (ChnIndex = 0; ChnIndex < FTM_PWM_IP_CHANNEL_COUNT; ChnIndex++)
    {
        FtmBase->CONTROLS[ChnIndex].CSC = 0U;
        FtmBase->CONTROLS[ChnIndex].CV = 0U;
        #if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
            #if (FTM_INSTANCE_COUNT > 2U)
                if ((FtmBase == Ftm_Pwm_Ip_aFtmBase[1]) || (FtmBase == Ftm_Pwm_Ip_aFtmBase[2]))
            #else
                #if (defined(FTM_PWM_IP_HAS_DITHERING_INSTANCE0) && (FTM_PWM_IP_HAS_DITHERING_INSTANCE0 == STD_ON))
                    #if (FTM_INSTANCE_COUNT == 1U)
                        if (FtmBase == Ftm_Pwm_Ip_aFtmBase[0])
                    #else
                        if ((FtmBase == Ftm_Pwm_Ip_aFtmBase[0]) || (FtmBase == Ftm_Pwm_Ip_aFtmBase[1]))
                    #endif
                #else
                    if (FtmBase == Ftm_Pwm_Ip_aFtmBase[1])
                #endif
            #endif
            {
                FtmBase->CV_MIRROR[ChnIndex] = 0U;
            }
        #endif
    }
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_SetChnTriggerCmd
 * Description   : Enables or disables the generation of the FTM peripheral timer channel trigger.
 * Enables or disables the generation of the FTM peripheral timer channel trigger when the
 * FTM counter is equal to its initial value.
 */
static inline void Ftm_Pwm_Ip_SetChnTriggerCmd(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               uint8                         Channel,
                                               boolean                       Enable)
{
    uint32 Value = 0U;

    if (Channel < 2U)
    {
        Value = (uint32)FTM_EXTTRIG_CH0TRIG_MASK << (uint32)Channel;
    }
    else if (Channel < 6U)
    {
        Value = (uint32)FTM_EXTTRIG_CH2TRIG_MASK << ((uint32)(Channel) - 2U);
    }
    else
    {
        /* Set trigger to other channels which are not aligned */
        #if (FTM_PWM_IP_CHANNEL_COUNT > 6U)
        Value = (uint32)FTM_EXTTRIG_CH6TRIG_MASK << ((uint32)(Channel) - 6U);
        #endif
    }

    if (TRUE == Enable)
    {
        FtmBase->EXTTRIG |= Value;
    }
    else
    {
        FtmBase->EXTTRIG &= ~Value;
    }
}

#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
/*!
 *
 * Function Name : Ftm_Pwm_Ip_SetFaultControlMode
 * Description   : Set the FTM fault control mode.
 */
static inline void Ftm_Pwm_Ip_SetFaultControlMode(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  Ftm_Pwm_Ip_FaultControlModeType FaultMode)
{
    switch(FaultMode)
    {
        case FTM_PWM_IP_FAULT_DISABLED:
            /*  Fault control is disabled for all channels. */
            FtmBase->MODE = (FtmBase->MODE & ~FTM_MODE_FAULTM_MASK) | FTM_MODE_FAULTM(0x00U);
            break;
        case FTM_PWM_IP_FAULT_EVEN_CHANNELS_MANUAL_CLEAR:
            /* Fault control is enabled for even channels only (channels 0, 2, 4, and 6), and the selected
               mode is the manual fault clearing. */
            FtmBase->MODE = (FtmBase->MODE & ~FTM_MODE_FAULTM_MASK) | FTM_MODE_FAULTM(0x01U);
            break;
        case FTM_PWM_IP_FAULT_ALL_CHANNELS_MANUAL_CLEAR:
            /* Fault control is enabled for all channels, and the selected mode is the manual fault clearing. */
            FtmBase->MODE = (FtmBase->MODE & ~FTM_MODE_FAULTM_MASK) | FTM_MODE_FAULTM(0x02U);
            break;
        case FTM_PWM_IP_FAULT_ALL_CHANNELS_AUTO_CLEAR:
            /*  Fault control is enabled for all channels, and the selected mode is the automatic fault clearing.*/
            FtmBase->MODE = (FtmBase->MODE & ~FTM_MODE_FAULTM_MASK) | FTM_MODE_FAULTM(0x03U);
            break;
        default:
            /* Nothing to do. This switch branch is empty because it shall not be executed for normal behaviour */
            break;
    }
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_SetDualChFaultCtr
 * Description   : Enables/Disables the fault control in channels (n) and (n+1)
 */
static inline void Ftm_Pwm_Ip_SetDualChFaultCtr(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                uint8                         ChPairId,
                                                boolean                       Enable)
{
    if (Enable)
    {
        FtmBase->COMBINE |= (uint32)FTM_COMBINE_FAULTEN0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH);
    }
    else
    {
        FtmBase->COMBINE &= ~((uint32)FTM_COMBINE_FAULTEN0_MASK << ((uint32)(ChPairId) * FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH));
    }
}

/*!
 * Function Name : Ftm_Pwm_Ip_SetFaultInterruptEnable
 * Description   : Enables/Disables the FTM fault interrupt.
 */
static inline void Ftm_Pwm_Ip_SetFaultInterruptEnable(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                      boolean                       Enable)
{
    FtmBase->MODE = (FtmBase->MODE & ~FTM_MODE_FAULTIE_MASK) | FTM_MODE_FAULTIE((Enable == TRUE) ? 0x01U : 0x00U);
}

/*!
 * Function Name : Ftm_Pwm_Ip_IsFaultEnabled
 * Description   : Reads the bit that controls enabling the FTM fault interrupt.
 */
static inline boolean Ftm_Pwm_Ip_IsFaultEnabled(const Ftm_Pwm_Ip_HwAddrType * FtmBase)
{
    return ((FtmBase->MODE & FTM_MODE_FAULTIE_MASK) >> FTM_MODE_FAULTIE_SHIFT) != 0U;
}

/*!
 * Function Name : Ftm_Pwm_Ip_ClearFaultFlag
 * Description   : Clears the fault interrupt flag.
 */
static inline void Ftm_Pwm_Ip_ClearFaultFlag(Ftm_Pwm_Ip_HwAddrType * const FtmBase)
{
    FtmBase->FMS = (FtmBase->FMS & ~FTM_FMS_FAULTF_MASK) | FTM_FMS_FAULTF(0U);
}

/*!
 * Function Name : Ftm_Pwm_Ip_ClearFaultFlagId
 * Description   : Clears the fault interrupt flag for each faultId.
 */
static inline void Ftm_Pwm_Ip_ClearFaultFlagId(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               uint8                         FaultId)
{
    FtmBase->FMS = (FtmBase->FMS & ~(1UL << (FaultId + FTM_FMS_FAULTF0_SHIFT))) | (0UL << (FaultId + FTM_FMS_FAULTF0_SHIFT));
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_GetFaultDetectionFlag
 * Description   : Returns whether any event for the FTM fault detection has occurred.
 */
static inline boolean Ftm_Pwm_Ip_GetFaultDetectionFlag(const Ftm_Pwm_Ip_HwAddrType * FtmBase)
{
    return ((FtmBase->FMS & FTM_FMS_FAULTF_MASK) >> FTM_FMS_FAULTF_SHIFT) != 0U;
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_GetFaultDetectionFlagId
 * Description   : Returns whether any event for the FTM peripheral fault channel has occurred.
 */
static inline boolean Ftm_Pwm_Ip_GetFaultDetectionFlagId(const Ftm_Pwm_Ip_HwAddrType * FtmBase,
                                                         uint8                         FaultId)
{
    return (((FtmBase->FMS & (1UL << (FaultId + FTM_FMS_FAULTF0_SHIFT)))) >> (FaultId + FTM_FMS_FAULTF0_SHIFT)) != 0U;
}


/*!
 *
 * Function Name : Ftm_Pwm_Ip_GetFaultModeStatus
 * Description   : Get fault mode status
 */
static inline uint32 Ftm_Pwm_Ip_GetFaultModeStatus(const Ftm_Pwm_Ip_HwAddrType * FtmBase)
{
    return (uint32)(FtmBase->FMS);
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_SetFaultModeStatus
 * Description   : Set fault mode status
 */
static inline void Ftm_Pwm_Ip_SetFaultModeStatus(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                 uint32                        Value)
{
    FtmBase->FMS = (uint32)Value;
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_IsEnableFaultControlMode
 * Description   : Get MODE_FAULTM bit 
 */
static inline boolean Ftm_Pwm_Ip_IsEnableFaultControlMode(const Ftm_Pwm_Ip_HwAddrType * FtmBase)
{
    return ((FtmBase->MODE & FTM_MODE_FAULTM_MASK) >> FTM_MODE_FAULTM_SHIFT) != 0U;
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_IsEnableFaultInput
 * Description   : Get FLTCTRL_FAULTxEN bit 
 */
static inline boolean Ftm_Pwm_Ip_IsEnableFaultInput(const Ftm_Pwm_Ip_HwAddrType * FtmBase)
{
    return (FtmBase->FLTCTRL & 0xFU) != 0U;
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_SetFaultFilterValue
 * Description   : Selects the filter value for the fault inputs.
 */
static inline void Ftm_Pwm_Ip_SetFaultFilterValue(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  uint8                         FaultFilterValue)
{
    FtmBase->FLTCTRL = (FtmBase->FLTCTRL & ~FTM_FLTCTRL_FFVAL_MASK) | FTM_FLTCTRL_FFVAL((uint32)FaultFilterValue);
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_SetFaultOutputState
 * Description   : Selects the fault output state when a fault event is ongoing.
 */
static inline void Ftm_Pwm_Ip_SetFaultOutputState(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                                  Ftm_Pwm_Ip_FaultOutputStateType FaultState)
{
    FtmBase->FLTCTRL = (FtmBase->FLTCTRL & ~FTM_FLTCTRL_FSTATE_MASK) | FTM_FLTCTRL_FSTATE((FaultState == FTM_PWM_IP_OUT_SAFE_VALUE)? 0x00U : 0x01U);
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_SetFaultPolarity
 * Description   : Selects the fault inputs polarity.
 */
static inline void Ftm_Pwm_Ip_SetFaultPolarity(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               uint8                         FaultId,
                                               Ftm_Pwm_Ip_PolarityType       FaultPol)
{
    uint32 FaultInPol = ((FaultPol == FTM_PWM_IP_POLARITY_HIGH)? (uint32)0U : (uint32)1U);
    FtmBase->FLTPOL = (FtmBase->FLTPOL & ~(1UL << FaultId)) | ((uint32)FaultInPol << FaultId);
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_SetFaultInputEn
 * Description   : Enables/Disables the fault inputs.
 */
static inline void Ftm_Pwm_Ip_SetFaultInputEn(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               uint8                        FaultId,
                                               boolean                      FaultEn)
{
    uint32 FaultInEn = ((FaultEn == TRUE)? (uint32)1U : (uint32)0U);
    FtmBase->FLTCTRL = (FtmBase->FLTCTRL & ~(1UL << FaultId)) | ((uint32)FaultInEn << FaultId);
}

/*!
 *
 * Function Name : Ftm_Pwm_Ip_SetFaultFilterEn
 * Description   : Enables/Disables the filter for the fault input.
 */
static inline void Ftm_Pwm_Ip_SetFaultFilterEn(Ftm_Pwm_Ip_HwAddrType * const FtmBase,
                                               uint8                         FaultId,
                                               boolean                       FaultFilEn)
{
    uint32 FaultFilterEn = ((FaultFilEn == TRUE)? (uint32)1U : (uint32)0U);
    FtmBase->FLTCTRL = (FtmBase->FLTCTRL & ~((uint32)FTM_FLTCTRL_FFLTR0EN_MASK << FaultId)) | (((uint32)FaultFilterEn << FaultId) << FTM_FLTCTRL_FFLTR0EN_SHIFT);
}

#endif

#if (defined(FTM_PWM_IP_SIM_AVAILABLE) && (FTM_PWM_IP_SIM_AVAILABLE == STD_ON))
/*!
 *
 * Function Name : Ftm_Pwm_Ip_SetSimOutputBufferEn
 * Description   : The FTM channel output state is retained when the channel is in output mode.
 */
static inline void Ftm_Pwm_Ip_SetSimOutputBufferEn(Ftm_Pwm_Ip_SimType * const SimBase,
                                                   uint8                      Instance)
{
    SimBase->MISCTRL0 = (SimBase->MISCTRL0  & ~(uint32)((uint32)SIM_MISCTRL0_FTM0_OBE_CTRL_MASK << Instance)) | (uint32)((uint32)SIM_MISCTRL0_FTM0_OBE_CTRL_MASK << Instance);
}
#endif

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/*! @}*/

#endif /* FTM_PWM_IP_HWACCESS_H */
