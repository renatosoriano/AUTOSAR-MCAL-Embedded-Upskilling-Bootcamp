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
*   @file       Power_Ip_Private.c
*   @version    2.0.0
*
*   @brief
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
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
#include "Power_Ip.h"
#include "Power_Ip_Private.h"
#include "OsIf.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_PRIVATE_VENDOR_ID_C                      43
#define POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_PRIVATE_SW_MAJOR_VERSION_C               2
#define POWER_IP_PRIVATE_SW_MINOR_VERSION_C               0
#define POWER_IP_PRIVATE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and OsIf header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Power_Ip_Private.c and OsIf.h are different"
    #endif
#endif

/* Check if current file and Power_Ip header file are of the same Autosar version */
#if (POWER_IP_PRIVATE_VENDOR_ID_C != POWER_IP_VENDOR_ID)
    #error "Power_Ip_Private.c and Power_Ip.h have different vendor ids"
#endif
/* Check if current file and Power_Ip header file are of the same Autosar version */
#if ((POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C    != POWER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C    != POWER_IP_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION_C != POWER_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_Private.c and Power_Ip.h are different"
#endif
/* Check if current file and Power_Ip header file are of the same Software version */
#if ((POWER_IP_PRIVATE_SW_MAJOR_VERSION_C != POWER_IP_SW_MAJOR_VERSION) || \
     (POWER_IP_PRIVATE_SW_MINOR_VERSION_C != POWER_IP_SW_MINOR_VERSION) || \
     (POWER_IP_PRIVATE_SW_PATCH_VERSION_C != POWER_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_Private.c and Power_Ip.h are different"
#endif

/* Check if current file and Power_Ip_Private header file are of the same Autosar version */
#if (POWER_IP_PRIVATE_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip_Private.c and Power_Ip_Private.h have different vendor ids"
#endif
/* Check if current file and Power_Ip_Private header file are of the same Autosar version */
#if ((POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION_C    != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION_C    != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_Private.c and Power_Ip_Private.h are different"
#endif
/* Check if current file and Power_Ip_Private header file are of the same Software version */
#if ((POWER_IP_PRIVATE_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_PRIVATE_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_PRIVATE_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_Private.c and Power_Ip_Private.h are different"
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

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
void Power_Ip_ReportPowerErrors(Power_Ip_ReportErrorType Error, uint8 ErrorCode)
{
    Power_Ip_pfReportErrorsCallback(Error, ErrorCode);
}

void Power_Ip_ReportPowerErrorsEmptyCallback(Power_Ip_ReportErrorType Error, uint8 ErrorCode)
{
    /* No implementation */
    (void)Error;
    (void)ErrorCode;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Power_Ip_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
void Power_Ip_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(POWER_IP_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, POWER_IP_TIMEOUT_TYPE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Power_Ip_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
boolean Power_Ip_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks)
{
    boolean RetVal = FALSE;
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, POWER_IP_TIMEOUT_TYPE);

    if (*ElapsedTimeInOut >= TimeoutTicks)
    {
        RetVal = TRUE;
    }
    return RetVal;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

