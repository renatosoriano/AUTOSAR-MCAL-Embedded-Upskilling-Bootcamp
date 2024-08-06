/*
*   (c) Copyright 2021 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"
#include "Gpt.h"
#include "Mcal.h"
#include "Wdg_43_Instance0.h"

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
#include "Wdg_43_Instance1.h"
#endif
#endif

#ifdef WDG_INSTANCE2
#if (WDG_INSTANCE2 == STD_ON)
#include "Wdg_43_Instance2.h"
#include "Ae.h"
#include "Spi.h"
#include "Port.h"
#endif
#endif
#define AEC_DATAWIDTH_16             (16U)
#define AEC_WDCFG_ADDR               (0x30)
#define AEWDOG_WDCFG_RESET_VAL       (0x0300)
#define AEWDOG_WDGCFG_EXAMPLE_VAL    (AEC_AE_ALIVE_WD_CFG_WDW_FAULTREC(AEWDOG_IP_RESET) \
                                      | AEC_AE_ALIVE_WD_CFG_WDW_MODE(AEWDOG_IP_SIMPLE_WATCHDOG) \
                                      | AEC_AE_ALIVE_WD_CFG_WDW_BADRESP(AEWDOG_IP_BADRESP_MAX_0) \
                                      | AEC_AE_ALIVE_WD_CFG_WDW_PERIOD(AEWDOG_IP_WD_PERIOD_TIME_125_512) \
                                      | AEC_AE_ALIVE_WD_CFG_WDW_DC(AEWDOG_IP_DUTY_DISABLED))
#include "Platform.h"
#include "Devassert.h"
#include "check_example.h"

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
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/**
* @brief        Variables
* @details      The callback set a variable that was set to confirm the interrupt was triggered
*/
volatile uint8 notificationCount = 0;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Delay function
* @details      Delay function to test the Wdg Trigger
*/
void delay(uint32 timeout)
{
    volatile uint32 i = timeout;
    
    while(i--);
}

/**
* @brief        LPIT_0 Interrupt handler
* @details      Defined in LPit_Gpt_Ip.c
*/
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
extern ISR(LPIT_0_ISR);
#else
extern ISR(LPIT_0_CH_0_ISR);

#endif

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
/**
* @brief        LPIT_1 Interrupt handler
* @details      Defined in LPit_Gpt_Ip.c
*/
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
extern ISR(LPIT_1_ISR);
#else
extern ISR(LPIT_0_CH_1_ISR);
#endif
#endif
#endif

#ifdef WDG_INSTANCE2
#if (WDG_INSTANCE2 == STD_ON)
/**
* @brief        LPIT_2 Interrupt handler
* @details      Defined in LPit_Gpt_Ip.c
*/
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
extern ISR(LPIT_2_ISR);
#else
extern ISR(LPIT_0_CH_2_ISR);
#endif
#endif
#endif

/**
* @brief        Wdg Interrupt handler
* @details      Defined in Wdg_Ipw_Isr.c
*/
extern ISR(Wdg_Ipw_Isr);
/**
* @brief        Wdg callback notification called by the configured channel periodically
* @details      Increments the counter
*/
void Wdg_CallBackNotification1(void)
{
    notificationCount = 1U;
}

/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses Wdg driver
*/
int main(void) 
{
#ifdef WDG_INSTANCE2
#if (WDG_INSTANCE2 == STD_ON)
    uint32 regVal;
#endif
#endif
    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);

#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();
#endif

    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Install LPIT ISR */
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
    Platform_SetIrq(LPIT_IRQn, TRUE);
    Platform_InstallIrqHandler(LPIT_IRQn, &LPIT_0_ISR, NULL_PTR);
#else
    Platform_SetIrq(LPIT0_Ch0_IRQn, TRUE);
    Platform_InstallIrqHandler(LPIT0_Ch0_IRQn, &LPIT_0_CH_0_ISR, NULL_PTR);
#endif

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
    /* Install LPIT ISR */
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
    Platform_SetIrq(LPIT_IRQn, TRUE);
    Platform_InstallIrqHandler(LPIT_IRQn, &LPIT_1_ISR, NULL_PTR);
#else
    Platform_SetIrq(LPIT0_Ch1_IRQn, TRUE);
    Platform_InstallIrqHandler(LPIT0_Ch1_IRQn, &LPIT_0_CH_1_ISR, NULL_PTR);  
#endif
    /* Install EWM ISR */
    Platform_SetIrq(WDOG_EWM_IRQn, TRUE);
    Platform_InstallIrqHandler(WDOG_EWM_IRQn, &Wdg_Ipw_Isr, NULL_PTR);
#endif
#endif

#ifdef WDG_INSTANCE2
#if (WDG_INSTANCE2 == STD_ON)
    /* Install LPIT ISR */
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
    Platform_SetIrq(LPIT_IRQn, TRUE);
    Platform_InstallIrqHandler(LPIT_IRQn, &LPIT_2_ISR, NULL_PTR);
#else
    Platform_SetIrq(LPIT0_Ch2_IRQn, TRUE);
    Platform_InstallIrqHandler(LPIT0_Ch2_IRQn, &LPIT_0_CH_2_ISR, NULL_PTR);
#endif
    /* EAWDOG has no ISR */
#endif
#endif

    /* Initialize the Gpt driver */
    Gpt_Init(&Gpt_Config_VS_0);
    
    /* Enable the Gpt notification to periodically service the Wdg */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);
    
    /* Initialize the Wdg driver */
    Wdg_43_Instance0_Init(&Wdg_Config_0_VS_0);

    /* Set the Wdg Trigger Condition in order to periodically service the Wdg */
    Wdg_43_Instance0_SetTriggerCondition(1000);

    /*Change the Wdg mode of operation */
    Wdg_43_Instance0_SetMode(WDGIF_FAST_MODE);

    /* Set the Wdg Trigger Condition in order to periodically service the Wdg */
    Wdg_43_Instance0_SetTriggerCondition(1000);

    /* Test that the Wdg will not expire while it is services */
    for (uint32 index = 0; index < 10; index++)
    {
        delay(50000U);
        Wdg_43_Instance0_SetTriggerCondition(1000);
    }

    /* Disable the Wdg driver by changing the mode of operation to OFF_MODE */
    Wdg_43_Instance0_SetMode(WDGIF_OFF_MODE);

    /* Verify that Wdg timer is stopped after calling Wdg_43_Instance0_SetMode function */
    delay(5000000U);
    
#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
    
    /* Enable the Gpt notification to periodically service the Wdg */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_1);
    
    /* Initialize the Wdg driver */
    Wdg_43_Instance1_Init(&Wdg_Config_1_VS_0);
    
    /* Set the Wdg Trigger Condition in order to periodically service the Wdg */
    Wdg_43_Instance1_SetTriggerCondition(5);
    while(notificationCount == 0)
    {
        /* Wait for the interrupt */
    };
    /* Verify the callback setting a variable */
    DevAssert(notificationCount == 1);
#endif
#endif

#ifdef WDG_INSTANCE2
#if (WDG_INSTANCE2 == STD_ON)
    /* Initialize pins for LPSPI */
    Port_Init(NULL_PTR);    
    /* Configure LPSI in sync mode */
    Spi_Init(NULL_PTR);
    /* Initialize the Gpt driver */
    Ae_Init(NULL_PTR);
    /* Enable the Gpt notification to periodically service the Wdg */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_2);
    
    /* Initialize the Wdg driver */
    Wdg_43_Instance2_Init(&Wdg_Config_2_VS_0);

    Ae_ReadRegister(AEC_WDCFG_ADDR, AEC_DATAWIDTH_16, &regVal);
    /* Check if AeWdog is init suscessfuly */
    DevAssert(AEWDOG_WDGCFG_EXAMPLE_VAL == regVal);

    /* Test that the Wdg will not expire while it is services */
    for (uint32 index = 0; index < 10; index++)
    {
        Wdg_43_Instance2_SetTriggerCondition(100);
        delay(50000);
    }

    Ae_ReadRegister(AEC_WDCFG_ADDR, AEC_DATAWIDTH_16, &regVal);
    /* Check if AeWdog is not reset, The value of register is not set to default */
    DevAssert(AEWDOG_WDGCFG_EXAMPLE_VAL == regVal);

    /* Set the Wdg Trigger Condition in order to periodically service the Wdg */
    Wdg_43_Instance2_SetTriggerCondition(100);
    for(uint32 index = 0; index < 10; index++)
    {
    	delay(50000);
    }

    Ae_ReadRegister(AEC_WDCFG_ADDR, AEC_DATAWIDTH_16, &regVal);
    /* Check if AeWdog is reset, The value of register is set to default */
    DevAssert(AEWDOG_WDCFG_RESET_VAL == regVal);

#endif
#endif
    /* If all tests pass, it goes here because no Watchdog instances cause to reset MCU */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
