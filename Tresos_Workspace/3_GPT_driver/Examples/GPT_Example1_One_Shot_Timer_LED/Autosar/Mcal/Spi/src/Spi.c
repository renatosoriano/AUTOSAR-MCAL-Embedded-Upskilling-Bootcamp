/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   Copyright 2020-2023 NXP Semiconductors NXP
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
*   @file    Spi.c
*   @implements Spi.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Implements the AUTOSAR SPI driver functionality.
*   @details Implements the AUTOSAR SPI driver. All the API functions are described by AUTOSAR
*
*   @addtogroup SPI_DRIVER Spi Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Spi_Ipw.h"
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif
#include "Det.h"
#include "SchM_Spi.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_MODULE_ID_C                     83
#define SPI_VENDOR_ID_C                     43
#define SPI_AR_RELEASE_MAJOR_VERSION_C      4
#define SPI_AR_RELEASE_MINOR_VERSION_C      7
#define SPI_AR_RELEASE_REVISION_VERSION_C   0
#define SPI_SW_MAJOR_VERSION_C              2
#define SPI_SW_MINOR_VERSION_C              0
#define SPI_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if this file and Spi.h are of the same vendor */
#if (SPI_VENDOR_ID_C != SPI_VENDOR_ID)
    #error "Spi.c and Spi.h have different vendor ids"
#endif
/* Check if current file and Spi header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_C != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_C != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_C != SPI_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi.c and Spi.h are different"
#endif
  /* Check if current file and Spi header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_C != SPI_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi.c and Spi.h are different"
#endif

/* Check if this header file and Spi_IPW_Types.h are of the same vendor */
#if (SPI_VENDOR_ID_C != SPI_IPW_VENDOR_ID)
    #error "Spi.c and Spi_Ipw.h have different vendor ids"
#endif
/* Check if current file and Spi_Ipw header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_C != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_C != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_C != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi.c and Spi_Ipw.h are different"
#endif
  /* Check if current file and Spi_Ipw header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_C != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_C != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_C != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi.c and Spi_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det.h header file are of the same Software version */
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi.h and Det.h are different"
    #endif
  
    #if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
      /* Check if the current file and Dem.h header file are of the same version */
      #if ((SPI_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
           (SPI_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Spi.c and Dem.h are different"
      #endif
    #endif

    /* Check if the current file and SchM_Spi.h header file are of the same version */
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_C != SCHM_SPI_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_AR_RELEASE_MINOR_VERSION_C != SCHM_SPI_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Spi.c and SchM_Spi.h are different"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief   This structure holds the HWUnit scheduling queue.
* @details For async transmissions, this structure holds the HWUnit scheduling queue .
*          For sync transmissions, only HWUnit Status is managed.
*
*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief  Values used to denote NULL indexes.
*/
#define SPI_JOB_NULL            ((Spi_JobType)(-1))
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define   SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
/**
* @brief Array of HW units queues.
*/
Spi_HWUnitQueue Spi_axSpiHwUnitQueueArray[SPI_MAX_HWUNIT];

#define   SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#if (SPI_PRECOMPILE_SUPPORT == STD_ON)
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Spi_MemMap.h"

extern const Spi_ConfigType * const Spi_PBCfgVariantPredefined[SPI_MAX_PARTITIONS];

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
#endif /* (SPI_PRECOMPILE_SUPPORT == STD_ON) */

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

const Spi_ConfigType *Spi_apxSpiConfigPtr[SPI_MAX_PARTITIONS];

/**
* @brief Spi State.
*/
static Spi_SequenceStateType Spi_axSpiSequenceState[SPI_MAX_SEQUENCE];

Spi_JobStateType Spi_axSpiJobState[SPI_MAX_JOB];

Spi_ChannelStateType Spi_axSpiChannelState[SPI_MAX_CHANNEL];

#if (SPI_MAX_HWUNIT > 32u)
    #error "Too many HW Units in configuration (max 32 units allowed)"
#endif

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define   SPI_START_SEC_VAR_CLEARED_32
#include "Spi_MemMap.h"

/**
* @note Array of used HW units per sequence:
*         The element corresponding to a given sequence will have asserted the bits
*         corresponding to the used HW units.
*/
#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
static uint32 Spi_au32SpiSeqUsedHWUnits[SPI_MAX_SEQUENCE];
#endif

/**
* @brief Spi Sync Transmit Running HWUnits Status.
*/
static volatile uint32 Spi_au32SpiBusySyncHWUnitsStatus[SPI_MAX_HWUNIT];

#define   SPI_STOP_SEC_VAR_CLEARED_32
#include "Spi_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static inline void Spi_ScheduleJob
    (
        Spi_HWUnitQueue* HWUnitQueue,
        Spi_JobType Job,
        const Spi_JobConfigType *JobConfig
    );
#endif

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL2)
static inline Spi_StatusType Spi_GetAsyncStatus(void);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static Std_ReturnType Spi_LockJobs
    (
        Spi_SequenceType SequenceId,
        const Spi_SequenceConfigType *Sequence
    );
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static inline void Spi_UnlockRemainingJobs
    (
        Spi_JobType RemainingJobs,
        const Spi_SequenceConfigType *Sequence
    );
#endif
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static void Spi_ScheduleNextJob
  (
      Spi_HWUnitQueue *HWUnitQueue,
      uint32 SpiCoreID
   );
#endif
static inline Std_ReturnType Spi_CheckInit
    ( 
        const Spi_ConfigType *ConfigPtr,
        uint32 SpiCoreID
    );

#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )  
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) )
static Std_ReturnType Spi_SynctransmitCheckChannelsIsValid
    (
        uint32 SpiCoreID,
        const Spi_JobConfigType *JobConfig
    );
#endif
#endif
#endif

#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_SynctransmitCheckJobsIsValid
    (
        const Spi_SequenceConfigType *SequenceConfig,
        uint32 SpiCoreID
    );
#endif /* #if (SPI_DEV_ERROR_DETECT == STD_ON)*/
    
static Std_ReturnType Spi_SyncJobsTranfer
    (
        const Spi_SequenceConfigType *SequenceConfig,
        uint32 SpiCoreID
    );
#endif /* ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )*/


#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_ChannelCheckValidity
    (
        const Spi_ChannelType Channel,
        const uint8 FunctionId
    );

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) )
static Std_ReturnType Spi_SetupEbCheckLength
    (
        const Spi_ChannelConfigType *ChannelConfig,
        Spi_NumberOfDataType Length
    );
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_AsyncTransmitCheckDemReport
    (
        uint32 SpiCoreID,
        Spi_SequenceType Sequence
    );
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) )
static Std_ReturnType Spi_AsyncTransmitCheckValidityOfChannels
    (
        uint32 SpiCoreID,
        const Spi_JobConfigType *JobConfig
    );
#endif
#endif
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_InitCheckDemError
    (
        uint32 SpiCoreID,
        const Spi_ConfigType *ConfigPtr
    );
#endif

static void Spi_InitChannelsJobsSeqsState
    (
        uint32 SpiCoreID
    );
    
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static void Spi_InitJobsList
    (
        uint32 HWUnit
    );
#endif

#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_SyncTransmitCheckDemReport
    (
        uint32 SpiCoreID,
        Spi_SequenceType Sequence
    );
#endif
#endif

static Spi_StatusType Spi_GetStatusAsyncCheckHwBusy
    (
        uint32 SpiCoreID
    );

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))    
static Std_ReturnType Spi_LockJobsProcess
    (
        Spi_SequenceType SequenceId,
        const Spi_SequenceConfigType *Sequence,
        Spi_JobType JobCount
    );
#endif

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static inline void Spi_DemReportStatus
    (
        uint32 SpiCoreID,
        Dem_EventStatusType EventStatus
    );
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    #if ( ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) || (SPI_HW_STATUS_API == STD_ON) )
static Std_ReturnType Spi_HWUnitCheckValidity
    (
        const Spi_HWUnitType HWUnit,
        const uint8 FunctionId
    );
    #endif /* ( ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) || (SPI_HW_STATUS_API == STD_ON) ) */
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    #if ( ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) || (SPI_HW_STATUS_API == STD_ON) )
/**
* @brief   This function check valid of HWUnit input
*
* @param[in]     HWUnit         The hardware Peripheral
* @param[in]     FunctionId     The Function Id to report error
* @param[out]    Std_ReturnType
* @retval E_OK      No error was reported
* @retval E_NOT_OK  Error was reported
*
*/
static Std_ReturnType Spi_HWUnitCheckValidity
    (
        const Spi_HWUnitType HWUnit,
        const uint8 FunctionId
    )
{
    Std_ReturnType Status = (Std_ReturnType) E_NOT_OK;
    uint32 SpiCoreID = Spi_GetCoreID;

    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_UNINIT);

    }
    else if (HWUnit >= SPI_MAX_HWUNIT)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_UNIT);
    }
    /* Check core has assigned for sequence */
    else if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig)
    {
        /* Call Det_ReportError for wrong core */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_CONFIG);
    }
    else if (SpiCoreID != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->SpiCoreUse)
    {
        /* Call Det_ReportError for wrong core */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_CONFIG);
    }
    else
    {
        Status = (Std_ReturnType)E_OK;
    }

    return Status;
}
    #endif /* ( ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) || (SPI_HW_STATUS_API == STD_ON) ) */
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

/**
* @brief   This function report production error SPI_E_HARDWARE_ERROR to DEM.
*
* @param[in]     ReportStatus       Specifies the Event status
* @param[out]    void
*
*/
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static inline void Spi_DemReportStatus
    (
        uint32 SpiCoreID,
        Dem_EventStatusType EventStatus
    )
{
    /* Call Dem_SetEventStatus. */
    if ((uint32)STD_ON == Spi_apxSpiConfigPtr[SpiCoreID]->SpiErrorHardwareCfg.state)
    {
        (void)Dem_SetEventStatus((Dem_EventIdType)Spi_apxSpiConfigPtr[SpiCoreID]->SpiErrorHardwareCfg.id, EventStatus);
    }
    else
    {
        /* Do nothing */
    }
}
#endif

/**
* @brief   This function checks parameters for initialization of SPI driver.
* @details This function checks parameters for initialization of SPI driver.
*
* @param[in]     ConfigPtr       Specifies the pointer to the configuration set
* @param[out]    CheckStatus      Specifies status of checking
*               - E_OK: The parameters are valid
*               - E_NOT_OK: The parameters are invalid
*
*/
static inline Std_ReturnType Spi_CheckInit
    ( 
        const Spi_ConfigType *ConfigPtr,
        uint32 SpiCoreID
    )
{
    Std_ReturnType CheckStatus = (Std_ReturnType)E_OK;
#if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
    uint32 Channel;
    uint32 Job;
    uint32 Sequence;
#endif

#if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
    /* Configuration sizes must be checked for Post Build & Link Time configurations */
    Channel  = (uint32)(ConfigPtr->SpiMaxChannel);
    Job      = (uint32)(ConfigPtr->SpiMaxJob);
    Sequence = (uint32)(ConfigPtr->SpiMaxSequence);

    if ((Channel >= SPI_MAX_CHANNEL) || (Job >= SPI_MAX_JOB) || (Sequence >= SPI_MAX_SEQUENCE))
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_CONFIG_OUT_OF_RANGE);
#endif
    }
    if (SpiCoreID != ConfigPtr->SpiCoreUse)
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_PARAM_CONFIG);
#endif
    }
#else /* (SPI_CONFIG_VARIANT == SPI_VARIANT_PRECOMPILE) */
    (void)ConfigPtr;
    if ( NULL_PTR == Spi_PBCfgVariantPredefined[SpiCoreID] )
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_INVALID_POINTER);
#endif
    }
#endif /* (SPI_PRECOMPILE_SUPPORT == STD_OFF) */

    return CheckStatus;
}

/**
* @brief   This function returns the status of the SPI driver related to async HW Units.
* @details Return SPI_BUSY if at least one async HW unit is busy.
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The driver is un-initialized  ->TBD pare ca nu se poate indeplini aceast status
* @retval SPI_IDLE    The driver has no pending transfers
* @retval SPI_BUSY    The driver is busy
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL2.
*/
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL2)
static inline Spi_StatusType Spi_GetAsyncStatus(void)
{
    Spi_StatusType StatusFlag = SPI_IDLE;
    Spi_HWUnitType HWUnit;
    uint32 SpiCoreID;

    SpiCoreID = Spi_GetCoreID;

    if(NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID])
    {
        for (HWUnit = 0u; HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT; HWUnit++)
        {
            if ((NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig) &&
                (SpiCoreID == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->SpiCoreUse)
               )
            {
                if ((SPI_BUSY == Spi_axSpiHwUnitQueueArray[HWUnit].Status) &&
                    (SPI_PHYUNIT_ASYNC_U32 == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IsSync))
                {
                    StatusFlag = SPI_BUSY;
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    else
    {
        /* Do nothing */
    }
    return StatusFlag;
}
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL2) */

/**
* @brief   This function is called in order to mark the jobs of a sequence as ready to be transmitted.
* @details For each job in sequence, the function checks if it is already
*          linked to another pending sequence.
*          If at least one job is already linked, the function returns E_NOT_OK.
*          Elsewhere, all jobs in sequence are locked (linked to the current
*          sequence)
*
* @param[in]      Sequence        The sequence ID.
* @param[in]      Sequence       The sequence configuration.
*
* @return Std_ReturnType
* @retval E_OK       The given sequence does not share its jobs with some
*                    other sequences, and all its jobs were successfully
*                    locked.
* @retval E_NOT_OK  The given sequence shares its jobs with some other
*                   sequences. No lock performed for its jobs.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static Std_ReturnType Spi_LockJobs
    (
        Spi_SequenceType SequenceId,
        const Spi_SequenceConfigType *Sequence
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_JobType JobCount = Sequence->NumJobs;
    const Spi_JobType *Jobs = Sequence->JobIndexList;
    Spi_JobStateType *JobState;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_03();
    /* Use an optimized implementation for one job sequences */
    if (1u == JobCount)
    {
        JobState = &Spi_axSpiJobState[*Jobs];
        if (NULL_PTR == JobState->AsyncCrtSequenceState)
        {
            /* Job not yet linked => link it to the current sequence */
            JobState->AsyncCrtSequenceState = &Spi_axSpiSequenceState[SequenceId];
        }
        else
        {
            /* The job is already locked by a pending sequence */
            Status = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        Status = Spi_LockJobsProcess(SequenceId, Sequence, JobCount);
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03();
    
    return Status;
}
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */

/**
* @brief   This function is called to release the jobs at the end of an async sequence transmission.
* @details Mark the linked sequence for all jobs as NULL_PTR.
*
* @param[in]      RemainingJobs    The starting job
* @param[in]      Sequence        The sequence configuration
*
* @pre  Pre-compile parameter SPI_CANCEL_API shall be STD_ON.
*
*/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static inline void Spi_UnlockRemainingJobs
    (
        Spi_JobType RemainingJobs,
        const Spi_SequenceConfigType *Sequence
    )
{
    Spi_JobType NumJobsInSeq = Sequence->NumJobs;
    Spi_JobType JobIdx;
    
    /* Mark the linked sequence for all jobs as NULL_PTR */
    for (JobIdx = NumJobsInSeq-RemainingJobs; JobIdx < NumJobsInSeq; JobIdx++)
    {
        MCAL_DATA_SYNC_BARRIER();
        Spi_axSpiJobState[Sequence->JobIndexList[JobIdx]].AsyncCrtSequenceState = NULL_PTR;
        MCAL_DATA_SYNC_BARRIER();
    }
}
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2) */

/**
* @brief   This function will schedule a job for a given HW unit.
* @details If the HWUnit is not busy, the transfer is started and the HW unit is
*          marked as busy.
*          If the HWUnit is not busy (another job is in progress), the new job is
*          scheduled in a waiting job list, according to its priority.
*
* @param[in]      HWUnitQueue     HW Unit to be used by the job
* @param[in]      Job             ID of the scheduled job
* @param[in]      JobConfig      Configuration of the scheduled job
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static inline void Spi_ScheduleJob
    (
        Spi_HWUnitQueue *HWUnitQueue,
        Spi_JobType Job,
        const Spi_JobConfigType *JobConfig
    )
{
    sint8 Priority;
    Spi_JobType *JobListTail;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
    if (SPI_IDLE == HWUnitQueue->Status)
    {
        /* idle unit => the job can be started */
        HWUnitQueue->Status = SPI_BUSY;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();

        /* mark the job as pending */
        Spi_axSpiJobState[Job].Result = SPI_JOB_PENDING;
        HWUnitQueue->Channel = 0;
        HWUnitQueue->Job = Job;
        Spi_Ipw_JobTransfer(JobConfig);
    }
    else
    {
        /* add the job to the scheduling corresponding queue */

        /* retrieve the tail of the scheduling queue for the job priority */
        Priority = JobConfig->Priority;
        JobListTail = &HWUnitQueue->ScheduledJobsListTail[Priority];

        if (SPI_JOB_NULL == *JobListTail)
        {
            /* the list is empty => set also the head of the list */
            HWUnitQueue->ScheduledJobsListHead[Priority] = Job;
        }
        else
        {
            /* add the item at the end of the list */
            Spi_axSpiJobState[*JobListTail].AsyncNextJob = Job;
        }

        /* set the new tail of the list */
        *JobListTail = Job;

        /* the new item will be the last element in the list */
        Spi_axSpiJobState[Job].AsyncNextJob = SPI_JOB_NULL;

        if (HWUnitQueue->MaxScheduledPriority < Priority)
        {
            HWUnitQueue->MaxScheduledPriority = Priority;
        }
        else
        {
            /* Do nothing */
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2) ) */

#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) )
/**
* @brief   This function will check validation of channels in a jobs in Synchronous mode.
* @details This function will check validation of channels in a jobs in Synchronous mode.
*
* @param[in]      SequenceConfig     The sequence configuration
* @param[in]      SpiCoreID         ID of Core
*
* @retval E_OK      No invalid configuration was found.
* @retval E_NOT_OK  The HWUnit which are assigning to the job is Async mode Or the buffer of channel is EB so Lenght is 0.
*
* @pre  This function will be called by Spi_Synctransmit()
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL0 or SPI_LEVEL2
*/
static Std_ReturnType Spi_SynctransmitCheckChannelsIsValid
    (
        uint32 SpiCoreID,
        const Spi_JobConfigType *JobConfig
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_ChannelType ChannelID;
    Spi_ChannelType ChannelIndex;
    Spi_ChannelType NumChannelsInJob = JobConfig->NumChannels;
    
    for(ChannelIndex=(Spi_ChannelType)0;ChannelIndex < NumChannelsInJob; ChannelIndex++)
    {
        ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
        if (EB == Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[ChannelID].ChannelCfg->BufferType)
        {
            /* Channel length is 0 for unconfigured ext. buffers */
            if (0U == Spi_axSpiChannelState[ChannelID].Length)
            {
                /* An used EB not initialized  */
                (void)Det_ReportError((uint16) SPI_MODULE_ID, (uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_EB_UNIT);
                Status = (Std_ReturnType)E_NOT_OK;
                break;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    return Status;
}
#endif
#endif
#endif

#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function will check validation of jobs in a sequence in Synchronous mode.
* @details This function will check validation of jobs in a sequence in Synchronous mode.
*
* @param[in]      SequenceConfig     The sequence configuration
* @param[in]      SpiCoreID         ID of Core
*
* @retval E_OK      No invalid configuration was found.
* @retval E_NOT_OK  The HWUnit which are assigning to the job is Async mode Or the buffer of channel is EB so Lenght is 0.
*
* @pre  This function will be called by Spi_Synctransmit()
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL0 or SPI_LEVEL2
*/
static Std_ReturnType Spi_SynctransmitCheckJobsIsValid
    (
        const Spi_SequenceConfigType *SequenceConfig,
        uint32 SpiCoreID
    )
{
    Spi_JobType NumJobsInSequence;
    Spi_JobType Job;
    Spi_JobType JobIndex;
    Spi_HWUnitType HWUnit;
    const Spi_JobConfigType *JobConfig;
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    uint32 UnitIsSync;
    /* Get the number of jobs in the sequence */
    NumJobsInSequence = SequenceConfig->NumJobs;
    for (JobIndex = 0u; JobIndex < NumJobsInSequence; JobIndex++)
    {
        /* Get the job id */
        Job = SequenceConfig->JobIndexList[JobIndex];
        JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg;
        /* Logical Spi HWUnit */
        HWUnit = JobConfig->HWUnit;
        UnitIsSync = Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IsSync;
        if ((uint32)(SPI_PHYUNIT_ASYNC_U32) == (UnitIsSync))
        {
            /* HwUnit is not prearranged for dedicated Synchronous
               transmission */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_UNIT);
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Do nothing */
        }
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) )
        if ((Std_ReturnType)E_OK == Status)
        {
            /* Check if all EBs have been setup */
            Status = Spi_SynctransmitCheckChannelsIsValid(SpiCoreID, JobConfig);
        }
        else
        {
            /* Do nothing */
        }
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) ) */
        if ((Std_ReturnType)E_NOT_OK == Status)
        {
            /* break */
            break;
        }
        else
        {
            /* Do nothing */
        }
    }
    return Status;
}

#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/
/**
* @brief   This function transmit Jobs in a sequence by Synctransmit mode.
* @details This function transmit Jobs in a sequence by Synctransmit mode.
*
* @param[in]      SequenceConfig     The sequence configuration.
* @param[in]      SpiCoreID         ID of Core
* @return Std_ReturnType
* @retval E_OK      Transmission command has been completed successfully
* @retval E_NOT_OK  Transmission command has not been accepted
*
* @pre  This function will be called by Spi_Synctransmit()
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL0 or SPI_LEVEL2
*
*/
static Std_ReturnType Spi_SyncJobsTranfer
    (
        const Spi_SequenceConfigType *SequenceConfig,
        uint32 SpiCoreID
    )
{
    Spi_JobType JobsCount;
    const Spi_JobType *JobIndexList;
    Spi_JobType Job;
    Spi_JobStateType *JobState;
    const Spi_JobConfigType *JobConfig;
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    
    /* Get the number of jobs in the sequence */
    JobsCount = SequenceConfig->NumJobs;
    JobIndexList = SequenceConfig->JobIndexList;
    while (0u < JobsCount)
    {
        /* Get the job id */
        Job = *JobIndexList;
        /* Set the job status as pending */
        JobState = &Spi_axSpiJobState[Job];
        JobState->Result = SPI_JOB_PENDING;
        JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg;
        
        /* start job notification to assert the non-cs pin,
        when non-cs pin is used as chipselect*/
        if (NULL_PTR != JobConfig->StartNotification)
        {
            JobConfig->StartNotification();
        }
        else
        {
            /* Do nothing */
        }
        /* Mark HWUnit as busy */
        Spi_axSpiHwUnitQueueArray[JobConfig->HWUnit].Status = SPI_BUSY;
        
        Status = Spi_Ipw_SyncTransmit(JobConfig, SpiCoreID);
        
        /* release HWUnit */
        Spi_axSpiHwUnitQueueArray[JobConfig->HWUnit].Status = SPI_IDLE;
        
        if ((Std_ReturnType)E_OK == Status)
        {
            /* Job is done set the status as OK */
            JobState->Result = SPI_JOB_OK;
            /* Perform job EndNotification (if there is one) */
            if (NULL_PTR != JobConfig->EndNotification)
            {
                JobConfig->EndNotification();
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* transmission failed */
            /* set the remaining job status (including the current one) as FAILED */
            do
            {
                /* Set the job status as FAILED */
                Spi_axSpiJobState[*JobIndexList].Result = SPI_JOB_FAILED;
                /* Update pointer position for JobConfig */
                JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[*JobIndexList].JobCfg;
                /* Perform job EndNotification (if there is one) */
                if (NULL_PTR != JobConfig->EndNotification)
                {
                    JobConfig->EndNotification();
                }
                else
                {
                    /* Do nothing */
                }
                JobIndexList++;
                JobsCount--;
            } while (0u < JobsCount);
            JobsCount = 1u;  /* needed to end correctly the outer loop */
        }
        /* iterate to next job in sequence */
        JobIndexList++;
        JobsCount--;
    } /* while (JobsCount > 0u) */
    return Status;
}
#endif /* ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )*/

#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function check valid for input Channel.
* @details This function check valid for input Channel.
*
* @param[in]      Channel              ID channel
* @param[in]      FunctionId           Function Id to report error
* @return Std_ReturnType
* @retval E_OK      No error was reported
* @retval E_NOT_OK  Error was reported
*
*
*/
static Std_ReturnType Spi_ChannelCheckValidity
    (
        const Spi_ChannelType Channel,
        const uint8 FunctionId
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    uint32 SpiCoreID = Spi_GetCoreID;

    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Channel ID - Valid channels range is from 0 to SpiMaxChannel*/
    else if (Channel > Spi_apxSpiConfigPtr[SpiCoreID]->SpiMaxChannel)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_CHANNEL);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Check core has assigned for this channel */
    else if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[Channel].ChannelCfg)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_CONFIG);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else if (SpiCoreID != Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[Channel].ChannelCfg->SpiCoreUse)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, FunctionId, SPI_E_PARAM_CONFIG);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    return Status;
}
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) )
#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function check valid for input parameters Length and CoreId.
* @details This function check valid for input parameters Length and CoreId.
*
* @param[in]      SpiCoreID         ID of Core
* @param[in]      Channel              ID channel
* @param[in]      Length               Number of bytes 
* @return Std_ReturnType
* @retval E_OK      No error was reported
* @retval E_NOT_OK  Error was reported
*
*
*/

/**
* @brief   This function transmit Jobs in a sequence by Synctransmit mode.
* @details This function transmit Jobs in a sequence by Synctransmit mode.
*
* @param[in]      ChannelConfig      Channel configuration
* @param[in]      Length               Number of bytes 
* @return none
*
*
*/
static Std_ReturnType Spi_SetupEbCheckLength
    (
        const Spi_ChannelConfigType *ChannelConfig,
        Spi_NumberOfDataType Length
    )
{
    Spi_NumberOfDataType SurplusLength;
    Spi_NumberOfDataType LengthCheck = Length;
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    
    if ((ChannelConfig->FrameSize > 8u) && (ChannelConfig->FrameSize < 17u))
    {
        SurplusLength = (Spi_NumberOfDataType)(LengthCheck%2u);
        /* If number of bytes of channel is not divisible by 2 then the surplus bytes will be lost */
        if (0u != SurplusLength)
        {
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID,SPI_E_PARAM_LENGTH);
            Status = (Std_ReturnType)E_NOT_OK;
        }
    }
    else if ((ChannelConfig->FrameSize > 16u) && (ChannelConfig->FrameSize < 33u))
    {
        SurplusLength = (Spi_NumberOfDataType)(LengthCheck%4u);
        /* If number of bytes of channel is not divisible by 4 then the surplus bytes will be lost */
        if (0u != SurplusLength)
        {
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID,SPI_E_PARAM_LENGTH);
            Status = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        /* Do nothing */
    }
    return Status;
}
#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/
#endif /* ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) ) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function check the initialization of driver and sequence ID is compatible.
* @details This function check the initialization of driver and sequence ID is compatible.
*
* @param[in]      SpiCoreID      CoreID
* @param[in]      Sequence          Sequence ID 
* @return Std_ReturnType
* @retval E_OK      No error was reported
* @retval E_NOT_OK  Error was reported
*
*
*/
static Std_ReturnType Spi_AsyncTransmitCheckDemReport
    (
        uint32 SpiCoreID,
        Spi_SequenceType Sequence
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Sequence Valid Range */
    else if (Sequence > (Spi_apxSpiConfigPtr[SpiCoreID]->SpiMaxSequence))
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_SEQ);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }
    return Status;
}
#endif /*((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))*/
#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) )
/**
* @brief   Check channel with EB buffer.
* @details Check channel with EB buffer.
*
* @param[in]      SpiCoreID      ID of core
* @param[in]      JobConfig       Job configuration 
* @return Std_ReturnType
*
*
*/
static Std_ReturnType Spi_AsyncTransmitCheckValidityOfChannels
    (
        uint32 SpiCoreID,
        const Spi_JobConfigType *JobConfig        
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_ChannelType ChannelID;
    Spi_ChannelType NumChannelsInJob;
    Spi_ChannelType ChannelIndex;
    
    /* Check if all EBs have been setup */
    NumChannelsInJob = JobConfig->NumChannels;
    for(ChannelIndex=(Spi_ChannelType)0;ChannelIndex < NumChannelsInJob; ChannelIndex++)
    {
        ChannelID = JobConfig->ChannelIndexList[ChannelIndex];
        if (EB == Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[ChannelID].ChannelCfg->BufferType)
        {
            /* Length is 0 for unconfigured ext. buffers */
            if (0U == Spi_axSpiChannelState[ChannelID].Length)
            {
                /* An used EB not initialized  */
                (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_EB_UNIT);
                Status = (Std_ReturnType)E_NOT_OK;
                break;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    return Status;
}
#endif /* #if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) ) */
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */
#endif /* #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)) */


#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   Check Dem report error in Init function.
* @details Check Dem report error in Init function.
*
* @param[in]      SpiCoreID      ID of core
* @return Std_ReturnType
*
*
*/
static Std_ReturnType Spi_InitCheckDemError
    (
        uint32 SpiCoreID,
        const Spi_ConfigType *ConfigPtr        
    )
{
    Std_ReturnType CheckStatus = (Std_ReturnType)E_OK;
    
    if (NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_ALREADY_INITIALIZED);
        CheckStatus = (Std_ReturnType)E_NOT_OK;
    }
    #if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
    else if (NULL_PTR == ConfigPtr)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_INIT_FAILED);
        CheckStatus = (Std_ReturnType)E_NOT_OK;
    }
    #else /* (SPI_CONFIG_VARIANT == SPI_VARIANT_PRECOMPILE) */
    else if (NULL_PTR != ConfigPtr)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_INIT_FAILED);
        CheckStatus = (Std_ReturnType)E_NOT_OK;
    }
    #endif /*(SPI_PRECOMPILE_SUPPORT == STD_OFF)*/
    else 
    {
        /* Do nothing */
    }
    return CheckStatus;
}
#endif

/**
* @brief   This function initiate channels, jobs, sequences state.
* @details This function initiate channels, jobs, sequences state.
*
* @param[in]      SpiCoreID      ID of core
* @return None
*
*
*/
static void Spi_InitChannelsJobsSeqsState
    (
        uint32 SpiCoreID      
    )
{
    uint32 Channel;
    uint32 Job;
    uint32 Sequence;
#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
    Spi_HWUnitType HWUnit;
#endif
#endif
    const Spi_ChannelConfigType *ChannelConfig;
    const Spi_JobConfigType *JobConfig;
    const Spi_SequenceConfigType *SequenceConfig;
    
    for (Channel = 0u;
        Channel <= (uint32)(Spi_apxSpiConfigPtr[SpiCoreID]->SpiMaxChannel);
        Channel++)
    {
        ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[Channel].ChannelCfg;
        /* Check which channel has assigned for current core */
        if((NULL_PTR != ChannelConfig) && (SpiCoreID == ChannelConfig->SpiCoreUse))
        {
            /* Check if configured buffers are External (EB) */
            if (EB == ChannelConfig->BufferType)
            {
                /* Initialize all buffers */
                ChannelConfig->BufferDescriptor->ExternalBufferTX = NULL_PTR;
                ChannelConfig->BufferDescriptor->BufferRX = NULL_PTR;
    
                /* Channel length is zero for unconfigured external buffers */
                Spi_axSpiChannelState[Channel].Length = (Spi_NumberOfDataType) 0;
            }
            else
            {
                /* Setup channel length according to configuration */
                Spi_axSpiChannelState[Channel].Length = ChannelConfig->Length;
            }
            Spi_axSpiChannelState[Channel].Flags = SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
        }
    }
    
    /* initialize job results */
    for (Job = 0u;
        Job <= (uint32)( Spi_apxSpiConfigPtr[SpiCoreID]->SpiMaxJob);
        Job++)
    {
        JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg;
        if((NULL_PTR != JobConfig) && (SpiCoreID == JobConfig->SpiCoreUse))
        {
            Spi_axSpiJobState[Job].Result = SPI_JOB_OK;
        #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
            /* mark the job as unlocked / not linked to a pending async sequence */
            Spi_axSpiJobState[Job].AsyncCrtSequenceState = NULL_PTR;
        #endif
        }
    }
    
    for (Sequence = 0u;
        Sequence <= (uint32)(Spi_apxSpiConfigPtr[SpiCoreID]->SpiMaxSequence);
        Sequence++)
    {
        SequenceConfig = Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig;
        if ((NULL_PTR != SequenceConfig) && (SpiCoreID == SequenceConfig->SpiCoreUse))
        {
            #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
            SequenceConfig = Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig;
            Spi_axSpiSequenceState[Sequence].Sequence = SequenceConfig;
            #endif
    
            /* initialize sequence results */
            Spi_axSpiSequenceState[Sequence].Result = SPI_SEQ_OK;
    
            #if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
            #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
            SequenceConfig = Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig;
            /* initialize the map of used HWUnits per sequence */
            Spi_au32SpiSeqUsedHWUnits[Sequence] = (uint32)0;
    
            for (Job = 0u; Job < SequenceConfig->NumJobs; Job++)
            {
                HWUnit = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[SequenceConfig->JobIndexList[Job]].JobCfg->HWUnit;
    
                Spi_au32SpiSeqUsedHWUnits[Sequence] |=
                    (uint32)((uint32)1 << (HWUnit));
            }
            #else /* (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF) */
            /* SPI135: Spi_SyncTransmit() must fail if an other sync transmission
                    is ongoing.*/
            /* mark all HW units as used by the sync transmission, in order to
                force the mutual exclusion of Spi_SyncTransmit() calls */
    
            Spi_au32SpiSeqUsedHWUnits[Sequence] = 0xFFFFFFFFU;
            #endif /* (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF) */
            #endif /* ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) ) */
    
        }
        else
        {
            /* Do nothing */
        }
    }
}

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief   This function initiate the jobs list.
* @details This function initiate the jobs list.
*
* @param[in]      HWUnit      The HW peripheral
* @return None
*
*
*/
static void Spi_InitJobsList
    (
        uint32 HWUnit      
    )
{
    sint8 Priority;
    
    /* initialize the Job lists => no scheduled job for the unit */
    for (Priority = 0; Priority < SPI_JOB_PRIORITY_LEVELS_COUNT; Priority++)
    {
        Spi_axSpiHwUnitQueueArray[HWUnit].ScheduledJobsListHead[Priority] = SPI_JOB_NULL;
        Spi_axSpiHwUnitQueueArray[HWUnit].ScheduledJobsListTail[Priority] = SPI_JOB_NULL;
    }
    
    /* no scheduled job => MaxScheduledPriority is -1 */
    Spi_axSpiHwUnitQueueArray[HWUnit].MaxScheduledPriority = -1;
}
#endif

#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function check the initialization of driver and sequence ID is compatible in Synchronous mode.
* @details This function check the initialization of driver and sequence ID is compatible in Synchronous mode.
*
* @param[in]      SpiCoreID      CoreID
* @param[in]      Sequence          Sequence ID 
* @return Std_ReturnType
* @retval E_OK      No error was reported
* @retval E_NOT_OK  Error was reported
*
*
*/
static Std_ReturnType Spi_SyncTransmitCheckDemReport
    (
        uint32 SpiCoreID,
        Spi_SequenceType Sequence
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0, SPI_SYNCTRANSMIT_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Sequence Valid Range */
    else if (Sequence > Spi_apxSpiConfigPtr[SpiCoreID]->SpiMaxSequence)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_SEQ);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Verify the core has assigned for sequence */
    else if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig)
    {
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_CONFIG); 
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else if (SpiCoreID != Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig->SpiCoreUse)
    {
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_CONFIG); 
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /*Do nothing */
    }
    return Status;
}
#endif
#endif

/**
* @brief   Check for busy HWUnit in async transmissions.
* @details Check for busy HWUnit in async transmissions.
*
* @param[in]      SpiCoreID      CoreID
* @return Spi_StatusType
*
*
*/
static Spi_StatusType Spi_GetStatusAsyncCheckHwBusy
    (
        uint32 SpiCoreID
    )
{
    Spi_StatusType StatusFlag = SPI_IDLE;
    Spi_HWUnitType HWUnit;
    
    for (HWUnit = 0u; HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT; HWUnit++)
    {
        if ((NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig) &&
            (SpiCoreID == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->SpiCoreUse)
           )
        {
            if (SPI_BUSY == Spi_axSpiHwUnitQueueArray[HWUnit].Status)
            {
                StatusFlag = SPI_BUSY;
                break;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    return StatusFlag;
}

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief   This function is called in order to mark the jobs of a sequence as ready to be transmitted.
* @details For each job in sequence, the function checks if it is already
*          linked to another pending sequence.
*          If at least one job is already linked, the function returns E_NOT_OK.
*          Elsewhere, all jobs in sequence are locked (linked to the current
*          sequence)
*
* @param[in]      Sequence        The sequence ID.
* @param[in]      JobCount        Number of job in sequence
*
* @return Std_ReturnType
* @retval E_OK       The given sequence does not share its jobs with some
*                    other sequences, and all its jobs were successfully
*                    locked.
* @retval E_NOT_OK  The given sequence shares its jobs with some other
*                   sequences. No lock performed for its jobs.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
static Std_ReturnType Spi_LockJobsProcess
    (
        Spi_SequenceType SequenceId,
        const Spi_SequenceConfigType *Sequence,
        Spi_JobType JobCount
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_JobType JobCountProcess = JobCount;
    Spi_JobStateType *JobState;
    const Spi_JobType *Jobs = Sequence->JobIndexList;
    Spi_SequenceStateType *SequenceState;

    SequenceState = &Spi_axSpiSequenceState[SequenceId];    
    while (0u < JobCountProcess)
    {
        JobState = &Spi_axSpiJobState[*Jobs];
        if (NULL_PTR == JobState->AsyncCrtSequenceState)
        {
            /* Job not yet linked => link it to the current sequence */
            JobState->AsyncCrtSequenceState = SequenceState;
        }
        else
        {
            /* The job is already locked by a pending sequence =>
               rollback all the previous locks */
            if (JobCountProcess < Sequence->NumJobs)
            {
                do
                {
                    JobCountProcess++;
                    Jobs--;
                    Spi_axSpiJobState[*Jobs].AsyncCrtSequenceState = NULL_PTR;
                }
                while (JobCountProcess < Sequence->NumJobs);
            }
            else
            {
                /* Do nothing */
            }
            Status = (Std_ReturnType)E_NOT_OK;
            break;
        }

        /* Next job */
        JobCountProcess--;
        Jobs++;
    }
    return Status;
}
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#if (SPI_VERSION_INFO_API == STD_ON)
/**
* @brief   This function returns the version information for the SPI driver.
* @details This function returns the version information for the SPI driver.
*          - Service ID:       0x09
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in,out]    VersionInfo      Pointer to where to store the version
*                                    information of this module.
*
* @pre  Pre-compile parameter SPI_VERSION_INFO_API shall be STD_ON.
*
*/
/** @implements Spi_GetVersionInfo_Activity */
void Spi_GetVersionInfo 
    (
        Std_VersionInfoType *versioninfo
    )
{
#if( SPI_DEV_ERROR_DETECT == STD_ON )
    if(NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID,(uint8)0,SPI_GETVERSIONINFO_ID,SPI_E_PARAM_POINTER);
    }
    else
    {
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
    versioninfo->vendorID = (uint16)SPI_VENDOR_ID;
    versioninfo->moduleID = (uint8)SPI_MODULE_ID;
    versioninfo->sw_major_version = (uint8)SPI_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = (uint8)SPI_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = (uint8)SPI_SW_PATCH_VERSION;
#if(SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
}
#endif /* (SPI_VERSION_INFO_API == STD_ON) */

/**
* @brief   This function initializes the SPI driver.
* @details This function initializes the SPI driver using the
*          pre-established configurations
*          - Service ID:       0x00
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in]     ConfigPtr      Specifies the pointer to the configuration set
*
*/
/** @implements Spi_Init_Activity */
void Spi_Init
    (
        const Spi_ConfigType *ConfigPtr
    )
{
    Spi_HWUnitType HWUnit;
    uint32 SpiCoreID;
    Std_ReturnType CheckStatus = (Std_ReturnType)E_OK;

    SpiCoreID = Spi_GetCoreID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    CheckStatus = Spi_InitCheckDemError(SpiCoreID, ConfigPtr);
    if ((Std_ReturnType)E_OK == CheckStatus) 
    {
#endif /*(SPI_DEV_ERROR_DETECT == STD_ON)*/

    CheckStatus = Spi_CheckInit(ConfigPtr, SpiCoreID);

    if((Std_ReturnType)E_OK == CheckStatus )
    {
    #if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
        Spi_apxSpiConfigPtr[SpiCoreID] = ConfigPtr;
    #else /* (SPI_CONFIG_VARIANT == SPI_VARIANT_PRECOMPILE) */
        Spi_apxSpiConfigPtr[SpiCoreID] = Spi_PBCfgVariantPredefined[SpiCoreID];
    #endif /* (SPI_PRECOMPILE_SUPPORT == STD_OFF) */
    /* Initiate Channels, Jobs, Sequences state */
    Spi_InitChannelsJobsSeqsState(SpiCoreID);
        
        /* initialize all physical HWUnits */
        for (HWUnit = (Spi_HWUnitType) 0;
            HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT;
            HWUnit++)
        {
            if((NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig) &&
               (SpiCoreID == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->SpiCoreUse)
              )
            {
                Spi_Ipw_Init(HWUnit, Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig);
        
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL1)
            /* handler uses interrupt mode only if LEVEL 1 is selected */
                Spi_Ipw_IrqConfig(HWUnit, SPI_INTERRUPT_MODE, SpiCoreID);
#endif            
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL2)
            /* handler uses polling mode only if LEVEL 2 is selected */
                Spi_Ipw_IrqConfig(HWUnit, SPI_POLLING_MODE, SpiCoreID);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
                /* initialize the Job lists => no scheduled job for the unit */
                Spi_InitJobsList(HWUnit);
#endif
                Spi_axSpiHwUnitQueueArray[HWUnit].Status = SPI_IDLE;
            }

        }
    }
    else
    {
        /*Do nothing. Should not enter here*/
    }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif /*(SPI_DEV_ERROR_DETECT == STD_ON)*/
}

/**
* @brief   This function de-initializes the SPI driver.
* @details This function de-initializes the SPI driver using the
*          pre-established configurations
*          - Service ID:       0x01
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @return Std_ReturnType
* @retval E_OK       de-initialisation command has been accepted
* @retval E_NOT_OK   de-initialisation command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_DeInit()
*       otherwise, the function Spi_DeInit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
* @implements Spi_DeInit_Activity
*/
Std_ReturnType Spi_DeInit(void)
{
    Std_ReturnType TempExit = (Std_ReturnType)E_OK;
    Spi_HWUnitType HWUnit;
    uint32 SpiCoreID;

    SpiCoreID = Spi_GetCoreID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_DEINIT_ID,SPI_E_UNINIT);
        TempExit = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        /* Check if Spi Status is Busy */
        if (SPI_BUSY == Spi_GetStatus())
        {
            TempExit = E_NOT_OK;
        }
        else
        {
            /* De-initialize all physical HWUnits */
            for (HWUnit = (Spi_HWUnitType) 0;
                 HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT;
                 HWUnit++)
            {
                if ((NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig) &&
                    (SpiCoreID == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->SpiCoreUse)
                   )
                {
                    Spi_Ipw_DeInit(HWUnit, SpiCoreID);
    
                    Spi_axSpiHwUnitQueueArray[HWUnit].Status = SPI_UNINIT;
                }
                else
                {
                    /* Do nothing */
                }
            }
            /* Reset configuration pointer */
            Spi_apxSpiConfigPtr[SpiCoreID] = NULL_PTR;
        }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return TempExit;
}

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE0) ||(SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) )
/**
* @brief   This function writes the given data into the buffer of a specific channel.
* @details This function writes the given data into the buffer of a specific channel.
*          - Service ID:       0x02
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Channel             Channel ID
* @param[in]      DataBufferPtr       Pointer to source data buffer
*
* @return Std_ReturnType
* @retval E_OK       Command has been accepted
* @retval E_NOT_OK   Command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_WriteIB()
*       otherwise, the function Spi_WriteIB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be SPI_USAGE0 or SPI_USAGE2.
*
*/
/** @implements Spi_WriteIB_Activity */
Std_ReturnType Spi_WriteIB
    (
        Spi_ChannelType Channel,
        const Spi_DataBufferType *DataBufferPtr
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    uint16 Index;
    Spi_ChannelStateType *ChannelState;
    const Spi_ChannelConfigType *ChannelConfig;
    Spi_DataBufferType *DataBufferDes;
    const Spi_DataBufferType *DataBufferSrc;
    uint32 SpiCoreID;
    
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    Status = Spi_ChannelCheckValidity(Channel, SPI_WRITEIB_ID);

    if ((Std_ReturnType)E_OK != Status)
    {
       /* Do nothing */
    }
    else
    {
#endif
        ChannelState = &Spi_axSpiChannelState[Channel];
        ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[Channel].ChannelCfg;

        /* exit early if this is the wrong buffer type */
        if (EB == ChannelConfig->BufferType)
        {
            Status = (Std_ReturnType)E_NOT_OK;
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_WRITEIB_ID,SPI_E_PARAM_CHANNEL);
#endif
        }
        else
        {
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_04();
            /* if DataBufferPtr is zero, then transmit default value */
            if (NULL_PTR == DataBufferPtr)
            {

                ChannelState->Flags |= SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
            }

            /* otherwise, copy data from DataBufferPtr to IB */
            else
            {
                DataBufferDes = ChannelConfig->BufferDescriptor->InternalBufferTX;
                DataBufferSrc = DataBufferPtr;
                for (Index = 0u; Index < ChannelConfig->Length; Index++)
                {
                    *DataBufferDes=*DataBufferSrc;
                    DataBufferDes++;
                    DataBufferSrc++;
                }
                ChannelState->Flags = 
                    (uint8)(ChannelState->Flags & ((uint8)(~SPI_CHANNEL_FLAG_TX_DEFAULT_U8)));
            }
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04();
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    /* Return status */
    return Status;
}
#endif


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief   This function triggers the asynchronous transmission for the given sequence.
* @details This function triggers the asynchronous transmission for the given sequence.
*          - Service ID:       0x03
*          - Sync or Async:       Asynchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Std_ReturnType
* @retval E_OK       Transmission command has been accepted
* @retval E_NOT_OK   Transmission command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_AsyncTransmit()
*       otherwise, the function Spi_AsyncTransmit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
/** @implements Spi_AsyncTransmit_Activity */
Std_ReturnType Spi_AsyncTransmit
    (
        Spi_SequenceType Sequence
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_JobType NumJobsInSequence;
    Spi_JobType JobIndex;
    Spi_JobType JobId;
    const Spi_SequenceConfigType *SequenceConfig;
    Spi_SequenceStateType *SequenceState;
    const Spi_JobConfigType *JobConfig;
    const Spi_JobType *Job;
    const Spi_JobType *JobCount;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    Spi_HWUnitType HWUnit;
#endif
    uint32 SpiCoreID;
    
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error and do nothing if driver isn't init or sequen ID is not in correct range */
    Status = Spi_AsyncTransmitCheckDemReport(SpiCoreID, Sequence);
    if ((Std_ReturnType)E_OK == Status)
    {
        /* Check core has assigned for sequence */
        if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig)
        {
            /* Has wrong core */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_CONFIG);
            Status = (Std_ReturnType)E_NOT_OK;
        } else if (SpiCoreID != Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig->SpiCoreUse)
        {
            /* Has wrong core */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_CONFIG);
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Do Nothing */
        }
#endif
        SequenceConfig = Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig;
        /* Get the number of jobs in the sequence */
        NumJobsInSequence = SequenceConfig->NumJobs;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* check for empty sequence */
        if (0u == NumJobsInSequence)
        {
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_SEQ_EMPTY);
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Do nothing */
        }
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */

        JobIndex = 0u;
        while(JobIndex < NumJobsInSequence)
        {
            /* Get the job id */
            JobId = SequenceConfig->JobIndexList[JobIndex];

            JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[JobId].JobCfg;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
            /* check for empty jobs */
            if (0u == JobConfig->NumChannels)
            {
                /* Call Det_ReportError */
                (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_JOB_EMPTY);
                Status = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }

            /* Logical Spi HWUnit */
            HWUnit = JobConfig->HWUnit;

            if (SPI_PHYUNIT_ASYNC_U32 != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IsSync)
            {
                /* HwUnit is not prearranged for dedicated Asynchronous
                   transmission */
                /* Call Det_ReportError */
                (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_UNIT);
                Status = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) )
            if ((Std_ReturnType)E_OK == Status)
            {
                /* Check the validity of EB channels */
                Status = Spi_AsyncTransmitCheckValidityOfChannels(SpiCoreID, JobConfig);
            }
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) ) */
            if ((Std_ReturnType)E_OK != Status)
            {
                /* break */
                break;
            }
            else
            {
                /* Do nothing */
            }
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */
            JobIndex++;
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        if ((Std_ReturnType)E_OK == Status)
        {
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */

            Status = Spi_LockJobs(Sequence, SequenceConfig);
            if ((Std_ReturnType)E_OK == Status)
            {
                SequenceState = &Spi_axSpiSequenceState[Sequence];
                /* Mark sequence pending */
                SequenceState->Result = SPI_SEQ_PENDING;

                /* Initialize job related information */
                SequenceState->RemainingJobs = SequenceConfig->NumJobs - 1u;
                Job = &SequenceConfig->JobIndexList[0];
                SequenceState->CurrentJobIndexPointer = Job;
                for(JobIndex = 0u; JobIndex < NumJobsInSequence; JobIndex++)
                {
                    JobCount = &SequenceConfig->JobIndexList[JobIndex];
                    Spi_axSpiJobState[*JobCount].Result = SPI_JOB_QUEUED;
                }
                /* Schedule transmission of the first job */
                JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[*Job].JobCfg;
                Spi_ScheduleJob(&Spi_axSpiHwUnitQueueArray[JobConfig->HWUnit],
                                *Job, JobConfig);
            }
            else
            {
                /* Call Det_ReportRuntimeError */
                (void)Det_ReportRuntimeError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_SEQ_PENDING);
            }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            /* Do nothing */
        }
    }
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */

    return Status;
}

#endif

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2))
/**
* @brief   This function reads the data from the buffer of a channel and puts at the memory location.
* @details This function reads the data from the buffer of a specific channel
*          and puts at the specified memory location.
*          - Service ID:       0x04
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
*
* @param[in]      Channel             Channel ID
* @param[in,out]  DataBufferPointer       Pointer to the memory location that will
*                                     be written with the data in the internal
*                                     buffer
*
* @return Std_ReturnType
* @retval E_OK      read command has been accepted
* @retval E_NOT_OK  read command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_ReadIB()
*       otherwise, the function Spi_ReadIB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be SPI_USAGE0 or SPI_USAGE2.
*
*/
/** @implements Spi_ReadIB_Activity */
Std_ReturnType Spi_ReadIB
    (
        Spi_ChannelType Channel,
        Spi_DataBufferType *DataBufferPointer
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_NumberOfDataType Index;
    const Spi_ChannelConfigType *ChannelConfig;
    Spi_DataBufferType *pDataBufferSrc;
    Spi_DataBufferType *DataBufferDes;
    uint32 SpiCoreID;
    
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    Status = Spi_ChannelCheckValidity(Channel, SPI_READIB_ID);

    if ((Std_ReturnType)E_OK != Status)
    {
        /* Do nothing */
    }
    else
    {
#endif
        ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[Channel].ChannelCfg;

        /* exit early if this is the wrong buffer type or destination
           is invalid */
        if (EB == ChannelConfig->BufferType)
        {
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_READIB_ID,SPI_E_PARAM_CHANNEL);
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else if (NULL_PTR == DataBufferPointer)
        {
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_READIB_ID,SPI_E_PARAM_CHANNEL);
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Copy Rx buffer to IB buffer */
            pDataBufferSrc = ChannelConfig->BufferDescriptor->BufferRX;
            DataBufferDes = DataBufferPointer;
            for (Index = 0u; Index < ChannelConfig->Length; Index++)
            {
                    *DataBufferDes=*pDataBufferSrc;
                    DataBufferDes++;
                    pDataBufferSrc++;
            }
        }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_USAGE2) )
/**
* @brief   This function setup an external buffer to be used by a specific channel.
* @details This function setup an external buffer to be used by a specific channel.
*          - Service ID:       0x05
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Channel             Channel ID
* @param[in]      SrcDataBufferPtr    Pointer to the memory location that will hold
*                                     the transmitted data
* @param[in]      Length              Length of the data in the external buffer
* @param[out]     DesDataBufferPtr    Pointer to the memory location that will hold
*                                     the received data
*
* @return Std_ReturnType
* @retval E_OK      Setup command has been accepted
* @retval E_NOT_OK  Setup command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_SetupEB()
*       otherwise, the function Spi_SetupEB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be SPI_USAGE1 or SPI_USAGE2.
*
*/
/** @implements Spi_SetupEB_Activity */
Std_ReturnType Spi_SetupEB
    (
        Spi_ChannelType Channel,
        const Spi_DataBufferType  *SrcDataBufferPtr,
        Spi_DataBufferType *DesDataBufferPtr,
        Spi_NumberOfDataType Length
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_ChannelStateType *ChannelState;
    const Spi_ChannelConfigType *ChannelConfig;
    uint32 SpiCoreID;

    /* get current coreID */
    SpiCoreID = Spi_GetCoreID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    Status = Spi_ChannelCheckValidity(Channel, SPI_SETUPEB_ID);

    if ((Std_ReturnType)E_OK != Status)
    {
        /* Do nothing */
    }
    /* Length - Valid range */
    else if ((Length > Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[Channel].ChannelCfg->Length) || (0u == Length))
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID, SPI_E_PARAM_LENGTH);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        ChannelState = &Spi_axSpiChannelState[Channel];
        ChannelConfig = Spi_apxSpiConfigPtr[SpiCoreID]->ChannelConfig[Channel].ChannelCfg;
        /* exit early if this is the wrong buffer type */
        if (IB == ChannelConfig->BufferType)
        {
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID,SPI_E_PARAM_CHANNEL);
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            /* Length and Framesize - aren't compatible */
            /* If 8 < Framesize =< 16: Length must be divisible by 2 */
            /* If 16 < Framesize =< 32: Length must be divisible by 4 */
            Status = Spi_SetupEbCheckLength(ChannelConfig, Length);
#endif
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_05();
            /* save the new parameters */
            ChannelConfig->BufferDescriptor->ExternalBufferTX = SrcDataBufferPtr;
            ChannelConfig->BufferDescriptor->BufferRX = DesDataBufferPtr;

            ChannelState->Length = Length;

            /* if source data pointer is zero, transmit default value */
            if (NULL_PTR == SrcDataBufferPtr)
            {
                ChannelState->Flags |= SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
            }
            else
            {
                ChannelState->Flags &= (uint8) (~SPI_CHANNEL_FLAG_TX_DEFAULT_U8);
            }

            /* if destination data pointer is zero, discard receiving data */
            if (NULL_PTR == DesDataBufferPtr)
            {
                ChannelState->Flags |= SPI_CHANNEL_FLAG_RX_DISCARD_U8;
            }
            else
            {
                ChannelState->Flags &= (uint8) (~SPI_CHANNEL_FLAG_RX_DISCARD_U8);
            }
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05();
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif

/**
* @brief   This function returns the status of the SPI driver.
* @details This function returns the status of the SPI driver.
*          - Service ID:       0x06
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The driver is un-initialized
* @retval SPI_IDLE    The driver has no pending transfers
* @retval SPI_BUSY    The driver is busy
*
* @pre  The driver needs to be initialized before calling Spi_GetStatus()
*       otherwise, the function Spi_GetStatus() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
* @implements Spi_GetStatus_Activity
*/
Spi_StatusType Spi_GetStatus(void)
{
    Spi_StatusType StatusFlag = SPI_IDLE;
    Spi_HWUnitType HWUnit;
    uint32 SpiCoreID;
    
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;

    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* If Development Error Detection is enabled, report error if not */
        /* initialized */
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSTATUS_ID,SPI_E_UNINIT);
#endif
        StatusFlag = SPI_UNINIT;
    }
    else
    {
        /* The SPI Handler Driver software module shall be busy when any
           HWUnit is busy */
        for (HWUnit = 0u; HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT; HWUnit++)
        {
            if ((NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig) &&
                (SpiCoreID == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->SpiCoreUse)
               )
            {
                if (1u == Spi_au32SpiBusySyncHWUnitsStatus[HWUnit])
                {
                    StatusFlag = SPI_BUSY;
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        /* check for busy HWUnit in async transmissions */
        if (SPI_BUSY != StatusFlag)
        {
            /* Note: Checking for IsSync attribute for HWUnit is not really needed
                 It is preferable to skip this check in order to have a more compact code
            */
            StatusFlag = Spi_GetStatusAsyncCheckHwBusy(SpiCoreID);
        }
        else
        {
            /* Do notthing */
        }
    }
    return StatusFlag;
}

/**
* @brief   This function is used to request the status of a specific job.
* @details This function is used to request the status of a specific job.
*          - Service ID:       0x07
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Job                 Job ID
*
* @return Spi_JobResultType
* @retval SPI_JOB_OK        The job ended successfully
* @retval SPI_JOB_PENDING   The job is pending
* @retval SPI_JOB_FAILED    The job has failed
*
* @pre  The driver needs to be initialized before calling Spi_GetJobResult()
*       otherwise, the function Spi_GetJobResult() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
*/
/** @implements Spi_GetJobResult_Activity */
Spi_JobResultType Spi_GetJobResult
    (
        Spi_JobType Job
    )
{
    Spi_JobResultType JobResult;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    uint32 SpiCoreID;
    
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
        JobResult = SPI_JOB_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETJOBRESULT_ID,SPI_E_UNINIT);
    }
    /* Job Valid Range - from 0 to SpiMaxJob*/
    else if (Job > Spi_apxSpiConfigPtr[SpiCoreID]->SpiMaxJob)
    {
        JobResult = SPI_JOB_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETJOBRESULT_ID,SPI_E_PARAM_JOB);
    }
    else if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg)
    {
        JobResult = SPI_JOB_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETJOBRESULT_ID,SPI_E_PARAM_CONFIG);
    }
    else if (SpiCoreID != Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg->SpiCoreUse) 
    {
        JobResult = SPI_JOB_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETJOBRESULT_ID,SPI_E_PARAM_CONFIG);
    }
    else
    {
#endif
        JobResult = Spi_axSpiJobState[Job].Result;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return JobResult;
}

/**
* @brief   This function is used to request the status of a specific sequence.
* @details This function is used to request the status of a specific sequence.
*          - Service ID:       0x08
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Spi_SeqResultType
* @retval SPI_SEQ_OK       The sequence ended successfully
* @retval SPI_SEQ_PENDING  The sequence is pending
* @retval SPI_SEQ_FAILED   The sequence has failed
*
* @pre  The driver needs to be initialized before calling Spi_GetSequenceResult()
*       otherwise, the function Spi_GetSequenceResult() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
*
*/
/** @implements Spi_GetSequenceResult_Activity */
Spi_SeqResultType Spi_GetSequenceResult
    (
        Spi_SequenceType Sequence
    )
{
    Spi_SeqResultType SequenceResult;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    uint32 SpiCoreID;
    const Spi_SequenceConfigType *SequenceConfig;
    
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;

#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
        SequenceResult = SPI_SEQ_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSEQUENCERESULT_ID,SPI_E_UNINIT);
    }
    /* Sequence Valid Range from 0 to SpiMaxSequence*/
    else if (Sequence > Spi_apxSpiConfigPtr[SpiCoreID]->SpiMaxSequence)
    {
        SequenceResult = SPI_SEQ_FAILED;
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSEQUENCERESULT_ID,SPI_E_PARAM_SEQ);
    }
    else
    {
        SequenceConfig = Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig;
        /* Check core has assigned for sequence */
        if (NULL_PTR == SequenceConfig)
        {
            SequenceResult = SPI_SEQ_FAILED;
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSEQUENCERESULT_ID,SPI_E_PARAM_CONFIG);
        }
        else if (SpiCoreID != SequenceConfig->SpiCoreUse)
        {
            SequenceResult = SPI_SEQ_FAILED;
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSEQUENCERESULT_ID,SPI_E_PARAM_CONFIG);
        }
        else
        {
#endif
           SequenceResult = Spi_axSpiSequenceState[Sequence].Result;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif

    return SequenceResult;
}

#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )

/**
* @brief   This function is used for synchronous transmission of a given sequence.
* @details This function is used for synchronous transmission of a given sequence.
*          - Service ID:       0x0a
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Std_ReturnType
* @retval E_OK      Transmission command has been completed successfully
* @retval E_NOT_OK  Transmission command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_SyncTransmit().
*       otherwise, the function Spi_SyncTransmit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL0 or SPI_LEVEL2
*
*/
/** @implements Spi_SyncTransmit_Activity */
Std_ReturnType Spi_SyncTransmit
    (
        Spi_SequenceType Sequence
    )
{
    Spi_SequenceStateType *SequenceState;
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_HWUnitType HWUnit;
    Spi_JobType JobIndex;
    const Spi_SequenceConfigType *SequenceConfig;
    Spi_JobType NumJobsInSequence;
    Spi_JobType Job;
    const Spi_JobConfigType *JobConfig;
    uint32 SpiCoreID;

    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    Status = Spi_SyncTransmitCheckDemReport(SpiCoreID, Sequence);
    if ((Std_ReturnType)E_NOT_OK != Status)
    {
        SequenceConfig = Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig;
        /* Check the validation of Job */
        Status = Spi_SynctransmitCheckJobsIsValid(SequenceConfig, SpiCoreID);

        if ((Std_ReturnType)E_NOT_OK != Status)
        {
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
            SequenceConfig = Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig;
            /* Get the number of jobs in the sequence */
            NumJobsInSequence = SequenceConfig->NumJobs;

            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_06();
            /* check if there are HW units already running */
            for (HWUnit = 0u; HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT; HWUnit++)
            {
                if (0u != ((Spi_au32SpiBusySyncHWUnitsStatus[HWUnit] << HWUnit) & Spi_au32SpiSeqUsedHWUnits[Sequence]))
                {
                    Status = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    /* Do notthing */
                }
            }
            
            if ((Std_ReturnType)E_NOT_OK != Status)
            {
                /* Set the sequence as pending */
                SequenceState = &Spi_axSpiSequenceState[Sequence];
                SequenceState->Result = SPI_SEQ_PENDING;
                /* set used HW units as busy */
                for (JobIndex = 0u; JobIndex < NumJobsInSequence; JobIndex++)
                {
                    /* Get the job id */
                    Job = SequenceConfig->JobIndexList[JobIndex];
                    JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg;
                    /* Logical Spi HWUnit */
                    HWUnit = JobConfig->HWUnit;
                    Spi_au32SpiBusySyncHWUnitsStatus[HWUnit] = 1u;
                }
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06();
                /* Transmit Jobs */
                Status = Spi_SyncJobsTranfer(SequenceConfig, SpiCoreID);
                
                if ((Std_ReturnType)E_OK == Status)
                {
                    /* Set the sequence as OK */
                    SequenceState->Result = SPI_SEQ_OK;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    /* Report to DEM */
                    Spi_DemReportStatus(SpiCoreID, DEM_EVENT_STATUS_PASSED);
#endif
                }
                else
                {
                    /* Set the sequence as FAILED */
                    SequenceState->Result = SPI_SEQ_FAILED;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    /* Report to DEM */
                    Spi_DemReportStatus(SpiCoreID, DEM_EVENT_STATUS_FAILED);
#endif
                }
                
                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_07();
                /* set used HW units as idle */
                for (JobIndex = 0u; JobIndex < NumJobsInSequence; JobIndex++)
                {
                    /* Get the job id */
                    Job = SequenceConfig->JobIndexList[JobIndex];
                    JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg;
                    /* Logical Spi HWUnit */
                    HWUnit = JobConfig->HWUnit;
                    Spi_au32SpiBusySyncHWUnitsStatus[HWUnit] = 0u;
                }
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07();
                
                /* End Sequence Notification */
                if (NULL_PTR != SequenceConfig->EndNotification)
                {
                    SequenceConfig->EndNotification();
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06();
#if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) )
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
                /* Call Det_ReportRuntimeError */
                (void)Det_ReportRuntimeError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_SEQ_IN_PROCESS);
#endif
#endif
            }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            /* Do nothing */
        }
    }
#endif

    return Status;
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL2) || (SPI_LEVEL_DELIVERED == SPI_LEVEL0) ) */


#if (SPI_HW_STATUS_API == STD_ON)
/**
* @brief   This function is used to request the status of a specific SPI peripheral unit.
* @details This function is used to request the status of a specific SPI peripheral unit.
*          - Service ID:       0x0b
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      HWUnit              The HW peripheral for which we need the status
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The peripheral is un-initialized
* @retval SPI_IDLE    The peripheral is in idle state
* @retval SPI_BUSY    The peripheral is busy
*
* @pre  The driver needs to be initialized before calling Spi_GetHWUnitStatus()
*       otherwise, the function Spi_GetHWUnitStatus() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  SPI_HW_STATUS_API == STD_ON
*
*/
/** @implements Spi_GetHWUnitStatus_Activity */
Spi_StatusType Spi_GetHWUnitStatus
    (
        Spi_HWUnitType HWUnit
    )
{
    Spi_StatusType Status = SPI_UNINIT;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    if ((Std_ReturnType)E_OK != Spi_HWUnitCheckValidity(HWUnit, SPI_GETHWUNITSTATUS_ID))
    {
        /* Do nothing */
    }
    else
    {
#endif
        Status = Spi_axSpiHwUnitQueueArray[HWUnit].Status;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return Status;
}
#endif

#if (SPI_CANCEL_API == STD_ON)
/**
* @brief   This function is used to request the cancelation of the given sequence.
* @details This function is used to request the cancelation of the given sequence.
*          - Service ID:       0x0c
*          - Sync or Async:       Asynchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @pre  The driver needs to be initialized before calling Spi_Cancel()
*       otherwise, the function Spi_Cancel() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CANCEL_API shall be STD_ON
* @post  The SPI Handler Driver is not responsible on external devices damages or
*       undefined state due to cancelling a sequence transmission.
*
*/
/**  @implements Spi_Cancel_Activity */
void Spi_Cancel(Spi_SequenceType Sequence)
{
#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_LEVEL0))
    const Spi_JobConfigType *JobConfig;
#endif
#if (((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_LEVEL0)) \
    || (SPI_DEV_ERROR_DETECT == STD_ON))
    const Spi_SequenceConfigType *SequenceConfig;
    uint32 SpiCoreID;

    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;
#endif      
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_CANCEL_ID,SPI_E_UNINIT);
    }
    /* Sequence Valid Range  from 0 to SpiMaxSequence*/
    else if (Sequence > Spi_apxSpiConfigPtr[SpiCoreID]->SpiMaxSequence)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_CANCEL_ID,SPI_E_PARAM_SEQ);
    }
    else
    {
#endif
#if (((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_LEVEL0)) \
    || (SPI_DEV_ERROR_DETECT == STD_ON))
        SequenceConfig = Spi_apxSpiConfigPtr[SpiCoreID]->SequenceConfig[Sequence].SeqConfig;
#endif
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Check core has assigned for sequence */
        if (NULL_PTR == SequenceConfig)
        {
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_CANCEL_ID,SPI_E_PARAM_CONFIG);
        }
        else if (SpiCoreID != SequenceConfig->SpiCoreUse)
        {
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_CANCEL_ID,SPI_E_PARAM_CONFIG);
        }
        else
        {
#endif
            /* Set sequence state to Cancel */
            Spi_axSpiSequenceState[Sequence].Result = SPI_SEQ_CANCELLED;
    
            /* In Slave mode: Stop sequence immediately */
            #if (SPI_SLAVE_SUPPORT == STD_ON)
            #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
            JobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[SequenceConfig->JobIndexList[0u]].JobCfg;
            Spi_Ipw_SlaveCancel(JobConfig);
            #endif /* #if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2) ) */
            #endif
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}
#endif

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL2)
/**
* @brief   This function specifies the asynchronous mode for the SPI busses handled asynchronously.
* @details This function specifies the asynchronous mode for the SPI busses
*          handled asynchronously.
*          - Service ID:       0x0d
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in]      Mode         This parameter specifies the asynchronous
*                              operating mode (SPI_POLLING_MODE or
*                              SPI_INTERRUPT_MODE)
*
* @return Std_ReturnType
* @retval E_OK      The command ended successfully
* @retval E_NOT_OK  The command has failed
*
* @pre  The driver needs to be initialized before calling Spi_SetAsyncMode()
*       otherwise, the function Spi_SetAsyncMode() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL2
*
*/
/** @implements Spi_SetAsyncMode_Activity */
Std_ReturnType Spi_SetAsyncMode
    (
        Spi_AsyncModeType Mode
    )
{
    Spi_HWUnitType HWUnit;
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    uint32 SpiCoreID;
    
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETASYNCMODE_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        if (SPI_BUSY == Spi_GetAsyncStatus())
        {
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* set the async mode for each HW Unit;
               activate/deactivate EOQ interrupts for Async HWUnits */
            for (HWUnit = 0u; HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT; HWUnit++)
            {
                if ((NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig) &&
                    (SpiCoreID == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->SpiCoreUse) &&
                    (SPI_PHYUNIT_ASYNC_U32 == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IsSync)
                   )
                {
                    Spi_Ipw_IrqConfig(HWUnit, Mode, SpiCoreID);
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON))
/**
* @brief   This function specifies the asynchronous mode for a given HWUnit.
* @details This function specifies the asynchronous mode for the SPI busses
*          handled asynchronously.
*          For synchronous HW units, the function has no impact.
*          The function will fail in two cases:
*          - driver not initialised (SPI_E_UNINIT reported by DET)
*          - a sequence transmission is pending the the asynchronous HW unit
*            (SPI_E_SEQ_PENDING reported by DET)
*
* @param[in]      HWUnit       The ID of the HWUnit to be configured
* @param[in]      AsyncMode    This parameter specifies the asynchronous
*                              operating mode (SPI_POLLING_MODE or
*                              SPI_INTERRUPT_MODE)
*
* @return Std_ReturnType
* @retval E_OK       The command ended successfully
* @retval E_NOT_OK   The command has failed
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL2 and
*       SPI_HWUNIT_ASYNC_MODE should be on STD_ON
*
*/
/** @implements Spi_SetHWUnitAsyncMode_Activity */
Std_ReturnType Spi_SetHWUnitAsyncMode
    (
        Spi_HWUnitType HWUnit,
        Spi_AsyncModeType AsyncMode
    )
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    uint32 SpiCoreID = Spi_GetCoreID;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    Status = Spi_HWUnitCheckValidity(HWUnit, SPI_SETHWUNITASYNCMODE_ID);

    if ((Std_ReturnType)E_OK != Status)
    {
        /* Do nothing */
    }
    else
    {
#endif
        if (SPI_PHYUNIT_ASYNC_U32 != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->IsSync)
        {
            /* return E_NOT_OK if HWUnit is Sync */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            /* Call Det_ReportError */
            (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETHWUNITASYNCMODE_ID,SPI_E_PARAM_UNIT);
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else if (SPI_BUSY == Spi_axSpiHwUnitQueueArray[HWUnit].Status)
        {
            /* return E_NOT_OK if HWUnit is Async and Busy */
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* set the async mode & activate/deactivate the interrupts for the HW Unit */
            Spi_Ipw_IrqConfig(HWUnit, AsyncMode, SpiCoreID);
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON) */

/**
* @brief   This function shall asynchronously poll SPI interrupts and call ISR if appropriate.
* @details This function shall asynchronously poll SPI interrupts and call
*          ISR if appropriate.
*          - Service ID:       0x10
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
/** @implements Spi_MainFunction_Handling_Activity */
void Spi_MainFunction_Handling(void)
{
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
    Spi_HWUnitType HWUnit;
    uint32 SpiCoreID;
    
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;

    if (NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID])
    {
        for (HWUnit = 0u; HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT; HWUnit++)
        {
            if((NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig) &&
               (SpiCoreID == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->SpiCoreUse)
              )
            {
                if (SPI_BUSY == Spi_axSpiHwUnitQueueArray[HWUnit].Status)
                {
                    Spi_Ipw_IrqPoll(HWUnit, SpiCoreID);
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /*Do nothing */
            }
        }
    }
#endif /* #if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2) ) */
}

/**
* @brief   This function starts the transfer of the first scheduled job for a given HW unit.
* @details If the list of scheduled jobs is not empty, pop the first job and
*          start the transfer. Elsewhere, mark the HW unit as IDLE.
*
* @param[in]      HWUnitQueue     The HW Unit used for scheduling
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
*/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
static void Spi_ScheduleNextJob
    (
        Spi_HWUnitQueue *HWUnitQueue,
        uint32 SpiCoreID
    )
{
    Spi_JobType Job;
    Spi_JobType *JobListHead;
    sint8 Priority;
    sint8 MaxScheduledPriority;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01();
    MaxScheduledPriority = HWUnitQueue->MaxScheduledPriority;
    if (0 > MaxScheduledPriority)
    {
        /* no job waiting => mark the HWUnit as IDLE */
        HWUnitQueue->Status = SPI_IDLE;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01();
    }
    else
    {
        /* a job is waiting => get the job ID from the highest priority queue */
        JobListHead = &HWUnitQueue->ScheduledJobsListHead[MaxScheduledPriority];
        Job = *JobListHead;

        /* set the new head of the list */
        *JobListHead = Spi_axSpiJobState[Job].AsyncNextJob;

        /* if the list is empty, set the tail accordingly and adjust the
           scheduled priority level */
        if (SPI_JOB_NULL == *JobListHead)
        {
            /* reset the tail */
            HWUnitQueue->ScheduledJobsListTail[MaxScheduledPriority] = SPI_JOB_NULL;

            /* find the first non empty scheduling queue */
            for (Priority = MaxScheduledPriority - 1; Priority >= 0; Priority--)
            {
                if (SPI_JOB_NULL != HWUnitQueue->ScheduledJobsListHead[Priority])
                {
                    /* there is a scheduled Job for this priority level */
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }

            /* Priority is set on the highest priority queue having
               scheduled jobs, or -1 if no other jobs scheduled */
            HWUnitQueue->MaxScheduledPriority = Priority;
        }
        else
        {
            /* Do nothing */
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01();

        /* mark the job as pending */
        Spi_axSpiJobState[Job].Result = SPI_JOB_PENDING;
        HWUnitQueue->Channel = 0u;
        HWUnitQueue->Job = Job;
        Spi_Ipw_JobTransfer(Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[Job].JobCfg);
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2) ) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2))
/**
* @brief   This function is called after a Job has been executed.
* @details The function calls Job and Sequence end notifications and schedules
*          the next job of the sequence or on the liberated HW Unit.
*
* @param[in]    JobConfig   The just transmited job pointer.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be SPI_LEVEL1 or SPI_LEVEL2.
*
* @implements Spi_JobTransferFinished_Activity
*/
void Spi_JobTransferFinished
    (
        const Spi_JobConfigType *JobConfig, Spi_JobResultType JobResult
    )
{
    Spi_HWUnitType HWUnit = JobConfig->HWUnit;
    Spi_HWUnitQueue *HWUnitQueue = &Spi_axSpiHwUnitQueueArray[HWUnit];
    Spi_JobStateType *JobState = JobConfig->JobState;
    Spi_SequenceStateType *SequenceState;
    const Spi_SequenceConfigType *SequenceConfig;
    const Spi_JobType *Job;
    const Spi_JobConfigType *CurrentJobConfig;
    Spi_JobType JobId;
    uint32 SpiCoreID;
    #if ((SPI_DMA_USED == STD_ON) && ((SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) || (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)))
    Spi_JobType JobIdx;
    boolean SkipAllJob = FALSE;
    #endif

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02();
    if((SPI_JOB_OK != JobState->Result) && (NULL_PTR != JobState->AsyncCrtSequenceState))
    {
        JobState->Result = JobResult;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02();
        
        SpiCoreID = JobConfig->SpiCoreUse;
        SequenceState = JobState->AsyncCrtSequenceState;
        SequenceConfig = SequenceState->Sequence;
        /* unlink the job from its sequence */
        JobState->AsyncCrtSequenceState = NULL_PTR;
        /* Perform job EndNotification (if there is one) */
        if (NULL_PTR != JobConfig->EndNotification)
        {
            JobConfig->EndNotification();
        }
        else
        {
            /* Do nothing */
        }
        /* set Sequence to fail if Job has been failed */
        if((SPI_JOB_FAILED == JobState->Result) && (SequenceState->Result != SPI_SEQ_CANCELLED))
        {
            SequenceState->Result = SPI_SEQ_FAILED;
        }
        else
        {
            /* Do nothing */
        }
        /* Check if current sequence has been cancelled or fail*/
#if (SPI_CANCEL_API == STD_ON)
        if ((SPI_SEQ_CANCELLED == SequenceState->Result) || (SPI_SEQ_FAILED == SequenceState->Result))
#else
        if (SPI_SEQ_FAILED == SequenceState->Result)
#endif
        {
            /* unlock jobs */
            Spi_UnlockRemainingJobs(SequenceState->RemainingJobs, SequenceConfig);
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if(SPI_SEQ_FAILED == SequenceState->Result)
            {
                /* Report to DEM */
                Spi_DemReportStatus(SpiCoreID, DEM_EVENT_STATUS_FAILED);
            }
            else
            {
                /* Report to DEM */
                Spi_DemReportStatus(SpiCoreID, DEM_EVENT_STATUS_PASSED);
            }
#endif
            /* SeqEndNotification */
            if (NULL_PTR != SequenceConfig->EndNotification)
            {
                SequenceConfig->EndNotification();
            }
            else
            {
                /* Do nothing */
            }

            Spi_ScheduleNextJob(HWUnitQueue, SpiCoreID);
        }
        else
        {
            #if ((SPI_DMA_USED == STD_ON) && ((SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) || (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)))
            #if (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
            SkipAllJob = SequenceConfig->EnableDmaFastTransfer;
            #endif
            #if (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT != STD_ON)
            SkipAllJob = SequenceConfig->EnableDmaContMemTransfer;
            #elif (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON)
            SkipAllJob = SkipAllJob || SequenceConfig->EnableDmaContMemTransfer;
            #endif 
            if(TRUE == SkipAllJob)
            {
                /* Set Job result to SPI_JOB_OK for all remaining Jobs */
                for (JobIdx = SequenceConfig->NumJobs-SequenceState->RemainingJobs; JobIdx < SequenceConfig->NumJobs; JobIdx++)
                {
                    MCAL_DATA_SYNC_BARRIER();
                    Spi_axSpiJobState[SequenceConfig->JobIndexList[JobIdx]].Result = SPI_JOB_OK;
                    MCAL_DATA_SYNC_BARRIER();
                }
                /* unlock jobs */
                Spi_UnlockRemainingJobs(SequenceState->RemainingJobs, SequenceConfig);
                /* Set remaining Jobs to 0 */
                SequenceState->RemainingJobs = 0u;
            }
            else
            {
                /* nothing to do */
            }
            #endif
            /* Check if this job is the last one */
            if (0u == SequenceState->RemainingJobs)
            {
                /* Reset sequence state */
                SequenceState->Result = SPI_SEQ_OK;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* Report to DEM */
                Spi_DemReportStatus(SpiCoreID, DEM_EVENT_STATUS_PASSED);
#endif

                /* SeqEndNotification */
                if (NULL_PTR != SequenceConfig->EndNotification)
                {
                    SequenceConfig->EndNotification();
                }
                else
                {
                    /* Do nothing */
                }

                Spi_ScheduleNextJob(HWUnitQueue, SpiCoreID);

            }
            else
            {
                /* advance to the next job */
                SequenceState->CurrentJobIndexPointer++;
                Job = SequenceState->CurrentJobIndexPointer;
                JobId = *Job;
                SequenceState->RemainingJobs--;
                CurrentJobConfig = Spi_apxSpiConfigPtr[SpiCoreID]->JobConfig[JobId].JobCfg;
                if (HWUnit != CurrentJobConfig->HWUnit)
                {
                    /* schedule the next job on the new DSPI unit */
                    Spi_ScheduleJob(&Spi_axSpiHwUnitQueueArray[CurrentJobConfig->HWUnit], JobId, CurrentJobConfig);

                    /* transmit the next scheduled job on the current DSPI unit */
                    Spi_ScheduleNextJob(HWUnitQueue, SpiCoreID);
                }
                else
                {
                    /* the next job uses the same DSPI unit */

#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
                    if (1u == SequenceConfig->Interruptible)
                    {
                        /* if the sequence is interruptible,
                           then schedule the next job */
                        /* DSPI is marked as BUSY => the new job is scheduled only */
                        Spi_ScheduleJob(HWUnitQueue, JobId, CurrentJobConfig);

                        /* run the first eligible job */
                        Spi_ScheduleNextJob(HWUnitQueue, SpiCoreID);
                    }
                    else
#endif
                    {
                        /* non-interruptible sequence =>
                           start transmission without scheduling */
                        /* mark the job as pending */
                        Spi_axSpiJobState[JobId].Result = SPI_JOB_PENDING;
                        HWUnitQueue->Channel = 0;
                        HWUnitQueue->Job = JobId;
                        Spi_Ipw_JobTransfer(CurrentJobConfig);
                    }
                }
            }
        }
    }
    else
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02();
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2) ) */

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   This function shall set different MCU clock configuration .
* @details This function shall set different MCU clock configuration .
*
* @param[in]    ClockMode   Clock mode to be set (SPI_NORMAL | SPI_ALTERNATE).
*
* @return Std_ReturnType
* @retval E_OK       The driver is initialised and in an IDLE state. The clock
*                    mode can be changed.
* @retval E_NOT_OK   The driver is NOT initialised OR is NOT in an IDLE state.
*                    The clock mode can NOT be changed.
*
* @pre  Pre-compile parameter SPI_DUAL_CLOCK_MODE shall be STD_ON.
*
*/
/** @implements Spi_SetClockMode_Activity */
Std_ReturnType Spi_SetClockMode
    (
        Spi_DualClockModeType ClockMode
    )
{
   Std_ReturnType Status = (Std_ReturnType)E_OK;
   Spi_HWUnitType HWUnit;
   uint32 SpiCoreID;
   
    /* Get current coreID */
    SpiCoreID = Spi_GetCoreID;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_apxSpiConfigPtr[SpiCoreID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETCLOCKMODE_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        /* Check if Spi Status is Busy */
        if (SPI_BUSY == Spi_GetStatus())
        {
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            for (HWUnit = (Spi_HWUnitType)0;
            HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT;
            HWUnit++)
            {
                if((NULL_PTR != Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig) &&
                   (SpiCoreID == Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig->SpiCoreUse)
                  )
                {
                    Spi_Ipw_SetClockMode(ClockMode, Spi_apxSpiConfigPtr[SpiCoreID]->HWUnitConfig[HWUnit].PhyUnitConfig);
                }
            }
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return Status;
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
