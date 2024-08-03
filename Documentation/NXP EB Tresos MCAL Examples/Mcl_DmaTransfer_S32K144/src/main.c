/*
*   Copyright 2020 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
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
#include "Mcl_Example_EBT.h"
#include "Dma_Ip_Hw_Access.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define DMA_CH0_BUFFER_DIMENSION           ((uint32)24U)
#define DMA_CH0_CONFIG_LIST_DIMENSION      ((uint32)2U)

#define DMA_CH1_ELEMENT0_DIMENSION         ((uint32)16U)
#define DMA_CH1_ELEMENT1_DIMENSION         ((uint32)32U)
#define DMA_CH1_ELEMENT2_DIMENSION         ((uint32)64U)
#define DMA_CH1_CONFIG_LIST_DIMENSION      ((uint32)2U)

#define DMA_CH2_BUFFER_DIMENSION           ((uint32)24U)
#define DMA_CH2_CONFIG_LIST_DIMENSION      ((uint32)9U)
#define DMA_CH2_GLOBAL_LIST_DIMENSION      ((uint32)3U)

#define DMA_IRQ_NOT_TRIGGERED              ((uint32)0U)
#define DMA_IRQ_TRIGGERED_ONCE             ((uint32)1U)

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
uint32 g_DmaCh0_CallbackCounter = 0U;
uint32 g_DmaCh0_ErrorCallbackCounter = 0U;
uint32 g_DmaCh1_CallbackCounter = 0U;
uint32 g_DmaCh1_ErrorCallbackCounter = 0U;
uint32 g_DmaCh2_CallbackCounter = 0U;
uint32 g_DmaCh2_ErrorCallbackCounter = 0U;
boolean Status = TRUE;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
Std_ReturnType CHECK_Uint8_BufferCompare(uint8 * pSource, uint8 * pDestination, uint32 Length);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void Mcl_DmaCh0_Callback(void)
{
    g_DmaCh0_CallbackCounter++;
}

void Mcl_DmaCh0_ErrorCallback(void)
{
    g_DmaCh0_ErrorCallbackCounter++;
}

void Mcl_DmaCh1_Callback(void)
{
    g_DmaCh1_CallbackCounter++;
}

void Mcl_DmaCh1_ErrorCallback(void)
{
    g_DmaCh1_ErrorCallbackCounter++;
}

void Mcl_DmaCh2_Callback(void)
{
    g_DmaCh2_CallbackCounter++;
}

void Mcl_DmaCh2_ErrorCallback(void)
{
    g_DmaCh2_ErrorCallbackCounter++;
}

Std_ReturnType CHECK_Uint8_BufferCompare(uint8 * pSource, uint8 * pDestination, uint32 Length)
{
    uint32 Index = 0U;

    for(Index = 0U; Index < Length; Index++)
    {
        if(pSource[Index] != pDestination[Index])
        {
            return E_NOT_OK;
        }
    }
    return E_OK;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
int main(void)
{
#if (STD_ON == MCL_CACHE_IS_AVAILABLE)
    /* DMA Logic Channel 0 Buffers */
    __attribute__(( aligned(32) )) static uint8 DmaCh0_SourceBuffer[DMA_CH0_BUFFER_DIMENSION] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    __attribute__(( aligned(32) )) static uint8 DmaCh0_DestinationBuffer[DMA_CH0_BUFFER_DIMENSION];

    /* DMA Logic Channel 1 Buffers */
    __attribute__(( aligned(32) )) static uint8 DmaCh1_SourceBuffer0[DMA_CH1_ELEMENT0_DIMENSION] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    __attribute__(( aligned(32) )) static uint8 DmaCh1_DestinationBuffer0[DMA_CH1_ELEMENT0_DIMENSION];
    __attribute__(( aligned(32) )) static uint8 DmaCh1_SourceBuffer1[DMA_CH1_ELEMENT1_DIMENSION] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7};
    __attribute__(( aligned(32) )) static uint8 DmaCh1_DestinationBuffer1[DMA_CH1_ELEMENT1_DIMENSION];
    __attribute__(( aligned(32) )) static uint8 DmaCh1_SourceBuffer2[DMA_CH1_ELEMENT2_DIMENSION] = {0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,100,100,100,100,99,99,99,99,98,98,98,98,97,97,97,97,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,96,96,96,96,95,95,95,95,94,94,94,94,93,93,93,93};
    __attribute__(( aligned(32) )) static uint8 DmaCh1_DestinationBuffer2[DMA_CH1_ELEMENT2_DIMENSION];

    /* DMA Logic Channel 2 Buffers */
    __attribute__(( aligned(32) )) static uint8 DmaCh2_SourceBuffer[DMA_CH2_BUFFER_DIMENSION] = {23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    __attribute__(( aligned(32) )) static uint8 DmaCh2_DestinationBuffer[DMA_CH2_BUFFER_DIMENSION];
#else
#define MCL_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"
    /* DMA Logic Channel 0 Buffers */
    __attribute__(( aligned(32) )) static uint8 DmaCh0_SourceBuffer[DMA_CH0_BUFFER_DIMENSION] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    __attribute__(( aligned(32) )) static uint8 DmaCh0_DestinationBuffer[DMA_CH0_BUFFER_DIMENSION];

    /* DMA Logic Channel 1 Buffers */
    __attribute__(( aligned(32) )) static uint8 DmaCh1_SourceBuffer0[DMA_CH1_ELEMENT0_DIMENSION] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    __attribute__(( aligned(32) )) static uint8 DmaCh1_DestinationBuffer0[DMA_CH1_ELEMENT0_DIMENSION];
    __attribute__(( aligned(32) )) static uint8 DmaCh1_SourceBuffer1[DMA_CH1_ELEMENT1_DIMENSION] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7};
    __attribute__(( aligned(32) )) static uint8 DmaCh1_DestinationBuffer1[DMA_CH1_ELEMENT1_DIMENSION];
    __attribute__(( aligned(32) )) static uint8 DmaCh1_SourceBuffer2[DMA_CH1_ELEMENT2_DIMENSION] = {0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,100,100,100,100,99,99,99,99,98,98,98,98,97,97,97,97,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,96,96,96,96,95,95,95,95,94,94,94,94,93,93,93,93};
    __attribute__(( aligned(32) )) static uint8 DmaCh1_DestinationBuffer2[DMA_CH1_ELEMENT2_DIMENSION];

    /* DMA Logic Channel 2 Buffers */
    __attribute__(( aligned(32) )) static uint8 DmaCh2_SourceBuffer[DMA_CH2_BUFFER_DIMENSION] = {23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    __attribute__(( aligned(32) )) static uint8 DmaCh2_DestinationBuffer[DMA_CH2_BUFFER_DIMENSION];
#define MCL_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"
#endif

    /* DMA Logic Channel 0 Address Configuration */
    Mcl_DmaChannelTransferListType DmaCh0_TransferList[DMA_CH0_CONFIG_LIST_DIMENSION] =
    {
        {MCL_DMA_CH_SET_SOURCE_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh0_SourceBuffer[0U]},
        {MCL_DMA_CH_SET_DESTINATION_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh0_DestinationBuffer[0U]},
    };

    /* DMA Logic Channel 1 Address Configuration */
    Mcl_DmaChannelScatterGatherListType DmaCh1_Element0_List[DMA_CH1_CONFIG_LIST_DIMENSION] =
    {
        {MCL_DMA_CH_SET_SOURCE_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh1_SourceBuffer0[0U]},
        {MCL_DMA_CH_SET_DESTINATION_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh1_DestinationBuffer0[0U]},
    };
    Mcl_DmaChannelScatterGatherListType DmaCh1_Element1_List[DMA_CH1_CONFIG_LIST_DIMENSION] =
    {
        {MCL_DMA_CH_SET_SOURCE_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh1_SourceBuffer1[0U]},
        {MCL_DMA_CH_SET_DESTINATION_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh1_DestinationBuffer1[0U]},
    };
    Mcl_DmaChannelScatterGatherListType DmaCh1_Element2_List[DMA_CH1_CONFIG_LIST_DIMENSION] =
    {
        {MCL_DMA_CH_SET_SOURCE_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh1_SourceBuffer2[0U]},
        {MCL_DMA_CH_SET_DESTINATION_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh1_DestinationBuffer2[0U]},
    };

    /* DMA Logic Channel 0 Address Configuration */
    Mcl_DmaChannelTransferListType DmaCh2_TransferList[DMA_CH2_CONFIG_LIST_DIMENSION] =
    {
        {MCL_DMA_CH_SET_SOURCE_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh2_SourceBuffer[0U]},
        {MCL_DMA_CH_SET_SOURCE_SIGNED_OFFSET, 2U},
        {MCL_DMA_CH_SET_SOURCE_TRANSFER_SIZE, DMA_IP_TRANSFER_SIZE_2_BYTE},
        {MCL_DMA_CH_SET_DESTINATION_ADDRESS, (Dma_Ip_uintPtrType)&DmaCh2_DestinationBuffer[0U]},
        {MCL_DMA_CH_SET_DESTINATION_SIGNED_OFFSET, 2U},
        {MCL_DMA_CH_SET_DESTINATION_TRANSFER_SIZE, DMA_IP_TRANSFER_SIZE_2_BYTE},
        {MCL_DMA_CH_SET_MINORLOOP_SIZE, 24U},
        {MCL_DMA_CH_SET_MAJORLOOP_COUNT, 1U},
        {MCL_DMA_CH_SET_CONTROL_EN_MAJOR_INTERRUPT, TRUE},
    };
    Mcl_DmaChannelGlobalListType DmaCh2_GlobalList[DMA_CH2_GLOBAL_LIST_DIMENSION] =
    {
        {MCL_DMA_CH_SET_EN_ERROR_INTERRUPT, TRUE},
    };

    Std_ReturnType StdStatus = E_OK;
    Mcl_DmaChannelStatusType t_GetChannel0Status;
    Mcl_DmaChannelStatusType t_GetChannel1Status;
    Mcl_DmaChannelStatusType t_GetChannel2Status;

    /* Initialize Mcu Driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config_VS_0);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */
    Mcu_InitClock(McuClockSettingConfig_0);

#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();
#endif

    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Platform Driver */
    Platform_Init(NULL_PTR);
#if defined(S32K3XX)
    #if (STD_ON == DMA_IP_IRQ_DISPATCHER_IS_AVAILABLE)
        Platform_InstallIrqHandler(eDMA0_DMATCD_CH0_CH1_IRQn, Dma0_Ch0_Ch1_IrqHandler, NULL_PTR);
        Platform_InstallIrqHandler(eDMA0_DMATCD_CH2_CH3_IRQn, Dma0_Ch2_Ch3_IrqHandler, NULL_PTR);
    #else
        #if defined(S32M276)
            Platform_InstallIrqHandler(DMA0_IRQn, Dma0_Ch0_IRQHandler, NULL_PTR);
            Platform_InstallIrqHandler(DMA1_IRQn, Dma0_Ch1_IRQHandler, NULL_PTR);
            Platform_InstallIrqHandler(DMA2_IRQn, Dma0_Ch2_IRQHandler, NULL_PTR);
        #else
            Platform_InstallIrqHandler(DMATCD0_IRQn, Dma0_Ch0_IRQHandler, NULL_PTR);
            Platform_InstallIrqHandler(DMATCD1_IRQn, Dma0_Ch1_IRQHandler, NULL_PTR);
            Platform_InstallIrqHandler(DMATCD2_IRQn, Dma0_Ch2_IRQHandler, NULL_PTR);
        #endif
    #endif
#elif (defined(S32G2XX) || defined(S32G3XX) || defined(S32R45) || defined(S32R41) || defined(SAF8544))
    Platform_InstallIrqHandler(DMA0_0_15_IRQn, Dma0_Ch0_Ch15_IrqHandler, NULL_PTR);
    Platform_InstallIrqHandler(DMA0_ERR0_IRQn, Dma0_Error_IrqHandler, NULL_PTR);
#elif (defined(SJA1110) || defined(S32K1XX) || defined(S32M244) || defined(S32M242))
    Platform_InstallIrqHandler(DMA0_IRQn, Dma0_Ch0_IRQHandler, NULL_PTR);
    Platform_InstallIrqHandler(DMA1_IRQn, Dma0_Ch1_IRQHandler, NULL_PTR);
    Platform_InstallIrqHandler(DMA2_IRQn, Dma0_Ch2_IRQHandler, NULL_PTR);
    Platform_InstallIrqHandler(DMA_Error_IRQn, Dma0_Error_IrqHandler, NULL_PTR);
#elif defined(S32ZE)
    #if defined(CPU_CORTEX_M33)
        #if defined(SMU_M33)
            Platform_InstallIrqHandler(SMU_DMA0_0_15_IRQn, Dma0_Ch0_Ch15_IrqHandler, NULL_PTR);
            Platform_InstallIrqHandler(SMU_DMA0_ERR_IRQn, Dma0_Error_IrqHandler, NULL_PTR);
        #else
            Platform_InstallIrqHandler(FLEXLLCE_CE_eDMA_CH0_IRQn, Dma6_Ch0_IRQHandler, NULL_PTR);
            Platform_InstallIrqHandler(FLEXLLCE_CE_eDMA_ERR_IRQn, Dma6_Error_IrqHandler, NULL_PTR);
        #endif  
    #elif defined(CPU_CORTEX_R52)
         Platform_InstallIrqHandler(RTU_DMA0_0_15_IRQn, Dma0_Ch0_Ch15_IrqHandler, NULL_PTR);
         Platform_InstallIrqHandler(RTU_DMA0_ERR_IRQn, Dma0_Error_IrqHandler, NULL_PTR);
    #else
        #error Unknown CPU
    #endif  
#elif defined(S32N2RT)
    #if defined(CPU_CORTEX_M7)
        Platform_InstallIrqHandler(FSS_eDMA4_eDMA_F_CH_0_IRQ, Fss_eDma_Ch0_IRQHandler, NULL_PTR);
        Platform_InstallIrqHandler(FSS_eDMA4_eDMA_F_CH_1_IRQ, Fss_eDma_Ch1_IRQHandler, NULL_PTR);
        Platform_InstallIrqHandler(FSS_eDMA4_eDMA_F_CH_2_IRQ, Fss_eDma_Ch1_IRQHandler, NULL_PTR);
        Platform_InstallIrqHandler(FSS_eDMA4_eDMA_F_Control_IRQ, Fss_eDma_Error_IrqHandler, NULL_PTR); 
    #elif defined(CPU_CORTEX_R52)
        Platform_InstallIrqHandler(RTU_DMA_0_CH3_0_IRQn, FssCOSS_eDma0_Ch3_Ch0_IrqHandler, NULL_PTR);
        Platform_InstallIrqHandler(RTU_DMA_0_ERR_IRQn, FssCOSS_eDma0_Error_IrqHandler, NULL_PTR); 
    #else
        #error Unknown CPU
    #endif    
#endif
    /* Initialize MCL Driver */
    Mcl_Init(NULL_PTR);

    /* Set Logic Channel 0 -> Source and Destination Address */
    Mcl_SetDmaChannelTransferList(DMA_LOGIC_CH_0, DmaCh0_TransferList, DMA_CH0_CONFIG_LIST_DIMENSION);

    /* Set Logic Channel 1 -> Source and Destination Address for each Scatter/Gather Element */
    Mcl_SetDmaChannelScatterGatherList(DMA_LOGIC_CH_1, DMA_LOGIC_CH_1_SGA_ELEMENT_0, DmaCh1_Element0_List, DMA_CH1_CONFIG_LIST_DIMENSION);
    Mcl_SetDmaChannelScatterGatherList(DMA_LOGIC_CH_1, DMA_LOGIC_CH_1_SGA_ELEMENT_1, DmaCh1_Element1_List, DMA_CH1_CONFIG_LIST_DIMENSION);
    Mcl_SetDmaChannelScatterGatherList(DMA_LOGIC_CH_1, DMA_LOGIC_CH_1_SGA_ELEMENT_2, DmaCh1_Element2_List, DMA_CH1_CONFIG_LIST_DIMENSION);
    Mcl_SetDmaChannelScatterGatherConfig(DMA_LOGIC_CH_1, DMA_LOGIC_CH_1_SGA_ELEMENT_0);

    /* Set Logic Channel 2 */
    Mcl_SetDmaChannelGlobalList(DMA_LOGIC_CH_2, DmaCh2_GlobalList, DMA_CH2_GLOBAL_LIST_DIMENSION);
    Mcl_SetDmaChannelTransferList(DMA_LOGIC_CH_2, DmaCh2_TransferList, DMA_CH2_CONFIG_LIST_DIMENSION);

    /* Start transfer for logic Channel 0 */
    Mcl_SetDmaChannelCommand(DMA_LOGIC_CH_0, MCL_DMA_CH_START_SERVICE);
    Mcl_GetDmaChannelStatus(DMA_LOGIC_CH_0, &t_GetChannel0Status);
    while(t_GetChannel0Status.Done != TRUE)
    {
        Mcl_GetDmaChannelStatus(DMA_LOGIC_CH_0, &t_GetChannel0Status);
    }

    /* Start transfer for logic Channel 1 */
    Mcl_SetDmaChannelCommand(DMA_LOGIC_CH_1, MCL_DMA_CH_START_SERVICE);
    Mcl_GetDmaChannelStatus(DMA_LOGIC_CH_1, &t_GetChannel1Status);
    while(t_GetChannel1Status.Done != TRUE)
    {
        Mcl_GetDmaChannelStatus(DMA_LOGIC_CH_1, &t_GetChannel1Status);
    }

    /* Start transfer for logic Channel 2 */
    Mcl_SetDmaChannelCommand(DMA_LOGIC_CH_2, MCL_DMA_CH_START_SERVICE);
    Mcl_GetDmaChannelStatus(DMA_LOGIC_CH_2, &t_GetChannel2Status);
    while(t_GetChannel2Status.Done != TRUE)
    {
        Mcl_GetDmaChannelStatus(DMA_LOGIC_CH_2, &t_GetChannel2Status);
    }

#if (STD_ON == MCL_CACHE_IS_AVAILABLE)
#if (STD_ON == CACHE_IP_ARMCOREMX_IS_AVAILABLE)
    Mcl_CacheInvalidateByAddr(MCL_CACHE_CORE, MCL_CACHE_DATA, (uint32)&DmaCh0_DestinationBuffer[0U], DMA_CH0_BUFFER_DIMENSION);
    Mcl_CacheInvalidateByAddr(MCL_CACHE_CORE, MCL_CACHE_DATA, (uint32)&DmaCh1_DestinationBuffer0[0U], DMA_CH1_ELEMENT0_DIMENSION);
    Mcl_CacheInvalidateByAddr(MCL_CACHE_CORE, MCL_CACHE_DATA, (uint32)&DmaCh1_DestinationBuffer1[0U], DMA_CH1_ELEMENT1_DIMENSION);
    Mcl_CacheInvalidateByAddr(MCL_CACHE_CORE, MCL_CACHE_DATA, (uint32)&DmaCh1_DestinationBuffer2[0U], DMA_CH1_ELEMENT2_DIMENSION);
    Mcl_CacheInvalidateByAddr(MCL_CACHE_CORE, MCL_CACHE_DATA, (uint32)&DmaCh2_DestinationBuffer[0U], DMA_CH2_BUFFER_DIMENSION);
#else
    Mcl_CacheInvalidateByAddr(MCL_CACHE_LMEM, MCL_CACHE_PC_BUS, (uint32)&DmaCh0_DestinationBuffer[0U], DMA_CH0_BUFFER_DIMENSION);
    Mcl_CacheInvalidateByAddr(MCL_CACHE_LMEM, MCL_CACHE_PC_BUS, (uint32)&DmaCh1_DestinationBuffer0[0U], DMA_CH1_ELEMENT0_DIMENSION);
    Mcl_CacheInvalidateByAddr(MCL_CACHE_LMEM, MCL_CACHE_PC_BUS, (uint32)&DmaCh1_DestinationBuffer1[0U], DMA_CH1_ELEMENT1_DIMENSION);
    Mcl_CacheInvalidateByAddr(MCL_CACHE_LMEM, MCL_CACHE_PC_BUS, (uint32)&DmaCh1_DestinationBuffer2[0U], DMA_CH1_ELEMENT2_DIMENSION);
    Mcl_CacheInvalidateByAddr(MCL_CACHE_LMEM, MCL_CACHE_PC_BUS, (uint32)&DmaCh2_DestinationBuffer[0U], DMA_CH2_BUFFER_DIMENSION);
#endif
#endif

    if(DMA_IRQ_TRIGGERED_ONCE != g_DmaCh0_CallbackCounter)
    {
        Status = FALSE;
    }
    if(DMA_IRQ_NOT_TRIGGERED != g_DmaCh0_ErrorCallbackCounter)
    {
        Status = FALSE;
    }
    if(DMA_IRQ_TRIGGERED_ONCE != g_DmaCh1_CallbackCounter)
    {
        Status = FALSE;
    }
    if(DMA_IRQ_NOT_TRIGGERED != g_DmaCh1_ErrorCallbackCounter)
    {
        Status = FALSE;
    }
    if(DMA_IRQ_TRIGGERED_ONCE != g_DmaCh2_CallbackCounter)
    {
        Status = FALSE;
    }
    if(DMA_IRQ_NOT_TRIGGERED != g_DmaCh2_ErrorCallbackCounter)
    {
        Status = FALSE;
    }

    StdStatus = CHECK_Uint8_BufferCompare(DmaCh0_SourceBuffer, DmaCh0_DestinationBuffer, DMA_CH0_BUFFER_DIMENSION);
    if(E_OK != StdStatus)
    {
        Status = FALSE;
    }
    StdStatus = CHECK_Uint8_BufferCompare(DmaCh1_SourceBuffer0, DmaCh1_DestinationBuffer0, DMA_CH1_ELEMENT0_DIMENSION);
    if(E_OK != StdStatus)
    {
        Status = FALSE;
    }StdStatus = CHECK_Uint8_BufferCompare(DmaCh1_SourceBuffer1, DmaCh1_DestinationBuffer1, DMA_CH1_ELEMENT1_DIMENSION);
    if(E_OK != StdStatus)
    {
        Status = FALSE;
    }
    StdStatus = CHECK_Uint8_BufferCompare(DmaCh1_SourceBuffer2, DmaCh1_DestinationBuffer2, DMA_CH1_ELEMENT2_DIMENSION);
    if(E_OK != StdStatus)
    {
        Status = FALSE;
    }
    StdStatus = CHECK_Uint8_BufferCompare(DmaCh2_SourceBuffer, DmaCh2_DestinationBuffer, DMA_CH2_BUFFER_DIMENSION);
    if(E_OK != StdStatus)
    {
        Status = FALSE;
    }

    Exit_Example(Status);

    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
