/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
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

#ifndef WDOG_IP_CFG_DEFINES_H
#define WDOG_IP_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup Wdog_Ip
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

#include "StandardTypes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDOG_IP_CFG_DEFINES_VENDOR_ID                    43
#define WDOG_IP_CFG_DEFINES_MODULE_ID                    102
#define WDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define WDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define WDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define WDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION             2
#define WDOG_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define WDOG_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((WDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (WDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdog_Ip_Cfg_Defines.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief  Compile switch to enable development error detection
*/
#define WDOG_IP_DEV_ERROR_DETECT (STD_ON)

/**
* @brief  This constant specifies if the instance of the WDG is selected or not
*/
#define WDOG_IP_ENABLE           (STD_ON)


/**
* @brief  Compile switch to allow/forbid disabling the Wdog during runtime
*/
#define WDOG_IP_DEINIT (STD_ON)

/**
* @brief Define Timeout Method.
* @details Define a certain timeout method from OsIf which will be used in the driver.
*/
#define WDOG_IP_TIMEOUT_METHOD           (OSIF_COUNTER_DUMMY)

/**
* @brief Define Timeout Value.
* @details Define a certain timeout value from OsIf which will be used in the driver.
*/
#define WDOG_IP_OSIF_TIMEOUT_VAL        (5000)



/**
* @brief  This variable will indicate if the ISR for WDOG instances is used
*/
#define WDOG_IP_ISR0_USED (STD_OFF)



/**
* @brief  This variable will indicate if the WDOG test mode is enabled
* Note: This feature is not available in the Wdg High Level Driver
*/
#define WDOG_IP_ENABLE_TEST_MODE (STD_OFF)


/**
* @brief  This variable will indicate RAM/ROM execution
*/

#define WDG_ROM (1U)


/**
 * @brief The 32-bit value used for unlocking the WDOG
 */
#define WDOG_IP_FEATURE_UNLOCK_VALUE_U32 (0xD928C520U)

/**
 * @brief The 32-bit value used for resetting the WDOG counter
 */
#define WDOG_IP_FEATURE_TRIGGER_VALUE_U32 (0xB480A602U)

/**
 * @brief The reset value of the timeout register
 */
#define WDOG_IP_FEATURE_TO_RESET_VALUE_U16 (0x0400U)

/**
 * @brief The value minimum of the timeout register
 */
#define WDOG_IP_FEATURE_MINIMUM_TIMEOUT_VALUE_U16 (0x0000U)

/**
 * @brief The reset value of the window register
 */
#define WDOG_IP_FEATURE_WIN_RESET_VALUE_U16 (0x0000U)

/**
 * @brief The first 16-bit value used for unlocking the WDOG
 */
#define WDOG_IP_FEATURE_UNLOCK16_FIRST_VALUE_U16 (0xC520U)

/**
 * @brief The second 16-bit value used for unlocking the WDOG
 */
#define WDOG_IP_FEATURE_UNLOCK16_SECOND_VALUE_U16 (0xD928U)

/**
 * @brief The first 16-bit value used for resetting the WDOG counter
 */
#define WDOG_IP_FEATURE_TRIGGER16_FIRST_VALUE_U16 (0xA602U)

/**
 * @brief The second 16-bit value used for resetting the WDOG counter
 */
#define WDOG_IP_FEATURE_TRIGGER16_SECOND_VALUE_U16 (0xB480U)

/**
 * @brief Default reset value of the CS register
 */
#define WDOG_IP_FEATURE_CS_RESET_VALUE_U16 (0x2980U)

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

/** @} */

#endif /* WDOG_IP_CFG_DEFINES_H */
