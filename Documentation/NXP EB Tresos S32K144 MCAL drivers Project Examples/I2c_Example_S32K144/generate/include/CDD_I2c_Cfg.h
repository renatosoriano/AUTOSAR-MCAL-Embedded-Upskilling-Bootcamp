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

#ifndef CDD_I2C_CFG_H
#define CDD_I2C_CFG_H

/**
*   @file
*
*   @addtogroup I2C_DRIVER_CONFIGURATION I2c Driver Configurations
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

#include "CDD_I2c_VS_0_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* Inclusion of incompatible header files shall be avoided */

#define I2C_VENDOR_ID_CFG                    43
#define I2C_MODULE_ID_CFG                    255
#define I2C_AR_RELEASE_MAJOR_VERSION_CFG     4
#define I2C_AR_RELEASE_MINOR_VERSION_CFG     7
#define I2C_AR_RELEASE_REVISION_VERSION_CFG  0
#define I2C_SW_MAJOR_VERSION_CFG             2
#define I2C_SW_MINOR_VERSION_CFG             0
#define I2C_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and CDD_I2c_VS_0_PBcfg.h file are of the same module */
#if (I2C_MODULE_ID_CFG  != I2C_VS_0_PBCFG_MODULE_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_VS_0_PBcfg.h have different module ids"
#endif
/* Check if current file and CDD_I2c_VS_0_PBcfg.h file are of the same vendor */
#if (I2C_VENDOR_ID_CFG != I2C_VS_0_PBCFG_VENDOR_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_VS_0_PBcfg.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_VS_0_PBcfg.h file are of the same Autosar version */
#if ((I2C_AR_RELEASE_MAJOR_VERSION_CFG != I2C_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_AR_RELEASE_MINOR_VERSION_CFG != I2C_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (I2C_AR_RELEASE_REVISION_VERSION_CFG != I2C_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_VS_0_PBcfg.h are different"
#endif
/* Check if current file and CDD_I2c_VS_0_PBcfg.h file are of the same Software version */
#if ((I2C_SW_MAJOR_VERSION_CFG != I2C_VS_0_PBCFG_SW_MAJOR_VERSION) || \
     (I2C_SW_MINOR_VERSION_CFG != I2C_VS_0_PBCFG_SW_MINOR_VERSION) || \
     (I2C_SW_PATCH_VERSION_CFG != I2C_VS_0_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_VS_0_PBcfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
 /**
* @brief   macro contains all PB configuration macros.
*/
#define I2C_CONFIG_EXT \
 I2C_CONFIG_VS_0_PB 


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief            The callback configured by the user for i2c events.
*/

#define I2C_MODULE_CALLBACK(Event, Channel) (I2c_Callback(Event, Channel))

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
* @brief            The callback configured by the user for i2c events.
*/
extern void I2C_MODULE_CALLBACK(uint8 Event, uint8 Channel);

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"





    

/**
* @brief            Pre-Compile structure from CDD_I2c_Cfg.c file.
*/
#define I2C_CONF_PB \
 extern const I2c_ConfigType I2cGlobalConfig_VS_0;



/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHERS
==================================================================================================*/

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

#endif /* CDD_I2C_CFG_H */

