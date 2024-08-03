/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : none
*   Dependencies         : MemAcc
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

/**
*   @file MemAcc_PBcfg.c
*
*   @addtogroup MEMACC
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
#include "MemAcc_Types.h"

#include "Mem_43_INFLS.h"
#include "SchM_Mem_43_INFLS.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMACC_PBCFG_VENDOR_ID_C                      43
#define MEMACC_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define MEMACC_PBCFG_AR_RELEASE_MINOR_VERSION_C       7
#define MEMACC_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define MEMACC_PBCFG_SW_MAJOR_VERSION_C               2
#define MEMACC_PBCFG_SW_MINOR_VERSION_C               0
#define MEMACC_PBCFG_SW_PATCH_VERSION_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/* Check if current file and MemAcc_Types.h file are of the same vendor */
#if (MEMACC_PBCFG_VENDOR_ID_C != MEMACC_TYPES_VENDOR_ID)
    #error "MemAcc_PBcfg.c and MemAcc_Types.h have different vendor ids"
#endif
/* Check if current file and MemAcc_Types.h file are of the same Autosar version */
#if ((MEMACC_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != MEMACC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEMACC_PBCFG_AR_RELEASE_MINOR_VERSION_C    != MEMACC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEMACC_PBCFG_AR_RELEASE_REVISION_VERSION_C != MEMACC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of MemAcc_PBcfg.c and MemAcc_Types.h are different"
#endif
/* Check if current file and MemAcc_Types.h file are of the same software version */
#if ((MEMACC_PBCFG_SW_MAJOR_VERSION_C != MEMACC_TYPES_SW_MAJOR_VERSION) || \
     (MEMACC_PBCFG_SW_MINOR_VERSION_C != MEMACC_TYPES_SW_MINOR_VERSION) || \
     (MEMACC_PBCFG_SW_PATCH_VERSION_C != MEMACC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of MemAcc_PBcfg.c and MemAcc_Types.h are different"
#endif

/* Check if current file and Mem_43_INFLS.h file are of the same vendor */
#if (MEMACC_PBCFG_VENDOR_ID_C != MEM_43_INFLS_VENDOR_ID)
    #error "MemAcc_PBcfg.c and Mem_43_INFLS.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS.h file are of the same Autosar version */
#if ((MEMACC_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION) || \
     (MEMACC_PBCFG_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION) || \
     (MEMACC_PBCFG_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of MemAcc_PBcfg.c and Mem_43_INFLS.h are different"
#endif
/* Check if current file and Mem_43_INFLS.h file are of the same software version */
#if ((MEMACC_PBCFG_SW_MAJOR_VERSION_C != MEM_43_INFLS_SW_MAJOR_VERSION) || \
     (MEMACC_PBCFG_SW_MINOR_VERSION_C != MEM_43_INFLS_SW_MINOR_VERSION) || \
     (MEMACC_PBCFG_SW_PATCH_VERSION_C != MEM_43_INFLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of MemAcc_PBcfg.c and Mem_43_INFLS.h are different"
#endif


/*==================================================================================================
                                       INTERNAL RUNTIME INFORMATION
==================================================================================================*/
#define MEMACC_START_SEC_CODE
#include "MemAcc_MemMap.h"
extern void Fee_JobEndNotification(MemAcc_AddressAreaIdType AddressAreaId, MemAcc_JobResultType JobResult);

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h"

#define MEMACC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemAcc_MemMap.h"

/* Information of the current processing job of each adddress area */
static MemAcc_JobRuntimeInfoType    MemAcc_JobRuntimeInfo[1];

#define MEMACC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemAcc_MemMap.h"


/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define MEMACC_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemAcc_MemMap.h"


/* Configuration of mem driver information */
static MemAcc_MemApiType MemAcc_MemApis[1] =
{
    {
        /* Mem_43_INFLS driver */
        0xFFFFFFFFU,                                                                                /* UniqueId               */
        0xFFFFFFFFU,                                                                                /* Flags                  */
        0xFFFFFFFFU,                                                                                /* Header                 */
        0xFFFFFFFFU,                                                                                /* Delimiter              */
        (MemAcc_MemInitFuncType)Mem_43_INFLS_Init,                                                  /* InitFunc               */
        (MemAcc_MemDeInitFuncType)Mem_43_INFLS_DeInit,                                              /* DeInitFunc             */
        (MemAcc_MemMainFuncType)Mem_43_INFLS_MainFunction,                                          /* MainFunc               */
        (MemAcc_MemGetJobResultFuncType)Mem_43_INFLS_GetJobResult,                                  /* GetJobResultFunc       */
        (MemAcc_MemReadFuncType)Mem_43_INFLS_Read,                                                  /* ReadFunc               */
        (MemAcc_MemWriteFuncType)Mem_43_INFLS_Write,                                                /* WriteFunc              */
        (MemAcc_MemEraseFuncType)Mem_43_INFLS_Erase,                                                /* EraseFunc              */
        (MemAcc_MemBlankCheckFuncType)Mem_43_INFLS_BlankCheck,                                      /* BlankCheckFunc         */
        NULL_PTR,                                                                                   /* PropagateErrorFunc     */
        NULL_PTR,                                                                                   /* SuspendFunc            */
        NULL_PTR,                                                                                   /* ResumeFunc             */
        (MemAcc_MemHwSpecificServiceFuncType)Mem_43_INFLS_HwSpecificService                         /* HwSpecificServiceFunc  */
    }
};
#define MEMACC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemAcc_MemMap.h"

#define MEMACC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemAcc_MemMap.h"
/* Configuration of mem driver invocation type */
static const MemAcc_MemInvocationType MemAcc_MemInvocation[1] =
{
    MEMACC_MEM_INDIRECT_STATIC
};
/* Configuration of sub address areas */
static const MemAcc_SubAddressAreaType MemAcc_MemAccAddressAreaConfiguration_0_SubAreas[4U] =
{
    {
        /* MemAccSubAddressAreaConfiguration_0 */
        0U,                                                                                         /* LogicalStartAddress  */
        268435456U,                                                                                 /* PhysicalStartAddress */
        2048U,                                                                                      /* Length               */
        0U,                                                                                         /* NumOfEraseRetries    */
        0U,                                                                                         /* NumOfWriteRetries    */
        0U,                                                                                         /* BurstSettings        */
        MEMACC_MEM_INDIRECT_STATIC,                                                                 /* MemInvocation        */
        &(MemAcc_MemApis[MEMACC_MEM_43_INFLS_HW_ID]),                                               /* MemApi               */
        0U,                                                                                         /* MemInstanceId        */
        {
            2048U,                                                                                  /* SectorEraseSize           */
            1U,                                                                                     /* ReadPageSize              */
            8U,                                                                                     /* WritePageSize             */
            2048U,                                                                                  /* SectorEraseBurstSize      */
            1U,                                                                                     /* ReadPageBurstSize         */
            8U                                                                                      /* WritePageBurstSize        */
        },
        MEMACC_MEM_HW_INTERNAL,                                                                     /* MemHwResource        */
        MEMACC_MEM_43_INFLS_HW_ID                                                                   /* MemoryDriverHwId     */
    },
    {
        /* MemAccSubAddressAreaConfiguration_1 */
        2048U,                                                                                      /* LogicalStartAddress  */
        268437504U,                                                                                 /* PhysicalStartAddress */
        2048U,                                                                                      /* Length               */
        0U,                                                                                         /* NumOfEraseRetries    */
        0U,                                                                                         /* NumOfWriteRetries    */
        0U,                                                                                         /* BurstSettings        */
        MEMACC_MEM_INDIRECT_STATIC,                                                                 /* MemInvocation        */
        &(MemAcc_MemApis[MEMACC_MEM_43_INFLS_HW_ID]),                                               /* MemApi               */
        0U,                                                                                         /* MemInstanceId        */
        {
            2048U,                                                                                  /* SectorEraseSize           */
            1U,                                                                                     /* ReadPageSize              */
            8U,                                                                                     /* WritePageSize             */
            2048U,                                                                                  /* SectorEraseBurstSize      */
            1U,                                                                                     /* ReadPageBurstSize         */
            8U                                                                                      /* WritePageBurstSize        */
        },
        MEMACC_MEM_HW_INTERNAL,                                                                     /* MemHwResource        */
        MEMACC_MEM_43_INFLS_HW_ID                                                                   /* MemoryDriverHwId     */
    },
    {
        /* MemAccSubAddressAreaConfiguration_2 */
        4096U,                                                                                      /* LogicalStartAddress  */
        268439552U,                                                                                 /* PhysicalStartAddress */
        2048U,                                                                                      /* Length               */
        0U,                                                                                         /* NumOfEraseRetries    */
        0U,                                                                                         /* NumOfWriteRetries    */
        0U,                                                                                         /* BurstSettings        */
        MEMACC_MEM_INDIRECT_STATIC,                                                                 /* MemInvocation        */
        &(MemAcc_MemApis[MEMACC_MEM_43_INFLS_HW_ID]),                                               /* MemApi               */
        0U,                                                                                         /* MemInstanceId        */
        {
            2048U,                                                                                  /* SectorEraseSize           */
            1U,                                                                                     /* ReadPageSize              */
            8U,                                                                                     /* WritePageSize             */
            2048U,                                                                                  /* SectorEraseBurstSize      */
            1U,                                                                                     /* ReadPageBurstSize         */
            8U                                                                                      /* WritePageBurstSize        */
        },
        MEMACC_MEM_HW_INTERNAL,                                                                     /* MemHwResource        */
        MEMACC_MEM_43_INFLS_HW_ID                                                                   /* MemoryDriverHwId     */
    },
    {
        /* MemAccSubAddressAreaConfiguration_3 */
        6144U,                                                                                      /* LogicalStartAddress  */
        268441600U,                                                                                 /* PhysicalStartAddress */
        2048U,                                                                                      /* Length               */
        0U,                                                                                         /* NumOfEraseRetries    */
        0U,                                                                                         /* NumOfWriteRetries    */
        0U,                                                                                         /* BurstSettings        */
        MEMACC_MEM_INDIRECT_STATIC,                                                                 /* MemInvocation        */
        &(MemAcc_MemApis[MEMACC_MEM_43_INFLS_HW_ID]),                                               /* MemApi               */
        0U,                                                                                         /* MemInstanceId        */
        {
            2048U,                                                                                  /* SectorEraseSize           */
            1U,                                                                                     /* ReadPageSize              */
            8U,                                                                                     /* WritePageSize             */
            2048U,                                                                                  /* SectorEraseBurstSize      */
            1U,                                                                                     /* ReadPageBurstSize         */
            8U                                                                                      /* WritePageBurstSize        */
        },
        MEMACC_MEM_HW_INTERNAL,                                                                     /* MemHwResource        */
        MEMACC_MEM_43_INFLS_HW_ID                                                                   /* MemoryDriverHwId     */
    }
};



/* Configuration of address areas */
static const MemAcc_AddressAreaType MemAcc_AddressAreas[1] =
{
    {
        /* MemAccAddressAreaConfiguration_0 */
        0U,                                                                                         /* AreaId          */
        8192U,                                                                                      /* Length          */
        0U,                                                                                         /* Priority        */
        1U,                                                                                         /* BufferAlignment */
        Fee_JobEndNotification,                                                                     /* JobEndNotif     */
        4U,                                                                                         /* SubAreaCount    */
        MemAcc_MemAccAddressAreaConfiguration_0_SubAreas                                            /* SubAreas        */
    }
};


/* Configuration of MemAcc */
const MemAcc_ConfigType MemAcc_Config =
{
    1U,                                                                                             /* AddressAreaCount */
    MemAcc_AddressAreas,                                                                            /* AddressAreas     */
    MemAcc_JobRuntimeInfo,                                                                          /* JobRuntimeInfo   */
    1U,                                                                                             /* MemApiCount      */
    MemAcc_MemApis,                                                                                 /* MemApis          */
    MemAcc_MemInvocation                                                                            /* MemInvocation    */
};

#define MEMACC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemAcc_MemMap.h"


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @}*/
