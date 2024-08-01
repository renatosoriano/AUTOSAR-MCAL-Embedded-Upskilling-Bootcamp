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

/**
*   @file Mpu_Ip_PBcfg.c
*
*   @addtogroup MPU_IP MPU IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mpu_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID_C                     43
#define CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION_C              2
#define CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION_C              0
#define CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mpu_Ip_Cfg.h */
#if (CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID_C != CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID)
    #error "Mpu_Ip_Cfg.c and Mpu_Ip_Cfg.h have different vendor ids"
#endif
#if ((CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_Cfg.h are different"
#endif
#if ((CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_Cfg.c and Mpu_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

const Mpu_Ip_RegionConfigType Mpu_Configuration_RegionConfig[4] =
{
    /* Region Configuration 0 */
    {
        0UL,
        4294967295UL,
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M0SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M1SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_AS_USER_MODE << MPU_RGD_WORD2_M2SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_AS_USER_MODE << MPU_RGD_WORD2_M3SM_SHIFT) | \
        (MPU_USER_MODE_RWX << MPU_RGD_WORD2_M0UM_SHIFT) | \
        (MPU_USER_MODE_RWX << MPU_RGD_WORD2_M1UM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M2UM_SHIFT) | \
        (MPU_USER_MODE_RWX << MPU_RGD_WORD2_M3UM_SHIFT),
        (0U),
        (0U)
    },
    /* Region Configuration 1 */
    {
        0UL,
        4294967295UL,
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M0SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M1SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_RX << MPU_RGD_WORD2_M2SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M3SM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M0UM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M1UM_SHIFT) | \
        (MPU_USER_MODE_RX << MPU_RGD_WORD2_M2UM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M3UM_SHIFT),
        (0U),
        (0U)
    },
    /* Region Configuration 2 */
    {
        0UL,
        4294967295UL,
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M0SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M1SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_AS_USER_MODE << MPU_RGD_WORD2_M2SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M3SM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M0UM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M1UM_SHIFT) | \
        (MPU_USER_MODE_W << MPU_RGD_WORD2_M2UM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M3UM_SHIFT),
        (0U),
        (0U)
    },
    /* Region Configuration 3 */
    {
        0UL,
        31UL,
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M0SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M1SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M2SM_SHIFT) | \
        (MPU_SUPERVISOR_MODE_RWX << MPU_RGD_WORD2_M3SM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M0UM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M1UM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M2UM_SHIFT) | \
        (MPU_USER_MODE_NONE << MPU_RGD_WORD2_M3UM_SHIFT),
        (0U),
        (0U)
    }
};

static const uint8 Mpu_Configuration_RegionNumber[4] =
{
    0U,
    1U,
    2U,
    3U
};

const Mpu_Ip_ConfigType Mpu_Config =
{
    4U,
    Mpu_Configuration_RegionConfig,
    Mpu_Configuration_RegionNumber
};

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

