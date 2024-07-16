/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Flexio
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
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file Flexio_Pwm_Ip_PBcfg.c
*
*   @addtogroup flexio_pwm_ip FlexIO Pwm IPL
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
#include "Flexio_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_PWM_IP_PBCFG_VENDOR_ID_C                      43
#define FLEXIO_PWM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_PWM_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_PWM_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_PWM_IP_PBCFG_SW_MAJOR_VERSION_C               2
#define FLEXIO_PWM_IP_PBCFG_SW_MINOR_VERSION_C               0
#define FLEXIO_PWM_IP_PBCFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same vendor */
#if (FLEXIO_PWM_IP_PBCFG_VENDOR_ID_C != FLEXIO_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_PBcfg.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXIO_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_PBcfg.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same software version */
#if ((FLEXIO_PWM_IP_PBCFG_SW_MAJOR_VERSION_C != FLEXIO_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_PBCFG_SW_MINOR_VERSION_C != FLEXIO_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_PBCFG_SW_PATCH_VERSION_C != FLEXIO_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_PBcfg.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

