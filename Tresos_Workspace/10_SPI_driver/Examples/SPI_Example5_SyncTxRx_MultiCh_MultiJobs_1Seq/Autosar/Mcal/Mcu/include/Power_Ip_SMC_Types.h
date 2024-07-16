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

#ifndef POWER_IP_SMC_TYPES_H
#define POWER_IP_SMC_TYPES_H

/**
*   @file       Power_Ip_SMC_Types.h
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
  #include "S32K116_SMC.h"
#elif defined(POWER_IP_S32K118)
  #include "S32K118_SMC.h"
#elif defined(POWER_IP_S32K142)
  #include "S32K142_SMC.h"
#elif defined(POWER_IP_S32K142W)
  #include "S32K142W_SMC.h"
#elif defined(POWER_IP_S32K144)
  #include "S32K144_SMC.h"
#elif defined(POWER_IP_S32K144W)
  #include "S32K144W_SMC.h"
#elif defined(POWER_IP_S32K146)
  #include "S32K146_SMC.h"
#elif defined(POWER_IP_S32K148)
  #include "S32K148_SMC.h"
#elif (defined(POWER_IP_S32M244) || defined(POWER_IP_S32M242) || defined(POWER_IP_S32M241) || defined(POWER_IP_S32M243))
  #include "S32M24x_SMC.h"
#else
  #error "Derivative not found"
#endif

#include "Mcal.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_SMC_TYPES_VENDOR_ID                       43
#define POWER_IP_SMC_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_SMC_TYPES_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_SMC_TYPES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_SMC_TYPES_SW_MAJOR_VERSION                2
#define POWER_IP_SMC_TYPES_SW_MINOR_VERSION                0
#define POWER_IP_SMC_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if Power_Ip_SMC_Types.h file and Mcal.h file are of the same Autosar version */
  #if ((POWER_IP_SMC_TYPES_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
       (POWER_IP_SMC_TYPES_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Power_Ip_SMC_Types.h and Mcal.h are different"
  #endif
#endif

/* Check if Power_Ip_SMC_Types.h file and Power_Ip_Cfg_Defines.h file have same versions */
#if (POWER_IP_SMC_TYPES_VENDOR_ID  != POWER_IP_CFG_DEFINES_VENDOR_ID)
    #error "Power_Ip_SMC_Types.h and Power_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Power_Ip_SMC_Types.h file and Power_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((POWER_IP_SMC_TYPES_AR_RELEASE_MAJOR_VERSION    != POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_SMC_TYPES_AR_RELEASE_MINOR_VERSION    != POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_SMC_TYPES_AR_RELEASE_REVISION_VERSION != POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_SMC_Types.h and Power_Ip_Cfg_Defines.h are different"
#endif

/* Check if Power_Ip_SMC_Types.h file and Power_Ip_Cfg_Defines.h file are of the same Software version */
#if ((POWER_IP_SMC_TYPES_SW_MAJOR_VERSION != POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (POWER_IP_SMC_TYPES_SW_MINOR_VERSION != POWER_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (POWER_IP_SMC_TYPES_SW_PATCH_VERSION != POWER_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_SMC_Types.h and Power_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/****************************************************/
/*                    SMC_PMPROT                    */
/****************************************************/
#if (STD_ON == POWER_IP_HSRUN_SUPPORT)
  #define SMC_PMPROT_RWBITS_MASK32            ((uint32)SMC_PMPROT_AVLP_MASK | SMC_PMPROT_AHSRUN_MASK)
#else
  #define SMC_PMPROT_RWBITS_MASK32            ((uint32)SMC_PMPROT_AVLP_MASK)
#endif
#define SMC_PMPROT_HSRUN_ALLOWED_U32        ((uint32)0x00000080U)
#define SMC_PMPROT_HSRUN_NOT_ALLOWED_U32    ((uint32)0x00000000U)
#define SMC_PMPROT_VLP_ALLOWED_U32          (SMC_PMPROT_AVLP_MASK)
#define SMC_PMPROT_VLP_NOT_ALLOWED_U32      ((uint32)0x00000000U)

/****************************************************/
/***              SMC_PMCTRL                      ***/
/****************************************************/
#define SMC_PMCTRL_RUN_MODE_U32             ((uint32)0x00000000U)
#define SMC_PMCTRL_VLPR_MODE_U32            ((uint32)0x00000040U)
#define SMC_PMCTRL_HSRUN_MODE_U32           ((uint32)0x00000060U)

#define SMC_PMCTRL_STOP_U32                 ((uint32)0x00000000U)
#define SMC_PMCTRL_VLPS_U32                 ((uint32)0x00000002U)

/****************************************************/
/***              SMC_STOPCTRL                    ***/
/****************************************************/
#define SMC_STOPCTRL_STOP1_U32              ((uint32)0x00000040U)
#define SMC_STOPCTRL_STOP2_U32              ((uint32)0x00000080U)

/****************************************************/
/***              SMC_PMSTAT                      ***/
/****************************************************/
#define SMC_PMSTAT_RUN_U32                  ((uint32)0x00000001U)
#define SMC_PMSTAT_VLPR_U32                 ((uint32)0x00000004U)
#define SMC_PMSTAT_VLPS_U32                 ((uint32)0x00000010U)
#define SMC_PMSTAT_HSRUN_U32                ((uint32)0x00000080U)

#define POWER_IP_SWITCH_MODE_SUCCESS        ((uint32)0U)
#define POWER_IP_SWITCH_MODE_FAIL           ((uint32)1U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief   SMC IP configuration.
* @details This structure contains information for allowed modes
*/
typedef struct
{
    /* Allowed modes */
    uint32  AllowedModes;
} Power_Ip_SMC_ConfigType;

typedef uint32 Power_Ip_PowerModeStateType;

typedef enum
{
    POWER_IP_MODE_OK = 0,
    POWER_IP_MODE_NOT_OK
} Power_Ip_SMC_ModeStatusType;

#ifdef POWER_IP_VLPSA_NOTIFICATION
typedef enum
{
    POWER_IP_STOP_SUCCESSFUL = 0,
    POWER_IP_STOP_ABORTED
} Power_Ip_SMC_VLPSA_StatusType;
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
#endif /* POWER_IP_SMC_TYPES_H */

