# AUTOSAR MCAL Embedded Upskilling Bootcamp

This repo contains the projects, codes, examples, exercises and results for the "[AUTOSAR MCAL Embedded Upskilling Bootcamp](https://embedded-house.ghost.io/tag/autosar-mcal-with-nxp-s32k1xx/)" by [Modular MX](https://www.linkedin.com/company/modular-mx/).

![AUTOSAR_MCAL_Upskilling.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/AUTOSAR_MCAL_Upskilling.png)

Date: July, 2024.

- The [**Certificate and Badge**](https://www.acreditta.com/credential/e82a8595-ae1b-4ffb-b578-efea011bb781?utm_source=copy&resource_type=badge&resource=e82a8595-ae1b-4ffb-b578-efea011bb781) are available.

![Autosar_MCAL_Certificate_Badge.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Autosar_MCAL_Certificate_Badge.png)

## Table of Contents
1. [**Description**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#description)
2. [**Hardware Requirements**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#hardware-requirements)
3. [**Software Requirements**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#software-requirements)
4. [**Notes**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#notes)
5. [**Documentation**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#documentation)
6. [**Examples and Exercises**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#examples-and-exercises)
7. [**Final Project**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#final-project)
8. [**Results**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp?tab=readme-ov-file#results)

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
13. Final Project

## 2. Hardware Requirements

**[NXP S32K144-Q100 Evaluation Board for Automotive General Purpose](https://www.nxp.com/design/design-center/development-boards-and-designs/automotive-development-platforms/s32k-mcu-platforms/s32k144-q100-evaluation-board-for-automotive-general-purpose:S32K144EVB)** - Based on the 32-bit Arm® Cortex®-M4F S32K14 MCU, this is the base board used in this bootcamp. 

![S32K144_pinout.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/S32K144_pinout.png)

**[Modular-S1 Board](https://embedded-house.ghost.io/tag/autosar-mcal-with-nxp-s32k1xx/)** - Board developed by Modular MX, comes with a whole new layer of additional peripherals customized specifically for NXP S32K144. Contains 2 potentiometers, 1 buzzer, 3 push buttons, 8 leds, general purpose inputs-outputs, USB Hub, CAN analyzer, 24 MHz logic analyzer, SPI display, 2 SPI Eeproms, and external CAN & LIN analyzer connectors.   

![Modular-S1_Board.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Modular-S1_Board.png)

**NXP S32K144 Board + Modular-S1 Board:**

![NXP-S32K144_Modular-S1.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/NXP-S32K144_Modular-S1.png)

## 3. Software Requirements

**[EB Tresos Studio](https://www.elektrobit.com/products/ecu/eb-tresos/studio/)** - Tool environment for electronic control unit (ECU) development with AUTOSAR. EB tresos Studio lets you configure, validate, and generate your ECU basic software (BSW). EB tresos Studio is the industry-standard tool for microcontroller abstraction layer (MCAL) development by semiconductor suppliers such as NXP, STM, and Infineon. Works on Windows and is free.

**[SEGGER Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger/)** - Full-featured graphical debugger for embedded applications. It is possible to debug any embedded application on C/C++ source and assembly level, as well as loading applications built with any tool chain / IDE or debug the target's resident application without any source. Ozone includes all well-known debug controls and information windows and makes use of the best performance of J-Link and J-Trace debug probes. Works on Windows/Linux/Mac and is free.

**[SavvyCAN](https://www.savvycan.com/)** - It is a CAN bus reverse engineering and capture tool. SavvyCAN can use any CAN interface supported by QT's SerialBus system (PeakCAN, Vector, SocketCAN, J2534, etc). It can capture and send to multiple buses and CAN capture devices at once. Works on Windows/Linux/Mac and is free. 

## 4. Notes

* ### 4.1 Tools Installation and Configuration Guide:

You can find here [**Setup AUTOSAR Tools**](https://embedded-house.ghost.io/part-0-setup-your-autosar-tools/) the section where Modular MX explains the right procedure to download, install and configure all needed tools, including its dependencies, how to import the template project file and flash it to the device.

* ### 4.2 Ozone .jdebug files made portable for running debugger correctly:
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

You can find here [**Tresos Workspace**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Tresos_Workspace/) the base template file as well as all the examples and exercises created for this Upskilling Bootcamp.
It is divided in folders for each of the MCAL drivers worked, and inside you will find 2 folders, Examples and Exercises.

_Will be uploading them as they are ready._

## 7. Final Project

You can find here the [**Final Project**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Tresos_Workspace/Final_Project) created for this Upskilling Bootcamp.
It consists on an AUTOSAR I/O Hardware Abstraction for the on board Buttons and LEDs (PORT and DIO Drivers), Potentiometers (MCU and ADC Drivers), and Buzzer (PW Driver), all together with the Scheduler and a state machine with specific application events and tasks requirements.

![AUTOSAR_layered_view.jpeg](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/AUTOSAR_layered_view.jpeg)

### **Outputs**

* #### Button 1: Single click
Shall toggle ON/OFF RGB_LED_BLUE (D0) and C10_LED2 (as SINGLE_CLICK visual indicator).

![Button_1_Single_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Single_click.GIF)

https://github.com/user-attachments/assets/7e254285-5b00-4ca3-b0b7-083ebd013bfa

![Button_1_Single_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Single_click_Terminal.png)

* #### Button 1: Double click
Shall display (SEGGER_RTT_printf) Pot 1 ADC0 value in ohms, toggle C13_LED5 (as DOUBLE_CLICK visual indicator), and toggle C14_LED6 (as Pot 1 visual indicator).

![Button_1_Double_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Double_click.GIF)

https://github.com/user-attachments/assets/9f66e0b6-36a8-45d1-8fdf-4e0b84e6d62f

![Button_1_Double_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Double_click_Terminal.png)

* #### Button 1: Hold and Release
Buzzer shall start to beep and play Tone 1, then stop.

![Button_1_Hold_Release.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Hold_Release.GIF)

![Button_1_Hold_Release_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Hold_Release_Terminal.png)

* #### Button 2: Single click
Shall toggle ON/OFF RGB_LED_RED (D15) and C9_LED1 (as SINGLE_CLICK visual indicator).

![Button_2_Single_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Single_click.GIF)

https://github.com/user-attachments/assets/b4d3c5dc-a298-42aa-b5f8-e419363fc6f3

![Button_2_Single_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Single_click_Terminal.png)

* #### Button 2: Double click
Shall display (SEGGER_RTT_printf) Pot 2 ADC0 value in ohms, toggle C12_LED4 (as DOUBLE_CLICK visual indicator), and toggle C15_LED7 (as Pot 2 visual indicator).

![Button_2_Double_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Double_click.GIF)

https://github.com/user-attachments/assets/9eea159c-86a7-4f8a-8b8b-228dc2623305

![Button_2_Double_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Double_click_Terminal.png)

* #### Button 2: Hold and Release
Buzzer shall start to beep and play Tone 2, then stop.

![Button_2_Hold_Release.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Hold_Release.GIF)

![Button_2_Hold_Release_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Hold_Release_Terminal.png)

* #### Button 3: Single click
Shall toggle ON/OFF RGB_LED_GREEN (D16) and C8_LED0 (as SINGLE_CLICK visual indicator).

![Button_3_Single_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_3_Single_click.GIF)

https://github.com/user-attachments/assets/b4d3c5dc-a298-42aa-b5f8-e419363fc6f3

![Button_3_Single_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_3_Single_click_Terminal.png)

## 8. Results
You can find here captures and media relevant to examples and/or exercises visible output in communication (software) or physical-world (board).

_Will be uploading them as they are ready._

### **CAN Driver Examples Results**

* #### CAN Example 3: Transmission using Interrupts (ISRs)
Hardware board transmits (Tx) an 8-byte single message with ID 0x123 and specified Data payload: 01 02 03 04 05 06 11 12. Savvy CAN receiving (Rx) the data, evertime having byte 1 and 8 increased by value of 0x1 as per the example intentional behavior.

![CAN_Example3_Transmission_using_Interrupts.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example3_Transmission_using_Interrupts.png)

* #### CAN_Example 4: Reception using Interrupts(ISRs), Dataset 1
Hardware board receives (Rx) an 8-byte single message with ID 0x010 and specified Data payload: 32 01 01 01 01 01 01 01. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CAN_Example4_Reception_using_Interrupts_Dataset1.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example4_Reception_using_Interrupts_Dataset1.png)

* #### CAN_Example 4: Reception using Interrupts(ISRs), Dataset 2
Similar as previous, hardware board receives (Rx) an 8-byte single message with ID 0x010 and specified Data payload: 32 08 07 06 05 04 03 02. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CAN_Example4_Reception_using_Interrupts_Dataset2.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example4_Reception_using_Interrupts_Dataset2.png)

* #### CAN Example 5: Transmission Mailboxes Buffers
Hardware board transmits (Tx) three 8-byte messages with ID 0x123, 0x133 and 0x143, all having the same specified Data payload: 01 02 03 04 05 06 11 12. Savvy CAN receiving (Rx) the data, evertime having byte 1 and 8 increased by value of 0x1 as per the example intentional behavior.

![CAN_Example5_Transmission_Mailboxes_Buffers.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example5_Transmission_Mailboxes_Buffers.png)

* #### CAN Example 6: Reception with_Filters, ID 0x1EF
Hardware board receives (Rx) every second an 8-byte single message with ID Ox1EF and specified Data payload: 32 00 00 00 01 02 03 04. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CAN_Example6_Reception_with_Filters_ID_0x1EF.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example6_Reception_with_Filters_ID_0x1EF.png)

* #### CAN Example 6: Reception with_Filters, ID 0x022
Hardware board receives (Rx) every second an 8-byte single message with ID 0x022 and specified Data payload: 32 00 00 00 05 06 07 08. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CAN_Example6_Reception_with_Filters_ID_0x022.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example6_Reception_with_Filters_ID_0x022.png)

### **CAN Interface (CANIF) Driver Examples Results**

* #### CANIF Example 1: Transmission single PDU
Hardware board transmits (Tx) an 8-byte single message with ID 0x123 and specified Data payload: 01 02 03 04 05 06 11 12. Savvy CAN receiving (Rx) the data, evertime having byte 1 and 8 increased by value of 0x1 as per the example intentional behavior.

![CANIF_Example1_Transmission_single_PDU.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CANIF_Driver_examples_results_screenshots/CANIF_Example1_Transmission_single_PDU.png)

* #### CANIF Example 2: Two PDUTx, one single HOH
Hardware board transmits (Tx) two 8-byte messages with ID 0x123 and 0x124, all having the same specified Data payload: 01 02 03 04 05 06 11 12. Savvy CAN receiving (Rx) the data, evertime having byte 1 and 8 increased by value of 0x1 as per the example intentional behavior.

![CANIF_Example2_Two_PDU_Tx_one_single_HOH.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CANIF_Driver_examples_results_screenshots/CANIF_Example2_Two_PDU_Tx_one_single_HOH.png)

* #### CANIF Example 3: Two PDUTx, Two HOH, Two Notifications
Hardware board transmits (Tx) two 8-byte messages with ID 0x123 and 0x124, all having the same specified Data payload: 01 02 03 04 05 06 11 12. Each message has its own interrupt callback function to indicate that the message was transmitted. Savvy CAN receiving (Rx) the data, evertime having byte 1 and 8 increased by value of 0x1 as per the example intentional behavior.

![CANIF_Example3_2_PDU_Tx_2_HOH_2_Notif.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CANIF_Driver_examples_results_screenshots/CANIF_Example3_2_PDU_Tx_2_HOH_2_Notif.png)

* #### CANIF Example 4: Reception single PDU, single Hrh, ID 0x1EF
Hardware board receives (Rx) every second an 8-byte single message with ID 0x1EF and specified Data payload: 32 00 00 00 01 02 03 04. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CANIF_Example4_Reception_single_PDU_single_Hrh_ID_0x1EF.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CANIF_Driver_examples_results_screenshots/CANIF_Example4_Reception_single_PDU_single_Hrh_ID_0x1EF.png)

* #### CANIF Example 4: Reception single PDU, single Hrh, ID 0x010
Hardware board receives (Rx) every second an 8-byte single message with ID 0x010 and specified Data payload: 32 08 07 06 05 04 03 02. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CANIF_Example4_Reception_single_PDU_single_Hrh_ID_0x010.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CANIF_Driver_examples_results_screenshots/CANIF_Example4_Reception_single_PDU_single_Hrh_ID_0x010.png)
