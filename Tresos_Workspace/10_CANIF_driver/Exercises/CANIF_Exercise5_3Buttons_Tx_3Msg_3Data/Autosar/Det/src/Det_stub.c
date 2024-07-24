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
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
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
*   @file Det_stub.c
*
*   @addtogroup DET_MODULE
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
#include "Mcal.h"
#include "OsIf.h"
#include "Det_stub.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


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
#define DET_START_SEC_CODE
#include "Det_MemMap.h"

/*================================================================================================*/
/**
* @brief            Tests if an expected error has been reported to DET
* @details          Tests if an expected error has been reported to DET
*
* @param[in]        ModuleId - ID of the module reporting the error
* @param[in]        InstanceId - ID of the Instance reporting the error
* @param[in]        APIId - ID of the API where the error has been generated from
* @param[in]        ErrorId - Error Code

* @return           boolean - true in case expected error has been found
*
*/
boolean Det_TestLastReportError(uint16 ModuleId,
                                uint8 InstanceId,
                                uint8 ApiId,
                                uint8 ErrorId)
{
    boolean result = FALSE;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    result = (Det_ModuleId[u32CoreId] == ModuleId) && (Det_InstanceId[u32CoreId] == InstanceId) &&
                     (Det_ApiId[u32CoreId] == ApiId) && (Det_ErrorId[u32CoreId] == ErrorId);

    Det_ModuleId[u32CoreId] = 0;
    Det_InstanceId[u32CoreId] = 0;
    Det_ApiId[u32CoreId] = 0;
    Det_ErrorId[u32CoreId] = 0;

    return result;
}


/*================================================================================================*/
/**
* @brief            Tests if an expected error has been reported to DET
* @details          Tests if an expected error has been reported to DET
*
* @param[in]        ModuleId - ID of the module reporting the error
* @param[in]        InstanceId - ID of the Instance reporting the error
* @param[in]        APIId - ID of the API where the error has been generated from
* @param[in]        ErrorId - Error Code

* @return           boolean - true in case expected error has been found
*
*/
boolean Det_TestLastReportRuntimeError(uint16 ModuleId,
                                       uint8 InstanceId,
                                       uint8 ApiId,
                                       uint8 ErrorId)
{
    boolean result = FALSE;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    result = (Det_RuntimeModuleId[u32CoreId] == ModuleId) && (Det_RuntimeInstanceId[u32CoreId] == InstanceId) &&
                     (Det_RuntimeApiId[u32CoreId] == ApiId) && (Det_RuntimeErrorId[u32CoreId] == ErrorId);

    Det_RuntimeModuleId[u32CoreId] = 0;
    Det_RuntimeInstanceId[u32CoreId] = 0;
    Det_RuntimeApiId[u32CoreId] = 0;
    Det_RuntimeErrorId[u32CoreId] = 0;

    return result;
}

/*================================================================================================*/
/**
* @brief            Tests if an expected error has been reported to DET
* @details          Tests if an expected error has been reported to DET
*
* @param[in]        ModuleId - ID of the module reporting the error
* @param[in]        InstanceId - ID of the Instance reporting the error
* @param[in]        APIId - ID of the API where the error has been generated from
* @param[in]        ErrorId - Error Code

* @return           boolean - true in case expected error has been found
*
*/
boolean Det_TestLastReportTransientFault(uint16 ModuleId,
                                         uint8 InstanceId,
                                         uint8 ApiId,
                                         uint8 FaultId)
{
    boolean result = FALSE;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    result = (Det_TransientModuleId[u32CoreId] == ModuleId) && (Det_TransientInstanceId[u32CoreId] == InstanceId) &&
                     (Det_TransientApiId[u32CoreId] == ApiId) && (Det_TransientFaultId[u32CoreId] == FaultId);

    Det_TransientModuleId[u32CoreId] = 0;
    Det_TransientInstanceId[u32CoreId] = 0;
    Det_TransientApiId[u32CoreId] = 0;
    Det_TransientFaultId[u32CoreId] = 0;

    return result;
}
/*================================================================================================*/
/**
* @brief            Tests if an error has been reported to DET
* @details          Tests if an error has been reported to DET
*
* @return           boolean - true in case of NO error has been reported to DET
*
*/
boolean Det_TestNoError(void) {
    boolean result = FALSE;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    result = Det_ModuleId[u32CoreId] || Det_InstanceId[u32CoreId] || Det_ApiId[u32CoreId] || Det_ErrorId[u32CoreId];

    Det_ModuleId[u32CoreId] = 0;
    Det_InstanceId[u32CoreId] = 0;
    Det_ApiId[u32CoreId] = 0;
    Det_ErrorId[u32CoreId] = 0;
    return !result;
}

/*================================================================================================*/
/**
* @brief            Tests if an runtime error has been reported to DET
* @details          Tests if an runtime error has been reported to DET
*
* @return           boolean - true in case of NO error has been reported to DET
*
*/
boolean Det_TestNoRuntimeError(void) {
    boolean result = FALSE;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    result = Det_RuntimeModuleId[u32CoreId] || Det_RuntimeInstanceId[u32CoreId] || Det_RuntimeApiId[u32CoreId] || Det_RuntimeErrorId[u32CoreId];

    Det_RuntimeModuleId[u32CoreId] = 0;
    Det_RuntimeInstanceId[u32CoreId] = 0;
    Det_RuntimeApiId[u32CoreId] = 0;
    Det_RuntimeErrorId[u32CoreId] = 0;
    return !result;
}

/*================================================================================================*/
/**
* @brief            Tests if an transient error has been reported to DET
* @details          Tests if an transient error has been reported to DET
*
* @return           boolean - true in case of NO error has been reported to DET
*
*/
boolean Det_TestNoTransientFault(void) {
    boolean result = FALSE;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    result = Det_TransientModuleId[u32CoreId] || Det_TransientInstanceId[u32CoreId] || Det_TransientApiId[u32CoreId] || Det_TransientFaultId[u32CoreId];

    Det_TransientModuleId[u32CoreId] = 0;
    Det_TransientInstanceId[u32CoreId] = 0;
    Det_TransientApiId[u32CoreId] = 0;
    Det_TransientFaultId[u32CoreId] = 0;
    return !result;
}

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
