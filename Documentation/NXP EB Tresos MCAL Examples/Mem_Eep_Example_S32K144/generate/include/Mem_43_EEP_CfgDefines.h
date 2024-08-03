
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_FTFC
*   Dependencies         : 
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
#ifndef MEM_43_EEP_CFG_DEFINES_H
#define MEM_43_EEP_CFG_DEFINES_H

/**
*   @file Mem_43_EEP_CfgDefines.h
*
*   @addtogroup MEM_43_EEP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_EEP_VENDOR_ID_CFG_DEFINES                           43
#define MEM_43_EEP_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES            4
#define MEM_43_EEP_AR_RELEASE_MINOR_VERSION_CFG_DEFINES            7
#define MEM_43_EEP_AR_RELEASE_REVISION_VERSION_CFG_DEFINES         0
#define MEM_43_EEP_SW_MAJOR_VERSION_CFG_DEFINES                    2
#define MEM_43_EEP_SW_MINOR_VERSION_CFG_DEFINES                    0
#define MEM_43_EEP_SW_PATCH_VERSION_CFG_DEFINES                    0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/



/* Define support for 32 or 64Bit address type */
#define MEM_43_EEP_ADDRESSTYPE                             uint32
#define MEM_43_EEP_LENGTHTYPE                              uint32

/* Enable calculates CRC for items of Mem Eep Configuration */
#define MEM_43_EEP_CHECK_CFG_CRC                           (STD_OFF)



#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_EEP_CFG_DEFINES_H */

