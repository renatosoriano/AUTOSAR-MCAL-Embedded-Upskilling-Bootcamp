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

#ifndef POWER_IP_CORTEXM4_H
#define POWER_IP_CORTEXM4_H

/**
*   @file       Power_Ip_CotexM4.h
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
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Types.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CORTEXM4_VENDOR_ID                    43
#define POWER_IP_CORTEXM4_AR_RELEASE_MAJOR_VERSION     4
#define POWER_IP_CORTEXM4_AR_RELEASE_MINOR_VERSION     7
#define POWER_IP_CORTEXM4_AR_RELEASE_REVISION_VERSION  0
#define POWER_IP_CORTEXM4_SW_MAJOR_VERSION             2
#define POWER_IP_CORTEXM4_SW_MINOR_VERSION             0
#define POWER_IP_CORTEXM4_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_CortexM4.h file and Power_Ip_Types.h file have same versions */
#if (POWER_IP_CORTEXM4_VENDOR_ID  != POWER_IP_TYPES_VENDOR_ID)
    #error "Power_Ip_CortexM4.h and Power_Ip_Types.h have different vendor IDs"
#endif

/* Check if Power_Ip_CortexM4.h file and Power_Ip_Types.h file are of the same Autosar version */
#if ((POWER_IP_CORTEXM4_AR_RELEASE_MAJOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CORTEXM4_AR_RELEASE_MINOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_CORTEXM4_AR_RELEASE_REVISION_VERSION != POWER_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_CortexM4.h and Power_Ip_Types.h are different"
#endif

/* Check if Power_Ip_CortexM4.h file and Power_Ip_Types.h file are of the same Software version */
#if ((POWER_IP_CORTEXM4_SW_MAJOR_VERSION != POWER_IP_TYPES_SW_MAJOR_VERSION) || \
     (POWER_IP_CORTEXM4_SW_MINOR_VERSION != POWER_IP_TYPES_SW_MINOR_VERSION) || \
     (POWER_IP_CORTEXM4_SW_PATCH_VERSION != POWER_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_CortexM4.h and Power_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/***********************************************************/
/*          CortexM4 System Control Register               */
/***********************************************************/
#define CM4_AIRCR_BASEADDR                   ((uint32)0xE000ED0CU)

#define CM4_AIRCR_SYSRESETREQ_MASK           0x4u

#define CM4_AIRCR_PRIGROUP_MASK              0x700u

#define CM4_AIRCR_VECTKEY_MASK               0xFFFF0000u
#define CM4_AIRCR_VECTKEY_SHIFT              16u
#define CM4_AIRCR_VECTKEY(x)                 (((uint32)(((uint32)(x))<<CM4_AIRCR_VECTKEY_SHIFT))&CM4_AIRCR_VECTKEY_MASK)

#define CM4_SCR_SLEEPONEXIT_MASK32           ((uint32)0x00000002U)
#define CM4_SCR_SLEEPDEEP_MASK32             ((uint32)0x00000004U)

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct{
    volatile uint32 AIRCR;                             /**< Application Interrupt and Reset Control Register , offset: 0xC */
    volatile uint32 SCR;                               /**< System Control Register, offset: 0x0 */
} Power_Ip_CM4_Type;
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
#define  Call_Power_Ip_CM4_EnableSleepOnExit()  OsIf_Trusted_Call(Power_Ip_CM4_EnableSleepOnExit)
#define  Call_Power_Ip_CM4_DisableSleepOnExit() OsIf_Trusted_Call(Power_Ip_CM4_DisableSleepOnExit)
#else
#define  Call_Power_Ip_CM4_EnableSleepOnExit()  Power_Ip_CM4_EnableSleepOnExit()
#define  Call_Power_Ip_CM4_DisableSleepOnExit() Power_Ip_CM4_DisableSleepOnExit()
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
#else /* POWER_IP_ENABLE_USER_MODE_SUPPORT */
#define  Call_Power_Ip_CM4_EnableSleepOnExit()  Power_Ip_CM4_EnableSleepOnExit()
#define  Call_Power_Ip_CM4_DisableSleepOnExit() Power_Ip_CM4_DisableSleepOnExit()
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */
#endif /* POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON */
#endif /* POWER_IP_SLEEPONEXIT_SUPPORT */

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
#define  Call_Power_Ip_CM4_EnableDeepSleep() \
do\
{ \
        OsIf_Trusted_Call(Power_Ip_CM4_EnableDeepSleep); \
}\
while(0)

#define  Call_Power_Ip_CM4_DisableDeepSleep() \
do\
{ \
        OsIf_Trusted_Call(Power_Ip_CM4_DisableDeepSleep); \
}\
while(0)

#else
#define  Call_Power_Ip_CM4_EnableDeepSleep() \
do\
{ \
        Power_Ip_CM4_EnableDeepSleep(); \
}\
while(0)

#define  Call_Power_Ip_CM4_DisableDeepSleep() \
do\
{ \
        Power_Ip_CM4_DisableDeepSleep(); \
}\
while(0)
#endif
#endif



#if (POWER_IP_PERFORM_RESET_API == STD_ON)

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
#define  Call_Power_Ip_CM4_SystemReset() \
do\
{ \
        OsIf_Trusted_Call(Power_Ip_CM4_SystemReset); \
}\
while(0)
#else
#define  Call_Power_Ip_CM4_SystemReset() \
do\
{ \
        Power_Ip_CM4_SystemReset(); \
}\
while(0)
#endif
#endif

#endif /* (POWER_IP_PERFORM_RESET_API == STD_ON) */


#if (POWER_IP_PERFORM_RESET_API == STD_ON)
 /**
* @brief        The function initiates a system reset request to reset the SoC.
* @details      The function initiates a system reset request to reset the SoC
*
* @param[in]    none
*
* @return void
*
*/
void Power_Ip_CM4_SystemReset(void);

#endif

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)

void Power_Ip_CM4_EnableSleepOnExit(void);
void Power_Ip_CM4_DisableSleepOnExit(void);
  #endif
#endif

void Power_Ip_CM4_EnableDeepSleep(void);
void Power_Ip_CM4_DisableDeepSleep(void);


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_CORTEXM4_H */

