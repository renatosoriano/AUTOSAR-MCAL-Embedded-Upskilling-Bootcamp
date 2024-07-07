/*
** ###################################################################
**     Processor:           S32M24x
**     Reference manual:    S32M24x RM Rev.2 Draft A
**     Version:             rev. 1.3, 2023-05-30
**     Build:               b230530
**
**     Abstract:
**         Peripheral Access Layer for S32M24x
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may
**     only be used strictly in accordance with the applicable license terms.
**     By expressly accepting such terms or by downloading, installing,
**     activating and/or otherwise using the software, you are agreeing that
**     you have read, and that you agree to comply with and are bound by,
**     such license terms. If you do not agree to be bound by the applicable
**     license terms, then you may not retain, install, activate or otherwise
**     use the software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 Taru Shree 15-Dec-21  Initial release based on 
**                                      S32M24x RM Rev.1 Draft C.
**
**     - rev. 1.1 Taru Shree 10-Jun-22  1)Initial release based on 
**                                      S32M24x RM Rev.1 Draft F.
**                                      2)LPUART2_RxTx interrupt is
**                                      removed.
**                                      3)AEC_AE-                              
**                                      -VERID register:                       
**                                       -VARIANT bitfield is added.          
**                                       -MAJOR bitfield’s size is changed from
**                                        4 to 8.                              
**                                       -ID bitfield’s size is changed from 24
**                                        to 16.                               
**                                      -LOCK_CONTROL register: FWDG_CFG_LOCK  
**                                       and RSTG_CFG_LOCK bitfields are       
**                                       added.                                 
**                                      -LPWU_CONTROL register: NOIRQ_CFG     
**                                       bitfield is added.                    
**                                      -NOTIFS_MONITOR register:              
**                                       EVENTS_ENA_PAR_VAL, EVENTS_ENA_PAR_ERR
**                                       FAULTS_ENA_PAR_VAL, FAULTS_ENA_PAR_ERR 
**                                       RSTG_CFG_PAR_VAL, RSTG_CFG_PAR_ERR,   
**                                       OTP_MIRROR_PAR_VAL, OTP_MIRROR_PAR_ERR
**                                       and DPGA_PAR_ERR bitfields are added. 
**                                      -IRQ_SET register: FLT09_SET and       
**                                       FLT14_SET bitfields are removed.      
**                                      -CLKGEN_CFG register:	              
**                                       -CLKGEN_CFG bitfield’s size is changed
**                                        from 8 to 9.                         
**                                       -SYSCLK_FREQ_VAL bitfield’s size is   
**                                        changed from 7 to 9.                 
**                                      -RSTGEN_CFG register:                  
**                                       -RSTGEN_CFG bitfield’s size is changed 
**                                        from 8 to 9.                         
**                                       -NOFLUSH bitfield is added.           
**                                      -IO_FUNCMUX_CFG register:              
**                                       -AMPOUT bitfield is renamed as        
**                                        DPGA_OUT.                            
**                                       -AMPOUT_SEL, VDDE_DRV, PHY_SEL,       
**                                        D2D_EN, OUTSEL and CLKSEL bitfields  
**                                        are added.                           
**                                       -SENSE_DPGA2AMPOUT, VDDE and CLK_OUT  
**                                        bitfields are removed.               
**                                      -LINPHY_CFG register: CXPI_NSL and     
**                                       CXPI_MS bitfields are added.          
**                                      4)DPGA_AE-                             
**                                      -INTF register: AMPCFGIF and BTCFGIF   
**                                       bitfields are added.                  
**                                      -INTEN register: AMPCFGIE and BTCFGIE 
**                                       bitfields are added.                 
**                                      -AE_STAT register: AMPCFGS and BTCFGS  
**                                       bitfields are added.                  
**                                      -AE_CTRL register: BIVDEN bitfield is  
**                                       added.                                
**                                      -AMPCFG register: IGND bitfield is     
**                                       added.                                
**                                      5)EWM module is added.                              
**                                      6)FLEXCAN0 instance is changed to      
**                                      FLEXCAN. 
*                                       7)FMC module is removed.                             
**                                      8)GDU_AE-         	                 
**                                      -CFG register: DISHDHVD bitfield is    
**                                       removed.                              
**                                      -STAT, CTL and DLYMCFG register is converted from 8  
**                                       to 16 bits. 
**                                      9)LPUART2 instance is removed.                           
**                                      10)MCM-	                              
**                                      FADR, FATR and FDR registers are       
**                                      removed.                               
**                                      11)MEM_OTP_AE-	                      
**                                      All registers are changed. 
**                                      12)PDB-
**                                      -PDB_INSTANCE_COUNT'S value is changed from  1 to 2.
**                                      -Instead of PDB, PDB0 and PDB1       
**                                      instances are added.   
**                                      13)PORT-
**                                      -PORT_INSTANCE_COUNT's value is changed from
**                                       1 to 5.
**                                      -Instead of PORT, PORT_A, PORT_B,    
**                                       PORT_C, PORT_D and PORT_E instances are
**                                       added.      
**                                      14)RCM-	                              
**                                      -PARAM register is added.              
**                                      -SRS register:	                      
**                                       LOC, LOL, CMU_LOC, JTAG and MDM_AP    
**                                       bitfields are added.                  
**                                      -SSRS register: SLOC, SLOL, SCMU_LOC, 
**                                       SJTAG and SMDM_AP bitfields are added.
**                                      -SRIE register is added.               
**                                      15)SCG-	                              
**                                      SPLLLOCK_CNFG register is removed.     
**                                      16)SIM-	                              
**                                      FTMOPT0 register is added.             
**                                      17)SMC-                                
**                                      PMCTRL register: RUNM bitfield is added.
**
**     - rev. 1.2 Taru Shree 08-Aug-22  1)Initial release based on 
**                                      RM Rev.1.
**                                      2)AIPS-
**                                      OPACRn registers are converted into an 
**                                      array.
**                                      3)CMP instance is renamed as CMP0.
**                                      4)CRC-
**                                      -DATALL register is renamed as LL.
**                                      -DATALU register is renamed as LU. 
**                                      -DATAHL register is renamed as HL. 
**                                      -DATAHU register is renamed as HU. 
**                                      -DATAL register is renamed as L. 
**                                      -DATAH register is renamed as H. 
**                                      5)DMA-
**                                      -NBYTES_MLNO register is renamed as
**                                       MLNO.
**                                      -NBYTES_MLOFFNO register is renamed as
**                                       MLOFFNO.
**                                      -NBYTES_MLOFFYES register is renamed as
**                                       MLOFFYES.
**                                      -CITER_ELINKNO register is renamed as
**                                       ELINKNO.
**                                      -CITER_ELINKYES register is renamed as
**                                       ELINKYES.
**                                      -BITER_ELINKNO register is renamed as
**                                       ELINKNO.
**                                      -BITER_ELINKYES register is renamed as
**                                       ELINKYES.
**                                      6)EIM-
**                                      EICHDm_WORDn registers are converted into 
**                                      an array.
**                                      7)ERM-
**                                      EARn registers are converted into
**                                      an array.
**                                      8)FTM-
**                                      -CSC register is renamed as CnSC.
**                                      -CV register is renamed as CnV.
**                                      9)LPIT-
**                                      CHANNEL array is renamed as TMR.
**                                      10)MCM-
**                                      Bitfield's position is reversed in
**                                      many register.
**                                      11)MPU-
**                                      EARm and EDRn registers are merged 
**                                      together into EAR_EDR array.
**                                      12)MSCM-
**                                      -CPXTYPE register is renamed as
**                                       CPxTYPE.
**                                      -CPXNUM register is renamed as
**                                       CPxNUM.
**                                      -CPXMASTER register is renamed as
**                                       CPxMASTER.
**                                      -CPXCOUNT register is renamed as
**                                       CPxCOUNT.
**                                      -CPXCFG0 register is renamed as
**                                       CPxCFG0.
**                                      -CPXCFG1 register is renamed as
**                                       CPxCFG1.
**                                      -CPXCFG2 register is renamed as
**                                       CPxCFG2.
**                                      -CPXCFG3 register is renamed as
**                                       CPxCFG3.
**                                      -OCMDRn registers are converted into
**                                       an array.
**                                      13)PCC-
**                                      All registers are merged into PCCn array.
**                                      14)PDB-
**                                      Substantial changes are done throughout
**                                      the module.
**                                      15)PORT-
**                                      -PCRn registers are converted into an 
**                                       array.
**                                      -PORT_A instance is renamed as PORTA. 
**                                      -PORT_B instance is renamed as PORTB. 
**                                      -PORT_C instance is renamed as PORTC. 
**                                      -PORT_D instance is renamed as PORTD. 
**                                      -PORT_E instance is renamed as PORTE. 
**                                      16)RCM-
**                                      -VERID register: Bitfield's position
**                                       is reversed.
**                                      -PARAM register: Bitfield's position
**                                       is reversed.
**                                      -SRS register: Bitfield's position
**                                       is reversed.
**                                      -RPC register: Bitfield's position
**                                       is reversed.
**                                      -SSRS register: Bitfield's position
**                                       is reversed.
**                                      -SRIE register: Bitfield's position
**                                       is reversed.
**                                      17)SMC-
**                                      -VERID register: Bitfield's position
**                                       is reversed.
**                                      -PARAM register: Bitfield's position
**                                       is reversed.
**                                      -PMCTRL register: Bitfield's position
**                                       is reversed. 
**                                      -STOPCTRL register is added.
**                                      18)TRGMUX-
**                                      All registers are merged into TRGMUXn
**                                      array.
**
**     - rev. 1.3 Suman Rani 30-May-23  1)Initial release based on 
**                                      RM Rev.2 Draft A.
**                                      2)AEC_AE-
**                                      -CLKGEN_CFG register:
**                                       -CLKGEN_CFG bitfield address is changed 
**                                       from 0x1FF to 0xFF.
**                                       -CLKGEN_CFG bitfield size is changed
**                                       from 9 to 8.
**                                       -Following bitfields are added:
**                                        -CXPI_CLK_EN,RCOSC_MOD_ENA,RCOSC_MOD_FRQ 
**                                        and RCOSC_MOD_NBR.
**                                      -LINPHY_CFG register:
**                                       -Following bitfields are added:
**                                        -CXPI_SLOPE,CXPI_BOOST and LIN_CXPI_SEL.
**                                      -LINPHY_MONITOR register:
**                                       -Following bitfields are added:
**                                        -CXPI_WKUP_FL,CXPI_DOMTIMOUT_FL,CXPI_ARBIT_FL, 
**                                        CXPI_WKUP_MON,CXPI_DOMTIMOUT_MON,CXPI_ARBIT_MON,
**                                        CXPI_WKUP_EN,CXPI_DOMTIMOUT_EN and CXPI_ARBIT_EN.
**                                      3)MEM_OTP_AE-
**                                      -Registers MIRR_ADDR and DATAIN are removed.
**                                      -Register ERROR:
**                                       -Bitfields PGMERR,VRRERR and PGMWPERR are removed.
**                                      4)PMC_AE-
**                                      -Register MONCHECK is added.
**
**
** ###################################################################
*/

/*!
 * @file S32M24x.h
 * @version 1.3
 * @date 2023-05-30
 * @brief Peripheral Access Layer for S32M24x
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32M24x_H_)  /* Check if memory map has not been already included */
#define S32M24x_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32M24x_ADC.h"
#include "S32M24x_AEC_AE.h"
#include "S32M24x_AIPS.h"
#include "S32M24x_CMP.h"
#include "S32M24x_CRC.h"
#include "S32M24x_DMA.h"
#include "S32M24x_DMAMUX.h"
#include "S32M24x_DPGA_AE.h"
#include "S32M24x_EIM.h"
#include "S32M24x_ERM.h"
#include "S32M24x_EWM.h"
#include "S32M24x_FLEXCAN.h"
#include "S32M24x_FLEXIO.h"
#include "S32M24x_FTFC.h"
#include "S32M24x_FTFM.h"
#include "S32M24x_FTM.h"
#include "S32M24x_GDU_AE.h"
#include "S32M24x_GPIO.h"
#include "S32M24x_HVI_AE.h"
#include "S32M24x_LMEM.h"
#include "S32M24x_LPI2C.h"
#include "S32M24x_LPIT.h"
#include "S32M24x_LPSPI.h"
#include "S32M24x_LPTMR.h"
#include "S32M24x_LPUART.h"
#include "S32M24x_MCM.h"
#include "S32M24x_MEM_OTP_AE.h"
#include "S32M24x_MPU.h"
#include "S32M24x_MSCM.h"
#include "S32M24x_NVIC.h"
#include "S32M24x_PCC.h"
#include "S32M24x_PDB.h"
#include "S32M24x_PMC.h"
#include "S32M24x_PMC_142.h"
#include "S32M24x_PMC_AE.h"
#include "S32M24x_PORT.h"
#include "S32M24x_RCM.h"
#include "S32M24x_RTC.h"
#include "S32M24x_SCB.h"
#include "S32M24x_SCG.h"
#include "S32M24x_SIM.h"
#include "S32M24x_SMC.h"
#include "S32M24x_SYSTICK.h"
#include "S32M24x_TRGMUX.h"
#include "S32M24x_WDOG.h"

#endif  /* #if !defined(S32M24x_H_) */
