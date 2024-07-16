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

#ifndef FLEXCAN_FLEXCAN_IP_HWACCESS_H_
#define FLEXCAN_FLEXCAN_IP_HWACCESS_H_

/**
 *  @file FlexCAN_Ip_HwAccess.h
 *
 *  @brief FlexCAN HardWare Access Header File
 *
 *  @addtogroup FlexCAN
 *  @{
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
#include "FlexCAN_Ip.h"
#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif
#include "OsIf.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_HWACCESS_VENDOR_ID_H                      43
#define FLEXCAN_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H       7
#define FLEXCAN_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_H    0
#define FLEXCAN_IP_HWACCESS_SW_MAJOR_VERSION_H               2
#define FLEXCAN_IP_HWACCESS_SW_MINOR_VERSION_H               0
#define FLEXCAN_IP_HWACCESS_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip header file are of the same vendor */
#if (FLEXCAN_IP_HWACCESS_VENDOR_ID_H != FLEXCAN_IP_VENDOR_ID_H)
    #error "FlexCAN_Ip_HwAccess.h and FlexCAN_Ip.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip header file are of the same Autosar version */
#if ((FLEXCAN_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip_HwAccess.h and FlexCAN_Ip.h are different"
#endif
/* Check if current file and FlexCAN_Ip header file are of the same Software version */
#if ((FLEXCAN_IP_HWACCESS_SW_MAJOR_VERSION_H != FLEXCAN_IP_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_HWACCESS_SW_MINOR_VERSION_H != FLEXCAN_IP_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_HWACCESS_SW_PATCH_VERSION_H != FLEXCAN_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of FlexCAN_Ip_HwAccess.h and FlexCAN_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Devassert header file are of the same version */
    #if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
        #if ((FLEXCAN_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H    !=  DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
             (FLEXCAN_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H     !=  DEVASSERT_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AUTOSAR Version Numbers of FlexCAN_Ip_HwAccess.h and Devassert.h are different"
        #endif
    #endif
    /* Check if current file and osif header file are of the same version */
    #if ((FLEXCAN_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H    !=  OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXCAN_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H     !=  OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of FlexCAN_Ip_HwAccess.h and OsIf.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* @brief Frames available in Rx FIFO flag shift */
#define FLEXCAN_IP_LEGACY_RXFIFO_FRAME_AVAILABLE  (5U)
/* @brief Rx FIFO warning flag shift */
#define FLEXCAN_IP_LEGACY_RXFIFO_WARNING          (6U)
/* @brief Rx FIFO overflow flag shift */
#define FLEXCAN_IP_LEGACY_RXFIFO_OVERFLOW         (7U)
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/* @brief Frames available in Enhanced Rx FIFO flag shift */
#define FLEXCAN_IP_ENHANCED_RXFIFO_FRAME_AVAILABLE     (28U)
/* @brief Enhanced Rx FIFO Watermark Indication flag shift */
#define FLEXCAN_IP_ENHANCED_RXFIFO_WATERMARK           (29U)
/* @brief Enhanced Rx FIFO Overflow  flag shift */
#define FLEXCAN_IP_ENHANCED_RXFIFO_OVERFLOW            (30U)
/* @brief Enhanced Rx FIFO Underflow flag shift */
#define FLEXCAN_IP_ENHANCED_RXFIFO_UNDERFLOW           (31U)
/*! @brief FlexCAN Enhanced Fifo Embedded RAM address offset */
#define FLEXCAN_IP_FEATURE_ENHANCED_FIFO_RAM_OFFSET        (0x00002000u)
/*! @brief FlexCAN Enhacend Fifo FilterDepth */
#define FLEXCAN_IP_ENHANCED_RXFIFO_FILTERDEPTH         (128U)
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

/*! @brief FlexCAN Embedded RAM address offset */
#define FLEXCAN_IP_FEATURE_RAM_OFFSET                      (0x00000080u)

#if (STD_ON == FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY)
/*! @brief FlexCAN Expandable Embedded RAM address offset */
#define FLEXCAN_IP_FEATURE_EXP_RAM_OFFSET                  (0x00001000u)
#endif /* (STD_ON == FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY) */

#define FLEXCAN_IP_ALL_INT                     (0x3B0006U)                 /*!< Masks for wakeup, error, bus off*/

#if (FLEXCAN_IP_FEATURE_BUSOFF_ERROR_INTERRUPT_UNIFIED == STD_OFF)
#define FLEXCAN_IP_BUS_OFF_INT                         (0xB0004U)                  /*!< Masks for busOff, Tx/Rx Warning */
#define FLEXCAN_IP_ERROR_INT                           (0x300002U)                 /*!< Masks for ErrorOvr, ErrorFast, Error */
#endif
#define FLEXCAN_IP_ESR1_FLTCONF_BUS_OFF                        (0x00000020U)

#define FLEXCAN_IP_ID_EXT_MASK                                   0x3FFFFu
#define FLEXCAN_IP_ID_EXT_SHIFT                                  0
#define FLEXCAN_IP_ID_EXT_WIDTH                                  18

#define FLEXCAN_IP_ID_STD_MASK                                   0x1FFC0000u
#define FLEXCAN_IP_ID_STD_SHIFT                                  18
#define FLEXCAN_IP_ID_STD_WIDTH                                  11

#define FLEXCAN_IP_ID_PRIO_MASK                                  0xE0000000u
#define FLEXCAN_IP_ID_PRIO_SHIFT                                 29
#define FLEXCAN_IP_ID_PRIO_WIDTH                                 3
/* CS Bit Fields */
#define FLEXCAN_IP_CS_TIME_STAMP_MASK                            0xFFFFu
#define FLEXCAN_IP_CS_TIME_STAMP_SHIFT                           0
#define FLEXCAN_IP_CS_TIME_STAMP_WIDTH                           16

#define FLEXCAN_IP_CS_DLC_MASK                                   0xF0000u
#define FLEXCAN_IP_CS_DLC_SHIFT                                  16
#define FLEXCAN_IP_CS_DLC_WIDTH                                  4

#define FLEXCAN_IP_CS_RTR_MASK                                   0x100000u
#define FLEXCAN_IP_CS_RTR_SHIFT                                  20
#define FLEXCAN_IP_CS_RTR_WIDTH                                  1

#define FLEXCAN_IP_CS_IDE_MASK                                   0x200000u
#define FLEXCAN_IP_CS_IDE_SHIFT                                  21
#define FLEXCAN_IP_CS_IDE_WIDTH                                  1

#define FLEXCAN_IP_CS_SRR_MASK                                   0x400000u
#define FLEXCAN_IP_CS_SRR_SHIFT                                  22
#define FLEXCAN_IP_CS_SRR_WIDTH                                  1

#define FLEXCAN_IP_CS_CODE_MASK                                  0xF000000u
#define FLEXCAN_IP_CS_CODE_SHIFT                                 24
#define FLEXCAN_IP_CS_CODE_WIDTH                                 4

#define FLEXCAN_IP_CS_IDHIT_MASK                                 0xFF800000u
#define FLEXCAN_IP_CS_IDHIT_SHIFT                                23
#define FLEXCAN_IP_CS_IDHIT_WIDTH                                9

#define FLEXCAN_IP_MB_EDL_MASK                                   0x80000000u
#define FLEXCAN_IP_MB_BRS_MASK                                   0x40000000u

#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATAB_RTR_SHIFT      (31U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format A&B RTR mask.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATAB_IDE_SHIFT      (30U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format A&B IDE mask.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_RTR_SHIFT       (15U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format B RTR-2 mask.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_IDE_SHIFT       (14U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format B IDE-2 mask.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATA_EXT_MASK        (0x3FFFFFFFU) /*!< FlexCAN RX FIFO ID filter*/
/*! format A extended mask.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATA_EXT_SHIFT       (1U)          /*!< FlexCAN RX FIFO ID filter*/
/*! format A extended shift.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATA_STD_MASK        (0x3FF80000U) /*!< FlexCAN RX FIFO ID filter*/
/*! format A standard mask.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATA_STD_SHIFT       (19U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format A standard shift.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK        (0x1FFF8000U) /*!< FlexCAN RX FIFO ID filter*/
/*! format B extended mask1.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_EXT_SHIFT1      (16U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format B extended shift 1.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_EXT_SHIFT2      (0U)          /*!< FlexCAN RX FIFO ID filter*/
/*! format B extended shift 2.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_STD_MASK        (0x7FFU)      /*!< FlexCAN RX FIFO ID filter*/
/*! format B standard mask.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_STD_SHIFT1      (19U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format B standard shift1.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_STD_SHIFT2      (3U)          /*!< FlexCAN RX FIFO ID filter*/
/*! format B standard shift2.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT   (15U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format B extended compare shift.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK        (0x1FE00000U) /*!< FlexCAN RX FIFO ID filter*/
/*! format C mask.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_STD_MASK        (0x7F8U)      /*!< FlexCAN RX FIFO ID filter*/
/*! format C mask.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT1          (24U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format C shift1.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT2          (16U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format C shift2.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT3          (8U)          /*!< FlexCAN RX FIFO ID filter*/
/*! format C shift3.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT4          (0U)          /*!< FlexCAN RX FIFO ID filter*/
/*! format C shift4.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT   (21U)         /*!< FlexCAN RX FIFO ID filter*/
/*! format C extended compare shift.*/
#define FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT   (3U)          /*!< FlexCAN RX FIFO ID filter*/

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)

#define FLEXCAN_IP_ENHANCED_IDHIT_MASK                           0x7Fu
#define FLEXCAN_IP_ENHANCED_IDHIT_SHIFT                          0
#define FLEXCAN_IP_ENHANCED_IDHIT_WIDTH                          7

#define FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_FSCH_SHIFT     (30U)             /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard & Extended FSCH shift.*/
#define FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_RTR2_SHIFT (27U)             /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard RTR-2 shift.*/
#define FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_RTR1_SHIFT (11U)             /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard RTR-1 shift.*/
#define FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_EXT_RTR_SHIFT  (29U)             /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Extended RTR shift.*/
#define FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_SHIFT2     (16U)             /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard ID-2 shift.*/
#define FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_SHIFT1     (0U)              /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard ID-1 shift.*/
#define FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_MASK       (0x7FFU)          /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Standard ID mask.*/
#define FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_EXT_SHIFT      (0U)              /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Extended ID shift.*/
#define FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_EXT_MASK       (0x1FFFFFFFU)     /*!< FlexCAN Enhanced RX FIFO ID filter*/
/*! Mask for enable all enhanced interrupts */
#define FLEXCAN_IP_ENHACED_RX_FIFO_ALL_INTERRUPT_MASK      (FLEXCAN_ERFIER_ERFUFWIE_MASK | FLEXCAN_ERFIER_ERFOVFIE_MASK | \
                                                            FLEXCAN_ERFIER_ERFWMIIE_MASK | FLEXCAN_ERFIER_ERFDAIE_MASK \
                                                           )

/*! Mask for disable all enhanced interrupts */
#define FLEXCAN_IP_ENHACED_RX_FIFO_NO_INTERRUPT_MASK         (0U)
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_On) */

/* This are for little endians cores and supporting rev32 asm instuction */
#define FLEXCAN_IP_SWAP_BYTES_IN_WORD_INDEX(index) (((index) & ~3U) + (3U - ((index) & 3U)))
#define FLEXCAN_IP_SWAP_BYTES_IN_WORD(a, b) FLEXCAN_IP_REV_BYTES_32(a, b)
#define FLEXCAN_IP_REV_BYTES_32(a, b) ((b) = (((a) & 0xFF000000U) >> 24U) | (((a) & 0xFF0000U) >> 8U) \
                                | (((a) & 0xFF00U) << 8U) | (((a) & 0xFFU) << 24U))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/*! @brief FlexCAN message buffer CODE for Rx buffers*/
enum
{
    FLEXCAN_RX_INACTIVE  = 0x0, /*!< MB is not active.*/
    FLEXCAN_RX_FULL      = 0x2, /*!< MB is full.*/
    FLEXCAN_RX_EMPTY     = 0x4, /*!< MB is active and empty.*/
    FLEXCAN_RX_OVERRUN   = 0x6, /*!< MB is overwritten into a full buffer.*/
    FLEXCAN_RX_BUSY      = 0x8, /*!< FlexCAN is updating the contents of the MB.*/
                                /*!  The CPU must not access the MB.*/
    FLEXCAN_RX_RANSWER   = 0xA, /*!< A frame was configured to recognize a Remote Request Frame*/
                                /*!  and transmit a Response Frame in return.*/
    FLEXCAN_RX_NOT_USED   = 0xF /*!< Not used*/
};

/*! @brief FlexCAN message buffer CODE FOR Tx buffers*/
enum
{
    FLEXCAN_TX_INACTIVE  = 0x08, /*!< MB is not active.*/
    FLEXCAN_TX_ABORT     = 0x09, /*!< MB is aborted.*/
    FLEXCAN_TX_DATA      = 0x0C, /*!< MB is a TX Data Frame(MB RTR must be 0).*/
    FLEXCAN_TX_REMOTE    = 0x1C, /*!< MB is a TX Remote Request Frame (MB RTR must be 1).*/
    FLEXCAN_TX_TANSWER   = 0x0E, /*!< MB is a TX Response Request Frame from.*/
                                 /*!  an incoming Remote Request Frame.*/
    FLEXCAN_TX_NOT_USED   = 0xF  /*!< Not used*/
};

/*! @brief FlexCAN error interrupt types
 */
typedef enum
{
    FLEXCAN_INT_RX_WARNING = FLEXCAN_CTRL1_RWRNMSK_MASK,     /*!< RX warning interrupt*/
    FLEXCAN_INT_TX_WARNING = FLEXCAN_CTRL1_TWRNMSK_MASK,     /*!< TX warning interrupt*/
    FLEXCAN_INT_ERR        = FLEXCAN_CTRL1_ERRMSK_MASK,      /*!< Error interrupt*/
    FLEXCAN_INT_ERR_FAST,                                    /*!< Error Fast interrupt*/
    FLEXCAN_INT_BUSOFF     = FLEXCAN_CTRL1_BOFFMSK_MASK,     /*!< Bus off interrupt*/
} flexcan_int_type_t;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*! @brief FlexCAN Message Buffer code and status for transmit and receive
 */
typedef struct
{
    uint32 code;                        /*!< MB code for TX or RX buffers.*/
                                        /*! Defined by flexcan_mb_code_rx_t and flexcan_mb_code_tx_t */
    Flexcan_Ip_MsgBuffIdType msgIdType; /*!< Type of message ID (standard or extended)*/
    uint32 dataLen;                     /*!< Length of Data in Bytes*/
    boolean fd_enable;
    uint8 fd_padding;
    boolean enable_brs;                   /* Enable bit rate switch*/
} Flexcan_Ip_MsbuffCodeStatusType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"


void FLEXCAN_ClearMsgBuffIntCmd(FLEXCAN_Type * pBase,
                                uint8 u8Instance,
                                uint32 mb_idx,
                                boolean bIsIntActive
                               );

void FlexCAN_SetErrIntCmd(FLEXCAN_Type * base,
                          flexcan_int_type_t errType,
                          boolean enable
                         );

Flexcan_Ip_StatusType FlexCAN_EnterFreezeMode(FLEXCAN_Type * base);

/*!
 * @brief Sets the FlexCAN Rx FIFO fields.
 *
 * @param   base             The FlexCAN base address
 * @param   idFormat         The format of the Rx FIFO ID Filter Table Elements
 * @param   idFilterTable    The ID filter table elements which contain RTR bit,
 *                           IDE bit, and RX message ID.
 */
void FlexCAN_SetRxFifoFilter(FLEXCAN_Type * base,
                             Flexcan_Ip_RxFifoIdElementFormatType idFormat,
                             const Flexcan_Ip_IdTableType * idFilterTable
                            );

/*!
 * @brief Gets the FlexCAN Rx FIFO data.
 *
 * @param   base    The FlexCAN base address
 * @param   rxFifo  The FlexCAN receive FIFO data
 */
void FlexCAN_ReadRxFifo(const FLEXCAN_Type * base,
                        Flexcan_Ip_MsgBuffType * rxFifo
                       );

/*!
 * @brief Un freezes the FlexCAN module.
 *
 * @param   base     The FlexCAN base address
 * @return FLEXCAN_STATUS_SUCCESS successfully exit from freeze
 *         FLEXCAN_STATUS_TIMEOUT fail to exit from freeze
 */
Flexcan_Ip_StatusType FlexCAN_ExitFreezeMode(FLEXCAN_Type * base);

Flexcan_Ip_StatusType FlexCAN_Disable(FLEXCAN_Type * base);

Flexcan_Ip_StatusType FlexCAN_Enable(FLEXCAN_Type * base);

/*!
 * @brief Locks the FlexCAN Rx message buffer.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer
 *
 */
void FlexCAN_LockRxMsgBuff(const FLEXCAN_Type * base,
                           uint32 msgBuffIdx
                          );

/*!
 * @brief Enables/Disables the FlexCAN Message Buffer interrupt.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer
 * @param   enable       choose enable or disable
 * @return  FLEXCAN_STATUS_SUCCESS if successful;
 *          FLEXCAN_STATUS_CAN_BUFF_OUT_OF_RANGE if the index of the
 *          message buffer is invalid
 */
Flexcan_Ip_StatusType FlexCAN_SetMsgBuffIntCmd(FLEXCAN_Type * base,
                                               uint8 u8Instance,
                                               uint32 msgBuffIdx,
                                               boolean enable,
                                               boolean bIsIntActive
                                              );

/*!
 * @brief Disable all interrupts.
 *
 * @param   pBase       The FlexCAN base address
 */
void FlexCAN_DisableInterrupts(FLEXCAN_Type * pBase);

/*!
 * @brief Enable all interrupts configured.
 *
 * @param   pBase       The FlexCAN base address
 * @param   u8Instance  A FlexCAN instance number
 */
void FlexCAN_EnableInterrupts(FLEXCAN_Type * pBase, uint8 u8Instance);
/*!
 * @brief Sets the FlexCAN message buffer fields for transmitting.
 *
 * @param   pMbAddr      The Message buffer address
 * @param   cs           CODE/status values (TX)
 * @param   msgId        ID of the message to transmit
 * @param   msgData      Bytes of the FlexCAN message
 * @param   isRemote     Will set RTR remote Flag
 * @return  FLEXCAN_STATUS_SUCCESS if successful;
 *          FLEXCAN_STATUS_CAN_BUFF_OUT_OF_RANGE if the index of the
 *          message buffer is invalid
 */
void FlexCAN_SetTxMsgBuff(volatile uint32 * const pMbAddr,
                          const Flexcan_Ip_MsbuffCodeStatusType * cs,
                          uint32 msgId,
                          const uint8 * msgData,
                          const boolean isRemote
                         );

/*!
 * @brief Enables the Rx FIFO.
 *
 * @param   base     The FlexCAN base address
 * @param   numOfFilters    The number of Rx FIFO filters
 * @return  The status of the operation
 * @retval  FLEXCAN_STATUS_SUCCESS RxFIFO was successfully enabled
 * @retval  FLEXCAN_STATUS_ERROR RxFIFO could not be enabled (e.g. the FD feature
 *          was enabled, and these two features are not compatible)
 */
Flexcan_Ip_StatusType FlexCAN_EnableRxFifo(FLEXCAN_Type * base, uint32 numOfFilters);


/*!
 * @brief Sets  the maximum number of Message Buffers.
 *
 * @param   base  The FlexCAN base address
 * @param   maxMsgBuffNum     Maximum number of message buffers
 * @return  FLEXCAN_STATUS_SUCCESS if successful;
 *          FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of the
 *          message buffer is invalid
 */
Flexcan_Ip_StatusType FlexCAN_SetMaxMsgBuffNum(FLEXCAN_Type * base, uint32 maxMsgBuffNum);

/*!
 * @brief Sets the FlexCAN message buffer fields for receiving.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer
 * @param   cs           CODE/status values (RX)
 * @param   msgId       ID of the message to receive
 * @return  FLEXCAN_STATUS_SUCCESS if successful;
 *          FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of the
 *          message buffer is invalid
 */
void FlexCAN_SetRxMsgBuff(const FLEXCAN_Type * base,
                          uint32 msgBuffIdx,
                          const Flexcan_Ip_MsbuffCodeStatusType * cs,
                          uint32 msgId
                         );

/*!
 * @brief Gets the message buffer timestamp value.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer
 * @return  value of timestamp for selected message buffer.
 */
uint32 FlexCAN_GetMsgBuffTimestamp(const FLEXCAN_Type * base, uint32 msgBuffIdx);

/*!
 * @brief Gets the FlexCAN message buffer fields.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer
 * @param   msgBuff           The fields of the message buffer
 */
void FlexCAN_GetMsgBuff(const FLEXCAN_Type * base,
                        uint32 msgBuffIdx,
                        Flexcan_Ip_MsgBuffType * msgBuff
                       );

#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
#if defined(CAN_FEATURE_S32K1XX)
/*!
 * @brief Check if instance support FD.
 *
 * @param[in]   base  The FlexCAN base address
 * @return TRUE\FALSE if support FD.
 */
boolean FlexCAN_IsFDAvailable(const FLEXCAN_Type * base);
#endif
/*!
 * @brief Sets the payload size of the MBs.
 *
 * @param   base         The FlexCAN base address
 * @param   payloadSize  The payload size
 */
void FlexCAN_SetPayloadSize(FLEXCAN_Type * base, const Flexcan_Ip_PayloadSizeType * payloadSize);

/*!
 * @brief Check If mb index is out of range or not.
 *
 * @param   pBase                The FlexCAN base address
 * @param   u8MbIndex            MB index
 * @param   bIsLegacyFifoEn      Legacy fifo enabled or not
 * @param   u32MaxMbNum          Max mb number
 */
boolean FlexCAN_IsMbOutOfRange
(
    const FLEXCAN_Type * pBase,
    uint8 u8MbIndex,
    boolean bIsLegacyFifoEn,
    uint32 u32MaxMbNum
);

/*!
 * @brief Sets the FlexCAN RX FIFO global mask.
 *
 * @param[in]   base  The FlexCAN base address
 * @param[in]   Mask     Sets mask
 */
static inline void FlexCAN_SetRxFifoGlobalMask(FLEXCAN_Type * base, uint32 Mask)
{
    (base->RXFGMASK) = Mask;
}

/*!
 * @brief Enables/Disables the Transceiver Delay Compensation feature and sets
 * the Transceiver Delay Compensation Offset (offset value to be added to the
 * measured transceiver's loop delay in order to define the position of the
 * delayed comparison point when bit rate switching is active).
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable Transceiver Delay Compensation
 * @param   offset Transceiver Delay Compensation Offset
 */
static inline void FlexCAN_SetTDCOffset(FLEXCAN_Type * base,
                                        boolean enable,
                                        uint8 offset
                                       )
{
    uint32 tmp;

    tmp = base->FDCTRL;
    tmp &= ~(FLEXCAN_FDCTRL_TDCEN_MASK | FLEXCAN_FDCTRL_TDCOFF_MASK);

    if (enable)
    {
        tmp = tmp | FLEXCAN_FDCTRL_TDCEN_MASK;
        tmp = tmp | FLEXCAN_FDCTRL_TDCOFF(offset);
    }

    base->FDCTRL = tmp;
}

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCE_CBT == STD_ON)
/*!
 * @brief Enables/Disables the Transceiver Delay Compensation feature and sets
 * the Transceiver Delay Compensation Offset (offset value to be added to the
 * measured transceiver's loop delay in order to define the position of the
 * delayed comparison point when bit rate switching is active).
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable Transceiver Delay Compensation
 * @param   offset Transceiver Delay Compensation Offset
 */
static inline void FlexCAN_SetEnhancedTDCOffset(FLEXCAN_Type * base,
                                                boolean enable,
                                                uint8 offset
                                               )
{
    uint32 tmp;

    tmp = base->ETDC;
    tmp &= ~(FLEXCAN_ETDC_ETDCEN_MASK | FLEXCAN_ETDC_ETDCOFF_MASK);

    if (enable)
    {
        tmp = tmp | FLEXCAN_ETDC_ETDCEN_MASK;
        tmp = tmp | FLEXCAN_ETDC_ETDCOFF(offset);
    }

    base->ETDC = tmp;
}
#endif
#endif /* FLEXCAN_IP_FEATURE_HAS_FD */

/*!
 * @brief Gets the payload size of the MBs.
 *
 * @param   base         The FlexCAN base address
 * @return  The payload size in bytes
 */
uint8 FlexCAN_GetMbPayloadSize(const FLEXCAN_Type * base, uint32 maxMsgBuffNum);
/*!
 * @brief Initializes the FlexCAN controller.
 *
 * @param   base  The FlexCAN base address
 */
Flexcan_Ip_StatusType FlexCAN_Init(FLEXCAN_Type * base);

/*!
 * @brief Checks if the FlexCAN is enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
static inline boolean FlexCAN_IsEnabled(const FLEXCAN_Type * pBase)
{
    return (((pBase->MCR & FLEXCAN_MCR_MDIS_MASK) >> FLEXCAN_MCR_MDIS_SHIFT) != 0U) ? FALSE : TRUE;
}

#if (FLEXCAN_IP_FEATURE_HAS_MEM_ERR_DET == STD_ON)
/*!
 * @brief Disable Error Detection and Correction of Memory Errors.
 *
 * @param   base  The FlexCAN base address
 */
static inline void FlexCAN_DisableMemErrorDetection(FLEXCAN_Type * base)
{
    /* Enable write of MECR register */
    base->CTRL2 |=  FLEXCAN_CTRL2_ECRWRE(1);
    /* Enable write of MECR */
    base->MECR = FLEXCAN_MECR_ECRWRDIS(0);
    /* Disable Error Detection and Correction mechanism,
     * that will set CAN in Freez Mode in case of trigger */
    base->MECR = FLEXCAN_MECR_NCEFAFRZ(0);
    /* Disable memory error correction */
    base->MECR |= FLEXCAN_MECR_ECCDIS(1);
    /* Disable write of MECR */
    base->CTRL2 &= ~FLEXCAN_CTRL2_ECRWRE(1);
}
#endif /* FLEXCAN_IP_FEATURE_HAS_MEM_ERR_DET */

/*!
 * @brief Enables/Disables Flexible Data rate (if supported).
 *
 * @param   base    The FlexCAN base address
 * @param   enable  TRUE to enable; FALSE to disable
 */
static inline void FlexCAN_SetFDEnabled(FLEXCAN_Type * base,
                                        boolean enableFD,
                                        boolean enableBRS
                                       )
{
    base->MCR = (base->MCR & ~FLEXCAN_MCR_FDEN_MASK) | FLEXCAN_MCR_FDEN(enableFD ? 1UL : 0UL);

    /* Enable BitRate Switch support from BRS_TX_MB field or ignore it */
    base->FDCTRL = (base->FDCTRL & ~FLEXCAN_FDCTRL_FDRATE_MASK) | FLEXCAN_FDCTRL_FDRATE(enableBRS ? 1UL : 0UL);

    /* Disable Transmission Delay Compensation by default */
    base->FDCTRL &= ~(FLEXCAN_FDCTRL_TDCEN_MASK | FLEXCAN_FDCTRL_TDCOFF_MASK);
}

/*!
 * @brief Enables/Disables Listen Only Mode.
 *
 * @param   base    The FlexCAN base address
 * @param   enable  TRUE to enable; FALSE to disable
 */
static inline void FlexCAN_SetListenOnlyMode(FLEXCAN_Type * base, boolean enableListenOnly)
{
    base->CTRL1 = (base->CTRL1 & ~FLEXCAN_CTRL1_LOM_MASK) | FLEXCAN_CTRL1_LOM(enableListenOnly ? 1UL : 0UL);
}



#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)

/*!
 * @brief Clears the FIFO
 *
 * @param   base  The FlexCAN base address
 */
static inline void FlexCAN_ClearFIFO(FLEXCAN_Type * base)
{
    base->IFLAG1 = FLEXCAN_IFLAG1_BUF0I_MASK;
}


/*!
 * @brief Enables/Disables the DMA support for RxFIFO.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable DMA support
 */
static inline void FlexCAN_SetRxFifoDMA(FLEXCAN_Type * base, boolean enable)
{
    base->MCR = (base->MCR & ~FLEXCAN_MCR_DMA_MASK) | FLEXCAN_MCR_DMA(enable ? 1UL : 0UL);
}

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/*!
 * @brief Resets Enhanced Rx FIFO engine and state.
 *
 * @param   base  The FlexCAN base address
 */
static inline void FlexCAN_ClearEnhancedRxFifoEngine(FLEXCAN_Type * base)
{
    base->ERFSR = base->ERFSR | FLEXCAN_ERFSR_ERFCLR_MASK;
}

/*!
 * @brief Clears the Enhanced Rx FIFO
 *
 * @param   base  The FlexCAN base address
 */
static inline void FlexCAN_ClearEnhancedFIFO(FLEXCAN_Type * base)
{
    base->ERFSR = FLEXCAN_ERFSR_ERFCLR_MASK;
}

/*!
 * @brief Configure the number of words to transfer for each Enhanced Rx FIFO data element in DMA mode.
 *
 * @param   base    The FlexCAN base address
 * @param   numOfWords   The number of words to transfer
 */
static inline void FlexCAN_ConfigEnhancedRxFifoDMA(FLEXCAN_Type * base, uint32 numOfWords)
{
    base->ERFCR = (base->ERFCR & (~FLEXCAN_ERFCR_DMALW_MASK)) | (((numOfWords - 1u) << FLEXCAN_ERFCR_DMALW_SHIFT) & FLEXCAN_ERFCR_DMALW_MASK);
}

#endif /* FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO */
#endif /* if FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE */

/*!
 * @brief Get The Max no of MBs allowed on CAN instance.
 *
 * @param   base    The FlexCAN base address
 * @return  The Max No of MBs on the CAN instance;
 */
uint32 FlexCAN_GetMaxMbNum(const FLEXCAN_Type * base);

/*!
 * @brief Unlocks the FlexCAN Rx message buffer.
 *
 * @param   base     The FlexCAN base address
 */
static inline void FlexCAN_UnlockRxMsgBuff(const FLEXCAN_Type * base)
{
    /* Unlock the mailbox by reading the free running timer */
    (void)base->TIMER;
}

/*!
 * @brief Clears the interrupt flag of the message buffers.
 *
 * @param   base        The FlexCAN base address
 * @param   msgBuffIdx  Index of the message buffer
 */
static inline void FlexCAN_ClearMsgBuffIntStatusFlag(FLEXCAN_Type * base, uint32 msgBuffIdx)
{
    uint32 flag = ((uint32)1U << (msgBuffIdx % 32U));

    /* Clear the corresponding message buffer interrupt flag*/
    if (msgBuffIdx < 32U)
    {
        (base->IFLAG1) = (flag);
    }

#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U
    else if (msgBuffIdx < 64U)
    {
        (base->IFLAG2) = (flag);
    }
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 64U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif
#endif /* if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U */
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U
    else if (msgBuffIdx < 96U)
    {
        (base->IFLAG3) = (flag);
    }
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 96U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif
#endif /* if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U */
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U
    else
    {
        (base->IFLAG4) = (flag);
    }
#endif
}

/*!
 * @brief Get the interrupt flag of the message buffers.
 *
 * @param   base                The FlexCAN base address
 * @param   msgBuffIdx  Index of the message buffer
 * @return  flag        The value of interrupt flag of the message buffer.
 */
static inline uint8 FlexCAN_GetBuffStatusFlag(const FLEXCAN_Type * base, uint32 msgBuffIdx)
{
    uint32 flag = 0U;

    if (msgBuffIdx < 32U)
    {
        flag = ((base->IFLAG1 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }

#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U
    else if (msgBuffIdx < 64U)
    {
        flag = ((base->IFLAG2 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 64U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif /* FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 64U */
#endif /* FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U */

#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U
    else if (msgBuffIdx < 96U)
    {
        flag = ((base->IFLAG3 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 96U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif /* FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 96U */
#endif /* FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U */

#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U
    else
    {
        flag = ((base->IFLAG4 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#endif

    return (uint8)flag;
}

/*!
 * @brief Get the interrupt Imask of the message buffers.
 *
 * @param   base                The FlexCAN base address
 * @param   msgBuffIdx  Index of the message buffer
 * @return  Imask        The value of interrupt Imask of the message buffer.
 */
static inline uint8 FlexCAN_GetBuffStatusImask(const FLEXCAN_Type * base, uint32 msgBuffIdx)
{
    uint32 u32Imask = 0U;

    if (msgBuffIdx < 32U)
    {
        u32Imask = ((base->IMASK1 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }

#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U
    else if (msgBuffIdx < 64U)
    {
        u32Imask = ((base->IMASK2 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 64U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif /* FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 64U */
#endif /* FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U */

#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U
    else if (msgBuffIdx < 96U)
    {
        u32Imask = ((base->IMASK3 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 96U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif /* FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 96U */
#endif /* FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U */

#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U
    else
    {
        u32Imask = ((base->IMASK4 & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U));
    }
#endif

    return (uint8)u32Imask;
}


#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)

/*!
 * @brief Sets the FlexCAN time segments for setting up bit rate for FD BRS.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
static inline void FlexCAN_SetFDTimeSegments(FLEXCAN_Type * base, const Flexcan_Ip_TimeSegmentType * timeSeg)
{
#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(timeSeg != NULL_PTR);
#endif
    /* Set FlexCAN time segments*/
    (base->FDCBT) = ((base->FDCBT) & ~((FLEXCAN_FDCBT_FPROPSEG_MASK | FLEXCAN_FDCBT_FPSEG2_MASK |
                                        FLEXCAN_FDCBT_FPSEG1_MASK | FLEXCAN_FDCBT_FPRESDIV_MASK
                                       ) | FLEXCAN_FDCBT_FRJW_MASK
                                      )
                    );

    (base->FDCBT) = ((base->FDCBT) | (FLEXCAN_FDCBT_FPROPSEG(timeSeg->propSeg) |
                                      FLEXCAN_FDCBT_FPSEG2(timeSeg->phaseSeg2) |
                                      FLEXCAN_FDCBT_FPSEG1(timeSeg->phaseSeg1) |
                                      FLEXCAN_FDCBT_FPRESDIV(timeSeg->preDivider) |
                                      FLEXCAN_FDCBT_FRJW(timeSeg->rJumpwidth)
                                     )
                    );
}

#endif /* FLEXCAN_IP_FEATURE_HAS_FD */
/*!
 * @brief Sets the FlexCAN time segments for setting up bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
static inline void FlexCAN_SetTimeSegments(FLEXCAN_Type * base, const Flexcan_Ip_TimeSegmentType * timeSeg)
{
#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(timeSeg != NULL_PTR);
#endif
    (base->CTRL1) = ((base->CTRL1) & ~((FLEXCAN_CTRL1_PROPSEG_MASK | FLEXCAN_CTRL1_PSEG2_MASK |
                                        FLEXCAN_CTRL1_PSEG1_MASK | FLEXCAN_CTRL1_PRESDIV_MASK
                                       ) | FLEXCAN_CTRL1_RJW_MASK
                                      )
                    );

    (base->CTRL1) = ((base->CTRL1) | (FLEXCAN_CTRL1_PROPSEG(timeSeg->propSeg) |
                                      FLEXCAN_CTRL1_PSEG2(timeSeg->phaseSeg2) |
                                      FLEXCAN_CTRL1_PSEG1(timeSeg->phaseSeg1) |
                                      FLEXCAN_CTRL1_PRESDIV(timeSeg->preDivider) |
                                      FLEXCAN_CTRL1_RJW(timeSeg->rJumpwidth)
                                     )
                    );
}

/*!
 * @brief Sets the FlexCAN extended time segments for setting up bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
static inline void FlexCAN_SetExtendedTimeSegments(FLEXCAN_Type * base, const Flexcan_Ip_TimeSegmentType * timeSeg)
{
#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(timeSeg != NULL_PTR);
#endif
    /* If extended bit time definitions are enabled, use CBT register */
    (base->CBT) = ((base->CBT) & ~((FLEXCAN_CBT_EPROPSEG_MASK | FLEXCAN_CBT_EPSEG2_MASK |
                                    FLEXCAN_CBT_EPSEG1_MASK | FLEXCAN_CBT_EPRESDIV_MASK
                                   ) | FLEXCAN_CBT_ERJW_MASK
                                  )
                  );

    (base->CBT) = ((base->CBT) | (FLEXCAN_CBT_EPROPSEG(timeSeg->propSeg) |
                                  FLEXCAN_CBT_EPSEG2(timeSeg->phaseSeg2) |
                                  FLEXCAN_CBT_EPSEG1(timeSeg->phaseSeg1) |
                                  FLEXCAN_CBT_EPRESDIV(timeSeg->preDivider) |
                                  FLEXCAN_CBT_ERJW(timeSeg->rJumpwidth)
                                 )
                  );
}

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCE_CBT == STD_ON)
/*!
 * @brief Sets the FlexCAN Enhanced time segments for setting up nominal bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
static inline void FlexCAN_SetEnhancedNominalTimeSegments(FLEXCAN_Type * base, const Flexcan_Ip_TimeSegmentType * timeSeg)
{
#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(timeSeg != NULL_PTR);
#endif
    (base->ENCBT) = ((base->ENCBT) & ~(FLEXCAN_ENCBT_NTSEG1_MASK | FLEXCAN_ENCBT_NTSEG2_MASK | FLEXCAN_ENCBT_NRJW_MASK));

    (base->ENCBT) = ((base->ENCBT) |(FLEXCAN_ENCBT_NTSEG1(timeSeg->phaseSeg1 + timeSeg->propSeg + 1U) |
                                     FLEXCAN_ENCBT_NTSEG2(timeSeg->phaseSeg2) |
                                     FLEXCAN_ENCBT_NRJW(timeSeg->rJumpwidth)
                                    )
                    );
    (base->EPRS) = (base->EPRS & ~FLEXCAN_EPRS_ENPRESDIV_MASK);
    (base->EPRS) |= FLEXCAN_EPRS_ENPRESDIV(timeSeg->preDivider);
}

/*!
 * @brief Get the FlexCAN Enhanced time segments for nominal bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
static inline void FlexCAN_GetEnhancedNominalTimeSegments(const FLEXCAN_Type * base, Flexcan_Ip_TimeSegmentType * timeSeg)
{
    timeSeg->propSeg = 0;
    timeSeg->preDivider = ((base->EPRS & FLEXCAN_EPRS_ENPRESDIV_MASK) >> FLEXCAN_EPRS_ENPRESDIV_SHIFT);
    timeSeg->phaseSeg1 = ((base->ENCBT & FLEXCAN_ENCBT_NTSEG1_MASK) >> FLEXCAN_ENCBT_NTSEG1_SHIFT);
    timeSeg->phaseSeg2 = ((base->ENCBT & FLEXCAN_ENCBT_NTSEG2_MASK) >> FLEXCAN_ENCBT_NTSEG2_SHIFT);
    timeSeg->rJumpwidth = ((base->ENCBT & FLEXCAN_ENCBT_NRJW_MASK) >> FLEXCAN_ENCBT_NRJW_SHIFT);
}

/*!
 * @brief Sets the FlexCAN Enhanced time segments for setting up data bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments, which need to be set for the bit rate.
 */
static inline void FlexCAN_SetEnhancedDataTimeSegments(FLEXCAN_Type * base, const Flexcan_Ip_TimeSegmentType * timeSeg)
{
#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
DevAssert(timeSeg != NULL_PTR);
#endif
(base->EDCBT) = ((base->EDCBT) & ~(FLEXCAN_EDCBT_DTSEG1_MASK | FLEXCAN_EDCBT_DTSEG2_MASK | FLEXCAN_EDCBT_DRJW_MASK));

(base->EDCBT) = ((base->EDCBT) | (FLEXCAN_EDCBT_DTSEG1(timeSeg->phaseSeg1 + timeSeg->propSeg) |
                                  FLEXCAN_EDCBT_DTSEG2(timeSeg->phaseSeg2) |
                                  FLEXCAN_EDCBT_DRJW(timeSeg->rJumpwidth)
                                 )
                );

(base->EPRS) = (base->EPRS & ~FLEXCAN_EPRS_EDPRESDIV_MASK);
(base->EPRS) |= FLEXCAN_EPRS_EDPRESDIV(timeSeg->preDivider);
}
/*!
 * @brief Get the FlexCAN Enhanced time segments.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments read for bit rate
 */
static inline void FlexCAN_GetEnhancedDataTimeSegments(const FLEXCAN_Type * base, Flexcan_Ip_TimeSegmentType * timeSeg)
{
#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
DevAssert(timeSeg != NULL_PTR);
#endif
timeSeg->propSeg = 0U;
timeSeg->phaseSeg1 = ((base->EDCBT & FLEXCAN_EDCBT_DTSEG1_MASK) >> FLEXCAN_EDCBT_DTSEG1_SHIFT);
timeSeg->phaseSeg2 = ((base->EDCBT & FLEXCAN_EDCBT_DTSEG2_MASK) >> FLEXCAN_EDCBT_DTSEG2_SHIFT);
timeSeg->rJumpwidth = ((base->EDCBT & FLEXCAN_EDCBT_DRJW_MASK) >> FLEXCAN_EDCBT_DRJW_SHIFT);
timeSeg->preDivider = ((base->EPRS & FLEXCAN_EPRS_EDPRESDIV_MASK) >> FLEXCAN_EPRS_EDPRESDIV_SHIFT);
}
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCE_CBT == STD_ON) */

/*!
 * @brief Gets the FlexCAN extended time segments used for setting up bit rate.
 *
 * @param[in]   base The FlexCAN base address
 * @param[out]   timeSeg    FlexCAN time segments read for bit rate
 */
static inline void FlexCAN_GetExtendedTimeSegments(const FLEXCAN_Type * base, Flexcan_Ip_TimeSegmentType * timeSeg)
{
    timeSeg->preDivider = ((base->CBT) & FLEXCAN_CBT_EPRESDIV_MASK) >> FLEXCAN_CBT_EPRESDIV_SHIFT;
    timeSeg->propSeg = ((base->CBT) & FLEXCAN_CBT_EPROPSEG_MASK) >> FLEXCAN_CBT_EPROPSEG_SHIFT;
    timeSeg->phaseSeg1 = ((base->CBT) & FLEXCAN_CBT_EPSEG1_MASK) >> FLEXCAN_CBT_EPSEG1_SHIFT;
    timeSeg->phaseSeg2 = ((base->CBT) & FLEXCAN_CBT_EPSEG2_MASK) >> FLEXCAN_CBT_EPSEG2_SHIFT;
    timeSeg->rJumpwidth = ((base->CBT) & FLEXCAN_CBT_ERJW_MASK) >> FLEXCAN_CBT_ERJW_SHIFT;
}

/*!
 * @brief Gets the FlexCAN time segments to calculate the bit rate.
 *
 * @param[in]   base The FlexCAN base address
 * @param[out]   timeSeg    FlexCAN time segments read for bit rate
 */
static inline void FlexCAN_GetTimeSegments(const FLEXCAN_Type * base, Flexcan_Ip_TimeSegmentType * timeSeg)
{
    timeSeg->preDivider = ((base->CTRL1) & FLEXCAN_CTRL1_PRESDIV_MASK) >> FLEXCAN_CTRL1_PRESDIV_SHIFT;
    timeSeg->propSeg = ((base->CTRL1) & FLEXCAN_CTRL1_PROPSEG_MASK) >> FLEXCAN_CTRL1_PROPSEG_SHIFT;
    timeSeg->phaseSeg1 = ((base->CTRL1) & FLEXCAN_CTRL1_PSEG1_MASK) >> FLEXCAN_CTRL1_PSEG1_SHIFT;
    timeSeg->phaseSeg2 = ((base->CTRL1) & FLEXCAN_CTRL1_PSEG2_MASK) >> FLEXCAN_CTRL1_PSEG2_SHIFT;
    timeSeg->rJumpwidth = ((base->CTRL1) & FLEXCAN_CTRL1_RJW_MASK) >> FLEXCAN_CTRL1_RJW_SHIFT;
}

#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
/*!
 * @brief Gets the  FlexCAN time segments for FD BRS to calculate the bit rate.
 *
 * @param   base The FlexCAN base address
 * @param   timeSeg    FlexCAN time segments read for bit rate
 */
static inline void FlexCAN_GetFDTimeSegments(const FLEXCAN_Type * base, Flexcan_Ip_TimeSegmentType * timeSeg)
{
    timeSeg->preDivider = ((base->FDCBT) & FLEXCAN_FDCBT_FPRESDIV_MASK) >> FLEXCAN_FDCBT_FPRESDIV_SHIFT;
    timeSeg->propSeg = ((base->FDCBT) & FLEXCAN_FDCBT_FPROPSEG_MASK) >> FLEXCAN_FDCBT_FPROPSEG_SHIFT;
    timeSeg->phaseSeg1 = ((base->FDCBT) & FLEXCAN_FDCBT_FPSEG1_MASK) >> FLEXCAN_FDCBT_FPSEG1_SHIFT;
    timeSeg->phaseSeg2 = ((base->FDCBT) & FLEXCAN_FDCBT_FPSEG2_MASK) >> FLEXCAN_FDCBT_FPSEG2_SHIFT;
    timeSeg->rJumpwidth = ((base->FDCBT) & FLEXCAN_FDCBT_FRJW_MASK) >> FLEXCAN_FDCBT_FRJW_SHIFT;
}

#endif /* if FLEXCAN_IP_FEATURE_HAS_FD */

/*!
 * @brief Checks if the Extended Time Segment are enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
static inline boolean FlexCAN_IsExCbtEnabled(const FLEXCAN_Type * pBase)
{
    return (0U == ((pBase->CBT & FLEXCAN_CBT_BTF_MASK) >> FLEXCAN_CBT_BTF_SHIFT)) ? FALSE : TRUE;
}

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCE_CBT == STD_ON)
/*!
 * @brief Checks if the Enhanced Time Segment are enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
static inline boolean FlexCAN_IsEnhCbtEnabled(const FLEXCAN_Type * pBase)
{
    return (0U == ((pBase->CTRL2 & FLEXCAN_CTRL2_BTE_MASK) >> FLEXCAN_CTRL2_BTE_SHIFT)) ? FALSE : TRUE;
}

/*!
 * @brief Set the Enhanced Time Segment are enabled or disabled.
 *
 * @param   base    The FlexCAN base address
 * @param   enableCBT Enable/Disable use of Enhanced Time Segments
 */
static inline void FlexCAN_EnhCbtEnable(FLEXCAN_Type * base, boolean enableCBT)
{   /* Enable the use of extended bit time definitions */
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_BTE_MASK) | FLEXCAN_CTRL2_BTE(enableCBT ? 1UL : 0UL);
}
#endif
/*!
 * @brief Set the Extended Time Segment are enabled or disabled.
 *
 * @param   base    The FlexCAN base address
 * @param   enableCBT Enable/Disable use of Extent Time Segments
 */
static inline void FlexCAN_EnableExtCbt(FLEXCAN_Type * base, boolean enableCBT)
{   /* Enable the use of extended bit time definitions */
    base->CBT = (base->CBT & ~FLEXCAN_CBT_BTF_MASK) | FLEXCAN_CBT_BTF(enableCBT ? 1UL : 0UL);
}

/*!
 * @brief Set operation mode.
 *
 * @param   base  The FlexCAN base address
 * @param   mode  Set an operation mode
 */
void FlexCAN_SetOperationMode(FLEXCAN_Type * base, Flexcan_Ip_ModesType mode);


/*!
 * @brief Enables/Disables the Self Reception feature.
 *
 * If enabled, FlexCAN is allowed to receive frames transmitted by itself.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable Self Reception
 */
static inline void FlexCAN_SetSelfReception(FLEXCAN_Type * base, boolean enable)
{
    base->MCR = (base->MCR & ~FLEXCAN_MCR_SRXDIS_MASK) | FLEXCAN_MCR_SRXDIS(enable ? 0UL : 1UL);
}

/*!
 * @brief Checks if the Flexible Data rate feature is enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
static inline boolean FlexCAN_IsFDEnabled(const FLEXCAN_Type * base)
{
    return ((base->MCR & FLEXCAN_MCR_FDEN_MASK) >> FLEXCAN_MCR_FDEN_SHIFT) != 0U;
}

/*!
 * @brief Checks if the listen only mode is enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
static inline boolean FlexCAN_IsListenOnlyModeEnabled(const FLEXCAN_Type * base)
{
    return (((base->CTRL1 & (FLEXCAN_CTRL1_LOM_MASK)) != 0U) ? TRUE : FALSE);
}


/*!
 * @brief Return last Message Buffer Occupied By RxFIFO
 *
 * @param   x    Number of Configured RxFIFO Filters
 * @return  number of last MB occupied by RxFIFO
 */
static inline uint32 RxFifoOcuppiedLastMsgBuff(uint8 x)
{
    return 5U + (((((uint32)x) + 1U) * 8U) / 4U);
}

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/*!
 * @brief Computes the maximum payload size (in bytes), given a DLC
 *
 * @param   dlcValue    DLC code from the MB memory.
 * @return  payload size (in bytes)
 */
uint8 FlexCAN_ComputePayloadSize(uint8 dlcValue);
#endif /*(FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

/*!
 * @brief Sets the FlexCAN message buffer fields for transmitting.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer
 * @return  Pointer to the beginning of the MBs space address
 */
volatile uint32 * FlexCAN_GetMsgBuffRegion(const FLEXCAN_Type * base, uint32 msgBuffIdx);

#if (FLEXCAN_IP_FEATURE_SWITCHINGISOMODE == STD_ON)
/*!
 * @brief Enables/Disables FD frame compatible with ISO-FD Frame ISO 11898-1 (2003)
 *
 * The CAN FD protocol has been improved to increase the failure detection capability that was in the original CAN FD protocol,
 * which is also called non-ISO CAN FD, by CAN in Automation (CiA). A three-bit stuff counter and a parity bit have been introduced
 * in the improved CAN FD protocol, now called ISO CAN FD. The CRC calculation has also been modified. All these improvements
 * make the ISO CAN FD protocol incompatible with the non-FD CAN FD protocol.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable ISO FD Compatible mode.
 */
static inline void FlexCAN_SetIsoCan(FLEXCAN_Type * base, boolean enable)
{
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_ISOCANFDEN_MASK) | FLEXCAN_CTRL2_ISOCANFDEN(enable ? 1UL : 0UL);
}
#endif
/*!
 * @brief This bit controls the comparison of IDE and RTR bits within Rx mailbox filters with their corresponding bits
 * in the incoming frame by the matching process. This bit does not affect matching for Legacy Rx FIFO or Enhanced Rx FIFO.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enables/Disables the comparison of both Rx mailbox filter’s IDE and RTR bit with their corresponding
 * bits within the incoming frame.
 */
static inline void FlexCAN_SetEntireFrameArbitrationFieldComparison(FLEXCAN_Type * base, boolean enable)
{
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_EACEN_MASK) | FLEXCAN_CTRL2_EACEN(enable ? 1UL : 0UL);
}
#if (FLEXCAN_IP_FEATURE_PROTOCOLEXCEPTION == STD_ON)
/*!
 * @brief Enables/Disable the protocol exception feature
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enables/Disable the protocol exception feature.
 */
static inline void FlexCAN_SetProtocolException(FLEXCAN_Type * base, boolean enable)
{
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_PREXCEN_MASK) | FLEXCAN_CTRL2_PREXCEN(enable ? 1UL : 0UL);
}
#endif
/*!
 * @brief If this bit is asserted a remote request frame is submitted to a matching process and stored in the
 * corresponding message buffer in the same fashion as a data frame. No automatic remote response frame will be generated.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable Remote Request Storing.
 */
static inline void FlexCAN_SetRemoteReqStore(FLEXCAN_Type * base, boolean enable)
{
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_RRS_MASK) | FLEXCAN_CTRL2_RRS(enable ? 1UL : 0UL);
}
/*!
 * @brief Enable/Disable Automatic recovering from Bus Off state
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable Automatic recovering from Bus Off state.
 */
static inline void FlexCAN_SetBusOffAutorecovery(FLEXCAN_Type * base, boolean enable)
{
    base->CTRL1 = (base->CTRL1 & ~FLEXCAN_CTRL1_BOFFREC_MASK) | FLEXCAN_CTRL1_BOFFREC(enable ? 0UL : 1UL);
}
#if (FLEXCAN_IP_FEATURE_EDGEFILTER == STD_ON)
/*!
 * @brief Enable/Disable the edge filter used during the bus integration state.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable the edge filter used during the bus integration state.
 */
static inline void FlexCAN_SetEdgeFilter(FLEXCAN_Type * base, boolean enable)
{
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_EDFLTDIS_MASK) | FLEXCAN_CTRL2_EDFLTDIS(enable ? 0UL : 1UL);
}
#endif
/*!
 * @brief Enable/Disable the sampling mode of CAN bits at the Rx input.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Enable/Disable the sampling mode of CAN bits at the Rx input.
 */
static inline void FlexCAN_CanBitSampling(FLEXCAN_Type * base, boolean enable)
{
    base->CTRL1 = (base->CTRL1 & ~FLEXCAN_CTRL1_SMP_MASK) | FLEXCAN_CTRL1_SMP(enable ? 1UL : 0UL);
}
#if (FLEXCAN_IP_FEATURE_HAS_PE_CLKSRC_SELECT == STD_ON)
/*!
 * @brief Specifies if The CAN engine clock source is the oscillator clock or peripheral clock.
 *
 * @param   base  The FlexCAN base address
 * @param   enable Specifies if The CAN engine clock source is the oscillator clock(FALSE) or peripheral clock(TRUE).
 */
static inline void FlexCAN_SetClkSrc(FLEXCAN_Type * base, boolean enable)
{
    base->CTRL1 = (base->CTRL1 & ~FLEXCAN_CTRL1_CLKSRC_MASK) | FLEXCAN_CTRL1_CLKSRC(enable ? 1UL : 0UL);
}
#endif

/*!
 * @brief Gets the individual FlexCAN MB interrupt flag.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer
 * @return  the individual Message Buffer interrupt flag (0 and 1 are the flag value)
 */
static inline uint8 FlexCAN_GetMsgBuffIntStatusFlag(const FLEXCAN_Type * base, uint32 msgBuffIdx)
{
    /* TODO: This need to be protected multithread access*/
    uint8 flag = 0;
    uint32 mask;

    if (msgBuffIdx < 32U)
    {
        mask = base->IMASK1 & FLEXCAN_IMASK1_BUF31TO0M_MASK;
        flag = (uint8)(((base->IFLAG1 & mask) >> (msgBuffIdx % 32U)) & 1U);
    }

#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U
    else if (msgBuffIdx < 64U)
    {
        mask = base->IMASK2 & FLEXCAN_IMASK2_BUF63TO32M_MASK;
        flag = (uint8)(((base->IFLAG2 & mask) >> (msgBuffIdx % 32U)) & 1U);
    }
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 64U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif
#endif /* if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U */
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U
    else if (msgBuffIdx < 96U)
    {
        mask = base->IMASK3 & FLEXCAN_IMASK3_BUF95TO64M_MASK;
        flag = (uint8)(((base->IFLAG3 & mask) >> (msgBuffIdx % 32U)) & 1U);
    }
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM <= 96U
    else
    {
        /* Required Rule 15.7, no 'else' at end of 'if ... else if' chain */
    }
#endif
#endif /* if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U */
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U
    else
    {
        mask = base->IMASK4 & FLEXCAN_IMASK4_BUF127TO96M_MASK;
        flag = (uint8)(((base->IFLAG4 & mask) >> (msgBuffIdx % 32U)) & 1U);
    }
#endif

    return flag;
}

/*!
 * @brief Sets the FlexCAN Rx Message Buffer global mask.
 *
 * @param   base  The FlexCAN base address
 * @param   Mask  Mask Value
 */
static inline void FlexCAN_SetRxMsgBuffGlobalMask(FLEXCAN_Type * base, uint32 Mask)
{
    (base->RXMGMASK) = Mask;
}

/*!
 * @brief Sets the FlexCAN Rx individual mask for ID filtering in the Rx Message Buffers and the Rx FIFO.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer/filter
 * @param   mask     Individual mask
 */
static inline void FlexCAN_SetRxIndividualMask(FLEXCAN_Type * base,
                                               uint32 msgBuffIdx,
                                               uint32 mask
                                              )
{
    base->RXIMR[msgBuffIdx] = mask;
}

/*!
 * @brief Check if controller is in freeze mode or not.
 *
 * @param   base  The FlexCAN base address
 * @return  TRUE if controller is in freeze mode
 *          FALSE if controller is not in freeze mode
 */
static inline boolean FlexCAN_IsFreezeMode(const FLEXCAN_Type * base)
{
    return (((base->MCR & (FLEXCAN_MCR_FRZACK_MASK)) != 0U)? TRUE : FALSE);
}

/*!
 * @brief Set Tx arbitration start delay.
 *
 * @param   base  The FlexCAN base address
 * @param   tasd  The Tx arbitration start delay value
 */
static inline void FlexCAN_SetTxArbitrationStartDelay(FLEXCAN_Type * base, uint8 tasd)
{
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_TASD_MASK) | FLEXCAN_CTRL2_TASD(tasd);
}

/*!
 * @brief Sets the Rx masking type.
 *
 * @param   base  The FlexCAN base address
 * @param   type         The FlexCAN Rx mask type
 */
static inline void FlexCAN_SetRxMaskType(FLEXCAN_Type * base, Flexcan_Ip_RxMaskType type)
{
    /* Set RX masking type (RX global mask or RX individual mask)*/
    if (FLEXCAN_RX_MASK_GLOBAL == type)
    {
        /* Enable Global RX masking */
        base->MCR = (base->MCR & ~FLEXCAN_MCR_IRMQ_MASK) | FLEXCAN_MCR_IRMQ(0U);
    }
    else
    {
        /* Enable Individual Rx Masking and Queue */
        base->MCR = (base->MCR & ~FLEXCAN_MCR_IRMQ_MASK) | FLEXCAN_MCR_IRMQ(1U);
    }
}

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/*!
 * @brief Checks if Enhanced Rx FIFO is enabled.
 *
 * @param   base     The FlexCAN base address
 * @return  EnhancedRxFifo status (true = enabled / false = disabled)
 */
static inline boolean FlexCAN_IsEnhancedRxFifoEnabled(const FLEXCAN_Type * base)
{
    return ((((base->ERFCR & FLEXCAN_ERFCR_ERFEN_MASK) >> FLEXCAN_ERFCR_ERFEN_SHIFT) != 0U) ? (TRUE): (FALSE));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_SetEnhancedRxFifoIntAll
 * Description   : Enable/Disable All(Underflow, Overflow, Watermark and frame available)
 *                 interrupts for Enhanced Rx FIFO.
 *
 *END**************************************************************************/
static inline void FlexCAN_SetEnhancedRxFifoIntAll(FLEXCAN_Type * base, boolean enable)
{
    if (TRUE == enable)
    {
        (base->ERFIER) = (uint32)(FLEXCAN_IP_ENHACED_RX_FIFO_ALL_INTERRUPT_MASK);
    }
    else
    {
        (base->ERFIER) = (uint32)(FLEXCAN_IP_ENHACED_RX_FIFO_NO_INTERRUPT_MASK);
    }
}

/*!
 * @brief Gets the individual FlexCAN Enhanced Rx FIFO flag.
 *
 * @param   base        The FlexCAN base address
 * @param   intFlag     Index of the Enhanced Rx FIFO flag
 * @return  the individual Enhanced Rx FIFO flag (0 and 1 are the flag value)
 */
static inline uint8 FlexCAN_GetEnhancedRxFIFOStatusFlag(const FLEXCAN_Type * base, uint32 intFlag)
{
    return (uint8)((base->ERFSR & ((uint32)1U << ((uint8)intFlag & (uint8)0x1F))) >> ((uint8)intFlag & (uint8)0x1F));
}

/*!
 * @brief Clears the interrupt flag of the Enhanced Rx FIFO.
 *
 * @param   base  The FlexCAN base address
 * @param   intFlag       Index of the Enhanced Rx FIFO interrupt flag
 */
static inline void FlexCAN_ClearEnhancedRxFifoIntStatusFlag(FLEXCAN_Type * base, uint32 intFlag)
{
    (base->ERFSR) = (uint32)1U << intFlag;
}

/*!
 * @brief Gets the individual FlexCAN Enhanced Rx FIFO interrupt flag.
 *
 * @param   base        The FlexCAN base address
 * @param   intFlag     Index of the Enhanced Rx FIFO interrupt flag
 * @return  the individual Enhanced Rx FIFO interrupt flag (0 and 1 are the flag value)
 */
static inline uint8 FlexCAN_GetEnhancedRxFIFOIntStatusFlag(const FLEXCAN_Type * base, uint32 intFlag)
{
    return (uint8)((base->ERFIER & ((uint32)1U << ((uint8)intFlag & (uint8)0x1F))) >> ((uint8)intFlag & (uint8)0x1F));
}
/*!
 * @brief Checks if FlexCAN has Enhanced Rx FIFO.
 *
 * @param   base  The FlexCAN base address
 * @return  EnhancedRxFifo status (TRUE = available / FALSE = unavailable)
 */
boolean FlexCAN_IsEnhancedRxFifoAvailable(const FLEXCAN_Type * base);

Flexcan_Ip_StatusType FlexCAN_EnableEnhancedRxFifo(FLEXCAN_Type * base,
                                                   uint32 numOfStdIDFilters,
                                                   uint32 numOfExtIDFilters,
                                                   uint32 numOfWatermark
                                                  );
void FlexCAN_SetEnhancedRxFifoFilter(const uint8 u8Instance, const Flexcan_Ip_EnhancedIdTableType * idFilterTable);

#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
/*!
 * @brief Clear Enhance fifo data.
 *
 * @param   base  The FlexCAN base address
 * @return  void
 */
void FlexCAN_ClearOutputEnhanceFIFO(FLEXCAN_Type * base);
#endif /* (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON) */

void FlexCAN_ReadEnhancedRxFifo(const uint8 u8Instance, Flexcan_Ip_MsgBuffType * rxFifo);
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */
#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
/*!
 * @brief Clear Legacy fifo data.
 *
 * @param   base  The FlexCAN base address
 * @return  void
 */
void FlexCAN_ClearOutputLegacyFIFO(FLEXCAN_Type * base);
#endif /* FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE */

#if (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)

void FlexCAN_ConfigTimestamp(uint8 instance, FLEXCAN_Type * base, const Flexcan_Ip_TimeStampConfigType * config);

#if (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON)
/*!
 * @brief Checks if High Resolution Time Stamp is enabled.
 *
 * @param   base     The FlexCAN base address
 * @return  HRTimeStamp status (true = enabled / false = disabled)
 */
static inline boolean FLEXCAN_IsHRTimeStampEnabled(const FLEXCAN_Type * base)
{
    return ((((base->CTRL2 & FLEXCAN_CTRL2_TSTAMPCAP_MASK) >> FLEXCAN_CTRL2_TSTAMPCAP_SHIFT) != 0U) ? TRUE : FALSE);
}
#endif /*(FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON) */
#endif /* #if (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON) */
/*!
 * @brief configure controller depending on options.
 *
 * @param   pBase          The FlexCAN base address.
 * @param   u32Options     Controller Options.
 */
void FlexCAN_ConfigCtrlOptions(FLEXCAN_Type * pBase, uint32 u32Options);

/*!
 * @brief Will set Flexcan Peripheral Register to default val.
 *
 * @param   base    The FlexCAN base address
 */
static inline void FlexCAN_SetRegDefaultVal(FLEXCAN_Type * base)
{
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    if (TRUE == FlexCAN_IsEnhancedRxFifoAvailable(base))
    {
        base->ERFSR = FLEXCAN_IP_ERFSR_DEFAULT_VALUE_U32;
        base->ERFIER = FLEXCAN_IP_ERFIER_DEFAULT_VALUE_U32;
        base->ERFCR = FLEXCAN_IP_ERFCR_DEFAULT_VALUE_U32;
    }
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
    #if defined(CAN_FEATURE_S32K1XX)
    if (TRUE == FlexCAN_IsFDAvailable(base))
    {
    #endif /* defined(CAN_FEATURE_S32K1XX) */
        base->FDCBT = FLEXCAN_IP_FDCBT_DEFAULT_VALUE_U32;
        base->FDCTRL = FLEXCAN_IP_FDCTRL_DEFAULT_VALUE_U32;
    #if defined(CAN_FEATURE_S32K1XX)
    }
    #endif /* defined(CAN_FEATURE_S32K1XX) */
#endif /* (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON) */
#if (FLEXCAN_IP_FEATURE_HAS_MEM_ERR_DET == STD_ON)
    base->ERRSR = FLEXCAN_IP_ERRSR_DEFAULT_VALUE_U32;
    base->ERRIPPR = FLEXCAN_IP_ERRIPPR_DEFAULT_VALUE_U32;
    base->ERRIDPR = FLEXCAN_IP_ERRIDPR_DEFAULT_VALUE_U32;
    base->ERRIAR = FLEXCAN_IP_ERRIAR_DEFAULT_VALUE_U32;
    /* Enable write of MECR register */
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_ECRWRE_MASK) | FLEXCAN_CTRL2_ECRWRE(1);
    /* Enable write of MECR */
    base->MECR = (base->MECR & ~FLEXCAN_MECR_ECRWRDIS_MASK) | FLEXCAN_MECR_ECRWRDIS(0);
    /* set Default value */
    base->MECR = FLEXCAN_IP_MECR_DEFAULT_VALUE_U32;
    /* disable write of MECR */
    base->MECR = (base->MECR & ~FLEXCAN_MECR_ECRWRDIS_MASK) | FLEXCAN_MECR_ECRWRDIS(1);
    /* Disable write of MECR */
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_ECRWRE_MASK) | FLEXCAN_CTRL2_ECRWRE(0);
#endif /* (FLEXCAN_IP_FEATURE_HAS_MEM_ERR_DET == STD_ON) */
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U)
    if (FlexCAN_GetMaxMbNum(base) > 96U)
    {
        base->IFLAG4 = FLEXCAN_IP_IFLAG_DEFAULT_VALUE_U32;
        base->IMASK4 = FLEXCAN_IP_IMASK_DEFAULT_VALUE_U32;
    }
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U) */
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U)
    if (FlexCAN_GetMaxMbNum(base) > 64U)
    {
        base->IFLAG3 = FLEXCAN_IP_IFLAG_DEFAULT_VALUE_U32;
        base->IMASK3 = FLEXCAN_IP_IMASK_DEFAULT_VALUE_U32;
    }
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U) */
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U)
    if (FlexCAN_GetMaxMbNum(base) > 32U)
    {
        base->IFLAG2 = FLEXCAN_IP_IFLAG_DEFAULT_VALUE_U32;
        base->IMASK2 = FLEXCAN_IP_IMASK_DEFAULT_VALUE_U32;
    }
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U) */
    base->IFLAG1 = FLEXCAN_IP_IFLAG_DEFAULT_VALUE_U32;
    base->IMASK1 = FLEXCAN_IP_IMASK_DEFAULT_VALUE_U32;
    base->CBT = FLEXCAN_IP_CBT_DEFAULT_VALUE_U32;
    base->CTRL2 = FLEXCAN_IP_CTRL2_DEFAULT_VALUE_U32;
    base->ESR1 = FLEXCAN_IP_ESR1_DEFAULT_VALUE_U32;
    base->ECR = FLEXCAN_IP_ECR_DEFAULT_VALUE_U32;
    base->TIMER = FLEXCAN_IP_TIMER_DEFAULT_VALUE_U32;
    base->CTRL1 = FLEXCAN_IP_CTRL1_DEFAULT_VALUE_U32;
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCE_CBT == STD_ON)
    base->EPRS  = FLEXCAN_IP_EPRS_DEFAULT_VALUE_U32;
    base->ENCBT = FLEXCAN_IP_ENCBT_DEFAULT_VALUE_U32;
    base->EDCBT = FLEXCAN_IP_EDCBT_DEFAULT_VALUE_U32;
    base->ETDC  = FLEXCAN_IP_ETDC_DEFAULT_VALUE_U32;
#endif
    base->MCR = FLEXCAN_IP_MCR_DEFAULT_VALUE_U32;
}

#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/*!
 * @brief Configures Pretended Networking mode filtering selection.
 *
 * @param   pBase  The FlexCAN base address
 * @param   pPnConfig The pretended networking configuration
 *
 */
static inline void FlexCAN_SetPNFilteringSelection(FLEXCAN_Type * pBase, const Flexcan_Ip_PnConfigType * pPnConfig)
{
    uint32 u32Tmp;

    u32Tmp = pBase->CTRL1_PN;
    u32Tmp &= ~(FLEXCAN_CTRL1_PN_WTOF_MSK_MASK |
             FLEXCAN_CTRL1_PN_WUMF_MSK_MASK |
             FLEXCAN_CTRL1_PN_NMATCH_MASK |
             FLEXCAN_CTRL1_PN_PLFS_MASK |
             FLEXCAN_CTRL1_PN_IDFS_MASK |
             FLEXCAN_CTRL1_PN_FCS_MASK);
    u32Tmp |= FLEXCAN_CTRL1_PN_WTOF_MSK(pPnConfig->bWakeUpTimeout ? 1UL : 0UL);
    u32Tmp |= FLEXCAN_CTRL1_PN_WUMF_MSK(pPnConfig->bWakeUpMatch ? 1UL : 0UL);
    u32Tmp |= FLEXCAN_CTRL1_PN_NMATCH(pPnConfig->u16NumMatches);
    u32Tmp |= FLEXCAN_CTRL1_PN_FCS(pPnConfig->eFilterComb);
    u32Tmp |= FLEXCAN_CTRL1_PN_IDFS(pPnConfig->eIdFilterType);
    u32Tmp |= FLEXCAN_CTRL1_PN_PLFS(pPnConfig->ePayloadFilterType);
    pBase->CTRL1_PN = u32Tmp;
}

/*!
 * @brief Set PN timeout value.
 *
 * @param   pBase  The FlexCAN base address
 * @param   u16TimeoutValue  timeout for no message matching
 */
static inline void FlexCAN_SetPNTimeoutValue(FLEXCAN_Type * pBase, uint16 u16TimeoutValue)
{
    pBase->CTRL2_PN = (pBase->CTRL2_PN & ~FLEXCAN_CTRL2_PN_MATCHTO_MASK) | FLEXCAN_CTRL2_PN_MATCHTO(u16TimeoutValue);
}

/*!
 * @brief Configures the Pretended Networking ID Filter 1.
 *
 * @param   pBase  The FlexCAN base address
 * @param   idFilter  The ID Filter configuration
 */
static inline void FlexCAN_SetPNIdFilter1(FLEXCAN_Type * pBase, Flexcan_Ip_PnIdFilterType idFilter)
{
    uint32 u32Tmp;

    u32Tmp = pBase->FLT_ID1;
    u32Tmp &= ~(FLEXCAN_FLT_ID1_FLT_IDE_MASK | FLEXCAN_FLT_ID1_FLT_RTR_MASK | FLEXCAN_FLT_ID1_FLT_ID1_MASK);
    u32Tmp |= FLEXCAN_FLT_ID1_FLT_IDE(idFilter.bExtendedId ? 1UL : 0UL);
    u32Tmp |= FLEXCAN_FLT_ID1_FLT_RTR(idFilter.bRemoteFrame ? 1UL : 0UL);
    if (idFilter.bExtendedId)
    {
        u32Tmp |= FLEXCAN_FLT_ID1_FLT_ID1(idFilter.u32Id);
    }
    else
    {
        u32Tmp |= FLEXCAN_FLT_ID1_FLT_ID1(idFilter.u32Id << FLEXCAN_IP_ID_STD_SHIFT);
    }

    pBase->FLT_ID1 = u32Tmp;
}

/*!
 * @brief Configures the Pretended Networking ID Filter 2 Check IDE&RTR.
 *
 * @param   pBase  The FlexCAN base address

 */
static inline void FlexCAN_SetPNIdFilter2Check(FLEXCAN_Type * pBase)
{
    pBase->FLT_ID2_IDMASK |= FLEXCAN_FLT_ID2_IDMASK_IDE_MSK_MASK | FLEXCAN_FLT_ID2_IDMASK_RTR_MSK_MASK;
}
/*!
 * @brief Configures the Pretended Networking ID Filter 2.
 *
 * @param   pBase  The FlexCAN base address
 * @param   pPnConfig  The pretended networking configuration
 */
static inline void FlexCAN_SetPNIdFilter2(FLEXCAN_Type * pBase, const Flexcan_Ip_PnConfigType * pPnConfig)
{
    uint32 u32Tmp;

    u32Tmp = pBase->FLT_ID2_IDMASK;
    u32Tmp &= ~(FLEXCAN_FLT_ID2_IDMASK_IDE_MSK_MASK | FLEXCAN_FLT_ID2_IDMASK_RTR_MSK_MASK | FLEXCAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK_MASK);
    u32Tmp |= FLEXCAN_FLT_ID2_IDMASK_IDE_MSK(pPnConfig->idFilter2.bExtendedId ? 1UL : 0UL);
    u32Tmp |= FLEXCAN_FLT_ID2_IDMASK_RTR_MSK(pPnConfig->idFilter2.bRemoteFrame ? 1UL : 0UL);
    /* Check if idFilter1 is extended and apply accordingly mask */
    if (pPnConfig->idFilter1.bExtendedId)
    {
        u32Tmp |= FLEXCAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK(pPnConfig->idFilter2.u32Id);
    }
    else
    {
        u32Tmp |= FLEXCAN_FLT_ID2_IDMASK_FLT_ID2_IDMASK(pPnConfig->idFilter2.u32Id << FLEXCAN_IP_ID_STD_SHIFT);
    }

    pBase->FLT_ID2_IDMASK = u32Tmp;
}


/*!
 * @brief Set PN DLC Filter.
 *
 * @param   pBase  The FlexCAN base address
 * @param   timeoutValue  timeout for no message matching
 */
static inline void FlexCAN_SetPNDlcFilter(FLEXCAN_Type * pBase,
                                          uint8 u8DlcLow,
                                          uint8 u8DlcHigh
                                         )
{
    uint32 tmp;

    tmp = pBase->FLT_DLC;
    tmp &= ~(FLEXCAN_FLT_DLC_FLT_DLC_LO_MASK | FLEXCAN_FLT_DLC_FLT_DLC_HI_MASK);
    tmp |= FLEXCAN_FLT_DLC_FLT_DLC_HI(u8DlcHigh);
    tmp |= FLEXCAN_FLT_DLC_FLT_DLC_LO(u8DlcLow);
    pBase->FLT_DLC = tmp;
}

/*!
 * @brief Set PN Payload High Filter 1.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   pPayload  message Payload filter
 */
static inline void FlexCAN_SetPNPayloadHighFilter1(FLEXCAN_Type * pBase, const uint8 * pPayload)
{
    pBase->PL1_HI = FLEXCAN_PL1_HI_Data_byte_4(pPayload[4]) |
                   FLEXCAN_PL1_HI_Data_byte_5(pPayload[5]) |
                   FLEXCAN_PL1_HI_Data_byte_6(pPayload[6]) |
                   FLEXCAN_PL1_HI_Data_byte_7(pPayload[7]);
}

/*!
 * @brief Set PN Payload Low Filter 1.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   pPayload  message Payload filter
 */
static inline void FlexCAN_SetPNPayloadLowFilter1(FLEXCAN_Type * pBase, const uint8 * pPayload)
{
    pBase->PL1_LO = FLEXCAN_PL1_LO_Data_byte_0(pPayload[0]) |
                   FLEXCAN_PL1_LO_Data_byte_1(pPayload[1]) |
                   FLEXCAN_PL1_LO_Data_byte_2(pPayload[2]) |
                   FLEXCAN_PL1_LO_Data_byte_3(pPayload[3]);
}

/*!
 * @brief Set PN Payload High Filter 2.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   pPayload  message Payload filter
 */
static inline void FlexCAN_SetPNPayloadHighFilter2(FLEXCAN_Type * pBase, const uint8 * pPayload)
{
    pBase->PL2_PLMASK_HI = FLEXCAN_PL2_PLMASK_HI_Data_byte_4(pPayload[4]) |
                          FLEXCAN_PL2_PLMASK_HI_Data_byte_5(pPayload[5]) |
                          FLEXCAN_PL2_PLMASK_HI_Data_byte_6(pPayload[6]) |
                          FLEXCAN_PL2_PLMASK_HI_Data_byte_7(pPayload[7]);
}

/*!
 * @brief Set PN Payload Low Filter 2.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   pPayload  message Payload filter
 */
static inline void FlexCAN_SetPNPayloadLowFilter2(FLEXCAN_Type * pBase, const uint8 * pPayload)
{
    pBase->PL2_PLMASK_LO = FLEXCAN_PL2_PLMASK_LO_Data_byte_0(pPayload[0]) |
                          FLEXCAN_PL2_PLMASK_LO_Data_byte_1(pPayload[1]) |
                          FLEXCAN_PL2_PLMASK_LO_Data_byte_2(pPayload[2]) |
                          FLEXCAN_PL2_PLMASK_LO_Data_byte_3(pPayload[3]);
}

/*!
 * @brief Configures the Pretended Networking mode.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   pnConfig  The pretended networking configuration
 */
void FlexCAN_ConfigPN(FLEXCAN_Type * pBase, const Flexcan_Ip_PnConfigType * pPnConfig);

/*!
 * @brief Enables/Disables the Pretended Networking mode.
 *
 * @param   pBase  The FlexCAN Base address
 * @param   enable  Enable/Disable Pretending Networking
 */
static inline void FlexCAN_SetPN(FLEXCAN_Type * pBase, boolean enable)
{
    pBase->MCR = (pBase->MCR & ~FLEXCAN_MCR_PNET_EN_MASK) | FLEXCAN_MCR_PNET_EN(enable ? 1UL : 0UL);
}

/*!
 * @brief Checks if the Pretended Networking mode is enabled/disabled.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  false if Pretended Networking mode is disabled;
 *          true if Pretended Networking mode is enabled
 */
static inline boolean FlexCAN_IsPNEnabled(const FLEXCAN_Type * pBase)
{
    return ((pBase->MCR & FLEXCAN_MCR_PNET_EN_MASK) >> FLEXCAN_MCR_PNET_EN_SHIFT) != 0U;
}

/*!
 * @brief Gets the Wake Up by Timeout Flag Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up by Timeout Flag Bit
 */
static inline uint8 FlexCAN_GetWTOF(const FLEXCAN_Type * pBase)
{
    return (uint8)((pBase->WU_MTC & FLEXCAN_WU_MTC_WTOF_MASK) >> FLEXCAN_WU_MTC_WTOF_SHIFT);
}

/*!
 * @brief Gets the Wake Up Timeout interrupt enable Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up Timeout interrupt enable Bit
 */
static inline uint8 FlexCAN_GetWTOIE(const FLEXCAN_Type * pBase)
{
    return (uint8)((pBase->CTRL1_PN & FLEXCAN_CTRL1_PN_WTOF_MSK_MASK) >> FLEXCAN_CTRL1_PN_WTOF_MSK_SHIFT);
}

/*!
 * @brief Clears the Wake Up by Timeout Flag Bit.
 *
 * @param   pBase  The FlexCAN Base address
 */
static inline void FlexCAN_ClearWTOF(FLEXCAN_Type * pBase)
{
    pBase->WU_MTC = FLEXCAN_WU_MTC_WTOF_MASK;
}

/*!
 * @brief Gets the Wake Up by Match Flag Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up by Match Flag Bit
 */
static inline uint8 FlexCAN_GetWUMF(const FLEXCAN_Type * pBase)
{
    return (uint8)((pBase->WU_MTC & FLEXCAN_WU_MTC_WUMF_MASK) >> FLEXCAN_WU_MTC_WUMF_SHIFT);
}

/*!
 * @brief Gets the Wake Up Match IE Bit.
 *
 * @param   pBase  The FlexCAN Base address
 * @return  the Wake Up Match IE Bit
 */
static inline uint8 FlexCAN_GetWUMIE(const FLEXCAN_Type * pBase)
{
    return (uint8)((pBase->CTRL1_PN & FLEXCAN_CTRL1_PN_WUMF_MSK_MASK) >> FLEXCAN_CTRL1_PN_WUMF_MSK_SHIFT);
}

/*!
 * @brief Clears the Wake Up by Match Flag Bit.
 *
 * @param   pBase  The FlexCAN Base address
 */
static inline void FlexCAN_ClearWUMF(FLEXCAN_Type * pBase)
{
    pBase->WU_MTC = FLEXCAN_WU_MTC_WUMF_MASK;
}

#endif /* FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING */

/*!
 * @brief  Reset Imask Buffers.
 *
 * @param   Instance  The FlexCAN instance
 */
void FlexCAN_ResetImaskBuff(uint8 Instance);

#define CAN_43_FLEXCAN_STOP_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXCAN_FLEXCAN_IP_HWACCESS_H_ */
