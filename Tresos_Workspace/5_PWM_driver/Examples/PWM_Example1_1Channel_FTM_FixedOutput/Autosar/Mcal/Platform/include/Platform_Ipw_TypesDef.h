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

#ifndef IPW_PLATFORM_IPW_TYPESDEF_H_
#define IPW_PLATFORM_IPW_TYPESDEF_H_

/**
*   @file
*
*   @internal
*   @addtogroup Platform_Ipw
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform_CfgDefines.h"
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#include "IntCtrl_Ip_TypesDef.h"
#include "System_Ip_CfgDefines.h"
#include "Mpu_Ip.h"
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_PLATFORM_IPW_TYPESDEF_VENDOR_ID                       43
#define CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MAJOR_VERSION        4
#define CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MINOR_VERSION        7
#define CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_REVISION_VERSION     0
#define CDD_PLATFORM_IPW_TYPESDEF_SW_MAJOR_VERSION                2
#define CDD_PLATFORM_IPW_TYPESDEF_SW_MINOR_VERSION                0
#define CDD_PLATFORM_IPW_TYPESDEF_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_CfgDefines header file are of the same vendor */
#if (CDD_PLATFORM_IPW_TYPESDEF_VENDOR_ID != CDD_PLATFORM_CFGDEFINES_VENDOR_ID)
    #error "Platform_Ipw_TypesDef.h and Platform_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Platform_CfgDefines header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_CFGDEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw_TypesDef.h and Platform_CfgDefines.h are different"
#endif

/* Check if current file and Platform_CfgDefines header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_TYPESDEF_SW_MAJOR_VERSION != CDD_PLATFORM_CFGDEFINES_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_SW_MINOR_VERSION != CDD_PLATFORM_CFGDEFINES_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_SW_PATCH_VERSION != CDD_PLATFORM_CFGDEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw_TypesDef.h and Platform_CfgDefines.h are different"
#endif

/* Check if current file and IntCtrl_Ip_TypesDef header file are of the same vendor */
#if (CDD_PLATFORM_IPW_TYPESDEF_VENDOR_ID != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_VENDOR_ID)
    #error "Platform_Ipw_TypesDef.c and IntCtrl_Ip_TypesDef.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip_TypesDef header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw_TypesDef.h and IntCtrl_Ip_TypesDef.h are different"
#endif
/* Check if current file and IntCtrl_Ip_TypesDef header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_TYPESDEF_SW_MAJOR_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_SW_MINOR_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_SW_PATCH_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw_TypesDef.h and IntCtrl_Ip_TypesDef.h are different"
#endif

/* Check if current file and System_Ip_CfgDefines header file are of the same vendor */
#if (CDD_PLATFORM_IPW_TYPESDEF_VENDOR_ID != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_VENDOR_ID)
    #error "Platform_Ipw_TypesDef.c and System_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and System_Ip_CfgDefines header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_TYPESDEF_SW_MAJOR_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_SW_MINOR_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_SW_PATCH_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw_TypesDef.h and System_Ip_CfgDefines.h are different"
#endif
/* Check if current file and System_Ip_CfgDefines header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw_TypesDef.h and System_Ip_CfgDefines.h are different"
#endif

/* Check if Platform_Ipw_TypesDef.h and Mpu_Ip.h are of the same vendor */
#if (CDD_PLATFORM_IPW_TYPESDEF_VENDOR_ID != CDD_PLATFORM_MPU_IP_TYPES_DEF_VENDOR_ID)
    #error "Platform_Ipw_TypesDef.h and Mpu_Ip.h have different vendor ids"
#endif
/* Check if Platform_Ipw_TypesDef.h file and Mpu_Ip.h file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MAJOR_VERSION) || \
    (CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MINOR_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MINOR_VERSION) || \
    (CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Platform_Ipw_TypesDef.h and Mpu_Ip.h are different"
#endif
/* Check if Platform_Ipw_TypesDef.h file and Mpu_Ip.h file are of the same Software version */
#if ((CDD_PLATFORM_IPW_TYPESDEF_SW_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MAJOR_VERSION) || \
    (CDD_PLATFORM_IPW_TYPESDEF_SW_MINOR_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MINOR_VERSION) || \
    (CDD_PLATFORM_IPW_TYPESDEF_SW_PATCH_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_PATCH_VERSION))
    #error "Software Version Numbers of Platform_Ipw_TypesDef.h and Mpu_Ip.h are different"
#endif

/*==================================================================================================
 *                              TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#if ((INT_CTRL_IP_CORTEXM == STD_ON) && (INT_CTRL_IP_CORTEXM0PLUS == STD_OFF))
/**
 * @internal
 * @brief          Configuration structure core-related interrupt requests.
 */
typedef struct
{
    System_Ip_IrqType eIrq;
    boolean bEnable;
}Platform_SystemIrqConfigType;

/**
 * @internal
 * @brief          Configuration structure system settings.
 */
typedef struct
{
    const Platform_SystemIrqConfigType *aSystemIrqs;
    uint8 u8SysIrqsCount;    
    boolean bAhbSlavePriority;
}Platform_SystemConfigType;
#endif
/**
 * @internal
 * @brief          Configuration structure for PLATFORM IP wrapper.
 */
typedef struct
{
    const IntCtrl_Ip_CtrlConfigType *pIntCtrlConfig;
#if ((INT_CTRL_IP_CORTEXM == STD_ON) && (INT_CTRL_IP_CORTEXM0PLUS == STD_OFF))
    const Platform_SystemConfigType *aSystemConfig;
#endif
#if (PLATFORM_ENABLE_MPU == STD_ON)
    const Mpu_Ip_ConfigType *Platform_Ipw_pMpuConfig;
#endif /* PLATFORM_ENABLE_MPU == STD_ON */
} Platform_Ipw_ConfigType;

#endif /* IPW_PLATFORM_IPW_TYPESDEF_H_ */
