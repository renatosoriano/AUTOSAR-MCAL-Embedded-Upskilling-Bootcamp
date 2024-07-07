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
/*==================================================================================================
==================================================================================================*/

/**
*   @file    Can_Flexcan_Irq.c
*   @version 2.0.0
*
*   @brief   AUTOSAR Can_43_FLEXCAN - LLD module implementation.
*   @details Low Level Driver implementation.
*
*   @addtogroup CAN_43_FLEXCAN_DRIVER
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
#include "Can_43_FLEXCAN.h"
#include "Can_43_FLEXCAN_Irq.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           Can_Irq.c
*/
#define CAN_43_FLEXCAN_IRQ_VENDOR_ID_C                    43
#define CAN_43_FLEXCAN_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
#define CAN_43_FLEXCAN_IRQ_AR_RELEASE_MINOR_VERSION_C     7
#define CAN_43_FLEXCAN_IRQ_AR_RELEASE_REVISION_VERSION_C  0
#define CAN_43_FLEXCAN_IRQ_SW_MAJOR_VERSION_C             2
#define CAN_43_FLEXCAN_IRQ_SW_MINOR_VERSION_C             0
#define CAN_43_FLEXCAN_IRQ_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can header file are of the same vendor */
#if (CAN_43_FLEXCAN_IRQ_VENDOR_ID_C != CAN_43_FLEXCAN_VENDOR_ID)
    #error "Can_43_FLEXCAN_Irq.c and Can_43_FLEXCAN.h have different vendor ids"
#endif
/* Check if current file and Can header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IRQ_AR_RELEASE_MAJOR_VERSION_C    != CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_AR_RELEASE_MINOR_VERSION_C    != CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_AR_RELEASE_REVISION_VERSION_C != CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_Irq.c and Can_43_FLEXCAN.h are different"
#endif
/* Check if current file and Can header file are of the same Software version */
#if ((CAN_43_FLEXCAN_IRQ_SW_MAJOR_VERSION_C != CAN_43_FLEXCAN_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_SW_MINOR_VERSION_C != CAN_43_FLEXCAN_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_SW_PATCH_VERSION_C != CAN_43_FLEXCAN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN_Irq.c and Can_43_FLEXCAN.h are different"
#endif

/* Check if current file and Can_Irq header file are of the same vendor */
#if (CAN_43_FLEXCAN_IRQ_VENDOR_ID_C != CAN_43_FLEXCAN_IRQ_VENDOR_ID)
    #error "Can_43_FLEXCAN_Irq.c and Can_43_FLEXCAN_Irq.h have different vendor ids"
#endif
/* Check if current file and Can_Irq header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IRQ_AR_RELEASE_MAJOR_VERSION_C    != CAN_43_FLEXCAN_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_AR_RELEASE_MINOR_VERSION_C    != CAN_43_FLEXCAN_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_AR_RELEASE_REVISION_VERSION_C != CAN_43_FLEXCAN_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_Irq.c and Can_43_FLEXCAN_Irq.h are different"
#endif
/* Check if current file and Can_Irq header file are of the same Software version */
#if ((CAN_43_FLEXCAN_IRQ_SW_MAJOR_VERSION_C != CAN_43_FLEXCAN_IRQ_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_SW_MINOR_VERSION_C != CAN_43_FLEXCAN_IRQ_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_SW_PATCH_VERSION_C != CAN_43_FLEXCAN_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN_Irq.c and Can_43_FLEXCAN_Irq.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define CAN_43_FLEXCAN_START_SEC_CODE
/* @violates @ref Can_Irq_c_REF_1 MISRA 2012 Required Directive 4.10 */
#include "Can_43_FLEXCAN_MemMap.h"

#if ((CAN_43_FLEXCAN_MB_INTERRUPT_SUPPORT == STD_ON) || (CAN_43_FLEXCAN_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON))
void Can_43_FLEXCAN_CommonIrqCallback(uint8 u8Instance,
                           Flexcan_Ip_EventType event,
                           uint32 u32buffIdx,
                           const Flexcan_Ip_StateType *driverState
                          )
{
#if (CAN_43_FLEXCAN_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    if (CAN_43_FLEXCAN_MB_ENHANCED_RXFIFO == u32buffIdx)
    {
        if (FALSE == driverState->enhancedFifoOutput.isPolling)
        {
            switch (event)
            {
                case FLEXCAN_EVENT_ENHANCED_RXFIFO_COMPLETE:
                /*case FLEXCAN_EVENT_ENHANCED_RXFIFO_WATERMARK: not supported on HLD yet */
                case FLEXCAN_EVENT_ENHANCED_RXFIFO_OVERFLOW:
                /* case FLEXCAN_EVENT_ENHANCED_RXFIFO_UNDERFLOW: not supported on HLD yet */
                {
                    Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)event, CAN_RX_ENHANCED_FIFO);
                    break;
                }
                default:
                {
                    /* nothing to do */
                    break;
                }
            }
        }
    #if (CAN_43_FLEXCAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
        else if ((FLEXCAN_EVENT_DMA_COMPLETE == event) || (FLEXCAN_EVENT_DMA_ERROR == event))
        {
            Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)event, CAN_RX_ENHANCED_FIFO);
        }
        else
        {
            /* prevent misra */
        }
    #endif /* (CAN_43_FLEXCAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
    }
    else
    {
#endif /* CAN_43_FLEXCAN_FEATURE_HAS_ENHANCED_RX_FIFO */
    #if (CAN_43_FLEXCAN_MB_INTERRUPT_SUPPORT == STD_ON)
        /* This callback is just used for interrupt buffter */
        if (FALSE == (driverState->mbs[u32buffIdx].isPolling))
        {
            switch (event)
            {
                case FLEXCAN_EVENT_TX_COMPLETE:
                {
                    Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)u32buffIdx, CAN_TX_NORMAL);
                    break;
                }
                case FLEXCAN_EVENT_RX_COMPLETE:
                {
                    Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)u32buffIdx, CAN_RX_NORMAL);
                    break;
                }
                case FLEXCAN_EVENT_RXFIFO_COMPLETE:
                {
                    Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)u32buffIdx, CAN_RX_LEGACY_FIFO);
                    break;
                }
                case FLEXCAN_EVENT_RXFIFO_WARNING:
                {
                    Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt(u8Instance, 6U, CAN_RX_LEGACY_FIFO);
                    break;
                }
                case FLEXCAN_EVENT_RXFIFO_OVERFLOW:
                {
                    Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt(u8Instance, 7U, CAN_RX_LEGACY_FIFO);
                    break;
                }
                default:
                {
                    /* nothing to do */
                    break;
                }
            }
        }
    #endif /* (CAN_43_FLEXCAN_MB_INTERRUPT_SUPPORT == STD_ON) */
#if (CAN_43_FLEXCAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
        else if ((FLEXCAN_EVENT_DMA_COMPLETE == event) || (FLEXCAN_EVENT_DMA_ERROR == event))
        {
            Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt(u8Instance, (uint8)event, CAN_RX_LEGACY_FIFO);
        }
        else
        {
            /* prevent misra */
        }
#endif /* (CAN_43_FLEXCAN_FEATURE_HAS_DMA_ENABLE == STD_ON)*/
#if (CAN_43_FLEXCAN_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
    }
#endif /* (CAN_43_FLEXCAN_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

#if (CAN_43_FLEXCAN_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
    if (FLEXCAN_EVENT_WAKEUP_MATCH == event)
    {
        Can_43_FLEXCAN_ProcessPNInterrupt(u8Instance);
    }
#endif /* (CAN_43_FLEXCAN_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON) */
    (void)u32buffIdx;
    (void)driverState;
}
#endif

void Can_43_FLEXCAN_ErrorIrqCallback(uint8 u8Instance,
                          Flexcan_Ip_EventType event,
                          uint32 u32ErrStatus,
                          const Flexcan_Ip_StateType *driverState
                         )
{
    (void) driverState; /* not used yet */
#if (CAN_43_FLEXCAN_ERROR_INTERRUPT_SUPPORT != STD_ON)
    (void) u32ErrStatus; /* prevent compiler warning */
#endif /* (CAN_43_FLEXCAN_ERROR_INTERRUPT_SUPPORT != STD_ON) */

    switch (event)
    {
#if (CAN_43_FLEXCAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
        case FLEXCAN_EVENT_ERROR:
        {
            Can_43_FLEXCAN_ProcessErrorInterrupt(u8Instance, u32ErrStatus);
            break;
        }
#endif /* (CAN_43_FLEXCAN_ERROR_INTERRUPT_SUPPORT == STD_ON) */
        /* this function is called for both interrupt & polling */
        case FLEXCAN_EVENT_BUSOFF:
        {
            Can_43_FLEXCAN_ProcessBusOffInterrupt(u8Instance);
            break;
        }
        default:
        {
            /* nothing to do */
            break;
        }
    }
}
#define CAN_43_FLEXCAN_STOP_SEC_CODE
/* @violates @ref Can_Irq_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_Irq_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
