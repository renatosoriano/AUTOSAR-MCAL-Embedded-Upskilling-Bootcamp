/*
*   Copyright 2021 NXP
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
#include "Adc.h"
#include "Mcu.h"
#include "Mcl.h"
#include "CDD_Rm.h"
#include "Platform.h"

#include "check_example.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Voltage level definition */
#define RESULT_ADC_VREFL        (0u)        /* VrefL is 0V */
#define RESULT_ADC_VREFH        (4096u)     /* VrefH is 5V */
#if ( defined(S32M242) || defined(S32M244) )
  #define RESULT_ADC_BANDGAP    (1241U) /* Vbandgap ~ 1.0V at 3.3V reference */
#elif defined(S32K148)
  #define RESULT_ADC_BANDGAP    (1200u) /* Vbandgap ~ 1.45V at 5V reference */
#else
  #define RESULT_ADC_BANDGAP    (819u)  /* Vbandgap ~ 1V at 5.0V reference */
#endif
#define RESULT_TOLERANCE        (150u)

#define NUM_RESULTS             (4u)
/*==================================================================================================
*                                      EXTERN DECLARATIONS
==================================================================================================*/
extern ISR(Adc_0_Isr);
extern ISR(Dma0_Ch1_IRQHandler);

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
Adc_ValueGroupType    ResultBuffer[NUM_RESULTS] =  {0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa};
/* Used for ReadGroup */
Adc_ValueGroupType    AdcReadGroupBuffer[NUM_RESULTS] =  {0xbbbb, 0xbbbb, 0xbbbb, 0xbbbb};
Adc_ValueGroupType    AdcReadGroupBufferDma[NUM_RESULTS] =  {0xbbbb, 0xbbbb, 0xbbbb, 0xbbbb};
const uint32 AdcExpectedValue[3] = {RESULT_ADC_VREFH, RESULT_ADC_BANDGAP, RESULT_ADC_VREFL};

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Adc_MemMap.h"
__attribute__(( aligned(32) )) Adc_ValueGroupType    ResultBufferDma[NUM_RESULTS] =  {0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa};
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Adc_MemMap.h"

volatile uint32 VarNotification_0 = 0;
volatile uint32 VarNotification_1 = 0;
volatile uint32 VarNotification_2 = 0;
volatile uint32 VarNotification_3 = 0;

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

boolean CheckResult(uint32 Result, uint32 Reference, uint32 Tolerance)
{
    boolean Status = FALSE;
    if(Result > Reference)
    {
        if((Result - Reference) < Tolerance)
        {
            Status = TRUE;
        }
    }
    else
    {
        if((Reference - Result) < Tolerance)
        {
            Status = TRUE;
        }
    }

    return Status;
}

void Notification_0(void)
{
    VarNotification_0++;
}
void Notification_1(void)
{
    VarNotification_1++;
}
void Notification_2(void)
{
    VarNotification_2++;
}
void Notification_3(void)
{
    VarNotification_3++;
}

int main(void)
{
    Std_ReturnType StdReturn = E_NOT_OK;
    boolean bLocalStatus = TRUE;
    volatile boolean bStatus = TRUE;
    Adc_CalibrationStatusType CalibStatus;
    uint8 i;
    uint8 Index;

    /* Initialize Mcu Driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(&Mcu_Config_VS_0);
#endif /* MCU_PRECOMPILE_SUPPORT == STD_ON */
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    /* Busy wait until the System PLL is locked */
    while(MCU_PLL_LOCKED != Mcu_GetPllStatus());
    Mcu_DistributePllClock();
#endif /* MCU_NO_PLL == STD_OFF */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Platform Driver */
    Platform_Init(NULL_PTR);
    Platform_InstallIrqHandler(ADC0_IRQn, Adc_0_Isr, NULL_PTR);
    Platform_InstallIrqHandler(DMA1_IRQn, Dma0_Ch1_IRQHandler, NULL_PTR);
    Platform_SetIrq(ADC0_IRQn, TRUE);
    Platform_SetIrq(DMA1_IRQn, TRUE);

#ifdef ADC_DMA_SUPPORTED
    /* Initialize Mcl Driver */
    Mcl_Init(NULL_PTR);
    /* Initialize Rm driver */
    Rm_Init(NULL_PTR);
#endif /* ADC_DMA_SUPPORTED */

#if (ADC_PRECOMPILE_SUPPORT == STD_ON)
    Adc_Init(NULL_PTR);
#else
    Adc_Init(&Adc_Config_VS_0);
#endif /* ADC_PRECOMPILE_SUPPORT == STD_ON */

    /* Part 1: Example with SW Triggered One-Shot Conversion Mode, data conversion is updated by Interrupt.*/
    /*******************************************************************************************************/
    Adc_Calibrate(AdcHwUnit_0, &CalibStatus);
    if(CalibStatus.AdcUnitSelfTestStatus == E_NOT_OK)
    {
        bStatus = FALSE;
    }
    /* ResultBuffer is updated new data in Adc_0_Isr handler */
    Adc_SetupResultBuffer(AdcGroupSoftwareOneShot, ResultBuffer);
    Adc_EnableGroupNotification(AdcGroupSoftwareOneShot);

    for(Index = 0; Index < 10; Index++)
    {
        VarNotification_0 = 0;
        Adc_StartGroupConversion(AdcGroupSoftwareOneShot);

        /* Check if notification is called */
        while(VarNotification_0 == 0)
        {}

        StdReturn = Adc_ReadGroup(AdcGroupSoftwareOneShot, AdcReadGroupBuffer);
        if(E_OK != StdReturn)
        {
            bStatus = FALSE;
        }
        /* Check converted results */
        if((ResultBuffer[0] != AdcReadGroupBuffer[0]) || \
           (ResultBuffer[1] != AdcReadGroupBuffer[1]) || \
           (ResultBuffer[2] != AdcReadGroupBuffer[2]) || \
           (ResultBuffer[3] != 0xaaaa) || \
           (AdcReadGroupBuffer[3] != 0xbbbb) \
          )
        {
            bStatus = FALSE;
        }
        for (i = 0; i < ADC_CFGSET_VS_0_GROUP_0_CHANNELS; i++)
        {
            bLocalStatus = CheckResult(ResultBuffer[i], AdcExpectedValue[i], RESULT_TOLERANCE);
            if(FALSE == bLocalStatus)
            {
                bStatus = FALSE;
            }
        }
        /* Reset the buffers before starting new conversion */
        for (i = 0; i < NUM_RESULTS; i++)
        {
            ResultBuffer[i] = 0xaaaa;
            AdcReadGroupBuffer[i] = 0xbbbb;
        }
    }
#ifdef ADC_DMA_SUPPORTED
    /* Part 2: Example with SW Triggered One-Shot Conversion Mode, data conversion is updated by DMA.*/
    /*************************************************************************************************/
    Adc_Calibrate(AdcHwUnitDma, &CalibStatus);
    if(CalibStatus.AdcUnitSelfTestStatus == E_NOT_OK)
    {
        bStatus = FALSE;
    }

    /* ResultBufferDma is updated new data by DMA Transferring */
    Adc_SetupResultBuffer(AdcGroupSoftwareOneShotDma, ResultBufferDma);
    Adc_EnableGroupNotification(AdcGroupSoftwareOneShotDma);

    for(Index = 0; Index < 10; Index++)
    {
        VarNotification_2 = 0;
        Adc_StartGroupConversion(AdcGroupSoftwareOneShotDma);
        /* Check if notification is called */
        while(VarNotification_2 == 0)
        {}

        StdReturn = Adc_ReadGroup(AdcGroupSoftwareOneShotDma, AdcReadGroupBufferDma);
        if(E_OK != StdReturn)
        {
            bStatus = FALSE;
        }
        
        /* Check converted results */
        if((ResultBufferDma[0] != AdcReadGroupBufferDma[0]) || \
           (ResultBufferDma[1] != AdcReadGroupBufferDma[1]) || \
           (ResultBufferDma[2] != AdcReadGroupBufferDma[2]) || \
           (ResultBufferDma[3] != 0xaaaa) || \
           (AdcReadGroupBuffer[3] != 0xbbbb) \
          )
        {
            bStatus = FALSE;
        }
        for (i = 0; i < ADC_CFGSET_VS_0_GROUP_2_CHANNELS; i++)
        {
            bLocalStatus = CheckResult(ResultBufferDma[i], AdcExpectedValue[i], RESULT_TOLERANCE);
            if(FALSE == bLocalStatus)
            {
                bStatus = FALSE;
            }
        }
        /* Reset the buffers before starting new conversion */
        for (i = 0; i < NUM_RESULTS; i++)
        {
            ResultBufferDma[i] = 0xaaaa;
            AdcReadGroupBufferDma[i] = 0xbbbb;
        }
    }
#endif /* ADC_DMA_SUPPORTED */
    Adc_DeInit();

    Exit_Example(bStatus);

    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */
