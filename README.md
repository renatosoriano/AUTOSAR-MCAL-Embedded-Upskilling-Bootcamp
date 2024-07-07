# AUTOSAR MCAL Embedded Upskilling Bootcamp

This repo contains the projects, codes, examples, exercises and results for the "[AUTOSAR MCAL Embedded Upskilling Bootcamp](https://embedded-house.ghost.io/tag/autosar-mcal-with-nxp-s32k1xx/)" by [Modular MX](https://www.linkedin.com/company/modular-mx/).

![AUTOSAR_MCAL_Upskilling.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/AUTOSAR_MCAL_Upskilling.png)

Date: July, 2024.

- The [**Certificate**](https://www.acreditta.com/credential/e82a8595-ae1b-4ffb-b578-efea011bb781?utm_source=copy&resource_type=badge&resource=e82a8595-ae1b-4ffb-b578-efea011bb781) is available.

![Autosar_MCAL_Certificate_Badge.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Autosar_MCAL_Certificate_Badge.png)

## Table of Contents
1. [**Description**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#description)
2. [**Hardware Requirements**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#hardware-requirements)
3. [**Software Requirements**]
4. [**Notes**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#notes)
5. [**Documentation**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#documentation)
6. [**Examples and Exercises**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#examples-and-exercises)
7. [**Results**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#results)

## 1. Description

This AUTOSAR Upskilling Bootcamp, focused on MCAL layer, shows how to configure multiple peripherals that can be found in the microcontroller hardware by making use of Automotive industry tools.
This Upskilling consists on 6 weeks, where 10% is theory and the 90% remaining is practice and hands-on.

By working through examples and exercises that use the NXP S32K144 board, the Modular MX Modular-S1 board and tools like Elektrobit Tresos, SEGGER Ozone debugger, and SavvyCAN, you'll gain an understanding on configuring, generating, and developing highly efficient low-level drivers and analyze their utilization in Classic AUTOSAR.

The Upskilling Bootcamp covers:
1. Introduction to AUTOSAR MCAL and EB Tresos.
2. PORT driver.
3. DIO driver.
4. MCU driver.
5. GPT Driver.
6. Platform Driver.
7. ADC driver.
8. PWM driver.
9. SPI driver.
10. I/O Hardware Abstraction.
11. CAN driver.
12. CANIF driver.

## 2. Hardware Requirements

**[NXP S32K144-Q100 Evaluation Board for Automotive General Purpose](https://www.nxp.com/design/design-center/development-boards-and-designs/automotive-development-platforms/s32k-mcu-platforms/s32k144-q100-evaluation-board-for-automotive-general-purpose:S32K144EVB)** - Based on the 32-bit Arm® Cortex®-M4F S32K14 MCU, this is the base board used in this bootcamp. \
![S32K144_pinout.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/S32K144_pinout.png)

**[Modular-S1 Board](https://embedded-house.ghost.io/tag/autosar-mcal-with-nxp-s32k1xx/)** - Board developed by Modular MX, comes with a whole new layer of additional peripherals customized specifically for NXP S32K144. Contains 2 potentiometers, 1 buzzer, 3 push buttons, 8 leds, general purpose inputs-outputs, USB Hub, CAN analyzer, 24 MHz logic analyzer, SPI display, 2 SPI Eeproms, and external CAN & LIN analyzer connectors.   \
![Modular-S1_Board.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Modular-S1_Board.png)

**NXP S32K144 Board + Modular-S1 Board:**
![NXP-S32K144_Modular-S1.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/NXP-S32K144_Modular-S1.png)

## 3. Software Requirements

**[EB Tresos Studio](https://www.elektrobit.com/products/ecu/eb-tresos/studio/)** - Tool environment for electronic control unit (ECU) development with AUTOSAR. EB tresos Studio lets you configure, validate, and generate your ECU basic software (BSW). EB tresos Studio is the industry-standard tool for microcontroller abstraction layer (MCAL) development by semiconductor suppliers such as NXP, STM, and Infineon. Works on Windows and is free. \
**[SEGGER Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger/)** - Full-featured graphical debugger for embedded applications. It is possible to debug any embedded application on C/C++ source and assembly level, as well as loading applications built with any tool chain / IDE or debug the target's resident application without any source. Ozone includes all well-known debug controls and information windows and makes use of the best performance of J-Link and J-Trace debug probes. Works on Windows/Linux/Mac and is free. \
**[SavvyCAN](https://www.savvycan.com/)** - It is a CAN bus reverse engineering and capture tool. SavvyCAN can use any CAN interface supported by QT's SerialBus system (PeakCAN, Vector, SocketCAN, J2534, etc). It can capture and send to multiple buses and CAN capture devices at once. Works on Windows/Linux/Mac and is free. 

## 4. Notes

* ### 4.1 Tools Installation and Configuration Guide:

You can find here [**Setup AUTOSAR Tools**](https://embedded-house.ghost.io/part-0-setup-your-autosar-tools/) the section where Modular MX explains the right procedure to download, install and configure all needed tools, including its dependencies, how to import the template project file and flash it to the device.

* ### 4.2 Ozone .jdebug files made portable for running correctly debugger:
After generating MCAL source files with EB Tresos Studio IDE and building the project, we need to make use of the .jdebug files that I'm providing in order to be capable or flashing the board with Ozone as well as for debugging. 
These files after generated were modified to be portable (using $(ProjectDir)), hence no need to be modified again and are ready to be executed.

Below you can see an example of the snippet for the .jdebug configuration file for any given project. 

```c
/*********************************************************************
*                                                                     
*       OnProjectLoad                                                 
*                                                                     
* Function description                                                
*   Project load routine. Required.                                   
*                                                                     
**********************************************************************
*/                                                                    
void OnProjectLoad (void) {
  //
  // Dialog-generated settings
  //
  Project.AddPathSubstitute ("C:/EB/tresos/workspace/DIO_Example4_Reading_channel", "$(ProjectDir)");
  Project.AddPathSubstitute ("c:/eb/tresos/workspace/dio_example4_reading_channel", "$(ProjectDir)");
  Project.SetDevice ("S32K144");
  Project.SetHostIF ("USB", "");
  Project.SetTargetIF ("JTAG");
  Project.SetTIFSpeed ("4 MHz");
  Project.AddSvdFile ("$(InstallDir)/Config/CPU/Cortex-M4F.svd");
  //Project.AddSvdFile ("C:/EB/tresos/workspace/DIO_Example4_Reading_channel/S32K144.svd");
  Project.AddSvdFile ("$(ProjectDir)/S32K144.svd");
  //
  // User settings
  //
  File.Open ("$(ProjectDir)/Build/temp.elf");
}
```

## 5. Documentation

You can find here [**Documentation**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Documentation/) all reference documents regarding:
* AUTOSAR MCAL drivers.
* Compiler Manuals.
* NXP S32K144 Board.
* Modular S-1 Board.
* SEGGER Tools.

## 6. Examples and Exercises

You can find here [**Tresos_Workspace**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Tresos_Workspace/) the base template file as weel as all the examples and exercises created for this Upskilling Bootcamp.
It is divided in folders for each of the MCAL drivers worked, and inside you will find 2 folders, Examples and Exercises.
Will be uploading them as they are ready.

## 7. Results
You can find here captures and media relevant to an example and/or exercise visible output in communication (software) or physical-world (board).
Will be uploading them as they are ready.

* ### Output from one of the CAN module's example:

![SavvyCAN_Ozone_Example.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/SavvyCAN_Ozone_Example.png)
