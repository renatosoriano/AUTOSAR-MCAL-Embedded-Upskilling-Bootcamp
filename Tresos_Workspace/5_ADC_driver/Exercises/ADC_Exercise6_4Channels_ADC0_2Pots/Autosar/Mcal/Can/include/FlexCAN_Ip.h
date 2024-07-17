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

/* implements FlexCAN_Ip.h_Artifact */
#ifndef FLEXCAN_FLEXCAN_IP_H_
#define FLEXCAN_FLEXCAN_IP_H_

/**
* @file FlexCAN_Ip.h
*
* @brief FlexCAN Ip Driver Header File
* @details FlexCAN Ip Driver Header File contains the APIs and structures exported by FlexCAN Driver
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
#include "Mcal.h"
#include "FlexCAN_Ip_DeviceReg.h"
#include "FlexCAN_Ip_Types.h"
#include "StandardTypes.h"
#include "FlexCAN_Ip_Cfg.h"
#include "FlexCAN_Ip_Wrapper.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_VENDOR_ID_H                      43
#define FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H       7
#define FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H    0
#define FLEXCAN_IP_SW_MAJOR_VERSION_H               2
#define FLEXCAN_IP_SW_MINOR_VERSION_H               0
#define FLEXCAN_IP_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip_DeviceReg header file are of the same vendor */
#if (FLEXCAN_IP_VENDOR_ID_H != FLEXCAN_IP_DEVICEREG_VENDOR_ID_H)
    #error "FlexCAN_Ip.h and FlexCAN_Ip_DeviceReg.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_DeviceReg header file are of the same Autosar version */
#if ((FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_DEVICEREG_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip.h and FlexCAN_Ip_DeviceReg.h are different"
#endif
/* Check if current file and FlexCAN_Ip_DeviceReg header file are of the same Software version */
#if ((FLEXCAN_IP_SW_MAJOR_VERSION_H != FLEXCAN_IP_DEVICEREG_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_SW_MINOR_VERSION_H != FLEXCAN_IP_DEVICEREG_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_SW_PATCH_VERSION_H != FLEXCAN_IP_DEVICEREG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of FlexCAN_Ip.h and FlexCAN_Ip_DeviceReg.h are different"
#endif

/* Check if current file and FlexCAN_Ip_Types header file are of the same vendor */
#if (FLEXCAN_IP_VENDOR_ID_H != FLEXCAN_IP_TYPES_VENDOR_ID_H)
    #error "FlexCAN_Ip.h and FlexCAN_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_Types header file are of the same Autosar version */
#if ((FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip.h and FlexCAN_Ip_Types.h are different"
#endif
/* Check if current file and FlexCAN_Ip_Types header file are of the same Software version */
#if ((FLEXCAN_IP_SW_MAJOR_VERSION_H != FLEXCAN_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_SW_MINOR_VERSION_H != FLEXCAN_IP_TYPES_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_SW_PATCH_VERSION_H != FLEXCAN_IP_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of FlexCAN_Ip.h and FlexCAN_Ip_Types.h are different"
#endif

/* Check if current file and FlexCAN_Ip_Cfg header file are of the same vendor */
#if (FLEXCAN_IP_VENDOR_ID_H != FLEXCAN_IP_CFG_VENDOR_ID_H)
    #error "FlexCAN_Ip.h and FlexCAN_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_Cfg header file are of the same Autosar version */
#if ((FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_CFG_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip.h and FlexCAN_Ip_Cfg.h are different"
#endif
/* Check if current file and FlexCAN_Ip_Cfg header file are of the same Software version */
#if ((FLEXCAN_IP_SW_MAJOR_VERSION_H != FLEXCAN_IP_CFG_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_SW_MINOR_VERSION_H != FLEXCAN_IP_CFG_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_SW_PATCH_VERSION_H != FLEXCAN_IP_CFG_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of FlexCAN_Ip.h and FlexCAN_Ip_Cfg.h are different"
#endif

/* Check if current file and FlexCAN_Ip_Wrapper header file are of the same vendor */
#if (FLEXCAN_IP_VENDOR_ID_H != FLEXCAN_IP_WRAPPER_VENDOR_ID_H)
    #error "FlexCAN_Ip.h and FlexCAN_Ip_Wrapper.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_Wrapper header file are of the same Autosar version */
#if ((FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_WRAPPER_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_WRAPPER_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_WRAPPER_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip.h and FlexCAN_Ip_Wrapper.h are different"
#endif
/* Check if current file and FlexCAN_Ip_Wrapper header file are of the same Software version */
#if ((FLEXCAN_IP_SW_MAJOR_VERSION_H != FLEXCAN_IP_WRAPPER_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_SW_MINOR_VERSION_H != FLEXCAN_IP_WRAPPER_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_SW_PATCH_VERSION_H != FLEXCAN_IP_WRAPPER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of FlexCAN_Ip.h and FlexCAN_Ip_Wrapper.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
#if ((FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H    != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip_DeviceReg.h and StandardTypes.h are different"
#endif
    /* Check if current file and Mcal header file are of the same Autosar version */
#if ((FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H    != MCAL_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip.h and Mcal.h are different"
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define FLEXCAN_IP_MB_HANDLE_RXFIFO     0U
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
#define FLEXCAN_IP_MB_ENHANCED_RXFIFO    255U
#endif /* FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_FLEXCAN_MemMap.h"

/* Calling the external Configuration symbols defined by FlexCAN_Ip_Cfg.h */
FLEXCAN_IP_CONFIG_EXT

#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
FLEXCAN_IP_PN_CONFIG_EXT
#endif

#define CAN_43_FLEXCAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_FLEXCAN_MemMap.h"

#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_FLEXCAN_MemMap.h"

FLEXCAN_IP_STATE_EXT

#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_FLEXCAN_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"
/**
 *  @brief Initializes the FlexCAN peripheral.
 *  @details This function will config FlexCAN module and will leave the module in freeze mode.
 *  @param[in] Flexcan_Ip_u8Instance A FlexCAN instance number
 *  @param[in\out] Flexcan_Ip_pState Pointer to the FlexCAN driver state structure.
 *  @param[in] Flexcan_Ip_pData      The FlexCAN platform configuration data
 *  @return FLEXCAN_STATUS_SUCCESS if successfull;<br>
 *          FLEXCAN_STATUS_ERROR if other error occurred;<br>
 *          FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of a message buffer is invalid;<br>
 *          FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *  @note In case of the enable option of Remote Request Store by setting corresponding bit for FLEXCAN_IP_REM_STORE_U32
 *  in the ctrlOptions structure member of the Flexcan platform configuration data, will disable Automatic Response Request,
 *  in this case is not allowed use of the function FlexCAN_Ip_ConfigRemoteResponseMb
 */
#define FlexCAN_Ip_Init(Flexcan_Ip_u8Instance, Flexcan_Ip_pState, Flexcan_Ip_pData) \
                Call_FlexCAN_Ip_Init(Flexcan_Ip_u8Instance, Flexcan_Ip_pState, Flexcan_Ip_pData)
/**
 *  @brief     Sends a CAN frame using the specified message buffer.
 *  @details   This function configure parameters form Flexcan_Ip_DataInfoType, ID and sends data as CAN frame using a message buffer.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] mb_idx   Index of the message buffer
 *  @param[in] tx_info  Data info
 *  @param[in] msg_id   ID of the message to transmit
 *  @param[in] mb_data  Data Bytes of the FlexCAN message.
 *  @return FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of a message buffer is invalid;<br>
 *          FLEXCAN_STATUS_BUSY if the message buffer is used for other operation;<br>
 *          FLEXCAN_STATUS_SUCCESS if successfull.<br>
 */
Flexcan_Ip_StatusType FlexCAN_Ip_Send(uint8 instance,
                                      uint8 mb_idx,
                                      const Flexcan_Ip_DataInfoType * tx_info,
                                      uint32 msg_id,
                                      const uint8 * mb_data);
/**
 *  @brief     Sends a CAN frame using the specified message buffer, in a blocking manner.
 *  @details   This function sends a CAN frame using a configured message buffer. The function
 *             blocks until either the frame was sent, or the specified timeout expired.
 *  @param[in] instance   A FlexCAN instance number
 *  @param[in] mb_idx     Index of the message buffer
 *  @param[in] tx_info    Data info
 *  @param[in] msg_id     ID of the message to transmit
 *  @param[in] mb_data    Data bytes of the FlexCAN message
 *  @param[in] timeout_ms  A timeout for the transfer in milliseconds.
 *  @return    FLEXCAN_STATUS_SUCCESS if successfull;<br>
 *             FLEXCAN_STATUS_TIMEOUT if the timeout is reached;<br>
 *             FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of a message buffer is invalid;<br>
 *             FLEXCAN_STATUS_BUSY if the message buffer is used for other operation.<br>
 *
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SendBlocking(uint8 instance,
                                  uint8 mb_idx,
                                  const Flexcan_Ip_DataInfoType * tx_info,
                                  uint32 msg_id,
                                  const uint8 * mb_data,
                                  uint32 timeout_ms);
/**
 *  @brief Receives a CAN frame using the specified message buffer.
 *  @details This function receives a CAN frame using a configured message buffer. The function
 *           returns immediately.
 *  @param[in] instance  A FlexCAN instance number
 *  @param[in] mb_idx    Index of the message buffer
 *  @param[out] data     The FlexCAN receive message buffer data.
 *  @param[in] isPolling If the message will be send using pooling(true) or interrupt(false).
 *  @return FLEXCAN_STATUS_SUCCESS if successfull operation;<br>
 *          FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of a message buffer is invalid;<br>
 *          FLEXCAN_STATUS_BUSY if the message buffer is used for other operation.<br>
 *
 */
Flexcan_Ip_StatusType FlexCAN_Ip_Receive(uint8 instance,
                                       uint8 mb_idx,
                                       Flexcan_Ip_MsgBuffType * data,
                                       boolean isPolling);

/**
 *  @brief     FlexCAN Rx FIFO field configuration
 *  @details   Each element in the ID filter table specifies an ID to be used as
 *             acceptance criteria for the FIFO as follows:
 *       - for format A: In the standard frame format, bits 10 to 0 of the ID
 *         are used for frame identification. In the extended frame format, bits
 *         28 to 0 are used.
 *       - for format B: In the standard frame format, bits 10 to 0 of the ID
 *         are used for frame identification. In the extended frame format, only
 *         the 14 most significant bits (28 to 15) of the ID are compared to the
 *         14 most significant bits (28 to 15) of the received ID.
 *       - for format C: In both standard and extended frame formats, only the 8
 *         most significant bits (7 to 0 for standard, 28 to 21 for extended) of
 *         the ID are compared to the 8 most significant bits (7 to 0 for
 *         standard, 28 to 21 for extended) of the received ID.
 *
 *  @param[in] instance        A FlexCAN instance number
 *  @param[in] id_format       The format of the Rx FIFO ID Filter Table Elements
 *  @param[in] id_filter_table The ID filter table elements which contain RTR
 *                             bit, IDE bit, and Rx message ID
 * @return      FLEXCAN_STATUS_SUCCESS if successful;<br>
 *              FLEXCAN_STATUS_ERROR if fail to set;<br>
 *              FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 *  @note The number of elements in the ID filter table is defined by the
 *       following formula:
 *       - for format A: the number of Rx FIFO ID filters
 *       - for format B: twice the number of Rx FIFO ID filters
 *       - for format C: four times the number of Rx FIFO ID filters
 *       The user must provide the exact number of elements in order to avoid
 *       any misconfiguration.
 *       This function should be called from StopMode or FreezeMode.
 */
#define FlexCAN_Ip_ConfigRxFifo(instance, id_format, id_filter_table) \
                Call_FlexCAN_Ip_ConfigRxFifo(instance, id_format, id_filter_table)

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/*!
 * @brief FlexCAN Enhanced Rx FIFO field configuration
 *
 * @note The number of elements in the ID filter table is defined by the
 *       following types:
 *       - Type 1:ID filter element with filter + mask scheme
 *       - Type 2: ID filter element with range scheme
 *       - Type 3: ID filter element with 2-filter scheme
 *       The user must provide the exact number of elements in order to avoid
 *       any misconfiguration.
 *       This function should be called from StopMode or FreezeMode.
 *       Each element in the ID filter table specifies an ID to be used as
 *       acceptance criteria for the Enhanced Rx FIFO as follows:
 *       - for type 1: In the standard frame format, bits 26 to 16 of the ID
 *         are used for frame identification and bits 10 to 0 are used for ID mask.
 *         In the extended frame format, bits 28 to 0 are used for frame identification and
 *         bits 28 to 0 of next work are used for ID mask.
 *       - for type 2: In the standard frame format, bits 26 to 16 and bits 10 to 0 of the ID
 *         are used for frame identification. The filter scheme is based on range.
 *         In the extended frame format, bits 28 to 0 and bits 28 to 0 of next work
 *         are used for frame identification. The filter scheme is based on range.
 *       - for type 3: In the standard frame format, bits 26 to 16 and bits 10 to 0 of the ID
 *         are used for frame identification.
 *         In the extended frame format, bits 28 to 0 and bits 28 to 0 of next work
 *         are used for frame identification.

 * @param   instance           A FlexCAN instance number
 * @param   id_filter_table    The ID filter table elements which contain Enhanced Rx FIFO
 *                             filter type, RTR bit, IDE bit, and Rx message ID
 *
 * @return      FLEXCAN_STATUS_SUCCESS if successful;<br>
 *              FLEXCAN_STATUS_ERROR if fail to set;<br>
 *              FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define FlexCAN_Ip_ConfigEnhancedRxFifo(instance, id_filter_table) \
        Call_FlexCAN_Ip_ConfigEnhancedRxFifo(instance, id_filter_table)

#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

/**
 *  @brief     Receives a CAN frame using the message FIFO.
 *  @details   This function receives a CAN frame using the Rx FIFO.
 *             The function returns immediately.
 *  @param[in] instance A FlexCAN instance number
 *  @param[out] data    The FlexCAN receive message buffer data.
 *  @return    FLEXCAN_STATUS_SUCCESS if successfull operation;<br>
 *             FLEXCAN_STATUS_ERROR if FiFO feature wasn't enable;<br>
 *             FLEXCAN_STATUS_BUSY if the message buffer is used by other operation.<br>
 *
 */
Flexcan_Ip_StatusType FlexCAN_Ip_RxFifo(uint8 instance, Flexcan_Ip_MsgBuffType * data);

/*!
 * @brief Receives a CAN frame using the message FIFO, in a blocking manner.
 *
 * This function receives a CAN frame using the Rx FIFO or
 * Enhanced Rx FIFO (if available and enabled). If using Enhanced Rx FIFO, the size of
 * the data array will be considered the same as the configured FIFO watermark.
 * The function blocks until either a frame was received, or the specified timeout expired.
 * FlexCAN_Ip_RxFifoBlocking/FlexCAN_Ip_RxFifo must not be called in callback invocation
 * while FlexCAN_Ip_RxFifoBlocking is running to avoid unexpected behaviour.
 *
 * @param   instance    A FlexCAN instance number
 * @param   data        The FlexCAN receive message buffer data.
 * @param   timeout     A timeout for the transfer in milliseconds.
 * @return  FLEXCAN_STATUS_SUCCESS if successful;
 *          FLEXCAN_STATUS_BUSY if a resource is busy;
 *          FLEXCAN_STATUS_TIMEOUT if the timeout is reached;
 *          FLEXCAN_STATUS_ERROR if other error occurred
 */
Flexcan_Ip_StatusType FlexCAN_Ip_RxFifoBlocking(uint8 instance, Flexcan_Ip_MsgBuffType *data, uint32 timeout);

/**
 *  @brief     FlexCAN receive message buffer field configuration
 *  @details   This function will config receive parameters form Flexcan_Ip_DataInfoType and
 *             the message Id, and can overwritte another MB status.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] mb_idx   Index of the message buffer
 *  @param[in] rx_info  Data info
 *  @param[in] msg_id   ID of the message to transmit
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of a message buffer is invalid.
 *
 */
Flexcan_Ip_StatusType FlexCAN_Ip_ConfigRxMb(uint8 instance,
                                            uint8 mb_idx,
                                            const Flexcan_Ip_DataInfoType * rx_info,
                                            uint32 msg_id
                                           );

/**
 *  @brief     Sets the FlexCAN Rx individual mask
 *  @details   This function will set directly the mask value as is provided.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] mb_idx   Index of the message buffer
 *  @param[in] mask     Mask value
 *  @note      This function should be called from StopMode or FreezeMode.
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of a message buffer is invalid.
 *
 */
#define FlexCAN_Ip_SetRxIndividualMask(instance, mb_idx, mask) \
        Call_FlexCAN_Ip_SetRxIndividualMask(instance, mb_idx, mask)

/**
 *  @brief     Sets the FlexCAN Rx MB global mask.
 *  @details   This function will set directly the mask value as is provided.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] mask     Mask value
 *  @note      This function should be called from StopMode or FreezeMode.
 *  @return      FLEXCAN_STATUS_SUCCESS if successful;<br>
 *               FLEXCAN_STATUS_ERROR if fail to set;<br>
 *               FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
#define FlexCAN_Ip_SetRxMbGlobalMask(instance, mask) \
        Call_FlexCAN_Ip_SetRxMbGlobalMask(instance, mask)

/**
 * @brief Sets the FlexCAN Rx FIFO global mask.
 * This mask is applied to all filters ID regardless the ID Filter format.
 *
 * @param[in]   instance    A FlexCAN instance number
 * @param[in]   mask        Mask Value.
 * @note      This function should be called from StopMode or FreezeMode.
 * @return      FLEXCAN_STATUS_SUCCESS if successful;<br>
 *              FLEXCAN_STATUS_ERROR if fail to set;<br>
 *              FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define FlexCAN_Ip_SetRxFifoGlobalMask(instance, mask) \
        Call_FlexCAN_Ip_SetRxFifoGlobalMask(instance, mask)

/**
 *  @brief     Check a receive event.
 *  @details   This will check if message is received and read the message buffer or RxFifo.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] mb_idx   Index of the message buffer
 */
void FlexCAN_Ip_MainFunctionRead(uint8 instance, uint8 mb_idx);

/**
 *  @brief     Check a Transmission event.
 *  @details   This function will check a specific MB have been sent of FlexCAN module and
 *             if was sent will reset the status of Mb and clear the status flag.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] mb_idx message buffer number
 *
 */
void FlexCAN_Ip_MainFunctionWrite(uint8 instance, uint8 mb_idx);

/**
 *  @brief     Check a bus-off event.
 *  @details   This function will check bus activity of FlexCAN module and
 *             if a bus off event is detected will suspend the future bus activities by setting
 *             module in stop mode.
 *  @param[in] instance A FlexCAN instance number
 *  @return    FLEXCAN_STATUS_SUCCESS if successful busoff and set on stop;<br>
 *             FLEXCAN_STATUS_ERROR if no busoff event detected;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in the configured timeout value.<br>
 *
 */
#define FlexCAN_Ip_MainFunctionBusOff(instance) \
                Call_FlexCAN_Ip_MainFunctionBusOff(instance)

/**
 *  @brief     Enter FlexCAN Module in Freeze Mode.
 *  @details   This function will suspend bus activity of FlexCAN module and
 *             set it to Freeze Mode to allow module configuration.
 *  @param[in] instance A FlexCAN instance number
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in the configured timeout value.<br>
 *
 */
#define FlexCAN_Ip_EnterFreezeMode(instance) \
        Call_FlexCAN_Ip_EnterFreezeMode(instance)

/**
 *  @brief     Exit FlexCAN Module from Freeze Mode.
 *  @details   This function will allow FlexCAN module to participate to the BUS activity and
 *             restore normal opertaion of the driver.
 *  @param[in] instance A FlexCAN instance number
 *  @note      This function should be called from FreezeMode.
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in the configured timeout value.<br>
 *
 */
#define FlexCAN_Ip_ExitFreezeMode(instance) \
        Call_FlexCAN_Ip_ExitFreezeMode(instance)

/**
 *  @brief     DeInitilize the FlexCAN instance driver
 *  @details   This function will make future operataions of FlexCAN instance imposibile and will restore
 *             it's state to default value as before initialization.
 *  @param[in] instance A FlexCAN instance number
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
#define FlexCAN_Ip_Deinit(instance) \
        Call_FlexCAN_Ip_Deinit(instance)

/**
 *  @brief     Get Start Mode Status
 *  @details   Return if the instance is in Start Mode
 *  @param[in] instance A FlexCAN instance number
 *  @return    True instance is in START Mode
 *             False instance is not in START Mode
 *
 */
#define FlexCAN_Ip_GetStartMode(instance) \
        Call_FlexCAN_Ip_GetStartMode(instance)

/**
 *  @brief     Set the FlexCAN instance in START mode
 *  @details   Set the FlexCAN instance in START mode, allowing to participate to bus transfers.
 *  @param[in] instance A FlexCAN instance number
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define FlexCAN_Ip_SetStartMode(instance) \
        Call_FlexCAN_Ip_SetStartMode(instance)

/**
 *  @brief     Set the FlexCAN instance in STOP mode
 *  @details   Set the FlexCAN instance in START mode, this will prevent instance to participate to
 *  bus transactions and disable module clocks.
 *  @param[in] instance A FlexCAN instance number
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
#define FlexCAN_Ip_SetStopMode(instance) \
        Call_FlexCAN_Ip_SetStopMode(instance)

/**
 *  @brief     Enable\Disable listen Only Mode
 *  @details   This function will Enable or Disable listen Only Mode.
 *  @note      This function should be called from StopMode or FreezeMode.
 *  @param[in] u8Instance A FlexCAN instance number
 *  @param[in] listenonlystate     Enable\Disable interrupt selected
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_ERROR if fail to set;<br>
 *
 */
#define FlexCAN_Ip_SetListenOnlyMode(instance, listenonlystate) \
        Call_FlexCAN_Ip_SetListenOnlyMode(instance, listenonlystate)

/**
 * @brief Returns whether the previous FlexCAN transfer has finished.
 *
 * When performing an async transfer, call this function to ascertain the state of the
 * current transfer: in progress (or busy) or complete (success).
 *
 * @param[in] instance The FlexCAN instance number.
 * @param[in] mb_idx   The index of the message buffer.
 * @return FLEXCAN_STATUS_SUCCESS if successful;
 *         FLEXCAN_STATUS_BUSY if a resource is busy;
 *         FLEXCAN_STATUS_ERROR in case of a DMA error transfer;
 */
Flexcan_Ip_StatusType FlexCAN_Ip_GetTransferStatus(uint8 instance,
                                                   uint8 mb_idx);

/**
 *  @brief      Get Error Status of FlexCAN
 *  @details    This function will return the error status from ESR1 register.
 *              For exact mapping of errors please refere to RM(Reference Manual)
 *              on FLEXCAN ESR1 register description.
 *  @param[in]  instance: A FlexCAN instance number
 *  @return     The errors flags stored by register ESR1
 */
uint32 FlexCAN_Ip_GetErrorStatus(uint8 instance);

/**
 *  @brief      Get Transmit error counter of FlexCAN
 *  @details    This function will return the Transmit error counter for all errors
 *              detected in transmitted messages from ECR register.
 *              For exact mapping of errors please refere to RM(Reference Manual)
 *              on FLEXCAN ECR register description.
 *  @param[in]  instance: A FlexCAN instance number
 *  @return     The Transmit error counter stored by TXERRCNT in register ECR
 */
uint8 FlexCAN_Ip_GetControllerTxErrorCounter(uint8 instance);

/**
 *  @brief      Get Receive error counter of FlexCAN
 *  @details    This function will return the Receive error counter for all errors
 *              detected in transmitted messages from ECR register.
 *              For exact mapping of errors please refere to RM(Reference Manual)
 *              on FLEXCAN ECR register description.
 *  @param[in]  instance: A FlexCAN instance number
 *  @return     The Receive error counter stored by RXERRCNT in register ECR
 */
uint8 FlexCAN_Ip_GetControllerRxErrorCounter(uint8 instance);

/**
 *  @brief      Clear Error Status of FlexCAN
 *  @details    This function will clear the error status from ESR1 register.
 *              For exact mapping of errors please refere to RM(Reference Manual)
 *              on FLEXCAN ESR1 register description.
 *  @param[in]  instance: A FlexCAN instance number
 *  @param[in]  error: errors flags to be cleared
 */
void FlexCAN_Ip_ClearErrorStatus(uint8 instance,
                                 uint32 error);

/**
 *  @brief      Set RX masking type
 *  @details    This function will set RX masking type as RX global mask or RX individual mask
 *  @param[in]  instance: A FlexCAN instance number
 *  @param[in]  type: FlexCAN Rx mask type
 *  @note       This function should be called from StopMode or FreezeMode.
 *  @return     FLEXCAN_STATUS_SUCCESS if successful<br>
 *              FLEXCAN_STATUS_ERROR if controller is not in freeze mode<br>
 *
 */
#define FlexCAN_Ip_SetRxMaskType(instance, type) \
        Call_FlexCAN_Ip_SetRxMaskType(instance, type)

/**
 *  @brief      Set Rx14Mask filter for message buffer 14.
 *  @details    This function will set directly the mask value as is provided.
 *  @param[in]  instance: A FlexCAN instance number
 *  @param[in]  mask: The value applied for mask
 *  @note       This function should be called from StopMode or FreezeMode.
 *  @return     FLEXCAN_STATUS_SUCCESS if successful<br>
 *              FLEXCAN_STATUS_ERROR if controller is not in freeze mode<br>
 *
 */
#define FlexCAN_Ip_SetRxMb14Mask(instance, mask) \
        Call_FlexCAN_Ip_SetRxMb14Mask(instance, mask)

/**
 *  @brief      Set Rx15Mask filter for message buffer 15.
 *  @details    This function will set directly the mask value as is provided.
 *  @param[in]  instance: A FlexCAN instance number
 *  @param[in]  mask: The value applied for mask
 *  @note       This function should be called from StopMode or FreezeMode.
 *  @return     FLEXCAN_STATUS_SUCCESS if successful<br>
 *              FLEXCAN_STATUS_ERROR if controller is not in freeze mode<br>
 *
 */
#define FlexCAN_Ip_SetRxMb15Mask(instance, mask) \
        Call_FlexCAN_Ip_SetRxMb15Mask(instance, mask)

/**
 * @brief Gets the FlexCAN bit rate for standard frames or the arbitration phase of FD frames.
 * @note In case is used Enhanced Time Segments the PhaseSeg1 is the sum of PropSeg +1+ PhaseSeg1, and the
 * PropSeg will be 0;
 * @param[in]   instance    A FlexCAN instance number
 * @param[out]  bitrate     A pointer to a variable for returning the FlexCAN bit rate settings
 * @return  true if Enhanced Time segments are used;
 *          false if Enhanced Time segments are not used.
 */
boolean FlexCAN_Ip_GetBitrate(uint8 instance,
                           Flexcan_Ip_TimeSegmentType * bitrate);

/**
 * @brief Sets the FlexCAN bit rate for standard frames or the arbitration phase of FD frames.
 * @details This function request the FlexCAN module to be in Stop Mode or in Freeze Mode.
 * @param[in]   instance    A FlexCAN instance number
 * @param[in]   bitrate     A pointer to the FlexCAN bit rate settings.
 * @param[in]   enhExt      The time segments used are set in Enhanced Time Seg Registers
 * @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *            FLEXCAN_STATUS_ERROR if fail to set;<br>
 *            FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define FlexCAN_Ip_SetBitrate(instance, bitrate, enhExt) \
        Call_FlexCAN_Ip_SetBitrate(instance, bitrate, enhExt)

#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
/*!
 * @brief Clears the TDC Fail flag.
 *
 * @param[in]   instance    A FlexCAN instance number
 */
void FlexCAN_Ip_ClearTDCFail(uint8 u8Instance);

/*!
 * @brief Gets the value of the TDC Fail flag.
 *
 * @param[in]   instance    A FlexCAN instance number
 * @return  If true, indicates that the TDC mechanism is out of range, unable to
 * compensate the transceiver's loop delay and successfully compare the delayed
 * received bits to the transmitted ones.
 */
boolean FlexCAN_Ip_GetTDCFail(uint8 u8Instance);

/*!
 * @brief Gets the value of the Transceiver Delay Compensation.
 *
 * @param[in] u8Instance A FlexCAN instance number
 * @return  The value of the transceiver loop delay measured from the transmitted
 * EDL to R0 transition edge to the respective received one added to the TDCOFF
 * value.
 */
uint8 FlexCAN_Ip_GetTDCValue(uint8 u8Instance);

/**
 * @brief Sets the FlexCAN bit rate for the data phase of FD frames.
 * @details This function request the FlexCAN module to be in Stop Mode or in Freeze Mode.
 * @param[in]   instance    A FlexCAN instance number
 * @param[in]   bitrate     A pointer to the FlexCAN bit rate settings.
 * @param[in]   fd_enable   Enable/Disable Fd Frame Feature Support
 * @param[in]   bitRateSwitch Enable/Disable of FD Data Bitrate Switch support
 * @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *            FLEXCAN_STATUS_ERROR if fail to set;<br>
 *            FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define FlexCAN_Ip_SetBitrateCbt(instance, bitrate, bitRateSwitch) \
        Call_FlexCAN_Ip_SetBitrateCbt(instance, bitrate, bitRateSwitch)

/**
 * @brief Gets the FlexCAN bit rate for the data phase of FD frames (BRS enabled).
 * @note In case is used Enhanced Time Segments the PhaseSeg1 is the sum of PropSeg + PhaseSeg1, and the
 * PropSeg will be 0;
 * @param   instance    A FlexCAN instance number
 * @param   bitrate     A pointer to a variable for returning the FlexCAN bit rate settings
 * @return  true if Enhanced Time segments are used;
 *          false if Enhanced Time segments are not used.
 */
boolean FlexCAN_Ip_GetBitrateFD(uint8 instance,
                              Flexcan_Ip_TimeSegmentType * bitrate);

/**
 *  @brief     This function will set how many CAN bits the Tx arbitration process start point can
 *             be delayed from the first bit of CRC field on CAN bus.
 *  @details   This function request the FlexCAN module to be in Stop Mode or in Freeze Mode.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] value    Tx Arbitration Start Delay value
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_ERROR if fail to set;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
#define FlexCAN_Ip_SetTxArbitrationStartDelay(instance, value) \
        Call_FlexCAN_Ip_SetTxArbitrationStartDelay(instance, value)

/**
 * @brief Enables/Disables the Transceiver Delay Compensation feature and sets
 * the Transceiver Delay Compensation Offset (offset value to be added to the
 * measured transceiver's loop delay in order to define the position of the
 * delayed comparison point when bit rate switching is active).
 * @details This function request the FlexCAN module to be in Stop Mode or in Freeze Mode.
 * @param[in]   instance    A FlexCAN instance number
 * @param[in]   enable Enable/Disable Transceiver Delay Compensation
 * @param[in]   offset Transceiver Delay Compensation Offset
 * @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *            FLEXCAN_STATUS_ERROR if fail to set;<br>
 *            FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 */
#define FlexCAN_Ip_SetTDCOffset(instance, enable, offset) \
        Call_FlexCAN_Ip_SetTDCOffset(instance, enable, offset)
#endif /* FLEXCAN_IP_FEATURE_HAS_FD == STD_ON */
/**
 *  @brief     Get the Status of Message Buffer
 *  @details   This function will return True if Message Buffer Flag
 *             is Set or False if is not set.
 *  @param[in] instance   A FlexCAN instance number
 *  @param[in] msgBuffIdx Index of the message buffer
 *  @return    True if is set
 *             False if is clear.
 *
 */
boolean FlexCAN_Ip_GetBuffStatusFlag(uint8 instance,
                                     uint8 msgBuffIdx);

/**
 *  @brief     Clear Message Buffer Status Flag
 *  @details   This function will clear the status of the message buffer
 *  @param[in] instance   A FlexCAN instance number
 *  @param[in] msgBuffIdx Index of the message buffer
 *
 */
void FlexCAN_Ip_ClearBuffStatusFlag(uint8 instance,
                                    uint8 msgBuffIdx);

/**
 * @brief Enable all interrupts configured.
 * @details Enable all interrupts configured.
 * @param[in]   u8Instance    A FlexCAN instance number
 * @return    FLEXCAN_STATUS_SUCCESS if successful<br>
 *            FLEXCAN_STATUS_ERROR if fail to set<br>
 */
#define FlexCAN_Ip_EnableInterrupts(u8Instance) \
        Call_FlexCAN_Ip_EnableInterrupts(u8Instance)

/**
 * @brief Disable all interrupts.
 * @details Disable all interrupts.
 * @param[in]   u8Instance    A FlexCAN instance number
 * @return    FLEXCAN_STATUS_SUCCESS if successful<br>
 *            FLEXCAN_STATUS_ERROR if fail to set<br>
 */
#define FlexCAN_Ip_DisableInterrupts(u8Instance) \
        Call_FlexCAN_Ip_DisableInterrupts(u8Instance)

/**
 *  @brief     Enable\Disable Error or BusOff Interrupt
 *  @details   This function will set Error or BusOff interrupt, Error Fast is available only
 *             if FD CAN support is active.
 *  @Note      This function should be called from StopMode or FreezeMode.
 *             When an error interrupt is set and error callback function is installed,
 *             The error callback function will be invoked with a respective event occurred and status of ESR1 register:
 *             In the callback, if another event(got from ESR1 register) recognized(Error, Error Fast, Bus Off, Tx/Rx warning)
 *             Then it should be cleared by FlexCAN_Ip_ClearErrorStatus with a respective mask to avoid dupplication.
 *  @param[in] u8Instance A FlexCAN instance number
 *  @param[in] type       Interrupt Type
 *  @param[in] enable     Enable\Disable interrupt selected
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_ERROR if fail to set;<br>
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
#define FlexCAN_Ip_SetErrorInt(u8Instance, type, enable) \
        Call_FlexCAN_Ip_SetErrorInt(u8Instance, type, enable)

/**
 *  @brief     Ends a non-blocking FlexCAN transfer early.
 *  @details   Full description
 *  @param[in] u8Instance A FlexCAN instance number
 *  @param[in] mb_idx     The index of the message buffer
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;
 *             FLEXCAN_STATUS_NO_TRANSFER_IN_PROGRESS if no transfer was running,
 *             FLEXCAN_STATUS_TIMEOUT if fail to configure in configured timeout value.<br>
 *
 */
Flexcan_Ip_StatusType FlexCAN_Ip_AbortTransfer(uint8 u8Instance,
                                               uint8 mb_idx);

/**
 *  @brief     Get the Status of Listen Only Mode
 *  @details   This function will return True if Listen Only Mode
 *             is Enable or False if is Disable.
 *  @param[in] instance   A FlexCAN instance number
 *  @return    True if Listen Only Mode is Enable
 *             False if Listen Only Mode is Disable.
 *
 */
boolean FlexCAN_Ip_GetListenOnlyMode(uint8 instance);

/**
 *  @brief     Get Stop Mode Status
 *  @details   Return if the instance is in Stop Mode
 *  @param[in] instance A FlexCAN instance number
 *  @return    True instance is in STOP Mode
 *             False instance is not in STOP Mode
 *
 */
#define FlexCAN_Ip_GetStopMode(instance) \
        Call_FlexCAN_Ip_GetStopMode(instance)

/*!
 * @brief Receives a CAN frame using the specified message buffer, in a blocking manner.
 *
 * This function receives a CAN frame using a configured message buffer. The function
 * blocks until either a frame was received, or the specified timeout expired.
 *
 *  @param[in] instance  A FlexCAN instance number
 *  @param[in] mb_idx    Index of the message buffer
 *  @param[out] data     The FlexCAN receive message buffer data.
 *  @param[in] isPolling If the message will be send using pooling(true) or interrupt(false).
 *  @param[in] timeout_ms A timeout for the transfer in milliseconds.
 *  @return FLEXCAN_STATUS_SUCCESS if successfull operation;<br>
 *          FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of a message buffer is invalid;<br>
 *          FLEXCAN_STATUS_BUSY if the message buffer is used for other operation.<br>
 *          FLEXCAN_STATUS_TIMEOUT if the timeout is reached.<br>
 */
Flexcan_Ip_StatusType FlexCAN_Ip_ReceiveBlocking(uint8 instance,
                                                 uint8 mb_idx,
                                                 Flexcan_Ip_MsgBuffType * data,
                                                 boolean isPolling,
                                                 uint32 u32TimeoutMs);

/**
 * @brief Configures a transmit message buffer for remote frame response.
 *
 * @Note In case of using this function as polling mode the user should call
 * FlexCAN_Ip_MainFunctionWrite to check it.
 * @Note In case of enable the option Remote Request Store by setting corresponding bit for FLEXCAN_IP_REM_STORE_U32
 *  in the ctrlOptions structure member of the Flexcan platform configuration data from FlexCAN_Ip_Init function,
 *  will disable Automatic Response Request feature, in this case is not allowed use of this function.
 *
 * @param[in]   instance                   A FlexCAN instance number
 * @param[in]   mb_idx                     Index of the message buffer
 * @param[in]   tx_info                    Data info
 * @param[in]   msg_id                     ID of the message to transmit
 * @param[in]   mb_data                    Bytes of the FlexCAN message
 * @return  FLEXCAN_STATUS_SUCCESS if successful;
 *          FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of the message buffer
 *          is invalid
 */
Flexcan_Ip_StatusType FlexCAN_Ip_ConfigRemoteResponseMb(uint8 instance,
                                                        uint8 mb_idx,
                                                        const Flexcan_Ip_DataInfoType *tx_info,
                                                        uint32 msg_id,
                                                        const uint8 *mb_data);

#if (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)
/*!
 * @brief This function configure the timestamp settings.
 *
 * This function will allow to set the timestamp timer source and config the
 * HR Timer selected capture point for timestamp.
 * @note  Need enable clock counter for the source selected before use HR Time Stamp.
 *
 *  @param[in] instance  A FlexCAN instance number
 *  @param[in] time_stamp A timestamp configuration structure
 *  @return FLEXCAN_STATUS_SUCCESS if successful operation;<br>
 *          FLEXCAN_STATUS_ERROR if fail to set;<br>
 *          FLEXCAN_STATUS_TIMEOUT if the timeout is reached.<br>
 */
#define FlexCAN_Ip_ConfigTimeStamp(instance, time_stamp) \
        Call_FlexCAN_Ip_ConfigTimeStamp(instance, time_stamp)
#endif /* FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON */

#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/*!
 * @brief Configures Pretended Networking settings.
 * @details This function will enable or disable the Pretended Network feature and configure PN the
 * wakeup events and filters. This function requires the FlexCAN module to be in Stop Mode or in Freeze Mode.
 * @note In order this feature to work, the FlexCAN module need to be in Start Mode after configuring PN
 * and the Protocol Clock needed to remain active during sleep mode.
 *
 * @param[in] u8Instance The FlexCAN instance number.
 * @param[in] bEnable Enable/Disable Pretended Networking mode.
 * @param[in] pPnConfig Pointer to the Pretended Networking configuration structure.
 * @return FLEXCAN_STATUS_SUCCESS if successful operation;<br>
 *         FLEXCAN_STATUS_ERROR if fail to set;<br>
 *         FLEXCAN_STATUS_TIMEOUT if the timeout is reached.<br>
 */
#define FlexCAN_Ip_ConfigPN(u8Instance, bEnable, pPnConfig) \
        Call_FlexCAN_Ip_ConfigPN(u8Instance, bEnable, pPnConfig)

/*!
 * @brief Extracts one of the frames which triggered the wake up event.
 *
 * @param[in]   u8Instance    The FlexCAN instance number.
 * @param[in]   u8WmbIndex  The index of the message buffer to be extracted.
 * @param[in]   pWmb  Pointer to the message buffer structure where the frame will be saved.
 */
void FlexCAN_Ip_GetWMB(uint8 u8Instance,
                        uint8 u8WmbIndex,
                        Flexcan_Ip_MsgBuffType * pWmb);

#endif /* FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING */

/*!
 * @brief Recover manually from bus-off if possible.
 * @note This function should be used when bus-off auto recovery disabled and controller is in START mode.
 * The function FlexCAN_Ip_GetErrorStatus can be used to check FLTCONF bits to check if bus-off state is exited or not.
 *
 * @param[in]   Instance    The FlexCAN instance number.
 * @return FLEXCAN_STATUS_SUCCESS if successful operation or the controller wasn't in bus-off.<br>
 *         FLEXCAN_STATUS_ERROR if bus-off auto recovery enabled.<br>
 *         FLEXCAN_STATUS_TIMEOUT if the timeout is reached.<br>
 */
Flexcan_Ip_StatusType FlexCAN_Ip_ManualBusOffRecovery(uint8 Instance);

#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
void DMA_Can_Callback0(void);
#if FLEXCAN_INSTANCE_COUNT > 1U
void DMA_Can_Callback1(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 2U
void DMA_Can_Callback2(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 3U
void DMA_Can_Callback3(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 4U
void DMA_Can_Callback4(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 5U
void DMA_Can_Callback5(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 6U
void DMA_Can_Callback6(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 7U
void DMA_Can_Callback7(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 8U
void DMA_Can_Callback8(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 9U
void DMA_Can_Callback9(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 10U
void DMA_Can_Callback10(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 11U
void DMA_Can_Callback11(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 12U
void DMA_Can_Callback12(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 13U
void DMA_Can_Callback13(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 14U
void DMA_Can_Callback14(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 15U
void DMA_Can_Callback15(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 16U
void DMA_Can_Callback16(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 17U
void DMA_Can_Callback17(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 18U
void DMA_Can_Callback18(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 19U
void DMA_Can_Callback19(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 20U
void DMA_Can_Callback20(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 21U
void DMA_Can_Callback21(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 22U
void DMA_Can_Callback22(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 23U
void DMA_Can_Callback23(void);
#endif
#if FLEXCAN_INSTANCE_COUNT > 24U
void DMA_Can_Callback24(void);
#endif
#endif /* FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE */

#define CAN_43_FLEXCAN_STOP_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXCAN_FLEXCAN_IP_H_ */
