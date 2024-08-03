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
#include "Mcl.h"
#include "CDD_Rm.h"
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


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
int main(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"
static Spi_DataBufferType RxChBuf0[20];
static Spi_DataBufferType RxChBuf1[20];
#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"
static Spi_DataBufferType TxChBuf0[20] = {0,11,0,12,0,13,0,14,0,15,0,16,0,17,0,18,0,19,0,20};
static Spi_DataBufferType TxChBuf1[20] = {0,21,0,22,0,23,0,24,0,25,0,26,0,27,0,28,0,29,0,30};
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

/**
* @brief        Main function of the example
*/
int main(void)
{
    boolean Result = TRUE;
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

    /* Initialize Port driver */
    Port_Init(NULL_PTR);
    /* Initialize Interrupt */
    Platform_Init(NULL_PTR);
    /* Initialize Mcl for using Flexio and Dma */
    Mcl_Init(NULL_PTR);

    /* Initialize Rm */
    Rm_Init(NULL_PTR);

    /* Initialize Spi */
    Spi_Init(NULL_PTR);

    /* Using interrupt in transfer */
    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);

    /* Set up external buffer to transmission and reception */
    Spi_SetupEB(0u, TxChBuf0, RxChBuf0, 20u);

    /* Copy transmitted data to internal buffer */
    Spi_WriteIB(1u, TxChBuf1);

    /* This sequence of slave: transferring 10 frame 16 bits using Dma */
    Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_Slave);

    /* This sequence of master transferring 10 frame 16 bits using synchronous method*/
    Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_Master);

    while (SPI_SEQ_OK != Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_Slave));

    /* Read received buffer with data length configured in configuration tool */
    Spi_ReadIB(1u, RxChBuf1);

    for (Index = 0u; Index < 20u; Index++)
    {
        if (TxChBuf0[Index] != RxChBuf1[Index])
        {
            Result = FALSE;
            break;
        }
        if (TxChBuf1[Index] != RxChBuf0[Index])
        {
            Result = FALSE;
            break;
        }
    }

    Exit_Example(Result);

    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
