
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

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_EEP.h"
/* If FTFC IP is present on the platform */
#include "Ftfc_Mem_Eep_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_VENDOR_ID_CFG_C                      43
#define MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG_C       7
#define MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define MEM_43_EEP_SW_MAJOR_VERSION_CFG_C               2
#define MEM_43_EEP_SW_MINOR_VERSION_CFG_C               0
#define MEM_43_EEP_SW_PATCH_VERSION_CFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_EEP header file are of the same vendor */
#if (MEM_43_EEP_VENDOR_ID_CFG_C != MEM_43_EEP_VENDOR_ID)
    #error "Mem_43_EEP_Cfg.c and Mem_43_EEP.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EEP header file are of the same Autosar version */
#if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG_C    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG_C    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG_C != MEM_43_EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_EEP_Cfg.c and Mem_43_EEP.h are different"
#endif
/* Check if current file and Mem_43_EEP header file are of the same Software version */
#if ((MEM_43_EEP_SW_MAJOR_VERSION_CFG_C != MEM_43_EEP_SW_MAJOR_VERSION) || \
     (MEM_43_EEP_SW_MINOR_VERSION_CFG_C != MEM_43_EEP_SW_MINOR_VERSION) || \
     (MEM_43_EEP_SW_PATCH_VERSION_CFG_C != MEM_43_EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_EEP_Cfg.c and Mem_43_EEP.h are different"
#endif

/* Check if current file and Ftfc_Mem_Eep_Ip_Cfg header file are of the same vendor */
#if (MEM_43_EEP_VENDOR_ID_CFG_C != FTFC_MEM_EEP_IP_CFG_VENDOR_ID_H)
    #error "AutoSar Version Numbers of Mem_43_EEP_Cfg.c and Ftfc_Mem_Eep_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Mem_Eep_Ip_Cfg header file are of the same Autosar version */
#if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG_C    != FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG_C    != FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG_C != FTFC_MEM_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mem_43_EEP_Cfg.c and Ftfc_Mem_Eep_Ip_Cfg.h are different"
#endif
/* Check if current file and Ftfc_Mem_Eep_Ip_Cfg header file are of the same Software version */
#if ((MEM_43_EEP_SW_MAJOR_VERSION_CFG_C != FTFC_MEM_EEP_IP_CFG_SW_MAJOR_VERSION_H) || \
     (MEM_43_EEP_SW_MINOR_VERSION_CFG_C != FTFC_MEM_EEP_IP_CFG_SW_MINOR_VERSION_H) || \
     (MEM_43_EEP_SW_PATCH_VERSION_CFG_C != FTFC_MEM_EEP_IP_CFG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_EEP_Cfg.c and Ftfc_Mem_Eep_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

#define MEM_43_EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_EEP_MemMap.h"

/* Configuration of MemSectorBatch */
const Mem_43_EEP_SectorBatchType Mem_43_EEP_MemInstance_0_SectorBatch[1U] =
{
    {
        /* MemSectorBatch_0 */
        0U,
        1023U,
        1024U,
        512U,
        512U,
        1024U,
        512U,
        512U
    }
};


/* Configuration of Mem instances */
static const Mem_43_EEP_MemInstanceType Mem_43_EEP_MemInstances[MEM_43_EEP_INSTANCE_COUNT] =
{

    {
        /* MemInstance_0 */
        MEM_43_EEP_INSTANCE_0_ID,
        1U,
        Mem_43_EEP_MemInstance_0_SectorBatch,
        0U
    }
};
/**
* @brief       Structure used to set function pointers notification, working mode
*/
const Mem_43_EEP_ConfigType Mem_43_EEP_Config =
{
    /* MemInstance Configuration                                 */ &Mem_43_EEP_MemInstances[0u],
    /* FTFC IP Config Set                */ &FtfcCfg
};

#define MEM_43_EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_EEP_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/

