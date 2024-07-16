/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SYSTEM_IP_H_
#define SYSTEM_IP_H_

/**
*   @file
*
*   @defgroup   System_Ip System IP
*   @ingroup    Platform
*
*   @addtogroup System_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "System_Ip_Cfg.h"
#include "Devassert.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_SYSTEM_IP_VENDOR_ID                         43
#define CDD_PLATFORM_SYSTEM_IP_AR_RELEASE_MAJOR_VERSION          4
#define CDD_PLATFORM_SYSTEM_IP_AR_RELEASE_MINOR_VERSION          7
#define CDD_PLATFORM_SYSTEM_IP_AR_RELEASE_REVISION_VERSION       0
#define CDD_PLATFORM_SYSTEM_IP_SW_MAJOR_VERSION                  2
#define CDD_PLATFORM_SYSTEM_IP_SW_MINOR_VERSION                  0
#define CDD_PLATFORM_SYSTEM_IP_SW_PATCH_VERSION                  0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and System_Ip_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_SYSTEM_IP_VENDOR_ID != CDD_PLATFORM_SYSTEM_IP_CFG_TYPES_VENDOR_ID)
    #error "System_Ip.h and System_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and System_Ip_Cfg.h header file are of the same Autosar version */
#if ((CDD_PLATFORM_SYSTEM_IP_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_SYSTEM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_SYSTEM_IP_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_SYSTEM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_SYSTEM_IP_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of System_Ip.h and System_Ip_Cfg.h are different"
#endif
/* Check if current file and System_Ip_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_SYSTEM_IP_SW_MAJOR_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_SYSTEM_IP_SW_MINOR_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_SYSTEM_IP_SW_PATCH_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of System_Ip.h and System_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"


#if ((SYSTEM_IP_ARM_CORTEXM == STD_ON) && (SYSTEM_FPU_CFG == STD_ON)) 
/**
 * @brief         Enables/disables core-related interrupt exceptions.
 *
 * @details       This function is non-reentrant and configures core-related interrupt
 *                exceptions, as defined per each platform.
 *
 * @param[in]     eIrq: core-related interrupt event.
 * @param[in]     bEnable: FALSE - disable interrupt, TRUE - enable interrupt.
 * @return        void
 *
 * @api
 *
 * @implements    System_Ip_ConfigIrq_Activity
 *
 * */
void System_Ip_ConfigIrq(System_Ip_IrqType eIrq, boolean bEnable);
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#endif /* SYSTEM_IP_H_ */

/** @} */
