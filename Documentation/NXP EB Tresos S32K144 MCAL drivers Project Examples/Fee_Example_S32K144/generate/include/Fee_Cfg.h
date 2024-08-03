/*==================================================================================================
* Project              : RTD AUTOSAR 4.7
* Platform             : CORTEXM
* Peripheral           : none
* Dependencies         : MemAcc
*
* Autosar Version      : 4.7.0
* Autosar Revision     : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version           : 2.0.0
* Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
* Copyright 2020-2024 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef FEE_CFG_H
#define FEE_CFG_H

/**
*   @file
*
*   @addtogroup FEE
*   @{
*/
/*   @implements Fee_Cfg.h_Artifact*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FEE_VENDOR_ID_CFG                    43
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG     4
#define FEE_AR_RELEASE_MINOR_VERSION_CFG     7
#define FEE_AR_RELEASE_REVISION_VERSION_CFG  0
#define FEE_SW_MAJOR_VERSION_CFG             2
#define FEE_SW_MINOR_VERSION_CFG             0
#define FEE_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MODULENAME configuration header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG != FEE_TYPES_VENDOR_ID)
    #error "Fee_Types.h and Fee_Cfg.h have different vendor ids"
#endif
/* Check if current file and MODULENAME configuration header file are
   of the same Autosar version
*/
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG != FEE_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif
/* Check if current file and MODULENAME configuration header file are
   of the same software version
*/
#if ((FEE_SW_MAJOR_VERSION_CFG != FEE_TYPES_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG != FEE_TYPES_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG != FEE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Pre-processor switch to enable and disable development error detection */
/** @implements   FeeDevErrorDetect_Object */
#define FEE_DEV_ERROR_DETECT                      (STD_ON)

/* Pre-processor switch to enable / disable the API to read out the modules
    version information */
/** @implements   FeeVersionInfoApi_Object */
#define FEE_VERSION_INFO_API                      (STD_ON)

/* The size in bytes to which logical blocks shall be aligned */
/** @implements   FeeVirtualPageSize_Object */
#define FEE_VIRTUAL_PAGE_SIZE                     (32U)

/* Minimum Page size will be a multiple of the minimum page size. Fee shallalign read requests to this size */
/** @implements   FeeMinimumReadPageSize_Object */
#define FEE_MINIMUM_READ_PAGE_SIZE                (1U)

/* Parameter determines the alignment of the start address that Fee buffers need to have */
/** @implements   FeeBufferAlignmentValue_Object */
#define FEE_BUFFER_ALIGN_VALUE                    (1U)

/* Job end notification routine provided by the upper layer module (declaration) */
/** @implements   FeeNvmJobEndNotification_Object */

#define FEE_NVM_JOB_END_NOTIFICATION_DECL         
/* Job end notification routine provided by the upper layer module */
/** @implements   FeeNvmJobEndNotification_Object */

#define FEE_NVM_JOB_END_NOTIFICATION              
/* Job error notification routine provided by the upper layer module (declaration) */
/** @implements   FeeNvmJobErrorNotification_Object */

#define FEE_NVM_JOB_ERROR_NOTIFICATION_DECL       
/* Job error notification routine provided by the upper layer module */
/** @implements   FeeNvmJobErrorNotification_Object */

#define FEE_NVM_JOB_ERROR_NOTIFICATION            
/* Job cluster format notification routine provided by the upper layer module (declaration) */
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION_DECL  
/* Job cluster format notification routine provided by the upper layer module */
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION       
/* Number of configured Fee cluster groups */
#define FEE_NUMBER_OF_CLUSTER_GROUPS              (1U)

/* Number of configured Fee blocks */
#define FEE_CRT_CFG_NR_OF_BLOCKS                  (2U)

/* Maximum number of Fee blocks in all project versions and configurations */
#define FEE_MAX_NR_OF_BLOCKS                      ((FEE_CRT_CFG_NR_OF_BLOCKS))

/* Management overhead per logical block in bytes */
/** @implements   FeeBlockOverhead_Object */
#define FEE_BLOCK_OVERHEAD                        (96U)

/* Management overhead per logical cluster in bytes */
#define FEE_CLUSTER_OVERHEAD                      (96U)

/* Size of the data buffer in bytes */
#define FEE_DATA_BUFFER_SIZE                      (96U)

/* The contents of an erased flash memory cell */
#define FEE_ERASED_VALUE                          (0xffU)

/* Value of the block and cluster validation flag */
#define FEE_VALIDATED_VALUE                       (0x81U)

/* Value of the block and cluster invalidation flag */
#define FEE_INVALIDATED_VALUE                     (0x18U)

/* If reset, power loss etc. occurs here, neither newly nor previously written data is available */
#define FEE_BLOCK_ALWAYS_AVAILABLE                (STD_OFF)

/* Behavior of Fee_ImmediateBlockErase */
#define FEE_LEGACY_IMM_ERASE_MODE                 (STD_OFF)

/* This configuration defines wheather Fee should swap foreign blocks found in flash at swap or not */
#define FEE_SWAP_FOREIGN_BLOCKS_ENABLED           (STD_OFF)

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/* This configuration defines for which project the Fee configuration is used  */
#define FEE_BOOTLOADER_CONFIG                     (STD_OFF)
#endif
/* This configuration defines if the status for the never written blocks must be INVALID or INCONSISTENT */
#define FEE_MARK_EMPTY_BLOCKS_INVALID             (STD_OFF)

#define FEE_MEMACC_ADDRESS_AREA_ID_USED           (0U)

/* Symbolic names of configured Fee blocks */
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_0     (1U)
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_1     (2U)

#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
/* Configuration of cluster group set */
extern const Fee_ClusterGroupType Fee_ClrGrps[ FEE_NUMBER_OF_CLUSTER_GROUPS ];

/* Configuration of Fee blocks */
extern const Fee_BlockConfigType Fee_BlockConfig[ FEE_CRT_CFG_NR_OF_BLOCKS ];

#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FEE_CFG_H */
