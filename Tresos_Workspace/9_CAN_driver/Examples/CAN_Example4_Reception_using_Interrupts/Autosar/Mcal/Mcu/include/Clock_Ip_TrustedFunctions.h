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

#ifndef CLOCK_IP_TRUSTEDFUNCTIONS_H
#define CLOCK_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Clock_Ip_TrustedFunctions.h
*   @version    2.0.0
*
*   @brief   CLOCK IP type header file.
*   @details CLOCK IP type header file.

*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#if defined(__cplusplus)
extern "C"{
#endif
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Clock_Ip_Types.h"
#include "Clock_Ip_Specific.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                2
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_TrustedFunctions.h file and StandardTypes.h file are of the same Autosar version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and StandardTypes.h are different"
#endif
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Types.h file have same versions */
#if (CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != CLOCK_IP_TYPES_VENDOR_ID)
    #error "Clock_Ip_TrustedFunctions.h and Clock_Ip_Types.h have different vendor IDs"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Types.h file are of the same Autosar version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CLOCK_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Types.h are different"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Types.h file are of the same Software version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CLOCK_IP_TYPES_SW_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CLOCK_IP_TYPES_SW_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CLOCK_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Types.h are different"
#endif


/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific.h file have same versions */
#if (CLOCK_IP_TRUSTEDFUNCTIONS_VENDOR_ID  != CLOCK_IP_SPECIFIC_VENDOR_ID)
    #error "Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific.h have different vendor IDs"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific.h file are of the same Autosar version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific.h are different"
#endif

/* Check if Clock_Ip_TrustedFunctions.h file and Clock_Ip_Specific.h file are of the same Software version */
#if ((CLOCK_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CLOCK_IP_SPECIFIC_SW_MINOR_VERSION) || \
     (CLOCK_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CLOCK_IP_SPECIFIC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_TrustedFunctions.h and Clock_Ip_Specific.h are different"
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef CLOCK_IP_SCG_ASYNC_DIV1
/**
 * @brief        Write Config to SCG_SIRCDIV1 register
 *
 * @param        Config - pointer to configuration of SIRC divider 1
 * @return       None
 *
 */
extern void Clock_Ip_SetScgAsyncDiv1_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_ASYNC_DIV2
/**
 * @brief        Write Config to SCG_SIRCDIV2 register
 *
 * @param        Config - pointer to configuration of SIRC divider 2
 * @return       None
 *
 */
extern void Clock_Ip_SetScgAsyncDiv2_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_RUN
/**
 * @brief        Write Config to SCG_RCCR register
 *
 * @param        Config - pointer to configuration of DIVCORE value in run mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgRunDivcore_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_RUN
/**
 * @brief        Write Config to SCG_RCCR register
 *
 * @param        Config - pointer to configuration of DIVBUS value in run mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgRunDivbus_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_RUN
/**
 * @brief        Write Config to SCG_RCCR register
 *
 * @param        Config - pointer to configuration of DIVSLOW value in run mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgRunDivslow_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_VLPR
/**
 * @brief        Write Config to SCG_VCCR register
 *
 * @param        Config - pointer to configuration of DIVCORE value in VLPR mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgVlprDivcore_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_VLPR
/**
 * @brief        Write Config to SCG_VCCR register
 *
 * @param        Config - pointer to configuration of DIVBUS value in VLPR mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgVlprDivbus_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_VLPR
/**
 * @brief        Write Config to SCG_VCCR register
 *
 * @param        Config - pointer to configuration of DIVSLOW value in VLPR mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgVlprDivslow_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif


#ifdef CLOCK_IP_SCG_DIVCORE_HSRUN
/**
 * @brief        Write Config to SCG_HCCR register
 *
 * @param        Config - pointer to configuration of DIVCORE value in HSRUN mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgHsrunDivcore_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_HSRUN
/**
 * @brief        Write Config to SCG_HCCR register
 *
 * @param        Config - pointer to configuration of DIVBUS value in HSRUN mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgHsrunDivbus_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_HSRUN
/**
 * @brief        Write Config to SCG_HCCR register
 *
 * @param        Config - pointer to configuration of DIVSLOW value in HSRUN mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgHsrunDivslow_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_DIV
/**
 * @brief        Write Config to IP_SIM::CHIPCTL register
 *
 * @param        Config - pointer to configuration of divider value of CLKOUT0_CLK
 * @return       None
 *
 */
extern void Clock_Ip_SetSimClkoutDiv_TrustedCall(Clock_Ip_DividerConfigType const *Config);
#endif

#ifdef CLOCK_IP_PCC_PCD_FRAC
/**
 * @brief        Write Config to PCC register
 *
 * @param        Config - pointer to configuration of divider value PCC pheripheral clock
 * @return       None
 *
 */
extern void Clock_Ip_SetPccPcdDivFrac_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_TRACE_DIV_MUL
/**
 * @brief        Write Config to IP_SIM::CLKDIV4 register
 *
 * @param        Config - pointer to configuration of divider value TRACE_CLK
 * @return       None
 *
 */
extern void Clock_Ip_SetSimTraceDivMul_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SOSC_ENABLE
/**
 * @brief        Reset IP_SCG::SOSCCSR register
 *
 * @param        Config  - can be NULL_PTR
 * @return       None
 *
 */
extern void Clock_Ip_ResetSOSC_TrustedCall(Clock_Ip_XoscConfigType const* Config);

/**
 * @brief        Write Config of SOSC to register
 *
 * @param        Config - pointer to configuration of SOSC
 * @return       None
 *
 */
extern void Clock_Ip_SetSOSC_TrustedCall(Clock_Ip_XoscConfigType const* Config);

/**
 * @brief        Disabele SOSC
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_DisableSOSC_TrustedCall(Clock_Ip_NameType XoscName);

/**
 * @brief        Enable SOSC
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_EnableSOSC_TrustedCall(Clock_Ip_XoscConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_LPO1K_ENABLE
/**
 * @brief        Set gate of LPO1K_CLK
 *
 * @param        Config- pointer to confguration of LPO1K_CLK
 * @return       None
 *
 */
extern void Clock_Ip_ClockSetSimLPO1KEnable_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_LPO32K_ENABLE
/**
 * @brief        Set gate of LPO3K_CLK
 *
 * @param        Config- pointer to confguration of LPO3K_CLK
 * @return       None
 *
 */
extern void Clock_Ip_ClockSetSimLPO32KEnable_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif


#ifdef CLOCK_IP_SIM_CLKOUT_ENABLE
/**
 * @brief        Set gate of CLKOUT_CLK
 *
 * @param        Config- pointer to confguration of CLKOUT_CLK
 * @return       None
 *
 */
extern void Clock_Ip_ClockSetSimClkoutEnable_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif


#ifdef CLOCK_IP_PCC_CGC_ENABLE
/**
 * @brief        Set gate of PCC peripheral
 *
 * @param        Config- pointer to confguration of PCC pheripheral clock
 * @return       None
 *
 */
extern void Clock_Ip_ClockSetPccCgcEnable_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_PLATCGC_CGC
/**
 * @brief        Set gate of CLOCK_IP_SIM_PLATCGC_CGC clock
 *
 * @param        Config- pointer to confguration of CLOCK_IP_SIM_PLATCGC_CGC clock
 * @return       None
 *
 */
extern void Clock_Ip_ClockSetSimGate_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_TRACE_ENABLE
/**
 * @brief        Set gate of TRACE_CLK
 *
 * @param        Config- pointer to confguration of TRACE_CLK
 * @return       None
 *
 */
extern void Clock_Ip_ClockSetSimTraceEnable_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIRC_ENABLE
/**
 * @brief        Write Config to SIRC register
 *
 * @param        Config- pointer to confguration of SIRC
 * @return       None
 *
 */
extern void Clock_Ip_SetSirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);

/**
 * @brief        Enable SIRC
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_EnableSirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);

/**
 * @brief        Disable SIRC
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_DisableSirc_TrustedCall(Clock_Ip_NameType Name);
#endif

#ifdef CLOCK_IP_SIRC_VLP_ENABLE
/**
 * @brief        Write Config for SIRC in Low power mode to register
 *
 * @param        Config - pointer to configuration of SIRC low power mode
 * @return       None
 *
 */
extern void Clock_Ip_SetSircVlp_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);

/**
 * @brief        Enable Sirc in Low power mode
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_EnableSircVlp_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);

/**
 * @brief        Disable Sirc in Low power mode
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_DisableSircVlp_TrustedCall(Clock_Ip_NameType Name);
#endif

#ifdef CLOCK_IP_SIRC_STOP_ENABLE
/**
 * @brief        Write Config for SIRC in Stop mode to register
 *
 * @param        Config - pointer to configuration of SIRC in Stop mode
 * @return       None
 *
 */
extern void Clock_Ip_SetSircStop_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);

/**
 * @brief        Enable SIRC in Stop mode to register
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_EnableSircStop_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);

/**
 * @brief        Disable SIRC in Stop mode to register
 *
 * @param        Config - pointer to configuration of SIRC in Stop mode
 * @return       None
 *
 */
extern void Clock_Ip_DisableSircStop_TrustedCall(Clock_Ip_NameType Name);
#endif


#ifdef CLOCK_IP_FIRC_ENABLE
/**
 * @brief        Write Config for Firc to register
 *
 * @param        Config - pointer to configuration of Firc
 * @return       None
 *
 */
extern void Clock_Ip_SetFirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);

/**
 * @brief        Enable Firc to register
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_EnableFirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);

/**
 * @brief        Disable Firc to register
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_DisableFirc_TrustedCall(Clock_Ip_NameType Name);
#endif

#ifdef CLOCK_IP_SPLL_ENABLE
/**
 * @brief        Reset Spll register
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_ResetSpll_TrustedCall(Clock_Ip_PllConfigType const* Config);

/**
 * @brief        Write Config to Spll register
 *
 * @param        Config - pointer to confguration of SPLL
 * @return       None
 *
 */
extern void Clock_Ip_SetSpll_TrustedCall(Clock_Ip_PllConfigType const* Config);

/**
 * @brief        Disable Spll
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_DisableSpll_TrustedCall(Clock_Ip_NameType PllName);

/**
 * @brief        Enable Spll
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_EnableSpll_TrustedCall(Clock_Ip_PllConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_SCS_RUN_SEL
/**
 * @brief        Reset SCG_RCCR selector register
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_ResetScgRunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);

/**
 * @brief        Write Config to SCG_RCCR selector register
 *
 * @param        Config - pointer to configuration of system selector in run mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgRunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SCG_SCS_VLPR_SEL
/**
 * @brief        Write Config to SCG_VCCR selector register
 *
 * @param        Config - pointer to configuration of system selector in low power mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgVlprSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SCG_SCS_HSRUN_SEL
/**
 * @brief        Reset SCG_HCCR selector register
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_ResetScgHsrunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);

/**
 * @brief        Write Config to SCG_HCCR selector register
 *
 * @param        Config - pointer to configuration of system selector in HSRUN mode
 * @return       None
 *
 */
extern void Clock_Ip_SetScgHsrunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_RTC_SEL
/**
 * @brief        Reset SIM_LPOCLKS_RTCCLKSEL register
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_ResetSimRtcSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);

/**
 * @brief        Write Config to RTC_CLK register
 *
 * @param        Config - pointer to configuration of RTC_CLK selector
 * @return       None
 *
 */
extern void Clock_Ip_SetSimRtcSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_LPO_SEL
/**
 * @brief        Reset LPO_CLK selector
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_ResetSimLpoSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);

/**
 * @brief        Write Config to LPO_CLK selector
 *
 * @param        Config - pointer to configuration of LPO_CLK selector
 * @return       None
 *
 */
extern void Clock_Ip_SetSimLpoSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SCG_CLKOUT_SEL
/**
 * @brief        Reset CLKOUT_CLK selector
 *
 * @param        Config - pointer to configuration of CLKOUT selector
 * @return       None
 *
 */
extern void Clock_Ip_ResetScgClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);

/**
 * @brief        Write Config to LPO_CLK register
 *
 * @param        Config - pointer to configuration of LPO_CLK selector
 * @return       None
 *
 */
extern void Clock_Ip_SetScgClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif


#ifdef CLOCK_IP_SIM_FTMOPT_SEL
/**
 * @brief        Reset SIM->FTMOPT0 selector register
 *
 * @param        Config - pointer to configuration of FTMOPT clock need to be reset
 * @return       None
 *
 */
extern void Clock_Ip_ResetSimFtmoptSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);

/**
 * @brief        Write Config to SIM->FTMOPT0 register
 *
 * @param        Config - pointer to configuration of FTMOPT clock need to be reset
 * @return       None
 *
 */
extern void Clock_Ip_SetSimFtmoptSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_SEL
/**
 * @brief        Write Config to SIM_CHIPCTL_CLKOUTSEL register
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_ResetSimClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);

/**
 * @brief        Write Config to SIM_CHIPCTL_CLKOUTSEL register
 *
 * @param        Config - pointer to configuration of CLKOUT_CLK selector
 * @return       None
 *
 */
extern void Clock_Ip_SetSimClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_PCC_PCS_SELECT
/**
 * @brief        Reset register of PCC peripheral clock
 *
 * @param        Config - pointer to configuration clock need to be reset
 * @return       None
 *
 */
extern void Clock_Ip_ResetPccPcsSelect_TrustedCall(Clock_Ip_SelectorConfigType const *Config);

/**
 * @brief        Write Config to PCC register
 *
 * @param        Config - pointer to configuration of PCC peripheral clock
 * @return       None
 *
 */
extern void Clock_Ip_SetPccPcsSelect_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif


#ifdef CLOCK_IP_SIM_TRACE_SEL
/**
 * @brief        Reset selector register of TRACE_CLK
 *
 * @param        Config
 * @return       None
 *
 */
extern void Clock_Ip_ResetSimTraceSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);

/**
 * @brief        Write Config to TRACE_CLK selector register
 *
 * @param        Config - pointer to configuration of TRACE_CLK selector
 * @return       None
 *
 */
extern void Clock_Ip_SetSimTraceSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

/**
 * @brief        Reset FIRC
 *
 * @param        None
 * @return       None
 *
 */
extern void SetFircToResetValue_TrustedCall(void);

/**
 * @brief        Write Confgig whole SIM_LPOCLKS register
 *
 * @param        Config - pointer to configuration of all SIM_LPOCLKS clock
 * @return       None
 *
 */
extern void SetSimLpoclksRegister_TrustedCall(Clock_Ip_ClockConfigType const *Config);

#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK)
/**
 * @brief        Enable Cmu clock gate
 *
 * @param        None
 * @return       None
 *
 */
extern void Clock_Ip_EnableCmu0Gate_TrustedCall(void);
#endif

#if defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
/**
 * @brief        Enable Cmu clock gate
 *
 * @param        None
 * @return       None
 *
 */
extern void Clock_Ip_EnableCmu1Gate_TrustedCall(void);
#endif

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */





#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* CLOCK_IP_TRUSTEDFUNCTIONS_H */


