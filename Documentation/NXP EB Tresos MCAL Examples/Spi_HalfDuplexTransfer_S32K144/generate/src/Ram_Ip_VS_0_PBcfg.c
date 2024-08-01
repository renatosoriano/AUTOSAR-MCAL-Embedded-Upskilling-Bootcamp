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
*   @file       Ram_Ip_VS_0_PBcfg.c
*   @version    2.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup RAM_DRIVER_CONFIGURATION Ram Ip Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Ram_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RAM_IP_VS_0_PBCFG_VENDOR_ID_C                         43
#define RAM_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C          4
#define RAM_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C          7
#define RAM_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C       0
#define RAM_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C                  2
#define RAM_IP_VS_0_PBCFG_SW_MINOR_VERSION_C                  0
#define RAM_IP_VS_0_PBCFG_SW_PATCH_VERSION_C                  0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Ram_Ip_VS_0_PBcfg.c file and Ram_Ip_Cfg.h file are of the same vendor */
#if (RAM_IP_VS_0_PBCFG_VENDOR_ID_C != RAM_IP_CFG_VENDOR_ID)
    #error "Ram_Ip_VS_0_PBcfg.c and Ram_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Ram_Ip_VS_0_PBcfg.c file and Ram_Ip_Cfg.h file are of the same Autosar version */
#if ((RAM_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != RAM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != RAM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RAM_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != RAM_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ram_Ip_VS_0_PBcfg.c and Ram_Ip_Cfg.h are different"
#endif

/* Check if Ram_Ip_VS_0_PBcfg.c file and Ram_Ip_Cfg.h file are of the same Software version */
#if ((RAM_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C != RAM_IP_CFG_SW_MAJOR_VERSION) || \
     (RAM_IP_VS_0_PBCFG_SW_MINOR_VERSION_C != RAM_IP_CFG_SW_MINOR_VERSION) || \
     (RAM_IP_VS_0_PBCFG_SW_PATCH_VERSION_C != RAM_IP_CFG_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Ram_Ip_VS_0_PBcfg.c and Ram_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Ram_Ip_VS_0_PBcfg.c file and StandardTypes.h file are of the same Autosar version */
#if ((RAM_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ram_Ip_VS_0_PBcfg.c and StandardTypes.h are different"
#endif
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"




#ifndef MCU_MAX_NORAMCONFIGS

/**
* @brief        Definition of RAM sections within the configuration structure.
* @details      Blocks of memory are initialized with a default data.
*               Configuration set by calling Mcu_InitRamSection() API.
*
*/
const Ram_Ip_RamConfigType Mcu_aRamConfigPB_VS_0[1] =
{

    {
        /* The ID for Ram Sector configuration. */
        (Ram_Ip_RamSectionType)0U,

        /* RAM section base address: Start of Mcu_aRamConfig[0]. */

        (uint8 (*)[1U])0x1ffffc00U,

        /* RAM section size: Section base address (must be aligned to 4 bytes). */

        (Ram_Ip_RamSizeType *)0x00000400U,

        /* RAM default value. */
        (uint64) ( ((uint64)0x00U << 0U) | ((uint64)0x00U << 8U) | ((uint64)0x00U << 16U) | ((uint64)0x00U << 24U) | ((uint64)0x00U << 32U) | ((uint64)0x00U << 40U) | ((uint64)0x00U << 48U) | ((uint64)0x00U << 56U) ),

        /* RAM section write size (maximum allowed: 8). */
        (Ram_Ip_RamWriteSizeType)8U

    } /* End of Mcu_aRamConfigPB[0]. */

};
#endif /* ifndef MCU_MAX_NORAMCONFIGS */



#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

