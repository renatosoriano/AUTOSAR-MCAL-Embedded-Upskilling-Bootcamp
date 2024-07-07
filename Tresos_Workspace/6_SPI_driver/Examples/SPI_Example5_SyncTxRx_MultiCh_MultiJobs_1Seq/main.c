/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 5. 
 * The example is almost identical to the second one, we write four bytes then we read them, the difference is the way we 
 * set the channels, assigning one for eeprom commands, one for Address in 16 bits long, and the channels for the data.
 * We use jobs to set the channels in the desired order and the we create sequence for writing and reading.
 * Please notice the use of NULL pointer when there is no need to specify buffer for Tx or Rx.
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
    Spi_DataBufferType TxBuffer[4] = { 0x00, 0x01, 0x02, 0x03 };
    Spi_DataBufferType RxBuffer[4];
    uint8 Wren, Cmd;
    uint16 Address;

    EcuM_Init();
    SEGGER_RTT_Init();

    /*Enable writing instructions in the eeprom memory by sending a 0x06
    and send it in the first Job*/
    Wren = 0x06;
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Wren, &Wren, NULL, 1 );
    /*Set up the buffer for the Write command + Memory Address and four bytes of data
    in the second job*/
    Cmd = 0x02;                 /*WREN Instruction value*/
    Address = 0x00A0;       /*Memory address to write data*/    
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Cmd, &Cmd, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Addr, (Spi_DataBufferType*)&Address, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Data, TxBuffer, NULL, 4 );
    /*Send the data to the eeprom memory, two jobs*/
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_Write );

    /*Wait for the data to be recorded in memory, it is not the best way to
    do it, so it's just for demonstration purposes*/
    Delay( 5 );

    /*Set up the buffer with the read command + address to read and the buffer to store
    the read data in one job*/
    Cmd = 0x03;                 /*READ Instruction value*/
    Address = 0x00A0;           /*Memory address to read data*/
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Cmd, &Cmd, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Addr, (Spi_DataBufferType*)&Address, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_Data, NULL, RxBuffer, 4 );
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_Read );

    //SEGGER_RTT_printf(0, "Data read from eeprom 1: %x\n", RxBuffer[0] );
    SEGGER_RTT_printf(0, "Data read from eeprom 1 - RxBuffer[0]: 0x%x\n", RxBuffer[0] );
    SEGGER_RTT_printf(0, "Data read from eeprom 1 - RxBuffer[1]: 0x%x\n", RxBuffer[1] );
    SEGGER_RTT_printf(0, "Data read from eeprom 1 - RxBuffer[2]: 0x%x\n", RxBuffer[2] );
    SEGGER_RTT_printf(0, "Data read from eeprom 1 - RxBuffer[3]: 0x%x\n", RxBuffer[3] );


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
