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
/**
*   @file       Ftm_Gpt_Ip.c
*
*   @addtogroup ftm_ip Ftm IPL
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
#include "Ftm_Gpt_Ip.h"

#if (STD_ON == FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT)
#define USER_MODE_REG_PROT_ENABLED  STD_ON
#include "RegLockMacros.h"
#else
#define USER_MODE_REG_PROT_ENABLED  STD_OFF
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FTM_GPT_IP_VENDOR_ID_C                    43
#define FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_C     7
#define FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_C  0
#define FTM_GPT_IP_SW_MAJOR_VERSION_C             2
#define FTM_GPT_IP_SW_MINOR_VERSION_C             0
#define FTM_GPT_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (FTM_GPT_IP_VENDOR_ID != FTM_GPT_IP_VENDOR_ID_C)
    #error "Ftm_Gpt_Ip.h and Ftm_Gpt_Ip.c have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION != FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (FTM_GPT_IP_AR_RELEASE_MINOR_VERSION != FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (FTM_GPT_IP_AR_RELEASE_REVISION_VERSION != FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_C) \
    )
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip.h and Ftm_Gpt_Ip.c are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((FTM_GPT_IP_SW_MAJOR_VERSION != FTM_GPT_IP_SW_MAJOR_VERSION_C) || \
     (FTM_GPT_IP_SW_MINOR_VERSION != FTM_GPT_IP_SW_MINOR_VERSION_C) || \
     (FTM_GPT_IP_SW_PATCH_VERSION != FTM_GPT_IP_SW_PATCH_VERSION_C) \
    )
    #error "Software Version Numbers of Ftm_Gpt_Ip.h and Ftm_Gpt_Ip.c are different"
#endif

#if (STD_ON == FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Platform_Types.h header file are of the same Autosar version */
    #if ((REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION != FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_C) || \
         (REGLOCKMACROS_AR_RELEASE_MINOR_VERSION != FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_C))
        #error "AutoSar Version Numbers of RegLockMacros.h and Ftm_Gpt_Ip.c are different"
    #endif
#endif
#endif
/*==================================================================================================
*                                          LOCAL DEFINIES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/**
 * @brief       internal context enumeration
 * @details     This enumeration is used by the IPL driver for internal logic.
 *
 */
typedef enum
{
    FTM_GPT_IP_STATUS_UNINITIALIZED = 0U,   /**< @brief FTM instance status - uninitialized */
    FTM_GPT_IP_STATUS_INITIALIZED   = 1U,   /**< @brief FTM instance status - initialized */
} Ftm_Gpt_Ip_InstanceStatusType;

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#if (FTM_GPT_IP_USED == STD_ON)

#define GPT_START_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"
/** @brief Global array variable used to store the runtime target time value. */
uint32 Ftm_Gpt_Ip_u32TargetValue[FTM_INSTANCE_COUNT][FTM_CONTROLS_COUNT];
#define GPT_STOP_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
/* Table of base pointers for FTM instances. */
FTM_Type * const ftmGptBase[FTM_INSTANCE_COUNT] = IP_FTM_BASE_PTRS;
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

static Ftm_Gpt_Ip_InstanceStatusType Ftm_Gpt_Ip_u32InstanceState[FTM_INSTANCE_COUNT] = {FTM_GPT_IP_STATUS_UNINITIALIZED};

#if ((defined FTM_0_ISR_USED) || (defined FTM_1_ISR_USED) || \
    (defined FTM_0_CH_0_CH_1_ISR_USED) || (defined FTM_0_CH_2_CH_3_ISR_USED) || (defined FTM_0_CH_4_CH_5_ISR_USED) || \
    (defined FTM_0_CH_6_CH_7_ISR_USED) || (defined FTM_1_CH_0_CH_1_ISR_USED) || (defined FTM_1_CH_2_CH_3_ISR_USED) || \
    (defined FTM_1_CH_4_CH_5_ISR_USED) || (defined FTM_1_CH_6_CH_7_ISR_USED) || (defined FTM_2_CH_0_CH_1_ISR_USED) || \
    (defined FTM_2_CH_2_CH_3_ISR_USED) || (defined FTM_2_CH_4_CH_5_ISR_USED) || (defined FTM_2_CH_6_CH_7_ISR_USED) || \
    (defined FTM_3_CH_0_CH_1_ISR_USED) || (defined FTM_3_CH_2_CH_3_ISR_USED) || (defined FTM_3_CH_4_CH_5_ISR_USED) || \
    (defined FTM_3_CH_6_CH_7_ISR_USED) || (defined FTM_4_CH_0_CH_1_ISR_USED) || (defined FTM_4_CH_2_CH_3_ISR_USED) || \
    (defined FTM_4_CH_4_CH_5_ISR_USED) || (defined FTM_4_CH_6_CH_7_ISR_USED) || (defined FTM_5_CH_0_CH_1_ISR_USED) || \
    (defined FTM_5_CH_2_CH_3_ISR_USED) || (defined FTM_5_CH_4_CH_5_ISR_USED) || (defined FTM_5_CH_6_CH_7_ISR_USED) || \
    (defined FTM_6_CH_0_CH_1_ISR_USED) || (defined FTM_6_CH_2_CH_3_ISR_USED) || (defined FTM_6_CH_4_CH_5_ISR_USED) || \
    (defined FTM_6_CH_6_CH_7_ISR_USED) || (defined FTM_7_CH_0_CH_1_ISR_USED) || (defined FTM_7_CH_2_CH_3_ISR_USED) || \
    (defined FTM_7_CH_4_CH_5_ISR_USED) || (defined FTM_7_CH_6_CH_7_ISR_USED))
static Ftm_Gpt_Ip_ChState Ftm_Gpt_Ip_u32ChState[FTM_INSTANCE_COUNT][FTM_CONTROLS_COUNT] =   {
                                                                                                {
                                                                                                    {
                                                                                                        (boolean)FALSE,
                                                                                                        NULL_PTR,
                                                                                                        0U,
                                                                                                        FTM_GPT_IP_CH_MODE_CONTINUOUS
                                                                                                    }
                                                                                                }
                                                                                            };
#endif
#if (FTM_GPT_IP_SET_CLOCK_MODE == STD_ON)
static Ftm_Gpt_Ip_InstancePrescalerType Ftm_Gpt_Ip_u32InstancePrescaler[FTM_INSTANCE_COUNT] =   {
                                                                                                    {
                                                                                                        0U,
                                                                                                        0U
                                                                                                    }
                                                                                                };
#endif
#if ((FTM_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON) && ((defined FTM_0_ISR_USED) || (defined FTM_1_ISR_USED) || \
    (defined FTM_0_CH_0_CH_1_ISR_USED) || (defined FTM_0_CH_2_CH_3_ISR_USED) || (defined FTM_0_CH_4_CH_5_ISR_USED) || \
    (defined FTM_0_CH_6_CH_7_ISR_USED) || (defined FTM_1_CH_0_CH_1_ISR_USED) || (defined FTM_1_CH_2_CH_3_ISR_USED) || \
    (defined FTM_1_CH_4_CH_5_ISR_USED) || (defined FTM_1_CH_6_CH_7_ISR_USED) || (defined FTM_2_CH_0_CH_1_ISR_USED) || \
    (defined FTM_2_CH_2_CH_3_ISR_USED) || (defined FTM_2_CH_4_CH_5_ISR_USED) || (defined FTM_2_CH_6_CH_7_ISR_USED) || \
    (defined FTM_3_CH_0_CH_1_ISR_USED) || (defined FTM_3_CH_2_CH_3_ISR_USED) || (defined FTM_3_CH_4_CH_5_ISR_USED) || \
    (defined FTM_3_CH_6_CH_7_ISR_USED) || (defined FTM_4_CH_0_CH_1_ISR_USED) || (defined FTM_4_CH_2_CH_3_ISR_USED) || \
    (defined FTM_4_CH_4_CH_5_ISR_USED) || (defined FTM_4_CH_6_CH_7_ISR_USED) || (defined FTM_5_CH_0_CH_1_ISR_USED) || \
    (defined FTM_5_CH_2_CH_3_ISR_USED) || (defined FTM_5_CH_4_CH_5_ISR_USED) || (defined FTM_5_CH_6_CH_7_ISR_USED) || \
    (defined FTM_6_CH_0_CH_1_ISR_USED) || (defined FTM_6_CH_2_CH_3_ISR_USED) || (defined FTM_6_CH_4_CH_5_ISR_USED) || \
    (defined FTM_6_CH_6_CH_7_ISR_USED) || (defined FTM_7_CH_0_CH_1_ISR_USED) || (defined FTM_7_CH_2_CH_3_ISR_USED) || \
    (defined FTM_7_CH_4_CH_5_ISR_USED) || (defined FTM_7_CH_6_CH_7_ISR_USED)))
static uint32 Ftm_Gpt_Ip_u32NextTargetValue[FTM_INSTANCE_COUNT][FTM_CONTROLS_COUNT] =   {{(uint32)0}};
#endif
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

static inline void Ftm_Gpt_Ip_SetFreezeBits(uint8 instance, boolean freezeBits);
static inline void Ftm_Gpt_Ip_SetClockSource(uint8 instance, Ftm_Gpt_Ip_ClockSource clocksource);
static inline void Ftm_Gpt_Ip_SetPrescaler(uint8 instance, uint8 prescalerValue);
static inline void Ftm_Gpt_Ip_ClearChInterruptStatusFlag(uint8 instance, uint8 channel);
static inline void Ftm_Gpt_Ip_SetEnFtmModule(uint8 instance, boolean enable);
static inline void Ftm_Gpt_Ip_SetCompareValue(uint8 instance, uint8 channel, uint32 value);
#if ((defined FTM_0_ISR_USED) || (defined FTM_1_ISR_USED) || \
     (defined FTM_0_CH_0_CH_1_ISR_USED) || (defined FTM_0_CH_2_CH_3_ISR_USED) || (defined FTM_0_CH_4_CH_5_ISR_USED) || \
     (defined FTM_0_CH_6_CH_7_ISR_USED) || (defined FTM_1_CH_0_CH_1_ISR_USED) || (defined FTM_1_CH_2_CH_3_ISR_USED) || \
     (defined FTM_1_CH_4_CH_5_ISR_USED) || (defined FTM_1_CH_6_CH_7_ISR_USED) || (defined FTM_2_CH_0_CH_1_ISR_USED) || \
     (defined FTM_2_CH_2_CH_3_ISR_USED) || (defined FTM_2_CH_4_CH_5_ISR_USED) || (defined FTM_2_CH_6_CH_7_ISR_USED) || \
     (defined FTM_3_CH_0_CH_1_ISR_USED) || (defined FTM_3_CH_2_CH_3_ISR_USED) || (defined FTM_3_CH_4_CH_5_ISR_USED) || \
     (defined FTM_3_CH_6_CH_7_ISR_USED) || (defined FTM_4_CH_0_CH_1_ISR_USED) || (defined FTM_4_CH_2_CH_3_ISR_USED) || \
     (defined FTM_4_CH_4_CH_5_ISR_USED) || (defined FTM_4_CH_6_CH_7_ISR_USED) || (defined FTM_5_CH_0_CH_1_ISR_USED) || \
     (defined FTM_5_CH_2_CH_3_ISR_USED) || (defined FTM_5_CH_4_CH_5_ISR_USED) || (defined FTM_5_CH_6_CH_7_ISR_USED) || \
     (defined FTM_6_CH_0_CH_1_ISR_USED) || (defined FTM_6_CH_2_CH_3_ISR_USED) || (defined FTM_6_CH_4_CH_5_ISR_USED) || \
     (defined FTM_6_CH_6_CH_7_ISR_USED) || (defined FTM_7_CH_0_CH_1_ISR_USED) || (defined FTM_7_CH_2_CH_3_ISR_USED) || \
     (defined FTM_7_CH_4_CH_5_ISR_USED) || (defined FTM_7_CH_6_CH_7_ISR_USED))
static inline boolean Ftm_Gpt_Ip_GetChInterruptEnableFlag(uint8 instance, uint8 channel);
#endif
static inline void Ftm_Gpt_Ip_SetChannelEnableInterrupt(uint8 instance, uint8 channel, boolean aboEn);

static inline void Ftm_Gpt_Ip_SetHalfCycleValue(FTM_Type * const base, uint16 value);

static inline void Ftm_Gpt_Ip_SetCounter(uint8 instance, uint16 value);

#if (defined (FTM_GPT_IP_MODULE_SINGLE_INTERRUPT) && (STD_ON == FTM_GPT_IP_MODULE_SINGLE_INTERRUPT))
#ifdef FTM_0_ISR_USED
ISR(FTM_0_ISR);
#endif
#ifdef FTM_1_ISR_USED
ISR(FTM_1_ISR);
#endif
#else
#ifdef FTM_0_CH_0_CH_1_ISR_USED
ISR(FTM_0_CH_0_CH_1_ISR);
#endif
#ifdef FTM_0_CH_2_CH_3_ISR_USED
ISR(FTM_0_CH_2_CH_3_ISR);
#endif
#ifdef FTM_0_CH_4_CH_5_ISR_USED
ISR(FTM_0_CH_4_CH_5_ISR);
#endif
#ifdef FTM_0_CH_6_CH_7_ISR_USED
ISR(FTM_0_CH_6_CH_7_ISR);
#endif
#ifdef FTM_1_CH_0_CH_1_ISR_USED
ISR(FTM_1_CH_0_CH_1_ISR);
#endif
#ifdef FTM_1_CH_2_CH_3_ISR_USED
ISR(FTM_1_CH_2_CH_3_ISR);
#endif
#ifdef FTM_1_CH_4_CH_5_ISR_USED
ISR(FTM_1_CH_4_CH_5_ISR);
#endif
#ifdef FTM_1_CH_6_CH_7_ISR_USED
ISR(FTM_1_CH_6_CH_7_ISR);
#endif
#ifdef FTM_2_CH_0_CH_1_ISR_USED
ISR(FTM_2_CH_0_CH_1_ISR);
#endif
#ifdef FTM_2_CH_2_CH_3_ISR_USED
ISR(FTM_2_CH_2_CH_3_ISR);
#endif
#ifdef FTM_2_CH_4_CH_5_ISR_USED
ISR(FTM_2_CH_4_CH_5_ISR);
#endif
#ifdef FTM_2_CH_6_CH_7_ISR_USED
ISR(FTM_2_CH_6_CH_7_ISR);
#endif
#ifdef FTM_3_CH_0_CH_1_ISR_USED
ISR(FTM_3_CH_0_CH_1_ISR);
#endif
#ifdef FTM_3_CH_2_CH_3_ISR_USED
ISR(FTM_3_CH_2_CH_3_ISR);
#endif
#ifdef FTM_3_CH_4_CH_5_ISR_USED
ISR(FTM_3_CH_4_CH_5_ISR);
#endif
#ifdef FTM_3_CH_6_CH_7_ISR_USED
ISR(FTM_3_CH_6_CH_7_ISR);
#endif
#ifdef FTM_4_CH_0_CH_1_ISR_USED
ISR(FTM_4_CH_0_CH_1_ISR);
#endif
#ifdef FTM_4_CH_2_CH_3_ISR_USED
ISR(FTM_4_CH_2_CH_3_ISR);
#endif
#ifdef FTM_4_CH_4_CH_5_ISR_USED
ISR(FTM_4_CH_4_CH_5_ISR);
#endif
#ifdef FTM_4_CH_6_CH_7_ISR_USED
ISR(FTM_4_CH_6_CH_7_ISR);
#endif
#ifdef FTM_5_CH_0_CH_1_ISR_USED
ISR(FTM_5_CH_0_CH_1_ISR);
#endif
#ifdef FTM_5_CH_2_CH_3_ISR_USED
ISR(FTM_5_CH_2_CH_3_ISR);
#endif
#ifdef FTM_5_CH_4_CH_5_ISR_USED
ISR(FTM_5_CH_4_CH_5_ISR);
#endif
#ifdef FTM_5_CH_6_CH_7_ISR_USED
ISR(FTM_5_CH_6_CH_7_ISR);
#endif
#ifdef FTM_6_CH_0_CH_1_ISR_USED
ISR(FTM_6_CH_0_CH_1_ISR);
#endif
#ifdef FTM_6_CH_2_CH_3_ISR_USED
ISR(FTM_6_CH_2_CH_3_ISR);
#endif
#ifdef FTM_6_CH_4_CH_5_ISR_USED
ISR(FTM_6_CH_4_CH_5_ISR);
#endif
#ifdef FTM_6_CH_6_CH_7_ISR_USED
ISR(FTM_6_CH_6_CH_7_ISR);
#endif
#ifdef FTM_7_CH_0_CH_1_ISR_USED
ISR(FTM_7_CH_0_CH_1_ISR);
#endif
#ifdef FTM_7_CH_2_CH_3_ISR_USED
ISR(FTM_7_CH_2_CH_3_ISR);
#endif
#ifdef FTM_7_CH_4_CH_5_ISR_USED
ISR(FTM_7_CH_4_CH_5_ISR);
#endif
#ifdef FTM_7_CH_6_CH_7_ISR_USED
ISR(FTM_7_CH_6_CH_7_ISR);
#endif
#endif /*FTM_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON*/
#if ((defined FTM_0_ISR_USED) || (defined FTM_1_ISR_USED) || \
     (defined FTM_0_CH_0_CH_1_ISR_USED) || (defined FTM_0_CH_2_CH_3_ISR_USED) || (defined FTM_0_CH_4_CH_5_ISR_USED) || \
     (defined FTM_0_CH_6_CH_7_ISR_USED) || (defined FTM_1_CH_0_CH_1_ISR_USED) || (defined FTM_1_CH_2_CH_3_ISR_USED) || \
     (defined FTM_1_CH_4_CH_5_ISR_USED) || (defined FTM_1_CH_6_CH_7_ISR_USED) || (defined FTM_2_CH_0_CH_1_ISR_USED) || \
     (defined FTM_2_CH_2_CH_3_ISR_USED) || (defined FTM_2_CH_4_CH_5_ISR_USED) || (defined FTM_2_CH_6_CH_7_ISR_USED) || \
     (defined FTM_3_CH_0_CH_1_ISR_USED) || (defined FTM_3_CH_2_CH_3_ISR_USED) || (defined FTM_3_CH_4_CH_5_ISR_USED) || \
     (defined FTM_3_CH_6_CH_7_ISR_USED) || (defined FTM_4_CH_0_CH_1_ISR_USED) || (defined FTM_4_CH_2_CH_3_ISR_USED) || \
     (defined FTM_4_CH_4_CH_5_ISR_USED) || (defined FTM_4_CH_6_CH_7_ISR_USED) || (defined FTM_5_CH_0_CH_1_ISR_USED) || \
     (defined FTM_5_CH_2_CH_3_ISR_USED) || (defined FTM_5_CH_4_CH_5_ISR_USED) || (defined FTM_5_CH_6_CH_7_ISR_USED) || \
     (defined FTM_6_CH_0_CH_1_ISR_USED) || (defined FTM_6_CH_2_CH_3_ISR_USED) || (defined FTM_6_CH_4_CH_5_ISR_USED) || \
     (defined FTM_6_CH_6_CH_7_ISR_USED) || (defined FTM_7_CH_0_CH_1_ISR_USED) || (defined FTM_7_CH_2_CH_3_ISR_USED) || \
     (defined FTM_7_CH_4_CH_5_ISR_USED) || (defined FTM_7_CH_6_CH_7_ISR_USED))
static void Ftm_Gpt_Ip_ProcessCommonInterrupt(uint8 instance, uint8 channel);
#endif

#if ((defined(MCAL_FTM_REG_PROT_AVAILABLE) && (STD_ON == MCAL_FTM_REG_PROT_AVAILABLE)) && (STD_ON == FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT))
    void Ftm_Gpt_Ip_SetUserAccessAllowed(uint32 FtmBaseAddr);
#endif

#if ((defined(MCAL_FTM_REG_PROT_AVAILABLE) && (STD_ON == MCAL_FTM_REG_PROT_AVAILABLE)) && (STD_ON == FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT))
    #define Call_Ftm_Gpt_Ip_SetUserAccessAllowed(BaseAddr) OsIf_Trusted_Call1param(Ftm_Gpt_Ip_SetUserAccessAllowed,(BaseAddr))
#else
    #define Call_Ftm_Gpt_Ip_SetUserAccessAllowed(BaseAddr)
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if ((defined(MCAL_FTM_REG_PROT_AVAILABLE) && (STD_ON == MCAL_FTM_REG_PROT_AVAILABLE)) && (STD_ON == FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief        Enables FTM registers writing in User Mode by configuring REG_PROT
 * @details      Sets the UAA (User Access Allowed) bit of the FTM IP allowing FTM registers writing in User Mode
 *
 * @param[in]    FtmBaseAddr
 *
 * @return       none
 *
 * @pre          Should be executed in supervisor mode
 */
void Ftm_Gpt_Ip_SetUserAccessAllowed(uint32 FtmBaseAddr)
{
    SET_USER_ACCESS_ALLOWED(FtmBaseAddr, FTM_PROT_MEM_U32);
}
#endif
/*================================================================================================*/
/**
 * @brief
 * Function Name : Ftm_Gpt_Ip_SetFreezeBits
 * Description   : Set BDMMODE[1:0]:    7-6 bits in Configuration (CONF) register
 *      BDMMODE: Selects the FTM behavior in Debug mode. See Debug mode.
 *          BDMMODE     FTM Channels Output
 *            00            Functional mode
 *            01            The channels outputs are forced to their safe value according to POLn bit
 *            10            The channels outputs are frozen when the chip enters in Debug mode
 *            11            Functional mode
 *
 * @param[in]   instance    FTM hardware instance number
 * @param[in]   freezeBits  true or false
 *
 * @return      void
 *
 */
static inline void Ftm_Gpt_Ip_SetFreezeBits(uint8 instance, boolean freezeBits)
{
    uint32 freezeVal = (TRUE == freezeBits) ? 0UL : 3UL;
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17();
    ftmGptBase[instance]->CONF = (ftmGptBase[instance]->CONF & ~FTM_CONF_BDMMODE_MASK) | FTM_CONF_BDMMODE(freezeVal);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17();
}
/*================================================================================================*/
/**
* @brief
* Function Name : Ftm_Gpt_Ip_SetCounterInitVal
* Description   : Set the CounterInitVal
*
* @param[in]     instance       FTM hardware instance number
* @param[in]     value
*
* @return        void
*
*/
static inline void Ftm_Gpt_Ip_SetCounterInitVal(uint8 instance, uint16 value)
{
    ftmGptBase[instance]->CNTIN = (uint32)(((uint32)value << FTM_CNTIN_INIT_SHIFT) & FTM_CNTIN_INIT_MASK);
}
/*================================================================================================*/
/**
* @brief
* Function Name : Ftm_Gpt_Ip_SetCounter
* Description   : Set the Ftm_Gpt_Ip_SetCounter
*
* @param[in]     instance       FTM hardware instance number
* @param[in]     value
*
* @return        void
*
*/
static inline void Ftm_Gpt_Ip_SetCounter(uint8 instance, uint16 value)
{
    ftmGptBase[instance]->CNT = (uint32)(((uint32)value << FTM_CNT_COUNT_SHIFT) & FTM_CNT_COUNT_MASK);
}
/*================================================================================================*/
/**
 * @brief
 * Function Name : Ftm_Gpt_Ip_ClearChInterruptStatusFlag
 * Description   : Clear the CHF bit from CSC - Channel (n) Status and Control Register (C0SC - C7SC)
 *
 * @details Channel (n) Flag (CHF)
 *          CHF is cleared by reading the CnSC register while CHF is set and then writing a 0 to the CHF bit. Writing a 1 to CHF has no effect.
 *          If another event occurs between the read and write operations, the write operation has no effect; therefore,
 *          CHF remains set indicating an event has occurred. In this case a CHF interrupt request is not lost due to the
 *          clearing sequence for a previous CHF.
 *
 * @param[in]   instance    FTM hw instance number
 * @param[in]   channel     FTM hw channel number
 *
 * @return      void
 * @pre         The driver needs to be initialized.
 */
static inline void Ftm_Gpt_Ip_ClearChInterruptStatusFlag(uint8 instance, uint8 channel)
{
    ftmGptBase[instance]-> CONTROLS[channel].CSC &= ~(FTM_CSC_CHF_MASK);
}

/*================================================================================================*/
/**
 * @brief
 * Function Name : Ftm_Gpt_Ip_SetChannelEnableInterrupt
 * Description   : Set or Clear the CHIE bit from CSC - Channel (n) Status and Control Register (C0SC - C7SC)
 *
 * @param[in]   instance    FTM hw instance number
 * @param[in]   channel     FTM hw channel number
 * @param[in]   aboEn - Enables the FTM channel(n) interrupt
 *              - True : Enable the FTM channel(n) interrupt.
 *              - False: Disable the FTM channel(n) interrupt.
 */
static inline void Ftm_Gpt_Ip_SetChannelEnableInterrupt(uint8 instance, uint8 channel, boolean aboEn)
{
    ftmGptBase[instance]-> CONTROLS[channel].CSC = (ftmGptBase[instance]-> CONTROLS[channel].CSC & ~(FTM_CSC_CHIE_MASK)) | FTM_CSC_CHIE((TRUE == aboEn) ? 1UL : 0UL);
}

/*================================================================================================*/
/**
 * @brief
 * Function Name : Ftm_Gpt_Ip_SetClockSource
 * Description   : Set CLKS[1:0]:    4-3 bits in Status And Control (SC) register
 *      CLKS: Clock Source Selection
 *          Selects one of the three FTM counter clock sources.
 *          This field is write protected. It can be written only when MODE[WPDIS] = 1.
 *              00b - No clock selected. This in effect disables the FTM counter.
 *              01b - FTM input clock
 *              10b - Fixed frequency clock
 *              11b - External clock
 * @param[in]       instance    FTM hardware instance number
 *
 * @return      void
 */
static inline void Ftm_Gpt_Ip_SetClockSource(uint8 instance, Ftm_Gpt_Ip_ClockSource clocksource)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_21();
    ftmGptBase[instance]->SC = (ftmGptBase[instance]->SC & ~FTM_SC_CLKS_MASK) | FTM_SC_CLKS(clocksource);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_21();
}

/*================================================================================================*/
/**
 * @brief
 * Function Name : Ftm_Gpt_Ip_SetPrescaler
 * Description   : Set PS[2:0]:    2-0 bits in Status And Control (SC) register
 *      PS: Prescale Factor Selection
 *          Selects one of 8 division factors for the clock source selected by CLKS. The new prescaler factor affects the
 *          clock source on the next FTM input clock cycle after the new value is updated into the register bits.
 *          This field is write protected. It can be written only when MODE[WPDIS] = 1.
 *              000b - Divide by 1
 *              001b - Divide by 2
 *              010b - Divide by 4
 *              011b - Divide by 8
 *              100b - Divide by 16
 *              101b - Divide by 32
 *              110b - Divide by 64
 *              111b - Divide by 128
 * @param[in]       instance    FTM hardware instance number
 * @param[in]       prescalerValue
 *
 * @return        void
 *
 */
static inline void Ftm_Gpt_Ip_SetPrescaler(uint8 instance, uint8 prescalerValue)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_22();
    ftmGptBase[instance]->SC = (ftmGptBase[instance]->SC & ~FTM_SC_PS_MASK) | FTM_SC_PS(prescalerValue);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_22();
}
/*================================================================================================*/
/**
 * @brief
 * Function Name : Ftm_Gpt_Ip_SetEnFtmModule
 * Description   : Set FTMEN - bit 0 in Features Mode Selection (MODE) register
 *      FTMEN - FTM Enable
 *      This field is write protected. It can be written only when MODE[WPDIS] = 1.
 *          0b - TPM compatibility. Free running counter and synchronization compatible with TPM.
 *          1b - Free running counter and synchronization are different from TPM behavior.
 *
 * @param[in]   instance    FTM hardware instance number
 * @param[in]   enable
 *
 * @return      void
 */
static inline void Ftm_Gpt_Ip_SetEnFtmModule(uint8 instance, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_23();
    {
        ftmGptBase[instance]->MODE &= ~(FTM_MODE_FTMEN_MASK);
        ftmGptBase[instance]->MODE |= FTM_MODE_FTMEN(enable ? 1UL : 0UL);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_23();
}
/*================================================================================================*/
/**
* @brief
* Function Name : Ftm_Gpt_Ip_SetCompareValue
* Description   : Set compare value (CV)
*
* @param[in]     instance       FTM hardware instance number
* @param[in]     channel
* @param[in]     value
*
* @return        void
*
*/
static inline void Ftm_Gpt_Ip_SetCompareValue(uint8 instance, uint8 channel, uint32 value)
{
    ftmGptBase[instance]-> CONTROLS[channel].CV = (uint32)((((uint32)value << FTM_CV_VAL_SHIFT) & FTM_CV_VAL_MASK));

}
/*================================================================================================*/
/**
* @brief
* Function Name : Ftm_Gpt_Ip_WriteModulo
* Description   : Set value (MOD)
*
* @param[in]     instance       FTM hardware instance number
* @param[in]     channel
* @param[in]     value
*
* @return        void
*
*/
static inline void Ftm_Gpt_Ip_WriteModulo(uint8 instance, uint16 value)
{
    ftmGptBase[instance]-> MOD = value;

}
/*================================================================================================*/
/**
* @brief
* Function Name : Ftm_Gpt_Ip_ModeSelectA
* Description   : Select mode MSA
*
* @param[in]     instance       FTM hardware instance number
* @param[in]     channel        FTM hardware channel number
* @param[in]     enable
*
* @return        void
*
*/
static inline void Ftm_Gpt_Ip_ModeSelectA(uint8 instance, uint8 channel, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_24();
    if (TRUE == enable)
    {
        ftmGptBase[instance]->CONTROLS[channel].CSC |= FTM_CSC_MSA_MASK;
    }
    else
    {
        ftmGptBase[instance]->CONTROLS[channel].CSC &= (~(FTM_CSC_MSA_MASK));
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_24();
}
/*================================================================================================*/
/**
* @brief
* Function Name : Ftm_Gpt_Ip_SetHalfCycleValue
* Description   : Ftm_Gpt_Ip_SetHalfCycleValue
*
* @param[in]     value
*
* @return        void
*
*/
static inline void Ftm_Gpt_Ip_SetHalfCycleValue(FTM_Type * const base, uint16 value)
{
    ((base)->HCR) = value;
}
/*================================================================================================*/
#if ((defined FTM_0_ISR_USED) || (defined FTM_1_ISR_USED) || \
     (defined FTM_0_CH_0_CH_1_ISR_USED) || (defined FTM_0_CH_2_CH_3_ISR_USED) || (defined FTM_0_CH_4_CH_5_ISR_USED) || \
     (defined FTM_0_CH_6_CH_7_ISR_USED) || (defined FTM_1_CH_0_CH_1_ISR_USED) || (defined FTM_1_CH_2_CH_3_ISR_USED) || \
     (defined FTM_1_CH_4_CH_5_ISR_USED) || (defined FTM_1_CH_6_CH_7_ISR_USED) || (defined FTM_2_CH_0_CH_1_ISR_USED) || \
     (defined FTM_2_CH_2_CH_3_ISR_USED) || (defined FTM_2_CH_4_CH_5_ISR_USED) || (defined FTM_2_CH_6_CH_7_ISR_USED) || \
     (defined FTM_3_CH_0_CH_1_ISR_USED) || (defined FTM_3_CH_2_CH_3_ISR_USED) || (defined FTM_3_CH_4_CH_5_ISR_USED) || \
     (defined FTM_3_CH_6_CH_7_ISR_USED) || (defined FTM_4_CH_0_CH_1_ISR_USED) || (defined FTM_4_CH_2_CH_3_ISR_USED) || \
     (defined FTM_4_CH_4_CH_5_ISR_USED) || (defined FTM_4_CH_6_CH_7_ISR_USED) || (defined FTM_5_CH_0_CH_1_ISR_USED) || \
     (defined FTM_5_CH_2_CH_3_ISR_USED) || (defined FTM_5_CH_4_CH_5_ISR_USED) || (defined FTM_5_CH_6_CH_7_ISR_USED) || \
     (defined FTM_6_CH_0_CH_1_ISR_USED) || (defined FTM_6_CH_2_CH_3_ISR_USED) || (defined FTM_6_CH_4_CH_5_ISR_USED) || \
     (defined FTM_6_CH_6_CH_7_ISR_USED) || (defined FTM_7_CH_0_CH_1_ISR_USED) || (defined FTM_7_CH_2_CH_3_ISR_USED) || \
     (defined FTM_7_CH_4_CH_5_ISR_USED) || (defined FTM_7_CH_6_CH_7_ISR_USED))
/**
 * @brief
 * Function Name : Ftm_Gpt_Ip_GetChInterruptEnableFlag
 * Description   : Get the status of CHIE bit from CSC - Channel (n) Status and Control Register (C0SC - C7SC)
 *
 * @details Channel (n) Interrupt Enable flag (CHIE)
 *          Enables channel (n) interrupt.
 *              0b - Disable channel (n) interrupt. Use software polling.
 *              1b - Enable channel (n) interrupt.
 *
 * @param[in]   instance    FTM hw instance number
 * @param[in]   channel     FTM hw channel number
 *
 * @return  TRUE if a channel (n) event has occurred, FALSE otherwise
 * @pre     The driver needs to be initialized.
 */
static inline boolean Ftm_Gpt_Ip_GetChInterruptEnableFlag(uint8 instance, uint8 channel)
{
    return (0U != (ftmGptBase[instance]->CONTROLS[channel].CSC & FTM_CSC_CHIE_MASK)) ? TRUE : FALSE;
}
#endif

/*================================================================================================*/
#if ((defined FTM_0_ISR_USED) || (defined FTM_1_ISR_USED) || \
     (defined FTM_0_CH_0_CH_1_ISR_USED) || (defined FTM_0_CH_2_CH_3_ISR_USED) || (defined FTM_0_CH_4_CH_5_ISR_USED) || \
     (defined FTM_0_CH_6_CH_7_ISR_USED) || (defined FTM_1_CH_0_CH_1_ISR_USED) || (defined FTM_1_CH_2_CH_3_ISR_USED) || \
     (defined FTM_1_CH_4_CH_5_ISR_USED) || (defined FTM_1_CH_6_CH_7_ISR_USED) || (defined FTM_2_CH_0_CH_1_ISR_USED) || \
     (defined FTM_2_CH_2_CH_3_ISR_USED) || (defined FTM_2_CH_4_CH_5_ISR_USED) || (defined FTM_2_CH_6_CH_7_ISR_USED) || \
     (defined FTM_3_CH_0_CH_1_ISR_USED) || (defined FTM_3_CH_2_CH_3_ISR_USED) || (defined FTM_3_CH_4_CH_5_ISR_USED) || \
     (defined FTM_3_CH_6_CH_7_ISR_USED) || (defined FTM_4_CH_0_CH_1_ISR_USED) || (defined FTM_4_CH_2_CH_3_ISR_USED) || \
     (defined FTM_4_CH_4_CH_5_ISR_USED) || (defined FTM_4_CH_6_CH_7_ISR_USED) || (defined FTM_5_CH_0_CH_1_ISR_USED) || \
     (defined FTM_5_CH_2_CH_3_ISR_USED) || (defined FTM_5_CH_4_CH_5_ISR_USED) || (defined FTM_5_CH_6_CH_7_ISR_USED) || \
     (defined FTM_6_CH_0_CH_1_ISR_USED) || (defined FTM_6_CH_2_CH_3_ISR_USED) || (defined FTM_6_CH_4_CH_5_ISR_USED) || \
     (defined FTM_6_CH_6_CH_7_ISR_USED) || (defined FTM_7_CH_0_CH_1_ISR_USED) || (defined FTM_7_CH_2_CH_3_ISR_USED) || \
     (defined FTM_7_CH_4_CH_5_ISR_USED) || (defined FTM_7_CH_6_CH_7_ISR_USED))
/**
 * @brief
 * Function Name : Ftm_Gpt_Ip_GetChannelEventStatus
 * Description   : Get the status of CHF bit from STATUS register
 *
 * @details The STATUS register contains a copy of the status flag CHF bit in CnSC for each FTM channel for software convenience.
 *          Each CHF bit in STATUS is a mirror of CHF bit in CnSC. All CHF bits can be checked using only one read of STATUS. All CHF
 *          bits can be cleared by reading STATUS followed by writing 0x00 to STATUS.
 *          Hardware sets the individual channel flags when an event occurs on the channel. CHF is cleared by reading STATUS while CHF
 *          is set and then writing a 0 to the CHF bit. Writing a 1 to CHF has no effect.
 *          If another event occurs between the read and write operations, the write operation has no effect; therefore, CHF remains set
 *          indicating an event has occurred. In this case, a CHF interrupt request is not lost due to the clearing sequence for a previous CHF.
 *
 * @param[in]   instance    FTM hw instance number
 * @param[in]   channel     FTM hw channel number
 *
 * @return Channel event status
 *         - True : A channel event has occurred
 *         - False: No channel event has occurred
 *
 */
static inline boolean Ftm_Gpt_Ip_GetChannelEventStatus(uint8 instance, uint8 channel)
{
    return (0U != (ftmGptBase[instance]->STATUS & (1UL << channel))) ? TRUE : FALSE;
}
#endif

/*================================================================================================*/
#if ((defined FTM_0_ISR_USED) || (defined FTM_1_ISR_USED) || \
     (defined FTM_0_CH_0_CH_1_ISR_USED) || (defined FTM_0_CH_2_CH_3_ISR_USED) || (defined FTM_0_CH_4_CH_5_ISR_USED) || \
     (defined FTM_0_CH_6_CH_7_ISR_USED) || (defined FTM_1_CH_0_CH_1_ISR_USED) || (defined FTM_1_CH_2_CH_3_ISR_USED) || \
     (defined FTM_1_CH_4_CH_5_ISR_USED) || (defined FTM_1_CH_6_CH_7_ISR_USED) || (defined FTM_2_CH_0_CH_1_ISR_USED) || \
     (defined FTM_2_CH_2_CH_3_ISR_USED) || (defined FTM_2_CH_4_CH_5_ISR_USED) || (defined FTM_2_CH_6_CH_7_ISR_USED) || \
     (defined FTM_3_CH_0_CH_1_ISR_USED) || (defined FTM_3_CH_2_CH_3_ISR_USED) || (defined FTM_3_CH_4_CH_5_ISR_USED) || \
     (defined FTM_3_CH_6_CH_7_ISR_USED) || (defined FTM_4_CH_0_CH_1_ISR_USED) || (defined FTM_4_CH_2_CH_3_ISR_USED) || \
     (defined FTM_4_CH_4_CH_5_ISR_USED) || (defined FTM_4_CH_6_CH_7_ISR_USED) || (defined FTM_5_CH_0_CH_1_ISR_USED) || \
     (defined FTM_5_CH_2_CH_3_ISR_USED) || (defined FTM_5_CH_4_CH_5_ISR_USED) || (defined FTM_5_CH_6_CH_7_ISR_USED) || \
     (defined FTM_6_CH_0_CH_1_ISR_USED) || (defined FTM_6_CH_2_CH_3_ISR_USED) || (defined FTM_6_CH_4_CH_5_ISR_USED) || \
     (defined FTM_6_CH_6_CH_7_ISR_USED) || (defined FTM_7_CH_0_CH_1_ISR_USED) || (defined FTM_7_CH_2_CH_3_ISR_USED) || \
     (defined FTM_7_CH_4_CH_5_ISR_USED) || (defined FTM_7_CH_6_CH_7_ISR_USED))
/**
* @brief   Driver routine to process all the interrupts of FTM.
* @details Support function used by interrupt service routines to implement FTM specific operations
*          and call the upper layer handler to implement non-hardware specific operations.
*
* @param[in]     instance     FTM hardware instance number
* @param[in]     channel      FTM hardware channel number
* @implements    Ftm_Gpt_Ip_ProcessCommonInterrupt_Activity
*/
static void Ftm_Gpt_Ip_ProcessCommonInterrupt(uint8 instance, uint8 channel)
{
    boolean HasChEvOccurred;
    boolean IsChEvEnabled;
    boolean                     chInit;
    Ftm_Gpt_Ip_CallbackType     callback;
    uint8                       callbackParam;
    Ftm_Gpt_Ip_ChannelModeType  channelMode;

    uint32 targetValue;
    uint32 oldCmpValue = Ftm_Gpt_Ip_GetCompareValue(instance, channel);

    if ((instance < FTM_INSTANCE_COUNT) && (channel < FTM_CONTROLS_COUNT))
    {
        /* enter critical section */
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_25();
        {
            /* check if channel event is enabled */
            IsChEvEnabled = Ftm_Gpt_Ip_GetChInterruptEnableFlag(instance, channel);

            /* check if channel event has occurred */
            HasChEvOccurred = Ftm_Gpt_Ip_GetChInterruptStatusFlag(instance, channel);

            /* Check for spurious interrupts */
            if (HasChEvOccurred && IsChEvEnabled)
            {
                /* Clear interrupt flag */
                Ftm_Gpt_Ip_ClearChInterruptStatusFlag(instance, channel);
            }
        }
        /* exit critical section */
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_25();

        if (HasChEvOccurred && IsChEvEnabled)
        {
            chInit          = Ftm_Gpt_Ip_u32ChState[instance][channel].chInit;
            callback        = Ftm_Gpt_Ip_u32ChState[instance][channel].callback;
            callbackParam   = Ftm_Gpt_Ip_u32ChState[instance][channel].callbackParam;

            /* Call GPT upper layer handler */
            if ((TRUE == chInit) && (NULL_PTR != callback))
            {
                callback(callbackParam);
            }

#if (FTM_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
            if(Ftm_Gpt_Ip_u32NextTargetValue[instance][channel] != 0x0U)
            {
                Ftm_Gpt_Ip_u32TargetValue[instance][channel] = Ftm_Gpt_Ip_u32NextTargetValue[instance][channel];
                Ftm_Gpt_Ip_u32NextTargetValue[instance][channel] = 0x0U;
            }
#endif
            /* Check if channel mode is ONE-SHOT */
            channelMode = Ftm_Gpt_Ip_u32ChState[instance][channel].channelMode;
            if(FTM_GPT_IP_CH_MODE_ONESHOT == channelMode)
            {
                Ftm_Gpt_Ip_DisableChannelInterrupt(instance, channel);
            }
            else
            {
                targetValue = Ftm_Gpt_Ip_u32TargetValue[instance][channel];
                if ((uint32)(oldCmpValue + targetValue) > FTM_CNT_MAX_VALUE)
                {
                    Ftm_Gpt_Ip_SetCompareValue(instance, channel, (uint32)(targetValue - (FTM_CNT_MAX_VALUE - oldCmpValue)));
                }
                else
                {
                    /* Set new CMP value */
                    Ftm_Gpt_Ip_SetCompareValue(instance, channel, (uint32)(oldCmpValue + targetValue));
                }
            }
        }
    }
}

#endif

/*================================================================================================*/
/**
* @brief         Function Name : Ftm_Gpt_Ip_Init
* @details       Initializes the FTM instance. This functions is called for each FTM hardware Instance and:
*
* @param[in]     instance     FTM hardware instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Ftm_Gpt_Ip_Init_Activity
*/
void Ftm_Gpt_Ip_Init(uint8 instance, const Ftm_Gpt_Ip_InstanceConfigType *configPtr)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(FTM_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != configPtr);
#endif
    /* Enable register access from user mode, if enabled from configuration file */
    Call_Ftm_Gpt_Ip_SetUserAccessAllowed((uint32)ftmGptBase[instance]);

    /* Check the FTM counter modes */
    if (FTM_GPT_IP_MODE_UP_TIMER == configPtr->mode)
    {
        /* Set clock and prescalerValue FTM */
        Ftm_Gpt_Ip_SetPrescaler(instance, configPtr->clockPrescaler);
        /* Set FTM counter clock source */
        Ftm_Gpt_Ip_SetClockSource(instance, configPtr->clocksource);

        /* Set freeze bits */
        Ftm_Gpt_Ip_SetFreezeBits(instance, configPtr->freezeBits);

        /*Set Counter register and Initial Counter Value*/
        Ftm_Gpt_Ip_SetCounterInitVal(instance, 1U);

        /* write the Ftm Modulo Register with 0xFFFF */
        Ftm_Gpt_Ip_WriteModulo(instance, 0xFFFFU);

        /* set FTM Enable bit */
        Ftm_Gpt_Ip_SetEnFtmModule(instance, TRUE);
    }
    else
    {
        /* TODO: DO NOTHING */
    }
#if (FTM_GPT_IP_SET_CLOCK_MODE == STD_ON)
    Ftm_Gpt_Ip_u32InstancePrescaler[instance].clockPrescaler = configPtr->clockPrescaler;
    Ftm_Gpt_Ip_u32InstancePrescaler[instance].clockAlternatePrescaler = configPtr->clockAlternatePrescaler;
#endif
    /* set FTM instance status to initialized */
    Ftm_Gpt_Ip_u32InstanceState[instance] = FTM_GPT_IP_STATUS_INITIALIZED;
}

/*================================================================================================*/
/**
* @brief         Function Name : Ftm_Gpt_Ip_InitChannel
* @details       Initializes the FTM channels. This functions is called for each FTM hardware channel and:
*
* @param[in]     instance     FTM hardware instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Ftm_Gpt_Ip_InitChannel_Activity
*/
void Ftm_Gpt_Ip_InitChannel(uint8 instance, const Ftm_Gpt_Ip_ChannelConfigType *configPtr)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != configPtr);
    DevAssert(FTM_INSTANCE_COUNT > instance);
    DevAssert(FTM_CONTROLS_COUNT > configPtr->hwChannel);
#endif

    /* Disable channels interrupt bit */
    Ftm_Gpt_Ip_SetChannelEnableInterrupt(instance, configPtr->hwChannel, FALSE);
    /* Clear ClearInterruptFlag */
    Ftm_Gpt_Ip_ClearChInterruptStatusFlag(instance, configPtr->hwChannel);
    /* Set Compare Value register to 0xFFFF */
    Ftm_Gpt_Ip_SetCompareValue(instance, configPtr->hwChannel, 0xFFFFU);
    /* Set bit MSA */
    Ftm_Gpt_Ip_ModeSelectA(instance, configPtr->hwChannel, TRUE);
#if ((defined FTM_0_ISR_USED) || (defined FTM_1_ISR_USED) || \
     (defined FTM_0_CH_0_CH_1_ISR_USED) || (defined FTM_0_CH_2_CH_3_ISR_USED) || (defined FTM_0_CH_4_CH_5_ISR_USED) || \
     (defined FTM_0_CH_6_CH_7_ISR_USED) || (defined FTM_1_CH_0_CH_1_ISR_USED) || (defined FTM_1_CH_2_CH_3_ISR_USED) || \
     (defined FTM_1_CH_4_CH_5_ISR_USED) || (defined FTM_1_CH_6_CH_7_ISR_USED) || (defined FTM_2_CH_0_CH_1_ISR_USED) || \
     (defined FTM_2_CH_2_CH_3_ISR_USED) || (defined FTM_2_CH_4_CH_5_ISR_USED) || (defined FTM_2_CH_6_CH_7_ISR_USED) || \
     (defined FTM_3_CH_0_CH_1_ISR_USED) || (defined FTM_3_CH_2_CH_3_ISR_USED) || (defined FTM_3_CH_4_CH_5_ISR_USED) || \
     (defined FTM_3_CH_6_CH_7_ISR_USED) || (defined FTM_4_CH_0_CH_1_ISR_USED) || (defined FTM_4_CH_2_CH_3_ISR_USED) || \
     (defined FTM_4_CH_4_CH_5_ISR_USED) || (defined FTM_4_CH_6_CH_7_ISR_USED) || (defined FTM_5_CH_0_CH_1_ISR_USED) || \
     (defined FTM_5_CH_2_CH_3_ISR_USED) || (defined FTM_5_CH_4_CH_5_ISR_USED) || (defined FTM_5_CH_6_CH_7_ISR_USED) || \
     (defined FTM_6_CH_0_CH_1_ISR_USED) || (defined FTM_6_CH_2_CH_3_ISR_USED) || (defined FTM_6_CH_4_CH_5_ISR_USED) || \
     (defined FTM_6_CH_6_CH_7_ISR_USED) || (defined FTM_7_CH_0_CH_1_ISR_USED) || (defined FTM_7_CH_2_CH_3_ISR_USED) || \
     (defined FTM_7_CH_4_CH_5_ISR_USED) || (defined FTM_7_CH_6_CH_7_ISR_USED))
    Ftm_Gpt_Ip_u32ChState[instance][configPtr->hwChannel].chInit = TRUE;
    Ftm_Gpt_Ip_u32ChState[instance][configPtr->hwChannel].callback = configPtr->callback;
    Ftm_Gpt_Ip_u32ChState[instance][configPtr->hwChannel].callbackParam = configPtr->callbackParam;
    Ftm_Gpt_Ip_u32ChState[instance][configPtr->hwChannel].channelMode = configPtr->channelMode;
#endif
}

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
* @implements    Ftm_Gpt_Ip_Deinit_Activity
*/
void Ftm_Gpt_Ip_Deinit(uint8 instance)
{
    #if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(FTM_INSTANCE_COUNT > instance);
    #endif

    uint8 channelIndex;

    /* Reset all channels to default */
    for (channelIndex = 0; channelIndex < FTM_CONTROLS_COUNT; channelIndex++)
    {
        /* Disable interrupts */
        Ftm_Gpt_Ip_SetChannelEnableInterrupt(instance, channelIndex, FALSE );
        /*Clear interrupt flags*/
        Ftm_Gpt_Ip_ClearChInterruptStatusFlag(instance, channelIndex);
    }
    /* Set clock source as 'No clock'. This in effect disables the FTM counter */
    Ftm_Gpt_Ip_SetClockSource(instance, FTM_GPT_IP_CLOCK_SOURCE_NONE);
    /* clear FTM Enable bit */
    Ftm_Gpt_Ip_SetEnFtmModule(instance, FALSE);
    /* clearde freeze bits */
    Ftm_Gpt_Ip_SetFreezeBits(instance, FALSE);
    /* Set Counter register to 0 and Initial Counter Value to 0 */
    Ftm_Gpt_Ip_SetCounterInitVal(instance, 0U);
    Ftm_Gpt_Ip_SetCounter(instance, 0U);
    /* set FTM instance status to uninitialized */
    Ftm_Gpt_Ip_u32InstanceState[instance] = FTM_GPT_IP_STATUS_UNINITIALIZED;
}

/*================================================================================================*/
/**
* @brief        Function Name : Ftm_Gpt_Ip_StartCounting
* @details      This function is called for starting the Ftm timer channel
*
* @param[in]     instance        FTM hardware instance
* @param[in]     channel         FTM hardware channel
* @param[in]     compareValue    Compare value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the FTM timer channel.
* @implements    Ftm_Gpt_Ip_StartCounting_Activity
*/
void Ftm_Gpt_Ip_StartCounting(uint8 instance, uint8 channel, uint16 compareValue)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(FTM_INSTANCE_COUNT > instance);
    DevAssert(FTM_CONTROLS_COUNT > channel);
#endif
    uint32 counterValue;
    uint32 currentCntValue = Ftm_Gpt_Ip_GetCntValue(instance);

    if ((uint32)(currentCntValue + compareValue) > FTM_CNT_MAX_VALUE)
    {
        counterValue = (uint32)(compareValue - (FTM_CNT_MAX_VALUE - currentCntValue));
    }
    else
    {
        counterValue = (uint32)(currentCntValue + compareValue);
    }
    /* Set new compare value */
    Ftm_Gpt_Ip_SetCompareValue(instance, channel, counterValue);
    /* Save compare value */
    Ftm_Gpt_Ip_u32TargetValue[instance][channel] = compareValue;
    /* Clear CHF flag */
    Ftm_Gpt_Ip_ClearChInterruptStatusFlag(instance,channel);
    /* Enable interrupt */
    Ftm_Gpt_Ip_SetChannelEnableInterrupt(instance, channel, TRUE);

}

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
* @implements    Ftm_Gpt_Ip_StartCountingAbsolute_Activity
*/
void Ftm_Gpt_Ip_StartCountingAbsolute(uint8 instance, uint8 channel, uint16 compareValue)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(FTM_INSTANCE_COUNT > instance);
    DevAssert(FTM_CONTROLS_COUNT > channel);
#endif

    Ftm_Gpt_Ip_u32TargetValue[instance][channel] = 0U;
    /* Set new compare value */
    Ftm_Gpt_Ip_SetCompareValue(instance, channel, compareValue);
    /* Clear CHF flag */
    Ftm_Gpt_Ip_ClearChInterruptStatusFlag(instance,channel);
    /* Enable interrupt */
    Ftm_Gpt_Ip_SetChannelEnableInterrupt(instance, channel, TRUE);

}
#endif

/*================================================================================================*/
/**
 * @brief       Function Name : Ftm_Gpt_Ip_StartTimer
 * @details     This function is called for setting a new start counter value and enables the FTM counter and
 *                  - sets the new counter value
 *                  - enables the FTM counter
 * @pre           The driver needs to be initialized.
 * @implements    Ftm_Gpt_Ip_StartTimer_Activity
 */
void Ftm_Gpt_Ip_StartTimer(uint8 instance, uint16 counterValue)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(FTM_INSTANCE_COUNT > instance);
#endif
    if (instance < FTM_INSTANCE_COUNT)
    {
        if (FTM_GPT_IP_STATUS_INITIALIZED == Ftm_Gpt_Ip_u32InstanceState[instance])
        {
            /* Set the new value counter */
            Ftm_Gpt_Ip_SetCounterInitVal(instance, counterValue);
            /* set FTM Enable bit */
            Ftm_Gpt_Ip_SetEnFtmModule(instance, TRUE);
        }
    }
}

/*================================================================================================*/
/**
* @brief        Function Name : Ftm_Gpt_Ip_StopTimer
* @details      This function is callded for stopping the Ftm counter.
*                   - disables the FTM counter
*
* @param[in]     instance        FTM hardware instance
* @return        void
* @pre           The driver needs to be initialized. This function is called for stoping the FTM timer channel.
* @implements    Ftm_Gpt_Ip_StopTimer_Activity
*/
void Ftm_Gpt_Ip_StopTimer(uint8 instance)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
DevAssert(FTM_INSTANCE_COUNT > instance);
#endif
    /* clear FTM Enable bit */
    Ftm_Gpt_Ip_SetEnFtmModule(instance, FALSE);
    /* Set clock source as 'No clock'. This in effect disables the FTM counter */
    Ftm_Gpt_Ip_SetClockSource(instance, FTM_GPT_IP_CLOCK_SOURCE_NONE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Ftm_Gpt_Ip_EnableChannelInterrupt
* @details      This function allows enabling interrupt generation of timer channel
*               when time-out occurs
*
* @param[in]    instance        FTM hardware instance
* @param[in]    channel         FTM hardware channel
* @return       void
* @pre          The driver needs to be initialized.
* @implements   Ftm_Gpt_Ip_EnableChannelInterrupt_Activity
*/
void Ftm_Gpt_Ip_EnableChannelInterrupt(uint8 instance, uint8 channel)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
DevAssert(FTM_INSTANCE_COUNT > instance);
DevAssert(FTM_CONTROLS_COUNT > channel);
#endif

     /* Clear interrupt flag */
    Ftm_Gpt_Ip_ClearChInterruptStatusFlag(instance, channel);
    /* Enable channel interrupt */
    Ftm_Gpt_Ip_SetChannelEnableInterrupt(instance, channel, TRUE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Ftm_Gpt_Ip_DisableChannelInterrupt
* @details      This function allows disabling interrupt generation of timer channel
*               when time-out occurs
*
* @param[in]     instance        FTM hardware instance
* @param[in]     channel         FTM hardware channel
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Ftm_Gpt_Ip_DisableChannelInterrupt_Activity
*/
void Ftm_Gpt_Ip_DisableChannelInterrupt(uint8 instance, uint8 channel)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
DevAssert(FTM_INSTANCE_COUNT > instance);
DevAssert(FTM_CONTROLS_COUNT > channel);
#endif

    /* Disable interrupt */
    Ftm_Gpt_Ip_SetChannelEnableInterrupt(instance, channel, FALSE);
    /* Clear interrupt flag */
    Ftm_Gpt_Ip_ClearChInterruptStatusFlag(instance, channel);
}

/*================================================================================================*/
/**
* @brief         Function Name : Ftm_Gpt_Ip_SetHalfCycleReloadPoint
* @details       Configures the value of the counter with half cycle of reload point.
*
* @param[in]     instance                  FTM hardware instance
* @param[in]     reloadPoint               Reload value

* @return
* @pre           The driver needs to be initialized.
* @implements    Ftm_Gpt_Ip_SetHalfCycleReloadPoint_Activity
*/
void Ftm_Gpt_Ip_SetHalfCycleReloadPoint(uint8 instance, uint16 reloadPoint)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
DevAssert(FTM_INSTANCE_COUNT > instance);
#endif
    Ftm_Gpt_Ip_SetHalfCycleValue(ftmGptBase[instance], reloadPoint);
}

#if (FTM_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/*================================================================================================*/
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
* @implements    Ftm_Gpt_Ip_ChangeNextTimeoutValue_Activity
*/
void Ftm_Gpt_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint16 value)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(FTM_INSTANCE_COUNT > instance);
    DevAssert(FTM_CONTROLS_COUNT > channel);
#endif
#if ((defined FTM_0_ISR_USED) || (defined FTM_1_ISR_USED) || \
     (defined FTM_0_CH_0_CH_1_ISR_USED) || (defined FTM_0_CH_2_CH_3_ISR_USED) || (defined FTM_0_CH_4_CH_5_ISR_USED) || \
     (defined FTM_0_CH_6_CH_7_ISR_USED) || (defined FTM_1_CH_0_CH_1_ISR_USED) || (defined FTM_1_CH_2_CH_3_ISR_USED) || \
     (defined FTM_1_CH_4_CH_5_ISR_USED) || (defined FTM_1_CH_6_CH_7_ISR_USED) || (defined FTM_2_CH_0_CH_1_ISR_USED) || \
     (defined FTM_2_CH_2_CH_3_ISR_USED) || (defined FTM_2_CH_4_CH_5_ISR_USED) || (defined FTM_2_CH_6_CH_7_ISR_USED) || \
     (defined FTM_3_CH_0_CH_1_ISR_USED) || (defined FTM_3_CH_2_CH_3_ISR_USED) || (defined FTM_3_CH_4_CH_5_ISR_USED) || \
     (defined FTM_3_CH_6_CH_7_ISR_USED) || (defined FTM_4_CH_0_CH_1_ISR_USED) || (defined FTM_4_CH_2_CH_3_ISR_USED) || \
     (defined FTM_4_CH_4_CH_5_ISR_USED) || (defined FTM_4_CH_6_CH_7_ISR_USED) || (defined FTM_5_CH_0_CH_1_ISR_USED) || \
     (defined FTM_5_CH_2_CH_3_ISR_USED) || (defined FTM_5_CH_4_CH_5_ISR_USED) || (defined FTM_5_CH_6_CH_7_ISR_USED) || \
     (defined FTM_6_CH_0_CH_1_ISR_USED) || (defined FTM_6_CH_2_CH_3_ISR_USED) || (defined FTM_6_CH_4_CH_5_ISR_USED) || \
     (defined FTM_6_CH_6_CH_7_ISR_USED) || (defined FTM_7_CH_0_CH_1_ISR_USED) || (defined FTM_7_CH_2_CH_3_ISR_USED) || \
     (defined FTM_7_CH_4_CH_5_ISR_USED) || (defined FTM_7_CH_6_CH_7_ISR_USED))

    /* Update the target time value to be used on next cycle */
    Ftm_Gpt_Ip_u32NextTargetValue[instance][channel] = (uint32)value;

#endif
}
#endif /*FTM_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE*/

#if (FTM_GPT_IP_SET_CLOCK_MODE == STD_ON)
/*================================================================================================*/
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
void Ftm_Gpt_Ip_SetClockMode(uint8 instance, Ftm_Gpt_Ip_ClockModeType prescalerMode)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(FTM_INSTANCE_COUNT > instance);
#endif

    /* Set Prescaler */
    if(FTM_GPT_IP_CLOCKMODE_NORMAL == prescalerMode)
    {
        Ftm_Gpt_Ip_SetPrescaler(instance, Ftm_Gpt_Ip_u32InstancePrescaler[instance].clockPrescaler);
    }
    else
    {
        Ftm_Gpt_Ip_SetPrescaler(instance, Ftm_Gpt_Ip_u32InstancePrescaler[instance].clockAlternatePrescaler);
    }
}
#endif/*FTM_GPT_IP_SET_CLOCK_MODE*/

#if(FTM_GPT_IP_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
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
void Ftm_Gpt_Ip_StartPredefTimer (uint8 instance,uint8 channel, uint8 uPrescaler, uint8 clocksource, boolean bFreezeEnable)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(FTM_INSTANCE_COUNT > instance);
    DevAssert(FTM_CONTROLS_COUNT > channel);
#endif

    /* Enable register access from user mode, if enabled from configuration file */
    Call_Ftm_Gpt_Ip_SetUserAccessAllowed((uint32)ftmGptBase[instance]);

    /* Disable all interrupts on this channel */
    Ftm_Gpt_Ip_SetChannelEnableInterrupt(instance, channel, FALSE);
    /* Clear interrupt flags */
    Ftm_Gpt_Ip_ClearChInterruptStatusFlag(instance, channel);
    /* Disable TOIE flags */
    ftmGptBase[instance]-> SC &= (~(FTM_SC_TOIE_MASK));
    /* Configure FTM as a Free-Running Timer by setting FTMEN=1, CTNIN=0, MOD=0xFFFF, QUADEN=0, CPWMS=0*/
    Ftm_Gpt_Ip_SetEnFtmModule(instance, TRUE);
    /* Initial Counter Value to 0 */
    Ftm_Gpt_Ip_SetCounterInitVal(instance, 0U);
    /* write the Ftm Modulo Register with 0xFFFF */
    Ftm_Gpt_Ip_WriteModulo(instance, 0xFFFFU);
    /* Set Compare Value register to 0xFFFF */
    Ftm_Gpt_Ip_SetCompareValue(instance, channel, 0xFFFFU);
    /* Enter EA_28*/
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_26();
    /* Clear bit QUADEN */
    ftmGptBase[instance]->QDCTRL &= (~(FTM_QDCTRL_QUADEN_MASK));
    /* Clear bit CPWMS */
    ftmGptBase[instance]->SC &= (~(FTM_SC_CPWMS_MASK));
    /* Exit EA_28*/
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_26();

    /* Configure Predef Timer */
    Ftm_Gpt_Ip_SetPrescaler(instance, uPrescaler);
    /* Set FTM counter clock source */
    Ftm_Gpt_Ip_SetClockSource(instance, (Ftm_Gpt_Ip_ClockSource)clocksource);
    /* Set freeze bits */
    Ftm_Gpt_Ip_SetFreezeBits(instance, bFreezeEnable);
    /* Intialize FTM timer by writing any value to CNT register when CLKS not equal 0 */
    ftmGptBase[instance]->CNT = (uint32)(((uint32)1U << FTM_CNT_COUNT_SHIFT) & FTM_CNT_COUNT_MASK);
}
/*================================================================================================*/
/**
* @brief      The function stops the FTM channel.
* @details    This function stops the FTM channel.
*
* @param[in]  channel      hardware channel
* @param[in]  instance     FTM hardware instance
*
*
* @return     void
* @pre        The driver needs to be initialized
*
*/
void Ftm_Gpt_Ip_StopPredefTimer (uint8 instance, uint8 channel)
{
#if FTM_GPT_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(FTM_INSTANCE_COUNT > instance);
    DevAssert(FTM_CONTROLS_COUNT > channel);
#endif
    /* Set clock source as 'No clock'. This in effect disables the FTM counter */
    Ftm_Gpt_Ip_SetClockSource(instance, FTM_GPT_IP_CLOCK_SOURCE_NONE);
    /* Disable all interrupts on this channel */
    Ftm_Gpt_Ip_SetChannelEnableInterrupt(instance, channel, FALSE);
    /* Clear interrupt flags */
    Ftm_Gpt_Ip_ClearChInterruptStatusFlag(instance, channel);
    /* clear FTM Enable bit */
    Ftm_Gpt_Ip_SetEnFtmModule(instance, FALSE);
    /* Set Counter register to 0 and Initial Counter Value to 0 */
    Ftm_Gpt_Ip_SetCounterInitVal(instance, 0U);
    Ftm_Gpt_Ip_SetCounter(instance, 0U);
    Ftm_Gpt_Ip_SetCompareValue(instance, channel, 0U);
    Ftm_Gpt_Ip_WriteModulo(instance, 0U );
    /* Set bit MSA */
    Ftm_Gpt_Ip_ModeSelectA(instance, channel, FALSE);
}
#endif/* FTM_GPT_IP_PREDEFTIMER_FUNCTIONALITY_API */

/*================================================================================================*/
#if (defined (FTM_GPT_IP_MODULE_SINGLE_INTERRUPT) && (STD_ON == FTM_GPT_IP_MODULE_SINGLE_INTERRUPT))
#ifdef FTM_0_ISR_USED
/**
* @brief   Interrupt handler for FTM channels.
* @details Interrupt Service Routine corresponding to common FTM_0 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(FTM_0_ISR)
{
    uint8 channel;
    uint8 instance = 0U;

    for (channel = 0U; channel < FTM_CONTROLS_COUNT; channel++)
    {
        if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
        {
            Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
        }
    }

    EXIT_INTERRUPT();
}
#endif
/*================================================================================================*/
#ifdef FTM_1_ISR_USED
/**
* @brief   Interrupt handler for FTM channels.
* @details Interrupt Service Routine corresponding to common FTM_1 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(FTM_1_ISR)
{
    uint8 channel;
    uint8 instance = 1U;

    for (channel = 0U; channel < FTM_CONTROLS_COUNT; channel++)
    {
        if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
        {
            Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
        }
    }

    EXIT_INTERRUPT();
}
#endif
#else /*FTM_GPT_IP_MODULE_SINGLE_INTERRUPT*/
/*================================================================================================*/
#if (defined FTM_0_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 0 - channel 1.
 */
ISR(FTM_0_CH_0_CH_1_ISR)
{
    uint8 channel = 0U;
    uint8 instance = 0U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_0_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 2 - channel 3.
 */
ISR(FTM_0_CH_2_CH_3_ISR)
{
    uint8 channel = 2U;
    uint8 instance = 0U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_0_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 4 - channel 5.
 */
ISR(FTM_0_CH_4_CH_5_ISR)
{
    uint8 channel = 4U;
    uint8 instance = 0U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_0_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 6 - channel 7.
 */
ISR(FTM_0_CH_6_CH_7_ISR)
{
    uint8 channel = 6U;
    uint8 instance = 0U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_1_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 0 - channel 1.
 */
ISR(FTM_1_CH_0_CH_1_ISR)
{
    uint8 channel = 0U;
    uint8 instance = 1U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_1_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 2 - channel 3.
 */
ISR(FTM_1_CH_2_CH_3_ISR)
{
    uint8 channel = 2U;
    uint8 instance = 1U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_1_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 4 - channel 5.
 */
ISR(FTM_1_CH_4_CH_5_ISR)
{
    uint8 channel = 4U;
    uint8 instance = 1U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_1_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 6 - channel 7.
 */
ISR(FTM_1_CH_6_CH_7_ISR)
{
    uint8 channel = 6U;
    uint8 instance = 1U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_2_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 0 - channel 1.
 */
ISR(FTM_2_CH_0_CH_1_ISR)
{
    uint8 channel = 0U;
    uint8 instance = 2U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_2_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 2 - channel 3.
 */
ISR(FTM_2_CH_2_CH_3_ISR)
{
    uint8 channel = 2U;
    uint8 instance = 2U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_2_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 4 - channel 5.
 */
ISR(FTM_2_CH_4_CH_5_ISR)
{
    uint8 channel = 4U;
    uint8 instance = 2U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_2_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 6 - channel 7.
 */
ISR(FTM_2_CH_6_CH_7_ISR)
{
    uint8 channel = 6U;
    uint8 instance = 2U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_3_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 0 - channel 1.
 */
ISR(FTM_3_CH_0_CH_1_ISR)
{
    uint8 channel = 0U;
    uint8 instance = 3U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_3_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 2 - channel 3.
 */
ISR(FTM_3_CH_2_CH_3_ISR)
{
    uint8 channel = 2U;
    uint8 instance = 3U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_3_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 4 - channel 5.
 */
ISR(FTM_3_CH_4_CH_5_ISR)
{
    uint8 channel = 4U;
    uint8 instance = 3U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_3_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 6 - channel 7.
 */
ISR(FTM_3_CH_6_CH_7_ISR)
{
    uint8 channel = 6U;
    uint8 instance = 3U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_4_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 0 - channel 1.
 */
ISR(FTM_4_CH_0_CH_1_ISR)
{
    uint8 channel = 0U;
    uint8 instance = 4U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_4_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 2 - channel 3.
 */
ISR(FTM_4_CH_2_CH_3_ISR)
{
    uint8 channel = 2U;
    uint8 instance = 4U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_4_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 4 - channel 5.
 */
ISR(FTM_4_CH_4_CH_5_ISR)
{
    uint8 channel = 4U;
    uint8 instance = 4U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_4_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 6 - channel 7.
 */
ISR(FTM_4_CH_6_CH_7_ISR)
{
    uint8 channel = 6U;
    uint8 instance = 4U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_5_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 0 - channel 1.
 */
ISR(FTM_5_CH_0_CH_1_ISR)
{
    uint8 channel = 0U;
    uint8 instance = 5U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_5_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 2 - channel 3.
 */
ISR(FTM_5_CH_2_CH_3_ISR)
{
    uint8 channel = 2U;
    uint8 instance = 5U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_5_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 4 - channel 5.
 */
ISR(FTM_5_CH_4_CH_5_ISR)
{
    uint8 channel = 4U;
    uint8 instance = 5U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_5_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 6 - channel 7.
 */
ISR(FTM_5_CH_6_CH_7_ISR)
{
    uint8 channel = 6U;
    uint8 instance = 5U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_6_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 0 - channel 1.
 */
ISR(FTM_6_CH_0_CH_1_ISR)
{
    uint8 channel = 0U;
    uint8 instance = 6U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_6_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 2 - channel 3.
 */
ISR(FTM_6_CH_2_CH_3_ISR)
{
    uint8 channel = 2U;
    uint8 instance = 6U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_6_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 4 - channel 5.
 */
ISR(FTM_6_CH_4_CH_5_ISR)
{
    uint8 channel = 4U;
    uint8 instance = 6U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_6_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 6 - channel 7.
 */
ISR(FTM_6_CH_6_CH_7_ISR)
{
    uint8 channel = 6U;
    uint8 instance = 6U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_7_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 0 - channel 1.
 */
ISR(FTM_7_CH_0_CH_1_ISR)
{
    uint8 channel = 0U;
    uint8 instance = 7U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_7_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 2 - channel 3.
 */
ISR(FTM_7_CH_2_CH_3_ISR)
{
    uint8 channel = 2U;
    uint8 instance = 7U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_7_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 4 - channel 5.
 */
ISR(FTM_7_CH_4_CH_5_ISR)
{
    uint8 channel = 4U;
    uint8 instance = 7U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined FTM_7_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 6 - channel 7.
 */
ISR(FTM_7_CH_6_CH_7_ISR)
{
    uint8 channel = 6U;
    uint8 instance = 7U;

    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    channel++;
    if (Ftm_Gpt_Ip_GetChannelEventStatus(instance, channel))
    {
        Ftm_Gpt_Ip_ProcessCommonInterrupt(instance, channel);
    }

    EXIT_INTERRUPT();
}
#endif
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* FTM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif  /*FTM_GPT_IP_C*/
/** @} */

