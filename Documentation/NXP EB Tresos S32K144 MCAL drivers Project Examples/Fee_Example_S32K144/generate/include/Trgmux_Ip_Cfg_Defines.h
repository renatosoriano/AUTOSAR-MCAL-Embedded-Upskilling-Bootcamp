/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,FLEXIO
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors
*   
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/* Prevention from multiple including the same header */
#ifndef TRGMUX_IP_CFG_DEFINES_H_
#define TRGMUX_IP_CFG_DEFINES_H_

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
#include "StandardTypes.h"
#include "BasicTypes.h"


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_CFG_DEFINES_VENDOR_ID                    43
#define TRGMUX_IP_CFG_DEFINES_MODULE_ID                    255
#define TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define TRGMUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define TRGMUX_IP_CFG_DEFINES_SW_MAJOR_VERSION             2
#define TRGMUX_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define TRGMUX_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and StandardTypes header file are of the same Autosar version */
#if ((TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Trgmux_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*-----------------------------------------------/
/  TRGMUX IP USER MODE SUPPORT                   /
/-----------------------------------------------*/
#define TRGMUX_IP_USER_MODE_SUPPORT_IS_AVAILABLE      STD_OFF

#define TRGMUX_IP_IS_AVAILABLE                         STD_OFF

#define TRGMUX_IP_MULTICORE_IS_AVAILABLE               STD_OFF

/*-----------------------------------------------/
/  TRGMUX IP DEV ERROR DETECT SUPPORT            /
/-----------------------------------------------*/
#define TRGMUX_IP_DEV_ERROR_DETECT                     STD_OFF

/*-----------------------------------------------/
/  TRGMUX HARDWARE INSTANCE                      /
/-----------------------------------------------*/
#define TRGMUX_IP_HW_INST_0                            ((uint8)0U)

/*-----------------------------------------------/
/  TRGMUX HARDWARE TRIGGER INPUT                 /
/-----------------------------------------------*/
#define TRGMUX_IP_INPUT_LOGIC0_VSS                     ((uint8)0U)
#define TRGMUX_IP_INPUT_LOGIC1_VDD                     ((uint8)1U)
#define TRGMUX_IP_INPUT_TRGMUX_IN0                     ((uint8)2U)
#define TRGMUX_IP_INPUT_TRGMUX_IN1                     ((uint8)3U)
#define TRGMUX_IP_INPUT_TRGMUX_IN2                     ((uint8)4U)
#define TRGMUX_IP_INPUT_TRGMUX_IN3                     ((uint8)5U)
#define TRGMUX_IP_INPUT_TRGMUX_IN4                     ((uint8)6U)
#define TRGMUX_IP_INPUT_TRGMUX_IN5                     ((uint8)7U)
#define TRGMUX_IP_INPUT_TRGMUX_IN6                     ((uint8)8U)
#define TRGMUX_IP_INPUT_TRGMUX_IN7                     ((uint8)9U)
#define TRGMUX_IP_INPUT_TRGMUX_IN8                     ((uint8)10U)
#define TRGMUX_IP_INPUT_TRGMUX_IN9                     ((uint8)11U)
#define TRGMUX_IP_INPUT_TRGMUX_IN10                    ((uint8)12U)
#define TRGMUX_IP_INPUT_TRGMUX_IN11                    ((uint8)13U)
#define TRGMUX_IP_INPUT_CMP0_OUT                       ((uint8)14U)
#define TRGMUX_IP_INPUT_LPIT_CH0                       ((uint8)17U)
#define TRGMUX_IP_INPUT_LPIT_CH1                       ((uint8)18U)
#define TRGMUX_IP_INPUT_LPIT_CH2                       ((uint8)19U)
#define TRGMUX_IP_INPUT_LPIT_CH3                       ((uint8)20U)
#define TRGMUX_IP_INPUT_LPTMR0                         ((uint8)21U)
#define TRGMUX_IP_INPUT_FTM0_INIT_TRIG                 ((uint8)22U)
#define TRGMUX_IP_INPUT_FTM0_EXT_TRIG                  ((uint8)23U)
#define TRGMUX_IP_INPUT_FTM1_INIT_TRIG                 ((uint8)24U)
#define TRGMUX_IP_INPUT_FTM1_EXT_TRIG                  ((uint8)25U)
#define TRGMUX_IP_INPUT_FTM2_INIT_TRIG                 ((uint8)26U)
#define TRGMUX_IP_INPUT_FTM2_EXT_TRIG                  ((uint8)27U)
#define TRGMUX_IP_INPUT_FTM3_INIT_TRIG                 ((uint8)28U)
#define TRGMUX_IP_INPUT_FTM3_EXT_TRIG                  ((uint8)29U)
#define TRGMUX_IP_INPUT_ADC0_COCO_0                    ((uint8)30U)
#define TRGMUX_IP_INPUT_ADC0_COCO_1                    ((uint8)31U)
#define TRGMUX_IP_INPUT_ADC1_COCO_0                    ((uint8)32U)
#define TRGMUX_IP_INPUT_ADC1_COCO_1                    ((uint8)33U)
#define TRGMUX_IP_INPUT_PDB0_ADCH0_TRIG                ((uint8)34U)
#define TRGMUX_IP_INPUT_PDB0_PULSE_OUT                 ((uint8)36U)
#define TRGMUX_IP_INPUT_PDB1_ADCH0_TRIG                ((uint8)37U)
#define TRGMUX_IP_INPUT_PDB1_PULSE_OUT                 ((uint8)39U)
#define TRGMUX_IP_INPUT_RTC_ALARM                      ((uint8)43U)
#define TRGMUX_IP_INPUT_RTC_SECOND                     ((uint8)44U)
#define TRGMUX_IP_INPUT_FLEXIO_TRIG0                   ((uint8)45U)
#define TRGMUX_IP_INPUT_FLEXIO_TRIG1                   ((uint8)46U)
#define TRGMUX_IP_INPUT_FLEXIO_TRIG2                   ((uint8)47U)
#define TRGMUX_IP_INPUT_FLEXIO_TRIG3                   ((uint8)48U)
#define TRGMUX_IP_INPUT_LPUART0_RX_DATA                ((uint8)49U)
#define TRGMUX_IP_INPUT_LPUART0_TX_DATA                ((uint8)50U)
#define TRGMUX_IP_INPUT_LPUART0_RX_IDLE                ((uint8)51U)
#define TRGMUX_IP_INPUT_LPUART1_RX_DATA                ((uint8)52U)
#define TRGMUX_IP_INPUT_LPUART1_TX_DATA                ((uint8)53U)
#define TRGMUX_IP_INPUT_LPUART1_RX_IDLE                ((uint8)54U)
#define TRGMUX_IP_INPUT_LPI2C0_MASTER_TRIG             ((uint8)55U)
#define TRGMUX_IP_INPUT_LPI2C0_SLAVE_TRIG              ((uint8)56U)
#define TRGMUX_IP_INPUT_LPSPI0_FRAME                   ((uint8)59U)
#define TRGMUX_IP_INPUT_LPSPI0_RX_DATA                 ((uint8)60U)
#define TRGMUX_IP_INPUT_LPSPI1_FRAME                   ((uint8)61U)
#define TRGMUX_IP_INPUT_LPSPI1_RX_DATA                 ((uint8)62U)
#define TRGMUX_IP_INPUT_SIM_SW_TRIG                    ((uint8)63U)
#define TRGMUX_IP_INPUT_LPI2C1_MASTER_TRIG             ((uint8)67U)
#define TRGMUX_IP_INPUT_LPI2C1_SLAVE_TRIG              ((uint8)68U)
#define TRGMUX_IP_INPUT_FTM4_INIT_TRIG                 ((uint8)69U)
#define TRGMUX_IP_INPUT_FTM4_EXT_TRIG                  ((uint8)70U)
#define TRGMUX_IP_INPUT_FTM5_INIT_TRIG                 ((uint8)71U)
#define TRGMUX_IP_INPUT_FTM5_EXT_TRIG                  ((uint8)72U)
#define TRGMUX_IP_INPUT_FTM6_INIT_TRIG                 ((uint8)73U)
#define TRGMUX_IP_INPUT_FTM6_EXT_TRIG                  ((uint8)74U)
#define TRGMUX_IP_INPUT_FTM7_INIT_TRIG                 ((uint8)75U)
#define TRGMUX_IP_INPUT_FTM7_EXT_TRIG                  ((uint8)76U)

/*-----------------------------------------------/
/  TRGMUX HARDWARE TRIGGER OUTPUT                /
/-----------------------------------------------*/
#define TRGMUX_IP_OUTPUT_DMA_CH0                       ((uint8)0U)
#define TRGMUX_IP_OUTPUT_DMA_CH1                       ((uint8)1U)
#define TRGMUX_IP_OUTPUT_DMA_CH2                       ((uint8)2U)
#define TRGMUX_IP_OUTPUT_DMA_CH3                       ((uint8)3U)
#define TRGMUX_IP_OUTPUT_EXTOUT0_TRGMUX_OUT0           ((uint8)4U)
#define TRGMUX_IP_OUTPUT_EXTOUT0_TRGMUX_OUT1           ((uint8)5U)
#define TRGMUX_IP_OUTPUT_EXTOUT0_TRGMUX_OUT2           ((uint8)6U)
#define TRGMUX_IP_OUTPUT_EXTOUT0_TRGMUX_OUT3           ((uint8)7U)
#define TRGMUX_IP_OUTPUT_EXTOUT1_TRGMUX_OUT4           ((uint8)8U)
#define TRGMUX_IP_OUTPUT_EXTOUT1_TRGMUX_OUT5           ((uint8)9U)
#define TRGMUX_IP_OUTPUT_EXTOUT1_TRGMUX_OUT6           ((uint8)10U)
#define TRGMUX_IP_OUTPUT_EXTOUT1_TRGMUX_OUT7           ((uint8)11U)
#define TRGMUX_IP_OUTPUT_ADC0_ADHWT_TRIG_0             ((uint8)12U)
#define TRGMUX_IP_OUTPUT_ADC0_ADHWT_TRIG_1             ((uint8)13U)
#define TRGMUX_IP_OUTPUT_ADC0_ADHWT_TRIG_2             ((uint8)14U)
#define TRGMUX_IP_OUTPUT_ADC0_ADHWT_TRIG_3             ((uint8)15U)
#define TRGMUX_IP_OUTPUT_ADC1_ADHWT_TRIG_0             ((uint8)16U)
#define TRGMUX_IP_OUTPUT_ADC1_ADHWT_TRIG_1             ((uint8)17U)
#define TRGMUX_IP_OUTPUT_ADC1_ADHWT_TRIG_2             ((uint8)18U)
#define TRGMUX_IP_OUTPUT_ADC1_ADHWT_TRIG_3             ((uint8)19U)
#define TRGMUX_IP_OUTPUT_CMP0_SAMPLE_INPUT             ((uint8)28U)
#define TRGMUX_IP_OUTPUT_FTM0_HWTRIG0                  ((uint8)40U)
#define TRGMUX_IP_OUTPUT_FTM0_FAULT0                   ((uint8)41U)
#define TRGMUX_IP_OUTPUT_FTM0_FAULT1                   ((uint8)42U)
#define TRGMUX_IP_OUTPUT_FTM0_FAULT2                   ((uint8)43U)
#define TRGMUX_IP_OUTPUT_FTM1_HWTRIG0                  ((uint8)44U)
#define TRGMUX_IP_OUTPUT_FTM1_FAULT0                   ((uint8)45U)
#define TRGMUX_IP_OUTPUT_FTM1_FAULT1                   ((uint8)46U)
#define TRGMUX_IP_OUTPUT_FTM1_FAULT2                   ((uint8)47U)
#define TRGMUX_IP_OUTPUT_FTM2_HWTRIG0                  ((uint8)48U)
#define TRGMUX_IP_OUTPUT_FTM2_FAULT0                   ((uint8)49U)
#define TRGMUX_IP_OUTPUT_FTM2_FAULT1                   ((uint8)50U)
#define TRGMUX_IP_OUTPUT_FTM2_FAULT2                   ((uint8)51U)
#define TRGMUX_IP_OUTPUT_FTM3_HWTRIG0                  ((uint8)52U)
#define TRGMUX_IP_OUTPUT_FTM3_FAULT0                   ((uint8)53U)
#define TRGMUX_IP_OUTPUT_FTM3_FAULT1                   ((uint8)54U)
#define TRGMUX_IP_OUTPUT_FTM3_FAULT2                   ((uint8)55U)
#define TRGMUX_IP_OUTPUT_PDB0_TRIGGER_IN0              ((uint8)56U)
#define TRGMUX_IP_OUTPUT_PDB1_TRIGGER_IN0              ((uint8)60U)
#define TRGMUX_IP_OUTPUT_FLEXIO_TRG_TIM0               ((uint8)68U)
#define TRGMUX_IP_OUTPUT_FLEXIO_TRG_TIM1               ((uint8)69U)
#define TRGMUX_IP_OUTPUT_FLEXIO_TRG_TIM2               ((uint8)70U)
#define TRGMUX_IP_OUTPUT_FLEXIO_TRG_TIM3               ((uint8)71U)
#define TRGMUX_IP_OUTPUT_LPIT0_TRG_CH0                 ((uint8)72U)
#define TRGMUX_IP_OUTPUT_LPIT0_TRG_CH1                 ((uint8)73U)
#define TRGMUX_IP_OUTPUT_LPIT0_TRG_CH2                 ((uint8)74U)
#define TRGMUX_IP_OUTPUT_LPIT0_TRG_CH3                 ((uint8)75U)
#define TRGMUX_IP_OUTPUT_LPUART0_TRG                   ((uint8)76U)
#define TRGMUX_IP_OUTPUT_LPUART1_TRG                   ((uint8)80U)
#define TRGMUX_IP_OUTPUT_LPI2C0_TRG                    ((uint8)84U)
#define TRGMUX_IP_OUTPUT_LPSPI0_TRG                    ((uint8)92U)
#define TRGMUX_IP_OUTPUT_LPSPI1_TRG                    ((uint8)96U)
#define TRGMUX_IP_OUTPUT_LPTMR0_ALT0                   ((uint8)100U)
#define TRGMUX_IP_OUTPUT_LPI2C1_TRG                    ((uint8)108U)
#define TRGMUX_IP_OUTPUT_FTM4_HWTRIG0                  ((uint8)112U)
#define TRGMUX_IP_OUTPUT_FTM5_HWTRIG0                  ((uint8)116U)
#define TRGMUX_IP_OUTPUT_FTM6_HWTRIG0                  ((uint8)120U)
#define TRGMUX_IP_OUTPUT_FTM7_HWTRIG0                  ((uint8)124U)


#ifdef __cplusplus
}
#endif

#endif  /* TRGMUX_IP_CFG_DEFINES_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
