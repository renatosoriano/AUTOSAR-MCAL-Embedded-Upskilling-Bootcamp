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
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   Copyright 2020-2023 NXP Semiconductors NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXIO_SPI_IP_TYPES_H
#define FLEXIO_SPI_IP_TYPES_H

/**
*   @file     Flexio_Spi_Ip_Types.h
*
*   @brief   FLEXIO_SPI_IP_TYPES IP driver types header file.
*   @details FLEXIO_SPI_IP_TYPES IP driver types header file.

*   @addtogroup FLEXIO_SPI_DRIVER  Flexio_Spi Driver
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
#include "Flexio_Spi_Ip_Cfg.h"
#include "StandardTypes.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_SPI_IP_TYPES_VENDOR_ID                       43
#define FLEXIO_SPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define FLEXIO_SPI_IP_TYPES_AR_RELEASE_MINOR_VERSION        7
#define FLEXIO_SPI_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define FLEXIO_SPI_IP_TYPES_SW_MAJOR_VERSION                2
#define FLEXIO_SPI_IP_TYPES_SW_MINOR_VERSION                0
#define FLEXIO_SPI_IP_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Flexio_Spi_Ip_Types.h and Flexio_Spi_Ip_Cfg.h are of the same vendor */
#if (FLEXIO_SPI_IP_TYPES_VENDOR_ID != FLEXIO_SPI_IP_VENDOR_ID_CFG)
    #error "Flexio_Spi_Ip_Types.h and Flexio_Spi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Flexio_Spi_Ip_Types.h file and Flexio_Spi_Ip_Cfg.h file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Flexio_Spi_Ip_Types.h and Flexio_Spi_Ip_Cfg.h are different"
#endif
#if ((FLEXIO_SPI_IP_TYPES_SW_MAJOR_VERSION != FLEXIO_SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_TYPES_SW_MINOR_VERSION != FLEXIO_SPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_TYPES_SW_PATCH_VERSION != FLEXIO_SPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Flexio_Spi_Ip_Types.h and Flexio_Spi_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Flexio_Spi_Ip_Types.h file and StandardTypes.h file are of the same Autosar version */
    #if ((FLEXIO_SPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_SPI_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Flexio_Spi_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
#if (FLEXIO_SPI_IP_ENABLE == STD_ON)
/** @brief   Enum defining the possible events which triggers end of transfer callback.
*
* @implements Flexio_Spi_Ip_EventType_enum
*/
typedef enum
{
    FLEXIO_SPI_IP_EVENT_END_TRANSFER = 0, /**< The transfer is successfully done. */
    FLEXIO_SPI_IP_EVENT_FAULT = 1         /**< The transfer failed due to overflow/underflow. */
} Flexio_Spi_Ip_EventType;

/** @brief   Callback for all peripherals which supports SPI features. */
typedef void (*Flexio_Spi_Ip_CallbackType)(uint8 Instance,  Flexio_Spi_Ip_EventType Event);

/** @brief   Enum defining the possible transfer modes.
 * @implements Flexio_Spi_Ip_ModeType_enum
*/
typedef enum
{
    FLEXIO_SPI_IP_POLLING = 0, /**< For polling mode the application must call periodically Spi_Ip_ManageBuffers after asynchronous transfers. */
    FLEXIO_SPI_IP_INTERRUPT   /**< For interrupt mode the application doesn't need to perform any additional operations after asynchronous transfers.*/   
}  Flexio_Spi_Ip_ModeType;

/** @brief   Enum defining the possible states of SPI/DSPI hardware unit.
 * @implements Flexio_Spi_Ip_HwStatusType_enum
*/
typedef enum
{
   FLEXIO_SPI_IP_UNINIT = 0u, /**< Module is not initialized. */
   FLEXIO_SPI_IP_IDLE = 1u,   /**< Module is not used. */
   FLEXIO_SPI_IP_BUSY = 2u,   /**< A transfer is in progress. */
   FLEXIO_SPI_IP_FAULT = 3u   /**< During last transfer a fault occurred. */
}  Flexio_Spi_Ip_HwStatusType;

/** @brief   Enum defining the possible return types. 
 * @implements Flexio_Spi_Ip_StatusType_enum
*/
typedef enum
{
   FLEXIO_SPI_IP_STATUS_SUCCESS = 0u, /**< Successful operation. */
   FLEXIO_SPI_IP_STATUS_FAIL    = 1u, /**< Failed operation. */
   FLEXIO_SPI_IP_FIFO_ERROR     = 2u, /**< Overflow or underflow error. */
   FLEXIO_SPI_IP_TIMEOUT        = 3u  /**< Timeout error. */
}  Flexio_Spi_Ip_StatusType;

#if (FLEXIO_SPI_IP_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   Specifies the Clock Modes.
*/
typedef enum
{
    FLEXIO_SPI_IP_NORMAL_CLOCK = 0,        /**< @brief Clock reference is from SpiClockRef. */
    FLEXIO_SPI_IP_ALTERNATE_CLOCK          /**< @brief Clock reference is from SpiAlternateClockRef. */
}Flexio_Spi_Ip_DualClockModeType;
#endif

/** @brief   Structure defining some parameters often change of the spi bus. */
typedef struct  
{
   uint8 FrameSize;    /**< Frame size configured */
   boolean Lsb;    /**< Transfer LSB first or MSB first */
   uint32 DefaultData;  /**< Default data to send when TxBuffer is NULL_PTR */
} Flexio_Spi_Ip_DeviceParamsType;

/** @brief   Structure defining the parameters of the spi bus. */
typedef struct  
{ 
    uint8 Instance; /**< Instance of the hardware unit. */
    uint8 Cpol; 
    uint8 Cpha; 
#if (FLEXIO_SPI_IP_DUAL_CLOCK_MODE == STD_ON)
    uint32 ClkTimeCmpBaudRate[2];
    uint32 ClkTimeCfgTimDec[2];
#else
    uint32 ClkTimeCmpBaudRate;
    uint32 ClkTimeCfgTimDec;
#endif
   uint32 TxShiftCtl;     /**< SHIFTCTL register of TX */
   uint32 TxShiftCfg;     /**< SHIFTCFG register of TX */
   uint32 RxShiftCtl;     /**< SHIFTCTL register of RX */
   uint32 RxShiftCfg;     /**< SHIFTCFG register of RX */
   uint32 ClkTimeCmp;     /**< TIMCMP register of CLK */
   uint32 ClkTimeCfg;     /**< TIMCFG register of CLK */
   uint32 ClkTimeCtl;      /**< TIMCTL register of CLK */
   uint32 CsTimeCmp;      /**< TIMCMP register of CS */
   uint32 CsTimeCfg;      /**< TIMCFG register of CS */
   uint32 CsTimeCtl;      /**< TIMCTL register of CS */
   Flexio_Spi_Ip_DeviceParamsType * DeviceParams;   /**< Contain configuration for bit order, frame size, default transmit data. */   
} Flexio_Spi_Ip_ExternalDeviceType;

/** @brief   Structure defining information needed for SPI driver initialization. */
typedef struct  
{
   uint8 Instance; /**< Instance of the hardware unit. */
#if (FLEXIO_SPI_IP_SLAVE_SUPPORT == STD_ON)
   boolean SlaveMode;
#endif    
#if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
   boolean DmaUsed;        /**< DMA is used or not */
   uint8   TxDmaChannel;    /**< Id of TX DMA channel for transmition */
   uint8   RxDmaChannel;    /**< Id of RX DMA channel for receive */
#endif
   Flexio_Spi_Ip_ModeType TransferMode; /**< Transfer mode for HWunit */
   uint32 FrameSize;    /**< Frame size configured */
   boolean Lsb;    /**< Transfer LSB first or MSB first */
   uint32 DefaultData;  /**< Default data to send when TxBuffer is NULL_PTR */
   uint8 TxShifterIndex; /**< No. of shifter for TX */
   uint8 RxShifterIndex; /**< No. of shifter for RX */
   uint8 ClkTimerIndex;  /**< No. of timer for CLK */
   uint8 CsTimerIndex;   /**< No. of timer for CS */
   uint8 StateIndex; /**< State of current transfer  */
} Flexio_Spi_Ip_ConfigType;

/** @brief   Structure defining information needed for internal state of the driver. */
typedef struct
{
   #if (FLEXIO_SPI_IP_DUAL_CLOCK_MODE == STD_ON)
   Flexio_Spi_Ip_DualClockModeType ClockMode; /**< Store current clock mode for HWunit */
   #endif
   Flexio_Spi_Ip_ModeType TransferMode; /**< Store current transfer mode for HWunit */
   boolean FirstChannel; /**< This is the first channel in a job */
   Flexio_Spi_Ip_HwStatusType Status; /**< 0 = available, 1 = busy, 2 = fail due to overflow or underflow */
   uint8* RxBuffer;  /**< Store pointer for Rx buffer */
   const uint8* TxBuffer;  /**< Store pointer for Tx buffer */
   Flexio_Spi_Ip_CallbackType Callback;  /**< Store pointer for call back function */
   uint16 RxIndex;  /**< Store current Rx index to receive data in Rx buffer */
   uint16 TxIndex;  /**< Store current Tx index to transmit data in Tx buffer */
   uint16 ExpectedFifoReads;    /**< Store number of frames needs to be receive for current transfer */
   uint16 ExpectedFifoWrites;   /**< Store number of frames needs to be transmit for current transfer */
   const Flexio_Spi_Ip_ConfigType *PhyUnitConfig;  
   const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice; /**< Store externalDevice */
} Flexio_Spi_Ip_StateStructureType;

#endif /*(FLEXIO_SPI_IP_ENABLE == STD_ON)*/

#ifdef __cplusplus
}
#endif

#endif /*FLEXIO_SPI_IP_TYPES*/

/** @} */
