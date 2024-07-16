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
/**
 *  @file FlexCAN_Ip_Irq.c
 *
 *  @brief FlexCAN Interrupts
 *
 *  @addtogroup FlexCAN
 *  @{
 */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "FlexCAN_Ip_Irq.h"
#include "FlexCAN_Ip_HwAccess.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_IRQ_VENDOR_ID_C                      43
#define FLEXCAN_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXCAN_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXCAN_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXCAN_IP_IRQ_SW_MAJOR_VERSION_C               2
#define FLEXCAN_IP_IRQ_SW_MINOR_VERSION_C               0
#define FLEXCAN_IP_IRQ_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip_Irq header file are of the same vendor */
#if (FLEXCAN_IP_IRQ_VENDOR_ID_C != FLEXCAN_IP_IRQ_VENDOR_ID_H)
    #error "FlexCAN_Ip_Irq.c and FlexCAN_Ip_Irq.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_Irq header file are of the same Autosar version */
#if ((FLEXCAN_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXCAN_IP_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXCAN_IP_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXCAN_IP_IRQ_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of FlexCAN_Ip_Irq.c and FlexCAN_Ip_Irq.h are different"
#endif
/* Check if current file and FlexCAN_Ip_Irq header file are of the same Software version */
#if ((FLEXCAN_IP_IRQ_SW_MAJOR_VERSION_C != FLEXCAN_IP_IRQ_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_SW_MINOR_VERSION_C != FLEXCAN_IP_IRQ_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_SW_PATCH_VERSION_C != FLEXCAN_IP_IRQ_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Ip_Irq.c and FlexCAN_Ip_Irq.h are different"
#endif

/* Check if current file and FlexCAN_Ip_HwAccess header file are of the same vendor */
#if (FLEXCAN_IP_IRQ_VENDOR_ID_C != FLEXCAN_IP_HWACCESS_VENDOR_ID_H)
    #error "FlexCAN_Ip_Irq.c and FlexCAN_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_HwAccess header file are of the same Autosar version */
#if ((FLEXCAN_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXCAN_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXCAN_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXCAN_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of FlexCAN_Ip_Irq.c and FlexCAN_Ip_HwAccess.h are different"
#endif
/* Check if current file and FlexCAN_Ip_HwAccess header file are of the same Software version */
#if ((FLEXCAN_IP_IRQ_SW_MAJOR_VERSION_C != FLEXCAN_IP_HWACCESS_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_SW_MINOR_VERSION_C != FLEXCAN_IP_HWACCESS_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_IRQ_SW_PATCH_VERSION_C != FLEXCAN_IP_HWACCESS_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Ip_Irq.c and FlexCAN_Ip_HwAccess.h are different"
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
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"




#if (defined(S32K118) || defined(S32K116))
ISR(CAN0_ORED_IRQHandler);

ISR(CAN0_ORED_0_31_MB_IRQHandler);
#else
ISR(CAN0_ORED_IRQHandler);

ISR(CAN0_Error_IRQHandler);

#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN0_Wake_Up_IRQHandler);
#endif

ISR(CAN0_ORED_0_15_MB_IRQHandler);

ISR(CAN0_ORED_16_31_MB_IRQHandler);
#endif

#if (defined(S32K142W) || defined(S32K144W) || defined(S32M243) || defined(S32M244))
ISR(CAN0_ORED_32_47_MB_IRQHandler);

ISR(CAN0_ORED_48_63_MB_IRQHandler);
#endif /* (defined(S32K142W) || defined(S32K144W) || defined(S32M243) || defined(S32M244)) */

#if (FLEXCAN_INSTANCE_COUNT > 1U)
ISR(CAN1_ORED_IRQHandler);

ISR(CAN1_Error_IRQHandler);

ISR(CAN1_ORED_0_15_MB_IRQHandler);

ISR(CAN1_ORED_16_31_MB_IRQHandler);
#if (defined(S32K142W) || defined(S32K144W))
ISR(CAN1_ORED_32_47_MB_IRQHandler);

ISR(CAN1_ORED_48_63_MB_IRQHandler);
#endif /* (defined(S32K142W) || defined(S32K144W)) */
#endif /* (FLEXCAN_INSTANCE_COUNT > 1U) */

#if (FLEXCAN_INSTANCE_COUNT > 2U)
ISR(CAN2_ORED_IRQHandler);

ISR(CAN2_Error_IRQHandler);

ISR(CAN2_ORED_0_15_MB_IRQHandler);
#if defined(S32K148)
ISR(CAN2_ORED_16_31_MB_IRQHandler);
#endif
#endif /* (FLEXCAN_INSTANCE_COUNT > 2U) */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


#if (defined(S32K118) || defined(S32K116))
/* Implementation of CAN0 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-31. Used for K11x derivatives.*/
ISR(CAN0_ORED_0_31_MB_IRQHandler)
{
    FlexCAN_IRQHandler(0U, 0U, 31U);
}

/* Implementation of CAN0 handler named in startup code for processing of Errors and Bus Off reporting. */
ISR(CAN0_ORED_IRQHandler)
{
    FlexCAN_Busoff_Error_IRQHandler(0U);
}

#else

/* Implementation of CAN0 handler named in startup code for processing of Tx\Rx Warning and Bus Off reporting. */
ISR(CAN0_ORED_IRQHandler)
{
    FlexCAN_BusOff_IRQHandler(0U);
    EXIT_INTERRUPT();
}

/* Implementation of CAN0 handler named in startup code for processing of Errors reporting. */
ISR(CAN0_Error_IRQHandler)
{
    FlexCAN_Error_IRQHandler(0U);
    EXIT_INTERRUPT();
}

#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
ISR(CAN0_Wake_Up_IRQHandler)
{
    (void)FlexCAN_WakeUp_IRQHandler(0U);
    EXIT_INTERRUPT();
}
#endif
/* Implementation of CAN0 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-15. */
ISR(CAN0_ORED_0_15_MB_IRQHandler)
{
    FlexCAN_IRQHandler(0U, 0U, 15U);
    EXIT_INTERRUPT();
}

/* Implementation of CAN0 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 16-31. */
ISR(CAN0_ORED_16_31_MB_IRQHandler)
{
    FlexCAN_IRQHandler(0U, 16U, 31U);
    EXIT_INTERRUPT();
}
#endif /* (defined(S32K118) || defined(S32K116)) */

#if (defined(S32K142W) || defined(S32K144W) || defined(S32M243) || defined(S32M244))
/* Implementation of CAN0 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 32-47. */
ISR(CAN0_ORED_32_47_MB_IRQHandler)
{
    FlexCAN_IRQHandler(0U, 32U, 47U);
    EXIT_INTERRUPT();
}
/* Implementation of CAN0 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 48-63. */
ISR(CAN0_ORED_48_63_MB_IRQHandler)
{
    FlexCAN_IRQHandler(0U, 48U, 63U);
    EXIT_INTERRUPT();
}
#endif /* (defined(S32K142W) || defined(S32K144W) || defined(S32M243) || defined(S32M244)) */

#if (FLEXCAN_INSTANCE_COUNT > 1U)
/* Implementation of CAN1 handler named in startup code for processing of Tx\Rx Warning and Bus Off reporting. */
ISR(CAN1_ORED_IRQHandler)
{
    FlexCAN_BusOff_IRQHandler(1U);
    EXIT_INTERRUPT();
}

/* Implementation of CAN1 handler named in startup code for processing of Errors reporting. */
ISR(CAN1_Error_IRQHandler)
{
    FlexCAN_Error_IRQHandler(1U);
    EXIT_INTERRUPT();
}

/* Implementation of CAN1 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-15. */
ISR(CAN1_ORED_0_15_MB_IRQHandler)
{
    FlexCAN_IRQHandler(1U, 0U, 15U);
    EXIT_INTERRUPT();
}

/* Implementation of CAN1 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 16-31. */
ISR(CAN1_ORED_16_31_MB_IRQHandler)
{
    FlexCAN_IRQHandler(1U, 16U, 31U);
    EXIT_INTERRUPT();
}
#if (defined(S32K142W) || defined(S32K144W))
/* Implementation of CAN1 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 32-47. */
ISR(CAN1_ORED_32_47_MB_IRQHandler)
{
    FlexCAN_IRQHandler(1U, 32U, 47U);
    EXIT_INTERRUPT();
}
/* Implementation of CAN1 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 48-63. */
ISR(CAN1_ORED_48_63_MB_IRQHandler)
{
    FlexCAN_IRQHandler(1U, 48U, 63U);
    EXIT_INTERRUPT();
}
#endif /* #if (defined(S32K142W) || defined(S32K144W)) */
#endif /* (FLEXCAN_INSTANCE_COUNT > 1U) */

#if (FLEXCAN_INSTANCE_COUNT > 2U)
/* Implementation of CAN2 handler named in startup code for processing of Errors and Bus Off reporting. */
ISR(CAN2_ORED_IRQHandler)
{
    FlexCAN_BusOff_IRQHandler(2U);
    EXIT_INTERRUPT();
}

/* Implementation of CAN1 handler named in startup code for processing of Errors reporting. */
ISR(CAN2_Error_IRQHandler)
{
    FlexCAN_Error_IRQHandler(2U);
    EXIT_INTERRUPT();
}

/* Implementation of CAN2 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 0-15. */
ISR(CAN2_ORED_0_15_MB_IRQHandler)
{
    FlexCAN_IRQHandler(2U, 0U, 15U);
    EXIT_INTERRUPT();
}

#if defined(S32K148)
/* Implementation of CAN2 IRQ handler for interrupts indicating a successful
transmission or reception for Message Buffers 16-31. */
ISR(CAN2_ORED_16_31_MB_IRQHandler)
{
    FlexCAN_IRQHandler(2U, 16U, 31U);
    EXIT_INTERRUPT();
}
#endif

#endif /* (FLEXCAN_INSTANCE_COUNT > 2U) */

#define CAN_43_FLEXCAN_STOP_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"

/** @} */
