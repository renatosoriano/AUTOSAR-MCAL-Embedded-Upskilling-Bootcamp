/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 1. 
 * Write a program to read and display the first 32 bytes of an eeprom in ASCII characters using Semihosting with RTT, 
 * you are free to chose the format of each number.
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Platform.h"
#include "Osif.h"
#include "Spi.h"
#include "SEGGER_RTT.h"

void EcuM_Init( void );
void Delay( uint32 ms );

/*this is dummy delay function prepare just for this example, in a real application 
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

/**
 * @brief This is the main function of the project
 * 
 * This is the main function of the project, it is the entry point of the program
 * 
 * @return Always zero
*/
int main( void )
{
    Spi_DataBufferType RxBuffer[32];
    uint8 Cmd;
    uint16 Address;

    EcuM_Init();
    SEGGER_RTT_Init();

    /*Set up the buffer with the read command + address to read and the buffer to store
    the read data in one job*/
    for(uint8 i=0; i<32; i++ )
    {
        Cmd = 0x03;                 /*READ Instruction value*/
        Address = i;           /*Memory address to read data*/
        Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Cmd, &Cmd, NULL, 1 );
        Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Addr, (Spi_DataBufferType*)&Address, NULL, 1 );
        Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Data, NULL, RxBuffer, 32 );
        Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_Read );

        /* From EEPROM 25AA320A USER MANUAL:
        The data stored in the memory at the next address can be read sequentially 
        by continuing to provide clock pulses. The internal Address Pointer is automatically 
        incremented to the next higher address after each byte of data are shifted out. 
        When the highest address is reached (0FFFh), the address counter rolls over to 
        address 0000h allowing the read cycle to be continued indefinitely.
        */

        // For that reason, only RxBuffer[0] is needed, will shift to the next value every cycle.
        SEGGER_RTT_printf(0, "Byte: %d - Address: 0x%x - RxBuffer[%d] in Hex: 0x%x, in Dec: %d \n", i, Address, i, RxBuffer[0], RxBuffer[0] );  
        
        // For testing:
        //SEGGER_RTT_printf(0, "Byte: %d - Address: 0x%x - RxBuffer[%d] in Hex: 0x%x, in Dec: %d, in ASCII: %c \n", i, Address, i, RxBuffer[0], RxBuffer[0], RxBuffer[0] ); 

    }

    while( 1u )
    {
        Delay( 10u );
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
    /*enable and setup interrupts*/
    Platform_Init( NULL_PTR );

    /*Apply all the Pin Port microcontroller configuration, for this case
    only Port Pin 122  (D16) is configured as output*/
    Port_Init( &Port_Config );

    /*init the FlexCAN0 with the paramters set in Tresos in loop back mode*/
    Spi_Init( &Spi_Config );
}
