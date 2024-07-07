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
#ifndef ADC_H
#define ADC_H

/**
*   @file    Adc.h
*   @implements      Adc.h_Artifact
*   @addtogroup adc_driver
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
#include "Mcal.h"
#include "Adc_Cfg.h"
#include "Adc_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID                           43
#define ADC_MODULE_ID                           123
#define ADC_AR_RELEASE_MAJOR_VERSION            4
#define ADC_AR_RELEASE_MINOR_VERSION            7
#define ADC_AR_RELEASE_REVISION_VERSION         0
#define ADC_SW_MAJOR_VERSION                    2
#define ADC_SW_MINOR_VERSION                    0
#define ADC_SW_PATCH_VERSION                    0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Mcal header file are of the same AutoSar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Adc.h and Mcal.h are different"
#endif
#endif

/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_VENDOR_ID != ADC_VENDOR_ID_CFG)
#error "Adc.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION_CFG) || \
     (ADC_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION_CFG) || \
     (ADC_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

/* Check if source file and Adc Types header file are of the same vendor */
#if (ADC_VENDOR_ID != ADC_VENDOR_ID_TYPES)
#error "Adc.h and Adc_Types.h have different vendor ids"
#endif

/* Check if source file and Adc Types header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
#error "AutoSar Version Numbers of Adc.h and Adc_Types.h are different"
#endif

/* Check if source file and Adc Types header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION_TYPES) || \
     (ADC_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION_TYPES) \
    )
#error "Software Version Numbers of Adc.h and Adc_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
*       Development errors.
*       The following errors shall be detectable by the ADC module depending on its
*       configuration (development / production mode).
*
*       All error codes
*
*/

/**
* @brief   API service used without Adc module initialization.
* */
#define ADC_E_UNINIT                                 ((uint8)0x0AU)

/**
* @brief   Adc module is busy with a running operation.
* */
#define ADC_E_BUSY                                   ((uint8)0x0BU)

/**
* @brief   Adc module is in idle state.
* */
#define ADC_E_IDLE                                   ((uint8)0x0CU)

/**
* @brief   The ADC module is already initialized.
* */
#define ADC_E_ALREADY_INITIALIZED                    ((uint8)0x0DU)

/**
* @brief   The ADC module is not properly configured.
* */
#define ADC_E_PARAM_CONFIG                           ((uint8)0x0EU)

/**
* @brief   API service is called using an invalid pointer (e.g. the pointer should not be NULL).
* */
#define ADC_E_PARAM_POINTER                          ((uint8)0x14U)

/**
* @brief   API service used with an invalid ADC group.
* */
#define ADC_E_PARAM_GROUP                            ((uint8)0x15U)

/**
* @brief   API service used with an invalid ADC Conversion Mode.
* */
#define ADC_E_WRONG_CONV_MODE                        ((uint8)0x16U)

/**
* @brief   API service used with an invalid ADC Trigger Source.
* */
#define ADC_E_WRONG_TRIGG_SRC                        ((uint8)0x17U)

/**
* @brief   Check the notification capability of a group.
* */
#define ADC_E_NOTIF_CAPABILITY                       ((uint8)0x18U)

/**
* @brief   API service used without initializing the buffer.
* */
#define ADC_E_BUFFER_UNINIT                          ((uint8)0x19U)

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief   One or more ADC group/channel not in IDLE state.
* */
#define ADC_E_NOT_DISENGAGED                        ((uint8)0x1AU)

/**
* @brief   Unsupported power state request.
* */
#define ADC_E_POWER_STATE_NOT_SUPPORTED             ((uint8)0x1BU)

/**
* @brief   Requested power state can not be reached directly.
* */
#define ADC_E_TRANSITION_NOT_POSSIBLE               ((uint8)0x1CU)

/**
* @brief   ADC not prepared for target power state.
* */
#define ADC_E_PERIPHERAL_NOT_PREPARED               ((uint8)0x1DU)
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

/**
* @brief    The Adc_StartGroupConversion and Adc_EnableHardwareTrigger services can not queue
            another conversion (queue is full)
*/
#define ADC_E_QUEUE_FULL                             ((uint8)0x20U)

#if (ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON)
/**
* @brief   An error occurred when the Adc_SetHwUnitPowerMode services is used.
* */
#define ADC_E_SET_HW_UNIT_POWER_MODE                 ((uint8)0x21U)
#endif

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
/**
* @brief   Wrong trigger source to be used for the group.
* */
#define ADC_E_PARAM_TRIGGER                          ((uint8)0x22U)
#endif

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
* @brief   Adc_EnableChannel or Adc_DisableChannel services called with a wrong channel.
* */
#define ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP       ((uint8)0x23U)
/**
* @brief   Adc_EnableChannel or Adc_DisableChannel services called with a wrong channel identifier (ID).
* */
#define ADC_E_WRONG_ENABLE_CH_DISABLE_CH_ID          ((uint8)0x24U)
#endif

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
/**
* @brief   Adc_ConfigureThreshold service is called using wrong values.
* */
#define ADC_E_WRONG_CONF_THRHLD_VALUE                ((uint8)0x25U)
#endif

/**
* @brief   API service called using a wrong ADC unit.
* */
#define ADC_E_PARAM_UNIT                             ((uint8)0x26U)

#if (ADC_CTU_CONTROL_MODE_EXTRA_APIS == STD_ON)
/**
* @brief   API service called using a wrong CTU trigger.
* */
#define ADC_E_WRONG_CTU_TRIGGER                    ((uint8)0x28U)
/**
* @brief   API service called using a wrong CTU CLCR trigger.
* */
#define ADC_E_WRONG_CTU_CLCR_TRIGGER               ((uint8)0x29U)
#endif

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   Adc_SetClockMode service called using an invalid clock mode.
* */
#define ADC_E_INVALID_CLOCK_MODE                     ((uint8)0x29U)
#endif

#if (ADC_SETCHANNEL_API == STD_ON)
/**
* @brief   Adc_SetChannel service called using an invalid channel list.
* */
#define ADC_E_PARAM_CHANNEL                          ((uint8)0x2AU)
#endif

/**
* @brief   An error occurred if the timeout counter variable has expired when checking status flags.
* */
#define ADC_E_TIMEOUT                                ((uint8)0x2BU)

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
/**
* @brief   Error when a function which works only in CTU Control Mode is called when CTU control mode is disabled.
* */
#define ADC_E_CONTROL_MODE_DISABLED                  ((uint8)0x30U)
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */

#define ADC_E_BUFFER_UNINIT_LIST                     ((uint32)0x00000001U)
#define ADC_E_WRONG_TRIGG_SRC_LIST                   ((uint32)0x00000002U)
#define ADC_E_QUEUE_FULL_LIST                        ((uint32)0x00000004U)
#define ADC_E_WRONG_CONV_MODE_LIST                   ((uint32)0x00000008U)
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
#define ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP_LIST  ((uint32)0x00000010U)
#define ADC_E_WRONG_ENABLE_CH_DISABLE_CH_ID_LIST     ((uint32)0x00000020U)
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */

/**
          All AUTOSAR API's service IDs
*/

/**
* @brief API service ID for Adc_Init function
* */
#define ADC_INIT_ID                                  0x00U

/**
* @brief API service ID for Adc_DeInit function
* */
#define ADC_DEINIT_ID                                0x01U

/**
* @brief API service ID for Adc_StartGroupConversion function
* */
#define ADC_STARTGROUPCONVERSION_ID                  0x02U

/**
* @brief API service ID for Adc_StopGroupConversion function
* */
#define ADC_STOPGROUPCONVERSION_ID                   0x03U

/**
* @brief API service ID for Adc_ReadGroup function
* */
#define ADC_VALUEREADGROUP_ID                        0x04U

/**
* @brief API service ID for Adc_EnableHardwareTrigger function
* */
#define ADC_ENABLEHARDWARETRIGGER_ID                 0x05U

/**
* @brief API service ID for Adc_DisableHardwareTrigger function
* */
#define ADC_DISABLEHARDWARETRIGGER_ID                0x06U

/**
* @brief API service ID for Adc_EnableGroupNotification function
* */
#define ADC_ENABLEGROUPNOTIFICATION_ID               0x07U

/**
* @brief API service ID for Adc_DisableGroupNotification function
* */
#define ADC_DISABLEGROUPNOTIFICATION_ID              0x08U

/**
* @brief API service ID for Adc_GetGroupStatus function
* */
#define ADC_GETGROUPSTATUS_ID                        0x09U

/**
* @brief API service ID for Adc_GetVersionInfo function
* */
#define ADC_GETVERSIONINFO_ID                        0x0AU

/**
* @brief API service ID for Adc_GetStreamLastPointer function
* */
#define ADC_GETSTREAMLASTPOINTER_ID                  0x0BU

/**
* @brief API service ID for Adc_SetupResultBuffer function
* */
#define ADC_SETUPRESULTBUFFER_ID                     0x0CU

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief API service ID for Adc_SetPowerState function
* */
#define ADC_SETPOWERSTATE_ID                         0x10U

/**
* @brief API service ID for Adc_GetCurrentPowerState function
* */
#define ADC_GETCURRENTPOWERSTATE_ID                  0x11U

/**
* @brief API service ID for Adc_GetTargetPowerState function
* */
#define ADC_GETTARGETPOWERSTATE_ID                   0x12U

/**
* @brief API service ID for Adc_PreparePowerState function
* */
#define ADC_PREPAREPOWERSTATE_ID                     0x13U
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

/**
*        All Autosar Extension API's service IDs
**       NOTE: Parameters used when raising an error/exception
*/
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
/**
* @brief API service ID for Adc_HwResultReadGroup function
* */
#define ADC_HWRESULTREADGROUP_ID                     0x20U
/**
* @brief API service ID for Adc_EnableCTUTrigge function
* */
#define ADC_ENABLECTUTRIGGER_ID                      0x21U
/**
* @brief API service ID for Adc_DisableCTUTrigger function
* */
#define ADC_DISABLECTUTRIGGER_ID                     0x22U
#endif

#if (ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON)
/**
* @brief API service ID for Adc_SetHwUnitPowerMode function
* */
#define ADC_SET_HW_UNIT_POWER_MODE_ID                0x23U
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
/**
* @brief API service ID for Adc_CtuSetPowerMode function
* */
#define ADC_CTU_SET_POWER_MODE_ID                    0x24U
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
#endif /* (ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON) */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief API service ID for Adc_SetClockMode function
* */
#define ADC_SETCLOCKMODE_ID                          0x25U
#endif

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
* @brief API service ID for Adc_EnableChannel function
* */
#define ADC_ENABLE_CHANNEL_ID                        0x26U
/**
* @brief API service ID for Adc_DisableChannel function
* */
#define ADC_DISABLE_CHANNEL_ID                       0x27U
#endif

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON)
/**
* @brief API service ID for Adc_GetInjectedConversionStatus function
* */
#define ADC_GETINJECTEDCONVERSIONSTATUS_ID           0x28U
#endif

#if (ADC_CALIBRATION == STD_ON)
/**
* @brief API service ID for Adc_Calibrate function
* */
#define ADC_CALIBRATE_ID                             0x29U
#endif

#if (ADC_SELF_TEST == STD_ON)
#define ADC_SELFTEST_ID                              0x2AU
#endif

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
/**
* @brief API service ID for Adc_ConfigureThreshold function
* */
#define ADC_CONFIGURE_THRESHOLD_ID                   0x2BU
#endif

#if (ADC_CTU_CONTROL_MODE_EXTRA_APIS == STD_ON)
/**
* @brief API service ID for Adc_CtuWriteTriggerEnableMask function
* */
#define ADC_CTU_SET_WRITE_TRIG_EN_MASK_ID                (0x2CU)
/**
* @brief API service ID for Adc_CtuSetTriggerEnable function
* */
#define ADC_CTU_SET_TRIGGER_ENABLE_ID                    (0x2DU)
/**
* @brief API service ID for Adc_CtuSetTriggerAdcCmdAddress function
* */
#define ADC_CTU_SET_TRIGGER_ADC_CMD_ADDRESS_ID           (0x2EU)
/**
* @brief API service ID for Adc_CtuSetTriggerCompare function
* */
#define ADC_CTU_SET_TRIGGER_COMPARE_ID                   (0x2FU)
#endif

#if (ADC_SETCHANNEL_API == STD_ON)
/**
* @brief API service ID for Adc_SetChannel function
* */
#define ADC_SETCHANNEL_ID                            (0x30U)
#endif

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
/**
* @brief API service ID for Adc_EnableCtuControlMode function
* */
#define ADC_ENABLE_CTU_CONTROL_MODE_ID               (0x32U)
/**
* @brief API service ID for Adc_DisableCtuControlMode function
* */
#define ADC_DISABLE_CTU_CONTROL_MODE_ID              (0x33U)

#define ADC_CTU_ENABLE_HW_TRIGGER_ID                 (0x34U)
#define ADC_CTU_DISABLE_HW_TRIGGER_ID                (0x35U)
#define ADC_CTU_START_CONVERSION_ID                  (0x36U)
#define ADC_CTU_READ_CONV_DATA_ID                    (0x37U)
#define ADC_CTU_READ_CONV_RESULT_ID                  (0x38U)
#define ADC_CTU_READ_FIFO_DATA_ID                    (0x39U)
#define ADC_CTU_READ_FIFO_RESULT_ID                  (0x3AU)
#define ADC_CTU_SET_FIFO_WATERMARK_ID                (0x3BU)
#define ADC_CTU_ENABLE_NOTIFICATION_ID               (0x3CU)
#define ADC_CTU_DISABLE_NOTIFICATION_ID              (0x3DU)
#define ADC_CTU_SET_LIST_POINTER_ID                  (0x3EU)
#define ADC_CTU_SET_LIST_ID                          (0x3FU)
#define ADC_CTU_STOP_LOOP_CONVERSION_ID              (0x40U)
#define ADC_CTU_MASTER_RELOAD_ID                     (0x41U)
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */

#if (ADC_ENABLE_READ_RAW_DATA_API == STD_ON)
#define ADC_ENABLE_READ_RAW_DATA_ID                  (0x42U)
#endif /* (ADC_ENABLE_READ_RAW_DATA_API == STD_ON) */

#ifdef ADC_WDG_SUPPORTED
#define ADC_ENABLEWDGNOTIFICATION_ID                 (0x43U)
#define ADC_DISABLEWDGNOTIFICATION_ID                (0x44U)
#endif /* ADC_WDG_SUPPORTED */

#if (ADC_ENABLE_TEMPSENSE_API == STD_ON)
#define ADC_TEMPSENSE_CALCULATE_TEMP_ID              (0x4AU)
#define ADC_TEMPSENSE_GET_TEMP_ID                    (0x4BU)
#endif /* (ADC_ENABLE_TEMPSENSE_API == STD_ON) */



/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
/**
* @brief          Used to point the configuration structure.
*/
extern const Adc_ConfigType * Adc_apxCfgPtr[ADC_MAX_PARTITIONS];
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
/**
* @brief          Clock mode in use
*/
extern Adc_SelectPrescalerType Adc_aeClockMode[ADC_MAX_PARTITIONS];
#endif /*if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)*/
#endif /*if (ADC_DUAL_CLOCK_MODE == STD_ON)*/

extern Adc_GroupStatusType Adc_axGroupStatus[ADC_MAX_GROUPS];
extern Adc_UnitStatusType Adc_axUnitStatus[ADC_IPW_MAX_HW_UNITS];
#if (ADC_SETCHANNEL_API == STD_ON)
extern Adc_RuntimeGroupChannelType Adc_axRuntimeGroupChannel[ADC_MAX_GROUPS];
#endif /*(ADC_SETCHANNEL_API == STD_ON)*/
#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

#if (ADC_PRECOMPILE_SUPPORT == STD_ON)
    #define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Adc_MemMap.h"
    extern const Adc_ConfigType * const Adc_ConfigVariantPredefined[ADC_MAX_PARTITIONS];
    #define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Adc_MemMap.h"
#else
    #define ADC_START_SEC_CONST_UNSPECIFIED
    #include "Adc_MemMap.h"

    ADC_CONFIG_EXT

    #define ADC_STOP_SEC_CONST_UNSPECIFIED
    #include "Adc_MemMap.h"
#endif /* (ADC_PRECOMPILE_SUPPORT == STD_ON) */

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
* @brief          Initializes the ADC hardware unit and the driver.
* @details        This function will initialize both the ADC HW unit and the driver structures.
*
* @param[in]      ConfigPtr   Pointer to configuration set in Variant PB
*                             (Variant PC requires a NULL_PTR).
* @return         void
*
* @implements  Adc_Init_Activity
*/
void Adc_Init(const Adc_ConfigType * ConfigPtr);

/**
* @brief          Initializes the group specific ADC result buffer pointer as
*                 configured to point to the pDataBufferPtr address which is
*                 passed as parameter.
* @details        Initializes ADC driver with the group specific result buffer
*                 start address where the conversion results will be stored.
*                 The application has to ensure that the application buffer,
*                 where pDataBufferPtr points to, can hold all the conversion
*                 results of the specified group. The initialization with
*                 Adc_SetupResultBuffer is required after reset, before a group
*                 conversion can be started.
*
* @param[in]      Group           Numeric ID of requested ADC channel group.
* @param[in]      pDataBufferPtr   Pointer to result data buffer
*
* @return         Std_ReturnType  Standard return type.
*                 E_OK:           Result buffer pointer initialized correctly.
*                 E_NOT_OK:       Operation failed or development error
*                                 occurred.
*
* @implements  Adc_SetupResultBuffer_Activity
*/
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group,
                                     Adc_ValueGroupType * const DataBufferPtr);

#if (ADC_DEINIT_API == STD_ON)
/**
* @brief          Returns all ADC HW Units to a state comparable to their
*                 power on reset state.
* @details        Returns all ADC HW Units to a state comparable to their
*                 power on reset state, and de-initialize the ADC driver.
*
* @return         void
*
* @implements  Adc_DeInit_Activity
*/
void Adc_DeInit(void);
#endif /* ADC_DEINIT_API == STD_ON */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
* @brief          Starts the conversion of all channels of
*                 the requested ADC Channel group.
* @details        This function will start the SW conversion of all channels
*                 of the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @implements  Adc_StartGroupConversion_Activity
*/
void Adc_StartGroupConversion(Adc_GroupType Group);

/**
* @brief          Stops the conversion of all channels of the requested ADC
*                 Channel group.
* @details        This function will stop the SW conversion of all channels
*                 of the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @implements  Adc_StopGroupConversion_Activity
*/
void Adc_StopGroupConversion(Adc_GroupType Group);

#endif /* ADC_ENABLE_START_STOP_GROUP_API == STD_ON */

#if (ADC_READ_GROUP_API == STD_ON)
/**
* @brief          Reads the group conversion results.
* @details        Reads the group conversion results of the last completed
*                 conversion round of the requested group and stores the
*                 channel values starting at the pDataBufferPtr address.
*                 The group channel values are stored in ascending channel
*                 number order (in contrast to the storage layout of the
*                 result buffer if streaming access is configured).
*
* @param[in]      Group          Numeric ID of requested ADC Channel group.
* @param[in]      pDataBufferPtr  ADC results of all channels of the selected group
*                                are stored in the data buffer addressed with the pointer.
* @return         Std_ReturnType Standard return type.
*                 E_OK:          results are available and written to the
*                                data buffer.
*                 E_NOT_OK:      no results are available or development
*                                error occurred.
*
* @implements  Adc_ReadGroup_Activity
*/
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group,
                             Adc_ValueGroupType * DataBufferPtr);

#endif /* ADC_READ_GROUP_API == STD_ON */

#if (ADC_ENABLE_READ_RAW_DATA_API == STD_ON)
/**
* @brief        Read the raw result data from an ADC unit.
* @details      Read the raw result data from an ADC unit.
*               Intended for reading ADC results directly from ADC registers
*               and can eliminate surplus interrupts if there are more triggered
*               measurements than FIFO length.
*               Measured values remain in ADC result registers(user must ensure
*               that they are not overwritten).
*
* @param[in]    Unit           Adc unit used. Recommended to use generated define for Adc Logical Unit Id.
* @param[in]    ChansArray     List of channels for which results to be read
* @param[in]    NumItems       Number of results to read
* @param[out]   DataBufferPtr  Destination pointer in which the results will be written
*
* @return         void
*
* @implements  Adc_ReadRawData_Activity
*/
void Adc_ReadRawData(Adc_HwUnitType Unit,
                     const Adc_ChannelType * const ChansArray,
                     uint8 NumItems,
                     Adc_ValueGroupType * const DataBufferPtr);

#endif /* (ADC_ENABLE_READ_RAW_DATA_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
* @brief          Enables the hardware trigger for the requested ADC Channel group.
* @details        This function will enable the HW trigger source for the requested
*                 ADC channel group. This function does set the CTU register for all
*                 platform that have the CTU Hw Unit.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @implements  Adc_EnableHardwareTrigger_Activity
*/
void Adc_EnableHardwareTrigger(Adc_GroupType Group);

/**
* @brief          Disables the hardware trigger for the requested ADC Channel group.
* @details        This function will disable the HW trigger source for the requested
*                 ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @implements  Adc_DisableHardwareTrigger_Activity
*/
void Adc_DisableHardwareTrigger(Adc_GroupType Group);

#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/**
* @brief          Enables the notification mechanism for the requested ADC
*                 channel group.
* @details        This function will enable the notification mechanism only for
*                 the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @implements  Adc_EnableGroupNotification_Activity
*/
void Adc_EnableGroupNotification(Adc_GroupType Group);

/**
* @brief          Disables the notification mechanism for the requested ADC
*                 channel group.
* @details        This function will disable the notification mechanism only for
*                 the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @implements  Adc_DisableGroupNotification_Activity
*/
void Adc_DisableGroupNotification(Adc_GroupType Group);

#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

/**
* @brief          Returns the conversion status of the requested ADC Channel group.
* @details        This function will return the conversion status of the requested
*                 ADC channel group.
*
* @param[in]      Group             Numeric ID of requested ADC channel group.
* @return         Adc_StatusType    Conversion status for the requested group.
*                 ADC_IDLE          in case of errors.
*                 conversion status in case of no errors.
*
* @implements  Adc_GetGroupStatus_Activity
*/
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group);

/**
* @brief          Returns the number of valid samples per channel.
* @details        Returns the number of valid samples per channel, stored in
*                 the result buffer. Reads a pointer, pointing to a position
*                 in the group result buffer. With the pointer position, the
*                 results of all group channels of the last completed conversion
*                 round can be accessed. With the pointer and the return value,
*                 all valid group conversion results can be accessed (the user
*                 has to take the layout of the result buffer into account).
*
* @param[in]      Group              Numeric ID of requested ADC channel group.
* @param[out]     PtrToSamplePtr     Pointer to result buffer pointer.
*
* @return         Adc_StreamNumSampleType Number of valid samples per channel.
*                 0                 in case of errors.
*                 >0                Number of valid samples per channel.
*
* @implements  Adc_GetStreamLastPointer_Activity
*/
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group,
                                                 Adc_ValueGroupType ** PtrToSamplePtr);

#if (ADC_VERSION_INFO_API == STD_ON)
/**
* @brief          Returns the version information of this module.
* @details        Returns the version information of this module.
*
* @param[out]     pVersionInfo    Pointer to where to store the version
*                                 information of this module.
*                 structure       in case of no errors.
*
* @implements  Adc_GetVersionInfo_Activity
*/
void Adc_GetVersionInfo(Std_VersionInfoType * versioninfo);

#endif /* ADC_VERSION_INFO_API == STD_ON */

#if (ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON)
/**
* @brief          Set the ADC mode either to powerdown or normal.
* @details        Set the ADC either to powerdown or normal mode.
*
* @param[in]      Unit            Adc unit used. Recommended to use generated define for Adc Logical Unit Id
* @param[in]      SetPowerMode    Power mode to set: normal or powerdown.
*
* @return         Std_ReturnType  Standard return type.
*                 E_OK:           Transition successful.
*                 E_NOT_OK:       Transition unsuccessful.
*
* @implements  Adc_SetHwUnitPowerMode_Activity
*/
Std_ReturnType Adc_SetHwUnitPowerMode(Adc_HwUnitType Unit,
                                      Adc_SetPowerModeType SetPowerMode);

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
/**
* @brief   Function to set BCTU/CTU power mode.
*
* @details Set BCTU/CTU power mode.
*
* @param[in] CtuUnit   Bctu/Ctu hardware unit. Recommended to use generated define for Bctu/Ctu Logical Unit Id.
* @param[in] State     Power state to be set
*
* @return         Std_ReturnType  Standard return type.
*                 E_OK:           Transition successful.
*                 E_NOT_OK:       Transition unsuccessful.
*
* @implements  Adc_CtuSetPowerMode_Activity
*/
Std_ReturnType Adc_CtuSetPowerMode(Adc_HwUnitType CtuUnit,
                                   Adc_PowerStateType State);

#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
#endif /* (ADC_SET_HW_UNIT_POWER_MODE_API == STD_ON) */

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
/**
* @brief          Enable the TriggerSource for group selected by Group parameter.
* @details        This Autosar Extension API is used to enable any one of the configured
*                 TriggerSource of the Group. When this Autosar Extension API is used to
*                 enable the trigger source the CTU interrupt will be disabled by the driver.
*                 So user has to call the Autosar Extension API Adc_HwResultReadGroup to read
*                 the converted result from the ADC hardware register.
*
* @param[in]      Group            Index of group.
* @param[in]      TriggerSource    Trigger source to be used for the group.
*                                  (Configuration file should contain it for that group).
* @return         void
*
* @implements  Adc_EnableCTUTrigger_Activity
*/
void Adc_EnableCTUTrigger(Adc_GroupType Group,
                          Adc_HwTriggerTimerType TriggerSource);

/**
* @brief          Disable the TriggerSource for group selected by Group parameter.
* @details        This Autosar Extension API is used to disable the already enabled
*                 TriggerSource of the Group.
*
* @param[in]      Group            Index of group.
* @param[in]      TriggerSource    Trigger source to be disabled for the group.
*                                  (Configuration file should contain it for that group).
* @return         void
*
* @implements  Adc_DisableCTUTrigger_Activity
*/
void Adc_DisableCTUTrigger(Adc_GroupType Group,
                           Adc_HwTriggerTimerType TriggerSource);

/**
* @brief          Read the result of the hardware triggered groups conversion result.
* @details        This Autosar Extension API is used to read the result of the hardware
*                 triggered groups conversion result from the ADC hardware register
*                 in this case the CTU interrupt will be disabled for the group.
*                 The VALID bit CDR register will be cleared automatically when we read the results
*                 from the channel data register. If the user calls Autosar Extension function
*                 Adc_HwResultReadGroup() once again before the next conversion takes place, the
*                 Adc_HwResultReadGroup() returns E_NOT_OK.
*
* @param[in]      Group      Index of group.
* @param[in]      DataPtr    Pointer to a buffer which will be filled by the
*                            conversion results.
* @return         Std_ReturnType Standard return type.
*                 E_OK:          results are available and written to the
*                                data buffer.
*                 E_NOT_OK:      no results are available or development
*                                error occurred.
*
* @implements  Adc_HwResultReadGroup_Activity
*/
Std_ReturnType Adc_HwResultReadGroup(Adc_GroupType Group,
                                     Adc_ValueGroupType * DataPtr);

#endif /* ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
 * @brief   Enable an individual channel configured in SW-triggered (non-injected) ADC Group at initialization
 * @details Enable an individual channel configured in SW-triggered (non-injected) ADC Group at initialization
 *          Use generated symbolic channel name defines (e.g. AdcChannel_0_0), because function assumes ChannelId to be in following format:
 *          Logical channel id on bits until position defined by ADC_CHANNEL_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16, and for the rest the Logical Unit Id
 *          The driver will not update the values in result buffers corresponding to disabled channels, keeping in the buffer the last results from when the channel was enabled.
 *
 * @param[in]  Adc_GroupType                Group logical ID or group symbolic name
 * @param[in]  Adc_ChannelType              Symbolic name of channel
 *
 * @return         void.
 *
 * @implements      Adc_EnableChannel_Activity
 */
void Adc_EnableChannel(Adc_GroupType Group,
                       Adc_ChannelType Channel);

/**
 * @brief   Disable an individual channel configured in SW-triggered (non-injected) ADC Group at initialization
 * @details Disable an individual channel configured in SW-triggered (non-injected) ADC Group at initialization
 *          Use generated symbolic channel name defines (e.g. AdcChannel_0_0), because function assumes ChannelId to be in following format:
 *          Logical channel id on bits until position defined by ADC_CHANNEL_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16, and for the rest the Logical Unit Id
 *          The driver will not update the values in result buffers corresponding to disabled channels, keeping in the buffer the last results from when the channel was enabled.
 *
 * @param[in]  Adc_GroupType                Group logical ID or group symbolic name
 * @param[in]  Adc_ChannelType              Symbolic name of channel
 *
 * @return         void.
 *
 * @implements      Adc_DisableChannel_Activity
 */
void Adc_DisableChannel(Adc_GroupType Group,
                        Adc_ChannelType Channel);

#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON)
/**
* @brief          Get the injected conversions status.
* @details        This function checks if an injected conversion (HW,SW) is ongoing
*
* @param[in]      Unit            Adc unit used. Recommended to use generated define for Adc Logical Unit Id
*
* @return         Adc_StatusType  Status of the ADC HW unit.
*                 ADC_IDLE:       SW,HW Injection or Hardware Trigger group are idle.
*                 ADC_BUSY:       SW,HW Injection or Hardware Trigger is in progress.
*
* @implements  Adc_GetInjectedConversionStatus_Activity
*/
Adc_StatusType Adc_GetInjectedConversionStatus(Adc_HwUnitType Unit);

#endif /* ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON */

#if (ADC_CALIBRATION == STD_ON)
/**
* @brief          Executes high accuracy calibration of a ADC HW unit.
* @details        This function calibrates the ADC HW unit and updates calibration related registers
*
* @param[in]      Unit      Adc unit used. Recommended to use generated define for Adc Logical Unit Id
* @param[in]      pStatus   Status of the ADC HW unit calibration and
*                           list of failed and passed tests.
*
* @return         void
*
* @implements  Adc_Calibrate_Activity
*/
void Adc_Calibrate(Adc_HwUnitType Unit,
                   Adc_CalibrationStatusType * pStatus);

#endif /* (ADC_CALIBRATION == STD_ON) */


#if (ADC_SELF_TEST == STD_ON)
/**
* @brief          Executes hardware Self Test of a ADC HW unit.
* @details        This function checks if the ADC HW unit is functioning correctly
*
* @param[in]      Unit      Adc unit used. Recommended to use generated define for Adc Logical Unit Id
*
* @return         Std_ReturnType. Status of the ADC HW unit Self Test.
*
* @implements  Adc_SelfTest_Activity
*/
Std_ReturnType Adc_SelfTest(Adc_HwUnitType Unit);

#endif /* (ADC_SELF_TEST == STD_ON) */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
/**
* @brief      Function to reconfigure High and Low thresholds for a given threshold control index.
* @details    This function is used to reconfigure High and Low thresholds for a given threshold control index.
*             Use generated symbolic name defines of threshold register (e.g. AdcThresholdControl_0_0), because function assumes ThresholdControlIndex to be in following format:
*             Logical threshold id on bits until position defined by ADC_THRESHOLD_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16, and for the rest the Logical Unit Id
*
* @param[in]  ThresholdControlIndex       Symbolic name of threshold control
* @param[in]  LowValue                    Low threshold value of the threshold control
* @param[in]  HighValue                   High threshold value of the threshold control
*
* @return     void
*
* @implements      Adc_ConfigureThreshold_Activity
*/
void Adc_ConfigureThreshold(Adc_ThresholdControlIndexType ThresholdControlIndex,
                            Adc_WdgThresholdValueType LowValue,
                            Adc_WdgThresholdValueType HighValue);

#endif /*  ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON */

#ifdef ADC_WDG_SUPPORTED
/**
 * @brief   Enable notification of a channel that has watchdog functionality configured at initialization
 * @details Enable notification of a channel that has watchdog functionality configured at initialization
 *          Use generated symbolic channel name defines (e.g. AdcChannel_0_0), because function assumes ChannelId to be in following format:
 *          Logical channel id on bits until position defined by ADC_CHANNEL_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16, and for the rest the Logical Unit Id
 *
 * @param[in]  Adc_ChannelType              Symbolic name of channel
 *
 * @return         void.
 *
 * @implements      Adc_EnableWdgNotification_Activity
 */
void Adc_EnableWdgNotification(Adc_ChannelType ChannelId);

/**
 * @brief   Disable notification of a channel that has watchdog functionality configured at initialization
 * @details Disable notification of a channel that has watchdog functionality configured at initialization
 *          Use generated symbolic channel name defines (e.g. AdcChannel_0_0), because function assumes ChannelId to be in following format:
 *          Logical channel id on bits until position defined by ADC_CHANNEL_SYMBOLIC_NAME_SHIFT_HW_UNIT_ID_U16, and for the rest the Logical Unit Id
 *
 * @param[in]  Adc_ChannelType              Symbolic name of channel
 *
 * @return         void.
 *
 * @implements      Adc_DisableWdgNotification_Activity
 */
void Adc_DisableWdgNotification(Adc_ChannelType ChannelId);

#endif /* ADC_WDG_SUPPORTED */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          Set the ADC clock prescaler if available and modify the conversion timings.
* @details        This function sets the ADC clock prescaler (Analog clock frequency selector)
*
* @param[in]      Prescaler      Normal or Alternate mode.
*
* @return         Std_ReturnType  Standard return type.
*                 E_OK:           In case of successful settings.
*                 E_NOT_OK:       In case of unsuccessful settings.
*
* @implements  Adc_SetClockMode_Activity
*/
Std_ReturnType Adc_SetClockMode(Adc_SelectPrescalerType Prescaler);

#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (ADC_CTU_CONTROL_MODE_EXTRA_APIS == STD_ON)
/**
* @brief   Function to set the trigger handler control registers of the CTU IPL.
*
* @details Full configurability of CTU THCR1 & THCR2 registers of the CTU IPL.
*          This function has in input the CTU trigger (0...7) and the mask (8 bit)
*          to enable the External Trigger and Timer output for that Trigger, without considering
*          the ADC command output enable.
*          See from the RM the THCR1 and THCR2 registers for the right Thcr_value to use.
*
* @note    The function Service ID[hex]: 0x35.
*
* @param[in]  Trigger     Index of the trigger: 0...7.
* @param[in]  ThcrValue   THCRx mask value (only with bits for Ext. Trigger and Timer) for the selected input trigger.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
*                 E_OK            In case of successful settings.
*                 E_NOT_OK        In case of unsuccessful settings.
*
* @implements  Adc_CtuWriteTriggerEnableMask_Activity
*/
Std_ReturnType Adc_CtuWriteTriggerEnableMask(Adc_CtuTrigSrcType Trigger,
                                             uint8 ThcrValue);

/**
* @brief   Function to set or clear the bit Tx_E of the trigger handler control registers of the CTU IPL.
*
* @details Full configurability of CTU THCR1 & THCR2 registers of the CTU IPL.
*          This function has in input the CTU trigger (0...7) and a Boolean to set to clear the right trigger bit.
*          See from the RM the THCR1 and THCR2 registers for the right API use.
*
* @param[in]  Trigger    Index of the trigger: 0...7.
* @param[in]  Enable     if True, the bit Tx_E shall be set to 1, 0 otherwise
*
* @note    The function Service ID[hex]: 0x36.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
*                 E_OK            In case of successful settings.
*                 E_NOT_OK        In case of unsuccessful settings.
*
* @implements  Adc_CtuSetTriggerEnable_Activity
*/
Std_ReturnType Adc_CtuSetTriggerEnable(Adc_CtuTrigSrcType Trigger,
                                       boolean Enable);

/**
* @brief   Function to set the cmd list handler control registers of the CTU IPL.
*
* @details Full configurability of CLCR1 & CLCR2 registers of the CTU IPL.
*          This function has in input the CTU trigger (0...7) and  the position of the first
*          command in the command list.
*          See from the RM the CLCR1 and CLCR2 registers for the right API use.
*
* @param[in]  Trigger      Index of the trigger: 0...7.
* @param[in]  ClcrValue    Position of the first command
*
* @note    The function Service ID[hex]: 0x37.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
*                 E_OK            In case of successful settings.
*                 E_NOT_OK        In case of unsuccessful settings.
*
* @implements  Adc_CtuSetTriggerAdcCmdAddress_Activity
*/
Std_ReturnType Adc_CtuSetTriggerAdcCmdAddress(Adc_CtuTrigSrcType Trigger,
                                              uint8 ClcrValue);

/**
* @brief   Function to set the trigger compare registers of the CTU IPL.
*
* @details Full configurability of CTU TxCR registers of the CTU IPL.
*          This function has in input the CTU trigger (0...7) and the comparator value
*          See from the RM the TxCR trigger compare registers for the right compare_value to use.
*
* @note    The function Service ID[hex]: 0x38.
*
* @param[in]  Trigger       Index of the trigger: 0...7.
* @param[in]  CompareValue  value to set in the register TxCR.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
*                 E_OK            In case of successful settings.
*                 E_NOT_OK        In case of unsuccessful settings.
*
* @implements  Adc_CtuSetTriggerCompare_Activity
*/
Std_ReturnType Adc_CtuSetTriggerCompare(Adc_CtuTrigSrcType Trigger,
                                        uint16 CompareValue);

#endif /* (ADC_CTU_CONTROL_MODE_EXTRA_APIS == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
/**
* @brief   Function to dynamic handling of ADC channels list for Adc channel group.
*
* @details Dynamic handling of ADC channels list.
*          This function to dynamic handling of ADC channels list for Adc channel group.
* @param[in]  Group                     Group Id.
* @param[in]  Channel                   Pointer to array of channels to be reconfigured for the group. Channel value is logical channel ID.
* @param[in]  Delays                    Pointer to array of delay value associated with array of channels to be reconfigured.
* @param[in]  ChannelUpdateMask         Bitmask selecting which channels to be reconfigured.
* @param[in]  NumberOfChannel           Number of channels in channels array.
*
* @note    For platforms supporting delays (Only if ADC_IPW_DELAY_AVAILABLE == STD_ON):
*          Delays:
*           - If NULL_PTR: channel delay values are not reconfigured.
*           - If group has configured only 1 delay: pointer to new delay value.
*           - If group has configured delay for each channel: array with new delay values - number of elements must be NumberOfChannel.

*          ChannelUpdateMask:
*           - Bitmask example: 0b0110 only reconfigures channels from positions 1 and 2.
*           - This bit mask can be used only if number of group channels are not greater than number of SC1 registers
*           - Last bit of this mask must be set for having interrupt if NumberOfChannel is different than number of configured channels.
*
* @implements  Adc_SetChannel_Activity
*/
void Adc_SetChannel(Adc_GroupType Group,
                    const Adc_GroupDefType * Channel,
#if (ADC_IPW_DELAY_AVAILABLE == STD_ON)
                    const uint16 * Delays,
                    uint32 ChannelUpdateMask,
#endif /* (ADC_IPW_DELAY_AVAILABLE == STD_ON) */
                    Adc_ChannelIndexType NumberOfChannel);

#endif /* ADC_SETCHANNEL_API == STD_ON */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief          Enters the already prepared power state.
* @details        This API configures the Adc module so that it enters the already prepared power
*                 state, chosen between a predefined set of configured ones.
*
* @param[out]     Result        Pointer to a variable to store the result of this function
*
* @return         Std_ReturnType  Standard return type.
*                 E_OK:           Power Mode changed.
*                 E_NOT_OK:       Request rejected.
*
* @implements  Adc_SetPowerState_Activity
*/
Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType * Result);

/**
* @brief          Get the current power state of the ADC HW unit.
* @details        This API returns the current power state of the ADC HW unit.
*
* @param[out]     CurrentPowerState     The current power mode of the ADC HW Unit is returned in this parameter
* @param[out]     Result                Pointer to a variable to store the result of this function
*
* @return         Std_ReturnType  Standard return type.
*                 E_OK:           Mode could be read.
*                 E_NOT_OK:       Service is rejected.
*
* @implements  Adc_GetCurrentPowerState_Activity
*/
Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType * CurrentPowerState,
                                        Adc_PowerStateRequestResultType * Result);

/**
* @brief          Get the target power state of the ADC HW unit.
* @details        This API returns the target power state of the ADC HW unit.
*
* @param[out]     TargetPowerState      The Target power mode of the ADC HW Unit is returned in this parameter.
* @param[out]     Result                Pointer to a variable to store the result of this function.
*
* @return         Std_ReturnType  Standard return type.
*                 E_OK:           Mode could be read.
*                 E_NOT_OK:       Service is rejected.
*
* @implements  Adc_GetTargetPowerState_Activity
*/
Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType * TargetPowerState,
                                       Adc_PowerStateRequestResultType * Result);

/**
* @brief          Starts the needed process to allow the ADC HW module to enter the requested power state.
* @details        This API starts the needed process to allow the ADC HW module to enter the requested power state.
*
* @param[in]      PowerState      The target power state intended to be attained.
* @param[out]     Result          Pointer to a variable to store the result of this function.
*
* @return         Std_ReturnType  Standard return type.
*                 E_OK:           Mode could be read.
*                 E_NOT_OK:       Service is rejected.
*
* @implements  Adc_PreparePowerState_Activity
*/
Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType PowerState,
                                     Adc_PowerStateRequestResultType * Result);

#if (ADC_POWER_STATE_ASYNCH_MODE_SUPPORTED == STD_ON)
/**
* @brief          Cyclically called and supervises the power state transitions.
* @details        This API is cyclically called and supervises the power state transitions, checking for the readiness of the module and issuing the callbacks.
*
* @param[in]      none
* @param[out]     none
*
* @return         void
*/
void Adc_Main_PowerTransitionManager(void);
#endif /* (ADC_POWER_STATE_ASYNCH_MODE_SUPPORTED == STD_ON) */
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
/**
* @brief   Function to enable CTU control mode for an ADC unit.
*
* @details Enable CTU control mode for an ADC unit.
*          This function to enable CTU control mode for Adc. When a unit works in CTU control mode,
*          no other conversions shall run in parallel(Adc). The only conversions occurring shall be
*          the ones defined in the CTU configuration.
*
* @param[in]  Unit      Adc unit used. Recommended to use generated define for Adc Logical Unit Id (e.g: AdcHwUnit_0)
*
* @return         void
*
* @implements  Adc_EnableCtuControlMode_Activity
*/
void Adc_EnableCtuControlMode(Adc_HwUnitType Unit);

/**
* @brief   Function to disable CTU control mode for an ADC unit.
*
* @details Disable CTU control mode for an ADC unit.
*          This function to disable CTU control mode for Adc. The other Adc conversions can run in
*          software trigger normal mode, software trigger injected mode or hardware trigger mode.
*
* @param[in]  Unit      Adc unit used. Recommended to use generated define for Adc Logical Unit Id (e.g: AdcHwUnit_0)
*
* @return         void
*
* @implements  Adc_DisableCtuControlMode_Activity
*/
void Adc_DisableCtuControlMode(Adc_HwUnitType Unit);

/**
* @brief   Function to enable CTU hardware trigger.
*
* @details Enable CTU hardware trigger.
*
* @param[in]  TrigSource      Symbolic name of source trigger index (e.g CtuHwUnit_0_CtuTriggerCfg_0; BctuHwUnit_0_BctuInternalTrigger_0)
*                             Symbolic name format:
*                              - Bit fields [15-8]: The CTU Logical Unit Id
*                              - Bit fields [7-0]: Trigger Control index in CTU unit.
*
* @return         void
*
* @implements  Adc_CtuEnableHwTrigger_Activity
*/
void Adc_CtuEnableHwTrigger(Adc_CtuTrigSrcType TrigSource);

/**
* @brief   Function to disable CTU hardware trigger.
*
* @details Disable CTU hardware trigger.
*
* @param[in]  TrigSource      Symbolic name of source trigger index (e.g CtuHwUnit_0_CtuTriggerCfg_0; BctuHwUnit_0_BctuInternalTrigger_0)
*                             Symbolic name format:
*                              - Bit fields [15-8]: The CTU Logical Unit Id
*                              - Bit fields [7-0]: Trigger Control index in CTU unit.
*
* @return         void
*
* @implements  Adc_CtuDisableHwTrigger_Activity
*/
void Adc_CtuDisableHwTrigger(Adc_CtuTrigSrcType TrigSource);

/**
* @brief   Function to start CTU conversion.
*
* @details Start CTU conversion.
*
* @param[in]  TrigSource      Symbolic name of source trigger index (e.g CtuHwUnit_0_CtuTriggerCfg_0; BctuHwUnit_0_BctuInternalTrigger_0)
*                             Symbolic name format:
*                              - Bit fields [15-8]: The CTU Logical Unit Id
*                              - Bit fields [7-0]: Trigger Control index in CTU unit.
*
* @return         void
*
* @implements  Adc_CtuStartConversion_Activity
*/
void Adc_CtuStartConversion(Adc_CtuTrigSrcType TrigSource);

#if (ADC_IPW_CTU_AVAILABLE == STD_ON)
/**
* @brief   Issue a software master reload signal for CTU.
*
* @details Issue a software master reload signal for CTU in CTU Control Mode.
*
* @param[in]    CtuUnit     CTU hardware unit. Recommended to use generated define for Ctu Logical Unit Id (e.g: CtuHwUnit_0)
*
* @return       void
*
* @implements  Adc_CtuMasterReload_Activity
*/
void Adc_CtuMasterReload(Adc_HwUnitType CtuUnit);

#endif /* (ADC_IPW_CTU_AVAILABLE == STD_ON) */

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
/**
* @brief   Function to read BCTU conversion data.
*
* @details Read CTU conversion data.
*
* @param[in]    AdcUnit             Adc HW unit. Recommended to use generated define for Adc Logical Unit Id.
*
* @return       Adc_ValueGroupType  Conversion result.
*
* @implements  Adc_CtuReadConvData_Activity
*/
Adc_ValueGroupType Adc_CtuReadConvData(Adc_HwUnitType AdcUnit);

/**
* @brief   Function to read BCTU conversion result.
*
* @details Read BCTU conversion result.
*
* @param[in]    AdcUnit      Adc HW unit. Recommended to use generated define for Adc Logical Unit Id.
* @param[out]   pResult      Adc result structure.
*
* @return       void
*
* @implements  Adc_CtuReadConvResult_Activity
*/
void Adc_CtuReadConvResult(Adc_HwUnitType AdcUnit,
                           Adc_CtuResultType * pResult);

/**
* @brief   Function to stop CTU loop conversion.
*
* @details Stop CTU loop conversions.
*
* @param[in]  TrigSource      Symbolic name of source trigger index (e.g CtuHwUnit_0_CtuTriggerCfg_0; BctuHwUnit_0_BctuInternalTrigger_0)
*                             Symbolic name format:
*                              - Bit fields [15-8]: The CTU Logical Unit Id
*                              - Bit fields [7-0]: Trigger Control index in CTU unit.
*
* @return         void
*
* @implements  Adc_CtuStopLoopConversions_Activity
*/
void Adc_CtuStopLoopConversions(Adc_CtuTrigSrcType TrigSource);

#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */

/**
* @brief   Function to read CTU conversion data from FIFO.
*
* @details Read CTU conversion data from FIFO.
*
* @param[in]   FifoIdx      Symbolic name of CTU FIFO index (e.g: CtuHwUnit_0_CtuResultFifos_0; BctuHwUnit_0_BctuResultFifos_0)
*                           Symbolic name format:
*                            - Bit fields [15-8]: The CTU Logical Unit Id
*                            - Bit fields [7-0]: FIFO index in CTU unit.
* @param[out]  Data         Pointer to pre-allocated result array.
* @param[in]   DataLength   Max amount of results to be read.
*
* @return         void
*
* @implements  Adc_CtuReadFifoData_Activity
*/
void Adc_CtuReadFifoData(Adc_CtuFifoIdxType FifoIdx,
                         uint16 * Data,
                         uint8 DataLength);

/**
* @brief   Function to read CTU conversion results from FIFO.
*
* @details Read CTU conversion results from FIFO.
*
* @param[in]   FifoIdx      Symbolic name of CTU FIFO index (e.g: CtuHwUnit_0_CtuResultFifos_0; BctuHwUnit_0_BctuResultFifos_0)
*                           Symbolic name format:
*                            - Bit fields [15-8]: The CTU Logical Unit Id
*                            - Bit fields [7-0]: FIFO index in CTU unit.
* @param[out]  Result           Pointer to pre-allocated result array.
* @param[in]   ResultLength     Max amount of results to be read.
*
* @return         void
*
* @implements  Adc_CtuReadFifoResult_Activity
*/
void Adc_CtuReadFifoResult(Adc_CtuFifoIdxType FifoIdx,
                           Adc_CtuFifoResultType * Result,
                           uint8 ResultLength);

/**
* @brief   Function to set CTU FIFO watermark.
*
* @details Set CTU FIFO watermark.
*
* @param[in]   FifoIdx      Symbolic name of CTU FIFO index (e.g: CtuHwUnit_0_CtuResultFifos_0; BctuHwUnit_0_BctuResultFifos_0)
*                           Symbolic name format:
*                            - Bit fields [15-8]: The CTU Logical Unit Id
*                            - Bit fields [7-0]: FIFO index in CTU unit.
* @param[in]   Watermark    Watermark value.
*
* @return         void
*
* @implements  Adc_CtuSetFifoWatermark_Activity
*/
void Adc_CtuSetFifoWatermark(Adc_CtuFifoIdxType FifoIdx,
                             uint8 Watermark);

/**
* @brief   Function to enable CTU notification.
*
* @details Enable CTU notification.
*
* @param[in] Notification  Notification to be enabled.
* Note: CTU logical mask must be 'OR'ed together with other notification masks (e.g: ADC_IPW_CTU_NOTIF_CTU_LOGICAL_0 | ADC_IPW_CTU_NOTIF_FIFO0_OVERFLOW)
*
* @return         void
*
* @implements  Adc_CtuEnableNotification_Activity
*/
void Adc_CtuEnableNotification(Adc_CtuNotificationType Notification);

/**
* @brief   Function to disable CTU notification.
*
* @details Disable CTU notification.
*
* @param[in] Notification  Notification to be disabled.
* Note: CTU logical mask must be 'OR'ed together with other notification masks (e.g: ADC_IPW_CTU_NOTIF_CTU_LOGICAL_0 | ADC_IPW_CTU_NOTIF_FIFO0_OVERFLOW)
*
* @return         void
*
* @implements  Adc_CtuDisableNotification_Activity
*/
void Adc_CtuDisableNotification(Adc_CtuNotificationType Notification);

/**
* @brief   Function to set CTU list.
*
* @details Reconfigure the CTU list of conversions in CTU Control Mode.
*
* @param[in] CtuUnit           Symbolic names of CTU Hardware units. (CTU logical unit ID)
* @param[in] ListItemsArray    Pointer to list items array to be set.
* @param[in] NumItems          Number of items in the array.
* @param[in] ListStartPosition Start position of the list.
*
* @return         void
*
* @implements  Adc_CtuSetList_Activity
*/
void Adc_CtuSetList(Adc_HwUnitType CtuUnit,
                    const Adc_CtuListItemType * const ListItemsArray,
                    const uint8 NumItems,
                    const uint8 ListStartPosition);

/**
* @brief   Reconfigure the list pointer of a triggered CTU source.
*
* @details Reconfigure the list pointer of a trigger source in CTU Control Mode.
*
* @param[in]  TrigSource      Symbolic name of source trigger index (e.g CtuHwUnit_0_CtuTriggerCfg_0; BctuHwUnit_0_BctuInternalTrigger_0)
*                             Symbolic name format:
*                              - Bit fields [15-8]: The CTU Logical Unit Id
*                              - Bit fields [7-0]: Trigger Control index in CTU unit.
* @param[in] ListPtr           Position of the first channel of the command list.
*
* @return         void
*
* @implements  Adc_CtuSetListPointer_Activity
*/
void Adc_CtuSetListPointer(Adc_CtuTrigSrcType TrigSource,
                           Adc_CtuListPtrType ListPtr);

#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_H */
