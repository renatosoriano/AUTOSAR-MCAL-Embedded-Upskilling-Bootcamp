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

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/


#include "Platform_Ipw_Cfg.h"
#include "IntCtrl_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_IPW_CFG_VENDOR_ID_C                     43
#define CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION_C              2
#define CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION_C              0
#define CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Ipw_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_IPW_CFG_VENDOR_ID_C != CDD_PLATFORM_IPW_CFG_VENDOR_ID)
    #error "Platform_Ipw_Cfg.c and Platform_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw_Cfg.c and Platform_Ipw_Cfg.h are different"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw_Cfg.c and Platform_Ipw_Cfg.h are different"
#endif

/* Check if current file and IntCtrl_Ip header file are of the same vendor */
#if (CDD_PLATFORM_IPW_CFG_VENDOR_ID_C != CDD_PLATFORM_INTCTRL_IP_VENDOR_ID)
    #error "Platform_Ipw_Cfg.c and IntCtrl_Ip.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw_Cfg.c and IntCtrl_Ip.h are different"
#endif
/* Check if current file and IntCtrl_Ip header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw_Cfg.c and IntCtrl_Ip.h are different"
#endif


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

/* Definition of the configuration structure for Platform IPW */
const Platform_Ipw_ConfigType ipwConfig = {
    &intCtrlConfig  , /* Interrupt controller configuration */
#if ((INT_CTRL_IP_CORTEXM == STD_ON) && (INT_CTRL_IP_CORTEXM0PLUS == STD_OFF))
     NULL_PTR  ,/* System settings */
#endif

};

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
