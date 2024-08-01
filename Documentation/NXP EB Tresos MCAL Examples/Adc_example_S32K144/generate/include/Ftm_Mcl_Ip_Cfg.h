/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,FLEXIO
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors
*   
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FTM_MCL_IP_CFG_H
#define FTM_MCL_IP_CFG_H

/**
 *   @file        Ftm_Mcl_Ip_Cfg.h
 *
 *   @addtogroup     
 *   @brief       MCL IPL Precompile defines header file.
 *   @details     Precompile defines.
 *
 *   @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftm_Mcl_Ip_Cfg_DeviceRegisters.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_MCL_IP_CFG_VENDOR_ID                    43
#define FTM_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define FTM_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define FTM_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define FTM_MCL_IP_CFG_SW_MAJOR_VERSION             2
#define FTM_MCL_IP_CFG_SW_MINOR_VERSION             0
#define FTM_MCL_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Ftm_Mcl_Ip_Cfg_DeviceRegisters.h header file are of the same vendor. */
#if (FTM_MCL_IP_CFG_VENDOR_ID != FTM_MCL_IP_CFG_DEVICEREGISTERS_VENDOR_ID)
    #error "Vendor IDs of Ftm_Mcl_Ip.h and Ftm_Mcl_Ip_Cfg_DeviceRegisters.h are different."
#endif

/* Check if header file and Ftm_Mcl_Ip_Cfg_DeviceRegisters.h header file are of the same AUTOSAR version. */
#if ((FTM_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION    != FTM_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (FTM_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION != FTM_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Mcl_Ip.h and Ftm_Mcl_Ip_Cfg_DeviceRegisters.h are different."
#endif

/* Check if header file and Ftm_Mcl_Ip_Cfg_DeviceRegisters.h header file are of the same software version */
#if ((FTM_MCL_IP_CFG_SW_MAJOR_VERSION != FTM_MCL_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION) || \
     (FTM_MCL_IP_CFG_SW_MINOR_VERSION != FTM_MCL_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION) || \
     (FTM_MCL_IP_CFG_SW_PATCH_VERSION != FTM_MCL_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Mcl_Ip.h and Ftm_Mcl_Ip_Cfg_DeviceRegisters.h are different."
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Enable/Disable FTM common timebase API from MCL. */
#define FTM_MCL_SELECT_COMMON_TIMEBASE_API           (STD_ON)

/** 
 * @brief      This define specifies the number of FTM modules present on the derivative. It's used for the
 *             Mcl_SelectCommonTimebase API
 */
#define FTM_MCL_IP_NOF_MODULES                       ((uint8)4U)

/** 
 * @brief Support for User mode.If this parameter has been configured to STD_ON,
 *        the FTM driver code can be executed from both supervisor and user mode.
 */
#define FTM_MCL_ENABLE_USER_MODE_SUPPORT             (STD_OFF)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define FTM_MCL_IP_DEV_ERROR_DETECT                  (STD_OFF)

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#if (defined (FTM_MCL_ENABLE_USER_MODE_SUPPORT) && (STD_ON == FTM_MCL_ENABLE_USER_MODE_SUPPORT))
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running MCL in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
#endif
#endif


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_MCL_IP_CFG_H_ */

