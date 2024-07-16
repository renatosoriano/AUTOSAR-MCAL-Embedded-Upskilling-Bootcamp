/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * This file contains the main function of the project, it is the entry point of the program
 * it contains a simple program that toggles a pin of the microcontroller
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Osif.h"

void EcuM_Init( void );

/**
 * @brief This is the main function of the project
 * 
 * This is the main function of the project, it is the entry point of the program
 * 
 * @return Always zero
*/
int main( void )
{
    EcuM_Init();

    /* Get the number of ticks corresponding to 500ms, the resolution will depend
    on the frequency feeding the systick timer, in this case with a freq of
    48MHz we could have up to 20ns, but the function only accepts microseconds*/
    uint32 Timeout_500ms = OsIf_MicrosToTicks( 500000u, OSIF_COUNTER_SYSTEM );

    /*get the Systic Timer count for the first time*/
    uint32 SeedTick = OsIf_GetCounter( OSIF_COUNTER_SYSTEM );

    /*We need to count the elapsed time from zero*/
    uint32 ElapsedTime = 0u;

    while( 1u )
    {
        /* Get the elapsed time count from the seed tick value*/
        ElapsedTime += OsIf_GetElapsed( &SeedTick, OSIF_COUNTER_SYSTEM );
        /* Query if the elapsed time is already equal or bigger than the timeout*/
        if( ElapsedTime >= Timeout_500ms )
        {
            /*reset the elapsed time */
            ElapsedTime = 0u;
            /*toggle led*/
            Dio_FlipChannel( DioConf_DioChannel_DioChannel_0 );
        }
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

    /*Apply all the Pin Port microcontroller configuration, for this case
    only Port Pin 122 (D16) is configured as output*/
    Port_Init( &Port_Config );
}
