/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 4. 
 * Use a potentiometer to variate the PWM duty cycle connected to RGB led from 10% to 90% in steps of 10%.
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Platform.h"
#include "Osif.h"
#include "Adc.h"
#include "SEGGER_RTT.h"
#include "Pwm.h"

void EcuM_Init( void );
void Delay( uint32 ms );

/**
 * @brief This is the main function of the project
 * 
 * This is the main function of the project, it is the entry point of the program
 * 
 * @return Always zero
*/
int main( void )
{
    Adc_CalibrationStatusType CalibStatus;
    Adc_ValueGroupType    AdcReadGroupBuffer[2];
    Adc_ValueGroupType    ResultBuffer[2];

    uint16_t adcvalue1_Pot1 = 0;
    uint16_t adcvalue1_Pot2 = 0;

    uint8_t step;
    uint16_t dutyCycle;

    EcuM_Init();

    /* Intiliaze RTT library */
    SEGGER_RTT_Init();

    /* By default ADC0-CH8 is not connected to B13, but with this function
    it will, this is called Interleave, read RM page 1194*/
    Port_Ci_Port_Ip_SetMuxModeSel( IP_PORTB, 13, PORT_MUX_ADC_INTERLEAVE );

    /* Calibrate ADC module */
    Adc_Calibrate( AdcHwUnit_0, &CalibStatus );
    /* Set the memory buffer to store conversions */
    Adc_SetupResultBuffer(AdcGroup_0, ResultBuffer);

    //Not caring of using this RGB LEDs now, so OFF
    Pwm_SetPeriodAndDuty( PwmChannel_1, 37500, 0x8000 );
    Pwm_SetPeriodAndDuty( PwmChannel_2, 37500, 0x8000 );

    while( 1u )
    {
        /* Software trigger conversion */
        Adc_StartGroupConversion( AdcGroup_0 );
        /* Wait until the conversion is done */
        while( Adc_GetGroupStatus( AdcGroup_0 ) == ADC_BUSY );

        /* Read ready conversion */
        Adc_ReadGroup( AdcGroup_0, AdcReadGroupBuffer );

        adcvalue1_Pot1 = AdcReadGroupBuffer[AdcChannel_0];
        adcvalue1_Pot2 = AdcReadGroupBuffer[AdcChannel_1];

        //SEGGER_RTT_printf( 0, "Pot1 ADC value: %d, Pot2 ADC value: %d\n", adcvalue1_Pot1, adcvalue1_Pot2 );       

        /*
        Voltage Disclaimer:
        The NXP board microcontroller is VDD with 5V, but the Modular-S1 board (where the Potentiometers are located) 
        assumes is 3.3V. Well, the only inconvenient will be the ADC can ONLY sample UP TO 3.3V, but it takes 5V as Upper reference.
        So the ADC will never give the maximum value of 0xFFF in 12 bits or in any resolution.
        2^12 = 4,095 for 5V
        2^12 = 2,703 for 3.3V  <-- To use
        */
        
        /*  GENERAL DEFAULT VALUES FROM TRESOS CONFIG:
        ADC resolution is 12-bit (2^12) (0 to 2703).
        Default value for duty cycle of Pwm channel at initialization.
        - 0     (0x0)       represents for 0% duty cycle
        - 3277  (0xCCD)     represents for 10% duty cycle
        - 16384 (0x4000)    represents for 50% duty cycle
        - 29491 (0x7333)    represents for 90% duty cycle
        - 32768 (0x8000)    represents for 100% duty cycle
        */

        /*
        ************ METHOD 1: 10% to 90% WITHOUT steps of 10% (considering all values)   *************
        
        Map the ADC value from its range of 0-2703 (12-bit resolution) to the desired 
        PWM duty cycle range of 10% to 90%. It does this by:

        1. Scaling the ADC value to the span of the desired duty cycle.
        2. Normalizing it to fit within the 0% to 80% range.
        3. Shifting it by the minimum duty cycle to get the final value within 10% to 90%.
        
        This ensures a smooth and linear mapping from the ADC input to the PWM output, 
        allowing the potentiometer to control the LED brightness accurately within the desired range.
        
        dutyCycle = (adcValue * (MAX_DUTY_CYCLE - MIN_DUTY_CYCLE)) / RESOLUTION + MIN_DUTY_CYCLE;
        dutyCycle = (adcvalue1_Pot1 * (29491 - 3277)) / 2703 + 3277;
        */

        /*
        ************ METHOD 2: 10% to 90% WITH steps of 10%   *************
        
        1. Step Calculation: 
        The step variable determines which of the 9 duty cycle increments (10%, 20%, ..., 90%) 
        the current ADC value falls into. This maps the resolution 0-2703 (for 12-bit resolution) ADC range to 0-8 step range.

        step = (adcValue * NUM_STEPS) / ADC_MAX_VALUE;
        step = (adcvalue1_Pot1 * 9) / 2703;

        Components:
        - adcValue: The raw value read from the ADC. This value ranges from 0 to ADC_MAX_VALUE (2703 for a 12-bit ADC).
        - NUM_STEPS: The number of discrete steps we want to map to. In this case, it is 9, representing the duty cycles from 10% to 90% in increments of 10%.
        - ADC_MAX_VALUE: The maximum value the ADC can read. For a 12-bit ADC, this is 2703.

        2. Duty Cycle Calculation: 
        The dutyCycle variable is computed by scaling the step to the actual duty cycle range (3277 to 29491, representing 10% to 90%). 
        This ensures that the duty cycle increments in steps of approximately 10%.

        dutyCycle = MIN_DUTY_CYCLE + step * (MAX_DUTY_CYCLE - MIN_DUTY_CYCLE) / NUM_STEPS;
        dutyCycle = 3277 + step * (29491 - 3277) / 9;

        Components:
        - MIN_DUTY_CYCLE: The minimum duty cycle value (3277 for 10%).
        - MAX_DUTY_CYCLE: The maximum duty cycle value (29491 for 90%).
        - NUM_STEPS: The number of discrete duty cycle steps (9).
        - step: The current step index, calculated in the previous line.
        */

        // Using method 2 with Pot1
        step = (adcvalue1_Pot1 * 9) / 2703;
        dutyCycle = 3277 + step * (29491 - 3277) / 9;

        Pwm_SetPeriodAndDuty( PwmChannel_0, 37500, dutyCycle );

        SEGGER_RTT_printf( 0, "Step percentaje: %d, RGB Raw Duty Cycle: %d\n", 
        step*10, dutyCycle );  

        Delay( 500u );
    }

    return 0u;
}

/**
 * @brief This function initialize the microcontroller and the peripherals
 * 
 * it is just a temporary function, in the future this function will be replaced when the EcuM module 
 * is configured and implemented
*/
void EcuM_Init( void )
{
    /*Init Mcu module, including internal PLL, reference to Mcu Config structure can 
    be found at Mcu_PBcfg.h and PLL defines at Mcu_Cfg.h*/
    Mcu_Init( &Mcu_Config );
    Mcu_InitClock( McuClockSettingConfig_0 );
    Mcu_SetMode( McuModeSettingConf_0 );

    /*Init the internal tick reference Systick Timer*/
    OsIf_Init( NULL_PTR );
    /*Enable and setup interrupts*/
    Platform_Init( NULL_PTR );

    /*Apply all the Pin Port microcontroller configuration, for this case
    only Port Pin ADC0-SE5 (B1) and ADC0-SE8 (B13) */
    Port_Init( &Port_Config );

    /* Init the ADC with the paramters set in Tresos*/
    Adc_Init( &Adc_Config );

    Pwm_Init( &Pwm_Config );
}

/* This is dummy delay function prepared just for this example, in a real application 
no delay shall be used*/
void Delay( uint32 ms )
{
    uint32 Timeout = OsIf_MicrosToTicks( ms * 1000u, OSIF_COUNTER_SYSTEM );
    uint32 SeedTick = OsIf_GetCounter( OSIF_COUNTER_SYSTEM );
    uint32 ElapsedTime = 0u;
    do
    {
        ElapsedTime += OsIf_GetElapsed( &SeedTick, OSIF_COUNTER_SYSTEM );
    }while( ElapsedTime < Timeout );
}
