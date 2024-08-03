/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,FLEXIO
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXIO_MCL_IP_CFG_H_
#define FLEXIO_MCL_IP_CFG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Include all variants header files. */
#include "Flexio_Mcl_Ip_VS_0_PBcfg.h"

#include "Flexio_Mcl_Ip_Cfg_Defines.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_MCL_IP_CFG_VENDOR_ID                    43
#define FLEXIO_MCL_IP_CFG_MODULE_ID                    255
#define FLEXIO_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_MCL_IP_CFG_SW_MAJOR_VERSION             2
#define FLEXIO_MCL_IP_CFG_SW_MINOR_VERSION             0
#define FLEXIO_MCL_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same vendor */
#if (FLEXIO_MCL_IP_CFG_VENDOR_ID != FLEXIO_MCL_IP_CFG_DEFINES_VENDOR_ID)
    #error "Flexio_Mcl_Ip_Cfg.h and Flexio_Mcl_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Cfg.h and Flexio_Mcl_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same Software version */
#if ((FLEXIO_MCL_IP_CFG_SW_MAJOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_SW_MINOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_SW_PATCH_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Mcl_Ip_Cfg.h and Flexio_Mcl_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Flexio_Mcl_Ip_VS_0_PBcfg.h file are of the same vendor */
#if (FLEXIO_MCL_IP_CFG_VENDOR_ID != FLEXIO_MCL_IP_VS_0_PBCFG_VENDOR_ID)
    #error "Flexio_Mcl_Ip_Cfg.h and Flexio_Mcl_Ip_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Flexio_Mcl_Ip_VS_0_PBcfg.h file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION != FLEXIO_MCL_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION != FLEXIO_MCL_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXIO_MCL_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Cfg.h and Flexio_Mcl_Ip_VS_0_PBcfg.h are different"
#endif

/* Check if header file and Flexio_Mcl_Ip_VS_0_PBcfg.h file are of the same Software version */
#if ((FLEXIO_MCL_IP_CFG_SW_MAJOR_VERSION != FLEXIO_MCL_IP_VS_0_PBCFG_SW_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_SW_MINOR_VERSION != FLEXIO_MCL_IP_VS_0_PBCFG_SW_MINOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_SW_PATCH_VERSION != FLEXIO_MCL_IP_VS_0_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Mcl_Ip_Cfg.h and Flexio_Mcl_Ip_VS_0_PBcfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"




#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* FLEXIO_MCL_IP_CFG_H_ */

