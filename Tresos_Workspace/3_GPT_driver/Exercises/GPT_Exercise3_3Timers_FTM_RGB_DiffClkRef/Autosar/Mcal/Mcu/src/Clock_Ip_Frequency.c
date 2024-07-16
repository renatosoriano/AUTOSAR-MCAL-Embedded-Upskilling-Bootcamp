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
/**
*   @file       Clock_Ip_Frequency.c
*   @version    2.0.0
*
*   @brief   CLOCK driver implementations.
*   @details CLOCK driver implementations.
*
*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Clock_Ip_Private.h"

#if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON))


/*==================================================================================================
*                                     SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_FREQUENCY_VENDOR_ID_C                      43
#define CLOCK_IP_FREQUENCY_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_FREQUENCY_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_FREQUENCY_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_FREQUENCY_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_FREQUENCY_SW_MINOR_VERSION_C               0
#define CLOCK_IP_FREQUENCY_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Frequency.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_FREQUENCY_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Frequency.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Frequency.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_FREQUENCY_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Frequency.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Frequency.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_FREQUENCY_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Frequency.c and Clock_Ip_Private.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef struct{

    Clock_Ip_NameType Name;
    uint32 Frequency;

}extSignalFreq;

typedef uint32 (*getFreqType)(void);

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define CLOCK_IP_EXT_SIGNALS_NO      4U
#define CLOCK_IP_DISABLED            0U
#define CLOCK_IP_ENABLED             0xFFFFFFFFU

#define CLOCK_IP_SIM_CHIPCTL_SELECTOR_HARDWARE_VALUES_NO      16U
#define CLOCK_IP_SIM_FTM_SELECTOR_HARDWARE_VALUES_NO          4U
#define CLOCK_IP_SCG_SELECTOR_HARDWARE_VALUES_NO              8U
#define CLOCK_IP_SCS_SELECTOR_HARDWARE_VALUES_NO              7U
#define CLOCK_IP_PCS1_SELECTOR_HARDWARE_VALUES_NO             7U
#define CLOCK_IP_PCS2_SELECTOR_HARDWARE_VALUES_NO             8U
#define CLOCK_IP_RTC_SELECTOR_HARDWARE_VALUES_NO              4U
#define CLOCK_IP_LPO_SELECTOR_HARDWARE_VALUES_NO              4U
#define CLOCK_IP_DIVIDER_VALUES_NO                            8U

#define CLOCK_IP_SPLL_FREQ                        160000000U
#define CLOCK_IP_SPLL_CHECKSUM                    1572864U


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static uint32 get_Zero_Frequency(void);
static uint32 get_LPO_128K_CLK_Frequency(void);
static uint32 get_FIRC_CLK_Frequency(void);
static uint32 get_SOSC_CLK_Frequency(void);
static uint32 get_SIRC_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_SPLL_CLK)
static uint32 get_SPLL_CLK_Frequency(void);
#endif
static uint32 get_SIRCDIV1_CLK_Frequency(void);
static uint32 get_SIRCDIV2_CLK_Frequency(void);
static uint32 get_FIRCDIV1_CLK_Frequency(void);
static uint32 get_FIRCDIV2_CLK_Frequency(void);
static uint32 get_SOSCDIV1_CLK_Frequency(void);
static uint32 get_SOSCDIV2_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_SPLLDIV1_CLK)
static uint32 get_SPLLDIV1_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_SPLLDIV2_CLK)
static uint32 get_SPLLDIV2_CLK_Frequency(void);
#endif
static uint32 get_LPO_32K_CLK_Frequency(void);
static uint32 get_LPO_1K_CLK_Frequency(void);
static uint32 get_tclk0_ref_Frequency(void);
static uint32 get_tclk1_ref_Frequency(void);
static uint32 get_tclk2_ref_Frequency(void);
static uint32 get_rtc_clkin_Frequency(void);
static uint32 get_SCS_CLK_Frequency(void);
static uint32 get_CORE_CLK_Frequency(void);
static uint32 get_BUS_CLK_Frequency(void);
static uint32 get_SLOW_CLK_Frequency(void);
static uint32 get_RTC_CLK_Frequency(void);
static uint32 get_LPO_CLK_Frequency(void);
static uint32 get_SCG_CLKOUT_CLK_Frequency(void);
static uint32 get_FTM0_EXT_CLK_Frequency(void);
static uint32 get_FTM1_EXT_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_FTM2_EXT_CLK)
static uint32 get_FTM2_EXT_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTM3_EXT_CLK)
static uint32 get_FTM3_EXT_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTM4_EXT_CLK)
static uint32 get_FTM4_EXT_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTM5_EXT_CLK)
static uint32 get_FTM5_EXT_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTM6_EXT_CLK)
static uint32 get_FTM6_EXT_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTM7_EXT_CLK)
static uint32 get_FTM7_EXT_CLK_Frequency(void);
#endif
static uint32 get_ADC0_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_ADC1_CLK)
static uint32 get_ADC1_CLK_Frequency(void);
#endif
static uint32 get_CLKOUT0_CLK_Frequency(void);
static uint32 get_CMP0_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_CMU0_CLK)
static uint32 get_CMU0_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_CMU1_CLK)
static uint32 get_CMU1_CLK_Frequency(void);
#endif
static uint32 get_CRC0_CLK_Frequency(void);
static uint32 get_DMA0_CLK_Frequency(void);
static uint32 get_DMAMUX0_CLK_Frequency(void);
static uint32 get_EIM0_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_ENET_CLK)
static uint32 get_ENET_CLK_Frequency(void);
#endif
static uint32 get_ERM0_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_EWM0_CLK)
static uint32 get_EWM0_CLK_Frequency(void);
#endif
static uint32 get_FLEXCAN0_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_FLEXCAN1_CLK)
static uint32 get_FLEXCAN1_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN2_CLK)
static uint32 get_FLEXCAN2_CLK_Frequency(void);
#endif
static uint32 get_FTM0_CLK_Frequency(void);
static uint32 get_FTM1_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_FTM2_CLK)
static uint32 get_FTM2_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTM3_CLK)
static uint32 get_FTM3_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTM4_CLK)
static uint32 get_FTM4_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTM5_CLK)
static uint32 get_FTM5_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTM6_CLK)
static uint32 get_FTM6_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTM7_CLK)
static uint32 get_FTM7_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_GPIO0_CLK)
static uint32 get_GPIO0_CLK_Frequency(void);
#endif
static uint32 get_FlexIO_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_FTFC_CLK)
static uint32 get_FTFC_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_FTFM_CLK)
static uint32 get_FTFM_CLK_Frequency(void);
#endif
static uint32 get_LPI2C0_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_LPI2C1_CLK)
static uint32 get_LPI2C1_CLK_Frequency(void);
#endif
static uint32 get_LPIT0_CLK_Frequency(void);
static uint32 get_LPSPI0_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_LPSPI1_CLK)
static uint32 get_LPSPI1_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_LPSPI2_CLK)
static uint32 get_LPSPI2_CLK_Frequency(void);
#endif
static uint32 get_LPTMR0_CLK_Frequency(void);
static uint32 get_LPUART0_CLK_Frequency(void);
static uint32 get_LPUART1_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_LPUART2_CLK)
static uint32 get_LPUART2_CLK_Frequency(void);
#endif
static uint32 get_MPU0_CLK_Frequency(void);
static uint32 get_MSCM0_CLK_Frequency(void);
static uint32 get_PDB0_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_PDB1_CLK)
static uint32 get_PDB1_CLK_Frequency(void);
#endif
static uint32 get_PORTA_CLK_Frequency(void);
static uint32 get_PORTB_CLK_Frequency(void);
static uint32 get_PORTC_CLK_Frequency(void);
static uint32 get_PORTD_CLK_Frequency(void);
static uint32 get_PORTE_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_QSPI_CLK)
static uint32 get_QSPI_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_QSPI_SFIF_CLK_HYP_PREMUX_CLK)
static uint32 get_QSPI_SFIF_CLK_HYP_PREMUX_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_QSPI_SFIF_CLK)
static uint32 get_QSPI_SFIF_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_QSPI_2xSFIF_CLK)
static uint32 get_QSPI_2xSFIF_CLK_Frequency(void);
#endif
static uint32 get_RTC0_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_SAI0_CLK)
static uint32 get_SAI0_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_SAI1_CLK)
static uint32 get_SAI1_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_TRACE_CLK)
static uint32 get_TRACE_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_SPLL_CLK)
static uint32 PLL_VCO(SCG_Type const *Base);
#endif

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

static const uint32 Clock_Ip_u32EnableClock[2U] = {CLOCK_IP_DISABLED,CLOCK_IP_ENABLED};
static const uint32 Clock_Ip_u32EnableGate[2U] = {CLOCK_IP_DISABLED,CLOCK_IP_ENABLED};

static const uint8 Clock_Ip_au8DividerMappingValue[CLOCK_IP_DIVIDER_VALUES_NO] = {
0U,                                /* Divider value for 0 hardware value */
1U,                                /* Divider value for 1 hardware value */
2U,                                /* Divider value for 2 hardware value */
4U,                                /* Divider value for 3 hardware value */
8U,                                /* Divider value for 4 hardware value */
16U,                               /* Divider value for 5 hardware value */
32U,                               /* Divider value for 6 hardware value */
64U,                               /* Divider value for 7 hardware value */
};


static const getFreqType Clock_Ip_apfFreqTablePcs2[CLOCK_IP_PCS2_SELECTOR_HARDWARE_VALUES_NO] =

{
        get_Zero_Frequency,                   /* function get clock for 0  hardware value */
        get_SOSCDIV2_CLK_Frequency,           /* function get clock for 1  hardware value */
        get_SIRCDIV2_CLK_Frequency,           /* function get clock for 2  hardware value */
        get_FIRCDIV2_CLK_Frequency,           /* function get clock for 3  hardware value */
        get_Zero_Frequency,                   /* function get clock for 4  hardware value */
        get_Zero_Frequency,                   /* function get clock for 5  hardware value */
#if defined(CLOCK_IP_HAS_SPLL_CLK)
        get_SPLLDIV2_CLK_Frequency,           /* function get clock for 6  hardware value */
#else
        get_Zero_Frequency,                   /* function get clock for 6  hardware value */
#endif
        get_LPO_128K_CLK_Frequency,           /* function get clock for 7  hardware value */
};

static const getFreqType Clock_Ip_apfFreqTablePcs1[CLOCK_IP_PCS1_SELECTOR_HARDWARE_VALUES_NO] =

{
        get_Zero_Frequency,                   /* function get clock for 0  hardware value */
        get_SOSCDIV1_CLK_Frequency,           /* function get clock for 1  hardware value */
        get_SIRCDIV1_CLK_Frequency,           /* function get clock for 2  hardware value */
        get_FIRCDIV1_CLK_Frequency,           /* function get clock for 3  hardware value */
        get_Zero_Frequency,                   /* function get clock for 4  hardware value */
        get_Zero_Frequency,                   /* function get clock for 5  hardware value */
#if defined(CLOCK_IP_HAS_SPLL_CLK)
        get_SPLLDIV1_CLK_Frequency,           /* function get clock for 6  hardware value */
#else
        get_Zero_Frequency,                   /* function get clock for 6  hardware value */
#endif
};

static const getFreqType Clock_Ip_apfFreqTableSimFtm[CLOCK_IP_SIM_FTM_SELECTOR_HARDWARE_VALUES_NO] =

{
        get_tclk0_ref_Frequency,              /* function get clock for 0  hardware value */
        get_tclk1_ref_Frequency,              /* function get clock for 1  hardware value */
        get_tclk2_ref_Frequency,              /* function get clock for 2  hardware value */
        get_Zero_Frequency,                   /* function get clock for 3  hardware value */
};

static const getFreqType FreqTableClkOut[CLOCK_IP_SIM_CHIPCTL_SELECTOR_HARDWARE_VALUES_NO] =
{
    get_SCG_CLKOUT_CLK_Frequency,                    /* function get clock for 0  hardware value */
    get_Zero_Frequency,                              /* function get clock for 1  hardware value */
    get_SOSCDIV2_CLK_Frequency,                      /* function get clock for 2  hardware value */
    get_Zero_Frequency,                              /* function get clock for 3  hardware value */
    get_SIRCDIV2_CLK_Frequency,                      /* function get clock for 4  hardware value */
#if defined(CLOCK_IP_HAS_QSPI_SFIF_CLK_HYP_PREMUX_CLK)
    get_QSPI_SFIF_CLK_HYP_PREMUX_CLK_Frequency,      /* function get clock for 5  hardware value */
#else
    get_Zero_Frequency,                              /* function get clock for 5  hardware value */
#endif
    get_FIRCDIV2_CLK_Frequency,                      /* function get clock for 6  hardware value */
    get_CORE_CLK_Frequency,                          /* function get clock for 7  hardware value */
#if defined(CLOCK_IP_HAS_SPLL_CLK)
    get_SPLLDIV2_CLK_Frequency,                      /* function get clock for 8  hardware value */
#else
    get_Zero_Frequency,                              /* function get clock for 8  hardware value */
#endif
    get_BUS_CLK_Frequency,                           /* function get clock for 9  hardware value */
    get_LPO_128K_CLK_Frequency,                      /* function get clock for 10 hardware value */
#if defined(CLOCK_IP_HAS_QSPI_CLK)
    get_QSPI_CLK_Frequency,                          /* function get clock for 11  hardware value */
#else
    get_Zero_Frequency,                              /* function get clock for 11  hardware value */
#endif
    get_LPO_CLK_Frequency,                           /* function get clock for 12 hardware value */
#if defined(CLOCK_IP_HAS_QSPI_SFIF_CLK)
    get_QSPI_SFIF_CLK_Frequency,                     /* function get clock for 13 hardware value */
#else
    get_Zero_Frequency,                              /* function get clock for 13  hardware value */
#endif
    get_RTC_CLK_Frequency,                           /* function get clock for 14 hardware value */
#if defined(CLOCK_IP_HAS_QSPI_2xSFIF_CLK)
    get_QSPI_2xSFIF_CLK_Frequency,                   /* function get clock for 15 hardware value */
#else
    get_Zero_Frequency,                              /* function get clock for 15 hardware value */
#endif
};

static const getFreqType FreqTableSCS[CLOCK_IP_SCS_SELECTOR_HARDWARE_VALUES_NO] =
{
    get_Zero_Frequency,                   /* function get clock for 0  hardware value */
    get_SOSC_CLK_Frequency,               /* function get clock for 1  hardware value */
    get_SIRC_CLK_Frequency,               /* function get clock for 2  hardware value */
    get_FIRC_CLK_Frequency,               /* function get clock for 3  hardware value */
    get_Zero_Frequency,                   /* function get clock for 4  hardware value */
    get_Zero_Frequency,                   /* function get clock for 5  hardware value */
#if defined(CLOCK_IP_HAS_SPLL_CLK)
    get_SPLL_CLK_Frequency,               /* function get clock for 6  hardware value */
#else
    get_Zero_Frequency,                   /* function get clock for 6  hardware value */
#endif
};

static const getFreqType FreqTableRtc[CLOCK_IP_RTC_SELECTOR_HARDWARE_VALUES_NO] =
{
    get_SOSCDIV1_CLK_Frequency,           /* function get clock for 0  hardware value */
    get_LPO_32K_CLK_Frequency,            /* function get clock for 1  hardware value */
    get_rtc_clkin_Frequency,              /* function get clock for 2  hardware value */
    get_FIRCDIV1_CLK_Frequency,           /* function get clock for 3  hardware value */
};

static const getFreqType FreqTableLpo[CLOCK_IP_LPO_SELECTOR_HARDWARE_VALUES_NO] =
{
    get_LPO_128K_CLK_Frequency,           /* function get clock for 0  hardware value */
    get_Zero_Frequency,                   /* function get clock for 1  hardware value */
    get_LPO_32K_CLK_Frequency,            /* function get clock for 2  hardware value */
    get_LPO_1K_CLK_Frequency,             /* function get clock for 3  hardware value */
};

static const getFreqType FreqTableScg[CLOCK_IP_SCG_SELECTOR_HARDWARE_VALUES_NO] =
{
    get_SLOW_CLK_Frequency,               /* function get clock for 0  hardware value */
    get_SOSC_CLK_Frequency,               /* function get clock for 1  hardware value */
    get_SIRC_CLK_Frequency,               /* function get clock for 2  hardware value */
    get_FIRC_CLK_Frequency,               /* function get clock for 3  hardware value */
    get_Zero_Frequency,                   /* function get clock for 4  hardware value */
    get_Zero_Frequency,                   /* function get clock for 5  hardware value */
#if defined(CLOCK_IP_HAS_SPLL_CLK)
    get_SPLL_CLK_Frequency,               /* function get clock for 6  hardware value */
#else
    get_Zero_Frequency,                   /* function get clock for 6  hardware value */
#endif
    get_Zero_Frequency,                   /* function get clock for 7  hardware value */
};

static const getFreqType FreqTable[CLOCK_IP_NAMES_NO] =
{
    get_Zero_Frequency,                   /* CLOCK_IS_OFF */
    get_LPO_128K_CLK_Frequency,           /* LPO_128K_CLK */
    get_SIRC_CLK_Frequency,               /* SIRC_CLK */
    get_Zero_Frequency,                   /* SIRC_VLP_CLK */
    get_Zero_Frequency,                   /* SIRC_STOP_CLK */
    get_FIRC_CLK_Frequency,               /* FIRC_CLK */
    get_Zero_Frequency,                   /* FIRC_VLP_CLK */
    get_Zero_Frequency,                   /* FIRC_STOP_CLK */
    get_SOSC_CLK_Frequency,               /* SOSC_CLK */
#if defined(CLOCK_IP_HAS_SPLL_CLK)
    get_SPLL_CLK_Frequency,               /* SPLL_CLK */
#endif
    get_SIRCDIV1_CLK_Frequency,           /* SIRCDIV1_CLK */
    get_SIRCDIV2_CLK_Frequency,           /* SIRCDIV2_CLK */
    get_FIRCDIV1_CLK_Frequency,           /* FIRCDIV1_CLK */
    get_FIRCDIV2_CLK_Frequency,           /* FIRCDIV2_CLK */
    get_SOSCDIV1_CLK_Frequency,           /* SOSCDIV1_CLK */
    get_SOSCDIV2_CLK_Frequency,           /* SOSCDIV2_CLK */
#if defined(CLOCK_IP_HAS_SPLLDIV1_CLK)
    get_SPLLDIV1_CLK_Frequency,           /* SPLLDIV1_CLK */
#endif
#if defined(CLOCK_IP_HAS_SPLLDIV2_CLK)
    get_SPLLDIV2_CLK_Frequency,           /* SPLLDIV2_CLK */
#endif
    get_LPO_32K_CLK_Frequency,            /* LPO_32K_CLK */
    get_LPO_1K_CLK_Frequency,             /* LPO_1K_CLK */
    get_tclk0_ref_Frequency,              /* tclk0_ref */
    get_tclk1_ref_Frequency,              /* tclk1_ref */
    get_tclk2_ref_Frequency,              /* tclk2_ref */
    get_rtc_clkin_Frequency,              /* rtc_clkin */
    get_SCS_CLK_Frequency,                /* SCS_CLK */
    get_Zero_Frequency,                   /* SCS_RUN_CLK */
    get_Zero_Frequency,                   /* SCS_VLPR_CLK */
#if defined(CLOCK_IP_HAS_SCS_HSRUN_CLK)
    get_Zero_Frequency,                   /* SCS_HSRUN_CLK */
#endif
    get_CORE_CLK_Frequency,               /* CORE_CLK */
    get_Zero_Frequency,                   /* CORE_RUN_CLK */
    get_Zero_Frequency,                   /* CORE_VLPR_CLK */
#if defined(CLOCK_IP_HAS_CORE_HSRUN_CLK)
    get_Zero_Frequency,                   /* CORE_HSRUN_CLK */
#endif
    get_BUS_CLK_Frequency,                /* BUS_CLK */
    get_Zero_Frequency,                   /* BUS_RUN_CLK */
    get_Zero_Frequency,                   /* BUS_VLPR_CLK */
#if defined(CLOCK_IP_HAS_BUS_HSRUN_CLK)
    get_Zero_Frequency,                   /* BUS_HSRUN_CLK */
#endif
    get_SLOW_CLK_Frequency,               /* SLOW_CLK */
    get_Zero_Frequency,                   /* SLOW_RUN_CLK */
    get_Zero_Frequency,                   /* SLOW_VLPR_CLK */
#if defined(CLOCK_IP_HAS_SLOW_HSRUN_CLK)
    get_Zero_Frequency,                   /* SLOW_HSRUN_CLK */
#endif
    get_RTC_CLK_Frequency,                /* RTC_CLK */
    get_LPO_CLK_Frequency,                /* LPO_CLK */
    get_SCG_CLKOUT_CLK_Frequency,         /* SCG_CLKOUT_CLK */
    get_FTM0_EXT_CLK_Frequency,           /* FTM0_EXT_CLK */
    get_FTM1_EXT_CLK_Frequency,           /* FTM1_EXT_CLK */
#if defined(CLOCK_IP_HAS_FTM2_EXT_CLK)
    get_FTM2_EXT_CLK_Frequency,           /* FTM2_EXT_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTM3_EXT_CLK)
    get_FTM3_EXT_CLK_Frequency,           /* FTM3_EXT_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTM4_EXT_CLK)
    get_FTM4_EXT_CLK_Frequency,           /* FTM0_EXT_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTM5_EXT_CLK)
    get_FTM5_EXT_CLK_Frequency,           /* FTM1_EXT_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTM6_EXT_CLK)
    get_FTM6_EXT_CLK_Frequency,           /* FTM2_EXT_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTM7_EXT_CLK)
    get_FTM7_EXT_CLK_Frequency,           /* FTM3_EXT_CLK */
#endif
    NULL_PTR,                             /* THE_LAST_PRODUCER_CLK */
    get_ADC0_CLK_Frequency,               /* ADC0_CLK */
#if defined(CLOCK_IP_HAS_ADC1_CLK)
    get_ADC1_CLK_Frequency,               /* ADC1_CLK */
#endif
    get_CLKOUT0_CLK_Frequency,            /* CLKOUT0_CLK */
    get_CMP0_CLK_Frequency,               /* CMP0_CLK */
#if defined(CLOCK_IP_HAS_CMU0_CLK)
    get_CMU0_CLK_Frequency,               /* CMU0_CLK */
#endif
#if defined(CLOCK_IP_HAS_CMU1_CLK)
    get_CMU1_CLK_Frequency,               /* CMU1_CLK */
#endif
    get_CRC0_CLK_Frequency,               /* CRC0_CLK */
    get_DMA0_CLK_Frequency,               /* DMA0_CLK */
    get_DMAMUX0_CLK_Frequency,            /* DMAMUX0_CLK */
    get_EIM0_CLK_Frequency,               /* EIM0_CLK */
#if defined(CLOCK_IP_HAS_ENET_CLK)
    get_ENET_CLK_Frequency,               /* ENET_CLK */
#endif
    get_ERM0_CLK_Frequency,               /* ERM0_CLK */
#if defined(CLOCK_IP_HAS_EWM0_CLK)
    get_EWM0_CLK_Frequency,                /* EWM0_CLK */
#endif
#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK)
    get_FIRC_CLK_Frequency,               /* FIRC_MON1_CLK */
#endif
#if defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
    get_FIRC_CLK_Frequency,               /* FIRC_MON2_CLK */
#endif
    get_FLEXCAN0_CLK_Frequency,               /* FLEXCAN0_CLK */
#if defined(CLOCK_IP_HAS_FLEXCAN1_CLK)
    get_FLEXCAN1_CLK_Frequency,               /* FLEXCAN1_CLK */
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN2_CLK)
    get_FLEXCAN2_CLK_Frequency,               /* FLEXCAN2_CLK */
#endif
    get_FlexIO_CLK_Frequency,             /* FlexIO_CLK */
#if defined(CLOCK_IP_HAS_FTFC_CLK)
    get_FTFC_CLK_Frequency,               /* FTFC_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTFM_CLK)
    get_FTFM_CLK_Frequency,               /* FTFM_CLK */
#endif
    get_FTM0_CLK_Frequency,               /* FTM0_CLK */
    get_FTM1_CLK_Frequency,               /* FTM1_CLK */
#if defined(CLOCK_IP_HAS_FTM2_CLK)
    get_FTM2_CLK_Frequency,               /* FTM2_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTM3_CLK)
    get_FTM3_CLK_Frequency,               /* FTM3_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTM4_CLK)
    get_FTM4_CLK_Frequency,               /* FTM4_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTM5_CLK)
    get_FTM5_CLK_Frequency,               /* FTM5_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTM6_CLK)
    get_FTM6_CLK_Frequency,               /* FTM6_CLK */
#endif
#if defined(CLOCK_IP_HAS_FTM7_CLK)
    get_FTM7_CLK_Frequency,               /* FTM7_CLK */
#endif
#if defined(CLOCK_IP_HAS_GPIO0_CLK)
    get_GPIO0_CLK_Frequency,               /* GPIO0_CLK */
#endif
    get_LPI2C0_CLK_Frequency,             /* LPI2C0_CLK */
#if defined(CLOCK_IP_HAS_LPI2C1_CLK)
    get_LPI2C1_CLK_Frequency,             /* LPI2C1_CLK */
#endif
    get_LPIT0_CLK_Frequency,              /* LPIT0_CLK */
    get_LPSPI0_CLK_Frequency,             /* LPSPI0_CLK */
#if defined(CLOCK_IP_HAS_LPSPI1_CLK)
    get_LPSPI1_CLK_Frequency,             /* LPSPI1_CLK */
#endif
#if defined(CLOCK_IP_HAS_LPSPI2_CLK)
    get_LPSPI2_CLK_Frequency,             /* LPSPI2_CLK */
#endif
    get_LPTMR0_CLK_Frequency,             /* LPTMR0_CLK */
    get_LPUART0_CLK_Frequency,            /* LPUART0_CLK */
    get_LPUART1_CLK_Frequency,            /* LPUART1_CLK */
#if defined(CLOCK_IP_HAS_LPUART2_CLK)
    get_LPUART2_CLK_Frequency,            /* LPUART2_CLK */
#endif
    get_MPU0_CLK_Frequency,               /* MPU0_CLK */
    get_MSCM0_CLK_Frequency,              /* MSCM0_CLK */
    get_PDB0_CLK_Frequency,               /* PDB0_CLK */
#if defined(CLOCK_IP_HAS_PDB1_CLK)
    get_PDB1_CLK_Frequency,               /* PDB1_CLK */
#endif
    get_PORTA_CLK_Frequency,              /* PORTA_CLK */
    get_PORTB_CLK_Frequency,              /* PORTB_CLK */
    get_PORTC_CLK_Frequency,              /* PORTC_CLK */
    get_PORTD_CLK_Frequency,              /* PORTD_CLK */
    get_PORTE_CLK_Frequency,              /* PORTE_CLK */
#if defined(CLOCK_IP_HAS_QSPI_CLK)
    get_QSPI_CLK_Frequency,               /* QSPI_CLK */
#endif
#if defined(CLOCK_IP_HAS_QSPI_SFIF_CLK_HYP_PREMUX_CLK)
    get_QSPI_SFIF_CLK_HYP_PREMUX_CLK_Frequency,                   /* QSPI_SFIF_CLK_HYP_PREMUX_CLK */
#endif
#if defined(CLOCK_IP_HAS_QSPI_SFIF_CLK)
    get_QSPI_SFIF_CLK_Frequency,                   /* QSPI_SFIF_CLK */
#endif
#if defined(CLOCK_IP_HAS_QSPI_2xSFIF_CLK)
    get_QSPI_2xSFIF_CLK_Frequency,                   /* QSPI_2xSFIF_CLK */
#endif
    get_RTC0_CLK_Frequency,               /* RTC0_CLK */
#if defined(CLOCK_IP_HAS_SAI0_CLK)
    get_SAI0_CLK_Frequency,               /* SAI0_CLK */
#endif
#if defined(CLOCK_IP_HAS_SAI1_CLK)
    get_SAI1_CLK_Frequency,               /* SAI1_CLK */
#endif
#if defined(CLOCK_IP_HAS_TRACE_CLK)
    get_TRACE_CLK_Frequency,              /* TRACE_CLK */
#endif
};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"

#if defined(CLOCK_IP_HAS_SPLL_CLK)
static uint32 SpllFreq = CLOCK_IP_SPLL_FREQ;
static uint32 SpllChecksum = CLOCK_IP_SPLL_CHECKSUM;
#endif

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static extSignalFreq Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_EXT_SIGNALS_NO] =  {{TCLK0_REF_CLK,0U},{TCLK1_REF_CLK,0U},{TCLK2_REF_CLK,0U},{RTC_CLKIN,0U}};

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"


#define MCU_START_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"

/* External oscillators */
static uint32 Clock_Ip_u32Sosc = CLOCK_IP_DEFAULT_SOSC_FREQUENCY;


#define MCU_STOP_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/* Return 0 frequency for no input clock or no clock */
static uint32 get_Zero_Frequency(void) {

    return 0U;
}

/* Return LPO_128K_CLK frequency */
static uint32 get_LPO_128K_CLK_Frequency(void) {

    return CLOCK_IP_LPO_128K_FREQUENCY;
}

/* Return FIRC_CLK frequency */
static uint32 get_FIRC_CLK_Frequency(void) {

    return (uint32)CLOCK_IP_FIRC_FREQUENCY & Clock_Ip_u32EnableClock[((IP_SCG->FIRCCSR & SCG_FIRCCSR_FIRCEN_MASK) >> SCG_FIRCCSR_FIRCEN_SHIFT)];
}

/* Return SOSC_CLK frequency */
static uint32 get_SOSC_CLK_Frequency(void) {

    return Clock_Ip_u32Sosc & Clock_Ip_u32EnableClock[((IP_SCG->SOSCCSR & SCG_SOSCCSR_SOSCEN_MASK) >> SCG_SOSCCSR_SOSCEN_SHIFT)];
}

/* Return SIRC_CLK frequency */
static uint32 get_SIRC_CLK_Frequency(void) {

    return (uint32)CLOCK_IP_SIRC_FREQUENCY & Clock_Ip_u32EnableClock[((IP_SCG->SIRCCSR & SCG_SIRCCSR_SIRCEN_MASK) >> SCG_SIRCCSR_SIRCEN_SHIFT)];
}

#if defined(CLOCK_IP_HAS_SPLL_CLK)
/* Return SPLL_CLK frequency */
static uint32 get_SPLL_CLK_Frequency(void) {

    if (SpllChecksum != IP_SCG->SPLLCFG)
    {
        SpllChecksum = IP_SCG->SPLLCFG;
        (void)SpllChecksum;
        SpllFreq = PLL_VCO(IP_SCG);
        SpllFreq &= Clock_Ip_u32EnableClock[((IP_SCG->SPLLCSR & SCG_SPLLCSR_SPLLEN_MASK) >> SCG_SPLLCSR_SPLLEN_SHIFT)];
    }

    return (((((IP_SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK) >> SCG_SPLLCSR_SPLLVLD_SHIFT)) != 0U )? SpllFreq : 0U);
}
#endif

/* Return SIRCDIV1_CLK frequency */
static uint32 get_SIRCDIV1_CLK_Frequency(void) {

    uint32 DivValue = Clock_Ip_au8DividerMappingValue[((IP_SCG->SIRCDIV & SCG_SIRCDIV_SIRCDIV1_MASK) >> SCG_SIRCDIV_SIRCDIV1_SHIFT)];
    return (DivValue != 0U) ? (get_SIRC_CLK_Frequency() / DivValue) : 0U;
}

/* Return SIRCDIV2_CLK frequency */
static uint32 get_SIRCDIV2_CLK_Frequency(void) {

    uint32 DivValue = Clock_Ip_au8DividerMappingValue[((IP_SCG->SIRCDIV & SCG_SIRCDIV_SIRCDIV2_MASK) >> SCG_SIRCDIV_SIRCDIV2_SHIFT)];
    return (DivValue != 0U) ? (get_SIRC_CLK_Frequency() / DivValue) : 0U;
}

/* Return FIRCDIV1_CLK frequency */
static uint32 get_FIRCDIV1_CLK_Frequency(void) {

    uint32 DivValue = Clock_Ip_au8DividerMappingValue[((IP_SCG->FIRCDIV & SCG_FIRCDIV_FIRCDIV1_MASK) >> SCG_FIRCDIV_FIRCDIV1_SHIFT)];
    return (DivValue != 0U) ? (get_FIRC_CLK_Frequency() / DivValue) : 0U;
}

/* Return FIRCDIV2_CLK frequency */
static uint32 get_FIRCDIV2_CLK_Frequency(void) {

    uint32 DivValue = Clock_Ip_au8DividerMappingValue[((IP_SCG->FIRCDIV & SCG_FIRCDIV_FIRCDIV2_MASK) >> SCG_FIRCDIV_FIRCDIV2_SHIFT)];
    return (DivValue != 0U) ? (get_FIRC_CLK_Frequency() / DivValue) : 0U;
}

/* Return SOSCDIV1_CLK frequency */
static uint32 get_SOSCDIV1_CLK_Frequency(void) {

    uint32 DivValue = Clock_Ip_au8DividerMappingValue[((IP_SCG->SOSCDIV & SCG_SOSCDIV_SOSCDIV1_MASK) >> SCG_SOSCDIV_SOSCDIV1_SHIFT)];
    return (DivValue != 0U) ? (get_SOSC_CLK_Frequency() / DivValue) : 0U;
}

/* Return SOSCDIV2_CLK frequency */
static uint32 get_SOSCDIV2_CLK_Frequency(void) {

    uint32 DivValue = Clock_Ip_au8DividerMappingValue[((IP_SCG->SOSCDIV & SCG_SOSCDIV_SOSCDIV2_MASK) >> SCG_SOSCDIV_SOSCDIV2_SHIFT)];
    return (DivValue != 0U) ? (get_SOSC_CLK_Frequency() / DivValue) : 0U;
}

#if defined(CLOCK_IP_HAS_SPLLDIV1_CLK)
/* Return SPLLDIV1_CLK frequency */
static uint32 get_SPLLDIV1_CLK_Frequency(void) {

    uint32 DivValue = Clock_Ip_au8DividerMappingValue[((IP_SCG->SPLLDIV & SCG_SPLLDIV_SPLLDIV1_MASK) >> SCG_SPLLDIV_SPLLDIV1_SHIFT)];
    return (DivValue != 0U) ? (get_SPLL_CLK_Frequency() / DivValue) : 0U;
}
#endif

#if defined(CLOCK_IP_HAS_SPLLDIV2_CLK)
/* Return SPLLDIV2_CLK frequency */
static uint32 get_SPLLDIV2_CLK_Frequency(void) {

    uint32 DivValue = Clock_Ip_au8DividerMappingValue[((IP_SCG->SPLLDIV & SCG_SPLLDIV_SPLLDIV2_MASK) >> SCG_SPLLDIV_SPLLDIV2_SHIFT)];
    return (DivValue != 0U) ? (get_SPLL_CLK_Frequency() / DivValue) : 0U;
}
#endif

/* Return LPO_32K_CLK frequency */
static uint32 get_LPO_32K_CLK_Frequency(void) {

    return (get_LPO_128K_CLK_Frequency() >> 2U) & Clock_Ip_u32EnableGate[((IP_SIM->LPOCLKS & SIM_LPOCLKS_LPO32KCLKEN_MASK) >> SIM_LPOCLKS_LPO32KCLKEN_SHIFT)];
}

/* Return LPO_1K_CLK frequency */
static uint32 get_LPO_1K_CLK_Frequency(void) {

    return (get_LPO_128K_CLK_Frequency() >> 7U) & Clock_Ip_u32EnableGate[((IP_SIM->LPOCLKS & SIM_LPOCLKS_LPO1KCLKEN_MASK) >> SIM_LPOCLKS_LPO1KCLKEN_SHIFT)];
}

/* Return TCLK0_REF_CLK frequency */
static uint32 get_tclk0_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[0U].Frequency;
}

/* Return TCLK1_REF_CLK frequency */
static uint32 get_tclk1_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[1U].Frequency;
}

/* Return TCLK2_REF_CLK frequency */
static uint32 get_tclk2_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[2U].Frequency;
}

/* Return RTC_CLKIN frequency */
static uint32 get_rtc_clkin_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[3U].Frequency;
}

/* Return SCS_CLK frequency */
static uint32 get_SCS_CLK_Frequency(void) {

    return FreqTableSCS[((IP_SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT)]();       /*  Selector value */
}

/* Return CORE_CLK frequency */
static uint32 get_CORE_CLK_Frequency(void) {

    return get_SCS_CLK_Frequency() / (((IP_SCG->CSR & SCG_CSR_DIVCORE_MASK) >> SCG_CSR_DIVCORE_SHIFT) + 1U);
}

/* Return SLOW_CLK frequency */
static uint32 get_BUS_CLK_Frequency(void) {

    return get_CORE_CLK_Frequency() / (((IP_SCG->CSR & SCG_CSR_DIVBUS_MASK) >> SCG_CSR_DIVBUS_SHIFT) + 1U);
}

/* Return SLOW_CLK frequency */
static uint32 get_SLOW_CLK_Frequency(void) {

    return get_CORE_CLK_Frequency() / (((IP_SCG->CSR & SCG_CSR_DIVSLOW_MASK) >> SCG_CSR_DIVSLOW_SHIFT) + 1U);
}

/* Return RTC_CLK frequency */
static uint32 get_RTC_CLK_Frequency(void) {

    return FreqTableRtc[((IP_SIM->LPOCLKS & SIM_LPOCLKS_RTCCLKSEL_MASK) >> SIM_LPOCLKS_RTCCLKSEL_SHIFT)]();       /*  Selector value */
}

/* Return LPO_CLK frequency */
static uint32 get_LPO_CLK_Frequency(void) {

    return FreqTableLpo[((IP_SIM->LPOCLKS & SIM_LPOCLKS_LPOCLKSEL_MASK) >> SIM_LPOCLKS_LPOCLKSEL_SHIFT)]();       /*  Selector value */
}

/* Return SCG_CLKOUT_CL frequency */
static uint32 get_SCG_CLKOUT_CLK_Frequency(void) {

    return FreqTableScg[((IP_SCG->CLKOUTCNFG & SCG_CLKOUTCNFG_CLKOUTSEL_MASK) >> SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT)]();       /*  Selector value */
}

/* Return FTM0_EXT_CLK frequency */
static uint32 get_FTM0_EXT_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableSimFtm[((IP_SIM->FTMOPT0 & SIM_FTMOPT0_FTM0CLKSEL_MASK) >> SIM_FTMOPT0_FTM0CLKSEL_SHIFT)]();       /*  Selector value */
}

/* Return FTM1_EXT_CLK frequency */
static uint32 get_FTM1_EXT_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableSimFtm[((IP_SIM->FTMOPT0 & SIM_FTMOPT0_FTM1CLKSEL_MASK) >> SIM_FTMOPT0_FTM1CLKSEL_SHIFT)]();       /*  Selector value */
}

#if defined(CLOCK_IP_HAS_FTM2_EXT_CLK)
/* Return FTM2_EXT_CLK frequency */
static uint32 get_FTM2_EXT_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableSimFtm[((IP_SIM->FTMOPT0 & SIM_FTMOPT0_FTM2CLKSEL_MASK) >> SIM_FTMOPT0_FTM2CLKSEL_SHIFT)]();       /*  Selector value */
}
#endif

#if defined(CLOCK_IP_HAS_FTM3_EXT_CLK)
/* Return FTM3_EXT_CLK frequency */
static uint32 get_FTM3_EXT_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableSimFtm[((IP_SIM->FTMOPT0 & SIM_FTMOPT0_FTM3CLKSEL_MASK) >> SIM_FTMOPT0_FTM3CLKSEL_SHIFT)]();       /*  Selector value */
}
#endif

#if defined(CLOCK_IP_HAS_FTM4_EXT_CLK)
/* Return FTM4_EXT_CLK frequency */
static uint32 get_FTM4_EXT_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableSimFtm[((IP_SIM->FTMOPT0 & SIM_FTMOPT0_FTM4CLKSEL_MASK) >> SIM_FTMOPT0_FTM4CLKSEL_SHIFT)]();       /*  Selector value */
}
#endif

#if defined(CLOCK_IP_HAS_FTM5_EXT_CLK)
/* Return FTM5_EXT_CLK frequency */
static uint32 get_FTM5_EXT_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableSimFtm[((IP_SIM->FTMOPT0 & SIM_FTMOPT0_FTM5CLKSEL_MASK) >> SIM_FTMOPT0_FTM5CLKSEL_SHIFT)]();       /*  Selector value */
}
#endif

#if defined(CLOCK_IP_HAS_FTM6_EXT_CLK)
/* Return FTM6_EXT_CLK frequency */
static uint32 get_FTM6_EXT_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableSimFtm[((IP_SIM->FTMOPT0 & SIM_FTMOPT0_FTM6CLKSEL_MASK) >> SIM_FTMOPT0_FTM6CLKSEL_SHIFT)]();       /*  Selector value */
}
#endif

#if defined(CLOCK_IP_HAS_FTM7_EXT_CLK)
/* Return FTM7_EXT_CLK frequency */
static uint32 get_FTM7_EXT_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableSimFtm[((IP_SIM->FTMOPT0 & SIM_FTMOPT0_FTM7CLKSEL_MASK) >> SIM_FTMOPT0_FTM7CLKSEL_SHIFT)]();       /*  Selector value */
}
#endif

/* Return ADC0_CLK frequency */
static uint32 get_ADC0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[59U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[59U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_ADC1_CLK)
/* Return ADC1_CLK frequency */
static uint32 get_ADC1_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[39U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[39U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

/* Return CLKOUT0_CLK frequency */
static uint32 get_CLKOUT0_CLK_Frequency(void) {

    const uint32 EnableDivider[2U] = {CLOCK_IP_DISABLED,CLOCK_IP_ENABLED};

    uint32 Frequency = FreqTableClkOut[((IP_SIM->CHIPCTL & SIM_CHIPCTL_CLKOUTSEL_MASK) >> SIM_CHIPCTL_CLKOUTSEL_SHIFT)]();       /*  Selector value */
    Frequency &= EnableDivider[((IP_SIM->CHIPCTL & SIM_CHIPCTL_CLKOUTEN_MASK) >> SIM_CHIPCTL_CLKOUTEN_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_SIM->CHIPCTL & SIM_CHIPCTL_CLKOUTDIV_MASK) >> SIM_CHIPCTL_CLKOUTDIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}

/* Return CMP0_CLK frequency */
static uint32 get_CMP0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[115] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_CMU0_CLK)
/* Return CMU0_CLK frequency */
static uint32 get_CMU0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[62] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_CMU1_CLK)
/* Return CMU1_CLK frequency */
static uint32 get_CMU1_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[63] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

/* Return CRC0_CLK frequency */
static uint32 get_CRC0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    /* Get Frequency after gate */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[50] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

/* Return DMA0_CLK frequency */
static uint32 get_DMA0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_SIM->PLATCGC & SIM_PLATCGC_CGCDMA_MASK) >> SIM_PLATCGC_CGCDMA_SHIFT)];
    return Frequency;
}

/* Return DMAMUX0_CLK frequency */
static uint32 get_DMAMUX0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[33] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

/* Return EIM0_CLK frequency */
static uint32 get_EIM0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_SIM->PLATCGC & SIM_PLATCGC_CGCEIM_MASK) >> SIM_PLATCGC_CGCEIM_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_ENET_CLK)
/* Return ENET_CLK frequency */
static uint32 get_ENET_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs1[((IP_PCC->PCCn[121U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    uint32 DivValue = ((IP_PCC->PCCn[121U] & PCC_PCCn_PCD_MASK) >> PCC_PCCn_PCD_SHIFT) + 1U;
    uint32 MulValue = ((IP_PCC->PCCn[121U] & PCC_PCCn_FRAC_MASK) >> PCC_PCCn_FRAC_SHIFT) + 1U;
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[121U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return ((Frequency * MulValue)  / DivValue);
}
#endif

/* Return ERM0_CLK frequency */
static uint32 get_ERM0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_SIM->PLATCGC & SIM_PLATCGC_CGCERM_MASK) >> SIM_PLATCGC_CGCERM_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_EWM0_CLK)
/* Return EWM0_CLK frequency */
static uint32 get_EWM0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[97U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

/* Return FLEXCAN0_CLK frequency */
static uint32 get_FLEXCAN0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[36U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_FLEXCAN1_CLK)
/* Return FLEXCAN1_CLK frequency */
static uint32 get_FLEXCAN1_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[37U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_FLEXCAN2_CLK)
/* Return FLEXCAN2_CLK frequency */
static uint32 get_FLEXCAN2_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[43U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

/* Return FTM0_CLK frequency */
static uint32 get_FTM0_CLK_Frequency(void) {

    uint32 Frequency;
    if(((IP_PCC->PCCn[56U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT) != 0U)
    {
        Frequency  = Clock_Ip_apfFreqTablePcs1[((IP_PCC->PCCn[56U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    }
    else
    {
        Frequency  = get_FTM0_EXT_CLK_Frequency();
    }
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[56U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

/* Return FTM1_CLK frequency */
static uint32 get_FTM1_CLK_Frequency(void) {

    uint32 Frequency;
    if(((IP_PCC->PCCn[57U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT) != 0U)
    {
        Frequency  = Clock_Ip_apfFreqTablePcs1[((IP_PCC->PCCn[57U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    }
    else
    {
        Frequency  = get_FTM1_EXT_CLK_Frequency();
    }
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[57U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_FTM2_CLK)
/* Return FTM2_CLK frequency */
static uint32 get_FTM2_CLK_Frequency(void) {

    uint32 Frequency;
    if(((IP_PCC->PCCn[58U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT) != 0U)
    {
        Frequency  = Clock_Ip_apfFreqTablePcs1[((IP_PCC->PCCn[58U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    }
    else
    {
        Frequency  = get_FTM2_EXT_CLK_Frequency();
    }
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[58U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_FTM3_CLK)
/* Return FTM3_CLK frequency */
static uint32 get_FTM3_CLK_Frequency(void) {

    uint32 Frequency;
    if(((IP_PCC->PCCn[38U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT) != 0U)
    {
        Frequency  = Clock_Ip_apfFreqTablePcs1[((IP_PCC->PCCn[38U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    }
    else
    {
        Frequency  = get_FTM3_EXT_CLK_Frequency();
    }
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[38U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_FTM4_CLK)
/* Return FTM5_CLK frequency */
static uint32 get_FTM4_CLK_Frequency(void) {

    uint32 Frequency;
    if(((IP_PCC->PCCn[110U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT) != 0U)
    {
        Frequency  = Clock_Ip_apfFreqTablePcs1[((IP_PCC->PCCn[110U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    }
    else
    {
        Frequency  = get_FTM4_EXT_CLK_Frequency();
    }
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[110U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_FTM5_CLK)
/* Return FTM5_CLK frequency */
static uint32 get_FTM5_CLK_Frequency(void) {

    uint32 Frequency;
    if(((IP_PCC->PCCn[111U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT) != 0U)
    {
        Frequency  = Clock_Ip_apfFreqTablePcs1[((IP_PCC->PCCn[111U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    }
    else
    {
        Frequency  = get_FTM5_EXT_CLK_Frequency();
    }
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[111U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_FTM6_CLK)
/* Return FTM6_CLK frequency */
static uint32 get_FTM6_CLK_Frequency(void) {

    uint32 Frequency;
    if(((IP_PCC->PCCn[112U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT) != 0U)
    {
        Frequency  = Clock_Ip_apfFreqTablePcs1[((IP_PCC->PCCn[112U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    }
    else
    {
        Frequency  = get_FTM6_EXT_CLK_Frequency();
    }
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[112U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_FTM7_CLK)
/* Return FTM7_CLK frequency */
static uint32 get_FTM7_CLK_Frequency(void) {

    uint32 Frequency;
    if(((IP_PCC->PCCn[113U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT) != 0U)
    {
        Frequency  = Clock_Ip_apfFreqTablePcs1[((IP_PCC->PCCn[113U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    }
    else
    {
        Frequency  = get_FTM7_EXT_CLK_Frequency();
    }
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[113U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_GPIO0_CLK)
/* Return GPIO0_CLK frequency */
static uint32 get_GPIO0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_SIM->PLATCGC & SIM_PLATCGC_CGCGPIO_MASK) >> SIM_PLATCGC_CGCGPIO_SHIFT)];
    return Frequency;
}
#endif

/* Return FlexIO_CLK frequency */
static uint32 get_FlexIO_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[90U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[90U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_FTFC_CLK)
/* Return FTFC_CLK frequency */
static uint32 get_FTFC_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = get_SLOW_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[32U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_FTFM_CLK)
/* Return FTFM_CLK frequency */
static uint32 get_FTFM_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = get_SLOW_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[32U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

/* Return LPI2C0_CLK frequency */
static uint32 get_LPI2C0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[102U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[102U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_LPI2C1_CLK)
/* Return LPI2C1_CLK frequency */
static uint32 get_LPI2C1_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[103U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[103U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

/* Return LPIT0_CLK frequency */
static uint32 get_LPIT0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[55U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[55U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

/* Return LPSPI0_CLK frequency */
static uint32 get_LPSPI0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[44U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[44U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_LPSPI1_CLK)
/* Return LPSPI1_CLK frequency */
static uint32 get_LPSPI1_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[45U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[45U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_LPSPI2_CLK)
/* Return LPSPI2_CLK frequency */
static uint32 get_LPSPI2_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[46U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[46U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

/* Return LPTMR0_CLK frequency */
static uint32 get_LPTMR0_CLK_Frequency(void) {

    uint32 Frequency = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[64U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)]();       /*  Selector value */
    uint32 DivValue = ((IP_PCC->PCCn[64U] & PCC_PCCn_PCD_MASK) >> PCC_PCCn_PCD_SHIFT) + 1U;
    uint32 MulValue = ((IP_PCC->PCCn[64U] & PCC_PCCn_FRAC_MASK) >> PCC_PCCn_FRAC_SHIFT) + 1U;
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[64U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return ((Frequency * MulValue)  / DivValue);
}

/* Return LPUART0_CLK frequency */
static uint32 get_LPUART0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[106U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[106U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

/* Return LPUART1_CLK frequency */
static uint32 get_LPUART1_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[107U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[107U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_LPUART2_CLK)
/* Return LPUART2_CLK frequency */
static uint32 get_LPUART2_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTablePcs2[((IP_PCC->PCCn[108U] & PCC_PCCn_PCS_MASK) >> PCC_PCCn_PCS_SHIFT)](); /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[108U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

/* Return MPU0_CLK frequency */
static uint32 get_MPU0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_SIM->PLATCGC & SIM_PLATCGC_CGCMPU_MASK) >> SIM_PLATCGC_CGCMPU_SHIFT)];
    return Frequency;
}

/* Return MSCM0_CLK frequency */
static uint32 get_MSCM0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_SIM->PLATCGC & SIM_PLATCGC_CGCMSCM_MASK) >> SIM_PLATCGC_CGCMSCM_SHIFT)];
    return Frequency;
}

/* Return PDB0_CLK frequency */
static uint32 get_PDB0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[54U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_PDB1_CLK)
/* Return PDB1_CLK frequency */
static uint32 get_PDB1_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[49U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

/* Return PORTA_CLK frequency */
static uint32 get_PORTA_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[73U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

/* Return PORTB_CLK frequency */
static uint32 get_PORTB_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[74U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

/* Return PORTC_CLK frequency */
static uint32 get_PORTC_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[75U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

/* Return PORTD_CLK frequency */
static uint32 get_PORTD_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[76U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

/* Return PORTE_CLK frequency */
static uint32 get_PORTE_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[77U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_QSPI_CLK)
#define QuadSPI_MCR_SCLKCFG_6_SHIFT   (30U)
#define QuadSPI_MCR_SCLKCFG_6_MASK   ((uint32)1U << QuadSPI_MCR_SCLKCFG_6_SHIFT)
/* Return QSPI_CLK frequency */
static uint32 get_QSPI_CLK_Frequency(void) {

    uint32 Frequency;
    uint8 Clkmodeselect;
    /* Check QSPI is enabled gate from PCC */
    if (Clock_Ip_u32EnableGate[((IP_PCC->PCCn[118U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)] == CLOCK_IP_ENABLED)
    {
        Clkmodeselect = (uint8)((IP_QuadSPI->MCR & QuadSPI_MCR_SCLKCFG_6_MASK) >> QuadSPI_MCR_SCLKCFG_6_SHIFT);
        if(Clkmodeselect  != 0U)
        {
            Frequency  = get_BUS_CLK_Frequency();
        }
        else
        {
            Frequency  = get_CORE_CLK_Frequency();
        }
    }
    else
    {
        Frequency  = get_Zero_Frequency();
    }

    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_QSPI_SFIF_CLK_HYP_PREMUX_CLK)
#define QuadSPI_MCR_SCLKCFG_4_SHIFT   (28U)
#define QuadSPI_MCR_SCLKCFG_4_MASK   ((uint32)1U << QuadSPI_MCR_SCLKCFG_4_SHIFT)
#define QuadSPI_SOCCR_SOCCFG_DIV_SHIFT   (29U)
#define QuadSPI_SOCCR_SOCCFG_DIV_MASK   ((uint32)7U << QuadSPI_SOCCR_SOCCFG_DIV_SHIFT)
#define SIM_MISCTRL0_QSPI_CLK_SEL_GATE_SHIFT   (26U)
#define SIM_MISCTRL0_QSPI_CLK_SEL_GATE_MASK   ((uint32)1U << SIM_MISCTRL0_QSPI_CLK_SEL_GATE_SHIFT)
/* Return QSPI_SFIF_CLK_HYP_PREMUX_CLK frequency */
static uint32 get_QSPI_SFIF_CLK_HYP_PREMUX_CLK_Frequency(void) {

    uint32 Frequency;
    uint8 Clkmodeselect;
    uint8 DivConfig;
    /* Check QSPI is enabled gate from PCC */
    if (Clock_Ip_u32EnableGate[((IP_PCC->PCCn[118U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)] == CLOCK_IP_ENABLED)
    {
        DivConfig = (uint8)((IP_QuadSPI->SOCCR & QuadSPI_SOCCR_SOCCFG_DIV_MASK) >> QuadSPI_SOCCR_SOCCFG_DIV_SHIFT);
        Clkmodeselect = (uint8)((IP_QuadSPI->MCR & QuadSPI_MCR_SCLKCFG_4_MASK) >> QuadSPI_MCR_SCLKCFG_4_SHIFT);
        if(Clkmodeselect  != 0U)
        {
            Frequency  = get_FIRCDIV1_CLK_Frequency() / ((DivConfig + (uint32)1U) * 2U) ;
        }
        else
        {
            #if defined(CLOCK_IP_HAS_SPLLDIV1_CLK)
            Frequency  = get_SPLLDIV1_CLK_Frequency() / ((DivConfig + (uint32)1U) * 2U) ;
            #else
            Frequency  = get_Zero_Frequency() / ((DivConfig + 1U) * 2U) ;
            #endif
        }
        Frequency &= Clock_Ip_u32EnableGate[((IP_SIM->MISCTRL0 & SIM_MISCTRL0_QSPI_CLK_SEL_GATE_MASK) >> SIM_MISCTRL0_QSPI_CLK_SEL_GATE_SHIFT)];
    }
    else
    {
        Frequency  = get_Zero_Frequency();
    }

    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_QSPI_SFIF_CLK)
#define QuadSPI_MCR_SCLKCFG_5_SHIFT   (29U)
#define QuadSPI_MCR_SCLKCFG_5_MASK   ((uint32)1U << QuadSPI_MCR_SCLKCFG_5_SHIFT)
/* Return QSPI_SFIF_CLK frequency */
static uint32 get_QSPI_SFIF_CLK_Frequency(void) {

    uint32 Frequency;
    uint8 Clkmodeselect;
    /* Check QSPI is enabled gate from PCC */
    if (Clock_Ip_u32EnableGate[((IP_PCC->PCCn[118U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)] == CLOCK_IP_ENABLED)
    {
        Clkmodeselect = (uint8)((IP_QuadSPI->MCR & QuadSPI_MCR_SCLKCFG_5_MASK) >> QuadSPI_MCR_SCLKCFG_5_SHIFT);
        if(Clkmodeselect  != 0U)
        {
            Frequency  = get_QSPI_SFIF_CLK_HYP_PREMUX_CLK_Frequency();
        }
        else
        {
            Frequency  = get_QSPI_SFIF_CLK_HYP_PREMUX_CLK_Frequency() * 2U;
        }
    }
    else
    {
        Frequency  = get_Zero_Frequency();
    }

    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_QSPI_2xSFIF_CLK)
/* Return QSPI_2xSFIF_CLK frequency */
static uint32 get_QSPI_2xSFIF_CLK_Frequency(void) {

    uint32 Frequency;
    uint8 Clkmodeselect;
    /* Check QSPI is enabled gate from PCC */
    if (Clock_Ip_u32EnableGate[((IP_PCC->PCCn[118U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)] == CLOCK_IP_ENABLED)
    {
        Clkmodeselect = (uint8)((IP_QuadSPI->MCR & QuadSPI_MCR_SCLKCFG_5_MASK) >> QuadSPI_MCR_SCLKCFG_5_SHIFT);
        if(Clkmodeselect  != 0U)
        {
            Frequency  =  get_QSPI_SFIF_CLK_HYP_PREMUX_CLK_Frequency() * 2U;
        }
        else
        {
            Frequency  = get_Zero_Frequency();
        }
    }
    else
    {
        Frequency  = get_Zero_Frequency();
    }

    return Frequency;
}
#endif

/* Return RTC0_CLK frequency */
static uint32 get_RTC0_CLK_Frequency(void) {
    uint32 Frequency;
    Frequency  = FreqTableRtc[((IP_SIM->LPOCLKS & SIM_LPOCLKS_RTCCLKSEL_MASK) >> SIM_LPOCLKS_RTCCLKSEL_SHIFT)]();       /*  Selector value */
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[61U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}

#if defined(CLOCK_IP_HAS_SAI0_CLK)
/* Return SAI0_CLK frequency */
static uint32 get_SAI0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[84U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_SAI1_CLK)
/* Return SAI1_CLK frequency */
static uint32 get_SAI1_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = get_BUS_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_PCC->PCCn[85U] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT)];
    return Frequency;
}
#endif

#if defined(CLOCK_IP_HAS_TRACE_CLK)
/* Return TRACE_CLK frequency */
static uint32 get_TRACE_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = get_CORE_CLK_Frequency();
    Frequency &= Clock_Ip_u32EnableGate[((IP_SIM->CLKDIV4 & SIM_CLKDIV4_TRACEDIVEN_MASK) >> SIM_CLKDIV4_TRACEDIVEN_SHIFT)];
    uint32 DivValue = ((IP_SIM->CLKDIV4 & SIM_CLKDIV4_TRACEDIV_MASK) >> SIM_CLKDIV4_TRACEDIV_SHIFT) + 1U;
    uint32 MulValue = ((IP_SIM->CLKDIV4 & SIM_CLKDIV4_TRACEFRAC_MASK) >> SIM_CLKDIV4_TRACEFRAC_SHIFT) + 1U;
    return ((Frequency * MulValue)  / DivValue);
}
#endif

#if defined(CLOCK_IP_HAS_SPLL_CLK)
/* Return PLL_VCO frequency */
#define CLOCK_IP_PLL_VCO_MAX_FREQ             (320000000U)
static uint32 PLL_VCO(SCG_Type const *Base)
{
    uint32 Fin;
    uint32 Prediv;
    uint32 Mul;
    uint32 Fout = 0U;
    uint32 Var1;
    uint32 Var2;
    boolean Overflow = FALSE;

    #if (defined (CLOCK_IP_S32K142W) || defined(CLOCK_IP_S32K144W) || defined(CLOCK_IP_S32M244))
    if ((IP_SCG->SPLLCFG & SCG_SPLLCFG_SOURCE_MASK) == 0U)
    {
        Fin  = get_SOSC_CLK_Frequency();
    }
    else
    {
        Fin  = get_FIRC_CLK_Frequency();
    }
    #else
    Fin  = get_SOSC_CLK_Frequency();                                                                       /* input freq */
    #endif
    Prediv = (((Base->SPLLCFG & SCG_SPLLCFG_PREDIV_MASK) >> SCG_SPLLCFG_PREDIV_SHIFT) + 1U) << 1U;         /* Prediv * 2 */
    Mul = (((Base->SPLLCFG & SCG_SPLLCFG_MULT_MASK) >> SCG_SPLLCFG_MULT_SHIFT) + 16U);                     /* mfi */

    Var1 = Mul / Prediv;                     /* mfi divide by (Prediv multiply by 2); */
    Var2 = Mul - (Var1 * Prediv);            /* mfi minus aux1 multiply by (Prediv multiply by 2); */

    if (0U != Fin)
    {
        if (Var1 == ((uint32)(Var1 * Fin) / Fin))
        {
            Fout = Var1 * Fin;                       /* aux1 multiply by Fin */
        }
        else
        {
            Overflow = TRUE;
        }

        if ((Var2 == ((uint32)(Fin * Var2) / Fin)) && (CLOCK_IP_PLL_VCO_MAX_FREQ >= Fout))
        {
            Fout += (Fin * Var2) / Prediv ;          /* Fin divide by (Prediv multiply by 2) multiply by Var2; */
        }
        else
        {
            Overflow = TRUE;
        }
    }

    if (TRUE == Overflow)
    {
        Fout = 0U;
    }

    return Fout;
}
#endif

/* Set frequency for External Oscillator clock */
void Clock_Ip_SetExternalOscillatorFrequency(Clock_Ip_NameType ExtOscName, uint32 Frequency)
{
    (void)ExtOscName;
    Clock_Ip_u32Sosc = Frequency;
}


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

uint32 Clock_Ip_GetFreq(Clock_Ip_NameType ClockName)
{

    return FreqTable[ClockName]();
}

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#endif  /* #if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON)) */

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/* Set frequency value for External Signal */
void Clock_Ip_SetExternalSignalFrequency(Clock_Ip_NameType SignalName, uint32 Frequency)
{
#if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON))
    uint32 Index;
    for (Index = 0U; Index < CLOCK_IP_EXT_SIGNALS_NO; Index++)
    {
        if (SignalName == Clock_Ip_axExtSignalFreqEntries[Index].Name)
        {
            Clock_Ip_axExtSignalFreqEntries[Index].Frequency = Frequency;
            break;
        }
    }
#else
    (void)SignalName;
    (void)Frequency;
#endif
}

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */


