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

/**
*   @file       Ftm_Pwm_Ip.c
*
*   @addtogroup ftm_pwm_ip Ftm Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Ftm_Pwm_Ip.h"
#include "Ftm_Pwm_Ip_HwAccess.h"
#include "Std_Types.h"
#include "SchM_Pwm.h"

#if ((STD_ON == FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE) || (STD_ON == FTM_PWM_IP_SIM_AVAILABLE))
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
#endif /* (FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE) */

#include "Mcal.h"
/*===============================================================================================
*                            SOURCE FILE VERSION INFORMATION
===============================================================================================*/

#define FTM_PWM_IP_VENDOR_ID_C                         43
#define FTM_PWM_IP_MODULE_ID_C                         121
#define FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION_C          4
#define FTM_PWM_IP_AR_RELEASE_MINOR_VERSION_C          7
#define FTM_PWM_IP_AR_RELEASE_REVISION_VERSION_C       0
#define FTM_PWM_IP_SW_MAJOR_VERSION_C                  2
#define FTM_PWM_IP_SW_MINOR_VERSION_C                  0
#define FTM_PWM_IP_SW_PATCH_VERSION_C                  0


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same AUTOSAR version */
    #if ((FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip.c and Std_Types.h are different."
    #endif

    /* Check if source file and SchM_Pwm.h are of the same AUTOSAR version */
    #if ((FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_PWM_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_PWM_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip.c and SchM_Pwm.h are different."
    #endif

    /* Check if source file and Mcal.h are of the same AUTOSAR version */
    #if ((FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip.c and Mcal.h are different."
    #endif

    #if ((STD_ON == FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE) || (STD_ON == FTM_PWM_IP_SIM_AVAILABLE))
        /* Check if source file and RegLockMacros.h are of the same AUTOSAR version */
        #if ((FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (FTM_PWM_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR version numbers of Ftm_Pwm_Ip.c and RegLockMacros.h are different."
        #endif
    #endif
#endif

/* Check if source file and Ftm_Pwm_Ip_HwAccess.h header file are of the same vendor */
#if (FTM_PWM_IP_VENDOR_ID_C != FTM_PWM_IP_HWACCESS_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip.c and Ftm_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip_HwAccess.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION_C    != FTM_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_AR_RELEASE_MINOR_VERSION_C    != FTM_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_AR_RELEASE_REVISION_VERSION_C != FTM_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip.c and Ftm_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_HwAccess.h header file are of the same software version */
#if ((FTM_PWM_IP_SW_MAJOR_VERSION_C != FTM_PWM_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_SW_MINOR_VERSION_C != FTM_PWM_IP_HWACCESS_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_SW_PATCH_VERSION_C != FTM_PWM_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip.c and Ftm_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip.h header file are of the same vendor */
#if (FTM_PWM_IP_VENDOR_ID_C != FTM_PWM_IP_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip.c and Ftm_Pwm_Ip.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION_C    != FTM_PWM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_AR_RELEASE_MINOR_VERSION_C    != FTM_PWM_IP_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_AR_RELEASE_REVISION_VERSION_C != FTM_PWM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip.c and Ftm_Pwm_Ip.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip.h header file are of the same software version */
#if ((FTM_PWM_IP_SW_MAJOR_VERSION_C != FTM_PWM_IP_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_SW_MINOR_VERSION_C != FTM_PWM_IP_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_SW_PATCH_VERSION_C != FTM_PWM_IP_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip.c and Ftm_Pwm_Ip.h are different."
#endif


/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/
#define PWM_START_SEC_VAR_CLEARED_8
#include "Pwm_MemMap.h"

#ifdef ERR_IPV_FTM_ERR010856
#if ((STD_ON == ERR_IPV_FTM_ERR010856) && (STD_ON == FTM_PWM_IP_HAS_FAULT))
/* A variable to indicate that a fault was detected or not.*/
uint8 Ftm_Pwm_Ip_u8FaultCheck;
#endif
#endif

#define PWM_STOP_SEC_VAR_CLEARED_8
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"

/*! @brief Arrays to store the period values for each Instance */
uint16 Ftm_Pwm_Ip_aPeriod[FTM_PWM_IP_INSTANCE_COUNT];

/*! @brief Arrays to store the duty cycle values for each channel */
static uint16 Ftm_Pwm_Ip_aDutyCycle[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_COUNT];

/*! @brief Arrays to store the shift values for each channel */
static uint16 Ftm_Pwm_Ip_aPhaseShift[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_PAIR_COUNT];

#define PWM_STOP_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
/*! @brief Arrays for irq fault notifications */
Ftm_Pwm_Ip_FaultCallbackType Ftm_Pwm_Ip_pFaultIrqCallback[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_FAULT_NUMBER_CHANNELS];
#endif

/*! @brief Arrays for irq channel notifications of each channel*/
Ftm_Pwm_Ip_CallbackCfgType  Ftm_Pwm_Ip_aChIrqCallbacks[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_IRQ_COUNT];

/*! @brief Arrays for irq overflow timer notifications of each Instance */
Ftm_Pwm_Ip_CallbackCfgType Ftm_Pwm_Ip_pOverflowIrqCallback[FTM_PWM_IP_INSTANCE_COUNT];

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
/*! @brief Arrays for irq reload notifications of each Instance*/
Ftm_Pwm_Ip_ReloadCallbackCfgType  Ftm_Pwm_Ip_pReloadIrqCallback[FTM_PWM_IP_INSTANCE_COUNT];
#endif

/*! @brief Arrays to store the state of each instance */
Ftm_Pwm_Ip_ChannelStateType Ftm_Pwm_Ip_aInstanceState[FTM_PWM_IP_INSTANCE_COUNT];

/*! @brief Arrays to store the state of channel */
Ftm_Pwm_Ip_ChannelStateType Ftm_Pwm_Ip_aChannelState[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_COUNT];

/*! @brief Arrays to store the previous state of each channel */
Ftm_Pwm_Ip_ChannelStateType Ftm_Pwm_Ip_aPreviousChannelState[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_COUNT];

/*! @brief Arrays to store the type of notification for each channel */
Ftm_Pwm_Ip_EdgeInterruptType Ftm_Pwm_Ip_aNotifIrq[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_COUNT];

/*! @brief Arrays to store the output state of each channel */
static Ftm_Pwm_Ip_OutputStateType Ftm_Pwm_Ip_aIdleState[FTM_PWM_IP_INSTANCE_COUNT][FTM_PWM_IP_CHANNEL_COUNT];

/*! @brief Arrays to store the clock source of each Instance */
static Ftm_Pwm_Ip_ClkSourceType Ftm_Pwm_Ip_aClockSource[FTM_PWM_IP_INSTANCE_COUNT];

/*! @brief Arrays to store the clock pre-scaler of each Instance */
static Ftm_Pwm_Ip_ClkPrescalerType Ftm_Pwm_Ip_aClockPrescaler[FTM_PWM_IP_INSTANCE_COUNT];

/*! @brief Arrays to store the alternate clock pre-scaler of each Instance */
static Ftm_Pwm_Ip_ClkPrescalerType Ftm_Pwm_Ip_aAlternateClockPrescaler[FTM_PWM_IP_INSTANCE_COUNT];

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/*! @brief Arrays of base addresses for FTM instances. */
Ftm_Pwm_Ip_HwAddrType * const Ftm_Pwm_Ip_aFtmBase[FTM_PWM_IP_INSTANCE_COUNT] = IP_FTM_BASE_PTRS;

#if (defined(FTM_PWM_IP_SIM_AVAILABLE) && (FTM_PWM_IP_SIM_AVAILABLE == STD_ON))
/*! @brief Arrays of base addresses for SIM instances. */
Ftm_Pwm_Ip_SimType * const Ftm_Pwm_Ip_aSimBase[FTM_PWM_IP_SIM_INSTANCE_COUNT] = IP_SIM_BASE_PTRS;
#endif

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)

/**
* @brief        Ftm_Pwm_Ip_ValidateParamDeadTime
* @details      This function will check the deadtime Value.
*/  
static boolean Ftm_Pwm_Ip_ValidateParamDeadTime(uint8 Instance,
                                                uint8 Channel,
                                                uint16 DeadTimeVal);
#endif


static uint16 Ftm_Pwm_Ip_CalculatePhaseShift(uint8 Instance, uint16 DutyCycle, uint16 PhaseShift);

static void Ftm_Pwm_Ip_ConfigureSWandHWSync(uint8 Instance, const Ftm_Pwm_Ip_SyncCfgType * SyncCfg);

static void Ftm_Pwm_Ip_ConfigureSyncType(uint8 Instance, const Ftm_Pwm_Ip_SyncCfgType * SyncCfg);

static void  Ftm_Pwm_Ip_InitPair(uint8 Instance,
                                 const Ftm_Pwm_Ip_PairCfgType * UserPairCfg);

static void Ftm_Pwm_Ip_DisableCmpIrq(uint8 Instance, uint8 Channel);

static Ftm_Pwm_Ip_StatusType Ftm_Pwm_Ip_UpdateSync(uint8 Instance,
                                                   const Ftm_Pwm_Ip_SyncCfgType * SyncCfg);

#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
static void Ftm_Pwm_Ip_CheckNotification(uint8 Instance, uint8 Channel);
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
void Ftm_Pwm_Ip_SetUserAccessAllowed(uint8 Instance);

void Ftm_Pwm_Ip_ClrUserAccessAllowed(uint8 Instance);
    #endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* (STD_ON == FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE) */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))    
static void Ftm_Pwm_Ip_SetOutputForIdleChannel(uint8 Instance,
                                               uint8 Channel)
{

#ifdef ERR_IPV_FTM_ERR010856
#if ((STD_ON == ERR_IPV_FTM_ERR010856) && (STD_ON == FTM_PWM_IP_HAS_FAULT))
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
#endif
#endif
       
    /* If given channel is using time-overflow interrupt */
    if (FTM_PWM_IP_NO_EDGE != (Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] & FTM_PWM_IP_TOF_IRQ_EDGE))
    {
        /* Mark given channel as not using time-overflow interrupt, but still remember notification
           is on so when this channel is set to have pulse again, notification will come back */
        Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] |= FTM_PWM_IP_IRQ_NO_EDGE_NOTIF;
    }

#ifdef ERR_IPV_FTM_ERR010856
#if ((STD_ON == ERR_IPV_FTM_ERR010856) && (STD_ON == FTM_PWM_IP_HAS_FAULT))
    /* Notify that given FTM module enable TOF interrupt to check fault */
    if ((TRUE == Ftm_Pwm_Ip_IsEnableFaultControlMode(FtmBase)) && (TRUE == Ftm_Pwm_Ip_IsEnableFaultInput(FtmBase)))
    {
       /* Notify that given FTM module enable TOF interrupt to check fault */
       Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] |= FTM_PWM_IP_TOF_FAULT_DETECT;
       /* TOF is enable for related faut errata */
       Ftm_Pwm_Ip_SetTimerOverflowInt(FtmBase, TRUE);
    }
#endif
#endif
    
    /* Disable interrupts for given channel */
    Ftm_Pwm_Ip_DisableCmpIrq(Instance, Channel);
}

static void Ftm_Pwm_Ip_SetOutputForForcedChannel(uint8 Instance,
                                                 uint8 Channel,
                                                 boolean ActiveState)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];

    if(TRUE == ActiveState)
    {
        /* Disable match compare interrupts for each channel */
        Ftm_Pwm_Ip_DisableCmpIrq(Instance, Channel);
    }
    else
    {
       
        if (FTM_PWM_IP_NO_EDGE != (Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] & FTM_PWM_IP_TOF_IRQ_EDGE))
        {
            /* Enable TOIE interrupt */
            Ftm_Pwm_Ip_SetTimerOverflowInt(FtmBase, TRUE);
        }

        if (FTM_PWM_IP_NO_EDGE != (Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] & FTM_PWM_IP_CHF_IRQ_EDGE))
        {
            /* Enable interrupts for the given channel */
            Ftm_Pwm_Ip_UpdateChnInt(FtmBase, Channel, TRUE);
        }
    }
}
#endif

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_ValidateParamDeadTime
 * Description   : This function will check the deadtime Value.
 *
 *END**************************************************************************/  
static boolean Ftm_Pwm_Ip_ValidateParamDeadTime(uint8 Instance,
                                                uint8 Channel,
                                                uint16 DeadTimeVal)
{
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    boolean RetVal = FALSE;

    uint8 PairId = Channel >> 1U;
    uint16 EvenCounterVal = Ftm_Pwm_Ip_GetChnCountVal(FtmBase, (PairId * 2U));
    uint16 OddCounterVal  = Ftm_Pwm_Ip_GetChnCountVal(FtmBase, ((PairId * 2U) + 1U));
    uint8 Prescaler = Ftm_Pwm_Ip_GetClockPs(FtmBase);
    uint8 DeadTimePs = Ftm_Pwm_Ip_GetDeadtimePrescaler(FtmBase);

    uint16 CompareEven = (OddCounterVal - EvenCounterVal);
    uint16 CompareOdd = Ftm_Pwm_Ip_aPeriod[Instance] - CompareEven;
    /* Validate the range deadtime value is less than 1024U and greater than 0U */
    if ((DeadTimeVal < 1024U) && (DeadTimeVal > 0U))
    {
        RetVal = TRUE;
    }
    /* Deadtime insertion corner cases */
    /* The deadtime delay is less than the channel (n) duty cycle */
    /* The deadtime delay is less than the channel (n+1) duty cycle */
    if ((0U == Prescaler) && ((0U == DeadTimePs) || (1U == DeadTimePs)))
    { 
        if ((DeadTimeVal < CompareEven) && (DeadTimeVal < CompareOdd))
        {
            RetVal = TRUE;
        }
        else
        {
            RetVal = FALSE;
        }
    }

    return RetVal;
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_CalculatePhaseShift
 * Description   : This function calculates the value of the CnV register for channel (n+1)
 *                 in phase-shifted mode
 *
 *END**************************************************************************/
static uint16 Ftm_Pwm_Ip_CalculatePhaseShift(uint8 Instance,
                                             uint16 DutyCycle,
                                             uint16 PhaseShift)
{
    uint16 CnVValue = 0U;

    /* If 100% duty cycle, C(n+1)V > MOD.
    Then choose C(n+1)V = Period = MOD + 1 for optimization. */
    if (Ftm_Pwm_Ip_aPeriod[Instance] == DutyCycle)
    {
        CnVValue = Ftm_Pwm_Ip_aPeriod[Instance];
        (void) PhaseShift;
    }
    /* If 0% duty cycle, C(n+1)V = CnV = phase-shift value. */
    else if (0U == DutyCycle)
    {
        CnVValue = PhaseShift;
        (void) Instance;
    }
    else
    {
        /* The n+1 match can occur at the next cycle */
        CnVValue = (PhaseShift + DutyCycle) % Ftm_Pwm_Ip_aPeriod[Instance];
    }

    return CnVValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_InitPair
 * Description   : Configures the PWM signal for the combined channel.
 *
 *END**************************************************************************/
static void  Ftm_Pwm_Ip_InitPair(uint8 Instance,
                                 const Ftm_Pwm_Ip_PairCfgType * UserPairCfg)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint8 MainChId = 0U;
    uint8 PairChId = 0U;

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FTM_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(NULL_PTR != UserPairCfg);
    DevAssert(FTM_PWM_IP_PAIR_COUNT > UserPairCfg->PairId);
    /* Check that deadtime is used in complementary mode */
    if (TRUE == UserPairCfg->DeadtimeEn)
    {
        DevAssert(TRUE == UserPairCfg->ComplementaryModeEn);
    }
#endif

    /* Get channel ids for pair */
    MainChId = (uint8)(UserPairCfg->PairId * 2U);
    PairChId = (uint8)(MainChId + 1U);

    Ftm_Pwm_Ip_aPhaseShift[Instance][UserPairCfg->PairId] = UserPairCfg->PhaseShiftValue;

    /* Configure Complementary mode for the Pair */
    Ftm_Pwm_Ip_SetDualChnCompCmd(FtmBase, UserPairCfg->PairId, UserPairCfg->ComplementaryModeEn);

    /* Configure polarity of the PWM signal taking into consideration POL of main channel */
    if (TRUE == UserPairCfg->ComplementaryModeEn)
    {
        /* Complementary mode active. Second channel active state is inverted. */
        if (FTM_PWM_IP_POLARITY_LOW == Ftm_Pwm_Ip_GetChnOutputPolarity(FtmBase, MainChId))
        {
            /* Main channel polarity is Active Low */
            if (FTM_PWM_IP_MAIN_DUPLICATED == UserPairCfg->PairChPolarity)
            {
                /* User wants to duplicate main channel active state. Set polarity to Active High. */
                Ftm_Pwm_Ip_SetChnOutputPolarityCmd(FtmBase, PairChId, FTM_PWM_IP_POLARITY_HIGH);
            }
            else
            {
                /* User wants to invert main channel active state. Set polarity to Active Low. */
                Ftm_Pwm_Ip_SetChnOutputPolarityCmd(FtmBase, PairChId, FTM_PWM_IP_POLARITY_LOW);
            }
        }
        else
        {
            /* Main channel polarity is Active High */
            if (FTM_PWM_IP_MAIN_DUPLICATED == UserPairCfg->PairChPolarity)
            {
                /* User wants to duplicate main channel active state. Set polarity to Active Low. */
                Ftm_Pwm_Ip_SetChnOutputPolarityCmd(FtmBase, PairChId, FTM_PWM_IP_POLARITY_LOW);
            }
            else
            {
                /* User wants to invert main channel active state. Set polarity to Active High. */
                Ftm_Pwm_Ip_SetChnOutputPolarityCmd(FtmBase, PairChId, FTM_PWM_IP_POLARITY_HIGH);
            }
        }
    }
#if (defined(FTM_PWM_IP_HAS_CHANNEL_PWM_ENABLE) && (FTM_PWM_IP_HAS_CHANNEL_PWM_ENABLE == STD_ON))
    /* Enable PWM output */
    Ftm_Pwm_Ip_EnablePwmChannelOutputs(FtmBase, PairChId);
#endif

    /* Configure sync control for channels CV registers */
    Ftm_Pwm_Ip_SetDualChnPwmSyncCmd(FtmBase, UserPairCfg->PairId, UserPairCfg->PairSyncEn);
    /* Configure dead time */
    Ftm_Pwm_Ip_SetDualChnDeadtimeCmd(FtmBase, UserPairCfg->PairId, UserPairCfg->DeadtimeEn);
    /* Configure the generation of external trigger on the channel (n+1) */
    Ftm_Pwm_Ip_SetChnTriggerCmd(FtmBase, PairChId, UserPairCfg->PairExtTrigEn);
    /* Sync Write buffered registers */
    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, TRUE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_DisableCmpIrq
 * Description   : This function clear enable interrupt and flag of match-compare (CHIE, CHF) and
 *                 time-overflow (TOIE, TOF) for the specified channel.
 *
 *END**************************************************************************/
static void Ftm_Pwm_Ip_DisableCmpIrq(uint8 Instance,
                                     uint8 Channel)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
    Ftm_Pwm_Ip_OutputStateType        OutputValue = FTM_PWM_IP_OUTPUT_STATE_LOW;
    Ftm_Pwm_Ip_EdgeInterruptType      NotifyState;
    uint8                             Index;

    /* For all channels of the given module check if it is possible to disable TOIE interrupt - this means that at this stage for all channels
     * the TOF behavior array should have the value  PWM_NO_EDGE. If something else is detected then TOIE can not be disabled. */
    for (Index = 0U; Index < FTM_PWM_IP_CHANNEL_COUNT; Index++)
    {
#ifdef ERR_IPV_FTM_ERR010856
    #if ((STD_ON == ERR_IPV_FTM_ERR010856) && (STD_ON == FTM_PWM_IP_HAS_FAULT))
        NotifyState = (Ftm_Pwm_Ip_aNotifIrq[Instance][Index] & (FTM_PWM_IP_TOF_IRQ_EDGE | FTM_PWM_IP_TOF_FAULT_DETECT));
    #else
        NotifyState = (Ftm_Pwm_Ip_aNotifIrq[Instance][Index] & FTM_PWM_IP_TOF_IRQ_EDGE);
    #endif
#else
        NotifyState = (Ftm_Pwm_Ip_aNotifIrq[Instance][Index] & FTM_PWM_IP_TOF_IRQ_EDGE);
#endif
        /* If there is channel using time-overflow interrupt */
        if (FTM_PWM_IP_NO_EDGE != NotifyState)
        {
            OutputValue = FTM_PWM_IP_OUTPUT_STATE_HIGH;

            /* Intentional break to optimize run time */
            break;
        }
    }

    if (FTM_PWM_IP_OUTPUT_STATE_LOW == OutputValue)
    {
        Ftm_Pwm_Ip_SetTimerOverflowInt(FtmBase, FALSE);
    }

    Ftm_Pwm_Ip_ClearTimerOverflow(FtmBase);
#endif

    /* Clear CHIE bit in CnSC register for the given channel to disable match-compare interrupts */
    Ftm_Pwm_Ip_UpdateChnInt(FtmBase, Channel, FALSE);
    /* Clear CHnF bit interrupt flag */
    Ftm_Pwm_Ip_ClearChnEventFlag(FtmBase, Channel);
}

static void Ftm_Pwm_Ip_ConfigureSWandHWSync(uint8 Instance, const Ftm_Pwm_Ip_SyncCfgType * SyncCfg)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    switch (SyncCfg->SyncMode)
    {
        case FTM_PWM_IP_SYNC_SWTRIGGER:
            /* Configure sync for OUTMASK register */
            Ftm_Pwm_Ip_SetOutmaskSoftwareSyncModeCmd(FtmBase, (SyncCfg->OutMaskSync != FTM_PWM_IP_SYNC_DISABLED));
            Ftm_Pwm_Ip_SetOutmaskHardwareSyncModeCmd(FtmBase, FALSE);
            /* Configure sync for INVCTRL register */
            Ftm_Pwm_Ip_SetInvctrlSoftwareSyncModeCmd(FtmBase, (SyncCfg->InverterSync != FTM_PWM_IP_SYNC_DISABLED));
            Ftm_Pwm_Ip_SetInvctrlHardwareSyncModeCmd(FtmBase, FALSE);
            /* Configure sync for SWOCTRL register */
            Ftm_Pwm_Ip_SetSwoctrlSoftwareSyncModeCmd(FtmBase, (SyncCfg->OutRegSync != FTM_PWM_IP_SYNC_DISABLED));
            Ftm_Pwm_Ip_SetInvctrlHardwareSyncModeCmd(FtmBase, FALSE);
            /* Configure sync for MOD, HCR, CNTIN, and CV registers */
            Ftm_Pwm_Ip_SetModCntinCvSoftwareSyncModeCmd(FtmBase, (SyncCfg->InitCounterSync != FTM_PWM_IP_SYNC_DISABLED));
            Ftm_Pwm_Ip_SetModCntinCvHardwareSyncModeCmd(FtmBase, FALSE);
            /* Configure sync for FTM counter reset */
            Ftm_Pwm_Ip_SetCounterSoftwareSyncModeCmd(FtmBase, (SyncCfg->CounterSync != FTM_PWM_IP_SYNC_DISABLED));
            Ftm_Pwm_Ip_SetCounterHardwareSyncModeCmd(FtmBase, FALSE);
            break;
        case FTM_PWM_IP_SYNC_HWTRIGGER:
            /* Configure sync for OUTMASK register */
            Ftm_Pwm_Ip_SetOutmaskSoftwareSyncModeCmd(FtmBase, FALSE);
            Ftm_Pwm_Ip_SetOutmaskHardwareSyncModeCmd(FtmBase, (SyncCfg->OutMaskSync != FTM_PWM_IP_SYNC_DISABLED));
            /* Configure sync for INVCTRL register */
            Ftm_Pwm_Ip_SetInvctrlSoftwareSyncModeCmd(FtmBase, FALSE);
            Ftm_Pwm_Ip_SetInvctrlHardwareSyncModeCmd(FtmBase, (SyncCfg->InverterSync != FTM_PWM_IP_SYNC_DISABLED));
            /* Configure sync for SWOCTRL register */
            Ftm_Pwm_Ip_SetSwoctrlSoftwareSyncModeCmd(FtmBase, FALSE);
            Ftm_Pwm_Ip_SetInvctrlHardwareSyncModeCmd(FtmBase, (SyncCfg->OutRegSync != FTM_PWM_IP_SYNC_DISABLED));
            /* Configure sync for MOD, HCR, CNTIN, and CV registers */
            Ftm_Pwm_Ip_SetModCntinCvSoftwareSyncModeCmd(FtmBase, FALSE);
            Ftm_Pwm_Ip_SetModCntinCvHardwareSyncModeCmd(FtmBase, (SyncCfg->InitCounterSync != FTM_PWM_IP_SYNC_DISABLED));
            /* Configure sync for FTM counter reset */
            Ftm_Pwm_Ip_SetCounterSoftwareSyncModeCmd(FtmBase, FALSE);
            Ftm_Pwm_Ip_SetCounterHardwareSyncModeCmd(FtmBase, (SyncCfg->CounterSync != FTM_PWM_IP_SYNC_DISABLED));
            break;

        default:    /* Nothing to do */
            break;
    }
}


static void Ftm_Pwm_Ip_ConfigureSyncType(uint8 Instance, const Ftm_Pwm_Ip_SyncCfgType * SyncCfg)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];

    /* Configure sync for OUTMASK register */
    Ftm_Pwm_Ip_SetOutmaskPwmSyncModeCmd(FtmBase, (SyncCfg->OutMaskSync  == FTM_PWM_IP_SYNC_DISABLED)? FALSE : TRUE);
    /* Configure sync for INVCTRL register */
    Ftm_Pwm_Ip_SetInvctrlPwmSyncModeCmd(FtmBase, (SyncCfg->InverterSync  == FTM_PWM_IP_SYNC_DISABLED)? FALSE : TRUE);
    /* Configure sync for SWOCTRL register */
    Ftm_Pwm_Ip_SetSwoctrlPwmSyncModeCmd(FtmBase, (SyncCfg->OutRegSync  == FTM_PWM_IP_SYNC_DISABLED)? FALSE : TRUE);
    /* Configure sync for MOD, HCR, CNTIN, and CV registers */
    Ftm_Pwm_Ip_SetCntinPwmSyncModeCmd(FtmBase, (SyncCfg->InitCounterSync  == FTM_PWM_IP_SYNC_DISABLED)? FALSE : TRUE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_UpdateSync
 * Description   : This function configure the synchronization for PWM register.
 * If this function is used whit wrong parameters it's possible to generate
 * wrong waveform.
 *
 * Implements : Ftm_Pwm_Ip_UpdateSync_Activity
 *END**************************************************************************/
static Ftm_Pwm_Ip_StatusType Ftm_Pwm_Ip_UpdateSync(uint8 Instance,
                                                   const Ftm_Pwm_Ip_SyncCfgType * SyncCfg)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    Ftm_Pwm_Ip_StatusType RetStatus = FTM_PWM_IP_STATUS_SUCCESS;
    boolean HardwareSync = FALSE;

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    DevAssert(SyncCfg != NULL_PTR);
#endif

    HardwareSync = SyncCfg->HwSync0 || SyncCfg->HwSync1 || SyncCfg->HwSync2;

    /* Software and hardware triggers are not allowed at the same time */
    if ((SyncCfg->SyncMode == FTM_PWM_IP_SYNC_SWTRIGGER) && (HardwareSync == TRUE))
    {
        RetStatus = FTM_PWM_IP_STATUS_ERROR;
    }
    if (SyncCfg->CounterSync == FTM_PWM_IP_SYNC_ON_CLK)
    {
        RetStatus = FTM_PWM_IP_STATUS_ERROR;
    }

    if (RetStatus == FTM_PWM_IP_STATUS_SUCCESS)
    {
        Ftm_Pwm_Ip_ConfigureSWandHWSync(Instance, SyncCfg);
        /* Enhanced PWM sync is used */
        Ftm_Pwm_Ip_SetPwmSyncModeCmd(FtmBase, TRUE);
        /* Configure trigger source for sync */
        Ftm_Pwm_Ip_SetHardwareSyncTriggerSrc(FtmBase, 0U, SyncCfg->HwSync0);
        Ftm_Pwm_Ip_SetHardwareSyncTriggerSrc(FtmBase, 1U, SyncCfg->HwSync1);
        Ftm_Pwm_Ip_SetHardwareSyncTriggerSrc(FtmBase, 2U, SyncCfg->HwSync2);
        /* Configure if FTM clears TRIGn (n=0,1,2) when the hardware trigger n is detected. */
        Ftm_Pwm_Ip_SetHwTriggerSyncModeCmd(FtmBase, SyncCfg->HwTriggerAutoClear);

        /* Configure loading points */
        Ftm_Pwm_Ip_SetMaxLoadingCmd(FtmBase, SyncCfg->MaxLoadPoint);
        Ftm_Pwm_Ip_SetMinLoadingCmd(FtmBase, SyncCfg->MinLoadPoint);

#if (defined(FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD) && (FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD == STD_ON))
        if(TRUE == SyncCfg->HalfCycleLoadPoint)
        {
            Ftm_Pwm_Ip_SetHalfCycleValue(FtmBase, SyncCfg->HalfCycleLoadPointValue);
        }
        Ftm_Pwm_Ip_SetHalfCycleCmd(FtmBase, SyncCfg->HalfCycleLoadPoint);
#endif

#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
        /* Sets the frequency of reload points */
        Ftm_Pwm_Ip_SetLoadFreq(FtmBase, SyncCfg->LoadPointFreq);
#endif        
        
        Ftm_Pwm_Ip_ConfigureSyncType(Instance, SyncCfg);
    }

    return RetStatus;
}

#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
static void Ftm_Pwm_Ip_SpecialCheckNotification(uint8 Instance, uint8 Channel)
{
    Ftm_Pwm_Ip_ChannelModeType ChMode;
    uint8 PairChId = Channel >> 1U;
    
    ChMode = (Ftm_Pwm_Ip_ChannelModeType)Ftm_Pwm_Ip_GetChannelMode(Ftm_Pwm_Ip_aFtmBase[Instance], Channel);
    /* If given channel is using time-overflow interrupt */
    if (FTM_PWM_IP_NO_EDGE != (Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] & FTM_PWM_IP_TOF_IRQ_EDGE))
    {
         /* Mark given channel as not using time-overflow interrupt, but still remember notification
           is on so when this channel is set to have pulse again, notification will come back */
        Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] |= FTM_PWM_IP_IRQ_NO_EDGE_NOTIF;
    }
#ifdef ERR_IPV_FTM_ERR010856
#if ((STD_ON == ERR_IPV_FTM_ERR010856) && (STD_ON == FTM_PWM_IP_HAS_FAULT))
    /* If given channel is using time-overflow interrupt for errata workaround */
    if (FTM_PWM_IP_NO_EDGE != (Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] & FTM_PWM_IP_TOF_FAULT_DETECT))
    {
        /* Clear check fault notification */
        Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] &= (uint8)~(FTM_PWM_IP_TOF_FAULT_DETECT);
    }
#endif
#endif

    /* Disable interrupts for given channel */
    Ftm_Pwm_Ip_DisableCmpIrq(Instance, Channel);

    if (( FTM_PWM_IP_MODE_COMBINE_HIGH          == ChMode) ||
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
         ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH == ChMode) ||
         ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  == ChMode) ||
#endif
         ( FTM_PWM_IP_MODE_COMBINE_LOW           == ChMode))
    {
        /* Disable interrupts for an even channel */
        Ftm_Pwm_Ip_DisableCmpIrq(Instance, (uint8)(PairChId * 2U));
        /* Disable interrupts for an odd channel */
        Ftm_Pwm_Ip_DisableCmpIrq(Instance, (uint8)((PairChId * 2U) + 1U));
    }
}

static void Ftm_Pwm_Ip_NormalCheckNotification(uint8 Instance, uint8 Channel)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    Ftm_Pwm_Ip_ChannelModeType ChMode;
    uint8 PairChId = Channel >> 1U;
    
    ChMode = (Ftm_Pwm_Ip_ChannelModeType)Ftm_Pwm_Ip_GetChannelMode(FtmBase, Channel);

    /* If given channel is using time-overflow interrupt */
    if (FTM_PWM_IP_NO_EDGE != (Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] & FTM_PWM_IP_TOF_IRQ_EDGE))
    {
        /* Clear this bit to indicate that given channel has pulse and ready to set notification */
        Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] &= (uint8)(~(FTM_PWM_IP_IRQ_NO_EDGE_NOTIF));
        /* Set TOIE bit for enable time-overflow interrupt */
        Ftm_Pwm_Ip_SetTimerOverflowInt(FtmBase, TRUE);
    }
#ifdef ERR_IPV_FTM_ERR010856
#if ((STD_ON == ERR_IPV_FTM_ERR010856) && (STD_ON == FTM_PWM_IP_HAS_FAULT))
    /* If given channel is using time-overflow interrupt for errata workaround */
    if (FTM_PWM_IP_NO_EDGE != (Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] & FTM_PWM_IP_TOF_FAULT_DETECT))
    {
        /* Clear check fault notification */
        Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] &= (uint8)~(FTM_PWM_IP_TOF_FAULT_DETECT);
        /* Disable interrupts for given channel */
        Ftm_Pwm_Ip_DisableCmpIrq(Instance, Channel);

        if (( FTM_PWM_IP_MODE_COMBINE_HIGH          == ChMode) ||
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
            ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH == ChMode) ||
            ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  == ChMode) ||
#endif
            ( FTM_PWM_IP_MODE_COMBINE_LOW           == ChMode))
        {
            /* Disable interrupts for an even channel */
            Ftm_Pwm_Ip_DisableCmpIrq(Instance, (uint8)(PairChId * 2U));
            /* Disable interrupts for an odd channel */
            Ftm_Pwm_Ip_DisableCmpIrq(Instance, (uint8)((PairChId * 2U) + 1U));
        }
    }
#endif
#endif
    /* If given channel is using match-compare interrupt */
    if (FTM_PWM_IP_NO_EDGE != (Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] & FTM_PWM_IP_CHF_IRQ_EDGE))
    {
        /* Set CHIE bit for enable match-compare interrupt */
        Ftm_Pwm_Ip_UpdateChnInt(FtmBase, Channel, TRUE);
    }

    if (( FTM_PWM_IP_MODE_COMBINE_HIGH          == ChMode) ||
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
         ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH == ChMode) ||
         ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  == ChMode) ||
#endif
         ( FTM_PWM_IP_MODE_COMBINE_LOW           == ChMode))
    {
        if (FTM_PWM_IP_NO_EDGE != (Ftm_Pwm_Ip_aNotifIrq[Instance][(uint8)(PairChId * 2U)] & FTM_PWM_IP_CHF_IRQ_EDGE))
        {
            /* Set CHIE bit for enable match-compare interrupt for an even channel */
            Ftm_Pwm_Ip_UpdateChnInt(FtmBase, (uint8)(PairChId * 2U), TRUE);
        }
        
        if (FTM_PWM_IP_NO_EDGE != (Ftm_Pwm_Ip_aNotifIrq[Instance][(uint8)((PairChId * 2U) + 1U)] & FTM_PWM_IP_CHF_IRQ_EDGE))
        {
            /* Set CHIE bit for enable match-compare interrupt for an odd channel */
            Ftm_Pwm_Ip_UpdateChnInt(FtmBase, (uint8)((PairChId * 2U) + 1U), TRUE);
        }
    }
}

static void Ftm_Pwm_Ip_CheckNotification(uint8 Instance, uint8 Channel)
{
    /* If duty cycle is 0% or 100% */
    if ((Ftm_Pwm_Ip_aPeriod[Instance] == Ftm_Pwm_Ip_aDutyCycle[Instance][Channel]) || (0U == Ftm_Pwm_Ip_aDutyCycle[Instance][Channel]))
    {
        Ftm_Pwm_Ip_SpecialCheckNotification(Instance, Channel);
    }
    /* If duty cycle is not 0% and 100% */
    else
    {
        Ftm_Pwm_Ip_NormalCheckNotification(Instance, Channel);
    }
}
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_SetUserAccessAllowed
 * Description   : Sets the UAA bit in REG_PROT to make the Instance accessible in user mode.
 *
 *END**************************************************************************/
void Ftm_Pwm_Ip_SetUserAccessAllowed(uint8 Instance)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    SET_USER_ACCESS_ALLOWED((uint32)FtmBase, FTM_PROT_MEM_U32);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_ClrUserAccessAllowed
 * Description   : Clears the UAA bit in REG_PROT to make the Instance not accessible in user mode.
 *
 *END**************************************************************************/
void Ftm_Pwm_Ip_ClrUserAccessAllowed(uint8 Instance)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    CLR_USER_ACCESS_ALLOWED((uint32)FtmBase, FTM_PROT_MEM_U32);
}
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* (STD_ON == FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE) */


static void Ftm_Pwm_Ip_ResetAndFirstConfigure(uint8 Instance, const Ftm_Pwm_Ip_InstanceCfgType * UserInstCfg)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];

    Ftm_Pwm_Ip_Reset(FtmBase);
    /* Disable counter clock */
    Ftm_Pwm_Ip_SetClockSource(FtmBase, FTM_PWM_IP_CLOCK_SOURCE_NONE);
    /* Clear the overflow flag */
    Ftm_Pwm_Ip_ClearTimerOverflow(FtmBase);
    /* Set Counter mode */
    Ftm_Pwm_Ip_SetCpwms(FtmBase, (UserInstCfg->CntMode == FTM_PWM_IP_EDGE_ALIGNED)? FALSE : TRUE);
    /* Disable FTM mode */
    Ftm_Pwm_Ip_Enable(FtmBase, FALSE);
    /* Configure debug mode */
    Ftm_Pwm_Ip_SetBdmMode(FtmBase, UserInstCfg->DebugMode);
    /* Configure Deadtime insertion */
    Ftm_Pwm_Ip_SetDeadtimeCount(FtmBase, (uint8)(UserInstCfg->DeadTimeValue & FTM_DEADTIME_DTVAL_MASK));
    Ftm_Pwm_Ip_SetExtDeadtimeValue(FtmBase, (uint8)(UserInstCfg->DeadTimeValue >> FTM_DEADTIME_DTVAL_WIDTH));
    Ftm_Pwm_Ip_SetDeadtimePrescaler(FtmBase, UserInstCfg->DeadTimePs);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_InitInstance
 * Description   : Configures the FTM Instance in PWM mode and all general registers.
 *
 *END**************************************************************************/
static void Ftm_Pwm_Ip_InitInstance(uint8 Instance,
                                    const Ftm_Pwm_Ip_InstanceCfgType * UserInstCfg)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];

#if (defined(FTM_PWM_IP_SIM_AVAILABLE) && (FTM_PWM_IP_SIM_AVAILABLE == STD_ON))
    Ftm_Pwm_Ip_SimType * SimBase  = Ftm_Pwm_Ip_aSimBase[0U];
#endif

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FTM_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(NULL_PTR != UserInstCfg);
    /* Maximum value for Deadtime is 1023 including the extension */
    DevAssert((uint16)0x3FF >= UserInstCfg->DeadTimeValue);
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
    /* Set the UAA bit in REG_PROT to make the Instance accessible in user mode */
    OsIf_Trusted_Call1param(Ftm_Pwm_Ip_SetUserAccessAllowed, Instance);
#endif
#endif

#if (defined(FTM_PWM_IP_SIM_AVAILABLE) && (FTM_PWM_IP_SIM_AVAILABLE == STD_ON))
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    /* The FTM channel output state is retained when the channel is in output mode.*/
    OsIf_Trusted_Call2params(Ftm_Pwm_Ip_SetSimOutputBufferEn, SimBase, Instance);
#else   
    /* The FTM channel output state is retained when the channel is in output mode.*/
    Ftm_Pwm_Ip_SetSimOutputBufferEn(SimBase, Instance);
#endif
#endif

    Ftm_Pwm_Ip_ResetAndFirstConfigure(Instance, UserInstCfg);

    /* Configure the synchronization and reload points */
    (void)Ftm_Pwm_Ip_UpdateSync(Instance, UserInstCfg->SyncCfg);

    /* Configure PWM period */
    Ftm_Pwm_Ip_SetCounterInitVal(FtmBase, 0x00U);

    Ftm_Pwm_Ip_aPeriod[Instance] = UserInstCfg->PwmPeriod;

    Ftm_Pwm_Ip_aClockSource[Instance] = UserInstCfg->ClkSrc;

    Ftm_Pwm_Ip_aClockPrescaler[Instance] = UserInstCfg->ClkPs;

    Ftm_Pwm_Ip_aAlternateClockPrescaler[Instance] = UserInstCfg->AlternateClkPs;

    if (TRUE == UserInstCfg->OverflowIrqEn)
    {
        Ftm_Pwm_Ip_pOverflowIrqCallback[Instance].FunctionCallback = UserInstCfg->OverflowCb.FunctionCallback;
        Ftm_Pwm_Ip_pOverflowIrqCallback[Instance].CbParam = UserInstCfg->OverflowCb.CbParam;
    }

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))    
    if (TRUE == UserInstCfg->ReloadIrqEn)
    {
        Ftm_Pwm_Ip_pReloadIrqCallback[Instance].FunctionCallback = UserInstCfg->ReloadCb.FunctionCallback;
        Ftm_Pwm_Ip_pReloadIrqCallback[Instance].CbParam = UserInstCfg->ReloadCb.CbParam;
    }
#endif    

    if (FTM_PWM_IP_CENTER_ALIGNED == UserInstCfg->CntMode)
    {
        /* For Center Aligned mode MOD register should be divided by 2. Period is 2 * (MOD − CNTIN) */
        Ftm_Pwm_Ip_SetMod(FtmBase, (uint16)(UserInstCfg->PwmPeriod >> 1U));
    }
    else
    {
        /* For Edge Aligned mode period is determined by: MOD-CNTIN+1 */
        Ftm_Pwm_Ip_SetMod(FtmBase, (uint16)(UserInstCfg->PwmPeriod - 1U));
    }

#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    /* Configure PWM period dither */
    Ftm_Pwm_Ip_SetModFracVal(FtmBase, UserInstCfg->PwmPeriodDither);
#endif

    /* Configure Initialization feature */
    Ftm_Pwm_Ip_SetInitTriggerCmd(FtmBase, UserInstCfg->InitTriggerEn);
#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
    Ftm_Pwm_Ip_SetInitTriggerMode(FtmBase, UserInstCfg->InitTrigMode);
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_InitInstanceStart
 * Description   : Configures the FTM clock and pre-scaler, enable FTM mode
 *
 *END**************************************************************************/
static void Ftm_Pwm_Ip_InitInstanceStart(uint8 Instance,
                                         const Ftm_Pwm_Ip_InstanceCfgType * UserInstCfg)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FTM_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(NULL_PTR != UserInstCfg);
#endif

#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    /* Set Fault Input Filter Value */  
    Ftm_Pwm_Ip_SetFaultFilterValue(FtmBase, UserInstCfg->FaultInFilter);
    /* Set Fault output state */  
    Ftm_Pwm_Ip_SetFaultOutputState(FtmBase, UserInstCfg->FaultOutState);
    /* Defines the FTM fault control mode */
    Ftm_Pwm_Ip_SetFaultControlMode(FtmBase, UserInstCfg->FaultCtrMode);
#endif

    /* Enable FTM mode */
    Ftm_Pwm_Ip_Enable(FtmBase, TRUE);

    Ftm_Pwm_Ip_SetPwmSyncMode(FtmBase, TRUE);

    /* Configure the clock prescaler */
    Ftm_Pwm_Ip_SetClockPs(FtmBase, UserInstCfg->ClkPs);
    /* Configure the clock source */
    Ftm_Pwm_Ip_SetClockSource(FtmBase, UserInstCfg->ClkSrc);
    /* Confirm the instance is active */
    Ftm_Pwm_Ip_aInstanceState[Instance] = (Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_RUNNING;
}

static void Ftm_Pwm_Ip_ConfigurePairedChannel(uint8 Instance, const Ftm_Pwm_Ip_ChannelConfigType * UserChCfg)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint8 ChannelId = 0U;
    uint8 ChPairId = 0U;
    
    /* Configure the PWM channel */
    ChannelId = UserChCfg->ChannelId;
    ChPairId =  (uint8)(ChannelId >> 1U);
    /* Enable sync control for channels*/
    Ftm_Pwm_Ip_SetDualChnPwmSyncCmd(FtmBase, ChPairId, TRUE);
#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    /* Enables the fault control in pair of channels */
    Ftm_Pwm_Ip_SetDualChFaultCtr(FtmBase, ChPairId, TRUE);
#endif
    /* Configure Paired channel for combined/mCombined modes */
    if ((FTM_PWM_IP_MODE_COMBINE_HIGH == UserChCfg->ChannelMode) ||
        (FTM_PWM_IP_MODE_COMBINE_LOW == UserChCfg->ChannelMode))
    {
        /* Configure ELSA/ELSB for an odd channel*/
        Ftm_Pwm_Ip_SetChnEdgeLevel(FtmBase, (uint8)((ChPairId * 2U) + 1U), UserChCfg->ChannelMode);
        /* Enable State of channel pair output combine mode */
        Ftm_Pwm_Ip_SetDualChnCombineCmd(FtmBase, ChPairId, TRUE);
    }
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
    else if ((FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH == UserChCfg->ChannelMode) ||
             (FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW == UserChCfg->ChannelMode))
    {
        /* Configure ELSA/ELSB for an odd channel*/
        Ftm_Pwm_Ip_SetChnEdgeLevel(FtmBase, (uint8)((ChPairId * 2U) + 1U), UserChCfg->ChannelMode);
        /* Enable State of channel pair output combine mode */
        Ftm_Pwm_Ip_SetDualChnCombineCmd(FtmBase, ChPairId, TRUE);
        /* Enables the FTM peripheral timer channel modified combine mode.*/
        Ftm_Pwm_Ip_SetDualChnMCombineCmd(FtmBase, ChPairId, TRUE);
    }
#endif
    else
    {
        /* Do Nothing */
    }

    /* Configure paired channel and pair */
    if (NULL_PTR != UserChCfg->PairCfg)
    {
        Ftm_Pwm_Ip_InitPair(Instance, UserChCfg->PairCfg);
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
        /* Configure the PWM edge dithering in the channel n or n+1 */
        if (FTM_PWM_IP_DITHER_LEADING_EDGE == UserChCfg->PairCfg->DitherEdge)
        {
            Ftm_Pwm_Ip_SetChnMatchFracVal(FtmBase, (uint8)(ChPairId * 2U), UserChCfg->DutyCycleDither);
        }
        else
        {
            Ftm_Pwm_Ip_SetChnMatchFracVal(FtmBase, (uint8)((ChPairId * 2U) + 1U), UserChCfg->DutyCycleDither);
        }
#endif
    }
}

static void Ftm_Pwm_Ip_SetChnTriggerAndSoftwareCtrl(uint8 Instance, const Ftm_Pwm_Ip_ChannelConfigType * UserChCfg)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];

    /* Configure External Trigger */
    Ftm_Pwm_Ip_SetChnTriggerCmd(FtmBase, UserChCfg->ChannelId, UserChCfg->ExtTrigEn);

#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
    /* Configure Ch Match Reload point */
    Ftm_Pwm_Ip_SetPwmLoadChnSelCmd(FtmBase, UserChCfg->ChannelId, UserChCfg->ChMatchLoadEn);
#endif

    /* Configure  Software Output Control Enable */
    Ftm_Pwm_Ip_SetChnSoftwareCtrlCmd(FtmBase, UserChCfg->ChannelId, UserChCfg->SwControlEn);

    /* Configure Channel Software Output Control Value */
    Ftm_Pwm_Ip_SetChnSoftwareCtrlVal(FtmBase, UserChCfg->ChannelId, UserChCfg->SwControlVal);

    /* Sync Write buffered registers */
    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, TRUE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_InitChannel
 * Description   : Configures the PWM signal for the ftm channel.
 *
 *END**************************************************************************/
static void Ftm_Pwm_Ip_InitChannel(uint8 Instance,
                                   const Ftm_Pwm_Ip_ChannelConfigType * UserChCfg)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint8 ChannelId = 0U;

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FTM_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(NULL_PTR != UserChCfg);
#endif

    /* Configure the PWM channel */
    ChannelId = UserChCfg->ChannelId;

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)

    /* Center Aligned PWM is available only in FTM CPWM counter mode */
    if ((FTM_PWM_IP_MODE_CENTER_ALIGNED_HIGH == UserChCfg->ChannelMode) ||
        (FTM_PWM_IP_MODE_CENTER_ALIGNED_LOW == UserChCfg->ChannelMode))
    {
        DevAssert(FTM_PWM_IP_CENTER_ALIGNED == Ftm_Pwm_Ip_GetCpwms(FtmBase));
    }
    /* Only the main channel of a pair can have the PairCfg pointer set */
    if (NULL_PTR != UserChCfg->PairCfg)
    {
        if (0x01U == (ChannelId % 2U))
        {
            DevAssert(FALSE);
        }/* Check if pair configuration */
        else if ((UserChCfg->PairCfg->PairId * 2U) != ChannelId)
        {
            DevAssert(FALSE);
        }
        else
        {
            /* MISRA Rule 15.7 All if...else if constructs shall be terminated with an else statement */
        }
    }

    if ((FTM_PWM_IP_MODE_COMBINE_HIGH == UserChCfg->ChannelMode) ||
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
        (FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH == UserChCfg->ChannelMode) ||
        (FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW == UserChCfg->ChannelMode) ||
#endif
        (FTM_PWM_IP_MODE_COMBINE_LOW == UserChCfg->ChannelMode))

    {
        DevAssert(NULL_PTR != UserChCfg->PairCfg);
        Ftm_Pwm_Ip_aChannelState[Instance][ChannelId + 1U] = (Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_RUNNING;
    }
#endif

#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
    Ftm_Pwm_Ip_aNotifIrq[Instance][ChannelId] = (Ftm_Pwm_Ip_EdgeInterruptType)FTM_PWM_IP_NO_EDGE;
#endif

    Ftm_Pwm_Ip_aDutyCycle[Instance][ChannelId] = UserChCfg->DutyCycle;

    Ftm_Pwm_Ip_aIdleState[Instance][ChannelId] = UserChCfg->InitOut;

    /* Configure POL bits */
    Ftm_Pwm_Ip_SetChnOutputPolarityCmd(FtmBase, ChannelId, UserChCfg->Polarity);
    /* Configure initial output state */
    Ftm_Pwm_Ip_SetChnOutputInitStateCmd(FtmBase, ChannelId, UserChCfg->InitOut);

    /* Configure Channel Mode */
    /* Configure ELSA/ELSB */
    Ftm_Pwm_Ip_SetChnEdgeLevel(FtmBase, ChannelId, UserChCfg->ChannelMode);
    /* Set MSB and MSA bits*/
    Ftm_Pwm_Ip_SetChnMSBAMode(FtmBase, ChannelId, UserChCfg->ChannelMode);

    Ftm_Pwm_Ip_ConfigurePairedChannel(Instance, UserChCfg);

    Ftm_Pwm_Ip_UpdatePwmDutyCycleChannel(Instance,
                                         ChannelId,
                                         Ftm_Pwm_Ip_aDutyCycle[Instance][ChannelId],
                                         TRUE);

    Ftm_Pwm_Ip_SetChnTriggerAndSoftwareCtrl(Instance, UserChCfg);

#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    if ((FTM_PWM_IP_MODE_COMBINE_HIGH != UserChCfg->ChannelMode) &&
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
        (FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH != UserChCfg->ChannelMode) &&
        (FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW != UserChCfg->ChannelMode) &&
#endif
        (FTM_PWM_IP_MODE_COMBINE_LOW != UserChCfg->ChannelMode))

    {
        /* Configure the PWM edge dithering */
        Ftm_Pwm_Ip_SetChnMatchFracVal(FtmBase, ChannelId, UserChCfg->DutyCycleDither);
    }
#endif

#if (defined(FTM_PWM_IP_HAS_CHANNEL_PWM_ENABLE) && (FTM_PWM_IP_HAS_CHANNEL_PWM_ENABLE == STD_ON))
    /* Enable PWM output */
    if(TRUE == UserChCfg->ChOutputEn)
    {
        Ftm_Pwm_Ip_EnablePwmChannelOutputs(FtmBase, ChannelId);
    }
#endif
    Ftm_Pwm_Ip_aChannelState[Instance][ChannelId] = (Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_RUNNING;

    if(TRUE == UserChCfg->ChIrqEn)
    {
        Ftm_Pwm_Ip_aChIrqCallbacks[Instance][ChannelId].FunctionCallback = UserChCfg->ChannelCb.FunctionCallback;
        Ftm_Pwm_Ip_aChIrqCallbacks[Instance][ChannelId].CbParam          = UserChCfg->ChannelCb.CbParam;
    }

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_DeinitInstance
 * Description   : Stops all PWM channels.
 *
 *END**************************************************************************/
static void Ftm_Pwm_Ip_DeInitInstance(uint8 Instance)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];

#if (FTM_PWM_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif

    /* Stop the FTM counter */
    Ftm_Pwm_Ip_SetClockSource(FtmBase, FTM_PWM_IP_CLOCK_SOURCE_NONE);

    /* Clear the dead-time pre-scaler and value */
    Ftm_Pwm_Ip_SetExtDeadtimeValue(FtmBase, 0U);
    Ftm_Pwm_Ip_SetDeadtimePrescaler(FtmBase, FTM_PWM_IP_DEADTIME_DIV_1);
    Ftm_Pwm_Ip_SetDeadtimeCount(FtmBase, 0U);

    /* Configure debug mode */
    Ftm_Pwm_Ip_SetBdmMode(FtmBase, FTM_PWM_IP_BDM_MODE_00);
    /* Disable overflow interrupt */
    Ftm_Pwm_Ip_SetTimerOverflowInt(FtmBase, FALSE);
    /* Clear the module value of the registers */
    Ftm_Pwm_Ip_SetMod(FtmBase, 0U);
    Ftm_Pwm_Ip_SetCounter(FtmBase, 0U);
    /* Confirm the instance is inactive */
    Ftm_Pwm_Ip_aInstanceState[Instance] = (Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_UNINIT;

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
    /* Clear the UAA bit in REG_PROT */
    OsIf_Trusted_Call1param(Ftm_Pwm_Ip_ClrUserAccessAllowed, Instance);
#endif
#endif

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_DeinitChannel
 * Description   : Stops all PWM channels.
 *
 *END**************************************************************************/
static void Ftm_Pwm_Ip_DeInitChannel(uint8 Instance,
                                     uint8 Channel)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint8 PairId = (uint8)(Channel >> 1U);
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FTM_PWM_IP_INSTANCE_COUNT > Instance);
#endif

    /* Disable interrupts for given channel */
    Ftm_Pwm_Ip_DisableCmpIrq(Instance, Channel);
    /* Set current channel channels to IDLE */
    Ftm_Pwm_Ip_SwOutputControl(Instance,
                               Channel,
                               Ftm_Pwm_Ip_aIdleState[Instance][Channel],
                               TRUE);
    /* Clear SWSYNC bit - has to be cleared to generate SW trigger */
    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, FALSE);
    /* OUTMASK register is updated with the value of its buffer only by the PWM synchronization */
    Ftm_Pwm_Ip_SetOutmaskPwmSyncModeCmd(FtmBase, TRUE);
    /* The software trigger activates the OUTMASK register synchronization */
    Ftm_Pwm_Ip_SetOutmaskSoftwareSyncModeCmd(FtmBase, TRUE);
    /* Channel output is not masked. It continues to operate normally */
    Ftm_Pwm_Ip_SetChnOutputMask(FtmBase, Channel, FALSE);
    /* set SWSYNC bit - has to be cleared to generate SW trigger */
    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, TRUE);
    /* Clear the type of notification for each channel (n) in paired channel*/
    Ftm_Pwm_Ip_aNotifIrq[Instance][(PairId * 2U)] = (Ftm_Pwm_Ip_EdgeInterruptType)FTM_PWM_IP_NO_EDGE;
    /* Clear the type of notification for each channel (n+1) in paired channel*/
    Ftm_Pwm_Ip_aNotifIrq[Instance][((PairId * 2U) + 1U)] = (Ftm_Pwm_Ip_EdgeInterruptType)FTM_PWM_IP_NO_EDGE;

}

#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_InitChFault
 * Description   : Configures the fault channels are available on the Pwm configuration.
 *
 *END**************************************************************************/
static void Ftm_Pwm_Ip_InitChFault(uint8 Instance,
                                   const Ftm_Pwm_Ip_FaultChCfgType * FaultChCfg)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    /* Set the fault inputs polarity. */
    Ftm_Pwm_Ip_SetFaultPolarity(FtmBase, FaultChCfg->FaultId, FaultChCfg->FaultPol);
    /* Enables/Disables the filter for the fault input. */
    Ftm_Pwm_Ip_SetFaultFilterEn(FtmBase, FaultChCfg->FaultId, FaultChCfg->FaultFilEn);
    /* Enables/Disables the fault inputs. */
    Ftm_Pwm_Ip_SetFaultInputEn(FtmBase, FaultChCfg->FaultId, TRUE);
    /* Fault Irq Callback*/
    Ftm_Pwm_Ip_pFaultIrqCallback[Instance][FaultChCfg->FaultId] = FaultChCfg->FaultCb;
}
#endif

/**
 *
 * Function Name : Ftm_Pwm_Ip_Init
 * Description   : Initializes the FTM Instance and all configured channels.
 * Resets the Instance and configures it with the values from the user configuration.
 * Configures the synchronization and reload mechanisms.
 * Configures all channels and the pairs of channels.
 *
 * @implements Ftm_Pwm_Ip_Init_Activity
 */
void Ftm_Pwm_Ip_Init(uint8 Instance,
                     const Ftm_Pwm_Ip_UserCfgType * UserCfg)
{

    uint8 Index = 0U;

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FTM_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(NULL_PTR != UserCfg);
#endif

#ifdef ERR_IPV_FTM_ERR010856
#if ((STD_ON == ERR_IPV_FTM_ERR010856) && (STD_ON == FTM_PWM_IP_HAS_FAULT))
    /* Set a variable to indicate that a fault was not detected when initializing */
    Ftm_Pwm_Ip_u8FaultCheck = (uint8)0U;
#endif
#endif
    /* Configure FTM Instance in PWM mode */
    Ftm_Pwm_Ip_InitInstance(Instance, UserCfg->InstanceCfg);

    /* Configure all channels in the user cfg */
    for (Index = 0; Index < UserCfg->NoOfConfiguredCh; Index++)
    {
        /* Configure PWM channels */
        Ftm_Pwm_Ip_InitChannel(Instance, UserCfg->ConfiguredChArray[Index]);
    }

#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    if (UserCfg->NoOfFaultCfg > 0U)
    {
        for (Index = 0; Index < UserCfg->NoOfFaultCfg; Index++)
        {
            /* Configure fault channels */
            Ftm_Pwm_Ip_InitChFault(Instance, UserCfg->ConfiguredFaultArray[Index]);
        }
    }
#endif

    Ftm_Pwm_Ip_InitInstanceStart(Instance, UserCfg->InstanceCfg);
}

/**
 *
 * Function Name : Ftm_Pwm_Ip_DeInit
 * Description   : Shuts down the FTM driver.
 * Firstly, Ftm_Pwm_Ip_Init must be called. Then this function will disables the FTM module.
 *
 * @implements Ftm_Pwm_Ip_DeInit_Activity
 */
void Ftm_Pwm_Ip_DeInit(uint8 Instance)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint8 ChannelId = 0U;
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif
    /* Reset all FTM register */
    Ftm_Pwm_Ip_Reset(FtmBase);
    
    /* Configure all channels in the user cfg */
    for (ChannelId = 0U; ChannelId < FTM_PWM_IP_CHANNEL_COUNT; ChannelId++)
    {
        if (FTM_PWM_IP_CHANNEL_UNINIT != Ftm_Pwm_Ip_aChannelState[Instance][ChannelId])
        {
            /* De-Initialize FTM channels */
            Ftm_Pwm_Ip_DeInitChannel(Instance, ChannelId);
            /* The channels is inactive */
            Ftm_Pwm_Ip_aChannelState[Instance][ChannelId] = FTM_PWM_IP_CHANNEL_UNINIT;
        }
    }
    /* De-Initialize FTM Instance */
    Ftm_Pwm_Ip_DeInitInstance(Instance);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Ftm_Pwm_Ip_UpdatePwmDutyCycleChannel
 * Description   : This function will update the duty cycle for the PWM signal
 *
 *END**************************************************************************/
void Ftm_Pwm_Ip_UpdatePwmDutyCycleChannel(uint8 Instance,
                                          uint8 Channel,
                                          uint16 DutyCycle,
                                          boolean SoftwareTrigger)
{

    const Ftm_Pwm_Ip_HwAddrType *const  FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint16 FirstEdge = DutyCycle;
    uint8 PairId = Channel >> 1U;
    Ftm_Pwm_Ip_ChannelModeType ChMode;
    
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    DevAssert(Channel < FTM_PWM_IP_CHANNEL_COUNT);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00();

    /* Stores the new duty cycle */
    Ftm_Pwm_Ip_aDutyCycle[Instance][Channel] = DutyCycle;

    ChMode = (Ftm_Pwm_Ip_ChannelModeType)Ftm_Pwm_Ip_GetChannelMode(FtmBase, Channel);

#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
    Ftm_Pwm_Ip_CheckNotification(Instance, Channel);
#endif

    if((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_IDLE == Ftm_Pwm_Ip_aChannelState[Instance][Channel])
    {
        /* Update the state of current channel*/
        Ftm_Pwm_Ip_aChannelState[Instance][Channel] = (Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_RUNNING;
        /* Set output for current channel*/
        Ftm_Pwm_Ip_SwOutputControl(Instance,
                                   Channel,
                                   FTM_PWM_IP_OUTPUT_STATE_LOW,
                                   FALSE);
    }

    if ((FTM_PWM_IP_MODE_EDGE_ALIGNED_HIGH   == ChMode) ||
        (FTM_PWM_IP_MODE_EDGE_ALIGNED_LOW    == ChMode) ||
        (FTM_PWM_IP_MODE_CENTER_ALIGNED_HIGH == ChMode) ||
        (FTM_PWM_IP_MODE_CENTER_ALIGNED_LOW  == ChMode))
    {
        /* Write CV registers and setup duty cycle and phase values */
        (void) Ftm_Pwm_Ip_UpdatePwmChannel(Instance,
                                      Channel,
                                      FirstEdge,
                                      0U,
                                      SoftwareTrigger);
    }
    else if (( FTM_PWM_IP_MODE_COMBINE_HIGH          == ChMode) ||
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
             ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH == ChMode) ||
             ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  == ChMode) ||
#endif
             ( FTM_PWM_IP_MODE_COMBINE_LOW           == ChMode))

    {
        if((uint16)0U == Ftm_Pwm_Ip_aPhaseShift[Instance][PairId])
        {
            /* Write CV registers and setup duty cycle and phase values */
            (void) Ftm_Pwm_Ip_UpdatePwmChannel(Instance,
                                               Channel,
                                               0U,
                                               FirstEdge,
                                               SoftwareTrigger);
        }
        else
        {
            FirstEdge = Ftm_Pwm_Ip_CalculatePhaseShift(Instance, DutyCycle, Ftm_Pwm_Ip_aPhaseShift[Instance][PairId]);
            /* Write CV registers and setup duty cycle and phase values */
            (void) Ftm_Pwm_Ip_UpdatePwmChannel(Instance,
                                               Channel,
                                               Ftm_Pwm_Ip_aPhaseShift[Instance][PairId],
                                               FirstEdge,
                                               SoftwareTrigger);

        }

    }
    else
    {
        /* Do Nothing */
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00();

}


/**
 *
 * Function Name : Ftm_Pwm_Ip_UpdatePwmPeriodAndDuty
 * Description   : The function shall update the period and duty cycle of the selected channels immediately or synchronized
 *
 * @implements   Ftm_Pwm_Ip_UpdatePwmPeriodAndDuty_Activity
 **/
void Ftm_Pwm_Ip_UpdatePwmPeriodAndDuty(uint8 Instance,
                                       uint8 Channel,
                                       uint16 Period,
                                       uint16 DutyCycle,
                                       boolean SoftwareTrigger)
{

    uint16 TempDutyCycle = 0U;
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    DevAssert(Channel < FTM_PWM_IP_CHANNEL_COUNT);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_01();

    if((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_IDLE == Ftm_Pwm_Ip_aChannelState[Instance][Channel])
    {
        /* Update the state of current channel*/
        Ftm_Pwm_Ip_aChannelState[Instance][Channel] = (Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_RUNNING;
        /* Set output for current channel*/
        Ftm_Pwm_Ip_SwOutputControl(Instance,
                                   Channel,
                                   FTM_PWM_IP_OUTPUT_STATE_LOW,
                                   FALSE);
    }
    else
    {
        /* Do Nothing */
    }

    (void) Ftm_Pwm_Ip_UpdatePwmPeriod(Instance,
                                      Period,
                                      FALSE);
    Ftm_Pwm_Ip_aPeriod[Instance] = Period;

    if (0U == Period)
    {
        TempDutyCycle = (uint16)0U;
    }
    else
    {
        TempDutyCycle = DutyCycle;
    }


    Ftm_Pwm_Ip_UpdatePwmDutyCycleChannel(Instance,
                                         Channel,
                                         TempDutyCycle,
                                         SoftwareTrigger);

    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, SoftwareTrigger);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_01();
}




/**
 *
 * Function Name : Ftm_Pwm_Ip_SwOutputControl
 * Description   : This function will set the output for the PWM signal
 *
 * @implements Ftm_Pwm_Ip_SwOutputControl_Activity
 **/
void Ftm_Pwm_Ip_SwOutputControl(uint8 Instance,
                                uint8 Channel,
                                Ftm_Pwm_Ip_OutputStateType OutputState,
                                boolean ActiveState)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint16 SwoCtrlRegVal = 0U;
    uint16 ChannelMask = 0U;
    uint16 SwoCtrlBitMask = 0U;
    uint16 TempPolVal = 0U;
    
    Ftm_Pwm_Ip_ChannelModeType ChMode = (Ftm_Pwm_Ip_ChannelModeType)Ftm_Pwm_Ip_GetChannelMode(FtmBase, Channel);

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FTM_PWM_IP_INSTANCE_COUNT > Instance);
    DevAssert(Channel < FTM_PWM_IP_CHANNEL_COUNT);
#endif
    if((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_IDLE == Ftm_Pwm_Ip_aChannelState[Instance][Channel])
    {
        Ftm_Pwm_Ip_aDutyCycle[Instance][Channel] = (uint16)0U;
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
        Ftm_Pwm_Ip_SetOutputForIdleChannel(Instance, Channel);
    }
    else if ((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_OUTPUT_FORCED == Ftm_Pwm_Ip_aChannelState[Instance][Channel])
    {
        Ftm_Pwm_Ip_SetOutputForForcedChannel(Instance, Channel, ActiveState);
    }
#else
    }
#endif
    else
    {
        /* Do Nothing */
    }

    SwoCtrlRegVal = Ftm_Pwm_Ip_GetSoftwareOutputControl(FtmBase);

    if ((FTM_PWM_IP_MODE_COMBINE_HIGH          == ChMode) ||
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
        (FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH == ChMode) ||
        (FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  == ChMode) ||
#endif
        (FTM_PWM_IP_MODE_COMBINE_LOW           == ChMode))
    {
        /* Two consecutive bits (n and n+1) */
        ChannelMask = (uint16)3U;
    }
    else
    {
        ChannelMask = (uint16)1U;
    }

    TempPolVal = (uint16)Ftm_Pwm_Ip_GetPolInstance(FtmBase) & (uint16)((uint32)ChannelMask << (uint16)Channel);

    /* Shift the polarity bit to match the output control value position (CHnOCV) in SWOCTRL register */
    TempPolVal = (uint16)((uint32)TempPolVal << FTM_SWOCTRL_CH0OCV_SHIFT);

    /* Clear the CHnOCV bit(s) from the SwoCtrlRegVal for the given channel
       and next odd channel if phase-shifted or combined */
    SwoCtrlRegVal &= (uint16)(~((uint32)ChannelMask << ((uint16)Channel + FTM_SWOCTRL_CH0OCV_SHIFT)));

     /* If software output control is enabled */
    if (TRUE == ActiveState)
    {
        if (FTM_PWM_IP_OUTPUT_STATE_HIGH == OutputState)
        {
            /* Sw control on given channel was requested so corresponding channel bits will be set to "1" */
            SwoCtrlBitMask = (uint16)((uint32)ChannelMask << ((uint16)Channel + FTM_SWOCTRL_CH0OCV_SHIFT));
        }
        else
        {
            SwoCtrlBitMask = (uint16)0U;
        }

        /* XOR between polarity bit(s) of the given channel register (shifted left by 8) and the desired sw output value
           will provide the correct values of the SWOCTRL*/
        SwoCtrlRegVal |= (SwoCtrlBitMask ^ TempPolVal);

        /* Software output control is requested so CHnOC bit of given channel will be set */
        SwoCtrlRegVal |= (uint16)((uint32)ChannelMask << (uint16)Channel);
    }
    else
    {
        /* Software output control is disabled so CHnOC bit of given channel will be cleared */
        SwoCtrlRegVal &= (uint16)(~((uint32)ChannelMask << (uint16)Channel));
    }

    /* Write temporary variable into SWOCTRL register */
    Ftm_Pwm_Ip_SoftwareOutputControl(FtmBase, SwoCtrlRegVal);

    /* Use software synchronization to update SWOCTRL register immediately */
    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, TRUE);
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_UpdatePwmChannel
 * Description   : This function will update the duty cycle of PWM output.
 * - If the type of update in the duty cycle, this function will convert the input parameters representing
 * frequency in Hz to a period value in ticks needed by the hardware timer. Period is calculated depending
 * on the operating mode of the FTM module and is stored in internal state structure.
 * FirstEdge and secondEdge can have value between 0 - FTM_PWM_IP_MAX_DUTY_CYCLE(0 = 0% duty
 * and FTM_PWM_IP_MAX_DUTY_CYCLE = 100% duty). secondEdge value is used only whenFTM module is used in PWM combine mode.
 * - If the type of update in ticks, this function will get value in ticks to the hardware timer.
 * FirstEdge and secondEdge variables can have value between 0 and FtmPeriod is stored in the state structure.
 * - in the modified combine mode, the FirstEdge parameter is fixed value and only can modify the secondEdge variables
 * which is the initial value in the channel (n+1) match edge when the FTM counter has been ran.
 *
 * @implements Ftm_Pwm_Ip_UpdatePwmChannel_Activity
 **/
Ftm_Pwm_Ip_StatusType Ftm_Pwm_Ip_UpdatePwmChannel(uint8 Instance,
                                                  uint8 Channel,
                                                  uint16 FirstEdge,
                                                  uint16 SecondEdge,
                                                  boolean SoftwareTrigger)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    Ftm_Pwm_Ip_StatusType RetStatus = FTM_PWM_IP_STATUS_SUCCESS;
    uint16 HwFirstEdge = 0U;
    uint16 HwSecondEdge = 0U;
    uint16 FtmPeriod = 0U;
    uint8 ChPairId = (uint8)(Channel >> 1U);

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    DevAssert(Channel < FTM_PWM_IP_CHANNEL_COUNT);
#endif

    /* Get the period in the FTM Instance */
    FtmPeriod = Ftm_Pwm_Ip_aPeriod[Instance];

    if (((FirstEdge <= FtmPeriod) && (SecondEdge <= FtmPeriod)) || (0U == FtmPeriod))
    {
        HwFirstEdge = FirstEdge;
        HwSecondEdge = SecondEdge;
    }
    else
    {
        RetStatus = FTM_PWM_IP_STATUS_ERROR;
    }

    if (FTM_PWM_IP_STATUS_SUCCESS == RetStatus)
    {
        if (TRUE == Ftm_Pwm_Ip_GetDualChnCombineCmd(FtmBase, ChPairId))
        {
            /* Modify the initial value in the channel n match edge */
            Ftm_Pwm_Ip_SetChnCountVal(FtmBase, (uint8)(ChPairId * 2U), HwFirstEdge);

            /* Modify the initial value in the channel (n+1) match edge */
            Ftm_Pwm_Ip_SetChnCountVal(FtmBase, (uint8)((ChPairId * 2U) + 1U), HwSecondEdge);
        }
        else
        {
            /* Channel value is divided by 2 for up down counter mode to keep same duty */
            if (FTM_PWM_IP_CENTER_ALIGNED == Ftm_Pwm_Ip_GetCpwms(FtmBase))
            {
                Ftm_Pwm_Ip_SetChnCountVal(FtmBase, Channel, (uint16)(HwFirstEdge >> 1U));
            }
            else
            {
                Ftm_Pwm_Ip_SetChnCountVal(FtmBase, Channel, HwFirstEdge);
            }
        }

        /* Software trigger is generated to change CV registers */
        /* Before this please configure sync mechanism to use software trigger */
        Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, SoftwareTrigger);
    }

    return RetStatus;
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_UpdatePwmPeriod
 * Description   : This function will update the new period in the frequency or
 * in the counter value into mode register which modify the period of PWM signal
 * on the channel output.
 * - If the type of update in the duty cycle which is reused in Ftm_Pwm_Ip_UpdatePwmChannel
 * function to convert the newValue parameters representing frequency in Hz to
 * a period value to update the MOD register. The newValue parameter must be value
 * between 1U and maximum is the frequency of the FTM counter.
 * - If the type of update in ticks, this function will get value in counting to
 * the MOD register. The newValue parameter must be value between 1U and 0xFFFFU
 *
 * @implements Ftm_Pwm_Ip_UpdatePwmPeriod_Activity
 **/
Ftm_Pwm_Ip_StatusType Ftm_Pwm_Ip_UpdatePwmPeriod(uint8 Instance,
                                                 uint32 NewValue,
                                                 boolean SoftwareTrigger)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint32 FtmPeriod = 0U;
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif
    FtmPeriod = NewValue;
    
    /* Store the new period */
    Ftm_Pwm_Ip_aPeriod[Instance] = (uint16)NewValue;

    /* Check the signal operation in which PWM mode */
    if (FTM_PWM_IP_CENTER_ALIGNED == Ftm_Pwm_Ip_GetCpwms(FtmBase))
    {
        FtmPeriod = (FtmPeriod >> 1U);
    }
    else
    {
        FtmPeriod = (FtmPeriod - 1U);
    }
    /* Set the new modulo value into MOD register */
    Ftm_Pwm_Ip_SetMod(FtmBase, (uint16)(FtmPeriod));
    /* Software trigger is generated to change MOD registers */
    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, SoftwareTrigger);

    return FTM_PWM_IP_STATUS_SUCCESS;
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_GetOutputState
 * Description   : The function shall return current output state of the selected channel output pin.
 *
 * @implements Ftm_Pwm_Ip_GetOutputState_Activity
 **/
Ftm_Pwm_Ip_OutputStateType Ftm_Pwm_Ip_GetOutputState(uint8 Instance,
                                                     uint8 Channel)
{

    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    Ftm_Pwm_Ip_OutputStateType OutputValue;

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    DevAssert(Channel < FTM_PWM_IP_CHANNEL_COUNT);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_03();

    if (TRUE == Ftm_Pwm_Ip_GetChOutputValue(FtmBase, Channel))
    {
        OutputValue = FTM_PWM_IP_OUTPUT_STATE_HIGH;
    }
    else
    {
        OutputValue = FTM_PWM_IP_OUTPUT_STATE_LOW;
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_03();

    return OutputValue;
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_DisableNotification
 * Description   : This function disables the user notifications for the corresponding type of notification
 *
 * @implements Ftm_Pwm_Ip_DisableNotification_Activity
 **/
void Ftm_Pwm_Ip_DisableNotification(uint8 Instance, Ftm_Pwm_Ip_NotifType NotifType)
{
    Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    Ftm_Pwm_Ip_ChannelModeType ChMode;
    uint8 PairChId;
    uint8 ChannelId = (uint8)NotifType;

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    if((FTM_PWM_IP_OVERFLOW_NOTIFICATION     != NotifType)  &&
       (FTM_PWM_IP_RELOAD_POINT_NOTIFICATION != NotifType)  &&
       (FTM_PWM_IP_FAULT_NOTIFICATION        != NotifType))
    {
        DevAssert(ChannelId < (uint8)FTM_PWM_IP_CHANNEL_COUNT);
    }
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_04();

    if((FTM_PWM_IP_CHANNEL_0_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_1_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_2_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_3_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_4_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_5_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_6_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_7_NOTIFICATION == NotifType))
    {
        PairChId = (uint8)(ChannelId >> 1U);
        /* Get the mode of channels */
        ChMode = (Ftm_Pwm_Ip_ChannelModeType)Ftm_Pwm_Ip_GetChannelMode(FtmBase, ChannelId);
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
        /* Clear notification state of given channel */
        Ftm_Pwm_Ip_aNotifIrq[Instance][ChannelId] = FTM_PWM_IP_NO_EDGE;
#endif
        /* Disable interrupts for given channel */
        Ftm_Pwm_Ip_DisableCmpIrq(Instance, ChannelId);

        if (( FTM_PWM_IP_MODE_COMBINE_HIGH          == ChMode) ||
    #if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
            ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH == ChMode) ||
            ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  == ChMode) ||
    #endif
            ( FTM_PWM_IP_MODE_COMBINE_LOW           == ChMode))
        {
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
            /* Clear notification state of an even channel */
            Ftm_Pwm_Ip_aNotifIrq[Instance][(uint8)(PairChId * 2U)] = FTM_PWM_IP_NO_EDGE;
            /* Clear notification state of an odd channel */
            Ftm_Pwm_Ip_aNotifIrq[Instance][(uint8)((PairChId * 2U) + 1U)] = FTM_PWM_IP_NO_EDGE;
#endif
            /* Disable interrupts for an even channel */
            Ftm_Pwm_Ip_DisableCmpIrq(Instance,(uint8)(PairChId * 2U));
            /* Disable interrupts for an odd channel */
            Ftm_Pwm_Ip_DisableCmpIrq(Instance,(uint8)((PairChId * 2U) + 1U));
        }
    }
#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
    else if(FTM_PWM_IP_RELOAD_POINT_NOTIFICATION == NotifType)
    {
        /* Disable reload interrupt */
        Ftm_Pwm_Ip_SetReIntEnabledCmd(FtmBase, FALSE);

        /* Clear reload point interrupt flag of a given FTM module */
        Ftm_Pwm_Ip_ClearReloadFlag(FtmBase);

        /* Avoid compiler warning */
        (void) ChMode;
        (void) PairChId;
        (void) ChannelId;
    }
#endif
#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    else if(FTM_PWM_IP_FAULT_NOTIFICATION == NotifType)
    {
        /* Disable the generation of an interrupt when a fault is detected by FTM and the FTM fault control is enabled.*/
        Ftm_Pwm_Ip_SetFaultInterruptEnable(FtmBase, FALSE);

        /* Clear fault interrupt flag of a given FTM module */
        Ftm_Pwm_Ip_ClearFaultFlag(FtmBase);

        /* Avoid compiler warning */
        (void) ChMode;
        (void) PairChId;
        (void) ChannelId;
    }
#endif
    else
    {
        /* Clear time-overflow interrupt flag of given module */
        Ftm_Pwm_Ip_ClearTimerOverflow(FtmBase);

        /* Disable time-overflow interrupt */
        Ftm_Pwm_Ip_SetTimerOverflowInt(FtmBase, FALSE);

        /* Avoid compiler warning */
        (void) ChMode;
        (void) PairChId;
        (void) ChannelId;
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_04();
}

static void Ftm_Pwm_Ip_SetNormalNotificationCase(uint8 Instance, uint8 Channel)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    Ftm_Pwm_Ip_ChannelModeType ChMode;
    uint8 PairChId = (uint8)(Channel >> 1U);

    ChMode = (Ftm_Pwm_Ip_ChannelModeType)Ftm_Pwm_Ip_GetChannelMode(FtmBase, Channel);
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
    /* If notification state includes time-overflow interrupt */
    if (FTM_PWM_IP_TOF_IRQ_EDGE == (Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] & FTM_PWM_IP_TOF_IRQ_EDGE))
    {
        /* Enable time-overflow interrupt */
        Ftm_Pwm_Ip_SetTimerOverflowInt(FtmBase, TRUE);
    }
    else
    {
        /* Do Nothing*/
    }
    if (FTM_PWM_IP_CHF_IRQ_EDGE == (Ftm_Pwm_Ip_aNotifIrq[Instance][Channel] & FTM_PWM_IP_CHF_IRQ_EDGE))
    {
#endif
        /* Enable match-compare interrupt */
        Ftm_Pwm_Ip_UpdateChnInt(FtmBase, Channel, TRUE);
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
    }
    else
    {
        Ftm_Pwm_Ip_UpdateChnInt(FtmBase, Channel, FALSE);
    }
#endif

    if (( FTM_PWM_IP_MODE_COMBINE_HIGH          == ChMode) ||
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
     ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH == ChMode) ||
     ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  == ChMode) ||
#endif
     ( FTM_PWM_IP_MODE_COMBINE_LOW           == ChMode))
    {
        /* Clear match-compare interrupt flag of given channel (n+1) */
        Ftm_Pwm_Ip_ClearChnEventFlag(FtmBase, ((PairChId * 2U) + 1U));
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
        /* Check the edge of interrupt with an even channel */
        if (FTM_PWM_IP_CHF_IRQ_EDGE == (Ftm_Pwm_Ip_aNotifIrq[Instance][(uint8)(PairChId * 2U)] & FTM_PWM_IP_CHF_IRQ_EDGE))
        {
#endif
            Ftm_Pwm_Ip_UpdateChnInt(FtmBase, (uint8)(PairChId * 2U), TRUE);
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
        }
        else
        {
            Ftm_Pwm_Ip_UpdateChnInt(FtmBase, (uint8)(PairChId * 2U), FALSE);
        }
        /* Check the edge of interrupt with an odd channel */
        if (FTM_PWM_IP_CHF_IRQ_EDGE == (Ftm_Pwm_Ip_aNotifIrq[Instance][(uint8)((PairChId * 2U) + 1U)] & FTM_PWM_IP_CHF_IRQ_EDGE))
        {
#endif
            Ftm_Pwm_Ip_UpdateChnInt(FtmBase, (uint8)((PairChId * 2U) + 1U), TRUE);
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
        }
        else
        {
            Ftm_Pwm_Ip_UpdateChnInt(FtmBase, (uint8)((PairChId * 2U) + 1U), FALSE);
        }
#endif
    }
}

/**
 *
 * Function Name : Ftm_Pwm_Ip_EnableNotification
 * Description   : This function enables the user notifications for the corresponding type of notification
 *
 * @implements Ftm_Pwm_Ip_EnableNotification_Activity
 **/
void Ftm_Pwm_Ip_EnableNotification(uint8 Instance,
                                   Ftm_Pwm_Ip_NotifType NotifType)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint8 ChannelId = (uint8)NotifType;

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    if((FTM_PWM_IP_OVERFLOW_NOTIFICATION     != NotifType)  &&
       (FTM_PWM_IP_RELOAD_POINT_NOTIFICATION != NotifType)  &&
       (FTM_PWM_IP_FAULT_NOTIFICATION        != NotifType))
    {
        DevAssert(ChannelId < (uint8)FTM_PWM_IP_CHANNEL_COUNT);
    }
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_05();
    
    if((FTM_PWM_IP_CHANNEL_0_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_1_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_2_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_3_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_4_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_5_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_6_NOTIFICATION == NotifType) ||
       (FTM_PWM_IP_CHANNEL_7_NOTIFICATION == NotifType))
    {
        /* Clear match-compare interrupt flag of given channel */
        Ftm_Pwm_Ip_ClearChnEventFlag(FtmBase, ChannelId);

#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
        /* Clear time-overflow interrupt flag of given channel */
        Ftm_Pwm_Ip_ClearTimerOverflow(FtmBase);
        /* If duty cycle is not 0% and 100% */
        if ((0U != Ftm_Pwm_Ip_aDutyCycle[Instance][ChannelId]) &&
            (Ftm_Pwm_Ip_aPeriod[Instance] != Ftm_Pwm_Ip_aDutyCycle[Instance][ChannelId]))
        {
#endif
            Ftm_Pwm_Ip_SetNormalNotificationCase(Instance, ChannelId);
#if (defined(FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
        }
        else
        {
            /* Mark channel as notification disabled */
            Ftm_Pwm_Ip_aNotifIrq[Instance][ChannelId] |= FTM_PWM_IP_IRQ_NO_EDGE_NOTIF;
            /* Disable interrupt for given channel */
            Ftm_Pwm_Ip_DisableCmpIrq(Instance, ChannelId);
        }
#endif
    }
#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
    else if(FTM_PWM_IP_RELOAD_POINT_NOTIFICATION == NotifType)
    {
        /* Clear reload point interrupt flag of a given FTM module */
        Ftm_Pwm_Ip_ClearReloadFlag(FtmBase);

        /* Enable reload interrupt */
        Ftm_Pwm_Ip_SetReIntEnabledCmd(FtmBase, TRUE);

        /* Avoid compiler warning */
        (void) ChannelId;
    }
#endif
#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    else if(FTM_PWM_IP_FAULT_NOTIFICATION == NotifType)
    {
        /* Clear fault interrupt flag of a given FTM module */
        Ftm_Pwm_Ip_ClearFaultFlag(FtmBase);

        /* Enables the generation of an interrupt when a fault is detected by FTM and the FTM fault control is enabled.*/
        Ftm_Pwm_Ip_SetFaultInterruptEnable(FtmBase, TRUE);

        /* Avoid compiler warning */
        (void) ChannelId;
    }
#endif
    else
    {
        /* Clear time-overflow interrupt flag of given channel */
        Ftm_Pwm_Ip_ClearTimerOverflow(FtmBase);

        /* Enable time-overflow interrupt */
        Ftm_Pwm_Ip_SetTimerOverflowInt(FtmBase, TRUE);
        
        /* Avoid compiler warning */
        (void) ChannelId;
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_05();
}

/**
 *
 * Function Name : Ftm_Pwm_Ip_SetPowerState
 * Description   : The function shall disable or enable the Ftm Instance clock based on the PowerState parameter.
 *
 * @implements Ftm_Pwm_Ip_SetPowerState_Activity
 **/
void Ftm_Pwm_Ip_SetPowerState(uint8 Instance,
                              Ftm_Pwm_Ip_PowerStateType PowerState)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif

    if (FTM_PWM_IP_LOW_POWER == PowerState)
    {
        /* Disable counter clock */
        Ftm_Pwm_Ip_SetClockSource(FtmBase, FTM_PWM_IP_CLOCK_SOURCE_NONE);
    }
    else
    {
        Ftm_Pwm_Ip_SetClockSource(FtmBase, Ftm_Pwm_Ip_aClockSource[Instance]);
    }
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_SetClockMode
 * Description   : This function sets the prescaler depending on the value ePrescaler parameter.
 *
 * @implements Ftm_Pwm_Ip_SetClockMode_Activity
 **/
void Ftm_Pwm_Ip_SetClockMode(uint8 Instance,
                             Ftm_Pwm_Ip_PrescalerType Prescaler)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif

    if (FTM_PWM_IP_ALTERNATIVE_PRESCALER == Prescaler)
    {
        Ftm_Pwm_Ip_SetClockPs(FtmBase, Ftm_Pwm_Ip_aAlternateClockPrescaler[Instance]);
    }
    else
    {
        Ftm_Pwm_Ip_SetClockPs(FtmBase, Ftm_Pwm_Ip_aClockPrescaler[Instance]);
    }
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_ResetCounter
 * Description   : This function endabel/disabled counter reset by Pwm_SyncUpdate() call
 *
 * @implements Ftm_Pwm_Ip_ResetCounter_Activity
 **/
void Ftm_Pwm_Ip_ResetCounter(uint8 Instance,
                             boolean IsResetCnt)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif

    Ftm_Pwm_Ip_SetCounterSoftwareSyncModeCmd(FtmBase, IsResetCnt);

}


/**
 *
 * Function Name : Ftm_Pwm_Ip_GetChannelState
 * Description   : The function shall return the duty cycle value of the selected channel.
 *
 * @implements  Ftm_Pwm_Ip_GetChannelState_Activity
 **/
uint16 Ftm_Pwm_Ip_GetChannelState(uint8 Instance, uint8 Channel)
{
    uint16 DutyCycle;

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    DevAssert(Channel < FTM_PWM_IP_CHANNEL_COUNT);
#endif
    DutyCycle = Ftm_Pwm_Ip_aDutyCycle[Instance][Channel];

    return DutyCycle;
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_FastUpdatePwmDuty
 * Description   : This function will update the duty cycle of PWM output for multiple channels.
 *
 * @implements Ftm_Pwm_Ip_FastUpdatePwmDuty_Activity
 **/
void Ftm_Pwm_Ip_FastUpdatePwmDuty(uint8 Instance,
                                  uint8 NumberOfChannels,
                                  const uint8 * Channels,
                                  const uint16 * Duty,
                                  boolean SoftwareTrigger)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint8 Index;

#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    DevAssert(NumberOfChannels <= FTM_PWM_IP_CHANNEL_COUNT);
#endif
    for (Index = 0U; Index < NumberOfChannels; Index++)
    {
        Ftm_Pwm_Ip_SetChnCountVal(FtmBase, Channels[Index], Duty[Index]);
        Ftm_Pwm_Ip_aDutyCycle[Instance][Channels[Index]] = Duty[Index];
    }

    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, SoftwareTrigger);
}


 /**
 *
 * Function Name : Ftm_Pwm_Ip_MaskOutputChannels
 * Description   : This function will mask the output of the channels and at match
 * events will be ignored by the masked channels.
 *
 * @implements Ftm_Pwm_Ip_MaskOutputChannels_Activity
 */
void Ftm_Pwm_Ip_MaskOutputChannels(uint8 Instance,
                                   uint32 ChannelsMask,
                                   boolean SoftwareTrigger)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_07();

    Ftm_Pwm_Ip_SetOutmaskReg(FtmBase, ChannelsMask);
    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, SoftwareTrigger);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_07();
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_UnMaskOutputChannels
 * Description   : This function will unmask the output of the channels and at match
 * events will be ignored by the masked channels.
 *
 * @implements Ftm_Pwm_Ip_UnMaskOutputChannels_Activity
 **/
void Ftm_Pwm_Ip_UnMaskOutputChannels(uint8 Instance,
                                     uint32 ChannelsMask,
                                     boolean SoftwareTrigger)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_08();

    Ftm_Pwm_Ip_ClearOutmaskReg(FtmBase, ChannelsMask);
    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, SoftwareTrigger);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_08();
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_SetPhaseShift
 * Description   : The function shall set phase shift, update the period and set duty cycle to 50% value immediately or synchronized.
 *
 * @implements  Ftm_Pwm_Ip_SetPhaseShift_Activity
 **/
void Ftm_Pwm_Ip_SetPhaseShift(uint8 Instance,
                              uint8 Channel,
                              uint16 Period,
                              uint16 PhaseShift,
                              boolean SoftwareTrigger)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint8 PairChId;
    uint16 DutyCycleVal;
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    Ftm_Pwm_Ip_ChannelModeType ChMode;
    uint16  CnVValue = 0U;
    boolean CheckChMode = TRUE;
    boolean RetVal = TRUE;

    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    DevAssert(Channel < FTM_PWM_IP_CHANNEL_COUNT);
    
    ChMode = (Ftm_Pwm_Ip_ChannelModeType)Ftm_Pwm_Ip_GetChannelMode(FtmBase, Channel);
    
    if (( FTM_PWM_IP_MODE_COMBINE_HIGH          != ChMode) &&
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
        ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH != ChMode) &&
        ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  != ChMode) &&
#endif
        ( FTM_PWM_IP_MODE_COMBINE_LOW           != ChMode))
    {
        CheckChMode = FALSE;
    }
    DevAssert(CheckChMode != FALSE);
    
    CnVValue = PhaseShift + (uint16)(Period >> 1U);
    if ((CnVValue <= PhaseShift) || (Period <= CnVValue))
    {
        RetVal = FALSE;
    }
    DevAssert(RetVal != FALSE);
#endif
    PairChId = Channel >> 1U;
    Ftm_Pwm_Ip_aPeriod[Instance] = Period;

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_09();

    if (FTM_PWM_IP_CENTER_ALIGNED == Ftm_Pwm_Ip_GetCpwms(FtmBase))
    {
        /* For Center Aligned mode MOD register should be divided by 2. Period is 2 * (MOD − CNTIN) */
        Ftm_Pwm_Ip_SetMod(FtmBase, (uint16)(Period >> 1U));
    }
    else
    {
        /* For Edge Aligned mode period is determined by: MOD-CNTIN+1 */
        Ftm_Pwm_Ip_SetMod(FtmBase, (uint16)(Period - 1U));
    }

    Ftm_Pwm_Ip_SetChnCountVal(FtmBase, (uint8)(PairChId * 2U), PhaseShift);

    /* Fix duty cycle to 50% */
    DutyCycleVal = (uint16)(Period >> 1U);
    
    Ftm_Pwm_Ip_aDutyCycle[Instance][Channel] = DutyCycleVal;
    /* Write C(n+1)V register */
    Ftm_Pwm_Ip_SetChnCountVal(FtmBase, (uint8)((PairChId * 2U) + 1U), (PhaseShift + DutyCycleVal));

    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, SoftwareTrigger);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_09();
}


/**
* @brief        This function set phase shift and duty cycle value (as immediate or synchronized base on API parameter SyncUpdate)
*
* @details      Ftm_Pwm_Ip_SetDutyPhaseShift allows to set both phase shift and duty cycle value,
*               The phase shift is the offset of the leading edge of the signal in respect to period starting point.
*
* @param[in]    DutyCycle               Pwm duty cycle value in ticks
* @param[in]    PhaseShift              Phase shift value (in ticks)
* @param[in]    boolean                 SyncUpdate
*                      TRUE             Set the phase shift and duty cycle value base on the synchronization when calling Pwm_SyncUpdate.
*                      FALSE            Set phase shift and duty cycle value immediately
*
* @return       void
* @implements   Ftm_Pwm_Ip_SetDutyPhaseShift_Activity
*/
void Ftm_Pwm_Ip_SetDutyPhaseShift(uint8 Instance,
                                  uint8 Channel,
                                  uint16 DutyCycle,
                                  uint16 PhaseShift,
                                  boolean SyncUpdate)
{

    uint16 FirstEdge;
    uint16 SecondEdgeEdge;
    uint8 PairId;
    boolean SoftwareTrigger;
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    Ftm_Pwm_Ip_ChannelModeType ChMode;
    boolean CheckChMode = TRUE;
    boolean RetVal = TRUE;

    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    DevAssert(Channel < FTM_PWM_IP_CHANNEL_COUNT);
    
    ChMode = (Ftm_Pwm_Ip_ChannelModeType)Ftm_Pwm_Ip_GetChannelMode(FtmBase, Channel);
    
    if (( FTM_PWM_IP_MODE_COMBINE_HIGH          != ChMode) &&
#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
        ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH != ChMode) &&
        ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  != ChMode) &&
#endif
        ( FTM_PWM_IP_MODE_COMBINE_LOW           != ChMode))
    {
        CheckChMode = FALSE;
    }
    DevAssert(CheckChMode != FALSE);

#if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
    if (((FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH          == ChMode) ||
         (FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW           == ChMode)) &&
        (TRUE == SyncUpdate))
    {
        RetVal = FALSE;
    }
#endif

    if ((Ftm_Pwm_Ip_aPeriod[Instance] != DutyCycle) && (0U != DutyCycle))
    {
        if ((Ftm_Pwm_Ip_aPeriod[Instance] <= PhaseShift) || (Ftm_Pwm_Ip_aPeriod[Instance] < DutyCycle))
        {
            RetVal = FALSE;
        }
    }
    DevAssert(RetVal != FALSE);

#endif
    PairId = Channel >> 1U;

    Ftm_Pwm_Ip_aPhaseShift[Instance][PairId] = PhaseShift;
    
    Ftm_Pwm_Ip_aDutyCycle[Instance][Channel] = DutyCycle;

    FirstEdge = PhaseShift;

    SecondEdgeEdge = Ftm_Pwm_Ip_CalculatePhaseShift(Instance, DutyCycle, PhaseShift);

    if (TRUE == SyncUpdate)
    {
        SoftwareTrigger = FALSE;
    }
    else
    {
        SoftwareTrigger = TRUE;
    }

    if((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_IDLE == Ftm_Pwm_Ip_aChannelState[Instance][Channel])
    {
        /* Update the state of current channel*/
        Ftm_Pwm_Ip_aChannelState[Instance][Channel] = (Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_RUNNING;
        /* Set output for current channel*/
        Ftm_Pwm_Ip_SwOutputControl(Instance,
                                   Channel,
                                   FTM_PWM_IP_OUTPUT_STATE_LOW,
                                   FALSE);
    }

    /* Write CV registers and setup duty cycle and phase values */
    (void)Ftm_Pwm_Ip_UpdatePwmChannel(Instance,
                                      Channel,
                                      FirstEdge,
                                      SecondEdgeEdge,
                                      SoftwareTrigger);
}


/**
*
* @brief        The function shall disable the trigger generation for the selected sources.
* @details      Corresponding bits with trigger source as bellow:
*
* @implements Ftm_Pwm_Ip_DisableTrigger_Activity
**/
void  Ftm_Pwm_Ip_DisableTrigger(uint8 Instance,
                                uint32 TriggerMask)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_10();

    Ftm_Pwm_Ip_DisableTriggerMask(FtmBase, TriggerMask);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_10();
}


/**
*
* @brief        The function shall enable the trigger generation for the selected sources.
* @details      Corresponding bits with trigger source as bellow:
*
* @implements Ftm_Pwm_Ip_EnableTrigger_Activity
**/
void  Ftm_Pwm_Ip_EnableTrigger(uint8 Instance,
                               uint32 TriggerMask)
{

    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_11();

    Ftm_Pwm_Ip_EnableTriggerMask(FtmBase, TriggerMask);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_11();
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_SyncUpdate
 * Description   : This function will allow synchronized loading
 *                of the duty registers for all the channels of a given FTM module
 * @implements Ftm_Pwm_Ip_SyncUpdate_Activity
 **/
void Ftm_Pwm_Ip_SyncUpdate(uint8 Instance)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
#endif
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_12();

    Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, TRUE);

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_12();
}


/**
 *
 * Function Name : Ftm_Pwm_Ip_SetChannelDeadTime
 * Description   : The function shall update the dead time at runtime for the selected channel.
 *
 * @implements Ftm_Pwm_Ip_SetChannelDeadTime_Activity
 **/
void Ftm_Pwm_Ip_SetChannelDeadTime(uint8 Instance,
                                   uint8 Channel,
                                   uint16 DeadTimeVal)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
#if (FTM_PWM_IP_DEV_ERROR_DETECT == STD_ON)

    DevAssert(Instance < FTM_PWM_IP_INSTANCE_COUNT);
    DevAssert(Channel < FTM_PWM_IP_CHANNEL_COUNT);
    DevAssert(TRUE == Ftm_Pwm_Ip_GetDualChnCompCmd(FtmBase, Channel));
    DevAssert(TRUE == Ftm_Pwm_Ip_GetDualChnDeadtimeCmd(FtmBase, Channel));
    DevAssert(TRUE == Ftm_Pwm_Ip_ValidateParamDeadTime(Instance, Channel, DeadTimeVal));
   
#else
    (void)Channel;
#endif

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_13();

    if (DeadTimeVal < 64U)
    {   /* Set the Deadtime Value */
        Ftm_Pwm_Ip_SetDeadtimeCount(FtmBase, (uint8)DeadTimeVal);
        /* Set the Extended Deadtime Value */
        Ftm_Pwm_Ip_SetExtDeadtimeValue(FtmBase, 0U);
    }
    else
    {
        /* Set the Deadtime Value */
        Ftm_Pwm_Ip_SetDeadtimeCount (FtmBase, (uint8)(DeadTimeVal & (uint8)0x3F));
        /* Set the Extended Deadtime Value */
        Ftm_Pwm_Ip_SetExtDeadtimeValue(FtmBase, (uint8)(DeadTimeVal >> 6U));
    }

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_13();
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
