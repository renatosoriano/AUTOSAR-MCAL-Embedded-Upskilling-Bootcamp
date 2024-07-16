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

#ifndef POWER_IP_RCM_TYPES_H
#define POWER_IP_RCM_TYPES_H

/**
*   @file       Power_Ip_RCM_Types.h
*   @version    2.0.0
*
*   @brief   POWER IP driver header file.
*   @details POWER IP driver header file.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
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
#include "Power_Ip_Cfg_Defines.h"

#if defined(POWER_IP_S32K116)
  #include "S32K116_RCM.h"
#elif defined(POWER_IP_S32K118)
  #include "S32K118_RCM.h"
#elif defined(POWER_IP_S32K142)
  #include "S32K142_RCM.h"
#elif defined(POWER_IP_S32K142W)
  #include "S32K142W_RCM.h"
#elif defined(POWER_IP_S32K144)
  #include "S32K144_RCM.h"
#elif defined(POWER_IP_S32K144W)
  #include "S32K144W_RCM.h"
#elif defined(POWER_IP_S32K146)
  #include "S32K146_RCM.h"
#elif defined(POWER_IP_S32K148)
  #include "S32K148_RCM.h"
#elif (defined(POWER_IP_S32M244) || defined(POWER_IP_S32M242) || defined(POWER_IP_S32M241) || defined(POWER_IP_S32M243))
  #include "S32M24x_RCM.h"
#else
  #error "Derivative not found"
#endif

#include "StandardTypes.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_RCM_TYPES_VENDOR_ID                       43
#define POWER_IP_RCM_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_RCM_TYPES_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_RCM_TYPES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_RCM_TYPES_SW_MAJOR_VERSION                2
#define POWER_IP_RCM_TYPES_SW_MINOR_VERSION                0
#define POWER_IP_RCM_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_RCM_Types.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_RCM_TYPES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RCM_TYPES_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_RCM_Types.h and StandardTypes.h are different"
#endif
#endif

/* Check if Power_Ip_RCM_Types.h file and Power_Ip_Cfg_Defines.h file have same versions */
#if (POWER_IP_RCM_TYPES_VENDOR_ID  != POWER_IP_CFG_DEFINES_VENDOR_ID)
    #error "Power_Ip_RCM_Types.h and Power_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Power_Ip_RCM_Types.h file and Power_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((POWER_IP_RCM_TYPES_AR_RELEASE_MAJOR_VERSION    != POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RCM_TYPES_AR_RELEASE_MINOR_VERSION    != POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_RCM_TYPES_AR_RELEASE_REVISION_VERSION != POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_RCM_Types.h and Power_Ip_Cfg_Defines.h are different"
#endif

/* Check if Power_Ip_RCM_Types.h file and Power_Ip_Cfg_Defines.h file are of the same Software version */
#if ((POWER_IP_RCM_TYPES_SW_MAJOR_VERSION != POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (POWER_IP_RCM_TYPES_SW_MINOR_VERSION != POWER_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (POWER_IP_RCM_TYPES_SW_PATCH_VERSION != POWER_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_RCM_Types.h and Power_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/***********************************************************/
/*                           RCM                           */
/***********************************************************/

/****************************************************/
/*                     RCM_SRS                      */
/****************************************************/
#if (defined(POWER_IP_S32K116) || defined(POWER_IP_S32K118))
    #define RCM_SSRS_RWBITS_MASK32              ((uint32)0x00002FF6U)
#else
    #define RCM_SSRS_RWBITS_MASK32              ((uint32)0x00002FEEU)
#endif

/* Mask used for getting reset reason position, containing resets available on all derivatives */
#define RCM_SSRS_RESET_SOURCES_MASK32          ((uint32)0x00002FFEU)

/****************************************************/
/*                     RCM_RPC                      */
/****************************************************/
#define RCM_RPC_RWBITS_MASK32       ((uint32)RCM_RPC_RSTFLTSRW_MASK | \
                                             RCM_RPC_RSTFLTSS_MASK  | \
                                             RCM_RPC_RSTFLTSEL_MASK)

#define RCM_RPC_STOP_ALL_FILTERING_DISABLE_U32       ((uint32)0x00000000U)
#define RCM_RPC_STOP_LPO_CLOCK_FILTER_ENABLE_U32     (RCM_RPC_RSTFLTSS_MASK)

#define RCM_RPC_NORMAL_ALL_FILTERING_DISABLE_U32     ((uint32)0x00000000U)
#define RCM_RPC_NORMAL_BUS_CLOCK_FILTER_ENABLE_U32   ((uint32)0x00000001U)
#define RCM_RPC_NORMAL_LPO_CLOCK_FILTER_ENABLE_U32   ((uint32)0x00000002U)

/****************************************************/
/*                     RCM_SRIE                     */
/****************************************************/
#define RCM_SRIE_RESET_MASK32               ((uint32)0x00000000U)
#define RCM_SRIE_RWBITS_MASK32              ((uint32)0x00002FFFU)

#define RCM_SRIE_SACKERR_INT_EN_U32         ((uint32)0x00002000U)
#define RCM_SRIE_SACKERR_INT_DIS_U32        ((uint32)0x00000000U)

#define RCM_SRIE_MDM_AP_INT_EN_U32          ((uint32)0x00000800U)
#define RCM_SRIE_MDM_AP_INT_DIS_U32         ((uint32)0x00000000U)

#define RCM_SRIE_SW_INT_EN_U32              ((uint32)0x00000400U)
#define RCM_SRIE_SSW_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_LOCKUP_INT_EN_U32          ((uint32)0x00000200U)
#define RCM_SRIE_LOCKUP_INT_DIS_U32         ((uint32)0x00000000U)

#define RCM_SRIE_JTAG_INT_EN_U32            ((uint32)0x00000100U)
#define RCM_SRIE_JTAG_INT_DIS_U32           ((uint32)0x00000000U)

#define RCM_SRIE_GIE_INT_EN_U32             ((uint32)0x00000080U)
#define RCM_SRIE_GIE_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_PIN_INT_EN_U32             ((uint32)0x00000040U)
#define RCM_SRIE_PIN_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_WDOG_INT_EN_U32            ((uint32)0x00000020U)
#define RCM_SRIE_WDOG_INT_DIS_U32           ((uint32)0x00000000U)

#define RCM_SRIE_CMU_INT_EN_U32             ((uint32)0x00000010U)
#define RCM_SRIE_CMU_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_LOL_INT_EN_U32             ((uint32)0x00000080U)
#define RCM_SRIE_LOL_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_LOC_INT_EN_U32             ((uint32)0x00000004U)
#define RCM_SRIE_LOC_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_DELAY_10_LPO_CYCLES_U32    ((uint32)0x00000000U)
#define RCM_SRIE_DELAY_34_LPO_CYCLES_U32    ((uint32)0x00000001U)
#define RCM_SRIE_DELAY_130_LPO_CYCLES_U32   ((uint32)0x00000002U)
#define RCM_SRIE_DELAY_514_LPO_CYCLES_U32   ((uint32)0x00000003U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief   RCM IP configuration.
* @details This structure contains information for peripheral configuration
*/
typedef struct
{
    uint32  ResetPinControlConfig;
    uint32  ResetInterruptEnableConfig;
} Power_Ip_RCM_ConfigType;

#if (defined(POWER_IP_RESET_ALTERNATE_ISR_USED))
  #if (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON)
typedef enum
{
    POWER_IP_RCM_UNINIT = 0,  /**< @brief The RCM driver is uninitialized. */
    POWER_IP_RCM_INIT = 1     /**< @brief The RCM driver is initialized. */
} Power_Ip_RCM_StatusType;
  #endif
#endif


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_RCM_TYPES_H */

