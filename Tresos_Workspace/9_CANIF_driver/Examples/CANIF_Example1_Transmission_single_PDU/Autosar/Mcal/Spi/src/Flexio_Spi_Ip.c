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

/**
*   @file    Flexio_Spi_Ip.c
*
*   @brief   FLEXIO_SPI low-level driver implementations.
*   @details FLEXIO_SPI low-level driver implementations.
*
*   @addtogroup FLEXIO_DRIVER Flexio_Spi Driver
*   @{
*/

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
#include "Mcal.h"
#include "Flexio_Spi_Ip.h"
#include "Flexio_Spi_Ip_Irq.h"
#include "Flexio_Spi_Ip_Cfg.h"
#include "OsIf.h"

#if (STD_ON == FLEXIO_SPI_IP_ENABLE)
#include "Flexio_Mcl_Ip_HwAccess.h"
#if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
   #include "Dma_Ip.h"
#endif
#if (STD_ON == FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT)
   #define USER_MODE_REG_PROT_ENABLED   (FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT)
   #include "RegLockMacros.h"
#endif
#include "SchM_Spi.h"
#if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif
#endif /*#if (FLEXIO_SPI_IP_ENABLE == STD_ON)*/

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_SPI_IP_VENDOR_ID_C                      43
#define FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_SPI_IP_SW_MAJOR_VERSION_C               2
#define FLEXIO_SPI_IP_SW_MINOR_VERSION_C               0
#define FLEXIO_SPI_IP_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == FLEXIO_SPI_IP_ENABLE)
        /* Check if current file and Mcal header file are of the same Autosar version */
        #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
             (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Flexio_Spi_Ip.c and Mcal.h are different"
        #endif

        #if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
            /* Check if current file and Dma_Ip header file are of the same Autosar version */
            #if ((DMA_IP_AR_RELEASE_MAJOR_VERSION != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C) || \
                 (DMA_IP_AR_RELEASE_MINOR_VERSION != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C))
                #error "AutoSar Version Numbers of Flexio_Spi_Ip.c and Dma_Ip.h are different"
            #endif
        #endif
        
        #if (STD_ON == FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT)
            #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
                 (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Flexio_Spi_Ip.c and RegLockMacros.h are different"
            #endif
        #endif

        /* Check if the current file and SchM_Spi.h header file are of the same version */
        #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_SPI_AR_RELEASE_MAJOR_VERSION) || \
             (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_SPI_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Flexio_Spi_Ip.c and SchM_Spi.h are different"
        #endif

        /* Check if the current file and OsIf.h header file are of the same version */
        #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
             (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Flexio_Spi_Ip.c and OsIf.h are different"
        #endif

        #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
            /* Check if the current file and Devassert.h header file are of the same version */
            #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
                 (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
                )
                #error "AutoSar Version Numbers of Flexio_Spi_Ip.c and Devassert.h are different"
            #endif
        #endif /* (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT) */

        /* Check if the current file and Flexio_Mcl_Ip_HwAccess.h header file are of the same version */
        #if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
             (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C != FLEXIO_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Flexio_Spi_Ip.c and Flexio_Mcl_Ip_HwAccess.h are different"
        #endif
    #endif /* (STD_ON == FLEXIO_SPI_IP_ENABLE) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Flexio_Spi_Ip.h and Flexio_Spi_Ip.c are of the same vendor */
#if (FLEXIO_SPI_IP_VENDOR_ID_C != FLEXIO_SPI_IP_VENDOR_ID)
    #error "Flexio_Spi_Ip.c and Flexio_Spi_Ip.h have different vendor ids"
#endif

/* Check if Flexio_Spi_Ip.c file and Flexio_Spi_Ip.h file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_C != FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexio_Spi_Ip.c and Flexio_Spi_Ip.h are different"
#endif

#if ((FLEXIO_SPI_IP_SW_MAJOR_VERSION_C != FLEXIO_SPI_IP_SW_MAJOR_VERSION) || \
     (FLEXIO_SPI_IP_SW_MINOR_VERSION_C != FLEXIO_SPI_IP_SW_MINOR_VERSION) || \
     (FLEXIO_SPI_IP_SW_PATCH_VERSION_C != FLEXIO_SPI_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_Spi_Ip.c and Flexio_Spi_Ip.h are different"
#endif

/* Check if Flexio_Spi_Ip_Irq.h and Flexio_Spi_Ip.c are of the same vendor */
#if (FLEXIO_SPI_IP_VENDOR_ID_C != FLEXIO_SPI_IP_IRQ_VENDOR_ID)
    #error "Flexio_Spi_Ip.c and Flexio_Spi_Ip_Irq.h have different vendor ids"
#endif

/* Check if Flexio_Spi_Ip.c file and Flexio_Spi_Ip_Irq.h file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_SPI_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_SPI_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_C != FLEXIO_SPI_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexio_Spi_Ip.c and Flexio_Spi_Ip_Irq.h are different"
#endif

#if ((FLEXIO_SPI_IP_SW_MAJOR_VERSION_C != FLEXIO_SPI_IP_IRQ_SW_MAJOR_VERSION) || \
     (FLEXIO_SPI_IP_SW_MINOR_VERSION_C != FLEXIO_SPI_IP_IRQ_SW_MINOR_VERSION) || \
     (FLEXIO_SPI_IP_SW_PATCH_VERSION_C != FLEXIO_SPI_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexio_Spi_Ip.c and Flexio_Spi_Ip_Irq.h are different"
#endif

/* Check if Flexio_Spi_Ip.c and Flexio_Spi_Ip_Cfg.h are of the same vendor */
#if (FLEXIO_SPI_IP_VENDOR_ID_C != FLEXIO_SPI_IP_VENDOR_ID_CFG)
    #error "Flexio_Spi_Ip.c and Flexio_Spi_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Flexio_Spi_Ip.c file and Flexio_Spi_Ip_Cfg.h file are of the same Autosar version */
#if ((FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_C != FLEXIO_SPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Flexio_Spi_Ip.c and Flexio_Spi_Ip_Cfg.h are different"
#endif

#if ((FLEXIO_SPI_IP_SW_MAJOR_VERSION_C != FLEXIO_SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_SW_MINOR_VERSION_C != FLEXIO_SPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLEXIO_SPI_IP_SW_PATCH_VERSION_C != FLEXIO_SPI_IP_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Flexio_Spi_Ip.c and Flexio_Spi_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (STD_ON == FLEXIO_SPI_IP_ENABLE)

#if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
    /* the maximum of Major loop when Minor loop Channel Linking Disabled */
    #define FLEXIO_SPI_IP_DMA_MAX_ITER_CNT_U16 ((uint16)0x7FFFu)
#endif
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                    GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

static Flexio_Spi_Ip_StateStructureType Flexio_Spi_Ip_axStateStructure[FLEXIO_SPI_IP_NUMBER_OF_INSTANCES];

#if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

Flexio_Spi_Ip_StateStructureType* Flexio_Spi_Ip_apxStateStructureArray[FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

static FLEXIO_Type* const Flexio_Spi_Ip_apxBases[FLEXIO_SPI_IP_INSTANCE_COUNT] = IP_FLEXIO_BASE_PTRS;

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

static void Flexio_Spi_Ip_TransferProcess(
                                            uint8 Instance,
                                            uint8 ShifterIndex,
                                            uint8 ShifterMaskFlag,
                                            uint8 ShifterErrMaskFlag
                                         );
#if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
static void Flexio_Spi_Ip_TxDmaConfig(uint8 Instance);
static void Flexio_Spi_Ip_RxDmaConfig(uint8 Instance);
static void Flexio_Spi_Ip_TxDmaContinueTransfer(uint8 Instance);
static void Flexio_Spi_Ip_RxDmaContinueTransfer(uint8 Instance);
#endif
#if (STD_ON == FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT)
void Flexio_Spi_Ip_SetUserAccess(uint8 Instance);
static void Flexio_Spi_Ip_SetUserAccessAllowed(uint8 Instance);
#endif /* FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT */

static void Flexio_Spi_Ip_WriteShifterBuffer
(
    uint8 Instance,
    uint8 TxShifterIndex
);

static void Flexio_Spi_Ip_ReadShifterBuffer
(
    uint8 Instance,
    uint8 RxShifterIndex
);

static void Flexio_Spi_Ip_ClearShifterTimerRegisters
(
    uint8 Instance
);
static void Flexio_Spi_Ip_ConfigExternalDevice
(
    const Flexio_Spi_Ip_StateStructureType *State
);

static void Flexio_Spi_Ip_SyncTransmitProcessData
(
    const uint8 InstanceFlexio
);
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief   This function is called by Flexio_Spi_Ip_IrqHandler or Flexio_Spi_Ip_ManageBuffers. It will process transfer in interrupt mode or polling mode.
* @details This function will fill Data into TX SHIFTBUF and read Data in RX SHIFTBUF fill to Rx Buffers.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
static void Flexio_Spi_Ip_TransferProcess(
                                            uint8 Instance,
                                            uint8 ShifterIndex,
                                            uint8 ShifterMaskFlag,
                                            uint8 ShifterErrMaskFlag
                                         )
{
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    boolean ErrorFlag = FALSE;
    uint8 TxShifterIndex = 0u;
    uint8 RxShifterIndex = 0u;

    if (FLEXIO_SPI_IP_BUSY == State->Status)
    {
        /* Get Shifters and timers index */
        TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;
        RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;
        
        if (0u != ShifterErrMaskFlag)
        {
            ErrorFlag = TRUE;
        }
        else
        {
            if (0u != ShifterMaskFlag)
            {
                /* Transmit */
                if (State->TxIndex != State->ExpectedFifoWrites)
                {
                    /* SHIFTBUF is available to transfer */
                    if (ShifterIndex == TxShifterIndex)
                    {
                        Flexio_Spi_Ip_WriteShifterBuffer(Instance, TxShifterIndex);
                    }
                }
                
                /* Receive */
                if (State->RxIndex != State->ExpectedFifoReads)
                {
                    /* SHIFTBUF is available to receive */
                    if (ShifterIndex == RxShifterIndex)
                    {
                        Flexio_Spi_Ip_ReadShifterBuffer(Instance, RxShifterIndex);
                    }
                }
            }

        }
        
        /* End of transfer */
        if ((State->RxIndex == State->ExpectedFifoReads) || (TRUE == ErrorFlag))
        {
            /* Disable ISRs */
            Flexio_Mcl_Ip_SetShifterInterrupt(Base, (1u<<TxShifterIndex) | (1u<<RxShifterIndex), FALSE);
            /* Disable Error interrupts */
            Flexio_Mcl_Ip_SetShifterErrorInterrupt(Base, (1u<<TxShifterIndex) | (1u<<RxShifterIndex), FALSE);
            
            if (TRUE == ErrorFlag)
            {
                State->Status = FLEXIO_SPI_IP_FAULT;
            }
            else
            {
                State->Status = FLEXIO_SPI_IP_IDLE;
            }
            if (State->Callback != NULL_PTR)
            {
                if (TRUE == ErrorFlag)
                {
                    State->Callback(Instance, FLEXIO_SPI_IP_EVENT_FAULT);
                }
                else
                {
                    State->Callback(Instance, FLEXIO_SPI_IP_EVENT_END_TRANSFER);
                }
            }
        }
    }
}

/**
* @brief   Configure Flexio register for an external device.
* @details This function initializes the SPI instance from Configurations in Slave or Master mode 
*          and other hardware specific parameters. This function won't initialize spi bus parameters.
*
* @param[in]      Configuration      Pointer to configurations of the hardware unit.
*/
static void Flexio_Spi_Ip_ConfigExternalDevice(
                                                const Flexio_Spi_Ip_StateStructureType *State
                                              )
{
    uint8 TxShifterIndex;
    uint8 RxShifterIndex;
    uint8 ClkTimerIndex;
    uint8 CsTimerIndex;
    uint8 InstanceFlexio;
    uint32 ClkTimerTrgsel;
    uint32 FrameSize;
    const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice;
    FLEXIO_Type* Base;

    Base = Flexio_Spi_Ip_apxBases[0];
    ExternalDevice = State->ExternalDevice;
    InstanceFlexio = ExternalDevice->Instance;
    /* Prepare frame size to write to TIMCMP register */
    FrameSize = ((uint32)ExternalDevice->DeviceParams->FrameSize * 2UL) - 1UL;

    /* Get Shifters and timers index */
    TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;
    RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;
    ClkTimerIndex = State->PhyUnitConfig->ClkTimerIndex;
    CsTimerIndex = State->PhyUnitConfig->CsTimerIndex;

    /* Select compatible shifter Status flag */
    ClkTimerTrgsel = ((uint32)TxShifterIndex * 4UL) + 1UL;

    /* Disable DMA requests and all interrupts before initialization, they will be enabled later */
    Flexio_Mcl_Ip_SetShifterInterrupt(Base, (1u << TxShifterIndex) | (1u << RxShifterIndex), FALSE);
    Flexio_Mcl_Ip_SetShifterDMARequest(Base, (1u << TxShifterIndex) | (1u << RxShifterIndex), FALSE);
    /* Disable error interrupt */
    Flexio_Mcl_Ip_SetShifterErrorInterrupt(Base, (1u << TxShifterIndex) | (1u << RxShifterIndex), FALSE);

    /* Clear Shifter and Timer Configuration registers */
    Flexio_Spi_Ip_ClearShifterTimerRegisters(InstanceFlexio);
    /* Clear Error status flag */
    Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, TxShifterIndex);
    Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, RxShifterIndex);
    /* Clear Rx shifter flag to avoid read data from previous transfer */
    Flexio_Mcl_Ip_ClearShifterStatus(Base, RxShifterIndex);

    /* Write to TX shifter SHIFTCTL */
    Base->SHIFTCTL[TxShifterIndex] = ExternalDevice->TxShiftCtl;
    /* Write to TX SHIFTCFG */
    Base->SHIFTCFG[TxShifterIndex] = ExternalDevice->TxShiftCfg;
    
    /* Write to RX shifter SHIFTCTL */
    Base->SHIFTCTL[RxShifterIndex] = ExternalDevice->RxShiftCtl;
    /* Write to RX SHIFTCFG */
    Base->SHIFTCFG[RxShifterIndex] = ExternalDevice->RxShiftCfg;

    /* Write to CLK Timer TIMCMP */
    /* Baudrate and frame size */
#if (STD_ON == FLEXIO_SPI_IP_SLAVE_SUPPORT)
    if (State->PhyUnitConfig->SlaveMode)
    {
        Base->TIMCMP[ClkTimerIndex] = FrameSize & ((uint32)FLEXIO_TIMCMP_CMP_MASK);
        /* Write to CLK Timer TIMCFG */
        Base->TIMCFG[ClkTimerIndex] = ExternalDevice->ClkTimeCfg;
        /* Write to CLK Timer TIMCTL */
        Base->TIMCTL[ClkTimerIndex] = ExternalDevice->ClkTimeCtl;
    }
    else
    {
#endif
        /* The value will be written to 8 upper bits fiel of TIMCMP */
        FrameSize = FrameSize << 8u;
        /* Write to CLK Timer TIMCFG */
        Base->TIMCFG[ClkTimerIndex] = ExternalDevice->ClkTimeCfg;
    #if ( STD_ON == FLEXIO_SPI_IP_DUAL_CLOCK_MODE)
        Base->TIMCMP[ClkTimerIndex] =  ( (ExternalDevice->ClkTimeCmpBaudRate[State->ClockMode] & FLEXIO_SPI_IP_TIMECMP_BAUDRATE_MASK_U32) \
                                    |  (FrameSize & FLEXIO_SPI_IP_TIMECMP_FRAMESIZE_MASK_U32) )  \
                                        & ((uint32)FLEXIO_TIMCMP_CMP_MASK);
        Base->TIMCFG[ClkTimerIndex] |= ExternalDevice->ClkTimeCfgTimDec[State->ClockMode];
    #else
        Base->TIMCMP[ClkTimerIndex] =  ( (ExternalDevice->ClkTimeCmpBaudRate & FLEXIO_SPI_IP_TIMECMP_BAUDRATE_MASK_U32) \
                                    |  (FrameSize & FLEXIO_SPI_IP_TIMECMP_FRAMESIZE_MASK_U32) )  \
                                        & ((uint32)FLEXIO_TIMCMP_CMP_MASK);
        Base->TIMCFG[ClkTimerIndex] |= ExternalDevice->ClkTimeCfgTimDec;
    #endif  
        /* Write to CLK Timer TIMCTL */
        Base->TIMCTL[ClkTimerIndex] = ExternalDevice->ClkTimeCtl | ((uint32)ClkTimerTrgsel << 24u);

        /* Write to CS Timer TIMCMP */
        Base->TIMCMP[CsTimerIndex] = ExternalDevice->CsTimeCmp;
        /* Write to CS Timer TIMCFG */
        Base->TIMCFG[CsTimerIndex] = ExternalDevice->CsTimeCfg;
        /* Write to CS Timer TIMCTL */
        Base->TIMCTL[CsTimerIndex] = ExternalDevice->CsTimeCtl;
#if (STD_ON == FLEXIO_SPI_IP_SLAVE_SUPPORT)
    }
#endif
}

static void Flexio_Spi_Ip_SyncTransmitProcessData(
                                                    const uint8 InstanceFlexio
                                                 )
{
    boolean IsShifterFlagRaised;
    uint8 TxShifterIndex;
    uint8 RxShifterIndex;
    const FLEXIO_Type *Base = (const FLEXIO_Type *)Flexio_Spi_Ip_apxBases[0];
    const Flexio_Spi_Ip_StateStructureType *State = (const Flexio_Spi_Ip_StateStructureType *)Flexio_Spi_Ip_apxStateStructureArray[InstanceFlexio];

    TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;
    RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;
    /* Transmit */
    if (State->TxIndex != State->ExpectedFifoWrites)
    {
        /* Get Tx shifter status */
        IsShifterFlagRaised = Flexio_Mcl_Ip_GetShifterStatus(Base, TxShifterIndex);
        /* SHIFTBUF is available to transfer */
        if (IsShifterFlagRaised)
        {
            Flexio_Spi_Ip_WriteShifterBuffer(InstanceFlexio, TxShifterIndex);
        }
    }

    /* Receive */
    if (State->RxIndex != State->ExpectedFifoReads)
    {
        /* Get Tx shifter status */
        IsShifterFlagRaised = Flexio_Mcl_Ip_GetShifterStatus(Base, RxShifterIndex);
        /* SHIFTBUF is available to read */
        if (IsShifterFlagRaised)
        {
            Flexio_Spi_Ip_ReadShifterBuffer(InstanceFlexio, RxShifterIndex);
        }
    }
}

#if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
/**
* @brief   This function will configure hardware TCDs for the channels TX DMA, RX DMA 
*          according to current transfer Configuration. DMA channels will be started at the end of the function.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
static void Flexio_Spi_Ip_TxDmaConfig(uint8 Instance)
{
    const FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[9u];
    uint16 NumberDmaIterWrite = State->ExpectedFifoWrites;
    uint8 TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;

    /* Limits number of major count */
    if (FLEXIO_SPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterWrite)
    {
        NumberDmaIterWrite = FLEXIO_SPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        /* Nothing to do */
    }

    /* Update buffers index */
    State->TxIndex = NumberDmaIterWrite;

    /* configure TX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    
    if (TRUE == State->ExternalDevice->DeviceParams->Lsb)
    {
        DmaTcdList[1u].Value = (uint32)&Base->SHIFTBUF[TxShifterIndex];    /* dest address write*/
    }
    else /* MSB mode */
    {
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            DmaTcdList[1u].Value = (uint32)&Base->SHIFTBUFBIS[TxShifterIndex] + 3u;    /* dest address write*/
        }
        else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            DmaTcdList[1u].Value = (uint32)&Base->SHIFTBUFBIS[TxShifterIndex] + 2u;    /* dest address write*/
        }
        else
        {
            DmaTcdList[1u].Value = (uint32)&Base->SHIFTBUFBIS[TxShifterIndex];    /* dest address write*/
        }
    }

    if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        DmaTcdList[2u].Value = 1u;  /* src offset is 1 byte */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
        DmaTcdList[5u].Value = 1u;   /* bytes to transfer for each request */
    }
    else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
    {
        DmaTcdList[2u].Value = 2u;  /* src offset is 2 bytes */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 bytes dest transfer size */
        DmaTcdList[5u].Value = 2u;   /* bytes to transfer for each request */
    }
    else
    {
        DmaTcdList[2u].Value = 4u;  /* src offset is 4 bytes */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 bytes src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 bytes dest transfer size */
        DmaTcdList[5u].Value = 4u;   /* bytes to transfer for each request */
    }
    DmaTcdList[6u].Value = 0u; /* no dest offset */
    DmaTcdList[7u].Value = NumberDmaIterWrite; /* iteration count */
    DmaTcdList[8u].Value = 1u; /* disable hardware request when major loop complete */
    if (NULL_PTR == State->TxBuffer)
    {
        /* send default Data */
        DmaTcdList[0u].Value = (uint32)&State->ExternalDevice->DeviceParams->DefaultData; /* src address read */
        DmaTcdList[2u].Value = 0u;  /* src offset is 0 byte */
    }
    else
    {
        DmaTcdList[0u].Value = (uint32)State->TxBuffer; /* src address read */
    }
    /* write TCD for TX DMA channel */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 9u);

    /* Enable TX DMA HW request */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

/**
* @brief   This function will configure hardware TCDs for the channels TX DMA, RX DMA 
*          according to current transfer Configuration. DMA channels will be started at the end of the function.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
static void Flexio_Spi_Ip_RxDmaConfig(uint8 Instance)
{
    const FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[9u];
    uint16 NumberDmaIterWrite = State->ExpectedFifoReads;
    uint8 RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;
    static uint32 Flexio_Spi_Ip_u32DiscardData;

    /* Limits number of major count */
    if (FLEXIO_SPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterWrite)
    {
        NumberDmaIterWrite = FLEXIO_SPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        /* Nothing to do */
    }

    /* Update buffers index */
    State->RxIndex = NumberDmaIterWrite;

    /* configure RX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;

    /* LSB mode */
    if (TRUE == State->ExternalDevice->DeviceParams->Lsb)
    {
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            DmaTcdList[0u].Value = (uint32)&Base->SHIFTBUF[RxShifterIndex] + 3u; /* src address read */
        }
        else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            DmaTcdList[0u].Value = (uint32)&Base->SHIFTBUF[RxShifterIndex] + 2u; /* src address read */
        }
        else 
        {
            DmaTcdList[0u].Value = (uint32)&Base->SHIFTBUF[RxShifterIndex]; /* src address read */
        }
    }
    else /* MSB mode */
    {
        DmaTcdList[0u].Value = (uint32)&Base->SHIFTBUFBIS[RxShifterIndex]; /* src address read */
    }
    
    DmaTcdList[2u].Value = 0u;  /* no src offset */
    if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
        DmaTcdList[5u].Value = 1u;   /* 1 byte to transfer for each request */
        DmaTcdList[6u].Value = 1u; /* dest offset is 1 bytes */
    }
    else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
    {
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 bytes dest transfer size */
        DmaTcdList[5u].Value = 2u;   /* 2 bytes to transfer for each request */
        DmaTcdList[6u].Value = 2u; /* dest offset is 2 bytes */
    }
    else
    {
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 bytes src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 bytes dest transfer size */
        DmaTcdList[5u].Value = 4u;   /* 4 bytes to transfer for each request */
        DmaTcdList[6u].Value = 4u; /* dest offset is 4 bytes */
    }
    if (NULL_PTR == State->RxBuffer)
    {
        /* Discard Data */
        DmaTcdList[1u].Value = (uint32)&Flexio_Spi_Ip_u32DiscardData;    /* dest address write*/
        DmaTcdList[6u].Value = 0u; /* dest offset is 0 bytes */
    }
    else
    {
        /* Avoid misra */
        (void)Flexio_Spi_Ip_u32DiscardData;
        DmaTcdList[1u].Value = (uint32)State->RxBuffer;    /* dest address write*/
    }
    DmaTcdList[7u].Value = NumberDmaIterWrite; /* iteration count */
    DmaTcdList[8u].Value = 1u; /* disable hardware request when major loop complete */
    /* write TCD for RX DMA channel */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 9u);

    /* Enable RX DMA HW request */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

static void Flexio_Spi_Ip_TxDmaContinueTransfer(uint8 Instance)
{
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];
    uint16 NumberDmaIterWrite = State->ExpectedFifoWrites - State->TxIndex;
    uint8 TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;

    /* Limits number of major count */
    if (FLEXIO_SPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterWrite)
    {
        NumberDmaIterWrite = FLEXIO_SPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        /* Nothing to do */
    }

    State->TxIndex += NumberDmaIterWrite;

    /* Update TX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[0u].Value = NumberDmaIterWrite;    /* iteration count */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 1u);

    /* Disable TX DMA request to avoid overflow because RX DMA needs time to be initialized for next transfer,
    TX DMA request will be enabled later when RX DMA complete by Flexio_Spi_Ip_RxDmaContinueTransfer. */
    Flexio_Mcl_Ip_SetShifterDMARequest(Base, 1u << TxShifterIndex, FALSE);
    
    /* Enable TX DMA HW request for TX DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    /* Push first frame to TX FIFO to ensure that previous received frame will be pushed to RX FIFO and RX DMA can be completed in the case of CS continue */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_SOFTWARE_REQUEST);
}

static void Flexio_Spi_Ip_RxDmaContinueTransfer(uint8 Instance)
{
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    Flexio_Spi_Ip_StateStructureType* State =  Flexio_Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];
    uint16 NumberDmaIterWrite = State->ExpectedFifoReads - State->RxIndex;
    uint8 TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;

    /* Limits number of major count */
    if (FLEXIO_SPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterWrite)
    {
        NumberDmaIterWrite = FLEXIO_SPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        /* Nothing to do */
    }

    State->RxIndex += NumberDmaIterWrite;

    /* Update RX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[0u].Value = NumberDmaIterWrite;    /* iteration count */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 1u);

    /* Enable DMA HW request for RX DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    /* Enable TX DMA request due to it is disabled in Flexio_Spi_Ip_TxDmaContinueTransfer */
    Flexio_Mcl_Ip_SetShifterDMARequest(Base, 1u << TxShifterIndex, TRUE);
}

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   This function will process TX DMA transfer complete interrupt. 
* @details This function will process continue transfer or end of transfer via TX DMA.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
* @implements Flexio_Spi_Ip_IrqTxDmaHandler_Activity
*/
void Flexio_Spi_Ip_IrqTxDmaHandler(uint8 Instance)
{
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    boolean ErrorFlag = FALSE;
    uint8 TxShifterIndex = 0u;
    uint8 RxShifterIndex = 0u;
    boolean IsTxShifterErrorRaised = FALSE;
    boolean IsRxShifterErrorRaised = FALSE;

    if (NULL_PTR != State)
    {
        if (FLEXIO_SPI_IP_BUSY == State->Status)
        {
            /* Get Shifters and timers index */
            TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;
            RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;
            /* Read error Status and clear flags. */
            IsTxShifterErrorRaised = Flexio_Mcl_Ip_GetShifterErrorStatus(Base, TxShifterIndex);
            IsRxShifterErrorRaised = Flexio_Mcl_Ip_GetShifterErrorStatus(Base, RxShifterIndex);
            /* Clear shifter error flag */
            Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, TxShifterIndex);
            Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, RxShifterIndex);

            if (IsTxShifterErrorRaised || IsRxShifterErrorRaised)
            {
                /* mark error flag */
                ErrorFlag = TRUE;
            }
            else
            {
                if (State->ExpectedFifoWrites != State->TxIndex)
                {
                    /* Transfer is not finished => update TX pointers */
                    Flexio_Spi_Ip_TxDmaContinueTransfer(Instance);
                }
                else
                {
                    /* Disable TX DMA request to avoid overflow because RX DMA needs time to be initialized for next transfer,
                    TX DMA request will be enabled later when RX DMA completed and next transfer initialized by Flexio_Spi_Ip_AsyncTransmit. */
                    Flexio_Mcl_Ip_SetShifterDMARequest(Base, 1u << TxShifterIndex, FALSE);
                    Flexio_Spi_Ip_TxDmaConfig(Instance);
                }
            }
            
            if (TRUE == ErrorFlag)
            {
                /* Disable DMA requests. */
                Flexio_Mcl_Ip_SetShifterDMARequest(Base, (1u << TxShifterIndex) | (1u << RxShifterIndex), FALSE);

                /* Disable RX DMA HW request because may RX DMA is not completed, no need to apply for TX DMA due to DMA HW request is cleared automatically */
                (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
                State->Status = FLEXIO_SPI_IP_FAULT;
                if (State->Callback != NULL_PTR)
                {
                    State->Callback(Instance, FLEXIO_SPI_IP_EVENT_FAULT);
                }
            }
        }
    }
    else
    {
        /* Driver is initialized but there was no poll request*/
        /* nothing to do */
    }
}

/**
* @brief   This function will process RX DMA transfer complete interrupt. 
* @details This function will process continue transfer or end of transfer via RX DMA.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
* @implements Flexio_Spi_Ip_IrqRxDmaHandler_Activity
*/
void Flexio_Spi_Ip_IrqRxDmaHandler(uint8 Instance)
{
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    boolean ErrorFlag = FALSE;
    uint8 TxShifterIndex = 0u;
    uint8 RxShifterIndex = 0u;
    boolean EndOfTransferFlag = FALSE;
    boolean IsTxShifterErrorRaised = FALSE;
    boolean IsRxShifterErrorRaised = FALSE;


    if (NULL_PTR != State)
    {
        if (FLEXIO_SPI_IP_BUSY == State->Status)
        {
            /* Get Shifters and timers index */
            TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;
            RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;
            /* Read error Status and clear flags. */
            IsTxShifterErrorRaised = Flexio_Mcl_Ip_GetShifterErrorStatus(Base, TxShifterIndex);
            IsRxShifterErrorRaised = Flexio_Mcl_Ip_GetShifterErrorStatus(Base, RxShifterIndex);
            /* Clear shifter error flag */
            Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, TxShifterIndex);
            Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, RxShifterIndex);

            if (IsTxShifterErrorRaised || IsRxShifterErrorRaised)
            {
                 /* mark error flag */
                ErrorFlag = TRUE;
            }
            else
            {
                if (State->ExpectedFifoReads != State->RxIndex)
                {
                    /* Transfer is not finished => update RX pointers */
                    Flexio_Spi_Ip_RxDmaContinueTransfer(Instance);
                }
                else
                {
                    EndOfTransferFlag = TRUE;
                }
            }

            if ((TRUE == EndOfTransferFlag) || (TRUE == ErrorFlag))
            {
                /* Disable DMA requests. */
                Flexio_Mcl_Ip_SetShifterDMARequest(Base, (1u << TxShifterIndex) | (1u << RxShifterIndex), FALSE);

                if (TRUE == ErrorFlag)
                {
                    State->Status = FLEXIO_SPI_IP_FAULT;
                    /* Disable TX DMA HW request because may TX DMA is not completed, no need to apply for RX DMA due to DMA HW request is cleared automatically */
                    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
                }
                else
                {
                    State->Status = FLEXIO_SPI_IP_IDLE;
                }
                if (State->Callback != NULL_PTR)
                {
                    if (TRUE == ErrorFlag)
                    {
                        State->Callback(Instance, FLEXIO_SPI_IP_EVENT_FAULT);
                    }
                    else
                    {
                        State->Callback(Instance, FLEXIO_SPI_IP_EVENT_END_TRANSFER);
                    }
                }
            }
        }
    }
    else
    {
        /* Driver is initialized but there was no poll request*/
        /* nothing to do */
    }
}
#endif /* (STD_ON == FLEXIO_SPI_IP_DMA_USED) */

#if (STD_ON == FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT)
/**
* @brief This function will set UAA bit in REG_PROT for SPI unit
*/
void Flexio_Spi_Ip_SetUserAccess(uint8 Instance)
{
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    
    SET_USER_ACCESS_ALLOWED((uint32)Base,FLEXIO_SPI_IP_PROT_MEM_U32);
}

/**
* @brief This function will enable writing all SPI registers under protection in User mode by configuring REG_PROT
*/
static void Flexio_Spi_Ip_SetUserAccessAllowed(uint8 Instance)
{
    OsIf_Trusted_Call1param(Flexio_Spi_Ip_SetUserAccess, Instance);
}
#endif /* FLEXIO_SPI_IP_ENABLE_USER_MODE_SUPPORT */

/**
* @brief This function will write to Shifter buffer
*/
static void Flexio_Spi_Ip_WriteShifterBuffer
(
    uint8 Instance,
    uint8 TxShifterIndex
)
{
    Flexio_Spi_Ip_StateStructureType *State;
    uint32 Data;
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    
    if (NULL_PTR != State->TxBuffer)
    {
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            Data = *((const uint8*)(&State->TxBuffer[State->TxIndex]));
        }
        else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            Data = *((const uint16*)(&State->TxBuffer[2u * State->TxIndex]));
        }
        else
        {
            Data = *((const uint32*)(&State->TxBuffer[4u * State->TxIndex]));
        }
    }
    else
    {
        Data = State->ExternalDevice->DeviceParams->DefaultData;
    }
    /* Write to SHIFTBUF */
    /* LSB mode */
    if (TRUE == State->ExternalDevice->DeviceParams->Lsb)
    {
        Base->SHIFTBUF[TxShifterIndex] = Data;
    }
    else /* MSB mode */
    {
        Data = Data << (32u - State->ExternalDevice->DeviceParams->FrameSize);
        Base->SHIFTBUFBIS[TxShifterIndex] = Data;
    }
    State->TxIndex++;
}

/**
* @brief This function will write to Shifter buffer
*/
static void Flexio_Spi_Ip_ReadShifterBuffer
(
    uint8 Instance,
    uint8 RxShifterIndex
)
{
    Flexio_Spi_Ip_StateStructureType *State;
    uint32 Data = 0u;
    const FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    
    /* LSB mode */
    if (TRUE == State->ExternalDevice->DeviceParams->Lsb)
    {
        Data = Base->SHIFTBUF[RxShifterIndex];
        Data = Data >> (32u - State->ExternalDevice->DeviceParams->FrameSize);
    }
    else /* MSB mode */
    {
        Data = Base->SHIFTBUFBIS[RxShifterIndex];
    }

    if (NULL_PTR != State->RxBuffer)
    {
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            *((uint8*)(&State->RxBuffer[State->RxIndex])) = (uint8)Data;
        }
        else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            *((uint16*)(&State->RxBuffer[2u * State->RxIndex])) = (uint16)Data;
        }
        else
        {
            *((uint32*)(&State->RxBuffer[4u * State->RxIndex])) = Data;
        }
    }
    else
    {
        /* Discard data */
        (void)Data;
    }

    State->RxIndex++;
}

/**
* @brief This function will clear all shifter and timer Configuration registers at beginning of transfer function.
*/
static void Flexio_Spi_Ip_ClearShifterTimerRegisters(
                                                        uint8 Instance
                                                    )
{
    const Flexio_Spi_Ip_StateStructureType *State;
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    uint8 TxShifterIndex = 0u;
    uint8 RxShifterIndex = 0u;
#if (STD_ON == FLEXIO_SPI_IP_SLAVE_SUPPORT)
    uint8 ClkTimerIndex = 0u;
#endif
    State = (const Flexio_Spi_Ip_StateStructureType *)Flexio_Spi_Ip_apxStateStructureArray[Instance];
    TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;
    RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;
    
    Base->SHIFTCTL[TxShifterIndex] = (uint32)0U;
    Base->SHIFTCTL[RxShifterIndex] = (uint32)0U;
    
    Base->SHIFTCFG[TxShifterIndex] = (uint32)0U;
    Base->SHIFTCFG[RxShifterIndex] = (uint32)0U;
#if (STD_ON == FLEXIO_SPI_IP_SLAVE_SUPPORT)
    ClkTimerIndex = State->PhyUnitConfig->ClkTimerIndex;
    if (State->PhyUnitConfig->SlaveMode)
    {
        Base->TIMCMP[ClkTimerIndex] = (uint32)0U;
        Base->TIMCFG[ClkTimerIndex] = (uint32)0U;
        Base->TIMCTL[ClkTimerIndex] = (uint32)0U;
    }
#endif
}

/**
* @brief   FLEXIO_SPI peripheral initialization.
* @details This function initializes the SPI instance from Configurations in Slave or Master mode 
*          and other hardware specific parameters. This function won't initialize spi bus parameters.
*
* @param[in]      PhyUnitConfigPtr      Pointer to configurations of the hardware unit.
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_Init(const Flexio_Spi_Ip_ConfigType *PhyUnitConfigPtr)
{
    Flexio_Spi_Ip_StateStructureType* State;
    Flexio_Spi_Ip_StatusType Status = FLEXIO_SPI_IP_STATUS_SUCCESS;
    uint8 FlexioInstance = 0u;

    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(PhyUnitConfigPtr != NULL_PTR);
    #endif
    FlexioInstance = PhyUnitConfigPtr->Instance;
    State = Flexio_Spi_Ip_apxStateStructureArray[FlexioInstance];
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(State == NULL_PTR);
    #endif
    {
        Flexio_Spi_Ip_apxStateStructureArray[FlexioInstance] = &Flexio_Spi_Ip_axStateStructure[PhyUnitConfigPtr->StateIndex];
        State = Flexio_Spi_Ip_apxStateStructureArray[FlexioInstance];
        State->PhyUnitConfig = PhyUnitConfigPtr;
        /* get  Framesize, LSB/MSB, Clock mode, Default Data, Slave mode values if this fucntion is only called from IP labyer */
        #if ( STD_ON == FLEXIO_SPI_IP_DUAL_CLOCK_MODE)
        State->ClockMode = FLEXIO_SPI_IP_NORMAL_CLOCK;
        #endif
        /* set default value of FirstChannel */
        State->FirstChannel = TRUE;
        /* set State to idle */
        State->Status = FLEXIO_SPI_IP_IDLE;
        /* Set to Polling mode by default */
        (void)Flexio_Spi_Ip_UpdateTransferMode(FlexioInstance, FLEXIO_SPI_IP_POLLING);
    }
    return Status;
}

/**
* @brief   This function performs the de-initialization of a specific peripheral unit.
* @details This function de-initializes all configured values
*          in all registers.
*
* @param[in]     Instance      Index of the hardware instance.
*
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_DeInit(uint8 Instance)
{
    const Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    Flexio_Spi_Ip_StatusType Status = FLEXIO_SPI_IP_STATUS_SUCCESS;

    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8 > Instance);
    DevAssert(NULL_PTR != State);
    #endif
    if (FLEXIO_SPI_IP_BUSY == State->Status)
    {
        Status = FLEXIO_SPI_IP_STATUS_FAIL;
    }
    else
    {

        Flexio_Spi_Ip_apxStateStructureArray[Instance] = NULL_PTR;
    }
    return Status;
}
/**
* @brief   This function performs the synchronous transmission.
* @details This function performs spi transfer by synchronous method
*
* @param[in]     Sequence      Specifies the sequence for which we will have
*                              the synchronous transmission
*
* @return Flexio_Spi_Ip_StatusType
* @retval FLEXIO_SPI_IP_STATUS_SUCCESS  Transmission command has been completed
* @retval FLEXIO_SPI_IP_STATUS_FAIL     Transmission command has been incompleted
*
* @implements Flexio_Spi_Ip_SyncTransmit
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_SyncTransmit(
                                                    const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice,
                                                    const uint8* TxBuffer,
                                                    uint8* RxBuffer,
                                                    uint16 Length,
                                                    uint32 TimeOut
                                                   )
{
    Flexio_Spi_Ip_StateStructureType *State;
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    Flexio_Spi_Ip_StatusType Status = FLEXIO_SPI_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(TimeOut, FLEXIO_SPI_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
    uint8 TxShifterIndex = 0u;
    uint8 RxShifterIndex = 0u;
    uint8 InstanceFlexio = 0u;
    boolean TxShifterError = FALSE;
    boolean RxShifterError = FALSE;

    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != ExternalDevice);
    DevAssert(0u != Length);
    DevAssert(0u != TimeOut);
    #endif
    InstanceFlexio = ExternalDevice->Instance;
    State = Flexio_Spi_Ip_apxStateStructureArray[InstanceFlexio];
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_17();
    if (FLEXIO_SPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_17();
        Status = FLEXIO_SPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark the hardware as busy. */
        State->Status = FLEXIO_SPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_17();

        /* Get Shifters and timers index */
        TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;
        RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;

        /* Update State structure */
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            State->ExpectedFifoWrites = Length;
        }
        else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            State->ExpectedFifoWrites = Length/2u;
        }
        else
        {
            State->ExpectedFifoWrites = Length/4u;
        }

        /* Update Data buffer */
        State->ExpectedFifoReads = State->ExpectedFifoWrites;
        State->TxIndex = 0u;
        State->TxBuffer = TxBuffer;
        State->RxIndex = 0u;
        State->RxBuffer = RxBuffer;
        /* Configure timer, shifter registers to start transfer */
        Flexio_Spi_Ip_ConfigExternalDevice(State);

        CurrentTicks = OsIf_GetCounter(FLEXIO_SPI_IP_TIMEOUT_METHOD); /* initialize current counter */
        while (((State->RxIndex != State->ExpectedFifoReads) || (State->TxIndex != State->ExpectedFifoWrites)) && (FLEXIO_SPI_IP_STATUS_SUCCESS == Status))
        {
            ElapsedTicks = 0;
            /* Process transmitting and receiving data */
            Flexio_Spi_Ip_SyncTransmitProcessData(InstanceFlexio);

            /* Check if errors like overflow or underflow are reported in Status register. */
            TxShifterError = Flexio_Mcl_Ip_GetShifterErrorStatus(Base, TxShifterIndex);
            RxShifterError = Flexio_Mcl_Ip_GetShifterErrorStatus(Base, RxShifterIndex);
            if (TxShifterError || RxShifterError)
            {
                /* If underflow */
                if (TxShifterError)
                {
                    Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, TxShifterIndex);
                }
                /* If overflow */
                if (RxShifterError)
                {
                    Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, RxShifterIndex);
                }
                Status = FLEXIO_SPI_IP_FIFO_ERROR;
            }
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, FLEXIO_SPI_IP_TIMEOUT_METHOD);
            if (ElapsedTicks >= TimeoutTicks)
            {
                Status = FLEXIO_SPI_IP_TIMEOUT;
            }
        }
    }
    if ((FLEXIO_SPI_IP_STATUS_SUCCESS != Status) || (0u == Length))
    {
#if (STD_OFF == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
        /* Return Fail status if length is 0. Error Detect is enabled, nothing need to be done here */
        if (0u == Length)
        {
            Status = FLEXIO_SPI_IP_STATUS_FAIL;
        }
#endif
        State->Status = FLEXIO_SPI_IP_FAULT;
    }
    else
    {
        State->Status = FLEXIO_SPI_IP_IDLE;
    }
    return Status;
}

/**
* @brief   This function performs the asynchronous transmission.
* @details This function performs spi transfer by asynchronous method
*
* @param[in]     Sequence      Specifies the sequence for which we will have
*                              the asynchronous transmission
*
* @return Flexio_Spi_Ip_StatusType
* @retval FLEXIO_SPI_IP_STATUS_SUCCESS  Transmission command has been started
* @retval FLEXIO_SPI_IP_STATUS_FAIL     Transmission command has not been accepted
*
* @implements Flexio_Spi_Ip_AsyncTransmit
*/
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_AsyncTransmit(
                                       const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice,
                                       const uint8* TxBuffer,
                                       uint8* RxBuffer,
                                       uint16 Length,
                                       Flexio_Spi_Ip_CallbackType EndCallback
                                      )
{
    Flexio_Spi_Ip_StateStructureType *State;
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    Flexio_Spi_Ip_StatusType Status = FLEXIO_SPI_IP_STATUS_SUCCESS;
    uint8 TxShifterIndex = 0u;
    uint8 RxShifterIndex = 0u;
    uint8 InstanceFlexio = 0u;

    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != ExternalDevice);
    DevAssert(0u != Length);
    #endif
    InstanceFlexio = ExternalDevice->Instance;
    State = Flexio_Spi_Ip_apxStateStructureArray[InstanceFlexio];
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
    DevAssert(!(
              (TRUE == State->PhyUnitConfig->DmaUsed) &&
              (FALSE == ExternalDevice->DeviceParams->Lsb) &&
              (
                (8u != ExternalDevice->DeviceParams->FrameSize) &&
                (16u != ExternalDevice->DeviceParams->FrameSize) &&
                (32u != ExternalDevice->DeviceParams->FrameSize)
              ))
             );
    #endif
    #endif /* (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT) */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_18();
    if (FLEXIO_SPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_18();
        Status = FLEXIO_SPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark the hardware as busy. */
        State->Status = FLEXIO_SPI_IP_BUSY;
        State->ExternalDevice = ExternalDevice;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_18();

        /* Get Shifters and timers index */
        TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;
        RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;

        /* Update State structure */
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            State->ExpectedFifoWrites = Length;
        }
        else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            State->ExpectedFifoWrites = Length/2u;
        }
        else
        {
            State->ExpectedFifoWrites = Length/4u;
        }

        /* Update Data buffer */
        State->ExpectedFifoReads = State->ExpectedFifoWrites;
        State->TxIndex = 0u;
        State->TxBuffer = TxBuffer;
        State->RxIndex = 0u;
        State->RxBuffer = RxBuffer;
        /* Configure timer, shifter registers to start transfer */
        Flexio_Spi_Ip_ConfigExternalDevice(State);

        /* Update State structure. */
        State->Callback = EndCallback;

        #if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
        if (FALSE == State->PhyUnitConfig->DmaUsed)
        #endif
        {
            /* Set mode */
            switch (State->TransferMode)
            {
                case FLEXIO_SPI_IP_POLLING:
                    /* Disable interrupts. It was done at beginning of this function */
                    break;
                case FLEXIO_SPI_IP_INTERRUPT:
                    /* Enable intterrupts. Both tranfer and Error ISRs */
                    Flexio_Mcl_Ip_SetShifterErrorInterrupt(Base, (1u << TxShifterIndex)|(1u << RxShifterIndex), TRUE);
                    Flexio_Mcl_Ip_SetShifterInterrupt(Base, (1u << TxShifterIndex)|(1u << RxShifterIndex), TRUE);
                    break;
                default:
                    /* Nothing to do */
                    break;
            }
        }
        #if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
        else
        {
            /* Initialize DMA Configuration for RX before TX*/
            Flexio_Spi_Ip_RxDmaConfig(InstanceFlexio);
            if (State->FirstChannel)
            {
                Flexio_Spi_Ip_TxDmaConfig(InstanceFlexio);
            }
            /* Enable DMA request. */
            Flexio_Mcl_Ip_SetShifterDMARequest(Base, (1u<<TxShifterIndex)|(1u<<RxShifterIndex), TRUE);
        }
        #endif
    }
    return Status;
}

void Flexio_Spi_Ip_ManageBuffers(uint8 Instance)
{
    #if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
    Dma_Ip_LogicChannelStatusType DmaChannelStatus;
    #endif
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0u];
    const Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    uint8 TxShifterIndex = 0u;
    uint8 RxShifterIndex = 0u;
    uint8 ShifterMaskFlag         = (uint8)0U;
    uint8 ShifterErrMaskFlag      = (uint8)0U;
    uint8 TxRxMask = 0u;

    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8 > Instance);
    DevAssert(NULL_PTR != State);
    #endif
    if (FLEXIO_SPI_IP_POLLING == State->TransferMode)
    {
        /* Get Shifters and timers index */
        TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;
        RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;
        
        TxRxMask = ((uint8)(1u<<TxShifterIndex) | (uint8)(1u<<RxShifterIndex));
        
        ShifterMaskFlag        = (uint8)Flexio_Mcl_Ip_GetAllShifterStatus(Base) & TxRxMask;
        ShifterErrMaskFlag     = (uint8)Flexio_Mcl_Ip_GetAllShifterErrorStatus(Base) & TxRxMask;
        /* Clear error flag, transfer flag will be cleared automatically by write/read shifter buffer */
        Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, TxShifterIndex);
        Flexio_Mcl_Ip_ClearShifterErrorStatus(Base, RxShifterIndex);
    
        #if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
        if(FALSE == State->PhyUnitConfig->DmaUsed)
        #endif
        {
            /* TX ISR */
            if ( ((ShifterMaskFlag & (1u<<TxShifterIndex)) != 0u) || ((ShifterErrMaskFlag & (1u<<TxShifterIndex)) != 0u) )
            {
                Flexio_Spi_Ip_TransferProcess(Instance, TxShifterIndex, ShifterMaskFlag, ShifterErrMaskFlag);
            }
            /* RX ISR */
            if ( ((ShifterMaskFlag & (1u<<RxShifterIndex)) != 0u) || ((ShifterErrMaskFlag & (1u<<RxShifterIndex)) != 0u) )
            {
                Flexio_Spi_Ip_TransferProcess(Instance, RxShifterIndex, ShifterMaskFlag, ShifterErrMaskFlag);
            }
        }
        #if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
        else
        {
            DmaChannelStatus.Done = FALSE;
            /* Polling RX before TX */
            (void)Dma_Ip_GetLogicChannelStatus(State->PhyUnitConfig->RxDmaChannel, &DmaChannelStatus);
            if(TRUE == DmaChannelStatus.Done)
            {
                /* Clear DONE bit */
                (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_CLEAR_DONE);
                Flexio_Spi_Ip_IrqRxDmaHandler(Instance);
            }
            
            (void)Dma_Ip_GetLogicChannelStatus(State->PhyUnitConfig->TxDmaChannel, &DmaChannelStatus);
            if(TRUE == DmaChannelStatus.Done)
            {
                /* Clear DONE bit */
                (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_CLEAR_DONE);
                Flexio_Spi_Ip_IrqTxDmaHandler(Instance);
            }
        }
        #endif
    }
}

Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_UpdateFrameSize(const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice, uint8 FrameSize)
{
    const Flexio_Spi_Ip_StateStructureType* State;
    Flexio_Spi_Ip_StatusType Status = FLEXIO_SPI_IP_STATUS_SUCCESS;

    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != ExternalDevice);
    DevAssert(FLEXIO_SPI_IP_FRAMESIZE_MAX_U8 >= FrameSize);
    DevAssert(FLEXIO_SPI_IP_FRAMESIZE_MIN_U8 <= FrameSize);
    #endif
    State = Flexio_Spi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    /* Frame size can be changed when no transfers are in progress. */
    if (FLEXIO_SPI_IP_BUSY != State->Status)
    {
        ExternalDevice->DeviceParams->FrameSize = FrameSize;
    }
    else
    {
        Status = FLEXIO_SPI_IP_STATUS_FAIL;
    }
    return Status;
}

Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_UpdateLsb(const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice, boolean Lsb)
{
    const Flexio_Spi_Ip_StateStructureType* State;
    Flexio_Spi_Ip_StatusType Status = FLEXIO_SPI_IP_STATUS_SUCCESS;
    
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != ExternalDevice);
    #endif
    State = Flexio_Spi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    /* Bite order can be changed when no transfers are in progress. */
    if (FLEXIO_SPI_IP_BUSY != State->Status)
    {
        ExternalDevice->DeviceParams->Lsb = Lsb;
    }
    else
    {
        Status = FLEXIO_SPI_IP_STATUS_FAIL;
    }
    return Status;
}

Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_UpdateDefaultTransmitData(const Flexio_Spi_Ip_ExternalDeviceType *ExternalDevice, uint32 DefaultData)
{
    const Flexio_Spi_Ip_StateStructureType* State;
    Flexio_Spi_Ip_StatusType Status = FLEXIO_SPI_IP_STATUS_SUCCESS;
    
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != ExternalDevice);
    #endif
    State = Flexio_Spi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != State);
    #endif
    /* Bit order can be changed when no transfers are in progress. */
    if (FLEXIO_SPI_IP_BUSY != State->Status)
    {
        ExternalDevice->DeviceParams->DefaultData = DefaultData;
    }
    else
    {
        Status = FLEXIO_SPI_IP_STATUS_FAIL;
    }
    return Status;
}

Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_UpdateTransferMode(uint8 Instance, Flexio_Spi_Ip_ModeType Mode)
{
    Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];
    #endif
    Flexio_Spi_Ip_StatusType Status = FLEXIO_SPI_IP_STATUS_SUCCESS;

    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8 > Instance);
    DevAssert(NULL_PTR != State);
    #endif
    /* Transfer mode can be changed when no transfers are in progress. */
    if (FLEXIO_SPI_IP_BUSY != State->Status)
    {
        State->TransferMode = Mode;
        #if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
        if(TRUE == State->PhyUnitConfig->DmaUsed)
        {
            /* Activate TX DMA and RX DMA interrupt in interrupt mode or disable then in polling mode. */
            DmaTcdList[0u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
            switch(Mode)
            {
                case FLEXIO_SPI_IP_POLLING:
                    /* Disable DMA major interrupt. */
                    DmaTcdList[0u].Value = 0u;
                    break;
                case FLEXIO_SPI_IP_INTERRUPT:
                    /* Enable DMA major interrupt. */
                    DmaTcdList[0u].Value = 1u;
                    break;
                default:
                    /* Nothing to do */
                    break;
            }
            (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 1u);
            (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 1u);
        }
        #endif
    }
    else
    {
        Status = FLEXIO_SPI_IP_STATUS_FAIL;
    }
    return Status;
}
 
void Flexio_Spi_Ip_Cancel(uint8 Instance)
{
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    uint8 TxShifterIndex = 0u;
    uint8 RxShifterIndex = 0u;
    uint8 ClkTimerIndex = 0u;
    
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8 > Instance);
    DevAssert(NULL_PTR != State);
    #endif
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_16();
    if (FLEXIO_SPI_IP_BUSY == State->Status)
    {
        /* Get Shifters and timers index */
        TxShifterIndex = State->PhyUnitConfig->TxShifterIndex;
        RxShifterIndex = State->PhyUnitConfig->RxShifterIndex;
        ClkTimerIndex = State->PhyUnitConfig->ClkTimerIndex;
        
        /* Disable interrupts and DMA requests. */
        Flexio_Mcl_Ip_SetShifterInterrupt(Base, (1u<<TxShifterIndex)|(1u<<RxShifterIndex), FALSE);
        Flexio_Mcl_Ip_SetShifterDMARequest(Base, (1u<<TxShifterIndex)|(1u<<RxShifterIndex), FALSE);
        /* Disable error interrupt */
        Flexio_Mcl_Ip_SetShifterErrorInterrupt(Base, (1u << TxShifterIndex) | (1u << RxShifterIndex), FALSE);
        
        #if (STD_ON == FLEXIO_SPI_IP_DMA_USED)
        if(TRUE == State->PhyUnitConfig->DmaUsed)
        {
            /* Disable all HW request */
            (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        }
        #endif
        /* Remove CLK TIMER Configuration */
        Base->TIMCMP[ClkTimerIndex] =  (uint32)0u;
        Base->TIMCFG[ClkTimerIndex] = (uint32)0u;
        Base->TIMCTL[ClkTimerIndex] = (uint32)0u;
        
        /* Clear SHFIBUF */
        Base->SHIFTBUF[TxShifterIndex] = (uint32)0u;
        Base->SHIFTBUF[RxShifterIndex] = (uint32)0u;
        Base->SHIFTBUFBIS[TxShifterIndex] = (uint32)0u;
        Base->SHIFTBUFBIS[RxShifterIndex] = (uint32)0u;
        
        /* set State to idle */
        State->Status = FLEXIO_SPI_IP_IDLE;
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_16();
}
/*****************************************************************************************/
/**
* @brief   This function is called by FLEXIO ISRs.
* @details This function will process activities for flags TDF, RDF, REF and TEF.
*
* @param[in]     Instance            Instance of the hardware unit.
*
* @implements Flexio_Spi_Ip_IrqHandler_Activity
*/
void Flexio_Spi_Ip_IrqHandler(
                                uint8 ShifterIndex,
                                uint8 ShifterMaskFlag,
                                uint8 ShifterErrMaskFlag
                              )
{
    FLEXIO_Type *Base = Flexio_Spi_Ip_apxBases[0];
    const Flexio_Spi_Ip_StateStructureType* State = NULL_PTR;
    uint8 TxShifterIndex = 0u;
    uint8 RxShifterIndex = 0u;
    uint8 Count = 0u;
    uint8 Instance = 0;
    uint8 ShifterEnabledIrq     = (uint8)0U;
    uint8 ShifterErrEnabledIrq  = (uint8)0U;
    uint8 ShifterEnabledIsrFlag = 0u;
    uint8 ShifterErrEnabledIrqFlag = 0u;
    
    /* Get current instance */
    for (Count=0; Count< FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8; Count++)
    {
       TxShifterIndex = Flexio_Spi_Ip_apxStateStructureArray[Count]->PhyUnitConfig->TxShifterIndex;
       RxShifterIndex = Flexio_Spi_Ip_apxStateStructureArray[Count]->PhyUnitConfig->RxShifterIndex;
       if((ShifterIndex == TxShifterIndex) || (ShifterIndex == RxShifterIndex))
       {
           Instance = Count;
           State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
           break;
       }
    }

    if (NULL_PTR != State)
    {
        ShifterEnabledIrq        = (uint8)Flexio_Mcl_Ip_GetAllShifterInterrupt(Base);
        ShifterEnabledIsrFlag    = ShifterMaskFlag & (ShifterEnabledIrq & (1u << ShifterIndex));

        ShifterErrEnabledIrq     = (uint8)Flexio_Mcl_Ip_GetAllShifterErrorInterrupt(Base);
        ShifterErrEnabledIrqFlag = ShifterErrMaskFlag & (ShifterErrEnabledIrq & (1u << ShifterIndex));

        Flexio_Spi_Ip_TransferProcess(Instance, ShifterIndex, ShifterEnabledIsrFlag, ShifterErrEnabledIrqFlag);
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags */
        Flexio_Mcl_Ip_ClearShifterStatus(Base, TxShifterIndex);
        Flexio_Mcl_Ip_ClearShifterStatus(Base, RxShifterIndex);
    }
}

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
*/
Flexio_Spi_Ip_HwStatusType Flexio_Spi_Ip_GetStatus(uint8 Instance)
{
    const Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    Flexio_Spi_Ip_HwStatusType Status = FLEXIO_SPI_IP_UNINIT;
    
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8 > Instance);
    #endif
    if (NULL_PTR != State)
    {
        Status = State->Status;
    }   
    return Status;
}

#if (STD_ON == FLEXIO_SPI_IP_DUAL_CLOCK_MODE)
Flexio_Spi_Ip_StatusType Flexio_Spi_Ip_SetClockMode(uint8 Instance, Flexio_Spi_Ip_DualClockModeType ClockMode)
{
    Flexio_Spi_Ip_StateStructureType* State = Flexio_Spi_Ip_apxStateStructureArray[Instance];
    Flexio_Spi_Ip_StatusType Status = FLEXIO_SPI_IP_STATUS_SUCCESS;
    
    #if (STD_ON == FLEXIO_SPI_IP_DEV_ERROR_DETECT)
    DevAssert(FLEXIO_SPI_IP_NUMBER_OF_HWUNIT_U8 > Instance);
    DevAssert(NULL_PTR != State);
    #endif
    /* Clock mode can be changed when no transfers are in progress. */
    if (FLEXIO_SPI_IP_BUSY != State->Status)
    {
        State->ClockMode = ClockMode;
    }
    else
    {
        Status = FLEXIO_SPI_IP_STATUS_FAIL;
    }    
    return Status;
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#endif /*(FLEXIO_SPI_IP_ENABLE == STD_ON)*/

#ifdef __cplusplus
}
#endif

/** @} */
