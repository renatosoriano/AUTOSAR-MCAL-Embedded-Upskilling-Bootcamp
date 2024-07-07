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
*   @file       Power_Ip_PBcfg.c
*   @version    2.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup POWER_DRIVER_CONFIGURATION Power Ip Driver
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
#include "Power_Ip_PBcfg.h"
#include "Power_Ip.h"
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_PBCFG_VENDOR_ID_C                      43
#define POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_PBCFG_SW_MAJOR_VERSION_C               2
#define POWER_IP_PBCFG_SW_MINOR_VERSION_C               0
#define POWER_IP_PBCFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_PBcfg.c file and Power_Ip_PBcfg.h file are of the same vendor */
#if (POWER_IP_PBCFG_VENDOR_ID_C != POWER_IP_PBCFG_VENDOR_ID)
    #error "Power_Ip_PBcfg.c and Power_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if Power_Ip_Type.c file and Power_Ip_PBcfg.h file are of the same Autosar version */
#if ((POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_PBcfg.c and Power_Ip_PBcfg.h are different"
#endif

/* Check if Power_Ip_PBcfg.c file and Power_Ip_PBcfg.h file are of the same Software version */
#if ((POWER_IP_PBCFG_SW_MAJOR_VERSION_C != POWER_IP_PBCFG_SW_MAJOR_VERSION) || \
     (POWER_IP_PBCFG_SW_MINOR_VERSION_C != POWER_IP_PBCFG_SW_MINOR_VERSION) || \
     (POWER_IP_PBCFG_SW_PATCH_VERSION_C != POWER_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_PBcfg.c and Power_Ip_PBcfg.h are different"
#endif

/* Check if Power_Ip_PBcfg.c file and Power_Ip.h file are of the same vendor */
#if (POWER_IP_PBCFG_VENDOR_ID_C != POWER_IP_VENDOR_ID)
    #error "Power_Ip_PBcfg.c and Power_Ip.h have different vendor ids"
#endif

/* Check if Power_Ip_PBcfg.c file and Power_Ip.h file are of the same Autosar version */
#if ((POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != POWER_IP_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != POWER_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_PBcfg.c and Power_Ip.h are different"
#endif

/* Check if Power_Ip_PBcfg.c file and Power_Ip.h file are of the same Software version */
#if ((POWER_IP_PBCFG_SW_MAJOR_VERSION_C != POWER_IP_SW_MAJOR_VERSION) || \
     (POWER_IP_PBCFG_SW_MINOR_VERSION_C != POWER_IP_SW_MINOR_VERSION) || \
     (POWER_IP_PBCFG_SW_PATCH_VERSION_C != POWER_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_PBcfg.c and Power_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_PBcfg.c file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_PBcfg.c and StandardTypes.h are different"
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







/**
* @brief          Initialization data for RCM hw IP.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/

static const Power_Ip_RCM_ConfigType Power_Ip_RCM_ConfigPB =
{
    /* Reset Pin Control register (RCM_RPC) */
    (
        RCM_RPC_STOP_ALL_FILTERING_DISABLE_U32 |
        RCM_RPC_NORMAL_ALL_FILTERING_DISABLE_U32 |
        RCM_RPC_RSTFLTSEL((uint32)(0U))
    ),
    /* System Reset Interrupt Enable Register (RCM_SRIE) */
    (
        RCM_SRIE_SACKERR_INT_DIS_U32 |
        RCM_SRIE_MDM_AP_INT_DIS_U32 |
        RCM_SRIE_SSW_INT_DIS_U32 |
        RCM_SRIE_LOCKUP_INT_DIS_U32 |
        RCM_SRIE_JTAG_INT_DIS_U32 |
        RCM_SRIE_GIE_INT_DIS_U32 |
        RCM_SRIE_PIN_INT_DIS_U32 |
        RCM_SRIE_WDOG_INT_DIS_U32 |
        RCM_SRIE_CMU_INT_DIS_U32 |
        RCM_SRIE_LOL_INT_DIS_U32 |
        RCM_SRIE_LOC_INT_DIS_U32 |
        RCM_SRIE_DELAY_10_LPO_CYCLES_U32
    )
};




/**
* @brief          Initialization data for PMC hw IP.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
static const Power_Ip_PMC_ConfigType Power_Ip_PMC_ConfigPB =
{
        /* Low Voltage Detect Status and Control 1 Register (PMC_LVDSC1). This register only exist on 1xx series of devices */
    (
        PMC_LVDSC1_LVD_DISABLE_U8 |
        PMC_LVDSC1_LVDRE_DISABLE_U8
    ),
        /* Low Voltage Detect Status and Control 2 Register (PMC_LVDSC2) */
    (
        PMC_LVDSC2_LVW_DISABLE_U8
    ),
    /* Regulator Status and Control Register (PMC_REGSC) */
    (
        PMC_REGSC_LPO_ENABLE_U8 |
        PMC_REGSC_CLKBIAS_ENABLE_U8 |
        PMC_REGSC_BIAS_DISABLE_U8
    )
    };




/**
* @brief          Initialization data for SMC hw IP.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
static const Power_Ip_SMC_ConfigType Power_Ip_SMC_ConfigPB =
{
    /* Allowed modes */
    (
        SMC_PMPROT_HSRUN_NOT_ALLOWED_U32 |
        SMC_PMPROT_VLP_NOT_ALLOWED_U32
    ),
};




#if(STD_ON == POWER_IP_AEC_SUPPORT)
/**
* @brief          Initialization data for AEC_AE_RSTGEN_CFG[RSTGEN_CFG] register
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
static const Power_Ip_AEC_ConfigType Power_Ip_AEC_ConfigPB =
{
    (
        AEC_AE_RSTGEN_CFG_REGS_OTP_ENABLE_U16 |
        AEC_AE_RSTGEN_CFG_CANPHY_DISABLE_U16 |
        AEC_AE_RSTGEN_CFG_LINPHY_HP_DISABLE_U16 |
        AEC_AE_RSTGEN_CFG_LINPHY_LP_DISABLE_U16 |
        AEC_AE_RSTGEN_CFG_GDU_DISABLE_U16 |
        AEC_AE_RSTGEN_CFG_HVI_DISABLE_U16 |
        AEC_AE_RSTGEN_CFG_DPGA_DISABLE_U16 |
        AEC_AE_RSTGEN_CFG_TEMPSENSOR_DISABLE_U16 |
        AEC_AE_RSTGEN_CFG_CXPI_DISABLE_U16
    ),
};
#endif



/**
* @brief          Initialization mode data.
* @details        Static configuration realized by calling Mcu_SetMode() API.
*
*/
const Power_Ip_ModeConfigType Power_Ip_aModeConfigPB[1U] =
{
    /* Start of Mcu_aModeConfig[0] */
    {
        /* Mode Configuration ID. */
        (Power_Ip_ModeType)0U,

        /* The Power Mode name (code). */
        POWER_IP_RUN_MODE,

        /* The Sleep On Exit configuration */
        FALSE,
    } /* End of Mcu_aModeConfig[0] */
};



/**
* @brief          Initialization data for different hw IPs.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
const Power_Ip_HwIPsConfigType Power_Ip_HwIPsConfigPB =
{
    /* Configuration for RCM (Reset Control Module) hardware IP. */
    &Power_Ip_RCM_ConfigPB,

    /* Configuration for PMC (Power Management Controller) hardware IP */
    &Power_Ip_PMC_ConfigPB,

    /* Configuration for SMC hardware IP. */
    &Power_Ip_SMC_ConfigPB,
    
#if (STD_ON == POWER_IP_AEC_SUPPORT)
    /* Configuration for AEC hardware IP. */
    &Power_Ip_AEC_ConfigPB,
#endif

};



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

