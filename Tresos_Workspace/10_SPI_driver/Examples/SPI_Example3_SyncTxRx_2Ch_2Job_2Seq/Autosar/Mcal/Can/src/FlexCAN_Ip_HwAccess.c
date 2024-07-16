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
 *  @file FlexCAN_Ip_HwAccess.c
 *
 *  @brief FlexCAN Functions to Hardware Acess
 *
 *  @addtogroup FlexCAN
 *  @{
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
#include "FlexCAN_Ip_HwAccess.h"
#include "SchM_Can_43_FLEXCAN.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_HWACCESS_VENDOR_ID_C                      43
#define FLEXCAN_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXCAN_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXCAN_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXCAN_IP_HWACCESS_SW_MAJOR_VERSION_C               2
#define FLEXCAN_IP_HWACCESS_SW_MINOR_VERSION_C               0
#define FLEXCAN_IP_HWACCESS_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip_HwAccess header file are of the same vendor */
#if (FLEXCAN_IP_HWACCESS_VENDOR_ID_C != FLEXCAN_IP_HWACCESS_VENDOR_ID_H)
    #error "FlexCAN_Ip_HwAccess.c and FlexCAN_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((FLEXCAN_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C    != FLEXCAN_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C    != FLEXCAN_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C != FLEXCAN_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip_HwAccess.c and FlexCAN_Ip_HwAccess.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((FLEXCAN_IP_HWACCESS_SW_MAJOR_VERSION_C != FLEXCAN_IP_HWACCESS_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_HWACCESS_SW_MINOR_VERSION_C != FLEXCAN_IP_HWACCESS_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_HWACCESS_SW_PATCH_VERSION_C != FLEXCAN_IP_HWACCESS_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Ip_HwAccess.c and FlexCAN_Ip_HwAccess.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SchM_Can header file are of the same version */
    #if ((FLEXCAN_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C    != SCHM_CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION) || \
        (FLEXCAN_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C     != SCHM_CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of FlexCAN_Ip_HwAccess.c and SchM_Can_43_FLEXCAN.h are different"
    #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* CAN FD extended data length DLC encoding */
#define FLEXCAN_IP_DLC_VALUE_12_BYTES              9U
#define FLEXCAN_IP_DLC_VALUE_16_BYTES              10U
#define FLEXCAN_IP_DLC_VALUE_20_BYTES              11U
#define FLEXCAN_IP_DLC_VALUE_24_BYTES              12U
#define FLEXCAN_IP_DLC_VALUE_32_BYTES              13U
#define FLEXCAN_IP_DLC_VALUE_48_BYTES              14U
#define FLEXCAN_IP_DLC_VALUE_64_BYTES              15U

#define FLEXCAN_IP_RX_FIFO_FILTER_TABLE_OFFSET      0x000000E0U
#define FLEXCAN_IP_RX_FIFO_ACCEPT_REMOTE_FRAME      1UL
#define FLEXCAN_IP_RX_FIFO_ACCEPT_EXT_FRAME         1UL

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
#define FLEXCAN_IP_ENHANCED_RX_FIFO_FILTER_TABLE_BASE       0x0U
#endif

/* Determines the RxFIFO Filter element number */
#define FLEXCAN_IP_RXFIFO_FILTER_ELEM_NUM(x) (((x) + 1U) * 8U)
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (FLEXCAN_IP_FEATURE_NO_CACHE_NEEDED == STD_ON)
#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#else
#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_32
#endif /* (FLEXCAN_IP_FEATURE_NO_CACHE_NEEDED == STD_ON) */
#include "Can_43_FLEXCAN_MemMap.h"

static volatile uint32 FlexCAN_Ip_au32ImaskBuff[FLEXCAN_INSTANCE_COUNT][FLEXCAN_IP_FEATURE_MBDSR_COUNT];

#if (FLEXCAN_IP_FEATURE_NO_CACHE_NEEDED == STD_ON)
#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#else
#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_32
#endif /* (FLEXCAN_IP_FEATURE_NO_CACHE_NEEDED == STD_ON) */
#include "Can_43_FLEXCAN_MemMap.h"


#if (FLEXCAN_IP_FEATURE_NO_CACHE_NEEDED == STD_ON)
#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
#define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_8
#endif /* (FLEXCAN_IP_FEATURE_NO_CACHE_NEEDED == STD_ON) */
#include "Can_43_FLEXCAN_MemMap.h"

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
static volatile uint8 filterIdMap[FLEXCAN_INSTANCE_COUNT][FLEXCAN_IP_ENHANCED_RXFIFO_FILTERDEPTH];
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */

#if (FLEXCAN_IP_FEATURE_NO_CACHE_NEEDED == STD_ON)
#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
#define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_8
#endif /* (FLEXCAN_IP_FEATURE_NO_CACHE_NEEDED == STD_ON) */
#include "Can_43_FLEXCAN_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"
static uint8 FlexCAN_ComputeDLCValue(uint8 payloadSize);

static void FlexCAN_ClearRAM(FLEXCAN_Type * base);

#if (FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY == STD_ON)
static boolean FlexCAN_IsExpandableMemoryAvailable(const FLEXCAN_Type * base);
#endif /* if FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY */

#if (defined (S32K116) || defined (S32K118))
static uint32 FlexCAN_DeserializeRevUint32(const uint8 * Buffer);

inline static uint32 FlexCAN_DataTransferTxMsgBuff(volatile uint32 * MbData32,
                                                   const Flexcan_Ip_MsbuffCodeStatusType * Cs,
                                                   const uint8 * MsgData);
#endif /* if (defined (S32K116) || defined (S32K118)) */

/*!
 * @brief Gets the payload size of the Ramblock.
 *
 * @param   base         The FlexCAN base address
 * @return  The payload size in bytes
 */
static uint8 FlexCAN_GetPayloadSize(const FLEXCAN_Type * base, uint8 mbdsrIdx);

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_OFF)
/*!
 * @brief Computes the maximum payload size (in bytes), given a DLC
 *
 * @param   dlcValue    DLC code from the MB memory.
 * @return  payload size (in bytes)
 */
static uint8 FlexCAN_ComputePayloadSize(uint8 dlcValue);
#endif /*(FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_OFF) */

#if (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)
#if (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON)
#if (FLEXCAN_IP_HR_TIMESTAMP_SRC_SELECTABLE == STD_ON)
#if (STD_ON == FLEXCAN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
void FlexCAN_ConfigTimestampModule
(
#ifdef FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED
    uint8 instance,
#endif /* FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED */
    const Flexcan_Ip_TimeStampConfigType * config
);
#else
static void FlexCAN_ConfigTimestampModule
(
#ifdef FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED
    uint8 instance,
#endif /* FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED */
    const Flexcan_Ip_TimeStampConfigType * config
);
#endif
#endif /* (FLEXCAN_IP_HR_TIMESTAMP_SRC_SELECTABLE == STD_ON) */
#endif /* (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON) */
#endif /* (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON) */
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (defined (S32K116) || defined (S32K118))
static uint32 FlexCAN_DeserializeRevUint32(const uint8 * Buffer)
{
    uint32 value = 0;

    value |= (uint32)Buffer[0] << 24U;
    value |= (uint32)Buffer[1] << 16U;
    value |= (uint32)Buffer[2] << 8U;
    value |= (uint32)Buffer[3];

    return value;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_DataTransferTxMsgBuff
 * Description   : Transfer Payload data in message buffer, in case of unaligned
 * buffer it makes a byte alignment.
 * This function is private.
 *
 *END**************************************************************************/
inline static uint32 FlexCAN_DataTransferTxMsgBuff(volatile uint32 * MbData32,
                                                   const Flexcan_Ip_MsbuffCodeStatusType * Cs,
                                                   const uint8 * MsgData)
{
    uint32 Databyte;
    const uint32 * MsgData_32 = (const uint32 *)MsgData;

    /* Check if the buffer address is aligned */
    if (((uint32)MsgData_32 & 0x3U) != 0U)
    {
        for (Databyte = 0U; Databyte < (Cs->dataLen & ~3U); Databyte += 4U)
        {
            MbData32[Databyte >> 2U] = FlexCAN_DeserializeRevUint32(&MsgData[Databyte]);
        }
    }
    else
    {
        for (Databyte = 0U; Databyte < (Cs->dataLen & ~3U); Databyte += 4U)
        {
            FLEXCAN_IP_SWAP_BYTES_IN_WORD(MsgData_32[Databyte >> 2U], MbData32[Databyte >> 2U]);
        }
    }

    return Databyte;
}
#endif /* if (defined (S32K116) || defined (S32K118)) */
/*FUNCTION**********************************************************************
 *
 * Function Name: FLEXCAN_ComputeDLCValue
 * Description  : Computes the DLC field value, given a payload size (in bytes).
 *
 *END**************************************************************************/
static uint8 FlexCAN_ComputeDLCValue(uint8 payloadSize)
{
    uint32 ret = 0xFFU;                   /* 0,  1,  2,  3,  4,  5,  6,  7,  8, */
    static const uint8 payload_code[65] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U,
                                           /* 9 to 12 payload have DLC Code 12 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_12_BYTES, FLEXCAN_IP_DLC_VALUE_12_BYTES, FLEXCAN_IP_DLC_VALUE_12_BYTES, FLEXCAN_IP_DLC_VALUE_12_BYTES,
                                           /* 13 to 16 payload have DLC Code 16 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_16_BYTES, FLEXCAN_IP_DLC_VALUE_16_BYTES, FLEXCAN_IP_DLC_VALUE_16_BYTES, FLEXCAN_IP_DLC_VALUE_16_BYTES,
                                           /* 17 to 20 payload have DLC Code 20 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_20_BYTES, FLEXCAN_IP_DLC_VALUE_20_BYTES, FLEXCAN_IP_DLC_VALUE_20_BYTES, FLEXCAN_IP_DLC_VALUE_20_BYTES,
                                           /* 21 to 24 payload have DLC Code 24 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_24_BYTES, FLEXCAN_IP_DLC_VALUE_24_BYTES, FLEXCAN_IP_DLC_VALUE_24_BYTES, FLEXCAN_IP_DLC_VALUE_24_BYTES,
                                           /* 25 to 32 payload have DLC Code 32 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES,
                                           /* 33 to 48 payload have DLC Code 48 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES,
                                           /* 49 to 64 payload have DLC Code 64 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES
                                          };

    if (payloadSize <= 64U)
    {
        ret = payload_code[payloadSize];
    }
    else
    {
        /* The argument is not a valid payload size will return 0xFF*/
    }

    return (uint8)ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_ClearRAM
 * Description   : Clears FlexCAN memory positions that require initialization.
 *
 *END**************************************************************************/
static void FlexCAN_ClearRAM(FLEXCAN_Type * base)
{
    uint32 databyte;
    uint32 RAM_size   = FlexCAN_GetMaxMbNum(base) * 4U;
    uint32 RXIMR_size = FlexCAN_GetMaxMbNum(base);
    /* Address of base + ram offset to point to MB start address */
    volatile uint32 * RAM = (uint32 *)((Flexcan_Ip_PtrSizeType)base + (uint32)FLEXCAN_IP_FEATURE_RAM_OFFSET);
    /* Clear MB region */
    for (databyte = 0U; databyte < RAM_size; databyte++)
    {
        RAM[databyte] = 0x0U;
    }
    RAM = (volatile uint32 *)base->RXIMR;
    /* Clear RXIMR region */
    for (databyte = 0U; databyte < RXIMR_size; databyte++)
    {
        RAM[databyte] = 0x0U;
    }
#if (FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY == STD_ON)
    if (FlexCAN_IsExpandableMemoryAvailable(base))
    {
        RAM = (uint32 *)((Flexcan_Ip_PtrSizeType)base + (uint32)FLEXCAN_IP_FEATURE_EXP_RAM_OFFSET);
        /* Clear Expanded Memory region */
        for (databyte = 0U; databyte < FLEXCAN_IP_RAM1n_COUNT; databyte++)
        {
            RAM[databyte] = 0x0U;
        }
    }
#endif /* if FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY */

#if (FLEXCAN_IP_FEATURE_HAS_MEM_ERR_DET == STD_ON)
    /* Set WRMFRZ bit in CTRL2 Register to grant write access to memory */
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_WRMFRZ_MASK) | FLEXCAN_CTRL2_WRMFRZ(1U);
    Flexcan_Ip_PtrSizeType ram_addr = (Flexcan_Ip_PtrSizeType)base + (uint32)FLEXCAN_IP_FEATURE_RAM_OFFSET;
    RAM = (volatile uint32 *)ram_addr;
    /* Clear RXMGMASK, RXFGMASK, RX14MASK, RX15MASK RAM mapping */
    base->RXMGMASK = 0U;
    base->RXFGMASK = 0U;
    base->RX14MASK = 0U;
    base->RX15MASK = 0U;
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
    /* Clear SMB FD region */
    for (databyte = 0U; databyte < (uint32)1U; databyte++)
    {
        RAM[databyte] = 0U;
    }
#endif
    /* Clear WRMFRZ bit in CTRL2 Register to restrict write access to memory */
    base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_WRMFRZ_MASK) | FLEXCAN_CTRL2_WRMFRZ(0U);
#endif /* if FLEXCAN_IP_FEATURE_HAS_MEM_ERR_DET */
}

#if (FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_IsExpandableMemoryAvailable
 * Description   : Checks if FlexCAN has expandable memory.
 * This function is private.
 *
 *END**************************************************************************/
static boolean FlexCAN_IsExpandableMemoryAvailable(const FLEXCAN_Type * base)
{
    uint32 i;
    static FLEXCAN_Type * const flexcanBase[] = FLEXCAN_IP_BASE_PTRS_HAS_EXPANDABLE_MEMORY;
    boolean returnValue = FALSE;
    for (i = 0U; i < FLEXCAN_IP_FEATURE_EXPANDABLE_MEMORY_NUM; i++)
    {
        if (base == flexcanBase[i])
        {
            returnValue = TRUE;
            break;
        }
    }

    return returnValue;
}

#endif /* if FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_ComputePayloadSize
 * Description   : Computes the maximum payload size (in bytes), given a DLC
 * field value.
 *
 *END**************************************************************************/
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
uint8 FlexCAN_ComputePayloadSize(uint8 dlcValue)
#else
static uint8 FlexCAN_ComputePayloadSize(uint8 dlcValue)
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */
{
    uint8 ret = 8U;

    if (dlcValue <= 8U)
    {
        ret = dlcValue;
    }
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
    else
    {
        switch (dlcValue)
        {
            case FLEXCAN_IP_DLC_VALUE_12_BYTES:
                ret = 12U;
                break;
            case FLEXCAN_IP_DLC_VALUE_16_BYTES:
                ret = 16U;
                break;
            case FLEXCAN_IP_DLC_VALUE_20_BYTES:
                ret = 20U;
                break;
            case FLEXCAN_IP_DLC_VALUE_24_BYTES:
                ret = 24U;
                break;
            case FLEXCAN_IP_DLC_VALUE_32_BYTES:
                ret = 32U;
                break;
            case FLEXCAN_IP_DLC_VALUE_48_BYTES:
                ret = 48U;
                break;
            case FLEXCAN_IP_DLC_VALUE_64_BYTES:
                ret = 64U;
                break;
            default:
                /* The argument is not a valid DLC size */
                break;
        }
    }
#endif /* FLEXCAN_IP_FEATURE_HAS_FD */

    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_GetMsgBuffRegion
 * Description   : Returns the start of a MB area, based on its index.
 *
 *END**************************************************************************/
volatile uint32 * FlexCAN_GetMsgBuffRegion(const FLEXCAN_Type * base, uint32 msgBuffIdx)
{
    uint8 arbitration_field_size = 8U;
    uint8 mb_size = 0U;
    uint32 ramBlockSize = 512U;
    uint16 ramBlockOffset = 0;
    uint8 msgBuffIdxBackup = (uint8)msgBuffIdx;
    uint8 i=0U;
    uint8 maxMbNum=0U;
    uint32 mb_index=0U;
    uint8 payload_size=0U;
    volatile uint32 * RAM = (uint32*)((Flexcan_Ip_PtrSizeType)base + (uint32)FLEXCAN_IP_FEATURE_RAM_OFFSET);
    volatile uint32 * pAddressRet = NULL_PTR;
#if (FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY == STD_ON)
    volatile uint32 * RAM_EXPANDED = (uint32*)((Flexcan_Ip_PtrSizeType)base + (uint32)FLEXCAN_IP_FEATURE_EXP_RAM_OFFSET);
#endif

    for (i=0; i< (uint8)FLEXCAN_IP_FEATURE_MBDSR_COUNT; i++)
    {
        payload_size = FlexCAN_GetPayloadSize(base, i);
        mb_size = (uint8)(payload_size + arbitration_field_size);
        maxMbNum = (uint8)(ramBlockSize / mb_size);
        if (maxMbNum > msgBuffIdxBackup)
        {
            break;
        }
        ramBlockOffset += 128U;
        msgBuffIdxBackup -= maxMbNum;
    }

#if (FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY == STD_ON)
    if (((uint8)FLEXCAN_IP_FEATURE_MBDSR_COUNT == i) && (TRUE == FlexCAN_IsExpandableMemoryAvailable(base)))
    {
        /* Multiply the MB index by the MB size (in words) */
        /* for expanded ramblock:
         * maxMbNum per one block: 7
         * mb_size per one Mb: 72
        */
        mb_index = (((uint32)msgBuffIdxBackup / 7U) * 128U) + (((uint32)msgBuffIdxBackup % 7U) * (72U >> 2U));
        pAddressRet = &(RAM_EXPANDED[mb_index]);
    }
    else
#endif
    {
        /* Multiply the MB index by the MB size (in words) */
        mb_index = (uint32)ramBlockOffset + (((uint32)msgBuffIdxBackup % (uint32)maxMbNum) * ((uint32)mb_size >> 2U));
        pAddressRet = &(RAM[mb_index]);
    }

    return pAddressRet;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_GetMaxMbNum
 * Description   : Computes the maximum RAM size occupied by MBs.
 *
 *END**************************************************************************/
uint32 FlexCAN_GetMaxMbNum(const FLEXCAN_Type * base)
{
    uint32 i, ret = 0u;
    static FLEXCAN_Type * const flexcanBase[] = IP_FLEXCAN_BASE_PTRS;
    static const uint32 maxMbNum[] = FLEXCAN_IP_FEATURE_MAX_MB_NUM_ARRAY;

    for (i = 0u; i < FLEXCAN_INSTANCE_COUNT; i++)
    {
        if (base == flexcanBase[i])
        {
            ret = maxMbNum[i];
        }
    }
    return ret;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_EnterFreezeMode
 * Description   : Enter the freeze mode.
 *
 *END**************************************************************************/
Flexcan_Ip_StatusType FlexCAN_EnterFreezeMode(FLEXCAN_Type * base)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = OsIf_MicrosToTicks(FLEXCAN_IP_TIMEOUT_DURATION, FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
    Flexcan_Ip_StatusType returnResult = FLEXCAN_STATUS_SUCCESS;

    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_02();
    base->MCR = (base->MCR & ~FLEXCAN_MCR_FRZ_MASK) | FLEXCAN_MCR_FRZ(1U);
    base->MCR = (base->MCR & ~FLEXCAN_MCR_HALT_MASK) | FLEXCAN_MCR_HALT(1U);
    if (((base->MCR & FLEXCAN_MCR_MDIS_MASK) >> FLEXCAN_MCR_MDIS_SHIFT) != 0U)
    {
        base->MCR &= ~FLEXCAN_MCR_MDIS_MASK;
    }
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_02();
    /* Wait for entering the freeze mode */
    timeStart = OsIf_GetCounter(FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
    while (0U == ((base->MCR & FLEXCAN_MCR_FRZACK_MASK) >> FLEXCAN_MCR_FRZACK_SHIFT))
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
        if (timeElapsed >= uS2Ticks)
        {
            returnResult = FLEXCAN_STATUS_TIMEOUT;
            break;
        }
    }

    return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_Enable
 * Description   : Enable the clock for FlexCAN Module.
 *
 *END**************************************************************************/
Flexcan_Ip_StatusType FlexCAN_Enable(FLEXCAN_Type * base)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = OsIf_MicrosToTicks(FLEXCAN_IP_TIMEOUT_DURATION, FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
    Flexcan_Ip_StatusType returnValue = FLEXCAN_STATUS_SUCCESS;

    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_03();

    /* Enable Module */
    base->MCR &= ~FLEXCAN_MCR_MDIS_MASK;
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_03();
    /* Wait for entering the freeze mode */
    timeStart = OsIf_GetCounter(FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
    while (0U == ((base->MCR & FLEXCAN_MCR_FRZACK_MASK) >> FLEXCAN_MCR_FRZACK_SHIFT))
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
        if (timeElapsed >= uS2Ticks)
        {
            returnValue = FLEXCAN_STATUS_TIMEOUT;
            break;
        }
    }
    return returnValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_ExitFreezeMode
 * Description   : Exit of freeze mode.
 *
 *END**************************************************************************/
Flexcan_Ip_StatusType FlexCAN_ExitFreezeMode(FLEXCAN_Type * base)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = OsIf_MicrosToTicks(FLEXCAN_IP_TIMEOUT_DURATION, FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
    Flexcan_Ip_StatusType returnValue = FLEXCAN_STATUS_SUCCESS;

    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_04();
    base->MCR = (base->MCR & ~FLEXCAN_MCR_HALT_MASK) | FLEXCAN_MCR_HALT(0U);
    base->MCR = (base->MCR & ~FLEXCAN_MCR_FRZ_MASK) | FLEXCAN_MCR_FRZ(0U);
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_04();
    /* Wait till exit freeze mode */
    timeStart = OsIf_GetCounter(FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
    while (((base->MCR & FLEXCAN_MCR_FRZACK_MASK) >> FLEXCAN_MCR_FRZACK_SHIFT) != 0U)
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
        if (timeElapsed >= uS2Ticks)
        {
            returnValue = FLEXCAN_STATUS_TIMEOUT;
            break;
        }
    }
    return returnValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_Disable
 * Description   : Disable FlexCAN module.
 * This function will disable FlexCAN module.
 *
 *END**************************************************************************/
Flexcan_Ip_StatusType FlexCAN_Disable(FLEXCAN_Type * base)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = OsIf_MicrosToTicks(FLEXCAN_IP_TIMEOUT_DURATION, FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
    Flexcan_Ip_StatusType returnResult = FLEXCAN_STATUS_SUCCESS;

    /* To access the memory mapped registers */
    /* Enter disable mode (hard reset). */
    if (0U == ((base->MCR & FLEXCAN_MCR_MDIS_MASK) >> FLEXCAN_MCR_MDIS_SHIFT))
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_05();
        /* Clock disable (module) */
        base->MCR = (base->MCR & ~FLEXCAN_MCR_MDIS_MASK) | FLEXCAN_MCR_MDIS(1U);
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_05();
        /* Wait until disable mode acknowledged */
        timeStart = OsIf_GetCounter(FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
        while (0U == ((base->MCR & FLEXCAN_MCR_LPMACK_MASK) >> FLEXCAN_MCR_LPMACK_SHIFT))
        {
            timeElapsed += OsIf_GetElapsed(&timeStart, FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                returnResult = FLEXCAN_STATUS_TIMEOUT;
                break;
            }
        }
    }
    return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_SetErrIntCmd
 * Description   : Enable the error interrupts.
 * This function will enable Error interrupt.
 *
 *END**************************************************************************/
void FlexCAN_SetErrIntCmd(FLEXCAN_Type * base, flexcan_int_type_t errType, boolean enable)
{
    uint32 temp = (uint32)errType;

    /* Start critical section: implementation depends on integrator */
    SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_06();
    if (enable)
    {
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
        if (FLEXCAN_INT_ERR_FAST == errType)
        {
            base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_ERRMSK_FAST_MASK) | FLEXCAN_CTRL2_ERRMSK_FAST(1U);
            (void)temp;
        }
        else
#endif
        {
            if ((FLEXCAN_INT_RX_WARNING == errType) || (FLEXCAN_INT_TX_WARNING == errType))
            {
                base->MCR = (base->MCR & ~FLEXCAN_MCR_WRNEN_MASK) | FLEXCAN_MCR_WRNEN(1U);
            }
            (base->CTRL1) = ((base->CTRL1) | (temp));
        }
    }
    else
    {
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
        if (FLEXCAN_INT_ERR_FAST == errType)
        {
            base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_ERRMSK_FAST_MASK) | FLEXCAN_CTRL2_ERRMSK_FAST(0U);
            (void)temp;
        }
        else
#endif
        {
            (base->CTRL1) = ((base->CTRL1) & ~(temp));
            temp = base->CTRL1;
            if ((0U == (temp & (uint32)FLEXCAN_INT_RX_WARNING)) && (0U == (temp & (uint32)FLEXCAN_INT_TX_WARNING)))
            {
                /* If WRNEN disabled then both FLEXCAN_INT_RX_WARNING and FLEXCAN_INT_TX_WARNING will be disabled */
                base->MCR = (base->MCR & ~FLEXCAN_MCR_WRNEN_MASK) | FLEXCAN_MCR_WRNEN(0U);
            }
        }
    }
    /* End critical section: implementation depends on integrator */
    SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_06();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_Init
 * Description   : Initialize FlexCAN module.
 * This function will reset FlexCAN module, set maximum number of message
 * buffers, initialize all message buffers as inactive, enable RX FIFO
 * if needed, mask all mask bits, and disable all MB interrupts.
 *
 *END**************************************************************************/
Flexcan_Ip_StatusType FlexCAN_Init(FLEXCAN_Type * base)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = OsIf_MicrosToTicks(FLEXCAN_IP_TIMEOUT_DURATION, FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
    Flexcan_Ip_StatusType returnResult = FLEXCAN_STATUS_SUCCESS;

    /* Reset the FLEXCAN */
    base->MCR = (base->MCR & ~FLEXCAN_MCR_SOFTRST_MASK) | FLEXCAN_MCR_SOFTRST(1U);
    /* Wait for reset cycle to complete */
    timeStart = OsIf_GetCounter(FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
    while (((base->MCR & FLEXCAN_MCR_SOFTRST_MASK) >> FLEXCAN_MCR_SOFTRST_SHIFT) != 0U)
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, FLEXCAN_IP_SERVICE_TIMEOUT_TYPE);
        if (timeElapsed >= uS2Ticks)
        {
            returnResult = FLEXCAN_STATUS_TIMEOUT;
            break;
        }
    }
    if (FLEXCAN_STATUS_SUCCESS == returnResult)
    {
        /* Avoid Abort Transmission, use Inactive MB */
        base->MCR = (base->MCR & ~FLEXCAN_MCR_AEN_MASK) | FLEXCAN_MCR_AEN(1U);
        /* Clear FlexCAN memory */
        FlexCAN_ClearRAM(base);
        /* Rx global mask*/
        (base->RXMGMASK) = (uint32)(FLEXCAN_RXMGMASK_MG_MASK);
        /* Rx reg 14 mask*/
        (base->RX14MASK) =  (uint32)(FLEXCAN_RX14MASK_RX14M_MASK);
        /* Rx reg 15 mask*/
        (base->RX15MASK) = (uint32)(FLEXCAN_RX15MASK_RX15M_MASK);
        /* Disable all MB interrupts */
        (base->IMASK1) = 0x0;
        /* Clear all MB interrupt flags */
        (base->IFLAG1) = FLEXCAN_IMASK1_BUF31TO0M_MASK;
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U
        if (FlexCAN_GetMaxMbNum(base) > 32U)
        {
            (base->IMASK2) = 0x0;
            (base->IFLAG2) = FLEXCAN_IMASK2_BUF63TO32M_MASK;
        }
#endif
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U
        if (FlexCAN_GetMaxMbNum(base) > 64U)
        {
            (base->IMASK3) = 0x0;
            (base->IFLAG3) = FLEXCAN_IMASK3_BUF95TO64M_MASK;
        }
#endif
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U
        if (FlexCAN_GetMaxMbNum(base) > 96U)
        {
            (base->IMASK4) = 0x0;
            (base->IFLAG4) = FLEXCAN_IMASK4_BUF127TO96M_MASK;
        }
#endif
        /* Clear all error interrupt flags */
        (base->ESR1) = FLEXCAN_IP_ALL_INT;
        /* clear registers which are not effected by soft reset */
        base->CTRL1 = FLEXCAN_IP_CTRL1_DEFAULT_VALUE_U32;
        base->CTRL2 = FLEXCAN_IP_CTRL2_DEFAULT_VALUE_U32;
        base->CBT   = FLEXCAN_IP_CBT_DEFAULT_VALUE_U32;

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCE_CBT == STD_ON)
        base->EPRS  = FLEXCAN_IP_EPRS_DEFAULT_VALUE_U32;
        base->ENCBT = FLEXCAN_IP_ENCBT_DEFAULT_VALUE_U32;
        base->EDCBT = FLEXCAN_IP_EDCBT_DEFAULT_VALUE_U32;
        base->ETDC  = FLEXCAN_IP_ETDC_DEFAULT_VALUE_U32;
#endif
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
    #if defined(CAN_FEATURE_S32K1XX)
    if (TRUE == FlexCAN_IsFDAvailable(base))
    {
    #endif /* defined(CAN_FEATURE_S32K1XX) */
        base->FDCBT = FLEXCAN_IP_FDCBT_DEFAULT_VALUE_U32;
        base->FDCTRL = FLEXCAN_IP_FDCTRL_DEFAULT_VALUE_U32;
    #if defined(CAN_FEATURE_S32K1XX)
    }
    #endif /* defined(CAN_FEATURE_S32K1XX) */
#endif /* (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON) */
    }
    return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_EnableRxFifo
 * Description   : Enable Rx FIFO feature.
 * This function will enable the Rx FIFO feature.
 *
 *END**************************************************************************/
Flexcan_Ip_StatusType FlexCAN_EnableRxFifo(FLEXCAN_Type * base,
                                         uint32 numOfFilters)
{
    uint32 i;
    uint16 noOfMbx = (uint16)FlexCAN_GetMaxMbNum(base);
    Flexcan_Ip_StatusType stat = FLEXCAN_STATUS_SUCCESS;

    /* RxFIFO cannot be enabled if FD is enabled */
    if (((base->MCR & FLEXCAN_MCR_FDEN_MASK) >> FLEXCAN_MCR_FDEN_SHIFT) != 0U)
    {
        stat = FLEXCAN_STATUS_ERROR;
    }
    if (FLEXCAN_STATUS_SUCCESS == stat)
    {
        /* Enable RX FIFO */
        base->MCR = (base->MCR & ~FLEXCAN_MCR_RFEN_MASK) | FLEXCAN_MCR_RFEN(1U);
        /* Set the number of the RX FIFO filters needed */
        base->CTRL2 = (base->CTRL2 & ~FLEXCAN_CTRL2_RFFN_MASK) | ((numOfFilters << FLEXCAN_CTRL2_RFFN_SHIFT) & FLEXCAN_CTRL2_RFFN_MASK);
        /* RX FIFO global mask, take in consideration all filter fields*/
        (base->RXFGMASK) = FLEXCAN_RXFGMASK_FGM_MASK;

        for (i = 0U; i < noOfMbx; i++)
        {
            /* RX individual mask */
            base->RXIMR[i] = (FLEXCAN_RXIMR_MI_MASK << FLEXCAN_IP_ID_EXT_SHIFT) & (FLEXCAN_IP_ID_STD_MASK | FLEXCAN_IP_ID_EXT_MASK);
        }
    }
    return stat;
}

#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
#if defined(CAN_FEATURE_S32K1XX)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_IsFDAvailable
 * Description   : Checks if FlexCAN has FD Support.
 * This function is private.
 *
 *END**************************************************************************/
boolean FlexCAN_IsFDAvailable(const FLEXCAN_Type * base)
{
    uint32 i=0U;
    static FLEXCAN_Type * const flexcanBase[] = CAN_BASE_PTRS_HAS_FD;
    boolean returnValue = FALSE;
    for (i = 0U; i < CAN_FEATURE_FD_INSTANCES; i++)
    {
        if (base == flexcanBase[i])
        {
            returnValue = TRUE;
            break;
        }
    }

    return returnValue;
}
#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_SetPayloadSize
 * Description   : Sets the payload size of the MBs.
 *
 *END**************************************************************************/
void FlexCAN_SetPayloadSize(FLEXCAN_Type * base,
                            const Flexcan_Ip_PayloadSizeType * payloadSize)
{
    uint32 tmp;
#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(FlexCAN_IsFDEnabled(base) || (FLEXCAN_PAYLOAD_SIZE_8 == payloadSize->payloadBlock0));
    #if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 1U)
    DevAssert(FlexCAN_IsFDEnabled(base) || (FLEXCAN_PAYLOAD_SIZE_8 == payloadSize->payloadBlock1));
    #endif
    #if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 2U)
    DevAssert(FlexCAN_IsFDEnabled(base) || (FLEXCAN_PAYLOAD_SIZE_8 == payloadSize->payloadBlock2));
    #endif
    #if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 3U)
    DevAssert(FlexCAN_IsFDEnabled(base) || (FLEXCAN_PAYLOAD_SIZE_8 == payloadSize->payloadBlock3));
    #endif
#endif
    /* If FD is not enabled, only 8 bytes payload is supported */
    if (FlexCAN_IsFDEnabled(base))
    {
        tmp = base->FDCTRL;
        tmp &= ~(FLEXCAN_FDCTRL_MBDSR0_MASK);
        tmp |= ((uint32)payloadSize->payloadBlock0) << FLEXCAN_FDCTRL_MBDSR0_SHIFT;
#if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 1U)
        tmp &= ~(FLEXCAN_FDCTRL_MBDSR1_MASK);
        tmp |= ((uint32)payloadSize->payloadBlock1) << FLEXCAN_FDCTRL_MBDSR1_SHIFT;
#endif
#if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 2U)
        tmp &= ~(FLEXCAN_FDCTRL_MBDSR2_MASK);
        tmp |= ((uint32)payloadSize->payloadBlock2) << FLEXCAN_FDCTRL_MBDSR2_SHIFT;
#endif
#if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 3U)
        tmp &= ~(FLEXCAN_FDCTRL_MBDSR3_MASK);
        tmp |= ((uint32)payloadSize->payloadBlock3) << FLEXCAN_FDCTRL_MBDSR3_SHIFT;
#endif
        base->FDCTRL = tmp;
    }
}

#endif /* End FLEXCAN_IP_FEATURE_HAS_FD */

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_GetPayloadSize
 * Description   : Returns the payload size of the MBs (in bytes).
 *
 *END**************************************************************************/
static uint8 FlexCAN_GetPayloadSize(const FLEXCAN_Type * base, uint8 mbdsrIdx)
{
    uint32 payloadSize = 0U;

#if defined(CAN_FEATURE_S32K1XX)
    if (TRUE == FlexCAN_IsFDAvailable(base))
    {
#endif /* defined(CAN_FEATURE_S32K1XX) */
    switch (mbdsrIdx)
    {
        case 0 : {  payloadSize = 8UL << ((base->FDCTRL & FLEXCAN_FDCTRL_MBDSR0_MASK) >> FLEXCAN_FDCTRL_MBDSR0_SHIFT); } break;
    #if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 1U)
        case 1 : {  payloadSize = 8UL << ((base->FDCTRL & FLEXCAN_FDCTRL_MBDSR1_MASK) >> FLEXCAN_FDCTRL_MBDSR1_SHIFT); } break;
    #endif
    #if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 2U)
        case 2 : {  payloadSize = 8UL << ((base->FDCTRL & FLEXCAN_FDCTRL_MBDSR2_MASK) >> FLEXCAN_FDCTRL_MBDSR2_SHIFT); } break;
    #endif
    #if (FLEXCAN_IP_FEATURE_MBDSR_COUNT > 3U)
        case 3 : {  payloadSize = 8UL << ((base->FDCTRL & FLEXCAN_FDCTRL_MBDSR3_MASK) >> FLEXCAN_FDCTRL_MBDSR3_SHIFT); } break;
    #endif
        default :{  payloadSize = 8UL << ((base->FDCTRL & FLEXCAN_FDCTRL_MBDSR0_MASK) >> FLEXCAN_FDCTRL_MBDSR0_SHIFT); } break;
    }
    #if defined(CAN_FEATURE_S32K1XX)
    }
    else
    {
        payloadSize = 8U;
    }
    #endif /* defined(CAN_FEATURE_S32K1XX) */
    return (uint8)payloadSize;
}



uint8 FlexCAN_GetMbPayloadSize(const FLEXCAN_Type * base, uint32 maxMsgBuffNum)
{
    uint8 arbitration_field_size = 8U;
    uint32 ramBlockSize = 512U;
    uint8 can_real_payload = 8U;
    uint8 maxMbBlockNum = 0U;
    uint8 i=0U;
    uint8 mb_size = 0U;

    for (i=0; i< (uint8)FLEXCAN_IP_FEATURE_MBDSR_COUNT; i++)
    {
        /* Check that the number of MBs is supported based on the payload size*/
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
        can_real_payload = FlexCAN_GetPayloadSize(base, i);
#endif /* Else can_real_payload will remain as 8 payload size */
        mb_size = (uint8)(can_real_payload + arbitration_field_size);
        maxMbBlockNum += (uint8)(ramBlockSize / mb_size);
        if (maxMbBlockNum > maxMsgBuffNum)
        {
            break;
        }
    }
#if (STD_ON == FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY)
    /* exceeded normal ram block */
    if ((uint8)FLEXCAN_IP_FEATURE_MBDSR_COUNT == i)
    {
        can_real_payload = 64U;
    }
 #endif

    return can_real_payload;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_LockRxMsgBuff
 * Description   : Lock the RX message buffer.
 * This function will lock the RX message buffer.
 *
 *END**************************************************************************/
void FlexCAN_LockRxMsgBuff(const FLEXCAN_Type * base, uint32 msgBuffIdx)
{
    volatile const uint32 * flexcan_mb = FlexCAN_GetMsgBuffRegion(base, msgBuffIdx);

    /* Lock the mailbox by reading it */
    (void)*flexcan_mb;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_SetMsgBuffIntCmd
 * Description   : Enable/Disable the corresponding Message Buffer interrupt.
 *
 *END**************************************************************************/
Flexcan_Ip_StatusType FlexCAN_SetMsgBuffIntCmd(FLEXCAN_Type * base,
                                               uint8 u8Instance,
                                               uint32 msgBuffIdx,
                                               boolean enable,
                                               boolean bIsIntActive
                                              )
{
    uint32 temp;
    Flexcan_Ip_StatusType stat = FLEXCAN_STATUS_SUCCESS;

        /* Enable the corresponding message buffer Interrupt */
        temp = 1UL << (msgBuffIdx % 32U);
        if (msgBuffIdx < 32U)
        {
            if (enable)
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
                FlexCAN_Ip_au32ImaskBuff[u8Instance][0U] = ((FlexCAN_Ip_au32ImaskBuff[u8Instance][0U]) | (temp));
                if (TRUE == bIsIntActive)
                {
                    base->IMASK1 = FlexCAN_Ip_au32ImaskBuff[u8Instance][0U];
                }
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
            }
            else
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
                FlexCAN_Ip_au32ImaskBuff[u8Instance][0U] = ((FlexCAN_Ip_au32ImaskBuff[u8Instance][0U]) & ~(temp));
                base->IMASK1 = FlexCAN_Ip_au32ImaskBuff[u8Instance][0U];
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
            }
        }
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U
        if ((msgBuffIdx >= 32U) && (msgBuffIdx < 64U))
        {
            if (enable)
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
                FlexCAN_Ip_au32ImaskBuff[u8Instance][1U] = ((FlexCAN_Ip_au32ImaskBuff[u8Instance][1U]) | (temp));
                if (TRUE == bIsIntActive)
                {
                    base->IMASK2 = FlexCAN_Ip_au32ImaskBuff[u8Instance][1U];
                }
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
            }
            else
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
                FlexCAN_Ip_au32ImaskBuff[u8Instance][1U] = ((FlexCAN_Ip_au32ImaskBuff[u8Instance][1U]) & ~(temp));
                base->IMASK2 = FlexCAN_Ip_au32ImaskBuff[u8Instance][1U];
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
            }
        }
#endif /* if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U */
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U
        if ((msgBuffIdx >= 64U) && (msgBuffIdx < 96U))
        {
            if (enable)
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
                FlexCAN_Ip_au32ImaskBuff[u8Instance][2U] = ((FlexCAN_Ip_au32ImaskBuff[u8Instance][2U]) | (temp));
                if (TRUE == bIsIntActive)
                {
                    base->IMASK3 = FlexCAN_Ip_au32ImaskBuff[u8Instance][2U];
                }
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
            }
            else
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
                FlexCAN_Ip_au32ImaskBuff[u8Instance][2U] = ((FlexCAN_Ip_au32ImaskBuff[u8Instance][2U]) & ~(temp));
                base->IMASK3 = FlexCAN_Ip_au32ImaskBuff[u8Instance][2U];
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
            }
        }
#endif /* if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U */
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U
        if (msgBuffIdx >= 96U)
        {
            if (enable)
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
                FlexCAN_Ip_au32ImaskBuff[u8Instance][3U] = ((FlexCAN_Ip_au32ImaskBuff[u8Instance][3U]) | (temp));
                if (TRUE == bIsIntActive)
                {
                    base->IMASK4 = FlexCAN_Ip_au32ImaskBuff[u8Instance][3U];
                }
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
            }
            else
            {
                /* Start critical section: implementation depends on integrator */
                SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
                FlexCAN_Ip_au32ImaskBuff[u8Instance][3U] = ((FlexCAN_Ip_au32ImaskBuff[u8Instance][3U]) & ~(temp));
                base->IMASK4 = FlexCAN_Ip_au32ImaskBuff[u8Instance][3U];
                /* End critical section: implementation depends on integrator */
                SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_18();
            }
        }
#endif /* if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U */

    return stat;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_ClearMsgBuffIntCmd
 * Description   : Disable the corresponding Message Buffer interrupt only if interrupts are active
 *
 *END**************************************************************************/
void FLEXCAN_ClearMsgBuffIntCmd(FLEXCAN_Type * pBase,
                                uint8 u8Instance,
                                uint32 mb_idx,
                                boolean bIsIntActive
                               )
{
    uint32 temp = (1UL << (mb_idx % 32U));

 /* Stop the running transfer. */
    if (mb_idx < 32U)
    {
          /* Start critical section: implementation depends on integrator */
          SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_11();
          FlexCAN_Ip_au32ImaskBuff[u8Instance][0U] = (pBase->IMASK1 & (~temp));
          if (TRUE == bIsIntActive)
          {
              pBase->IMASK1 = FlexCAN_Ip_au32ImaskBuff[u8Instance][0U];
          }
          /* End critical section: implementation depends on integrator */
          SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_11();
    }
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U
    if ((mb_idx >= 32U) && (mb_idx < 64U))
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_11();
        FlexCAN_Ip_au32ImaskBuff[u8Instance][1U] = (pBase->IMASK2 & (~temp));
        if (TRUE == bIsIntActive)
        {
            pBase->IMASK2 = FlexCAN_Ip_au32ImaskBuff[u8Instance][1U];
        }
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_11();
    }
#endif
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U
    if ((mb_idx >= 64U) && (mb_idx < 96U))
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_11();
        FlexCAN_Ip_au32ImaskBuff[u8Instance][2U] = (pBase->IMASK3 & (~temp));
        if (TRUE == bIsIntActive)
        {
            pBase->IMASK3 = FlexCAN_Ip_au32ImaskBuff[u8Instance][2U];
        }
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_11();
    }
#endif /* FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U */
#if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U
    if (mb_idx >= 96U)
    {
        /* Start critical section: implementation depends on integrator */
        SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_11();
        FlexCAN_Ip_au32ImaskBuff[u8Instance][3U] = (pBase->IMASK4 & (~temp));
        if (TRUE == bIsIntActive)
        {
            pBase->IMASK4 = FlexCAN_Ip_au32ImaskBuff[u8Instance][3U];
        }
        /* End critical section: implementation depends on integrator */
        SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_11();
    }
#endif /* #if FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U */
}


void FlexCAN_DisableInterrupts(FLEXCAN_Type * pBase)
{
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U)
    uint32 u32MaxMbCrtlNum = FlexCAN_GetMaxMbNum(pBase);
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U) */

    pBase->IMASK1 = 0U;
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U)
    if (u32MaxMbCrtlNum > 32U)
    {
        pBase->IMASK2 = 0U;
    }
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U) */
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U)
    if (u32MaxMbCrtlNum > 64U)
    {
        pBase->IMASK3 = 0U;
    }
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U) */
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U)
    if (u32MaxMbCrtlNum > 96U)
    {
        pBase->IMASK4 = 0U;
    }
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U) */
}

void FlexCAN_EnableInterrupts(FLEXCAN_Type * pBase, uint8 u8Instance)
{
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U)
    uint32 u32MaxMbCrtlNum = FlexCAN_GetMaxMbNum(pBase);
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U) */

    pBase->IMASK1 = FlexCAN_Ip_au32ImaskBuff[u8Instance][0U];
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U)
    if (u32MaxMbCrtlNum > 32U)
    {
        pBase->IMASK2 = FlexCAN_Ip_au32ImaskBuff[u8Instance][1U];
    }
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 32U) */
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U)
    if (u32MaxMbCrtlNum > 64U)
    {
        pBase->IMASK3 = FlexCAN_Ip_au32ImaskBuff[u8Instance][2U];
    }
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 64U) */
#if (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U)
    if (u32MaxMbCrtlNum > 96U)
    {
        pBase->IMASK4 = FlexCAN_Ip_au32ImaskBuff[u8Instance][3U];
    }
#endif /* (FLEXCAN_IP_FEATURE_MAX_MB_NUM > 96U) */
}
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_SetRxMsgBuff
 * Description   : Configure a message buffer for receiving.
 * This function will first check if RX FIFO is enabled. If RX FIFO is enabled,
 * the function will make sure if the MB requested is not occupied by RX FIFO
 * and ID filter table. Then this function will configure the message buffer as
 * required for receiving.
 *
 *END**************************************************************************/
void FlexCAN_SetRxMsgBuff(const FLEXCAN_Type * base,
                          uint32 msgBuffIdx,
                          const Flexcan_Ip_MsbuffCodeStatusType * cs,
                          uint32 msgId
                         )
{
    volatile uint32 * flexcan_mb = FlexCAN_GetMsgBuffRegion(base, msgBuffIdx);
    volatile uint32 * flexcan_mb_id = &flexcan_mb[1];

#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(cs != NULL_PTR);
#endif


    /* Clean up the arbitration field area */
    *flexcan_mb = 0;
    *flexcan_mb_id = 0;

    /* Set the ID according the format structure */
    if (FLEXCAN_MSG_ID_EXT == cs->msgIdType)
    {
        /* Set IDE */
        *flexcan_mb |= FLEXCAN_IP_CS_IDE_MASK;

        /* Clear SRR bit */
        *flexcan_mb &= ~FLEXCAN_IP_CS_SRR_MASK;

        /* ID [28-0] */
        *flexcan_mb_id &= ~(FLEXCAN_IP_ID_STD_MASK | FLEXCAN_IP_ID_EXT_MASK);
        *flexcan_mb_id |= (msgId & (FLEXCAN_IP_ID_STD_MASK | FLEXCAN_IP_ID_EXT_MASK));
    }

    if (FLEXCAN_MSG_ID_STD == cs->msgIdType)
    {
        /* Make sure IDE and SRR are not set */
        *flexcan_mb &= ~(FLEXCAN_IP_CS_IDE_MASK | FLEXCAN_IP_CS_SRR_MASK);

        /* ID[28-18] */
        *flexcan_mb_id &= ~FLEXCAN_IP_ID_STD_MASK;
        *flexcan_mb_id |= (msgId << FLEXCAN_IP_ID_STD_SHIFT) & FLEXCAN_IP_ID_STD_MASK;
    }

    /* Set MB CODE */
    if ((uint32)FLEXCAN_RX_NOT_USED != cs->code)
    {
        *flexcan_mb &= ~FLEXCAN_IP_CS_CODE_MASK;
        *flexcan_mb |= (cs->code << FLEXCAN_IP_CS_CODE_SHIFT) & FLEXCAN_IP_CS_CODE_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_GetMsgBuffTimestamp
 * Description   : Get a message buffer timestamp value.
 *
 *END**************************************************************************/
uint32 FlexCAN_GetMsgBuffTimestamp(const FLEXCAN_Type * base, uint32 msgBuffIdx)
{
    uint32 TimeStamp = 0U;
    volatile const uint32 * Flexcan_Mb = FlexCAN_GetMsgBuffRegion(base, msgBuffIdx);

#if (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON)
    if (FLEXCAN_IsHRTimeStampEnabled(base))
    {
        /* Extract the Time Stamp */
        TimeStamp = (uint32)base->HR_TIME_STAMP[msgBuffIdx];
    }
    else
#endif /* EATURE_CAN_HAS_HR_TIMER */
    {
        TimeStamp = (uint32)((*Flexcan_Mb & FLEXCAN_IP_CS_TIME_STAMP_MASK) >> FLEXCAN_IP_CS_TIME_STAMP_SHIFT);
    }
    return TimeStamp;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_GetMsgBuff
 * Description   : Get a message buffer field values.
 * This function will first check if RX FIFO is enabled. If RX FIFO is enabled,
 * the function will make sure if the MB requested is not occupied by RX FIFO
 * and ID filter table. Then this function will get the message buffer field
 * values and copy the MB data field into user's buffer.
 *
 *END**************************************************************************/
void FlexCAN_GetMsgBuff(const FLEXCAN_Type * base,
                        uint32 msgBuffIdx,
                        Flexcan_Ip_MsgBuffType * msgBuff
                       )
{

    uint8 i;
    volatile const uint32 * Flexcan_Mb = FlexCAN_GetMsgBuffRegion(base, msgBuffIdx);
    volatile const uint32 * Flexcan_Mb_Id   = &Flexcan_Mb[1];
    volatile const uint8 * Flexcan_Mb_Data = (volatile const uint8 *)(&Flexcan_Mb[2]);
    volatile const uint32 * Flexcan_Mb_Data_32 = &Flexcan_Mb[2];
    uint32 * MsgBuff_Data_32 = NULL_PTR;
    uint32 MbWord;

    uint8 Flexcan_Mb_Dlc_Value = (uint8)(((*Flexcan_Mb) & FLEXCAN_IP_CS_DLC_MASK) >> 16);
    uint8 Payload_Size = FlexCAN_ComputePayloadSize(Flexcan_Mb_Dlc_Value);

#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(msgBuff != NULL_PTR);
#endif
    /* Asign after NULL Check */
    MsgBuff_Data_32 = (uint32 *)(msgBuff->data);
#if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
    /* Payload Size is based on MBDSR for 1 MBDSR corresponds 32 * 8Bytes MBs  */
    if (Payload_Size > FlexCAN_GetMbPayloadSize(base, msgBuffIdx))
    {
        Payload_Size = FlexCAN_GetMbPayloadSize(base, msgBuffIdx);
    }
#endif /* FLEXCAN_IP_FEATURE_HAS_FD */

    msgBuff->dataLen = Payload_Size;
    /* Get a MB field values */
    msgBuff->cs = *Flexcan_Mb;
    if ((msgBuff->cs & FLEXCAN_IP_CS_IDE_MASK) != 0U)
    {
        msgBuff->msgId = (*Flexcan_Mb_Id);
    }
    else
    {
        msgBuff->msgId = (*Flexcan_Mb_Id) >> FLEXCAN_IP_ID_STD_SHIFT;
    }


#if (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON)
    if (FLEXCAN_IsHRTimeStampEnabled(base))
    {
        /* Extract the Time Stamp */
        msgBuff->time_stamp = (uint32)base->HR_TIME_STAMP[msgBuffIdx];
    }
    else
#endif /* EATURE_CAN_HAS_HR_TIMER */
    {
        msgBuff->time_stamp = (uint32)((msgBuff->cs & FLEXCAN_IP_CS_TIME_STAMP_MASK) >> FLEXCAN_IP_CS_TIME_STAMP_SHIFT);
    }

#if (defined (CPU_S32K116) || defined (CPU_S32K118))
    /* Check if the buffer address is aligned */
    if (((uint32)MsgBuff_Data_32 & 0x3U) != 0U)
    {
        /* Copy MB data field into user's buffer */
        for (i = 0U; i < (Payload_Size & ~3U); i += 4U)
        {
            MbWord = Flexcan_Mb_Data_32[i >> 2U];
            uint8 index;
            uint32 x;
            const uint8 * p;
            FLEXCAN_IP_SWAP_BYTES_IN_WORD(MbWord, x);
            p = (uint8 *)&x;
            for (index = 0; index < 4U; index++)
            {
                msgBuff->data[i + index] = p[index];
            }
        }
    }
    else
    {
        for (i = 0U; i < (Payload_Size & ~3U); i += 4U)
        {
            MbWord = Flexcan_Mb_Data_32[i >> 2U];
            FLEXCAN_IP_SWAP_BYTES_IN_WORD(MbWord, MsgBuff_Data_32[i >> 2U]);
        }
    }

#else  /* if (defined (CPU_S32K116) || defined (CPU_S32K118)) */
    for (i = 0U; i < (Payload_Size & ~3U); i += 4U)
    {
        MbWord = Flexcan_Mb_Data_32[i >> 2U];
        FLEXCAN_IP_SWAP_BYTES_IN_WORD((MbWord), (MsgBuff_Data_32[i >> 2U]));
    }

#endif /* if (defined (CPU_S32K116) || defined (CPU_S32K118)) */
    for (; i < Payload_Size; i++)
    {   /* Max allowed value for index is 63 */
        msgBuff->data[i] = Flexcan_Mb_Data[FLEXCAN_IP_SWAP_BYTES_IN_WORD_INDEX(i)];
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_SetTxMsgBuff
 * Description   : Configure a message buffer for transmission.
 * This function will first check if RX FIFO is enabled. If RX FIFO is enabled,
 * the function will make sure if the MB requested is not occupied by RX FIFO
 * and ID filter table. Then this function will copy user's buffer into the
 * message buffer data area and configure the message buffer as required for
 * transmission.
 *
 *END**************************************************************************/
void FlexCAN_SetTxMsgBuff(volatile uint32 * const pMbAddr,
                          const Flexcan_Ip_MsbuffCodeStatusType * cs,
                          uint32 msgId,
                          const uint8 * msgData,
                          const boolean isRemote
                         )
{
    uint32 Flexcan_Mb_Config = 0;
    uint32 DataByte;
    uint8 Dlc_Value;
    uint8 Payload_Size;
    volatile uint32 * Flexcan_Mb = pMbAddr;
    volatile uint32 * Flexcan_Mb_Id   = &Flexcan_Mb[1];
    volatile uint8 * Flexcan_Mb_Data = (volatile uint8*)(&Flexcan_Mb[2]);
    volatile uint32 * Flexcan_Mb_Data_32 = &Flexcan_Mb[2];
    const uint32 * MsgData_32 = (const uint32*)msgData;

    #if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(cs != NULL_PTR);
    #endif

        /* Clean up the arbitration field area and set TxMB Inactive */
        *Flexcan_Mb = (uint32)((((uint32)FLEXCAN_TX_INACTIVE & (uint32)0x1F) << (uint8)FLEXCAN_IP_CS_CODE_SHIFT) & (uint32)FLEXCAN_IP_CS_CODE_MASK);
        *Flexcan_Mb_Id = 0;

        /* Compute the value of the DLC field */
        Dlc_Value = FlexCAN_ComputeDLCValue((uint8)cs->dataLen);
        /* Copy user's buffer into the message buffer data area */
        if (msgData != NULL_PTR)
        {
#if (defined(S32K116) || defined (S32K118))
            (void)MsgData_32;
            DataByte = FlexCAN_DataTransferTxMsgBuff(Flexcan_Mb_Data_32, cs, msgData);
#else
            for (DataByte = 0; DataByte < (cs->dataLen & ~3U); DataByte += 4U)
            {
                FLEXCAN_IP_SWAP_BYTES_IN_WORD((MsgData_32[DataByte >> 2U]), (Flexcan_Mb_Data_32[DataByte >> 2U]));
            }
#endif /* (defined(S32K116) || defined (S32K118)) */
            for ( ; DataByte < cs->dataLen; DataByte++)
            {
                Flexcan_Mb_Data[FLEXCAN_IP_SWAP_BYTES_IN_WORD_INDEX(DataByte)] =  msgData[DataByte];
            }
        #if (FLEXCAN_IP_FEATURE_HAS_FD == STD_ON)
            Payload_Size = FlexCAN_ComputePayloadSize(Dlc_Value);
            /* Add padding, if needed */
            for (DataByte = cs->dataLen; DataByte < Payload_Size; DataByte++)
            {
                Flexcan_Mb_Data[FLEXCAN_IP_SWAP_BYTES_IN_WORD_INDEX(DataByte)] = cs->fd_padding;
            }
        #endif /* FLEXCAN_IP_FEATURE_HAS_FD */
        }
        /* Set the ID according the format structure */
        if (FLEXCAN_MSG_ID_EXT == cs->msgIdType)
        {
            /* ID [28-0] */
            *Flexcan_Mb_Id &= ~(FLEXCAN_IP_ID_STD_MASK | FLEXCAN_IP_ID_EXT_MASK);
            *Flexcan_Mb_Id |= (msgId & (FLEXCAN_IP_ID_STD_MASK | FLEXCAN_IP_ID_EXT_MASK));
            /* Set IDE and SRR bit*/
            Flexcan_Mb_Config |= (FLEXCAN_IP_CS_IDE_MASK | FLEXCAN_IP_CS_SRR_MASK);
        }
        if (FLEXCAN_MSG_ID_STD == cs->msgIdType)
        {
            /* ID[28-18] */
            *Flexcan_Mb_Id &= ~FLEXCAN_IP_ID_STD_MASK;
            *Flexcan_Mb_Id |= (msgId << FLEXCAN_IP_ID_STD_SHIFT) & FLEXCAN_IP_ID_STD_MASK;
            /* make sure IDE and SRR are not set */
            Flexcan_Mb_Config &= ~(FLEXCAN_IP_CS_IDE_MASK | FLEXCAN_IP_CS_SRR_MASK);
        }
        /* Set the length of data in bytes */
        Flexcan_Mb_Config &= ~FLEXCAN_IP_CS_DLC_MASK;
        Flexcan_Mb_Config |= ((uint32)Dlc_Value << FLEXCAN_IP_CS_DLC_SHIFT) & FLEXCAN_IP_CS_DLC_MASK;
        /* Set MB CODE */
        if (cs->code != (uint32)FLEXCAN_TX_NOT_USED)
        {
            if ((uint32)FLEXCAN_TX_REMOTE == cs->code)
            {
                /* Set RTR bit */
                Flexcan_Mb_Config |= FLEXCAN_IP_CS_RTR_MASK;
            }
            else
            {
                if (TRUE == isRemote)
                {
                    /* Set RTR bit */
                    Flexcan_Mb_Config |= FLEXCAN_IP_CS_RTR_MASK;
                }
            }
            /* Reset the code */
            Flexcan_Mb_Config &= ~FLEXCAN_IP_CS_CODE_MASK;
            /* Set the code */
            if (cs->fd_enable)
            {
                Flexcan_Mb_Config |= ((cs->code << FLEXCAN_IP_CS_CODE_SHIFT) & FLEXCAN_IP_CS_CODE_MASK) | FLEXCAN_IP_MB_EDL_MASK;
                /* In case of FD frame not supported RTR */
                Flexcan_Mb_Config &= ~FLEXCAN_IP_CS_RTR_MASK;
            }
            else
            {
                Flexcan_Mb_Config |= (cs->code << FLEXCAN_IP_CS_CODE_SHIFT) & FLEXCAN_IP_CS_CODE_MASK;
            }

            if (cs->enable_brs)
            {
                Flexcan_Mb_Config |= FLEXCAN_IP_MB_BRS_MASK;
            }
            *Flexcan_Mb = Flexcan_Mb_Config;
        }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_SetMaxMsgBuffNum
 * Description   : Set the number of the last Message Buffers.
 * This function will define the number of the last Message Buffers
 *
 *END***************************************************************************/
Flexcan_Ip_StatusType FlexCAN_SetMaxMsgBuffNum(FLEXCAN_Type * base, uint32 maxMsgBuffNum)
{
    uint32 MsgBuffIdx;
    uint32 DataByte;
    const volatile uint32 * RAM = (uint32*)((Flexcan_Ip_PtrSizeType)base + (uint32)FLEXCAN_IP_FEATURE_RAM_OFFSET);
#if (STD_ON == FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY)
    const volatile uint32 * RAM_EXPANDED = (uint32*)((Flexcan_Ip_PtrSizeType)base + (uint32)FLEXCAN_IP_FEATURE_EXP_RAM_OFFSET);
#endif /* FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY */
    const volatile uint32 * ValEndMbPointer = NULL_PTR;
    volatile uint32 *Flexcan_Mb = NULL_PTR;
    volatile uint32 *Flexcan_Mb_Id   = NULL_PTR ;
    volatile uint8  *Flexcan_Mb_Data = NULL_PTR;
    uint8 Arbitration_Field_Size = 8U;
    uint8 Can_Real_Payload = FlexCAN_GetMbPayloadSize(base, maxMsgBuffNum - (uint32)1U);
    Flexcan_Ip_PtrSizeType ValEndMb = 0U;
    Flexcan_Ip_PtrSizeType ValEndRam = 0U;
    Flexcan_Ip_StatusType Status = FLEXCAN_STATUS_SUCCESS;

    #if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(maxMsgBuffNum>0U);
    #endif

    ValEndMbPointer = FlexCAN_GetMsgBuffRegion(base, (maxMsgBuffNum - (uint32)1U));

    ValEndMb = (Flexcan_Ip_PtrSizeType)ValEndMbPointer + Can_Real_Payload + Arbitration_Field_Size;

#if (STD_ON == FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY)
    if (FlexCAN_IsExpandableMemoryAvailable(base))
    {
        ValEndRam = (Flexcan_Ip_PtrSizeType)&RAM_EXPANDED[FLEXCAN_IP_RAM1n_COUNT];
    }
    else
    {
        ValEndRam = (Flexcan_Ip_PtrSizeType)&RAM[(FlexCAN_GetMaxMbNum(base) * 4U)];
    }
#else
    ValEndRam = (Flexcan_Ip_PtrSizeType)&RAM[(FlexCAN_GetMaxMbNum(base) * 4U)];
#endif /* FLEXCAN_IP_FEATURE_HAS_EXPANDABLE_MEMORY */

    if ((ValEndMb > ValEndRam) || (maxMsgBuffNum > FlexCAN_GetMaxMbNum(base)))
    {
        Status = FLEXCAN_STATUS_BUFF_OUT_OF_RANGE;
    }

    if (FLEXCAN_STATUS_SUCCESS == Status)
    {
        /* Set the maximum number of MBs*/
        base->MCR = (base->MCR & ~FLEXCAN_MCR_MAXMB_MASK) | (((maxMsgBuffNum-1U) << FLEXCAN_MCR_MAXMB_SHIFT) & FLEXCAN_MCR_MAXMB_MASK);
        if (!(((base->MCR & FLEXCAN_MCR_RFEN_MASK) >> FLEXCAN_MCR_RFEN_SHIFT) != 0U))
        {
            /* Initialize all message buffers as inactive */
            for (MsgBuffIdx = 0; MsgBuffIdx < maxMsgBuffNum; MsgBuffIdx++)
            {
                Flexcan_Mb = FlexCAN_GetMsgBuffRegion(base, MsgBuffIdx);
                Flexcan_Mb_Id   = &Flexcan_Mb[1];
                Flexcan_Mb_Data = (volatile uint8*)(&Flexcan_Mb[2]);
                *Flexcan_Mb = 0x0U;
                *Flexcan_Mb_Id = 0x0U;
                Can_Real_Payload = FlexCAN_GetMbPayloadSize(base, MsgBuffIdx);
                for (DataByte = 0; DataByte < Can_Real_Payload; DataByte++)
                {
                   Flexcan_Mb_Data[DataByte] = 0x0U;
                }
            }
        }
    }
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_SetOperationMode
 * Description   : Enable a FlexCAN operation mode.
 * This function will enable one of the modes listed in flexcan_operation_modes_t.
 *
 *END**************************************************************************/
void FlexCAN_SetOperationMode(FLEXCAN_Type * base, Flexcan_Ip_ModesType mode)
{
    switch (mode)
    {
        case FLEXCAN_NORMAL_MODE:
            base->CTRL1 = (base->CTRL1 & ~FLEXCAN_CTRL1_LOM_MASK) | FLEXCAN_CTRL1_LOM(0U);
            base->CTRL1 = (base->CTRL1 & ~FLEXCAN_CTRL1_LPB_MASK) | FLEXCAN_CTRL1_LPB(0U);
            break;
        case FLEXCAN_LISTEN_ONLY_MODE:
            base->CTRL1 = (base->CTRL1 & ~FLEXCAN_CTRL1_LOM_MASK) | FLEXCAN_CTRL1_LOM(1U);
            break;
        case FLEXCAN_LOOPBACK_MODE:
            base->CTRL1 = (base->CTRL1 & ~FLEXCAN_CTRL1_LPB_MASK) | FLEXCAN_CTRL1_LPB(1U);
            base->CTRL1 = (base->CTRL1 & ~FLEXCAN_CTRL1_LOM_MASK) | FLEXCAN_CTRL1_LOM(0U);
            /* Enable Self Reception */
            FlexCAN_SetSelfReception(base, TRUE);
            break;
        default:
            /* Should not get here */
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_SetRxFifoFilter
 * Description   : Configure RX FIFO ID filter table elements.
 *
 *END**************************************************************************/
void FlexCAN_SetRxFifoFilter(FLEXCAN_Type * base,
                             Flexcan_Ip_RxFifoIdElementFormatType idFormat,
                             const Flexcan_Ip_IdTableType * idFilterTable
                            )
{

    /* Set RX FIFO ID filter table elements*/
    uint32 i, j, NumOfFilters;
    uint32 Val1 = 0UL, Val2 = 0UL, Val = 0UL;
    volatile uint32 * FilterTable = (uint32 *)((Flexcan_Ip_PtrSizeType)base + (uint32)FLEXCAN_IP_RX_FIFO_FILTER_TABLE_OFFSET);


    #if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert((idFilterTable != NULL_PTR) || (FLEXCAN_RX_FIFO_ID_FORMAT_D == idFormat));
    #endif

    NumOfFilters = (((base->CTRL2) & FLEXCAN_CTRL2_RFFN_MASK) >> FLEXCAN_CTRL2_RFFN_SHIFT);
    switch (idFormat)
    {
        case (FLEXCAN_RX_FIFO_ID_FORMAT_A):
            /* Start critical section: implementation depends on integrator */
            SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_13();
            /* One full ID (standard and extended) per ID Filter Table element.*/
            (base->MCR) =
                (((base->MCR) & ~(FLEXCAN_MCR_IDAM_MASK)) |
                 ((((uint32)(((uint32)(FLEXCAN_RX_FIFO_ID_FORMAT_A)) << FLEXCAN_MCR_IDAM_SHIFT)) & FLEXCAN_MCR_IDAM_MASK)));
            /* End critical section: implementation depends on integrator */
            SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_13();
            for (i = 0U; i < FLEXCAN_IP_RXFIFO_FILTER_ELEM_NUM(NumOfFilters); i++)
            {
                Val = 0UL;

                if (idFilterTable[i].isRemoteFrame)
                {
                    Val = FLEXCAN_IP_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATAB_RTR_SHIFT;
                }

                if (idFilterTable[i].isExtendedFrame)
                {
                    Val |= FLEXCAN_IP_RX_FIFO_ACCEPT_EXT_FRAME << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATAB_IDE_SHIFT;
                    FilterTable[i] = Val + ((idFilterTable[i].id << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATA_EXT_SHIFT) &
                                             FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATA_EXT_MASK
                                           );
                }
                else
                {
                    FilterTable[i] = Val + ((idFilterTable[i].id << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATA_STD_SHIFT) &
                                             FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATA_STD_MASK
                                           );
                }
            }
            break;
        case (FLEXCAN_RX_FIFO_ID_FORMAT_B):
            /* Two full standard IDs or two partial 14-bit (standard and extended) IDs*/
            /* per ID Filter Table element.*/
            /* Start critical section: implementation depends on integrator */
            SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_13();
            (base->MCR) =
                (((base->MCR) & ~(FLEXCAN_MCR_IDAM_MASK)) | ((((uint32)(((uint32)(FLEXCAN_RX_FIFO_ID_FORMAT_B)) << FLEXCAN_MCR_IDAM_SHIFT)) & FLEXCAN_MCR_IDAM_MASK)));
            /* End critical section: implementation depends on integrator */
            SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_13();
            j = 0U;
            for (i = 0U; i < FLEXCAN_IP_RXFIFO_FILTER_ELEM_NUM(NumOfFilters); i++)
            {
                Val1 = 0U;
                Val2 = 0U;

                if (idFilterTable[j].isRemoteFrame)
                {
                    Val1 = FLEXCAN_IP_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATAB_RTR_SHIFT;
                }

                if (idFilterTable[j + 1U].isRemoteFrame)
                {
                    Val2 = FLEXCAN_IP_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_RTR_SHIFT;
                }

                if (idFilterTable[j].isExtendedFrame)
                {
                    Val1 |= FLEXCAN_IP_RX_FIFO_ACCEPT_EXT_FRAME << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATAB_IDE_SHIFT;

                    FilterTable[i] = Val1 + (((idFilterTable[j].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK) >>
                                               FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT
                                             ) << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_EXT_SHIFT1
                                            );
                }
                else
                {
                    FilterTable[i] = Val1 + ((idFilterTable[j].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_STD_MASK) <<
                                              FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_STD_SHIFT1
                                            );
                }

                if (idFilterTable[j + 1U].isExtendedFrame)
                {
                    Val2 |= FLEXCAN_IP_RX_FIFO_ACCEPT_EXT_FRAME << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_IDE_SHIFT;

                    FilterTable[i] |= Val2 + (((idFilterTable[j + 1U].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_EXT_MASK) >>
                                                FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT
                                              ) << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_EXT_SHIFT2
                                             );
                }
                else
                {
                    FilterTable[i] |= Val2 + ((idFilterTable[j + 1U].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_STD_MASK) <<
                                               FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATB_STD_SHIFT2
                                             );
                }

                j = j + 2U;
            }
            break;
        case (FLEXCAN_RX_FIFO_ID_FORMAT_C):
            /* Four partial 8-bit Standard IDs per ID Filter Table element.*/
            /* Start critical section: implementation depends on integrator */
            SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_13();
            (base->MCR) =
                (((base->MCR) & ~(FLEXCAN_MCR_IDAM_MASK)) |
                 ((((uint32)(((uint32)(FLEXCAN_RX_FIFO_ID_FORMAT_C)) << FLEXCAN_MCR_IDAM_SHIFT)) & FLEXCAN_MCR_IDAM_MASK))
                );
            /* End critical section: implementation depends on integrator */
            SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_13();
            j = 0U;
            for (i = 0U; i < FLEXCAN_IP_RXFIFO_FILTER_ELEM_NUM(NumOfFilters); i++)
            {
                if (idFilterTable[j].isExtendedFrame)
                {
                    FilterTable[i] = Val1 + (((idFilterTable[j].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>
                                                FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT
                                             ) << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT1
                                            );
                }
                else
                {
                    FilterTable[i] = Val1 + (((idFilterTable[j].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>
                                                FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT
                                             ) << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT1
                                            );
                }

                if (idFilterTable[j + 1U].isExtendedFrame)
                {
                    FilterTable[i] |= Val1 + (((idFilterTable[j + 1U].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>
                                                FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT
                                              ) << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT2
                                             );
                }
                else
                {
                    FilterTable[i] |= Val1 + (((idFilterTable[j + 1U].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>
                                                FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT
                                              ) << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT2
                                             );
                }

                if (idFilterTable[j + 2U].isExtendedFrame)
                {
                    FilterTable[i] |= Val1 + (((idFilterTable[j + 2U].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>
                                                FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT
                                              ) << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT3
                                             );
                }
                else
                {
                    FilterTable[i] |= Val1 + (((idFilterTable[j + 2U].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>
                                                FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT
                                              ) << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT3
                                             );
                }

                if (idFilterTable[j + 3U].isExtendedFrame)
                {
                    FilterTable[i] |= Val1 + (((idFilterTable[j + 3U].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_EXT_MASK) >>
                                                FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_EXT_CMP_SHIFT
                                              ) << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT4
                                             );
                }
                else
                {
                    FilterTable[i] |= Val1 +
                                      (((idFilterTable[j + 3U].id & FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_STD_MASK) >>
                                        FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_STD_CMP_SHIFT
                                       ) << FLEXCAN_IP_RX_FIFO_ID_FILTER_FORMATC_SHIFT4
                                      );
                }

                j = j + 4U;
            }
            break;
        case (FLEXCAN_RX_FIFO_ID_FORMAT_D):
            /* All frames rejected.*/
            /* Start critical section: implementation depends on integrator */
            SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_13();
            (base->MCR) =
                (((base->MCR) & ~(FLEXCAN_MCR_IDAM_MASK)) |
                 ((((uint32)(((uint32)(FLEXCAN_RX_FIFO_ID_FORMAT_D)) << FLEXCAN_MCR_IDAM_SHIFT)) & FLEXCAN_MCR_IDAM_MASK))
                );
            /* End critical section: implementation depends on integrator */
            SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_13();
            break;
        default:
            /* Should not get here */
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_ReadRxFifo
 * Description   : Read Rx FIFO data.
 * This function will copy MB[0] data field into user's buffer.
 *
 *END**************************************************************************/
void FlexCAN_ReadRxFifo(const FLEXCAN_Type * base, Flexcan_Ip_MsgBuffType * rxFifo)
{

    uint32 DataByte;
    uint32 MbWord;
    #if (defined (CPU_S32K116) || defined (CPU_S32K118))
    uint32 x;
    uint8 Index;
    const uint8 * p;
    #endif

    volatile const uint32 * flexcan_mb = (uint32 *)((Flexcan_Ip_PtrSizeType)base + (uint32)FLEXCAN_IP_FEATURE_RAM_OFFSET);
    volatile const uint32 * flexcan_mb_id = &flexcan_mb[1];
    volatile const uint32 * flexcan_mb_data_32 = &flexcan_mb[2];
    uint32 * msgData_32 = NULL_PTR;
    uint8 flexcan_mb_dlc_value = (uint8)(((*flexcan_mb) & FLEXCAN_IP_CS_DLC_MASK) >> 16);
    uint8 can_real_payload = FlexCAN_ComputePayloadSize(flexcan_mb_dlc_value);

    #if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(rxFifo != NULL_PTR);
    #endif
    msgData_32 = (uint32 *)(rxFifo->data);
    /*
       Check if the length of received data packet bigger than the maximum length accepted,
       then processing flow shall continue with the maximum length defined by configuration.
       Legacy FIFO just support in normal mode.
    */
    /* no need to check if FD enabled or not because this function just is invoked when legacy fifo enabled only ! */
    if (can_real_payload > 8U)
    {
        can_real_payload = 8U;
    }

    rxFifo->dataLen = can_real_payload;
    rxFifo->cs = *flexcan_mb;
    if ((rxFifo->cs & FLEXCAN_IP_CS_IDE_MASK) != 0U)
    {
        rxFifo->msgId = *flexcan_mb_id;
    }
    else
    {
        rxFifo->msgId = (*flexcan_mb_id) >> FLEXCAN_IP_ID_STD_SHIFT;
    }
    /* Extract the IDHIT */
    rxFifo->id_hit = (uint8)base->RXFIR;
    /* Extract the Time Stamp */
    rxFifo->time_stamp = (uint32)((rxFifo->cs & FLEXCAN_IP_CS_TIME_STAMP_MASK) >> FLEXCAN_IP_CS_TIME_STAMP_SHIFT);
#if (defined (CPU_S32K116) || defined (CPU_S32K118))
    /* Check if the buffer address is aligned */
    if (((uint32)msgData_32 & 0x3U) != 0U)
    {
        /* Copy MB[0] data field into user's buffer */
        for (DataByte = 0U; DataByte < can_real_payload; DataByte += 4U)
        {

            MbWord = flexcan_mb_data_32[DataByte >> 2U];

            FLEXCAN_IP_SWAP_BYTES_IN_WORD(MbWord, x);
            p = (uint8 *)&x;
            for (Index = 0U; Index < 4U; Index++)
            {
                rxFifo->data[DataByte + Index] = p[Index];
            }
        }
    }
    else
    {
        /* Copy MB[0] data field into user's buffer */
        for (DataByte = 0U; DataByte < can_real_payload; DataByte += 4U)
        {
            MbWord = flexcan_mb_data_32[DataByte >> 2U];
            FLEXCAN_IP_SWAP_BYTES_IN_WORD(MbWord, msgData_32[DataByte >> 2U]);
        }
    }
#else  /* if (defined (CPU_S32K116) || defined (CPU_S32K118)) */
      /* Copy MB[0] data field into user's buffer */
    for (DataByte = 0U; DataByte < can_real_payload; DataByte += 4U)
    {
        MbWord = flexcan_mb_data_32[DataByte >> 2U];
        FLEXCAN_IP_SWAP_BYTES_IN_WORD((MbWord), (msgData_32[DataByte >> 2U]));
    }
#endif /* if (defined (CPU_S32K116) || defined (CPU_S32K118)) */
}
#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_ReadEnhancedRxFifo
 * Description   : Read Enhanced Rx FIFO data.
 * This function will copy Enhanced Rx FIFO data output into user's buffer.
 *
 *END**************************************************************************/
void FlexCAN_ReadEnhancedRxFifo(const uint8 u8Instance, Flexcan_Ip_MsgBuffType * rxFifo)
{
    uint32 DataByte;
    uint32 MbWord;
    uint8 Idhit_Offset;
    static FLEXCAN_Type * const FlexcanBase[] = FLEXCAN_IP_BASE_PTRS_HAS_ENHANCED_RX_FIFO;
    FLEXCAN_Type * base = FlexcanBase[u8Instance];
    volatile const uint32 * Flexcan_Mb = (uint32 *)((Flexcan_Ip_PtrSizeType)base + (uint32)FLEXCAN_IP_FEATURE_ENHANCED_FIFO_RAM_OFFSET);
    volatile const uint32 * Flexcan_Mb_Id = &Flexcan_Mb[1];
    volatile const uint32 * Flexcan_Mb_Data_32 = &Flexcan_Mb[2];
    uint32 * MsgData_32 = NULL_PTR;
    uint8 idHitaux = 0U;
    uint8 filterElement = 0U;

    /* Check if the buffer address is aligned */

    /* Compute payload size */
    uint8 flexcan_mb_dlc_value = (uint8)(((*Flexcan_Mb) & FLEXCAN_IP_CS_DLC_MASK) >> FLEXCAN_IP_CS_DLC_SHIFT);
    uint8 can_real_payload = FlexCAN_ComputePayloadSize(flexcan_mb_dlc_value);

#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(rxFifo != NULL_PTR);
#endif

    MsgData_32 = (uint32 *)(rxFifo->data);
    rxFifo->dataLen = can_real_payload;
    rxFifo->cs = *Flexcan_Mb;

    if ((rxFifo->cs & FLEXCAN_IP_CS_IDE_MASK) != 0U)
    {
        rxFifo->msgId = *Flexcan_Mb_Id;
    }
    else
    {
        rxFifo->msgId = (*Flexcan_Mb_Id) >> FLEXCAN_IP_ID_STD_SHIFT;
    }

    if ((rxFifo->cs & FLEXCAN_IP_CS_RTR_MASK) != 0U)
    {
        can_real_payload = 0U;
    }

    Idhit_Offset = (can_real_payload >> 2U) + (((can_real_payload % 4U) != 0U) ? 1U : 0U);

    /* Extract the IDHIT */
    idHitaux = (uint8)(((Flexcan_Mb_Data_32[Idhit_Offset]) & FLEXCAN_IP_ENHANCED_IDHIT_MASK) >> FLEXCAN_IP_ENHANCED_IDHIT_SHIFT);
	filterElement = ((rxFifo->cs & FLEXCAN_IP_CS_IDE_MASK) == 0U) ? ((uint8)(((base->ERFCR) & FLEXCAN_ERFCR_NEXIF_MASK) >> FLEXCAN_ERFCR_NEXIF_SHIFT) + idHitaux) : idHitaux;
    rxFifo->id_hit = filterIdMap[u8Instance][filterElement];
#if (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON)
    /* Extract the Time Stamp */
    if (FLEXCAN_IsHRTimeStampEnabled(base))
    {
        rxFifo->time_stamp = (uint32)(Flexcan_Mb_Data_32[Idhit_Offset + 1U]);
    }
    else
#endif
    {
        rxFifo->time_stamp = (uint32)((rxFifo->cs & FLEXCAN_IP_CS_TIME_STAMP_MASK) >> FLEXCAN_IP_CS_TIME_STAMP_SHIFT);
    }

    /* Copy EnhancedRxFIFO data field into user's buffer */
    for (DataByte = 0U; DataByte < can_real_payload; DataByte += 4U)
    {
        MbWord = Flexcan_Mb_Data_32[DataByte >> 2U];
        FLEXCAN_IP_SWAP_BYTES_IN_WORD((MbWord), (MsgData_32[DataByte >> 2U]));
    }
}
#endif /* FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO */

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_IsMbOutOfRange
 * Description   : Check if the mb index is out of range or not.
 *
 *END**************************************************************************/
boolean FlexCAN_IsMbOutOfRange
(
    const FLEXCAN_Type * pBase,
    uint8 u8MbIndex,
    boolean bIsLegacyFifoEn,
    uint32 u32MaxMbNum
)
{
    boolean ReturnValue = FALSE;
    uint32 u32NumOfFiFoElement = 0U;
    uint32 u32NumOfMbOccupiedByFiFo = 0U;

    if (u8MbIndex >= (uint8)u32MaxMbNum)
    {
       ReturnValue = TRUE;
    }
    /* Check if RX FIFO is enabled*/
    else if (TRUE == bIsLegacyFifoEn)
    {
        /* Get the number of RX FIFO Filters*/
        u32NumOfFiFoElement = (((pBase->CTRL2) & FLEXCAN_CTRL2_RFFN_MASK) >> FLEXCAN_CTRL2_RFFN_SHIFT);
        /* Get the number if MBs occupied by RX FIFO and ID filter table*/
        /* the Rx FIFO occupies the memory space originally reserved for MB0-5*/
        /* Every number of RFFN means 8 number of RX FIFO filters*/
        /* and every 4 number of RX FIFO filters occupied one MB*/
        u32NumOfMbOccupiedByFiFo = 5U + ((((u32NumOfFiFoElement) + 1U) * 8U) / 4U);
        if (u8MbIndex <= u32NumOfMbOccupiedByFiFo)
        {
            ReturnValue = TRUE;
        }
    }
    else
    {
        ReturnValue = FALSE;
    }

    return ReturnValue;
}

#if (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON)

/*FUNCTION**********************************************************************
 *
 * Function Name : FLEXCAN_IsEnhancedRxFifoAvailable
 * Description   : Checks if FlexCAN has Enhanced Rx FIFO.
 * This function is private.
 *
 *END**************************************************************************/
boolean FlexCAN_IsEnhancedRxFifoAvailable(const FLEXCAN_Type * base)
{
    uint32 i=0U;
    static FLEXCAN_Type * const FlexcanBase[] = FLEXCAN_IP_BASE_PTRS_HAS_ENHANCED_RX_FIFO;
    boolean ReturnValue = FALSE;

    for (i = 0U; i < FLEXCAN_IP_FEATURE_ENHANCED_RX_FIFO_NUM; i++)
    {
        if (base == FlexcanBase[i])
        {
            ReturnValue = TRUE;
            break;
        }
    }

    return ReturnValue;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_EnableEnhancedRxFifo
 * Description   : Enable Enhanced Rx FIFO feature.
 * This function will enable the Enhanced Rx FIFO feature.
 *
 *END**************************************************************************/
Flexcan_Ip_StatusType FlexCAN_EnableEnhancedRxFifo(FLEXCAN_Type * base,
                                                   uint32 numOfStdIDFilters,
                                                   uint32 numOfExtIDFilters,
                                                   uint32 numOfWatermark
                                                  )
{
    Flexcan_Ip_StatusType Stat = FLEXCAN_STATUS_SUCCESS;
    uint32 NumOfEnhancedFilters = 0U;

    if (FlexCAN_IsEnhancedRxFifoAvailable(base))
    {

        /* NumOfEnhancedFilters equals (numOfStdIDFilters/2) + numOfExtIDFilters - 1u */
        NumOfEnhancedFilters = (numOfStdIDFilters >> 1u) + numOfExtIDFilters - 1u;

        if ((0U == numOfStdIDFilters) && (0U == numOfExtIDFilters))
        {
            Stat = FLEXCAN_STATUS_ERROR;
        }
        /* If the no of Std Filters is odd */
        if (1U == (numOfStdIDFilters & 1U))
        {
             Stat = FLEXCAN_STATUS_ERROR;
        }
        /*Enhanced RX FIFO and Legacy RX FIFO cannot be enabled at the same time.*/
        if (FLEXCAN_MCR_RFEN_MASK == (base->MCR & FLEXCAN_MCR_RFEN_MASK))
        {
            Stat = FLEXCAN_STATUS_ERROR;
        }

        if (FLEXCAN_STATUS_SUCCESS == Stat)
        {
            /* Enable Enhanced Rx FIFO */
            base->ERFCR = (base->ERFCR & ~FLEXCAN_ERFCR_ERFEN_MASK) | FLEXCAN_ERFCR_ERFEN(1U);
            /* Reset Enhanced Rx FIFO engine */
            base->ERFSR = (base->ERFSR & ~FLEXCAN_ERFSR_ERFCLR_MASK) | FLEXCAN_ERFSR_ERFCLR(1U);
            /* Clear the status bits of the Enhanced RX FIFO */
            base->ERFSR = base->ERFSR & ~(FLEXCAN_ERFSR_ERFUFW_MASK | FLEXCAN_ERFSR_ERFOVF_MASK | FLEXCAN_ERFSR_ERFWMI_MASK | FLEXCAN_ERFSR_ERFDA_MASK);
            /* Set the total number of enhanced Rx FIFO filter elements */
            base->ERFCR = (base->ERFCR & ~FLEXCAN_ERFCR_NFE_MASK) | ((NumOfEnhancedFilters << FLEXCAN_ERFCR_NFE_SHIFT) & FLEXCAN_ERFCR_NFE_MASK);
            /* Set the number of extended ID filter elements */
            base->ERFCR = (base->ERFCR & ~FLEXCAN_ERFCR_NEXIF_MASK) | ((numOfExtIDFilters << FLEXCAN_ERFCR_NEXIF_SHIFT) & FLEXCAN_ERFCR_NEXIF_MASK);
            /* Set the Enhanced Rx FIFO watermark */
            base->ERFCR = (base->ERFCR & ~FLEXCAN_ERFCR_ERFWM_MASK) | ((numOfWatermark << FLEXCAN_ERFCR_ERFWM_SHIFT) & FLEXCAN_ERFCR_ERFWM_MASK);
        }
    }
    else
    {
        Stat = FLEXCAN_STATUS_ERROR;
    }

    return Stat;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_SetEnhancedRxFifoFilter
 * Description   : Configure Enhanced RX FIFO ID filter table elements.
 *
 *END**************************************************************************/
void FlexCAN_SetEnhancedRxFifoFilter(const uint8 u8Instance, const Flexcan_Ip_EnhancedIdTableType * idFilterTable)
{
    /* Set Enhanced RX FIFO ID filter table elements*/
    uint8 i, j, n, NumOfEnhancedFilter, NumOfExtIDFilter, NumOfStdIDFilter;
    uint32 Val2 = 0U, Val1 = 0U, Val = 0U;

    volatile uint32 * FilterExtIDTable = NULL_PTR;
    volatile uint32 * FilterStdIDTable = NULL_PTR;

    static FLEXCAN_Type * const FlexcanBase[] = FLEXCAN_IP_BASE_PTRS_HAS_ENHANCED_RX_FIFO;
    FLEXCAN_Type * base = FlexcanBase[u8Instance];
    NumOfEnhancedFilter = (uint8)(((base->ERFCR) & FLEXCAN_ERFCR_NFE_MASK) >> FLEXCAN_ERFCR_NFE_SHIFT);
    NumOfExtIDFilter = (uint8)(((base->ERFCR) & FLEXCAN_ERFCR_NEXIF_MASK) >> FLEXCAN_ERFCR_NEXIF_SHIFT);
    NumOfStdIDFilter = 2U * (NumOfEnhancedFilter - NumOfExtIDFilter + 1U);
    FilterExtIDTable = (volatile uint32 *)&base->ERFFEL[FLEXCAN_IP_ENHANCED_RX_FIFO_FILTER_TABLE_BASE];
    FilterStdIDTable = (volatile uint32 *)&base->ERFFEL[NumOfExtIDFilter * 2U];
    j = 0U;
    n = 0U;
    for (i = 0U; i < (NumOfExtIDFilter + NumOfStdIDFilter); i++)
    {
        if (!(idFilterTable[i].isExtendedFrame))
        {
            Val = 0U;
            filterIdMap[u8Instance][NumOfExtIDFilter+j]=i;
            if (idFilterTable[i].rtr2)
            {
                Val = FLEXCAN_IP_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_RTR2_SHIFT;
            }

            if (idFilterTable[i].rtr1)
            {
                Val |= FLEXCAN_IP_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_RTR1_SHIFT;
            }

            FilterStdIDTable[j] =
                ((idFilterTable[i].id2 & FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_MASK) << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_SHIFT2) |
                ((idFilterTable[i].id1 & FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_MASK) << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_STD_SHIFT1) | Val;
            switch (idFilterTable[i].filterType)
            {
                case FLEXCAN_IP_ENHANCED_RX_FIFO_ONE_ID_FILTER :
                {
                    FilterStdIDTable[j] |= (uint32)FLEXCAN_IP_ENHANCED_RX_FIFO_ONE_ID_FILTER << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_FSCH_SHIFT;
                }break;

                case FLEXCAN_IP_ENHANCED_RX_FIFO_RANGE_ID_FILTER :
                {
                    FilterStdIDTable[j] |= (uint32)FLEXCAN_IP_ENHANCED_RX_FIFO_RANGE_ID_FILTER << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_FSCH_SHIFT;
                }break;

                case FLEXCAN_IP_ENHANCED_RX_FIFO_TWO_ID_FILTER :
                {
                    FilterStdIDTable[j] |= (uint32)FLEXCAN_IP_ENHANCED_RX_FIFO_TWO_ID_FILTER << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_FSCH_SHIFT;
                }break;
                default:
                {
#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
                    DevAssert(FALSE);
                    /* Should not get here */
#endif
                }break;
            }

            j++;
        }
        else
        {
            Val2 = 0U;
            Val1 = 0U;
            filterIdMap[u8Instance][n>>1U]=i;
            if (idFilterTable[i].rtr2)
            {
                Val2 = FLEXCAN_IP_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_EXT_RTR_SHIFT;
            }

            if (idFilterTable[i].rtr1)
            {
                Val1 = FLEXCAN_IP_RX_FIFO_ACCEPT_REMOTE_FRAME << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_EXT_RTR_SHIFT;
            }
            FilterExtIDTable[n] = ((idFilterTable[i].id2 & FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_EXT_MASK) << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_EXT_SHIFT) |
                                    Val2;

            FilterExtIDTable[n + 1U] = ((idFilterTable[i].id1 & FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_EXT_MASK) << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_EXT_SHIFT) |
                                        Val1;
            switch (idFilterTable[i].filterType)
            {
                case FLEXCAN_IP_ENHANCED_RX_FIFO_ONE_ID_FILTER :
                {
                    FilterExtIDTable[n] |= (uint32)FLEXCAN_IP_ENHANCED_RX_FIFO_ONE_ID_FILTER << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_FSCH_SHIFT;
                }break;
                case FLEXCAN_IP_ENHANCED_RX_FIFO_RANGE_ID_FILTER :
                {
                    FilterExtIDTable[n] |= (uint32)FLEXCAN_IP_ENHANCED_RX_FIFO_RANGE_ID_FILTER << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_FSCH_SHIFT;
                }break;
                case FLEXCAN_IP_ENHANCED_RX_FIFO_TWO_ID_FILTER :
                {
                    FilterExtIDTable[n] |= (uint32)FLEXCAN_IP_ENHANCED_RX_FIFO_TWO_ID_FILTER << FLEXCAN_IP_ENHANCED_RX_FIFO_ID_FILTER_FSCH_SHIFT;
                }break;
                default :
                {
#if (FLEXCAN_IP_DEV_ERROR_DETECT == STD_ON)
                    DevAssert(FALSE);
                    /* Should not get here */
#endif
                }break;
            }
            n = n + 2U;
        }
    }
}

#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_ClearOutputEnhanceFIFO
 * Description   : Clear output of enhance fifo.
 *
 *END**************************************************************************/
void FlexCAN_ClearOutputEnhanceFIFO(FLEXCAN_Type * base)
{
    volatile const uint32 * Ram = (uint32 *)((Flexcan_Ip_PtrSizeType)base);
    uint32 LastWord_Offset = ((uint32)0x204C) / ((uint32)4U); /* fixed, because DMALW is always = 19 */
    uint8 u8TimeOut = 0;

    /* If Enhanced Rx FIFO has Pending Request that generated error,
     * the EnhancedRxFIFO need to be empty to activate DMA */
    if ((uint8)1U == FlexCAN_GetEnhancedRxFIFOStatusFlag(base, FLEXCAN_IP_ENHANCED_RXFIFO_FRAME_AVAILABLE))
    {
        /* Enter CAN in freeze Mode to allow Enhanced Rx FIFO Clear */
        (void)FlexCAN_EnterFreezeMode(base);
        FlexCAN_ClearEnhancedFIFO(base);

        do
        {
            if ((uint32)FLEXCAN_MCR_DMA_MASK == (base->MCR & ((uint32)FLEXCAN_MCR_DMA_MASK)))
            {
                /* Read Enhanced Output to clear DMA pending request */
                (void)Ram[LastWord_Offset];
            }
            else
            {
                FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, FLEXCAN_IP_ENHANCED_RXFIFO_FRAME_AVAILABLE);
            }
            u8TimeOut++;
        }
        while (((uint8)1U == FlexCAN_GetEnhancedRxFIFOStatusFlag(base, FLEXCAN_IP_ENHANCED_RXFIFO_FRAME_AVAILABLE)) && (u8TimeOut <= ((uint8)64U))); /* avoid blocking */

        FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, FLEXCAN_IP_ENHANCED_RXFIFO_OVERFLOW);
        FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, FLEXCAN_IP_ENHANCED_RXFIFO_WATERMARK);
        FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, FLEXCAN_IP_ENHANCED_RXFIFO_FRAME_AVAILABLE);
        FlexCAN_ClearEnhancedRxFifoIntStatusFlag(base, FLEXCAN_IP_ENHANCED_RXFIFO_UNDERFLOW);

        /* Return CAN to normal Mode */
        (void)FlexCAN_ExitFreezeMode(base);
    }
}
#endif /* (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON) */
#endif /* (FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO == STD_ON) */
#if (FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_ClearOutputLegacyFIFO
 * Description   : Clear output of legacy fifo.
 *
 *END**************************************************************************/
void FlexCAN_ClearOutputLegacyFIFO(FLEXCAN_Type * base)
{
    volatile const uint32 * Ram = (uint32 *)((Flexcan_Ip_PtrSizeType)base);
    uint32 LastWord_Offset = ((uint32)0x8C) / ((uint32)4U); /* fixed, dma last word */
    uint8 i = 0;

    /* Check if FIFO has Pending Request that generated error,
    * the RxFIFO need to be empty to activate DMA */
    if ((uint8)1U == FlexCAN_GetBuffStatusFlag(base, FLEXCAN_IP_LEGACY_RXFIFO_FRAME_AVAILABLE))
    {
        /* Enter CAN in freeze Mode to allow FIFO Clear */
        (void)FlexCAN_EnterFreezeMode(base);
        FlexCAN_ClearFIFO(base);
        if ((uint32)FLEXCAN_MCR_DMA_MASK == (base->MCR & ((uint32)FLEXCAN_MCR_DMA_MASK)))
        {
            do
            {
                /* Read Offset 0x8C to clear DMA pending request */
                (void)Ram[LastWord_Offset];
                i++;
            }
            while (((uint8)1U == FlexCAN_GetBuffStatusFlag(base, FLEXCAN_IP_LEGACY_RXFIFO_FRAME_AVAILABLE)) && (i <= (uint8)12U)); /* avoid blocking */
        }

        FlexCAN_ClearMsgBuffIntStatusFlag(base, FLEXCAN_IP_LEGACY_RXFIFO_FRAME_AVAILABLE);
        FlexCAN_ClearMsgBuffIntStatusFlag(base, FLEXCAN_IP_LEGACY_RXFIFO_WARNING);
        FlexCAN_ClearMsgBuffIntStatusFlag(base, FLEXCAN_IP_LEGACY_RXFIFO_OVERFLOW);

        /* Return CAN to normal Mode */
        (void)FlexCAN_ExitFreezeMode(base);
    }
}
#endif /* FLEXCAN_IP_FEATURE_HAS_DMA_ENABLE */

#if (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)
#if (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON)
#if (FLEXCAN_IP_HR_TIMESTAMP_SRC_SELECTABLE == STD_ON)
#if (STD_ON == FLEXCAN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_ConfigTimestampModule
 * Description   : Configure High Resolution Timestamp Source.
 *
 *END**************************************************************************/
void FlexCAN_ConfigTimestampModule
(
#ifdef FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED
    uint8 instance,
#endif /* FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED */
    const Flexcan_Ip_TimeStampConfigType * config
)
#else
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_ConfigTimestampModule
 * Description   : Configure High Resolution Timestamp Source.
 *
 *END**************************************************************************/
static void FlexCAN_ConfigTimestampModule
(
#ifdef FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED
    uint8 instance,
#endif /* FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED */
    const Flexcan_Ip_TimeStampConfigType * config
)
#endif
{
    #ifdef FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED
    uint16 TimestampIns = 0U;
    static FLEXCAN_IP_TBS_Type * const pCanTBSBase[] = FLEXCAN_IP_TBS_BASE_PTRS;
    /* The index of TBS of FLEXCANs will start behind CANXLs */
    TimestampIns = instance + (uint8)FLEXCAN_IP_TIMESTAMP_TBS_START_INDEX;
    FLEXCAN_IP_TIMESTAMP_REG(TimestampIns) &= ~(FLEXCAN_IP_TIMESTAMP_EN_MASK | FLEXCAN_IP_TIMESTAMP_SEL_MASK);
    FLEXCAN_IP_TIMESTAMP_REG(TimestampIns) |= FLEXCAN_IP_TIMESTAMP_SEL(config->hrSrc)|FLEXCAN_IP_TIMESTAMP_EN_MASK;
    #else
    FLEXCAN_IP_TIMESTAMP_REG &= ~(FLEXCAN_IP_TIMESTAMP_EN_MASK | FLEXCAN_IP_TIMESTAMP_SEL_MASK);
    FLEXCAN_IP_TIMESTAMP_REG |= FLEXCAN_IP_TIMESTAMP_SEL(config->hrSrc)|FLEXCAN_IP_TIMESTAMP_EN_MASK;
    #endif /* FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED */
}
#endif /* (FLEXCAN_IP_HR_TIMESTAMP_SRC_SELECTABLE == STD_ON) */
#endif /* (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON) */

void FlexCAN_ConfigTimestamp(uint8 instance, FLEXCAN_Type * base, const Flexcan_Ip_TimeStampConfigType * config)
{
    uint32 Temp = 0U;

    SchM_Enter_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_19();
    Temp = FLEXCAN_CTRL2_TIMER_SRC(config->timeStampSurce);
#if (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON)
    Temp |= FLEXCAN_CTRL2_MBTSBASE(config->msgBuffTimeStampType);
    Temp |= FLEXCAN_CTRL2_TSTAMPCAP(config->hrConfigType);
    base->CTRL2 &= ~(FLEXCAN_CTRL2_TIMER_SRC_MASK | FLEXCAN_CTRL2_MBTSBASE_MASK | FLEXCAN_CTRL2_TSTAMPCAP_MASK);
#else
    base->CTRL2 &= ~(FLEXCAN_CTRL2_TIMER_SRC_MASK);
#endif /* FLEXCAN_IP_FEATURE_HAS_HR_TIMER */
    base->CTRL2 |= Temp;
    SchM_Exit_Can_43_FLEXCAN_CAN_EXCLUSIVE_AREA_19();
#if ((FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON) && (FLEXCAN_IP_HR_TIMESTAMP_SRC_SELECTABLE == STD_ON))
    if (config->hrConfigType != FLEXCAN_TIMESTAMPCAPTURE_DISABLE)
    {
#ifdef FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED
    #if (STD_ON == FLEXCAN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
        OsIf_Trusted_Call2params(FlexCAN_ConfigTimestampModule, instance, config);
    #else
        FlexCAN_ConfigTimestampModule(instance, config);
    #endif
#else
    #if (STD_ON == FLEXCAN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
        OsIf_Trusted_Call1param(FlexCAN_ConfigTimestampModule, config);
    #else
        FlexCAN_ConfigTimestampModule(config);
    #endif
    (void)instance;
#endif /* FLEXCAN_IP_TIMESTAMP_HR_SOURCE_TBS_USED */
    }
#else
    (void)instance;
#endif /* (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON) && (FLEXCAN_IP_HR_TIMESTAMP_SRC_SELECTABLE == STD_ON) */
}
#endif /* (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON) */

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_ConfigCtrlOptions
 * Description   : configure controller depending on options
 * note: should be call after FD configuration.
 *
 *END**************************************************************************/
void FlexCAN_ConfigCtrlOptions(FLEXCAN_Type * pBase, uint32 u32Options)
{
#if (FLEXCAN_IP_FEATURE_SWITCHINGISOMODE == STD_ON)
    /* If the FD feature is enabled, in order to be ISO-compliant. */
    if ((u32Options & FLEXCAN_IP_ISO_U32) != 0U)
    {
        FlexCAN_SetIsoCan(pBase, TRUE);
    }
    else
    {
        /* This maybe don't have sense if the Deinit returns the state of registers at init values */
        FlexCAN_SetIsoCan(pBase, FALSE);
    }
#endif /*(FLEXCAN_IP_FEATURE_SWITCHINGISOMODE == STD_ON) */
    /* Set Entire Frame Arbitration Field Comparison. */
    if ((u32Options & FLEXCAN_IP_EACEN_U32) != 0U)
    {
        FlexCAN_SetEntireFrameArbitrationFieldComparison(pBase, TRUE);
    }
    else
    {
        FlexCAN_SetEntireFrameArbitrationFieldComparison(pBase, FALSE);
    }
#if (FLEXCAN_IP_FEATURE_PROTOCOLEXCEPTION == STD_ON)
    /* Set protocol Exception */
    if ((u32Options & FLEXCAN_IP_PROTOCOL_EXCEPTION_U32) != 0U)
    {
        FlexCAN_SetProtocolException(pBase, TRUE);
    }
    else
    {
        FlexCAN_SetProtocolException(pBase, FALSE);
    }
#endif /* Endif  (FLEXCAN_IP_FEATURE_PROTOCOLEXCEPTION == STD_ON)  */
    /* Set CAN Bit Sampling */
    if (((u32Options & FLEXCAN_IP_THREE_SAMPLES_U32) != 0U) && (0U == (pBase->MCR & FLEXCAN_MCR_FDEN_MASK)))
    {
        FlexCAN_CanBitSampling(pBase, TRUE);
    }
    else
    {
        FlexCAN_CanBitSampling(pBase, FALSE);
    }

    /* Set AutoBusOff Recovery */
    if ((u32Options & FLEXCAN_IP_BUSOFF_RECOVERY_U32) != 0U)
    {
        FlexCAN_SetBusOffAutorecovery(pBase, TRUE);
    }
    else
    {
        FlexCAN_SetBusOffAutorecovery(pBase, FALSE);
    }
    /* Set Remote Request Store for received of Remote Request Frames */
    if ((u32Options & FLEXCAN_IP_REM_STORE_U32) != 0U)
    {
        FlexCAN_SetRemoteReqStore(pBase, TRUE);
    }
    else
    {
        FlexCAN_SetRemoteReqStore(pBase, FALSE);
    }
#if (FLEXCAN_IP_FEATURE_EDGEFILTER == STD_ON)
    /* Set Edge Filter */
    if ((u32Options & FLEXCAN_IP_EDGE_FILTER_U32) != 0U)
    {
        FlexCAN_SetEdgeFilter(pBase, TRUE);
    }
    else
    {
        FlexCAN_SetEdgeFilter(pBase, FALSE);
    }
#endif /* End of (FLEXCAN_IP_FEATURE_EDGEFILTER == STD_ON)  */
}

#if (FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_ConfigPN
 * Description   : Configures the Pretended Networking mode.
 *
 *END**************************************************************************/
void FlexCAN_ConfigPN(FLEXCAN_Type * pBase,
                      const Flexcan_Ip_PnConfigType * pPnConfig)
{
    /* Configure specific pretended networking settings */
    FlexCAN_SetPNFilteringSelection(pBase, pPnConfig);

    FlexCAN_SetPNTimeoutValue(pBase, pPnConfig->u16MatchTimeout);

    /* Configure ID filtering */
    FlexCAN_SetPNIdFilter1(pBase, pPnConfig->idFilter1);

    /* Configure the second ID, if needed (as mask for exact matching or higher limit for range matching) */
    if ((FLEXCAN_FILTER_MATCH_EXACT == pPnConfig->eIdFilterType) || (FLEXCAN_FILTER_MATCH_RANGE == pPnConfig->eIdFilterType))
    {
        FlexCAN_SetPNIdFilter2(pBase, pPnConfig);
    }
    else
    {
        /* In other case need only to check the IDE and RTR match the ID_MASK is not considered */
        FlexCAN_SetPNIdFilter2Check(pBase);
    }

    /* Configure payload filtering, if requested */
    if ((FLEXCAN_FILTER_ID_PAYLOAD == pPnConfig->eFilterComb) || (FLEXCAN_FILTER_ID_PAYLOAD_NTIMES == pPnConfig->eFilterComb))
    {
        FlexCAN_SetPNDlcFilter(pBase, pPnConfig->payloadFilter.u8DlcLow, pPnConfig->payloadFilter.u8DlcHigh);

        FlexCAN_SetPNPayloadHighFilter1(pBase, pPnConfig->payloadFilter.aPayload1);
        FlexCAN_SetPNPayloadLowFilter1(pBase, pPnConfig->payloadFilter.aPayload1);

        /* Configure the second payload, if needed (as mask for exact matching or higher limit for range matching) */
        if ((FLEXCAN_FILTER_MATCH_EXACT == pPnConfig->ePayloadFilterType) || (FLEXCAN_FILTER_MATCH_RANGE == pPnConfig->ePayloadFilterType))
        {
            FlexCAN_SetPNPayloadHighFilter2(pBase, pPnConfig->payloadFilter.aPayload2);
            FlexCAN_SetPNPayloadLowFilter2(pBase, pPnConfig->payloadFilter.aPayload2);
        }
    }
}

#endif /* FLEXCAN_IP_FEATURE_HAS_PRETENDED_NETWORKING */

/*FUNCTION**********************************************************************
 *
 * Function Name : FlexCAN_ResetImaskBuff (uses in FlexCAN_Ip_Init function only)
 * Description   : Reset Imask Buffers.
 *
 *END**************************************************************************/
void FlexCAN_ResetImaskBuff(uint8 Instance)
{
    uint8 ImaskCnt = 0U;

    for (ImaskCnt = 0U; ImaskCnt < FLEXCAN_IP_FEATURE_MBDSR_COUNT; ImaskCnt++)
    {
        FlexCAN_Ip_au32ImaskBuff[Instance][ImaskCnt] = 0U;
    }
}

#define CAN_43_FLEXCAN_STOP_SEC_CODE
#include "Can_43_FLEXCAN_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
