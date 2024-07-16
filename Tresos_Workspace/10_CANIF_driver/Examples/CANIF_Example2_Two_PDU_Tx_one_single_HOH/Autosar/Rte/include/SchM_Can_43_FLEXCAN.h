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
*   @file    SchM_Can_43_FLEXCAN.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Rte - module interface
*   @details This file contains the functions prototypes and data types of the AUTOSAR Rte.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup RTE_MODULE
*   @{
*/
#ifndef SCHM_CAN_43_FLEXCAN_H
#define SCHM_CAN_43_FLEXCAN_H

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION     4
#define SCHM_CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION     7
#define SCHM_CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION  0
#define SCHM_CAN_43_FLEXCAN_SW_MAJOR_VERSION             2
#define SCHM_CAN_43_FLEXCAN_SW_MINOR_VERSION             0
#define SCHM_CAN_43_FLEXCAN_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define NUMBER_OF_CORES         (uint8)(1U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#ifdef MCAL_TESTING_ENVIRONMENT
/** 
@brief   This function checks that all entered exclusive areas were also exited. 
@details This function checks that all entered exclusive areas were also exited. The check
         is done by verifying that all reentry_guard_* static variables are back to the
         zero value.
    
@param[in]     void       No input parameters
@return        void       This function does not return a value. Test asserts are used instead. 

@pre  None
@post None

@remarks Covers 
@remarks Implements 
*/
void SchM_Check_can_43_FLEXCAN(void);
#endif /*MCAL_TESTING_ENVIRONMENT*/

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_02(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_03(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_03(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_04(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_04(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_05(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_05(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_06(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_06(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_07(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_07(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_08(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_08(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_09(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_09(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_10(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_10(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_11(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_11(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_12(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_12(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_13(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_13(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_14(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_14(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_15(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_15(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_16(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_16(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_17(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_17(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_19(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_19(void);

extern void SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_20(void);
extern void SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_20(void);


void Can_43_FLEXCAN_MainFunction_Write(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_0(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_1(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_2(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_3(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_4(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_5(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_6(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_7(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_8(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_9(void);
void Can_43_FLEXCAN_MainFunction_Write_CanMainFunctionRWPeriods_10(void);
void Can_43_FLEXCAN_MainFunction_Read(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_0(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_1(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_2(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_3(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_4(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_5(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_6(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_7(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_8(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_9(void);
void Can_43_FLEXCAN_MainFunction_Read_CanMainFunctionRWPeriods_10(void);
void Can_43_FLEXCAN_MainFunction_BusOff(void);
void Can_43_FLEXCAN_MainFunction_Wakeup(void);
void Can_43_FLEXCAN_MainFunction_Mode(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_CAN_43_FLEXCAN_H */
