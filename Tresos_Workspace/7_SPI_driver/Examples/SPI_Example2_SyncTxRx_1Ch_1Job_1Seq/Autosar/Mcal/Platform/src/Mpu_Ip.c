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
*   @file Mpu_Ip.c
*
*   @addtogroup MPU_IP MPU IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Mpu_Ip.h"
#ifdef MPU_IP_DEV_ERROR_DETECT
#if (MPU_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MPU_IP_VENDOR_ID_C                      43
#define CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION_C       7
#define CDD_PLATFORM_MPU_IP_AR_RELEASE_REVISION_VERSION_C    0
#define CDD_PLATFORM_MPU_IP_SW_MAJOR_VERSION_C               2
#define CDD_PLATFORM_MPU_IP_SW_MINOR_VERSION_C               0
#define CDD_PLATFORM_MPU_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mpu_Ip.h */
#if (CDD_PLATFORM_MPU_IP_VENDOR_ID_C !=  CDD_PLATFORM_MPU_IP_VENDOR_ID)
    #error "Mpu_Ip.c and Mpu_Ip.h have different vendor ids"
#endif
#if (( CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION_C    !=  CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION_C    !=  CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_AR_RELEASE_REVISION_VERSION_C !=  CDD_PLATFORM_MPU_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip.c and Mpu_Ip.h are different"
#endif
#if (( CDD_PLATFORM_MPU_IP_SW_MAJOR_VERSION_C !=  CDD_PLATFORM_MPU_IP_SW_MAJOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_SW_MINOR_VERSION_C !=  CDD_PLATFORM_MPU_IP_SW_MINOR_VERSION) || \
     ( CDD_PLATFORM_MPU_IP_SW_PATCH_VERSION_C !=  CDD_PLATFORM_MPU_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip.c and Mpu_Ip.h are different"
#endif

#ifdef MPU_IP_DEV_ERROR_DETECT
#if (MPU_IP_DEV_ERROR_DETECT == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /*  Check if current file and Devassert.h are of the same version */
        #if ((CDD_PLATFORM_MPU_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
             (CDD_PLATFORM_MPU_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AUTOSAR Version Numbers of Mpu_Ip.c and Devassert.h are different"
        #endif
    #endif
#endif
#endif

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#ifdef PLATFORM_IP_ENABLE_MPU
#if (PLATFORM_IP_ENABLE_MPU == STD_ON)
    
#define PLATFORM_START_SEC_CONST_UNSPECIFIED
#include "Platform_MemMap.h"

static MPU_Type * const Mpu_Ip_pBase = IP_MPU;

#define PLATFORM_STOP_SEC_CONST_UNSPECIFIED
#include "Platform_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief         Initializes the MPU instance and memory regions configured
 */
void Mpu_Ip_Init_Privileged(const Mpu_Ip_ConfigType * pConfig);

/**
 * @brief         Configures the specified region number using the input region configuration
 */
void Mpu_Ip_SetRegionConfig_Privileged(uint8 regionNumber, const Mpu_Ip_RegionConfigType * const pUserConfigPtr);

/**
 * @brief         Deinitialize MPU instance
 */
void Mpu_Ip_Deinit_Privileged(void);

/**
 * @brief         Enable or disable region configuration
 */
void Mpu_Ip_EnableRegion_Privileged(uint8 u8RegionNum, boolean bEnable);

/**
 * @brief         Modify the access mode for a master to a specific region
 */
void Mpu_Ip_SetAccessMode_Privileged(uint8 u8RegionNum,
                                            Mpu_Ip_MasterType eMaster,
                                            Mpu_Ip_SupervisorAccessModeType eSupervisorMode,
                                            Mpu_Ip_UserAccessModeType eUserMode
                                           );

/**
 * @brief         Retrieves error details such as address and error type
 */
boolean Mpu_Ip_GetErrorDetails_Privileged(Mpu_Ip_ErrorDetailsType * pErrorDetails);

/**
 * @brief         Convert from value error master readed on the register to error enum
 */
static Mpu_Ip_MasterType Mpu_Ip_ConvertErrorMasterToEnum(uint32 errorMaster);

/**
 * @brief         Convert from value error attribute readed on the register to error enum
 */
static Mpu_Ip_ErrorAttributesType Mpu_Ip_ConvertErrorAttributeToEnum(uint32 errorAttribute);

/**
 * @brief         Convert from value error access readed on the register to error enum
 */
static Mpu_Ip_AccessType Mpu_Ip_ConvertErrorAccessToEnum(uint32 errorAccess);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief         Initializes the Memory Protection Unit general parameters and
 *                region configurations
 *
 * @details       This function is non-reentrant
 *
 * @param[in]     pConfig: pointer to configuration structure for MPU.
 * @return        void
 *
 * @pre           None
 *
 *
 **/
void Mpu_Ip_Init_Privileged(const Mpu_Ip_ConfigType * pConfig)
{
    uint8 regionIt;
    const Mpu_Ip_RegionConfigType * regionCfg;
    uint8 regionNumber;

#if (MPU_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(pConfig != NULL_PTR);
    DevAssert(pConfig->pRegionConfigArr != NULL_PTR);
    DevAssert(pConfig->u8RegionCnt > 0U);
    DevAssert(pConfig->u8RegionCnt <= MPU_RGD_COUNT);
#endif

    /*Reset all MPU configuration to default*/
    Mpu_Ip_Deinit_Privileged();

    for (regionIt = 0U; regionIt < pConfig->u8RegionCnt; regionIt++)
    {
        regionCfg = &pConfig->pRegionConfigArr[regionIt];
        regionNumber = pConfig->pRegionNumberArr[regionIt];
        Mpu_Ip_SetRegionConfig_Privileged(regionNumber, regionCfg);
    }
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
    /*Enable MPU*/
    Mpu_Ip_pBase->CESR |= ((uint32)MPU_CESR_VLD_MASK);
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

}

/**
 * @brief         Configures the region selected by u8RegionNum with the data from pUserConfigPtr
 *
 * @details       This function is Reentrant
 *
 * @param[in]     regionNumber: Region to be modified .
 * @param[in]     pUserConfigPtr: pointer to the region configuration structure for MPU.
 * @return        void
 *
 * @pre
 *
 **/
void Mpu_Ip_SetRegionConfig_Privileged(uint8 regionNumber, const Mpu_Ip_RegionConfigType * const pUserConfigPtr)
{

#if (MPU_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(regionNumber < MPU_RGD_COUNT);
    DevAssert(pUserConfigPtr != NULL_PTR);
#endif

    if (0U == regionNumber)
    {
        /*Region 0 only can setup permission for user mode and supervisor mode*/
        Mpu_Ip_pBase->RGDAAC[regionNumber] = pUserConfigPtr->u32Word2;
    }
    else
    {
        /*Set start address of the region*/
        Mpu_Ip_pBase->RGD[regionNumber].WORD0 = pUserConfigPtr->u32StartAddr;
        /*Set end address of the region*/
        Mpu_Ip_pBase->RGD[regionNumber].WORD1 = pUserConfigPtr->u32EndAddr;
        /*Set Word 2 value*/
        Mpu_Ip_pBase->RGD[regionNumber].WORD2 = pUserConfigPtr->u32Word2;
        /*Mark the region as valid*/
        Mpu_Ip_pBase->RGD[regionNumber].WORD3 = MPU_RGD_WORD3_PID(pUserConfigPtr->u32Pid) | MPU_RGD_WORD3_PIDMASK(pUserConfigPtr->u32PidMask) | MPU_RGD_WORD3_VLD(MPU_RGD_WORD3_VLD_MASK);
    }
}

/**
 * @brief         Disables the module and resets all region configurations
 *
 * @details       This function is Reentrant
 *
 * @return        Void
 *
 * @pre           None
 *
 **/
void Mpu_Ip_Deinit_Privileged(void)
{
    uint8 region;

    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
    SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_00();
    /*Disable MPU*/
    Mpu_Ip_pBase->CESR = (Mpu_Ip_pBase->CESR) & (~((uint32)MPU_CESR_VLD_MASK));
    SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_00();
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();

    /*Reset value for Region 0*/
    Mpu_Ip_pBase->RGDAAC[0] = 0x0061F7DFU;
    /*Reset value for Region 1 to (MPU_RGD_COUNT -1)*/
    for (region = 1U; region < MPU_RGD_COUNT; region++)
    {
        Mpu_Ip_pBase->RGD[region].WORD0 = 0x0U;
        Mpu_Ip_pBase->RGD[region].WORD1 = 0x0U;
        Mpu_Ip_pBase->RGD[region].WORD2 = 0x0U;
        Mpu_Ip_pBase->RGD[region].WORD3 = 0x0U;
        Mpu_Ip_pBase->RGDAAC[region]    = 0x0U;
    }
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
 * @pre           None
 *
 **/
void Mpu_Ip_EnableRegion_Privileged(uint8 u8RegionNum, boolean bEnable)
{

#if (MPU_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(u8RegionNum < MPU_RGD_COUNT);
#endif

    SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_01();
    if (TRUE == bEnable)
    {
        Mpu_Ip_pBase->RGD[u8RegionNum].WORD3 |= MPU_RGD_WORD3_VLD(MPU_RGD_WORD3_VLD_MASK);
    }
    else
    {
        Mpu_Ip_pBase->RGD[u8RegionNum].WORD3 &= ~MPU_RGD_WORD3_VLD(MPU_RGD_WORD3_VLD_MASK);
    }
    SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_01();
}

/**
 * @brief         Modify the access mode for a master to a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum     : Region to be modified
 * @param[in]     eMaster         : Master to be modified
 * @param[in]     eSupervisorMode : Specifies the new mode access in supervisor mode
 * @param[in]     eUserMode       : Specifies the new mode access in user mode
 * @return        void
 *
 * @pre           None
 *
 **/

void Mpu_Ip_SetAccessMode_Privileged(uint8 u8RegionNum,
                                            Mpu_Ip_MasterType eMaster,
                                            Mpu_Ip_SupervisorAccessModeType eSupervisorMode,
                                            Mpu_Ip_UserAccessModeType eUserMode
                                           )
{

#if (MPU_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check the input parameters */
    DevAssert(u8RegionNum < MPU_RGD_COUNT);
#endif

    SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_02();
    switch (eMaster)
    {
        case MPU_MASTER_CORE :
            /*Clear old configuration*/
            Mpu_Ip_pBase->RGDAAC[u8RegionNum] &=~((uint32)MPU_RGDAAC_M0SM_MASK | (uint32)MPU_RGDAAC_M0UM_MASK);
            /*Set new configuration*/
            Mpu_Ip_pBase->RGDAAC[u8RegionNum] |= (MPU_RGDAAC_M0SM(eSupervisorMode) | MPU_RGDAAC_M0UM(eUserMode));
            break;
        case MPU_MASTER_DEBUGGER :
            /*Clear old configuration*/
            Mpu_Ip_pBase->RGDAAC[u8RegionNum] &=~((uint32)MPU_RGDAAC_M1SM_MASK | (uint32)MPU_RGDAAC_M1UM_MASK);
            /*Set new configuration*/
            Mpu_Ip_pBase->RGDAAC[u8RegionNum] |= (MPU_RGDAAC_M1SM(eSupervisorMode) | MPU_RGDAAC_M1UM(eUserMode));
            break;
        case MPU_MASTER_DMA :
            /*Clear old configuration*/
            Mpu_Ip_pBase->RGDAAC[u8RegionNum] &=~((uint32)MPU_RGDAAC_M2SM_MASK | (uint32)MPU_RGDAAC_M2UM_MASK);
            /*Set new configuration*/
            Mpu_Ip_pBase->RGDAAC[u8RegionNum] |= (MPU_RGDAAC_M2SM(eSupervisorMode) | MPU_RGDAAC_M2UM(eUserMode));
            break;
        case MPU_MASTER_ENET :
            /*Clear old configuration*/
            Mpu_Ip_pBase->RGDAAC[u8RegionNum] &=~((uint32)MPU_RGDAAC_M3SM_MASK | (uint32)MPU_RGDAAC_M3UM_MASK);
            /*Set new configuration*/
            Mpu_Ip_pBase->RGDAAC[u8RegionNum] |= (MPU_RGDAAC_M3SM(eSupervisorMode) | MPU_RGDAAC_M3UM(eUserMode));
            break;
        default:
            /* Compiler_Warning: This default branch will never be reached*/
            break;
    }
    SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_02();
}

/**
 * @brief         Retrieve error details
 *
 * @details       This function is Reentrant
 *
 * @param[out]    pErrorDetails : Storage where the data will be saved
 * @return        boolean - TRUE if an error was present, FALSE otherwise
 *
 * @pre           None
 *
 **/
boolean Mpu_Ip_GetErrorDetails_Privileged(Mpu_Ip_ErrorDetailsType * pErrorDetails)
{
    boolean result;
    uint32  ErrorSlavePortNumber;
    uint32  errorEDR;
    uint32  RegCESR;
    uint32  errorMaster;
    uint32  errorAttribute;
    uint32  errorAccess;

#if (MPU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(pErrorDetails != NULL_PTR);
#endif

    SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_03();
    RegCESR = Mpu_Ip_pBase->CESR;
    if(0UL != (RegCESR & MPU_CESR_SPERR0_MASK))
    {
        ErrorSlavePortNumber = 0U;
        /*Clear Error*/
        Mpu_Ip_pBase->CESR = MPU_CESR_SPERR0_MASK | (RegCESR & MPU_CESR_VLD_MASK);
    }
    else if (0UL != (RegCESR & MPU_CESR_SPERR1_MASK))
    {
        ErrorSlavePortNumber = 1U;
        /*Clear Error*/
        Mpu_Ip_pBase->CESR = MPU_CESR_SPERR1_MASK | (RegCESR & MPU_CESR_VLD_MASK);
    }
#if ((MPU_EAR_EDR_COUNT == MPU_IP_EAR_EDR_COUNT_4) || (MPU_EAR_EDR_COUNT == MPU_IP_EAR_EDR_COUNT_5))
    else if (0UL != (RegCESR & MPU_CESR_SPERR2_MASK))
    {
        ErrorSlavePortNumber = 2U;
        /*Clear Error*/
        Mpu_Ip_pBase->CESR = MPU_CESR_SPERR2_MASK | (RegCESR & MPU_CESR_VLD_MASK);
    }
    else if (0UL != (RegCESR & MPU_CESR_SPERR3_MASK))
    {
        ErrorSlavePortNumber = 3U;
        /*Clear Error*/
        Mpu_Ip_pBase->CESR = MPU_CESR_SPERR3_MASK | (RegCESR & MPU_CESR_VLD_MASK);
    }
#endif
#if (MPU_EAR_EDR_COUNT == MPU_IP_EAR_EDR_COUNT_5)
    else if (0UL != (RegCESR & MPU_CESR_SPERR4_MASK))
    {
        ErrorSlavePortNumber = 4U;
        Mpu_Ip_pBase->CESR = MPU_CESR_SPERR4_MASK | (RegCESR & MPU_CESR_VLD_MASK);
    }
#endif
    else
    {
        ErrorSlavePortNumber = 0xFFU;
    }
    SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_03();

    if (0xFFU != ErrorSlavePortNumber)
    {
        errorEDR = Mpu_Ip_pBase->EAR_EDR[ErrorSlavePortNumber].EDR;

        /*Store Error Address*/
        pErrorDetails->u32Address       = Mpu_Ip_pBase->EAR_EDR[ErrorSlavePortNumber].EAR;

        /*Store Error information*/
        pErrorDetails->u16EACD          = (uint16)(((Mpu_Ip_pBase->EAR_EDR[ErrorSlavePortNumber].EDR) & MPU_EDR_EACD_MASK) >> MPU_EDR_EACD_SHIFT);
        errorMaster                     = ((errorEDR & MPU_EDR_EMN_MASK) >> MPU_EDR_EMN_SHIFT);
        pErrorDetails->eMaster          = Mpu_Ip_ConvertErrorMasterToEnum(errorMaster);
        errorAttribute                  = ((errorEDR & MPU_EDR_EATTR_MASK) >> MPU_EDR_EATTR_SHIFT);
        pErrorDetails->eErrorAttribute  = Mpu_Ip_ConvertErrorAttributeToEnum(errorAttribute);
        errorAccess                     = ((errorEDR & MPU_EDR_ERW_MASK) >> MPU_EDR_ERW_SHIFT);
        pErrorDetails->eErrorAccess     = Mpu_Ip_ConvertErrorAccessToEnum(errorAccess);

        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    return result;
}

/**
 * @brief         Convert from value error master readed on the register to enum error
 *
 * @details       This function is Reentrant
 *
 * @param[in]     errorMaster      : Value master error readed from register
 * @return        Mpu_Ip_MasterType
 *
 * @pre           None
 *
 **/
static Mpu_Ip_MasterType Mpu_Ip_ConvertErrorMasterToEnum(uint32 errorMaster)
{
    Mpu_Ip_MasterType eErrorMaster = MPU_MASTER_UNKNOWN;

    switch(errorMaster)
    {
        case 0U :
            eErrorMaster          = MPU_MASTER_CORE;
            break;
        case 1U :
            eErrorMaster          = MPU_MASTER_DEBUGGER;
            break;
        case 2U :
            eErrorMaster          = MPU_MASTER_DMA;
            break;
        case 3U :
            eErrorMaster          = MPU_MASTER_ENET;
            break;
        default:
            /* Compiler_Warning: This default branch will never be reached*/
            break;
    }

    return eErrorMaster;
}

/**
 * @brief         Convert from value error Attribute readed on the register to enum error
 *
 * @details       This function is Reentrant
 *
 * @param[in]     errorAttribute      : Value Attribute error readed from register
 * @return        Mpu_Ip_ErrorAttributesType
 *
 * @pre           None
 *
 **/
static Mpu_Ip_ErrorAttributesType Mpu_Ip_ConvertErrorAttributeToEnum(uint32 errorAttribute)
{
    Mpu_Ip_ErrorAttributesType eErrorAttribute = MPU_ERROR_UNKNOWN;

    switch (errorAttribute)
    {
        case 0U :
            eErrorAttribute      = MPU_USER_MODE_INSTRUCTION_ACCESS;
            break;
        case 1U :
            eErrorAttribute      = MPU_USER_MODE_DATA_ACCESS;
            break;
        case 2U :
            eErrorAttribute      = MPU_SUPERVISOR_MODE_INSTRUCTION_ACCESS;
            break;
        case 3U :
            eErrorAttribute      = MPU_SUPERVISOR_MODE_DATA_ACCESS;
            break;
        default:
            /* Compiler_Warning: This default branch will never be reached*/
            break;
    }

    return eErrorAttribute;
}

/**
 * @brief         Convert from value error Access readed on the register to enum error
 *
 * @details       This function is Reentrant
 *
 * @param[in]     errorAccess      : Value Access error readed from register
 * @return        Mpu_Ip_AccessType
 *
 * @pre           None
 *
 **/
static Mpu_Ip_AccessType Mpu_Ip_ConvertErrorAccessToEnum(uint32 errorAccess)
{
    Mpu_Ip_AccessType eErrorAccess = MPU_ACCESS_READ;

    switch (errorAccess)
    {
        case 0U :
            eErrorAccess      = MPU_ACCESS_READ;
            break;
        case 1U :
            eErrorAccess      = MPU_ACCESS_WRITE;
            break;
        default:
            /* Compiler_Warning: This default branch will never be reached*/
            break;
    }

    return eErrorAccess;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief         Initializes the MPU instance and memory regions configured
 */
/* @implements    Mpu_Ip_Init_Activity */
void Mpu_Ip_Init(const Mpu_Ip_ConfigType * pConfig)
{
#ifdef MPU_IP_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call1param(Mpu_Ip_Init_Privileged, pConfig);
#else
    Mpu_Ip_Init_Privileged(pConfig);
#endif
}

/**
 * @brief         Configures the specified region number using the input region configuration
 */
/* @implements    Mpu_Ip_SetRegionConfig_Activity */
void Mpu_Ip_SetRegionConfig(uint8 u8RegionNum, const Mpu_Ip_RegionConfigType * const pUserConfigPtr)
{
#ifdef MPU_IP_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call2params(Mpu_Ip_SetRegionConfig_Privileged, u8RegionNum, pUserConfigPtr);
#else
    Mpu_Ip_SetRegionConfig_Privileged(u8RegionNum,pUserConfigPtr);
#endif
}

/**
 * @brief         Deinitialize MPU instance
 */
/* @implements    Mpu_Ip_Deinit_Activity */
void Mpu_Ip_Deinit(void)
{
#ifdef MPU_IP_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call(Mpu_Ip_Deinit_Privileged);
#else
    Mpu_Ip_Deinit_Privileged();
#endif
}

/**
 * @brief         Enable or disable region configuration
 */
/* @implements    Mpu_Ip_EnableRegion_Activity */
void Mpu_Ip_EnableRegion(uint8 u8RegionNum, boolean bEnable)
{
#ifdef MPU_IP_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call2params(Mpu_Ip_EnableRegion_Privileged, u8RegionNum, bEnable);
#else
    Mpu_Ip_EnableRegion_Privileged(u8RegionNum, bEnable);
#endif
}

/**
 * @brief         Modify the User access mode for a master to a specific region
 */
/* @implements    Mpu_Ip_SetAccessMode_Activity */
void Mpu_Ip_SetAccessMode(uint8 u8RegionNum,
                          Mpu_Ip_MasterType eMaster,
                          Mpu_Ip_SupervisorAccessModeType eSupervisorMode,
                          Mpu_Ip_UserAccessModeType eUserMode
                         )
{
#ifdef MPU_IP_ENABLE_USER_MODE_SUPPORT
    OsIf_Trusted_Call4params(Mpu_Ip_SetAccessMode_Privileged, u8RegionNum, eMaster, eSupervisorMode, eUserMode);
#else
    Mpu_Ip_SetAccessMode_Privileged(u8RegionNum, eMaster, eSupervisorMode, eUserMode);
#endif
}

/**
 * @brief         Retrieves error details such as address and error type
 */
/* @implements    Mpu_Ip_GetErrorDetails_Activity */
boolean Mpu_Ip_GetErrorDetails(Mpu_Ip_ErrorDetailsType * pErrorDetails)
{
#ifdef MPU_IP_ENABLE_USER_MODE_SUPPORT
    return OsIf_Trusted_Call_Return1param(Mpu_Ip_GetErrorDetails_Privileged, pErrorDetails);
#else
    return Mpu_Ip_GetErrorDetails_Privileged(pErrorDetails);
#endif
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#endif /* PLATFORM_IP_ENABLE_MPU == STD_ON */
#endif /* PLATFORM_IP_ENABLE_MPU */

#ifdef __cplusplus
}
#endif

/** @} */
