/**
*   @file    Spi.h
*   
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Spi driver header file.
*   @details AUTOSAR specific Spi driver header file.

*   @addtogroup SPI_DRIVER Spi Driver
*   @{
*/
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

#ifndef SPI_H
#define SPI_H

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

#include "StandardTypes.h"
#include "Mcal.h"
#include "Spi_Cfg.h"
#include "Spi_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_MODULE_ID                    83
#define SPI_VENDOR_ID                    43
#define SPI_AR_RELEASE_MAJOR_VERSION     4
#define SPI_AR_RELEASE_MINOR_VERSION     7
#define SPI_AR_RELEASE_REVISION_VERSION  0
#define SPI_SW_MAJOR_VERSION             2
#define SPI_SW_MINOR_VERSION             0
#define SPI_SW_PATCH_VERSION             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if this header file and Spi_Cfg.h are of the same vendor */
#if (SPI_VENDOR_ID != SPI_VENDOR_ID_CFG)
    #error "Spi.h and Spi_Cfg.h have different vendor ids"
#endif
/* Check if source file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION != SPI_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (SPI_AR_RELEASE_MINOR_VERSION != SPI_AR_RELEASE_MINOR_VERSION_CFG) || \
   (SPI_AR_RELEASE_REVISION_VERSION != SPI_AR_RELEASE_REVISION_VERSION_CFG))
  #error "AutoSar Version Numbers of Spi.h and Spi_Cfg.h are different"
#endif
/* Check if current file and Spi_Cfg header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION_CFG) || \
     (SPI_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION_CFG) || \
     (SPI_SW_PATCH_VERSION != SPI_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Spi.h and Spi_Cfg.h are different"
#endif

/* Check if this header file and Spi_Ipw_Types.h are of the same vendor */
#if (SPI_VENDOR_ID != SPI_IPW_TYPES_VENDOR_ID)
    #error "Spi.h and Spi_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Spi_Ipw_Types header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION != SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION != SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION != SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi.h and Spi_Ipw_Types.h are different"
#endif
  /* Check if current file and Spi_Ipw_Types header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION != SPI_IPW_TYPES_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION != SPI_IPW_TYPES_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION != SPI_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi.h and Spi_Ipw_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((SPI_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi.h and StandardTypes.h are different"
    #endif
    
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((SPI_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define SPI_PHYUNIT_ASYNC_U32       ((uint32)0u)

/** @brief Define state of hardware unit for synchronous transmission. */
#define SPI_PHYUNIT_SYNC_U32       ((uint32)1u)

/* Error Values */
/**
* @brief API service called with wrong parameter of Channel.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_PARAM_CHANNEL       ((uint8)0x0Au)
/**
* @brief API service called with wrong parameter of Job.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_PARAM_JOB           ((uint8)0x0Bu)
/**
* @brief API service called with wrong parameter of Sequence.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_PARAM_SEQ           ((uint8)0x0Cu)
/**
* @brief API service called with wrong parameter of external buffer length.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_PARAM_LENGTH        ((uint8)0x0Du)
/**
* @brief API service called with wrong parameter of HWUnit.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_PARAM_UNIT          ((uint8)0x0Eu)
/**
* @brief API service called with wrong resource assigned.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_PARAM_CONFIG        ((uint8)0x0Fu)
/**
* @brief API service used without module initialization.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_UNINIT              ((uint8)0x1Au)
/**
* @brief Services called in a wrong sequence.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_SEQ_PENDING         ((uint8)0x2Au)
/**
* @brief Synchronous transmission service called at wrong time.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_SEQ_IN_PROCESS      ((uint8)0x3Au)
/**
* @brief API SPI_Init service called while the SPI driver has already been initialized.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_ALREADY_INITIALIZED ((uint8)0x4Au)

/**
* @brief   The number of sequences, jobs or channels exceeds precompile time sizes.
* @details The number of sequences, jobs or channels in the configuration
*          exceeds precompile time related sizes:
*          SPI_MAX_SEQUENCE, SPI_MAX_JOB or SPI_MAX_CHANNEL.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_CONFIG_OUT_OF_RANGE ((uint8)0x5Au)

/**
* @brief API Spi_Init was called with wrong configuration pointer.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_INIT_FAILED              ((uint8)0x6Au)

/**
* @brief   When a sequence contains uninitialized external buffers.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_PARAM_EB_UNIT       ((uint8)0x5Bu)

/**
* @brief   No job in sequence.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_SEQ_EMPTY           ((uint8)0x5Cu)

/**
* @brief   No channel in job.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_JOB_EMPTY           ((uint8)0x5Du)
/**
* @brief   If the parameter versioninfo or Spi configuration is NULL_PTR.
*
*/
/** @implements Spi_ErrorCodes_define  */
#define SPI_E_PARAM_POINTER           ((uint8)0x10u)

#define SPI_CHANNEL_FLAG_TX_DEFAULT_U8 ((uint8) 0x01u)
#define SPI_CHANNEL_FLAG_RX_DISCARD_U8 ((uint8) 0x02u)

#define SPI_E_INVALID_POINTER ((uint8)0x6Fu)

#define SPI_E_HWUNIT_BUSY ((uint8)0x7Fu)


    /* Service IDs */
/**
* @brief API service ID for SPI Init function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_INIT_ID              ((uint8) 0x00u)
/**
* @brief API service ID for SPI DeInit function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_DEINIT_ID            ((uint8) 0x01u)
/**
* @brief API service ID for SPI write IB function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_WRITEIB_ID           ((uint8) 0x02u)
/**
* @brief API service ID for SPI async transmit function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_ASYNCTRANSMIT_ID     ((uint8) 0x03u)
/**
* @brief API service ID for SPI read IB function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define */
#define SPI_READIB_ID            ((uint8) 0x04u)
/**
* @brief API service ID for SPI setup EB function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_SETUPEB_ID           ((uint8) 0x05u)
/**
* @brief API service ID for SPI get status function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_GETSTATUS_ID         ((uint8) 0x06u)
/**
* @brief API service ID for SPI get job result function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_GETJOBRESULT_ID      ((uint8) 0x07u)
/**
* @brief API service ID for SPI get sequence result function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_GETSEQUENCERESULT_ID ((uint8) 0x08u)
/**
* @brief API service ID for SPI get version info function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_GETVERSIONINFO_ID    ((uint8) 0x09u)
/**
* @brief API service ID for SPI sync transmit function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_SYNCTRANSMIT_ID      ((uint8) 0x0Au)
/**
* @brief API service ID for SPI get hwunit status function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_GETHWUNITSTATUS_ID   ((uint8) 0x0Bu)
/**
* @brief API service ID for SPI cancel function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_CANCEL_ID            ((uint8) 0x0Cu)
/**
* @brief API service ID for SPI set async mode function.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_SETASYNCMODE_ID      ((uint8) 0x0Du)
/**
* @brief API service ID for SPI main function
* @details Parameters used when raising an error or exception
*
* @implements Spi_ServiceIds_define
*/
#define SPI_MAINFUNCTION_HANDLING_ID  ((uint8)0x10u)
/**
* @brief API service ID for SPI set HW Unit async mode.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define */
#define SPI_SETHWUNITASYNCMODE_ID  ((uint8)0x80u)
/**
* @brief API service ID for SPI Set Clock Mode.
* @details Parameters used when raising an error or exception.
*
*/
/** @implements Spi_ServiceIds_define  */
#define SPI_SETCLOCKMODE_ID  ((uint8)0x81u)

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief   The number of allowed job priority levels (0..3).
* @details The Priority has to be sint8.
*
*/
#define SPI_JOB_PRIORITY_LEVELS_COUNT    (4)
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/**
* @brief   This type defines a range of specific status for SPI Driver.
*
* @implements Spi_StatusType_enum
*/
typedef enum
{
    SPI_UNINIT = 0,          /**< @brief Not initialized or not usable. */
    SPI_IDLE,                /**< @brief Not currently transmitting any jobs. */
    SPI_BUSY                 /**< @brief Is performing a SPI Job(transmit). */
} Spi_StatusType;

/**
* @brief   This type defines a range of specific Jobs status for SPI Driver.
*
* @implements Spi_JobResultType_enum
*/
typedef enum
{
    SPI_JOB_OK = 0,     /**< @brief The last transmission of the Job has been finished successfully. */
    SPI_JOB_PENDING,    /**< @brief The SPI handler/Driver is performing a SPI Job. */
    SPI_JOB_FAILED,     /**< @brief The last transmission of the Job has failed. */
    SPI_JOB_QUEUED      /**< @brief An asynchronous transmit Job has been accepted, while actual
                                     transmission for this Job has not started yet. */
} Spi_JobResultType;

/**
* @brief   This type defines a range of specific Sequences status for SPI Driver.
*
* @implements Spi_SeqResultType_enum
*/
typedef enum
{
    SPI_SEQ_OK = 0,         /**< @brief The last transmission of the Sequence has been finished successfully. */
    SPI_SEQ_PENDING,        /**< @brief The SPI handler/Driver is performing a SPI Sequence. */
    SPI_SEQ_FAILED,         /**< @brief The last transmission of the Sequence has failed. */
    SPI_SEQ_CANCELLED       /**< @brief The last transmission of the Sequence has been cancelled by the user. */
} Spi_SeqResultType;

/**
* @brief   The enumeration containing the designated values for buffer types (internal or external).
*
*/
typedef enum
{
    IB = 0,     /**< @brief The Channel is configured using Internal Buffer. */
    EB          /**< @brief The Channel is configured using External Buffer. */
} Spi_BufferType;

/**
* @brief   Specifies the asynchronous mechanism mode for SPI buses handled asynchronously in Level 2
* @details #if (SPI_LEVEL2 == SPI_LEVEL_DELIVERED)
*            Specifies the asynchronous mechanism mode for SPI buses handled
*            asynchronously in LEVEL 2. SPI150: This type is available or not
*           according to the pre compile time parameter:
*            SPI_LEVEL_DELIVERED. This is only relevant for LEVEL 2.
*
* @implements Spi_AsyncModeType_enum
*/
typedef enum
{
    /** @brief The asynchronous mechanism is ensured by polling, so interrupts
       related to SPI buses handled asynchronously are disabled. */
    SPI_POLLING_MODE = 0,
    /** @brief The asynchronous mechanism is ensured by interrupt, so interrupts
       related to SPI buses handled asynchronously are enabled. */
    SPI_INTERRUPT_MODE
} Spi_AsyncModeType;

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   Specifies the Clock Modes.
*
* @implements Spi_DualClockMode_enum
*/
typedef enum
{
    SPI_NORMAL = 0,        /**< @brief Clock reference is from SpiClockRef. */
    SPI_ALTERNATE          /**< @brief Clock reference is from SpiAlternateClockRef. */
}Spi_DualClockModeType;
#endif

#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
/**
* @brief   Half duplex mode.
*/
typedef enum
{
    SPI_HALF_DUPLEX_TRANSMIT = 0,        /**< Transmit only. */
    SPI_HALF_DUPLEX_RECEIVE = 1,          /**< Receive only. */
    SPI_FULL_DUPLEX = 2                       /**< Full duplex mode. */
}Spi_HalfDuplexModeType;
 #endif
#endif
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*---------------------------------------------------------------------------
*                 SPI Driver AUTOSAR Related Type Definitions
-----------------------------------------------------------------------------*/
/**
* @brief   Type of application data buffer elements.
*/
/**
* @implements Spi_DataBufferType_typedef
*/
typedef uint8 Spi_DataBufferType;

/**
* @brief   Type for defining the number of data elements of the type Spi_DataBufferType.
* @details Type for defining the number of data elements of the type Spi_DataBufferType
*          to send or receive by Channel.
*
* @implements Spi_NumberOfDataType_typedef
*/
typedef uint16 Spi_NumberOfDataType;

#if (SPI_ALLOW_BIGSIZE_COLLECTIONS == STD_ON)

/**
* @brief   Specifies the identification (ID) for a Channel.
*
* @implements Spi_ChannelType_typedef
*/
typedef uint32 Spi_ChannelType;

/**
* @brief   Specifies the identification (ID) for a Job.
*
* @implements Spi_JobType_typedef
*/
typedef uint32 Spi_JobType;

/**
* @brief   Specifies the identification (ID) for a sequence of jobs.
*
* @implements Spi_SequenceType_typedef
*/
typedef uint32 Spi_SequenceType;
#else

/**
* @brief   Specifies the identification (ID) for a Channel.
*
* @implements Spi_ChannelType_typedef
*/
typedef uint8 Spi_ChannelType;

/**
* @brief   Specifies the identification (ID) for a Job.
*
* @implements Spi_JobType_typedef.
*/
typedef uint16 Spi_JobType;

/**
* @brief   Specifies the identification (ID) for a sequence of jobs.
*
* @implements Spi_SequenceType_typedef.
*/
typedef uint8 Spi_SequenceType;
#endif

/**
* @brief     Specifies the ID for a SPI Hardware microcontroller peripheral unit.
* @details  This type is used for specifying the identification (ID) for a SPI
*            Hardware microcontroller peripheral unit.
*
* @implements Spi_HWUnitType_typedef
*/
typedef uint8 Spi_HWUnitType;

/**
* @brief     Contains the ID of an external device.
* @details  This contains the identification (ID) of the external device for which
*            there's a collection of particular settings
*
*/
typedef uint8 Spi_ExternalDeviceType;

typedef void (Spi_NotifyType) (void);

/**
* @brief   This structure contains all the needed data to configure one SPI Sequence.
*
* @implements Spi_SequenceConfigType_struct
*/
typedef struct
{
    /** @brief Number of jobs in the sequence. */
    Spi_JobType NumJobs;
    /** @brief CoreID used */
    uint32 SpiCoreUse;
    /** @brief Job index list. */
    const Spi_JobType *JobIndexList;
    /** @brief Job notification handler. */
    Spi_NotifyType (*EndNotification);
    /** @brief Boolean indicating if the Sequence is interruptible or not. */
    uint8 Interruptible;
    #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
    /** @brief Boolean indicating if the Sequence is transferred in Dma fast mode or not. */
    boolean EnableDmaFastTransfer;
    #endif
    #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON))
    /** @brief Boolean indicating if the Sequence is used for DMA Rx buffer adjacent feature support. */
    boolean EnableDmaContMemTransfer;
    Spi_DmaContMemState* DmaContTransferState;
    #endif
} Spi_SequenceConfigType;

/**
* @brief   This structure contains Sequence configuration.
*/
typedef struct
{
    /** @brief Point to Sequence configuration. */
    const Spi_SequenceConfigType *SeqConfig;
} Spi_SeqsConfigType;

/**
* @brief   Internal structure used to manage the sequence state.
*/
typedef struct
{
    /** @brief Sequence Result. */
    Spi_SeqResultType Result;             
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
    /** @brief Pointer to the configuration. */
    const Spi_SequenceConfigType *Sequence;
    /** @brief Position in JobIndexList to the job in transmission of an async sequence. */
    const Spi_JobType *CurrentJobIndexPointer;
    /** @brief Number of jobs in a pending async sequence, not yet transmitted. */
    Spi_JobType RemainingJobs;
#endif
} Spi_SequenceStateType;

/**
* @brief   Internal structure used to manage the job state.
*
*/
typedef struct
{
    /** @brief Job Result. */
    Spi_JobResultType Result;      

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
    /** @brief Pointer to the state information of the async sequence. */
    Spi_SequenceStateType *AsyncCrtSequenceState;
    /** @brief Pointer to the next async job planned for transmission. */
    Spi_JobType AsyncNextJob;
#endif
} Spi_JobStateType;

/**
* @brief   This is the structure containing all the parameters needed to completely define a Job.
*
* @implements Spi_JobConfigType_struct
*/
typedef struct
{
    /** @brief Number of channels in the job. */
    Spi_ChannelType NumChannels;
    /** @brief Channel index list. */
    const Spi_ChannelType *ChannelIndexList;
    /** @brief Job end notification. */
    Spi_NotifyType (*EndNotification);
    /** @brief Job start notification. */
    Spi_NotifyType (*StartNotification);
    /** @brief Priority. */
    sint8 Priority;
    /** @brief CoreID used */
    uint32 SpiCoreUse;
    /** @brief Implementation specific field referencing the channel internal state. */
    Spi_JobStateType *JobState;
    /** @brief HWUnit. */
    Spi_HWUnitType HWUnit;
    /** @brief ExternalDevice. */
    Spi_ExternalDeviceType ExternalDevice;
    /** @brief Implementation specific field: cached LLD device attributes. */
    const Spi_ExDevicesConfigType *ExternalDeviceConfig;
} Spi_JobConfigType;

/**
* @brief   This is the structure containing Job configuration.
*/
typedef struct
{
    /** @brief Point to Job configuration. */
    const Spi_JobConfigType *JobCfg;
} Spi_JobsCfgType;

/**
* @brief   The structure contains the pointers to the Tx/Rx memory locations for the given buffer (IB or EB).
*
*/
typedef struct
{
    /** @brief Transmit buffer pointer. */
    const Spi_DataBufferType *ExternalBufferTX;
    Spi_DataBufferType *InternalBufferTX;
    /** @brief Receive buffer pointer. */
    Spi_DataBufferType *BufferRX;
} Spi_BufferDescriptorType;

/**
* @brief   Internal structure used to manage the channel state.
*
*/
typedef struct
{
    uint8 Flags;                 /**< @brief Default Transmit Enabled. */
    Spi_NumberOfDataType Length; /**< @brief Actual Transfer size for EB. */
} Spi_ChannelStateType;

/**
* @brief   This structure holds the HWUnit scheduling queue.
* @details For async transmissions, this structure holds the HWUnit scheduling queue .
*          For sync transmissions, only HWUnit Status is managed.
*
*/
typedef struct
{
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
    /** @brief Array of the IDs of jobs to be scheduled, for each priority level. */
    Spi_JobType ScheduledJobsListHead[SPI_JOB_PRIORITY_LEVELS_COUNT];
    /** @brief Array of the IDs of last jobs in queues, for each priority level. */
    Spi_JobType ScheduledJobsListTail[SPI_JOB_PRIORITY_LEVELS_COUNT];
    /** @brief Array of the IDs of last jobs in queues, for each priority level. */
    sint8 MaxScheduledPriority;
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */
    Spi_StatusType Status;    /**< @brief DSPI state. */
    Spi_ChannelType Channel; /**< Current channel index in Job */
    Spi_JobType Job; /**< Current job index */
} Spi_HWUnitQueue;

/**
* @brief   The structure contains the channel configuration parameters.
*/
typedef struct
{
    /** @brief Buffer Type IB/EB. */
    Spi_BufferType BufferType;
    /** @brief Data frame size. */
    uint8 FrameSize;
    /** @brief Bite order (MSB/LSB). */
    boolean Lsb;
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
    /** @brief Half duplex mode. */
    Spi_HalfDuplexModeType HalfDuplexMode;
  #endif
#endif
    /** @brief Default Transmit Value. */
    uint32 DefaultTransmitValue;
    /** @brief Data length. */
    Spi_NumberOfDataType Length;
    /** @brief Buffer Descriptor. */
    Spi_BufferDescriptorType *BufferDescriptor;
    /** @brief CoreID assigned */
    uint32 SpiCoreUse;
    /** @brief Implementation specific field referencing the channel internal state. */
    Spi_ChannelStateType *ChannelState;
} Spi_ChannelConfigType;

/**
* @brief   The structure contains the channel configuration.
*/
typedef struct
{
    /** @brief Point to Channel configuration. */
    const Spi_ChannelConfigType *ChannelCfg;
} Spi_ChannelsCfgType;

/*---------------------------------------------------------------------------
*             SPI Driver Low Level Implementation Specific Type Definitions
-----------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
*             SPI Driver Configuration Main Structure
-----------------------------------------------------------------------------*/
/**
* @brief   This is the top level structure containing all the 
*          needed parameters for the SPI Handler Driver.
*
* @implements Spi_ConfigType_struct
*/
typedef struct
{
    /** @brief Number of external devices defined in the configuration. */
    uint16 MaxExternalDevice;
    /** @brief Number of channels defined in the configuration. */
    Spi_ChannelType SpiMaxChannel;
    /** @brief Number of jobs defined in the configuration. */
    Spi_JobType SpiMaxJob;
    /** @brief Number of sequences defined in the configuration. */
    Spi_SequenceType SpiMaxSequence;
    /** @brief CoreID used */
    uint32 SpiCoreUse;
    /** @brief Pointer to Array of channels defined in the configuration. */
    const Spi_ChannelsCfgType *ChannelConfig;
    /** @brief Pointer to Array of jobs defined in the configuration. */
    const Spi_JobsCfgType *JobConfig;
    /** @brief Pointer to Array of sequences defined in the configuration. */
    const Spi_SeqsConfigType *SequenceConfig;
    /** @brief External device unit attributes. */
    const Spi_ExDevicesConfigType *ExternalDeviceConfig;
    /** @brief Pointer to Array of LLD DSPI device instances. */
    const Spi_PhyUnitsConfigType *HWUnitConfig;
    /** @brief SPI Driver DEM Error: SPI_E_HARDWARE_ERROR. */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    const Mcal_DemErrorType SpiErrorHardwareCfg;
#endif
} Spi_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/**
* @brief   Export Post-Build configurations.
*/
SPI_CONFIG_EXT

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
#endif /* (SPI_PRECOMPILE_SUPPORT == STD_OFF) */

#define   SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
extern const Spi_ConfigType *Spi_apxSpiConfigPtr[SPI_MAX_PARTITIONS];
/**
* @brief Extern arrays contain the state of Sequences, Jobs and Channels.
*/
extern Spi_JobStateType Spi_axSpiJobState[SPI_MAX_JOB];
extern Spi_ChannelStateType Spi_axSpiChannelState[SPI_MAX_CHANNEL];
#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
* @brief   This function is called after a Job has been executed.
* @details The function calls Job and Sequence end notifications and schedules
*          the next job of the sequence or on the liberated HW Unit.
*
* @param[in]    JobConfig   The just transmited job pointer.
*
* @return void
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
#if ((SPI_LEVEL2 == SPI_LEVEL_DELIVERED) || (SPI_LEVEL1 == SPI_LEVEL_DELIVERED))
extern void Spi_JobTransferFinished
    (
        const Spi_JobConfigType *JobConfig, Spi_JobResultType JobResult
    );
#endif

#if (SPI_VERSION_INFO_API == STD_ON)
/**
* @brief   This function returns the version information for the SPI driver.
* @details This function returns the version information for the SPI driver.
*          - Service ID:       0x09
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in,out]    VersionInfo      Pointer to where to store the version
*                                    information of this module.
*
* @pre  Pre-compile parameter SPI_VERSION_INFO_API shall be STD_ON.
* @return void
*/
void Spi_GetVersionInfo
    (
        Std_VersionInfoType *versioninfo
    );
#endif

/**
* @brief   This function initializes the SPI driver.
* @details This function initializes the SPI driver using the
*          pre-established configurations
*          - Service ID:       0x00
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in]     ConfigPtr      Specifies the pointer to the configuration set
* @return   void
*/
void Spi_Init
    (
        const Spi_ConfigType *ConfigPtr
    );

/**
* @brief   This function de-initializes the SPI driver.
* @details This function de-initializes the SPI driver using the
*          pre-established configurations
*          - Service ID:       0x01
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @return Std_ReturnType
* @retval E_OK       de-initialisation command has been accepted
* @retval E_NOT_OK   de-initialisation command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_DeInit()
*       otherwise, the function Spi_DeInit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
*/
Std_ReturnType Spi_DeInit(void);

#if ((SPI_USAGE0 == SPI_CHANNEL_BUFFERS_ALLOWED) || (SPI_USAGE2 == SPI_CHANNEL_BUFFERS_ALLOWED ))
/**
* @brief   This function writes the given data into the buffer of a specific channel.
* @details This function writes the given data into the buffer of a specific channel.
*          - Service ID:       0x02
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Channel             Channel ID
* @param[in]      DataBufferPtr       Pointer to source data buffer
*
* @return Std_ReturnType
* @retval E_OK       Command has been accepted
* @retval E_NOT_OK   Command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_WriteIB()
*       otherwise, the function Spi_WriteIB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be SPI_USAGE0 or SPI_USAGE2.
*
*/
Std_ReturnType Spi_WriteIB
    (
        Spi_ChannelType Channel,
        const Spi_DataBufferType *DataBufferPtr
    );

/**
* @brief   This function reads the data from the buffer of a channel and puts at the memory location.
* @details This function reads the data from the buffer of a specific channel
*          and puts at the specified memory location.
*          - Service ID:       0x04
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
*
* @param[in]      Channel             Channel ID
* @param[in,out]  DataBufferPointer       Pointer to the memory location that will
*                                     be written with the data in the internal
*                                     buffer
*
* @return Std_ReturnType
* @retval E_OK      read command has been accepted
* @retval E_NOT_OK  read command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_ReadIB()
*       otherwise, the function Spi_ReadIB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be SPI_USAGE0 or SPI_USAGE2.
*
* @implements Spi_ReadIB_Activity
*/
Std_ReturnType Spi_ReadIB
    (
        Spi_ChannelType Channel,
        Spi_DataBufferType *DataBufferPointer
    );
#endif

#if ((SPI_LEVEL2 == SPI_LEVEL_DELIVERED) || (SPI_LEVEL1 == SPI_LEVEL_DELIVERED))
/**
* @brief   This function triggers the asynchronous transmission for the given sequence.
* @details This function triggers the asynchronous transmission for the given sequence.
*          - Service ID:       0x03
*          - Sync or Async:       Asynchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Std_ReturnType
* @retval E_OK       Transmission command has been accepted
* @retval E_NOT_OK   Transmission command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_AsyncTransmit()
*       otherwise, the function Spi_AsyncTransmit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*/
Std_ReturnType Spi_AsyncTransmit
    (
        Spi_SequenceType Sequence
    );
#endif

#if ( ( SPI_USAGE1 == SPI_CHANNEL_BUFFERS_ALLOWED) || \
        ( SPI_USAGE2 == SPI_CHANNEL_BUFFERS_ALLOWED)  )
/**
* @brief   This function setup an external buffer to be used by a specific channel.
* @details This function setup an external buffer to be used by a specific channel.
*          - Service ID:       0x05
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Channel             Channel ID
* @param[in]      SrcDataBufferPtr    Pointer to the memory location that will hold
*                                     the transmitted data
* @param[in]      Length              Length of the data in the external buffer
* @param[out]     DesDataBufferPtr    Pointer to the memory location that will hold
*                                     the received data
*
* @return Std_ReturnType
* @retval E_OK      Setup command has been accepted
* @retval E_NOT_OK  Setup command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_SetupEB()
*       otherwise, the function Spi_SetupEB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be SPI_USAGE1 or SPI_USAGE2.
*
*/
Std_ReturnType Spi_SetupEB
    (
        Spi_ChannelType Channel,
        const Spi_DataBufferType *SrcDataBufferPtr,
        Spi_DataBufferType *DesDataBufferPtr,
        Spi_NumberOfDataType Length
    );
#endif

/**
* @brief   This function returns the status of the SPI driver.
* @details This function returns the status of the SPI driver.
*          - Service ID:       0x06
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The driver is un-initialized
* @retval SPI_IDLE    The driver has no pending transfers
* @retval SPI_BUSY    The driver is busy
*
* @pre  The driver needs to be initialized before calling Spi_GetStatus()
*       otherwise, the function Spi_GetStatus() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*/
Spi_StatusType Spi_GetStatus(void);

/**
* @brief   This function is used to request the status of a specific job.
* @details This function is used to request the status of a specific job.
*          - Service ID:       0x07
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Job                 Job ID
*
* @return Spi_JobResultType
* @retval SPI_JOB_OK        The job ended successfully
* @retval SPI_JOB_PENDING   The job is pending
* @retval SPI_JOB_FAILED    The job has failed
*
* @pre  The driver needs to be initialized before calling Spi_GetJobResult()
*       otherwise, the function Spi_GetJobResult() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
* @implements Spi_GetJobResult_Activity
*/
Spi_JobResultType Spi_GetJobResult
    (
        Spi_JobType Job
    );

/**
* @brief   This function is used to request the status of a specific sequence.
* @details This function is used to request the status of a specific sequence.
*          - Service ID:       0x08
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Spi_SeqResultType
* @retval SPI_SEQ_OK       The sequence ended successfully
* @retval SPI_SEQ_PENDING  The sequence is pending
* @retval SPI_SEQ_FAILED   The sequence has failed
*
* @pre  The driver needs to be initialized before calling Spi_GetSequenceResult()
*       otherwise, the function Spi_GetSequenceResult() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
*/
Spi_SeqResultType Spi_GetSequenceResult
    (
        Spi_SequenceType Sequence
    );

#if ((SPI_LEVEL2 == SPI_LEVEL_DELIVERED) || (SPI_LEVEL0 == SPI_LEVEL_DELIVERED))
/**
* @brief   This function is used for synchronous transmission of a given sequence.
* @details This function is used for synchronous transmission of a given sequence.
*          - Service ID:       0x0a
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Std_ReturnType
* @retval E_OK      Transmission command has been completed successfully
* @retval E_NOT_OK  Transmission command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_SyncTransmit().
*       otherwise, the function Spi_SyncTransmit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL0 or SPI_LEVEL2
*/
Std_ReturnType Spi_SyncTransmit
    (
        Spi_SequenceType Sequence
    );
#endif

#if (SPI_HW_STATUS_API == STD_ON)
/**
* @brief   This function is used to request the status of a specific SPI peripheral unit.
* @details This function is used to request the status of a specific SPI peripheral unit.
*          - Service ID:       0x0b
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      HWUnit              The HW peripheral for which we need the status
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The peripheral is un-initialized
* @retval SPI_IDLE    The peripheral is in idle state
* @retval SPI_BUSY    The peripheral is busy
*
* @pre  The driver needs to be initialized before calling Spi_GetHWUnitStatus()
*       otherwise, the function Spi_GetHWUnitStatus() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  SPI_HW_STATUS_API == STD_ON
*/
Spi_StatusType Spi_GetHWUnitStatus
    (
        Spi_HWUnitType HWUnit
    );
#endif

#if (SPI_CANCEL_API == STD_ON)
/**
* @brief   This function is used to request the cancelation of the given sequence.
* @details This function is used to request the cancelation of the given sequence.
*          - Service ID:       0x0c
*          - Sync or Async:       Asynchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @pre  The driver needs to be initialized before calling Spi_Cancel()
*       otherwise, the function Spi_Cancel() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CANCEL_API shall be STD_ON
* @post  The SPI Handler Driver is not responsible on external devices damages or
*       undefined state due to cancelling a sequence transmission.
*/
void Spi_Cancel
    (
        Spi_SequenceType Sequence
    );
#endif

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL2)
/**
* @brief   This function specifies the asynchronous mode for the SPI busses handled asynchronously.
* @details This function specifies the asynchronous mode for the SPI busses
*          handled asynchronously.
*          - Service ID:       0x0d
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in]      Mode         This parameter specifies the asynchronous
*                              operating mode (SPI_POLLING_MODE or
*                              SPI_INTERRUPT_MODE)
*
* @return Std_ReturnType
* @retval E_OK      The command ended successfully
* @retval E_NOT_OK  The command has failed
*
* @pre  The driver needs to be initialized before calling Spi_SetAsyncMode()
*       otherwise, the function Spi_SetAsyncMode() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL2
*/
Std_ReturnType Spi_SetAsyncMode
    (
        Spi_AsyncModeType Mode
    );
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON))
/**
* @brief   This function specifies the asynchronous mode for a given HWUnit.
* @details This function specifies the asynchronous mode for the SPI busses
*          handled asynchronously.
*          For synchronous HW units, the function has no impact.
*          The function will fail in two cases:
*          - driver not initialised (SPI_E_UNINIT reported by DET)
*          - a sequence transmission is pending the the asynchronous HW unit
*            (SPI_E_SEQ_PENDING reported by DET)
*
* @param[in]      HWUnit       The ID of the HWUnit to be configured
* @param[in]      AsyncMode    This parameter specifies the asynchronous
*                              operating mode (SPI_POLLING_MODE or
*                              SPI_INTERRUPT_MODE)
*
* @return Std_ReturnType
* @retval E_OK       The command ended successfully
* @retval E_NOT_OK   The command has failed
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL2 and
*       SPI_HWUNIT_ASYNC_MODE should be on STD_ON
*/
Std_ReturnType Spi_SetHWUnitAsyncMode
    (
        Spi_HWUnitType HWUnit,
        Spi_AsyncModeType AsyncMode
    );
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON) */

/**
* @brief   This function shall asynchronously poll SPI interrupts and call ISR if appropriate.
* @details This function shall asynchronously poll SPI interrupts and call
*          ISR if appropriate.
*          - Service ID:       0x10
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
void Spi_MainFunction_Handling(void);

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
Std_ReturnType Spi_SetClockMode
    (
        Spi_DualClockModeType ClockMode
    );
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SPI_H */

/** @} */

