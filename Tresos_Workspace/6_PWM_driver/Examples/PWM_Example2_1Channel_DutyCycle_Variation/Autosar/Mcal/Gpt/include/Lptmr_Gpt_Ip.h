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

#ifndef LPTMR_GPT_IP_H
#define LPTMR_GPT_IP_H

/**
*   @file       Lptmr_Gpt_Ip.h
*
*   @addtogroup Lptmr_Gpt_Ip Lptmr IPL
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
#include "Lptmr_Gpt_Ip_Types.h"
#include "Lptmr_Gpt_Ip_Cfg.h"
#include "OsIf.h"
#include "Mcal.h"
#include "SchM_Gpt.h"
#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
#include "Devassert.h"
#endif
#if (LPTMR_GPT_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
#include "Reg_eSys.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPTMR_GPT_IP_VENDOR_ID                       43
#define LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION        4
#define LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION        7
#define LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION     0
#define LPTMR_GPT_IP_SW_MAJOR_VERSION                2
#define LPTMR_GPT_IP_SW_MINOR_VERSION                0
#define LPTMR_GPT_IP_SW_PATCH_VERSION                0

/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/
#if (LPTMR_GPT_IP_VENDOR_ID != LPTMR_GPT_IP_TYPES_VENDOR_ID)
    #error "Lptmr_Gpt_Ip.h and Lptmr_Gpt_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION != LPTMR_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION != LPTMR_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION != LPTMR_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lptmr_Gpt_Ip.h and Lptmr_Gpt_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((LPTMR_GPT_IP_SW_MAJOR_VERSION != LPTMR_GPT_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPTMR_GPT_IP_SW_MINOR_VERSION != LPTMR_GPT_IP_TYPES_SW_MINOR_VERSION) || \
     (LPTMR_GPT_IP_SW_PATCH_VERSION != LPTMR_GPT_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lptmr_Gpt_Ip.h and Lptmr_Gpt_Ip_Types.h are different"
#endif

#if (LPTMR_GPT_IP_VENDOR_ID != LPTMR_GPT_IP_VENDOR_ID_CFG)
    #error "Lptmr_Gpt_Ip.h and Lptmr_Gpt_Ip_Cfg.h have different vendor ids"
#endif
/* Check if LPTMR_GPT_IP header file and LPTMR_GPT_IP_Cfg header file are of the same Autosar version */
#if ((LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION != LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION != LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION != LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Lptmr_Gpt_Ip.h and Lptmr_Gpt_Ip_Cfg.h are different"
#endif
/* Check if LPTMR_GPT_IP file and LPTMR_GPT_IP_Cfg header file are of the same Software version */
#if ((LPTMR_GPT_IP_SW_MAJOR_VERSION != LPTMR_GPT_IP_SW_MAJOR_VERSION_CFG) || \
     (LPTMR_GPT_IP_SW_MINOR_VERSION != LPTMR_GPT_IP_SW_MINOR_VERSION_CFG) || \
     (LPTMR_GPT_IP_SW_PATCH_VERSION != LPTMR_GPT_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Lptmr_Gpt_Ip.h and Lptmr_Gpt_Ip_Cfg.h are different"
#endif

#if (LPTMR_GPT_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lptmr_Gpt_Ip.h and Reg_eSys.h are different"
    #endif
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_AR_RELEASE_MAJOR_VERSION) || \
         (LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION != SCHM_GPT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lptmr_Gpt_Ip.h and SchM_Gpt.h are different"
    #endif
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lptmr_Gpt_Ip.h and OsIf.h are different"
    #endif
    /* Check if source file and Std_Types.h header file are of the same Autosar version */
    #if ((LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lptmr_Gpt_Ip.h and Mcal.h  are different"
    #endif
#endif

#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lptmr_Gpt_Ip.h and Devassert.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (LPTMR_GPT_IP_USED == STD_ON)
/**
 * @brief     Define Mode
 * @details   Mode type (TMS)
 */
#define    LPTMR_GPT_IP_TM_MODE                 ((uint32)(0x00))          /**< @brief Time Counter mode */

extern LPTMR_Type * const lptmrGptBase[LPTMR_INSTANCE_COUNT];

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/*================================================================================================*/

/**
* @brief         Lptmr_Gpt_Ip_GetInterruptStatusFlag Get the Compare Flag state
* @details       This function checks whether a Compare Match event has occurred or if there is an Interrupt Pending.
*
*
* @param[in]     instance     LPtimer hw instance number
*
*
* @return       The Compare Flag state
*               - true: Compare Match/Interrupt Pending asserted
*               - false: Compare Match/Interrupt Pending not asserted
* @pre           The driver needs to be initialized.
*
*/
static inline boolean Lptmr_Gpt_Ip_GetInterruptStatusFlag(uint8 instance)
{
#if LPTMR_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(LPTMR_INSTANCE_COUNT > instance);
#endif
    return (0U != (lptmrGptBase[instance]->CSR & LPTMR_CSR_TCF_MASK)) ? TRUE : FALSE;
}

uint32 Lptmr_Gpt_Ip_GetCompareValue(uint8 instance);
uint32 Lptmr_Gpt_Ip_GetCntValue(uint8 instance);
void Lptmr_Gpt_Ip_WriteCounterValue(uint8 instance, uint16 value);

/*================================================================================================*/
/**
* @brief          LPTMR Driver initialization function
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
*/
void Lptmr_Gpt_Ip_Init(uint8 instance, const Lptmr_Gpt_Ip_ConfigType *config);

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
*
*/
void Lptmr_Gpt_Ip_DeInit(uint8 instance);
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
*
*
* @param[in]     value            channel timeout value
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
*
*/
void Lptmr_Gpt_Ip_StartTimer(uint8 instance, uint16 value);

/*================================================================================================*/
/**
* @brief        Function for stopping the Lptmr timer channel.
* @details      This function disables the LPTMR channel
*
*
* @param[in]     instance        LPTMR hw instance
* @return        void
* @pre           The driver needs to be initialized.
*/
void Lptmr_Gpt_Ip_StopTimer(uint8 instance);


/*================================================================================================*/
/**
* @brief         Driver function for Enable Interrupt for LPTMR channel
* @details       This function:
*                        - Enable Interrupt for LPTMR channel
*
* @param[in]     instance        LPTMR hw instance
* @return        void
* @pre           The driver needs to be initialized.
*
*/
void Lptmr_Gpt_Ip_EnableInterrupt(uint8 instance);
/*================================================================================================*/
/**
* @brief         Lptmr_Gpt_Ip_SetCompareValue
* @details       This function:
*                        - Set the compare value in counter tick units, for a LPTMR instance.
*                   Possible return values:
*                  - STATUS_SUCCESS: completed successfully
*                  - STATUS_ERROR: cannot reconfigure compare value (TCF not set)
*                  - STATUS_TIMEOUT: compare value is smaller than current counter value
*
* @param[in]     instance        LPTMR hw instance
* @param[in]     compareValue    Compare value in counter tick units
* @return        void
* @pre           The driver needs to be initialized.
*
*
*
*/
Lptmr_Gpt_Ip_StatusType Lptmr_Gpt_Ip_SetCompareValue(uint8 instance,
                                           uint16 compareValue);

/*================================================================================================*/
/**
* @brief         Gpt driver function for Disable Interrupt for LPTMR channel
* @details       This function:
*                        - Disable Interrupt for LPTMR channel
* @param[in]     instance        LPTMR hw instance
* @return        void
* @pre           The driver needs to be initialized.
*
*/
void Lptmr_Gpt_Ip_DisableInterrupt(uint8 instance);

/*================================================================================================*/
#if (LPTMR_GPT_IP_SET_CLOCK_MODE == STD_ON)
/**
* @brief        The function changes the LPtimer prescaler value.
* @details      This function sets the LPtimer prescaler based on the input mode.
*
* @param[in]    instance     LPtimer hardware instance
* @param[in]    clockMode    LPTMR_GPT_IP_CLOCKMODE_NORMAL or LPTMR_GPT_IP_CLOCKMODE_ALTERNATE
*
* @return       void
* @pre          The driver needs to be initialized.On/Off by the configuration parameter: GPT_DUAL_CLOCK_MODE
* @implements   Lptmr_Gpt_Ip_SetClockMode_Activity
*/
void Lptmr_Gpt_Ip_SetClockMode(uint8 instance, Lptmr_Gpt_Ip_ClockModeType clockMode);
/*================================================================================================*/
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif /* LPTMR_GPT_IP_USED == STD_ON */

/** @} */
#endif /* LPTMR_GPT_IP_H*/
#endif /* LPTMR_GPT_IP_H*/
