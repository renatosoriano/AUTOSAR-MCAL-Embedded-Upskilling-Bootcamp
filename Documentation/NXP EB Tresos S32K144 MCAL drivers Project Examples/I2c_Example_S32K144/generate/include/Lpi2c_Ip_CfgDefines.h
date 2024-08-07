/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : LPI2C
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 2.0.0
* Build Version : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
* Copyright 2020-2024 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef LPI2C_IP_CFGDEFINES_H
#define LPI2C_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup LPI2C_DRIVER_CONFIGURATION LPI2C Driver Configurations
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
#include "S32K144_LPI2C.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_CFGDEFINES_VENDOR_ID                     43
#define LPI2C_IP_CFGDEFINES_MODULE_ID                     255
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION      4
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION      7
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION   0
#define LPI2C_IP_CFGDEFINES_SW_MAJOR_VERSION              2
#define LPI2C_IP_CFGDEFINES_SW_MINOR_VERSION              0
#define LPI2C_IP_CFGDEFINES_SW_PATCH_VERSION              0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/



/**
* @brief            Error detection for IP layer
*/
#define LPI2C_IP_DEV_ERROR_DETECT   (STD_ON)  /* Enable Development Error Detection for IP */

/**
* @brief            Error events of the i2c module enable/disabled
*/
#define LPI2C_IP_EVENT_ERROR_DETECT   (STD_OFF) /* Disable Development Error Detection for IP */

/**
* @brief            Dma transfer error of the i2c module enable/disabled
*/
#define LPI2C_IP_DMA_TRANSFER_ERROR_DETECT   (STD_OFF) /* Disable Dma Transfer Error Detection for IP */


/**
* @brief            Dma support enable/disabled
*/
#define LPI2C_IP_DMA_FEATURE_AVAILABLE (STD_OFF) /* Disable DMA support for IP */

/**
* @brief            LPI2C timeout type
*/
#define I2C_TIMEOUT_TYPE                (OSIF_COUNTER_DUMMY)

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPI2C_IP_CFGDEFINES_H */
