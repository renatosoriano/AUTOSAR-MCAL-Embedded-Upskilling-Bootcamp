/*==================================================================================================
*   Copyright 2022-2023 NXP Semiconductors
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
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Pwm.h"
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Mcl.h"
#include "Platform.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define NUM_BLINK_LED     (uint8)10U
#define DELAY_TIMER       (uint32)2000000U

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

volatile uint8 count_FlexIO_Irq;
volatile boolean toggle_led = FALSE;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

void TestDelay(uint32 delay);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void TestDelay(uint32 delay)
{
    static volatile uint32 DelayTimer = 0;
    while(DelayTimer<delay)
    {
        DelayTimer++;
    }
    DelayTimer=0;
}

/**
* @brief        FlexIO notification called by the configured channel periodically
* @details      Used to blink a led
*/
void FlexIO_Pwm_Notification(void)
{
    count_FlexIO_Irq++;
    if(count_FlexIO_Irq > 100)
    {
        toggle_led = TRUE;
        count_FlexIO_Irq = 0;
    }
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/**
* @brief        Main function of the example
* @details      Initialize the used drivers and uses the Pwm driver to control the led brightness
*               and blink this Led.
*/
int main(void)
{
    uint8 num_blink = 0U;
    uint8 pinValue_FlexIO = STD_LOW;
    count_FlexIO_Irq = 0U;

    /* Initialize the Mcu driver */
#if (STD_ON == MCU_PRECOMPILE_SUPPORT)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(&Mcu_Config_VS_0);
#endif
    /* Initialize the clock tree */
    Mcu_InitClock(McuClockSettingConfig_0);

    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Initialize all pins using the Port driver */
    Port_Init(&Port_Config_VS_0);

    /* Initialize Mcl driver */
    Mcl_Init(NULL_PTR);

    /* Initialize PWM driver */
    Pwm_Init(&Pwm_Config_VS_0);

    /* Set up check blink led for FTM */
    /* Set new period and duty cycle*/
    Pwm_SetPeriodAndDuty(PwmChannel_0, 0x5000, 0x2000);

    /* Decreasing LED brightness, using Pwm_SetDutyCycle*/
    Pwm_SetDutyCycle(PwmChannel_0, 0x7000);

    /* Increasing LED brightness, using Pwm_SetDutyCycle*/
    Pwm_SetDutyCycle(PwmChannel_0, 0x200);

    /* Using duty cycle 0% and 100% to Blink LED */
    while(num_blink < NUM_BLINK_LED)
    {
        /* Led on when duty cycle is 0% */
        Pwm_SetDutyCycle(PwmChannel_0, 0x0000);
        TestDelay(DELAY_TIMER);

        /* Led off when duty cycle is 100% */
        Pwm_SetDutyCycle(PwmChannel_0, 0x8000);
        TestDelay(DELAY_TIMER);
        num_blink++;
    }

    /* Set up check blink led for FlexIO */
    /* Set new period and duty cycle */
    Pwm_SetPeriodAndDuty(PwmChannel_1, 500U, 0x4000);

    /* Enable the PWM signal edge notification */
    Pwm_EnableNotification(PwmChannel_1, (Pwm_EdgeNotificationType)PWM_RISING_EDGE);

    /* Reset num_blink variable */
    num_blink = 0U;

    while(num_blink < NUM_BLINK_LED)
    {
        if(toggle_led){
            pinValue_FlexIO = (STD_LOW == pinValue_FlexIO) ? STD_HIGH : STD_LOW;
            if(pinValue_FlexIO == STD_LOW){
                num_blink++;
            }
            Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, pinValue_FlexIO);
            TestDelay(DELAY_TIMER);
            toggle_led = FALSE;
        }
    }



    /* De-initialize the PWM module. */
    Pwm_DeInit();

    Exit_Example(TRUE);

    return (0);
}

#ifdef __cplusplus
}
#endif

/** @} */
