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
#ifndef DMA_IP_CFG_DEVICE_REGISTERS_V2_H_
#define DMA_IP_CFG_DEVICE_REGISTERS_V2_H_

/**
*   @file    Dma_Ip_Cfg_DeviceRegistersV2.h
*
*   @version 2.0.0
*
*   @brief   AUTOSAR Mcl - Dma Ip Cfg Device Register V2 header file.
*   @details Contains common register information and specific register information for
*            DMA Hardware Version 2.
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "BasicTypes.h"

#include "S32K144_DMA.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_CFG_DEVICEREGISTERSV2_VENDOR_ID                       43
#define DMA_IP_CFG_DEVICEREGISTERSV2_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_CFG_DEVICEREGISTERSV2_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_CFG_DEVICEREGISTERSV2_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_CFG_DEVICEREGISTERSV2_SW_MAJOR_VERSION                2
#define DMA_IP_CFG_DEVICEREGISTERSV2_SW_MINOR_VERSION                0
#define DMA_IP_CFG_DEVICEREGISTERSV2_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Mcal header file are of the same Autosar version */
#if ((DMA_IP_CFG_DEVICEREGISTERSV2_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_DEVICEREGISTERSV2_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dma_Ip_Cfg_DeviceRegisters.h and Mcal.h are different"
#endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/*-----------------------------------------------/
/  SOC SPECIFIC DMA INSTANCES                    /
/-----------------------------------------------*/
#define DMA_IP_BASE                            (IP_DMA_BASE)
#define DMA_IP_PTR                             ((Dma_Ip_Hwv2InstRegType *)DMA_IP_BASE)
#define DMA_IP_DMA_HWV2_BASE_PTRS              { DMA_IP_PTR }

#define DMA_IP_HWV2_DMA_MP_GRPRI_COUNT         DMA_IP_MP_GRPRI_COUNT

#define DMA_IP_HWV2_DMA_NOF_INST               DMA_INSTANCE_COUNT       /* Total number of hardware instances */

#define DMA_IP_HWV2_PRIOLVL_REG_INDEX_CONV(x)  ((uint32)(x) ^ 3U)

/*-----------------------------------------------/
/  SOC SPECIFIC DMA CHANNELS                     /
/-----------------------------------------------*/
#define DMA_IP_TCD_BASE                     (IP_DMA_BASE + 4096U)
#define DMA_IP_TCD_PTR                      ((Dma_Ip_Hwv2TcdArrayType *)DMA_IP_TCD_BASE)
#define DMA_IP_TCD_HWV2_BASE_PTRS           { DMA_IP_TCD_PTR }

#define DMA_IP_TCD_RESERVED                 (0U)                     /* Reserved space between hardware TCDs */

#define DMA_IP_HWV2_TCD_NOF_CH              DMA_TCD_COUNT            /* Number of hardware channels */

#define DMA_IP_HWV2_TCD_NOF_INST            DMA_INSTANCE_COUNT       /* Number of hardware TCD instances */

/*-----------------------------------------------/
/  SOC SPECIFIC DMA TOTAL CHANNELS               /
/-----------------------------------------------*/
#define DMA_IP_NOF_HWV2_CH                  (DMA_IP_HWV2_TCD_NOF_INST * DMA_IP_HWV2_TCD_NOF_CH)  /* Total number of hardware channels of all instances */

/*-----------------------------------------------/
/  DMA HWV3 ES MASK                              /
/-----------------------------------------------*/
#define DMA_IP_MP_ES_MASK                   (DMA_ES_DBE_MASK | DMA_ES_SBE_MASK | DMA_ES_SGE_MASK |\
                                             DMA_ES_NCE_MASK | DMA_ES_DOE_MASK | DMA_ES_DAE_MASK |\
                                             DMA_ES_SOE_MASK | DMA_ES_SAE_MASK | DMA_ES_VLD_MASK |\
                                             DMA_ES_CPE_MASK | DMA_ES_ECX_MASK | DMA_ES_ERRCHN_MASK)

/*-----------------------------------------------/
/  SOC SPECIFIC DMA TCD ALIGNMENT                /
/-----------------------------------------------*/
#define DMA_IP_TCD_NOT_ALIGNED               STD_OFF

/*==================================================================================================
   COMMON DMA REGISTER PROTECTION
==================================================================================================*/
/*-----------------------------------------------/
/  DMA REGISTER PROTECTION SIZE                  /
/-----------------------------------------------*/
#define DMA_IP_REG_PROT_SIZE                ((uint32)0x4U)

/*-----------------------------------------------/
/  DMA BASE REGISTER ADDRESS                     /
/-----------------------------------------------*/
#define DMA_IP_BASE_ADDR(instIdx)           ((uint32)IP_DMA_BASE)

#define DMA_IP_CSR_BASE_ADDR(instIdx) \
        ((uint32)(DMA_IP_BASE_ADDR(instIdx)))

/*==================================================================================================
                                        DMA MP STRUCTURE
==================================================================================================*/
typedef struct {
  __IO uint32_t reg_CR;                                /**< Control Register, offset: 0x0 */
  __I  uint32_t reg_ES;                                /**< Error Status Register, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t reg_ERQ;                               /**< Enable Request Register, offset: 0xC */
       uint8_t RESERVED_1[4];
  __IO uint32_t reg_EEI;                               /**< Enable Error Interrupt Register, offset: 0x14 */
  __O  uint8_t  reg_CEEI;                               /**< Clear Enable Error Interrupt Register, offset: 0x18 */
  __O  uint8_t  reg_SEEI;                               /**< Set Enable Error Interrupt Register, offset: 0x19 */
  __O  uint8_t  reg_CERQ;                               /**< Clear Enable Request Register, offset: 0x1A */
  __O  uint8_t  reg_SERQ;                               /**< Set Enable Request Register, offset: 0x1B */
  __O  uint8_t  reg_CDNE;                               /**< Clear DONE Status Bit Register, offset: 0x1C */
  __O  uint8_t  reg_SSRT;                               /**< Set START Bit Register, offset: 0x1D */
  __O  uint8_t  reg_CERR;                               /**< Clear Error Register, offset: 0x1E */
  __O  uint8_t  reg_CINT;                               /**< Clear Interrupt Request Register, offset: 0x1F */
       uint8_t RESERVED_2[4];
  __IO uint32_t reg_INT;                               /**< Interrupt Request Register, offset: 0x24 */
       uint8_t RESERVED_3[4];
  __IO uint32_t reg_ERR;                               /**< Error Register, offset: 0x2C */
       uint8_t RESERVED_4[4];
  __I  uint32_t reg_HRS;                               /**< Hardware Request Status Register, offset: 0x34 */
       uint8_t RESERVED_5[12];
  __IO uint32_t reg_EARS;                              /**< Enable Asynchronous Request in Stop Register, offset: 0x44 */
       uint8_t RESERVED_6[184];
  __IO uint8_t  reg_DCHPRI[DMA_DCHPRI_COUNT];           /**< Channel n Priority Register, array offset: 0x100, array step: 0x1 */
       uint8_t RESERVED_7[3824];
} Dma_Ip_Hwv2InstRegType;

/*==================================================================================================
                                         TCD STRUCTURE
==================================================================================================*/

typedef struct {
    uint32 reg_SADDR;                       /**< @brief TCD Source Address, array offset: 0x20, array step: 0x1000 */
    uint16 reg_SOFF;                        /**< @brief TCD Signed Source Address Offset, array offset: 0x24, array step: 0x1000 */
    uint16 reg_ATTR;                        /**< @brief TCD Transfer Attributes, array offset: 0x26, array step: 0x1000 */
    union {                             /* offset: 0x28, array step: 0x1000 */
        uint32 reg_MLOFFNO;                 /**< @brief TCD Transfer Size without Minor Loop Offsets Register, array offset: 0x28, array step: 0x1000 */
        uint32 reg_MLOFFYES;                /**< @brief TCD Transfer Size with Minor Loop Offsets Register, array offset: 0x28, array step: 0x1000 */
    } reg_NBYTES;
    uint32 reg_SLAST_SDA;                       /**< @brief TCD Last Source Address Adjustment / Store reg_DADDR Address Register, array offset: 0x2C, array step: 0x1000 */
    uint32 reg_DADDR;                       /**< @brief TCD Destination Address, array offset: 0x30, array step: 0x1000 */
    uint16 reg_DOFF;                        /**< @brief TCD Signed Destination Address Offset, array offset: 0x34, array step: 0x1000 */
    union {                             /* offset: 0x36, array step: 0x1000 */
        uint16 reg_ELINKNO;                 /**< @brief TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) Register, array offset: 0x36, array step: 0x1000 */
        uint16 reg_ELINKYES;                /**< @brief TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) Register, array offset: 0x36, array step: 0x1000 */
    } reg_CITER;
    uint32 reg_DLAST_SGA;                   /**< @brief TCD Last Destination Address Adjustment / Scatter Gather Address Register, array offset: 0x38, array step: 0x1000 */
    uint16 reg_CSR;                         /**< @brief TCD Control and Status Register, array offset: 0x3C, array step: 0x1000 */
    union {                             /* offset: 0x3E, array step: 0x1000 */
        uint16 reg_ELINKNO;                 /**< @brief TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) Register, array offset: 0x3E, array step: 0x1000 */
        uint16 reg_ELINKYES;                /**< @brief TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) Register, array offset: 0x3E, array step: 0x1000 */
    } reg_BITER;
} Dma_Ip_TcdRegType, Dma_Ip_SwTcdRegType;

typedef struct {
    Dma_Ip_TcdRegType tTcdReg;
} Dma_Ip_Hwv2ChTcdRegType;

#if (DMA_IP_TCD_NOT_ALIGNED == STD_OFF)
typedef struct {
    struct {
        Dma_Ip_Hwv2ChTcdRegType tChTcdReg;
    } TCD_RSV[DMA_IP_HWV2_TCD_NOF_CH];
} Dma_Ip_Hwv2TcdArrayType;
#endif

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef DMA_IP_CFG_DEVICE_REGISTERS_V2_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
