/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXCAN_IP_TYPES_H_
#define FLEXCAN_IP_TYPES_H_

/**
* @file FlexCAN_Ip_Types.h
*
* @brief FlexCAN Ip Types Header File
* @details This Files Contains the FlexCAN Ip data types used external by FlexCAN Ip Driver
*
* @addtogroup FlexCAN
* @{
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
#include "FlexCAN_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_TYPES_VENDOR_ID_H                      43
#define FLEXCAN_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_IP_TYPES_AR_RELEASE_MINOR_VERSION_H       7
#define FLEXCAN_IP_TYPES_AR_RELEASE_REVISION_VERSION_H    0
#define FLEXCAN_IP_TYPES_SW_MAJOR_VERSION_H               2
#define FLEXCAN_IP_TYPES_SW_MINOR_VERSION_H               0
#define FLEXCAN_IP_TYPES_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip_Cfg header file are of the same vendor */
#if (FLEXCAN_IP_TYPES_VENDOR_ID_H != FLEXCAN_IP_CFG_VENDOR_ID_H)
    #error "FlexCAN_Ip_Types.h and FlexCAN_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_Cfg header file are of the same Autosar version */
#if ((FLEXCAN_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_TYPES_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_TYPES_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_CFG_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of FlexCAN_Ip_Types.h and FlexCAN_Ip_Cfg.h are different"
#endif
/* Check if current file and FlexCAN_Ip_Cfg header file are of the same Software version */
#if ((FLEXCAN_IP_TYPES_SW_MAJOR_VERSION_H != FLEXCAN_IP_CFG_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_TYPES_SW_MINOR_VERSION_H != FLEXCAN_IP_CFG_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_TYPES_SW_PATCH_VERSION_H != FLEXCAN_IP_CFG_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Ip_Types.h and FlexCAN_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**@brief Remote Request Store enable */
#define FLEXCAN_IP_REM_STORE_U32                   ((uint32)0x00000001U)
/**@brief Three samples to determine the value of received bit */
#define FLEXCAN_IP_THREE_SAMPLES_U32               ((uint32)0x00000002U)
/**@brief Define how controller recover from bus off state */
#define FLEXCAN_IP_BUSOFF_RECOVERY_U32             ((uint32)0x00000004U)
/**@brief Protocol Exception */
#define FLEXCAN_IP_PROTOCOL_EXCEPTION_U32          ((uint32)0x00000008U)
/**@brief Edge Filter */
#define FLEXCAN_IP_EDGE_FILTER_U32                 ((uint32)0x00000010U)
/**@brief CAN FD protocol according to ISO specification (ISO 11898-1) */
#define FLEXCAN_IP_ISO_U32                      ((uint32)0x00000020U)
/**@brief Entire Frame Arbitration Field Comparison */
#define FLEXCAN_IP_EACEN_U32                       ((uint32)0x00000040U)
/*==================================================================================================
*                                             ENUMS
====================================================================================================*/

/*! @brief The type of the RxFIFO transfer (interrupts/DMA).
 */
/* implements Flexcan_Ip_RxFifoTransferType_enum */
typedef enum
{
    FLEXCAN_RXFIFO_USING_INTERRUPTS,    /**< Use interrupts for RxFIFO. */
    FLEXCAN_RXFIFO_USING_POLLING,       /**< Use polling method for RxFIFO */
#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
    FLEXCAN_RXFIFO_USING_DMA            /**< Use DMA for RxFIFO. */
#endif
} Flexcan_Ip_RxFifoTransferType;

/*! @brief FlexCAN Rx FIFO filters number
 */
/* implements  Flexcan_Ip_RxFifoIdFilterNumType_enum */
typedef enum
{
    FLEXCAN_RX_FIFO_ID_FILTERS_8   = 0x0,         /**<  8 Rx FIFO Filters. @internal gui name="8 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_16  = 0x1,         /**<  16 Rx FIFO Filters. @internal gui name="16 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_24  = 0x2,         /**<  24 Rx FIFO Filters. @internal gui name="24 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_32  = 0x3,         /**<  32 Rx FIFO Filters. @internal gui name="32 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_40  = 0x4,         /**<  40 Rx FIFO Filters. @internal gui name="40 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_48  = 0x5,         /**<  48 Rx FIFO Filters. @internal gui name="48 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_56  = 0x6,         /**<  56 Rx FIFO Filters. @internal gui name="56 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_64  = 0x7,         /**<  64 Rx FIFO Filters. @internal gui name="64 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_72  = 0x8,         /**<  72 Rx FIFO Filters. @internal gui name="72 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_80  = 0x9,         /**<  80 Rx FIFO Filters. @internal gui name="80 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_88  = 0xA,         /**<  88 Rx FIFO Filters. @internal gui name="88 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_96  = 0xB,         /**<  96 Rx FIFO Filters. @internal gui name="96 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_104 = 0xC,         /**< 104 Rx FIFO Filters. @internal gui name="104 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_112 = 0xD,         /**< 112 Rx FIFO Filters. @internal gui name="112 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_120 = 0xE,         /**< 120 Rx FIFO Filters. @internal gui name="120 Rx FIFO Filters" */
    FLEXCAN_RX_FIFO_ID_FILTERS_128 = 0xF          /**< 128 Rx FIFO Filters. @internal gui name="128 Rx FIFO Filters" */
} Flexcan_Ip_RxFifoIdFilterNumType;

/*! @brief FlexCAN Rx mask type.
 */
/* implements  Flexcan_Ip_RxMaskType_enum */
typedef enum
{
    FLEXCAN_RX_MASK_GLOBAL,      /**< Rx global mask */
    FLEXCAN_RX_MASK_INDIVIDUAL   /**< Rx individual mask */
} Flexcan_Ip_RxMaskType;


/*! @brief FlexCAN payload sizes
 */
/* implements Flexcan_Ip_FdPayloadSizeType_enum */
typedef enum
{
    FLEXCAN_PAYLOAD_SIZE_8 = 0,  /**< FlexCAN message buffer payload size in bytes*/
    FLEXCAN_PAYLOAD_SIZE_16 ,    /**< FlexCAN message buffer payload size in bytes*/
    FLEXCAN_PAYLOAD_SIZE_32 ,    /**< FlexCAN message buffer payload size in bytes*/
    FLEXCAN_PAYLOAD_SIZE_64      /**< FlexCAN message buffer payload size in bytes*/
} Flexcan_Ip_FdPayloadSizeType;


/*! @brief FlexCAN operation modes
 */
/*  implements  Flexcan_Ip_ModesType_enum */
typedef enum
{
    FLEXCAN_NORMAL_MODE,        /**< Normal mode or user mode @internal gui name="Normal" */
    FLEXCAN_LISTEN_ONLY_MODE,   /**< Listen-only mode @internal gui name="Listen-only" */
    FLEXCAN_LOOPBACK_MODE       /**< Loop-back mode @internal gui name="Loop back" */
} Flexcan_Ip_ModesType;


#if (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)

typedef enum
{
    FLEXCAN_CAN_CLK_TIMESTAMP_SRC,           /**< Captured time base is CAN bit clock. */
    FLEXCAN_ONCHIP_CLK_TIMESTAMP_SRC         /**< Captured time base is on-chip timer clock. */
} Flexcan_Ip_TimeStampClockConfigType;

/*! @brief FlexCAN Free Running Counter Time Stamp config. */
/* implements  Flexcan_Ip_TimeStampConfigType_structure */
typedef struct
{
    Flexcan_Ip_TimeStampClockConfigType timeStampSurce;     /**< Timestamp Timer Source selection */
} Flexcan_Ip_TimeStampConfigType;
#endif /* if FLEXCAN_IP_FEATURE_HAS_TS_ENABLE */

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/*! @brief FlexCAN Enhanced Rx FIFO filter type */
/* implements  Flexcan_Ip_EnhancedFilterType_structure */
typedef enum
{
    FLEXCAN_IP_ENHANCED_RX_FIFO_ONE_ID_FILTER = 0U,         /*!< Filter element with filter + mask scheme*/
    FLEXCAN_IP_ENHANCED_RX_FIFO_RANGE_ID_FILTER,       /*!< Filter element with range scheme*/
    FLEXCAN_IP_ENHANCED_RX_FIFO_TWO_ID_FILTER          /*!< Filter element with 2-filter scheme*/
} Flexcan_Ip_EnhancedFilterType;

/*! @brief FlexCAN Enhanced Rx FIFO ID filter table structure */
/* implements  Flexcan_Ip_EnhancedIdTableType_structure */
typedef struct
{
    Flexcan_Ip_EnhancedFilterType filterType;       /*!< Enhanced Rx FIFO filter type*/
    boolean isExtendedFrame;                           /*!< Extended frame*/
    boolean rtr2;                                      /*!< Enhanced Rx FIFO RTR2 */
    boolean rtr1;                                      /*!< Enhanced Rx FIFO RTR1 */
    uint32 id2;                                     /*!< Enhanced Rx FIFO ID2 filter element*/
    uint32 id1;                                     /*!< Enhanced Rx FIFO ID1 filter element*/
} Flexcan_Ip_EnhancedIdTableType;
#endif /* FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO */

/*! @brief The state of a given MB (idle/Rx busy/Tx busy). */
/* implements  Flexcan_Ip_MbStateType_enum */
typedef enum
{
    FLEXCAN_MB_IDLE,      /**< The MB is not used by any transfer. */
    FLEXCAN_MB_RX_BUSY,   /**< The MB is used for a reception. */
    FLEXCAN_MB_TX_BUSY,   /**< The MB is used for a transmission. */
#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
    FLEXCAN_MB_DMA_ERROR /**< The MB is used as DMA source and fail to transfer */
#endif
} Flexcan_Ip_MbStateType;

/*! @brief The type of the event which occurred when the callback was invoked.
 */
/* implements Flexcan_Ip_EventType_enum */
typedef enum
{
    FLEXCAN_EVENT_RX_COMPLETE = 0U,     /**< A frame was received in the configured Rx MB. */
    FLEXCAN_EVENT_RXFIFO_COMPLETE, /**< A frame was received in the Rx FIFO. */
    FLEXCAN_EVENT_RXFIFO_WARNING,  /**< Rx FIFO is almost full (5 frames). */
    FLEXCAN_EVENT_RXFIFO_OVERFLOW, /**< Rx FIFO is full (incoming message was lost). */
    FLEXCAN_EVENT_TX_COMPLETE,     /**< A frame was sent from the configured Tx MB. */
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    FLEXCAN_EVENT_ENHANCED_RXFIFO_COMPLETE,     /**< A frame was received in the Enhanced Rx FIFO. */
    FLEXCAN_EVENT_ENHANCED_RXFIFO_WATERMARK,    /**< The number of messages available is greater */
                                                /**< than the watermark defined. */
    FLEXCAN_EVENT_ENHANCED_RXFIFO_OVERFLOW,     /**< Enhanced Rx FIFO is full (incoming message was lost). */
    FLEXCAN_EVENT_ENHANCED_RXFIFO_UNDERFLOW,    /**< An underflow condition occurred in the enhanced Rx FIFO. */
#endif /* FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO */
#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
    FLEXCAN_EVENT_WAKEUP_TIMEOUT,  /**< An wake up event occurred due to timeout. */
    FLEXCAN_EVENT_WAKEUP_MATCH,    /**< An wake up event occurred due to matching. */
#endif /* (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON) */
#if FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE
    FLEXCAN_EVENT_DMA_COMPLETE = 11U,   /**< A complete transfer occurred on DMA */
    FLEXCAN_EVENT_DMA_ERROR = 12U,      /**< A DMA transfer fail, because of a DMA channel error */
#endif /* FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE */
    FLEXCAN_EVENT_ERROR,         /**<  Errors detected in CAN frames of any format (interrupt mode only) */
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
    FLEXCAN_EVENT_ERROR_FAST,   /**< Errors detected in the data phase of CAN FD frames with the BRS bit set only (interrupt mode only) */
#endif /* FLEXCAN_IP_FEATURE_HAS_FD */
    FLEXCAN_EVENT_BUSOFF,       /**< FlexCAN module entered Bus Off state */
    FLEXCAN_EVENT_RX_WARNING,     /*!< The Rx error counter transitioned from less than 96 to greater than or equal to 96 (interrupt mode only) */
    FLEXCAN_EVENT_TX_WARNING     /*!< The Tx error counter transitioned from less than 96 to greater than or equal to 96 (interrupt mode only) */
} Flexcan_Ip_EventType;

/** @brief FlexCAN error interrupt types
 */
/* implements  Flexcan_Ip_ErrorIntType_enum */
typedef enum
{
    FLEXCAN_IP_INT_RX_WARNING,     /*!< RX warning interrupt*/
    FLEXCAN_IP_INT_TX_WARNING,     /*!< TX warning interrupt*/
    FLEXCAN_IP_INT_ERR,            /*!< Error interrupt*/
    FLEXCAN_IP_INT_ERR_FAST,       /*!< Error Fast interrupt*/
    FLEXCAN_IP_INT_BUSOFF          /*!< Bus off interrupt*/
} Flexcan_Ip_ErrorIntType;

/** @brief FlexCAN Message Buffer ID type
 *  @details FlexCAN Id Type, Standard or Extended
 */
/* implements Flexcan_Ip_MsgBuffIdType_enum */
typedef enum
{
    FLEXCAN_MSG_ID_STD = 0,     /**< Standard ID*/
    FLEXCAN_MSG_ID_EXT          /**< Extended ID*/
} Flexcan_Ip_MsgBuffIdType;

/** @brief ID formats for Rx FIFO
 *  @details Legacy RxFIFO Id Format Types
 */
/*  implements Flexcan_Ip_RxFifoIdElementFormatType_enum */
typedef enum
{
    FLEXCAN_RX_FIFO_ID_FORMAT_A, /**< One full ID (standard and extended) per ID Filter Table element.*/
    FLEXCAN_RX_FIFO_ID_FORMAT_B, /**< Two full standard IDs or two partial 14-bit (standard and
                                      extended) IDs per ID Filter Table element.*/
    FLEXCAN_RX_FIFO_ID_FORMAT_C, /**< Four partial 8-bit Standard IDs per ID Filter Table element.*/
    FLEXCAN_RX_FIFO_ID_FORMAT_D  /**< All frames rejected.*/
} Flexcan_Ip_RxFifoIdElementFormatType;

/** @brief The status used and reported by FlexCAN Ip driver.
 *  @details The FlexCAN specific error codes
 */
/* implements  Flexcan_Ip_StatusType_enum */
typedef enum
{
    FLEXCAN_STATUS_SUCCESS  = E_OK,          /**< Successfull Operation Completed */
    FLEXCAN_STATUS_ERROR = E_NOT_OK,         /**< Error Operation Completed */
    FLEXCAN_STATUS_BUSY,                     /**< Busy Operation Completed */
    FLEXCAN_STATUS_TIMEOUT,                  /**< TimeOut Operation Completed */
    FLEXCAN_STATUS_BUFF_OUT_OF_RANGE,        /**< The specified MB index is out of the configurable range */
    FLEXCAN_STATUS_NO_TRANSFER_IN_PROGRESS,  /**< There is no transmission or reception in progress */
} Flexcan_Ip_StatusType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (CPU_TYPE == CPU_TYPE_64)
    typedef uint64 Flexcan_Ip_PtrSizeType;
#elif (CPU_TYPE == CPU_TYPE_32)
    typedef uint32 Flexcan_Ip_PtrSizeType;
#else
    #error "Unsupported CPU_TYPE"
#endif

/*! @brief FlexCAN bitrate related structures
 */
/* implements  Flexcan_Ip_TimeSegmentType_structure */
typedef struct
{
    uint32 propSeg;         /**< Propagation segment*/
    uint32 phaseSeg1;       /**< Phase segment 1*/
    uint32 phaseSeg2;       /**< Phase segment 2*/
    uint32 preDivider;      /**< Clock prescaler division factor*/
    uint32 rJumpwidth;      /**< Resync jump width*/
} Flexcan_Ip_TimeSegmentType;

/*! @brief FlexCAN Blocks payload sizes structure
 */
/*  implements  Flexcan_Ip_PayloadSizeType_structure */
typedef struct
{   /** Payload for  Ram Block 0*/
    Flexcan_Ip_FdPayloadSizeType payloadBlock0;
#if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 1)
    /** Payload for Ram Block 1 */
    Flexcan_Ip_FdPayloadSizeType payloadBlock1;
#endif
#if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 2)
    /** Payload for Ram Block 2 */
    Flexcan_Ip_FdPayloadSizeType payloadBlock2;
#endif
#if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 3)
    /** Payload for Ram Block 3 */
    Flexcan_Ip_FdPayloadSizeType payloadBlock3;
#endif
} Flexcan_Ip_PayloadSizeType;

/*! @brief FlexCAN message buffer structure
 */
/*  implements  Flexcan_Ip_MsgBuffType_structure */
typedef struct
{
    uint32 cs;                        /**< Code and Status*/
    uint32 msgId;                     /**< Message Buffer ID*/
    uint8 data[64];                   /**< Data bytes of the FlexCAN message*/
    uint8 dataLen;                    /**< Length of data in bytes */
    uint8 id_hit;                     /**< Identifier Acceptance Filter Hit Indicator*/
    uint32 time_stamp;                /**< Free-Running Counter Time Stamp*/
} Flexcan_Ip_MsgBuffType;

/*! @brief Information needed for internal handling of a given MB. */
/* implements  Flexcan_Ip_MBhandleType_structure */
typedef struct
{
    Flexcan_Ip_MsgBuffType * pMBmessage;    /**< The FlexCAN MB structure */
    volatile Flexcan_Ip_MbStateType state;  /**< The state of the current MB (idle/Rx busy/Tx busy) */
#if FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE
    volatile boolean isDmaBusy;             /**< The state of the current DMA (idle/busy) */
#endif /* FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE */
    boolean isPolling;                      /**< True if the transfer is Polling Mode  */
    boolean isRemote;                       /**< True if the frame is a remote frame */
    uint32  time_stamp;                     /**< TimeStamp of the Message */
} Flexcan_Ip_MBhandleType;

/*!
 * @brief Internal driver state information.
 *
 * @note The contents of this structure are internal to the driver and should not be
 *      modified by users. Also, contents of the structure are subject to change in
 *      future releases.
 */
/* implements   Flexcan_Ip_StateType_structure */
typedef struct FlexCANState
{
    Flexcan_Ip_MBhandleType mbs[FLEXCAN_IP_FEATURE_MAX_MB_NUM];       /**< Array containing information
                                                                    related to each MB */
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    Flexcan_Ip_MBhandleType enhancedFifoOutput;                /**< Containing information output
                                                                    of Enhanced Rx FIFO */
#endif /* FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO */
    void (*callback)(uint8 instance,
                     Flexcan_Ip_EventType eventType,
                     uint32 buffIdx,
                     const struct FlexCANState *driverState
                    );        /**< IRQ handler callback function. */
    void *callbackParam;                                       /**< Parameter used to pass user data
                                                                    when invoking the callback
                                                                    function. */
    void (*error_callback)(uint8 instance,
                           Flexcan_Ip_EventType eventType,
                           uint32 u32ErrStatus,
                           const struct FlexCANState *driverState
                          );   /**< Error IRQ handler callback
                                                                    function. */
    void *errorCallbackParam;                                  /**< Parameter used to pass user data
                                                                    when invoking the error callback
                                                                    function. */
#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
    uint8 rxFifoDMAChannel;                                    /**< DMA channel number used for transfers. */
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    uint32 u32NumOfMbTransferByDMA;                            /**< The number of message buffers transferred by DMA(major loop count). */
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */
#endif /* (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON) */
    Flexcan_Ip_RxFifoTransferType transferType;                /**< Type of RxFIFO transfer. */
    boolean bIsLegacyFifoEn;                                   /**< This controls whether the Rx FIFO feature is enabled or not. */
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    boolean bIsEnhancedFifoEn;                                 /**< This controls whether the Rx Enhanced FIFO feature is enabled or not. */
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */
    uint32 u32MaxMbNum;                                        /**< The maximum number of Message Buffers. */
    boolean isIntActive;                                       /**< Save status of enabling/disabling interrupts in runtime. */
} Flexcan_Ip_StateType;

/*! @brief FlexCAN Driver callback function type
 */
/* implements FlexCAN_Ip_CallbackType_typdef */
typedef void (* FlexCAN_Ip_CallbackType)(uint8 instance,
                                         Flexcan_Ip_EventType eventType,
                                         uint32 buffIdx,
                                         const Flexcan_Ip_StateType * flexcanState
                                        );

/*! @brief FlexCAN Driver error callback function type
 */
/* implements  FlexCAN_Ip_ErrorCallbackType_typdef  */
typedef void (* FlexCAN_Ip_ErrorCallbackType)(uint8 instance,
                                              Flexcan_Ip_EventType eventType,
                                              uint32 u32ErrStatus,
                                              const Flexcan_Ip_StateType * flexcanState
                                             );

/*! @brief FlexCAN configuration
 * @internal gui name="Common configuration" id="flexcanCfg"
 */
/* implements   Flexcan_Ip_ConfigType_structure */
typedef struct
{
    uint32 max_num_mb;                              /**< The maximum number of Message Buffers
                                                         @internal gui name="Maximum number of message buffers" id="max_num_mb" */
    Flexcan_Ip_RxFifoIdFilterNumType num_id_filters; /**< The number of RX FIFO ID filters needed
                                                         @internal gui name="Number of RX FIFO ID filters" id="num_id_filters" */
    boolean is_rx_fifo_needed;                         /**< 1 if needed; 0 if not. This controls whether the Rx FIFO feature is enabled or not.
                                                         @internal gui name="Use rx fifo" id="is_rx_fifo_needed" */
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    uint32 num_enhanced_std_id_filters;             /**< The number of standard ID filter elements
                                                         @internal gui name="Number of standard ID filter elements" id="num_enhanced_std_id_filters" */
    uint32 num_enhanced_ext_id_filters;             /**< The number of extended ID filter elements
                                                         @internal gui name="Number of extended ID filter elements" id="num_enhanced_ext_id_filters" */
    uint32 num_enhanced_watermark;                  /**< The number of enhanced Rx FIFO watermark
                                                         @internal gui name="Number of enhanced Rx FIFO watermark" id="num_enhanced_watermark" */
    boolean is_enhanced_rx_fifo_needed;                /**< 1 if needed; 0 if not. This controls whether the Enhanced Rx FIFO feature is enabled or not.
                                                         @internal gui name="Use enhanced rx fifo" id="is_enhanced rx_fifo_needed" */
#endif /* FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO */
#if (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)
    Flexcan_Ip_TimeStampConfigType time_stamp;        /**< Free Running Counter Time Stamp config
                                                         @internal gui name="Free Running Counter Time Stamp config" id="time_stamp" */
#endif /* FLEXCAN_IP_FEATURE_HAS_TS_ENABLE */
    Flexcan_Ip_ModesType flexcanMode;               /**< User configurable FlexCAN operation modes.
                                                         @internal gui name="Flexcan Operation Mode" id="flexcanMode" */
    uint32 ctrlOptions;                             /**< Use of different features support like ISO-FD, EDGE_FILTER, AUTO_BussOffRecovery, Protocol_Exception. */
    Flexcan_Ip_PayloadSizeType payload;               /**< The payload size of the mailboxes specified in bytes for every partition block */
    boolean fd_enable;                                 /**< Enable/Disable the Flexible Data Rate feature. */
#if (FLEXCAN_IP_FEATURE_HAS_PE_CLKSRC_SELECT == STD_ON)
    boolean is_pe_clock;                                /**< This controls the clock source of the CAN Protocol Engine (PE). 1 if The CAN engine clock source is the peripheral clock
                                                            ; 0 if the CAN engine clock source is the oscillator clock.*/
#endif
    boolean enhCbtEnable;                               /**< The use of enhanced bit time segments format from ExCBT register, instead of CTRL1 or CBT register */
    boolean bitRateSwitch;                              /**< Enable of BitRate Switch support for FD frames */
    Flexcan_Ip_TimeSegmentType bitrate;                 /**< The bitrate used for standard frames or for the arbitration phase of FD frames. */
    Flexcan_Ip_TimeSegmentType bitrate_cbt;             /**< The bitrate used for the data phase of FD frames. */
    Flexcan_Ip_RxFifoTransferType transfer_type;   /**< Specifies if the Rx FIFO uses interrupts or DMA. */
#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
    uint8 rxFifoDMAChannel;                         /**< Specifies the DMA channel number to be used for DMA transfers. */
#endif /* FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE */
    FlexCAN_Ip_CallbackType Callback;               /**< The Callback for Rx or Tx DMA Events */
    FlexCAN_Ip_ErrorCallbackType ErrorCallback;     /**< The ErrorCallback for Error Events */
} Flexcan_Ip_ConfigType;



/** @brief FlexCAN Rx FIFO ID filter table structure
 *  @details Structure Used to configure and add filters to Legacy RxFIFO
 */
/* implements  Flexcan_Ip_IdTableType_structure */
typedef struct
{
    boolean isRemoteFrame;      /**< Remote frame*/
    boolean isExtendedFrame;    /**< Extended frame*/
    uint32 id;                  /**< Rx FIFO ID filter element*/
} Flexcan_Ip_IdTableType;



/** @brief FlexCAN data info from user
 *  @details This structure defines the members used to configure the Frame Parameters used to be Send or Receive.
 *           Some parameters are available based on configuration of driver like: fd_enable, fd_padding, enable_brs.
 */
/* implements  Flexcan_Ip_DataInfoType_structure */
typedef struct
{
    Flexcan_Ip_MsgBuffIdType msg_id_type;  /**< Type of message ID (standard or extended)*/
    uint32 data_length;                    /**< Length of Data in Bytes*/
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
    boolean fd_enable;                     /**< Enable or disable FD*/
    uint8 fd_padding;                      /**< Set a value for padding. It will be used when the data length code (DLC)
                                                 specifies a bigger payload size than data_length to fill the MB */
    boolean enable_brs;                    /**< Enable bit rate switch inside a CAN FD format frame*/
#endif
    boolean is_remote;                     /**< Specifies if the frame is standard or remote */
    boolean is_polling;                    /**< Specifies if the MB is in polling mode */
} Flexcan_Ip_DataInfoType;

#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/*! @brief Pretended Networking ID filter */
typedef struct
{
    boolean bExtendedId;    /*!< Specifies if the ID is standard or extended. */
    boolean bRemoteFrame;   /*!< Specifies if the frame is standard or remote. */
    uint32 u32Id;           /*!< Specifies the ID value. */
} Flexcan_Ip_PnIdFilterType;

/*! @brief Pretended Networking payload filter */
typedef struct
{
    uint8 u8DlcLow;       /*!< Specifies the lower limit of the payload size. */
    uint8 u8DlcHigh;      /*!< Specifies the upper limit of the payload size. */
    uint8 aPayload1[8U]; /*!< Specifies the payload to be matched (for MATCH_EXACT), the lower limit
                              (for MATCH_GEQ and MATCH_RANGE) or the upper limit (for MATCH_LEQ). */
    uint8 aPayload2[8U]; /*!< Specifies the mask (for MATCH_EXACT) or the upper limit (for MATCH_RANGE). */
} Flexcan_Ip_PnPayloadFilterType;

/*! @brief Pretended Networking filtering combinations */
typedef enum
{
    FLEXCAN_FILTER_ID,                  /*!< Message ID filtering only */
    FLEXCAN_FILTER_ID_PAYLOAD,          /*!< Message ID and payload filtering */
    FLEXCAN_FILTER_ID_NTIMES,           /*!< Message ID filtering occurring a specified number of times */
    FLEXCAN_FILTER_ID_PAYLOAD_NTIMES    /*!< Message ID and payload filtering  occurring a specified number of times */
} Flexcan_Ip_PnfilterCombinationType;

/*! @brief Pretended Networking matching schemes */
typedef enum
{
    FLEXCAN_FILTER_MATCH_EXACT,   /*!< Match an exact target value. */
    FLEXCAN_FILTER_MATCH_GEQ,     /*!< Match greater than or equal to a specified target value. */
    FLEXCAN_FILTER_MATCH_LEQ,     /*!< Match less than or equal to a specified target value. */
    FLEXCAN_FILTER_MATCH_RANGE    /*!< Match inside a range, greater than or equal to a specified lower limit and smaller than or
                                      equal to a specified upper limit. */
} Flexcan_Ip_PnFilterSelectionType;

/*! @brief Pretended Networking configuration structure */
/* implements  Flexcan_Ip_PnConfigType_structure */
typedef struct
{
    boolean bWakeUpTimeout;                               /*!< Specifies if an wake up event is triggered on timeout. */
    boolean bWakeUpMatch;                                 /*!< Specifies if an wake up event is triggered on match. */
    uint16 u16NumMatches;                                 /*!< The number of matches needed before generating an wake up event. */
    uint16 u16MatchTimeout;                               /*!< Defines a timeout value that generates an wake up event if wakeUpTimeout is true. */
    Flexcan_Ip_PnfilterCombinationType eFilterComb;       /*!< Defines the filtering scheme used. */
    Flexcan_Ip_PnIdFilterType idFilter1;                  /*!< The configuration of the first ID filter (match exact / lower limit / upper limit). */
    Flexcan_Ip_PnIdFilterType idFilter2;                  /*!< The configuration of the second ID filter (mask / upper limit). */
    Flexcan_Ip_PnFilterSelectionType eIdFilterType;       /*!< Defines the ID filtering scheme. */
    Flexcan_Ip_PnFilterSelectionType ePayloadFilterType;  /*!< Defines the payload filtering scheme. */
    Flexcan_Ip_PnPayloadFilterType payloadFilter;         /*!< The configuration of the payload filter. */
} Flexcan_Ip_PnConfigType;
#endif /* (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXCAN_IP_TYPES_H_ */
