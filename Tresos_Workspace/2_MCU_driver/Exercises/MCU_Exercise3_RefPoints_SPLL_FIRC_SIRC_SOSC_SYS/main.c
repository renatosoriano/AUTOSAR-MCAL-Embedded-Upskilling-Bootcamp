/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 3. 
 * Sets reference points for SPLLDIVn_CLK, FIRCDIVn_CLK, SIRCDIVn_CLK, SOSCDIVn_CL and SYS_CLK.
 * 
 * From Reference manual Section 27.4 Internal clocking requirements:
 *      -  Run CORE Clock Frequency: the CPU Frequency shall be at maximum of 80 MHz (normal RUN mode) or 112 MHz (HSRUN mode).
 *      -  Run SYSTEM Clock Frequency: the CPU Frequency shall be at maximum of 80 MHz (normal RUN mode) or 112 MHz (HSRUN mode).
 *      -  Run BUS Clock Frequency: the CPU Frequency shall be at maximum of 48 MHz (normal RUN mode) or 56 MHz (HSRUN mode) or 40 MHz (when using PLL as system clock source).
 *      -  Run FLASH Clock Frequency: the CPU Frequency shall be at maximum of 26.67 MHz (normal RUN mode) or 28 MHz (HSRUN mode).
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"

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

    while( 1u )
    {

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
    /* Busy wait until the System PLL is locked */
    while(MCU_PLL_LOCKED != Mcu_GetPllStatus());
    Mcu_DistributePllClock();
    Mcu_SetMode( McuModeSettingConf_0 );
    /*Apply all the Pin Port microcontroller configuration, for this case
    only Port Pin 122  (D16) is configured as output*/
    Port_Init( &Port_Config );
}
