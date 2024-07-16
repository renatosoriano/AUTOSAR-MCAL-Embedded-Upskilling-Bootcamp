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
*   @file       Gpt_Ipw.c
*
*   @internal
*   @addtogroup gpt gpt_ipw
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
#include "Gpt_Ipw.h"
#include "Std_Types.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_IPW_VENDOR_ID_C                    43
#define GPT_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define GPT_IPW_AR_RELEASE_MINOR_VERSION_C     7
#define GPT_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define GPT_IPW_SW_MAJOR_VERSION_C             2
#define GPT_IPW_SW_MINOR_VERSION_C             0
#define GPT_IPW_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_IPW_VENDOR_ID_C != GPT_IPW_VENDOR_ID)
    #error "Gpt_Ipw.c and Gpt_Ipw.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw.c and Gpt_Ipw.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_C != GPT_IPW_SW_MAJOR_VERSION) || \
     (GPT_IPW_SW_MINOR_VERSION_C != GPT_IPW_SW_MINOR_VERSION) || \
     (GPT_IPW_SW_PATCH_VERSION_C != GPT_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Ipw.c and Gpt_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw.c and Std_Types.h are different"
    #endif

    #if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcal.h and Gpt_Ipw.c are different"
    #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#if (FTM_GPT_IP_USED == STD_ON)
    #define FTM_CNT_MAX_VALUE_U32        ((uint32)0xFFFFuL)
    #define FTM_OVERFLOW_PAD_U32         ((uint32)1U)
#endif

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (FTM_GPT_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_FtmGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo);
#endif
#if (SRTC_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_SrtcGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo);
#endif
#if (LPTMR_GPT_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_LptmrGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo);
#endif
#if (LPIT_GPT_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_LpitGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo);
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if (FTM_GPT_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_FtmGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
    Gpt_ValueType returnValue;
    boolean HasChEvOccurred;

    /* Read compare and counter registers */
    uint32 counterValue = Ftm_Gpt_Ip_GetCntValue(pHwChannelConfig->instance);
    uint32 compareValue = Ftm_Gpt_Ip_GetCompareValue(pHwChannelConfig->instance, pHwChannelConfig->channel);

    pReturnHwChannelInfo->uTargetTime = Ftm_Gpt_Ip_u32TargetValue[pHwChannelConfig->instance][pHwChannelConfig->channel];

    /* Calculate the elapsed time */
    if (counterValue > compareValue)
    {
        /* Counter value passed the set-up Target value - might have roll-over */
        if(((FTM_CNT_MAX_VALUE_U32 - counterValue) + compareValue) <= pReturnHwChannelInfo->uTargetTime)
        {
            /* New compare value was read by register read - isr served in time - we have roll-over */
            returnValue =   (Gpt_ValueType)(    (   pReturnHwChannelInfo->uTargetTime - \
                                                    ((FTM_CNT_MAX_VALUE_U32 - counterValue) + compareValue) ) + \
                                                FTM_OVERFLOW_PAD_U32 );
        }
        else
        {
            /* There is an delay in serving ISR or updating u32CompareValue - report last timer time */
            returnValue = (Gpt_ValueType)(pReturnHwChannelInfo->uTargetTime);
        }
    }
    else
    {
        /* Timer in between ISRs period */
        returnValue = (Gpt_ValueType)(pReturnHwChannelInfo->uTargetTime - (compareValue - counterValue));
    }

    /* check if channel event has occurred */
    HasChEvOccurred = Ftm_Gpt_Ip_GetChInterruptStatusFlag(pHwChannelConfig->instance, pHwChannelConfig->channel);

    /*Check interrupt status flag*/
    if (HasChEvOccurred)
    {
        /* Channel counter was roll-over */
        pReturnHwChannelInfo->bChannelRollover = TRUE;
    }
    else
    {
        /* Channel counter was not rollover */
        pReturnHwChannelInfo->bChannelRollover = FALSE;
    }
    return returnValue;
}
#endif

#if (SRTC_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_SrtcGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig,
                                                      Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
    uint32 returnValue = 0U;
    uint32 tempValue = 0U;
    
    /* Read Time Seconds Register and Time Alarm Register. Time Alarm was minus one at initial */
    uint32 counterValue = Srtc_Ip_GetTimeSecondsRegister(pHwChannelConfig->instance);
    uint32 compareValue = Srtc_Ip_GetTimeAlarmRegister(pHwChannelConfig->instance) + 1U;
    
    
    /* Check interrupt status flag */
    boolean alarmInterruptStatusFlag = Srtc_Ip_GetInterruptStatusFlag(pHwChannelConfig->instance, SRTC_IP_ALARM_INTERRUPT);
    if (alarmInterruptStatusFlag)
    {
        /* Channel counter was roll-over */
        pReturnHwChannelInfo->bChannelRollover = TRUE;
    }
    else
    {
        /* Channel counter was not rollover */
        pReturnHwChannelInfo->bChannelRollover = FALSE;
    }
    
    pReturnHwChannelInfo->uTargetTime = Srtc_Ip_u32TargetValue;
    /* Calculate the elapsed time */
    if (counterValue > compareValue)
    {
        tempValue = (MAX_32BIT - counterValue) + compareValue + 1U;
    }
    else
    {
        tempValue = compareValue - counterValue;
    }
    if (tempValue > Srtc_Ip_u32TargetValue)
    {
        returnValue = Srtc_Ip_u32TargetValue;
    }
    else
    {
        returnValue = Srtc_Ip_u32TargetValue - tempValue;
    }

    return (Gpt_ValueType)returnValue;
}
#endif

#if (LPTMR_GPT_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_LptmrGetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig,
                                                      Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
    uint32 returnValue = 0U;

    /* Read the LPTMR channel load register */
    pReturnHwChannelInfo->uTargetTime = Lptmr_Gpt_Ip_GetCompareValue(pHwChannelConfig->instance);
    /* The Counter Register returns the current value of the LPTMR at the time this register was last written. */
    Lptmr_Gpt_Ip_WriteCounterValue(pHwChannelConfig->instance, 0U);

    /* Read the LPTMR counter register*/
    returnValue = Lptmr_Gpt_Ip_GetCntValue(pHwChannelConfig->instance);

    /* check if interrupt has occurred */
    boolean HasInterruptOccurred = Lptmr_Gpt_Ip_GetInterruptStatusFlag(pHwChannelConfig->instance);
    if (TRUE == HasInterruptOccurred)
    {
        /* Channel counter was roll-over */
        pReturnHwChannelInfo->bChannelRollover = TRUE;
    }
    else
    {
        /* Channel counter was not roll-over */
        pReturnHwChannelInfo->bChannelRollover = FALSE;
    }
    return (Gpt_ValueType)returnValue;
}
#endif

#if (LPIT_GPT_IP_USED == STD_ON)
static Gpt_ValueType Gpt_Ipw_LpitGetTimeElapsed( const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig,
                                                        Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
    uint32 returnValue = 0U;

    /* Check interrupt status flag */
    boolean HasChEvOccurred = Lpit_Gpt_Ip_GetChannelInterruptFlagStatus(pHwChannelConfig->instance, pHwChannelConfig->channel);

#if(LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
    pReturnHwChannelInfo->uTargetTime = Lpit_Gpt_Ip_u32OldTargetValue;
#endif
    pReturnHwChannelInfo->uTargetTime = Lpit_Gpt_Ip_GetTimerValue(pHwChannelConfig->instance,pHwChannelConfig->channel);
    returnValue = (uint32)(pReturnHwChannelInfo->uTargetTime) - Lpit_Gpt_Ip_GetCurrentTimerValue(pHwChannelConfig->instance, pHwChannelConfig->channel);

    if (HasChEvOccurred)
    {
        /* Channel counter was roll-over */
        pReturnHwChannelInfo->bChannelRollover = TRUE;
    }
    else
    {
        /* Channel counter was not roll-over */
        pReturnHwChannelInfo->bChannelRollover = FALSE;
    }
    return (Gpt_ValueType)returnValue;
}
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/**
* @brief        Gpt driver Autosar independent and IP dependent initialization function.
* @details      This Gpt_Ipw_InitInstances is called once for each channel in the used configuration.
*               It determines the type of the HW channel and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    configPtr    Pointer to the channel configuration structure dependent by platform
*
* @return       void
* @pre          The driver needs to be initialized.
*/
void Gpt_Ipw_InitInstances(const Gpt_ConfigType * configPtr)
{

    uint8 index = 0U;

    for(index = 0; index < configPtr->instanceCount; index++)
    {
        switch((*(configPtr->Gpt_Ipw_HwInstanceConfig))[index].instanceType)
        {
#if (FTM_GPT_IP_USED == STD_ON)
            case(GPT_FTM_MODULE):
            {
                Ftm_Gpt_Ip_Init((*(configPtr->Gpt_Ipw_HwInstanceConfig))[index].instance,
                                (*(configPtr->Gpt_Ipw_HwInstanceConfig))[index].Gpt_Ipw_InstanceConfig.Ftm_Gpt_Ip_InstanceConfig);
            }
            break;
#endif

#if (SRTC_IP_USED == STD_ON)
            case(GPT_SRTC_MODULE):
            {
                /*Srtc is empty because it shall not be executed for InitInstances */
            }
            break;
#endif

#if (LPTMR_GPT_IP_USED == STD_ON)
            case(GPT_LPTMR_MODULE):
            {
                /*LPtimer is empty because it shall not be executed for InitInstances */
            }
            break;
#endif

#if (LPIT_GPT_IP_USED == STD_ON)
            case(GPT_LPIT_MODULE):
            {
                Lpit_Gpt_Ip_Init((*(configPtr->Gpt_Ipw_HwInstanceConfig))[index].instance,
                                 (*(configPtr->Gpt_Ipw_HwInstanceConfig))[index].Gpt_Ipw_InstanceConfig.Lpit_Gpt_Ip_InstanceConfig);
            }
            break;
#endif

            default:
                /*This switch branch is empty because it shall not be executed for normal behaviour*/
            break;
        }
    }
    return;
}

/**
* @brief        Gpt driver Autosar independent and IP dependent initialization function.
* @details      This function Gpt_Ipw_Init is called once for each channel in the used configuration.
*               It determines the type of the HW channel and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return       void
* @pre          The driver needs to be initialized.
*/
void Gpt_Ipw_Init(const Gpt_Ipw_HwChannelConfigType *pHwChannelConfig)
{

    switch(pHwChannelConfig->instanceType)
    {
#if (FTM_GPT_IP_USED == STD_ON)
        case(GPT_FTM_MODULE):
        {
            Ftm_Gpt_Ip_InitChannel(pHwChannelConfig->instance,
                                   pHwChannelConfig->Gpt_Ipw_ChannelConfig.Ftm_Gpt_Ip_ChannelConfig);
        }
        break;
#endif

#if (SRTC_IP_USED == STD_ON)
        case(GPT_SRTC_MODULE):
        {
            Srtc_Ip_Init(pHwChannelConfig->instance,
                         pHwChannelConfig->Gpt_Ipw_ChannelConfig.Srtc_Ip_ChannelConfig);
        }
        break;
#endif

#if (LPTMR_GPT_IP_USED == STD_ON)
        case(GPT_LPTMR_MODULE):
        {
            Lptmr_Gpt_Ip_Init(pHwChannelConfig->instance,
                              pHwChannelConfig->Gpt_Ipw_ChannelConfig.Lptmr_Gpt_Ip_ChannelConfig);
        }
        break;
#endif

#if (LPIT_GPT_IP_USED == STD_ON)
        case(GPT_LPIT_MODULE):
        {
             Lpit_Gpt_Ip_InitChannel(pHwChannelConfig->instance,
                                     pHwChannelConfig->Gpt_Ipw_ChannelConfig.Lpit_Gpt_Ip_ChannelConfig);
        }
            break;
#endif
        default:
            /* This switch branch is empty because it shall not be executed for normal behaviour */
        break;
    }
    return;
}
/*================================================================================================*/
/**
* @brief         Gpt driver Autosar independent and platform dependent function for starting the timer channel.
* @details       It checks the type of the HW module and calls the appropriate
*                IP function for starting the timer channel.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     uValue              Timeout period (in ticks) after which a notification shall occur (if enabled).
* @return        void
* @pre           The driver needs to be initialized.Call Gpt_StartTimer before.
*/
Std_ReturnType Gpt_Ipw_StartTimer(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig, Gpt_ValueType uValue)
{

    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    switch(pHwChannelConfig->instanceType)
    {
#if (FTM_GPT_IP_USED == STD_ON)
        case(GPT_FTM_MODULE):
            {
                Ftm_Gpt_Ip_StartCounting(pHwChannelConfig->instance,
                                         pHwChannelConfig->channel,
                                         (uint16)uValue);
                returnValue = (Std_ReturnType)E_OK;
            }
        break;
#endif
#if (SRTC_IP_USED == STD_ON)
        case(GPT_SRTC_MODULE):
            {
                Srtc_Ip_StartTimer(pHwChannelConfig->instance,
                                   uValue);
                returnValue = (Std_ReturnType)E_OK;
            }
        break;
#endif

#if (LPTMR_GPT_IP_USED == STD_ON)
        case(GPT_LPTMR_MODULE):
            {
                Lptmr_Gpt_Ip_StartTimer(pHwChannelConfig->instance,
                                        (uint16)uValue);
                returnValue = (Std_ReturnType)E_OK;
            }
        break;
#endif

#if (LPIT_GPT_IP_USED == STD_ON)
            case(GPT_LPIT_MODULE):
            {
                Lpit_Gpt_Ip_StartTimer(pHwChannelConfig->instance,
                                       pHwChannelConfig->channel,
                                         uValue);
                returnValue = (Std_ReturnType)E_OK;
            }
            break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour */
        break;
    }

    return returnValue;
}

/*================================================================================================*/
/**
* @brief         Gpt driver Autosar independent and IP dependent function for fetching the elapsed timer value.
* @details       It determines the type of the HW channel and calls the
*                appropriate IP function for reading the elapsed timer value from the HW.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     uTargetTime         Target time value
* @param[out]    pbReturnChannelOverflow  Rollover status flag value of the hardware timer channel
* @return        returnValue         The elapsed time
* @pre           The driver needs to be initialized.Call GetTimeElapsed before.
*
*/
Gpt_ValueType Gpt_Ipw_GetTimeElapsed(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig,
                                                      Gpt_HwChannelInfoType * pReturnHwChannelInfo)
{
    uint32 returnValue;

    switch(pHwChannelConfig->instanceType)
    {
#if (FTM_GPT_IP_USED == STD_ON)
        case(GPT_FTM_MODULE):
        {
            returnValue = Gpt_Ipw_FtmGetTimeElapsed(pHwChannelConfig, pReturnHwChannelInfo);
        }
        break;
#endif

#if (SRTC_IP_USED == STD_ON)
        case(GPT_SRTC_MODULE):
        {
            returnValue = Gpt_Ipw_SrtcGetTimeElapsed(pHwChannelConfig, pReturnHwChannelInfo);
        }
        break;
#endif
#if (LPTMR_GPT_IP_USED == STD_ON)
        case(GPT_LPTMR_MODULE):
        {
            returnValue = Gpt_Ipw_LptmrGetTimeElapsed(pHwChannelConfig, pReturnHwChannelInfo);
        }
        break;
#endif

#if (LPIT_GPT_IP_USED == STD_ON)
        case(GPT_LPIT_MODULE):
        {
            returnValue = Gpt_Ipw_LpitGetTimeElapsed(pHwChannelConfig, pReturnHwChannelInfo);
        }
        break;
#endif

        default:
             /* This switch branch is empty because it shall not be executed for normal behaviour */
             returnValue = 0U;
        break;
    }
    return (Gpt_ValueType)returnValue;
}

/*================================================================================================*/
/**
* @brief         Gpt driver Autosar independent and platform dependent function for stopping the timer channel.
* @details       It checks the type of the HW module and calls the appropriate
*                IP function for stopping the timer channel.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized.Call StopTimer before.
*/
void Gpt_Ipw_StopTimer(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    switch(pHwChannelConfig->instanceType)
    {
#if (FTM_GPT_IP_USED == STD_ON)
        case(GPT_FTM_MODULE):
        {

            Ftm_Gpt_Ip_DisableChannelInterrupt(pHwChannelConfig->instance,
                                               pHwChannelConfig->channel);
        }
        break;
#endif
#if (SRTC_IP_USED == STD_ON)
        case(GPT_SRTC_MODULE):
        {
            /* Stop counter */
            (void)Srtc_Ip_StopCounter(pHwChannelConfig->instance);
        }
        break;
#endif
#if (LPTMR_GPT_IP_USED == STD_ON)
        case(GPT_LPTMR_MODULE):
        {
            Lptmr_Gpt_Ip_StopTimer(pHwChannelConfig->instance);
        }
        break;
#endif
#if (LPIT_GPT_IP_USED == STD_ON)
        case(GPT_LPIT_MODULE):
        {
            Lpit_Gpt_Ip_StopTimer(pHwChannelConfig->instance,
                                   pHwChannelConfig->channel);
        }
            break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return;
}

/*================================================================================================*/
/**
* @brief         Gpt driver Autosar independent and platform dependent function for enabling hardware timer interrupts.
* @details       It checks the type of the HW module and calls the appropriate
*                IP function for enabling hardware timer interrupts.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized.
*/
void Gpt_Ipw_EnableInterrupt(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    switch(pHwChannelConfig->instanceType)
    {
#if (FTM_GPT_IP_USED == STD_ON)
        case(GPT_FTM_MODULE):
        {
            /* For a FTM enabled channel the interrupts are always activated */
        }
        break;
#endif
#if (SRTC_IP_USED == STD_ON)
        case(GPT_SRTC_MODULE):
        {
            Srtc_Ip_EnableInterrupt(pHwChannelConfig->instance, SRTC_IP_ALARM_INTERRUPT);
        }
        break;
#endif
#if (LPTMR_GPT_IP_USED == STD_ON)
        case(GPT_LPTMR_MODULE):
        {
            Lptmr_Gpt_Ip_EnableInterrupt(pHwChannelConfig->instance);
        }
        break;
#endif
#if (LPIT_GPT_IP_USED == STD_ON)
        case(GPT_LPIT_MODULE):
        {
            Lpit_Gpt_Ip_EnableChInterrupt(pHwChannelConfig->instance, pHwChannelConfig->channel);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return;
}

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief         Gpt driver Autosar independent and IP dependent de-initialization function.
* @details       This function is called for each  channel from the current configuration.
*                It determines the type of the HW channel and calls the
*                appropriate IP function in order to de-initializes the hardware timer.
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized. On/Off by the configuration parameter: GPT_DEINIT_API
*/
void Gpt_Ipw_DeInit(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    switch(pHwChannelConfig->instanceType)
    {
#if (FTM_GPT_IP_USED == STD_ON)
        case(GPT_FTM_MODULE):
        {
           Ftm_Gpt_Ip_Deinit(pHwChannelConfig->instance);
        }
        break;
#endif
#if (SRTC_IP_USED == STD_ON)
        case(GPT_SRTC_MODULE):
        {
            Srtc_Ip_DeInit(pHwChannelConfig->instance);
        }
        break;
#endif
#if (LPTMR_GPT_IP_USED == STD_ON)
        case(GPT_LPTMR_MODULE):
        {
            Lptmr_Gpt_Ip_DeInit(pHwChannelConfig->instance);
        }
        break;
#endif
#if (LPIT_GPT_IP_USED == STD_ON)
        case(GPT_LPIT_MODULE):
        {
            Lpit_Gpt_Ip_Deinit(pHwChannelConfig->instance);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }
    return;
}

#endif
/*================================================================================================*/
#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
* @brief         Gpt driver Autosar independent and platform dependent function for disabling hardware timer interrupts.
* @details       It checks the type of the HW module and calls the appropriate
*                IP function for disabling hardware timer interrupts.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return        void
* @pre           The driver needs to be initialized.On/Off by the configuration parameter: GPT_ENABLE_DISABLE_NOTIFICATION_API
*/
void Gpt_Ipw_DisableInterrupt(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    switch(pHwChannelConfig->instanceType)
    {
#if (FTM_GPT_IP_USED == STD_ON)
        case(GPT_FTM_MODULE):
        {
            /* For a FTM enabled channel the interrupts are always activated */
        }
        break;
#endif
#if (SRTC_IP_USED == STD_ON)
        case(GPT_SRTC_MODULE):
        {
            Srtc_Ip_DisableInterrupt(pHwChannelConfig->instance, SRTC_IP_ALARM_INTERRUPT);
        }
        break;
#endif
#if (LPTMR_GPT_IP_USED == STD_ON)
        case(GPT_LPTMR_MODULE):
        {
            Lptmr_Gpt_Ip_DisableInterrupt(pHwChannelConfig->instance);
        }
        break;
#endif
#if (LPIT_GPT_IP_USED == STD_ON)
        case(GPT_LPIT_MODULE):
        {
            Lpit_Gpt_Ip_DisableChInterrupt(pHwChannelConfig->instance, pHwChannelConfig->channel);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return;
}
#endif
/*================================================================================================*/

#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief        Gpt driver Autosar independent and IP dependent function to change compare register value.
* @details      This function:
*                - Write next timeout to local variable
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent
*                                       by platform
* @param[in]     value               New Timeout period (in ticks) after which a notification
*                                       shall occur (if enabled).
* @return        void
* @pre           The driver needs to be initialized.On/Off by the configuration parameter: GPT_CHANGE_NEXT_TIMEOUT_VALUE
*
*/

Std_ReturnType Gpt_Ipw_ChangeNextTimeoutValue(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig,
                                                               Gpt_ValueType value)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    switch(pHwChannelConfig->instanceType)
    {
#if (FTM_GPT_IP_USED == STD_ON)
        case (GPT_FTM_MODULE):
        {
             Ftm_Gpt_Ip_ChangeNextTimeoutValue( pHwChannelConfig->instance,
                                                pHwChannelConfig->channel, (uint16)value);
             returnValue =(Std_ReturnType)E_OK;

        }
        break;
#endif
#if (LPIT_GPT_IP_USED == STD_ON)
        case (GPT_LPIT_MODULE):
        {
             Lpit_Gpt_Ip_ChangeNextTimeoutValue( pHwChannelConfig->instance,
                                                pHwChannelConfig->channel, value);
             returnValue =(Std_ReturnType)E_OK;

        }
        break;
#endif
#if (SRTC_IP_USED == STD_ON)
        case (GPT_SRTC_MODULE):
        {
             (void)value;
        }
        break;
#endif
#if (LPTMR_GPT_IP_USED == STD_ON)
        case (GPT_LPTMR_MODULE):
        {
             (void)value;
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour */
        break;
    }

    return returnValue;
}
#endif /* GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */
/*================================================================================================*/
/**
* @brief         Gpt driver Autosar independent and IP dependent function to change eMios compare register value.
* @details       Calls the eMios function to change the eMios compare register value at the next match.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     clkMode             Clock mode for configuration channel
*
* @return        void
* @pre           The driver needs to be initialized.On/Off by the configuration parameter: GPT_SET_CLOCK_MODE
*/
#if (GPT_SET_CLOCK_MODE == STD_ON)
void Gpt_Ipw_SetClockModeInStance(const Gpt_Ipw_HwInstanceConfigType * pHwInstanceConfig,
                                            Gpt_ClockModeType clkMode)
{
    switch(pHwInstanceConfig->instanceType)
    {
#if (FTM_GPT_IP_USED == STD_ON)
        case (GPT_FTM_MODULE):
        {
            if(GPT_CLOCKMODE_NORMAL == clkMode)
            {
                Ftm_Gpt_Ip_SetClockMode(pHwInstanceConfig->instance, FTM_GPT_IP_CLOCKMODE_NORMAL);
            }
            else
            {
                Ftm_Gpt_Ip_SetClockMode(pHwInstanceConfig->instance, FTM_GPT_IP_CLOCKMODE_ALTERNATE);
            }
        }
        break;
#endif

#if (LPTMR_GPT_IP_USED == STD_ON)
        case (GPT_LPTMR_MODULE):
        {
            if(GPT_CLOCKMODE_NORMAL == clkMode)
            {
                Lptmr_Gpt_Ip_SetClockMode(pHwInstanceConfig->instance, LPTMR_GPT_IP_CLOCKMODE_NORMAL);
            }
            else
            {
                Lptmr_Gpt_Ip_SetClockMode(pHwInstanceConfig->instance, LPTMR_GPT_IP_CLOCKMODE_ALTERNATE);
            }
        }
        break;
#endif
#if (LPIT_GPT_IP_USED == STD_ON)
        case (GPT_LPIT_MODULE):
        {
             (void)clkMode;
        }
        break;
#endif
#if (SRTC_IP_USED == STD_ON)
        case (GPT_SRTC_MODULE):
        {
             (void)clkMode;
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }
}
#endif /* GPT_SET_CLOCK_MODE == STD_ON */
/*================================================================================================*/
#if(GPT_CHAIN_MODE == STD_ON)
/**
* @brief         The function Gpt_Ipw_EnableChainMode.
* @details       This function:
*               - Chain the timer.
*
* @param[in]     pHwChannelConfig        Pointer to the channel configuration structure dependent by platform
* @return        returnValue
* @pre           The driver needs to be initialized. CHAIN_MODE == STD_ON
*/
Std_ReturnType Gpt_Ipw_EnableChainMode(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    switch(pHwChannelConfig->instanceType)
    {
#if (LPIT_GPT_IP_USED == STD_ON)
        case (GPT_LPIT_MODULE):
        {
            returnValue = (Std_ReturnType)Lpit_Gpt_Ip_ChainMode(pHwChannelConfig->instance, pHwChannelConfig->channel, TRUE);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return returnValue;
}
#endif /*(GPT_CHAIN_MODE == STD_ON)*/
/*================================================================================================*/
#if(GPT_CHAIN_MODE == STD_ON)
/**
* @brief         The function Gpt_Ipw_DisableChainMode.
* @details       This function:
*               - Chain the timer.
*
* @param[in]     pHwChannelConfig        Pointer to the channel configuration structure dependent by platform
* @return        returnValue
* @pre           The driver needs to be initialized. CHAIN_MODE == STD_ON
*/
Std_ReturnType Gpt_Ipw_DisableChainMode(const Gpt_Ipw_HwChannelConfigType * pHwChannelConfig)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    switch(pHwChannelConfig->instanceType)
    {
#if (LPIT_GPT_IP_USED == STD_ON)
        case (GPT_LPIT_MODULE):
        {
            returnValue = (Std_ReturnType)Lpit_Gpt_Ip_ChainMode(pHwChannelConfig->instance, pHwChannelConfig->channel, FALSE);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }
    return returnValue;
}
#endif /*(GPT_CHAIN_MODE == STD_ON)*/
/*================================================================================================*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief        Gpt driver Autosar start predeftimer hw.
* @details      This function to start channel, which using predeftimer feature in the used configuration.
*               It determines the type of the HW channel and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return       void
* @pre          The driver needs to be initialized. On/Off GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON
*/

void Gpt_Ipw_StartPredefTimer
(
    const Gpt_ConfigType * configPtr
)
{
    Gpt_ChannelType channel;
    const Gpt_HwPredefChannelConfigType * pHwChannelConfig;

    for(channel = 0U; channel < GPT_HW_PREDEFTIMER_NUM; channel++)
    {
        pHwChannelConfig = (configPtr->Gpt_pChannelPredefConfigType)[channel];

        if(NULL_PTR != pHwChannelConfig)
        {
            switch(pHwChannelConfig->instanceType)
            {
#if (FTM_GPT_IP_USED == STD_ON)
            case GPT_FTM_MODULE:
            {
                Ftm_Gpt_Ip_StartPredefTimer(pHwChannelConfig->instance, \
                                            pHwChannelConfig->channel, \
                                            pHwChannelConfig->Gpt_uPrescaler, \
                                            pHwChannelConfig->Gpt_uClockSource, \
                                            pHwChannelConfig->Gpt_bFreezeEnable);
            }
            break;
#endif
            default:
                /*This switch branch is empty because it shall not be executed for normal behaviour*/
            break;
            }
        }
    }

    return;
}

/**
* @brief        Gpt driver Autosar get value of predeftimer hw.
* @details      This function to start channel, which using predeftimer feature in the used configuration.
*               It determines the type of the HW channel and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]    TimeValuePtr        The pointer using for save current value of hardware channel
* @param[in]    PredefTimer         Gpt_PredefTimerType
* @return       void
* @pre          The driver needs to be initialized. On/Off GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON
*/
void Gpt_Ipw_GetPredefTimerValue
(
    const Gpt_HwPredefChannelConfigType * pHwChannelConfig,
    Gpt_PredefTimerType PredefTimer,
    uint32 * TimeValuePtr
)
{
    uint32 u32ReturnValue = 0U;
    switch(pHwChannelConfig->instanceType)
    {
#if (FTM_GPT_IP_USED == STD_ON)
        case GPT_FTM_MODULE:
        {
            u32ReturnValue = Ftm_Gpt_Ip_GetCntValue(pHwChannelConfig->instance);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }
    if(0U != u32ReturnValue)
    {
        switch(PredefTimer)
        {
            case GPT_PREDEF_TIMER_1US_16BIT:
                *TimeValuePtr = (0x0000FFFFU & u32ReturnValue);
            break;
            case GPT_PREDEF_TIMER_1US_24BIT:
                *TimeValuePtr = (0x00FFFFFFU & u32ReturnValue);
            break;
            case GPT_PREDEF_TIMER_1US_32BIT:
                *TimeValuePtr = u32ReturnValue;
            break;
            case GPT_PREDEF_TIMER_100US_32BIT:
                *TimeValuePtr = u32ReturnValue;
            break;
            default:
                /* 32bit timer */
            break;
        }
    }
    return;
}

/**
* @brief        Gpt driver Autosar stop predeftimer hw.
* @details      This function to start channel, which using predeftimer feature in the used configuration.
*               It determines the type of the HW channel and calls the
*               appropriate IP function in order to initializes the hardware timer.
* @param[in]    pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @return       void
* @pre          The driver needs to be initialized. GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON
*/
void Gpt_Ipw_StopPredefTimer
(
    const Gpt_ConfigType * configPtr
)
{
    Gpt_ChannelType channel;
    const Gpt_HwPredefChannelConfigType * pHwChannelConfig;

    for(channel = 0U; channel < GPT_HW_PREDEFTIMER_NUM; channel++)
    {

        pHwChannelConfig = (configPtr->Gpt_pChannelPredefConfigType)[channel];
        if(NULL_PTR != pHwChannelConfig)
        {
            switch(pHwChannelConfig->instanceType)
            {
#if (FTM_GPT_IP_USED == STD_ON)
            case GPT_FTM_MODULE:
            {
                Ftm_Gpt_Ip_StopPredefTimer(pHwChannelConfig->instance, \
                                           pHwChannelConfig->channel);
            }
            break;
#endif
            default:
                /*This switch branch is empty because it shall not be executed for normal behaviour*/
            break;
            }
        }
    }
    return;
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
/** @} */
#endif/*GPT_IPW_C*/


