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

/* Prevention from multiple including the same header */
#ifndef TRGMUX_IP_CFG_DEVICEREGISTERS_REGISTERS_H_
#define TRGMUX_IP_CFG_DEVICEREGISTERS_REGISTERS_H_

/**
*   @file    Trgmux_Ip_Cfg_DeviceRegisters.h
*
*   @version 2.0.0
*
*   @brief   AUTOSAR Mcl - Trgmux Ip Cfg Device Registers header file.
*   @details
*
*   @addtogroup TRGMUX_IP_DRIVER TRGMUX IP Driver
*   @{
*/

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
#include "S32K144_TRGMUX.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_CFG_DEVICEREGISTERS_VENDOR_ID                    43
#define TRGMUX_IP_CFG_DEVICEREGISTERS_MODULE_ID                    255
#define TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION     4
#define TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION     7
#define TRGMUX_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION  0
#define TRGMUX_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION             2
#define TRGMUX_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION             0
#define TRGMUX_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION             0


/* ----------------------------------------------------------------------------
   -- TRGMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Peripheral_Access_Layer TRGMUX Peripheral Access Layer
 * @{
 */
#define TRGMUX_IP_TRGMUXn_INSTANCE_COUNT(Instance)   TRGMUX_TRGMUXn_COUNT

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef TRGMUX_IP_CFG_DEVICEREGISTERS_REGISTERS_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
