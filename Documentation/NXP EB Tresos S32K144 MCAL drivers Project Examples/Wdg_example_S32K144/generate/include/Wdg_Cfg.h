/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
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

#ifndef WDG_CFG_H
#define WDG_CFG_H

/**
*   @file
*
*   @addtogroup Wdg
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
#include "WdgIf_Types.h"
#include "Wdg_Cfg_Defines.h"
#include "Mcal.h"

#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #include "Dem.h"
#endif



#include "Wdg_43_Instance0_VS_0_PBcfg.h"
#include "Wdg_43_Instance1_VS_0_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_VENDOR_ID_CFG                    43
#define WDG_AR_RELEASE_MAJOR_VERSION_CFG     4
#define WDG_AR_RELEASE_MINOR_VERSION_CFG     7
#define WDG_AR_RELEASE_REVISION_VERSION_CFG  0
#define WDG_SW_MAJOR_VERSION_CFG             2
#define WDG_SW_MINOR_VERSION_CFG             0
#define WDG_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg_43_Instance0_VS_0_PBcfg.h header file are of the same vendor */
#if (WDG_VENDOR_ID_CFG != WDG_43_INSTANCE0_VENDOR_ID_VS_0_PBCFG)
#error "Wdg_Cfg.h and Wdg_43_Instance0_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if current file and Wdg_43_Instance0_VS_0_PBcfg.h header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG    != WDG_43_INSTANCE0_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG) || \
(WDG_AR_RELEASE_MINOR_VERSION_CFG    != WDG_43_INSTANCE0_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG) || \
(WDG_AR_RELEASE_REVISION_VERSION_CFG != WDG_43_INSTANCE0_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG))
#error "AutoSar Version Numbers of Wdg_Cfg.h and Wdg_43_Instance0_VS_0_PBcfg.h are different"
#endif
/* Check if current file and Wdg_43_Instance0_VS_0_PBcfg.h header file are of the same Software version */
#if ((WDG_SW_MAJOR_VERSION_CFG != WDG_43_INSTANCE0_SW_MAJOR_VERSION_VS_0_PBCFG) || \
(WDG_SW_MINOR_VERSION_CFG != WDG_43_INSTANCE0_SW_MINOR_VERSION_VS_0_PBCFG) || \
(WDG_SW_PATCH_VERSION_CFG != WDG_43_INSTANCE0_SW_PATCH_VERSION_VS_0_PBCFG))
#error "Software Version Numbers of Wdg_Cfg.h and Wdg_43_Instance0_VS_0_PBcfg.h are different"
#endif

/* Check if current file and Wdg_43_Instance1_VS_0_PBcfg.h header file are of the same vendor */
#if (WDG_VENDOR_ID_CFG != WDG_43_INSTANCE1_VENDOR_ID_VS_0_PBCFG)
#error "Wdg_Cfg.h and Wdg_43_Instance1_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if current file and Wdg_43_Instance1_VS_0_PBcfg.h header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG    != WDG_43_INSTANCE1_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG) || \
(WDG_AR_RELEASE_MINOR_VERSION_CFG    != WDG_43_INSTANCE1_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG) || \
(WDG_AR_RELEASE_REVISION_VERSION_CFG != WDG_43_INSTANCE1_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG))
#error "AutoSar Version Numbers of Wdg_Cfg.h and Wdg_43_Instance1_VS_0_PBcfg.h are different"
#endif
/* Check if current file and Wdg_43_Instance1_VS_0_PBcfg.h header file are of the same Software version */
#if ((WDG_SW_MAJOR_VERSION_CFG != WDG_43_INSTANCE1_SW_MAJOR_VERSION_VS_0_PBCFG) || \
(WDG_SW_MINOR_VERSION_CFG != WDG_43_INSTANCE1_SW_MINOR_VERSION_VS_0_PBCFG) || \
(WDG_SW_PATCH_VERSION_CFG != WDG_43_INSTANCE1_SW_PATCH_VERSION_VS_0_PBCFG))
#error "Software Version Numbers of Wdg_Cfg.h and Wdg_43_Instance1_VS_0_PBcfg.h are different"
#endif

 #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Mcal header file are of the same Autosar version */
     #if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
          (WDG_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Cfg.h and Mcal.h are different"
     #endif

    #if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG    != WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_AR_RELEASE_MINOR_VERSION_CFG    != WDGIF_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_Cfg.h and WdgIf_Types.h are different"
    #endif
    
    #if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if source file and Dem header file are of the same Autosar version */
        #if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
            (WDG_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Wdg_Cfg.h and Dem.h are different"
        #endif
    #endif
    
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


#define WDG_START_SEC_CONST_UNSPECIFIED
#include "Wdg_MemMap.h"

/**
* @brief Dem error codes
*/

 extern const Mcal_DemErrorType Wdg_E_Disable_Rejected;

 extern const Mcal_DemErrorType Wdg_E_Mode_Failed;

#define WDG_STOP_SEC_CONST_UNSPECIFIED
#include "Wdg_MemMap.h"

/**
* @brief Dem error codes
*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define WDG_43_INSTANCE0_CONFIG_EXT WDG_43_INSTANCE0_CONFIG_VS_0_PB

#define WDG_43_INSTANCE1_CONFIG_EXT WDG_43_INSTANCE1_CONFIG_VS_0_PB


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDG_CFG_H */
