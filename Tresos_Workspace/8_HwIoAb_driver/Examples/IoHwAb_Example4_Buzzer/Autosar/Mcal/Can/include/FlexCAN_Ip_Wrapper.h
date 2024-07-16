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

#ifndef FLEXCAN_IP_WRAPPER_H_
#define FLEXCAN_IP_WRAPPER_H_

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_WRAPPER_VENDOR_ID_H                      43
#define FLEXCAN_IP_WRAPPER_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_IP_WRAPPER_AR_RELEASE_MINOR_VERSION_H       7
#define FLEXCAN_IP_WRAPPER_AR_RELEASE_REVISION_VERSION_H    0
#define FLEXCAN_IP_WRAPPER_SW_MAJOR_VERSION_H               2
#define FLEXCAN_IP_WRAPPER_SW_MINOR_VERSION_H               0
#define FLEXCAN_IP_WRAPPER_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (FLEXCAN_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
        #define Call_FlexCAN_Ip_Init(Flexcan_Ip_u8Instance, Flexcan_Ip_pState, Flexcan_Ip_pData) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return3param((uint32)FlexCAN_Ip_Init_Privileged, Flexcan_Ip_u8Instance, Flexcan_Ip_pState, Flexcan_Ip_pData))

        #define Call_FlexCAN_Ip_ConfigRxFifo(instance, id_format, id_filter_table) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return3param((uint32)FlexCAN_Ip_ConfigRxFifo_Privileged, instance, id_format, id_filter_table))

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        #define Call_FlexCAN_Ip_ConfigEnhancedRxFifo(instance, id_filter_table) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return2param((uint32)FlexCAN_Ip_ConfigEnhancedRxFifo_Privileged, instance, id_filter_table))
#endif

        #define Call_FlexCAN_Ip_MainFunctionBusOff(instance) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return1param((uint32)FlexCAN_Ip_MainFunctionBusOff_Privileged, instance))

        #define Call_FlexCAN_Ip_GetStopMode(instance) \
                (OsIf_Trusted_Call_Return1param((uint32)FlexCAN_Ip_GetStopMode_Privileged, instance))

        #define Call_FlexCAN_Ip_GetStartMode(instance) \
                (OsIf_Trusted_Call_Return1param((uint32)FlexCAN_Ip_GetStartMode_Privileged, instance))

        #define Call_FlexCAN_Ip_EnterFreezeMode(instance) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return1param((uint32)FlexCAN_Ip_EnterFreezeMode_Privileged, instance))

        #define Call_FlexCAN_Ip_ExitFreezeMode(instance) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return1param((uint32)FlexCAN_Ip_ExitFreezeMode_Privileged, instance))

        #define Call_FlexCAN_Ip_SetRxFifoGlobalMask(instance, mask) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return2param((uint32)FlexCAN_Ip_SetRxFifoGlobalMask_Privileged, instance, mask))

        #define Call_FlexCAN_Ip_Deinit(instance) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return1param((uint32)FlexCAN_Ip_Deinit_Privileged, instance))

        #define Call_FlexCAN_Ip_SetStartMode(instance) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return1param((uint32)FlexCAN_Ip_SetStartMode_Privileged, instance))

        #define Call_FlexCAN_Ip_SetStopMode(instance) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return1param((uint32)FlexCAN_Ip_SetStopMode_Privileged, instance))

        #define Call_FlexCAN_Ip_SetRxMaskType(instance, type) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return2param((uint32)FlexCAN_Ip_SetRxMaskType_Privileged, instance, type))

        #define Call_FlexCAN_Ip_SetRxMb14Mask(instance, mask) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return2param((uint32)FlexCAN_Ip_SetRxMb14Mask_Privileged, instance, mask))

        #define Call_FlexCAN_Ip_SetRxMb15Mask(instance, mask) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return2param((uint32)FlexCAN_Ip_SetRxMb15Mask_Privileged, instance, mask))

        #define Call_FlexCAN_Ip_SetRxMbGlobalMask(instance, mask) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return2param((uint32)FlexCAN_Ip_SetRxMbGlobalMask_Privileged, instance, mask))

        #define Call_FlexCAN_Ip_SetRxIndividualMask(instance, mb_idx, mask) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return3param((uint32)FlexCAN_Ip_SetRxIndividualMask_Privileged, instance, mb_idx, mask))

        #define Call_FlexCAN_Ip_SetBitrateCbt(instance, bitrate, bitRateSwitch) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return3param((uint32)FlexCAN_Ip_SetBitrateCbt_Privileged, instance, bitrate, bitRateSwitch))

        #define Call_FlexCAN_Ip_SetBitrate(instance, bitrate, enhExt) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return3param((uint32)FlexCAN_Ip_SetBitrate_Privileged, instance, bitrate, enhExt))

        #define Call_FlexCAN_Ip_SetTxArbitrationStartDelay(instance, value) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return2param((uint32)FlexCAN_Ip_SetTxArbitrationStartDelay_Privileged, instance, value))

        #define Call_FlexCAN_Ip_SetTDCOffset(instance, enable, offset) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return3param((uint32)FlexCAN_Ip_SetTDCOffset_Privileged, instance, enable, offset))

        #define Call_FlexCAN_Ip_EnableInterrupts(u8Instance) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return1param((uint32)FlexCAN_Ip_EnableInterrupts_Privileged, u8Instance))

        #define Call_FlexCAN_Ip_DisableInterrupts(u8Instance) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return1param((uint32)FlexCAN_Ip_DisableInterrupts_Privileged, u8Instance))

        #define Call_FlexCAN_Ip_SetErrorInt(u8Instance, type, enable) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return3param((uint32)FlexCAN_Ip_SetErrorInt_Privileged, u8Instance, type, enable))

        #define Call_FlexCAN_Ip_SetListenOnlyMode(instance, value) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return2param((uint32)FlexCAN_Ip_SetListenOnlyMode_Privileged, instance, value))
#if (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)
        #define Call_FlexCAN_Ip_ConfigTimeStamp(instance, time_stamp) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return2param((uint32)FlexCAN_Ip_ConfigTimeStamp_Privileged, instance, time_stamp))
#endif
#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
        #define Call_FlexCAN_Ip_ConfigPN(u8Instance, bEnable, pPnConfig) \
                ((Flexcan_Ip_StatusType)OsIf_Trusted_Call_Return3param((uint32)FlexCAN_Ip_ConfigPN_Privileged, u8Instance, bEnable, pPnConfig))
#endif /* (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON) */
#else
        #define Call_FlexCAN_Ip_Init(Flexcan_Ip_u8Instance, Flexcan_Ip_pState, Flexcan_Ip_pData) \
                FlexCAN_Ip_Init_Privileged(Flexcan_Ip_u8Instance, Flexcan_Ip_pState, Flexcan_Ip_pData)

        #define Call_FlexCAN_Ip_ConfigRxFifo(instance, id_format, id_filter_table) \
                FlexCAN_Ip_ConfigRxFifo_Privileged(instance, id_format, id_filter_table)

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
        #define Call_FlexCAN_Ip_ConfigEnhancedRxFifo(instance, id_filter_table) \
                FlexCAN_Ip_ConfigEnhancedRxFifo_Privileged(instance, id_filter_table)
#endif

        #define Call_FlexCAN_Ip_MainFunctionBusOff(instance) \
                FlexCAN_Ip_MainFunctionBusOff_Privileged(instance)

        #define Call_FlexCAN_Ip_GetStopMode(instance) \
                FlexCAN_Ip_GetStopMode_Privileged(instance)

        #define Call_FlexCAN_Ip_GetStartMode(instance) \
                FlexCAN_Ip_GetStartMode_Privileged(instance)

        #define Call_FlexCAN_Ip_EnterFreezeMode(instance) \
                FlexCAN_Ip_EnterFreezeMode_Privileged(instance)

        #define Call_FlexCAN_Ip_ExitFreezeMode(instance) \
                FlexCAN_Ip_ExitFreezeMode_Privileged(instance)

        #define Call_FlexCAN_Ip_SetRxFifoGlobalMask(instance, mask) \
                FlexCAN_Ip_SetRxFifoGlobalMask_Privileged(instance, mask)

        #define Call_FlexCAN_Ip_Deinit(instance) \
                FlexCAN_Ip_Deinit_Privileged(instance)

        #define Call_FlexCAN_Ip_SetStartMode(instance) \
                FlexCAN_Ip_SetStartMode_Privileged(instance)

        #define Call_FlexCAN_Ip_SetStopMode(instance) \
                FlexCAN_Ip_SetStopMode_Privileged(instance)

        #define Call_FlexCAN_Ip_SetRxMaskType(instance, type) \
                FlexCAN_Ip_SetRxMaskType_Privileged(instance, type)

        #define Call_FlexCAN_Ip_SetRxMb14Mask(instance, mask) \
                FlexCAN_Ip_SetRxMb14Mask_Privileged(instance, mask)

        #define Call_FlexCAN_Ip_SetRxMb15Mask(instance, mask) \
                FlexCAN_Ip_SetRxMb15Mask_Privileged(instance, mask)

        #define Call_FlexCAN_Ip_SetRxIndividualMask(instance, mb_idx, mask) \
                FlexCAN_Ip_SetRxIndividualMask_Privileged(instance, mb_idx, mask)

        #define Call_FlexCAN_Ip_SetRxMbGlobalMask(instance, mask) \
                FlexCAN_Ip_SetRxMbGlobalMask_Privileged(instance, mask)

        #define Call_FlexCAN_Ip_SetBitrateCbt(instance, bitrate, bitRateSwitch) \
                FlexCAN_Ip_SetBitrateCbt_Privileged(instance, bitrate, bitRateSwitch)

        #define Call_FlexCAN_Ip_SetBitrate(instance, bitrate, enhExt) \
                FlexCAN_Ip_SetBitrate_Privileged(instance, bitrate, enhExt)

        #define Call_FlexCAN_Ip_SetTxArbitrationStartDelay(instance, value) \
                FlexCAN_Ip_SetTxArbitrationStartDelay_Privileged(instance, value)

        #define Call_FlexCAN_Ip_SetTDCOffset(instance, enable, offset) \
                FlexCAN_Ip_SetTDCOffset_Privileged(instance, enable, offset)

        #define Call_FlexCAN_Ip_EnableInterrupts(u8Instance) \
                FlexCAN_Ip_EnableInterrupts_Privileged(u8Instance)

        #define Call_FlexCAN_Ip_DisableInterrupts(u8Instance) \
                FlexCAN_Ip_DisableInterrupts_Privileged(u8Instance)

        #define Call_FlexCAN_Ip_SetErrorInt(u8Instance, type, enable) \
                FlexCAN_Ip_SetErrorInt_Privileged(u8Instance, type, enable)

        #define Call_FlexCAN_Ip_SetListenOnlyMode(instance, value) \
                FlexCAN_Ip_SetListenOnlyMode_Privileged(instance, value)
#if (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)
        #define Call_FlexCAN_Ip_ConfigTimeStamp(instance, time_stamp) \
                FlexCAN_Ip_ConfigTimeStamp_Privileged(instance, time_stamp)
#endif
#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
        #define Call_FlexCAN_Ip_ConfigPN(u8Instance, bEnable, pPnConfig) \
                FlexCAN_Ip_ConfigPN_Privileged(u8Instance, bEnable, pPnConfig)
#endif /* (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON) */
#endif /* (FLEXCAN_IP_ENABLE_USER_MODE_SUPPORT == STD_ON) */
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
/**
 *  @brief Initializes the FlexCAN peripheral.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_Init_Privileged(uint8 Flexcan_Ip_u8Instance,
                                                Flexcan_Ip_StateType * Flexcan_Ip_pState,
                                                const Flexcan_Ip_ConfigType * Flexcan_Ip_pData);
/**
 *  @brief FlexCAN Rx Legacy FIFO filter configuration
 */
Flexcan_Ip_StatusType FlexCAN_Ip_ConfigRxFifo_Privileged(uint8 instance,
                                        Flexcan_Ip_RxFifoIdElementFormatType id_format,
                                        const Flexcan_Ip_IdTableType * id_filter_table);

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/**
 *  @brief FlexCAN Enhanced Rx FIFO filter configuration
 */
Flexcan_Ip_StatusType FlexCAN_Ip_ConfigEnhancedRxFifo_Privileged(uint8 instance,
                                                 const Flexcan_Ip_EnhancedIdTableType * id_filter_table);
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

/**
 *  @brief     Check a bus-off event.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_MainFunctionBusOff_Privileged(uint8 instance);

/**
 *  @brief     Check if the FlexCAN instance is STOPPED.
 */
boolean FlexCAN_Ip_GetStopMode_Privileged(uint8 instance);

/**
 *  @brief     Check if the FlexCAN instance is STARTED.
 */
boolean FlexCAN_Ip_GetStartMode_Privileged(uint8 instance);

/**
 *  @brief     Enter FlexCAN Module in Freeze Mode.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_EnterFreezeMode_Privileged(uint8 instance);
/**
 *  @brief     Exit FlexCAN Module from Freeze Mode.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_ExitFreezeMode_Privileged(uint8 instance);

/**
 *  @brief     Set RxFifo Global Mask.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SetRxFifoGlobalMask_Privileged(uint8 instance,
                                                      uint32 mask);
/**
 *  @brief     DeInitilize the FlexCAN instance driver
 */
Flexcan_Ip_StatusType FlexCAN_Ip_Deinit_Privileged(uint8 instance);
/**
 *  @brief     Set the FlexCAN instance in START mode
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SetStartMode_Privileged(uint8 instance);
/**
 *  @brief     Set the FlexCAN instance in STOP mode
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SetStopMode_Privileged(uint8 instance);
/**
 *  @brief      Set RX masking type
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SetRxMaskType_Privileged(uint8 instance,
                               Flexcan_Ip_RxMaskType type);
/*
* @brief Set Rx14Mask filter for message buffer 14.
*/
Flexcan_Ip_StatusType FlexCAN_Ip_SetRxMb14Mask_Privileged(uint8 instance, uint32 mask);
/*
* @brief Set Rx14Mask filter for message buffer 15.
*/
Flexcan_Ip_StatusType FlexCAN_Ip_SetRxMb15Mask_Privileged(uint8 instance, uint32 mask);
/*
* @brief Sets the FlexCAN Rx individual mask
*/
Flexcan_Ip_StatusType FlexCAN_Ip_SetRxIndividualMask_Privileged(uint8 instance, uint8 mb_idx, uint32 mask);
/*
* @brief Sets the FlexCAN Rx Message Buffer Global mask
*/
Flexcan_Ip_StatusType FlexCAN_Ip_SetRxMbGlobalMask_Privileged(uint8 instance, uint32 mask);
/**
 * @brief Sets the FlexCAN bit rate for standard frames or the arbitration phase of FD frames.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SetBitrate_Privileged(uint8 instance,
                                                        const Flexcan_Ip_TimeSegmentType * bitrate,
                                                        boolean enhExt);
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
/**
 * @brief Sets the FlexCAN bit rate for the data phase of FD frames.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SetBitrateCbt_Privileged(uint8 instance,
                                                        const Flexcan_Ip_TimeSegmentType * bitrate,
                                                        boolean bitRateSwitch);
/**
 *  @brief     This function will set how many CAN bits the Tx arbitration process start point can
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SetTxArbitrationStartDelay_Privileged(uint8 instance, uint8 value);

/**
 * @brief Enables/Disables the Transceiver Delay Compensation feature and sets
 * the Transceiver Delay Compensation Offset (offset value to be added to the
 * measured transceiver's loop delay in order to define the position of the
 * delayed comparison point when bit rate switching is active).
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SetTDCOffset_Privileged(uint8 instance,
                                              boolean enable,
                                              uint8 offset);

#endif /* FLEXCAN_IP_FEATURE_HAS_FD == STD_ON */

/**
 *  @brief     Enable all mb interrupts configured.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_EnableInterrupts_Privileged(uint8 u8Instance);

/**
 *  @brief     Disable all mb interrupts configured.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_DisableInterrupts_Privileged(uint8 u8Instance);

/**
 *  @brief     Enable\Disable Error or BusOff Interrupt
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SetErrorInt_Privileged(uint8 u8Instance,
                                             Flexcan_Ip_ErrorIntType type,
                                             boolean enable);

/**
 *  @brief     Set FlexCAN Listen Only.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_SetListenOnlyMode_Privileged(uint8 instance, const boolean enable);
#if    (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)
/**
 *  @brief     Set FlexCAN Config Timestamp.
 */
Flexcan_Ip_StatusType FlexCAN_Ip_ConfigTimeStamp_Privileged(uint8 instance, const Flexcan_Ip_TimeStampConfigType * time_stamp);
#endif

#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
Flexcan_Ip_StatusType FlexCAN_Ip_ConfigPN_Privileged(uint8 u8Instance,
                          boolean bEnable,
                          const Flexcan_Ip_PnConfigType * pPnConfig);
#endif /* (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON) */

#define CAN_43_FLEXCAN_STOP_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"

#endif /* FLEXCAN_IP_WRAPPER_H_ */
