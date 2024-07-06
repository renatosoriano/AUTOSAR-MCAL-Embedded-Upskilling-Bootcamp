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

#ifndef GPT_IPW_TYPES_H
#define GPT_IPW_TYPES_H

/**
*   @file       Gpt_Ipw_Types.h
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
#include "Gpt_Cfg.h"
#include "Ftm_Gpt_Ip.h"
#include "SRtc_Ip.h"
#include "Lptmr_Gpt_Ip.h"
#include "LPit_Gpt_Ip.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_IPW_TYPES_VENDOR_ID                      43
#define GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION       7
#define GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION    0
#define GPT_IPW_TYPES_SW_MAJOR_VERSION               2
#define GPT_IPW_TYPES_SW_MINOR_VERSION               0
#define GPT_IPW_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (GPT_IPW_TYPES_VENDOR_ID != GPT_VENDOR_ID_CFG)
    #error "Gpt_Ipw_Types.h and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Gpt_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Gpt_Cfg.h are different"
#endif

#if (GPT_IPW_TYPES_VENDOR_ID != FTM_GPT_IP_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and Ftm_Gpt_Ip.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != FTM_GPT_IP_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != FTM_GPT_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Ftm_Gpt_Ip.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != FTM_GPT_IP_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != FTM_GPT_IP_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != FTM_GPT_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Ftm_Gpt_Ip.h are different"
#endif

#if (GPT_IPW_TYPES_VENDOR_ID != LPTMR_GPT_IP_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and Lptmr_Gpt_Ip.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Lptmr_Gpt_Ip.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != LPTMR_GPT_IP_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != LPTMR_GPT_IP_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != LPTMR_GPT_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Lptmr_Gpt_Ip.h are different"
#endif

#if (GPT_IPW_TYPES_VENDOR_ID != LPIT_GPT_IP_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and LPit_Gpt_Ip.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and LPit_Gpt_Ip.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != LPIT_GPT_IP_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != LPIT_GPT_IP_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != LPIT_GPT_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Ipw_Types.h and LPit_Gpt_Ip.h are different"
#endif

#if (GPT_IPW_TYPES_VENDOR_ID != SRTC_IP_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and SRtc_Ip.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != SRTC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != SRTC_IP_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != SRTC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and SRtc_Ip.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != SRTC_IP_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != SRTC_IP_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != SRTC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Ipw_Types.h and SRtc_Ip.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @internal
* @brief    Gpt_PrescalerType
* @details  Gpt prescaler data type
*/

typedef uint8 Gpt_PrescalerType;

/**
* @internal
* @brief    Gpt_ClockSourceType
* @details  Gpt clock source data type
*/
typedef uint8 Gpt_ClockSourceType;
/**
* @internal
* @brief      SupportedIpTypes
* @details    This enumeration specifies HW support
*
*/
typedef enum
{
    GPT_FTM_MODULE   = 0,      /**< @brief Support FTM_MODULE   - 0 */
    GPT_SRTC_MODULE  = 1,      /**< @brief Support SRTC_MODULE  - 1 */
    GPT_LPTMR_MODULE = 2,      /**< @brief Support LPTMR_MODULE - 2 */
    GPT_LPIT_MODULE  = 3       /**< @brief Support LPIT_MODULE  - 3 */
}Gpt_Ipw_SupportedIpTypes;

/**
* @internal
* @brief      ChannelConfigType
* @details    This union specifies channel config type
*
*/
typedef struct
{
    const Ftm_Gpt_Ip_ChannelConfigType *Ftm_Gpt_Ip_ChannelConfig;       /**< @brief pointer to configuration Ftm_Gpt_Ip_ChannelConfig */
    const Srtc_Ip_ConfigType *Srtc_Ip_ChannelConfig;                    /**< @brief pointer to configuration SRtc_Ip_ChannelConfig    */
    const Lptmr_Gpt_Ip_ConfigType *Lptmr_Gpt_Ip_ChannelConfig;          /**< @brief pointer to configuration Lptmr_Ip_ChannelConfig   */
    const Lpit_Gpt_Ip_ChannelConfigType *Lpit_Gpt_Ip_ChannelConfig;     /**< @brief pointer to configuration LPit_Ip_ChannelConfig    */
}Gpt_Ipw_ChannelConfigType;

/**
* @internal
* @brief      InstanceConfigType
* @details    This union specifies InstanceConfigType
*
*/
typedef struct
{
    const Ftm_Gpt_Ip_InstanceConfigType *Ftm_Gpt_Ip_InstanceConfig;      /**< @brief pointer to configuration Ftm_Gpt_Ip_InstanceConfig */
    const Lpit_Gpt_Ip_InstanceConfigType *Lpit_Gpt_Ip_InstanceConfig;    /**< @brief pointer to configuration LPit_Gpt_Ip_InstanceConfig */
}Gpt_Ipw_InstanceConfigType;
/**
* @internal
* @brief    HwChannelConfigType  - this is the type of the data structure including the
*           informations of a channel.
* @details  It contains the information like instance, channel , channelconfig.
*
* @implements
*/
typedef struct
{
    Gpt_Ipw_SupportedIpTypes instanceType;              /**< @brief IP type */
    uint8 instance;                                     /**< @brief IP instance  */
    uint8 channel;                                      /**< @brief IP channel */
    Gpt_Ipw_ChannelConfigType Gpt_Ipw_ChannelConfig;    /**< @brief IP instance config pointer */
}Gpt_Ipw_HwChannelConfigType;
/**
* @internal
* @brief    HwInstanceConfigType  - this is the type of the data structure including the
*           informations of a channel.
* @details  It contains the information like instance, channel , channelconfig.
*
* @implements
*/
typedef struct
{
    Gpt_Ipw_SupportedIpTypes instanceType;              /**< @brief Gpt_Ipw_SupportedIpTypes */
    uint8 instance;                                     /**< @brief uint8 instance  */
    Gpt_Ipw_InstanceConfigType Gpt_Ipw_InstanceConfig;  /**< @brief Gpt_Ipw_InstanceConfigType */
}Gpt_Ipw_HwInstanceConfigType;

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @internal
* @brief    Low level configuration for channel specific parameters
* @details  It contains the information like ip type, Channel freeze enable , channel , Channel prescaler value , hw module used .
*
* @implements
*/
typedef struct
{
    Gpt_Ipw_SupportedIpTypes instanceType;    /**< @brief IP type */
    uint8 instance;                           /**< @brief IP instance */
    uint8 channel;                            /**< @brief GPT hw channel ID */
    Gpt_ClockSourceType Gpt_uClockSource;     /**< @brief Clock source FTM */
    boolean Gpt_bFreezeEnable;                /**< @brief freeze enable */
    Gpt_PrescalerType Gpt_uPrescaler;         /**< @brief prescaler value*/
} Gpt_HwPredefChannelConfigType;
#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
#endif /*GPT_IPW_TYPES_H*/
