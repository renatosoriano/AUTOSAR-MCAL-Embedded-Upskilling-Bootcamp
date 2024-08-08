/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO
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
*   @file
*
*   @defgroup uart_driver UART Driver
*   @addtogroup  uart_driver UART Driver
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

#include "StandardTypes.h"
#include "CDD_Uart_Cfg.h"
#include "Uart_Ipw_Cfg.h"
#include "CDD_Uart_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define UART_VS_0_PBCFG_VENDOR_ID_C                     43
#define UART_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define UART_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define UART_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define UART_VS_0_PBCFG_SW_MAJOR_VERSION_C              2
#define UART_VS_0_PBCFG_SW_MINOR_VERSION_C              0
#define UART_VS_0_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Uart_Cfg.h */
#if (UART_VS_0_PBCFG_VENDOR_ID_C != UART_CFG_VENDOR_ID)
    #error "Uart_VS_0_PBcfg.c and CDD_Uart_Cfg.h have different vendor ids"
#endif
#if ((UART_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != UART_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (UART_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C    != UART_CFG_AR_RELEASE_MINOR_VERSION) || \
     (UART_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != UART_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Uart_VS_0_PBcfg.c and CDD_Uart_Cfg.h are different"
#endif
#if ((UART_VS_0_PBCFG_SW_MAJOR_VERSION_C != UART_CFG_SW_MAJOR_VERSION) || \
     (UART_VS_0_PBCFG_SW_MINOR_VERSION_C != UART_CFG_SW_MINOR_VERSION) || \
     (UART_VS_0_PBCFG_SW_PATCH_VERSION_C != UART_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Uart_VS_0_PBcfg.c and CDD_Uart_Cfg.h are different"
#endif

/* Checks against Uart_Ipw_Cfg.h */
#if (UART_VS_0_PBCFG_VENDOR_ID_C != UART_IPW_CFG_VENDOR_ID)
    #error "Uart_VS_0_PBcfg.c and Uart_Ipw_Cfg.h have different vendor ids"
#endif
#if ((UART_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != UART_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (UART_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C    != UART_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (UART_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != UART_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Uart_VS_0_PBcfg.c and Uart_Ipw_Cfg.h are different"
#endif
#if ((UART_VS_0_PBCFG_SW_MAJOR_VERSION_C != UART_IPW_CFG_SW_MAJOR_VERSION) || \
     (UART_VS_0_PBCFG_SW_MINOR_VERSION_C != UART_IPW_CFG_SW_MINOR_VERSION) || \
     (UART_VS_0_PBCFG_SW_PATCH_VERSION_C != UART_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Uart_VS_0_PBcfg.c and Uart_Ipw_Cfg.h are different"
#endif

/* Checks against CDD_Uart_Defines.h */
#if (UART_VS_0_PBCFG_VENDOR_ID_C != UART_DEFINES_VENDOR_ID_CFG)
    #error "Uart_VS_0_PBcfg.c and CDD_Uart_Defines.h have different vendor ids"
#endif
#if ((UART_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != UART_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (UART_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C    != UART_DEFINES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (UART_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != UART_DEFINES_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AUTOSAR Version Numbers of Uart_VS_0_PBcfg.c and CDD_Uart_Defines.h are different"
#endif
#if ((UART_VS_0_PBCFG_SW_MAJOR_VERSION_C != UART_DEFINES_SW_MAJOR_VERSION_CFG) || \
     (UART_VS_0_PBCFG_SW_MINOR_VERSION_C != UART_DEFINES_SW_MINOR_VERSION_CFG) || \
     (UART_VS_0_PBCFG_SW_PATCH_VERSION_C != UART_DEFINES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Uart_VS_0_PBcfg.c and CDD_Uart_Defines.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

/* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((UART_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
            (UART_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Uart_VS_0_PBcfg.c and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define UART_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"

/**
* @brief   Export IPW configurations.
*/
UART_IPW_CONFIG_EXT

#define UART_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Uart_MemMap.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define UART_CORE_ID     ((uint32)0U)


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define UART_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Uart_VS_0_PBcfg_c_REF_1 <MA>_MemMap.h is included
                 after each section define in order to set the current memory section as defined by AUTOSAR.
* @violates @ref Uart_VS_0_PBcfg_c_REF_2 This violation is not fixed
                  since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*/
#include "Uart_MemMap.h"


/**
* @brief          Configuration for Uart Channel 0
*
*
*/
const Uart_ChannelConfigType Uart_ChannelConfig_0_VS_0 =
{
    0, /*Uart Channel Id*/

#if (UART_MULTICORE_SUPPORT == STD_ON)
    UART_CORE_ID, /*Uart Channel Core Id*/
#endif
    4000000U, /* Clock frequency */
    &Uart_Ipw_xHwConfigPB_0_VS_0  /* Uart Hardware config */
};

/**
* @brief          Configuration for Uart Channel 1
*
*
*/
const Uart_ChannelConfigType Uart_ChannelConfig_1_VS_0 =
{
    1, /*Uart Channel Id*/

#if (UART_MULTICORE_SUPPORT == STD_ON)
    UART_CORE_ID, /*Uart Channel Core Id*/
#endif
    4000000U, /* Clock frequency */
    &Uart_Ipw_xHwConfigPB_1_VS_0  /* Uart Hardware config */
};

/**
* @brief          Configuration for Uart Channel 2
*
*
*/
const Uart_ChannelConfigType Uart_ChannelConfig_2_VS_0 =
{
    2, /*Uart Channel Id*/

#if (UART_MULTICORE_SUPPORT == STD_ON)
    UART_CORE_ID, /*Uart Channel Core Id*/
#endif
    4000000U, /* Clock frequency */
    &Uart_Ipw_xHwConfigPB_2_VS_0  /* Uart Hardware config */
};




        
/**
* @brief          Configuration for Uart driver
*
*
*/
static const Uart_ConfigType Uart_xConfig =
{

    
#if (UART_MULTICORE_SUPPORT == STD_ON)
    UART_CORE_ID,
#endif
    {


        &Uart_ChannelConfig_0_VS_0

    ,
            
        &Uart_ChannelConfig_1_VS_0

    ,
            
        &Uart_ChannelConfig_2_VS_0




    }
};



/**
* @brief          Uart Configuration data for Uart_pxPBcfgVariantPredefined.
*
*/
/**
* @violates @ref Uart_VS_0_PBcfg_c_REF_3 Function with external linkage is not visible.
* @violates @ref Uart_VS_0_PBcfg_c_REF_4 These functions
                 represent the API of the driver. External linkage is needed to "export" the API.
* @violates @ref Uart_VS_0_PBcfg_c_REF_5 This violation is due to exporting
                 the externally configured initialization structure used by the "<MA>_Init" function.
*/
const Uart_ConfigType* const Uart_pxPBcfgVariantPredefined[UART_MAX_PARTITIONS] =
{

    &Uart_xConfig
    };


#define UART_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Uart_VS_0_PBcfg_c_REF_1 <MA>_MemMap.h is included
                 after each section define in order to set the current memory section as defined by AUTOSAR.
* @violates @ref Uart_VS_0_PBcfg_c_REF_2 This violation is not fixed
                  since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*/
#include "Uart_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}

/** @} */

#endif
