/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_FTFC
*   Dependencies         : 
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
*   @file       Ftfc_Mem_Eep_Ip_Cfg.c
*
*   @addtogroup FTFC_MEM_EEP_IP
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
#include "Ftfc_Mem_Eep_Ip_Cfg.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_MEM_EEP_IP_CFG_VENDOR_ID_C                      43
#define FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_C       7
#define FTFC_MEM_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define FTFC_MEM_EEP_IP_CFG_SW_MAJOR_VERSION_C               2
#define FTFC_MEM_EEP_IP_CFG_SW_MINOR_VERSION_C               0
#define FTFC_MEM_EEP_IP_CFG_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Version checks for Ftfc_Mem_Eep_Ip_Cfg.h */
#if (FTFC_MEM_EEP_IP_CFG_VENDOR_ID_C != FTFC_MEM_EEP_IP_CFG_VENDOR_ID_H)
    #error "Ftfc_Mem_Eep_Ip_Cfg.c and Ftfc_Mem_Eep_Ip_Cfg.h have different vendor IDs!"
#endif
#if ((FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_MEM_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_C != FTFC_MEM_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "Ftfc_Mem_Eep_Ip_Cfg.c and Ftfc_Mem_Eep_Ip_Cfg.h are for different AUTOSAR versions!"
#endif
#if ((FTFC_MEM_EEP_IP_CFG_SW_MAJOR_VERSION_C != FTFC_MEM_EEP_IP_CFG_SW_MAJOR_VERSION_H) || \
     (FTFC_MEM_EEP_IP_CFG_SW_MINOR_VERSION_C != FTFC_MEM_EEP_IP_CFG_SW_MINOR_VERSION_H) || \
     (FTFC_MEM_EEP_IP_CFG_SW_PATCH_VERSION_C != FTFC_MEM_EEP_IP_CFG_SW_PATCH_VERSION_H)    \
    )
    #error "Ftfc_Mem_Eep_Ip_Cfg.c and Ftfc_Mem_Eep_Ip_Cfg.h have different SW versions!"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                        FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define MEM_43_EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_EEP_MemMap.h"

const Ftfc_Mem_Eep_Ip_ConfigType FtfcCfg =
{
    /** acCallBackPtr                */ NULL_PTR,
    /** startEepromAccessNotifPtr    */ NULL_PTR,
    /** finishedEepromAccessNotifPtr */ NULL_PTR,
};

#define MEM_43_EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_EEP_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

