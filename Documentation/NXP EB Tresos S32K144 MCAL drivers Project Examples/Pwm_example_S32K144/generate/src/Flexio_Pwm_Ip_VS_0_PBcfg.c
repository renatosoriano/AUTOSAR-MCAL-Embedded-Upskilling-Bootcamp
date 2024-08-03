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
#define FLEXIO_PWM_IP_VS_0_PBCFG_VENDOR_ID_C                      43
#define FLEXIO_PWM_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_PWM_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_PWM_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_PWM_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C               2
#define FLEXIO_PWM_IP_VS_0_PBCFG_SW_MINOR_VERSION_C               0
#define FLEXIO_PWM_IP_VS_0_PBCFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same vendor */
#if (FLEXIO_PWM_IP_VS_0_PBCFG_VENDOR_ID_C != FLEXIO_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_VS_0_PBcfg.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXIO_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_VS_0_PBcfg.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same software version */
#if ((FLEXIO_PWM_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C != FLEXIO_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_VS_0_PBCFG_SW_MINOR_VERSION_C != FLEXIO_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_VS_0_PBCFG_SW_PATCH_VERSION_C != FLEXIO_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_VS_0_PBcfg.h and Flexio_Pwm_Ip_Types.h are different."
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
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/** @brief  Prototypes of Pwm notification callback */
extern void Pwm_Ipw_FlexioNotification(uint8 Channel);

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief PwmFlexioChannels_0 of PwmFlexio_0 Pwm using Timer 0 and Pin 0 */
const Flexio_Pwm_Ip_ChannelConfigType Flexio_Pwm_Ip_VS_0_I0_Ch0 =
{
    /* TimerId */   0U,
    /* PinId */     0U,
    /* Period */    1U,
    /* DutyCycle */ 0U,
#if (defined(FLEXIO_PWM_IP_HAS_LOW_MODE) && (FLEXIO_PWM_IP_HAS_LOW_MODE == STD_ON))
    /* Polarity */  FLEXIO_PWM_IP_ACTIVE_HIGH,
#endif
    /* IrqMode */   FLEXIO_PWM_IP_IRQ_ON_PERIOD_END,
    /* Callback */  {
        /* CbFunction */    NULL_PTR,
        /* CbParameter */   NULL_PTR
                    },
    /* Callback */  {
        /* CbFunction */    &Pwm_Ipw_FlexioNotification,
        /* CbParameter */   (uint8)0
                    }
};

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
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

