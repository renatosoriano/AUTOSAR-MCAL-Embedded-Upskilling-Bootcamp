/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Ftm_Srtc_Lptmr_LPit
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 2.0.0
* Build Version : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
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
/**
*   @file           SRtc_Ip.c
*
*   @addtogroup     srtc_ip Rtc IPL
*
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
#include "SRtc_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SRTC_IP_VENDOR_ID_C                    43
#define SRTC_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define SRTC_IP_AR_RELEASE_MINOR_VERSION_C     7
#define SRTC_IP_AR_RELEASE_REVISION_VERSION_C  0
#define SRTC_IP_SW_MAJOR_VERSION_C             2
#define SRTC_IP_SW_MINOR_VERSION_C             0
#define SRTC_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (SRTC_IP_VENDOR_ID_C != SRTC_IP_VENDOR_ID)
    #error "SRtc_Ip.c and SRtc_Ip.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION_C != SRTC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SRTC_IP_AR_RELEASE_MINOR_VERSION_C != SRTC_IP_AR_RELEASE_MINOR_VERSION) || \
     (SRTC_IP_AR_RELEASE_REVISION_VERSION_C != SRTC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SRtc_Ip.h and SRtc_Ip.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((SRTC_IP_SW_MAJOR_VERSION_C != SRTC_IP_SW_MAJOR_VERSION) || \
     (SRTC_IP_SW_MINOR_VERSION_C != SRTC_IP_SW_MINOR_VERSION) || \
     (SRTC_IP_SW_PATCH_VERSION_C != SRTC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SRtc_Ip.c and SRtc_Ip.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if (SRTC_IP_USED == STD_ON)


#define GPT_START_SEC_CONST_8
#include "Gpt_MemMap.h"
/** @brief  Table of month length (in days) for the Un-leap-year*/
static const uint8 ULY[] = {0U, 31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};

/** @brief Table of month length (in days) for the Leap-year*/
static const uint8 LY[] = {0U, 31U, 29U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};
#define GPT_STOP_SEC_CONST_8
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_16
#include "Gpt_MemMap.h"
/** @brief Number of days from begin of the non Leap-year*/
static const uint16 MONTH_DAYS[] = {0U, 0U, 31U, 59U, 90U, 120U, 151U, 181U, 212U, 243U, 273U, 304U, 334U};
#define GPT_STOP_SEC_CONST_16
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"
/**
* @brief          array variable used to store the runtime target time value.
*/
uint32 Srtc_Ip_u32TargetValue = 0U;

#define GPT_STOP_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Table of sRTC base pointers */
RTC_Type * const sRtcBase[RTC_INSTANCE_COUNT] = IP_RTC_BASE_PTRS;
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Global array variable used to channel state for process common interrupt */
static Srtc_Ip_State Srtc_Ip_u32ChState[RTC_INSTANCE_COUNT] =  {
                                                                {
                                                                    (boolean)FALSE,
                                                                    0U,
                                                                    0U,
                                                                    (boolean)FALSE,
                                                                    (boolean)FALSE,
                                                                    NULL_PTR,
                                                                    0U,
                                                                    (boolean)FALSE,
                                                                    (boolean)FALSE,
                                                                    NULL_PTR,
                                                                    0U,
                                                                    SRTC_IP_CH_MODE_CONTINUOUS
                                                                }
                                                            };
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef SRTC_0_CH_0_ISR_USED
ISR(SRTC_0_Ch_0_ISR);
static void Srtc_Ip_ProcessAlarmInterrupt(uint8 instance);
static void Srtc_Ip_ProcessInterrupt(uint8 instance);
#endif
static inline void Srtc_Ip_SetTimeSecondsRegVal(uint8 instance, uint32 value);
static inline void Srtc_Ip_SetTimeAlarmRegVal(uint8 instance, uint32 value);
static inline void Srtc_Ip_SetSoftwareResetFlag(uint8 instance, boolean aboEn);
static inline void Srtc_Ip_SetTimeCounterEnable(uint8 instance, boolean aboEn);
static inline boolean Srtc_Ip_IsTimerEnabled(uint8 instance);
static inline void Srtc_Ip_SelectClock(RTC_Type * const base, Srtc_Ip_ClockSelectType clockSelect);
static inline void Srtc_Ip_SelectClockOut(RTC_Type * const base, Srtc_Ip_ClockOutType clockOut);
#if (defined (SRTC_IP_ENABLE_COMPENSATION_SUPPORT) && (SRTC_IP_ENABLE_COMPENSATION_SUPPORT == STD_ON))
static inline void Srtc_Ip_SetCompensationInterval(RTC_Type * const base, uint8 interval);
static inline void Srtc_Ip_SetCompensationRegister(RTC_Type * const base, uint8 value);
#endif
static inline Srtc_Ip_StatusType Srtc_Ip_SetSecondsInterruptConfiguration(uint8 instance, Srtc_Ip_SecIntFreqType occursFrequency);
static boolean Srtc_Ip_IsYearLeap(uint16 year);
static boolean Srtc_Ip_IsTimeDateCorrectFormat(const Srtc_Ip_TimedateType *timeDate);
#if ((defined(MCAL_SRTC_REG_PROT_AVAILABLE) && (STD_ON == MCAL_SRTC_REG_PROT_AVAILABLE)) && (STD_ON == SRTC_IP_ENABLE_USER_MODE_SUPPORT))
void Srtc_Ip_SetUserAccessAllowed(void);
#endif
#if (STD_ON == SRTC_IP_ENABLE_LOCK_REGISTER_API)
static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureLockRegLock(RTC_Type * const base);
static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureStatusRegLock(RTC_Type * const base);
static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureControlRegLock(RTC_Type * const base);
static inline Srtc_Ip_StatusType Srtc_Ip_TimeControlRegLock(RTC_Type * const base);
static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureLockReg(RTC_Type * const base, Srtc_Ip_LockRegSelectType lockReg);
#endif

static void Srtc_Ip_ClearTimeInvalidAndOverflowFlags(uint8 instance);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief
 * Function Name : Srtc_Ip_GetInterruptEnableFlag
 * Description   : Get the status of Time Seconds Interrupt Enable (TSIE), Time Alarm Interrupt Enable (TAIE),
 *                 Time Overflow Interrupt Enable (TOIE) and Time Invalid Interrupt Enable (TIIE): RTC Interrupt Enable Register (IER)
 *
 * @details
 * Time Seconds Interrupt Enable: TSIE
 *  The seconds interrupt is an edge-sensitive interrupt with a dedicated interrupt vector.
 *  It is generated at least once a second and requires no software overhead (there is no corresponding status flag to clear).
 *  The frequency of the seconds interrupt is configured by TSIC.
 *      0b - Seconds interrupt is disabled.
 *      1b - Seconds interrupt is enabled.
 * Time Alarm Interrupt Enable: TAIE
 *  0b - Time alarm flag does not generate an interrupt.
 *  1b - Time alarm flag does generate an interrupt.
 * Time Overflow Interrupt Enable: TOIE
 *      0b - Time overflow flag does not generate an interrupt.
 *      1b - Time overflow flag does generate an interrupt.
 * Time Invalid Interrupt Enable: TIIE
 * 0b - Time invalid flag does not generate an interrupt.
 * 1b - Time invalid flag does generate an interrupt.
 * @param[in]   instance        RTC hw instance number
 * @param[in]   interruptMode   Enum containing RTC interrupt type
 *
 * @return  TRUE if an interrupt is enabled, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
static inline boolean Srtc_Ip_GetInterruptEnableFlag(uint8 instance, Srtc_Ip_InterruptType interruptMode)
{
    boolean returnFlag;
    /* Check all RTC Interrupt Enable flags */
    switch(interruptMode)
    {
        case SRTC_IP_INVALID_INTERRUPT:
        {
            returnFlag = (0U != (sRtcBase[instance]->IER & RTC_IER_TIIE_MASK)) ? TRUE : FALSE;
        }
        break;
        case SRTC_IP_OVERFLOW_INTERRUPT:
        {
            returnFlag = (0U != (sRtcBase[instance]->IER & RTC_IER_TOIE_MASK)) ? TRUE : FALSE;
        }
        break;
        case SRTC_IP_ALARM_INTERRUPT:
        {
            returnFlag = (0U != (sRtcBase[instance]->IER & RTC_IER_TAIE_MASK)) ? TRUE : FALSE;
        }
        break;
        case SRTC_IP_SECONDS_INTERRUPT:
        {
            returnFlag = (0U != (sRtcBase[instance]->IER & RTC_IER_TSIE_MASK)) ? TRUE : FALSE;
        }
        break;
        default:
        {
            returnFlag = FALSE;
        }
        break;
    }

    return returnFlag;
}

/**
 * @brief
 * Function Name : Srtc_Ip_SetInterruptEnableFlag
 * Description   : Set or Clear one the flags from RTC Interrupt Enable Register (IER):
 *                 Time Seconds Interrupt Enable (TSIE), Time Alarm Interrupt Enable (TAIE),
 *                 Time Overflow Interrupt Enable (TOIE) or Time Invalid Interrupt Enable (TIIE)
 *
 * @param[in]   instance        RTC hw instance number
 * @param[in]   interruptMode   Enum containing RTC interrupt type
 * @param[in]   aboEn - Enables the RTC Interrupt
 *              - True : Enable the RTC Interrupt.
 *              - False: Disable the RTC Interrupt.
 *
 * @return  none
 * @pre     The driver needs to be initialized.
 */
static inline void Srtc_Ip_SetInterruptEnableFlag(uint8 instance, Srtc_Ip_InterruptType interruptMode, boolean aboEn)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_60();
    switch(interruptMode)
    {
        case SRTC_IP_INVALID_INTERRUPT:
        {
            sRtcBase[instance]->IER = (sRtcBase[instance]->IER & ~(RTC_IER_TIIE_MASK)) | RTC_IER_TIIE((TRUE == aboEn) ? 1UL : 0UL);
        }
        break;
        case SRTC_IP_OVERFLOW_INTERRUPT:
        {
            sRtcBase[instance]->IER = (sRtcBase[instance]->IER & ~(RTC_IER_TOIE_MASK)) | RTC_IER_TOIE((TRUE == aboEn) ? 1UL : 0UL);
        }
        break;
        case SRTC_IP_ALARM_INTERRUPT:
        {
            sRtcBase[instance]->IER = (sRtcBase[instance]->IER & ~(RTC_IER_TAIE_MASK)) | RTC_IER_TAIE((TRUE == aboEn) ? 1UL : 0UL);
        }
        break;
        case SRTC_IP_SECONDS_INTERRUPT:
        {
            sRtcBase[instance]->IER = (sRtcBase[instance]->IER & ~(RTC_IER_TSIE_MASK)) | RTC_IER_TSIE((TRUE == aboEn) ? 1UL : 0UL);
        }
        break;
        default:
        {
            /* do nothing */
        }
        break;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_60();
}

/**
 * @brief
 * Function Name : Srtc_Ip_GetEnableAndStatusInterruptFlags
 * Description   : Get the Enable and Status Interrupt Flags
 *
 * @param[in]   instance        RTC hw instance number
 * @param[in]   interruptMode   Enum containing RTC interrupt type
 *
 * @return  TRUE if an interrupt has occurred and it is enabled, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
static boolean Srtc_Ip_GetEnableAndStatusInterruptFlags(uint8 instance, Srtc_Ip_InterruptType interruptMode)
{
    boolean interruptStatusFlag = Srtc_Ip_GetInterruptStatusFlag(instance, interruptMode);
    boolean interruptEnableFlag = Srtc_Ip_GetInterruptEnableFlag(instance, interruptMode);

    return (interruptStatusFlag && interruptEnableFlag) ? TRUE : FALSE;
}

/**
 * @brief
 * Function Name : Srtc_Ip_SetTimeSecondsRegVal
 * Description   : Set RTC Time Seconds Register (TSR)
 *
 * @details
 *  Time Seconds Register: TSR
 *      When the time counter is enabled, the TSR is read only and increments once a second provided
 *      SR[TOF] or SR[TIF] are not set. The time counter will read as zero when SR[TOF] or SR[TIF] are set.
 *      When the time counter is disabled, the TSR can be read or written. Writing to the TSR when the time
 *      counter is disabled will clear the SR[TOF] and/or the SR[TIF]. Writing to TSR with zero is supported, but
 *      not recommended because TSR will read as zero when SR[TIF] or SR[TOF] are set (indicating the time is invalid).
 *
 * @param[in]   instance    RTC hw instance number
 * @param[in]   value
 *
 * @return      void
 *
 */
static inline void Srtc_Ip_SetTimeSecondsRegVal(uint8 instance, uint32 value)
{
    sRtcBase[instance]->TSR = (uint32)((value << RTC_TSR_TSR_SHIFT) & RTC_TSR_TSR_MASK);
}

/**
 * @brief
 * Function Name : Srtc_Ip_SetTimeAlarmRegVal
 * Description   : Set RTC Time Alarm Register (TAR)
 *
 * @details
 *  RTC Time Alarm Register: TAR
 *      When the time counter is enabled, the SR[TAF] is set whenever the TAR[TAR] equals the TSR[TSR] and the TSR[TSR] increments.
 *      Writing to the TAR clears the SR[TAF].
 *
 * @param[in]   instance    RTC hw instance number
 * @param[in]   value
 *
 * @return      void
 *
 */
static inline void Srtc_Ip_SetTimeAlarmRegVal(uint8 instance, uint32 value)
{
    sRtcBase[instance]->TAR = (uint32)((value << RTC_TAR_TAR_SHIFT) & RTC_TAR_TAR_MASK);
}

/**
 * @brief
 * Function Name : Srtc_Ip_SetSoftwareResetFlag
 * Description   : Set or Clear the Software Reset Flag (SWR) from RTC Control Register (CR)
 *
 * @details
 * Software Reset: SWR
 *      0b - No effect.
 *      1b - Resets all RTC registers except for the SWR bit. The SWR bit is cleared by POR and by software explicitly clearing it.
 *
 * @param[in]   instance    RTC hw instance number
 * @param[in]   aboEn - Set or Clear the Software Reset Flag
 *
 * @return  none
 * @pre     The driver needs to be initialized.
 */
static inline void Srtc_Ip_SetSoftwareResetFlag(uint8 instance, boolean aboEn)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_64();
    sRtcBase[instance]->CR = (sRtcBase[instance]->CR & ~(RTC_CR_SWR_MASK)) | RTC_CR_SWR((TRUE == aboEn) ? 1UL : 0UL);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_64();
}

#if ((defined(MCAL_SRTC_REG_PROT_AVAILABLE) && (STD_ON == MCAL_SRTC_REG_PROT_AVAILABLE)) && (STD_ON == SRTC_IP_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief
 * Function Name : Srtc_Ip_GetSoftwareResetFlag
 * Description   : Get the status of the Software Reset Flag (SWR) from RTC Control Register (CR)
 *
 * @param[in]   instance    RTC hw instance number
 *
 * @return  TRUE if Software Reset Flag is set, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */

static inline boolean Srtc_Ip_GetSoftwareResetFlag(uint8 instance)
{
    return (0U != (sRtcBase[instance]->CR & RTC_CR_SWR_MASK)) ? TRUE : FALSE;
}
#endif
/**
 * @brief
 * Function Name : Srtc_Ip_SetTimeCounterEnable
 * Description   : Set the Time Counter Enable bit
 *
 * @details
 *  Time Counter Enable: TCE
 *      When time counter is disabled the TSR register and TPR register are writeable, but do not increment.
 *      When time counter is enabled the TSR register and TPR register are not writeable, but increment.
 *          0b - Time counter is disabled.
 *          1b - Time counter is enabled.
 *
 * @param[in]   instance - RTC hw instance number
 * @param[in]   aboEn - Enables the Time Counter
 *
 * @return  none
 * @pre     The driver needs to be initialized.
 */
static inline void Srtc_Ip_SetTimeCounterEnable(uint8 instance, boolean aboEn)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_65();
    {
        sRtcBase[instance]->SR &= ~(RTC_SR_TCE_MASK);
        sRtcBase[instance]->SR |= RTC_SR_TCE((TRUE == aboEn) ? 1UL : 0UL);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_65();
}

/**
 * @brief
 * Function Name : Srtc_Ip_IsTimerEnabled
 * Description   : Get status of the Time Counter Enable bit
 *
 * @param[in]   instance - RTC hw instance number
 *
 * @return  TRUE if timer is enabled, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
static inline boolean Srtc_Ip_IsTimerEnabled(uint8 instance)
{
    return (0U != (sRtcBase[instance]->SR & RTC_SR_TCE_MASK)) ? TRUE : FALSE;
}

static inline void Srtc_Ip_SelectClock(RTC_Type * const base, Srtc_Ip_ClockSelectType clockSelect)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_66();
    switch(clockSelect)
    {
        case SRTC_IP_CLK_SRC_OSC_32KHZ:
        {
            /* Select clock source as 32KHZ */
            base->CR &= ~(uint32)(1UL << RTC_CR_LPOS_SHIFT);
        }
        break;
        case SRTC_IP_CLK_SRC_LPO_1KHZ:
        {
           /* Select clock source as 1KHZ */
            base->CR |= (uint32)(1UL << RTC_CR_LPOS_SHIFT);
        }
        break;
        default:
        {
            /* default branch, do nothing */
        }
        break;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_66();

}

static inline void Srtc_Ip_SelectClockOut(RTC_Type * const base, Srtc_Ip_ClockOutType clockOut)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_67();
    switch(clockOut)
    {
        case SRTC_IP_CLKOUT_DISABLED:
        {
            /* Disable the clock out pin */
            base->CR &= ~(uint32)(1UL << RTC_CR_CPE_SHIFT);
        }
        break;
        case SRTC_IP_CLKOUT_SRC_TSIC:
        {
            /* Select clock out source as Time Seconds Interrupt and enable the pin */
            base->CR |= (uint32)(1UL << RTC_CR_CPE_SHIFT);
            base->CR &= ~(uint32)(1UL << RTC_CR_CPS_SHIFT);
        }
        break;
        case SRTC_IP_CLKOUT_SRC_32KHZ:
        {
            /* Select clock out source as the 32 KHz clock and enable the pin */
            base->CR |= (uint32)(1UL << RTC_CR_CPE_SHIFT);
            base->CR |= (uint32)(1UL << RTC_CR_CPS_SHIFT);
        }
        break;
        default:
        {
            /* default branch, do nothing */
        }
        break;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_67();
}

#if (defined (SRTC_IP_ENABLE_COMPENSATION_SUPPORT) && (SRTC_IP_ENABLE_COMPENSATION_SUPPORT == STD_ON))
static inline void Srtc_Ip_SetCompensationInterval(RTC_Type * const base, uint8 interval)
{
    /* Set Compensation Interval */
    base->TCR = (base->TCR & ~RTC_TCR_CIR_MASK) | RTC_TCR_CIR(interval);
}

static inline void Srtc_Ip_SetCompensationRegister(RTC_Type * const base, uint8 value)
{
    /* Set Compensation Register */
    base->TCR = (base->TCR & ~RTC_TCR_TCR_MASK) | RTC_TCR_TCR(value);
}
#endif

static inline Srtc_Ip_StatusType Srtc_Ip_SetSecondsInterruptConfiguration(uint8 instance, Srtc_Ip_SecIntFreqType occursFrequency)
{
    Srtc_Ip_StatusType status;
    
    /* check if TimeSecondsInterrupt is enabled */
    if (FALSE == Srtc_Ip_GetInterruptEnableFlag(instance, SRTC_IP_SECONDS_INTERRUPT))
    {
        /* set frequency for TimeSeconds */
        sRtcBase[instance]->IER = (sRtcBase[instance]->IER & ~RTC_IER_TSIC_MASK) | RTC_IER_TSIC(occursFrequency);
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;
}

static boolean Srtc_Ip_IsYearLeap(uint16 year)
{
    boolean returnValue;

    if ((year % 4U) > 0U)
    {
        returnValue = FALSE;
    }
    else if ((year % 100U) > 0U)
    {
        returnValue = TRUE;
    }
    else if ((year % 400U) > 0U)
    {
        returnValue = FALSE;
    }
    else
    {
        returnValue = TRUE;
    }

    /* Return the exit code */
    return returnValue;
}

static boolean Srtc_Ip_IsTimeDateCorrectFormat(const Srtc_Ip_TimedateType *timeDate)
{

    /* Declare local variables */
    boolean returnValue;
    const uint8 * pDays;

    /* Set the days-in-month table for the corresponding year */
    pDays = Srtc_Ip_IsYearLeap(timeDate->year) ? (LY) : (ULY);

    /* Check if the time and date are in the correct ranges */
    if ((timeDate->year < YEAR_RANGE_START) || (timeDate->year > YEAR_RANGE_END)
            ||  (timeDate->month < 1U) || (timeDate->month > 12U)
            ||  (timeDate->day < 1U) || (timeDate->day > 31U)
            ||  (timeDate->hour >= HOURS_IN_A_DAY)
            ||  (timeDate->minutes >= MINS_IN_A_HOUR) || (timeDate->seconds >= SECONDS_IN_A_MIN))
    {
        returnValue = FALSE;
    }
    /* Check if the day is a valid day from the corresponding month */
    else if (timeDate->day > pDays[timeDate->month])
    {
        returnValue = FALSE;
    }
    else
    {
        returnValue = TRUE;
    }

    /* Return the exit code */
    return returnValue;
}

#if ((defined(MCAL_SRTC_REG_PROT_AVAILABLE) && (STD_ON == MCAL_SRTC_REG_PROT_AVAILABLE)) && (STD_ON == SRTC_IP_ENABLE_USER_MODE_SUPPORT))
void Srtc_Ip_SetUserAccessAllowed(void)
{
    uint8 instance = 0U;
    /* Check Software Reset */
    if (TRUE == Srtc_Ip_GetSoftwareResetFlag(instance))
    {
        /* Clear Software Reset */
        Srtc_Ip_SetSoftwareResetFlag(instance, FALSE);
    }
    /* Non-supervisor mode write accesses are supported. */
    sRtcBase[instance]->CR |= RTC_CR_SUP_MASK;
}
#endif

/*================================================================================================*/
#ifdef SRTC_0_CH_0_ISR_USED
/**
* @brief        Srtc_Ip_ProcessAlarmInterrupt.
*
* @param[in]    channel hardware channel index
*/
static void Srtc_Ip_ProcessAlarmInterrupt(uint8 instance)
{
    uint32 counterValue;

    boolean                 chInit = Srtc_Ip_u32ChState[instance].chInit;
    Srtc_Ip_CallbackType    callback = Srtc_Ip_u32ChState[instance].callback;
    uint8                   callbackParam = Srtc_Ip_u32ChState[instance].callbackParam;
    boolean                 alarmIntEnable = Srtc_Ip_u32ChState[instance].alarmIntEnable;
    uint32                  numberOfRepeats = Srtc_Ip_u32ChState[instance].numberOfRepeats;
    boolean                 repeatForever = Srtc_Ip_u32ChState[instance].repeatForever;
    Srtc_Ip_CallbackType    alarmCallback = Srtc_Ip_u32ChState[instance].alarmCallback;
    uint8                   callbackParams = Srtc_Ip_u32ChState[instance].callbackParams;

    /* Compute next Time Alarm */
    uint32 newAlarmTime = Srtc_Ip_GetTimeAlarmRegister(instance) + Srtc_Ip_u32TargetValue;

    /* Set New Time Alarm, and this also clears the TAF flag */
    Srtc_Ip_SetTimeAlarmRegVal(instance, newAlarmTime);

    /* Call upper layer handler */
    if ((TRUE == chInit) && (NULL_PTR != callback))
    {
        callback(callbackParam);
    } /* If the alarm interrupt configuration has been defined */
    else if (Srtc_Ip_u32ChState[instance].alarmInit && alarmIntEnable)
    {
        if ((0UL < numberOfRepeats) || repeatForever)
        {
            /* Get current time */
            counterValue = Srtc_Ip_GetTimeSecondsRegister(instance);
            /* Current time is incremented with the repetition value */
            newAlarmTime = counterValue + (Srtc_Ip_u32ChState[instance].repetitionInterval - 1U);
            /* Set new value to trigger the alarm */
            Srtc_Ip_SetTimeAlarmRegVal(instance, newAlarmTime);
            Srtc_Ip_u32ChState[instance].isAlarmTimeNew = TRUE;
            /* If the alarm repeats forever, set number of repeats to 0 to avoid an accidental trigger of the core overflow flag */
            Srtc_Ip_u32ChState[instance].numberOfRepeats = !repeatForever ? (numberOfRepeats - 1UL) : 0UL;
        }
        else
        {
            Srtc_Ip_u32ChState[instance].isAlarmTimeNew = FALSE;
        }
        /* If the user has defined a callback, call it */
        if (NULL_PTR != alarmCallback)
        {
            alarmCallback(callbackParams);
        }
    }
    else
    {
        /* DO NOTHING */
    }
}

/**
* @brief        Srtc_Ip_ProcessInterrupt.
* @details      Function used by interrupt service routines to call notification
*               functions if provided and enabled
*
* @param[in]     channel      hardware channel index
* @implements    Srtc_Ip_ProcessInterrupt_Activity
*/
static void Srtc_Ip_ProcessInterrupt(uint8 instance)
{
    boolean alarmInterruptFlags;
    boolean invalidInterruptFlags;
    boolean overflowInterruptFlags;
    boolean secondsInterruptEnableFlag;

    boolean                 chInit;
    Srtc_Ip_CallbackType    callback;
    uint8                   callbackParam;

#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif
    if (instance < RTC_INSTANCE_COUNT)
    {
        /* enter critical section */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_61();
        {
            /* Check the status and interrupt enable flags */
            alarmInterruptFlags = Srtc_Ip_GetEnableAndStatusInterruptFlags(instance, SRTC_IP_ALARM_INTERRUPT);
            invalidInterruptFlags = Srtc_Ip_GetEnableAndStatusInterruptFlags(instance, SRTC_IP_INVALID_INTERRUPT);
            overflowInterruptFlags = Srtc_Ip_GetEnableAndStatusInterruptFlags(instance, SRTC_IP_OVERFLOW_INTERRUPT);

            secondsInterruptEnableFlag = Srtc_Ip_GetInterruptEnableFlag(instance, SRTC_IP_SECONDS_INTERRUPT);
            
            if (alarmInterruptFlags)
            {
                /* Cleare Time Alarm Flag (TAF) by writing the TAR register.
                    For Time Seconds Interrupt there is no corresponding status flag to clear */
                Srtc_Ip_SetTimeAlarmRegVal(instance, 0U);
            }

            if (invalidInterruptFlags || overflowInterruptFlags)
            {
                /* Configure TIF when POR or software reset */
                Srtc_Ip_ClearTimeInvalidAndOverflowFlags(instance);
            }
        }
        /* exit critical section */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_61();

        if (alarmInterruptFlags || invalidInterruptFlags || overflowInterruptFlags || secondsInterruptEnableFlag)
        {
            chInit = Srtc_Ip_u32ChState[instance].chInit;
            callback = Srtc_Ip_u32ChState[instance].callback;
            callbackParam = Srtc_Ip_u32ChState[instance].callbackParam;

            if (SRTC_IP_CH_MODE_ONESHOT == Srtc_Ip_u32ChState[instance].channelMode)
            {
                /* Stop counter */
                (void)Srtc_Ip_StopCounter(instance);
            }

            /* Check if TAF and TAIE */
            if (alarmInterruptFlags)
            {
                /* Process AlarmInterrupt */
                Srtc_Ip_ProcessAlarmInterrupt(instance);
            }
            else if (invalidInterruptFlags || overflowInterruptFlags || secondsInterruptEnableFlag)
            {
                /* Call callback notification */
                if ((TRUE == chInit) && (NULL_PTR != callback))
                {
                    callback(callbackParam);
                }
            }
            else
            {
                /* DO NOTHING */
            }
        }
    }
}
#endif
#if (STD_ON == SRTC_IP_ENABLE_LOCK_REGISTER_API)
static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureLockRegLock(RTC_Type * const base)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    if (1U == (((base->LR) & RTC_LR_LRL_MASK) >> RTC_LR_LRL_SHIFT))
    {
        base->LR &= (~(RTC_LR_LRL_MASK));
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;
}

static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureStatusRegLock(RTC_Type * const base)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    if (1U == (((base->LR) & RTC_LR_SRL_MASK) >> RTC_LR_SRL_SHIFT))
    {
        base->LR &= (~(RTC_LR_SRL_MASK));
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;
}

static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureControlRegLock(RTC_Type * const base)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    if (1U == (((base->LR) & RTC_LR_CRL_MASK) >> RTC_LR_CRL_SHIFT))
    {
        base->LR &= (~(RTC_LR_CRL_MASK));
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;
}

static inline Srtc_Ip_StatusType Srtc_Ip_TimeControlRegLock(RTC_Type * const base)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    if (1U == (((base->LR) & RTC_LR_TCL_MASK) >> RTC_LR_TCL_SHIFT))
    {
        base->LR &= (~(RTC_LR_TCL_MASK));
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;
}

static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureLockReg(RTC_Type * const base, Srtc_Ip_LockRegSelectType lockReg)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    switch (lockReg)
    {
        case SRTC_IP_LOCK_REG_LOCK:
        {
            status = Srtc_Ip_ConfigureLockRegLock(base);
        }
        break;
        case SRTC_IP_STATUS_REG_LOCK:
        {
            status = Srtc_Ip_ConfigureStatusRegLock(base);
        }
        break;
        case SRTC_IP_CTRL_REG_LOCK:
        {
            status = Srtc_Ip_ConfigureControlRegLock(base);
        }
        break;
        case SRTC_IP_TCL_REG_LOCK:
        {
            status = Srtc_Ip_TimeControlRegLock(base);
        }
        break;
        default:
        {
            /* If the register is not recognized, return error */
            status = SRTC_IP_ERROR;
        }
        break;
    }

    return status;
}
#endif

static void Srtc_Ip_ClearTimeInvalidAndOverflowFlags(uint8 instance)
{
    /* Check if TIF */
    boolean invalidinterruptStatusFlag = Srtc_Ip_GetInterruptStatusFlag(instance, SRTC_IP_INVALID_INTERRUPT);
    boolean overflowinterruptStatusFlag = Srtc_Ip_GetInterruptStatusFlag(instance, SRTC_IP_OVERFLOW_INTERRUPT);

    if (invalidinterruptStatusFlag || overflowinterruptStatusFlag)
    {
        /* Clear Software Reset */
        Srtc_Ip_SetSoftwareResetFlag(instance, FALSE);
        /* Disable time counter */
        Srtc_Ip_SetTimeCounterEnable(instance, FALSE);
        /* Clear the Time Invalid Flag (TIF) and Time Overflow Flag (TOF) by writing the TSR register when the time counter is disabled */
        Srtc_Ip_SetTimeSecondsRegVal(instance, 0U);
    }
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief
 * Function Name : Srtc_Ip_GetInterruptStatusFlag
 * Description   : Get the status of Time Invalid Flag (TIF),
 *                 Time Alarm Flag (TAF) and Time Overflow Flag (TOF): RTC Status Register (SR)
 *
 * @details
 * Time Alarm Flag: TAF
 *  Time alarm flag is set when the TAR[TAR] equals the TSR[TSR] and the TSR[TSR] increments.
 *  This bit is cleared by writing the TAR register.
 *      0b - Time alarm has not occurred.
 *      1b - Time alarm has occurred.
 * Time Overflow Flag: TOF
 *  Time overflow flag is set when the time counter is enabled and overflows.
 *  The TSR and TPR do not increment and read as zero when this bit is set.
 *  This bit is cleared by writing the TSR register when the time counter is disabled.
 *      0b - Time overflow has not occurred.
 *      1b - Time overflow has occurred and time counter is read as zero.
 * Time Invalid Flag: TIF
 *  The time invalid flag is set on POR or software reset.
 *  The TSR and TPR do not increment and read as zero when this bit is set.
 *  This bit is cleared by writing the TSR register when the time counter is disabled.
 *      0b - Time is valid.
 *      1b - Time is invalid and time counter is read as zero.
 *
 * @param[in]   instance        RTC hw instance number
 * @param[in]   interruptMode   Enum containing RTC interrupt type
 *
 * @return  TRUE if an interrupt has occurred, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
boolean Srtc_Ip_GetInterruptStatusFlag(uint8 instance, Srtc_Ip_InterruptType interruptMode)
{
    boolean returnFlag;
    /* Check all RTC interrupt flags */
    switch(interruptMode)
    {
        case SRTC_IP_INVALID_INTERRUPT:
        {
            returnFlag = (0U != (sRtcBase[instance]->SR & RTC_SR_TIF_MASK)) ? TRUE : FALSE;
        }
        break;
        case SRTC_IP_OVERFLOW_INTERRUPT:
        {
            returnFlag = (0U != (sRtcBase[instance]->SR & RTC_SR_TOF_MASK)) ? TRUE : FALSE;
        }
        break;
        case SRTC_IP_ALARM_INTERRUPT:
        {
            returnFlag = (0U != (sRtcBase[instance]->SR & RTC_SR_TAF_MASK)) ? TRUE : FALSE;
        }
        break;
        default:
        {
            returnFlag = FALSE;
        }
        break;
    }

    return returnFlag;
}

/*================================================================================================*/
uint32 Srtc_Ip_GetTimeSecondsRegister(uint8 instance)
{
    uint32 secondsRegisterValue = 0U;
    /* Get TimeSecondsRegister value */
    secondsRegisterValue = sRtcBase[instance]->TSR;
    return secondsRegisterValue;
}

uint32 Srtc_Ip_GetTimeAlarmRegister(uint8 instance)
{
    uint32 alarmRegisterValue = 0U;
    /* Get TimeAlarmRegister value */
    alarmRegisterValue = sRtcBase[instance]->TAR;
    return alarmRegisterValue;
}

/*================================================================================================*/
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                        - will convert seconds into time-date format.
*
* @param[in]     seconds         number of seconds
* @param[in]     *timeDate       pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_ConvertSecondsToTimeDate_Activity
*/
void Srtc_Ip_ConvertSecondsToTimeDate(const uint32 * const seconds,
                                      Srtc_Ip_TimedateType * const timeDate)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != seconds);
    DevAssert(NULL_PTR != timeDate);
#endif
    /* Declare the variables needed */
    uint8 index;
    boolean yearLeap;
    uint32 numberOfDays;
    uint32 tempSeconds;
    uint16 daysInYear;

    /* Because the starting year(1970) is not leap, set the daysInYear
     * variable with the number of the days in a normal year
     */
    daysInYear = DAYS_IN_A_YEAR;

    /* Set the year to the beginning of the range */
    timeDate->year = YEAR_RANGE_START;

    /* Get the number of days */
    numberOfDays = (*seconds) / SECONDS_IN_A_DAY;
    /* Get the number of seconds remaining */
    tempSeconds = (*seconds) % SECONDS_IN_A_DAY;

    /* Get the current hour */
    timeDate->hour        = (uint16)(tempSeconds / SECONDS_IN_A_HOUR);
    /* Get the remaining seconds */
    tempSeconds           = tempSeconds % SECONDS_IN_A_HOUR;
    /* Get the minutes */
    timeDate->minutes     = (uint16)(tempSeconds / SECONDS_IN_A_MIN);
    /* Get seconds */
    timeDate->seconds     = (uint8)(tempSeconds % SECONDS_IN_A_MIN);

    /* Get the current year */
    while (numberOfDays >= daysInYear)
    {
        /* Increment year if the number of days is greater than the ones in
         * one year
         */
        timeDate->year++;
        /* Subtract the number of the days */
        numberOfDays -= daysInYear;

        /* Check if the year is leap or unleap */
        if (!Srtc_Ip_IsYearLeap(timeDate->year))
        {
            /* Set the number of non leap year to the current year number
             * of days.
             */
            daysInYear = DAYS_IN_A_YEAR;
        }
        else
        {
            /* Set the number of leap year to the current year number
             * of days.
             */
            daysInYear = DAYS_IN_A_LEAP_YEAR;
        }
    }

    /* Add the current day */
    numberOfDays += 1U;

    /* Check if the current year is leap */
    yearLeap = Srtc_Ip_IsYearLeap(timeDate->year);

    /* Get the month */
    for (index = 1U; index <= 12U; index++)
    {
        uint32 daysInCurrentMonth = ((yearLeap == TRUE) ? (uint32)LY[index] : (uint32)ULY[index]);
        if (numberOfDays <= daysInCurrentMonth)
        {
            timeDate->month = (uint16)index;
            break;
        }
        else
        {
            numberOfDays -= daysInCurrentMonth;
        }

    }

    /* Set the current day */
    timeDate->day = (uint16)numberOfDays;
}

/*================================================================================================*/
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                        - will convert time-date into seconds.
*
* @param[in]     seconds         number of seconds
* @param[in]     *timeDate       pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_ConvertTimeDateToSeconds_Activity
*/
void Srtc_Ip_ConvertTimeDateToSeconds(const Srtc_Ip_TimedateType * const timeDate,
                                      uint32 * const seconds)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != seconds);
    DevAssert(NULL_PTR != timeDate);
#endif

    /* Declare local variables */
    uint16 year;

    /* Convert years to seconds */
    (*seconds) = (uint32)(DAYS_IN_A_YEAR * (uint32)(SECONDS_IN_A_DAY));
    (*seconds) *= ((uint32)timeDate->year - YEAR_RANGE_START);

    /* Add the seconds from the leap years */
    for (year = YEAR_RANGE_START; year < timeDate->year; year++)
    {
        if (Srtc_Ip_IsYearLeap(year))
        {
            (*seconds) += SECONDS_IN_A_DAY;
        }
    }

    /* If the current year is leap and 29th of February has passed, add
     * another day to seconds passed.
     */
    if ((Srtc_Ip_IsYearLeap(year)) && (timeDate->month > 2U))
    {
        (*seconds) += SECONDS_IN_A_DAY;
    }

    /* Add the rest of the seconds from the current month */
    (*seconds) += MONTH_DAYS[timeDate->month] * SECONDS_IN_A_DAY;
    /* Add the rest of the seconds from the current day */
    (*seconds) += (uint32)(((uint32)timeDate->day - 1U) * (uint32)SECONDS_IN_A_DAY);
    /* Add the rest of the seconds from the current time */
    (*seconds) += (uint32)(((uint32)timeDate->hour * SECONDS_IN_A_HOUR)   + \
                           ((uint32)timeDate->minutes * SECONDS_IN_A_MIN) + \
                            (uint32)timeDate->seconds);
}

/*================================================================================================*/
/**
* @brief   SRtc driver initialization function for SRtc module.
* @details This function:
*          - Disables the time counter
*          - Disables all interrupt modes
*          - Clears Time Invalid Flag
*          - Selects source Clock
*          - If compensation support is enabled sets the configured values
*          - Sets channel state variables
*
* @param[in]     instance     hw instance
* @param[in]     *config      pointer to configuration
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver
* @implements    Srtc_Ip_Init_Activity
*/
void Srtc_Ip_Init(uint8 instance, const Srtc_Ip_ConfigType *config)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != config);
#endif

#if ((defined(MCAL_SRTC_REG_PROT_AVAILABLE) && (STD_ON == MCAL_SRTC_REG_PROT_AVAILABLE)) && (STD_ON == SRTC_IP_ENABLE_USER_MODE_SUPPORT))
    /* Enables SRTC registers writing in User Mode */
    OsIf_Trusted_Call(Srtc_Ip_SetUserAccessAllowed);
#endif

    RTC_Type * base = sRtcBase[instance];

#if (defined (SRTC_IP_STANDBY_WAKEUP_SUPPORT) && (SRTC_IP_STANDBY_WAKEUP_SUPPORT == STD_ON))
    if (FALSE == Srtc_Ip_GetInterruptEnableFlag(instance, SRTC_IP_ALARM_INTERRUPT))
    {
#endif
        /* Disable time counter */
        Srtc_Ip_SetTimeCounterEnable(instance, FALSE);
        /* Disable all interrupt modes */
        Srtc_Ip_SetInterruptEnableFlag(instance, SRTC_IP_INVALID_INTERRUPT, FALSE);
        Srtc_Ip_SetInterruptEnableFlag(instance, SRTC_IP_OVERFLOW_INTERRUPT, FALSE);
        Srtc_Ip_SetInterruptEnableFlag(instance, SRTC_IP_ALARM_INTERRUPT, FALSE);
        /* On POR, TIF is set. The TSR ans TPR do not increment. */
        /* Clear the Time Invalid Flag (TIF) and Time Overflow Flag (TOF) by writing the TSR register when the time counter is disabled */
        Srtc_Ip_SetTimeSecondsRegVal(instance, 0U);
#if (defined (SRTC_IP_STANDBY_WAKEUP_SUPPORT) && (SRTC_IP_STANDBY_WAKEUP_SUPPORT == STD_ON))
    }
#endif
    /* Setup the RTC instance as configured in the structure */
    Srtc_Ip_SelectClock(base, config->clockSelect);
    Srtc_Ip_SelectClockOut(base, config->clockOutSelect);
#if (defined (SRTC_IP_ENABLE_COMPENSATION_SUPPORT) && (SRTC_IP_ENABLE_COMPENSATION_SUPPORT == STD_ON))
    /* If compensation support is enabled sets the configured values */
    Srtc_Ip_SetCompensationInterval(base, config->compensationInterval);
    Srtc_Ip_SetCompensationRegister(base, config->compensation);
#endif
    /* Set channel state variables */
    Srtc_Ip_u32ChState[instance].chInit = TRUE;
    Srtc_Ip_u32ChState[instance].callback = config->callback;
    Srtc_Ip_u32ChState[instance].callbackParam = config->callbackParam;
    Srtc_Ip_u32ChState[instance].channelMode = config->channelMode;
    Srtc_Ip_u32TargetValue = 0U;
}

/*================================================================================================*/
/**
* @brief         SRtc driver de-initialization function
* @details       This function:
*                       - Performs a software reset
*                       - Clears global variables
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Srtc_Ip_DeInit_Activity
*/
void Srtc_Ip_DeInit(uint8 instance)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    /* Perform a software reset */
    Srtc_Ip_SetSoftwareResetFlag(instance, TRUE);
    /* Clear global variables */
    Srtc_Ip_u32TargetValue = 0U;
}

/*================================================================================================*/
/**
* @brief         SRtc Driver function for starting the Rtc counter.
* @details       This function:
*                           - Enables the counter
* @param[in]     instance            Rtc hw instance
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_StartCounter_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_StartCounter(uint8 instance)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    Srtc_Ip_StatusType status;

    if (FALSE == Srtc_Ip_IsTimerEnabled(instance))
    {
        Srtc_Ip_SetTimeCounterEnable(instance, TRUE);
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }
    return status;
}

/*================================================================================================*/
/**
* @brief         SRtc Driver function for stopping the Rtc counter.
* @details       This function:
*                           - Disables Time Alarm Interrupt
*                           - Clears interrupt flag
*                           - Disables the counter
* @param[in]     instance            Rtc hw instance
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_StopCounter_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_StopCounter(uint8 instance)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif
    uint32 timeAlarmValue;
    Srtc_Ip_StatusType status;
#ifdef ERR_IPV_RTC_ERR010716
#if ERR_IPV_RTC_ERR010716 == STD_ON
    boolean alarminterruptStatusFlag;
#endif
#endif

    if (TRUE == Srtc_Ip_IsTimerEnabled(instance))
    {
        /* Disable Time Alarm Interrupt */
        Srtc_Ip_DisableInterrupt(instance, SRTC_IP_ALARM_INTERRUPT);
        /* Get current Timer Alarm Value */
        timeAlarmValue = Srtc_Ip_GetTimeAlarmRegister(instance);
        /* Make sure that the time alarm interrupt flag was pending cleared */
        /* Clear TAF by writing to the TAR register */
        Srtc_Ip_SetTimeAlarmRegVal(instance, timeAlarmValue);

#ifdef ERR_IPV_RTC_ERR010716
#if ERR_IPV_RTC_ERR010716 == STD_ON
        /* Check the status and interrupt enable flags */
        alarminterruptStatusFlag = Srtc_Ip_GetInterruptStatusFlag(instance, SRTC_IP_ALARM_INTERRUPT);
        if (alarminterruptStatusFlag)
        {
            /* Clear TAF by writing to the TAR register */
            Srtc_Ip_SetTimeAlarmRegVal(instance, timeAlarmValue);
        }
#endif
#endif

        Srtc_Ip_SetTimeCounterEnable(instance, FALSE);
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;

}

/*================================================================================================*/
/**
* @brief         SRtc Driver function for starting the Rtc timer channel with a timeout value.
* @details       This function:
*                       - Disables counter
*                       - Disables Time Alarm Interrupt
*                       - Gets Time Seconds Register value
*                       - Calculates new compare value
*                       - Sets Time Alarm Register
*                       - Enables Time Alarm Interrupt
*                       - Enables counter
*
* @param[in]     instance         Rtc hw instance
*                value            channel time-out value
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Srtc_Ip_StartTimer_Activity
*/
void Srtc_Ip_StartTimer(uint8 instance, uint32 value)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    uint32 counterValue = 0U;
    Srtc_Ip_u32TargetValue = value;

    /* Disable counter */
    Srtc_Ip_SetTimeCounterEnable(instance, FALSE);
    /* Disable Time Alarm Interrupt */
    Srtc_Ip_SetInterruptEnableFlag(instance, SRTC_IP_ALARM_INTERRUPT, FALSE);
    /* Get Time Seconds Register value */
    counterValue = Srtc_Ip_GetTimeSecondsRegister(instance);
    /* Calculate new compare value */
    counterValue = counterValue + value - 1U;
    /* Set Time Alarm Register */
    Srtc_Ip_SetTimeAlarmRegVal(instance, counterValue);
    /* Enable Time Alarm Interrupt */
    Srtc_Ip_SetInterruptEnableFlag(instance, SRTC_IP_ALARM_INTERRUPT, TRUE);
    /* Enable counter */
    Srtc_Ip_SetTimeCounterEnable(instance, TRUE);

}

/*================================================================================================*/
/**
* @brief         SRtc Driver function for enabling interrupt for RTC channel
* @details       This function:
*                        - Enables Interrupt for RTC channel based on selected mode
*
* @param[in]     instance        Rtc hw instance
*                interruptMode   Rtc hw interrupt mode
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_EnableInterrupt_Activity
*/
void Srtc_Ip_EnableInterrupt(uint8 instance, Srtc_Ip_InterruptType interruptMode)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    uint32 timeAlarmValue = 0U;
    boolean alarminterruptStatusFlag;
    switch(interruptMode)
    {
        case SRTC_IP_INVALID_INTERRUPT:
        case SRTC_IP_OVERFLOW_INTERRUPT:
        case SRTC_IP_SECONDS_INTERRUPT:
        {
            Srtc_Ip_SetInterruptEnableFlag(instance, interruptMode, TRUE);
        }
        break;
        case SRTC_IP_ALARM_INTERRUPT:
        {
            /* Check the status and interrupt enable flags */
            alarminterruptStatusFlag = Srtc_Ip_GetInterruptStatusFlag(instance, SRTC_IP_ALARM_INTERRUPT);
            if (!alarminterruptStatusFlag)
            {
                /* Get current Timer Alarm Value */
                timeAlarmValue = Srtc_Ip_GetTimeAlarmRegister(instance);
                /* Clear TAF by writing to the TAR register */
                Srtc_Ip_SetTimeAlarmRegVal(instance, timeAlarmValue);

#ifdef ERR_IPV_RTC_ERR010716
#if ERR_IPV_RTC_ERR010716 == STD_ON
                /* Get current Timer Alarm Value */
                timeAlarmValue = Srtc_Ip_GetTimeAlarmRegister(instance);
                alarminterruptStatusFlag = Srtc_Ip_GetInterruptStatusFlag(instance, SRTC_IP_ALARM_INTERRUPT);
                if (alarminterruptStatusFlag)
                {
                    /* Clear TAF by writing to the TAR register */
                    Srtc_Ip_SetTimeAlarmRegVal(instance, timeAlarmValue);
                }
#endif
#endif
                /* Enabled TimeAlarmInterrupt */
                Srtc_Ip_SetInterruptEnableFlag(instance, interruptMode, TRUE);
            }
        }
        break;
        default:
        {
            /* do nothing */
        }
        break;
    }
}
/*================================================================================================*/
/**
*
* @brief         SRtc Driver function for Disable Interrupt for RTC channel
* @details       This function:
*                        - Disable Interrupt for RTC channel based on selected mode
*
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_DisableInterrupt_Activity
*/
void Srtc_Ip_DisableInterrupt(uint8 instance, Srtc_Ip_InterruptType interruptMode)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

#ifdef ERR_IPV_RTC_ERR010716
#if ERR_IPV_RTC_ERR010716 == STD_ON
    boolean alarminterruptStatusFlag;
#endif
#endif

    uint32 timeAlarmValue = 0U;

    switch(interruptMode)
    {
        case SRTC_IP_INVALID_INTERRUPT:
        case SRTC_IP_OVERFLOW_INTERRUPT:
        case SRTC_IP_SECONDS_INTERRUPT:
        {
            Srtc_Ip_SetInterruptEnableFlag(instance, interruptMode, FALSE);
        }
        break;
        case SRTC_IP_ALARM_INTERRUPT:
        {
            /* Time Alarm Interrupt Disable */
            Srtc_Ip_SetInterruptEnableFlag(instance, interruptMode, FALSE);
            /* Get current Timer Alarm Value */
            timeAlarmValue = Srtc_Ip_GetTimeAlarmRegister(instance);
            /* Clear TAF by writing to the TAR register */
            Srtc_Ip_SetTimeAlarmRegVal(instance, timeAlarmValue);

#ifdef ERR_IPV_RTC_ERR010716
#if ERR_IPV_RTC_ERR010716 == STD_ON
            /* Get current Timer Alarm Value */
            timeAlarmValue = Srtc_Ip_GetTimeAlarmRegister(instance);
            /* Check the status and interrupt enable flags */
            alarminterruptStatusFlag = Srtc_Ip_GetInterruptStatusFlag(instance, SRTC_IP_ALARM_INTERRUPT);
            if (alarminterruptStatusFlag)
            {
                /* Clear TAF by writing to the TAR register */
                Srtc_Ip_SetTimeAlarmRegVal(instance, timeAlarmValue);
            }
#endif
#endif
        }
        break;
        default:
        {
            /* do nothing */
        }
        break;
    }

}

/*================================================================================================*/
/**
* @brief         SRtc Driver function
* @details       This function:
*                        - Sets the date passed by the user.
*
* @param[in]     instance           SRtc hw instance
* @param[in]     *timeDate          pointer to configuration
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_SetTimeDate_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_SetTimeDate(uint8 instance, const Srtc_Ip_TimedateType *timeDate)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != timeDate);
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    Srtc_Ip_StatusType status;
    uint32 seconds = 0U;

    /* Check if the date/time format is correct */
    if (!Srtc_Ip_IsTimeDateCorrectFormat(timeDate))
    {
        /* Set the status code to error */
        status = SRTC_IP_ERROR;
    }
    else
    {
        /* Convert the time and date to seconds */
        Srtc_Ip_ConvertTimeDateToSeconds(timeDate, &seconds);
        /* Set the time */
        Srtc_Ip_SetTimeSecondsRegVal(instance, seconds);
        status = SRTC_IP_SUCCESS;
    }

    return status;
}

/*================================================================================================*/
/**
* @brief         SRtc Driver function
* @details       This function:
*                        - Gets the current time and date and it will
*                               store in the state structure.
*
* @param[in]     instance           sRtc hw instance
* @param[in]     *timeDate          pointer to configuration
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_GetTimeDate_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_GetTimeDate(uint8 instance, Srtc_Ip_TimedateType * const timeDate)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != timeDate);
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    Srtc_Ip_StatusType status = SRTC_IP_ERROR;
    uint32 firstRead = 0U;
    uint32 secondRead = 0U;

    /* Make two consecutive reads to ensure that the read was not done when the counter is incrementing.
     * This is recommended in the reference manual. */
    firstRead = Srtc_Ip_GetTimeSecondsRegister(instance);
    secondRead = Srtc_Ip_GetTimeSecondsRegister(instance);

    if (firstRead != secondRead)
    {
        /* Reinitialize the temporary variable */
        firstRead = 0U;
        /* Get the current time again */
        firstRead = Srtc_Ip_GetTimeSecondsRegister(instance);
        if (firstRead != secondRead)
        {
            status = SRTC_IP_ERROR;
        }
        else
        {
            /* Convert the current time from seconds to time date structure */
            Srtc_Ip_ConvertSecondsToTimeDate(&firstRead, timeDate);
            status = SRTC_IP_SUCCESS;
        }
    }
    else
    {
        /* Convert the current time from seconds to time date structure */
        Srtc_Ip_ConvertSecondsToTimeDate(&firstRead, timeDate);
        status = SRTC_IP_SUCCESS;
    }

    return status;
}

/*================================================================================================*/
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                        - Configures the alarm based on the
*                               configuration structure passed by the user.
*                               When using alarm that are configured to be repetitive,
*                               enable the interrupt. Otherwise the repeat function will
*                               not work.
*
* @param[in]     instance           Rtc hw instance
* @param[in]     *alarmConfig       pointer to configuration
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_ConfigureAlarm_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_ConfigureAlarm(uint8 instance,
                                          const Srtc_Ip_AlarmConfigType *alarmConfig)
{
    Srtc_Ip_StatusType status;
    uint32 convertedAlarmTime;
    uint32 currentTime;

#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != alarmConfig);
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    /* Check if the alarm time is in a correct format */
    if (TRUE == Srtc_Ip_IsTimeDateCorrectFormat(&(alarmConfig->alarmTime)))
    {
        /* save alarm configuration into ch state variable*/
        Srtc_Ip_u32ChState[instance].alarmInit = TRUE;
        Srtc_Ip_u32ChState[instance].repetitionInterval = alarmConfig->repetitionInterval;
        Srtc_Ip_u32ChState[instance].numberOfRepeats = alarmConfig->numberOfRepeats;
        Srtc_Ip_u32ChState[instance].repeatForever = alarmConfig->repeatForever;
        Srtc_Ip_u32ChState[instance].alarmIntEnable = alarmConfig->alarmIntEnable;
        Srtc_Ip_u32ChState[instance].alarmCallback = alarmConfig->alarmCallback;
        Srtc_Ip_u32ChState[instance].callbackParams = alarmConfig->callbackParams;
        /* Convert the time date to seconds */
        Srtc_Ip_ConvertTimeDateToSeconds(&(alarmConfig->alarmTime), &convertedAlarmTime);
        /* Get current time in seconds */
        currentTime = Srtc_Ip_GetTimeSecondsRegister(instance);

        /* Check if the alarm time is greater than current time */
        if (convertedAlarmTime > currentTime)
        {
            /* Write alarm time into Time Alarm Register */
            Srtc_Ip_SetTimeAlarmRegVal(instance, convertedAlarmTime);
            /* Enable/disable interrupt source based on the configuration */
            Srtc_Ip_SetInterruptEnableFlag(instance, SRTC_IP_ALARM_INTERRUPT, Srtc_Ip_u32ChState[instance].alarmIntEnable);
            status = SRTC_IP_SUCCESS;
        }
        else
        {
            status = SRTC_IP_ERROR;
        }
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    /* Return the exit code */
    return status;
}

/*================================================================================================*/
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                - Configures the Time Seconds Interrupt with the Seconds interrupt Configuration Type.
* @param[in]     instance            Rtc hw instance
* @param[in]     occursFrequency     how often seconds interrupt occurs
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_ConfigureSecondsInterrupt_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_ConfigureSecondsInterrupt(uint8 instance,
                                                     Srtc_Ip_SecIntFreqType occursFrequency)
{
    Srtc_Ip_StatusType status;

#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif
    status = Srtc_Ip_SetSecondsInterruptConfiguration(instance, occursFrequency);
    return status;
}

/*================================================================================================*/
#if (STD_ON == SRTC_IP_ENABLE_LOCK_REGISTER_API)
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                   - Configures register lock for the corresponding
*                     RTC instance. Remember that all the registers are unlocked
*                     only by software reset or power on reset.
*                     (Except for CR that is unlocked only by POR).
* @param[in]     instance            Rtc hw instance
* @param[in]     lockRegister        register that will be locked
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_ConfigureLockRegister_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_ConfigureLockRegister(uint8 instance,
                                                     Srtc_Ip_LockRegConfigType * const lockRegister)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;
    RTC_Type * base = sRtcBase[instance];

#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    /* Configure Control register lock */
    if (lockRegister->controlRegisterLock)
    {
        status = Srtc_Ip_ConfigureLockReg(base, SRTC_IP_CTRL_REG_LOCK);
    }
    /* Configure Status register lock */
    if (lockRegister->statusRegisterLock)
    {
        status = Srtc_Ip_ConfigureLockReg(base, SRTC_IP_STATUS_REG_LOCK);
    }
    /* Configure Time Compensation register lock */
    if (lockRegister->timeCompensationRegisterLock)
    {
        status = Srtc_Ip_ConfigureLockReg(base, SRTC_IP_TCL_REG_LOCK);
    }
    /* Configure Lock register lock */
    if (lockRegister->lockRegisterLock)
    {
        status = Srtc_Ip_ConfigureLockReg(base, SRTC_IP_LOCK_REG_LOCK);
    }

    /* Return the exit code */
    return status;

}
#endif

#ifdef SRTC_0_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief          Interrupt handler for RTC channel
* @details        Interrupt Service Routine corresponding to RTC_CH_0 hw channel.
* @param[in]      none
* @return         void
* @isr
* @pre            The driver needs to be initialized.
*/
ISR(SRTC_0_Ch_0_ISR)
{
    Srtc_Ip_ProcessInterrupt(0U);
    EXIT_INTERRUPT();
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* SRTC_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif /* SRTC_IP_C */

/** @} */
