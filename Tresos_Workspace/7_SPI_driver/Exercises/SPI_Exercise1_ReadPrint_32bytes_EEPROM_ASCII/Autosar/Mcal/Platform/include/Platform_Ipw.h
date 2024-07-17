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

#ifndef PLATFORM_IPW_H_
#define PLATFORM_IPW_H_

/**
*   @file
*
*   @internal
*   @addtogroup Platform_Ipw
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform_Ipw_Cfg.h"
#include "IntCtrl_Ip.h"
#include "System_Ip.h"

#include "Mpu_Ip_TypesDef.h"
#include "Mpu_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_IPW_VENDOR_ID                         43
#define CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION          4
#define CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION          7
#define CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION       0
#define CDD_PLATFORM_IPW_SW_MAJOR_VERSION                  2
#define CDD_PLATFORM_IPW_SW_MINOR_VERSION                  0
#define CDD_PLATFORM_IPW_SW_PATCH_VERSION                  0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Ipw_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID != CDD_PLATFORM_IPW_CFG_VENDOR_ID)
    #error "Platform_Ipw.h and Platform_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.h and Platform_Ipw_Cfg.h are different"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION != CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION != CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION != CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.h and Platform_Ipw_Cfg.h are different"
#endif

/* Check if current file and IntCtrl_Ip header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID != CDD_PLATFORM_INTCTRL_IP_VENDOR_ID)
    #error "Platform_Ipw.h and IntCtrl_Ip.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip.h header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.h and IntCtrl_Ip.h are different"
#endif
/* Check if current file and IntCtrl_Ip header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION != CDD_PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION != CDD_PLATFORM_INTCTRL_IP_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION != CDD_PLATFORM_INTCTRL_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.h and IntCtrl_Ip.h are different"
#endif

/* Check if current file and System_Ip header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID != CDD_PLATFORM_SYSTEM_IP_VENDOR_ID)
    #error "Platform_Ipw.h and System_Ip.h have different vendor ids"
#endif
/* Check if current file and System_Ip.h header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_SYSTEM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_SYSTEM_IP_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_SYSTEM_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.h and System_Ip.h are different"
#endif
/* Check if current file and System_Ip header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION != CDD_PLATFORM_SYSTEM_IP_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION != CDD_PLATFORM_SYSTEM_IP_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION != CDD_PLATFORM_SYSTEM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.h and System_Ip.h are different"
#endif

/* Check if current file and Mpu_Ip_Types header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID != CDD_PLATFORM_MPU_IP_TYPES_DEF_VENDOR_ID)
    #error "Platform_Ipw.h and Mpu_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Mpu_Ip_Types.h header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.h and Mpu_Ip_Types.h are different"
#endif
/* Check if current file and Mpu_Ip_Types header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION != CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.h and Mpu_Ip_Types.h are different"
#endif

/* Check if current file and Mpu_Ip header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID != CDD_PLATFORM_MPU_IP_VENDOR_ID)
    #error "Platform_Ipw.h and Mpu_Ip.h have different vendor ids"
#endif
/* Check if current file and Mpu_Ip.h header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MPU_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.h and Mpu_Ip.h are different"
#endif
/* Check if current file and Mpu_Ip header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION != CDD_PLATFORM_MPU_IP_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION != CDD_PLATFORM_MPU_IP_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION != CDD_PLATFORM_MPU_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.h and Mpu_Ip.h are different"
#endif

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (PLATFORM_ENABLE_MPU == STD_ON)
typedef Mpu_Ip_RegionConfigType              Platform_Mpu_RegionConfigType;
typedef Mpu_Ip_UserAccessModeType            Platform_Mpu_UserAccessModeType;
typedef Mpu_Ip_SupervisorAccessModeType      Platform_Mpu_SupervisorAccessModeType;
typedef Mpu_Ip_ErrorDetailsType              Platform_Mpu_ErrorDetailsType;
typedef Mpu_Ip_MasterType                    Platform_Mpu_MasterType;
#endif /* #if (STD_ON == PLATFORM_ENABLE_MPU)  */
/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
extern uint32 VTABLE[((uint32)(INT_CTRL_IP_IRQ_MAX)) + 16U + 1U];


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @internal
 * @brief         Initializes the platform settings based on user configuration.
 */
void Platform_Ipw_Init(const Platform_Ipw_ConfigType *pConfig);


/**
 * @internal
 * @brief         Enables/disables an interrupt by calling the Interrupt Controller IP layer.
 */
static inline void Platform_Ipw_SetIrq(IRQn_Type eIrqNumber, boolean bEnable)
{
    if (bEnable)
    {
        IntCtrl_Ip_EnableIrq(eIrqNumber);
    }
    else
    {
        IntCtrl_Ip_DisableIrq(eIrqNumber);
    }
}

/**
 * @internal
 * @brief         Sets the priority of an interrupt by calling the Interrupt Controller IP layer.
 */
static inline void Platform_Ipw_SetIrqPriority(IRQn_Type eIrqNumber, uint8 u8Priority)
{
    IntCtrl_Ip_SetPriority(eIrqNumber, u8Priority);
}

/**
 * @internal
 * @brief         Returns the priority of an interrupt by calling the Interrupt Controller IP layer.
 */
static inline uint8 Platform_Ipw_GetIrqPriority(IRQn_Type eIrqNumber)
{
    return IntCtrl_Ip_GetPriority(eIrqNumber);
}

/**
 * @internal
 * @brief         Installs a new interrupt handler by calling the Interrupt Controller IP layer.
 */
static inline void Platform_Ipw_InstallIrqHandler(IRQn_Type eIrqNumber,
                                                  const IntCtrl_Ip_IrqHandlerType pfNewHandler,
                                                  IntCtrl_Ip_IrqHandlerType* const pfOldHandler)
{
    IntCtrl_Ip_InstallHandler(eIrqNumber, pfNewHandler, pfOldHandler);
}

#if (PLATFORM_ENABLE_MPU == STD_ON)
/*
 * @brief         Initializes the Memory Protection Unit general parameters and
 *                region configurations
 * @details       This function is non-reentrant
 * @param[in]     pConfig: pointer to configuration structure for MPU.
 * @return        void
 * @pre           None
 */
void Platform_Ipw_Mpu_Init(const Platform_Ipw_ConfigType * pIpwConfig);

/*
 * @brief         Configures the region selected by regionNumber with the data from pUserConfigPtr
 * @details       This function is Reentrant
 * @param[in]     regionNumber: Region to be modified .
 * @param[in]     pUserConfigPtr: pointer to the region configuration structure for MPU.
 * @return        void
 * @pre           None
 */
void Platform_Ipw_Mpu_SetRegionConfig(uint8 u8RegionNum, const Platform_Mpu_RegionConfigType * const pUserConfigPtr);

/*
 * @brief         Enables or disabled a specific region
 * @details       This function is Reentrant
 * @param[in]     u8RegionNum : Region to be modified
 * @param[in]     bEnable  : Specifies wheter the region is enabled or disabled
 * @return        void
 * @pre           None
 */
void Platform_Ipw_Mpu_EnableRegion(uint8 u8RegionNum, boolean bEnable);

/*
 * @brief         Modify the User access mode for a master to a specific region
 * @details       This function is Reentrant
 * @param[in]     u8RegionNum : Region to be modified
 * @param[in]     eMaster     : Master to be modified
 * @param[in]     eSupervisorMode : Specifies the new mode access in supervisor mode
 * @param[in]     eUserMode       : Specifies the new mode access in user mode
 * @return        void
 * @pre           None
 */
void Platform_Ipw_Mpu_SetAccessMode(uint8 u8RegionNum,
                              Platform_Mpu_MasterType eMaster,
                              Platform_Mpu_SupervisorAccessModeType eSupervisorMode,
                              Platform_Mpu_UserAccessModeType eUserMode
                             );

/*
 * @brief         Retrieve error details
 * @details       This function is Reentrant
 * @param[out]    pErrorDetails : Storage where the data will be saved
 * @return        boolean - TRUE if an error was present, FALSE otherwise
 * @pre           None
 */
boolean Platform_Ipw_Mpu_GetErrorDetails(Platform_Mpu_ErrorDetailsType * pErrorDetails);

#endif /* #if (STD_ON == PLATFORM_ENABLE_MPU) */

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"


#endif /* PLATFORM_IPW_H_ */
