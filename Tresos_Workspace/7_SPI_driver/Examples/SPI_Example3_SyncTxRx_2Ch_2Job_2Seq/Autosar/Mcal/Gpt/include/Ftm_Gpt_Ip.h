/*==================================================================================================
* Project :             RTD AUTOSAR 4.7
* Platform :            CORTEXM
* Peripheral :          Ftm_Srtc_Lptmr_LPit
* Dependencies :        none
*
* Autosar Version :     4.7.0
* Autosar Revision :    ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version :          2.0.0
* Build Version :       S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
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

#ifndef FTM_GPT_IP_H
#define FTM_GPT_IP_H

/**
*   @file       Ftm_Gpt_Ip.h
*
*   @addtogroup ftm_ip FTM IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftm_Gpt_Ip_Types.h"
#include "Ftm_Gpt_Ip_Cfg.h"
#include "OsIf.h"
#include "Mcal.h"
#include "SchM_Gpt.h"
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
#include "Devassert.h"
#endif
#if (STD_ON == FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT)
#include "Reg_eSys.h"
#endif
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @internal
* @brief Defines used for file version checks
*/
#define FTM_GPT_IP_VENDOR_ID                       43
#define FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION        4
#define FTM_GPT_IP_AR_RELEASE_MINOR_VERSION        7
#define FTM_GPT_IP_AR_RELEASE_REVISION_VERSION     0
#define FTM_GPT_IP_SW_MAJOR_VERSION                2
#define FTM_GPT_IP_SW_MINOR_VERSION                0
#define FTM_GPT_IP_SW_PATCH_VERSION                0


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (FTM_GPT_IP_VENDOR_ID != FTM_GPT_IP_TYPES_VENDOR_ID)
#error "Ftm_Gpt_Ip.h and Ftm_Gpt_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION != FTM_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
(FTM_GPT_IP_AR_RELEASE_MINOR_VERSION != FTM_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
(FTM_GPT_IP_AR_RELEASE_REVISION_VERSION != FTM_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Numbers of Ftm_Gpt_Ip.h and Ftm_Gpt_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((FTM_GPT_IP_SW_MAJOR_VERSION != FTM_GPT_IP_TYPES_SW_MAJOR_VERSION) || \
(FTM_GPT_IP_SW_MINOR_VERSION != FTM_GPT_IP_TYPES_SW_MINOR_VERSION) || \
(FTM_GPT_IP_SW_PATCH_VERSION != FTM_GPT_IP_TYPES_SW_PATCH_VERSION) \
)
#error "Software Version Numbers of Ftm_Gpt_Ip.h and Ftm_Gpt_Ip_Types.h are different"
#endif


#if (FTM_GPT_IP_VENDOR_ID != FTM_GPT_IP_VENDOR_ID_CFG)
#error "Ftm_Gpt_Ip.h and Ftm_Gpt_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Ftm_Gpt_Ip header file and Ftm_Gpt_Ip_Cfg header file are of the same Autosar version */
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION != FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
(FTM_GPT_IP_AR_RELEASE_MINOR_VERSION != FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
(FTM_GPT_IP_AR_RELEASE_REVISION_VERSION != FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG) \
)
#error "AutoSar Version Numbers of Ftm_Gpt_Ip.h and Ftm_Gpt_Ip_Cfg.h are different"
#endif
/* Check if Ftm_Gpt_Ip file and Ftm_Gpt_Ip_Cfg header file are of the same Software version */
#if ((FTM_GPT_IP_SW_MAJOR_VERSION != FTM_GPT_IP_SW_MAJOR_VERSION_CFG) || \
(FTM_GPT_IP_SW_MINOR_VERSION != FTM_GPT_IP_SW_MINOR_VERSION_CFG) || \
(FTM_GPT_IP_SW_PATCH_VERSION != FTM_GPT_IP_SW_PATCH_VERSION_CFG) \
)
#error "Software Version Numbers of Ftm_Gpt_Ip.h and Ftm_Gpt_Ip_Cfg.h are different"
#endif


#if (STD_ON == FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT)
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
(FTM_GPT_IP_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Ftm_Gpt_Ip.h and Reg_eSys.h are different"
#endif
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_AR_RELEASE_MAJOR_VERSION) || \
(FTM_GPT_IP_AR_RELEASE_MINOR_VERSION != SCHM_GPT_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Ftm_Gpt_Ip.h and SchM_Gpt.h are different"
#endif
/* Check if this header file and OsIf.h file are of the same Autosar version */
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
(FTM_GPT_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Ftm_Gpt_Ip.h and OsIf.h are different"
#endif

/* Check if source file and Std_Types.h header file are of the same Autosar version */
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_GPT_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip.h and Mcal.h  are different"
#endif
#endif

/* Checks against Devassert.h */
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
(FTM_GPT_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Ftm_Gpt_Ip.h and Devassert.h are different"
#endif
#endif
#endif /* STD_ON == FTM_GPT_IP_DEV_ERROR_DETECT */
/*==================================================================================================
*                                           CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/
#if (FTM_GPT_IP_USED == STD_ON)

/**
* @internal
* @brief The total FTM timer channel
*/
#define FTM_CHANNEL_COUNT   FTM_CONTROLS_COUNT

/**
* @internal
* @brief Counter max value
*/
#define FTM_CNT_MAX_VALUE   0x0000FFFFU

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Table of base addresses for FTM instances. */
extern FTM_Type * const ftmGptBase[FTM_INSTANCE_COUNT];
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

/**
* @internal
* @brief Global array variable used to store the runtime target time value.
*/
extern uint32 Ftm_Gpt_Ip_u32TargetValue[FTM_INSTANCE_COUNT][FTM_CONTROLS_COUNT];

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/*================================================================================================*/
/**
 * @brief
 * Function Name : Ftm_Gpt_Ip_GetChInterruptStatusFlag
 * Description   : Get the status of CHF bit from CSC - Channel (n) Status and Control Register (C0SC - C7SC)
 *
 * @details Channel (n) Flag (CHF)
 *          Set by hardware when an event occurs on the channel (n). CHF is cleared by reading the CnSC register
 *          while CHF is set and then writing a 0 to the CHF bit. Writing a 1 to CHF has no effect.
 *          If another event occurs between the read and write operations, the write operation has no effect;
 *          therefore, CHF remains set indicating an event has occurred. In this case a CHF interrupt request is not lost due to the
 *          clearing sequence for a previous CHF.
 *              0b - No channel (n) event has occurred.
 *              1b - A channel (n) event has occurred.
 *
 * @param[in]   instance    FTM hw instance number
 * @param[in]   channel     FTM hw channel number
 *
 * @return  TRUE if a channel (n) event has occurred, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
static inline boolean Ftm_Gpt_Ip_GetChInterruptStatusFlag(uint8 instance, uint8 channel)
{
    return (0U != (ftmGptBase[instance]->CONTROLS[channel].CSC & FTM_CSC_CHF_MASK)) ? TRUE : FALSE;
}
/*================================================================================================*/
/**
* @brief
* Function Name : Ftm_Gpt_Ip_GetCntValue
* Description   : Get current counter value
*
* @param[in]    instance    FTM hardware instance number
*
* @return   current counter value
*
*/
static inline uint32 Ftm_Gpt_Ip_GetCntValue(uint8 instance)
{
    return ftmGptBase[instance]->CNT;
}

/*================================================================================================*/
/**
 * @brief
 * Function Name : Ftm_Gpt_Ip_GetCompareValue
 * Description   : Get compare value (CV)
 *
 * @param[in]   instance    FTM hw instance number
 * @param[in]   channel     FTM hw channel number
 *
 * @return      compare value (CV)
 *
 */
static inline uint32 Ftm_Gpt_Ip_GetCompareValue(uint8 instance, uint8 channel)
{
    return ftmGptBase[instance]->CONTROLS[channel].CV;
}
/*================================================================================================*/
/**
* @brief         Function Name : Ftm_Gpt_Ip_Init
* @details       Initializes the FTM instance. This functions is called for each FTM hardware Instance.
*
* @param[in]     instance     FTM hardware instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
*/
void Ftm_Gpt_Ip_Init(uint8 instance, const Ftm_Gpt_Ip_InstanceConfigType *configPtr);
/*================================================================================================*/
/**
* @brief         Function Name : Ftm_Gpt_Ip_InitChannel
* @details       Initializes the FTM channels. This functions is called for each FTM hardware channel and:
*
* @param[in]     instance     FTM hardware instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
*/
void Ftm_Gpt_Ip_InitChannel(uint8 instance, const Ftm_Gpt_Ip_ChannelConfigType *configPtr);
/*================================================================================================*/
/**
* @brief        Function Name : Ftm_Gpt_Ip_Deinit
* @details      De-Initializes the FTM module. This functions is called for each FTM hardware instance and:
*                    - resets all channels to default
*                    - disables the timer compare interrupts corresponding to Ftm channel
*                    - clears the timer compare interrupt flags corresponding to Ftm channel
*                    - resets the counter register and the counter initial value register.
*                    - resets the channel value register and the modulo register
*                    - disables the freeze mode
*
* @param[in]     instance     FTM hardware instance number
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver.
*/
void Ftm_Gpt_Ip_Deinit(uint8 instance);
/*================================================================================================*/
/**
* @brief        Function Name : Ftm_Gpt_Ip_StartCounting
* @details      This function is called for starting the Ftm timer channel
*
* @param[in]     instance        FTM hardware instance number
* @param[in]     channel         Ftm channel
* @param[in]     compareValue    Compare value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the FTM timer channel.
*/
void Ftm_Gpt_Ip_StartCounting(uint8 instance, uint8 channel, uint16 compareValue);
/*================================================================================================*/
#if FTM_GPT_IP_ABSOLUTE_COUNTING_API == STD_ON
/**
* @brief        Function Name : Ftm_Gpt_Ip_StartCountingAbsolute
* @details      This function is called for starting the Ftm timer channel
*                    - sets the compare value without adding the current counter value to the timeout value
*                    - enables the FTM channel
*
* @param[in]     instance        FTM hardware instance
* @param[in]     channel         FTM hardware channel
* @param[in]     compareValue    Compare value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the FTM timer channel.
*
*/
void Ftm_Gpt_Ip_StartCountingAbsolute(uint8 instance, uint8 channel, uint16 compareValue);
#endif
/*================================================================================================*/
/**
* @brief             Function Name : Ftm_Gpt_Ip_StartTimer
* @details           This function is called for setting a new start counter value and enables the FTM counter and
*                           - sets the new counter value
*                           - enables the FTM counter
*/
void Ftm_Gpt_Ip_StartTimer(uint8 instance, uint16 counterValue);
/*================================================================================================*/
/**
* @brief        Function Name : Ftm_Gpt_Ip_StopTimer
* @details      This function is callded for stopping the Ftm counter.
*                   - disables the FTM counter
*
* @param[in]     instance       FTM hardware instance
* @return        void
* @pre           The driver needs to be initialized. This function is called for stoping the FTM timer channel.
*/
void Ftm_Gpt_Ip_StopTimer(uint8 instance);
/*================================================================================================*/
/**
* @brief        Function Name : Ftm_Gpt_Ip_EnableChannelInterrupt
* @details      This function allows enabling interrupt generation of timer channel
*               when timeout occurs
*
* @param[in]    instance        FTM hardware instance
* @param[in]    channel         FTM hardware channel
* @return       void
* @pre          The driver needs to be initialized.
*/
void Ftm_Gpt_Ip_EnableChannelInterrupt(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief        Function Name : Ftm_Gpt_Ip_DisableChannelInterrupt
* @details      This function allows disabling interrupt generation of timer channel
*               when timeout occurs
*
* @param[in]     instance        FTM hardware instance
* @param[in]     channel         FTM hardware channel
* @return        void
* @pre           The driver needs to be initialized.
*/
void Ftm_Gpt_Ip_DisableChannelInterrupt(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief         Function Name : Ftm_Gpt_Ip_SetHalfCycleReloadPoint
* @details       Configures the value of the counter with half cycle of reload point.
*
* @param[in]     instance                  FTM hardware instance
* @param[in]     reloadPoint               Reload value

* @return
* @pre           The driver needs to be initialized.
*/
void Ftm_Gpt_Ip_SetHalfCycleReloadPoint(uint8 instance, uint16 reloadPoint);
/*================================================================================================*/
#if (FTM_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief      The function changes the Ftm compare register value.
* @details This function:
*          - Write next timeout to local variable
*
* @param[in]     instance        FTM hardware instance
* @param[in]     channel         Channel
* @param[in]     value           Channel timeout value
* @return        void
* @pre           The driver needs to be initialized.
*/
void Ftm_Gpt_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint16 value);
#endif/*FTM_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE*/
/*================================================================================================*/
#if (FTM_GPT_IP_SET_CLOCK_MODE == STD_ON)
/**
* @brief        The function changes the FTM prescaler value.
* @details      This function sets the FTM prescaler based on the input mode.
*
* @param[in]    instance     FTM hardware instance
* @param[in]    prescalerMode    FTM_GPT_IP_CLOCKMODE_NORMAL or FTM_GPT_IP_CLOCKMODE_ALTERNATE
*
* @return       void
* @pre          The driver needs to be initialized.On/Off by the configuration parameter: GPT_DUAL_CLOCK_MODE
* @implements   Ftm_Gpt_Ip_SetClockMode_Activity
*/
void Ftm_Gpt_Ip_SetClockMode(uint8 instance, Ftm_Gpt_Ip_ClockModeType prescalerMode);
#endif/*FTM_GPT_IP_SET_CLOCK_MODE*/
/*================================================================================================*/
#if(FTM_GPT_IP_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief      The function start the FTM channel.
* @details    This function start the FTM channel the input mode.
*
* @param[in]  instance        FTM hardware instance
* @param[in]  uPrescaler      Prescaler
* @param[in]  bFreezeEnable   enables/disables freeze bits
* @return     void
* @pre        The driver needs to be initialized
*/
void Ftm_Gpt_Ip_StartPredefTimer (uint8 instance,uint8 channel, uint8 uPrescaler, uint8 clocksource, boolean bFreezeEnable);
/*================================================================================================*/
/**
* @brief      The function stop the FTM channel.
* @details    This function stop the FTM channel.
*
* @param[in]  channel      FTM hardware channel
* @param[in]  instance     FTM hardware instance
*
*
* @return     void
* @pre        The driver needs to be initialized
*/
void Ftm_Gpt_Ip_StopPredefTimer (uint8 instance, uint8 channel);
#endif/*FTM_GPT_IP_PREDEFTIMER_FUNCTIONALITY_API*/

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif/*FTM_GPT_IP_USED*/

#ifdef __cplusplus
}
#endif
/** @} */
#endif/*FTM_GPT_IP_H*/
