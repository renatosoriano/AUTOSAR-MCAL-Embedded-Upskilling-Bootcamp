/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   (c) Copyright 2020-2024 NXP Semiconductors
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


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "IntCtrl_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C                          43
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C                   2
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION_C           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION_C           7
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION_C        0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C != CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID)
    #error "IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Autosar version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IntCtrl_Ip_Cfg.C and IntCtrl_Ip_Cfg.h are different"
#endif
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

    
    /* List of configurations for interrupts */
    static const IntCtrl_Ip_IrqConfigType aIrqConfiguration[] = {
        {DMA0_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA1_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA2_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA3_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA4_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA5_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA6_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA7_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA8_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA9_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA10_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA11_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA12_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA13_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA14_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA15_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {DMA_Error_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {MCM_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTFC_CMD_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTFC_Read_Collision_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LVD_LVW_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTFC_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {WDOG_EWM_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {RCM_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPI2C0_Master_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPI2C0_Slave_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPSPI0_IRQn, (boolean)TRUE, 7U, Lpspi_Ip_LPSPI_0_IRQHandler},
        {LPSPI1_IRQn, (boolean)TRUE, 7U, Lpspi_Ip_LPSPI_1_IRQHandler},
        {LPSPI2_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPUART0_RxTx_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPUART1_RxTx_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPUART2_RxTx_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {ADC0_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {ADC1_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CMP0_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {ERM_single_fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {ERM_double_fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {RTC_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {RTC_Seconds_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPIT0_Ch0_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPIT0_Ch1_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPIT0_Ch2_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPIT0_Ch3_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {PDB0_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {SCG_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {LPTMR0_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {PORTA_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {PORTB_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {PORTC_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {PORTD_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {PORTE_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {SWI_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {PDB1_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FLEXIO_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN0_ORed_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN0_Error_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN0_Wake_Up_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN0_ORed_0_15_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN0_ORed_16_31_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN1_ORed_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN1_Error_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN1_ORed_0_15_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN2_ORed_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN2_Error_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {CAN2_ORed_0_15_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM0_Ch0_Ch1_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM0_Ch2_Ch3_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM0_Ch4_Ch5_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM0_Ch6_Ch7_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM0_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM0_Ovf_Reload_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM1_Ch0_Ch1_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM1_Ch2_Ch3_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM1_Ch4_Ch5_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM1_Ch6_Ch7_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM1_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM1_Ovf_Reload_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM2_Ch0_Ch1_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM2_Ch2_Ch3_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM2_Ch4_Ch5_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM2_Ch6_Ch7_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM2_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM2_Ovf_Reload_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM3_Ch0_Ch1_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM3_Ch2_Ch3_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM3_Ch4_Ch5_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM3_Ch6_Ch7_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM3_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
        {FTM3_Ovf_Reload_IRQn, (boolean)FALSE, 0U, undefined_handler},
    };

/* Configuration structure for interrupt controller */
const IntCtrl_Ip_CtrlConfigType intCtrlConfig = {
    89U,
    
    
    aIrqConfiguration
    
    
};
    

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
