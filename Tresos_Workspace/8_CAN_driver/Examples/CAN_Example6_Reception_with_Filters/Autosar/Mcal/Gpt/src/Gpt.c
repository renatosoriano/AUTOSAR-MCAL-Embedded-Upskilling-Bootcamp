/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Ftm_Srtc_Lptmr_LPit
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 2.0.0
* Build Version : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/
/**
*   @file           Gpt.c
*   @implements     Gpt.c_Artifact
*   @addtogroup     gpt Gpt Driver
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
#include "OsIf.h"
#include "Gpt.h"
#include "Gpt_Irq.h"
#include "Gpt_Ipw.h"
#include "Det.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_C                      43
#define GPT_AR_RELEASE_MAJOR_VERSION_C       4
#define GPT_AR_RELEASE_MINOR_VERSION_C       7

#define GPT_AR_RELEASE_REVISION_VERSION_C    0
#define GPT_SW_MAJOR_VERSION_C               2
#define GPT_SW_MINOR_VERSION_C               0
#define GPT_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT header file are of the same vendor */
#if (GPT_VENDOR_ID_C != GPT_VENDOR_ID)
    #error "Gpt.c and Gpt.h have different vendor ids"
#endif
/* Check if source file and GPT header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt.c and Gpt.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt.c and Gpt.h are different"
#endif

#if (GPT_VENDOR_ID_C != GPT_IPW_VENDOR_ID)
    #error "Gpt.c and Gpt_Ipw.h have different vendor ids"
#endif
/* Check if source file and GPT Ipw header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt.c and Gpt_Ipw.h are different"
#endif
/* Check if source file and GPT Ipw header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_C != GPT_IPW_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_C != GPT_IPW_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_C != GPT_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt.c and Gpt_Ipw.h are different"
#endif

/* Check if source file and GPT header file are of the same vendor */
#if (GPT_VENDOR_ID_C != GPT_IRQ_VENDOR_ID)
    #error "Gpt.c and Gpt_Irq.h have different vendor ids"
#endif
/* Check if source file and GPT header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_C != GPT_IRQ_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Gpt.c and Gpt_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_C != GPT_IRQ_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_C != GPT_IRQ_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_C != GPT_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt.c and Gpt_Irq.h are different"
#endif

/* Check if source file and DET header file are of the same version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((GPT_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (GPT_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Gpt.c and Det.h are different"
        #endif
        /* Check if this source file and OsIf.h file are of the same Autosar version */
        #if ((GPT_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
            (GPT_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Gpt.c and OsIf.h are different"
        #endif
    #endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief      This enumeration type allows the selection of channel status type.
* @details    This enumeration specifies the return type of Gpt_ChannelStatusType
*
* @implements
*/
typedef enum
{
    GPT_STATUS_UNINITIALIZED = 0,               /**< @brief GPT channel status - uninitialized */
    GPT_STATUS_INITIALIZED = 1,                 /**< @brief GPT channel status - initialized */
    GPT_STATUS_STOPPED = 2,                     /**< @brief GPT channel status - stopped */
    GPT_STATUS_EXPIRED = 3,                     /**< @brief GPT channel status - expired */
    GPT_STATUS_RUNNING = 4                      /**< @brief GPT channel status - running */
} Gpt_ChannelStatusType;

/**
* @brief    Gpt runtime status type - this is the type of the data structure including the
*           runtime status informations of a channel.
* @details  It contains the information like GPT channel runtime status, Channel has notification enabled at runtime,
*           Channel has wakeup enabled at runtime,Channel executed wakeup.
* @implements
*/
typedef struct
{
    Gpt_ChannelStatusType eChannelStatus;           /**< @brief GPT channel runtime status */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) /**< @brief GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */
    boolean bNotificationEnabled;                   /**< @brief GPT channel has notification enabled at runtime */
#endif
/** @brief (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) */
#if((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
    boolean bWakeupEnabled;                         /**< @brief GPT channel has wakeup enabled at runtime*/
    boolean bWakeupGenerated;                       /**< @brief GPT channel executed wakeup */
#endif
} Gpt_ChannelInfoType;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (GPT_MULTICORE_ENABLED == STD_ON)
    #define Gpt_GetCoreID()            (uint32)OsIf_GetCoreID()
#else
    #define Gpt_GetCoreID()            ((uint32)0UL)
#endif
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

/**
* @brief    Global variable used for indicating the current GPT driver mode.
*/
#if (((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) || \
     (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || \
     (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON))
#if (GPT_MULTICORE_ENABLED == STD_ON)
static Gpt_ModeType Gpt_eMode[GPT_MAX_PARTITIONS] = {GPT_MODE_NORMAL};
#else
static Gpt_ModeType Gpt_eMode[1U] = {GPT_MODE_NORMAL};
#endif
#endif

#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
* @brief          Global variable (pointer) used for storing the GPT driver configuration data.
*/
#if (GPT_MULTICORE_ENABLED == STD_ON)
const Gpt_ConfigType *Gpt_pConfig[GPT_MAX_PARTITIONS];
#else
const Gpt_ConfigType *Gpt_pConfig[1U];
#endif

#if (GPT_MULTICORE_ENABLED == STD_ON)

/**
* @brief         Global array variable used to store runtime internal context of each logic channel.
*/
static Gpt_ChannelInfoType Gpt_aChannelInfo[GPT_MAX_PARTITIONS][GPT_HW_CHANNEL_NUM];

#else

/**
* @brief         Global array variable used to store runtime internal context of each logic channel.
*/
static Gpt_ChannelInfoType Gpt_aChannelInfo[1U][GPT_HW_CHANNEL_NUM];

#endif

#if ((GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON))
#if (GPT_MULTICORE_ENABLED == STD_ON)
/**
* @brief         Global array variable used to store for each channel the time value when it is
*                stopped
*/
static Gpt_ValueType Gpt_aStopTime[GPT_MAX_PARTITIONS][GPT_HW_CHANNEL_NUM];
#else
/**
* @brief         Global array variable used to store for each channel the time value when it is
*                stopped
*/
static Gpt_ValueType Gpt_aStopTime[1U][GPT_HW_CHANNEL_NUM];
#endif
#endif

#define GPT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
static inline Std_ReturnType Gpt_ValidateChannelCall
(
    uint8 u8ServiceId,
    Gpt_ChannelType channel,
    uint32 coreID
);
#endif

#if(GPT_VALIDATE_GLOBAL_CALL == STD_ON)
static inline Std_ReturnType Gpt_ValidateGlobalCall
(
uint8 u8ServiceId,
uint32 coreID
);
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) && (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON))
static inline Std_ReturnType Gpt_ValidateChannelNotification
(
    uint8 u8ServiceId,
    Gpt_ChannelType channel,
    uint32 coreID
);
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
static inline Std_ReturnType Gpt_ValidateChannelWakeup
(
    uint8 u8ServiceId,
    Gpt_ChannelType channel,
    uint32 coreID
);
#endif

#if (GPT_VALIDATE_STATE == STD_ON)
static inline Std_ReturnType Gpt_ValidateChannelStatus
(
    uint8 u8ServiceId,
    Gpt_ChannelType channel,
    uint32 coreID
);
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
static inline Std_ReturnType Gpt_ValidateParamMode(Gpt_ModeType eMode);
#endif

#if (GPT_VALIDATE_PARAM == STD_ON)
static inline Std_ReturnType Gpt_ValidateParamValue
(
    uint8 u8ServiceId,
    Gpt_ChannelType channel,
    Gpt_ValueType value,
    uint32 coreID
);
#endif

#if (GPT_VALIDATE_PARAM == STD_ON)
static inline Std_ReturnType Gpt_ValidateParamPtrInit
(
    const Gpt_ConfigType * configPtr
);
#endif

#if (GPT_SET_CLOCK_MODE == STD_ON) && (GPT_VALIDATE_PARAM == STD_ON)
static inline Std_ReturnType Gpt_ValidateParamSetClockMode
(
    Gpt_ClockModeType eClkMode
);
#endif

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
#if (GPT_VALIDATE_PARAM == STD_ON)
static inline Std_ReturnType Gpt_ValidateParamTypePredefTimer
(
    Gpt_PredefTimerType u32PredefTimer,
    uint32 coreID
);

static inline Std_ReturnType Gpt_ValidatePointerGetPredefTimer
(
    const uint32 * ParamPtr
);
#endif
#if (GPT_VALIDATE_STATE == STD_ON)
static inline Std_ReturnType Gpt_ValidateMode
(
    uint8 u8ServiceId,
	uint32 coreID
);
#endif
#endif

#if((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
/* Check channel has wakeup enabled at runtime*/
static inline void Gpt_CheckStatusWakeupEnabled(uint32 coreID);
/* Check channel has notification enabled at runtime*/
static inline void Gpt_CheckStatusNotificationEnabled(uint32 coreID);
#endif

static inline Gpt_ChannelType Gpt_ConvertChannelIndexToChannel(Gpt_ChannelType ChannelIndex,
                                                                              uint32 coreID
                                                                              );
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
/**
 * @brief           This function validates the call for a specific channel
 * @details         This service is a non re entrant function on channel used for validating the calls
 *                  for functions that use one channel
 *
 * @param[in]       Channel          Numeric identifier of the GPT channel
 * @param[in]       u8ServiceId      The service id of the caller function
 * @return          The validity of the function call
 * @returnValue     E_OK             The function call is valid
 * @returnValue     E_NOT_OK         The function call is invalid
 *
 * @pre             Gpt_Init must be called before.
 * @implements      Gpt_ValidateChannelCall_Activity
 *
 * */
static inline Std_ReturnType Gpt_ValidateChannelCall
(
    uint8 u8ServiceId,
    Gpt_ChannelType channel,
    uint32 coreID
)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    /* If driver is not initialized report error */
    if (NULL_PTR == Gpt_pConfig[coreID])
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)u8ServiceId,\
            (uint8)GPT_E_UNINIT\
        );
    }
    else
    {
        if (GPT_HW_CHANNEL_NUM <= channel)
        {
            /* Check if the configured channel is out of range */
            (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)u8ServiceId,\
                (uint8)GPT_E_PARAM_CHANNEL\
            );
        }
        else
        {
            /* Check if the channel is used on the current core */
            if (255U != (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel])
            {
                returnValue = (Std_ReturnType)E_OK;
            }
            else
            {
                (void)Det_ReportError\
                (\
                    (uint16)GPT_MODULE_ID,\
                    (uint8)GPT_INSTANCE_ID,\
                    (uint8)u8ServiceId,\
                    (uint8)GPT_E_PARAM_CONFIG\
                );
            }
        }
    }
    return returnValue;
}
#endif

#if(GPT_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief            This function validates the global call
 * @details          This service is a non re-entrant function used for validating the calls for functions
 *                   that uses all the channels - Gpt_Init, Gpt_DeInit, Gpt_SetMode.
 *
 * @param[in]        u8ServiceId The service id of the caller function
 *
 * @return           The validity of the function call
 * @returnValue      E_OK     The function call is valid
 * @returnValue      E_NOT_OK The function call is invalid
 *
 * @pre              Gpt_Init must be called before.
 * @implements       Gpt_ValidateGlobalCall_Activity
 * */
static inline Std_ReturnType Gpt_ValidateGlobalCall
(
uint8 u8ServiceId,
uint32 coreID
)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;


    /* If caller is the initialization function, error */
    if (NULL_PTR == Gpt_pConfig[coreID])
    {
        /* If caller is the initialization function, OK */
        if (GPT_INIT_ID == u8ServiceId)
        {
            returnValue = (Std_ReturnType)E_OK;
        }
        else
        {
            (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)u8ServiceId,\
                (uint8)GPT_E_UNINIT\
            );
        }
    }
    else
    {
        if (GPT_INIT_ID == u8ServiceId)
        {
            (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)u8ServiceId,\
                (uint8)GPT_E_ALREADY_INITIALIZED\
            );
        }
        else
        {
            returnValue = (Std_ReturnType)E_OK;
        }
    }

    return returnValue;
}
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) && (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON))
/**
 * @brief           This function validate the channel notification capability for a
 *                  specific channel.
 * @details         Validate the notification handler of a GPT channel.
 *                  In order to be valid, the notification handler should not be
 *                  NULL_PTR. In case it is NULL_PTR, the function will report an error to
 *                  DET or SERR, depending on the environment the driver is run in.
 * @param[in]       u8ServiceId   The service id of the caller function
 * @param[in]       channel     Numeric identifier of the GPT channel
 *
 * @return          The validity of the function call
 * @returnValue     E_OK     The function call is valid
 * @returnValue     E_NOT_OK The function call is invalid
 *
 * @pre             The driver needs to be initialized and GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON.
 * @implements      Gpt_ValidateChannelNotification_Activity
 *
 * */
static inline Std_ReturnType Gpt_ValidateChannelNotification
(
    uint8 u8ServiceId,
    Gpt_ChannelType channel,
    uint32 coreID
)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;
    uint8 ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];

    if (NULL_PTR == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_pfNotification)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)u8ServiceId,\
            (uint8)GPT_E_PARAM_CHANNEL\
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }

    return returnValue;

}
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
/**
 * @brief           This function validate the channel wakeup capability for a specific channel.
 * @details         Function validate the channel wakeup capability for a specific channel.
 *                  In case Gpt_bEnableWakeup is FALSE, the function will report an error to
 *                  DET or SERR, depending on the environment the driver is run in.
 * @param[in]       u8ServiceId   The service id of the caller function
 * @param[in]       channel       Numeric identifier of the GPT channel
 *
 * @return          The validity of the function call
 * @returnValue     E_OK          The function call is valid
 * @returnValue     E_NOT_OK      The function call is invalid
 *
 * @pre             The driver needs to be initialized.
 * @implements      Gpt_ValidateChannelWakeup_Activity
 *
 * */
static inline Std_ReturnType Gpt_ValidateChannelWakeup
(
    uint8 u8ServiceId,
    Gpt_ChannelType channel,
    uint32 coreID
)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;
    uint8 ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];

    if (FALSE == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_bEnableWakeup)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)u8ServiceId,\
            (uint8)GPT_E_PARAM_CHANNEL\
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }

    return returnValue;

}
#endif

/**
 * @brief           This function validate the channel status related to the caller function
 *                  and to a specific channel.
 * @details         Function validate the channel status for a specific channel.
 *                  In case disabled wakeup channel in sleep mode ((bWakeupEnabled == False) && (GPT_MODE_SLEEP == Gpt_eMode)),
 *                  In case channel status (GPT_STATUS_RUNNING != eChannelStatus) && GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON
 *                  In case channel status (GPT_STATUS_RUNNING == eChannelStatus)
 *                  In case channel mode (GPT_CH_MODE_ONESHOT == eChannelMode) && GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON
 *                  the function will report an error to DET or SERR, depending on the environment the driver is run in.
 * @param[in]       u8ServiceId   The service id of the caller function
 * @param[in]       channel     Numeric identifier of the GPT channel
 *
 * @return          The validity of the function call
 * @returnValue     E_OK     The function call is valid
 * @returnValue     E_NOT_OK The function call is invalid
 *
 * @pre             The driver needs to be initialized.
 * @implements
 * */
static inline Std_ReturnType Gpt_ValidateChannelStatus
(
    uint8 u8ServiceId,
    Gpt_ChannelType channel,
    uint32 coreID
)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;
#if ((GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON) && (GPT_VALIDATE_STATE == STD_ON))
    uint8 ChannelIndex;
#endif

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(u8ServiceId, channel, coreID))
    {
#endif
        if(channel < GPT_HW_CHANNEL_NUM)
        {
    #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_VALIDATE_STATE == STD_ON))
        #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
            /* Do not start a not enabled wakeup channel in sleep mode */
            if ((GPT_MODE_SLEEP == Gpt_eMode[coreID]) && (FALSE == Gpt_aChannelInfo[coreID][channel].bWakeupEnabled) && (GPT_STARTTIMER_ID == u8ServiceId))
            {
                (void)Det_ReportError\
                (\
                    (uint16)GPT_MODULE_ID,\
                    (uint8)GPT_INSTANCE_ID,\
                    (uint8)u8ServiceId,\
                    (uint8)GPT_E_INVALID_CALL\
                );
            }
            else
            {
        #endif
    #endif /* (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_VALIDATE_STATE == STD_ON) */
    #if (GPT_VALIDATE_STATE == STD_OFF)
            (void) coreID;
    #endif
    #if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
        #if (GPT_VALIDATE_STATE == STD_ON)
                ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
                if ((GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID == u8ServiceId) && \
                    (GPT_STATUS_RUNNING != Gpt_aChannelInfo[coreID][channel].eChannelStatus)
                   )
                {
                    (void)Det_ReportError\
                    (\
                        (uint16)GPT_MODULE_ID,\
                        (uint8)GPT_INSTANCE_ID,\
                        (uint8)u8ServiceId,\
                        (uint8)GPT_E_INVALID_CALL\
                    );
                }
                else if ((GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID == u8ServiceId) && \
                         (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_eChannelMode)
                        )
                {
                    (void)Det_ReportError\
                    (\
                        (uint16)GPT_MODULE_ID,\
                        (uint8)GPT_INSTANCE_ID,\
                        (uint8)u8ServiceId,\
                        (uint8)GPT_E_PARAM_CHANNEL\
                    );
                }
                else
        #endif /* (GPT_VALIDATE_STATE == STD_ON) */
                    if ((GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID != u8ServiceId) && \
                         (GPT_STATUS_RUNNING == Gpt_aChannelInfo[coreID][channel].eChannelStatus)
                        )
                {
                    (void)Det_ReportRuntimeError\
                    (\
                        (uint16)GPT_MODULE_ID,\
                        (uint8)GPT_INSTANCE_ID,\
                        (uint8)u8ServiceId,\
                        (uint8)GPT_E_BUSY\
                    );
                }
                else
                {
    #else
                    if (GPT_STATUS_RUNNING == Gpt_aChannelInfo[coreID][channel].eChannelStatus)
                    {
                        (void)Det_ReportRuntimeError\
                        (\
                            (uint16)GPT_MODULE_ID,\
                            (uint8)GPT_INSTANCE_ID,\
                            (uint8)u8ServiceId,\
                            (uint8)GPT_E_BUSY\
                        );
                    }
                    else
                    {
    #endif
                        returnValue = (Std_ReturnType)E_OK;
    #if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_OFF)
                    }
    #endif
    #if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
                }
    #endif
    #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)&& (GPT_VALIDATE_STATE == STD_ON))
    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
            }
    #endif
    #endif
    #if ((GPT_VALIDATE_STATE == STD_OFF)||(GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_OFF))
            /*variable coreID is not used in this case - this should be commented*/
            (void) coreID;
    #endif
        }
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
    return returnValue;
}


#if ((GPT_VALIDATE_PARAM == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
/**
 * @brief           This function validate the mode that will be set in the driver.
 * @details         Validate the mode that will be set in the driver.
 *                  In case (GPT_MODE_SLEEP != eMode) && (GPT_MODE_NORMAL != eMode)
 *                  the function will report an error to DET or SERR, depending on the environment the driver is run in.
 * @param[in]       eMode        Specifies the operation mode
 *
 * @return          The validity of the function call
 * @returnValue     E_OK     The function call is valid
 * @returnValue     E_NOT_OK The function call is invalid
 *
 * @pre             The driver needs to be initialized.
 * @implements      Gpt_ValidateParamMode_Activity
 * */
static inline Std_ReturnType Gpt_ValidateParamMode(Gpt_ModeType eMode)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    if((GPT_MODE_SLEEP != eMode) && (GPT_MODE_NORMAL != eMode))
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_SETMODE_ID,\
            (uint8)GPT_E_PARAM_MODE\
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }

    return returnValue;
}
#endif

#if (GPT_VALIDATE_PARAM == STD_ON)
/**
 * @brief           This function validate the time value parameter related to a specific GPT channel.
 * @details         Function validate the time value parameter related to a specific GPT channel.
 *                  In case ((Gpt_ValueType)0 == value) || (value > Gpt_uChannelTickValueMax)
 *                  the function will report an error to DET or SERR, depending on the environment the driver is run in.
 * @param[in]       u8ServiceId The service id of the caller function
 * @param[in]       value       The time value which is verified
 * @param[in]       channel     Numeric identifier of the GPT channel
 *
 * @return          The validity of the function call
 * @returnValue     E_OK     The function call is valid
 * @returnValue     E_NOT_OK The function call is invalid
 *
 * @pre             The driver needs to be initialized.
 * @implements      Gpt_ValidateParamValue_Activity
 *
 * */
static inline Std_ReturnType Gpt_ValidateParamValue
(
    uint8 u8ServiceId,
    Gpt_ChannelType channel,
    Gpt_ValueType value,
    uint32 coreID
)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;
    uint8 ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];

    if ((value > (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_uChannelTickValueMax) || \
        ((Gpt_ValueType)0 == value )
       )
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            u8ServiceId,\
            (uint8)GPT_E_PARAM_VALUE\
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }

    return returnValue;

}
#endif

#if (GPT_VALIDATE_PARAM == STD_ON)
/**
 * @brief          This function validate the initialization pointer.
 * @details        Validate the initialization pointer.
 *                 In case NULL_PTR == configPtr and (GPT_PRECOMPILE_SUPPORT == STD_OFF)
 *                 In case NULL_PTR != configPtr and (GPT_PRECOMPILE_SUPPORT == STD_ON)
 *                 The function will report an error to DET or SERR, depending on the environment the driver is run in.
 * @param[in]      configPtr        Pointer to a selected configuration structure.
 *
 * @return         The validity of the function call
 * @returnValue    E_OK     The function call is valid
 * @returnValue    E_NOT_OK The function call is invalid
 *
 * @pre            The data structure including the configuration set required for initializing the GPT driver.
 * @implements     Gpt_ValidateParamPtrInit_Activity
 *
 * */
static inline Std_ReturnType Gpt_ValidateParamPtrInit
(
    const Gpt_ConfigType * configPtr
)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == configPtr)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_INIT_ID,\
            (uint8)GPT_E_INIT_FAILED \
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }
#endif
#elif (GPT_PRECOMPILE_SUPPORT == STD_ON)
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != configPtr)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_INIT_ID,\
            (uint8)GPT_E_INIT_FAILED \
        );
    }
    else
    {
        returnValue=(Std_ReturnType)E_OK;
    }
#endif
#endif

    return returnValue;
}
#endif
#if (GPT_SET_CLOCK_MODE == STD_ON) && (GPT_VALIDATE_PARAM == STD_ON)
/**
 * @brief          This function validates the eClkMode parameter.
 * @details        Validate the function ValidateParamSetClockMode.
 *                 In case (GPT_CLOCKMODE_NORMAL != eClkMode) && (GPT_CLOCKMODE_ALTERNATE != eClkMode)
 *                 The function will report an error to DET or SERR, depending on the environment the driver is run in.
 * @param[in]      eClkMode   prescaler setting ( NORMAL or ALTERNATE )
 *
 * @return         The validity of the function call
 * @returnValue    E_OK     The function call is valid
 * @returnValue    E_NOT_OK The function call is invalid
 *
 * @pre            The driver needs to be initialized.
 * @implements     Gpt_ValidateParamSetClockMode_Activity
 *
 * */
static inline Std_ReturnType Gpt_ValidateParamSetClockMode
(
    Gpt_ClockModeType eClkMode
)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    if((GPT_CLOCKMODE_NORMAL != eClkMode) && (GPT_CLOCKMODE_ALTERNATE != eClkMode))
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_SET_CLOCK_MODE_ID,\
            (uint8)GPT_E_PARAM_CLOCK_MODE\
        );
    }
    else
    {
        returnValue=(Std_ReturnType)E_OK;
    }

    return returnValue;
}
#endif

#if((GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON) && (GPT_VALIDATE_PARAM == STD_ON))
/**
 * @brief          This function validates parameter of PredefTimer
 * @details        Validate the function Gpt_ValidateParamTypePredefTimer.
 *                 In case (Gpt_PredefTimerType != u32PredefTimer)
 *                 In case pointer to the GPT channel predeftimer configuration == NULL_PTR
 *                 The function will report an error to DET or SERR, depending on the environment the driver is run in.
 *
 * @param[in]      u32PredefTimer Parameter of PredefTimer functionality
 * @return         The validity of the function call
 * @returnValue    E_OK     The function call is valid
 * @returnValue    E_NOT_OK The function call is invalid
 *
 * @pre            The driver needs to be initialized.
 *
 * @implements     Gpt_ValidateParamTypePredefTimer_Activity
 *
 **/
static inline Std_ReturnType Gpt_ValidateParamTypePredefTimer
(
    Gpt_PredefTimerType u32PredefTimer,
    uint32 coreID
)
{
    Std_ReturnType      returnValue = (Std_ReturnType)E_NOT_OK;
    Gpt_ChannelType     channel;

    if ((u32PredefTimer != GPT_PREDEF_TIMER_1US_16BIT) && \
        (u32PredefTimer != GPT_PREDEF_TIMER_1US_24BIT) && \
        (u32PredefTimer != GPT_PREDEF_TIMER_1US_32BIT) && \
        (u32PredefTimer != GPT_PREDEF_TIMER_100US_32BIT))
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_GET_PREDEF_TIMERVALUE_ID,\
            (uint8)GPT_E_PARAM_PREDEF_TIMER\
        );
    }
    else
    {
       channel = (Gpt_ChannelType)u32PredefTimer;
       if(NULL_PTR == ((Gpt_pConfig[coreID]->Gpt_pChannelPredefConfigType)[channel]))
       {
           (void)Det_ReportError\
           (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_GET_PREDEF_TIMERVALUE_ID,\
            (uint8)GPT_E_PARAM_PREDEF_TIMER\
           );
       }
       else
       {
            returnValue = (Std_ReturnType)E_OK;
       }

    }
    return returnValue;
}
/**
 * @brief            This function validate the Pointer GetPredefTimer.
 * @details          Validate the function Gpt_ValidatePointerGetPredefTimer.
 *                   In case (NULL_PTR == ParamPtr)
 *                   The function will report an error to DET or SERR, depending on the environment the driver is run in.
 * @param[in]        ParamPtr        Pointer to a selected configuration structure.
 * @return           The validity of the function call
 * @returnValue      E_OK     The function call is valid
 * @returnValue      E_NOT_OK The function call is invalid
 *
 * @pre              The driver needs to be initialized.
 * @implements       Gpt_ValidatePointerGetPredefTimer_Activity
 *
 **/
static inline Std_ReturnType Gpt_ValidatePointerGetPredefTimer
(
    const uint32 * ParamPtr
)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;
    if(NULL_PTR == ParamPtr)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_GET_PREDEF_TIMERVALUE_ID,\
            (uint8)GPT_E_PARAM_POINTER\
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }
    return returnValue;
}
#endif
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       This function validate the initialization mode.
 * @details     Validate the function Gpt_ValidateMode.
  *             In case (GPT_MODE_SLEEP == Gpt_eMode)
 *              The function will report an error to DET or SERR, depending on the environment the driver is run in.
 * @param[in]   u8ServiceId The service id of the caller function.
 *
 * @return      The validity of the function call.
 * @returnValue E_OK     The function call is valid.
 * @returnValue E_NOT_OK The function call is invalid.
 *
 * @pre         The driver needs to be initialized.
 * @implements  Gpt_ValidateMode_Activity
 *
 **/
static inline Std_ReturnType Gpt_ValidateMode
(
	uint8 u8ServiceId,
	uint32 coreID
)
{
    Std_ReturnType returnValue;
    if (GPT_MODE_SLEEP == Gpt_eMode[coreID])
    {
        (void)Det_ReportRuntimeError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)u8ServiceId,\
            (uint8)GPT_E_MODE\
        );
		returnValue = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }
    return returnValue;
}
#endif

/**
 * @brief       This function get the channel number corresponding to the index of channel
 *
 * @param[in]   ChannelIndex          Channel Index of the Gpt channel
 * @param[in]   coreID                The number of current core ID
 *
 * @return      The channel number corresponds to the channel in the core
 * @pre         Gpt_Init must be called before.
 *
 *
 * */
static inline Gpt_ChannelType Gpt_ConvertChannelIndexToChannel(Gpt_ChannelType ChannelIndex,
                                                                              uint32 coreID
                                                                              )
{
    Gpt_ChannelType Channel;

    for (Channel = 0U; Channel < GPT_HW_CHANNEL_NUM; ++Channel)
    {
        if(ChannelIndex == (*Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap)[Channel])
        {
            break;
        }
    }
    return Channel;
}
#if((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
/**
 * @brief       This function check channel has notification enabled at runtime in case GPT_MODE_NORMAL == eMode
 *
 * @param[in]   coreID   The number of current core ID
 *
 * @return      void
 * @pre         Gpt_Init,  must be called before.
 *
 *
 * */
static inline void Gpt_CheckStatusNotificationEnabled(uint32 coreID)
{
    Gpt_ChannelType channel;
    Gpt_ChannelType ChannelIndex;

    /*Implements the behaviour for normal mode*/
    for (ChannelIndex = 0U; ChannelIndex < Gpt_pConfig[coreID]->channelCount; ChannelIndex++)
    {
        channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, coreID);
        if(channel < GPT_HW_CHANNEL_NUM)
        {
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
            if (TRUE == Gpt_aChannelInfo[coreID][channel].bNotificationEnabled)
            {
                /* Enable hardware interrupts */
                Gpt_Ipw_EnableInterrupt
                (
                    ((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)
                );
            }
            else
            {
#endif
                /* Disable hardware interrupts if the channel is not running in the ONE-SHOT mode.
                This is needed because the channel state is updated by ISR for ONE-SHOT mode */
                if((GPT_STATUS_RUNNING != Gpt_aChannelInfo[coreID][channel].eChannelStatus) || \
                    (GPT_CH_MODE_CONTINUOUS == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_eChannelMode)
                    )
                {
                    /*Disable hardware interrupts*/
                    Gpt_Ipw_DisableInterrupt
                    (
                        ((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)
                    );
                }
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
            }
#endif
        }
    }
}

/**
 * @brief       This function check channel has wakeup enabled at runtime in case GPT_MODE_SLEEP
 *
 * @param[in]   coreID       The number of current core ID
 *
 * @return      void
 * @pre         Gpt_Init, Gpt_SetMode must be called before.
 *
 *
 * */
static inline void Gpt_CheckStatusWakeupEnabled(uint32 coreID)
{
	Gpt_HwChannelInfoType returnHwChannelInfo = {FALSE, 0U};
#if ((GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON))
	Gpt_HwChannelInfoType * pRetHwChannelInfo = &returnHwChannelInfo;
    Gpt_ValueType uElapsedTime = 0U;
#endif
    Gpt_ChannelType ChannelIndex;
    Gpt_ChannelType channel;

    for (ChannelIndex = 0U; ChannelIndex < Gpt_pConfig[coreID]->channelCount; ChannelIndex++)
    {
        channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, coreID);
        if(channel < GPT_HW_CHANNEL_NUM)
        {
            if (TRUE == Gpt_aChannelInfo[coreID][channel].bWakeupEnabled)
            {
                /*Enable hardware interrupts*/
                Gpt_Ipw_EnableInterrupt(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig));
            }
            else
            {
                /*Disable hardware interrupts*/
                Gpt_Ipw_DisableInterrupt(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig));

#if ((GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON))
                /*Gpt_Ipw_GetTimeElapsed() shall be called first, because the occurred ISRs
                can change the logical channel state between the checking of logical channel
                state and timestamp retrieval*/
                /* Get the elapsed  time  for later use by other API calls*/
                uElapsedTime = Gpt_Ipw_GetTimeElapsed((((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)), pRetHwChannelInfo);
#endif

                /*Stop  the running timer*/
                if (GPT_STATUS_RUNNING == Gpt_aChannelInfo[coreID][channel].eChannelStatus)
                {
                    if ((TRUE == returnHwChannelInfo.bChannelRollover) && \
                        (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_eChannelMode)
                        )
                    {
                        /*This action could be executed only when the function is called
                        during a critical section implemented by disabling all interrupts*/
                        /*Set the channel status to EXPIRED*/
                        Gpt_aChannelInfo[coreID][channel].eChannelStatus = GPT_STATUS_EXPIRED;
                    }
                    else
                    {
#if ((GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON))
                        /* Store the stopping time for later use by other API calls*/
                        Gpt_aStopTime[coreID][channel] = uElapsedTime;
#endif
                        /* Set the channel status to STOPPED*/
                        Gpt_aChannelInfo[coreID][channel].eChannelStatus = GPT_STATUS_STOPPED;
                    }
                    /* Call low level stop timer */
                    Gpt_Ipw_StopTimer
                    (
                        ((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)
                    );
                }
            }
        }
    }
}
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#if (GPT_VERSION_INFO_API == STD_ON)
/**
* @brief   This function returns the version information of this module.
* @details This service returns the version information of this module. The version information
*          includes:
*                    - Module Id
*                    - Vendor Id
*                    - Vendor specific version numbers
*          If source code for caller and callee of this function is available this function should
*          be realized as a macro. The macro should be defined in the modules header file.
* @param[out]  VersionInfoPtr - pointer to location to store version info
*
* @return void
* @api
*
* @pre            Gpt_Init must be called before.
* @implements     Gpt_GetVersionInfo_Activity
*/
void Gpt_GetVersionInfo
(
    Std_VersionInfoType * VersionInfoPtr
)
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_GETVERSIONINFO_ID,\
            (uint8)GPT_E_PARAM_POINTER\
        );
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         = (uint16)GPT_VENDOR_ID;
        VersionInfoPtr->moduleID         = (uint16)GPT_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8)GPT_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)GPT_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)GPT_SW_PATCH_VERSION;
    }
}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver initialization function.
* @details This service is a non reentrant function used for driver initialization.
*          The Initialization function shall initialize all relevant registers of
*          the configured hardware with the values of the structure referenced by the parameter ConfigPtr.
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          This function shall only initialize the configured resources. Resources that are
*          not configured in the configuration file shall not be touched.
*          The following rules regarding initialization of controller registers shall apply
*          to the GPT Driver implementation:
*          [1] If the hardware allows for only one usage of the register, the driver
*              module implementing that functionality is responsible for initializing the register
*          [2] If the register can affect several hardware modules and if it is an IO register it
*              shall be initialized by the PORT driver
*          [3] If the register can affect several hardware modules and if it is not an IO register
*              it shall be initialized by the MCU driver
*          [4] One-time writable registers that require initialization directly after reset shall be
*              initialized by the startup code
*          [5] All other registers shall be initialized by the startup code
*
* @param[in]     configPtr    Pointer to a selected configuration structure
*
* @return        void
* @api
*
* @pre            The data structure including the configuration set required for initializing the GPT driver..
* @implements     Gpt_Init_Activity
*/
void Gpt_Init(const Gpt_ConfigType * configPtr)
{
    Gpt_ChannelType ChannelIndex;
    Gpt_ChannelType channel;
    uint32 coreID = (uint32)Gpt_GetCoreID();

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    /*Validate the calling context*/
    if((Std_ReturnType)E_OK == Gpt_ValidateGlobalCall(GPT_INIT_ID, coreID))
    {
#endif
#if (GPT_VALIDATE_PARAM  == STD_ON)
        /*Validate configuration pointer parameter.*/
        if((Std_ReturnType)E_OK == Gpt_ValidateParamPtrInit(configPtr))
        {
#endif

    #if (GPT_PRECOMPILE_SUPPORT == STD_ON)
        #if(GPT_MULTICORE_ENABLED == STD_ON)
            Gpt_pConfig[coreID] = Gpt_Config[coreID];
        #else
            Gpt_pConfig[coreID] = &Gpt_Config;
        #endif
            (void)configPtr;
    #else
            Gpt_pConfig[coreID] = configPtr;
    #endif

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
            /*Initialize and Start Predef Timers.*/
            Gpt_Ipw_StartPredefTimer(Gpt_pConfig[coreID]);
#endif
            Gpt_Ipw_InitInstances(Gpt_pConfig[coreID]);

            /*Initialize for each channel the runtime status informations.*/
            for (ChannelIndex = 0U; ChannelIndex < Gpt_pConfig[coreID]->channelCount; ChannelIndex++)
            {
                channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, coreID);
                if(channel < GPT_HW_CHANNEL_NUM)
                {
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
                    /*Disable notification*/
                    Gpt_aChannelInfo[coreID][channel].bNotificationEnabled = FALSE;
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
                    /*Disable wakeup*/
                    Gpt_aChannelInfo[coreID][channel].bWakeupEnabled = FALSE;
                    /*Clear wakeup generation status*/
                    Gpt_aChannelInfo[coreID][channel].bWakeupGenerated = FALSE;
#endif
                    /* Initialize the running information of the channel*/
                    Gpt_aChannelInfo[coreID][channel].eChannelStatus = GPT_STATUS_INITIALIZED;
#if ((GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON))
                    Gpt_aStopTime[coreID][channel] = 0U;
#endif
                }

                /*Initialize hardware timer channel.*/
                Gpt_Ipw_Init(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig));
            }
#if (((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) || \
     (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || \
     (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON))
            /*Set the driver to normal mode*/
            Gpt_eMode[coreID] = GPT_MODE_NORMAL;
#endif
#if (GPT_VALIDATE_PARAM  == STD_ON)
        }
#endif
#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
    return;
}

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief   GPT driver de-initialization function.
* @details Service for de initializing all hardware timer channels to their power on reset state.
*          The state of the peripheral after DeInit shall be the same as after power on
*          reset.
*          The service influences only the peripherals, which are allocated by static
*          configuration and the runtime configuration set passed by the previous call of Gpt_Init()
*          The driver needs to be initialized before calling Gpt_DeInit(). Otherwise, the
*          function Gpt_DeInit shall raise the development error GPT_E_UNINIT and leave the desired
*          de initialization functionality without any action.
*
* @api
* @return  void
*
* @implements   Gpt_DeInit_Activity
*/
void Gpt_DeInit(void)
{
    Gpt_ChannelType channel;
    Gpt_ChannelType ChannelIndex;

    Std_ReturnType allChannelStatus = (Std_ReturnType)E_OK;
    uint32 coreID = (uint32)Gpt_GetCoreID();

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    /*Validate if the calling context is valid*/
    if((Std_ReturnType)E_OK == Gpt_ValidateGlobalCall(GPT_DEINIT_ID, coreID))
    {
#endif
        /* Initialize for each channel the runtime status informations.*/
        for (ChannelIndex = 0U; ChannelIndex < Gpt_pConfig[coreID]->channelCount; ChannelIndex++)
        {
            channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, coreID);
            /*Check if the channel is not running.*/
            if((Std_ReturnType)E_NOT_OK == Gpt_ValidateChannelStatus(GPT_DEINIT_ID, channel, coreID))
            {
                allChannelStatus = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }

        if((Std_ReturnType)E_OK == allChannelStatus)
        {
            for (ChannelIndex = 0U; ChannelIndex < Gpt_pConfig[coreID]->channelCount; ChannelIndex++)
            {
                channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, coreID);
                if(channel < GPT_HW_CHANNEL_NUM)
                {
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
                    /*Disable notification*/
                    Gpt_aChannelInfo[coreID][channel].bNotificationEnabled = FALSE;
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
                    /*Disable wakeup*/
                    Gpt_aChannelInfo[coreID][channel].bWakeupEnabled = FALSE;
                    /*Clear wakeup generation status*/
                    Gpt_aChannelInfo[coreID][channel].bWakeupGenerated = FALSE;
#endif
                    /* De initialize the running information of the channel*/
                    Gpt_aChannelInfo[coreID][channel].eChannelStatus = GPT_STATUS_UNINITIALIZED;
#if ((GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON))
                    Gpt_aStopTime[coreID][channel] = 0U;
#endif
                    /*Initialize hardware timer channel.*/
                    Gpt_Ipw_DeInit
                    (
                        ((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)
                    );

                }
            }

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
            /* Deinitialize and stop Predef timers.*/
            Gpt_Ipw_StopPredefTimer(Gpt_pConfig[coreID]);
#endif
            /* Writing NULL to configuration pointer is mandatory because that variable
            is used to test the initialization of the driver */
            Gpt_pConfig[coreID] = NULL_PTR;
        }

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
    return;
}
#endif

/*================================================================================================*/
#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
* @brief   GPT driver function for fetching the elapsed timer value.
* @details Service for querying the time already elapsed.
*          In one shot mode, this is the value relative to the point in time, the channel has been
*          started with Gpt_StartTimer (calculated by the normal operation function by subtracting
*          the current minus the initial timer value and returning the absolute value).
*          In continuous mode, the function returns the timer value relative to the last timeout or
*          the start of the channel.
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          To get times out of register values it is necessary to know the oscillator frequency, pre
*          prescalers and so on. Since these settings are made in MCU and(or) in other modules it is
*          not possible to calculate such times. Hence the conversions between time and ticks shall
*          be part of an upper layer.
*          The driver needs to be initialized before calling Gpt_GetTimeElapsed(). Otherwise, the
*          function shall raise the development error GPT_E_UNINIT and return 0.
*
* @param[in]  channel - channel id
*
* @return  Gpt_ValueType - Elapsed Time in number of ticks
*
* @api
*
* @pre     The driver needs to be initialized.
* @implements Gpt_GetTimeElapsed_Activity
*/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType channel)
{
	Gpt_HwChannelInfoType returnHwChannelInfo = {FALSE, 0U};
	Gpt_HwChannelInfoType * pRetHwChannelInfo = &returnHwChannelInfo;
    Gpt_ChannelType ChannelIndex;

    Gpt_ValueType returnValue = 0U;
    uint32 coreID = (uint32)Gpt_GetCoreID();


#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_TIMEELAPSED_ID, channel, coreID))
    {
#endif
        ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
        /*Gpt_Ipw_GetTimeElapsed() shall be called first, because the occurred ISRs can change
        the logical channel state between the checking of logical channel state and timestamp
        retrieval*/
        returnValue = Gpt_Ipw_GetTimeElapsed((((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)), pRetHwChannelInfo);

        /*Check the channel status*/
        switch(Gpt_aChannelInfo[coreID][channel].eChannelStatus)
        {
            case GPT_STATUS_RUNNING:
            {
                /*Check if channel counter has already rollover*/
                if ((TRUE == returnHwChannelInfo.bChannelRollover) && \
                    (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_eChannelMode)
                   )
                {
                    /*The timer has already expired.The hardware timer status is not yet
                    synchronized with the logical timer status*/
                    returnValue = returnHwChannelInfo.uTargetTime;
                }
            }
            break;
            case GPT_STATUS_INITIALIZED:
            {
                returnValue = 0U;
            }
            break;
            case GPT_STATUS_STOPPED:
            {
                /*Return elapsed time at the when the channel was stopped*/
                returnValue = Gpt_aStopTime[coreID][channel];
            }
            break;
            case GPT_STATUS_EXPIRED:
            {
                returnValue = returnHwChannelInfo.uTargetTime;
            }
            break;
            default:
                /*Only the above four channel states are allowed when this function is called*/
                break;
        }
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif

    return returnValue;
}
#endif

/*================================================================================================*/
#if (GPT_TIME_REMAINING_API == STD_ON)
/**
* @brief   GPT driver function for fetching the remaining timer value.
* @details This function returns the timer value remaining until the next timeout period will
*          expire (calculated by the normal operation function by subtracting the timeout minus
*          the current timer value and returning the absolute value)
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          Usage of re-entrant capability is only allowed if the callers take care that there is no
*          simultaneous usage of the same channel.
*          To get times out of register values it is necessary to know the oscillator frequency,
*          pre-scalers and so on. Since these settings are made in MCU and(or) in other modules it is
*          not possible to calculate such times. Hence the conversions between time and ticks shall
*          be part of an upper layer.
*          The driver needs to be initialized before calling Gpt_GetTimeRemaining(). Otherwise, the
*          function shall raise the development error GPT_E_UNINIT and return 0.
*
*
* @param[in]     channel - channel id
*
* @return  Gpt_ValueType - Returns the time remaining until the target time is reached in number of ticks.
*
* @api
*
* @pre           The driver needs to be initialized.
* @implements    Gpt_GetTimeRemaining_Activity
*/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType channel)
{
	Gpt_HwChannelInfoType returnHwChannelInfo = {FALSE, 0U};
	Gpt_HwChannelInfoType * pRetHwChannelInfo = &returnHwChannelInfo;
    Gpt_ChannelType ChannelIndex;

    Gpt_ValueType returnValue = 0U;
    uint32 coreID = (uint32)Gpt_GetCoreID();

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_TIMEREMAINING_ID, channel, coreID))
    {
#endif
        ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
        /* Calculate the remaining time from the elapsed time*/
        /* Gpt_Ipw_GetTimeElapsed() shall be called first, because the occurred ISRs can
        change the logical channel state between the checking of logical channel state
        and timestamps retrieval*/
        returnValue = Gpt_Ipw_GetTimeElapsed((((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)), pRetHwChannelInfo);

        /*Check the channel status*/
        switch(Gpt_aChannelInfo[coreID][channel].eChannelStatus)
        {
            case GPT_STATUS_RUNNING:
            {
                /*Check if channel counter has already roll-over*/
                if((TRUE == returnHwChannelInfo.bChannelRollover) && \
                   (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_eChannelMode)
                  )
                {
                    /*The timer has already expired.The hardware timer status is not yet
                    synchronized with the logical timer status*/
                    returnValue = 0U;
                }
                else
                {
                    /*Calculate remaining time from elapsed time*/
                    returnValue = returnHwChannelInfo.uTargetTime - returnValue;
                }
            }
            break;
            case GPT_STATUS_INITIALIZED:
            {
                returnValue = 0U;
            }
            break;
            case GPT_STATUS_STOPPED:
            {
                returnValue = returnHwChannelInfo.uTargetTime-Gpt_aStopTime[coreID][channel];
            }
            break;
            case GPT_STATUS_EXPIRED:
            {
                returnValue = 0U;
            }
            break;
            default:
                /*Only the above four channel states are allowed when this function is called*/
                break;
        }
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif

    return returnValue;
}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver function for starting a timer channel.
* @details The function Gpt_StartTimer shall start the selected timer channel with a defined
*          time-out period.
*          The function Gpt_StartTimer shall invoke the configured notification for that channel
*          (see also GPT292) after the time-out period referenced via the parameter value (if
*          enabled).
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          In production mode no error is generated. The rational is that it adds no
*          additional functionality to the driver. In this case the timer will be restarted with the
*          time-out value, given as a parameter to the service.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          To get times out of register values it is necessary to know the oscillator
*          frequency, pre-scalers and so on. Since these settings are made in MCU and(or) in other
*          modules it is not possible to calculate such times. Hence the conversions between time
*          and ticks shall be part of an upper layer.
*          The driver needs to be initialized before calling Gpt_StartTimer(). Otherwise, the
*          function Gpt_StartTimer shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel channel id
* @param[in]     value   time-out period (in number of ticks) after a notification or a
*                        wakeup event shall occur
*
* @api
* @return void
*
* @pre     The driver needs to be initialized.
* @implements    Gpt_StartTimer_Activity
*/
void Gpt_StartTimer
(
    Gpt_ChannelType channel,
    Gpt_ValueType value
)
{
    uint8 ChannelIndex;
    Std_ReturnType returnValue;
    uint32 coreID = (uint32)Gpt_GetCoreID();

    if ((Std_ReturnType)E_OK == Gpt_ValidateChannelStatus(GPT_STARTTIMER_ID, channel, coreID))
    {
#if (GPT_VALIDATE_PARAM  == STD_ON)
        if ((Std_ReturnType)E_OK == Gpt_ValidateParamValue(GPT_STARTTIMER_ID, channel, value, coreID))
        {
#endif
            ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
            /*Enable hardware interrupts for the one-shot mode to set the status of  channel*/
            if (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_eChannelMode)
            {
                Gpt_Ipw_EnableInterrupt
                (
                    ((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)
                );
            }

            /* Change GPT channel status.Channel status change shall be made before to start
            the hardware in order to not change the channel status from EXPIRED to RUNNING*/
            Gpt_aChannelInfo[coreID][channel].eChannelStatus = GPT_STATUS_RUNNING;

            /* Call low level API */
            returnValue = Gpt_Ipw_StartTimer(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig),value);

            if((Std_ReturnType)E_OK != returnValue)
            {
                (void)Det_ReportRuntimeError\
                (\
                    (uint16)GPT_MODULE_ID,\
                    (uint8)GPT_INSTANCE_ID,\
                    (uint8)GPT_STARTTIMER_ID,\
                    (uint8)GPT_E_TIMEOUT\
                );
            }
#if (GPT_VALIDATE_PARAM  == STD_ON)
        }
#endif
    }
    return;
}
/*================================================================================================*/
/**
* @brief   GPT driver function for stopping a timer channel.
* @details Service for stopping the selected timer channel
*          Stopping a timer channel, not been started before will not return a development error
*          Timer channels configured in one shot mode are stopped automatically, when the
*          time-out period has expired.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_StopTimer(). Otherwise,
*          the function shall raise the development error GPT_E_UNINIT.
*
* @param[in]    channel        channel id
* @return       void
*
* @api
*
* @pre          The driver needs to be initialized. Gpt_StartTimer must be called before.
* @implements   Gpt_StopTimer_Activity
*/
void Gpt_StopTimer(Gpt_ChannelType channel)
{
	Gpt_HwChannelInfoType returnHwChannelInfo = {FALSE, 0U};
#if ((GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON))
	Gpt_HwChannelInfoType * pRetHwChannelInfo = &returnHwChannelInfo;
    Gpt_ValueType uElapsedTime = 0U;
#endif
    Gpt_ChannelType ChannelIndex;

    uint32 coreID = (uint32)Gpt_GetCoreID();

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_STOPTIMER_ID, channel, coreID))
    {
#endif
        ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
        /*Gpt_Ipw_GetTimeElapsed() shall be called first, because the occurred ISRs can change
        the logical channel state between the checking of logical channel state and timestamps
        retrieval*/
#if ((GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON))
        /* Get the elapsed  time  for later use by other API calls*/
        uElapsedTime = Gpt_Ipw_GetTimeElapsed((((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)), pRetHwChannelInfo);
#endif

        /*Check the logical channel status*/
        if (GPT_STATUS_RUNNING == Gpt_aChannelInfo[coreID][channel].eChannelStatus)
        {
            /* Call low level stop timer */
            Gpt_Ipw_StopTimer(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig));

            if ((TRUE == returnHwChannelInfo.bChannelRollover) && \
                (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_eChannelMode)
            )
            {
                /*This action could be executed only when the function is called during a critical
                section implemented by disabling all interrupts*/
                /*Set channel status to EXPIRED*/
                Gpt_aChannelInfo[coreID][channel].eChannelStatus = GPT_STATUS_EXPIRED;
            }
            else
            {
#if ((GPT_TIME_REMAINING_API == STD_ON) || (GPT_TIME_ELAPSED_API == STD_ON))
                /* Store the stopping time for later use by other API calls*/
                Gpt_aStopTime[coreID][channel] = uElapsedTime;
#endif

                /* Set GPT channel status to stopped*/
                Gpt_aChannelInfo[coreID][channel].eChannelStatus = GPT_STATUS_STOPPED;
            }
        }
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
    return;
}

/*================================================================================================*/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
* @brief   GPT driver function for enabling the notification for a timer channel.
* @details Service for enabling the notification for a channel during runtime.
*          This function can be called, while the timer is already running.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_EnableNotification(). Otherwise,
*          the function Gpt_EnableNotification shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
* @return void
* @api
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_EnableNotification_Activity
*/
void Gpt_EnableNotification(Gpt_ChannelType channel)
{
    uint8 ChannelIndex;
    uint32 coreID = (uint32)Gpt_GetCoreID();

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_ENABLENOTIFICATION_ID, channel, coreID))
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        if ((Std_ReturnType)E_OK == Gpt_ValidateChannelNotification(GPT_ENABLENOTIFICATION_ID, channel, coreID))
        {
#endif
            ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
            /* Set the enable notification attribute */
            Gpt_aChannelInfo[coreID][channel].bNotificationEnabled = TRUE;

            if (GPT_MODE_NORMAL == Gpt_eMode[coreID])
            {
                /*Enable hardware interrupts*/
                Gpt_Ipw_EnableInterrupt
                (
                    ((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)
                );
            }
#if (GPT_VALIDATE_PARAM == STD_ON)
        }
#endif
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif

    return;
}
#endif
/*================================================================================================*/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
* @brief   GPT driver function for disabling the notification for a timer channel.
* @details Service for disabling the notification for a channel during runtime.
*          This function can be called, while the timer is already running
*          When disabled, no notification will be sent. When re-enabled again, the user
*          will not be notified of events, occurred while notifications have been disabled.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_DisableNotification().
*          Otherwise, the function shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
* @return void
* @api
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_DisableNotification_Activity
*/
void Gpt_DisableNotification(Gpt_ChannelType channel)
{
    uint8 ChannelIndex;
    uint32 coreID = (uint32)Gpt_GetCoreID();

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_DISABLENOTIFICATION_ID, channel, coreID))
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        if ((Std_ReturnType)E_OK == Gpt_ValidateChannelNotification(GPT_DISABLENOTIFICATION_ID, channel, coreID))
        {
#endif
            ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
            /* Set the enable notification attribute */
            Gpt_aChannelInfo[coreID][channel].bNotificationEnabled = FALSE;

            /* Disable hardware interrupts if the channel is not running in the ONE-SHOT mode.
            This is needed because the channel state is updated by ISR for ONE-SHOT mode */
            if ((GPT_MODE_NORMAL == Gpt_eMode[coreID]) && \
                ((GPT_CH_MODE_CONTINUOUS == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_eChannelMode) \
                 || (GPT_STATUS_RUNNING != Gpt_aChannelInfo[coreID][channel].eChannelStatus)
                )
               )
            {
                /*Disable hardware interrupts*/
                Gpt_Ipw_DisableInterrupt
                (
                    ((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)
                );
            }
#if (GPT_VALIDATE_PARAM == STD_ON)
        }
#endif
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
    return;
}
#endif

/*================================================================================================*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
* @brief        GPT driver function for setting the operation mode.
* @details      Service for GPT mode selection. This service shall set the operation mode to the given
*               mode parameter .
*               When sleep mode is requested, the ECU State Manager calls Gpt_SetMode with mode
*               parameter "GPT_MODE_SLEEP" and prepares the GPT for sleep mode. The MCU Driver is then
*               putting the controller into SLEEP mode
*               The driver needs to be initialized before calling Gpt_SetMode(). Otherwise, the
*               function Gpt_SetMode shall raise the development error GPT_E_UNINIT.
*
* @param[in]    eMode        operation mode
*                           - GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
*                           - GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable)
* @return       void
* @api
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_SetMode_Activity
*/
void Gpt_SetMode(Gpt_ModeType Mode)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void)Mode;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    uint32 coreID = (uint32)Gpt_GetCoreID();

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    /*Validate the driver calling context*/
    if((Std_ReturnType)E_OK == Gpt_ValidateGlobalCall(GPT_SETMODE_ID, coreID))
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        /*Validate the driver calling context*/
        if((Std_ReturnType)E_OK == Gpt_ValidateParamMode(Mode))
        {
#endif
            /*Implements the behaviour for the sleep mode */
            if(GPT_MODE_SLEEP == Mode)
            {
                /* Check channel has wakeup enabled at runtime */
                Gpt_CheckStatusWakeupEnabled(coreID);

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
                /* De-initialize and Stop Predef Timers. */
                Gpt_Ipw_StopPredefTimer(Gpt_pConfig[coreID]);
#endif
#if (((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) || \
     (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || \
     (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON))
                /* Set the driver mode to sleep */
                Gpt_eMode[coreID] = GPT_MODE_SLEEP;
#endif

            }
            else if (GPT_MODE_NORMAL == Mode)
            {
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
                   if ((Gpt_ModeType)GPT_MODE_SLEEP == Gpt_eMode[coreID])
                   {
                   /* Start for each predef timer status informations. */
                   Gpt_Ipw_StartPredefTimer(Gpt_pConfig[coreID]);
                   }
#endif
                /* Check channel has notification enabled at runtime */
                Gpt_CheckStatusNotificationEnabled(coreID);
#if (((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) || \
     (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || \
     (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON))
                /* Set the driver mode to normal mode*/
                Gpt_eMode[coreID] = GPT_MODE_NORMAL;
#endif

            }
            else
            {
              /* This else clause is required due to MISRA rules */
            }
#if (GPT_VALIDATE_PARAM == STD_ON)
        }
#endif

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif

#endif /*GPT_REPORT_WAKEUP_SOURCE*/
    return;
}
#endif

/*================================================================================================*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
* @brief        GPT driver function for disabling the wakeup interrupt invocation for a timer channel.
* @details      This service shall disable the wakeup interrupt invocation of a single GPT
*               channel.
*               Usage of re-entrant capability is only allowed if the callers take care that
*               there is no simultaneous usage of the same channel.
*               The driver needs to be initialized before calling Gpt_DisableWakeup(). Otherwise, the
*               function Gpt_DisableWakeup shall raise the development error GPT_E_UNINIT.
*
* @param[in]    channel        channel id
* @return       void
* @api
*
* @pre          The driver needs to be initialized.
* @implements   Gpt_DisableWakeup_Activity
*/
void Gpt_DisableWakeup(Gpt_ChannelType channel)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    uint8 ChannelIndex;
    uint32 coreID = (uint32)Gpt_GetCoreID();
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void)channel;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_DISABLEWAKEUP_ID, channel, coreID))
    {
#endif

#if (GPT_VALIDATE_PARAM == STD_ON)
        if((Std_ReturnType)E_OK == Gpt_ValidateChannelWakeup(GPT_DISABLEWAKEUP_ID, channel, coreID))
        {
#endif
            ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
            /* Set the enable wakeup attribute */
            Gpt_aChannelInfo[coreID][channel].bWakeupEnabled = FALSE;

            /* Disable hardware interrupts if the channel is not running in the ONE-SHOT mode.
            This is needed because the channel state is updated by ISR for ONE-SHOT mode */
            if ((GPT_MODE_SLEEP == Gpt_eMode[coreID]) && \
                ((GPT_CH_MODE_CONTINUOUS == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_eChannelMode)
                 || (GPT_STATUS_RUNNING != Gpt_aChannelInfo[coreID][channel].eChannelStatus)
                )
               )
            {
                /*Disable hardware interrupts*/
                Gpt_Ipw_DisableInterrupt
                (
                    ((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)
                );
            }
#if (GPT_VALIDATE_PARAM == STD_ON)
        }
#endif
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
#endif /*GPT_REPORT_WAKEUP_SOURCE*/
    return;
}
#endif

/*================================================================================================*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
* @brief        GPT driver function for enabling the wakeup interrupt invocation for a timer channel.
* @details      This service shall re-enable the wakeup interrupt invocation of a single GPT
*               channel.
*               If supported by hardware and enabled, an internal hardware timer can serve as a
*               wakeup source
*               Usage of re-entrant capability is only allowed if the callers take care that
*               there is no simultaneous usage of the same channel.
*
* @param[in]    channel        channel id
* @return       void
* @api
*
* @pre          The driver needs to be initialized. The channel must be configured as wakeup capable.
* @implements   Gpt_EnableWakeup_Activity
*/
void Gpt_EnableWakeup(Gpt_ChannelType channel)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    uint8 ChannelIndex;
    uint32 coreID = (uint32)Gpt_GetCoreID();
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void)channel;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_ENABLEWAKEUP_ID, channel, coreID))
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        if((Std_ReturnType)E_OK == Gpt_ValidateChannelWakeup(GPT_ENABLEWAKEUP_ID, channel, coreID))
        {
#endif
            ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
            /* Functionality implementation */
            /* Set the enable wakeup attribute */
            Gpt_aChannelInfo[coreID][channel].bWakeupEnabled = TRUE;

            if (GPT_MODE_SLEEP == Gpt_eMode[coreID])
            {
                /*Enable hardware interrupts*/
                Gpt_Ipw_EnableInterrupt
                (
                    ((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig)
                );
            }
#if (GPT_VALIDATE_PARAM == STD_ON)
        }
#endif
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
#endif /*GPT_REPORT_WAKEUP_SOURCE*/
    return;
}
#endif

/*================================================================================================*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)

/**
* @brief        GPT driver function for checking if a wakeup capable GPT channel is the source for a
*               wakeup event.
* @details      Checks if a wakeup capable GPT channel is the source for a wakeup event and calls the ECU
*               state manager service EcuM_SetWakeupEvent in case of a valid GPT channel wakeup event.
*               The driver needs to be initialized before calling Gpt_CheckWakeup(). Otherwise, the
*               function Gpt_CheckWakeup shall raise the development error GPT_E_UNINIT.
*
* @param[in]    wakeupSource        wakeup source
* @return       void
* @api
*
* @pre          The driver needs to be initialized. The channel must be configured as wakeup capable.
* @implements   Gpt_CheckWakeup_Activity
*/
void Gpt_CheckWakeup(EcuM_WakeupSourceType wakeupSource)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    uint32 coreID = (uint32)Gpt_GetCoreID();
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void) wakeupSource;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    Gpt_ChannelType channel;
    Gpt_ChannelType ChannelIndex;


#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    /*Validate the driver calling context*/
    if((Std_ReturnType)E_OK == Gpt_ValidateGlobalCall(GPT_CHECKWAKEUP_ID, coreID))
    {
#endif
        for (ChannelIndex = 0U; ChannelIndex < Gpt_pConfig[coreID]->channelCount; ChannelIndex++)
        {
            channel = Gpt_ConvertChannelIndexToChannel(ChannelIndex, coreID);
            if(channel < GPT_HW_CHANNEL_NUM)
            {
                if ((((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_uWakeupSource) == wakeupSource) && \
                    ((boolean)TRUE == Gpt_aChannelInfo[coreID][channel].bWakeupGenerated)
                    )
                {
                    /*Reset the wakeup flag */
                    Gpt_aChannelInfo[coreID][channel].bWakeupGenerated = FALSE;

                    /* Calling EcuM_SetWakeupEvent and exit*/
                    EcuM_SetWakeupEvent(wakeupSource);

                    break;
                }
            }
        }    /*for*/
#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
#endif /* GPT_REPORT_WAKEUP_SOURCE */
    return;
}
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

/*================================================================================================*/
/**
* @brief        Gpt common handler to implements generic part of the ISR.
* @details      Generic function used by all interrupt service routines to call notification
*               functions  and wakeup the EcuM
*
* @param[in]    channel     logic channel number
* @return       void
* @pre          The driver needs to be initialized.
* @implements   Gpt_ProcessCommonInterrupt_Activity
*/
void Gpt_ProcessCommonInterrupt(uint8 channel)
{
    uint8 ChannelIndex;
    uint32 coreID = (uint32)Gpt_GetCoreID();

    if (Gpt_pConfig[coreID] != NULL_PTR)
    {
        /* Extract the logical channel from the hardware to logic map table */
        ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];

        /* Change the channel status for one-shot mode */
        if (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_eChannelMode)
        {
            /* Change the channel status to expired */
            Gpt_aChannelInfo[coreID][channel].eChannelStatus = GPT_STATUS_EXPIRED;
        }
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        if ((GPT_MODE_NORMAL == Gpt_eMode[coreID]) && (TRUE == Gpt_aChannelInfo[coreID][channel].bNotificationEnabled))
        {
            (*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_pfNotification();
        }
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
        if ((GPT_MODE_SLEEP == Gpt_eMode[coreID]) && (TRUE == Gpt_aChannelInfo[coreID][channel].bWakeupEnabled))
        {
            Gpt_aChannelInfo[coreID][channel].bWakeupGenerated =TRUE;
            EcuM_CheckWakeup((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_uWakeupSource);
        }
#endif
#endif
    }
    return;
}
/*================================================================================================*/
#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief       The function changes the time out period value of the requested running channel.
* @details     The function changes the time out period (in number of ticks) of the channel is
*              running which will be used after the first compare matching.
*              This is a non-autosar function.
* @param[in]   channel        channel id
* @param[in]   value          time out period (in number of ticks) after a notification shall occur
* @return      void
* @pre         Gpt_Init and Gpt_StartTimer must be called before.
* @implements  Gpt_ChangeNextTimeoutValue_Activity
*/
void Gpt_ChangeNextTimeoutValue(Gpt_ChannelType channel, Gpt_ValueType value)
{
    uint8 ChannelIndex;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType returnValue;
#endif

    uint32 coreID = (uint32)Gpt_GetCoreID();

    if ((Std_ReturnType)E_OK == Gpt_ValidateChannelStatus(GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID, channel, coreID))
    {
#if (GPT_VALIDATE_PARAM  == STD_ON)
        if ((Std_ReturnType)E_OK == Gpt_ValidateParamValue(GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID, channel, value, coreID))
        {
#endif
        ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            /* Call low level API */
            returnValue = Gpt_Ipw_ChangeNextTimeoutValue(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig), value);

            if((Std_ReturnType)E_OK != returnValue)
            {
                (void)Det_ReportError\
                (\
                    (uint16)GPT_MODULE_ID,\
                    (uint8)GPT_INSTANCE_ID,\
                    (uint8)GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID,\
                    (uint8)GPT_E_PARAM_CHANNEL\
                );
            }
#else
            /* Call low level API */
            (void)Gpt_Ipw_ChangeNextTimeoutValue(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig), value);
#endif

#if (GPT_VALIDATE_PARAM  == STD_ON)
        }
#endif
    }
    return;
}
#endif /* GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */

/*================================================================================================*/
#if (GPT_CHAIN_MODE == STD_ON)
/**
* @brief     The function enables the chain functionality for timer.
* @details   The function enables the chain functionality for timer. Timer will be chained with timer n-1.
             Channel 0 cannot be chained.
*            This is a non-autosar function.
* @param[in] channel        channel id
* @return    void
* @pre       Gpt_Init must be called before.
*
* @implements Gpt_Channel_EnableChainMode_Activity
*/
void Gpt_Channel_EnableChainMode(Gpt_ChannelType channel)
{
    uint8 ChannelIndex;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType returnValue;
#endif

    uint32 coreID = (uint32)Gpt_GetCoreID();
    if ((Std_ReturnType)E_OK == Gpt_ValidateChannelStatus(GPT_ENABLE_CHAIN_MODE_ID, channel, coreID))
    {
        ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        /* Call low level API */
        returnValue = Gpt_Ipw_EnableChainMode(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig));

        if((Std_ReturnType)E_OK != returnValue)
        {
            (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)GPT_ENABLE_CHAIN_MODE_ID,\
                (uint8)GPT_E_PARAM_CHANNEL\
            );
        }
#else
        /*Call low level API.*/
        (void)Gpt_Ipw_EnableChainMode(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig));
#endif
    }
}
#endif /*GPT_CHAIN_MODE == STD_ON*/
/*================================================================================================*/
#if (GPT_CHAIN_MODE == STD_ON)
/**
* @brief     The function disables the chain functionality for timer.
* @details   The function disables the chain functionality for timer. Timer will not be chained with timer n-1.
             Channel 0 cannot be chained or unchained.
*            This is a non-autosar function.
* @param[in] channel        channel id
* @return    void
* @pre       Gpt_Init must be called before.
*
* @implements Gpt_Channel_DisableChainMode_Activity
*/
void Gpt_Channel_DisableChainMode(Gpt_ChannelType channel)
{
    uint8 ChannelIndex;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType returnValue;
#endif

    uint32 coreID = (uint32)Gpt_GetCoreID();

    if ((Std_ReturnType)E_OK == Gpt_ValidateChannelStatus(GPT_DISABLE_CHAIN_MODE_ID, channel, coreID))
    {
        ChannelIndex = (*(Gpt_pConfig[coreID]->u8GptChannelIdToIndexMap))[channel];
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        /* Call low level API */
        returnValue = Gpt_Ipw_DisableChainMode(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig));

        if((Std_ReturnType)E_OK != returnValue)
        {
            (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)GPT_DISABLE_CHAIN_MODE_ID,\
                (uint8)GPT_E_PARAM_CHANNEL\
            );
        }
#else
        /*Call low level API.*/
        (void)Gpt_Ipw_DisableChainMode(((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig));
#endif
    }
}
#endif /*GPT_CHAIN_MODE == STD_ON*/
/*================================================================================================*/
#if (GPT_SET_CLOCK_MODE == STD_ON)
/**
* @brief     This function changes the channel pre scaler.
* @details   This function sets all channels pre scalers based on the input mode.
*
* @param[in] eClkMode   prescaler setting ( NORMAL or ALTERNATE )
* @return    void
* @pre       Gpt_Init must be called before.
*
* @implements     Gpt_SetClockMode_Activity
*/
void Gpt_SetClockMode(Gpt_ClockModeType eClkMode)
{
    uint32 coreID = (uint32)Gpt_GetCoreID();
    Gpt_ChannelType ChannelIndex;

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    Std_ReturnType returnValue;

    returnValue = Gpt_ValidateGlobalCall(GPT_SET_CLOCK_MODE_ID, coreID);
    if((Std_ReturnType)E_OK == returnValue)
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        if ((Std_ReturnType)E_OK == Gpt_ValidateParamSetClockMode(eClkMode))
        {
#endif
            for (ChannelIndex = 0U; ChannelIndex < Gpt_pConfig[coreID]->instanceCount; ChannelIndex++)
            {
                    Gpt_Ipw_SetClockModeInStance
                    (
                        (&((*(Gpt_pConfig[coreID]->Gpt_Ipw_HwInstanceConfig))[ChannelIndex])), eClkMode
                    );
            }

#if (GPT_HW_CHANNEL_USED == STD_ON)
            for (ChannelIndex = 0U; ChannelIndex < Gpt_pConfig[coreID]->channelCount; ChannelIndex++)
            {
                    Gpt_Ipw_SetClockModeChannel
                    (
                        ((*(Gpt_pConfig[coreID]->Gpt_pChannelConfig))[ChannelIndex].Gpt_Ipw_HwChannelConfig),eClkMode
                    );
            }
#endif

#if (GPT_VALIDATE_PARAM  == STD_ON)
        }
#endif
#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}
#endif /* GPT_SET_CLOCK_MODE */

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/**
* @brief     Provides the current value of the given predefined free-running timer
* @details   This function provides the current value of the given predefined free-running timer.
*
* @param[in]  PredefTimer: Gpt_PredefTimerType ( GPT_PREDEF_TIMER_1US_16BIT,
*                                               GPT_PREDEF_TIMER_1US_24BIT,
*                                               GPT_PREDEF_TIMER_1US_32BIT
*                                               GPT_PREDEF_TIMER_100US_32BIT)
* @param[out] TimeValuePtr: Pointer to time value destination data in RAM
* @pre        Gpt_Init must be called before.
* @return     returnValue - E_OK: no error has been detected.
*                         - E_NOT_OK: aborted due to errors.
*
* @implements     Gpt_GetPredefTimerValue_Activity
*/
Std_ReturnType Gpt_GetPredefTimerValue
(
    Gpt_PredefTimerType PredefTimer,
    uint32 * TimeValuePtr
)
{
    Std_ReturnType returnValue;
    Gpt_ChannelType channel;
    uint32 coreID = (uint32)Gpt_GetCoreID();

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    returnValue = Gpt_ValidateGlobalCall(GPT_GET_PREDEF_TIMERVALUE_ID, coreID);
    if((Std_ReturnType)E_OK == returnValue)
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        returnValue = Gpt_ValidatePointerGetPredefTimer(TimeValuePtr);
        if((Std_ReturnType)E_OK == returnValue)
        {
            returnValue = Gpt_ValidateParamTypePredefTimer(PredefTimer, coreID);
            if((Std_ReturnType)E_OK == returnValue)
            {
#endif

               returnValue = Gpt_ValidateMode(GPT_GET_PREDEF_TIMERVALUE_ID, coreID);
               if((Std_ReturnType)E_OK ==returnValue)
               {

                        channel = (Gpt_ChannelType)PredefTimer;

                        Gpt_Ipw_GetPredefTimerValue((Gpt_pConfig[coreID]->Gpt_pChannelPredefConfigType)[channel], PredefTimer, TimeValuePtr);

               }
               else
               {
                   *TimeValuePtr = 0U;
               }

#if (GPT_VALIDATE_PARAM == STD_ON)
            }
            else
            {
                *TimeValuePtr = 0U;
            }

        }
        else
        {
            /* This else clause is required due to MISRA rules */
        }
#endif
#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
    return returnValue;
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif /* GPT_C */
/** @} */

