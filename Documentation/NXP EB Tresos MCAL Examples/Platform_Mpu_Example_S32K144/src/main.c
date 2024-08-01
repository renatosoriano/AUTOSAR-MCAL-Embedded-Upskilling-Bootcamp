/*
*   (c) Copyright 2020 NXP
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
#include "sys_init.h"
#include "Platform.h"
#include "CDD_Mcl.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define DATA_LENGTH                         (16U)

#define DMA_CH0_CONFIG_LIST_DIMENSION      ((uint32)2U)
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
__attribute__(( aligned(16) )) uint8 Src_data[DATA_LENGTH]  = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
__attribute__(( aligned(16) )) uint8 Dest_data[DATA_LENGTH] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS

==================================================================================================*/
Mcl_DmaChannelTransferListType DmaCh0_TransferList[DMA_CH0_CONFIG_LIST_DIMENSION] =
{
    {MCL_DMA_CH_SET_SOURCE_ADDRESS, (uint32)&Src_data[0U]},
    {MCL_DMA_CH_SET_DESTINATION_ADDRESS, (uint32)&Dest_data[0U]},
};

void PerformDmaTransfer(void)
{
    /* Clear error for Channel 0 */
    Mcl_SetDmaChannelCommand(DMA_LOGIC_CH_0, MCL_DMA_CH_ACK_ERROR);
    /* Set Logic Channel 0 -> Source and Destination Address */
    Mcl_SetDmaChannelTransferList(DMA_LOGIC_CH_0, DmaCh0_TransferList, DMA_CH0_CONFIG_LIST_DIMENSION);
    /* Start transfer for logic Channel 0 */
    Mcl_SetDmaChannelCommand(DMA_LOGIC_CH_0, MCL_DMA_CH_START_SERVICE);
}

void ClearData(void)
{
    uint16 i;
    for( i=0; i< DATA_LENGTH; i++)
    {
        Dest_data[i] = 0U;
    }
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Example uses PLATFORM_init to initialize regions for the MPU and uses DMA to perform data transfers from the source array to the destination array.               
*               Depending on the permission of PLATFORM, the data transfer is successful or not.
*               The steps are as follows:
*                 - Declare variables
*                 - Call sys_init() to initialize clock
*                 - Call Platform_Init to initialize 3 regions, with 3 regions configured as follows:
*                   - Region 0: Disable DMA (not allow to read/write in user mode/supervisor mode)
*                   - Region 1: Only-read permission for DMA (allow to read in user mode/supervisor mode)
*                   - Region 2: Only-write permission for DMA (allow to write in user mode/supervisor mode)
*                 - Perform DMA transfer.
*                 - Verification Point: DMA transfer successfully
*                 - Call Platform_Mpu_EnableRegion to disable 2 regions. DMA has not read/write permission
*                 - Perform DMA transfer.
*                 - Verification Point: DMA transfer failed
*                 - Call Platform_Mpu_GetErrorDetails to get error information
*                 - Verification Point: check correct error information
*                 - Call Platform_Mpu_EnableRegion to enable region 1. DMA has only-read permission
*                 - Perform DMA transfer.
*                 - Verification Point: DMA transfer failed
*                 - Call Platform_Mpu_GetErrorDetails to get error information
*                 - Verification Point: check correct error information
*                 - Call Platform_Mpu_EnableRegion to enable region 2. DMA has read/write permission
*                 - Perform DMA transfer.
*                 - Verification Point: DMA transfer successfully
*                 - Exit example
*/

int main(void)
{
    uint16 i;
    Platform_Mpu_ErrorDetailsType ErrorDetails;
    boolean Status = TRUE;

    /* Initialize the clock */
    sys_init();

    /* Initialize PLATFORM, DMA has read/write permission */
    Platform_Init(NULL_PTR);
   
    /* Initialize MCL Driver */
    Mcl_Init(NULL_PTR);
    
    /* Use DMA to transfer data from array Src_data to Dest_data */
    PerformDmaTransfer();
    
    /* Check data is transfered successfully */
    for( i=0; i< DATA_LENGTH; i++)
    {
        if(Dest_data[i] != Src_data[i])
        {
            Status = FALSE;
        }
    }

    /* Clear data after checking */
    ClearData();

    /* Disable region 1, 2 that mean disable read and write permission of DMA master */
    Platform_Mpu_EnableRegion(1, (boolean)FALSE);
    Platform_Mpu_EnableRegion(2, (boolean)FALSE);

    PerformDmaTransfer();
    /* Check transferred data failed */
    for( i=0; i< DATA_LENGTH; i++)
    {
        if(Dest_data[i] != 0U)
        {
            Status = FALSE;
        }
    }

    /* Get error details */
    (void)Platform_Mpu_GetErrorDetails(&ErrorDetails);
    if( ( MPU_MASTER_DMA      != ErrorDetails.eMaster )    |  \
        ( (uint32)(&Src_data) != ErrorDetails.u32Address ) |  \
        ( MPU_ACCESS_READ     != ErrorDetails.eErrorAccess) )
    {
        Status = FALSE;
    }

    /* Enable region 1, DMA has read permission */
    Platform_Mpu_EnableRegion(1, (boolean)TRUE);

    PerformDmaTransfer();
    /* Check transferred data failed */
    for( i=0; i< DATA_LENGTH; i++)
    {
        if(Dest_data[i] != 0U)
        {
            Status = FALSE;
        }    
    }

    /* Get error details */
    (void)Platform_Mpu_GetErrorDetails(&ErrorDetails);
    if( ( MPU_MASTER_DMA      != ErrorDetails.eMaster )    |  \
        ( (uint32)(&Dest_data) != ErrorDetails.u32Address ) |  \
        ( MPU_ACCESS_WRITE     != ErrorDetails.eErrorAccess) )
    {
        Status = FALSE;
    }

    /* Enable region 2, DMA has write permission. Now. DMA can transfer data successfully */
    Platform_Mpu_EnableRegion(2, (boolean)TRUE);

    PerformDmaTransfer();
    /* Check data is transfered successfully */
    for( i=0; i< DATA_LENGTH; i++)
    {
        if(Dest_data[i] != Src_data[i])
        {
            Status = FALSE;
        }    
    }

    Exit_Example(Status);
}


#ifdef __cplusplus
}
#endif

/** @} */
