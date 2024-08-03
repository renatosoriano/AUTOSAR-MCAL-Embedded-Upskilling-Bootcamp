
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
#ifndef MEM_43_EEP_CFG_H
#define MEM_43_EEP_CFG_H

/**
*   @file Mem_43_EEP_Cfg.h
*
*   @addtogroup MEM_43_EEP
*   @{
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
#include "Mem_43_EEP_Types.h"
#include "Mem_43_EEP_InternalTypes.h"
#include "StandardTypes.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_VENDOR_ID_CFG                           43
#define MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG            4
#define MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG            7
#define MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG         0
#define MEM_43_EEP_SW_MAJOR_VERSION_CFG                    2
#define MEM_43_EEP_SW_MINOR_VERSION_CFG                    0
#define MEM_43_EEP_SW_PATCH_VERSION_CFG                    0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_EEP configuration header file are of the same vendor */
#if (MEM_43_EEP_TYPES_VENDOR_ID != MEM_43_EEP_VENDOR_ID_CFG)
    #error "Mem_43_EEP_Types.h and Mem_43_EEP_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EEP configuration header file are of the same Autosar version */
#if ((MEM_43_EEP_TYPES_AR_RELEASE_MAJOR_VERSION    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_43_EEP_TYPES_AR_RELEASE_MINOR_VERSION    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_43_EEP_TYPES_AR_RELEASE_REVISION_VERSION != MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_EEP_Types.h and Mem_43_EEP_Cfg.h are different"
#endif
/* Check if current file and Mem_43_EEP configuration header file are of the same software version */
#if ((MEM_43_EEP_TYPES_SW_MAJOR_VERSION != MEM_43_EEP_SW_MAJOR_VERSION_CFG) || \
     (MEM_43_EEP_TYPES_SW_MINOR_VERSION != MEM_43_EEP_SW_MINOR_VERSION_CFG) || \
     (MEM_43_EEP_TYPES_SW_PATCH_VERSION != MEM_43_EEP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_43_EEP_Types.h and Mem_43_EEP_Cfg.h are different"
#endif

/* Check if current file and Mem_43_EEP configuration header file are of the same vendor */
#if (MEM_43_EEP_INTERNALTYPES_VENDOR_ID != MEM_43_EEP_VENDOR_ID_CFG)
    #error "Mem_43_EEP_InternalTypes.h and Mem_43_EEP_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_43_EEP configuration header file are of the same Autosar version */
#if ((MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION    != MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_43_EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION    != MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_43_EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION != MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_EEP_InternalTypes.h and Mem_43_EEP_Cfg.h are different"
#endif
/* Check if current file and Mem_43_EEP configuration header file are of the same software version */
#if ((MEM_43_EEP_INTERNALTYPES_SW_MAJOR_VERSION != MEM_43_EEP_SW_MAJOR_VERSION_CFG) || \
     (MEM_43_EEP_INTERNALTYPES_SW_MINOR_VERSION != MEM_43_EEP_SW_MINOR_VERSION_CFG) || \
     (MEM_43_EEP_INTERNALTYPES_SW_PATCH_VERSION != MEM_43_EEP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_43_EEP_InternalTypes.h and Mem_43_EEP_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_EEP_Cfg.h and StandardTypes.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same version */
    #if ((MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_EEP_Cfg.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Pre-processor switch to enable and disable development error detection */
#define MEM_43_EEP_DEV_ERROR_DETECT        (STD_ON)

/* Pre-processor value for driver istance id*/
/* Mem Instances ID */
#define MEM_43_EEP_INSTANCE_0_ID            (Mem_43_EEP_InstanceIdType)(0U)

/* Number of configured Mem instances */
#define MEM_43_EEP_INSTANCE_COUNT                           (1U)

/* The maximum number of bytes to read in one cycle */
#define MEM_43_EEP_MAX_READ_BLOCK_SIZE                      (4096)

/* The maximum number of bytes to write in one cycle */
#define MEM_43_EEP_MAX_WRITE_BLOCK_SIZE                     (4096)

/* Compile switch to enable and disable the Mem_Suspend function */
#define MEM_43_EEP_SUSPEND_API             (STD_ON)

/* Compile switch to enable and disable the Mem_Resume function */
#define MEM_43_EEP_RESUME_API              (STD_ON)

/* Compile switch to enable and disable the Mem_PropagateError function */
#define MEM_43_EEP_PROPAGATEERROR_API      (STD_ON)

/* Compile switch to enable and disable the Mem_BlankCheck function */
#define MEM_43_EEP_BLANKCHECK_API          (STD_ON)


/* Compile switch to enable and disable the Mem_HwSpecificService function */
/* MEM_43_EEP_HWSPECIFICSERVICE_API = STD_ON if at least a ServiceId is enabled */
#define MEM_43_EEP_HWSPECIFICSERVICE_API    STD_ON

/* Compile switch to enable and disable the MemServiceCompare feature */
#define MEM_43_EEP_SERVICE_COMPARE          (STD_ON)


/* Compile switch to enable and disable the Mem_GetJobResult function */
#define MEM_43_EEP_GET_JOB_RESULT_API       (STD_ON)

/* Pre-processor switch to enable / disable the API to read out the modules version information */
#define MEM_43_EEP_VERSION_INFO_API         (STD_ON)

/** Enable / disable the QuickWrites mode */
#define MEM_43_EEP_SERVICE_QUICKWRITES_API  STD_OFF

/* defines if the write operation will be executed in asynchronous mode or not*/
#define MEM_43_EEP_ASYNC_WRITE_OPERATIONS_ENABLED      (STD_OFF)

/* defines if the Erase operation will be executed in asynchronous mode or not*/
#define MEM_43_EEP_ASYNC_ERASE_OPERATIONS_ENABLED      (STD_OFF)

/**
* @brief      Support for User mode.
*             If this parameter has been configured to 'TRUE' the Mem driver can be executed from both supervisor and user mode.
* @implements Mem_43_EEP_Cfg.h_Artifact
*/
#define MEM_43_EEP_ENABLE_USER_MODE_SUPPORT  (STD_OFF)

/** Check the driver user mode is enabled only when the MCAL_ENABLE_USER_MODE_SUPPORT is enabled */
#if (MEM_43_EEP_ENABLE_USER_MODE_SUPPORT == STD_ON)
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Mem_EEP in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* (MEM_43_EEP_ENABLE_USER_MODE_SUPPORT == STD_ON) */

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define MEM_43_EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_EEP_MemMap.h"

/* Declaration of pre-compile configuration set structure */
extern const Mem_43_EEP_ConfigType Mem_43_EEP_Config;

#define MEM_43_EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_EEP_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_EEP_CFG_H */

