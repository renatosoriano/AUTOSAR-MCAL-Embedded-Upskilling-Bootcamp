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

#ifndef FTFC_MEM_EEP_IP_CFG_H
#define FTFC_MEM_EEP_IP_CFG_H

/**
*   @file Ftfc_Mem_Eep_Ip_Cfg.h
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

#include "S32K144_FTFC.h"
#include "S32K144_SIM.h"
#include "Ftfc_Mem_Eep_Ip_Types.h"
#include "Devassert.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_MEM_EEP_IP_CFG_VENDOR_ID_H                    43
#define FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H     4
#define FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H     7
#define FTFC_MEM_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_H  0
#define FTFC_MEM_EEP_IP_CFG_SW_MAJOR_VERSION_H             2
#define FTFC_MEM_EEP_IP_CFG_SW_MINOR_VERSION_H             0
#define FTFC_MEM_EEP_IP_CFG_SW_PATCH_VERSION_H             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Version checks for Ftfc_Mem_Eep_Ip_Types.h */
#if (FTFC_MEM_EEP_IP_CFG_VENDOR_ID_H != FTFC_MEM_EEP_IP_TYPES_VENDOR_ID_H)
    #error "Ftfc_Mem_Eep_Ip_Cfg.h and Ftfc_Mem_Eep_Ip_Types.h have different vendor IDs!"
#endif
#if ((FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H    != FTFC_MEM_EEP_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H    != FTFC_MEM_EEP_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_MEM_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_H != FTFC_MEM_EEP_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "Ftfc_Mem_Eep_Ip_Cfg.h and Ftfc_Mem_Eep_Ip_Types.h are for different AUTOSAR versions!"
#endif
#if ((FTFC_MEM_EEP_IP_CFG_SW_MAJOR_VERSION_H != FTFC_MEM_EEP_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (FTFC_MEM_EEP_IP_CFG_SW_MINOR_VERSION_H != FTFC_MEM_EEP_IP_TYPES_SW_MINOR_VERSION_H) || \
     (FTFC_MEM_EEP_IP_CFG_SW_PATCH_VERSION_H != FTFC_MEM_EEP_IP_TYPES_SW_PATCH_VERSION_H)    \
    )
    #error "Ftfc_Mem_Eep_Ip_Cfg.h and Ftfc_Mem_Eep_Ip_Types.h have different SW versions!"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Version checks for Devassert.h */
    #if ((FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (FTFC_MEM_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H != DEVASSERT_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Ftfc_Mem_Eep_Ip_Cfg.h and Devassert.h are different"
    #endif
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define FTFC_MEM_EEP_IP_QUICK_WRITE STD_OFF


/** FlexRAM base address */
#define FTFC_MEM_EEP_IP_FLEXRAM_ADDRESS         0x14000000U

/** Total size of EEP */
#define FTFC_MEM_EEP_IP_EEP_SIZE                2048U

/** If this is a HT chip derivative the FTFM registers will be used - instead of FTFC. */
#define FTFC_MEM_EEP_IP_HIGH_TEMP_CHIP          STD_OFF

/** STD_ON: Access code loaded on job start / unloaded on job end or error */
#define FTFC_MEM_EEP_IP_LOAD_AC_INTO_RAM        STD_ON

/** Check if source is aligned with half-word and word access. */
#define FTFC_MEM_EEP_IP_ALIGNED_RAM_ACCESS      STD_ON

/**
* @brief   Switches the Dem Error Report
*/
#define FTFC_DISABLE_DEM_REPORT_ERROR_STATUS      (STD_ON)

#define FTFC_DEM_EVENT_BO_MAINTENANCE             (STD_OFF) 
#define FTFC_DEM_EVENT_BO_QUICK_WRITE             (STD_OFF) 
#define FTFC_DEM_EVENT_BO_NORMAL_WRITE            (STD_OFF) 
#define FTFC_DEM_EVENT_BO_MGSTAT_BLOCK            (STD_OFF) 

/** OsIf counter type used in timeout detection */
#define FTFC_MEM_EEP_IP_TIMEOUT_TYPE            OSIF_COUNTER_DUMMY
#define FTFC_MEM_EEP_IP_ABORT_TIMEOUT           268435456U
#define FTFC_MEM_EEP_IP_ASYNC_WRITE_TIMEOUT     268435456U
#define FTFC_MEM_EEP_IP_SYNC_WRITE_TIMEOUT      268435456U

/** This macro can be used to deactivate the DEV_ASSERTs */
#define FTFC_MEM_EEP_IP_DEV_ERROR_DETECT        STD_ON

/** Toggle the development errors detection. */
#define FTFC_DEV_ASSERT(X)              DevAssert((X))


#define IP_EEPROM                       IP_FTFC                        /**< ptr to the IP_FTFM structure                                               */
#define FCNFG_EEERDY_MASK               FTFC_FCNFG_EEERDY_MASK         /**< set when FlexRAM is ready for emulated EEPROM operations                   */
#define FSTAT_CCIF_MASK                 FTFC_FSTAT_CCIF_MASK           /**< zero while a FTFC command or an EEPROM operation is in progress            */
#define FSTAT_ACCERR_MASK               FTFC_FSTAT_ACCERR_MASK         /**< flash access error flag                                                    */
#define FSTAT_FPVIOL_MASK               FTFC_FSTAT_FPVIOL_MASK         /**< a write was attempted to a protected area                                  */
#define FSTAT_RDCOLERR_MASK             FTFC_FSTAT_RDCOLERR_MASK       /**< collision over a FTFC resource that was being manipulated by a command     */
#define FSTAT_MGSTAT0_MASK              FTFC_FSTAT_MGSTAT0_MASK        /**< set if an error is detected during execution of an FTFC command            */

#if (FTFC_MEM_EEP_IP_HIGH_TEMP_CHIP == STD_ON)
#define FSTAT_MGSTAT1_MASK                  FTFM_FSTAT_MGSTAT1_MASK        /**< uncorrectable ECC fault was detected during execution of a flash command   */
#define FSTAT_MGSTAT2_MASK                  FTFM_FSTAT_MGSTAT2_MASK        /**< uncorrectable ECC fault was detected during emulated EEPROM initialization */
#define FSTAT_MGSTAT3_MASK                  FTFM_FSTAT_MGSTAT3_MASK        /**< uncorrectable ECC fault was detected during the flash reset sequence       */
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define MEM_43_EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_EEP_MemMap.h"

extern const Ftfc_Mem_Eep_Ip_ConfigType FtfcCfg;

#define MEM_43_EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_EEP_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTFC_MEM_EEP_IP_CFG_H */

