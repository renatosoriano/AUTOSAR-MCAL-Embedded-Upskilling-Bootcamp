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
*   @file           Lptmr_Gpt_Ip.c
*
*   @addtogroup     LPTMR_GPT_IP Lptmr IPL
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
#include "Lptmr_Gpt_Ip.h"
#ifdef LPTMR_GPT_IP_ENABLE_USER_MODE_SUPPORT
   #define USER_MODE_REG_PROT_ENABLED   LPTMR_GPT_IP_ENABLE_USER_MODE_SUPPORT
   #include "RegLockMacros.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPTMR_GPT_IP_VENDOR_ID_C                    43
#define LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION_C     7
#define LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION_C  0
#define LPTMR_GPT_IP_SW_MAJOR_VERSION_C             2
#define LPTMR_GPT_IP_SW_MINOR_VERSION_C             0
#define LPTMR_GPT_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (LPTMR_GPT_IP_VENDOR_ID_C != LPTMR_GPT_IP_VENDOR_ID)
    #error "Lptmr_Gpt_Ip.c and Lptmr_Gpt_Ip.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION_C != LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION_C != LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION) || \
     (LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION_C != LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lptmr_Gpt_Ip.c and Lptmr_Gpt_Ip.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((LPTMR_GPT_IP_SW_MAJOR_VERSION_C != LPTMR_GPT_IP_SW_MAJOR_VERSION) || \
     (LPTMR_GPT_IP_SW_MINOR_VERSION_C != LPTMR_GPT_IP_SW_MINOR_VERSION) || \
     (LPTMR_GPT_IP_SW_PATCH_VERSION_C != LPTMR_GPT_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lptmr_Gpt_Ip.c and Lptmr_Gpt_Ip.h are different"
#endif

#ifdef LPTMR_GPT_IP_ENABLE_USER_MODE_SUPPORT
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION != LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION_C) || \
         (REGLOCKMACROS_AR_RELEASE_MINOR_VERSION != LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION_C))
        #error "AutoSar Version Numbers of RegLockMacros.h and Lptmr_Gpt_Ip.c are different"
    #endif
#endif
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
#if (LPTMR_GPT_IP_USED == STD_ON)

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Table of LPTMR base pointers */
LPTMR_Type * const lptmrGptBase[LPTMR_INSTANCE_COUNT] = IP_LPTMR_BASE_PTRS;
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#if (defined LPTMR_0_CH_0_ISR_USED)
static Lptmr_Gpt_Ip_State Lptmr_Gpt_Ip_u32ChState[LPTMR_INSTANCE_COUNT] =   {
                                                                                {
                                                                                    (boolean)FALSE,
                                                                                    NULL_PTR,
                                                                                    0U,
                                                                                    LPTMR_GPT_IP_CH_MODE_CONTINUOUS
                                                                                }
                                                                            };
#endif
#if (LPTMR_GPT_IP_SET_CLOCK_MODE == STD_ON)
static Lptmr_Gpt_Ip_InstanceState Lptmr_Gpt_Ip_u32InstanceState[LPTMR_INSTANCE_COUNT] =     {
                                                                                                {
                                                                                                    0U,
                                                                                                    0U
                                                                                                }
                                                                                            };
#endif
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

static inline void Lptmr_Gpt_Ip_Configure(LPTMR_Type * const base,
                                                             Lptmr_Gpt_Ip_ClockSelectType clocksource,
                                                             uint8 prescalerValue);
#if (LPTMR_GPT_IP_SET_CLOCK_MODE == STD_ON)
static inline void Lptmr_Gpt_Ip_SetPrescaler(uint8 instance, uint8 prescalerValue);
#endif
static inline void Lptmr_Gpt_Ip_SetTimerEnable(uint8 instance, boolean aboEn);
static inline void Lptmr_Gpt_Ip_SetInterruptEnableFlag(uint8 instance, boolean aboEn);
static inline void Lptmr_Gpt_Ip_ClearInterruptStatusFlag(uint8 instance);
static inline void Lptmr_Gpt_Ip_TimerModeSelect(uint8 instance, uint32 mode);
static inline void Lptmr_Gpt_Ip_CompareValue(uint8 instance, uint16 value);
static inline boolean Lptmr_Gpt_Ip_GetInterruptEnableFlag(uint8 instance);
#ifdef LPTMR_0_CH_0_ISR_USED
ISR(LPTMR_0_CH_0_ISR);
static void Lptmr_Gpt_Ip_ProcessCommonInterrupt(uint8 instance);
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief
* Function Name : Lptmr_Gpt_Ip_GetInterruptEnableFlag
* Description   : Get the bit CSR_TIE (CSR)
*
* @param[in]     instance       LPtimer hardware instance number
*
* @return        status
*
*/
static inline boolean Lptmr_Gpt_Ip_GetInterruptEnableFlag(uint8 instance)
{
    return (0U != (lptmrGptBase[instance]->CSR & LPTMR_CSR_TIE_MASK)) ? TRUE : FALSE;
}

#ifdef LPTMR_0_CH_0_ISR_USED
/**
* @brief         Lptmr_Gpt_Ip_ProcessCommonInterrupt.
* @details       Function used by interrupt service routines to call notification
*                functions if provided and enabled
*
* @param[in]     instance hardware index
* @return        void
* @pre           Enable interrupt service routines
*
* @implements    Lptmr_Gpt_Ip_ProcessCommonInterrupt_Activity
*/
static void Lptmr_Gpt_Ip_ProcessCommonInterrupt(uint8 instance)
{
    boolean IsInterruptEnabled;
    boolean HasInterruptOccurred;

    boolean                         chInit;
    Lptmr_Gpt_Ip_CallbackType       callback;
    uint8                           callbackParam;
    Lptmr_Gpt_Ip_ChannelModeType    channelMode;

    if (instance < LPTMR_INSTANCE_COUNT)
    {
        /* enter critical section */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_40();
        {
            /* check if interrupt is enabled */
            IsInterruptEnabled = Lptmr_Gpt_Ip_GetInterruptEnableFlag(instance);

            /* check if interrupt has occurred */
            HasInterruptOccurred = Lptmr_Gpt_Ip_GetInterruptStatusFlag(instance);

            if (IsInterruptEnabled && HasInterruptOccurred)
            {
                /* Clear pending interrupts */
                Lptmr_Gpt_Ip_ClearInterruptStatusFlag(instance);
            }
        }
        /* exit critical section */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_40();

        /* Check for spurious interrupts */
        if (IsInterruptEnabled && HasInterruptOccurred)
        {
            chInit          = Lptmr_Gpt_Ip_u32ChState[instance].chInit;
            callback        = Lptmr_Gpt_Ip_u32ChState[instance].callback;
            channelMode     = Lptmr_Gpt_Ip_u32ChState[instance].channelMode;
            callbackParam   = Lptmr_Gpt_Ip_u32ChState[instance].callbackParam;

            if(LPTMR_GPT_IP_CH_MODE_ONESHOT == channelMode)
            {
                Lptmr_Gpt_Ip_StopTimer(instance);
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

/**
* @brief
* Function Name : Lptmr_Gpt_Ip_SetTimerEnable
* Description   : Enable/Disable (CSR_TEN)
*
* @param[in]     pointer       Lptimer hardware
* @param[in]     aboEn         TRUE/FALSE
*
* @return        void
*
*/
static inline void Lptmr_Gpt_Ip_SetTimerEnable(uint8 instance, boolean aboEn)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_41();
    lptmrGptBase[instance]->CSR = (lptmrGptBase[instance]->CSR & ~(LPTMR_CSR_TEN_MASK)) | LPTMR_CSR_TEN((TRUE == aboEn) ? 1UL : 0UL);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_41();
}

/**
* @brief
* Function Name : Lptmr_Gpt_Ip_SetInterruptEnableFlag
* Description   : Enable/Disable (CSR_TIE)
*
* @param[in]     pointer       Lptimer hardware
* @param[in]     aboEn        TRUE/FALSE
*
* @return        void
*
*/
static inline void Lptmr_Gpt_Ip_SetInterruptEnableFlag(uint8 instance, boolean aboEn)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_42();
    lptmrGptBase[instance]->CSR = (lptmrGptBase[instance]->CSR & ~(LPTMR_CSR_TIE_MASK)) | LPTMR_CSR_TIE((TRUE == aboEn) ? 1UL : 0UL);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_42();
}

/**
 * @brief
 * Function Name : Lptmr_Gpt_Ip_ClearInterruptStatusFlag
 * Description   : Clear the Timer Compare Flag (TCF)
 *
 * @details
 *  Timer Compare Flag: TCF
 *      TCF is set when the LPTMR is enabled and the CNR equals the CMR and increments.
 *      TCF is cleared when the LPTMR is disabled or a logic 1 is written to it.
 *      NOTE: Ensure to clear this field before enabling the Timer interrupt or DMA request.
 *          0b - The value of CNR is not equal to CMR and increments.
 *          1b - The value of CNR is equal to CMR and increments.
 *
 * @param[in]     instance       LPtimer hardware instance number
 *
 * @return        void
 *
 */
static inline void Lptmr_Gpt_Ip_ClearInterruptStatusFlag(uint8 instance)
{
    /* Clear TCF by writing a logic 1 to it */
    lptmrGptBase[instance]->CSR |= LPTMR_CSR_TCF_MASK;
}

/**
* @brief
* Function Name : Lptmr_Gpt_Ip_TimerModeSelect
* Description   : Enable/Disable (CSR_TMS)
*
* @param[in]     pointer       Lptimer hardware
* @param[in]     enable        TRUE/FALSE
*
* @return        void
*
*/
static inline void Lptmr_Gpt_Ip_TimerModeSelect(uint8 instance, uint32 mode)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_43();

    /* Select mode TMS */
    lptmrGptBase[instance]->CSR = (lptmrGptBase[instance]->CSR & ~LPTMR_CSR_TMS_MASK) | LPTMR_CSR_TMS(mode);

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_43();
}

#if (LPTMR_GPT_IP_SET_CLOCK_MODE == STD_ON)
/**
* @brief
* Function Name : Lptmr_Gpt_Ip_SetPrescaler
* Description   : SetPrescaler - (PSR_PRESCALE)
*
* @param[in]     pointer       Lptimer hardware
* @param[in]     prescalerValue
*
* @return        void
*
*/
static inline void Lptmr_Gpt_Ip_SetPrescaler(uint8 instance, uint8 prescalerValue)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_44();

    lptmrGptBase[instance]->PSR = (lptmrGptBase[instance]->PSR & ~LPTMR_PSR_PRESCALE_MASK) | LPTMR_PSR_PRESCALE(prescalerValue);

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_44();
}
#endif
/*================================================================================================*/
/**
* @brief
* Function Name : Lptmr_Gpt_Ip_Configure
* Description   : Configure the clock source and prescalerValue (PSR register)
*
* @param[in]     instance       LPtimer hardware instance number
* @param[in]     clocksource
* @param[in]     prescalerValue
*
* @return        void
*
*/
static inline void Lptmr_Gpt_Ip_Configure(LPTMR_Type * const base,
                                        Lptmr_Gpt_Ip_ClockSelectType clocksource,
                                        uint8 prescalerValue)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_45();

    base->PSR = (base->PSR & ~LPTMR_PSR_PCS_MASK) | LPTMR_PSR_PCS(clocksource);

    base->PSR = (base->PSR & ~LPTMR_PSR_PRESCALE_MASK) | LPTMR_PSR_PRESCALE(prescalerValue);

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_45();
}

/*================================================================================================*/
/**
* @brief
* Function Name : Lptmr_Gpt_Ip_WriteCompareValue
* Description   : Set value (CMR)
*
* @param[in]     instance       LPtimer hardware instance number
* @param[in]     channel
* @param[in]     value
*
* @return        void
*
*/
static inline void Lptmr_Gpt_Ip_WriteCompareValue(uint8 instance, uint16 value)
{
    lptmrGptBase[instance]->CMR = value;

}

/*================================================================================================*/
/**
* @brief
* Function Name : Lptmr_Gpt_Ip_WriteCounterValue
* Description   : Set value (CNR)
*
* @param[in]     instance       LPtimer hardware instance number
* @param[in]     channel
* @param[in]     value
*
* @return        void
*
*/
void Lptmr_Gpt_Ip_WriteCounterValue(uint8 instance, uint16 value)
{
    lptmrGptBase[instance]->CNR = value;

}

/**
* @brief
* Function Name : Lptmr_Gpt_Ip_CompareValue
* Description   : CompareValue - (LPTMR_CMR_COMPARE)
*
* @param[in]     pointer       Lptimer hardware
* @param[in]     CompareValue
*
* @return        void
*
*/
static inline void Lptmr_Gpt_Ip_CompareValue(uint8 instance, uint16 value)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_46();

    lptmrGptBase[instance]->CMR = (lptmrGptBase[instance]->CMR & ~LPTMR_CMR_COMPARE_MASK) | LPTMR_CMR_COMPARE(value);

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_46();
}

/**
* @brief         Lptmr_Gpt_Ip_GetTimerEnableStatus
* @details       Get the state of a LPTMR instance .Support enable/disable Timer Enable
*                This register is intended for Timer Control Register
*
* @param[in]     instance     LPtimer hw instance number
*
*
* @return        isRunning
* @pre           The driver needs to be initialized.
*
*/
static inline boolean Lptmr_Gpt_Ip_GetTimerEnableStatus(uint8 instance)
{
    return (0U != (lptmrGptBase[instance]->CSR & LPTMR_CSR_TEN_MASK)) ? TRUE : FALSE;
}

/*================================================================================================*/
/**
* @brief
* Function Name : Lptmr_Gpt_Ip_GetCntValue
* Description   : Get current counter value (base->CNR)
*
* @param[in]     instance       LPtimer hardware instance number
*
* @return        currentCntValue
*
*/
uint32 Lptmr_Gpt_Ip_GetCntValue(uint8 instance)
{
    uint32 currentCntValue;
    currentCntValue = lptmrGptBase[instance]->CNR;
    return currentCntValue;
}

/*================================================================================================*/
/**
* @brief
* Function Name : Lptmr_Gpt_Ip_GetCompareValue
* Description   : Get current compare value (base->CMR)
*
* @param[in]     instance       LPtimer hardware instance number
*
* @return        currentCmpValue
*
*/
uint32 Lptmr_Gpt_Ip_GetCompareValue(uint8 instance)
{
    uint32 currentCmpValue;
    currentCmpValue = lptmrGptBase[instance]->CMR;
    return currentCmpValue;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          Low power timer Driver initialization function
* @details        This function is called separately for each LPTMR hw channel corresponding to the configured
*
*               - enables the LPTMR module
*               - configures the freeze mode (enabled or disabled)
*               - disables the IRQ corresponding to the LPTMR channel
*               - clears the (pending) interrupt flag corresponding to Lptmr channel
*               - disables the LPTMR timer channel
*               - clears the Load Value register corresponding to the Lptmr channel.
*
* @param[in]     instance     hw instance
* @param[in]     *config      pointer to configuration
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Lptmr_Gpt_Ip_Init_Activity
*/
void Lptmr_Gpt_Ip_Init(uint8 instance, const Lptmr_Gpt_Ip_ConfigType *config)
{
#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(LPTMR_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != config);
#endif

#if (LPTMR_GPT_IP_STANDBY_WAKEUP_SUPPORT == STD_ON)
    /* check if interrupt is enabled */
    boolean IsInterruptEnabled = Lptmr_Gpt_Ip_GetInterruptEnableFlag(instance);
    /* check if interrupt has occurred */
    boolean HasInterruptOccurred = Lptmr_Gpt_Ip_GetInterruptStatusFlag(instance);
    if (IsInterruptEnabled && HasInterruptOccurred)
    {
#endif
        /* Stop Channel to Configure Channel. This shall be be executed before any other setup is made */
        Lptmr_Gpt_Ip_SetTimerEnable(instance, FALSE);

        /* Disable interrupts */
        Lptmr_Gpt_Ip_SetInterruptEnableFlag(instance, FALSE);

        /* Clear pending interrupts */
        Lptmr_Gpt_Ip_ClearInterruptStatusFlag(instance);

        /* Configures the mode of LPTMR is Time Counter */
        Lptmr_Gpt_Ip_TimerModeSelect(instance, LPTMR_GPT_IP_TM_MODE);

#if (LPTMR_GPT_IP_STANDBY_WAKEUP_SUPPORT == STD_ON)
    }
#endif
    /* Check Prescaler Bypass */
    if (TRUE == config->prescalerEnable)
    {
        lptmrGptBase[instance]->PSR &= ~(LPTMR_PSR_PBYP_MASK);
    }
    else
    {
        lptmrGptBase[instance]->PSR |= (LPTMR_PSR_PBYP_MASK);
    }
    /* Set clock and prescalerValue LPtimer */
    Lptmr_Gpt_Ip_Configure( lptmrGptBase[instance],
                            config->clocksource,
                            config->clockPrescaler );

    /* Write Compare Value */
    Lptmr_Gpt_Ip_WriteCompareValue(instance, 0xFFFFU);

#if (defined LPTMR_0_CH_0_ISR_USED)
    Lptmr_Gpt_Ip_u32ChState[instance].chInit = TRUE;
    Lptmr_Gpt_Ip_u32ChState[instance].callback = config->callback;
    Lptmr_Gpt_Ip_u32ChState[instance].callbackParam = config->callbackParam;
    Lptmr_Gpt_Ip_u32ChState[instance].channelMode = config->channelMode;
#endif

#if (LPTMR_GPT_IP_SET_CLOCK_MODE == STD_ON)
    Lptmr_Gpt_Ip_u32InstanceState[instance].clockPrescaler = config->clockPrescaler;
    Lptmr_Gpt_Ip_u32InstanceState[instance].clockAlternatePrescaler = config->clockAlternatePrescaler;
#endif
}

/*================================================================================================*/
/**
* @brief          de-initialization function for Lptmr module.
* @details        This function is called separately for each LPTMR hw channel corresponding to the configured
*                 timer channels, and:
*               - disables the LPTMR channel
*               - disables the freeze mode
*               - disables IRQ corresponding to Lptmr channel
*               - clears the (pending) interrupt flag corresponding to Lptmr channel
*
*
*
* @param[in]     instance        LPTMR hw instance
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Lptmr_Gpt_Ip_DeInit_Activity
*/
void Lptmr_Gpt_Ip_DeInit(uint8 instance)
{
#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(LPTMR_INSTANCE_COUNT > instance);
#endif

    /* Enable hardware module clock. This shall be be executed before any other setup is made */
    Lptmr_Gpt_Ip_SetTimerEnable(instance, FALSE);

    /* Disable channel interrupts*/
    Lptmr_Gpt_Ip_SetInterruptEnableFlag(instance, FALSE);

    /* Clear Interrupt Flag */
    Lptmr_Gpt_Ip_ClearInterruptStatusFlag(instance);
}

/*================================================================================================*/
/**
* @brief        Function for starting the Lptmr timer channel.
* @details      This function:
*               - clears the (pending) interrupt flag corresponding to Lptmr channel
*               - disables the LPTMR timer channel
*               - sets the timeout value into the LPTMR timer channel register
*               - enables the LPTMR timer channel
*               - enables the IRQ corresponding to the LPTMR timer channel,if channel configured in One Shot mode.
*
* @param[in]     instance   LPtimer hw instance
* @param[in]     value   channel timeout value
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver
* @implements    Lptmr_Gpt_Ip_StartTimer_Activity
*/
void Lptmr_Gpt_Ip_StartTimer(uint8 instance, uint16 value)
{
#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(LPTMR_INSTANCE_COUNT > instance);
#endif

    /* Disable LPTMR timer */
    Lptmr_Gpt_Ip_SetTimerEnable(instance, FALSE);

    /* Write compare value*/
    Lptmr_Gpt_Ip_WriteCompareValue(instance, value);

    /* Enable LPTMR timer */
    Lptmr_Gpt_Ip_SetTimerEnable(instance, TRUE);

}

/*================================================================================================*/
/**
* @brief        Function for stopping the Lptmr timer channel.
* @details      This function disables the LPTMR channel
*
*
* @param[in]     instance        LPTMR hw instance
* @return        void
* @pre           The driver needs to be initialized.
*
* @implements    Lptmr_Gpt_Ip_StopTimer_Activity
*/
void Lptmr_Gpt_Ip_StopTimer(uint8 instance)
{
#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(LPTMR_INSTANCE_COUNT > instance);
#endif

    /* Disable LPTMR timer */
    Lptmr_Gpt_Ip_SetTimerEnable(instance, FALSE);

    /* Clear interrupt flag */
    Lptmr_Gpt_Ip_ClearInterruptStatusFlag(instance);
}

/*================================================================================================*/
/**
* @brief          LPTMR Driver function for get status of comparevalue.
* @details        This function:
*                           - Set the compare value in counter tick units, for a LPTMR instance
* @param[in]     instance           LPTMR hw instance
* @param[in]     compareValue        compare value
*
* @return         Possible return values:
*                - STATUS_SUCCESS: completed successfully
*                - STATUS_ERROR: cannot reconfigure compare value (TCF not set)
*                - STATUS_TIMEOUT: compare value is smaller than current counter value
*
* @pre           The driver needs to be initialized.
*
*
*/
Lptmr_Gpt_Ip_StatusType Lptmr_Gpt_Ip_SetCompareValue(uint8 instance,
                                                     uint16 compareValue)
{
#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(LPTMR_INSTANCE_COUNT > instance);
#endif
    Lptmr_Gpt_Ip_StatusType status;
    uint16 counterVal;

    boolean TimerEnableStatus = Lptmr_Gpt_Ip_GetTimerEnableStatus(instance);
    /* check if interrupt has occurred */
    boolean HasInterruptOccurred = Lptmr_Gpt_Ip_GetInterruptStatusFlag(instance);

    /* The compare value can only be written if counter is disabled or the compare flag is set. */
    if (!TimerEnableStatus || HasInterruptOccurred)
    {
        /* Check if new value is below the current counter value */
        Lptmr_Gpt_Ip_CompareValue(instance, compareValue);
        counterVal = (uint16)Lptmr_Gpt_Ip_GetCntValue(instance);
        status = (counterVal >= compareValue) ? LPTMR_GPT_IP_TIMEOUT : LPTMR_GPT_IP_SUCCESS;
    }
    else      
    {
        status = LPTMR_GPT_IP_ERROR;
    }
    return status;

}

/*================================================================================================*/
/**
* @brief         Driver function for Enable Interrupt for LPtimer channel
* @details       This function:
*                        - Enable Interrupt for LPtimer channel
*
* @param[in]     instance        LPtimer hw instance
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Lptmr_Gpt_Ip_EnableInterrupt_Activity
*/
void Lptmr_Gpt_Ip_EnableInterrupt(uint8 instance)
{
#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(LPTMR_INSTANCE_COUNT > instance);
#endif
    /* check if interrupt is enabled */
    boolean IsInterruptEnabled = Lptmr_Gpt_Ip_GetInterruptEnableFlag(instance);
    
    if (FALSE == IsInterruptEnabled)
    {
        /* Clear interrupt flag */
        Lptmr_Gpt_Ip_ClearInterruptStatusFlag(instance);

        /* Enable LPTMR interrupt */
        Lptmr_Gpt_Ip_SetInterruptEnableFlag(instance, TRUE);
    }
}

/*================================================================================================*/
/**
*
* @brief         LPTMR driver function for Disable Interrupt for LPTMR channel
* @details       This function:
*                        - Disable Interrupt for LPTMR channel
* @param[in]     instance        LPTMR hw instance
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Lptmr_Gpt_Ip_DisableInterrupt_Activity
*/
void Lptmr_Gpt_Ip_DisableInterrupt(uint8 instance)
{
#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(LPTMR_INSTANCE_COUNT > instance);
#endif
    /* Disable LPTMR interrupt */
    Lptmr_Gpt_Ip_SetInterruptEnableFlag(instance, FALSE);
    /* Clear interrupt flag */
    Lptmr_Gpt_Ip_ClearInterruptStatusFlag(instance);

}

#if (LPTMR_GPT_IP_SET_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief        The function changes the LPtimer prescaler value.
* @details      This function sets the LPtimer prescaler based on the input mode.
*
* @param[in]    instance     Lptmr hardware instance
* @param[in]    clockMode    LPTMR_GPT_IP_CLOCKMODE_NORMAL or LPTMR_GPT_IP_CLOCKMODE_ALTERNATE
*
* @return       void
* @pre          The driver needs to be initialized.On/Off by the configuration parameter: GPT_DUAL_CLOCK_MODE
* @implements   Lptmr_Gpt_Ip_SetClockMode_Activity
*/
void Lptmr_Gpt_Ip_SetClockMode(uint8 instance, Lptmr_Gpt_Ip_ClockModeType clockMode)
{
#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
DevAssert(LPTMR_INSTANCE_COUNT > instance);
#endif

    /* Set Prescaler */
    if(LPTMR_GPT_IP_CLOCKMODE_NORMAL == clockMode)
    {
        Lptmr_Gpt_Ip_SetPrescaler(instance, Lptmr_Gpt_Ip_u32InstanceState[instance].clockPrescaler);
    }
    else
    {
        Lptmr_Gpt_Ip_SetPrescaler(instance, Lptmr_Gpt_Ip_u32InstanceState[instance].clockAlternatePrescaler);
    }

}
#endif/*LPTMR_GPT_IP_SET_CLOCK_MODE*/

#ifdef LPTMR_0_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief          Interrupt handler for RTC channel
* @details        Interrupt Service Routine corresponding to Gpt_RTC_Ch_0 hw channel.
* @param[in]      none
* @return         void
* @isr
* @pre            The driver needs to be initialized.
*/
ISR(LPTMR_0_CH_0_ISR)
{
    Lptmr_Gpt_Ip_ProcessCommonInterrupt(0U);
    EXIT_INTERRUPT();
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* LPTMR_GPT_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif /*LPTMR_GPT_IP_C*/

/** @} */
