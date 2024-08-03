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

#ifndef MEM_43_INFLS_CFG_H
#define MEM_43_INFLS_CFG_H

/**
 * @file        Mem_43_INFLS_Cfg.h
 *
 * @addtogroup  MEM_43_INFLS Driver
 * implement    Mem_43_INFLS_Cfg.h_Artifact
 *
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
#include "Mem_43_INFLS_Types.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_VENDOR_ID_CFG                           43
#define MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_CFG            4
#define MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_CFG            7
#define MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_CFG         0
#define MEM_43_INFLS_SW_MAJOR_VERSION_CFG                    2
#define MEM_43_INFLS_SW_MINOR_VERSION_CFG                    0
#define MEM_43_INFLS_SW_PATCH_VERSION_CFG                    0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Mem_43_INFLS_Types.h header file are of the same vendor */
#if (MEM_43_INFLS_VENDOR_ID_CFG != MEM_43_INFLS_TYPES_VENDOR_ID)
    #error "Mem_43_INFLS_Cfg.h and Mem_43_INFLS_Types.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS_Types.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_CFG    != MEM_43_INFLS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_CFG    != MEM_43_INFLS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_CFG != MEM_43_INFLS_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS_Cfg.h and Mem_43_INFLS_Types.h are different"
#endif
/* Check if current file and Mem_43_INFLS_Types.h header file are of the same Software version */
#if ((MEM_43_INFLS_SW_MAJOR_VERSION_CFG != MEM_43_INFLS_TYPES_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_SW_MINOR_VERSION_CFG != MEM_43_INFLS_TYPES_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_SW_PATCH_VERSION_CFG != MEM_43_INFLS_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Cfg.h and Mem_43_INFLS_Types.h are different"
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Mem Instances ID */
#define MEM_43_INFLS_INSTANCE_0_ID            (0U)

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"


/* Configuration of Mem_43_INFLS */
extern const Mem_43_INFLS_ConfigType Mem_43_INFLS_Config;

/* Configuration of MemSectorBatch */
extern const Mem_43_INFLS_SectorBatchType Mem_43_INFLS_MemInstance_0_SectorBatch[3U];


#define MEM_43_INFLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_INFLS_CFG_H */
