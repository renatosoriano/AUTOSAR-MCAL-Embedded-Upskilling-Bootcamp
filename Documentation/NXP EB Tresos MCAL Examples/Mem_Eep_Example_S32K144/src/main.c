/*
*   (c) Copyright 2023 NXP
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
#include "Mem_43_EEP.h"
#include "S32K144.h"
#include "Mcu.h"
#include "check_example.h"
#include "Mcal.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
    @brief control code for key size
*/
typedef enum
{
    EEP_FTFC_KEY_SIZE_0_BYTES   = 0x0,  /**< @brief control code for key size 0 bytes, used for the partitioning command */
    EEP_FTFC_KEY_SIZE_128_BYTES = 0x1,  /**< @brief control code for key size 128 bytes, used for the partitioning command */
    EEP_FTFC_KEY_SIZE_256_BYTES = 0x2,  /**< @brief control code for key size 256 bytes, used for the partitioning command */
    EEP_FTFC_KEY_SIZE_512_BYTES = 0x3   /**< @brief control code for key size 512 bytes, used for the partitioning command */
} TestEep_CsecKeySize;

/**
    @brief FlexRamPartition Type used for the partitioning command
*/
typedef enum
{
    EEP_FTFC_EERAM_SIZE_0K  = 0xF,   /**< @brief control code for flexram partitioned as sram, used for the partitioning command */
    EEP_FTFC_EERAM_SIZE_4K  = 0x2,   /**< @brief control code for flexram partitioned as eeram, used for the partitioning command */
    EEP_FTFC_EERAM_SIZE_2K  = 0x3    /**< @brief control code for flexram partitioned as eeram, used for the partitioning command */
} TestEep_Eeprom_FlexRamPartitionType;

/**
    @brief FlexNvmPartition Type used for the partitioning command
*/
typedef enum
{
    EEP_FTFC_EEEPROM_SIZE_0K_V1   =  0x0,   /**< @brief control code to partition EEPROM backup size as 0K, used for the partitioning command */
    EEP_FTFC_EEEPROM_SIZE_0K_V2   =  0xC,   /**< @brief control code to partition EEPROM backup size as 0K, used for the partitioning command */
    EEP_FTFC_EEEPROM_SIZE_0K_V3   =  0x0F,  /**< @brief control code to partition EEPROM backup size as 0K, used for the partitioning command */
    EEP_FTFC_EEEPROM_SIZE_32K_V1  = 0x3,    /**< @brief control code to partition EEPROM backup size as 32K, used for the partitioning command */
    EEP_FTFC_EEEPROM_SIZE_32K_V2  = 0xB,    /**< @brief control code to partition EEPROM backup size as 32K, used for the partitioning command */
    EEP_FTFC_EEEPROM_SIZE_48K_V1  = 0xA,    /**< @brief control code to partition EEPROM backup size as 48K, used for the partitioning command */
    EEP_FTFC_EEEPROM_SIZE_64K_V1  = 0x8,    /**< @brief control code to partition EEPROM backup size as 64K, used for the partitioning command */
    EEP_FTFC_EEEPROM_SIZE_64K_V2  = 0x4,    /**< @brief control code to partition EEPROM backup size as 64K, used for the partitioning command */
    EEP_FTFC_EEEPROM_SIZE_24K_V2  = 0x9     /**< @brief control code to partition EEPROM backup size as 24K, used for the partitioning command */
} TestEep_Eeprom_FlexNvmPartitionType;
/**
    @brief Sfe Type used for the partitioning command
*/
typedef enum
{
    EEP_FTFC_VERIFY_ONLY_DISABLED  = 0x0,    /**< @brief control code for sfe verify only disabled, used for the partitioning command */
    EEP_FTFC_VERIFY_ONLY_ENABLED   = 0x1     /**< @brief control code for sfe verify only enabled, used for the partitioning command */
} TestEep_SfeType;

/**
    @brief LoadFlexRam at reset Type used for the partitioning command
*/
typedef enum
{
    EEP_FTFC_LOAD_AT_RESET_ENABLED  = 0x0,  /**< @brief control code for loading flexram at reset, used for the partitioning command */
    EEP_FTFC_LOAD_AT_RESET_DISABLED = 0x1   /**< @brief control code for not loading flexram at reset, used for the partitioning command */
} TestEep_LoadFlexRamType;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define EEP_ERASE_START_ADD         (0U)
#define EEP_WRTESTPATT_SIZE         (32U)
#define EEP_RDTESTPATT_SIZE         (32U)

#define REG_WRITE8(address, value)        (*((volatile uint8*)(address)) = (value))
#define REG_BIT_GET8(address, mask)       ((*(volatile uint8*)(address))& (mask))

#define T_EEEPROM_SIZE                     EEP_FTFC_EEEPROM_SIZE_32K_V2
#define TEST_EEP_EEPROM_FSTAT_ADDR32                               ((uint32)(IP_FTFC_BASE + (uint32)0x00UL)) /**< @brief Eeprom Status Register (FTFE_FSTAT) */
#define TEST_EEP_EEPROM_FCCOB3_ADDR32                              ((uint32)(IP_FTFC_BASE + (uint32)0x04UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB3) */
#define TEST_EEP_EEPROM_FCCOB2_ADDR32                              ((uint32)(IP_FTFC_BASE + (uint32)0x05UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB2) */
#define TEST_EEP_EEPROM_FCCOB1_ADDR32                              ((uint32)(IP_FTFC_BASE + (uint32)0x06UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB1) */
#define TEST_EEP_EEPROM_FCCOB0_ADDR32                              ((uint32)(IP_FTFC_BASE + (uint32)0x07UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB0) */
#define TEST_EEP_EEPROM_FCCOB7_ADDR32                              ((uint32)(IP_FTFC_BASE + (uint32)0x08UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB7) */
#define TEST_EEP_EEPROM_FCCOB6_ADDR32                              ((uint32)(IP_FTFC_BASE + (uint32)0x09UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB6) */
#define TEST_EEP_EEPROM_FCCOB5_ADDR32                              ((uint32)(IP_FTFC_BASE + (uint32)0x0AUL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB5) */
#define TEST_EEP_EEPROM_FCCOB4_ADDR32                              ((uint32)(IP_FTFC_BASE + (uint32)0x0BUL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB4) */

#define TEST_EEP_EEPROM_FSTAT_CCIF_U8                              (0x0080U)
#define TEST_EEP_EEPROM_FSTAT_ACCERR_U8                            (0x0020U)
#define TEST_EEP_EEPROM_FSTAT_FPVIOL_U8                            (0x0010U)
/* Start address for DFLASH sector 0 */
#define TEST_EEP_DEEPROM_SECTOR_0_ADDR32                           0x10000000
#define D_EEPROM_BASE_ADDR                                         (0x10000000UL)
#define TEST_EEP_EEPROM_CMD_ERASE_SECTOR                           (0x09UL)

#define EEPROM_CMD_PROGRAM_PARTITION                               (0x80UL)
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define MEM_43_EEP_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"
VAR_ALIGN(uint8 dataWrTestPatt[EEP_WRTESTPATT_SIZE],4)
VAR_ALIGN(uint8 BufferRead[EEP_WRTESTPATT_SIZE],4)
/* Data write to eeprom device */
uint8 dataWrTestPatt[EEP_WRTESTPATT_SIZE]=
{
    0x01, 0x02, 0x03, 0x04,
    0x11, 0x12, 0x13, 0x14,
    0x21, 0x22, 0x23, 0x24,
    0x31, 0x32, 0x33, 0x34,
    0x41, 0x42, 0x43, 0x44,
    0x51, 0x52, 0x53, 0x54,
    0x61, 0x62, 0x63, 0x64,
    0x71, 0x72, 0x73, 0x74
};

uint8 BufferRead[EEP_WRTESTPATT_SIZE] = {0};

#define MEM_43_EEP_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Mem_43_Eep_MemMap.h"
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static Std_ReturnType TestEep_FlexNvmProgramPartCmd
(
    VAR(TestEep_CsecKeySize, AUTOMATIC) eepKeysize,
    VAR(TestEep_SfeType, AUTOMATIC) eepSecurityFlagExtension,
    VAR(TestEep_LoadFlexRamType, AUTOMATIC) eepLoadFlexRamAtReset,
    VAR(TestEep_Eeprom_FlexRamPartitionType, AUTOMATIC) eepFlexRamPartition,
    VAR(TestEep_Eeprom_FlexNvmPartitionType, AUTOMATIC) eepFlexNvmPartition
);
void Eep_DepartParitition(TestEep_Eeprom_FlexNvmPartitionType T_EEP_SIZE);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static Std_ReturnType TestEep_FlexNvmProgramPartCmd
(
    VAR(TestEep_CsecKeySize, AUTOMATIC) eepKeysize,
    VAR(TestEep_SfeType, AUTOMATIC) eepSecurityFlagExtension,
    VAR(TestEep_LoadFlexRamType, AUTOMATIC) eepLoadFlexRamAtReset,
    VAR(TestEep_Eeprom_FlexRamPartitionType, AUTOMATIC) eepFlexRamPartition,
    VAR(TestEep_Eeprom_FlexNvmPartitionType, AUTOMATIC) eepFlexNvmPartition
)
{
     Std_ReturnType u8RetVal = (Std_ReturnType)E_OK;
     uint32 u32Addr=0;
     uint32 u32FlexNvmPartSize = 0;

    uint32 u32RegSimFcfg1      = 0UL;

    u32RegSimFcfg1 = IP_SIM->FCFG1;

    /*get DEPART value */
    u32FlexNvmPartSize = (uint32)( (u32RegSimFcfg1 & SIM_FCFG1_DEPART_MASK) >> SIM_FCFG1_DEPART_SHIFT );

    /* check that it was not partitioned before */
    if (u32FlexNvmPartSize == 0xF)
    {
        /* if error flags are set the cmd is not executed */
        REG_WRITE8(TEST_EEP_EEPROM_FSTAT_ADDR32, TEST_EEP_EEPROM_FSTAT_ACCERR_U8 | TEST_EEP_EEPROM_FSTAT_FPVIOL_U8);

        /*erase DF 0 sector*/
        u32Addr=(TEST_EEP_DEEPROM_SECTOR_0_ADDR32 - D_EEPROM_BASE_ADDR) + 0x800000UL;

        REG_WRITE8(TEST_EEP_EEPROM_FCCOB0_ADDR32, TEST_EEP_EEPROM_CMD_ERASE_SECTOR);
        REG_WRITE8(TEST_EEP_EEPROM_FCCOB1_ADDR32, (uint8)(u32Addr >> 16UL));
        REG_WRITE8(TEST_EEP_EEPROM_FCCOB2_ADDR32, (uint8)(u32Addr >> 8UL));
        REG_WRITE8(TEST_EEP_EEPROM_FCCOB3_ADDR32, (uint8)(u32Addr >> 0UL));
        REG_WRITE8(TEST_EEP_EEPROM_FSTAT_ADDR32 , TEST_EEP_EEPROM_FSTAT_CCIF_U8);
        while((0U == REG_BIT_GET8(TEST_EEP_EEPROM_FSTAT_ADDR32, TEST_EEP_EEPROM_FSTAT_CCIF_U8)))
        {
        }

        if(0U==REG_BIT_GET8(TEST_EEP_EEPROM_FSTAT_ADDR32,TEST_EEP_EEPROM_FSTAT_ACCERR_U8 | TEST_EEP_EEPROM_FSTAT_FPVIOL_U8))
        {
            /* run program partition command */
            REG_WRITE8(TEST_EEP_EEPROM_FCCOB0_ADDR32,EEPROM_CMD_PROGRAM_PARTITION);
            REG_WRITE8(TEST_EEP_EEPROM_FCCOB1_ADDR32, (uint8)eepKeysize);
            REG_WRITE8(TEST_EEP_EEPROM_FCCOB2_ADDR32, (uint8)eepSecurityFlagExtension);
            REG_WRITE8(TEST_EEP_EEPROM_FCCOB3_ADDR32, (uint8)eepLoadFlexRamAtReset);
            REG_WRITE8(TEST_EEP_EEPROM_FCCOB4_ADDR32, (uint8)eepFlexRamPartition);
            REG_WRITE8(TEST_EEP_EEPROM_FCCOB5_ADDR32, (uint8)eepFlexNvmPartition);
            REG_WRITE8(TEST_EEP_EEPROM_FSTAT_ADDR32 , TEST_EEP_EEPROM_FSTAT_CCIF_U8);
            while((0U == REG_BIT_GET8(TEST_EEP_EEPROM_FSTAT_ADDR32, TEST_EEP_EEPROM_FSTAT_CCIF_U8)))
            {
            /* wait for operation to finish */
            }
            /* check if errors occured  */
            if(REG_BIT_GET8(TEST_EEP_EEPROM_FSTAT_ADDR32,TEST_EEP_EEPROM_FSTAT_ACCERR_U8 | TEST_EEP_EEPROM_FSTAT_FPVIOL_U8))
            {
                /* NOK, error flags are set */
                u8RetVal = (Std_ReturnType)E_NOT_OK;
            }
        }
        else
        {
            /* NOK, error flags are set */
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        /* NOK, partitioned already */
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return u8RetVal;
}

void Eep_DepartParitition(TestEep_Eeprom_FlexNvmPartitionType T_EEP_SIZE)
{
    uint32 u32FlexNvmPartSize = 0;

    uint32 u32RegSimFcfg1      = 0UL;

    u32RegSimFcfg1 = IP_SIM->FCFG1;

    /*get DEPART value */
    u32FlexNvmPartSize = (uint32)( (u32RegSimFcfg1 & SIM_FCFG1_DEPART_MASK) >> SIM_FCFG1_DEPART_SHIFT );
    if (u32FlexNvmPartSize == 0xF) /* We just partition again if curent size different with expected */
    {

        /* partition for EERAM 64K with NOT loading EERAM at reset in hardware */
        TestEep_FlexNvmProgramPartCmd(EEP_FTFC_KEY_SIZE_0_BYTES, EEP_FTFC_VERIFY_ONLY_DISABLED, \
                                               EEP_FTFC_LOAD_AT_RESET_ENABLED, EEP_FTFC_EERAM_SIZE_4K, T_EEP_SIZE);
    }

}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initializez the used drivers
*/
int main(void)
{
    uint16 count = 0;
    Std_ReturnType retReturnType;
    Mem_43_EEP_JobResultType retJobResultType;

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
    /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

    /* Partition only if it was not partitioned before for EERAM with code 0x4 */
    Eep_DepartParitition(T_EEEPROM_SIZE);
    /* Initialize Mem_Eep driver */
    Mem_43_EEP_Init(NULL_PTR);

    /* Erase memory by writing erase value */
    retReturnType = Mem_43_EEP_Erase(0u, EEP_ERASE_START_ADD, EEP_WRTESTPATT_SIZE);
    if(E_OK != retReturnType)
    {
        Exit_Example(FALSE);
        return 0;
    }
    while(MEM_43_EEP_JOB_PENDING == Mem_43_EEP_GetJobResult(0u))
    {
        Mem_43_EEP_MainFunction();
    }
    retJobResultType = Mem_43_EEP_GetJobResult(0u);
    if(MEM_43_EEP_JOB_OK != retJobResultType)
    {
        Exit_Example(FALSE);
        return 0;
    }

    /* Write one or more complete eeprom pages to the eeprom device */
    retReturnType = Mem_43_EEP_Write(0u, EEP_ERASE_START_ADD, dataWrTestPatt, EEP_WRTESTPATT_SIZE);
    if(E_OK != retReturnType)
    {
        Exit_Example(FALSE);
        return 0;
    }
    while(MEM_43_EEP_JOB_PENDING == Mem_43_EEP_GetJobResult(0u))
    {
        Mem_43_EEP_MainFunction();
    }
    retJobResultType = Mem_43_EEP_GetJobResult(0u);
    if(MEM_43_EEP_JOB_OK != retJobResultType)
    {
        Exit_Example(FALSE);
        return 0;
    }

    /* Declare a configuration struct variable for hwServiceID */
    Mem_43_EEP_CompareConfigType sCompareCfg;
    Mem_43_EEP_LengthType u32CompareCfgLength;
    sCompareCfg.eepromAddr = EEP_ERASE_START_ADD;
    sCompareCfg.dataSourcePtr = dataWrTestPatt;
    sCompareCfg.length = EEP_WRTESTPATT_SIZE;
    /* Save the length of the variable of struct configuration hwServiceID */
    u32CompareCfgLength = sizeof(sCompareCfg);
    /* Compares a eeprom memory area with an application data buffer */
    retReturnType = Mem_43_EEP_HwSpecificService(0u, MEM_43_EEP_HWSERVICEID_COMPARE, (Mem_43_EEP_DataType *)&sCompareCfg, &u32CompareCfgLength);
    if(E_OK != retReturnType)
    {
        Exit_Example(FALSE);
        return 0;
    }
    while(MEM_43_EEP_JOB_PENDING == Mem_43_EEP_GetJobResult(0u))
    {
        Mem_43_EEP_MainFunction();
    }
    retJobResultType = Mem_43_EEP_GetJobResult(0u);
    if(MEM_43_EEP_JOB_OK != retJobResultType)
    {
        Exit_Example(FALSE);
        return 0;
    }

    /* Reads from eeprom memory */
    retReturnType = Mem_43_EEP_Read(0u, EEP_ERASE_START_ADD, BufferRead, EEP_RDTESTPATT_SIZE);
    if(E_OK != retReturnType)
    {
        Exit_Example(FALSE);
        return 0;
    }
    while(MEM_43_EEP_JOB_PENDING == Mem_43_EEP_GetJobResult(0u))
    {
        Mem_43_EEP_MainFunction();
    }
    retJobResultType = Mem_43_EEP_GetJobResult(0u);
    if(MEM_43_EEP_JOB_OK != retJobResultType)
    {
        Exit_Example(FALSE);
        return 0;
    }

    /* Check data read from MEM_EEP */
    for ( count = 0; count < EEP_WRTESTPATT_SIZE; count++)
    {
        if(BufferRead[count] != dataWrTestPatt[count] )
        {
            Exit_Example(FALSE);
            return 0;
        }
    }

    Exit_Example(TRUE);
    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */
