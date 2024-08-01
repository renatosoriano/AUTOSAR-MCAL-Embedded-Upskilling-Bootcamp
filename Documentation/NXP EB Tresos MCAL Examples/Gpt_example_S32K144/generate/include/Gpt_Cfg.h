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
* Build Version : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
* Copyright 2020-2024 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef GPT_CFG_H
#define GPT_CFG_H

/**
*   @file           Gpt_Cfg.h
*
*   @addtogroup     gpt Gpt Driver
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
#include "Std_Types.h"


#include "Gpt_VS_0_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_CFG                    43
#define GPT_AR_RELEASE_MAJOR_VERSION_CFG     4
#define GPT_AR_RELEASE_MINOR_VERSION_CFG     7
#define GPT_AR_RELEASE_REVISION_VERSION_CFG  0
#define GPT_SW_MAJOR_VERSION_CFG             2
#define GPT_SW_MINOR_VERSION_CFG             0
#define GPT_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
    /* Check if source file and GPT configuration header file are of the same vendor */
#if (GPT_VENDOR_ID_VS_0_PBCFG_H != GPT_VENDOR_ID_CFG)
    #error "Gpt_VS_0_PBcfg.h and Gpt_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and Gpt configuration header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_H != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_H != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_H != GPT_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Gpt_VS_0_PBcfg.h and Gpt_Cfg.h are different"
#endif
/* Check if header file and Gpt configuration header file are of the same software version */
#if ((GPT_SW_MAJOR_VERSION_VS_0_PBCFG_H != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_SW_MINOR_VERSION_VS_0_PBCFG_H != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_SW_PATCH_VERSION_VS_0_PBCFG_H != GPT_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Gpt_VS_0_PBcfg.h and Gpt_Cfg.h are different"
#endif
    
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Gpt_Cfg.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief    GPT_DEV_ERROR_DETECT switch
* @details  Enable/disable GPT_DEV_ERROR_DETECT.
*/
#define GPT_DEV_ERROR_DETECT (STD_OFF)
/*================================================================================================*/
/**
* @brief    GPT_REPORT_WAKEUP_SOURCE switch
* @details  Enable/disable GPT_REPORT_WAKEUP_SOURCE.
*/
#define GPT_REPORT_WAKEUP_SOURCE (STD_OFF)

/*================================================================================================*/
/**
* @brief    GPT_VERSION_INFO_API switch
* @details  Enable/disable GPT_VERSION_INFO_API.
*/
#define GPT_VERSION_INFO_API (STD_OFF)
/*================================================================================================*/
/**
* @brief    GPT_DEINIT_API switch
* @details  Enable/disable GPT_DEINIT_API.
*/
#define GPT_DEINIT_API (STD_ON)
/*================================================================================================*/
/**
* @brief    GPT_TIME_ELAPSED_API switch
* @details  Enable/disable GPT_VERSION_INFO_API.
*/
#define GPT_TIME_ELAPSED_API (STD_OFF)
/*================================================================================================*/
/**
* @brief    GPT_TIME_REMAINING_API switch
* @details  Enable/disable GPT_VERSION_INFO_API.
*/
#define GPT_TIME_REMAINING_API (STD_OFF)
/*================================================================================================*/
/**
* @brief    GPT_ENABLE_DISABLE_NOTIFICATION_API switch
* @details  Enable/disable GPT_VERSION_INFO_API.
*/
#define GPT_ENABLE_DISABLE_NOTIFICATION_API (STD_ON)
/*================================================================================================*/
/**
* @brief    GPT_WAKEUP_FUNCTIONALITY_API switch
* @details  Enable/disable GPT_VERSION_INFO_API.
*/
#define GPT_WAKEUP_FUNCTIONALITY_API (STD_OFF)

/*================================================================================================*/
/**
* @brief    GPT_CHANGE_NEXT_TIMEOUT_VALUE switch
* @details  Enable/disable support for changing timeout value during timer running
*/
#define GPT_CHANGE_NEXT_TIMEOUT_VALUE     (STD_OFF)

/*================================================================================================*/
/**
* @brief    GPT_SET_CLOCK_MODE switch
* @details  Enable/disable API for Dual Mode support.
*/
#define GPT_SET_CLOCK_MODE           (STD_OFF)

/*================================================================================================*/
/**
* @brief    GPT_CHAIN_MODE switch
* @details  Enable/disable API for Chain Mode.
*/
#define GPT_CHAIN_MODE (STD_OFF)

/*================================================================================================*/
/**
* @brief    GPT_STANDBY_WAKEUP_SUPPORT switch
* @details  Support for GPT Standby wakeup.
*           The driver shall NOT CLEAR the interrupt flag,
*           the interrupt enable bit and also should not disable the counter, during init *(Gpt_Rtc_Init()) the flag is already set.
*
*/
#define GPT_STANDBY_WAKEUP_SUPPORT    (STD_OFF)
/*================================================================================================*/
/**
* @brief    GPT_ENABLE_USER_MODE_SUPPORT switch
* @details  Enable/disable support usermode.If this parameter has been configured to 'TRUE' the GPT driver code can be executed from both supervisor and user mode.
*/
#define GPT_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef GPT_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == GPT_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Gpt in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == GPT_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef GPT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
/*================================================================================================*/
/**
* @brief    GPT_PREDEFTIMER_FUNCTIONALITY_API switch
* @details  Enable/disable GPT_PREDEFTIMER_FUNCTIONALITY_API.
*/
#define GPT_PREDEFTIMER_FUNCTIONALITY_API (STD_OFF)
/*================================================================================================*/
/**
* @brief    GPT_MULTICORE_ENABLED switch
* @details  Enable/disable GPT_MULTICORE_ENABLED.
*/
#define GPT_MULTICORE_ENABLED   (STD_OFF)
/*================================================================================================*/
/**
* @brief    GPT_HW_CHANNEL_USED switch
* @details  Enable/disable GPT_HW_CHANNEL_USED.
*/
#define GPT_HW_CHANNEL_USED (STD_OFF)
/*================================================================================================*/
/**
* @brief    GPT_PRECOMPILE_SUPPORT Switch
* @details  Enable/disable GPT_PRECOMPILE_SUPPORT.
*/
#define GPT_PRECOMPILE_SUPPORT (STD_ON)
/*================================================================================================*/
/**
* @brief        Define symbolic names of channels
* @details      Symbolic names of channels.
*/
    #define GptConf_GptChannelConfiguration_GptChannelConfiguration_0  (0U)
            
    #define GptConf_GptChannelConfiguration_GptChannelConfiguration_1  (1U)
            


/*================================================================================================*/
/*================================================================================================*/

/**
* @brief       GPT_HW_CHANNEL_NUM
* @details     The maximum number of HW channels. This is used to allocate memory space for channel runtime info.
*/
#define GPT_HW_CHANNEL_NUM  (2U)

/*================================================================================================*/
/**
* @brief        GPT_MAX_PARTITIONS_CFG.
* @details      Number of configured partitions.
*/
#define GPT_MAX_PARTITIONS_CFG         (0U)
/**
* @brief        GPT_MAX_PARTITIONS.
* @details      Number of maximum partitions.
*/
#define GPT_MAX_PARTITIONS             (1U)
/**
* @brief        GPT_NUM_CONFIG.
* @details      Number of ChannelConfiguration
*/
#define GPT_NUM_CONFIG             (2U)
/**
*   @brief      GPT_HW_PREDEFTIMER_NUM
*   @details    Number of Predefined timers supported
*/
#define GPT_HW_PREDEFTIMER_NUM (4U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief    Predef Timer type. Indicates the type of predef timer.
* @details  This enumeration specifies the possible types of Predef Timer used to configure PREDEFTIMER
* @implements Gpt_PredefTimerType_enumeration
*/
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT = 0x0U,  /**< @brief Selected value is the PREDEF_TIMER_1US_16BIT  */
    GPT_PREDEF_TIMER_1US_24BIT,         /**< @brief Selected value is the PREDEF_TIMER_1US_24BIT  */
    GPT_PREDEF_TIMER_1US_32BIT,         /**< @brief Selected value is the PREDEF_TIMER_1US_32BIT  */
    GPT_PREDEF_TIMER_100US_32BIT        /**< @brief Selected value is the PREDEF_TIMER_100US_32BIT  */
}Gpt_PredefTimerType;
#endif

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

#endif  /* GPT_CFG_H */
