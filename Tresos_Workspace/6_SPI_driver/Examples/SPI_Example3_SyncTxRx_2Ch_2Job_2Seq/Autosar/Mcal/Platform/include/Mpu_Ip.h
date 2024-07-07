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
#ifndef MPU_IP_H
#define MPU_IP_H

/**
*   @file Mpu_Ip.h
*
*   @addtogroup MPU_IP MPU IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"
#include "Devassert.h"
#include "BasicTypes.h"
#include "SchM_Platform.h"

#include "Mpu_Ip_TypesDef.h"
#include "Mpu_Ip_Cfg_Defines.h"
#include "Mpu_Ip_Cfg.h"

#ifdef MPU_IP_ENABLE_USER_MODE_SUPPORT
    #include "OsIf.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MPU_IP_VENDOR_ID                      43
#define CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION       4
#define CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION       7
#define CDD_PLATFORM_MPU_IP_AR_RELEASE_REVISION_VERSION    0
#define CDD_PLATFORM_MPU_IP_SW_MAJOR_VERSION               2
#define CDD_PLATFORM_MPU_IP_SW_MINOR_VERSION               0
#define CDD_PLATFORM_MPU_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /*  Check if current file and Mcal.h are of the same version */
    #if ((CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Mpu_Ip.h and Mcal.h are different"
    #endif

    /*  Check if current file and Devassert.h are of the same version */
    #if ((CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Mpu_Ip.h and Devassert.h are different"
    #endif

    #ifdef MPU_IP_ENABLE_USER_MODE_SUPPORT
        /*  Check if current file and OsIf.h are of the same version */
        #if ((CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
             (CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AUTOSAR Version Numbers of Mpu_Ip.h and OsIf.h are different"
        #endif
    #endif

    /* Checks against SchM_Platform.h */
    #if ((CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION != SCHM_PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION != SCHM_PLATFORM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Mpu_Ip.h and SchM_Platform.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Checks against Mpu_Ip_Types.h */
#if (CDD_PLATFORM_MPU_IP_VENDOR_ID != CDD_PLATFORM_MPU_IP_TYPES_DEF_VENDOR_ID)
    #error "Mpu_Ip.h and Mpu_Ip_Types.h have different vendor ids"
#endif
#if (( CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip.h and Mpu_Ip_TypesDef.h are different"
#endif
#if (( CDD_PLATFORM_MPU_IP_SW_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_SW_MINOR_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_SW_PATCH_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip.h and Mpu_Ip_TypesDef.h are different"
#endif

/* Checks against Mpu_Ip_Cfg_Defines.h */
#if (CDD_PLATFORM_MPU_IP_VENDOR_ID != CDD_PLATFORM_MPU_IP_CFG_DEFINES_VENDOR_ID)
    #error "Mpu_Ip.h and Mpu_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if (( CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_MPU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_MPU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MPU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip.h and Mpu_Ip_Cfg_Defines.h are different"
#endif
#if (( CDD_PLATFORM_MPU_IP_SW_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_SW_MINOR_VERSION != CDD_PLATFORM_MPU_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_SW_PATCH_VERSION != CDD_PLATFORM_MPU_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip.h and Mpu_Ip_Cfg_Defines.h are different"
#endif

/* Checks against Mpu_Ip_Cfg.h */
#if (CDD_PLATFORM_MPU_IP_VENDOR_ID != CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID)
    #error "Mpu_Ip.h and Mpu_Ip_Cfg.h have different vendor ids"
#endif
#if (( CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip.h and Mpu_Ip_Cfg.h are different"
#endif
#if (( CDD_PLATFORM_MPU_IP_SW_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_SW_MINOR_VERSION != CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_SW_PATCH_VERSION != CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip.h and Mpu_Ip_Cfg.h are different"
#endif



/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef  PLATFORM_IP_ENABLE_MPU
#if  (PLATFORM_IP_ENABLE_MPU == STD_ON)
    
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/**
 * @brief         Initializes the Memory Protection Unit general parameters and
 *                region configurations
 *
 * @details       This function is non-reentrant
 *
 * @param[in]     pConfig: pointer to configuration structure for MPU.
 * @return        void
 *
 * @pre           None
 *
 **/
void Mpu_Ip_Init(const Mpu_Ip_ConfigType * pConfig);

/**
 * @brief         Configures the region selected by u8RegionNum with the data from pUserConfigPtr
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum: Region to be modified .
 * @param[in]     pUserConfigPtr: pointer to the region configuration structure for MPU.
 * @return        void
 *
 * @pre
 *
 **/
void Mpu_Ip_SetRegionConfig(uint8 u8RegionNum, const Mpu_Ip_RegionConfigType * const pUserConfigPtr);

/**
 * @brief         Disables the module and resets all region configurations
 *
 * @details       This function is Reentrant
 *
 * @return        Void
 *
 * @pre           None
 *
 **/
void Mpu_Ip_Deinit(void);

/**
 * @brief         Enables or disabled a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8Region : Region to be modified
 * @param[in]     bEnable  : Specifies wheter the region is enabled or disabled
 * @return        void
 *
 * @pre           None
 *
 */
void Mpu_Ip_EnableRegion(uint8 u8RegionNum, boolean bEnable);

/**
 * @brief         Modify the access mode for a master to a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum     : Region to be modified
 * @param[in]     eMaster         : Master to be modified
 * @param[in]     eSupervisorMode : Specifies the new mode access in supervisor mode
 * @param[in]     eUserMode       : Specifies the new mode access in user mode
 * @return        void
 *
 * @pre           None
 *
 **/
void Mpu_Ip_SetAccessMode(uint8 u8RegionNum,
                          Mpu_Ip_MasterType eMaster,
                          Mpu_Ip_SupervisorAccessModeType eSupervisorMode,
                          Mpu_Ip_UserAccessModeType eUserMode
                         );
/**
 * @brief         Retrieve error details
 *
 * @details       This function is Reentrant
 *
 * @param[out]    pErrorDetails : Storage where the data will be saved
 * @return        boolean - TRUE if an error was present, FALSE otherwise
 *
 * @pre           None
 *
 **/
boolean Mpu_Ip_GetErrorDetails(Mpu_Ip_ErrorDetailsType * pErrorDetails);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#endif /* PLATFORM_IP_ENABLE_MPU == STD_ON */
#endif /* PLATFORM_IP_ENABLE_MPU */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MPU_IP_H */
