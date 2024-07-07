
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Flexio
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors
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
*   @file       Ftm_Pwm_Ip_PBcfg.c
*
*   @addtogroup ftm_pwm_ip Ftm Pwm IPL
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
#include "Ftm_Pwm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FTM_PWM_IP_PB_CFG_VENDOR_ID_C                       43
#define FTM_PWM_IP_PB_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define FTM_PWM_IP_PB_CFG_AR_RELEASE_MINOR_VERSION_C        7
#define FTM_PWM_IP_PB_CFG_AR_RELEASE_REVISION_VERSION_C     0
#define FTM_PWM_IP_PB_CFG_SW_MAJOR_VERSION_C                2
#define FTM_PWM_IP_PB_CFG_SW_MINOR_VERSION_C                0
#define FTM_PWM_IP_PB_CFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and Ftm_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (FTM_PWM_IP_PB_CFG_VENDOR_ID_C != FTM_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_PBcfg.c and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_PB_CFG_AR_RELEASE_MAJOR_VERSION_C    != FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_PB_CFG_AR_RELEASE_MINOR_VERSION_C    != FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_PB_CFG_AR_RELEASE_REVISION_VERSION_C != FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_PBcfg.c and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((FTM_PWM_IP_PB_CFG_SW_MAJOR_VERSION_C != FTM_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_PB_CFG_SW_MINOR_VERSION_C != FTM_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_PB_CFG_SW_PATCH_VERSION_C != FTM_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_PBcfg.c and Ftm_Pwm_Ip_Cfg.h are different."
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#ifndef FTM_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"


/*================================================================================================*/

/* Ftm instance 0 synchronization initialization configuration */
const Ftm_Pwm_Ip_SyncCfgType Ftm_Pwm_Ip_SyncCfg0 =
{
    /* SyncMode */                   FTM_PWM_IP_SYNC_SWTRIGGER,
    /* HwSync0 */                    (boolean)FALSE,
    /* HwSync1 */                    (boolean)FALSE,
    /* HwSync2 */                    (boolean)FALSE,
    /* HwTriggerAutoClear */         (boolean)FALSE,
    /* MaxLoadPoint */               (boolean)FALSE,
    /* MinLoadPoint */               (boolean)FALSE,
#if (defined(FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD) && (FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD == STD_ON))
    /* HalfCycleLoadPoint */         (boolean)FALSE,
    /* HalfCycleLoadPointValue */    0U,
#endif
#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
    /* LoadPointFreq */              0U,
#endif
    /* InverterSync */               FTM_PWM_IP_SYNC_DISABLED,
    /* OutRegSync */                 FTM_PWM_IP_SYNC_DISABLED,
    /* OutMaskSync */                FTM_PWM_IP_SYNC_DISABLED,
    /* InitCounterSync */            FTM_PWM_IP_SYNC_ON_TRIGGER,
    /* CounterSync */                FTM_PWM_IP_SYNC_ON_TRIGGER
};


/* Ftm instance 0 initialization configuration */
const Ftm_Pwm_Ip_InstanceCfgType Ftm_Pwm_Ip_InstCfg0 =
{
    /* ClkSrc */                FTM_PWM_IP_CLOCK_SOURCE_SYSTEMCLK,
    /* ClkPs */                 FTM_PWM_IP_CLOCK_DIV_128,
    /* AlternateclkPs */        FTM_PWM_IP_CLOCK_DIV_1,
    /* CntMode */               FTM_PWM_IP_EDGE_ALIGNED,
    /* OverflowIrqEn */         (boolean)FALSE,
    /* OverflowCb */            {
        /* FunctionCallback */      NULL_PTR,
        /* CbParam */               NULL_PTR
                                },
#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
    /* ReloadIrqEn */           (boolean)FALSE,
    /* ReloadCb */              {
        /* FunctionCallback */      NULL_PTR,
        /* CbParam */               NULL_PTR
                                },
#endif
    /* DebugMode */             FTM_PWM_IP_BDM_MODE_00,
    /* WriteProtection */       (boolean)FALSE,
    /* InitTriggerEn */         (boolean)FALSE,
    /* InitTrigMode */          FTM_PWM_IP_INIT_TRIGG_RELOAD_POINT,
    /* PwmPeriod */             37500U,
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    /* PwmPeriodDither */       0U,
#endif
    /* DeadTimeValue */         0U,
    /* DeadTimePs */            FTM_PWM_IP_DEADTIME_DIV_1,
#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    /* FaultCtrMode */          FTM_PWM_IP_FAULT_DISABLED,
    /* FaultOutState */         FTM_PWM_IP_OUT_SAFE_VALUE,
    /* FaultInFilter */         0U,
    /* FaultIrqEn */            (boolean)FALSE,
#endif
    /* SyncCfg */               &Ftm_Pwm_Ip_SyncCfg0
};


/* Ftm instance 0 paired channels initialization configuration */



/* Ftm instance 0 channels initialization configuration */

/* Ftm channel 2 configuration */
const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_I0_Ch2 =
{
    /* ChannelId */             2U,
    /* ChannelMode */           FTM_PWM_IP_MODE_EDGE_ALIGNED_HIGH,
    /* ChIrqEn */               (boolean)FALSE,
    /* ChannelCb */             {
        /* FunctionCallback */       NULL_PTR,
        /* CbParam */                NULL_PTR
                                },
    /* ChOutputEn */            (boolean)TRUE,
    /* SwControlEn */           (boolean)FALSE,
    /* SwControlVal */          (boolean)FALSE,
    /* ExtTrigEn */             (boolean)FALSE,
#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))    
    /* ChMatchLoadEn */         (boolean)FALSE,
#endif
    /* DutyCycle */             0U,
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    /* DutyCycleDither */       0U,
#endif
    /* InitOut */               FTM_PWM_IP_OUTPUT_STATE_LOW,
    /* Polarity */              FTM_PWM_IP_POLARITY_HIGH,
    /* PairCfg */               NULL_PTR
};

/* Ftm channel 0 configuration */
const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_I0_Ch0 =
{
    /* ChannelId */             0U,
    /* ChannelMode */           FTM_PWM_IP_MODE_EDGE_ALIGNED_HIGH,
    /* ChIrqEn */               (boolean)FALSE,
    /* ChannelCb */             {
        /* FunctionCallback */       NULL_PTR,
        /* CbParam */                NULL_PTR
                                },
    /* ChOutputEn */            (boolean)TRUE,
    /* SwControlEn */           (boolean)FALSE,
    /* SwControlVal */          (boolean)FALSE,
    /* ExtTrigEn */             (boolean)FALSE,
#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))    
    /* ChMatchLoadEn */         (boolean)FALSE,
#endif
    /* DutyCycle */             0U,
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    /* DutyCycleDither */       0U,
#endif
    /* InitOut */               FTM_PWM_IP_OUTPUT_STATE_LOW,
    /* Polarity */              FTM_PWM_IP_POLARITY_HIGH,
    /* PairCfg */               NULL_PTR
};

/* Ftm channel 1 configuration */
const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_I0_Ch1 =
{
    /* ChannelId */             1U,
    /* ChannelMode */           FTM_PWM_IP_MODE_EDGE_ALIGNED_HIGH,
    /* ChIrqEn */               (boolean)FALSE,
    /* ChannelCb */             {
        /* FunctionCallback */       NULL_PTR,
        /* CbParam */                NULL_PTR
                                },
    /* ChOutputEn */            (boolean)TRUE,
    /* SwControlEn */           (boolean)FALSE,
    /* SwControlVal */          (boolean)FALSE,
    /* ExtTrigEn */             (boolean)FALSE,
#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))    
    /* ChMatchLoadEn */         (boolean)FALSE,
#endif
    /* DutyCycle */             0U,
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    /* DutyCycleDither */       0U,
#endif
    /* InitOut */               FTM_PWM_IP_OUTPUT_STATE_LOW,
    /* Polarity */              FTM_PWM_IP_POLARITY_HIGH,
    /* PairCfg */               NULL_PTR
};



/* Ftm channels configuration array */
const Ftm_Pwm_Ip_ChannelConfigType * const Ftm_Pwm_Ip_I0_ChArray[3U] =
{
    &Ftm_Pwm_Ip_I0_Ch2,
    &Ftm_Pwm_Ip_I0_Ch0,
    &Ftm_Pwm_Ip_I0_Ch1
};

/* Ftm instance 0 User configuration structure */
const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip_UserCfg0 =
{
    /* InstanceCfg */           &Ftm_Pwm_Ip_InstCfg0,
    /* ConfiguredChArray */     Ftm_Pwm_Ip_I0_ChArray,
    /* NoOfConfiguredCh */      3U
#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    ,

    /* ConfiguredFaultArray */  NULL_PTR,
    /* NoOfFaultCfg */          0U
#endif 
};


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* FTM_PWM_IP_PRECOMPILE_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

