/*==================================================================================================
 *   Copyright 2020-2023 NXP Semiconductors
 *
 *   NXP Confidential. This software is owned or controlled by NXP and may only be
 *   used strictly in accordance with the applicable license terms. By expressly
 *   accepting such terms or by downloading, installing, activating and/or otherwise
 *   using the software, you are agreeing that you have read, and that you agree to
 *   comply with and are bound by, such license terms. If you do not agree to be
 *   bound by the applicable license terms, then you may not retain, install,
 *   activate or otherwise use the software.
==================================================================================================*/

/**
 *   @file          main.c
 *   @brief         This file contains sample code only. It is not part of the production code deliverables.
 *
 *   @addtogroup    main_module main module documentation
 *   @{
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
#include "Mem_43_INFLS.h"

#include "Mcu.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define EXAMPLE_NUMBER_OF_SECTORS      1U
#define EXAMPLE_SECTOR_SIZE            0x800U   /* 2K */
#define EXAMPLE_ERASE_SIZE             ( EXAMPLE_NUMBER_OF_SECTORS * EXAMPLE_SECTOR_SIZE )

#define EXAMPLE_SECTOR_START_ADDR      0x10000000U
#define EXAMPLE_BUFFER_SIZE            512U     /* byte */

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
#define MEM_43_INFLS_START_SEC_VAR_CLEARED_8
#include "Mem_43_INFLS_MemMap.h"

uint8 TxBuffer[EXAMPLE_BUFFER_SIZE];
uint8 RxBuffer[EXAMPLE_BUFFER_SIZE];

#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_8
#include "Mem_43_INFLS_MemMap.h"


#define MEM_43_INFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"

const Mem_43_INFLS_InstanceIdType Example_MemInstanceId = MEM_43_INFLS_INSTANCE_0_ID;

#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Example_CheckAssert(boolean Condition);
static void Example_InitBuffers(uint32 Length);
static void Example_VerifyBuffers(uint32 Length);

static void Example_ProcessJobs(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief Implement a simple assert macro
 *
 * @param  Condition
 * @return void
 */
static void Example_CheckAssert(boolean Condition)
{
    while (!Condition)
    {
        /* Stop here Loop forever */
    }
}

static void Example_InitBuffers(uint32 Length)
{
    uint32 Index;

    for (Index = 0U; Index < Length; Index++)
    {
        TxBuffer[Index] = (uint8)Index;
        RxBuffer[Index] = 0U;
    }
}

static void Example_VerifyBuffers(uint32 Length)
{
    uint32 Index;

    for (Index = 0U; Index < Length; Index++)
    {
        Example_CheckAssert(RxBuffer[Index] == TxBuffer[Index]);
    }

}

static void Example_ProcessJobs(void)
{
    Example_CheckAssert(MEM_43_INFLS_JOB_PENDING == Mem_43_INFLS_GetJobResult(Example_MemInstanceId));

    /* Polling until the driver is not busy */
    do
    {
        Mem_43_INFLS_MainFunction();
    }
    while ( MEM_43_INFLS_JOB_PENDING == Mem_43_INFLS_GetJobResult(Example_MemInstanceId) );

    Example_CheckAssert(MEM_43_INFLS_JOB_OK == Mem_43_INFLS_GetJobResult(Example_MemInstanceId));
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses the Mem Internal driver to erase, write, read and compare the memory
*/
int main(void)
{
    Std_ReturnType                  t_ReturnValue;
    Mem_43_INFLS_CompareConfigType  t_CompareCfg;
    Mem_43_INFLS_LengthType         t_CompareCfgLength;

    uint32 t_SectorStartAddr = EXAMPLE_SECTOR_START_ADDR;
    uint32 t_EraseSize       = EXAMPLE_ERASE_SIZE;
    uint32 t_BufferSize      = EXAMPLE_BUFFER_SIZE;

    /* Initialize buffers */
    Example_InitBuffers(t_BufferSize);

    /* Initialize the Mcu driver */
    Mcu_Init(&Mcu_Config_VS_0);

    /* Initialize the clock for the system */
    Mcu_InitClock(McuClockSettingConfig_0);

    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Mem Internal driver */
    Mem_43_INFLS_Init(NULL_PTR);
    Example_CheckAssert(NULL_PTR != Mem_43_INFLS_pConfigPtr);
    Example_CheckAssert(MEM_43_INFLS_JOB_OK == Mem_43_INFLS_GetJobResult(Example_MemInstanceId));

    /* Erase */
    t_ReturnValue = Mem_43_INFLS_Erase(Example_MemInstanceId, t_SectorStartAddr, t_EraseSize);
    Example_CheckAssert(E_OK == t_ReturnValue);
    Example_ProcessJobs();

    /* BlankCheck */
    t_ReturnValue = Mem_43_INFLS_BlankCheck(Example_MemInstanceId, t_SectorStartAddr, t_EraseSize);
    Example_CheckAssert(E_OK == t_ReturnValue);
    Example_ProcessJobs();

    /* Write */
    t_ReturnValue = Mem_43_INFLS_Write(Example_MemInstanceId, t_SectorStartAddr, TxBuffer, t_BufferSize);
    Example_CheckAssert(E_OK == t_ReturnValue);
    Example_ProcessJobs();

    /* Read */
    t_ReturnValue = Mem_43_INFLS_Read(Example_MemInstanceId, t_SectorStartAddr, RxBuffer, t_BufferSize);
    Example_CheckAssert(E_OK == t_ReturnValue);
    Example_ProcessJobs();

    /* Compare Config */
    t_CompareCfg.CompareAddr   = t_SectorStartAddr;
    t_CompareCfg.DataSourcePtr = TxBuffer;
    t_CompareCfg.Length        = t_BufferSize;
    t_CompareCfgLength         = sizeof(t_CompareCfg);

    /* Compare */
    t_ReturnValue = Mem_43_INFLS_HwSpecificService(Example_MemInstanceId, MEM_43_INFLS_HWSERVICEID_COMPARE, (uint8 *)&t_CompareCfg, &t_CompareCfgLength);
    Example_CheckAssert(E_OK == t_ReturnValue);
    Example_ProcessJobs();

    /* Compare data between Tx and Rx buffer */
    Example_VerifyBuffers(t_BufferSize);

    Mem_43_INFLS_DeInit();
    Example_CheckAssert(NULL_PTR == Mem_43_INFLS_pConfigPtr);


    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
