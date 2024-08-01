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
#include "Mcu.h"
#include "Mcu_Cfg.h"
#include "Platform.h"
#include "Can_43_FLEXCAN.h"
#include "SchM_Can_43_FLEXCAN.h"
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

uint8 Can_au8Sdu8bytes[8U] = {0x01U, 0x02U, 0x03U, 0x04U, 0x05U, 0x06U, 0x07U, 0x08};
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
uint8 CanIf_u8TxConfirmCnt = 0U;
boolean CanIf_bTxFlag = FALSE;
uint8 CanIf_u8RxIndicationCnt = 0U;
boolean CanIf_bRxFlag = FALSE;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void CanIf_ControllerBusOff(uint8 ControllerId)
{
    (void)ControllerId;
}

void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode )
{
    (void)ControllerId;
    (void)ControllerMode;
}
void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    CanIf_u8TxConfirmCnt++;
    CanIf_bTxFlag = TRUE;
    (void)CanTxPduId;
}

void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr )
{
    CanIf_u8RxIndicationCnt++;
    CanIf_bRxFlag = TRUE;
    (void)Mailbox;
    (void)PduInfoPtr;
}

void Can_DummyDelay(uint32 loops)
{
    VAR( volatile uint32, CAN_VAR) data = 0xAA55AA55;
    VAR( volatile uint32, CAN_VAR) contor1 = 0;
    VAR( volatile uint32, CAN_VAR) contor2 = loops;

    do
    {
        for (contor1 = 0; contor1 < 0x2FF; contor1++)
        {
            data ^= (1 << contor1) | (0xAAAAAA | contor2);
        }
        contor2--;
    } while( contor2 > 0);
}

Can_PduType Can_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu)
{
    Can_PduType PduInfo;
    
    PduInfo.id = id;
    PduInfo.swPduHandle = swPduHandle;
    PduInfo.length = length;
    PduInfo.sdu = sdu;
    
    return PduInfo;
}

int main(void) 
{
    uint8 u8TimeOut = 100U;
    CanIf_bTxFlag = FALSE;
    CanIf_bRxFlag = FALSE;
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config);
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

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);  
    static Can_PduType Can_PduInfo;
    
    /* Can_CreatePduInfo(id, swPduHandle,length, sdu) */
    Can_PduInfo = Can_CreatePduInfo(0U, 0U, 8U, Can_au8Sdu8bytes);
    /* Initilize Can driver */
#if (CAN_43_FLEXCAN_PRECOMPILE_SUPPORT == STD_ON)
    Can_43_FLEXCAN_Init(NULL_PTR);
#else
    Can_43_FLEXCAN_Init(&Can_43_FLEXCAN_Config);
#endif
    Can_43_FLEXCAN_SetControllerMode(CanController_0, CAN_CS_STARTED);
    if((Can_43_FLEXCAN_Write(CanHardwareObject_1, &Can_PduInfo) == E_OK))
    while((!CanIf_bTxFlag) && (u8TimeOut != 0U))
    {
        Can_43_FLEXCAN_MainFunction_Write();
        Can_DummyDelay(100U);
        u8TimeOut--;
    }
        
    u8TimeOut = 100U;
    while((!CanIf_bRxFlag) && (u8TimeOut != 0U))
    {
        Can_43_FLEXCAN_MainFunction_Read();
        Can_DummyDelay(100U);
        u8TimeOut--;
    }
    Can_43_FLEXCAN_SetControllerMode(CanController_0, CAN_CS_STOPPED);
    Can_43_FLEXCAN_DeInit();
    
    Exit_Example((CanIf_bTxFlag && CanIf_bRxFlag) == TRUE);
    
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
