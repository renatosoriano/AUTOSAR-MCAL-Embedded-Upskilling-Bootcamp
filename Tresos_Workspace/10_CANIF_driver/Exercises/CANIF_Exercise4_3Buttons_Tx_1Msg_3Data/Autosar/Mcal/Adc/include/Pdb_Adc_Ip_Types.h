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

#ifndef PDB_ADC_IP_TYPES_H
#define PDB_ADC_IP_TYPES_H

/**
*   @file
*
*   @addtogroup pdb_adc_ip Pdb Adc IPL
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
#include "StandardTypes.h"
#include "Pdb_Adc_Ip_CfgDefines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PDB_ADC_IP_VENDOR_ID_TYPES                      43
#define PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES       4
#define PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES       7
#define PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_TYPES    0
#define PDB_ADC_IP_SW_MAJOR_VERSION_TYPES               2
#define PDB_ADC_IP_SW_MINOR_VERSION_TYPES               0
#define PDB_ADC_IP_SW_PATCH_VERSION_TYPES               0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if Pdb_Adc_Ip_Types.h file and Pdb_Adc_Ip_CfgDefines.h file are of the same vendor */
#if (PDB_ADC_IP_VENDOR_ID_TYPES != PDB_ADC_IP_VENDOR_ID_CFGDEFINES)
    #error "Pdb_Adc_Ip_Types.h and Pdb_Adc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Pdb_Adc_Ip_Types.h file and Pdb_Adc_Ip_CfgDefines.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_TYPES != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip_Types.h and Pdb_Adc_Ip_CfgDefines.h are different"
#endif

/* Check if Pdb_Adc_Ip_Types.h file and Pdb_Adc_Ip_CfgDefines.h file are of the same Software version */
#if ((PDB_ADC_IP_SW_MAJOR_VERSION_TYPES != PDB_ADC_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_SW_MINOR_VERSION_TYPES != PDB_ADC_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (PDB_ADC_IP_SW_PATCH_VERSION_TYPES != PDB_ADC_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Pdb_Adc_Ip_Types.h and Pdb_Adc_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Pdb_Adc_Ip_Types.h file and StandardTypes.h file are of the same Autosar version */
#if ((PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_TYPES != STD_AR_RELEASE_MAJOR_VERSION) || \
     (PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_TYPES != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Pdb_Adc_Ip_Types.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief Defines the type of value load mode for the PDB module.
 *
 * Some timing related registers, such as the MOD, IDLY, CHnDLYm, INTx and POyDLY,
 * buffer the setting values. Only the load operation is triggered.
 * The setting value is loaded from a buffer and takes effect. There are
 * four loading modes to fit different applications.
 * Implements : Pdb_Adc_Ip_LoadValueModeType_Class
 */
typedef enum
{
    PDB_ADC_IP_LOAD_VAL_IMMEDIATELY                        = 0U, /*!< Loaded immediately after load operation. */
    PDB_ADC_IP_LOAD_VAL_AT_MODULO_COUNTER                  = 1U, /*!< Loaded when counter hits the modulo after load operation. */
    PDB_ADC_IP_LOAD_VAL_AT_NEXT_TRIGGER                    = 2U, /*!< Loaded when detecting an input trigger after load operation. */
    PDB_ADC_IP_LOAD_VAL_AT_MODULO_COUNTER_OR_NEXT_TRIGGER  = 3U  /*!< Loaded when counter hits the modulo or detecting an input trigger after load operation. */
} Pdb_Adc_Ip_LoadValueModeType;

/*!
 * @brief Defines the type of prescaler divider for the PDB counter clock.
 * Implements : Pdb_Adc_Ip_ClkPrescalerDivType_Class
 */
typedef enum
{
    PDB_ADC_IP_CLK_PREDIV_BY_1   = 0U, /*!< Counting divided by 1 x prescaler multiplication factor (selected by MULT). */
    PDB_ADC_IP_CLK_PREDIV_BY_2   = 1U, /*!< Counting divided by 2 x prescaler multiplication factor (selected by MULT). */
    PDB_ADC_IP_CLK_PREDIV_BY_4   = 2U, /*!< Counting divided by 4 x prescaler multiplication factor (selected by MULT). */
    PDB_ADC_IP_CLK_PREDIV_BY_8   = 3U, /*!< Counting divided by 8 x prescaler multiplication factor (selected by MULT). */
    PDB_ADC_IP_CLK_PREDIV_BY_16  = 4U, /*!< Counting divided by 16 x prescaler multiplication factor (selected by MULT). */
    PDB_ADC_IP_CLK_PREDIV_BY_32  = 5U, /*!< Counting divided by 32 x prescaler multiplication factor (selected by MULT). */
    PDB_ADC_IP_CLK_PREDIV_BY_64  = 6U, /*!< Counting divided by 64 x prescaler multiplication factor (selected by MULT). */
    PDB_ADC_IP_CLK_PREDIV_BY_128 = 7U  /*!< Counting divided by 128 x prescaler multiplication factor (selected by MULT). */
} Pdb_Adc_Ip_ClkPrescalerDivType;

/*!
 * @brief Defines the type of the multiplication source mode for PDB.
 *
 * Selects the multiplication factor of the prescaler divider for the PDB counter clock.
 * Implements : Pdb_Adc_Ip_ClkPrescalerMultFactType_Class
 */
typedef enum
{
    PDB_ADC_IP_CLK_PREMULT_FACT_AS_1  = 0U, /*!< Multiplication factor is 1. */
    PDB_ADC_IP_CLK_PREMULT_FACT_AS_10 = 1U, /*!< Multiplication factor is 10. */
    PDB_ADC_IP_CLK_PREMULT_FACT_AS_20 = 2U, /*!< Multiplication factor is 20. */
    PDB_ADC_IP_CLK_PREMULT_FACT_AS_40 = 3U  /*!< Multiplication factor is 40. */
} Pdb_Adc_Ip_ClkPrescalerMultFactType;

/*!
 * @brief Defines the type of trigger source mode for the PDB.
 *
 * Selects the trigger input source for the PDB. The trigger input source can
 * be internal or the software trigger.
 * Implements : Pdb_Adc_Ip_TriggerSrcType_Class
 */
typedef enum
{
    PDB_ADC_IP_TRIGGER_IN0         = 0U,    /*!< Source trigger comes from TRGMUX. */
    PDB_ADC_IP_SOFTWARE_TRIGGER    = 15U    /*!< Select software trigger. */
} Pdb_Adc_Ip_TriggerSrcType;

/*!
 * @brief Defines the sequence error notification header
 *
 * This header is used for sequence error notification callbacks
 *
 * Implements : Pdb_Adc_Ip_SeqErrNotificationType_Class
 */
typedef void Pdb_Adc_Ip_SeqErrNotificationType(uint8 ChanIdx, uint16 SeqErrMask);

/*!
 * @brief Defines the type of structure for configuring an ADC pretrigger.
 * Implements : Pdb_Adc_Ip_PretriggerConfigType_Class
 */
typedef struct
{
    uint8 EnableMask;           /*!< Mask of enabled pretriggers. */
    uint8 EnableDelayMask;      /*!< Mask of pretriggers with delays enabled. */
    uint8 BackToBackEnableMask; /*!< Mask of pretriggers with back to back mode enabled.
                                    If enabled, the pretrigger will be activated automatically when the ADC COCO flag corresponding to the previous pretrigger in the chain, is set.
                                    The previous pretrigger for pretriggers with index 0, depend on features InstanceBackToBackEnable and InterChannelBackToBackEnable. */
} Pdb_Adc_Ip_PretriggersConfigType;

/*!
 * @brief Defines the type of structure for configuring a single PDB channel.
 * Implements : Pdb_Adc_Ip_ChanConfigType_Class
 */
typedef struct
{
    uint8 ChnIdx;                                       /*!< PDB channel index. */
    Pdb_Adc_Ip_PretriggersConfigType PretriggersConfig; /*!< Pretriggers configuration. */
    uint16 PretriggerDelays[PDB_DLY_COUNT];             /*!< Pretriggers delay array, positional dependent(delay for pretrigger 0 must be at index 0) */
} Pdb_Adc_Ip_ChanConfigType;

/*!
 * @brief Defines the type of structure for basic timer in PDB.
 *
 * Implements : Pdb_Adc_Ip_ConfigType_Class
 */
typedef struct
{
    Pdb_Adc_Ip_LoadValueModeType LoadValueMode;           /*!< Select the load mode. */
    Pdb_Adc_Ip_ClkPrescalerDivType PrescalerDiv;          /*!< Select the prescaler divider. */
    Pdb_Adc_Ip_ClkPrescalerMultFactType ClkPreMultFactor; /*!< Select multiplication factor for prescaler. */
    Pdb_Adc_Ip_TriggerSrcType TriggerSource;              /*!< Select the trigger input source. */
    boolean ContinuousModeEnable;                         /*!< Enable the continuous mode. */
    boolean DmaEnable;                                    /*!< Enable the dma for timer. */
    uint16 ModValue;                                      /*!< Modulus register value. */
#if  (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK)
    boolean InstanceBackToBackEnable;                     /*!< Enable the instance back to back mode between PDB0 CH0 and PDB1 CH0 pretriggers, forming a ring (PDB0_CH0_pretrigger7 -> PDB1_CH0_pretrigger0 and PDB1_CH0_pretrigger7 -> PDB0_CH0_pretrigger0).
                                                            Note: this configuration is common between all PDB instances (configures the same register SIM_CHIPCTL[PDB_BB_SEL] even if configured for either PDB instance)
                                                            Enabling when configuring PDB0, then disabling when configuring PDB1, will result in being disabled.
                                                            Note: must not be enabled simultaneously with inter-channel back to back on any PDB instance. */
#endif /* (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK) */
#if  (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK)
    boolean InterChannelBackToBackEnable;   /*!< Enable the inter-channel back to back mode between PDBx CH0 and PDBx CH1 pretriggers, forming a ring (PDBx_CH0_pretrigger7 -> PDBx_CH1_pretrigger0 and PDBx_CH1_pretrigger7 -> PDBx_CH0_pretrigger0).
                                                Note: this configuration is dedicated to each PDB instance.
                                                Note: must not be enabled simultaneously with instance back to back on any PDB instance. */
#endif /* (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK) */

    uint8 NumChans;                                         /*!< Number of PDB Channels */
    const Pdb_Adc_Ip_ChanConfigType * ChanConfigs;          /*!< PDB Channel configuration */

    Pdb_Adc_Ip_SeqErrNotificationType * SeqErrNotification; /*!< Sequence error notification. */
} Pdb_Adc_Ip_ConfigType;

/*!
 * @brief Structure used to store runtime info
 *
 * This structure is used to store PDB runtime info
 *
 * Implements : Pdb_Adc_Ip_StateStructType_Class
 */
typedef struct
{
    boolean Init;      /*!< Check if the driver was initialized. */

    /* Sequence error notification */
    Pdb_Adc_Ip_SeqErrNotificationType * SeqErrNotification; /*!< Sequence error notification */
} Pdb_Adc_Ip_StateStructType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PDB_ADC_IP_TYPES_H */
