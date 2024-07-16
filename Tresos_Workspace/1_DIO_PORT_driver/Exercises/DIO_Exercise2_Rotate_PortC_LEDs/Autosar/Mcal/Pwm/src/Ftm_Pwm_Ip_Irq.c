/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Flexio
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
*     @file
*
*     @addtogroup ftm_ip IPL Driver
*     @{
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
#include "Ftm_Pwm_Ip_Irq.h"
#include "Ftm_Pwm_Ip_HwAccess.h"
#include "Mcal.h"
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_PWM_IP_IRQ_VENDOR_ID_C                      43
#define FTM_PWM_IP_IRQ_MODULE_ID_C                      121
#define FTM_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FTM_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define FTM_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define FTM_PWM_IP_IRQ_SW_MAJOR_VERSION_C               2
#define FTM_PWM_IP_IRQ_SW_MINOR_VERSION_C               0
#define FTM_PWM_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Ftm_Pwm_Ip_Irq.h header file are of the same vendor */
#if (FTM_PWM_IP_IRQ_VENDOR_ID_C != FTM_PWM_IP_IRQ_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Irq.c and Ftm_Pwm_Ip_Irq.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip_Irq.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FTM_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FTM_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FTM_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Irq.c and Ftm_Pwm_Ip_Irq.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Irq.h header file are of the same software version */
#if ((FTM_PWM_IP_IRQ_SW_MAJOR_VERSION_C != FTM_PWM_IP_IRQ_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_IRQ_SW_MINOR_VERSION_C != FTM_PWM_IP_IRQ_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_IRQ_SW_PATCH_VERSION_C != FTM_PWM_IP_IRQ_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Irq.c and Ftm_Pwm_Ip_Irq.h are different."
#endif


/* Check if source file and Ftm_Pwm_Ip_HwAccess.h header file are of the same vendor */
#if (FTM_PWM_IP_IRQ_VENDOR_ID_C != FTM_PWM_IP_HWACCESS_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Irq.c and Ftm_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip_HwAccess.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FTM_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FTM_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FTM_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Irq.c and Ftm_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_HwAccess.h header file are of the same software version */
#if ((FTM_PWM_IP_IRQ_SW_MAJOR_VERSION_C != FTM_PWM_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_IRQ_SW_MINOR_VERSION_C != FTM_PWM_IP_HWACCESS_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_IRQ_SW_PATCH_VERSION_C != FTM_PWM_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Irq.c and Ftm_Pwm_Ip_HwAccess.h are different."
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Mcal.h are of the same AUTOSAR version */
    #if ((FTM_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Irq.c and Mcal.h are different."
    #endif
#endif
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/*! @brief Arrays to store the type of notification for each channel */
extern Ftm_Pwm_Ip_EdgeInterruptType Ftm_Pwm_Ip_aNotifIrq[FTM_PWM_IP_IRQS_ARR_COUNT][FTM_PWM_IP_CHANNEL_IRQ_COUNT];

 /*! @brief Arrays for irq overflow timer notifications of each Instance */
extern Ftm_Pwm_Ip_CallbackCfgType Ftm_Pwm_Ip_pOverflowIrqCallback[FTM_PWM_IP_IRQS_ARR_COUNT];

/*! @brief Arrays for irq channel notifications of each channel*/
extern Ftm_Pwm_Ip_CallbackCfgType Ftm_Pwm_Ip_aChIrqCallbacks[FTM_PWM_IP_IRQS_ARR_COUNT][FTM_PWM_IP_CHANNEL_IRQ_COUNT];

#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
/*! @brief Arrays for irq fault notifications */
extern Ftm_Pwm_Ip_FaultCallbackType Ftm_Pwm_Ip_pFaultIrqCallback[FTM_PWM_IP_IRQS_ARR_COUNT][FTM_PWM_IP_FAULT_NUMBER_CHANNELS];
#endif

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
/*! @brief Arrays for irq reload notifications of each Instance */
extern Ftm_Pwm_Ip_ReloadCallbackCfgType Ftm_Pwm_Ip_pReloadIrqCallback[FTM_PWM_IP_IRQS_ARR_COUNT];
#endif

/*! @brief Arrays to store the state of each instance */
extern Ftm_Pwm_Ip_ChannelStateType Ftm_Pwm_Ip_aInstanceState[FTM_PWM_IP_IRQS_ARR_COUNT];

/*! @brief Arrays to store the state of channel */
extern Ftm_Pwm_Ip_ChannelStateType Ftm_Pwm_Ip_aChannelState[FTM_PWM_IP_IRQS_ARR_COUNT][FTM_PWM_IP_CHANNEL_IRQ_COUNT];

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_CLEARED_8
#include "Pwm_MemMap.h"

#ifdef ERR_IPV_FTM_ERR010856
#if ((STD_ON == ERR_IPV_FTM_ERR010856) && (STD_ON == FTM_PWM_IP_HAS_FAULT))
/* A variable to indicate that a fault was detected or not.*/
extern uint8 Ftm_Pwm_Ip_u8FaultCheck;
#endif
#endif

#define PWM_STOP_SEC_VAR_CLEARED_8
#include "Pwm_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if ((defined FTM_PWM_IP_0_ISR_USED) || (defined FTM_PWM_IP_1_ISR_USED) || (defined FTM_PWM_IP_2_ISR_USED) || (defined FTM_PWM_IP_3_ISR_USED) || (defined FTM_PWM_IP_4_ISR_USED)|| (defined FTM_PWM_IP_5_ISR_USED) \
     || (defined FTM_PWM_IP_0_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_1_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_2_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_3_OVF_RELOAD_ISR_USED) \
     || (defined FTM_PWM_IP_4_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_5_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_6_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_7_OVF_RELOAD_ISR_USED) \
     || (defined FTM_PWM_IP_0_OVF_ISR_USED) || (defined FTM_PWM_IP_1_OVF_ISR_USED) || (defined FTM_PWM_IP_2_OVF_ISR_USED) || (defined FTM_PWM_IP_3_OVF_ISR_USED) \
     || (defined FTM_PWM_IP_4_OVF_ISR_USED) || (defined FTM_PWM_IP_5_OVF_ISR_USED) || (defined FTM_PWM_IP_6_OVF_ISR_USED) || (defined FTM_PWM_IP_7_OVF_ISR_USED))
static void Ftm_Pwm_Ip_ProcessTofInterrupt(uint8 Instance);
#endif

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
static void Ftm_Pwm_Ip_ProcessReloadInterrupt(uint8 Instance);
#endif

#if ((defined FTM_PWM_IP_0_ISR_USED) || (defined FTM_PWM_IP_1_ISR_USED) || (defined FTM_PWM_IP_2_ISR_USED) || (defined FTM_PWM_IP_3_ISR_USED) || (defined FTM_PWM_IP_4_ISR_USED) || (defined FTM_PWM_IP_5_ISR_USED) || \
    (defined FTM_PWM_IP_0_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_0_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_0_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_0_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_1_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_1_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_1_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_1_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_2_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_2_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_2_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_2_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_3_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_3_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_3_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_3_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_4_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_4_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_4_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_4_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_5_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_5_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_5_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_5_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_6_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_6_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_6_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_6_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_7_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_7_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_7_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_7_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_0_CH_0_ISR_USED) || (defined FTM_PWM_IP_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_0_CH_2_ISR_USED) || (defined FTM_PWM_IP_0_CH_3_ISR_USED) || (defined FTM_PWM_IP_0_CH_4_ISR_USED) || (defined FTM_PWM_IP_0_CH_5_ISR_USED) || \
    (defined FTM_PWM_IP_1_CH_0_ISR_USED) || (defined FTM_PWM_IP_1_CH_1_ISR_USED) || (defined FTM_PWM_IP_1_CH_2_ISR_USED) || (defined FTM_PWM_IP_1_CH_3_ISR_USED) || (defined FTM_PWM_IP_1_CH_4_ISR_USED) || (defined FTM_PWM_IP_1_CH_5_ISR_USED) || \
    (defined FTM_PWM_IP_2_CH_0_ISR_USED) || (defined FTM_PWM_IP_2_CH_1_ISR_USED) || (defined FTM_PWM_IP_2_CH_2_ISR_USED) || (defined FTM_PWM_IP_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_2_CH_4_ISR_USED) || (defined FTM_PWM_IP_2_CH_5_ISR_USED) || \
    (defined FTM_PWM_IP_3_CH_0_ISR_USED) || (defined FTM_PWM_IP_3_CH_1_ISR_USED) || (defined FTM_PWM_IP_3_CH_2_ISR_USED) || (defined FTM_PWM_IP_3_CH_3_ISR_USED) || (defined FTM_PWM_IP_3_CH_4_ISR_USED) || (defined FTM_PWM_IP_3_CH_5_ISR_USED))
static void Ftm_Pwm_Ip_ProcessCommonInterrupt(uint8 Instance, uint8 HwChannel);
#endif

#if ((defined FTM_PWM_IP_0_FAULT_ISR_USED) || (defined FTM_PWM_IP_1_FAULT_ISR_USED) || (defined FTM_PWM_IP_2_FAULT_ISR_USED) || (defined FTM_PWM_IP_3_FAULT_ISR_USED) \
     || (defined FTM_PWM_IP_4_FAULT_ISR_USED) || (defined FTM_PWM_IP_5_FAULT_ISR_USED) || (defined FTM_PWM_IP_6_FAULT_ISR_USED) || (defined FTM_PWM_IP_7_FAULT_ISR_USED))
static void Ftm_Pwm_Ip_ProcessFaultInterrupt(uint8 Instance, uint8 FaultId);
#endif

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if ((defined FTM_PWM_IP_0_ISR_USED) || (defined FTM_PWM_IP_1_ISR_USED) || (defined FTM_PWM_IP_2_ISR_USED) || (defined FTM_PWM_IP_3_ISR_USED)|| (defined FTM_PWM_IP_4_ISR_USED) || (defined FTM_PWM_IP_5_ISR_USED) \
     || (defined FTM_PWM_IP_0_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_1_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_2_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_3_OVF_RELOAD_ISR_USED) \
     || (defined FTM_PWM_IP_4_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_5_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_6_OVF_RELOAD_ISR_USED) || (defined FTM_PWM_IP_7_OVF_RELOAD_ISR_USED) \
     || (defined FTM_PWM_IP_0_OVF_ISR_USED) || (defined FTM_PWM_IP_1_OVF_ISR_USED) || (defined FTM_PWM_IP_2_OVF_ISR_USED) || (defined FTM_PWM_IP_3_OVF_ISR_USED) \
     || (defined FTM_PWM_IP_4_OVF_ISR_USED) || (defined FTM_PWM_IP_5_OVF_ISR_USED) || (defined FTM_PWM_IP_6_OVF_ISR_USED) || (defined FTM_PWM_IP_7_OVF_ISR_USED))

#ifdef ERR_IPV_FTM_ERR010856
#if ((STD_ON == ERR_IPV_FTM_ERR010856) && (STD_ON == FTM_PWM_IP_HAS_FAULT))
static void Ftm_Pwm_Ip_ProcessErrata(uint8 Instance)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    boolean FaultStatus = Ftm_Pwm_Ip_GetFaultDetectionFlag(FtmBase);
    uint32 TemRegVal;

    if (TRUE == FaultStatus)
    {  
        /* Set a variable to indicate that a fault was detected */
        Ftm_Pwm_Ip_u8FaultCheck |= (uint8)1U << Instance;
        /* Get FTM_OUTMASK register that were set in last notification */
        TemRegVal = (uint32)Ftm_Pwm_Ip_GetSoftwareOutputControl(FtmBase);
        /* Clear the FTM_OUTMASK bits that were set in last notification */
        TemRegVal |= (uint32)Ftm_Pwm_Ip_GetOutputMask(FtmBase);
        /* Write the FTM_OUTMASK register to set the bit or bits corresponding to any channels that
           are controlled by FTM_SWOCTRL to temporarily inactivate the channel output. */
        Ftm_Pwm_Ip_SetOutmaskReg(FtmBase, TemRegVal);
        /* Clear fault conditions by reading the FTM_FMS register and then writing FTM_FMS with all zeroes.*/
        TemRegVal = Ftm_Pwm_Ip_GetFaultModeStatus(FtmBase);
        Ftm_Pwm_Ip_SetFaultModeStatus(FtmBase, (uint32)0U);
        /* Set SWSYNC to synchronize */
        Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, TRUE);
    }
    else
    {     
        if ((uint8)0U != (Ftm_Pwm_Ip_u8FaultCheck & ((uint8)(1U << Instance))))
        {
            /* Get FTM_SWOCTRL register  */
            TemRegVal = (uint32)Ftm_Pwm_Ip_GetSoftwareOutputControl(FtmBase);
            /* Clear the FTM_SWOCTRL by writing all zeroes to it. */
            Ftm_Pwm_Ip_SoftwareOutputControl(FtmBase, (uint16)0U);
            /* Write FTM_SWOCTRL with the desired value again. */
            Ftm_Pwm_Ip_SoftwareOutputControl(FtmBase, (uint16)TemRegVal);
            /* Get FTM_OUTMASK register */
            TemRegVal = Ftm_Pwm_Ip_GetOutputMask(FtmBase);
            TemRegVal &= (uint32)Ftm_Pwm_Ip_GetSoftwareOutputControl(FtmBase);
            /* Clear the FTM_OUTMASK bits that were set */
            Ftm_Pwm_Ip_ClearOutmaskReg(FtmBase, TemRegVal);
            /* Set SWSYNC to synchronize */
            Ftm_Pwm_Ip_SetSoftwareTriggerCmd(FtmBase, TRUE);
            /* Clear the fault variable that was set when the fault condition was originally detected.*/
            Ftm_Pwm_Ip_u8FaultCheck &= (uint8)~(1U << Instance);
        }
    }
}
#endif
#endif
     
/**
 *
 * Function Name : Ftm_Pwm_Ip_ProcessTofInterrupt
 * Description   :
 * @implements Ftm_Pwm_Ip_ProcessTofInterrupt_Activity
 **/
static void Ftm_Pwm_Ip_ProcessTofInterrupt(uint8 Instance)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];

    uint8 ToieStatus;
    uint8 TofStatus;

#if (defined (FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
    Ftm_Pwm_Ip_EdgeInterruptType TofState;
    Ftm_Pwm_Ip_EdgeInterruptType TofNoEdgeState;
    uint8 Index;
    uint8 LgChannelIdx;
    Ftm_Pwm_Ip_ChannelModeType ChMode;
#endif

#ifdef ERR_IPV_FTM_ERR010856
#if ((STD_ON == ERR_IPV_FTM_ERR010856) && (STD_ON == FTM_PWM_IP_HAS_FAULT))
    Ftm_Pwm_Ip_ProcessErrata(Instance);
#endif
#endif

    /* Get time-overflow enable interrupt status */
    ToieStatus = (TRUE == Ftm_Pwm_Ip_IsOverflowIntEnabled(FtmBase))? 0x01U : 0x00U;
    /* Get time-overflow interrupt flag status */
    TofStatus = (TRUE == Ftm_Pwm_Ip_GetTimerOverflow(FtmBase))? 0x01U : 0x00U;

    if ((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_UNINIT == Ftm_Pwm_Ip_aInstanceState[Instance])
    {
        /* Clear TOF interrupt flag bit if the driver is not initialized */
        Ftm_Pwm_Ip_ClearTimerOverflow(FtmBase);
    }
    else
    {
        if (((uint8)0U != ToieStatus) && ((uint8)0U != TofStatus))
        {
            /* Clear TOF interrupt flag bit if the interrupt is not spurious */
            Ftm_Pwm_Ip_ClearTimerOverflow(FtmBase);

    #if (defined (FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
            /* Loop all channels in FTM module */
            for (Index = (uint8)0U; Index < FTM_PWM_IP_CHANNEL_COUNT; Index++)
            {
                /* Get state of given channel */
                TofState = (Ftm_Pwm_Ip_aNotifIrq[Instance][Index] & FTM_PWM_IP_TOF_IRQ_EDGE);

                /* Get "time-overflow enable interrupt but not use due to no edge" status of given channel */
                TofNoEdgeState = (Ftm_Pwm_Ip_aNotifIrq[Instance][Index] & FTM_PWM_IP_IRQ_NO_EDGE_NOTIF);

                if ((FTM_PWM_IP_NO_EDGE != TofState) && (FTM_PWM_IP_NO_EDGE == TofNoEdgeState))
                {
                                  /* Get the mode of channels */
                    ChMode = (Ftm_Pwm_Ip_ChannelModeType)Ftm_Pwm_Ip_GetChannelMode(FtmBase, Index);
                    if (( FTM_PWM_IP_MODE_COMBINE_HIGH          != ChMode) &&
    #if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
                        ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH != ChMode) &&
                        ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  != ChMode) &&
    #endif
                        ( FTM_PWM_IP_MODE_COMBINE_LOW           != ChMode))
                    {
                        LgChannelIdx = (FTM_PWM_IP_CHANNEL_COUNT * Instance) + Index;
                        (Ftm_Pwm_Ip_pOverflowIrqCallback[Instance].FunctionCallback)(LgChannelIdx);
                    }
    #else
                    if(NULL_PTR != Ftm_Pwm_Ip_pOverflowIrqCallback[Instance].FunctionCallback)
                    {
                        (Ftm_Pwm_Ip_pOverflowIrqCallback[Instance].FunctionCallback)(Ftm_Pwm_Ip_pOverflowIrqCallback[Instance].CbParam);
                    }
    #endif    
    #if (defined (FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
                }
            }
    #endif
        }
    }
}
#endif


#if ((defined FTM_PWM_IP_0_ISR_USED) || (defined FTM_PWM_IP_1_ISR_USED)|| (defined FTM_PWM_IP_2_ISR_USED)|| (defined FTM_PWM_IP_3_ISR_USED)|| (defined FTM_PWM_IP_4_ISR_USED)|| (defined FTM_PWM_IP_5_ISR_USED) || \
    (defined FTM_PWM_IP_0_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_0_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_0_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_0_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_1_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_1_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_1_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_1_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_2_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_2_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_2_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_2_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_3_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_3_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_3_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_3_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_4_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_4_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_4_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_4_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_5_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_5_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_5_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_5_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_6_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_6_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_6_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_6_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_7_CH_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_7_CH_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_7_CH_4_CH_5_ISR_USED) || (defined FTM_PWM_IP_7_CH_6_CH_7_ISR_USED) || \
    (defined FTM_PWM_IP_0_CH_0_ISR_USED) || (defined FTM_PWM_IP_0_CH_1_ISR_USED) || (defined FTM_PWM_IP_0_CH_2_ISR_USED) || (defined FTM_PWM_IP_0_CH_3_ISR_USED) || (defined FTM_PWM_IP_0_CH_4_ISR_USED) || (defined FTM_PWM_IP_0_CH_5_ISR_USED) || \
    (defined FTM_PWM_IP_1_CH_0_ISR_USED) || (defined FTM_PWM_IP_1_CH_1_ISR_USED) || (defined FTM_PWM_IP_1_CH_2_ISR_USED) || (defined FTM_PWM_IP_1_CH_3_ISR_USED) || (defined FTM_PWM_IP_1_CH_4_ISR_USED) || (defined FTM_PWM_IP_1_CH_5_ISR_USED) || \
    (defined FTM_PWM_IP_2_CH_0_ISR_USED) || (defined FTM_PWM_IP_2_CH_1_ISR_USED) || (defined FTM_PWM_IP_2_CH_2_ISR_USED) || (defined FTM_PWM_IP_2_CH_3_ISR_USED) || (defined FTM_PWM_IP_2_CH_4_ISR_USED) || (defined FTM_PWM_IP_2_CH_5_ISR_USED) || \
    (defined FTM_PWM_IP_3_CH_0_ISR_USED) || (defined FTM_PWM_IP_3_CH_1_ISR_USED) || (defined FTM_PWM_IP_3_CH_2_ISR_USED) || (defined FTM_PWM_IP_3_CH_3_ISR_USED) || (defined FTM_PWM_IP_3_CH_4_ISR_USED) || (defined FTM_PWM_IP_3_CH_5_ISR_USED))
/**
 *
 * Function Name : Ftm_Pwm_Ip_ProcessCommonInterrupt
 * Description   :
 * @implements Ftm_Pwm_Ip_ProcessCommonInterrupt_Activity
 **/
static void Ftm_Pwm_Ip_ProcessCommonInterrupt(uint8 Instance, uint8 HwChannel)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint8 ChieStatus;
    uint8 ChfStatus;
    Ftm_Pwm_Ip_ChannelModeType ChMode;
#if (defined (FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
    Ftm_Pwm_Ip_EdgeInterruptType ChEdgeState;
    uint8 LgChannelIdx;
    /* Get match-compare notification state of given channel */
    ChEdgeState =(Ftm_Pwm_Ip_aNotifIrq[Instance][HwChannel] & FTM_PWM_IP_CHF_IRQ_EDGE);
#endif
    /* Get match-compare enable interrupt status */
    ChieStatus = (TRUE == Ftm_Pwm_Ip_IsChnIntEnabled(FtmBase, HwChannel))? 0x01U : 0x00U;
    /* Get match-compare interrupt flag status */
    ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, HwChannel))? 0x01U : 0x00U;
    
    if ((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_UNINIT == Ftm_Pwm_Ip_aChannelState[Instance][HwChannel])
    {
        /* Clear CHF bit interrupt flag if the driver is not initialized*/
        Ftm_Pwm_Ip_ClearChnEventFlag(FtmBase, HwChannel);
    }
    else
    {
        if (((uint8)0U != ChieStatus) && ((uint8)0U != ChfStatus))
        {
            /* Clear CHF bit interrupt flag if the interrupt is not spurious */
            Ftm_Pwm_Ip_ClearChnEventFlag(FtmBase, HwChannel);
        #if (defined (FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
            if (FTM_PWM_IP_NO_EDGE != ChEdgeState)
            {
                LgChannelIdx = (uint8)((FTM_PWM_IP_CHANNEL_COUNT * Instance) + HwChannel);
        #endif

                if ((uint8)1U == (uint8)(HwChannel & 0x01U))
                {
                    /* Get the mode of channels */
                    ChMode = (Ftm_Pwm_Ip_ChannelModeType)Ftm_Pwm_Ip_GetChannelMode(FtmBase, (HwChannel - 1U));
                    if (( FTM_PWM_IP_MODE_COMBINE_HIGH     == ChMode) ||
        #if (defined(FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE) && (FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE == STD_ON))
                    ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_HIGH == ChMode) ||
                    ( FTM_PWM_IP_MODE_MODIFIED_COMBINE_LOW  == ChMode) ||
        #endif
                    ( FTM_PWM_IP_MODE_COMBINE_LOW           == ChMode))
                    {
        #if (defined (FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
                        (Ftm_Pwm_Ip_pOverflowIrqCallback[Instance].FunctionCallback)(LgChannelIdx - 1U);
        #else
                        if(NULL_PTR != Ftm_Pwm_Ip_aChIrqCallbacks[Instance][HwChannel - 1U].FunctionCallback)
                        {
                            (Ftm_Pwm_Ip_aChIrqCallbacks[Instance][HwChannel - 1U].FunctionCallback)(Ftm_Pwm_Ip_aChIrqCallbacks[Instance][HwChannel - 1U].CbParam);
                        }
        #endif
                    }
                    else
                    {
        #if (defined (FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
                        (Ftm_Pwm_Ip_pOverflowIrqCallback[Instance].FunctionCallback)(LgChannelIdx);
        #else
                        if(NULL_PTR != Ftm_Pwm_Ip_aChIrqCallbacks[Instance][HwChannel].FunctionCallback)
                        {
                            (Ftm_Pwm_Ip_aChIrqCallbacks[Instance][HwChannel].FunctionCallback)(Ftm_Pwm_Ip_aChIrqCallbacks[Instance][HwChannel].CbParam);
                        }
        #endif
                    }
                }
                else
                {
        #if (defined (FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
                    (Ftm_Pwm_Ip_pOverflowIrqCallback[Instance].FunctionCallback)(LgChannelIdx);
        #else
                    if(NULL_PTR != Ftm_Pwm_Ip_aChIrqCallbacks[Instance][HwChannel].FunctionCallback)
                    {
                        (Ftm_Pwm_Ip_aChIrqCallbacks[Instance][HwChannel].FunctionCallback)(Ftm_Pwm_Ip_aChIrqCallbacks[Instance][HwChannel].CbParam);
                    }
        #endif
                }
        #if (defined (FTM_PWM_IP_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_NOTIFICATION_SUPPORTED == STD_ON))
            }
        #endif
        }
    }
}
#endif

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
/**
 *
 * Function Name : Ftm_Pwm_Ip_ProcessReloadInterrupt
 * Description   :
 * @implements Ftm_Pwm_Ip_ProcessReloadInterrupt_Activity
 **/
static void Ftm_Pwm_Ip_ProcessReloadInterrupt(uint8 Instance)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    uint8 RieStatus;
    uint8 RfStatus;
    /* Get reload enable interrupt status */
    RieStatus = (TRUE == Ftm_Pwm_Ip_IsReloadIntEnabled(FtmBase))? 0x01U : 0x00U;
    /* Get reload interrupt flag status */
    RfStatus = (TRUE == Ftm_Pwm_Ip_GetReloadFlag(FtmBase))? 0x01U : 0x00U;
    
    if ((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_UNINIT == Ftm_Pwm_Ip_aInstanceState[Instance])
    {
        /* Clear RF bit interrupt flag if the driver is not initialized*/
        Ftm_Pwm_Ip_ClearReloadFlag(FtmBase);
    }
    else
    {   
        if (((uint8)0U != RieStatus) && ((uint8)0U != RfStatus))
        {
            /* Clear RF bit interrupt flag if the interrupt is not spurious */
            Ftm_Pwm_Ip_ClearReloadFlag(FtmBase);            
            
            if(NULL_PTR != Ftm_Pwm_Ip_pReloadIrqCallback[Instance].FunctionCallback)
            {
                (Ftm_Pwm_Ip_pReloadIrqCallback[Instance].FunctionCallback)(Ftm_Pwm_Ip_pReloadIrqCallback[Instance].CbParam);
            }
        }
    }
}
#endif

#if ((defined FTM_PWM_IP_0_FAULT_ISR_USED) || (defined FTM_PWM_IP_1_FAULT_ISR_USED) || (defined FTM_PWM_IP_2_FAULT_ISR_USED) || (defined FTM_PWM_IP_3_FAULT_ISR_USED) \
     || (defined FTM_PWM_IP_4_FAULT_ISR_USED) || (defined FTM_PWM_IP_5_FAULT_ISR_USED) || (defined FTM_PWM_IP_6_FAULT_ISR_USED) || (defined FTM_PWM_IP_7_FAULT_ISR_USED))
static void Ftm_Pwm_Ip_ProcessFaultInterrupt(uint8 Instance, uint8 FaultId)
{
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[Instance];
    /* Get fault enable interrupt flag status */
    boolean FaultEn = Ftm_Pwm_Ip_IsFaultEnabled(FtmBase);
    /* Get fault interrupt flag status */
    boolean FaultStatus = Ftm_Pwm_Ip_GetFaultDetectionFlagId(FtmBase, FaultId); 

    if ((Ftm_Pwm_Ip_ChannelStateType)FTM_PWM_IP_CHANNEL_UNINIT == Ftm_Pwm_Ip_aInstanceState[Instance])
    {
        /* Clear fault detection flag bit if the driver is not initialized */
        Ftm_Pwm_Ip_ClearFaultFlagId(FtmBase, FaultId);
    }
    else
    {
        if ((TRUE == FaultEn) && (TRUE == FaultStatus))
        {
            /* Clear fault detection flag bit if the interrupt is not spurious */
            Ftm_Pwm_Ip_ClearFaultFlagId(FtmBase, FaultId);

            if(NULL_PTR != Ftm_Pwm_Ip_pFaultIrqCallback[Instance][FaultId])
            {
                Ftm_Pwm_Ip_pFaultIrqCallback[Instance][FaultId]();
            }
        }
    }
}
#endif

#if (defined FTM_PWM_IP_0_ISR_USED)
ISR(FTM_0_ISR)
{

    uint8 InstanceId  = 0U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;

    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < FTM_PWM_IP_CHANNEL_COUNT; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_1_ISR_USED)
ISR(FTM_1_ISR)
{

    uint8 InstanceId  = 1U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;

    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < FTM_PWM_IP_CHANNEL_COUNT; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_2_ISR_USED)
ISR(FTM_2_ISR)
{

    uint8 InstanceId  = 2U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;

    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < FTM_PWM_IP_CHANNEL_COUNT; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_3_ISR_USED)
ISR(FTM_3_ISR)
{

    uint8 InstanceId  = 3U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;

    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < FTM_PWM_IP_CHANNEL_COUNT; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_4_ISR_USED)
ISR(FTM_4_ISR)
{

    uint8 InstanceId  = 4U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;

    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < FTM_PWM_IP_CHANNEL_COUNT; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_5_ISR_USED)
ISR(FTM_5_ISR)
{

    uint8 InstanceId  = 5U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;

    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < FTM_PWM_IP_CHANNEL_COUNT; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }

    EXIT_INTERRUPT();
}
#endif



#if (defined FTM_PWM_IP_0_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 overflow, reload interrupt
 */
ISR(FTM_0_OVF_RELOAD_ISR)
{
    uint8 InstanceId  = 0U;
    uint8 TofStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))    
    uint8 RfStatus;

    /* Get reload point interrupt flag status */
    RfStatus = (TRUE == Ftm_Pwm_Ip_GetReloadFlag(FtmBase))? 0x01U : 0x00U;
#endif

    /* Get time-overflow interrupt flag status */
    TofStatus = (TRUE == Ftm_Pwm_Ip_GetTimerOverflow(FtmBase))? 0x01U : 0x00U;

    /* Read TOF value and verify if it was an overflow. */
    if (0U != TofStatus )
    {
        Ftm_Pwm_Ip_ProcessTofInterrupt(InstanceId);
    }

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
    /* Read RF value and verify if it was a reload point interrupt. */
    if(0U != RfStatus)
    {
        Ftm_Pwm_Ip_ProcessReloadInterrupt(InstanceId);
    }
#endif

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_1_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 overflow, reload interrupt
 */
ISR(FTM_1_OVF_RELOAD_ISR)
{
    uint8 InstanceId  = 1U;
    uint8 TofStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))    
    uint8 RfStatus;

    /* Get reload point interrupt flag status */
    RfStatus = (TRUE == Ftm_Pwm_Ip_GetReloadFlag(FtmBase))? 0x01U : 0x00U;
#endif

    /* Get time-overflow interrupt flag status */
    TofStatus = (TRUE == Ftm_Pwm_Ip_GetTimerOverflow(FtmBase))? 0x01U : 0x00U;

    /* Read TOF value and verify if it was an overflow. */
    if (0U != TofStatus )
    {
        Ftm_Pwm_Ip_ProcessTofInterrupt(InstanceId);
    }

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
    /* Read RF value and verify if it was a reload point interrupt. */
    if(0U != RfStatus)
    {
        Ftm_Pwm_Ip_ProcessReloadInterrupt(InstanceId);
    }
#endif

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_2_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 overflow, reload interrupt
 */
ISR(FTM_2_OVF_RELOAD_ISR)
{
    uint8 InstanceId  = 2U;
    uint8 TofStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))    
    uint8 RfStatus;

    /* Get reload point interrupt flag status */
    RfStatus = (TRUE == Ftm_Pwm_Ip_GetReloadFlag(FtmBase))? 0x01U : 0x00U;
#endif

    /* Get time-overflow interrupt flag status */
    TofStatus = (TRUE == Ftm_Pwm_Ip_GetTimerOverflow(FtmBase))? 0x01U : 0x00U;

    /* Read TOF value and verify if it was an overflow. */
    if (0U != TofStatus )
    {
        Ftm_Pwm_Ip_ProcessTofInterrupt(InstanceId);
    }

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
    /* Read RF value and verify if it was a reload point interrupt. */
    if(0U != RfStatus)
    {
        Ftm_Pwm_Ip_ProcessReloadInterrupt(InstanceId);
    }
#endif

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_3_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 overflow, reload interrupt
 */
ISR(FTM_3_OVF_RELOAD_ISR)
{
    uint8 InstanceId  = 3U;
    uint8 TofStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))    
    uint8 RfStatus;

    /* Get reload point interrupt flag status */
    RfStatus = (TRUE == Ftm_Pwm_Ip_GetReloadFlag(FtmBase))? 0x01U : 0x00U;
#endif

    /* Get time-overflow interrupt flag status */
    TofStatus = (TRUE == Ftm_Pwm_Ip_GetTimerOverflow(FtmBase))? 0x01U : 0x00U;

    /* Read TOF value and verify if it was an overflow. */
    if (0U != TofStatus )
    {
        Ftm_Pwm_Ip_ProcessTofInterrupt(InstanceId);
    }

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
    /* Read RF value and verify if it was a reload point interrupt. */
    if(0U != RfStatus)
    {
        Ftm_Pwm_Ip_ProcessReloadInterrupt(InstanceId);
    }
#endif

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_4_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 overflow, reload interrupt
 */
ISR(FTM_4_OVF_RELOAD_ISR)
{
    uint8 InstanceId  = 4U;
    uint8 TofStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))    
    uint8 RfStatus;

    /* Get reload point interrupt flag status */
    RfStatus = (TRUE == Ftm_Pwm_Ip_GetReloadFlag(FtmBase))? 0x01U : 0x00U;
#endif

    /* Get time-overflow interrupt flag status */
    TofStatus = (TRUE == Ftm_Pwm_Ip_GetTimerOverflow(FtmBase))? 0x01U : 0x00U;

    /* Read TOF value and verify if it was an overflow. */
    if (0U != TofStatus )
    {
        Ftm_Pwm_Ip_ProcessTofInterrupt(InstanceId);
    }

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
    /* Read RF value and verify if it was a reload point interrupt. */
    if(0U != RfStatus)
    {
        Ftm_Pwm_Ip_ProcessReloadInterrupt(InstanceId);
    }
#endif

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_5_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 overflow, reload interrupt
 */
ISR(FTM_5_OVF_RELOAD_ISR)
{
    uint8 InstanceId  = 5U;
    uint8 TofStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))    
    uint8 RfStatus;

    /* Get reload point interrupt flag status */
    RfStatus = (TRUE == Ftm_Pwm_Ip_GetReloadFlag(FtmBase))? 0x01U : 0x00U;
#endif

    /* Get time-overflow interrupt flag status */
    TofStatus = (TRUE == Ftm_Pwm_Ip_GetTimerOverflow(FtmBase))? 0x01U : 0x00U;

    /* Read TOF value and verify if it was an overflow. */
    if (0U != TofStatus )
    {
        Ftm_Pwm_Ip_ProcessTofInterrupt(InstanceId);
    }

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
    /* Read RF value and verify if it was a reload point interrupt. */
    if(0U != RfStatus)
    {
        Ftm_Pwm_Ip_ProcessReloadInterrupt(InstanceId);
    }
#endif

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_6_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 overflow, reload interrupt
 */
ISR(FTM_6_OVF_RELOAD_ISR)
{
    uint8 InstanceId  = 6U;
    uint8 TofStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))    
    uint8 RfStatus;

    /* Get reload point interrupt flag status */
    RfStatus = (TRUE == Ftm_Pwm_Ip_GetReloadFlag(FtmBase))? 0x01U : 0x00U;
#endif

    /* Get time-overflow interrupt flag status */
    TofStatus = (TRUE == Ftm_Pwm_Ip_GetTimerOverflow(FtmBase))? 0x01U : 0x00U;

    /* Read TOF value and verify if it was an overflow. */
    if (0U != TofStatus )
    {
        Ftm_Pwm_Ip_ProcessTofInterrupt(InstanceId);
    }

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
    /* Read RF value and verify if it was a reload point interrupt. */
    if(0U != RfStatus)
    {
        Ftm_Pwm_Ip_ProcessReloadInterrupt(InstanceId);
    }
#endif

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_7_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 overflow, reload interrupt
 */
ISR(FTM_7_OVF_RELOAD_ISR)
{
    uint8 InstanceId  = 7U;
    uint8 TofStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))    
    uint8 RfStatus;

    /* Get reload point interrupt flag status */
    RfStatus = (TRUE == Ftm_Pwm_Ip_GetReloadFlag(FtmBase))? 0x01U : 0x00U;
#endif

    /* Get time-overflow interrupt flag status */
    TofStatus = (TRUE == Ftm_Pwm_Ip_GetTimerOverflow(FtmBase))? 0x01U : 0x00U;

    /* Read TOF value and verify if it was an overflow. */
    if (0U != TofStatus )
    {
        Ftm_Pwm_Ip_ProcessTofInterrupt(InstanceId);
    }

#if (defined(FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED) && (FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED == STD_ON))
    /* Read RF value and verify if it was a reload point interrupt. */
    if(0U != RfStatus)
    {
        Ftm_Pwm_Ip_ProcessReloadInterrupt(InstanceId);
    }
#endif

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_0_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 0 - channel 1.
 */
ISR(FTM_0_CH_0_CH_1_ISR)
{

    uint8 InstanceId  = 0U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < 2U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_0_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 2 - channel 3.
 */
ISR(FTM_0_CH_2_CH_3_ISR)
{

    uint8 InstanceId  = 0U;
    uint8 ChanneId = 2U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 2U; ChanneId < 4U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_0_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 4 - channel 5.
 */
ISR(FTM_0_CH_4_CH_5_ISR)
{

    uint8 InstanceId  = 0U;
    uint8 ChanneId = 4U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 4U; ChanneId < 6U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}

#endif

#if (defined FTM_PWM_IP_0_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 6 - channel 7.
 */
ISR(FTM_0_CH_6_CH_7_ISR)
{

    uint8 InstanceId  = 0U;
    uint8 ChanneId = 6U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 6U; ChanneId < 8U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_1_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 0 - channel 1.
 */
ISR(FTM_1_CH_0_CH_1_ISR)
{

    uint8 InstanceId  = 1U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < 2U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_1_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 2 - channel 3.
 */
ISR(FTM_1_CH_2_CH_3_ISR)
{

    uint8 InstanceId  = 1U;
    uint8 ChanneId = 2U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 2U; ChanneId < 4U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_1_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 4 - channel 5.
 */
ISR(FTM_1_CH_4_CH_5_ISR)
{

    uint8 InstanceId  = 1U;
    uint8 ChanneId = 4U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 4U; ChanneId < 6U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_1_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 6 - channel 7.
 */
ISR(FTM_1_CH_6_CH_7_ISR)
{

    uint8 InstanceId  = 1U;
    uint8 ChanneId = 6U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 6U; ChanneId < 8U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_2_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 0 - channel 1.
 */
ISR(FTM_2_CH_0_CH_1_ISR)
{

    uint8 InstanceId  = 2U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < 2U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_2_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 2 - channel 3.
 */
ISR(FTM_2_CH_2_CH_3_ISR)
{

    uint8 InstanceId  = 2U;
    uint8 ChanneId = 2U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 2U; ChanneId < 4U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_2_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 4 - channel 5.
 */
ISR(FTM_2_CH_4_CH_5_ISR)
{

    uint8 InstanceId  = 2U;
    uint8 ChanneId = 4U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 4U; ChanneId < 6U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_2_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 6 - channel 7.
 */
ISR(FTM_2_CH_6_CH_7_ISR)
{

    uint8 InstanceId  = 2U;
    uint8 ChanneId = 6U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 6U; ChanneId < 8U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_3_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 0 - channel 1.
 */
ISR(FTM_3_CH_0_CH_1_ISR)
{

    uint8 InstanceId  = 3U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < 2U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_3_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 2 - channel 3.
 */
ISR(FTM_3_CH_2_CH_3_ISR)
{

    uint8 InstanceId  = 3U;
    uint8 ChanneId = 2U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 2U; ChanneId < 4U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_3_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 4 - channel 5.
 */
ISR(FTM_3_CH_4_CH_5_ISR)
{

    uint8 InstanceId  = 3U;
    uint8 ChanneId = 4U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 4U; ChanneId < 6U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_3_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 6 - channel 7.
 */
ISR(FTM_3_CH_6_CH_7_ISR)
{

    uint8 InstanceId  = 3U;
    uint8 ChanneId = 6U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 6U; ChanneId < 8U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_4_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 0 - channel 1.
 */
ISR(FTM_4_CH_0_CH_1_ISR)
{

    uint8 InstanceId  = 4U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < 2U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_4_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 2 - channel 3.
 */
ISR(FTM_4_CH_2_CH_3_ISR)
{

    uint8 InstanceId  = 4U;
    uint8 ChanneId = 2U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 2U; ChanneId < 4U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_4_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 4 - channel 5.
 */
ISR(FTM_4_CH_4_CH_5_ISR)
{

    uint8 InstanceId  = 4U;
    uint8 ChanneId = 4U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 4U; ChanneId < 6U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_4_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 6 - channel 7.
 */
ISR(FTM_4_CH_6_CH_7_ISR)
{

    uint8 InstanceId  = 4U;
    uint8 ChanneId = 6U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 6U; ChanneId < 8U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_5_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 0 - channel 1.
 */
ISR(FTM_5_CH_0_CH_1_ISR)
{

    uint8 InstanceId  = 5U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < 2U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_5_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 2 - channel 3.
 */
ISR(FTM_5_CH_2_CH_3_ISR)
{

    uint8 InstanceId  = 5U;
    uint8 ChanneId = 2U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 2U; ChanneId < 4U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_5_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 4 - channel 5.
 */
ISR(FTM_5_CH_4_CH_5_ISR)
{

    uint8 InstanceId  = 5U;
    uint8 ChanneId = 4U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 4U; ChanneId < 6U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_5_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 6 - channel 7.
 */
ISR(FTM_5_CH_6_CH_7_ISR)
{

    uint8 InstanceId  = 5U;
    uint8 ChanneId = 6U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 6U; ChanneId < 8U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_6_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 0 - channel 1.
 */
ISR(FTM_6_CH_0_CH_1_ISR)
{

    uint8 InstanceId  = 6U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < 2U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_6_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 2 - channel 3.
 */
ISR(FTM_6_CH_2_CH_3_ISR)
{

    uint8 InstanceId  = 6U;
    uint8 ChanneId = 2U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 2U; ChanneId < 4U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_6_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 4 - channel 5.
 */
ISR(FTM_6_CH_4_CH_5_ISR)
{

    uint8 InstanceId  = 6U;
    uint8 ChanneId = 4U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 4U; ChanneId < 6U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_6_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 6 - channel 7.
 */
ISR(FTM_6_CH_6_CH_7_ISR)
{

    uint8 InstanceId  = 6U;
    uint8 ChanneId = 6U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 6U; ChanneId < 8U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_7_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 0 - channel 1.
 */
ISR(FTM_7_CH_0_CH_1_ISR)
{

    uint8 InstanceId  = 7U;
    uint8 ChanneId = 0U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 0U; ChanneId < 2U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_7_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 2 - channel 3.
 */
ISR(FTM_7_CH_2_CH_3_ISR)
{

    uint8 InstanceId  = 7U;
    uint8 ChanneId = 2U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 2U; ChanneId < 4U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_7_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 4 - channel 5.
 */
ISR(FTM_7_CH_4_CH_5_ISR)
{

    uint8 InstanceId  = 7U;
    uint8 ChanneId = 4U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 4U; ChanneId < 6U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_7_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 6 - channel 7.
 */
ISR(FTM_7_CH_6_CH_7_ISR)
{

    uint8 InstanceId  = 7U;
    uint8 ChanneId = 6U;
    uint8 ChfStatus;
    const Ftm_Pwm_Ip_HwAddrType *const FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];

    /* Verify status for each channel and process interrupt. */
    for (ChanneId = 6U; ChanneId < 8U; ChanneId++)
    {
        /* Get match-compare interrupt flag status */
        ChfStatus = (TRUE == Ftm_Pwm_Ip_HasChnEventOccurred(FtmBase, ChanneId))? 0x01U : 0x00U;

        if(0U != ChfStatus )
        {
            Ftm_Pwm_Ip_ProcessCommonInterrupt(InstanceId, ChanneId);
        }
    }
    EXIT_INTERRUPT();
}
#endif


#if (defined FTM_PWM_IP_0_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 fault
 */
ISR(FTM_0_FAULT_ISR)
{
    uint8 InstanceId = 0U;
    uint8 FaultId = 0U;
    boolean FaultStatus;
    boolean FaultChStatus;
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
    /* Get fault interrupt flag status */
    FaultStatus = Ftm_Pwm_Ip_GetFaultDetectionFlag(FtmBase);
    /* Clear fault detection flag */
    Ftm_Pwm_Ip_ClearFaultFlag(FtmBase);
    /* Read FAULTF value and verify if it was an fault detection. */
    if (TRUE == FaultStatus )
    {
         /* Verify status for each fault channel and process interrupt. */
        for (FaultId = 0U; FaultId < FTM_PWM_IP_FAULT_NUMBER_CHANNELS; FaultId++)
        {
            /* Get fault interrupt flag status for each FaultId */
            FaultChStatus = Ftm_Pwm_Ip_GetFaultDetectionFlagId(FtmBase, FaultId);

            if(TRUE == FaultChStatus )
            {
                Ftm_Pwm_Ip_ProcessFaultInterrupt(InstanceId, FaultId);
            }
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_1_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 fault
 */
ISR(FTM_1_FAULT_ISR)
{
    uint8 InstanceId = 1U;
    uint8 FaultId = 0U;
    boolean FaultStatus;
    boolean FaultChStatus;
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
    /* Get fault interrupt flag status */
    FaultStatus = Ftm_Pwm_Ip_GetFaultDetectionFlag(FtmBase);
    /* Clear fault detection flag */
    Ftm_Pwm_Ip_ClearFaultFlag(FtmBase);
    /* Read FAULTF value and verify if it was an fault detection. */
    if (TRUE == FaultStatus )
    {
         /* Verify status for each fault channel and process interrupt. */
        for (FaultId = 0U; FaultId < FTM_PWM_IP_FAULT_NUMBER_CHANNELS; FaultId++)
        {
            /* Get fault interrupt flag status for each FaultId */
            FaultChStatus = Ftm_Pwm_Ip_GetFaultDetectionFlagId(FtmBase, FaultId);

            if(TRUE == FaultChStatus )
            {
                Ftm_Pwm_Ip_ProcessFaultInterrupt(InstanceId, FaultId);
            }
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_2_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 fault
 */
ISR(FTM_2_FAULT_ISR)
{
    uint8 InstanceId = 2U;
    uint8 FaultId = 0U;
    boolean FaultStatus;
    boolean FaultChStatus;
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
    /* Get fault interrupt flag status */
    FaultStatus = Ftm_Pwm_Ip_GetFaultDetectionFlag(FtmBase);
    /* Clear fault detection flag */
    Ftm_Pwm_Ip_ClearFaultFlag(FtmBase);
    /* Read FAULTF value and verify if it was an fault detection. */
    if (TRUE == FaultStatus )
    {
         /* Verify status for each fault channel and process interrupt. */
        for (FaultId = 0U; FaultId < FTM_PWM_IP_FAULT_NUMBER_CHANNELS; FaultId++)
        {
            /* Get fault interrupt flag status for each FaultId */
            FaultChStatus = Ftm_Pwm_Ip_GetFaultDetectionFlagId(FtmBase, FaultId);

            if(TRUE == FaultChStatus )
            {
                Ftm_Pwm_Ip_ProcessFaultInterrupt(InstanceId, FaultId);
            }
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_3_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 fault
 */
ISR(FTM_3_FAULT_ISR)
{
    uint8 InstanceId = 3U;
    uint8 FaultId = 0U;
    boolean FaultStatus;
    boolean FaultChStatus;
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
    /* Get fault interrupt flag status */
    FaultStatus = Ftm_Pwm_Ip_GetFaultDetectionFlag(FtmBase);
    /* Clear fault detection flag */
    Ftm_Pwm_Ip_ClearFaultFlag(FtmBase);
    /* Read FAULTF value and verify if it was an fault detection. */
    if (TRUE == FaultStatus )
    {
         /* Verify status for each fault channel and process interrupt. */
        for (FaultId = 0U; FaultId < FTM_PWM_IP_FAULT_NUMBER_CHANNELS; FaultId++)
        {
            /* Get fault interrupt flag status for each FaultId */
            FaultChStatus = Ftm_Pwm_Ip_GetFaultDetectionFlagId(FtmBase, FaultId);

            if(TRUE == FaultChStatus )
            {
                Ftm_Pwm_Ip_ProcessFaultInterrupt(InstanceId, FaultId);
            }
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_4_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 fault
 */
ISR(FTM_4_FAULT_ISR)
{
    uint8 InstanceId = 4U;
    uint8 FaultId = 0U;
    boolean FaultStatus;
    boolean FaultChStatus;
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
    /* Get fault interrupt flag status */
    FaultStatus = Ftm_Pwm_Ip_GetFaultDetectionFlag(FtmBase);
    /* Clear fault detection flag */
    Ftm_Pwm_Ip_ClearFaultFlag(FtmBase);
    /* Read FAULTF value and verify if it was an fault detection. */
    if (TRUE == FaultStatus )
    {
         /* Verify status for each fault channel and process interrupt. */
        for (FaultId = 0U; FaultId < FTM_PWM_IP_FAULT_NUMBER_CHANNELS; FaultId++)
        {
            /* Get fault interrupt flag status for each FaultId */
            FaultChStatus = Ftm_Pwm_Ip_GetFaultDetectionFlagId(FtmBase, FaultId);

            if(TRUE == FaultChStatus )
            {
                Ftm_Pwm_Ip_ProcessFaultInterrupt(InstanceId, FaultId);
            }
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_5_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 fault
 */
ISR(FTM_5_FAULT_ISR)
{
    uint8 InstanceId = 5U;
    uint8 FaultId = 0U;
    boolean FaultStatus;
    boolean FaultChStatus;
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
    /* Get fault interrupt flag status */
    FaultStatus = Ftm_Pwm_Ip_GetFaultDetectionFlag(FtmBase);
    /* Clear fault detection flag */
    Ftm_Pwm_Ip_ClearFaultFlag(FtmBase);
    /* Read FAULTF value and verify if it was an fault detection. */
    if (TRUE == FaultStatus )
    {
         /* Verify status for each fault channel and process interrupt. */
        for (FaultId = 0U; FaultId < FTM_PWM_IP_FAULT_NUMBER_CHANNELS; FaultId++)
        {
            /* Get fault interrupt flag status for each FaultId */
            FaultChStatus = Ftm_Pwm_Ip_GetFaultDetectionFlagId(FtmBase, FaultId);

            if(TRUE == FaultChStatus )
            {
                Ftm_Pwm_Ip_ProcessFaultInterrupt(InstanceId, FaultId);
            }
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_6_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 fault
 */
ISR(FTM_6_FAULT_ISR)
{
    uint8 InstanceId = 6U;
    uint8 FaultId = 0U;
    boolean FaultStatus;
    boolean FaultChStatus;
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
    /* Get fault interrupt flag status */
    FaultStatus = Ftm_Pwm_Ip_GetFaultDetectionFlag(FtmBase);
    /* Clear fault detection flag */
    Ftm_Pwm_Ip_ClearFaultFlag(FtmBase);
    /* Read FAULTF value and verify if it was an fault detection. */
    if (TRUE == FaultStatus )
    {
         /* Verify status for each fault channel and process interrupt. */
        for (FaultId = 0U; FaultId < FTM_PWM_IP_FAULT_NUMBER_CHANNELS; FaultId++)
        {
            /* Get fault interrupt flag status for each FaultId */
            FaultChStatus = Ftm_Pwm_Ip_GetFaultDetectionFlagId(FtmBase, FaultId);

            if(TRUE == FaultChStatus )
            {
                Ftm_Pwm_Ip_ProcessFaultInterrupt(InstanceId, FaultId);
            }
        }
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_PWM_IP_7_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 fault
 */
ISR(FTM_7_FAULT_ISR)
{
    uint8 InstanceId = 7U;
    uint8 FaultId = 0U;
    boolean FaultStatus;
    boolean FaultChStatus;
    Ftm_Pwm_Ip_HwAddrType * FtmBase = Ftm_Pwm_Ip_aFtmBase[InstanceId];
    /* Get fault interrupt flag status */
    FaultStatus = Ftm_Pwm_Ip_GetFaultDetectionFlag(FtmBase);
    /* Clear fault detection flag */
    Ftm_Pwm_Ip_ClearFaultFlag(FtmBase);
    /* Read FAULTF value and verify if it was an fault detection. */
    if (TRUE == FaultStatus )
    {
         /* Verify status for each fault channel and process interrupt. */
        for (FaultId = 0U; FaultId < FTM_PWM_IP_FAULT_NUMBER_CHANNELS; FaultId++)
        {
            /* Get fault interrupt flag status for each FaultId */
            FaultChStatus = Ftm_Pwm_Ip_GetFaultDetectionFlagId(FtmBase, FaultId);

            if(TRUE == FaultChStatus )
            {
                Ftm_Pwm_Ip_ProcessFaultInterrupt(InstanceId, FaultId);
            }
        }
    }
    EXIT_INTERRUPT();
}
#endif

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}

/** @} */

#endif
