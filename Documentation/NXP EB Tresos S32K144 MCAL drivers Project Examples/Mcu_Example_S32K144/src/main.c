/*
*   Copyright 2022 NXP
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

/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary configuration files. */
#include "Mcal.h"
#include "Mcu.h"
#include "check_example.h"

#define CLOCKOUT_FREQ_CFG_0   16000000U
#define CLOCKOUT_FREQ_CFG_1   6000000U

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    boolean Result = TRUE;

#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config_VS_0);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */

    Mcu_InitClock(McuClockSettingConfig_0);

#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();
#endif


    Mcu_SetMode(McuModeSettingConf_0);

    if (Mcu_GetClockFrequency(CLKOUT0_CLK) != CLOCKOUT_FREQ_CFG_0)
    {
        Result = FALSE;
    }

    Mcu_InitClock(McuClockSettingConfig_1);

    if (Mcu_GetClockFrequency(CLKOUT0_CLK) != CLOCKOUT_FREQ_CFG_1)
    {
        Result = FALSE;
    }

    Exit_Example(Result);
    return (0U);
}

/* END main */
/*!
** @}
*/
