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
*   @file    SchM_Adc.c
*   @version 2.0.0
*
*   @brief   AUTOSAR Rte - module implementation
*   @details This module implements stubs for the AUTOSAR Rte
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup RTE_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Mcal.h"
#include "OsIf.h"
#include "SchM_Adc.h"
#ifdef MCAL_TESTING_ENVIRONMENT
#include "EUnit.h" /* EUnit Test Suite */
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_ADC_AR_RELEASE_MAJOR_VERSION_C     4
#define SCHM_ADC_AR_RELEASE_MINOR_VERSION_C     7
#define SCHM_ADC_AR_RELEASE_REVISION_VERSION_C  0
#define SCHM_ADC_SW_MAJOR_VERSION_C             2
#define SCHM_ADC_SW_MINOR_VERSION_C             0
#define SCHM_ADC_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        #define ISR_STATE_MASK     ((uint32)0x000000C0UL)   /**< @brief DAIF bit I and F */
    #elif  (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
        #define ISR_STATE_MASK     ((uint32)0x00000080UL)   /**< @brief CPSR bit I */
    #else
        #if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
            #define ISR_STATE_MASK     ((uint32)0x000000FFUL)   /**< @brief BASEPRI[7:0] mask */
        #else
            #define ISR_STATE_MASK     ((uint32)0x00000001UL)   /**< @brief PRIMASK bit 0 */
        #endif
    #endif 
#else
    #ifdef MCAL_PLATFORM_S12
        #define ISR_STATE_MASK     ((uint32)0x00000010UL)   /**< @brief I bit of CCR */
    #else
        #define ISR_STATE_MASK     ((uint32)0x00008000UL)   /**< @brief EE bit of MSR */
    #endif
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        #define ISR_ON(msr)            (uint32)(((uint32)(msr) & (uint32)(ISR_STATE_MASK)) != (uint32)(ISR_STATE_MASK))
    #elif  (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
        #define ISR_ON(msr)            (uint32)(((uint32)(msr) & (uint32)(ISR_STATE_MASK)) != (uint32)(ISR_STATE_MASK))
    #else
        #define ISR_ON(msr)            (uint32)(((uint32)(msr) & (uint32)(ISR_STATE_MASK)) == (uint32)0)
    #endif    
#else
    #ifdef MCAL_PLATFORM_S12
        #define ISR_ON(msr)            (uint32)(((uint32)(msr) & (uint32)(ISR_STATE_MASK)) == (uint32)0)
    #else
        #define ISR_ON(msr)            (uint32)((uint32)(msr) & (uint32)(ISR_STATE_MASK))
    #endif
#endif

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define RTE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_00[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_00[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_01[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_01[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_02[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_02[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_03[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_03[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_04[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_04[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_05[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_05[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_10[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_10[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_100[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_100[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_101[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_101[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_102[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_102[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_103[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_103[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_11[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_11[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_12[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_12[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_13[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_13[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_14[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_14[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_15[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_15[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_16[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_16[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_17[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_17[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_18[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_18[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_19[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_19[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_20[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_20[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_21[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_21[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_22[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_22[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_23[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_23[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_24[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_24[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_25[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_25[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_26[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_26[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_27[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_27[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_28[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_28[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_29[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_29[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_30[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_30[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_31[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_31[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_32[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_32[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_33[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_33[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_34[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_34[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_35[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_35[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_36[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_36[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_37[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_37[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_38[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_38[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_39[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_39[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_40[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_40[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_41[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_41[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_42[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_42[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_43[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_43[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_44[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_44[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_45[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_45[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_46[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_46[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_47[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_47[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_48[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_48[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_49[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_49[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_50[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_50[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_51[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_51[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_54[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_54[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_55[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_55[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_56[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_56[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_57[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_57[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_58[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_58[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_59[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_59[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_60[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_60[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_61[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_61[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_62[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_62[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_63[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_63[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_64[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_64[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_65[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_65[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_66[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_66[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_67[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_67[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_68[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_68[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_69[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_69[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_70[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_70[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_71[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_71[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_72[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_72[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_73[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_73[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_74[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_74[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_75[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_75[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_76[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_76[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_77[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_77[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_78[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_78[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_79[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_79[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_80[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_80[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_81[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_81[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_82[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_82[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_83[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_83[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_84[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_84[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_85[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_85[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_86[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_86[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_87[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_87[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_88[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_88[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_89[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_89[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_90[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_90[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_91[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_91[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_92[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_92[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_93[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_93[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_94[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_94[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_95[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_95[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_96[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_96[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_97[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_97[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_98[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_98[NUMBER_OF_CORES];
static volatile uint32 msr_ADC_EXCLUSIVE_AREA_99[NUMBER_OF_CORES];
static volatile uint32 reentry_guard_ADC_EXCLUSIVE_AREA_99[NUMBER_OF_CORES];

#define RTE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#ifndef _COSMIC_C_S32K1XX_
/*================================================================================================*/
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
uint32 Adc_schm_read_msr(void); 
#endif /*ifndef _COSMIC_C_S32K1XX_*/
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#if (defined(_GREENHILLS_C_S32K1XX_) || defined(_CODEWARRIOR_C_S32K1XX_))
/*================================================================================================*/
/** 
* @brief   This macro returns the MSR register value (32 bits). 
* @details This macro function implementation returns the MSR register value in r3 (32 bits). 
*     
* @pre  None
* @post None
* 
*/
#ifdef MCAL_PLATFORM_ARM
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
ASM_KEYWORD uint32 Adc_schm_read_msr(void)
{
    mrs x0, S3_3_c4_c2_1
}
#elif  (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
ASM_KEYWORD uint32 Adc_schm_read_msr(void)
{
    mrs r0, CPSR
}
#else
ASM_KEYWORD uint32 Adc_schm_read_msr(void)
{
#if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
    mrs r0, BASEPRI
#else
    mrs r0, PRIMASK
#endif
}
#endif
#else
#ifdef MCAL_PLATFORM_S12
ASM_KEYWORD uint32 Adc_schm_read_msr(void)
{
   tfr ccr, d6
}
#else
ASM_KEYWORD uint32 Adc_schm_read_msr(void)
{
    mfmsr r3
}
#endif
#endif
#endif /*#ifdef GHS||CW*/

#ifdef _DIABDATA_C_S32K1XX_
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
#ifdef MCAL_PLATFORM_ARM
uint32 Adc_schm_read_msr(void)
{
    register uint32 reg_tmp;
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        __asm volatile( " mrs %x0, DAIF " : "=r" (reg_tmp) );
    #elif  (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
        __asm volatile( " mrs %0, CPSR " : "=r" (reg_tmp) );
    #else
        #if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
        __asm volatile( " mrs %0, basepri " : "=r" (reg_tmp) );
        #else
        __asm volatile( " mrs %0, primask " : "=r" (reg_tmp) );
        #endif
    #endif
    return (uint32)reg_tmp;
}
#else
ASM_KEYWORD uint32 Adc_schm_read_msr(void)
{
    mfmsr r3
}    
#endif  /* MCAL_PLATFORM_ARM */

#endif   /* _DIABDATA_C_S32K1XX_*/

#ifdef _COSMIC_C_S32K1XX_
/*================================================================================================*/
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/

#ifdef MCAL_PLATFORM_S12
    #define Adc_schm_read_msr()  ASM_KEYWORD("tfr ccr, d6")
#else
    #define Adc_schm_read_msr() ASM_KEYWORD("mfmsr r3")
#endif

#endif  /*Cosmic compiler only*/


#ifdef _HITECH_C_S32K1XX_
/*================================================================================================*/
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
uint32 Adc_schm_read_msr(void)
{
    uint32 result;
    __asm volatile("mfmsr %0" : "=r" (result) :);
    return result;
}

#endif  /*HighTec compiler only*/
 /*================================================================================================*/
#ifdef _LINARO_C_S32K1XX_
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
uint32 Adc_schm_read_msr(void)
{
    register uint32 reg_tmp;
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        __asm volatile( " mrs %x0, DAIF " : "=r" (reg_tmp) );
    #elif  (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
        __asm volatile( " mrs %0, CPSR " : "=r" (reg_tmp) );
    #else
        #if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
        __asm volatile( " mrs %0, basepri " : "=r" (reg_tmp) );
        #else
        __asm volatile( " mrs %0, primask " : "=r" (reg_tmp) );
        #endif
    #endif
    return (uint32)reg_tmp;
}
#endif   /* _LINARO_C_S32K1XX_*/
/*================================================================================================*/

#ifdef _ARM_DS5_C_S32K1XX_
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
uint32 Adc_schm_read_msr(void)
{
    register uint32 reg_tmp;
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        __asm volatile( " mrs %x0, DAIF " : "=r" (reg_tmp) );
    #elif  (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
        __asm volatile( " mrs %0, CPSR " : "=r" (reg_tmp) );
    #else
        #if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
        __asm volatile( " mrs %0, basepri " : "=r" (reg_tmp) );
        #else
        __asm volatile( " mrs %0, primask " : "=r" (reg_tmp) );
        #endif
    #endif
    return (uint32)reg_tmp;
}
#endif   /* _ARM_DS5_C_S32K1XX_ */

#ifdef _IAR_C_S32K1XX_
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
uint32 Adc_schm_read_msr(void)
{
    register uint32 reg_tmp;

#if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
   __asm volatile( " mrs %0, basepri " : "=r" (reg_tmp) );
#else
   __asm volatile( " mrs %0, primask " : "=r" (reg_tmp) );
#endif

    return (uint32)reg_tmp;
}
#endif   /* _IAR_C_S32K1XX_ */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_00[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_00[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_00[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_00[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_00[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_00[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_01[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_01[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_01[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_01[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_01[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_01[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_02(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_02[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_02[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_02[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_02[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_02[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_02[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_03[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_03[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_03[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_03[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_03[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_03[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_04[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_04[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_04[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_04[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_04[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_04[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_05[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_05[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_05[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_05[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_05[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_05[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_10[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_10[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_10[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_10[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_10[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_10[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_100(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_100[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_100[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_100[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_100(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_100[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_100[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_100[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_101(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_101[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_101[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_101[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_101(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_101[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_101[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_101[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_102(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_102[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_102[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_102[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_102(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_102[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_102[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_102[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_103(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_103[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_103[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_103[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_103(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_103[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_103[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_103[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_11[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_11[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_11[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_11[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_11[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_11[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_12[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_12[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_12[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_12[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_12[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_12[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_13[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_13[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_13[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_13[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_13[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_13[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_14[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_14[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_14[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_14[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_14[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_14[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_15[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_15[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_15[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_15[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_15[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_15[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_16[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_16[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_16[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_16[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_16[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_16[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_17[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_17[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_17[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_17[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_17[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_17[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_18[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_18[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_18[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_18[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_18[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_18[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_19[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_19[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_19[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_19[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_19[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_19[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_20[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_20[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_20[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_20[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_20[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_20[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_21[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_21[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_21[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_21[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_21[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_21[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_22(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_22[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_22[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_22[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_22(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_22[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_22[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_22[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_23[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_23[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_23[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_23[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_23[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_23[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_24(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_24[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_24[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_24[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_24[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_24[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_24[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_25[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_25[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_25[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_25[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_25[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_25[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_26[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_26[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_26[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_26[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_26[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_26[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_27(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_27[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_27[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_27[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_27(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_27[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_27[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_27[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_28(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_28[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_28[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_28[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_28(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_28[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_28[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_28[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_29(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_29[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_29[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_29[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_29(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_29[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_29[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_29[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_30(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_30[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_30[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_30[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_30(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_30[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_30[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_30[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_31(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_31[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_31[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_31[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_31(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_31[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_31[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_31[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_32(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_32[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_32[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_32[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_32(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_32[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_32[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_32[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_33(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_33[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_33[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_33[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_33(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_33[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_33[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_33[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_34(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_34[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_34[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_34[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_34(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_34[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_34[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_34[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_35[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_35[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_35[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_35[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_35[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_35[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_36(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_36[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_36[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_36[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_36(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_36[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_36[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_36[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_37(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_37[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_37[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_37[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_37(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_37[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_37[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_37[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_38(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_38[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_38[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_38[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_38(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_38[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_38[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_38[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_39(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_39[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_39[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_39[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_39(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_39[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_39[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_39[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_40(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_40[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_40[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_40[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_40(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_40[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_40[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_40[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_41(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_41[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_41[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_41[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_41(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_41[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_41[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_41[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_42(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_42[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_42[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_42[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_42(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_42[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_42[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_42[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_43(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_43[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_43[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_43[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_43(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_43[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_43[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_43[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_44(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_44[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_44[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_44[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_44(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_44[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_44[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_44[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_45(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_45[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_45[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_45[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_45(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_45[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_45[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_45[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_46(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_46[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_46[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_46[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_46(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_46[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_46[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_46[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_47(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_47[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_47[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_47[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_47(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_47[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_47[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_47[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_48(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_48[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_48[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_48[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_48(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_48[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_48[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_48[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_49(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_49[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_49[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_49[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_49(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_49[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_49[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_49[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_50(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_50[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_50[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_50[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_50(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_50[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_50[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_50[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_51(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_51[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_51[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_51[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_51(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_51[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_51[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_51[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_54(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_54[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_54[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_54[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_54(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_54[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_54[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_54[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_55(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_55[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_55[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_55[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_55(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_55[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_55[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_55[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_56(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_56[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_56[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_56[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_56(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_56[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_56[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_56[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_57(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_57[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_57[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_57[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_57(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_57[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_57[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_57[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_58(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_58[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_58[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_58[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_58(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_58[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_58[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_58[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_59(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_59[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_59[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_59[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_59(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_59[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_59[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_59[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_60(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_60[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_60[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_60[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_60(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_60[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_60[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_60[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_61(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_61[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_61[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_61[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_61(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_61[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_61[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_61[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_62(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_62[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_62[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_62[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_62(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_62[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_62[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_62[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_63(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_63[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_63[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_63[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_63(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_63[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_63[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_63[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_64(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_64[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_64[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_64[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_64(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_64[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_64[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_64[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_65(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_65[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_65[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_65[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_65(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_65[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_65[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_65[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_66(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_66[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_66[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_66[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_66(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_66[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_66[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_66[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_67(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_67[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_67[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_67[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_67(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_67[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_67[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_67[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_68(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_68[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_68[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_68[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_68(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_68[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_68[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_68[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_69(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_69[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_69[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_69[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_69(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_69[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_69[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_69[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_70(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_70[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_70[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_70[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_70(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_70[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_70[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_70[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_71(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_71[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_71[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_71[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_71(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_71[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_71[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_71[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_72(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_72[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_72[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_72[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_72(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_72[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_72[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_72[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_73(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_73[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_73[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_73[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_73(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_73[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_73[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_73[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_74(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_74[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_74[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_74[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_74(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_74[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_74[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_74[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_75(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_75[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_75[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_75[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_75(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_75[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_75[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_75[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_76(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_76[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_76[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_76[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_76(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_76[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_76[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_76[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_77(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_77[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_77[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_77[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_77(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_77[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_77[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_77[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_78(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_78[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_78[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_78[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_78(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_78[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_78[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_78[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_79(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_79[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_79[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_79[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_79(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_79[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_79[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_79[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_80(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_80[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_80[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_80[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_80(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_80[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_80[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_80[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_81(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_81[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_81[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_81[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_81(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_81[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_81[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_81[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_82(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_82[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_82[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_82[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_82(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_82[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_82[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_82[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_83(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_83[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_83[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_83[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_83(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_83[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_83[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_83[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_84(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_84[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_84[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_84[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_84(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_84[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_84[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_84[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_85(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_85[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_85[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_85[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_85(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_85[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_85[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_85[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_86(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_86[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_86[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_86[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_86(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_86[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_86[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_86[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_87(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_87[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_87[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_87[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_87(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_87[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_87[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_87[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_88(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_88[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_88[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_88[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_88(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_88[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_88[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_88[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_89(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_89[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_89[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_89[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_89(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_89[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_89[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_89[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_90(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_90[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_90[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_90[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_90(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_90[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_90[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_90[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_91(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_91[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_91[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_91[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_91(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_91[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_91[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_91[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_92(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_92[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_92[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_92[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_92(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_92[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_92[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_92[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_93(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_93[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_93[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_93[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_93(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_93[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_93[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_93[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_94(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_94[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_94[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_94[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_94(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_94[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_94[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_94[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_95(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_95[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_95[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_95[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_95(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_95[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_95[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_95[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_96(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_96[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_96[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_96[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_96(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_96[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_96[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_96[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_97(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_97[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_97[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_97[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_97(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_97[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_97[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_97[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_98(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_98[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_98[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_98[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_98(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_98[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_98[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_98[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_99(void)
{
    uint32 msr;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_99[u32CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        msr = OsIf_Trusted_Call_Return(Adc_schm_read_msr);
#else
        msr = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
            ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
        }
        msr_ADC_EXCLUSIVE_AREA_99[u32CoreId] = msr;
    }
    reentry_guard_ADC_EXCLUSIVE_AREA_99[u32CoreId]++;
}

void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_99(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    reentry_guard_ADC_EXCLUSIVE_AREA_99[u32CoreId]--;
    if ((ISR_ON(msr_ADC_EXCLUSIVE_AREA_99[u32CoreId]))&&(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_99[u32CoreId]))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K1XX_
        ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}


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
void SchM_Check_adc(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_00[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_00[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_00 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_01[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_01[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_01 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_02[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_02[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_02 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_03[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_03[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_03 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_04[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_04[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_04 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_05[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_05[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_05 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_10[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_10[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_10 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_100[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_100[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_100 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_101[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_101[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_101 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_102[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_102[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_102 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_103[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_103[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_103 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_11[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_11[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_11 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_12[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_12[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_12 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_13[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_13[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_13 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_14[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_14[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_14 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_15[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_15[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_15 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_16[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_16[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_16 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_17[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_17[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_17 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_18[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_18[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_18 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_19[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_19[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_19 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_20[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_20[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_20 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_21[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_21[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_21 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_22[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_22[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_22 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_23[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_23[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_23 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_24[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_24[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_24 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_25[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_25[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_25 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_26[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_26[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_26 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_27[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_27[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_27 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_28[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_28[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_28 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_29[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_29[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_29 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_30[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_30[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_30 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_31[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_31[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_31 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_32[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_32[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_32 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_33[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_33[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_33 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_34[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_34[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_34 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_35[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_35[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_35 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_36[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_36[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_36 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_37[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_37[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_37 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_38[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_38[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_38 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_39[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_39[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_39 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_40[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_40[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_40 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_41[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_41[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_41 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_42[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_42[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_42 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_43[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_43[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_43 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_44[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_44[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_44 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_45[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_45[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_45 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_46[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_46[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_46 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_47[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_47[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_47 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_48[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_48[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_48 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_49[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_49[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_49 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_50[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_50[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_50 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_51[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_51[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_51 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_54[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_54[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_54 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_55[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_55[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_55 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_56[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_56[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_56 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_57[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_57[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_57 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_58[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_58[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_58 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_59[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_59[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_59 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_60[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_60[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_60 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_61[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_61[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_61 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_62[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_62[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_62 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_63[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_63[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_63 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_64[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_64[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_64 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_65[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_65[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_65 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_66[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_66[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_66 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_67[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_67[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_67 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_68[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_68[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_68 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_69[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_69[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_69 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_70[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_70[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_70 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_71[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_71[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_71 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_72[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_72[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_72 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_73[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_73[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_73 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_74[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_74[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_74 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_75[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_75[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_75 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_76[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_76[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_76 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_77[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_77[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_77 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_78[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_78[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_78 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_79[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_79[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_79 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_80[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_80[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_80 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_81[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_81[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_81 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_82[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_82[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_82 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_83[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_83[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_83 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_84[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_84[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_84 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_85[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_85[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_85 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_86[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_86[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_86 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_87[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_87[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_87 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_88[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_88[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_88 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_89[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_89[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_89 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_90[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_90[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_90 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_91[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_91[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_91 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_92[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_92[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_92 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_93[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_93[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_93 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_94[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_94[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_94 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_95[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_95[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_95 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_96[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_96[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_96 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_97[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_97[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_97 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_98[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_98[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_98 for the next test in the suite*/

    EU_ASSERT(0UL == reentry_guard_ADC_EXCLUSIVE_AREA_99[u32CoreId]);
    reentry_guard_ADC_EXCLUSIVE_AREA_99[u32CoreId] = 0UL; /*reset reentry_guard_ADC_EXCLUSIVE_AREA_99 for the next test in the suite*/


}
#endif /*MCAL_TESTING_ENVIRONMENT*/

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
