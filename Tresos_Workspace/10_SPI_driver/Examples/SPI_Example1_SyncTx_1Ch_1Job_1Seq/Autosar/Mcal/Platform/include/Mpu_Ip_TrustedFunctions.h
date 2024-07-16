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
*   (c) Copyright 2020-2023 NXP Semiconductors
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

#ifndef MPU_IP_TRUSTEDFUNCTIONS_H
#define MPU_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Mpu_Ip_TrustedFunctions.h
*
*   @addtogroup MPU_IP MPU IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mpu_Ip_TypesDef.h"
#include "Mpu_Ip_Cfg.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_VENDOR_ID                    43
#define CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION     4
#define CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION     7
#define CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION  0
#define CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION             2
#define CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION             0
#define CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mpu_Ip_TypesDef header file are of the same vendor */
#if (CDD_PLATFORM_MPU_IP_TYPES_DEF_VENDOR_ID != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Mpu_Ip_TrustedFunctions.h and Mpu_Ip_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Mpu_Ip_TypesDef header file are of the same Autosar version */
#if ((CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mpu_Ip_TrustedFunctions.h and Mpu_Ip_TypesDef.h are different"
#endif
/* Check if current file and Mpu_Ip_TypesDef header file are of the same Software version */
#if ((CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MINOR_VERSION != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_PATCH_VERSION != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_TrustedFunctions.h and Mpu_Ip_TypesDef.h are different"
#endif

/* Check if current file and Mpu_Ip_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Mpu_Ip_TrustedFunctions.h and Mpu_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mpu_Ip_Cfg header file are of the same Autosar version */
#if ((CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mpu_Ip_TrustedFunctions.h and Mpu_Ip_Cfg.h are different"
#endif
/* Check if current file and Mpu_Ip_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION != CDD_PLATFORM_MPU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_TrustedFunctions.h and Mpu_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef  PLATFORM_IP_ENABLE_MPU
#if  (PLATFORM_IP_ENABLE_MPU == STD_ON)
    
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief         Initializes the MPU instance and memory regions configured
 */
extern void Mpu_Ip_Init_Privileged(const Mpu_Ip_ConfigType * pConfig);

/**
 * @brief         Configures the specified region number using the input region configuration
 */
extern void Mpu_Ip_SetRegionConfig_Privileged(const uint8 regionNumber, const Mpu_Ip_RegionConfigType * const pUserConfigPtr);

/**
 * @brief         Deinitialize MPU instance
 */
extern void Mpu_Ip_Deinit_Privileged(void);

/**
 * @brief         Enable or disable region configuration
 */
extern void Mpu_Ip_EnableRegion_Privileged(uint8 u8RegionNum, boolean bEnable);

/**
 * @brief         Modify the access mode for a master to a specific region
 */
extern void Mpu_Ip_SetAccessMode_Privileged(uint8 u8RegionNum,
                                            Mpu_Ip_MasterType eMaster,
                                            Mpu_Ip_SupervisorAccessModeType eSupervisorMode,
                                            Mpu_Ip_UserAccessModeType eUserMode
                                           );

/**
 * @brief         Retrieves error details such as address and error type
 */
extern boolean Mpu_Ip_GetErrorDetails_Privileged(Mpu_Ip_ErrorDetailsType * pErrorDetails);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#endif /* PLATFORM_IP_ENABLE_MPU == STD_ON */
#endif /* PLATFORM_IP_ENABLE_MPU */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MPU_IP_TRUSTEDFUNCTIONS_H */

