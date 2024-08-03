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

#ifndef FTFC_MEM_INFLS_IP_CFG_H
#define FTFC_MEM_INFLS_IP_CFG_H

/**
 * @file       Ftfc_Mem_InFls_Ip_Cfg.h
 *
 * @defgroup   FTFC_MEM_INFLS_IP FTFC IP Driver
 *
 * implement   Ftfc_Mem_InFls_Ip_Cfg.h_Artifact
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
#include "Ftfc_Mem_InFls_Ip_Types.h"

#include "S32K144_FTFC.h"
#include "S32K144_MSCM.h"
#include "S32K144_SIM.h"

#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_MEM_INFLS_IP_VENDOR_ID_CFG                          43
#define FTFC_MEM_INFLS_IP_AR_RELEASE_MAJOR_VERSION_CFG           4
#define FTFC_MEM_INFLS_IP_AR_RELEASE_MINOR_VERSION_CFG           7
#define FTFC_MEM_INFLS_IP_AR_RELEASE_REVISION_VERSION_CFG        0
#define FTFC_MEM_INFLS_IP_SW_MAJOR_VERSION_CFG                   2
#define FTFC_MEM_INFLS_IP_SW_MINOR_VERSION_CFG                   0
#define FTFC_MEM_INFLS_IP_SW_PATCH_VERSION_CFG                   0

/*==================================================================================================
*                                 FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ftfc_Mem_InFls_Ip_Types.h header file are of the same vendor */
#if (FTFC_MEM_INFLS_IP_VENDOR_ID_CFG != FTFC_MEM_INFLS_IP_TYPES_VENDOR_ID)
    #error "Ftfc_Mem_InFls_Ip_Cfg.h and Ftfc_Mem_InFls_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Mem_InFls_Ip header file are of the same Autosar version */
#if ((FTFC_MEM_INFLS_IP_AR_RELEASE_MAJOR_VERSION_CFG    != FTFC_MEM_INFLS_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTFC_MEM_INFLS_IP_AR_RELEASE_MINOR_VERSION_CFG    != FTFC_MEM_INFLS_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTFC_MEM_INFLS_IP_AR_RELEASE_REVISION_VERSION_CFG != FTFC_MEM_INFLS_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ftfc_Mem_InFls_Ip_CFGfg.h and Ftfc_Mem_InFls_Ip_Types.h are different"
#endif
/* Check if current file and Ftfc_Mem_InFls_Ip header file are of the same Software version */
#if ((FTFC_MEM_INFLS_IP_SW_MAJOR_VERSION_CFG != FTFC_MEM_INFLS_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTFC_MEM_INFLS_IP_SW_MINOR_VERSION_CFG != FTFC_MEM_INFLS_IP_TYPES_SW_MINOR_VERSION) || \
     (FTFC_MEM_INFLS_IP_SW_PATCH_VERSION_CFG != FTFC_MEM_INFLS_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ftfc_Mem_InFls_Ip_Cfg.h and Ftfc_Mem_InFls_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((FTFC_MEM_INFLS_IP_AR_RELEASE_MAJOR_VERSION_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (FTFC_MEM_INFLS_IP_AR_RELEASE_MINOR_VERSION_CFG != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Ftfc_Mem_InFls_Ip_Cfg.h and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* FTFx Access Layer */
#define FTFx_HARDWARE_TYPE                   FTFC_Type
#define FTFx_HARDWARE_UNIT                   IP_FTFC

#define FTFx_FPROT_COUNT                     FTFC_FPROT_COUNT
#define FTFx_FSTAT_CCIF_MASK                 FTFC_FSTAT_CCIF_MASK
#define FTFx_FSTAT_ACCERR_MASK               FTFC_FSTAT_ACCERR_MASK
#define FTFx_FSTAT_FPVIOL_MASK               FTFC_FSTAT_FPVIOL_MASK
#define FTFx_FSTAT_MGSTAT0_MASK              FTFC_FSTAT_MGSTAT0_MASK
#define FTFx_FSTAT_RDCOLERR_MASK             FTFC_FSTAT_RDCOLERR_MASK
#define FTFx_FERSTAT_DFDIF_MASK              FTFC_FERSTAT_DFDIF_MASK
#define FTFx_FCNFG_ERSSUSP_MASK              FTFC_FCNFG_ERSSUSP_MASK

#define FTFx_FSTAT_MGSTAT3_MASK              (0x00U)
#define FTFx_FSTAT_MGSTAT2_MASK              (0x00U)
#define FTFx_FSTAT_MGSTAT1_MASK              (0x00U)

/* Mask of FTFx IP-related error flags */
#define FTFx_ERR_FLAGS_MASK                  (FTFx_FSTAT_RDCOLERR_MASK | \
                                              FTFx_FSTAT_ACCERR_MASK   | \
                                              FTFx_FSTAT_FPVIOL_MASK   | \
                                              FTFx_FSTAT_MGSTAT3_MASK  | \
                                              FTFx_FSTAT_MGSTAT2_MASK  | \
                                              FTFx_FSTAT_MGSTAT1_MASK  | \
                                              FTFx_FSTAT_MGSTAT0_MASK)

/* ---------------------------------------------- */
/* FTFx feature  */

/*! Enable development error check */
#define DEV_ASSERT_FTFC(x)

#define FTFC_MEM_INFLS_IP_SUPPORT_USER_MODE               (STD_OFF)
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == FTFC_MEM_INFLS_IP_SUPPORT_USER_MODE)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Mem Internal in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#define FTFC_MEM_INFLS_IP_SYNCHRONIZE_CACHE               (STD_OFF)
#if (STD_ON == FTFC_MEM_INFLS_IP_SYNCHRONIZE_CACHE)
    #define FTFC_FLS_D_FLASH_CACHEABLE              (STD_ON)
#endif

#define FTFC_MEM_INFLS_IP_ERASE_VERIFICATION              (STD_OFF)

#define FTFC_MEM_INFLS_IP_PROGRAM_VERIFICATION            (STD_OFF)

#define FTFC_TIMEOUT_SUPERVISION_ENABLED            (STD_OFF)
#if (STD_ON == FTFC_TIMEOUT_SUPERVISION_ENABLED)
#define FTFC_MEM_INFLS_IP_TIMEOUT_TYPE                    (OSIF_COUNTER_DUMMY)

#define FTFC_MEM_INFLS_IP_ERASE_TIMEOUT                   (2147483647U)

#define FTFC_MEM_INFLS_IP_WRITE_TIMEOUT                   (2147483647U)

#define FTFC_MEM_INFLS_IP_ABORT_SUSPEND_TIMEOUT           (32767U)

#define FTFC_MEM_INFLS_IP_ERASE_SUSPEND_TIMEOUT            (32767U)

#define FTFC_MEM_INFLS_IP_ERASE_RESUME_TIMEOUT            (32767U)
#endif  /*(STD_ON == FTFC_TIMEOUT_SUPERVISION_ENABLED)*/


/* FlsInvalidPrefetchBufFromRam */
#define FTFC_MEM_INFLS_IP_INVALID_PREBUF_FROM_RAM         (STD_ON)

/* ---------------------------------------------- */
/* Memory Information  */

/* Flash memory characteristics */
#define FTFC_MEM_INFLS_IP_P_FLASH_BASE_ADDR               (0x00000000UL)
#define FTFC_MEM_INFLS_IP_P_FLASH_SIZE                    (0x80000UL)
#define FTFC_MEM_INFLS_IP_P_FLASH_SECTOR_SIZE             (0x1000UL)

#define FTFC_MEM_INFLS_IP_D_FLASH_BASE_ADDR               (0x10000000UL)
#define FTFC_MEM_INFLS_IP_D_FLASH_SIZE                    (0x10000UL)
#define FTFC_MEM_INFLS_IP_D_FLASH_SECTOR_SIZE             (0x800UL)

/* Valid P_FLASH address */
#define FTFC_MEM_INFLS_IP_ADDRESS_VALID_P_FLASH(addr)     ( (addr) < (FTFC_MEM_INFLS_IP_P_FLASH_BASE_ADDR + FTFC_MEM_INFLS_IP_P_FLASH_SIZE) )

/* Valid D_FLASH address */
#define FTFC_MEM_INFLS_IP_ADDRESS_VALID_D_FLASH(addr)     ( (FTFC_MEM_INFLS_IP_D_FLASH_BASE_ADDR <= (addr)) && ((addr) < (FTFC_MEM_INFLS_IP_D_FLASH_BASE_ADDR + FTFC_MEM_INFLS_IP_D_FLASH_SIZE)) )

/* Valid P_FLASH or D_FLASH address */
#define FTFC_MEM_INFLS_IP_ADDRESS_VALID(addr)             ( FTFC_MEM_INFLS_IP_ADDRESS_VALID_P_FLASH(addr) || FTFC_MEM_INFLS_IP_ADDRESS_VALID_D_FLASH(addr) )

/* Check if the address is sector alignment or not */
#define FTFC_MEM_INFLS_IP_SECTOR_ALIGNED(addr)            ( ( ((addr) & (FTFC_MEM_INFLS_IP_P_FLASH_SECTOR_SIZE - 1UL)) == 0UL ) || ( ((addr) & (FTFC_MEM_INFLS_IP_D_FLASH_SECTOR_SIZE - 1UL)) == 0UL ) )

/* Code block size (flash read partition size) */
#define FTFC_MEM_INFLS_IP_P_BLOCK_SIZE                    (0x80000U)

#define FTFC_MEM_INFLS_IP_ERASED_VALUE                    (0xFFFFFFFFU)


/* FlexNVM Partition Code Ratios (DFLASH_EEPROM sizes in KB) - used for Program Partition Command */
#define FLASH_FLEXNVM_DFLASH_EEPROM_DEFAULT         (0x0FU)   /* Bit value:1111   Data flash (KByte):default*/
#if (0x8000UL == FTFC_MEM_INFLS_IP_D_FLASH_SIZE)
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_0_V1         (0x00U)   /* Bit value:0000   Data flash (KByte):32 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_32_V1         (0x03U)   /* Bit value:0011   Data flash (KByte):0  EEPROM backup (KByte):32 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_32_V2         (0x08U)   /* Bit value:1000   Data flash (KByte):0  EEPROM backup (KByte):32 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_8_24_V1         (0x09U)   /* Bit value:1001   Data flash (KByte):8  EEPROM backup (KByte):24 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_0_V2         (0x0BU)   /* Bit value:1011   Data flash (KByte):32 EEPROM backup (KByte):0 */

#elif (0x10000UL == FTFC_MEM_INFLS_IP_D_FLASH_SIZE)
#define FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V1         (0x00U)   /* Bit value:0000   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_32_V1        (0x03U)   /* Bit value:0011   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_64_V1         (0x04U)   /* Bit value:0100   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_64_V2         (0x08U)   /* Bit value:1000   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_16_48_V1        (0x0AU)   /* Bit value:1010   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_32_V2        (0x0BU)   /* Bit value:1011   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V2         (0x0CU)   /* Bit value:1100   Data flash (KByte):64 EEPROM backup (KByte):0 */

#elif (0x80000UL == FTFC_MEM_INFLS_IP_D_FLASH_SIZE)
#define FLASH_FLEXNVM_DFLASH_EEPROM_512_0_V1        (0x00U)   /* Bit value:0000   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_448_64_V1       (0x04U)   /* Bit value:0100   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_512_0_V2        (0x0FU)   /* Bit value:1111   Data flash (KByte):64 EEPROM backup (KByte):0 */
#endif

/* ---------------------------------------------- */
/* ECC Feature */
#define FTFC_MEM_INFLS_IP_ECC_CHECK                       (STD_ON)

#define FTFC_MEM_INFLS_IP_ECC_CHECK_BY_AUTOSAR_OS         (STD_ON)

#if ( (FTFC_MEM_INFLS_IP_ECC_CHECK == STD_ON) || (FTFC_MEM_INFLS_IP_ECC_CHECK_BY_AUTOSAR_OS == STD_ON) )

/* Support for all the derivatives excepting the M0++ core missing some registers related to read syndrome(CFSR) and data address(BFAR) */
#define FTFC_MEM_INFLS_IP_ECC_SYNDROME_AND_DATA_ADDRESS_CHECK    (STD_ON)

#if (FTFC_MEM_INFLS_IP_ECC_SYNDROME_AND_DATA_ADDRESS_CHECK == STD_ON)
    #define FTFC_DSI_EXC_SYNDROME                   (0x00008200U)
#endif


/*Return value for Fls_DsiHandler and Fls_MciHandler*/
/**
 *   Return value for Fls_DsiHandler and Fls_MciHandler.
 *   module does not feel responsible (e.g. address does not belong to its current job,
 *   there is no current pending read/compare job, the syndrome is different).
 *
 */
#define FLS_UNHANDLED       (0U)

/**
 *   Return value for Fls_DsiHandler and Fls_MciHandler.
 *   module feels responsible, but wants to repeat the  causing instruction.
 *   Maybe: it still uses information in MCM or ECSM module, but they are outdated
 *   (e.g. due to an erroneous DMA transfer in the meantime)
 *
 */
#define FLS_HANDLED_RETRY   (1U)

/**
 *   Return value for Fls_DsiHandler and Fls_MciHandler.
 *   module feels responsible, the current job is marked as failed,
 *   processing may continue, skipping the causing instruction.
 *
 */
#define FLS_HANDLED_SKIP    (2U)

/**
 *   Return value for Fls_DsiHandler and Fls_MciHandler.
 *   module  feels responsible, but the only reaction is to stop the system
 *   (e.g.: try to shut-down in a quite safe way)
 *
 */
#define FLS_HANDLED_STOP    (3U)

#endif  /* #if ( (FTFC_MEM_INFLS_IP_ECC_CHECK == STD_ON) || (FTFC_MEM_INFLS_IP_ECC_CHECK_BY_AUTOSAR_OS == STD_ON) ) */

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"

extern const Ftfc_Mem_InFls_Ip_ConfigType Ftfc_Mem_InFls_Ip_InitCfg;

#define MEM_43_INFLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTFC_MEM_INFLS_IP_CFG_H */
