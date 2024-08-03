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
*   Copyright 2020-2024 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef DMA_MUX_IP_CFG_DEFINES_H
#define DMA_MUX_IP_CFG_DEFINES_H

/**
*   @file Dma_Mux_Ip_CfgDefines.h
*
*   @addtogroup DMA_MUX_IP DMA_MUX IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
/**
 * Include specific header file
 */
#include "StandardTypes.h" 
#include "S32K144_DMAMUX.h"



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_DMA_MUX_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_DMA_MUX_IP_CFG_DEFINES_SW_MAJOR_VERSION             2
#define RM_DMA_MUX_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_DMA_MUX_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Checks against StandardTypes.h */
#if ((RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
    (RM_DMA_MUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dma_Mux_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define RM_IP_ENABLE_DMA_MUX                (STD_ON)
/** @brief    Development error checking */
#define DMA_MUX_IP_DEV_ERROR_DETECT         (STD_ON)


#define DMA_MUX_IP_INSTANCE_COUNT            (1UL)
#define DMA_MUX_IP_INSTANCE_BASE_PTRS        {IP_DMAMUX}
#define DMA_MUX_IP_GATE_OFFSET(x)           ((x) ^ ((uint8)0UL))

#define DMA_MUX_INSTANCE_0                  (0U)


/* Sources of DMA_MUX_INSTANCE_0 */
#define DMA_MUX_0_REQ_DISABLED                                         (0U)
#define DMA_MUX_0_LPUART_0_RX_REQUEST                                  (2U)
#define DMA_MUX_0_LPUART_0_TX_REQUEST                                  (3U)
#define DMA_MUX_0_LPUART_1_RX_REQUEST                                  (4U)
#define DMA_MUX_0_LPUART_1_TX_REQUEST                                  (5U)
#define DMA_MUX_0_LPUART_2_RX_REQUEST                                  (6U)
#define DMA_MUX_0_LPUART_2_TX_REQUEST                                  (7U)
#define DMA_MUX_0_FLEXIO_SHIFT_0_REQUEST                               (10U)
#define DMA_MUX_0_FLEXIO_SHIFT_1_REQUEST                               (11U)
#define DMA_MUX_0_FLEXIO_SHIFT_2_REQUEST                               (12U)
#define DMA_MUX_0_FLEXIO_SHIFT_3_REQUEST                               (13U)
#define DMA_MUX_0_LPSPI_0_RX_REQUEST                                   (14U)
#define DMA_MUX_0_LPSPI_0_TX_REQUEST                                   (15U)
#define DMA_MUX_0_LPSPI_1_RX_REQUEST                                   (16U)
#define DMA_MUX_0_LPSPI_1_TX_REQUEST                                   (17U)
#define DMA_MUX_0_LPSPI_2_RX_REQUEST                                   (18U)
#define DMA_MUX_0_LPSPI_2_TX_REQUEST                                   (19U)
#define DMA_MUX_0_FLEXTIMER_1_CH_0_REQUEST                             (20U)
#define DMA_MUX_0_FLEXTIMER_1_CH_1_REQUEST                             (21U)
#define DMA_MUX_0_FLEXTIMER_1_CH_2_REQUEST                             (22U)
#define DMA_MUX_0_FLEXTIMER_1_CH_3_REQUEST                             (23U)
#define DMA_MUX_0_FLEXTIMER_1_CH_4_REQUEST                             (24U)
#define DMA_MUX_0_FLEXTIMER_1_CH_5_REQUEST                             (25U)
#define DMA_MUX_0_FLEXTIMER_1_CH_6_REQUEST                             (26U)
#define DMA_MUX_0_FLEXTIMER_1_CH_7_REQUEST                             (27U)
#define DMA_MUX_0_FLEXTIMER_2_CH_0_REQUEST                             (28U)
#define DMA_MUX_0_FLEXTIMER_2_CH_1_REQUEST                             (29U)
#define DMA_MUX_0_FLEXTIMER_2_CH_2_REQUEST                             (30U)
#define DMA_MUX_0_FLEXTIMER_2_CH_3_REQUEST                             (31U)
#define DMA_MUX_0_FLEXTIMER_2_CH_4_REQUEST                             (32U)
#define DMA_MUX_0_FLEXTIMER_2_CH_5_REQUEST                             (33U)
#define DMA_MUX_0_FLEXTIMER_2_CH_6_REQUEST                             (34U)
#define DMA_MUX_0_FLEXTIMER_2_CH_7_REQUEST                             (35U)
#define DMA_MUX_0_FLEXTIMER_0_CH_0_7_REQUEST                           (36U)
#define DMA_MUX_0_FLEXTIMER_3_CH_0_7_REQUEST                           (37U)
#define DMA_MUX_0_ADC_0_DMA_REQUEST                                    (42U)
#define DMA_MUX_0_ADC_1_DMA_REQUEST                                    (43U)
#define DMA_MUX_0_LPI2C_0_RX_REQUEST                                   (44U)
#define DMA_MUX_0_LPI2C_0_TX_REQUEST                                   (45U)
#define DMA_MUX_0_SSL_PDB_PIONEER_0_REQUEST                            (46U)
#define DMA_MUX_0_SSL_PDB_PIONEER_1_REQUEST                            (47U)
#define DMA_MUX_0_ANALOG_COMPARATOR_0_REQUEST                          (48U)
#define DMA_MUX_0_RGPIOC_PCTL_PORTA_REQUEST                            (49U)
#define DMA_MUX_0_RGPIOC_PCTL_PORTB_REQUEST                            (50U)
#define DMA_MUX_0_RGPIOC_PCTL_PORTC_REQUEST                            (51U)
#define DMA_MUX_0_RGPIOC_PCTL_PORTD_REQUEST                            (52U)
#define DMA_MUX_0_RGPIOC_PCTL_PORTE_REQUEST                            (53U)
#define DMA_MUX_0_FLEXCAN_0_DMA_REQUEST                                (54U)
#define DMA_MUX_0_FLEXCAN_1_DMA_REQUEST                                (55U)
#define DMA_MUX_0_FLEXCAN_2_DMA_REQUEST                                (56U)
#define DMA_MUX_0_LPTIMER_0_DMA_REQUEST                                (59U)
#define DMA_MUX_0_REQ_ALWAYS_ON_0                                      (62U)
#define DMA_MUX_0_REQ_ALWAYS_ON_1                                      (63U)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DMA_MUX_IP_CFG_DEFINES_H */

