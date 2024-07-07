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

#ifndef DET_STUB_H
#define DET_STUB_H

/**
*   @file Det_stub.h
*
*   @addtogroup DET_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif



/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Det.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/


/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/
#define DET_START_SEC_CODE
#include "Det_MemMap.h"

extern boolean Det_TestLastReportError(uint16 ModuleId,
                                       uint8 InstanceId,
                                       uint8 ApiId,
                                       uint8 ErrorId);
extern boolean Det_TestLastReportRuntimeError(uint16 ModuleId,
                                              uint8 InstanceId,
                                              uint8 ApiId,
                                              uint8 ErrorId);
extern boolean Det_TestLastReportTransientFault(uint16 ModuleId,
                                                uint8 InstanceId,
                                                uint8 ApiId,
                                                uint8 FaultId);
extern boolean Det_TestNoError(void);
extern boolean Det_TestNoRuntimeError(void);
extern boolean Det_TestNoTransientFault(void);

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DET_STUB_H */
