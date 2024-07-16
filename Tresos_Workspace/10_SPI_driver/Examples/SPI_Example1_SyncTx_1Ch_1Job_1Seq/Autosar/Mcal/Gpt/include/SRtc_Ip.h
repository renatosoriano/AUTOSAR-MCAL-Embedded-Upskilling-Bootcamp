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

#ifndef SRTC_IP_H
#define SRTC_IP_H

/**
*   @file       SRtc_Ip.h
*
*   @addtogroup srtc_ip Rtc IPL
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
#include "SRtc_Ip_Types.h"
#include "SRtc_Ip_Cfg.h"
#include "OsIf.h"
#include "Mcal.h"
#if (STD_ON == SRTC_IP_ENABLE_USER_MODE_SUPPORT)
#include "Reg_eSys.h"
#endif
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
#include "Devassert.h"
#endif
#include "SchM_Gpt.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SRTC_IP_VENDOR_ID                       43
#define SRTC_IP_AR_RELEASE_MAJOR_VERSION        4
#define SRTC_IP_AR_RELEASE_MINOR_VERSION        7
#define SRTC_IP_AR_RELEASE_REVISION_VERSION     0
#define SRTC_IP_SW_MAJOR_VERSION                2
#define SRTC_IP_SW_MINOR_VERSION                0
#define SRTC_IP_SW_PATCH_VERSION                0

/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/
#if (SRTC_IP_VENDOR_ID != SRTC_IP_TYPES_VENDOR_ID)
    #error "SRtc_Ip.h and SRtc_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION != SRTC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SRTC_IP_AR_RELEASE_MINOR_VERSION != SRTC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SRTC_IP_AR_RELEASE_REVISION_VERSION != SRTC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SRtc_Ip.h and SRtc_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((SRTC_IP_SW_MAJOR_VERSION != SRTC_IP_TYPES_SW_MAJOR_VERSION) || \
     (SRTC_IP_SW_MINOR_VERSION != SRTC_IP_TYPES_SW_MINOR_VERSION) || \
     (SRTC_IP_SW_PATCH_VERSION != SRTC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SRtc_Ip.h and SRtc_Ip_Types.h are different"
#endif

#if (SRTC_IP_VENDOR_ID != SRTC_IP_VENDOR_ID_CFG)
    #error "SRtc_Ip.h and SRtc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if RTC_IP header file and RTC_IP_Cfg header file are of the same Autosar version */
#if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION != SRTC_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SRTC_IP_AR_RELEASE_MINOR_VERSION != SRTC_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SRTC_IP_AR_RELEASE_REVISION_VERSION != SRTC_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of SRtc_Ip.h and SRtc_Ip_Cfg.h are different"
#endif
/* Check if RTC_IP file and RTC_IP_Cfg header file are of the same Software version */
#if ((SRTC_IP_SW_MAJOR_VERSION != SRTC_IP_SW_MAJOR_VERSION_CFG) || \
     (SRTC_IP_SW_MINOR_VERSION != SRTC_IP_SW_MINOR_VERSION_CFG) || \
     (SRTC_IP_SW_PATCH_VERSION != SRTC_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of SRtc_Ip.h and SRtc_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_AR_RELEASE_MAJOR_VERSION) || \
         (SRTC_IP_AR_RELEASE_MINOR_VERSION != SCHM_GPT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of SRtc_Ip.h and SchM_Gpt.h are different"
    #endif
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (SRTC_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of SRtc_Ip.h and OsIf.h are different"
    #endif
    /* Check if header file and Mcal.h header file are of the same Autosar version */
    #if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SRTC_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of SRtc_Ip.h and Mcal.h  are different"
    #endif
#endif

#if (STD_ON == SRTC_IP_ENABLE_USER_MODE_SUPPORT)
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (SRTC_IP_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of SRtc_Ip.h and Reg_eSys.h are different"
    #endif
#endif
#endif

#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (SRTC_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of SRtc_Ip.h and Devassert.h are different"
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
#if (SRTC_IP_USED == STD_ON)

#define GPT_START_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"
/**
* @brief          array variable used to store the runtime target time value.
*/
extern uint32 Srtc_Ip_u32TargetValue;

#define GPT_STOP_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/**
 * @brief
 * Function Name : Srtc_Ip_GetInterruptStatusFlag
 * Description   : Get the status of Time Invalid Flag (TIF),
 *                 Time Alarm Flag (TAF) and Time Overflow Flag (TOF): RTC Status Register (SR)
 *
 * @param[in]   instance        RTC hw instance number
 * @param[in]   interruptMode   Enum containing RTC interrupt type
 *
 * @return  TRUE if an interrupt has occurred, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
boolean Srtc_Ip_GetInterruptStatusFlag(uint8 instance, Srtc_Ip_InterruptType interruptMode);
uint32 Srtc_Ip_GetTimeSecondsRegister(uint8 instance);
uint32 Srtc_Ip_GetTimeAlarmRegister(uint8 instance);
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
*
*/
void Srtc_Ip_ConvertSecondsToTimeDate(const uint32 * const seconds,
                                      Srtc_Ip_TimedateType * const timeDate);
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
*
*/
void Srtc_Ip_ConvertTimeDateToSeconds(const Srtc_Ip_TimedateType * const timeDate,
                                      uint32 * const seconds);
/*================================================================================================*/
/**
* @brief   SRtc driver initialization function for SRtc module.
* @details This function:
*          - Disables the time counter
*          - Disables all interupt modes
*          - Clears Time Invalid Flag
*          - Selects source Clock
*          - If compensation support is enabled sets the configured values
*          - Sets channel state variables
*
* @param[in]     instance     hw instance
* @param[in]     *config      pointer to configuration
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver
*
*/
void Srtc_Ip_Init(uint8 instance, const Srtc_Ip_ConfigType *config);
/*================================================================================================*/
/**
* @brief         SRtc driver de-initialization function
* @details       This function:
*                       - Performs a software reset
*                       - Clears global variables
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
*
*/
void Srtc_Ip_DeInit(uint8 instance);
/*================================================================================================*/
/**
* @brief         SRtc Driver function for starting the Rtc counter.
* @details       This function:
*                           - Enables the counter
* @param[in]     instance            Rtc hw instance
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
*
*/
Srtc_Ip_StatusType Srtc_Ip_StartCounter(uint8 instance);
/*================================================================================================*/
/**
* @brief         SRtc Driver function for stopping the Rtc counter.
* @details       This function:
*                           - Disables Time Alaram Interrupt
*                           - Clears interrupt flag
*                           - Disables the counter
* @param[in]     instance            Rtc hw instance
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
*
*/
Srtc_Ip_StatusType Srtc_Ip_StopCounter(uint8 instance);
/*================================================================================================*/
/**
* @brief         SRtc Driver function for starting the Rtc timer channel with a timeout value.
* @details       This function:
*                       - Disables counter
*                       - Disables Time Alaram Interrupt
*                       - Gets Time Seconds Register value
*                       - Calcutates new compare value
*                       - Sets Time Alarm Register
*                       - Enables Time Alaram Interrupt
*                       - Enables counter
*
* @param[in]     instance         Rtc hw instance
*                value            channel timeout value
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
*
*/
void Srtc_Ip_StartTimer(uint8 instance, uint32 value);
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
*
*/
void Srtc_Ip_EnableInterrupt(uint8 instance, Srtc_Ip_InterruptType interruptMode);
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
*
*/
void Srtc_Ip_DisableInterrupt(uint8 instance, Srtc_Ip_InterruptType interruptMode);
/*================================================================================================*/
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                        - Sets the date passed by the user.
*
* @param[in]     instance           SRtc hw instance
* @param[in]     *timeDate          pointer to configuration
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
*
*/
Srtc_Ip_StatusType Srtc_Ip_SetTimeDate(uint8 instance,
                                       const Srtc_Ip_TimedateType *timeDate);
/*================================================================================================*/
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                        - Gets the current time and date and it will
*                               store in the state structure.
*
* @param[in]     instance           sRtc hw instance
* @param[in]     *timeDate          pointer to configuration
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
*
*/
Srtc_Ip_StatusType Srtc_Ip_GetTimeDate(uint8 instance,
                         Srtc_Ip_TimedateType * const timeDate);


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
*
*/
Srtc_Ip_StatusType Srtc_Ip_ConfigureAlarm(uint8 instance,
                                          const Srtc_Ip_AlarmConfigType *alarmConfig);

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
*
*/
Srtc_Ip_StatusType Srtc_Ip_ConfigureSecondsInterrupt(uint8 instance,
                                                     Srtc_Ip_SecIntFreqType occursFrequency);

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
*
*/
Srtc_Ip_StatusType Srtc_Ip_ConfigureLockRegister(uint8 instance,
                                                     Srtc_Ip_LockRegConfigType * const lockRegister);
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* SRTC_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */
#endif /* SRTC_IP_H*/
