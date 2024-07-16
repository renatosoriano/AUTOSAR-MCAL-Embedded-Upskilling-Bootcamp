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

#ifndef LPIT_GPT_IP_H
#define LPIT_GPT_IP_H
/**
*   @file       LPit_Gpt_Ip.h
*
*   @addtogroup lpit_ip LPit IPL
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
#include "LPit_Gpt_Ip_Types.h"
#include "LPit_Gpt_Ip_Cfg.h"
#include "OsIf.h"
#include "Mcal.h"
#include "SchM_Gpt.h"
#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
#include "Devassert.h"
#endif
#if (LPIT_GPT_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
#include "Reg_eSys.h"
#endif
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPIT_GPT_IP_VENDOR_ID                       43
#define LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION        4
#define LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION        7
#define LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION     0
#define LPIT_GPT_IP_SW_MAJOR_VERSION                2
#define LPIT_GPT_IP_SW_MINOR_VERSION                0
#define LPIT_GPT_IP_SW_PATCH_VERSION                0


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (LPIT_GPT_IP_VENDOR_ID != LPIT_GPT_IP_TYPES_VENDOR_ID)
    #error "LPit_Gpt_Ip.h and LPit_Gpt_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION != LPIT_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION != LPIT_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION != LPIT_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of LPit_Gpt_Ip.h and LPit_Gpt_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((LPIT_GPT_IP_SW_MAJOR_VERSION != LPIT_GPT_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPIT_GPT_IP_SW_MINOR_VERSION != LPIT_GPT_IP_TYPES_SW_MINOR_VERSION) || \
     (LPIT_GPT_IP_SW_PATCH_VERSION != LPIT_GPT_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LPit_Gpt_Ip.h and LPit_Gpt_Ip_Types.h are different"
#endif

#if (LPIT_GPT_IP_VENDOR_ID != LPIT_GPT_IP_VENDOR_ID_CFG)
    #error "LPit_Gpt_ip.h and LPit_Gpt_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Pit_ip header file and LPit_Gpt_Ip_Cfg header file are of the same Autosar version */
#if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION != LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION != LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION != LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of LPit_Gpt_Ip.h and LPit_Gpt_Ip_Cfg.h are different"
#endif
/* Check if Pit_ip file and LPit_Gpt_Ip_Cfg header file are of the same Software version */
#if ((LPIT_GPT_IP_SW_MAJOR_VERSION != LPIT_GPT_IP_SW_MAJOR_VERSION_CFG) || \
     (LPIT_GPT_IP_SW_MINOR_VERSION != LPIT_GPT_IP_SW_MINOR_VERSION_CFG) || \
     (LPIT_GPT_IP_SW_PATCH_VERSION != LPIT_GPT_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of LPit_Gpt_Ip.h and LPit_Gpt_Ip_Cfg.h are different"
#endif

#if (LPIT_GPT_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
/* Check if header file and Reg_eSys.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of LPit_Gpt_Ip.h and Reg_eSys.h are different"
    #endif
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_AR_RELEASE_MAJOR_VERSION) || \
         (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION != SCHM_GPT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of LPit_Gpt_Ip.h and SchM_Gpt.h are different"
    #endif
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of LPit_Gpt_Ip.h and OsIf.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Mcal.h header file are of the same Autosar version */
    #if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of LPit_Gpt_Ip.h and Mcal.h  are different"
    #endif
#endif

#if (STD_ON == LPIT_GPT_IP_DEV_ERROR_DETECT)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of LPit_Gpt_Ip.h and Devassert.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                                           CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/
#if (LPIT_GPT_IP_USED == STD_ON)
#define LPIT_MAX_VALUE  0xFFFFFFFFUL
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
/** @brief Table of base addresses for PIT instances. */
extern LPIT_Type * const LPitGptBase[LPIT_INSTANCE_COUNT];
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#if (LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

/**
* @internal
* @brief            Lpit_Gpt_Ip_u32OldTargetValue
* @details          Local variable used to store the previous target time value after call ChangeNextTimeout.
*/
extern uint32 Lpit_Gpt_Ip_u32OldTargetValue;

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"
#endif /* (LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON) */
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/*!
 * @brief   Get the Interrupt Flag Status of LPIT peripheral timer channel.
 * @details MSR Module Status Register
 *          Channel 0 ... 3 Timer Interrupt Flags: TIF0 ... TIF3.
 *          • 0 - No timer event (compare match or timeout) has occurred
 *          • 1 - A timer event (compare match or timeout) has occurred
 *
 * @param[in] instance - Instance number of LPIT module
 * @param[in] channel - The channel in the LPIT instance
 *
 * @return Channel Interrupt Flag Status
 *         - True : Channel interrupt has occurred
 *         - False: No channel interrupt has occurred
 * @pre The driver needs to be initialized.
 *
 */
static inline boolean Lpit_Gpt_Ip_GetChannelInterruptFlagStatus(uint8 instance, uint8 channel)
{
    uint32 mask = ((instance < LPIT_INSTANCE_COUNT) && (channel < LPIT_TMR_COUNT)) ? (1UL << channel) : 0U;
    boolean retVal = ((instance < LPIT_INSTANCE_COUNT) && (channel < LPIT_TMR_COUNT)) ? ((0U != (LPitGptBase[instance]->MSR & mask)) ? TRUE : FALSE) : FALSE;
    return retVal;
}

/**
* @brief    Lpit_Gpt_Ip_GetCurrentTimerValue - Gets the current timer channel counting value.
*
* @details  This function returns the real-time timer channel counting value, the value in
*           a range from 0 to timer channel period.
*           Need to make sure the running time does not exceed the timer channel period.
*
* @param[in] instance LPIT peripheral base address
* @param[in] channel Timer channel number
* @return    Current timer channel counting value
*/
static inline uint32 Lpit_Gpt_Ip_GetCurrentTimerValue(uint8 instance, uint8 channel)
{
    return (LPitGptBase[instance]->TMR[channel].CVAL);
}

/**
* @brief    Lpit_Gpt_Ip_GetTimerValue-  Gets the timer channel period in count unit.
*
* @details  This function returns current period of timer channel given as argument.
*
* @param[in] instance   LPIT peripheral base address
* @param[in] channel    Timer channel number
* @return   Timer channel period in count unit
*/
static inline uint32 Lpit_Gpt_Ip_GetTimerValue(uint8 instance, uint8 channel)
{
    return (LPitGptBase[instance]->TMR[channel].TVAL);
}

/*!
 * @brief   Clear the Interrupt Flag of LPIT peripheral timer channel.
 * @details MSR Module Status Register
 *          Channel 0 ... 3 Timer Interrupt Flags: TIF0 ... TIF3; write 1 to clear the bits.
 *
 * @param[in] instance - Instance number of LPIT module
 * @param[in] channel - The channel in the LPIT instance
 *
 * @return  void
 * @pre The driver needs to be initialized.
 *
 */
static inline void Lpit_Gpt_Ip_ClearChannelInterruptFlag(uint8 instance, uint8 channel)
{
    uint32 mask = ((instance < LPIT_INSTANCE_COUNT) && (channel < LPIT_TMR_COUNT)) ? (1UL << channel) : 0U;
    if ((instance < LPIT_INSTANCE_COUNT) && (channel < LPIT_TMR_COUNT))
    {
         /* Write 1 to clear the interrupt flag. */
        LPitGptBase[instance]->MSR = mask;
    }
}

/**
* @brief         Function Name : Lpit_Gpt_Ip_Init
* @details       Driver initialization function for LPit instance.
*
*
* @param[in]     instance     LPIT hw instance number
* @param[in]     config       Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver
*
*/
void Lpit_Gpt_Ip_Init(uint8 instance, const Lpit_Gpt_Ip_InstanceConfigType *config);
/*================================================================================================*/
/**
* @brief         Function Name : Lpit_Gpt_Ip_InitChannel
* @details       Initializes the LPIT channels. This functions is called for each PIT hw channel and:
*
*
* @param[in]     instance        PIT hw instance number
* @param[in]     configChannel   Pointer to a selected configuration structure.
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver.
*
*/
void Lpit_Gpt_Ip_InitChannel(uint8 instance, const Lpit_Gpt_Ip_ChannelConfigType *configChannel);
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
*
*/
void Lpit_Gpt_Ip_Deinit(uint8 instance);
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
*
*/
void Lpit_Gpt_Ip_StartTimer(uint8 instance, uint8 channel, uint32 countValue);
/*================================================================================================*/
/**
* @brief         Function Name : Lpit_Gpt_Ip_StopTimer
* @details       This function is called for stopping the Pit counter. This function disables the LPIT channel and:
*
*
* @param[in]     instance        LPit hw instance
* @param[in]     channel         LPit hw channel
* @return        void
* @pre           The driver needs to be initialized. LPit_Gpt_Ip_StartTimer must be call before.
*
*/
void Lpit_Gpt_Ip_StopTimer(uint8 instance, uint8 channel);
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
*
*/
void Lpit_Gpt_Ip_EnableChInterrupt(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief        Function Name : Lpit_Gpt_Ip_DisableChInterrupt
* @details      This function allows disabling interrupt of a timer channel
*
* @param[in]    instance        LPit hw instance
* @param[in]    channel         LPit hw channel
* @return       void
* @pre          The driver needs to be initialized.
*
*/
void Lpit_Gpt_Ip_DisableChInterrupt(uint8 instance, uint8 channel);
/*================================================================================================*/
#if (LPIT_GPT_IP_CHAIN_MODE == STD_ON)
/**
* @brief      Function Name : Lpit_Gpt_Ip_ChainMode.
* @details    This function:
*               - Chain/Unchain LPit channels.
* @param[in]     instance        LPit hw channel ID
* @param[in]     channel         channel timeout value
* @param[in]     enable          enable/disable chain mode
* @return        returnValue
* @pre           The driver needs to be initialized. LPIT_GPT_IP_CHAIN_MODE == STD_ON
*
*/
Lpit_Gpt_Ip_StatusType Lpit_Gpt_Ip_ChainMode(uint8 instance, uint8 channel, boolean enable);
#endif /* LPIT_GPT_IP_CHAIN_MODE == STD_ON */
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
void Lpit_Gpt_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint32 value);
#endif /* LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* LPIT_GPT_IP_USED == STD_ON */

#ifdef __cplusplus
}
#endif
/** @} */
#endif  /* LPIT_GPT_IP_H */
