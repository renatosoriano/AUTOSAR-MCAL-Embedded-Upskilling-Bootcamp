/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : S32K14X
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
/**
*   @file    modules.h
*   @version 2.0.0
*
*   @brief   AUTOSAR BaseNXP - Project configuration.
*   @details Header file describing all Autosar MCAL modules present in the current project.
*
*   @addtogroup BASENXP_COMPONENT
*   @{
*/
/**
* @file        modules.h
*/

#ifndef MODULES_H
#define MODULES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** 
* @file        modules.h
* @brief Include Standard types & defines
*/
#include "StandardTypes.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/** 
@{
* @brief Parameters that shall be published within the modules header file.
*       The integration of incompatible files shall be avoided.
*/
#define MODULES_VENDOR_ID                       43
#define MODULES_MODULE_ID                       0
#define MODULES_AR_RELEASE_MAJOR_VERSION_H      4
#define MODULES_AR_RELEASE_MINOR_VERSION_H      7
#define MODULES_AR_RELEASE_REVISION_VERSION_H   0
#define MODULES_SW_MAJOR_VERSION_H              2
#define MODULES_SW_MINOR_VERSION_H              0
#define MODULES_SW_PATCH_VERSION_H              0
/**@}*/
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and StandardTypes.h header file are of the same Autosar version */
    #if ((MODULES_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MODULES_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of modules.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** 
* @brief This constant used for other modules to check if ADC is present in the project.   
*/
#define USE_ADC_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if CAN is present in the project.   
*/
#define USE_CAN_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if CAN_43_FLEXCAN is present in the project.   
*/
#define USE_CAN_43_FLEXCAN_MODULE   (STD_ON)

/** 
* @brief This constant used for other modules to check if CAN_43_CANEXCEL is present in the project.   
*/
#define USE_CAN_43_CANEXCEL_MODULE  (STD_OFF) 

/** 
* @brief This constant used for other modules to check if CAN_43_LLCE is present in the project.   
*/
#define USE_CAN_43_LLCE_MODULE      (STD_OFF) 

/** 
* @brief This constant used for other modules to check if CRCU is present in the project.   
*/
#define USE_CRCU_MODULE             (STD_OFF) 

/** 
* @brief This constant used for other modules to check if CRYPTO is present in the project.   
*/
#define USE_CRYPTO_MODULE           (STD_OFF) 

/** 
* @brief This constant used for other modules to check if CRYPTO_43_HSE is present in the project.   
*/
#define USE_CRYPTO_43_HSE_MODULE    (STD_OFF) 

/** 
* @brief This constant used for other modules to check if CRYPTO_43_ACE is present in the project.   
*/
#define USE_CRYPTO_43_ACE_MODULE    (STD_OFF) 

/** 
* @brief This constant used for other modules to check if DIO is present in the project.   
*/
#define USE_DIO_MODULE              (STD_OFF) 

/** 
* @brief This constant used for other modules to check if EEP is present in the project. 
*/
#define USE_EEP_MODULE              (STD_OFF) 

/** 
* @brief This constant used for other modules to check if ETH is present in the project. 
*/
#define USE_ETH_MODULE              (STD_OFF) 

/** 
* @brief This constant used for other modules to check if ETH_43_ENET is present in the project. 
*/
#define USE_ETH_43_ENET_MODULE      (STD_OFF) 

/** 
* @brief This constant used for other modules to check if ETH_43_GMAC is present in the project. 
*/
#define USE_ETH_43_GMAC_MODULE      (STD_OFF) 

/** 
* @brief This constant used for other modules to check if ETH_43_NETC is present in the project. 
*/
#define USE_ETH_43_NETC_MODULE      (STD_OFF) 

/** 
* @brief This constant used for other modules to check if FEE is present in the project.   
*/
#define USE_FEE_MODULE              (STD_OFF) 

/** 
* @brief This constant used for other modules to check if FLS is present in the project.   
*/
#define USE_FLS_MODULE              (STD_OFF) 

/** 
* @brief This constant used for other modules to check if Fr is present in the project.   
*/
#define USE_FR_MODULE               (STD_OFF) 

/** 
* @brief This constant used for other modules to check if Fr_43_LLCE is present in the project.   
*/
#define USE_FR_43_LLCE_MODULE       (STD_OFF) 

/** 
* @brief This constant used for other modules to check if GPT is present in the project.   
*/
#define USE_GPT_MODULE              (STD_OFF) 

/** 
* @brief This constant used for other modules to check if I2C is present in the project.   
*/
#define USE_I2C_MODULE              (STD_OFF) 

/** 
* @brief This constant used for other modules to check if ICU is present in the project.   
*/
#define USE_ICU_MODULE              (STD_OFF) 

/**
* @brief This constant used for other modules to check if LIN is present in the project.   
*/
#define USE_LIN_MODULE              (STD_OFF) 

/**
* @brief This constant used for other modules to check if Lin_43_LPUART_FLEXIO is present in the project.   
*/
#define USE_LIN_43_LPUART_FLEXIO_MODULE      (STD_OFF) 

/**
* @brief This constant used for other modules to check if Lin_43_LINFLEXD is present in the project.   
*/
#define USE_LIN_43_LINFLEXD_MODULE           (STD_OFF) 

/** 
* @brief This constant used for other modules to check if Lin_43_LLCE is present in the project.   
*/
#define USE_LIN_43_LLCE_MODULE      (STD_OFF) 

/** 
* @brief This constant used for other modules to check if MCEM is present in the project.   
*/
#define USE_MCEM_MODULE             (STD_OFF) 

/** 
* @brief This constant used for other modules to check if MCEM is present in the project.   
*/
#define USE_MCL_MODULE              (STD_OFF) 

/** 
* @brief This constant used for other modules to check if MCU is present in the project.   
*/
#define USE_MCU_MODULE              (STD_ON) 

/** 
* @brief This constant used for other modules to check if OCU is present in the project. 
*/
#define USE_OCU_MODULE              (STD_OFF) 

/**
* @brief This constant used for other modules to check if PORT is present in the project.   
*/
#define USE_PORT_MODULE             (STD_OFF) 

/** 
* @brief This constant used for other modules to check if PWM is present in the project.   
*/
#define USE_PWM_MODULE              (STD_OFF) 

/** 
* @brief This constant used for other modules to check if SENT is present in the project.   
*/
#define USE_SENT_MODULE             (STD_OFF) 

/** 
* @brief This constant used for other modules to check if SPI is present in the project.   
*/
#define USE_SPI_MODULE              (STD_OFF) 

/** 
* @brief This constant used for other modules to check if WDG is present in the project.   
*/
#define USE_WDG_MODULE    (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 1 is present in the project.
 */
#define USE_WDG_INSTANCE1     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 2 is present in the project.
 */
#define USE_WDG_INSTANCE2     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 3 is present in the project.
 */
#define USE_WDG_INSTANCE3     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 4 is present in the project.
 */
#define USE_WDG_INSTANCE4     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 5 is present in the project.
 */
#define USE_WDG_INSTANCE5     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 6 is present in the project.
 */
#define USE_WDG_INSTANCE6     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 7 is present in the project.
 */
#define USE_WDG_INSTANCE7     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 8 is present in the project.
 */
#define USE_WDG_INSTANCE8     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 9 is present in the project.
 */
#define USE_WDG_INSTANCE9     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 10 is present in the project.
 */
#define USE_WDG_INSTANCE10     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 11 is present in the project.
 */
#define USE_WDG_INSTANCE11     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 12 is present in the project.
 */
#define USE_WDG_INSTANCE12     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 13 is present in the project.
 */
#define USE_WDG_INSTANCE13     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 14 is present in the project.
 */
#define USE_WDG_INSTANCE14     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 15 is present in the project.
 */
#define USE_WDG_INSTANCE15     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 16 is present in the project.
 */
#define USE_WDG_INSTANCE16     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 17 is present in the project.
 */
#define USE_WDG_INSTANCE17     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 18 is present in the project.
 */
#define USE_WDG_INSTANCE18     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 19 is present in the project.
 */
#define USE_WDG_INSTANCE19     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 20 is present in the project.
 */
#define USE_WDG_INSTANCE20     (STD_OFF)

 /**
 * @brief This constant used for other modules to check if WDG Instance 21 is present in the project.
 */
#define USE_WDG_INSTANCE21     (STD_OFF)

/**
 * @brief This constant used for other modules to check if any WDG Instance is present in the project.
 */
#define USE_WDG_INSTANCE_ANY     (STD_OFF)

/** 
* @brief This constant used for other modules to check if WDG for chip vr5510 is present in the project.   
*/
#define USE_WDG_43_VR5510_MODULE      (STD_OFF)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */

/** @} */


