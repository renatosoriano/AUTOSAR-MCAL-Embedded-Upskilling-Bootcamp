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
 *   @file
 *
 *   @addtogroup Platform
 *   @{
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Mcal.h"
#include "Platform.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_VENDOR_ID_C                     43
#define CDD_PLATFORM_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_PLATFORM_AR_RELEASE_MINOR_VERSION_C      7
#define CDD_PLATFORM_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_PLATFORM_SW_MAJOR_VERSION_C              2
#define CDD_PLATFORM_SW_MINOR_VERSION_C              0
#define CDD_PLATFORM_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform header file are of the same vendor */
#if (CDD_PLATFORM_VENDOR_ID_C != CDD_PLATFORM_VENDOR_ID)
    #error "Platform.c and Platform.h have different vendor ids"
#endif
/* Check if current file and Platform header file are of the same Autosar version */
#if ((CDD_PLATFORM_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform.c and Platform.h are different"
#endif
/* Check if current file and Platform header file are of the same Software version */
#if ((CDD_PLATFORM_SW_MAJOR_VERSION_C != CDD_PLATFORM_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_SW_MINOR_VERSION_C != CDD_PLATFORM_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_SW_PATCH_VERSION_C != CDD_PLATFORM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform.c and Platform.h are different"
#endif


/* Check if current file and Platform_Ipw header file are of the same vendor */
#if (CDD_PLATFORM_VENDOR_ID_C != CDD_PLATFORM_IPW_VENDOR_ID)
    #error "Platform.c and Platform_Ipw.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw header file are of the same Autosar version */
#if ((CDD_PLATFORM_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform.c and Platform_Ipw.h are different"
#endif
/* Check if current file and Platform_Ipw header file are of the same Software version */
#if ((CDD_PLATFORM_SW_MAJOR_VERSION_C != CDD_PLATFORM_IPW_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_SW_MINOR_VERSION_C != CDD_PLATFORM_IPW_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_SW_PATCH_VERSION_C != CDD_PLATFORM_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform.c and Platform_Ipw.h are different"
#endif

/*==================================================================================================
 *                                        GLOBAL CONSTANTS
==================================================================================================*/

#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

extern const Platform_ConfigType *const Platform_Config[PLATFORM_MAX_PARTITIONS];

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
 /*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"


#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/*==================================================================================================
 *                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @internal
 * @brief         Initializes the platform settings based on user configuration.
 * @implements    Platform_Init_Activity
 */
void Platform_Init(const Platform_ConfigType *pConfig)
{
    uint8 u8CoreId;

    u8CoreId = (uint8)Platform_GetCoreID();
    (void)pConfig;
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != pConfig)
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_INIT_ID, PLATFORM_E_PARAM_POINTER);
    }
    else
    {
#if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
        if (NULL_PTR == (Platform_Config[u8CoreId]))
        {
            (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_INIT_ID, PLATFORM_E_PARAM_CONFIG);
        }
        else
        {
#endif /*(PLATFORM_MULTICORE_SUPPORT == STD_ON)*/
#endif /*(PLATFORM_DEV_ERROR_DETECT == STD_ON)*/


            Platform_Ipw_Init(Platform_Config[u8CoreId]->pIpwConfig);




#if (PLATFORM_ENABLE_MPU == STD_ON)
            Platform_Ipw_Mpu_Init(Platform_Config[u8CoreId]->pIpwConfig);
#endif




#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
#if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
        }
#endif /*(PLATFORM_MULTICORE_SUPPORT == STD_ON)*/
    }
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

}


/**
 * @internal
 * @brief         Configures (enables/disables) an interrupt request.
 * @implements    Platform_SetIrq_Activity
 */
Std_ReturnType Platform_SetIrq(IRQn_Type eIrqNumber, boolean bEnable)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)eIrqNumber > (sint32)INT_CTRL_IP_IRQ_MAX) || \
        ((sint32)INT_CTRL_IP_IRQ_MIN > (sint32)eIrqNumber))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_IRQ_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        Platform_Ipw_SetIrq(eIrqNumber, bEnable);
    }
    return RetValue;
}

/**
 * @internal
 * @brief         Configures the priority of an interrupt request.
 * @implements    Platform_SetIrqPriority_Activity
 */
Std_ReturnType Platform_SetIrqPriority(IRQn_Type eIrqNumber, uint8 u8Priority)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
#if (INT_CTRL_IP_CORTEXM == STD_ON)
    if (((sint32)eIrqNumber > (sint32)INT_CTRL_IP_IRQ_MAX) || \
        ((sint32)INT_CTRL_IP_IRQ_MIN > (sint32)eIrqNumber) || \
        (u8Priority >= (uint8)(1U << INT_CTRL_IP_NVIC_PRIO_BITS)))
#else
    if (((sint32)eIrqNumber > (sint32)INT_CTRL_IP_IRQ_MAX) || \
        ((sint32)INT_CTRL_IP_IRQ_MIN > (sint32)eIrqNumber) || \
        (u8Priority >= (uint8)(1U << INT_CTRL_IP_GIC_PRIO_BITS)))
#endif
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_IRQ_PRIO_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        Platform_Ipw_SetIrqPriority(eIrqNumber, u8Priority);
    }
    return RetValue;
}

/**
 * @internal
 * @brief         Returns the priority of an interrupt request.
 * @implements    Platform_GetIrqPriority_Activity
 */
Std_ReturnType Platform_GetIrqPriority(IRQn_Type eIrqNumber, uint8 * u8Priority)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)eIrqNumber > (sint32)INT_CTRL_IP_IRQ_MAX) || \
        ((sint32)INT_CTRL_IP_IRQ_MIN > (sint32)eIrqNumber))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_GET_IRQ_PRIO_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else if (u8Priority == NULL_PTR)
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_GET_IRQ_PRIO_ID, PLATFORM_E_PARAM_POINTER);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        *u8Priority = Platform_Ipw_GetIrqPriority(eIrqNumber);
    }

    return RetValue;
}

/**
 * @internal
 * @brief         Installs a new handler for an interrupt request.
 * @implements    Platform_InstallIrqHandler_Activity
 */
Std_ReturnType Platform_InstallIrqHandler(IRQn_Type eIrqNumber,
                                          const Platform_IrqHandlerType pfNewHandler,
                                          Platform_IrqHandlerType* const pfOldHandler)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)eIrqNumber > (sint32)INT_CTRL_IP_IRQ_MAX) || \
        ((sint32)INT_CTRL_IP_IRQ_MIN > (sint32)eIrqNumber))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_INSTALL_HANDLER_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
        Platform_Ipw_InstallIrqHandler(eIrqNumber, pfNewHandler, pfOldHandler);
    }
    return RetValue;
}





#if (PLATFORM_ENABLE_MPU == STD_ON)
/*================================================================================================*/

 /**
 * @brief         Configures the region selected by u8RegionNum with the data from pUserConfigPtr
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum:    region number
 * @param[in]     pUserConfigPtr: pointer to the region configuration structure for MPU.
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Platform_Mpu_SetRegionConfig_Activity */
void Platform_Mpu_SetRegionConfig(uint8 u8RegionNum, const Platform_Mpu_RegionConfigType * const pUserConfigPtr)
{
    Platform_Ipw_Mpu_SetRegionConfig(u8RegionNum, pUserConfigPtr);
}

/**
 * @brief         Enables or disabled a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8Region : Region to be modified
 * @param[in]     bEnable  : Specifies wheter the region is enabled or disabled
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Platform_Mpu_EnableRegion_Activity */
void Platform_Mpu_EnableRegion(uint8 u8RegionNum, boolean bEnable)
{
    Platform_Ipw_Mpu_EnableRegion(u8RegionNum, bEnable);
}

/**
 * @brief         Modify the access mode for a master to a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum     : Region to be modified
 * @param[in]     eSupervisorMode : Specifies the new mode access in supervisor mode
 * @param[in]     eUserMode       : Specifies the new mode access in user mode
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Platform_Mpu_SetAccessMode_Activity */
void Platform_Mpu_SetAccessMode(uint8 u8RegionNum,
                          Platform_Mpu_MasterType eMaster,
                          Platform_Mpu_SupervisorAccessModeType eSupervisorMode,
                          Platform_Mpu_UserAccessModeType eUserMode
                         )
{
    Platform_Ipw_Mpu_SetAccessMode(u8RegionNum, eMaster, eSupervisorMode, eUserMode);
}

/**
 * @brief         Retrieve error details
 *
 * @details       This function is Reentrant
 *
 * @param[out]    pErrorDetails : Storage where the data will be saved
 * @return        boolean - TRUE if an error was present, FALSE otherwise
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Platform_Mpu_GetErrorDetails_Activity */
Std_ReturnType Platform_Mpu_GetErrorDetails(Platform_Mpu_ErrorDetailsType * pErrorDetails)
{
    Std_ReturnType retval = (Std_ReturnType)E_NOT_OK;
    boolean bErr;
    bErr = Platform_Ipw_Mpu_GetErrorDetails(pErrorDetails);

    if (TRUE == bErr)
    {
        retval = (Std_ReturnType)E_OK;
    }
    else
    {
        retval = (Std_ReturnType)E_NOT_OK;
    }
    return retval;
}

#endif /* #if (STD_ON == PLATFORM_ENABLE_MPU)  */


#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} */
