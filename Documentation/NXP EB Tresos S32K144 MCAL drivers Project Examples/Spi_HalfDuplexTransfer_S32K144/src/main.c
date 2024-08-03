/*
*   Copyright 2020 NXP
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
#include "Spi.h"
#include "Platform.h"
#include "Port.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"
static Spi_DataBufferType RxMasterBuffer[10];
static Spi_DataBufferType RxSlaveBuffer[10];
#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"
static Spi_DataBufferType TxMasterBuffer[10] = {11,12,13,14,15,16,17,18,19,20};
static Spi_DataBufferType TxSlaveBuffer[10] = {21,22,23,24,25,26,27,28,29,30};
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

int main(void)
{
    boolean Result = TRUE;
    Spi_SequenceType SeqStatus;
    uint32 Count = 0xFFFFFF;
    uint8 Index;

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_Default);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

    /* Install interrupt handlers using the Platform driver */
    Platform_Init(NULL_PTR);

    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);

    /* Initialize Spi */
    Spi_Init(NULL_PTR);

    /* Setup operation mode for Spi_AsyncTransmit */
    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);

    /* Set up external buffer to transmission and reception */
    Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_0, TxMasterBuffer, RxMasterBuffer, 10u);
    Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_1, TxSlaveBuffer, RxSlaveBuffer, 10u);

    /* setup SLAVE sequence */
    Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_Slave);
    /* setup MASTER sequence */
    Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_Master);

    do
    {
        SeqStatus = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_Master);
        Count--;
    }
    while ((Count > 0u) && (SeqStatus != SPI_SEQ_OK));

    if (0u == Count)
    {
        Result = FALSE;
    }
    Count = 0xFFFFFF;
    do
    {
        SeqStatus = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_Slave);
        Count--;
    }
    while ((Count > 0u) && (SeqStatus != SPI_SEQ_OK));
    
    if (0u == Count)
    {
        Result = FALSE;
    }

    /* Verify data after transfer from MASTER to SLAVE */
    for (Index = 0; Index < 10; Index++)
    {
        if (TxMasterBuffer[Index] != RxSlaveBuffer[Index])
        {
            Result = FALSE;
            break;
        }
    }

    Exit_Example(Result);
}


#ifdef __cplusplus
}
#endif

/** @} */
