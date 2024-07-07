/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 2. 
 * The following example just show how to transmit data to one of the eeprom in the board, one single byte will be written 
 * and read again to be displayed using printf statement. Notice we only configure one single channel, job and sequence 
 * for all the operations.
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
    Spi_DataBufferType TxBuffer[4];
    Spi_DataBufferType RxBuffer[4];

    EcuM_Init();
    SEGGER_RTT_Init();

    /*Enable writing instructions in the eeprom memory by sending a 0x06*/
    TxBuffer[0] = 0x06;                                 /*WREN Instruction value*/
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_0, TxBuffer, NULL, 1 );
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_0 );

    /*Send to write the value 0x37 in the address 0 of the memory*/
    TxBuffer[0] = 0x02;             /*Write instruction */
    TxBuffer[1] = 0x00;             /*16 bit - address  */
    TxBuffer[2] = 0x00;             /*16 bit - address  */
    TxBuffer[3] = 0x37;             /*Data byte         */
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_0, TxBuffer, NULL, 4 );
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_0 );

    /*Wait for the data to be recorded in memory, it is not the best way to
    do it, so it's just for demonstration purposes*/
    Delay( 5 );

    /*Read a single byte from direccion 0x00 of eeprom memory, we need to transmit first
    the read instruction plus the address to read*/
    TxBuffer[0] = 0x03;             /*Read instruction */
    TxBuffer[1] = 0x00;             /*16 bit - address  */
    TxBuffer[2] = 0x00;             /*16 bit - address  */
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_0, TxBuffer, RxBuffer, 4 );
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_0 );

    /*Display data read it*/
    SEGGER_RTT_printf(0, "Data read from eeprom: 0x%X\n", RxBuffer[3] );

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
