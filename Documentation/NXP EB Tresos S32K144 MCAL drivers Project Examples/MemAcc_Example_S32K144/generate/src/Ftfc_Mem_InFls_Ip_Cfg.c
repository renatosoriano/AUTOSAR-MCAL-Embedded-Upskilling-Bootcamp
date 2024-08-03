/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FTFC
*   Dependencies         : None
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors
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
 * @file       Ftfc_Mem_InFls_Ip_Cfg.c
 *
 * @defgroup   FTFC_MEM_INFLS_IP FTFC_MEM_INFLS_IP Driver
 *
 * implement   Ftfc_Mem_InFls_Ip_Cfg.c_Artifact
 * @{
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
#include "Ftfc_Mem_InFls_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_MEM_INFLS_IP_VENDOR_ID_CFG_C                          43
#define FTFC_MEM_INFLS_IP_AR_RELEASE_MAJOR_VERSION_CFG_C           4
#define FTFC_MEM_INFLS_IP_AR_RELEASE_MINOR_VERSION_CFG_C           7
#define FTFC_MEM_INFLS_IP_AR_RELEASE_REVISION_VERSION_CFG_C        0
#define FTFC_MEM_INFLS_IP_SW_MAJOR_VERSION_CFG_C                   2
#define FTFC_MEM_INFLS_IP_SW_MINOR_VERSION_CFG_C                   0
#define FTFC_MEM_INFLS_IP_SW_PATCH_VERSION_CFG_C                   0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ftfc_Mem_InFls_Ip_Cfg header file are of the same vendor */
#if (FTFC_MEM_INFLS_IP_VENDOR_ID_CFG_C != FTFC_MEM_INFLS_IP_VENDOR_ID_CFG)
    #error "Ftfc_Mem_InFls_Ip_Cfg.c and Ftfc_Mem_InFls_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Mem_InFls_Ip_Cfg header file are of the same Autosar version */
#if ((FTFC_MEM_INFLS_IP_AR_RELEASE_MAJOR_VERSION_CFG_C    != FTFC_MEM_INFLS_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FTFC_MEM_INFLS_IP_AR_RELEASE_MINOR_VERSION_CFG_C    != FTFC_MEM_INFLS_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FTFC_MEM_INFLS_IP_AR_RELEASE_REVISION_VERSION_CFG_C != FTFC_MEM_INFLS_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Ftfc_Mem_InFls_Ip_Cfg.c and Ftfc_Mem_InFls_Ip_Cfg.h are different"
#endif
/* Check if current file and Ftfc_Mem_InFls_Ip_Cfg header file are of the same Software version */
#if ((FTFC_MEM_INFLS_IP_SW_MAJOR_VERSION_CFG_C != FTFC_MEM_INFLS_IP_SW_MAJOR_VERSION_CFG) || \
     (FTFC_MEM_INFLS_IP_SW_MINOR_VERSION_CFG_C != FTFC_MEM_INFLS_IP_SW_MINOR_VERSION_CFG) || \
     (FTFC_MEM_INFLS_IP_SW_PATCH_VERSION_CFG_C != FTFC_MEM_INFLS_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Ftfc_Mem_InFls_Ip_Cfg.c and Ftfc_Mem_InFls_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
#define MEM_43_INFLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"

const Ftfc_Mem_InFls_Ip_ConfigType Ftfc_Mem_InFls_Ip_InitCfg =
{
    NULL_PTR,                                               /* MemStartFlashAccessNotif    */
    NULL_PTR                                                /* MemFinishedFlashAccessNotif */
};

#define MEM_43_INFLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/
