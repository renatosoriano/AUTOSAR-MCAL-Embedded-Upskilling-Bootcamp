/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXIO_SPI_IP_CFG_H
#define FLEXIO_SPI_IP_CFG_H

/**
*   @file     Flexio_Spi_Ip_Cfg.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the necessary information for SPI
*            module configuration(s).
*   @addtogroup FLEXIO_DRIVER_CONFIGURATION  Flexio_Spi Driver Configuration
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
* 4) user callback header files
==================================================================================================*/
#include "Mcal.h"
#include "OsIf.h"

#include "Flexio_Spi_Ip_PBcfg.h"

#include "S32K144_FLEXIO.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_SPI_IP_VENDOR_ID_CFG                       43
#define FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG        4
#define FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG        7
#define FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_CFG     0
#define FLEXIO_SPI_IP_SW_MAJOR_VERSION_CFG                2
#define FLEXIO_SPI_IP_SW_MINOR_VERSION_CFG                0
#define FLEXIO_SPI_IP_SW_PATCH_VERSION_CFG                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexio_Spi_Ip_Cfg.h and Mcal.h are different"
    #endif

    /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexio_Spi_Ip_Cfg.h and OsIf.h are different"
    #endif
#endif


/* Check if Flexio_Spi_Ip_PBcfg header file and Spi configuration header file are of the same vendor */
#if (FLEXIO_SPI_IP_VENDOR_ID_PBCFG != FLEXIO_SPI_IP_VENDOR_ID_CFG)
    #error "Flexio_Spi_Ip_PBcfg.h and Flexio_Spi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Flexio_Spi_Ip_PBcfg header file and Spi  configuration header file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_PBCFG != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_PBCFG != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_PBCFG != FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Flexio_Spi_Ip_PBcfg.h and Flexio_Spi_Ip_Cfg.h are different"
#endif
/* Check if Flexio_Spi_Ip_PBcfg header file and Spi configuration header file are of the same software version */
#if ((FLEXIO_SPI_IP_SW_MAJOR_VERSION_PBCFG != FLEXIO_SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_SW_MINOR_VERSION_PBCFG != FLEXIO_SPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_SW_PATCH_VERSION_PBCFG != FLEXIO_SPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Flexio_Spi_Ip_PBcfg.h and Flexio_Spi_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief Flexio SPI supported enable.
* @details Flexio SPI supported enable. 
*/
#define FLEXIO_SPI_IP_ENABLE     (STD_OFF)

#if (FLEXIO_SPI_IP_ENABLE == STD_ON)
#define FLEXIO_SPI_IP_CONFIG_EXT \
 FLEXIO_SPI_IP_CONFIG_PB


/** @brief Total number of SpiPhyUnit configured. */
#define FLEXIO_SPI_IP_NUMBER_OF_INSTANCES           (1U)

/** @brief Total number of FLEXIO_SPI HW Unit are supported . */
#define FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8         (uint8)(2U)

/** @brief Total number of Flexio instance. */
#define FLEXIO_SPI_IP_INSTANCE_COUNT           (FLEXIO_INSTANCE_COUNT)

/** @brief HWUnits enabled/disabled */

#define FLEXIO_SPI_IP_SLAVE_SUPPORT  ((STD_OFF))


/**
* @brief Defines if transfers are made using DMA or FIFO.
* @details Defines if transfers are made using DMA or FIFO.
*/
#define FLEXIO_SPI_IP_DMA_USED     (STD_OFF)

/**
* @brief If enabled, allows dual MCU clock configuration settings.
* @details If enabled, allows dual MCU clock configuration settings.
*/
#define FLEXIO_SPI_IP_DUAL_CLOCK_MODE  (STD_OFF)

/**
* @brief Define Timeout Method.
* @details Define a certain timeout method from OsIf will be used in the driver.
*/
#define FLEXIO_SPI_IP_TIMEOUT_METHOD           (OSIF_COUNTER_DUMMY)

/**
* @brief          Enable User Mode Support.
* @details        When SpiAutosarExt/SpiEnableUserModeSupport = TRUE,
*                 the SPI driver can be executed from both supervisor and user mode.
*
* @api
*/
#define FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT (STD_OFF)

/**
* @brief Switches ON or OFF for the detection and reporting of development errors(API parameter checking) at IP level.
*/
/** @implements FLEXIO_SPI_IP_DEV_ERROR_DETECT_define  */
#define FLEXIO_SPI_IP_DEV_ERROR_DETECT     (STD_OFF)

/**
* @brief Maximum of frame size supported.
*/
#define FLEXIO_SPI_IP_FRAMESIZE_MAX_U8                              ((uint8)64U)

/**
* @brief Maximum of frame size supported.
*/
#define FLEXIO_SPI_IP_FRAMESIZE_MIN_U8                              ((uint8)4U)

/** @brief Write to CTRL */
#define FLEXIO_SPI_IP_CTRL_FLEXEN(x)  FLEXIO_CTRL_FLEXEN(x)

/** @brief Write to  TIMCMP */
#define FLEXIO_SPI_IP_TIMECMP_BAUDRATE_MASK_U32  ((uint32) 0x00FFu)
#define FLEXIO_SPI_IP_TIMECMP_FRAMESIZE_MASK_U32 ((uint32) 0xFF00u)
#define FLEXIO_SPI_IP_TIMCMP_CMP(x)        FLEXIO_TIMCMP_CMP(x)

/** @brief CPOL and CPHA selection */
#define FLEXIO_SPI_IP_CPOL_LOW_U8          ((uint8) 0U)
#define FLEXIO_SPI_IP_CPOL_HIGH_U8         ((uint8) 1U)
#define FLEXIO_SPI_IP_CPHA_LEADING_U8      ((uint8) 0U)
#define FLEXIO_SPI_IP_CPHA_TRAILING_U8     ((uint8) 1U)

/** @brief Write to  SHIFTCTL */
#define FLEXIO_SPI_IP_SHIFTCTL_TIMSEL(x)     FLEXIO_SHIFTCTL_TIMSEL(x)
#define FLEXIO_SPI_IP_SHIFTCTL_PINSEL(x)     FLEXIO_SHIFTCTL_PINSEL(x)
#define FLEXIO_SPI_IP_SHIFTCTL_PINCFG(x)     FLEXIO_SHIFTCTL_PINCFG(x) 
#define FLEXIO_SPI_IP_SHIFTCTL_SMOD(x)       FLEXIO_SHIFTCTL_SMOD(x)
#define FLEXIO_SPI_IP_SHIFTCTL_TIMPOL(x)     FLEXIO_SHIFTCTL_TIMPOL(x)

/** @brief Write to SHIFTCFG */
#define FLEXIO_SPI_IP_SHIFTCFG_SSTOP(x)      FLEXIO_SHIFTCFG_SSTOP(x)
#define FLEXIO_SPI_IP_SHIFTCFG_SSTART(x)     FLEXIO_SHIFTCFG_SSTART(x)
#define FLEXIO_SPI_IP_TIMCFG_TIMDEC(x)       FLEXIO_TIMCFG_TIMDEC(x)

/** @brief Write to TIMCTL  */
#define FLEXIO_SPI_IP_TIMCTL_PINSEL(x)             FLEXIO_TIMCTL_PINSEL(x)
#define FLEXIO_SPI_IP_TIMCTL_TRGSEL(x)             FLEXIO_TIMCTL_TRGSEL(x)
#define FLEXIO_SPI_IP_TIMCTL_TRGSRC(x)             FLEXIO_TIMCTL_TRGSRC(x)
#define FLEXIO_SPI_IP_TIMCTL_TIMOD(x)              FLEXIO_TIMCTL_TIMOD(x)
#define FLEXIO_SPI_IP_TIMCTL_TRGPOL(x)             FLEXIO_TIMCTL_TRGPOL(x)
#define FLEXIO_SPI_IP_TIMCTL_PINPOL(x)             FLEXIO_TIMCTL_PINPOL(x)
#define FLEXIO_SPI_IP_TIMCTL_PINCFG(x)             FLEXIO_TIMCTL_PINCFG(x)
#define FLEXIO_SPI_IP_TIMCTL_ONETIM(x)             FLEXIO_TIMCTL_ONETIM(x)

/** @brief Write to TIMCFG  */
#define FLEXIO_SPI_IP_TIMCFG_TIMOUT(x)             FLEXIO_TIMCFG_TIMOUT(x)
#define FLEXIO_SPI_IP_TIMCFG_TIMDIS(x)             FLEXIO_TIMCFG_TIMDIS(x)
#define FLEXIO_SPI_IP_TIMCFG_TIMENA(x)             FLEXIO_TIMCFG_TIMENA(x)
#define FLEXIO_SPI_IP_TIMCFG_TIMRST(x)             FLEXIO_TIMCFG_TIMRST(x)
#define FLEXIO_SPI_IP_TIMCFG_DEFAULT_MASTER_VALUE_U32         ((uint32) 0x00000222u)
#define FLEXIO_SPI_IP_TIMCFG_DEFAULT_SLAVE_CPHA0_VALUE         ((uint32) 0x01200600u)
#define FLEXIO_SPI_IP_TIMCFG_DEFAULT_SLAVE_CPHA1_VALUE         ((uint32) 0x01206602u)

/** @brief Write to SHIFTSIEN and SHIFTSDEN */
#define FLEXIO_SPI_IP_SHIFTSIEN_SSIE(x)         FLEXIO_SHIFTSIEN_SSIE(x)
#define FLEXIO_SPI_IP_SHIFTSDEN_SSDE(x)         FLEXIO_SHIFTSDEN_SSDE(x) 

/**
* @brief Shifters and Timer index
*/
#define FLEXIO_SPI_IP_SHIFTER_0_U8                   ((uint8)0U)
#define FLEXIO_SPI_IP_SHIFTER_1_U8                   ((uint8)1U)
#define FLEXIO_SPI_IP_SHIFTER_2_U8                   ((uint8)2U)
#define FLEXIO_SPI_IP_SHIFTER_3_U8                   ((uint8)3U)
#define FLEXIO_SPI_IP_SHIFTER_4_U8                   ((uint8)4U)
#define FLEXIO_SPI_IP_SHIFTER_5_U8                   ((uint8)5U)
#define FLEXIO_SPI_IP_SHIFTER_6_U8                   ((uint8)6U)
#define FLEXIO_SPI_IP_SHIFTER_7_U8                   ((uint8)7U)

#define FLEXIO_SPI_IP_TIMER_0_U8                     ((uint8)0U)
#define FLEXIO_SPI_IP_TIMER_1_U8                     ((uint8)1U)
#define FLEXIO_SPI_IP_TIMER_2_U8                     ((uint8)2U)
#define FLEXIO_SPI_IP_TIMER_3_U8                     ((uint8)3U)
#define FLEXIO_SPI_IP_TIMER_4_U8                     ((uint8)4U)
#define FLEXIO_SPI_IP_TIMER_5_U8                     ((uint8)5U)
#define FLEXIO_SPI_IP_TIMER_6_U8                     ((uint8)6U)
#define FLEXIO_SPI_IP_TIMER_7_U8                     ((uint8)7U)

#endif /*(FLEXIO_SPI_IP_ENABLE == STD_ON)*/
/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
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

#endif 

/** @} */
