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

#ifndef SPI_IP_TYPES_H
#define SPI_IP_TYPES_H

/**
*   @file    Lpspi_Ip_Types.h
*
*   @brief   LPSPI IP driver types header file.
*   @details LPSPI IP driver types header file.

*   @addtogroup LPSPI_DRIVER Lpspi Driver
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
#include "StandardTypes.h"
#include "Lpspi_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPSPI_IP_TYPES_VENDOR_ID                    43
#define LPSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define LPSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define LPSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define LPSPI_IP_TYPES_SW_MAJOR_VERSION             2
#define LPSPI_IP_TYPES_SW_MINOR_VERSION             0
#define LPSPI_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((LPSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LPSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lpspi_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif

/* Check if Lpspi_Ip_Types.h header file and Lpspi_Ip_Cfg.h configuration header file are of the same vendor */
#if (LPSPI_IP_TYPES_VENDOR_ID != LPSPI_IP_VENDOR_ID_CFG)
    #error "Lpspi_Ip_Types.h and Lpspi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Lpspi_Ip_Types.h header file and Lpspi_Ip_Cfg.h  configuration header file are of the same Autosar version */
#if ((LPSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (LPSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION != LPSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (LPSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION != LPSPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Lpspi_Ip_Types.h and Lpspi_Ip_Cfg.h are different"
#endif
/* Check if Lpspi_Ip_Types.h header file and Lpspi_Ip_Cfg.h configuration header file are of the same software version */
#if ((LPSPI_IP_TYPES_SW_MAJOR_VERSION != LPSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (LPSPI_IP_TYPES_SW_MINOR_VERSION != LPSPI_IP_SW_MINOR_VERSION_CFG) || \
     (LPSPI_IP_TYPES_SW_PATCH_VERSION != LPSPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Lpspi_Ip_Types.h and Lpspi_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief   Enum defining the possible events which triggers end of transfer callback. 
*
* @implements Lpspi_Ip_EventType_enum
*/
typedef enum
{
    LPSPI_IP_EVENT_END_TRANSFER = 0, /**< The transfer is successfully done. */
    LPSPI_IP_EVENT_FAULT = 1         /**< The transfer failed due to overflow/underflow. */
} Lpspi_Ip_EventType;

/** @brief   Callback for all peripherals which supports SPI features. */
typedef void (*Lpspi_Ip_CallbackType)(uint8 Instance, Lpspi_Ip_EventType Event);

/** @brief   Enum defining the possible transfer modes.
* @implements Lpspi_Ip_ModeType_enum
*/
typedef enum
{
    LPSPI_IP_POLLING = 0, /**< For polling mode the application must call periodically Spi_Ip_ManageBuffers after asynchronous transfers. */
    LPSPI_IP_INTERRUPT   /**< For interrupt mode the application doesn't need to perform any additional operations after asynchronous transfers.
                            The application must enable the interrupt requests and install the right callbacks. */
} Lpspi_Ip_ModeType;

/** @brief   Enum defining the possible states of SPI/DSPI hardware unit.
* @implements Lpspi_Ip_HwStatusType_enum
*/
typedef enum
{
   LPSPI_IP_UNINIT = 0u, /**< Module is not initialized. */
   LPSPI_IP_IDLE = 1u, /**< Module is not used. */
   LPSPI_IP_BUSY = 2u,   /**< A transfer is in progress. */
   LPSPI_IP_FAULT = 3u   /**< During last transfer a fault occurred. */
} Lpspi_Ip_HwStatusType;

/** @brief   Enum defining the possible return types. 
* @implements Lpspi_Ip_StatusType_enum
*/
typedef enum
{
   LPSPI_IP_STATUS_SUCCESS = 0u, /**< Successful operation. */
   LPSPI_IP_STATUS_FAIL    = 1u, /**< Failed operation. */
   LPSPI_IP_FIFO_ERROR     = 2u, /**< Overflow or underflow error. */
   LPSPI_IP_TIMEOUT        = 3u  /**< Timeout error. */
} Lpspi_Ip_StatusType;

#if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
/** @brief   Enum defining the half duplex types. 
*/
typedef enum
{
   LPSPI_IP_HALF_DUPLEX_TRANSMIT   = 0u, /**< Transmit only. */
   LPSPI_IP_HALF_DUPLEX_RECEIVE    = 1u, /**< Receive only. */
   LPSPI_IP_FULL_DUPLEX                 = 2u /**< Full duplex mode. */
} Lpspi_Ip_HalfDuplexType;
#endif

/** @brief   Structure defining some parameters often change of the spi bus. */
typedef struct  
{
   uint16 FrameSize;    /**< Frame size configured */
   boolean Lsb;    /**< Transfer LSB first or MSB first */
   uint32 DefaultData;  /**< Default data to send when TxBuffer is NULL_PTR */
#if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
   Lpspi_Ip_HalfDuplexType TransferType;    /**< TransferType */
#endif
} Lpspi_Ip_DeviceParamsType;

/** @brief   Structure defining the parameters of the spi bus. */
typedef struct
{
   uint8 Instance; /**< Instance of the hardware unit. */
   #if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
   uint32 Ccr[2u];     /**< CCR register which contains clocking and frame size configuration. */
   uint32 Tcr[2u];     /**< TCR register which contains clock polarities, frame size, which PCS and continuous mode. */
   #else
   uint32 Ccr;     /**< CCR register which contains clocking and frame size configuration. */
   uint32 Tcr;     /**< TCR register which contains clock polarities, frame size, which PCS and continuous mode. */
   #endif
   #if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
   uint32 HalfDuplexCfgr1;  /**< CFGR1 register which contains bit fields to support half duplex mode . */
   #endif
   Lpspi_Ip_DeviceParamsType * DeviceParams;   /**< Contain configuration for bit order, frame size, default transmit data. */
} Lpspi_Ip_ExternalDeviceType;

#if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   Specifies the Clock Modes.
*/
typedef enum
{
    LPSPI_IP_NORMAL_CLOCK = 0,        /**< @brief Clock reference is from SpiClockRef. */
    LPSPI_IP_ALTERNATE_CLOCK          /**< @brief Clock reference is from SpiAlternateClockRef. */
}Lpspi_Ip_DualClockModeType;
#endif

#if (LPSPI_IP_DMA_USED == STD_ON)
#if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
/** @brief   Structure defining transmition command needed for Dma Fast transfer. */
typedef struct  
{ 
   uint32 DmaFastTcrCmd;   /**< Contains transfer command for Dma Fast transfer. */
   uint32 DmaFastTcrCmdLast;   /**< Contains transfer command  and disable continuos mode for Dma Fast transfer. */
   uint32 DefaultData;  /**< Default data to send when TxBuffer is NULL_PTR */
} Lpspi_Ip_CmdDmaFastType;

/** @brief   Structure defining information needed for Dma Fast transfer session.
 * @implements Lpspi_Ip_FastTransferType_struct
 */
typedef struct  
{
    const Lpspi_Ip_ExternalDeviceType *ExternalDevice; /**< Point to external device configuration */
    const uint8* TxBuffer;  /**< Store pointer for Tx buffer */
    uint8* RxBuffer;  /**< Store pointer for Rx buffer */
    uint32 DefaultData;  /**< Default data to send when TxBuffer is NULL_PTR */
    uint16 Length;  /**< Number of bytes to be sent */
    boolean KeepCs;  /**< Keep CS signal after transfer session completed */
} Lpspi_Ip_FastTransferType;
#endif
#endif

/** @brief   Structure defining information needed for SPI driver initialization. */
typedef struct
{
   uint8 Instance; /**< Instance of the hardware unit. */
   uint32  Cr;     /**< It contains only debug enable. */
   uint32  Cfgr1;  /**< It contains PCS polarities. */
   #if (LPSPI_IP_SLAVE_SUPPORT == STD_ON)
   boolean SlaveMode;
   #endif
   #if (LPSPI_IP_DMA_USED == STD_ON)
   boolean DmaUsed;    /**< DMA is used or not */
   uint8   TxDmaChannel;    /**< Id of TX DMA channel for transmition */
   uint8   RxDmaChannel;    /**< Id of RX DMA channel for receive */
   #if (LPSPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
   uint8 MaxNumOfFastTransfer; /**< Maximum number of transfers in Dma Fast */
   Lpspi_Ip_CmdDmaFastType *CmdDmaFast; /**< Point to list of TCR command used in Dma Fast transfer */
   uint8 NumberTxSG; /**< Number of TCD Scatter Gather for Tx DMA channel used in Dma Fast transfer */
   uint8 NumberRxSG; /**< Number of TCD Scatter Gather for Rx DMA channel used in Dma Fast transfer */
   const uint8 *TxDmaFastSGId; /**< Point to list of TCD Scatter Gather Id for Tx DMA channel used in Dma Fast transfer */
   const uint8 *RxDmaFastSGId; /**< Point to list of TCD Scatter Gather Id for Rx DMA channel used in Dma Fast transfer */
   #endif
   #endif
   Lpspi_Ip_ModeType TransferMode; /**< Transfer mode for HWunit */
   uint8 StateIndex; /**< State of current transfer  */
} Lpspi_Ip_ConfigType;

/** @brief   Structure defining information needed for internal state of the driver. */
typedef struct
{
   #if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
   Lpspi_Ip_DualClockModeType ClockMode; /**< Store current clock mode for HWunit */
   #endif
   Lpspi_Ip_ModeType TransferMode; /**< Store current transfer mode for HWunit */
   Lpspi_Ip_HwStatusType Status; /**< 0 = available, 1 = busy, 2 = fail due to overflow or underflow */
   uint8* RxBuffer;  /**< Store pointer for Rx buffer */
   const uint8* TxBuffer;  /**< Store pointer for Tx buffer */
   Lpspi_Ip_CallbackType Callback;  /**< Store pointer for call back function */
   uint16 RxIndex;  /**< Store current Rx index to receive data in Rx buffer */
   uint16 TxIndex;  /**< Store current Tx index to transmit data in Tx buffer */
   uint16 ExpectedFifoReads;    /**< Store number of words needed to be receive for current transfer */
   uint16 ExpectedFifoWrites;   /**< Store number of words needed to be transmitted for current transfer */
   boolean KeepCs;   /**< Keep CS signal after transfers completed. */
   boolean FirstCmd;
   const Lpspi_Ip_ConfigType *PhyUnitConfig;
   const Lpspi_Ip_ExternalDeviceType *ExternalDevice;
   uint16 TxFrameSize; /**< Store current frame size for HWunit */
   boolean TxLsb;   /**< Transfer LSB first or MSB first */
   const uint8* TxBufferNext;  /**< Store pointer for Tx buffer */
   uint16 FrameSizeNext; /**< Store current frame size for HWunit */
   boolean LsbNext;   /**< Transfer LSB first or MSB first */
   uint32 DefaultDataNext;  /**< Default data to send when TxBuffer is NULL_PTR */
   uint16 LengthNext;   /**< Store number of frames needs to be transmit for current transfer */
   boolean NextTransferConfigAvailable;   /**< Flag to check next transfer configuration is available */
   boolean NextTransferDone;   /**< Flag to check next transfer done */
   uint8 CurrentTxFifoSlot;   /**< Number of TX FIFO slots are current available. */
#if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
   uint32 HalfDuplexTcrCommand;   /**< Save the value which will be written to TCR register in DMA mode */
   boolean NextChannelIsRX;   /**< Save the value which will be written to TCR register in DMA mode */
#endif
   boolean TxDoneFlag;   /**< Flag to check TX is done */
} Lpspi_Ip_StateStructureType;

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

#endif /*LPSPI_IP_TYPES*/
