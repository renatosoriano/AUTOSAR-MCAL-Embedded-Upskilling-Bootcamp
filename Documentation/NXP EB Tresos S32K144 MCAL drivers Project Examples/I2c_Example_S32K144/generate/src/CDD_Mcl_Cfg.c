/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,FLEXIO
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
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
**/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl_Cfg.h"

#if (STD_ON == MCL_DEM_IS_AVAILABLE)
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_MCL_CFG_VENDOR_ID_C                     43
#define CDD_MCL_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_MCL_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define CDD_MCL_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_MCL_CFG_SW_MAJOR_VERSION_C              2
#define CDD_MCL_CFG_SW_MINOR_VERSION_C              0
#define CDD_MCL_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if CDD_Mcl_Cfg.c file and CDD_Mcl_Cfg.h file are of the same vendor */
#if (CDD_MCL_CFG_VENDOR_ID_C != CDD_MCL_CFG_VENDOR_ID)
    #error "CDD_Mcl_Cfg.c and CDD_Mcl_Cfg.h have different vendor ids"
#endif

/* Check if CDD_Mcl_Cfg.c file and CDD_Mcl_Cfg.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_AR_RELEASE_MAJOR_VERSION_C != CDD_MCL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_AR_RELEASE_MINOR_VERSION_C != CDD_MCL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_MCL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg.c and CDD_Mcl_Cfg.h are different"
#endif

/* Check if CDD_Mcl_Cfg.c file and CDD_Mcl_Cfg.h file are of the same Software version */
#if ((CDD_MCL_CFG_SW_MAJOR_VERSION_C != CDD_MCL_CFG_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_SW_MINOR_VERSION_C != CDD_MCL_CFG_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_SW_PATCH_VERSION_C != CDD_MCL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg.c and CDD_Mcl_Cfg.h are different"
#endif

#if (STD_ON == MCL_DEM_IS_AVAILABLE)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if CDD_Mcl_Cfg.c file and Dem header file are of the same Autosar version */
#if ((CDD_MCL_CFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Mcl_Cfg.c and Dem.h are different"
#endif
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
#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Mcl_MemMap.h"


/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType.
*/
const Mcl_DemConfigType Mcl_Dem_Config =
{

    /* DEM error reporting MCL_E_TIMEOUT_FAILURE */
    {(uint32)STD_OFF, 0U}

};


#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Mcl_MemMap.h"

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

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
