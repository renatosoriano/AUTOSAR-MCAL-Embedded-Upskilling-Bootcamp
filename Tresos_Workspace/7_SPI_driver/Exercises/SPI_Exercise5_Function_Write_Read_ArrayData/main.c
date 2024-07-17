/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 5. 
 * Write the following functions to allow to write a given array of n number of bytes starting at any address of the eeprom:
 *         void write_data( uint16 addr, uint8 *data, uint8 size );
 *         void read_data( uint16 addr, uint8 *data, uint8 size );
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
void write_byte( uint16 addr, uint8 *data );
uint8 read_byte( uint16 addr );
void write_data( uint16 addr, uint8 *data, uint8 size );
void read_data( uint16 addr, uint8 *data, uint8 size );

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
    Spi_DataBufferType TxBuffer[4] = { 0x00, 0x01, 0x02, 0x03 };
    Spi_DataBufferType RxBuffer[4];
    uint16 Address = 0x0009;
    uint16 sizeTX = sizeof(TxBuffer);
    uint16 sizeRX = sizeof(RxBuffer);

    EcuM_Init();
    SEGGER_RTT_Init();

    write_data( Address, TxBuffer, sizeTX );

    /*Wait for the data to be recorded in memory, it is not the best way to
    do it, so it's just for demonstration purposes*/
    Delay( 5 );

    read_data( Address, RxBuffer, sizeRX );

    for(uint8 i = 0; i < sizeRX ; i++)
    {
        SEGGER_RTT_printf(0, "Data from eeprom 1: 0x%x, Address: 0x%x\n", RxBuffer[i], Address+i );
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

void write_byte( uint16 addr, uint8 *data )
{
    uint8 Wren, Cmd;

    /*Enable writing instructions in the eeprom memory by sending a 0x06
    and send it in the first Job*/
    Wren = 0x06;                //WREN: 0000 0110 - Set the write enable latch (enable write operations)
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Wren, &Wren, NULL, 1 );

    /*Set up the buffer for the Write command + Memory Address and four bytes of data
    in the second job*/
    Cmd = 0x02;                 //WRITE: 0000 0010 - Write data to memory array beginning at selected address
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Cmd, &Cmd, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Addr, (Spi_DataBufferType*)&addr, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Data, data, NULL, 1 );
    /*Send the data to the eeprom memory, two jobs*/
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_Write );
}

uint8 read_byte( uint16 addr )
{
    uint8 Cmd;
    Spi_DataBufferType buffer[1];

    /*Set up the buffer with the read command + address to read and the buffer to store
    the read data in one job*/
    Cmd = 0x03;                 //READ: 0000 0011 - Read data from memory array beginning at selected address
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Cmd, &Cmd, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Addr, (Spi_DataBufferType*)&addr, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Data, NULL, buffer, 1 );
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_Read );
    SEGGER_RTT_printf(0, "[Debug] Data read from eeprom 1 - RxBuffer[0]: 0x%x\n", buffer[0] );
    return buffer[0];
}

void write_data( uint16 addr, uint8 *data, uint8 size )
{
    uint8 Wren, Cmd;

    /*Enable writing instructions in the eeprom memory by sending a 0x06
    and send it in the first Job*/
    Wren = 0x06;                //WREN: 0000 0110 - Set the write enable latch (enable write operations)
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Wren, &Wren, NULL, 1 );

    /*Set up the buffer for the Write command + Memory Address and four bytes of data
    in the second job*/
    Cmd = 0x02;                 //WRITE: 0000 0010 - Write data to memory array beginning at selected address
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Cmd, &Cmd, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Addr, (Spi_DataBufferType*)&addr, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Data, data, NULL, size );
    /*Send the data to the eeprom memory, two jobs*/
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_Write );
}
void read_data( uint16 addr, uint8 *data, uint8 size )
{
    uint8 Cmd;

    /*Set up the buffer with the read command + address to read and the buffer to store
    the read data in one job*/
    Cmd = 0x03;                 //READ: 0000 0011 - Read data from memory array beginning at selected address
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Cmd, &Cmd, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Addr, (Spi_DataBufferType*)&addr, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Data, NULL, data, size );
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_Read );
    for(uint8 i = 0; i < size ; i++)
    {
        SEGGER_RTT_printf(0, "[Debug] Data read from eeprom 1 - RxBuffer[%d]: 0x%x\n", i, data[i] );

    }
}
