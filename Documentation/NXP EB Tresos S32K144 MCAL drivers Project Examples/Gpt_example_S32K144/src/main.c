/*
*   Copyright 2020-2022 NXP
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
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Platform.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* time-out period - equivalent to 1s */
#define TIMEOUT_PERIOD 4800000

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
static volatile uint8 toggleLedLpit = 0U;
static volatile uint8 toggleLedFtm = 0U;
volatile uint8 pinValue0 = 0U;
volatile uint8 pinValue1 = 0U;
volatile uint16 index1 = 0U;
volatile uint16 index2 = 0U;
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
* @brief        Gpt notification called by the configured channel periodically
* @details      Used to blink a led
*/
void Gpt_LpitNotification(void)
{
    ++index1;
    if (index1 == 10U)
    {
    	/*Blink a RGB_LED*/
    	 toggleLedLpit = 1U;
    	 index1 = 0U;
    }

}

void Gpt_FtmNotification(void)
{
    ++index2;
    if (index2 == 3000U)
    {
    	/*Blink a RGB_LED*/
    	 toggleLedFtm = 1U;
    	 index2 = 0U;
    }

}

/**
* @brief        LPIT_0 Interrupt handler
* @details      Defined in Lpit_Gpt_Ip.c
*/
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
extern ISR(LPIT_0_ISR);
#else
extern ISR(LPIT_0_CH_0_ISR);
#endif

/**
* @brief        FTM_0 Interrupt handler
* @details      Defined in Ftm_Gpt_Ip.c
*/
#if (FTM_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
extern ISR(FTM_0_ISR);
#else
ISR(FTM_0_CH_0_CH_1_ISR);
#endif


/**
* @brief        Main function of the example
* @details      Initialize the used drivers and uses the Gpt
*               and Dio drivers to toggle a LED periodically
*/
int main(void)
{
    uint8 channel = 0U;

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    /* Initialize the clock tree */
    Mcu_InitClock(McuClockSettingConfig_0);
    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);
    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);
    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Initialize the Gpt driver */
    Gpt_Init(NULL_PTR);
    
    for(channel = 0U; channel < GPT_HW_CHANNEL_NUM; ++channel)
    {
        /* Start the Gpt timer */
        Gpt_StartTimer(channel, TIMEOUT_PERIOD);
        /* Enable the Gpt notification to get the event for toggling the LED periodically */
        Gpt_EnableNotification(channel);
    }
    
    while (TRUE)
    {
        /* Toggle the RGB_LED when the Gpt notification is called */
        if (toggleLedLpit == 1U)
        {
            pinValue0 = pinValue0 ^ 1U;
            /* Toggle led */
            Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, pinValue0);
            toggleLedLpit = 0U;
        }

        /* Toggle the RGB_LED when the Gpt notification is called */
        if (toggleLedFtm == 1U)
        {
            pinValue1 = pinValue1 ^ 1U;
            /* Toggle led */
            Dio_WriteChannel(DioConf_DioChannel_DioChannel_1, pinValue1);
            toggleLedFtm = 0U;
        }

    }

    /* Stop the Gpt timer */
    Gpt_StopTimer(channel);
    Exit_Example(TRUE);

    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
