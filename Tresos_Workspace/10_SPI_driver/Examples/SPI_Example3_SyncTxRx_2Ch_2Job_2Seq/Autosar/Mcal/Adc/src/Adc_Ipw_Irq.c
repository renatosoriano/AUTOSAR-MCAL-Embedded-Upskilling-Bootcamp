/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC
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
*   @file
*
*   @internal
*   @addtogroup adc_ipw Adc Ipw
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external Units
* 3) internal and external interfaces from this Unit
==================================================================================================*/
#include "Adc.h"
#include "Adc_Ipw.h"
#include "Adc_Ipw_Irq.h"
#include "Adc_Ipw_Types.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IPW_VENDOR_ID_IRQ_C                      43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C       7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define ADC_IPW_SW_MAJOR_VERSION_IRQ_C               2
#define ADC_IPW_SW_MINOR_VERSION_IRQ_C               0
#define ADC_IPW_SW_PATCH_VERSION_IRQ_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Ipw_Irq.c file and Adc.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_VENDOR_ID)
    #error "Adc_Ipw_Irq.c and Adc.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_SW_MINOR_VERSION) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_IPW_VENDOR_ID)
    #error "Adc_Ipw_Irq.c and Adc_Ipw.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_IPW_SW_MAJOR_VERSION) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_IPW_SW_MINOR_VERSION) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_IPW_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Irq.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_IPW_VENDOR_ID_IRQ)
    #error "Adc_Ipw_Irq.c and Adc_Ipw_Irq.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Irq.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Irq.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Irq.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_IPW_SW_MAJOR_VERSION_IRQ) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_IPW_SW_MINOR_VERSION_IRQ) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_IPW_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Irq.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Types.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_IPW_VENDOR_ID_TYPES)
    #error "Adc_Ipw_Irq.c and Adc_Ipw_Types.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Types.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Types.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Types.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_IPW_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_IPW_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_IPW_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Mcal header file are of the same AutoSar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
    (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Mcal.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* The macro to calculate the index of the first channel in the previous configuration */
#define ADC_IPW_PREV_CHANNEL_INDEX(x) ((((x) % ADC_MAX_CHAN_COUNT) == 0U) ? ((x) - ADC_MAX_CHAN_COUNT) : ((Adc_ChannelIndexType)((x)-((x) % ADC_MAX_CHAN_COUNT))))

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
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_DMA_SUPPORTED)) \
    )
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
static inline void Adc_Ipw_CallNotification(Adc_GroupType Group,
                                            uint8 CoreId);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
static inline void Adc_Ipw_UpdateQueue(Adc_HwUnitType Unit,
                                       uint8 CoreId);
#endif  /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
static inline void Adc_Ipw_CallExtraNotification(Adc_GroupType Group,
                                                 uint8 CoreId);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

static inline Std_ReturnType Adc_Ipw_CheckConversionChannels(Adc_HwUnitType Unit,
                                                            Adc_GroupType Group,
                                                            Adc_StreamNumSampleType GroupSamples,
                                                            uint8 CoreId);

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static inline void Adc_Ipw_HandleConversionCheckFail(Adc_HwUnitType Unit,
                                                     Adc_GroupType Group,
                                                     const Adc_GroupConfigurationType * GroupPtr,
                                                     uint8 CoreId);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
static inline void Adc_Ipw_ConfigureRuntimeChannels(Adc_HwUnitType Unit,
                                                    const Adc_GroupConfigurationType * GroupPtr,
                                                    uint8 NumChannel,
                                                    uint8 CoreId);
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
static inline void Adc_Ipw_RestartConversion(Adc_HwUnitType Unit,
                                             Adc_GroupType Group,
                                             uint8 CoreId);

static inline uint32 Adc_Ipw_GetCurrentSampleCount(Adc_GroupType Group
                                                #if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
                                                   , Adc_HwUnitType Unit,
                                                   Adc_StreamNumSampleType GroupSamples,
                                                   uint8 CoreId
                                                #endif
                                                  );

static inline void Adc_Ipw_UpdateSoftwareGroupState(Adc_HwUnitType Unit,
                                                    Adc_GroupType Group,
                                                    Adc_StreamNumSampleType GroupSamples,
                                                    uint8 CoreId);

#if (ADC_HW_TRIGGER_API == STD_ON)
#ifdef ADC_DMA_SUPPORTED
static inline void Adc_Ipw_CheckAndUpdateDmaHwGroupState(Adc_HwUnitType Unit,
                                                         Adc_GroupType Group,
                                                         const uint32 AdcDmaLogicChId,
                                                         uint8 CoreId);
#endif /* ADC_DMA_SUPPORTED */

static inline void Adc_Ipw_UpdateHardwareGroupState(Adc_HwUnitType Unit,
                                                    Adc_GroupType Group,
                                                    Adc_StreamNumSampleType GroupSamples,
                                                    uint8 CoreId);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif  /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

static inline void Adc_Ipw_EndConversion(Adc_HwUnitType Unit,
                                         Adc_GroupType Group,
                                         boolean IsSoftwareConversion,
                                         uint8 CoreId);

#ifdef ADC_DMA_SUPPORTED
static inline void Adc_Ipw_EndDmaConversion(Adc_HwUnitType Unit,
                                            Adc_GroupType Group,
                                            boolean IsSoftwareConversion,
                                            uint8 CoreId);

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
static inline void Adc_Ipw_UpdateDmaConfig(const Adc_ValueGroupType * DataPtr,
                                           const uint32 DmaLogicChId,
                                           uint8 NumChannel);

static inline void Adc_Ipw_ContinueDmaConversion(Adc_HwUnitType Unit,
                                                 Adc_GroupType Group,
                                                 const Adc_ChannelIndexType ChannelCount,
                                                 const uint32 AdcDmaLogicChId,
                                                 uint8 CoreId);
#endif  /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static inline Std_ReturnType Adc_Ipw_CheckGroupConvResultDma(const Adc_GroupConfigurationType * GroupPtr,
                                                             uint8 CoreId);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /* ADC_DMA_SUPPORTED */

static inline void Adc_Ipw_ReadData(const Adc_GroupConfigurationType * GroupPtr,
                                    Adc_ValueGroupType * ResultPtr,
                                    const Adc_StreamNumSampleType GroupSamples,
                                    const Adc_ChannelIndexType Index,
                                    const uint16 ConvResult);

static inline void Adc_Ipw_EndConversionNotification(const Adc_HwUnitType PhysicalAdcUnit);
#endif  /* (defined(ADC_UNIT_0_ISR_USED) || ... */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_DMA_SUPPORTED)) \
    )
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/**
* @brief          This function checks and calls group notification
* @details        This function checks and calls group notification
*
* @param[in]      Group             The group to be converted
* @param[in]      CoreId            Current CoreID
*
* @return         void
*
*/
static inline void Adc_Ipw_CallNotification(Adc_GroupType Group,
                                            uint8 CoreId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];

    /* SWS_Adc_00080, SWS_Adc_00083 */
    if ((ADC_NOTIFICATION_ENABLED == Adc_axGroupStatus[Group].Notification) && \
        (NULL_PTR != Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].Notification)
       )
    {
        /* Execute notification function */
        Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].Notification();
    }
}
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
/**
* @brief          This function updates queue
* @details        This function updates queue elements after a conversion
*                 and start conversion if requests are still available in queue
*
* @param[in]      Unit              The ADC hardware unit
* @param[in]      CoreId            Current CoreID
*
* @return         void
*
*/
static inline void Adc_Ipw_UpdateQueue(Adc_HwUnitType Unit,
                                       uint8 CoreId)
{
#if (ADC_ENABLE_QUEUING == STD_ON)
    /* Remove current request element in queue */
    Adc_Ipw_RemoveFromQueue(Unit, 0U);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    if (Adc_axUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
    {
        /* Start conversion if request elements are still available in queue */
        Adc_Ipw_StartNormalConversion(Unit, CoreId);
    }
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#else
    /* No element will be present in the queue */
    Adc_axUnitStatus[Unit].SwNormalQueueIndex = (Adc_QueueIndexType)0;
#endif /* ADC_ENABLE_QUEUING == STD_ON */
    (void)CoreId;
}
#endif  /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
/**
* @brief          This function calls extra notification
* @details        This function calls extra notification
*
* @param[in]      Group         The channel group to be converted
* @param[in]      CoreId        Current CoreID
*
* @return         void
* CPR_RTD_00328.adc, SWS_Adc_00140
*/
static inline void Adc_Ipw_CallExtraNotification(Adc_GroupType Group,
                                                 uint8 CoreId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];

    /* Call notification if available */
    if (Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].ExtraNotification != NULL_PTR)
    {
        Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].ExtraNotification();
    }
}
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

/**
* @brief          This function checks conversion results
* @details        This function checks conversion results
*
* @param[in]      Unit          Adc Logical Unit Id
* @param[in]      Group         Selected group Id
* @param[in]      GroupSamples  Number of samples
* @param[in]      CoreId        Current CoreID
*
* @return         void
*/
static inline Std_ReturnType Adc_Ipw_CheckConversionChannels(Adc_HwUnitType Unit,
                                                            Adc_GroupType Group,
                                                            Adc_StreamNumSampleType GroupSamples,
                                                            uint8 CoreId)
{
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr; /* Pointer to AdcGroup */
    Adc_ChannelIndexType CurrentChannel = Adc_axGroupStatus[Group].CurrentChannel;
    Adc_ChannelIndexType Temp;
    Adc_ChannelIndexType Index;
    uint16 ConvResult;
    Adc_ValueGroupType * ResultIndex = NULL_PTR;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    const uint8 NumsBitShift = Adc_Ipw_CalculateNumsBitShift(Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit]->Resolution);
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    Adc_ChannelType HwChannel;
    boolean ResultInRange = FALSE;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    boolean ValidConversion;

    /* record the result of the Channel conversion and update group status */
#if (ADC_SETCHANNEL_API == STD_ON)
    Index = Adc_axRuntimeGroupChannel[Group].ChannelCount;
#else
    Index = Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AssignedChannelCount;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

    GroupPtr = &(Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex]);

    if (CurrentChannel <= Index)
    {
        /* Calculate the index of the first channel in the previous configuration */
        Temp = (Adc_ChannelIndexType)ADC_IPW_PREV_CHANNEL_INDEX(CurrentChannel);

#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        /* Get the result buffer pointer */
        if (FALSE == GroupPtr->StreamResultGroupMultiSets)
        {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
            ResultIndex = &(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]);
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        }
        else
        {
            ResultIndex = &(Adc_axGroupStatus[Group].ResultsBufferPtr[(Adc_axGroupStatus[Group].ResultIndex * Index)]);
        }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */

        ValidConversion = Adc_Ipw_CheckValidConversion(PhysicalHwUnitId, Temp, CurrentChannel);

        if (TRUE == ValidConversion)
        {
            /* For each of channels in the list of previous configuration, read data and take result into user buffer */
            for (Index = Temp; Index < CurrentChannel; Index++)
            {
                ConvResult = Adc_Ip_GetConvData(PhysicalHwUnitId, Index - Temp);
                /* Assumption: the width of the register is less than 16 */
                ConvResult = ConvResult << (NumsBitShift);
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
                if (
                        (TRUE == GroupPtr->AdcGroupLimitcheck)
#if (ADC_SETCHANNEL_API == STD_ON)
                        || (TRUE == Adc_axRuntimeGroupChannel[Group].AdcRuntimeGroupLimitcheck)
#endif /* ADC_SETCHANNEL_API == STD_ON */
                   )
                {
#if (ADC_SETCHANNEL_API == STD_ON)
                    HwChannel = Adc_axRuntimeGroupChannel[Group].ChannelPtr[Index];
#else
                    HwChannel = Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AssignmentPtr[Index];
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
                    /* SWS_Adc_00446, SWS_Adc_00447 */
                    ResultInRange = Adc_Ipw_CheckConversionValuesInRange(ConvResult, Unit, HwChannel, CoreId);
                    if (TRUE == ResultInRange)
                    {
                        Adc_Ipw_ReadData(GroupPtr, ResultIndex, GroupSamples, Index, ConvResult);
                        Adc_axGroupStatus[Group].LimitCheckFailed = FALSE;
                    }
                    else
                    {
                        Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
                        Adc_axGroupStatus[Group].LimitCheckFailed = TRUE;

                        Status = E_NOT_OK;
                        break;
                    }
                }
                else
                {
                    Adc_Ipw_ReadData(GroupPtr, ResultIndex, GroupSamples, Index, ConvResult);
                }
#else
                Adc_Ipw_ReadData(GroupPtr, ResultIndex, GroupSamples, Index, ConvResult);
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
            }
        }
        else
        {
            Status = (Std_ReturnType)E_NOT_OK;
        }
    }

    return Status;
}

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          This function handles the case where conversion check fails
* @details        This function stop all ongoing conversions, clears channel
*                 configurations and conversion complete flag if the one shot
*                 mode is selected, but reconfigures hardware if continuous mode
*                 is selected for the group.
*
*
* @param[in]      Unit          Adc Logical Unit Id
* @param[in]      Group         Selected group Id
* @param[in]      GroupPtr      Pointer to group config
* @param[in]      CoreId        Current CoreID
*
* @return         void
*/
static inline void Adc_Ipw_HandleConversionCheckFail(Adc_HwUnitType Unit,
                                                     Adc_GroupType Group,
                                                     const Adc_GroupConfigurationType * GroupPtr,
                                                     uint8 CoreId)
{
    uint8 Channel;
    Adc_Ip_ChanConfigType ChannelConfig;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    if (ADC_CONV_MODE_ONESHOT == GroupPtr->Mode)
    {
        /* Stop and clear all internal channels */
        for (Channel = 0U; Channel < Adc_axUnitStatus[Unit].Sc1Used; Channel++)
        {
            ChannelConfig.ChnIdx = Channel;
            ChannelConfig.Channel = ADC_IP_INPUTCHAN_DISABLED;
#if (defined(ADC_UNIT_0_END_CONVERSION_NOTIF_USED) || defined(ADC_UNIT_1_END_CONVERSION_NOTIF_USED))
            ChannelConfig.InterruptEnable = FALSE;
#endif /* (defined(ADC_UNIT_0_END_CONVERSION_NOTIF_USED) || defined(ADC_UNIT_1_END_CONVERSION_NOTIF_USED)) */
            Adc_Ip_ConfigChannel(PhysicalHwUnitId, &ChannelConfig);
        }
    }
    /* Group configured as continuous will be re-configured*/
    else
    {
        Adc_axGroupStatus[Group].CurrentChannel = 0U;
        Adc_Ipw_ConfigureConversion(Unit, Group, PDB_ADC_IP_SOFTWARE_TRIGGER, 1U, CoreId);
    }
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
/**
* @brief          This function reconfigures runtime updated channels
* @details        This function reconfigures runtime updated channels
*
* @param[in]      Unit          Adc Logical Unit Id
* @param[in]      GroupPtr      Selected group pointer
* @param[in]      NumChannel    Calculated number of channels within range of SC1 registers
* @param[in]      CoreId        Current CoreID
*
* @return         void
*/
static inline void Adc_Ipw_ConfigureRuntimeChannels(Adc_HwUnitType Unit,
                                                    const Adc_GroupConfigurationType * GroupPtr,
                                                    uint8 NumChannel,
                                                    uint8 CoreId)
{
    Adc_GroupType Group = GroupPtr->GroupId;

    Adc_axGroupStatus[Group].CurrentChannel = 0U;
    Adc_axGroupStatus[Group].ResultIndex = 0U;

#ifdef ADC_DMA_SUPPORTED
    /* Not required to check AdcWithoutDma == FALSE in DMA notification handler */
    if ((ADC_DMA == Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit]))
    {
        if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
        {
            /* Configure for DMA transfer, starting from first sample, consider both Optimize DMA stream and normal DMA scenarios */
            Adc_Ipw_StartDmaOperation(Unit, Group, NumChannel, CoreId);
        }

        /* Reconfigure DMA transfer */
#if (ADC_HW_TRIGGER_API == STD_ON)
        Adc_Ipw_ConfigureDmaConversion(Unit, Group, GroupPtr->HwTriggerSource, NumChannel);
#else
        Adc_Ipw_ConfigureDmaConversion(Unit, Group, PDB_ADC_IP_SOFTWARE_TRIGGER, NumChannel);
#endif
    }
    else
#endif /* ADC_DMA_SUPPORTED */
    {
        /* Re-configure group channels and trigger PDB by software */
#if (ADC_HW_TRIGGER_API == STD_ON)
        Adc_Ipw_ConfigureConversion(Unit, Group, GroupPtr->HwTriggerSource, NumChannel, CoreId);
#else
        Adc_Ipw_ConfigureConversion(Unit, Group, PDB_ADC_IP_SOFTWARE_TRIGGER, NumChannel, CoreId);
#endif
    }

    /* Reset runtime update status */
    Adc_axRuntimeGroupChannel[Group].RuntimeUpdated = FALSE;
}
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
/**
* @brief          This function restarts a conversion
* @details        This function restarts a conversion and reconfigure the
*                 hardware if necessary
*
* @param[in]      Unit          Adc Logical Unit Id
* @param[in]      Group         Selected group Id
* @param[in]      CoreId        Current CoreID
*
* @return         void
*/
static inline void Adc_Ipw_RestartConversion(Adc_HwUnitType Unit,
                                             Adc_GroupType Group,
                                             uint8 CoreId)
{
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
#if ((ADC_SETCHANNEL_API == STD_ON) || defined(ADC_DMA_SUPPORTED))
    /* Pointer to AdcGroup */
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex]);
#endif /* ((ADC_SETCHANNEL_API == STD_ON) || (defined(ADC_DMA_SUPPORTED)) */
#ifdef ADC_DMA_SUPPORTED
    const uint32 AdcDmaLogicChId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
    uint16 ResultIndex;
#endif /*ADC_DMA_SUPPORTED*/
    uint8 NumChannel;
    Adc_ChannelIndexType ChannelCount;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Get channel count in case of changing at runtime */
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
#else
    /* Get channel count from configuration */
    ChannelCount = Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AssignedChannelCount;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

    /* Get left channel from channel count */
    NumChannel = (uint8)ADC_IPW_CALCULATE_CHAN_NUMBER(ChannelCount);

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Configure again Adc hardware unit in case of channels of group configured */
    if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
    {
        Adc_Ipw_ConfigureRuntimeChannels(Unit, GroupPtr, NumChannel, CoreId);
    }
    else
#endif  /* (ADC_SETCHANNEL_API == STD_ON) */
    {
#ifdef ADC_DMA_SUPPORTED
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
        if (FALSE == GroupPtr->AdcOptimizeDmaStream)
#endif /*  (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#endif /*ADC_DMA_SUPPORTED*/
        {
            /* Incase of the number of channels in group less than the SC1 register used then update group status and start Pdb */
            if (ChannelCount <= ADC_MAX_CHAN_COUNT)
            {
                /* No need to re-configure channels if they are not changed */
                /* End of chain interrupt (if used) is still in last channel (= ChannelCount) */
                Adc_axGroupStatus[Group].CurrentChannel = ChannelCount;

                /* Trigger PDB by software */
                Pdb_Adc_Ip_SwTrigger(PhysicalHwUnitId);
            }
            /* Incase of the number of channels greater than max SC1 register, re-configure Adc hardware unit for the next conversion */
            else
            {
                Adc_axGroupStatus[Group].CurrentChannel = 0U;
#ifdef ADC_DMA_SUPPORTED
                if (ADC_DMA == Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
                {
                    /* Dma need to be re-init for next result index */
                    if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
                    {
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
                        if (TRUE == GroupPtr->StreamResultGroupMultiSets)
                        {
                            ResultIndex = Adc_axGroupStatus[Group].ResultIndex * ChannelCount;
                        }
                        else
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
                        {
                            ResultIndex = Adc_axGroupStatus[Group].ResultIndex;
                        }

                        /* Update DMA configuration for new samples */
                        Adc_Ipw_UpdateDmaConfig((&(Adc_axGroupStatus[Group].ResultsBufferPtr[ResultIndex])), AdcDmaLogicChId, NumChannel);
                    }

                    Adc_Ipw_ConfigureDmaConversion(Unit, Group, PDB_ADC_IP_SOFTWARE_TRIGGER, NumChannel);
                }
                else
#endif /*ADC_DMA_SUPPORTED*/
                {
                    /* Re-configure other segment channels of groups And start next conversion*/
                    Adc_Ipw_ConfigureConversion(Unit, Group, PDB_ADC_IP_SOFTWARE_TRIGGER, NumChannel, CoreId);
                }
            }
        }
    }
}

static inline uint32 Adc_Ipw_GetCurrentSampleCount(Adc_GroupType Group
                                                #if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
                                                   , Adc_HwUnitType Unit,
                                                   Adc_StreamNumSampleType GroupSamples,
                                                   uint8 CoreId
                                                #endif
                                                  )
{
    Adc_StreamNumSampleType CurrentSampleCount;
#ifdef ADC_DMA_SUPPORTED
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    uint32 CurrentIter = 0U;
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    const Adc_Ipw_Config * const LocIpwConfigPtr = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr;
    const uint32 AdcDmaLogicChId = (uint32)LocIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
    const uint32 AdcCountingDmaLogicChId = (uint32)LocIpwConfigPtr->Mapping.AdcCountingDmaChanLogicId[Unit];
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#endif /* ADC_DMA_SUPPORTED */

#ifdef ADC_DMA_SUPPORTED
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    if (TRUE == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AdcOptimizeDmaStream)
    {
        if (1U < Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AssignedChannelCount)
        {
            (void)Dma_Ip_GetLogicChannelParam(AdcCountingDmaLogicChId, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &CurrentIter);
        }
        else
        {
            (void)Dma_Ip_GetLogicChannelParam(AdcDmaLogicChId, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &CurrentIter);
        }

        /* This condition only occurs at half interrupt */
        if ((Adc_StreamNumSampleType)CurrentIter != GroupSamples)
        {
            /* Re-calculate CurrentSampleCount because CITER decrements its value from GroupSamples to 1 */
            CurrentSampleCount = GroupSamples - (Adc_StreamNumSampleType)CurrentIter;
        }
        else
        {
            /* When major loop completed, CITER roll back to be equal to GroupSamples so no need to re-calculate */
            CurrentSampleCount = (Adc_StreamNumSampleType)CurrentIter;
        }
        Adc_axGroupStatus[Group].ResultIndex = CurrentSampleCount;
    }
    else
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#endif /* ADC_DMA_SUPPORTED */
    {
        CurrentSampleCount = Adc_axGroupStatus[Group].ResultIndex;
    }

    return CurrentSampleCount;
}

/**
* @brief          This function update state of software conversion according to AutoSar diagrams
* @details        This function update state of software conversion according to AutoSar diagrams
*
* @param[in]      Unit          Adc Logical Unit Id
* @param[in]      Group         Selected group Id
* @param[in]      GroupSamples  Number of samples
* @param[in]      CoreId        Current CoreID
*
* @return         void
*/
static inline void Adc_Ipw_UpdateSoftwareGroupState(Adc_HwUnitType Unit,
                                                    Adc_GroupType Group,
                                                    Adc_StreamNumSampleType GroupSamples,
                                                    uint8 CoreId)
{
    uint32 CurrentSampleCount;
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
#ifdef ADC_DMA_SUPPORTED
    const Adc_Ipw_Config * const LocIpwConfigPtr = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr;
    const uint32 AdcDmaLogicChId = (uint32) LocIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
    Adc_HwUnitType PhysicalHwUnitId = LocIpwConfigPtr->AdcPhysicalIdArr[Unit];
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
#endif /* ADC_DMA_SUPPORTED */

    /* At least once the group was converted */
    /* It's already check for validation */
    Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

    /* Although updating Conversion is a RMW operation, it does not need an
     * exclusive area because two simultaneous interrupts will not access the
     * same areas e.g. the interrupt for ADC1 will not have the same group as
     * an interrupt on ADC0 */
    /* Change when configuration is ADC streaming access mode */
    if (ADC_BUSY == Adc_axGroupStatus[Group].Conversion)
    {
        /* SWS_Adc_00224 */
        Adc_axGroupStatus[Group].Conversion = ADC_COMPLETED;
    }

#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    CurrentSampleCount = Adc_Ipw_GetCurrentSampleCount(Group, Unit, GroupSamples, CoreId);
#else
    CurrentSampleCount = Adc_Ipw_GetCurrentSampleCount(Group);
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */

    /* If buffer is full of samples */
    if (CurrentSampleCount >= GroupSamples)
    {
        /* Change to stream complete according to AutoSar diagram */
        Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;

        if ((ADC_STREAM_BUFFER_LINEAR == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].BufferMode) && \
            (ADC_ACCESS_MODE_STREAMING == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AccessMode) \
           )
        {
#ifdef ADC_DMA_SUPPORTED
            /* Not required to check AdcWithoutDma == FALSE, because AdcWithoutDma is only supported for SW normal triggered which cannot be ADC_ACCESS_MODE_STREAMING when DMA transfer selected for HW unit */
            if (ADC_DMA == LocIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
            {
                /* Disable ADC DMA Request */
                Adc_Ip_DisableDma(PhysicalHwUnitId);
            }
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
            /* Because of PDB was configured as CONT MODE then need to disable */
            if (TRUE == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AdcOptimizeDmaStream)
            {
                Pdb_Adc_Ip_DisableAndClearPdb(PhysicalHwUnitId);
            }
#endif /*  (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#endif /* ADC_DMA_SUPPORTED */
            /* Update queue and execute new start conversion request from queue if available */
            Adc_Ipw_UpdateQueue(Unit, CoreId);
        }
        else
        {
            /* ADC_ACCESS_MODE_STREAMING && ADC_STREAM_BUFFER_CIRCULAR */
            if (ADC_CONV_MODE_CONTINUOUS == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].Mode)
            {
                /* Restart new continuous conversion */
                Adc_axGroupStatus[Group].ResultIndex = 0U;
#ifdef ADC_DMA_SUPPORTED
                if (ADC_DMA == LocIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
                {
                    if ((uint8)STD_OFF == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AdcExtDMAChanEnable)
                    {
                        LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                        LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[0U]));
                        (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
                    }
                }
#endif /*ADC_DMA_SUPPORTED*/
                Adc_Ipw_RestartConversion(Unit, Group, CoreId);
            }
            else
            {
                /* Update queue and execute new request from queue if available */
                Adc_Ipw_UpdateQueue(Unit, CoreId);
            }
        }
    }
    else
    {
        /* Need to restart conversion until buffer is full */
        Adc_Ipw_RestartConversion(Unit, Group, CoreId);
    }

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* Implement user notification function if available */
    Adc_Ipw_CallNotification(Group, CoreId);
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
}

#if (ADC_HW_TRIGGER_API == STD_ON)
#ifdef ADC_DMA_SUPPORTED
static inline void Adc_Ipw_CheckAndUpdateDmaHwGroupState(Adc_HwUnitType Unit,
                                                         Adc_GroupType Group,
                                                         const uint32 AdcDmaLogicChId,
                                                         uint8 CoreId)
{
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
    /* ADC_ACCESS_MODE_STREAMING && ADC_STREAM_BUFFER_CIRCULAR */
    if ((ADC_STREAM_BUFFER_CIRCULAR == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].BufferMode) && \
        (ADC_ACCESS_MODE_STREAMING == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AccessMode)
        )
    {
        if (ADC_DMA == Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
        {
            if ((uint8)STD_OFF == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AdcExtDMAChanEnable)
            {
                LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[0U]));
                (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
            }
        }
    }
}
#endif /* ADC_DMA_SUPPORTED */

/**
* @brief          This function update state of hardware conversion according to AutoSar diagrams
* @details        This function update state of hardware conversion according to AutoSar diagrams
*
* @param[in]      Unit          Adc Logical Unit Id
* @param[in]      Group         Selected group Id
* @param[in]      GroupSamples  Number of samples
* @param[in]      CoreId        Current CoreID
*
* @return         void
*/
static inline void Adc_Ipw_UpdateHardwareGroupState(Adc_HwUnitType Unit,
                                                    Adc_GroupType Group,
                                                    Adc_StreamNumSampleType GroupSamples,
                                                    uint8 CoreId)
{
    boolean NotificationCalled = FALSE;
    uint32 CurrentSampleCount;
    Adc_ChannelIndexType ChannelCount;
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
#if (defined(ADC_DMA_SUPPORTED) || defined(ADC_UNIT_0_END_CONVERSION_NOTIF_USED) || defined(ADC_UNIT_1_END_CONVERSION_NOTIF_USED))
    const Adc_Ipw_Config * const LocIpwConfigPtr = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr;
    Adc_HwUnitType PhysicalHwUnitId = LocIpwConfigPtr->AdcPhysicalIdArr[Unit];
#endif /* (defined(ADC_UNIT_0_END_CONVERSION_NOTIF_USED) || defined(ADC_UNIT_1_END_CONVERSION_NOTIF_USED)) */
#ifdef ADC_DMA_SUPPORTED
    const uint32 AdcDmaLogicChId = (uint32)LocIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
#endif /* ADC_DMA_SUPPORTED */

#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
#else
    ChannelCount = Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AssignedChannelCount;
#endif

    /* At least once the group was converted */
    Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

    /* Although updating Conversion is a RMW operation, it does not need an
     * exclusive area because two simultaneous interrupts will not access the
     * same areas e.g. the interrupt for ADC1 will not have the same group as
     * an interrupt on ADC0 */
    if (ADC_BUSY == Adc_axGroupStatus[Group].Conversion)
    {
        /* SWS_Adc_00224 */
        Adc_axGroupStatus[Group].Conversion = ADC_COMPLETED;
    }

#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    CurrentSampleCount = Adc_Ipw_GetCurrentSampleCount(Group, Unit, GroupSamples, CoreId);
#else
    CurrentSampleCount = Adc_Ipw_GetCurrentSampleCount(Group);
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */

    if (CurrentSampleCount >= GroupSamples)
    {
        Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;

        if ((ADC_STREAM_BUFFER_LINEAR == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].BufferMode) && \
            (ADC_ACCESS_MODE_STREAMING == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].AccessMode)
           )
        {
#if (defined(ADC_UNIT_0_END_CONVERSION_NOTIF_USED) || defined(ADC_UNIT_1_END_CONVERSION_NOTIF_USED))
            Adc_Ip_DisableChannelNotification(PhysicalHwUnitId, (Adc_axUnitStatus[Unit].Sc1Used - 1U));
#endif /* (defined(ADC_UNIT_0_END_CONVERSION_NOTIF_USED) || defined(ADC_UNIT_1_END_CONVERSION_NOTIF_USED)) */
#ifdef ADC_DMA_SUPPORTED
            /* Not required to check AdcWithoutDma == FALSE, because AdcWithoutDma is only supported for SW normal triggered which cannot be ADC_ACCESS_MODE_STREAMING when DMA transfer selected for HW unit */
            if (ADC_DMA == LocIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
            {
                /* Disable ADC DMA Request */
                Adc_Ip_DisableDma(PhysicalHwUnitId);
            }
#endif /* ADC_DMA_SUPPORTED */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
            Adc_Ipw_CallNotification(Group, CoreId);
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
            NotificationCalled = TRUE;
        }
        else
        {
            Adc_axGroupStatus[Group].ResultIndex = 0U;
#ifdef ADC_DMA_SUPPORTED
            Adc_Ipw_CheckAndUpdateDmaHwGroupState(Unit, Group, AdcDmaLogicChId, CoreId);
#endif /* ADC_DMA_SUPPORTED */
        }
    }

    if (FALSE == NotificationCalled)
    {
        /* Setting up to PDB HW trigger mode for each completed sample in case of configured channels > SC */
        if ((ChannelCount > ADC_MAX_CHAN_COUNT)
#if (ADC_SETCHANNEL_API == STD_ON)
            || (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
        )
        {
            Adc_Ipw_StartHwTrigConversion(Unit, Group, CoreId);
        }

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        Adc_Ipw_CallNotification(Group, CoreId);
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    }
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif  /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

/**
* @brief          This function handles conversion ending routines
* @details        This function handles conversion ending routines
*
* @param[in]      Unit                  Adc Logical Unit Id
* @param[in]      Group                 Selected group Id
* @param[in]      IsSoftwareConversion  Software or Hardware triggered conversion
* @param[in]      CoreId                Current CoreID
*
* @return         void
*/
static inline void Adc_Ipw_EndConversion(Adc_HwUnitType Unit,
                                         Adc_GroupType Group,
                                         boolean IsSoftwareConversion,
                                         uint8 CoreId)
{
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr; /* Pointer to AdcGroup */
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    Adc_ChannelIndexType NumChannel;
    uint8 LeftChannel;
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
#if ((ADC_SETCHANNEL_API == STD_ON) || ((ADC_SETCHANNEL_API == STD_OFF) && (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)))
    Adc_ChannelIndexType ChannelCount;
#endif /* ((ADC_SETCHANNEL_API == STD_ON) || ((ADC_SETCHANNEL_API == STD_OFF) && (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF))) */

    /* Get the group configuration */
    GroupPtr = &(Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex]);

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Channels configured at runtime */
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;

    /* Check if channel was updated before interrupt of previous conversions */
    if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
    {
        Adc_Ipw_ConfigureRuntimeChannels(Unit, GroupPtr, (uint8)ADC_IPW_CALCULATE_CHAN_NUMBER(ChannelCount), CoreId);
    }
    else
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    {
        /* Limit checking */
        if ((Std_ReturnType)E_OK == Adc_Ipw_CheckConversionChannels(Unit, Group, GroupPtr->NumSamples, CoreId))
        {
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
            /* Following code will not be reduced when oneshot hardware trigger optimization is not enabled */
#if (ADC_SETCHANNEL_API == STD_OFF)
            /* Channels configured when initializing */
            ChannelCount = GroupPtr->AssignedChannelCount;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

            /* More channels in group */
            /* Both HW and SW groups are using PDB SW trigger mode to restart conversion when ChannelCount > Max SC registers */
            if (Adc_axGroupStatus[Group].CurrentChannel < ChannelCount)
            {
                /* Get left channel */
                NumChannel = ChannelCount - Adc_axGroupStatus[Group].CurrentChannel;

                /* In case of left channels excess maximum allowed channels */
                LeftChannel = (uint8)ADC_IPW_CALCULATE_CHAN_NUMBER(NumChannel);

                /* Configure left channels and start more conversions */
                Adc_Ipw_ConfigureConversion(Unit, Group, PDB_ADC_IP_SOFTWARE_TRIGGER, LeftChannel, CoreId);
            }
            /* All of channels converted */
            else
#endif
            {
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
            Adc_Ipw_CallExtraNotification(Group, CoreId);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON)
                /* At least once the group was converted */
                Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

                Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;

#if (ADC_SETCHANNEL_API == STD_ON)
                /* Check if channel was updated in Adc_Ipw_CallExtraNotification */
                if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
                {
                    Adc_Ipw_ConfigureRuntimeChannels(Unit, GroupPtr, (uint8)ADC_IPW_CALCULATE_CHAN_NUMBER(ChannelCount), CoreId);
                }
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_OFF)
            (void)IsSoftwareConversion;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_OFF) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
                /* Check notification of a group and call the notification function if needed */
                Adc_Ipw_CallNotification(Group, CoreId);
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

#else /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

                /* Although this is a RMW operation, it does not need an exclusive area because two
                * simultaneous interrupts will not access the same areas e.g. the interrupt for
                * ADC1 will not have the same group as an interrupt on ADC0 */
                /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
                Adc_axGroupStatus[Group].ResultIndex++;

                /* Update state following AutoSar diagrams */
                if (TRUE == IsSoftwareConversion)
                {
                    Adc_Ipw_UpdateSoftwareGroupState(Unit, Group, GroupPtr->NumSamples, CoreId);
                }
#if (ADC_HW_TRIGGER_API == STD_ON)
                else
                {
                    Adc_Ipw_UpdateHardwareGroupState(Unit, Group, GroupPtr->NumSamples, CoreId);
                }
#endif  /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif  /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON) */
            }
        }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        else
        {
            if (TRUE == IsSoftwareConversion)
            {
                Adc_Ipw_HandleConversionCheckFail(Unit, Group, GroupPtr, CoreId);
            }
        }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    }
}

#ifdef ADC_DMA_SUPPORTED
/**
* @brief          This function handles conversion ending routines incase of DMA Transfering
* @details        This function handles conversion ending routines incase of DMA Transfering
*
* @param[in]      Unit                  Adc Logical Unit Id
* @param[in]      Group                 Selected group Id
* @param[in]      IsSoftwareConversion  Software or Hardware triggered conversion
* @param[in]      CoreId                Current CoreID
*
* @return         void
*/
static inline void Adc_Ipw_EndDmaConversion(Adc_HwUnitType Unit,
                                            Adc_GroupType Group,
                                            boolean IsSoftwareConversion,
                                            uint8 CoreId)
{
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex]); /* Pointer to AdcGroup */
    const uint32 AdcDmaLogicChId = (uint32) Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
#if ((ADC_SETCHANNEL_API == STD_ON) || ((ADC_SETCHANNEL_API == STD_OFF) && (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)))
    Adc_ChannelIndexType ChannelCount;
#endif /* ((ADC_SETCHANNEL_API == STD_ON) || ((ADC_SETCHANNEL_API == STD_OFF) && (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF))) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    Dma_Ip_LogicChannelTransferListType LocTransferList[1U];
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Channels configured at runtime */
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;

    /* Check if channel was updated before interrupt of previous conversions */
    if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
    {
        Adc_Ipw_ConfigureRuntimeChannels(Unit, GroupPtr, (uint8)ADC_IPW_CALCULATE_CHAN_NUMBER(ChannelCount), CoreId);
    }
    else
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    {
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_Ipw_CheckGroupConvResultDma(GroupPtr, CoreId))
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
        {
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
            /* Following code will not be reduced when oneshot hardware trigger optimization is not enabled */
#if (ADC_SETCHANNEL_API == STD_OFF)
            /* Channels configured when initializing */
            ChannelCount = GroupPtr->AssignedChannelCount;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
            /* More channels in group */
            if (Adc_axGroupStatus[Group].CurrentChannel < ChannelCount)
            {
                Adc_Ipw_ContinueDmaConversion(Unit, Group, ChannelCount, AdcDmaLogicChId, CoreId);
            }
            /* All of channels converted */
            else
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
            {
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
                Adc_Ipw_CallExtraNotification(Group, CoreId);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON)
                /* At least once the group was converted */
                Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

                Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;

#if (ADC_SETCHANNEL_API == STD_ON)
                /* Check if channel was updated in Adc_Ipw_CallExtraNotification */
                if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
                {
                    Adc_Ipw_ConfigureRuntimeChannels(Unit, GroupPtr, (uint8)ADC_IPW_CALCULATE_CHAN_NUMBER(ChannelCount), CoreId);
                }
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_OFF)
            (void)IsSoftwareConversion;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_OFF) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
                /* Check notification of a group and call the notification function if needed */
                Adc_Ipw_CallNotification(Group, CoreId);
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

#else /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

                /* Although this is a RMW operation, it does not need an exclusive area because two
                * simultaneous interrupts will not access the same areas e.g. the interrupt for
                * ADC1 will not have the same group as an interrupt on ADC0 */
                /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
                Adc_axGroupStatus[Group].ResultIndex++;

                /* Update state following AutoSar diagrams */
                if (TRUE == IsSoftwareConversion)
                {
                    Adc_Ipw_UpdateSoftwareGroupState(Unit, Group, GroupPtr->NumSamples, CoreId);
                }
#if (ADC_HW_TRIGGER_API == STD_ON)
                else
                {
                    Adc_Ipw_UpdateHardwareGroupState(Unit, Group, GroupPtr->NumSamples, CoreId);
                }
#endif  /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif  /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON) */

                if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
                {
                    /* DMA Hardware Request was disabled after transfer completed, to avoid overwriting any new results before this gets processed. Re-enable DMA here. */
                    (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
                }
            }
        }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        else
        {
            if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
            {
                /* Update the Destination Address and enable DMA HW Request since results weren't valid */
                LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]));
                (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
                (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
            }
            if (TRUE == IsSoftwareConversion)
            {
                Adc_Ipw_HandleConversionCheckFail(Unit, Group, GroupPtr, CoreId);
            }
        }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    }
}

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
/**
* @brief          This function updates Dma configuration
* @details        This function updates Dma configuration if number of configured channels
*                 are greater than number of SC1 register
*
* @param[in]      DataPtr       Adc_ValueGroupType * DataPtr,
* @param[in]      DmaLogicChId  Dma logical channel
* @param[in]      NumChannel    Number of channel to be converted
*
* @return         void
*/
static inline void Adc_Ipw_UpdateDmaConfig(const Adc_ValueGroupType * DataPtr,
                                           const uint32 DmaLogicChId,
                                           uint8 NumChannel)
{
    Dma_Ip_LogicChannelTransferListType LocTransferList[3U];

    LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    LocTransferList[0].Value = (uint32)(DataPtr);
    LocTransferList[1].Param = DMA_IP_CH_SET_SOURCE_SIGNED_LAST_ADDR_ADJ;
    LocTransferList[1].Value = ADC_IPW_GET_COMPLEMENT_OF_2((uint32)NumChannel << 2UL);
    LocTransferList[2].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    LocTransferList[2].Value = (uint32)NumChannel;

    /* Setting for DMA transfer */
    (void)Dma_Ip_SetLogicChannelTransferList(DmaLogicChId, LocTransferList, 3U);
    (void)Dma_Ip_SetLogicChannelCommand(DmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

static inline void Adc_Ipw_ContinueDmaConversion(Adc_HwUnitType Unit,
                                                 Adc_GroupType Group,
                                                 const Adc_ChannelIndexType ChannelCount,
                                                 const uint32 AdcDmaLogicChId,
                                                 uint8 CoreId)
{
    const Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    const Adc_ChannelIndexType NumChannel = ChannelCount - Adc_axGroupStatus[Group].CurrentChannel;
    /* In case of left channels excess maximum allowed channels */
    const uint8 LeftChannel = (uint8)ADC_IPW_CALCULATE_CHAN_NUMBER(NumChannel);
    const Adc_GroupConfigurationType * GroupPtr; /* Pointer to AdcGroup */
    uint16 ResultIndex;

    GroupPtr = &(Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex]);

    if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
    {
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        if (TRUE == GroupPtr->StreamResultGroupMultiSets)
        {
            ResultIndex = (Adc_axGroupStatus[Group].ResultIndex * ChannelCount) + Adc_axGroupStatus[Group].CurrentChannel;
        }
        else
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        {
            ResultIndex = ((Adc_axGroupStatus[Group].CurrentChannel) * (GroupPtr->NumSamples)) + Adc_axGroupStatus[Group].ResultIndex;
        }

        /* Update DMA configuration for remaining channels */
        Adc_Ipw_UpdateDmaConfig((&(Adc_axGroupStatus[Group].ResultsBufferPtr[ResultIndex])), AdcDmaLogicChId, LeftChannel);
    }

    /* Configure left channels and start more conversions */
    Adc_Ipw_ConfigureDmaConversion(Unit, Group, PDB_ADC_IP_SOFTWARE_TRIGGER, LeftChannel);
}
#endif  /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          This function checks the conversion result when Limit Check and DMA are enabled.
* @details        This function checks the conversion result when Limit Check and DMA are enabled.
*
* @param[in]      GroupPtr          The Adc Group Pointer.
* @param[in]      CoreId            Current CoreID
*
* @return         Std_ReturnType
*
*/
static inline Std_ReturnType Adc_Ipw_CheckGroupConvResultDma(const Adc_GroupConfigurationType * GroupPtr,
                                                             uint8 CoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    const Adc_GroupType Group = GroupPtr->GroupId;
    const Adc_HwUnitType Unit = GroupPtr->AdcLogicalUnitId;
    Adc_ValueGroupType * ResultDataPtr = &(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]);
    Adc_ChannelType HwChannel;

#if (ADC_SETCHANNEL_API == STD_ON)
    HwChannel = Adc_axRuntimeGroupChannel[Group].ChannelPtr[0];
#else
    HwChannel = GroupPtr->AssignmentPtr[0];
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

    if (
            (TRUE == GroupPtr->AdcGroupLimitcheck)
#if (ADC_SETCHANNEL_API == STD_ON)
            || (TRUE == Adc_axRuntimeGroupChannel[Group].AdcRuntimeGroupLimitcheck)
#endif /* ADC_SETCHANNEL_API == STD_ON */
       )
    {
        /* Assumption: because of SWS_Adc_00451, the number of channels configured for a group when limit checking is disabled, must be one.*/
        if (FALSE == Adc_Ipw_CheckConversionValuesInRange(ResultDataPtr[0], Unit, HwChannel, CoreId))
        {
            /* SWS_Adc_00448 */
            /* Return an error */
            Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
            Adc_axGroupStatus[Group].LimitCheckFailed = TRUE;
            ResultDataPtr[0] = 0U;
            ReturnValue = (Std_ReturnType) E_NOT_OK;
        }
        else
        {
            Adc_axGroupStatus[Group].LimitCheckFailed = FALSE;
        }
    }

    return ReturnValue;
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /* ADC_DMA_SUPPORTED */


/**
* @brief          This function read conversion results
* @details        This function read conversion results
*
* @param[in]      GroupPtr      Group Pointer
* @param[in]      ResultPtr     Pointer to conversion results
* @param[in]      GroupSamples  Number of samples
* @param[in]      Index         Current index of result
* @param[in]      ConvResult    Conversion result
*
* @return         void
*/
static inline void Adc_Ipw_ReadData(const Adc_GroupConfigurationType * GroupPtr,
                                    Adc_ValueGroupType * ResultPtr,
                                    const Adc_StreamNumSampleType GroupSamples,
                                    const Adc_ChannelIndexType Index,
                                    const uint16 ConvResult)
{
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    if (FALSE == GroupPtr->StreamResultGroupMultiSets)
    {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        ResultPtr[(Index * GroupSamples)] = ConvResult;
        (void)GroupPtr;
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    }
    else
    {
        ResultPtr[Index] = ConvResult;
    }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
}

/**
* @brief          This function handles the end conversion notification.
* @details        This function handles the end conversion notification.
*
* @param[in]      PhysicalAdcUnit   ADC Hardware Unit
*
* @return         void
*/
static inline void Adc_Ipw_EndConversionNotification(const Adc_HwUnitType PhysicalAdcUnit)
{
    /* Check that ADC unit is assigned to current core partition */
    const volatile uint8 CoreId = Adc_GetCoreID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.HwLogicalId[PhysicalAdcUnit];
    const Adc_GroupType SwGroupId = Adc_axUnitStatus[LogicalHwUnitId].SwNormalQueue[0U];
#if (ADC_HW_TRIGGER_API == STD_ON)
    const Adc_GroupType HwGroupId = Adc_axUnitStatus[LogicalHwUnitId].OngoingHwGroup;
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
    /* Check if requests are available in queue */
    if (ADC_INVALID_HW_GROUP_ID != HwGroupId)
    {
#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId])
        {
            Adc_Ipw_EndDmaConversion(LogicalHwUnitId, HwGroupId, FALSE, CoreId);
        }
        else
#endif /* ADC_DMA_SUPPORTED */
        {
            Adc_Ipw_EndConversion(LogicalHwUnitId, HwGroupId, FALSE, CoreId);
        }
    }
    else
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    if (Adc_axUnitStatus[LogicalHwUnitId].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
    {
#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[LogicalHwUnitId])
        {
            Adc_Ipw_EndDmaConversion(LogicalHwUnitId, SwGroupId, TRUE, CoreId);
        }
        else
#endif /* ADC_DMA_SUPPORTED */
        {
            Adc_Ipw_EndConversion(LogicalHwUnitId, SwGroupId, TRUE, CoreId);
        }
    }
#if (ADC_HW_TRIGGER_API == STD_ON)
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
}
#endif  /* (defined(ADC_UNIT_0_ISR_USED) || ... */

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                          ADC HW UNIT 0
==================================================================================================*/
#if (defined(ADC_UNIT_0_ISR_USED) && defined(ADC_UNIT_0_END_CONVERSION_NOTIF_USED))
/**
* @brief          This function handles the ISR for the conversion done of
*                 the ADC Hardware Unit 0.
* @details        The function handles the ISR for the ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0EndConversionNotification(const uint8 ControlChanIdx)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;

    (void)ControlChanIdx;

    Adc_Ipw_EndConversionNotification(PhysicalAdcUnit);
}
#endif /* (defined(ADC_UNIT_0_ISR_USED) && defined(ADC_UNIT_0_END_CONVERSION_NOTIF_USED)) */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_0_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of DMA transfer notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the end of DMA transfer notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;

    Adc_Ipw_EndConversionNotification(PhysicalAdcUnit);
}
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_0_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          ADC HW UNIT 1
==================================================================================================*/
#if (defined(ADC_UNIT_1_ISR_USED) && defined(ADC_UNIT_1_END_CONVERSION_NOTIF_USED))
/**
* @brief          This function handles the ISR for the conversion done of
*                 the ADC Hardware Unit 1.
* @details        The function handles the ISR for the ADC Hardware Unit 1.
*
* @return         void
*
*/
void Adc_Ipw_Adc1EndConversionNotification(const uint8 ControlChanIdx)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;

    (void)ControlChanIdx;

    Adc_Ipw_EndConversionNotification(PhysicalAdcUnit);
}
#endif /* (defined(ADC_UNIT_1_ISR_USED) && defined(ADC_UNIT_1_END_CONVERSION_NOTIF_USED)) */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_1_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of DMA transfer notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the end of DMA transfer notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc1DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;

    Adc_Ipw_EndConversionNotification(PhysicalAdcUnit);
}
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_1_DMA_TRANSFER_USED)) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
