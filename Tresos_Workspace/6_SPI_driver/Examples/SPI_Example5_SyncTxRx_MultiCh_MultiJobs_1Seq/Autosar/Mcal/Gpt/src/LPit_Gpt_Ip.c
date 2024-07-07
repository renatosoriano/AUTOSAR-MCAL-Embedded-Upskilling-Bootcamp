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
*   @file       LPit_Gpt_Ip.c
*
*   @addtogroup lpit_ip LPit IPL
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
#include "LPit_Gpt_Ip.h"

#ifdef LPIT_GPT_IP_ENABLE_USER_MODE_SUPPORT
   #define USER_MODE_REG_PROT_ENABLED   LPIT_GPT_IP_ENABLE_USER_MODE_SUPPORT
   #include "RegLockMacros.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPIT_GPT_IP_VENDOR_ID_C                    43
#define LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_C     7
#define LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_C  0
#define LPIT_GPT_IP_SW_MAJOR_VERSION_C             2
#define LPIT_GPT_IP_SW_MINOR_VERSION_C             0
#define LPIT_GPT_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (LPIT_GPT_IP_VENDOR_ID != LPIT_GPT_IP_VENDOR_ID_C)
    #error "LPit_Ip.h and LPit_Ip.c have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION != LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION != LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION != LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_C) \
    )
    #error "AutoSar Version Numbers of LPit_Gpt_Ip.h and LPit_Gpt_Ip.c are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((LPIT_GPT_IP_SW_MAJOR_VERSION != LPIT_GPT_IP_SW_MAJOR_VERSION_C) || \
     (LPIT_GPT_IP_SW_MINOR_VERSION != LPIT_GPT_IP_SW_MINOR_VERSION_C) || \
     (LPIT_GPT_IP_SW_PATCH_VERSION != LPIT_GPT_IP_SW_PATCH_VERSION_C) \
    )
    #error "Software Version Numbers of LPit_Gpt_Ip.h and LPit_Gpt_Ip.c are different"
#endif

#ifdef LPIT_GPT_IP_ENABLE_USER_MODE_SUPPORT
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION != LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_C) || \
         (REGLOCKMACROS_AR_RELEASE_MINOR_VERSION != LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_C))
        #error "AutoSar Version Numbers of RegLockMacros.h and LPit_Gpt_Ip.c are different"
    #endif
#endif
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if (LPIT_GPT_IP_USED == STD_ON)
#if ((defined LPIT_0_ISR_USED) || (defined LPIT_0_CH_0_ISR_USED) || (defined LPIT_0_CH_1_ISR_USED) || (defined LPIT_0_CH_2_ISR_USED) || (defined LPIT_0_CH_3_ISR_USED))
static Lpit_Gpt_Ip_State Lpit_Gpt_Ip_u32ChState[LPIT_INSTANCE_COUNT][LPIT_TMR_COUNT] =  {
                                                                                            {
                                                                                                {
                                                                                                    (boolean)FALSE,
                                                                                                    NULL_PTR,
                                                                                                    0U,
                                                                                                    LPIT_GPT_IP_CH_MODE_CONTINUOUS
                                                                                                }
                                                                                            }
                                                                                        };
#endif
#if (LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
#define GPT_START_SEC_VAR_CLEARED_BOOLEAN
#include "Gpt_MemMap.h"
/**
* @brief            Lpit_Gpt_Ip_bIsChangedTimeout
* @details          Local variable used to check that whether this channel called ChangeNextTimeout.
*/
static boolean Lpit_Gpt_Ip_bIsChangedTimeout;
#define GPT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Gpt_MemMap.h"
#endif /* (LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON) */
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Table of base addresses for PIT instances. */
LPIT_Type * const LPitGptBase[LPIT_INSTANCE_COUNT] = IP_LPIT_BASE_PTRS;
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#if (LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
#define GPT_START_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"
/**
* @brief            Lpit_Gpt_Ip_u32OldTargetValue
* @details          Local variable used to store the previous target time value after call ChangeNextTimeout.
*/
uint32 Lpit_Gpt_Ip_u32OldTargetValue;
#define GPT_STOP_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"
#endif /* (LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON) */

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#if ((defined LPIT_0_ISR_USED) || (defined LPIT_0_CH_0_ISR_USED) || (defined LPIT_0_CH_1_ISR_USED) || (defined LPIT_0_CH_2_ISR_USED) || (defined LPIT_0_CH_3_ISR_USED))
static void Lpit_Gpt_Ip_ProcessChannelInterrupt(uint8 instance, uint8 channel);
#endif

static inline void Lpit_Gpt_Ip_EnableMdlClk(uint8 instance, boolean enable);
static inline void Lpit_Gpt_Ip_TimerEnable(uint8 instance, uint8 channel, boolean enable);
#if (LPIT_GPT_IP_ENABLE_EXT_TRIGGERS == STD_ON)
static inline void Lpit_Gpt_Ip_SetTrigger(uint8 instance, uint8 channel, uint32 value);
#endif
static inline void Lpit_Gpt_Ip_SetMode(uint8 instance, uint8 channel, uint32 mode);
static inline void Lpit_Gpt_Ip_SetCmpValue(uint8 instance, uint8 channel, uint32 value);
static inline void Lpit_Gpt_Ip_SetDebugMode(uint8 instance, boolean stopRun);
#if (LPIT_GPT_IP_DOZE_MODE_SUPPORT == STD_ON)
static inline void Lpit_Gpt_Ip_SetDozeMode(uint8 instance, boolean running);
#endif

#if (LPIT_GPT_IP_CHAIN_MODE == STD_ON)
static inline void Lpit_Gpt_Ip_SetChainMode(uint8 instance, uint8 channel, boolean enable);
#endif

/*!
 * @brief   Set the Interrupt Enable Flag of LPIT peripheral timer channel.
 * @details MIER Module Interrupt Enable Register
 *          Channel 0 ... 3 Timer Interrupt Enable Flags: TIE0 ... TIE3.
 *          • 0 - Disables Timer Interrupt
 *          • 1 - Enables Timer Interrupt
 *
 * @param[in] instance - Instance number of LPIT module
 * @param[in] channel - The channel in the LPIT instance
 * @param[in] enable - The interrupt enabling/disabling that decides if Timer Interrupt will be enabled/disabled.
 *
 * @return  void
 * @pre The driver needs to be initialized.
 *
 */
static inline void Lpit_Gpt_Ip_SetChannelInterruptEnableFlag(uint8 instance, uint8 channel, boolean enable);

/*!
 * @brief   Get the Interrupt Enable Status of LPIT peripheral timer channel.
 * @details MIER Module Interrupt Enable Register
 *          Channel 0 ... 3 Timer Interrupt Enable Flags: TIE0 ... TIE3.
 *          • 0 - Disables Timer Interrupt
 *          • 1 - Enables Timer Interrupt
 *
 * @param[in] instance - Instance number of LPIT module
 * @param[in] channel - The channel in the LPIT instance
 *
 * @return Channel Interrupt Enable Status
 *         - True : Channel interrupts are enabled
 *         - False : Channel interrupts are disabled
 * @pre The driver needs to be initialized.
 *
 */
static inline boolean Lpit_Gpt_Ip_GetChannelInterruptEnableStatus(uint8 instance, uint8 channel);
/*==================================================================================================
*                                     GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if (defined (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT) && (STD_ON == LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT))
    #ifdef LPIT_0_ISR_USED
ISR(LPIT_0_ISR);
    #endif
#else
    #ifdef LPIT_0_CH_0_ISR_USED
ISR(LPIT_0_CH_0_ISR);
    #endif

    #ifdef LPIT_0_CH_1_ISR_USED
ISR(LPIT_0_CH_1_ISR);
    #endif

    #ifdef LPIT_0_CH_2_ISR_USED
ISR(LPIT_0_CH_2_ISR);
    #endif

    #ifdef LPIT_0_CH_3_ISR_USED
ISR(LPIT_0_CH_3_ISR);
    #endif
#endif /*LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON*/

/*==================================================================================================
*                                  LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief
* Function Name : Lpit_Gpt_Ip_EnableMdlClk
* Description   : Enable hardware module clock (Module Clock Enable)
*
* @param[in]     instance       LPit hardware instance number
* @param[in]     enable         (TRUE/FALSE)
*
* @return        void
*
*/
static inline void Lpit_Gpt_Ip_EnableMdlClk(uint8 instance, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_50();
    if (TRUE == enable)
    {
        LPitGptBase[instance]->MCR  |= LPIT_MCR_M_CEN_MASK;
    }
    else
    {
        LPitGptBase[instance]->MCR  &= (~(LPIT_MCR_M_CEN_MASK));
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_50();
}

/**
* @brief
* Function Name : Lpit_Gpt_Ip_TimerEnable
* Description   : Enable Timer Enable (T_EN)
*
* @param[in]     instance       LPit hardware instance number
* @param[in]     channel        LPit hardware channel number
* @param[in]     enable         (TRUE/FALSE)
*
* @return        void
*
*/
static inline void Lpit_Gpt_Ip_TimerEnable(uint8 instance, uint8 channel, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_51();
    if (TRUE == enable)
    {
        LPitGptBase[instance]->TMR[channel].TCTRL  |= LPIT_TMR_TCTRL_T_EN_MASK;
    }
    else
    {
        LPitGptBase[instance]->TMR[channel].TCTRL  &= (~(LPIT_TMR_TCTRL_T_EN_MASK));
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_51();
}

#if (LPIT_GPT_IP_ENABLE_EXT_TRIGGERS == STD_ON)
/**
* @brief
* Function Name : Lpit_Gpt_Ip_SetTrigger
* Description   : Set trigger (TCTRL)
*
* @param[in]     instance       LPit hardware instance number
* @param[in]     channel
* @param[in]     value
*
* @return        void
*
*/
static inline void Lpit_Gpt_Ip_SetTrigger(uint8 instance, uint8 channel, uint32 value)
{
    LPitGptBase[instance]-> TMR[channel].TCTRL = value;
}
#endif

/**
* @brief
* Function Name : Lpit_Gpt_Ip_SetMode
* Description   : Configures the channel timer's mode of operation. The MODE bits control how the timer decrements
* @param[in]    : Set mode
*                               - 00b - 32-bit Periodic Counter
*                               - 01b - Dual 16-bit Periodic Counter
*                               - 10b - 32-bit Trigger Accumulator
*                               - 11b - 32-bit Trigger Input Capture
* @param[in]     instance       LPit hardware instance number
*
* @return        void
*
*/
static inline void Lpit_Gpt_Ip_SetMode(uint8 instance, uint8 channel, uint32 mode)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_52();
    LPitGptBase[instance]->TMR[channel].TCTRL = (LPitGptBase[instance]->TMR[channel].TCTRL & ~LPIT_TMR_TCTRL_MODE_MASK) | LPIT_TMR_TCTRL_MODE(mode);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_52();
}


/**
* @brief
* Function Name : Lpit_Gpt_Ip_SetCmpValue
* Description   : Set the SetCmpValue
*
* @param[in]     instance       LPit hardware instance number
* @param[in]     value
*
* @return        void
*
*/
static inline void Lpit_Gpt_Ip_SetCmpValue(uint8 instance, uint8 channel, uint32 value)
{
    LPitGptBase[instance]->TMR[channel].TVAL = (uint32)(((uint32)value << LPIT_TMR_TVAL_TMR_VAL_SHIFT) & LPIT_TMR_TVAL_TMR_VAL_MASK);
}


/**
* @brief         Lpit_Ip_SetDebugMode
* @details       This register enables or disables the LPIT timer clocks and controls the timers
*                when the LPIT enters the Debug mode. (DBG_EN)
*
*                Stops the timer channels when the device enters Debug mode
*                  - 0b - Stop timer channels in Debug mode
*                  - 1b - Allow timer channels to continue to run in Debug mode
*
* @param[in]     instance      LPIT hw instance number
* @param[in]     stopRun       (TRUE/FALSE)
*
*
* @return        void
* @pre           The driver needs to be initialized.Enable/disable debug mode.
*/
static inline void Lpit_Gpt_Ip_SetDebugMode(uint8 instance, boolean stopRun)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_53();
    if (TRUE == stopRun)
    {
        LPitGptBase[instance]->MCR &= ~LPIT_MCR_DBG_EN_MASK;
    }
    else
    {
        LPitGptBase[instance]->MCR |= LPIT_MCR_DBG_EN_MASK;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_53();
}
#if (LPIT_GPT_IP_DOZE_MODE_SUPPORT == STD_ON)
/**
* @brief         Lpit_Ip_SetDozeMode
* @details       This register enables or disables Doze mode
*                when the LPIT enters the Doze mode. (DOZE_EN)
*
*                Stops the timer channels when the device enters DOZE mode
*                - 0b - Stop timer channels in DOZE mode
*                - 1b - Allow timer channels to continue to run in DOZE mode
*
* @param[in]     instance      LPIT hw instance number
* @param[in]     running
*
* @return        void
* @pre           The driver needs to be initialized.Enable/disable Doze mode.
*/
static inline void Lpit_Gpt_Ip_SetDozeMode(uint8 instance, boolean running)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_54();
    if (TRUE == running)
    {
        LPitGptBase[instance]->MCR |= LPIT_MCR_DOZE_EN_MASK;
    }
    else
    {
        LPitGptBase[instance]->MCR &= ~LPIT_MCR_DOZE_EN_MASK;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_54();
}
#endif

/*!
 * @brief   Set the Interrupt Enable Flag of LPIT peripheral timer channel.
 *
 */
static inline void Lpit_Gpt_Ip_SetChannelInterruptEnableFlag(uint8 instance, uint8 channel, boolean enable)
{
    uint32 mask = ((instance < LPIT_INSTANCE_COUNT) && (channel < LPIT_TMR_COUNT)) ? (1UL << channel) : 0U;
    if ((instance < LPIT_INSTANCE_COUNT) && (channel < LPIT_TMR_COUNT))
    {
        if (enable)
        {
            LPitGptBase[instance]->MIER |= mask;
        }
        else
        {
            LPitGptBase[instance]->MIER &= ~mask;
        }
    }
}

#if (LPIT_GPT_IP_CHAIN_MODE == STD_ON)
/**
* @brief         Lpit_Gpt_Ip_SetChainMode
* @details       Support chain mode (CHAIN)
*                This register is intended for Timer Control
*
*                Chain Channel
*                When enabled, the timer channel will decrement when timer channel N-1 trigger asserts. Timer channel 0
*                cannot be chained.
*                 - 0b - Channel Chaining is disabled. The channel timer runs independently.
*                 - 1b - Channel Chaining is enabled. The timer decrements on the previous channel's timeout.
*
* @param[in]     instance      LPIT hw instance number
* @param[in]     channel       LPIT hw instance number
* @param[in]     enable        TRUE/FALSE
*
* @return        void
* @pre           The driver needs to be initialized.Enable/disable chain mode.
*/
static inline void Lpit_Gpt_Ip_SetChainMode(uint8 instance, uint8 channel, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_56();
    if ((TRUE == enable) && (channel > 0U))
    {
        LPitGptBase[instance]->TMR[channel].TCTRL |= LPIT_TMR_TCTRL_CHAIN_MASK;
    }
    else
    {
        LPitGptBase[instance]->TMR[channel].TCTRL &= ~LPIT_TMR_TCTRL_CHAIN_MASK;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_56();
}
#endif

/*!
 * @brief   Get the Interrupt Enable Status of LPIT peripheral timer channel.
 *
 */
static inline boolean Lpit_Gpt_Ip_GetChannelInterruptEnableStatus(uint8 instance, uint8 channel)
{
    uint32 mask = ((instance < LPIT_INSTANCE_COUNT) && (channel < LPIT_TMR_COUNT)) ? (1UL << channel) : 0U;
    boolean retVal = ((instance < LPIT_INSTANCE_COUNT) && (channel < LPIT_TMR_COUNT)) ? ((0U != (LPitGptBase[instance]->MIER & mask)) ? TRUE : FALSE) : FALSE;
    return retVal;
}

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief         Function Name : Lpit_Gpt_Ip_Init
* @details       Driver initialization function for LPit instance.
*
*               - enables the LPIT module
*               - configures the freeze mode (enabled or disabled)
*               - configures the DOZE mode (enabled or disabled)
*
* @param[in]     instance     LPIT hw instance number
* @param[in]     config       Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver
* @implements    Lpit_Gpt_Ip_Init_Activity
*/
void Lpit_Gpt_Ip_Init(uint8 instance, const Lpit_Gpt_Ip_InstanceConfigType *config)
{
#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
    DevAssert(LPIT_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != config);
#endif
    /* Enable hardware module clock. This shall be be executed before any other setup is made */
    Lpit_Gpt_Ip_EnableMdlClk(instance, TRUE);

    /* Sets LPIT operation in Debug mode*/
    Lpit_Gpt_Ip_SetDebugMode(instance, config->stopRunInDebug);
#if (LPIT_GPT_IP_DOZE_MODE_SUPPORT == STD_ON)
    /* Enable LPIT in DOZE modes */
    Lpit_Gpt_Ip_SetDozeMode(instance, config->runInDozeMode);
#endif
}
/*================================================================================================*/
/**
* @brief         Function Name : Lpit_Gpt_Ip_InitChannel
* @details       Initializes the LPIT channels. This functions is called for each LPIT hw channel.
*
*               - disables the IRQ correpsonding to the LPIT channel
*               - clears the (pending) interrupt flag corresponding to LPit channel
*               - disables the LPIT timer channel
*               - clears the Load Value register correponding to the LPit channel.
*
*
* @param[in]     instance        LPIT hw instance number
* @param[in]     configChannel   Pointer to a selected configuration structure.
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver.
* @implements    Lpit_Gpt_Ip_InitChannel_Activity
*/
void Lpit_Gpt_Ip_InitChannel(uint8 instance, const Lpit_Gpt_Ip_ChannelConfigType *configChannel)
{
#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
    DevAssert(LPIT_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != configChannel);
    DevAssert(LPIT_TMR_COUNT > configChannel->hwChannel);
#endif

    /* Enable hardware module clock. This shall be be executed before any other setup is made */
    Lpit_Gpt_Ip_EnableMdlClk(instance, TRUE);
    /* Stop Channel to Configure Channel */
    Lpit_Gpt_Ip_TimerEnable(instance, configChannel->hwChannel, FALSE);

    /* Config LPIT Mode as periodic counters */
    Lpit_Gpt_Ip_SetMode(instance, configChannel->hwChannel, (uint32)0U);

    /* Set Compare Value to 0 */
    Lpit_Gpt_Ip_SetCmpValue(instance, configChannel->hwChannel, 0xFFFFFFFFU);

#if (LPIT_GPT_IP_ENABLE_EXT_TRIGGERS == STD_ON)
    /* Configures Trigger */
    Lpit_Gpt_Ip_SetTrigger(instance, configChannel->hwChannel,configChannel->triggerConfig);
#endif

    /* Disable interrupts */
    Lpit_Gpt_Ip_SetChannelInterruptEnableFlag(instance, configChannel->hwChannel, FALSE);

    /* Clear pending interrupts */
    Lpit_Gpt_Ip_ClearChannelInterruptFlag(instance, configChannel->hwChannel);

#if ((defined LPIT_0_ISR_USED) || (defined LPIT_0_CH_0_ISR_USED) || (defined LPIT_0_CH_1_ISR_USED) || (defined LPIT_0_CH_2_ISR_USED) || (defined LPIT_0_CH_3_ISR_USED))
    Lpit_Gpt_Ip_u32ChState[instance][configChannel->hwChannel].chInit = TRUE;
    Lpit_Gpt_Ip_u32ChState[instance][configChannel->hwChannel].callback = configChannel->callback;
    Lpit_Gpt_Ip_u32ChState[instance][configChannel->hwChannel].callbackParam = configChannel->callbackParam;
    Lpit_Gpt_Ip_u32ChState[instance][configChannel->hwChannel].channelMode = configChannel->channelMode;
#endif

}

/*================================================================================================*/
/**
* @brief         Function Name: Lpit_Gpt_Ip_Deinit
* @details       De-Initializes the LPIT instances. This functions is called and
*
*
* @param[in]     instance        LPit hw instance
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver.
*
* @implements    Lpit_Gpt_Ip_Deinit_Activity
*/
void Lpit_Gpt_Ip_Deinit(uint8 instance)
{
#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
    DevAssert(LPIT_INSTANCE_COUNT > instance);
#endif
    uint8 channelIndex;
    /* Enable hardware module clock. This shall be be executed before any other setup is made */
    Lpit_Gpt_Ip_EnableMdlClk(instance, TRUE);
    /*Reset all channels to default*/
    for (channelIndex = 0; channelIndex < LPIT_TMR_COUNT; channelIndex++)
    {
        /* Reset Status and Control Register */
        Lpit_Gpt_Ip_TimerEnable(instance, channelIndex, FALSE);

        /* Config LPIT Mode as periodic counters */
        Lpit_Gpt_Ip_SetMode(instance, channelIndex, (uint32)0U);

        /* Disable channel interrupts */
        Lpit_Gpt_Ip_SetChannelInterruptEnableFlag(instance, channelIndex, FALSE);

        /* Clear Interrupt Flag */
        Lpit_Gpt_Ip_ClearChannelInterruptFlag(instance, channelIndex);
    }

    /* Sets LPIT operation in Debug mode*/
    Lpit_Gpt_Ip_SetDebugMode(instance, FALSE);
#if (LPIT_GPT_IP_DOZE_MODE_SUPPORT == STD_ON)
    /* Enable LPIT in DOZE modes */
    Lpit_Gpt_Ip_SetDozeMode(instance, FALSE);
#endif
    /* Disable hardware module clock */
    Lpit_Gpt_Ip_EnableMdlClk(instance, FALSE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Lpit_Gpt_Ip_StartTimer
* @details      This function is called for starting the LPit timer channel.
*                    - sets the timeout value into the LPIT timer channel register
*                    - enables the LPIT channel
*
* @param[in]     instance        LPit hw instance
* @param[in]     channel         LPit hw channel
* @param[in]     countValue      channel timeout value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the Pit timer channel.
* @implements    Lpit_Gpt_Ip_StartTimer_Activity
*/
void Lpit_Gpt_Ip_StartTimer(uint8 instance, uint8 channel, uint32 countValue)
{
#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
    DevAssert(LPIT_INSTANCE_COUNT > instance);
    DevAssert(LPIT_TMR_COUNT > channel);
    DevAssert(LPIT_MAX_VALUE > countValue);
#endif
#if (LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
    Lpit_Gpt_Ip_bIsChangedTimeout = FALSE;
#endif
    /* Lpit timer disable */
    Lpit_Gpt_Ip_TimerEnable(instance, channel, FALSE);

    /* Sets the timer channel period in count unit   */
    Lpit_Gpt_Ip_SetCmpValue(instance, channel, countValue);

    /* Lpit timer enable */
    Lpit_Gpt_Ip_TimerEnable(instance, channel, TRUE);
}

/*================================================================================================*/
/**
* @brief         Function Name : Lpit_Gpt_Ip_StopTimer
* @details       This function is called for stopping the LPit counter. This function disables the LPIT channel
*
*
* @param[in]     instance        LPit hw instance
* @param[in]     channel         LPit hw channel
* @return        void
* @pre           The driver needs to be initialized. Lpit_Gpt_Ip_StartTimer must be call before.
* @implements    Lpit_Gpt_Ip_StopTimer_Activity
*/
void Lpit_Gpt_Ip_StopTimer(uint8 instance, uint8 channel)
{
#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
    DevAssert(LPIT_INSTANCE_COUNT > instance);
    DevAssert(LPIT_TMR_COUNT > channel);
#endif
    /* Lpit timer disable */
    Lpit_Gpt_Ip_TimerEnable(instance, channel, FALSE);

    /* Clear interrupt flag */
    Lpit_Gpt_Ip_ClearChannelInterruptFlag(instance, channel);
}

/*================================================================================================*/
/**
* @brief        Function Name : Lpit_Gpt_Ip_EnableChInterrupt
* @details      This function allows enabling interrupt generation of timer channel
*               when timeout occurs
*
* @param[in]    instance        LPit hw instance
* @param[in]    channel         LPit hw channel
* @return       void
* @pre          The driver needs to be initialized.
* @implements    Lpit_Gpt_Ip_EnableChInterrupt_Activity
*/
void Lpit_Gpt_Ip_EnableChInterrupt(uint8 instance, uint8 channel)
{
#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
    DevAssert(LPIT_INSTANCE_COUNT > instance);
    DevAssert(LPIT_TMR_COUNT > channel);
#endif
    /* Clear interrupt flag */
    Lpit_Gpt_Ip_ClearChannelInterruptFlag(instance, channel);

    /* Enable interrupt */
    Lpit_Gpt_Ip_SetChannelInterruptEnableFlag(instance, channel, TRUE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Lpit_Gpt_Ip_DisableChInterrupt
* @details      This function allows disabling interrupt of a timer channel
*
* @param[in]    instance        LPit hw instance
* @param[in]    channel         LPit hw channel
* @return       void
* @pre          The driver needs to be initialized.
* @implements    Lpit_Gpt_Ip_DisableChInterrupt_Activity
*/
void Lpit_Gpt_Ip_DisableChInterrupt(uint8 instance, uint8 channel)
{
#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
    DevAssert(LPIT_INSTANCE_COUNT > instance);
    DevAssert(LPIT_TMR_COUNT > channel);
#endif
    /* Clear Lpit interrupt flag */
    Lpit_Gpt_Ip_ClearChannelInterruptFlag(instance, channel);

    /* Disable Lpit interrupt */
    Lpit_Gpt_Ip_SetChannelInterruptEnableFlag(instance, channel, FALSE);
}

/*================================================================================================*/
#if (LPIT_GPT_IP_CHAIN_MODE == STD_ON)
/**
* @brief      Function Name :  Lpit_Gpt_Ip_ChainMode.
* @details    This function:
*               - Chain/Unchain LPit channels.
* @param[in]     instance        LPit hw channel ID
* @param[in]     channel         channel timeout value
* @param[in]     enable          enable/disable chain mode
* @return        returnValue
* @pre           The driver needs to be initialized. LPIT_GPT_IP_CHAIN_MODE == STD_ON
* @implements    Lpit_Gpt_Ip_ChainMode_Activity
*/
Lpit_Gpt_Ip_StatusType Lpit_Gpt_Ip_ChainMode(uint8 instance, uint8 channel, boolean enable)
{
#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
    DevAssert(LPIT_INSTANCE_COUNT > instance);
    DevAssert(LPIT_TMR_COUNT > channel);
#endif
    Lpit_Gpt_Ip_StatusType returnValue = LPIT_GPT_IP_ERROR;
    /* Can not enable chain mode for LPIT_0_CH_0 */
    if((uint8) 0x00 < channel)
    {
        /* Enable Chain Mode*/
        Lpit_Gpt_Ip_SetChainMode(instance, channel, enable);
        returnValue = LPIT_GPT_IP_SUCCESS;
    }

    return returnValue;
}
#endif /*(LPIT_GPT_IP_CHAIN_MODE== STD_ON)*/
/*================================================================================================*/
#if (LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief      The function changes Lpit Timer Load Value Register value.
* @details    This function:
*               - sets the next timeout value.
*
* @param[in]     instance        Lpit hw instance ID
* @param[in]     channel         Lpit hw channel ID
* @param[in]     value           channel timeout value
* @return        void
* @pre           The driver needs to be initialized. LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON
* @implements    Lpit_Gpt_Ip_ChangeNextTimeoutValue_Activity
*/
void Lpit_Gpt_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint32 value)
{
#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
    DevAssert(LPIT_INSTANCE_COUNT > instance);
    DevAssert(LPIT_TMR_COUNT > channel);
#endif

    if(FALSE == Lpit_Gpt_Ip_bIsChangedTimeout)
    {
        Lpit_Gpt_Ip_u32OldTargetValue = Lpit_Gpt_Ip_GetTimerValue(instance, channel);
        Lpit_Gpt_Ip_bIsChangedTimeout = TRUE;
    }
    Lpit_Gpt_Ip_SetCmpValue(instance, channel, value);

}
#endif /* LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */

/*================================================================================================*/
#if ((defined LPIT_0_ISR_USED) || (defined LPIT_0_CH_0_ISR_USED) || (defined LPIT_0_CH_1_ISR_USED) || (defined LPIT_0_CH_2_ISR_USED) || (defined LPIT_0_CH_3_ISR_USED))
/**
* @brief         Driver routine to process all the interrupts of LPIT.
* @details       Support function used by interrupt service routines to implement LPIT specific operations
*                and call the upper layer handler to implement non-hardware specific operations.
*
* @param[in]     instance     LPIT hw instance number
* @param[in]     channel      LPIT hw channel number
* @return        void
* @pre           Enable interrupt service routines
* @implements    Lpit_Gpt_Ip_ProcessChannelInterrupt_Activity
*/
static void Lpit_Gpt_Ip_ProcessChannelInterrupt(uint8 instance, uint8 channel)
{
#if (LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
    Lpit_Gpt_Ip_bIsChangedTimeout = FALSE;
#endif
    boolean IsChEvEnabled;
    boolean HasChEvOccurred;

    boolean                     chInit;
    Lpit_Gpt_Ip_CallbackType    callback;
    uint8                       callbackParam;
    Lpit_Gpt_Ip_ChannelModeType channelMode;

    if ((instance < LPIT_INSTANCE_COUNT) && (channel < LPIT_TMR_COUNT))
    {
        /* enter critical section */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_55();

        /* check if channel event is enabled */
        IsChEvEnabled = Lpit_Gpt_Ip_GetChannelInterruptEnableStatus(instance, channel);

        /* check if channel event has occurred */
        HasChEvOccurred = Lpit_Gpt_Ip_GetChannelInterruptFlagStatus(instance, channel);

        if ((TRUE == IsChEvEnabled) && (TRUE == HasChEvOccurred))
        {
            /* Clear pending interrupts */
            Lpit_Gpt_Ip_ClearChannelInterruptFlag(instance, channel);
        }

        /* exit critical section */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_55();

        /* Check for spurious interrupts */
        if ((TRUE == IsChEvEnabled) && (TRUE == HasChEvOccurred))
        {
            chInit          = Lpit_Gpt_Ip_u32ChState[instance][channel].chInit;
            callback        = Lpit_Gpt_Ip_u32ChState[instance][channel].callback;
            channelMode     = Lpit_Gpt_Ip_u32ChState[instance][channel].channelMode;
            callbackParam   = Lpit_Gpt_Ip_u32ChState[instance][channel].callbackParam;

            if(LPIT_GPT_IP_CH_MODE_ONESHOT == channelMode)
            {
                Lpit_Gpt_Ip_StopTimer(instance, channel);
            }

            /* Call GPT upper layer handler */
            if ((TRUE == chInit) && (NULL_PTR != callback))
            {
                callback(callbackParam);
            }
        }
    }
}
#endif
/*================================================================================================*/

#if (defined (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT) && (STD_ON == LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT))
#ifdef LPIT_0_ISR_USED
/**
* @brief   Interrupt handler for LPIT_0_CH_0 channels.
* @details Interrupt Service Routine corresponding to LPIT_0_CH_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(LPIT_0_ISR)
{
    uint8 channel;

    for (channel = 0U; channel < LPIT_TMR_COUNT; ++channel)
    {
        Lpit_Gpt_Ip_ProcessChannelInterrupt(0U, channel);
    }

    EXIT_INTERRUPT();
}
#endif
#else
#ifdef LPIT_0_CH_0_ISR_USED
/**
* @brief   Interrupt handler for LPIT_0_CH_0 channels.
* @details Interrupt Service Routine corresponding to LPIT_0_CH_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(LPIT_0_CH_0_ISR)
{
    uint8 channel = 0U;

    Lpit_Gpt_Ip_ProcessChannelInterrupt(0U, channel);

    EXIT_INTERRUPT();
}
#endif
/*================================================================================================*/
#ifdef LPIT_0_CH_1_ISR_USED
/**
* @brief   Interrupt handler for LPIT_0_CH_1 channels.
* @details Interrupt Service Routine corresponding to LPIT_0_CH_1 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(LPIT_0_CH_1_ISR)
{
    uint8 channel = 1U;

    Lpit_Gpt_Ip_ProcessChannelInterrupt(0U, channel);

    EXIT_INTERRUPT();
}
#endif
/*================================================================================================*/
#ifdef LPIT_0_CH_2_ISR_USED
/**
* @brief   Interrupt handler for LPIT_0_CH_0 channels.
* @details Interrupt Service Routine corresponding to LPIT_0_CH_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(LPIT_0_CH_2_ISR)
{
    uint8 channel = 2U;

    Lpit_Gpt_Ip_ProcessChannelInterrupt(0U, channel);

    EXIT_INTERRUPT();
}
#endif
/*================================================================================================*/
#ifdef LPIT_0_CH_3_ISR_USED
/**
* @brief   Interrupt handler for LPIT_0_CH_0 channels.
* @details Interrupt Service Routine corresponding to LPIT_0_CH_0 hw module.
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized
*/
ISR(LPIT_0_CH_3_ISR)
{
    uint8 channel = 3U;

    Lpit_Gpt_Ip_ProcessChannelInterrupt(0U, channel);

    EXIT_INTERRUPT();
}
#endif

#endif /*LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT*/
/*================================================================================================*/
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* LPIT_GPT_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif /* LPIT_GPT_IP_C */

/** @} */
