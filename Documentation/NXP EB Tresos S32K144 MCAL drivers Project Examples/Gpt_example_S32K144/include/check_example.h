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

#ifndef CHECK_EXAMPLE_H
#define CHECK_EXAMPLE_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

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


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Function used for testing automatically examples
* @details      Writes a pass or fail status in the memory at a given address
* @internal
*/
static inline void Exit_Example(boolean result) 
{
    volatile uint8 * testResultBasePtr;
    
    testResultBasePtr = (volatile uint8 *)VV_RESULT_ADDRESS;
    
    if (TRUE == result)
    {
        *testResultBasePtr = 0x5AU;
    }
    else
    {
        *testResultBasePtr = 0x33U;
    }
}

static inline void EX_ASSERT(boolean result) 
{
    volatile uint8 * testResultBasePtr;
    
    testResultBasePtr = (volatile uint8 *)VV_RESULT_ADDRESS;
    
    if (TRUE == result)
    {
        if(*testResultBasePtr != 0x33U)
        {
            *testResultBasePtr = 0x5AU;
        }
    }
    else
    {
        *testResultBasePtr = 0x33U;
    }
}

#ifdef __cplusplus
}
#endif

#endif 

/** @} */
