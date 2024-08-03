/**   
*   @file    Spi_PBcfg.c
*   @implements Spi_PBcfg.c_Artifact
*   @version 2.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup SPI_DRIVER_CONFIGURATION Spi Driver Configuration
*   @{
*/
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
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Spi_Ipw_VS_0_PBcfg.h"

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VS_0_MODULE_ID_PBCFG_C                        83
#define SPI_VS_0_VENDOR_ID_PBCFG_C                        43
#define SPI_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define SPI_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C         7
#define SPI_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define SPI_VS_0_SW_MAJOR_VERSION_PBCFG_C                 2
#define SPI_VS_0_SW_MINOR_VERSION_PBCFG_C                 0
#define SPI_VS_0_SW_PATCH_VERSION_PBCFG_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_VS_0_VENDOR_ID_PBCFG_C != SPI_VENDOR_ID)
    #error "Spi_PBCfg.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_VS_0_SW_MAJOR_VERSION_PBCFG_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_VS_0_SW_MINOR_VERSION_PBCFG_C != SPI_SW_MINOR_VERSION) || \
     (SPI_VS_0_SW_PATCH_VERSION_PBCFG_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif

/* Check if current file and SPI header file are of the same vendor */
#if (SPI_VS_0_VENDOR_ID_PBCFG_C != SPI_IPW_VENDOR_ID_VS_0_PBCFG_H)
    #error "Spi_PBCfg.c and Spi_Ipw_PBCfg.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_IPW_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_H) || \
     (SPI_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_IPW_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_H) || \
     (SPI_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_IPW_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_H ))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi_Ipw_PBCfg.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_VS_0_SW_MAJOR_VERSION_PBCFG_C != SPI_IPW_SW_MAJOR_VERSION_VS_0_PBCFG_H) || \
     (SPI_VS_0_SW_MINOR_VERSION_PBCFG_C != SPI_IPW_SW_MINOR_VERSION_VS_0_PBCFG_H) || \
     (SPI_VS_0_SW_PATCH_VERSION_PBCFG_C != SPI_IPW_SW_PATCH_VERSION_VS_0_PBCFG_H))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi_Ipw_PBCfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/* Check if current file and Dem.h file are of the same Autosar version */
#if ((SPI_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Dem.h are different"
#endif
#endif
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/* List Of Notification Functions */
/* Job start Notifications */

/* Job End Notifications */

/* Sequence End Notifications */


#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)))
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) ||
        (SPI_LEVEL_DELIVERED == SPI_LEVEL2))) */
#include "Spi_MemMap.h"

/* Buffers Descriptors for EB Channels and Allocate Buffers for IB Channels */
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_BufferDescriptorType Spi_Buffer_VS_0_SpiChannel_Master, 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_BufferDescriptorType Spi_Buffer_VS_0_SpiChannel_Master, 4)
#endif
/* Allocate Buffers for IB Channels (if any) */
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_VS_0_SpiChannel_Slave[20], 8)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_VS_0_SpiChannel_Slave[20], 8)
#else
/** Compiler_Warning: It is intended for aligning memory. */
VAR_ALIGN(static Spi_DataBufferType Spi_BufferTX_VS_0_SpiChannel_Slave[20], 4)
VAR_ALIGN(static Spi_DataBufferType Spi_BufferRX_VS_0_SpiChannel_Slave[20], 4)
#endif


#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)))
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) ||
        (SPI_LEVEL_DELIVERED == SPI_LEVEL2))) */
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

/* Buffers Descriptors for IB Channels */
    /*  Buffers Descriptors for IB Channels (if any) */
static Spi_BufferDescriptorType Spi_Buffer_VS_0_SpiChannel_Slave =
{
    (const uint8*)NULL_PTR,
    Spi_BufferTX_VS_0_SpiChannel_Slave,  /* pBufferTX */
    Spi_BufferRX_VS_0_SpiChannel_Slave   /* pBufferRX */
};



#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/* Channel Configuration */
/* Channel Configuration of SpiChannel_Master*/
static const Spi_ChannelConfigType Spi_ChannelConfig_SpiChannel_Master_VS_0 =
{
        /* SpiChannel_Master*/
        EB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)1U, /* In the case SpiDefaultData is disabled. Set this value is 1U */
        100U, /* Length (configured in SpiEbMaxLength) */
        &Spi_Buffer_VS_0_SpiChannel_Master, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[0U] /* pChannelState pointer */
};
/* Channel Configuration of SpiChannel_Slave*/
static const Spi_ChannelConfigType Spi_ChannelConfig_SpiChannel_Slave_VS_0 =
{
        /* SpiChannel_Slave*/
        IB, /* BufferType IB or EB */
        16U, /* Frame size */
        
        (boolean)TRUE, /* Bite order */
        
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
        
        SPI_FULL_DUPLEX,
        
  #endif
#endif
        (uint32)1U, /* In the case SpiDefaultData is disabled. Set this value is 1U */
        20U, /* Length (configured in SpiIbNBuffers) */
        &Spi_Buffer_VS_0_SpiChannel_Slave, /* pcBufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,
        &Spi_axSpiChannelState[1U] /* pChannelState pointer */
};
/* Spi_apChannelConfigList_VS_0 Channel Configuration of Spi*/
static const Spi_ChannelsCfgType Spi_aChannelConfigList_VS_0[2] =
{
    {
    /* SpiChannel_Master */
    /* SpiChannel_Master */
    &Spi_ChannelConfig_SpiChannel_Master_VS_0
    },
    {
    /* SpiChannel_Slave */
    /* SpiChannel_Slave */
    &Spi_ChannelConfig_SpiChannel_Slave_VS_0
    }

};

/* Channel Assignment of Jobs */

/* Channel to Job Assignment */

static const Spi_ChannelType Spi_SpiJob_0_ChannelAssignment_VS_0[1] = {SpiConf_SpiChannel_SpiChannel_Master};
static const Spi_ChannelType Spi_SpiJob_1_ChannelAssignment_VS_0[1] = {SpiConf_SpiChannel_SpiChannel_Slave};

/* Configuration of Jobs */

/* Job Configuration of SpiJob_0*/
static const Spi_JobConfigType Spi_JobConfig_SpiJob_0_VS_0 =
{
        /* SpiJob_0 */
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_SpiJob_0_ChannelAssignment_VS_0, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[0], /* JobState instance */
        CSIB1, /* HWUnit index */
        /* External Device Settings */
        SPI_SpiExternalDevice_1, /* External Device */
                &Spi_aExternalDeviceConfigList_VS_0[SPI_SpiExternalDevice_1] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Job Configuration of SpiJob_1*/
static const Spi_JobConfigType Spi_JobConfig_SpiJob_1_VS_0 =
{
        /* SpiJob_1 */
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_SpiJob_1_ChannelAssignment_VS_0, /* List of Channels */
        
            NULL_PTR,
        
        
            NULL_PTR,
        
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,        &Spi_axSpiJobState[1], /* JobState instance */
        CSIB0, /* HWUnit index */
        /* External Device Settings */
        SPI_SpiExternalDevice_0, /* External Device */
                &Spi_aExternalDeviceConfigList_VS_0[SPI_SpiExternalDevice_0] /* pcExternalDeviceConfig - pointer to the external device configuration */        };
/* Spi_apJobConfigList_VS_0 Job Configuration of Spi*/
static const Spi_JobsCfgType Spi_aJobConfigList_VS_0[2] =
{
    {
    /* SpiJob_0 */
    /* SpiJob_0 */
    &Spi_JobConfig_SpiJob_0_VS_0
    },
    {
    /* SpiJob_1 */
    /* SpiJob_1 */
    &Spi_JobConfig_SpiJob_1_VS_0
    }

};


/* Job Assignment of Sequences  */
/* Job to Sequence Assignment */

static const Spi_JobType Spi_SpiSequence_Master_JobAssignment_VS_0[1] = {SpiConf_SpiJob_SpiJob_0};
static const Spi_JobType Spi_SpiSequence_Slave_JobAssignment_VS_0[1] = {SpiConf_SpiJob_SpiJob_1};
/* Configuration of Sequences */

/* Sequence Configuration of SpiSequence_Master_VS_0 */
static const Spi_SequenceConfigType Spi_SequenceConfig_SpiSequence_Master_VS_0 =
{
        /* SpiSequence_Master */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_SpiSequence_Master_JobAssignment_VS_0, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
        
};
/* Sequence Configuration of SpiSequence_Slave_VS_0 */
static const Spi_SequenceConfigType Spi_SequenceConfig_SpiSequence_Slave_VS_0 =
{
        /* SpiSequence_Slave */
        (Spi_JobType)1U,
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_SpiSequence_Slave_JobAssignment_VS_0, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE /* Interruptible */
                #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        
        
};
/* Spi_apSequenceConfigList_VS_0 Sequence Configuration of Spi*/
static const Spi_SeqsConfigType Spi_aSequenceConfigList_VS_0[2] =
{
    {
    /* SpiSequence_Master */
    /* SpiSequence_Master */
    &Spi_SequenceConfig_SpiSequence_Master_VS_0
    },
    {
    /* SpiSequence_Slave */
    /* SpiSequence_Slave */
    &Spi_SequenceConfig_SpiSequence_Slave_VS_0
    }
};

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/* Spi Configuration */


/** Compiler_Warning: In some cases, the partition configuration may not be used by the application. */
static const Spi_ConfigType Spi_Config=
{
    2U, /* u16MaxExternalDevice - number of external devices */
    1U, /* Spi_Max_Channel - number of channels */
    1U, /* Spi_Max_Job - number of jobs */
    1U, /* Spi_Max_Sequence - number of sequences */
    SPI_SPURIOUS_CORE_ID_U32, /* u32SpiCoreUse */
    Spi_aChannelConfigList_VS_0, /* pcChannelConfig */
    Spi_aJobConfigList_VS_0, /* pcJobConfig */
    Spi_aSequenceConfigList_VS_0, /* pcSequenceConfig */
    Spi_aExternalDeviceConfigList_VS_0, /* pcExternalDeviceConfig */
    Spi_aHwUnitConfigList_VS_0 /* pcHWUnitConfig */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            ,{ (uint32)STD_OFF, (uint32)0U}/* SPI_E_HARDWARE_ERROR parameters*/         
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */  
};




const Spi_ConfigType * const Spi_PBCfgVariantPredefined[SPI_MAX_PARTITIONS]=
{
    &Spi_Config
};





#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

