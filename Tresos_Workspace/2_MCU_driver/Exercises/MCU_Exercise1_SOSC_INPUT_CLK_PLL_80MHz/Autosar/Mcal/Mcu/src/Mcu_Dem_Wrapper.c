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
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   Copyright 2020-2023 NXP Semiconductors
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
*   @file       Mcu_Dem_Wrapper.c
*   @version    2.0.0
*
*   @brief      AUTOSAR Mcu - Implements the AUTOSAR MCU driver functionality.
*   @details    Implements the AUTOSAR MCU driver. All the API functions are described by AUTOSAR
*
*   @addtogroup MCU_DRIVER Mcu Driver
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
#include "Mcu_Dem_Wrapper.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_DEM_WRAPPER_VENDOR_ID_C                      43
#define MCU_DEM_WRAPPER_AR_RELEASE_MAJOR_VERSION_C       4
#define MCU_DEM_WRAPPER_AR_RELEASE_MINOR_VERSION_C       7
#define MCU_DEM_WRAPPER_AR_RELEASE_REVISION_VERSION_C    0
#define MCU_DEM_WRAPPER_SW_MAJOR_VERSION_C               2
#define MCU_DEM_WRAPPER_SW_MINOR_VERSION_C               0
#define MCU_DEM_WRAPPER_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mcu_Dem_Wrapper.c file and Mcu_Dem_Wrapper.h file are of the same vendor */
#if (MCU_DEM_WRAPPER_VENDOR_ID_C != MCU_DEM_WRAPPER_VENDOR_ID)
    #error "Mcu_Dem_Wrapper.c and Mcu_Dem_Wrapper.h have different vendor ids"
#endif

/* Check if Mcu_Dem_Wrapper.c file and Mcu_Dem_Wrapper.h file are of the same Autosar version */
#if ((MCU_DEM_WRAPPER_AR_RELEASE_MAJOR_VERSION_C != MCU_DEM_WRAPPER_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_DEM_WRAPPER_AR_RELEASE_MINOR_VERSION_C != MCU_DEM_WRAPPER_AR_RELEASE_MINOR_VERSION) || \
     (MCU_DEM_WRAPPER_AR_RELEASE_REVISION_VERSION_C != MCU_DEM_WRAPPER_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Dem_Wrapper.c and Mcu_Dem_Wrapper.h are different"
#endif

/* Check if Mcu_Dem_Wrapper.c file and Mcu_Dem_Wrapper.h file are of the same Software version */
#if ((MCU_DEM_WRAPPER_SW_MAJOR_VERSION_C != MCU_DEM_WRAPPER_SW_MAJOR_VERSION) || \
     (MCU_DEM_WRAPPER_SW_MINOR_VERSION_C != MCU_DEM_WRAPPER_SW_MINOR_VERSION) || \
     (MCU_DEM_WRAPPER_SW_PATCH_VERSION_C != MCU_DEM_WRAPPER_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Dem_Wrapper.c and Mcu_Dem_Wrapper.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
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
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"


#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief    Reports timeout error to DEM.
* @details  Checks if the timeout expired and reports the timeout error to DEM if that is the case.
*
* @param[in]  u32Timeout  Maximum timeout to be waited.
*
* @return     void.
*/
void Mcu_ReportDemTimeoutError(void)
{
    if ((uint32)STD_ON == Mcu_pDemCfgPtr->ErrorTimeoutFailureCfg.state)
    {
        /* According to requirement [SWS_Dem_00183] from the ASR 4.4 "AUTOSAR_SWS_DiagnosticEventManager" document,
         * "BSW modules calling Dem_SetEventStatus can safely ignore the return value." */
        (void)Dem_SetEventStatus((Dem_EventIdType)Mcu_pDemCfgPtr->ErrorTimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
    }
 }

/**
* @brief    Reports timeout error to DEM.
* @details  Checks if the switch mode failure and reports the timeout error to DEM if that is the case.
*
* @param[in]  void.
*
* @return     void.
*/
void Mcu_ReportDemSwitchModeError(void)
{
    if ((uint32)STD_ON == Mcu_pDemCfgPtr->ErrorSwitchModeFailureCfg.state)
    {
        /* According to requirement [SWS_Dem_00183] from the ASR 4.4 "AUTOSAR_SWS_DiagnosticEventManager" document,
         * "BSW modules calling Dem_SetEventStatus can safely ignore the return value." */
        (void)Dem_SetEventStatus((Dem_EventIdType)Mcu_pDemCfgPtr->ErrorSwitchModeFailureCfg.id, DEM_EVENT_STATUS_FAILED);
    }
}
#endif


#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
