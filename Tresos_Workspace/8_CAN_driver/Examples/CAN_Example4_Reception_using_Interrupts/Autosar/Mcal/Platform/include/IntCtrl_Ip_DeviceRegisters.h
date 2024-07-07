/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
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

#ifndef INTCTRL_IP_DEVICE_REGISTERS_H_
#define INTCTRL_IP_DEVICE_REGISTERS_H_

/**
*   @file
*
*   @addtogroup IntCtrl_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"
#define PLATFORM_INTCTRL_IP_DEVICE_REGISTERS_TYPES_VENDOR_ID                    43
#define PLATFORM_INTCTRL_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION                   2
#define PLATFORM_INTCTRL_IP_DEVICE_REGISTERS_SW_MINOR_VERSION                   0
#define PLATFORM_INTCTRL_IP_DEVICE_REGISTERS_SW_PATCH_VERSION                   0

#if defined(S32K116)
    #include "S32K116.h"
#elif defined(S32K118)
    #include "S32K118.h"
#elif defined(S32K142)
    #include "S32K142.h"
#elif defined(S32K142W)
    #include "S32K142W.h"
#elif defined(S32K144)
    #include "S32K144.h"
#elif defined(S32K144W)
    #include "S32K144W.h"
#elif defined(S32K146)
    #include "S32K146.h"
#elif defined(S32K148)
    #include "S32K148.h"
#elif (defined(S32M244)||defined(S32M243)||defined(S32M242)||defined(S32M241))
    #include "S32M24x.h"
#else
    #error "Unknown Platform"
#endif

typedef struct {
    __IO uint32_t IntStatusR;  /**< Interrupt Router CPn Interruptx Status Register, array offset: 0x200, index*0x20, index2*0x8 */
    __O  uint32_t IGR;  /**< Interrupt Router CPn Interruptx Generation Register, array offset: 0x204, index*0x20, index2*0x8 */
} MSCM_IRCP_IR_Type;

typedef struct {
    MSCM_IRCP_IR_Type IRCPnIRx[2][4];
} MSCM_IRCPnIRx_Type;

#define MSCM_IRCPnIRx ((MSCM_IRCPnIRx_Type*)&MSCM->IRCP0ISR0)




#endif /* INTCTRL_IP_DEVICE_REGISTERS_H_ */

/** @} */
