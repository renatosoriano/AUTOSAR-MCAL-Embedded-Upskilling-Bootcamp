/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 4. 
 * This is similar to previous example but this time we perform the same operations in each eeprom, one after the other memory. 
 * This is to demonstrate how one single sequence is necessary instead of duplicate sequences. 
 * Two jobs are attached to the only sequence we have but it is necessary two buffers, one for each job.
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
    Spi_DataBufferType TxBuffer1[4];
    Spi_DataBufferType TxBuffer2[4];
    Spi_DataBufferType RxBuffer1[4];
    Spi_DataBufferType RxBuffer2[4];

    EcuM_Init();
    SEGGER_RTT_Init();

    /*Enable writing instructions in the eeprom memories by sending a 0x06*/
    TxBuffer2[0] = TxBuffer1[0] = 0x06;          /*WREN Instruction value*/
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_0, TxBuffer1, NULL, 1 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_1, TxBuffer2, NULL, 1 );
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_0 );

    /*Send to write the value 0x35 in the address 0 of the memory*/
    TxBuffer2[0] = TxBuffer1[0] = 0x02;                 /*Write instruction */
    TxBuffer2[1] = TxBuffer1[1] = 0x00;                 /*16 bit - address  */
    TxBuffer2[2] = TxBuffer1[2] = 0x00;                 /*16 bit - address  */
    TxBuffer1[3] = 0x38;                                /*Data byte         */
    TxBuffer2[3] = 0x39;                                /*Data byte         */
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_0, TxBuffer1, NULL, 4 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_1, TxBuffer2, NULL, 4 );
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_0 );

    /*Wait for the data to be recorded in memory, it is not the best way to
    do it, so it's just for demonstration purposes*/
    Delay( 10 );

    /*Read a byte from direccion 0x00 of each eeprom memory, TransmitReceive() Function needs as parameters structure
    to handle SPI , buffer where data to transmit is stored, buffer where data received is stored, total amount
    of bytes to transmit and receive*/
    TxBuffer2[0] = TxBuffer1[0] = 0x03; 
    TxBuffer2[1] = TxBuffer1[1] = 0x00; 
    TxBuffer2[2] = TxBuffer1[2] = 0x00;
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_0, TxBuffer1, RxBuffer1, 4 );
    Spi_SetupEB( SpiConf_SpiChannel_SpiChannel_1, TxBuffer2, RxBuffer2, 4 );
    Spi_SyncTransmit( SpiConf_SpiSequence_SpiSequence_0 );
    
    SEGGER_RTT_printf(0, "Data read from eeprom 1: 0x%x\n", RxBuffer1[3] );
    SEGGER_RTT_printf(0, "Data read from eeprom 2: 0x%x\n", RxBuffer2[3] );


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
