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
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   (c) Copyright 2020-2024 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef MPU_IP_CFG_H_
#define MPU_IP_CFG_H_

/**
*   @file Mpu_Ip_Cfg.h
*
*   @addtogroup MPU_IP MPU IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mpu_Ip_TypesDef.h"
#include "Mpu_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID                    43
#define CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION             2
#define CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION             0
#define CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mpu_Ip_TypesDef.h */
#if (CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID != CDD_PLATFORM_MPU_IP_TYPES_DEF_VENDOR_ID)
    #error "Mpu_Ip_Cfg.h and Mpu_Ip_TypesDef.h have different vendor ids"
#endif
#if (( CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_TypesDef.h are different"
#endif
#if (( CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_TypesDef.h are different"
#endif

/* Checks against Mpu_Ip_Cfg_Defines.h */
#if (CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID != CDD_PLATFORM_MPU_IP_CFG_DEFINES_VENDOR_ID)
    #error "Mpu_Ip_Cfg.h and Mpu_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if (( CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_MPU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_MPU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MPU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_Cfg_Defines.h are different"
#endif
#if (( CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION != CDD_PLATFORM_MPU_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION != CDD_PLATFORM_MPU_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_Cfg_Defines.h are different"
#endif


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
/**
* @brief   Collection of all configuration structures declarations.
*/

#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
    
#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MPU_IP_CFG_H_ */



