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

#ifndef FLEXIO_SPI_IP_H
#define FLEXIO_SPI_IP_H

/**
*   @file     Flexio_Spi_Ip.h
*
*   @brief   FLEXIO_SPI IP driver header file.
*   @details FLEXIO_SPI IP driver header file.

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
#include "Flexio_Spi_Ip_Types.h"
#ifdef FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT
#include "Mcal.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_SPI_IP_VENDOR_ID                       43
#define FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION        4
#define FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION        7
#define FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION     0
#define FLEXIO_SPI_IP_SW_MAJOR_VERSION                2
#define FLEXIO_SPI_IP_SW_MINOR_VERSION                0
#define FLEXIO_SPI_IP_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Flexio_Spi_Ip.h and Flexio_Spi_Ip_Types.h are of the same vendor */
#if (FLEXIO_SPI_IP_VENDOR_ID != FLEXIO_SPI_IP_TYPES_VENDOR_ID)
    #error "Flexio_Spi_Ip.h and Flexio_Spi_Ip_Types.h have different vendor ids"
#endif
/* Check if Flexio_Spi_Ip.h file and Flexio_Spi_Ip_Types.h file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION    != FLEXIO_SPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION    != FLEXIO_SPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_SPI_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexio_Spi_Ip.h and Flexio_Spi_Ip_Types.h are different"
#endif
#if ((FLEXIO_SPI_IP_SW_MAJOR_VERSION != FLEXIO_SPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_SPI_IP_SW_MINOR_VERSION != FLEXIO_SPI_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_SPI_IP_SW_PATCH_VERSION != FLEXIO_SPI_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_Spi_Ip.h and Flexio_Spi_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT
        /* Check if Flexio_Spi_Ip.h file and Mcal.h file are of the same Autosar version */
        #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
             (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Flexio_Spi_Ip.h and Mcal.h are different"
        #endif
    #endif /* FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT */
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (FLEXIO_SPI_IP_ENABLE == STD_ON)
    
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/**
* @brief   Export Post-Build configurations.
*/
FLEXIO_SPI_IP_CONFIG_EXT

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h" 
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
* @brief            FLEXIO_SPI peripheral initialization.
* @details          The function initialize the SPI Unit specified in the configuration.
*
* @param[in]        PhyUnitConfigPtr -  pointer to the specified SPI Unit configuration.
*
* @return           FLEXIO_SPI_IP_STATUS_SUCCESS: Initialization command has been accepted.
*                   FLEXIO_SPI_IP_STATUS_FAIL: Initialization command has not been accepted.
* @implements Flexio_Spi_Ip_Init_Activity
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_Init(const Flexio_Spi_Ip_ConfigType *PhyUnitConfigPtr);

/**
* @brief            FLEXIO_SPI peripheral deinitialization.
* @details          The function de-initialize the SPI peripheral instance specified.
*                   All registers of SPI peripheral will be reset.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return           FLEXIO_SPI_IP_STATUS_SUCCESS: De-initialization command has been accepted.
*                   FLEXIO_SPI_IP_STATUS_FAIL: De-initialization command has not been accepted.
* @implements Flexio_Spi_Ip_DeInit_Activity
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_DeInit(uint8 Instance);

/**
* @brief            FLEXIO_SPI synchronous transmission.
* @details          This function initializes a synchronous transfer using the bus parameters provided
*                   by external device.
*
* @param[in]        ExternalDevice - pointer to the external device where data is transmitted.
* @param[in]        TxBuffer - pointer to transmit buffer.
* @param[in-out]    RxBuffer - pointer to receive buffer.
* @param[in]        Length - number of bytes to be sent.
* @param[in]        TimeOut - duration for sending one frame.
*
* @return           FLEXIO_SPI_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   FLEXIO_SPI_IP_FIFO_ERROR: Overflow or underflow error occurred.
*                   FLEXIO_SPI_IP_STATUS_FAIL: Transmission command has not been accepted.
*                   FLEXIO_SPI_IP_TIMEOUT: Timeout error occurred.
*
* @implements Flexio_Spi_Ip_SyncTransmit_Activity
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_SyncTransmit(
                                                      const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice, 
                                                      const uint8 *TxBuffer,
                                                      uint8 *RxBuffer,
                                                      uint16 Length,
                                                      uint32 TimeOut
                                                   );

/**
* @brief            FLEXIO_SPI asynchronous transmission.
* @details          This function initializes an asynchronous transfer using the bus parameters provided
*                   by external device. After Flexio_Spi_Ip_Init function is called, FLEXIO_SPI_IP_POLLING
*					mode is set as default to change the default mode Flexio_Spi_Ip_UpdateTransferMode should be called.
*
* @param[in]        ExternalDevice - pointer to the external device where data is transmitted
* @param[in]        TxBuffer - pointer to transmit buffer.
* @param[in-out]    RxBuffer - pointer to receive buffer.
* @param[in]        Length - number of bytes to be sent.
* @param[in]        Callback - callback function is called at the end of transfer.
*
* @return           FLEXIO_SPI_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   FLEXIO_SPI_IP_STATUS_FAIL: Transmission command has not been accepted.
* @implements Flexio_Spi_Ip_AsyncTransmit_Activity
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_AsyncTransmit(
                                       const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice,
                                       const uint8* TxBuffer, 
                                       uint8* RxBuffer,
                                       uint16 Length, 
                                       Flexio_Spi_Ip_CallbackType EndCallback /* TBD de pus la init/instanta */
                                      );

/**
* @brief   Get status of HW unit.
* @details This function will return status of HW unit assigned.
*
* @param[in]      instance            Instance of the hardware unit.
*
* @return Flexio_Spi_Ip_HwStatusType
* @retval FLEXIO_SPI_IP_IDLE           Hardware unit is not used
* @retval FLEXIO_SPI_IP_BUSY           A transfer is in progress
* @retval FLEXIO_SPI_IP_FAULT          During last transfer a fault occurred
* @implements Flexio_Spi_Ip_GetStatus_Activity
*/
Flexio_Spi_Ip_HwStatusType Flexio_Spi_Ip_GetStatus(uint8 Instance);

/**
* @brief            Process transfer in POLLING mode.
* @details          This function shall polls the SPI interrupts linked to SPI peripheral instance allocated to 
*                   the transmission of data to enable the evolution of transmission state machine.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return void
* @implements Flexio_Spi_Ip_ManageBuffers_Activity
*/
void Flexio_Spi_Ip_ManageBuffers(uint8 Instance);

/**
* @brief            FLEXIO_SPI change frame size.
* @details          This function updates frame size of specific external device configuration for next transfers.
*
* @param[in]        ExternalDevice - pointer to the external device configuration.
* @param[in]        FrameSize - Frame size.
*
* @return           FLEXIO_SPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   FLEXIO_SPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Flexio_Spi_Ip_UpdateFrameSize_Activity
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_UpdateFrameSize(const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice, uint8 FrameSize);

/**
* @brief            FLEXIO_SPI change bit order.
* @details          This function updates bits order LSB or MSB of specific external device configuration for next transfer.
*
* @param[in]        ExternalDevice - pointer to the external device configuration.
* @param[in]        Lsb - Data is transferred LSB first or not.
*
* @return           FLEXIO_SPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   FLEXIO_SPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Flexio_Spi_Ip_UpdateLsb_Activity
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_UpdateLsb(const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice, boolean Lsb);

/**
* @brief            FLEXIO_SPI change default transmit data.
* @details          This function updates default transmit data of specific external device configuration for next transfer.
*
* @param[in]        ExternalDevice - pointer to the external device configuration.
* @param[in]        DefaultData - New default transmit data.
*
* @return           FLEXIO_SPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   FLEXIO_SPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Flexio_Spi_Ip_UpdateDefaultTransmitData_Activity
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_UpdateDefaultTransmitData(const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice, uint32 DefaultData);

/**
* @brief            FLEXIO_SPI change transfer mode.
* @details          This function updates the asynchronous mechanism mode for the specified SPI Hardware microcontroller peripheral.
*
* @param[in]        Instance - SPI peripheral instance number.
* @param[in]        Mode - new mode (interrupt or polling).
*
* @return           FLEXIO_SPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   FLEXIO_SPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Flexio_Spi_Ip_UpdateTransferMode_Activity
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_UpdateTransferMode(uint8 Instance, Flexio_Spi_Ip_ModeType Mode);

/**
* @brief   FLEXIO_SPI cancel current transmission.
* @details This function will cancel current asynchronous transmission.
*
* @param[in]      Instance            Instance of the hardware unit.
*
* @implements Flexio_Spi_Ip_Cancel_Activity
*/
void Flexio_Spi_Ip_Cancel(uint8 Instance);

#if (FLEXIO_SPI_IP_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   This function will change clock mode.
* @details This function will change clock mode to operate with other clock reference.
*
* @param[in]     Instance            Instance of the hardware unit.
* @param[in]     ClockMode           Clock mode.
*
* @return         An error code or FLEXIO_SPI_IP_STATUS_SUCCESS
* @implements Flexio_Spi_Ip_SetClockMode_Activity
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_SetClockMode(uint8 Instance, Flexio_Spi_Ip_DualClockModeType ClockMode);
#endif
#if (FLEXIO_SPI_IP_DMA_USED == STD_ON)
void Flexio_Spi_Ip_IrqTxDmaHandler(uint8 Instance);
void Flexio_Spi_Ip_IrqRxDmaHandler(uint8 Instance);
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#endif /*FLEXIO_SPI_IP_ENABLE == STD_ON)*/
 
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_SPI_IP_H */
