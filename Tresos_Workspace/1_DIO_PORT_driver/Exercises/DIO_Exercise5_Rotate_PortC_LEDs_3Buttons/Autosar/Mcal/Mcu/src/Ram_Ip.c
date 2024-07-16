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
/**
*   @file       Ram_Ip.c
*   @version    2.0.0
*
*   @brief   RAM driver implementations.
*   @details RAM driver implementations.
*
*   @addtogroup RAM_DRIVER Ram Ip Driver
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
#include "Ram_Ip.h"
#include "OsIf.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RAM_IP_VENDOR_ID_C                      43
#define RAM_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define RAM_IP_AR_RELEASE_MINOR_VERSION_C       7
#define RAM_IP_AR_RELEASE_REVISION_VERSION_C    0
#define RAM_IP_SW_MAJOR_VERSION_C               2
#define RAM_IP_SW_MINOR_VERSION_C               0
#define RAM_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Ram_Ip.c file and Ram_Ip.h file are of the same vendor */
#if (RAM_IP_VENDOR_ID_C != RAM_IP_VENDOR_ID)
    #error "Ram_Ip.c and Ram_Ip.h have different vendor ids"
#endif

/* Check if Ram_Ip.c file and Ram_Ip.h file are of the same Autosar version */
#if ((RAM_IP_AR_RELEASE_MAJOR_VERSION_C != RAM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_IP_AR_RELEASE_MINOR_VERSION_C != RAM_IP_AR_RELEASE_MINOR_VERSION) || \
     (RAM_IP_AR_RELEASE_REVISION_VERSION_C != RAM_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ram_Ip.c and Ram_Ip.h are different"
#endif

/* Check if Ram_Ip.c file and Ram_Ip.h file are of the same Software version */
#if ((RAM_IP_SW_MAJOR_VERSION_C != RAM_IP_SW_MAJOR_VERSION) || \
     (RAM_IP_SW_MINOR_VERSION_C != RAM_IP_SW_MINOR_VERSION) || \
     (RAM_IP_SW_PATCH_VERSION_C != RAM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ram_Ip.c and Ram_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Ram_Ip.c file and OsIf.h file are of the same Autosar version */
#if ((RAM_IP_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_IP_AR_RELEASE_MINOR_VERSION_C    != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ram_Ip.c and OsIf.h are different"
#endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief            This function initializes a given RAM section of the MCU on the common (main) platform.
* @details          Function initializes the RAM section specified by the pointer to the "Mcu_RamConfigType" parameter.
*                   The section's base address, size, value to be written, and write-at-once-size are provided by
*                   the configuration structure.
*                   The function will write the value specified in the configuration structure.
*                   After the write it will read back the RAM to verify that the requested value was
*                   written.
*                   Called by:
*                       - Mcu_InitRamSection() from HLD.
*
* @param[in]        RamConfigPtr   Pointer to RAM section configuration structure
*                   (member of 'Mcu_ConfigType' struct).
*
* @return           Status signaling if the given RAM section has or has not been successfully initialized.
* @retval           RAM_IP_STATUS_OK        The RAM section check was successful.
* @retval           RAM_IP_STATUS_NOT_OK    The RAM section check was not successful.
*
* @implements Ram_Ip_InitRamSection_Activity
*
*/
Ram_Ip_StatusType Ram_Ip_InitRamSection(const Ram_Ip_RamConfigType * RamConfigPtr)
{
    /* Result of the operation. */
    Ram_Ip_StatusType RamStatus = RAM_IP_STATUS_OK;
    /* Variable for indexing RAM sections. */
    Ram_Ip_RamIndexType RamCounter;
    /* Limit of RamCounter. */
    Ram_Ip_RamSizeType RamCounterLimit;

    RAM_IP_DEV_ASSERT(NULL_PTR != RamConfigPtr);

    RamCounterLimit = (Ram_Ip_RamSizeType)( ((Ram_Ip_RamSizeType)(RamConfigPtr->RamSize)) / (RamConfigPtr->RamWriteSize) );

    RamStatus = RAM_IP_STATUS_OK;
    RamCounter = (Ram_Ip_RamIndexType)0UL;
    while ((RamCounter < RamCounterLimit) && (RAM_IP_STATUS_OK == RamStatus))
    {
        switch (RamConfigPtr->RamWriteSize)
        {
            case (Ram_Ip_RamWriteSizeType)1U:

                ( *((uint8 (*)[1U]) ((Ram_Ip_uintPtrType) RamConfigPtr->RamBaseAddrPtr)) )[RamCounter]  = (uint8) RamConfigPtr->RamDefaultValue;
                break;

            case (Ram_Ip_RamWriteSizeType)2U:

                ( *((uint16 (*)[1U]) ((Ram_Ip_uintPtrType) RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] = (uint16) RamConfigPtr->RamDefaultValue;
                break;

            case (Ram_Ip_RamWriteSizeType)4U:

                ( *((uint32 (*)[1U]) ((Ram_Ip_uintPtrType) RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] = (uint32) RamConfigPtr->RamDefaultValue;
                break;

            case (Ram_Ip_RamWriteSizeType)8U:

                ( *((uint64 (*)[1U]) ((Ram_Ip_uintPtrType) RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] = (uint64) RamConfigPtr->RamDefaultValue;
                break;

            default:
                RamStatus = RAM_IP_STATUS_NOT_OK;
                break;
        }
        RamCounter++;
    }

    if ( RAM_IP_STATUS_OK == RamStatus )
    {
        RamCounter = (Ram_Ip_RamIndexType)0UL;
        /* Check if RAM was initialized correctly. */
        while ((RamCounter < RamCounterLimit) && (RAM_IP_STATUS_OK == RamStatus))
        {
            switch (RamConfigPtr->RamWriteSize)
            {
                case (Ram_Ip_RamWriteSizeType)1U:

                    if ( (uint8) RamConfigPtr->RamDefaultValue  != ( *((uint8 (*)[1U]) ((Ram_Ip_uintPtrType)RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] )
                    {
                        RamStatus = RAM_IP_STATUS_NOT_OK;
                    }
                    break;

                case (Ram_Ip_RamWriteSizeType)2U:

                    if ( (uint16) RamConfigPtr->RamDefaultValue != ( *((uint16 (*)[1U]) ((Ram_Ip_uintPtrType)RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] )
                    {
                        RamStatus = RAM_IP_STATUS_NOT_OK;
                    }
                    break;

                case (Ram_Ip_RamWriteSizeType)4U:

                    if ( (uint32) RamConfigPtr->RamDefaultValue != ( *((uint32 (*)[1U]) ((Ram_Ip_uintPtrType)RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] )
                    {
                        RamStatus = RAM_IP_STATUS_NOT_OK;
                    }
                    break;

                case (Ram_Ip_RamWriteSizeType)8U:

                    if ( (uint64) RamConfigPtr->RamDefaultValue != ( *((uint64 (*)[1U]) ((Ram_Ip_uintPtrType)RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] )
                    {
                        RamStatus = RAM_IP_STATUS_NOT_OK;
                    }
                    break;

                default:
                    RamStatus = RAM_IP_STATUS_NOT_OK;
                    break;
            }
            RamCounter++;
        }
    }

    return RamStatus;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

