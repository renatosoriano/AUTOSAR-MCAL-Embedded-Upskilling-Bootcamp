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
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXCAN_IP_TRUSTEDFUNCTIONS_H
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_H

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "FlexCAN_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                      43
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H       7
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H    0
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H               2
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H               0
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip.h header file are of the same vendor */
#if (FLEXCAN_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H != FLEXCAN_IP_VENDOR_ID_H)
    #error "FlexCAN_Ip_TrustedFunctions.h and FlexCAN_Ip.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip.h header file are of the same Autosar version */
#if ((FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip_TrustedFunctions.h and FlexCAN_Ip.h are different"
#endif
/* Check if current file and FlexCAN_Ip.h header file are of the same Software version */
#if ((FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H != FLEXCAN_IP_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H != FLEXCAN_IP_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H != FLEXCAN_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of FlexCAN_Ip_TrustedFunctions.h and FlexCAN_Ip.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"

#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
 *  @brief Clears Legacy RxFifo message buffers.
 */
extern void FlexCAN_ClearOutputLegacyFIFO(FLEXCAN_Type * base);
#endif /* (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON) */

/**
 *  @brief Initializes the FlexCAN peripheral.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_Init_Privileged(uint8 Flexcan_Ip_u8Instance,
                                                Flexcan_Ip_StateType * Flexcan_Ip_pState,
                                                const Flexcan_Ip_ConfigType * Flexcan_Ip_pData);
/**
 *  @brief FlexCAN Rx Legacy FIFO filter configuration
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_ConfigRxFifo_Privileged(uint8 instance,
                                        Flexcan_Ip_RxFifoIdElementFormatType id_format,
                                        const Flexcan_Ip_IdTableType * id_filter_table);

/**
 *  @brief     Check a bus-off event.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_MainFunctionBusOff_Privileged(uint8 instance);

/**
 *  @brief     Check if the FlexCAN instance is STOPPED.
 */
extern boolean FlexCAN_Ip_GetStopMode_Privileged(uint8 instance);

/**
 *  @brief     Check if the FlexCAN instance is STARTED.
 */
extern boolean FlexCAN_Ip_GetStartMode_Privileged(uint8 instance);

/**
 *  @brief     Enter FlexCAN Module in Freeze Mode.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_EnterFreezeMode_Privileged(uint8 instance);
/**
 *  @brief     Exit FlexCAN Module from Freeze Mode.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_ExitFreezeMode_Privileged(uint8 instance);

/**
 *  @brief     Set RxFifo Global Mask.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetRxFifoGlobalMask_Privileged(uint8 instance,
                                                      uint32 mask);
/**
 *  @brief     DeInitilize the FlexCAN instance driver
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_Deinit_Privileged(uint8 instance);
/**
 *  @brief     Set the FlexCAN instance in START mode
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetStartMode_Privileged(uint8 instance);
/**
 *  @brief     Set the FlexCAN instance in STOP mode
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetStopMode_Privileged(uint8 instance);
/**
 *  @brief      Set RX masking type
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetRxMaskType_Privileged(uint8 instance,
                               Flexcan_Ip_RxMaskType type);
/*
* @brief Set Rx14Mask filter for message buffer 14.
*/
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetRxMb14Mask_Privileged(uint8 instance, uint32 mask);
/*
* @brief Set Rx14Mask filter for message buffer 15.
*/
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetRxMb15Mask_Privileged(uint8 instance, uint32 mask);
/*
* @brief Sets the FlexCAN Rx individual mask
*/
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetRxIndividualMask_Privileged(uint8 instance, uint8 mb_idx, uint32 mask);
/*
* @brief Sets the FlexCAN Rx Message Buffer Global mask
*/
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetRxMbGlobalMask_Privileged(uint8 instance, uint32 mask);
/**
 * @brief Sets the FlexCAN bit rate for standard frames or the arbitration phase of FD frames.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetBitrate_Privileged(uint8 instance,
                                                        const Flexcan_Ip_TimeSegmentType * bitrate,
                                                        boolean enhExt);
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
/**
 * @brief Sets the FlexCAN bit rate for the data phase of FD frames.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetBitrateCbt_Privileged(uint8 instance,
                                                        const Flexcan_Ip_TimeSegmentType * bitrate,
                                                        boolean bitRateSwitch);
/**
 *  @brief     This function will set how many CAN bits the Tx arbitration process start point can
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetTxArbitrationStartDelay_Privileged(uint8 instance, uint8 value);

/**
 * @brief Enables/Disables the Transceiver Delay Compensation feature and sets
 * the Transceiver Delay Compensation Offset (offset value to be added to the
 * measured transceiver's loop delay in order to define the position of the
 * delayed comparison point when bit rate switching is active).
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetTDCOffset_Privileged(uint8 instance,
                                              boolean enable,
                                              uint8 offset);

#endif /* FLEXCAN_IP_FEATURE_HAS_FD == STD_ON */

/**
 *  @brief     Enable all mb interrupts configured.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_EnableInterrupts_Privileged(uint8 u8Instance);

/**
 *  @brief     Disable all mb interrupts configured.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_DisableInterrupts_Privileged(uint8 u8Instance);

/**
 *  @brief     Enable\Disable Error or BusOff Interrupt
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetErrorInt_Privileged(uint8 u8Instance,
                                             Flexcan_Ip_ErrorIntType type,
                                             boolean enable);

/**
 *  @brief     Set FlexCAN Listen Only.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_SetListenOnlyMode_Privileged(uint8 instance, const boolean enable);
#if    (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)
/**
 *  @brief     Set FlexCAN Config Timestamp.
 */
extern Flexcan_Ip_StatusType FlexCAN_Ip_ConfigTimeStamp_Privileged(uint8 instance, const Flexcan_Ip_TimeStampConfigType * time_stamp);
#endif

#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
extern Flexcan_Ip_StatusType FlexCAN_Ip_ConfigPN_Privileged(uint8 u8Instance,
                          boolean bEnable,
                          const Flexcan_Ip_PnConfigType * pPnConfig);
#endif /* (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON) */

#define CAN_43_FLEXCAN_STOP_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"

#endif /* FLEXCAN_IP_TRUSTEDFUNCTIONS_H */
