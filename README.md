# AUTOSAR MCAL Embedded Upskilling Bootcamp

This repo contains the projects, codes, examples, exercises and results for the "[AUTOSAR MCAL Embedded Upskilling Bootcamp](https://embedded-house.ghost.io/tag/autosar-mcal-with-nxp-s32k1xx/)" by [Modular MX](https://www.linkedin.com/company/modular-mx/).

![AUTOSAR_MCAL_Upskilling.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/AUTOSAR_MCAL_Upskilling.png)

Date: July, 2024.

- The [**Certificate and Badge**](https://www.acreditta.com/credential/e82a8595-ae1b-4ffb-b578-efea011bb781?utm_source=copy&resource_type=badge&resource=e82a8595-ae1b-4ffb-b578-efea011bb781) are available.

![Autosar_MCAL_Certificate_Badge.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Autosar_MCAL_Certificate_Badge.png)

## Table of Contents

_<-- Back to [Top of Page](#autosar-mcal-embedded-upskilling-bootcamp)_

1. [**Description**](#1-description)
2. [**Hardware Requirements**](#2-hardware-requirements)
3. [**Software Requirements**](#3-software-requirements)
4. [**Setup Notes**](#4-setup-notes)
5. [**Documentation**](#5-documentation)
6. [**Examples and Exercises**](#6-examples-and-exercises)
7. [**Final Project**](#7-final-project)
8. [**Sample Evidences**](#8-sample-evidences)

## 1. Description

_<-- Back to [Table of Contents](#table-of-contents)_

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
13. Final Project.

What it's covered from the Classic AUTOSAR layers perspective:

![AUTOSAR_layered_view.jpeg](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/AUTOSAR_layered_view.jpeg)

## 2. Hardware Requirements

_<-- Back to [Table of Contents](#table-of-contents)_

**[NXP S32K144-Q100 Evaluation Board for Automotive General Purpose](https://www.nxp.com/design/design-center/development-boards-and-designs/automotive-development-platforms/s32k-mcu-platforms/s32k144-q100-evaluation-board-for-automotive-general-purpose:S32K144EVB)** - Based on the 32-bit Arm® Cortex®-M4F S32K14 MCU, this is the base board used in this bootcamp. 

![S32K144_pinout.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/S32K144_pinout.png)

**[Modular-S1 Board](https://embedded-house.ghost.io/tag/autosar-mcal-with-nxp-s32k1xx/)** - Board developed by Modular MX, comes with a whole new layer of additional peripherals customized specifically for NXP S32K144. Contains 2 potentiometers, 1 buzzer, 3 push buttons, 8 leds, general purpose inputs-outputs, USB Hub, CAN analyzer, 24 MHz logic analyzer, SPI display, 2 SPI Eeproms, and external CAN & LIN analyzer connectors.   

![Modular-S1_Board.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Modular-S1_Board.png)

**NXP S32K144 Board + Modular-S1 Board:**

![NXP-S32K144_Modular-S1.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/NXP-S32K144_Modular-S1.png)

## 3. Software Requirements

_<-- Back to [Table of Contents](#table-of-contents)_

**[EB Tresos Studio](https://www.elektrobit.com/products/ecu/eb-tresos/studio/)** - Tool environment for electronic control unit (ECU) development with AUTOSAR. EB tresos Studio lets you configure, validate, and generate your ECU basic software (BSW). EB tresos Studio is the industry-standard tool for microcontroller abstraction layer (MCAL) development by semiconductor suppliers such as NXP, STM, and Infineon. Works on Windows and is free.

**[SEGGER Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger/)** - Full-featured graphical debugger for embedded applications. It is possible to debug any embedded application on C/C++ source and assembly level, as well as loading applications built with any tool chain / IDE or debug the target's resident application without any source. Ozone includes all well-known debug controls and information windows and makes use of the best performance of J-Link and J-Trace debug probes. Works on Windows/Linux/Mac and is free.

**[SavvyCAN](https://www.savvycan.com/)** - It is a CAN bus reverse engineering and capture tool. SavvyCAN can use any CAN interface supported by QT's SerialBus system (PeakCAN, Vector, SocketCAN, J2534, etc). It can capture and send to multiple buses and CAN capture devices at once. Works on Windows/Linux/Mac and is free. 

## 4. Setup Notes

_<-- Back to [Table of Contents](#table-of-contents)_

* ### 4.1 Tools Installation and Configuration Guide:

_Back to [Setup Notes](#4-setup-notes)_

You can find here [**Setup AUTOSAR Tools**](https://embedded-house.ghost.io/part-0-setup-your-autosar-tools/) the section where Modular MX explains the right procedure to download, install and configure all needed tools, including its dependencies, how to import the template project file and flash it to the device.

As a summary, these are the steps to follow in order to have the environment set up with all tools **FREE** of charge:

#### <ins>For NXP / EB Tresos tools installation:<ins>

_Back to [Setup Notes](#4-setup-notes)_

1. Create your own NXP account.
2. Go to [Real-Time Drivers RTD](https://www.nxp.com/design/design-center/software/automotive-software-and-tools/real-time-drivers-rtd:AUTOMOTIVE-RTD). You should scroll until you reach the Download section for the Real-Time Drivers for S32K1. Click on Download and will open a new website that asks to log-in using your account.

![Setup_image_1.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_1.png)

3. You should have reached this area called _Product Information: Automotive SW - S32K1 - Real-Time Drivers_ where we will download the Real-Time Drivers for S32K1 as well as EB Tresos Studio

![Setup_image_2.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_2.png)

4. First let's download _EB tresos Studio / AUTOSAR Configuration Tool_. Click on the second option and then click on _EB tresos Studio 29.0.0_ which as of now is the latest version.

![Setup_image_3.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_3.png)

5. You will see Software Terms and Conditions, click '_I Agree_' and then we will see the main Product Download section. Download **EBTresosStudio_EBTresosStudio.uip**, **EB_Client_License_Administrator_1_5_1_Setup.exe** and **setup.exe**. Place all the files in a folder, the **EBTresosStudio_EBTresosStudio.uip** might be downloaded automatically as a .zip file. In case it is not, change the file extension from .uip to .zip, then extract. Execute **setup.exe** and click **Install**.

![Setup_image_4.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_4.png)

![Setup_image_19.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_19.png)

6. Once the EB Tresos tool is installed, notice that in the website there was a text highlighted in yellow that contains the chain of characters for the license code. Input that in the EB Client License Administrator.

![Setup_image_5.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_5.png)

7. Now let's download _S32K1_S32M24x - Real-Time Drivers for Cortex-M_. Go back and click on the first option and then download latest version which at the moment of writing this is _S32K1-S32M24X Real Time Drivers AUTOSAR R21-11 Version 2.0.0 P04_.

![Setup_image_2.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_2.png)

![Setup_image_6.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_6.png)

8. <ins>VERY IMPORTANT: At the moment of installing it do not forget to point it out to the EB Tresos install path!<ins>

![Setup_image_7.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_7.png)

9. Now we need a compiler, let's download the GCC NXP one from this [link](https://www.nxp.com/design/design-center/software/development-software/s32-design-studio-ide/s32-design-studio-for-s32-platform:S32DS-S32PLATFORM). Scroll down until you reach the Downloads section and there look up for this item as in the image: _NXP Embedded GCC 10.2 Compiler Tools for ARM v7 Embedded, build 1728 - Windows_. Proceed to install. (Only the compiler is needed, not the S32 Design Studio.)

![Setup_image_8.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_8.png)

![Setup_image_20.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_20.png)

#### <ins>For SEGGER tools installation:<ins>

_Back to [Setup Notes](#4-setup-notes)_

1. For the Debugger, the hardware board provided by [Modular MX](https://www.linkedin.com/company/modular-mx/) is programmed with SEGGER J-Link to flash and debug the microcontroller. In case you acquire separately the NXP S32K144, you need to switch from OpenSDA for J-Link. Go to [**Setup AUTOSAR Tools**](https://embedded-house.ghost.io/part-0-setup-your-autosar-tools/) and perform the steps in section _Switching OpenSDA for J-Link_.

2. After that, drivers are needed so go to [SEGGER J-Link official page](https://www.segger.com/downloads/jlink) and download and install the latest version of J-Link Software and Documentation Pack.

![Setup_image_9.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_9.png)

3. For [SEGGER Ozone Debugger](https://www.segger.com/products/development-tools/ozone-j-link-debugger/) download and install the latest version.

![Setup_image_10.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_10.png)

#### <ins>For importing the EB Tresos template project file:<ins>

_Back to [Setup Notes](#4-setup-notes)_

1. Git clone the project (that also comes with a makefile to compile the basic example in there and run it into the hardware board).

2. Open EB Tresos, go to **File → Import…**, then select **General → Existing Projects into Workspace**, then **Next** and **Browse…** the project folder (the cloned repository), check the template-s144 project and **Finish**. Ignore the warning in the image, is because I already have it in the workspace.

![Setup_image_11.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_11.png)

3. Select the project and double click in **template-s144 → template-s144 (CORTEXM, S32K14X)** to display all the modules in use, then just click the hammer icon _'Generate code for the currently selected project'_.

![Setup_image_12.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_12.png)

4. Might see a warning dialog box regarding Module Configurations. Just ignore, those are not required due to the license type.

![Setup_image_13.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_13.png)

#### <ins>For compiling and flashing the project to the device:<ins>

_Back to [Setup Notes](#4-setup-notes)_

1. You can work your code using VS Code, open the terminal and select **bash** as the shell (please avoid **powershell**). Type 'cd' then leave an empty space ' ' and then drag and drop your project folder to insert the path and then Enter. You should be ready to start compiling. Type '**make**' and wait for it to finish, should see something like this:

![Setup_image_14.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_14.png)

```c
renatosoriano@RENATOSORIAD632 MINGW64 /c/EB/tresos/workspace/template-s144 (master)
$ make
...
...
/c/NXP/gcc-10.2-arm32-eabi/bin/arm-none-eabi-objcopy -Oihex Build/temp.elf Build/temp.hex
/c/NXP/gcc-10.2-arm32-eabi/bin/arm-none-eabi-objdump -S Build/temp.elf > Build/temp.lst
/c/NXP/gcc-10.2-arm32-eabi/bin/arm-none-eabi-size --format=berkeley Build/temp.elf
   text    data     bss     dec     hex filename
  31384      40    2464   33888    8460 Build/temp.elf
```

2. After compiling we can flash the microcontroller using Ozone. Open the program and click in **File → New → New Project Wizard**.

![Setup_image_15.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_15.png)

3. Configure the fields **Device**, **Register Set** and **Peripherals** as in the image below and then clik **Next** two times.

![Setup_image_16.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_16.png)

4. Then in the following page select the .elf file that was generated after Build, then **Next** and **Finish**.

![Setup_image_17.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_17.png)

5. Go to **File → Save Project as...** and select a name for your .jdebug file (recommend the same name as the Tresos project). Then go to **File → Edit Project File...** and a window should open with the .jdebug file code configuration. Go to the note below [4.2 Ozone .jdebug files made portable for running debugger correctly](#42-ozone-jdebug-files-made-portable-for-running-debugger-correctly) to make sure you are configuring correctly and portable your file.

6. Click the first green icon (that looks like a 'Power ON/OFF' icon) to download the binary into the microcontroller. You might see some pop-up small dialog windows while loading, just click 'Yes' and the initial Green icon now should be Red. The program execution is now halted and ready to begin, so click the second icon (currently a 'Play' icon) to **Resume program Execution** and see the hardware board working by blinking an LED.

![Setup_image_18.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Tools_Setup/Setup_image_18.png)

7. And that's it! Don't forget to read Ozone documentation to get familiar with all the amazing functions it provides (call stack, disassembly, registers, memory), it is really powerful.

* ### 4.2 Ozone .jdebug files made portable for running debugger correctly:

_Back to [Setup Notes](#4-setup-notes)_

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

_<-- Back to [Table of Contents](#table-of-contents)_

You can find here [**Documentation**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Documentation/) all reference documents regarding:
* [AUTOSAR Driver Specification.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Documentation/AUTOSAR%20Driver%20Specification)
* [EB Tresos S32K1 MCAL drivers.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Documentation/EB%20Tresos%20MCAL%20Real%20Time%20Drivers)
* [Compiler Manuals.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Documentation/Manuals)
* [NXP S32K144 Board.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Documentation/S32K144%20Board)
* [Modular S-1 Board.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Documentation/Modular%20S-1%20Board)
* [SEGGER Tools.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Documentation/SEGGER)

## 6. Examples and Exercises

_<-- Back to [Table of Contents](#table-of-contents)_

You can find here [**Tresos Workspace**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Tresos_Workspace/) the base template file as well as all the examples and exercises created for this Upskilling Bootcamp.
It is divided in folders for each of the MCAL drivers worked, and inside you will find 2 folders, **Examples** and **Exercises**. For getting started using EB Tresos for ach of the MCAL Modules, highly recommend reading [EB Tresos S32K1 MCAL drivers User Manuals](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Documentation/EB%20Tresos%20MCAL%20Real%20Time%20Drivers), they explain how to configure each MCAL from the EB Tresos GUI perspective.

1. [Templates: Tresos Project and Ozone Semihosting RTT.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/0_Template_Initial_File)
2. [DIO and PORT driver.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/1_DIO_PORT_driver)
3. [MCU driver.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/2_MCU_driver)
4. [GPT Driver.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/3_GPT_driver)
5. [Platform Driver.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/4_Platform_driver)
6. [ADC driver.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/5_ADC_driver)
7. [PWM driver.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/6_PWM_driver)
8. [SPI driver.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/7_SPI_driver)
9. [I/O Hardware Abstraction.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/8_HwIoAb_driver)
10. [CAN driver.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver)
11. [CANIF driver.](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/10_CANIF_driver)

## 7. Final Project

_<-- Back to [Table of Contents](#table-of-contents)_

You can find here the [**Final Project**](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Tresos_Workspace/Final_Project) created for this Upskilling Bootcamp.
It consists on an AUTOSAR I/O Hardware Abstraction for the on board Buttons and LEDs (PORT and DIO Drivers), Potentiometers (MCU and ADC Drivers), and Buzzer (PWM Driver), all together with the Scheduler and a state machine with specific application tasks requirements and the following events, each with particular peripheral behaviors:

**Button 1 Events:**
- [Button 1 Single Click Event](#button-1-single-click)
- [Button 1 Double Click Event](#button-1-double-click)
- [Button 1 Hold and Release Event](#button-1-hold-and-release)

**Button 2 Events:**
- [Button 2 Single Click Event](#button-2-single-click)
- [Button 2 Double Click Event](#button-2-double-click)
- [Button 2 Hold and Release Event](#button-2-hold-and-release)

**Button 3 Events:**
- [Button 3 Single Click Event](#button-3-single-click)
- [Button 3 Double Click Event](#button-3-double-click)
- [Button 3 Hold and Release Event](#button-3-hold-and-release)


### <ins>Button 1 Single Click:<ins>

_Back to [Final Project](#7-final-project)_

* Shall toggle ON/OFF RGB_LED_BLUE (D0) and C10_LED2 (as SINGLE_CLICK visual indicator).

![Button_1_Single_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Single_click.GIF)

https://github.com/user-attachments/assets/7e254285-5b00-4ca3-b0b7-083ebd013bfa

![Button_1_Single_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Single_click_Terminal.png)

### <ins>Button 1 Double Click:<ins>

_Back to [Final Project](#7-final-project)_

* Shall display (SEGGER_RTT_printf) Pot 1 ADC0 value in ohms, toggle C13_LED5 (as DOUBLE_CLICK visual indicator), and toggle C14_LED6 (as Pot 1 visual indicator).

![Button_1_Double_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Double_click.GIF)

https://github.com/user-attachments/assets/9f66e0b6-36a8-45d1-8fdf-4e0b84e6d62f

![Button_1_Double_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Double_click_Terminal.png)

### <ins>Button 1 Hold and Release:<ins>

_Back to [Final Project](#7-final-project)_

* Buzzer shall start to beep and play Tone 1, then stop.

![Button_1_Hold_Release.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Hold_Release.GIF)

https://github.com/user-attachments/assets/b3b2fbca-c40f-4838-b6ee-8cbb92740021

![Button_1_Hold_Release_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_1_Hold_Release_Terminal.png)

### <ins>Button 2 Single Click:<ins>

_Back to [Final Project](#7-final-project)_

* Shall toggle ON/OFF RGB_LED_RED (D15) and C9_LED1 (as SINGLE_CLICK visual indicator).

![Button_2_Single_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Single_click.GIF)

https://github.com/user-attachments/assets/b4d3c5dc-a298-42aa-b5f8-e419363fc6f3

![Button_2_Single_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Single_click_Terminal.png)

### <ins>Button 2 Double Click:<ins>

_Back to [Final Project](#7-final-project)_

* Shall display (SEGGER_RTT_printf) Pot 2 ADC0 value in ohms, toggle C12_LED4 (as DOUBLE_CLICK visual indicator), and toggle C15_LED7 (as Pot 2 visual indicator).

![Button_2_Double_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Double_click.GIF)

https://github.com/user-attachments/assets/9eea159c-86a7-4f8a-8b8b-228dc2623305

![Button_2_Double_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Double_click_Terminal.png)

### <ins>Button 2 Hold and Release:<ins>

_Back to [Final Project](#7-final-project)_

* Buzzer shall start to beep and play Tone 2, then stop.

![Button_2_Hold_Release.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Hold_Release.GIF)

https://github.com/user-attachments/assets/41513747-1fff-478c-84a3-2e4da0ab3ca1

![Button_2_Hold_Release_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_2_Hold_Release_Terminal.png)

### <ins>Button 3 Single Click:<ins>

_Back to [Final Project](#7-final-project)_

* Shall toggle ON/OFF RGB_LED_GREEN (D16) and C8_LED0 (as SINGLE_CLICK visual indicator).

![Button_3_Single_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_3_Single_click.GIF)

https://github.com/user-attachments/assets/2ae425f0-8526-4a7d-ba0b-80b507f2b16e

![Button_3_Single_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_3_Single_click_Terminal.png)

### <ins>Button 3 Double Click:<ins>

_Back to [Final Project](#7-final-project)_

* Shall display (SEGGER_RTT_printf) Pot 1 and Pot 2 ADC1 alternate values in ohms, toggle C11_LED3 (as DOUBLE_CLICK visual indicator), toggle C14_LED6 (as Pot 1 visual indicator), and toggle C15_LED7 (as Pot 2 visual indicator).

![Button_3_Double_click.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_3_Double_click.GIF)

https://github.com/user-attachments/assets/2bfb6ac9-46a6-4cf8-8ef3-cd11ad5b9d95

![Button_3_Double_click_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_3_Double_click_Terminal.png)

### <ins>Button 3 Hold and Release:<ins>

_Back to [Final Project](#7-final-project)_

* Buzzer shall start to beep and play Tone 3, then stop.

![Button_3_Hold_Release.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_3_Hold_Release.GIF)

https://github.com/user-attachments/assets/0583da24-9d69-4de4-affc-c40bbd631f13

![Button_3_Hold_Release_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Final_Project/Button_3_Hold_Release_Terminal.png)

## 8. Sample Evidences

_<-- Back to [Table of Contents](#table-of-contents)_

You can find here captures and media, relevant to examples and exercises, visible output in communication (software) or physical world (board).

- [DIO-PORT Evidences.](#dio-port-driver-evidences)
- [GPT Evidences.](#gpt-driver-evidences)
- [ADC Evidences.](#adc-driver-evidences)
- [PWM Evidences.](#pwm-driver-evidences)
- [SPI Evidences.](#spi-driver-evidences)
- [CAN Evidences.](#can-driver-evidences)
- [CANIF Evidences.](#can-interface-canif-driver-evidences)

### <ins>DIO-PORT Driver Evidences<ins>

_Back to [Sample Evidences](#8-sample-evidences)_

* #### [DIO Exercise 8: Rotate LEDs Left-Right using Buttons](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/1_DIO_PORT_driver/Exercises/DIO_Exercise8_Rotate_LEDs_Left_Right_Buttons)
Pressing 1st button will rotate the LEDs from right to left, and pressing 2nd button will rotate them from left to right. 3rd button activates a different speed.

![DIO_Exercise8_Rotate_LEDs_Left_Right_Buttons.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/DIO_PORT_driver/DIO_Exercise8_Rotate_LEDs_Left_Right_Buttons.GIF)

https://github.com/user-attachments/assets/80e7ae72-599a-454c-8cb2-881933acbc30

### <ins>GPT Driver Evidences<ins>

_Back to [Sample Evidences](#8-sample-evidences)_

* #### [GPT Exercise 1: Two Timers in OneShot mode using FIRC clock to toggle Two LEDs](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/3_GPT_driver/Exercises/GPT_Exercise1_2Timers_OneShot_FIRC_2LEDs)
Using two different timers (FTM1 and FTM2) to toggle two pairs of leds (1st pair: normal led C8 and Blue RGB led, 2nd pair: normal led C9 and Green RGB led) at 100ms and 300ms, both timers use notifications in one shot mode, plus been feed by FIRC clock at 12MHz.

![GPT_Exercise1_2Timers_OneShot_FIRC_2LEDs.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/GPT_driver/GPT_Exercise1_2Timers_OneShot_FIRC_2LEDs.GIF)

https://github.com/user-attachments/assets/193ff80f-5500-420f-af6e-2be51721c8a4

* #### [GPT Exercise 3: Three FTM Timers to toggle all RGB at different Frequencies](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/3_GPT_driver/Exercises/GPT_Exercise3_3Timers_FTM_RGB_DiffClkRef)
Using three FTM timers with one channel each, toggle the three RGB leds at different values (100ms, 400ms, and 800ms), the most important is that each FTM timer is feed by a different clock reference (12MHz, 4MHz, and 8MHz).

![GPT_Exercise3_3Timers_FTM_RGB_DiffClkRef.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/GPT_driver/GPT_Exercise3_3Timers_FTM_RGB_DiffClkRef.GIF)

https://github.com/user-attachments/assets/51c8bdf2-141e-4744-be3b-26aa9c43fdc1

### <ins>ADC Driver Evidences<ins>

_Back to [Sample Evidences](#8-sample-evidences)_

* #### [ADC Exercise 1: Rotate Speed of Eight LEDs with Potentiometer](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/5_ADC_driver/Exercises/ADC_Exercise1_Rotate_Speed_8LEDs_Potentiometer)
Vary the rotation speed of eight LEDs C8 to C15 using one of the potentiometers on the board.

![ADC_Exercise1_Rotate_Speed_8LEDs_Potentiometer.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/ADC_driver/ADC_Exercise1_Rotate_Speed_8LEDs_Potentiometer.GIF)

https://github.com/user-attachments/assets/52fb87fa-588e-4ca8-92fe-8630d8d8d1d9

![ADC_Exercise1_Rotate_Speed_8LEDs_Potentiometer_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/ADC_driver/ADC_Exercise1_Rotate_Speed_8LEDs_Potentiometer_Terminal.png)

* #### [ADC Exercise 2: Two Potentiometers, display Volts and Ohms](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/5_ADC_driver/Exercises/ADC_Exercise2_2PotValues_Ohms_Volts)
Display the values of the two potentiometers in Ohms and Volts.

![ADC_Exercise2_2PotValues_Ohms_Volts_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/ADC_driver/ADC_Exercise2_2PotValues_Ohms_Volts_Terminal.png)

* #### [ADC Exercise 6: Four Channels in ADC0 using Two Potentiometers](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/5_ADC_driver/Exercises/ADC_Exercise6_4Channels_ADC0_2Pots)
Using a jumper wire to connect other channels available from ADC0 to have four channels to sample: 
- Pot 1: pin PTB1->CH5 connected to pin PTB0->CH4 (Blue jumper wire).
- Pot 2: pin PTB13->CH8 (Interleaved, by default ADC0-CH8 is connected to PTC0 but changed to PTB13 using interleave function in code) connected to pin PTC1->CH9 (Purple jumper wire). 

Also configure the hardware average sample with a value of 8, and calculate the total timing conversion for the entire group of channels.

![ADC_Exercise6_4Channels_ADC0_2Pots.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/ADC_driver/ADC_Exercise6_4Channels_ADC0_2Pots.png)

![ADC_Exercise6_4Channels_ADC0_2Pots_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/ADC_driver/ADC_Exercise6_4Channels_ADC0_2Pots_Terminal.png)

ADC0 and ADC1 Interleaved Channels diagram from NXP S32K1xx Reference Manual Rev. 13, page 1194 and 1195: 

![ADC_Exercise6_4Channels_ADC0_2Pots_Interleave.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/ADC_driver/ADC_Exercise6_4Channels_ADC0_2Pots_Interleave.png)

### <ins>PWM Driver Evidences<ins>

_Back to [Sample Evidences](#8-sample-evidences)_

* #### [PWM Exercise 1: Two Channels, Two FTM Timers with SIRC Clock](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/6_PWM_driver/Exercises/PWM_Exercise1_2CH_2Timers_FTM_SIRC_Clk)
A program that generates two PWM channels but using two different timers, must see which pins are available with FTM functionality. Feed those timers with a SIRC clock.
- Timer 1: FTM0, Channel: CH0, Pin: RED RGB LED.
- Timer 2: FTM2, Channel: CH0, Pin: BLUE RGB LED.

Both RGB LEDs working, hence the purple color.

![PWM_Exercise1_2CH_2Timers_FTM_SIRC_Clk.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/PWM_driver/PWM_Exercise1_2CH_2Timers_FTM_SIRC_Clk.png)

* #### [PWM Exercise 2: Two Complementary Channels with DeadTime Insertion](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/6_PWM_driver/Exercises/PWM_Exercise2_2CH_Complementary_DeadTime_Insertion)
Generate two complement PWM signal with dead time insertion of around 1% of the period of the signal.

https://github.com/user-attachments/assets/dade5bbc-cec0-4004-9f04-f78ad7fcd22b

![PWM_Exercise2_2CH_Complementary_DeadTime_Insertion_Tresos.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/PWM_driver/PWM_Exercise2_2CH_Complementary_DeadTime_Insertion_Tresos.png)

'_Paired channel enable_' Tresos feature: The channels n and n+1 will be used as a channel pair.
In this case the pair is Red RGB Led (FTM0-CH0) for 'channel n' and Green RGB Led (FTM0-CH1) for 'channel n+1'.

'_Complementary channel enable_' Tresos feature: Enable the complementary mode for Ftm channel.
In Complementary mode, the channel (n+1) output (Green RGB Led) is the inverse of the channel (n) output (Red RGB Led).

'_Complementary mode_' Tresos feature: Selects complementary mode of the Ftm channel n+1.
Here we confirm that the desired mode is 'Invert Output'. Hence when one RGB Led goes OFF the other goes ON and viceversa.

'_Deadtime enable_' Tresos feature: Enable the deadtime delay for Ftm channel.
The deadtime delay insertion ensures that no two complementary signals (channels n and n+1) drive the active state at the same time.

'_Phase Shift (Ticks)_' Tresos feature: Define the offset value (in tick) from 1 that the leading edge of pulse signal will start.
In this case it is wanted to be 1% of the period, so the 375 ticks value is the 1% of the 37500 period value configured for the channels.

Channel (n+1) output in Complementary mode diagram from NXP S32K1xx Reference Manual Rev. 13, page 1448: 

![PWM_Exercise2_2CH_Complementary_DeadTime_Insertion_ComplementaryMode.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/PWM_driver/PWM_Exercise2_2CH_Complementary_DeadTime_Insertion_ComplementaryMode.png)

* #### [PWM Exercise 4: ADC Potentiometer modifies PWM DutyCycle of RGB LED](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/6_PWM_driver/Exercises/PWM_Exercise4_ADC_Pot_DutyCycle_RGB_LED)
Used a potentiometer to variate the PWM duty cycle, connected to Blue RGB led, from 10% to 90% in steps of 10%.
Two available methods, with and without steps, can be found in code with algorithm explained.

https://github.com/user-attachments/assets/a163665e-de78-469f-a384-a67201327c4e

![PWM_Exercise4_ADC_Pot_DutyCycle_RGB_LED_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/PWM_driver/PWM_Exercise4_ADC_Pot_DutyCycle_RGB_LED_Terminal.png)

### <ins>SPI Driver Evidences<ins>

_Back to [Sample Evidences](#8-sample-evidences)_

* #### [SPI Exercise 1: Read and Print 32 bytes from EEPROM](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/7_SPI_driver/Exercises/SPI_Exercise1_ReadPrint_32bytes_EEPROM_ASCII)
Read and display the first 32 bytes of an Eeprom in different formats using Semihosting with RTT.

![SPI_Exercise1_ReadPrint_32bytes_EEPROM_ASCII_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/SPI_driver/SPI_Exercise1_ReadPrint_32bytes_EEPROM_ASCII_Terminal.png)

* #### [SPI Exercise 4: Create Two Functions to Write and Read a Byte](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/7_SPI_driver/Exercises/SPI_Exercise4_Function_Write_Read_Byte)
Wrote two functions that allow to write and read a byte to any valid memory address in the Eeprom memory, functions shall have the following prototypes:
- void write_byte( uint16 addr, uint8 data );
- uint8_t read_byte( uint16_t addr );

![SPI_Exercise4_Function_Write_Read_Byte_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/SPI_driver/SPI_Exercise4_Function_Write_Read_Byte_Terminal.png)

* #### [SPI Exercise 5: Create Two Functions to Write and Read Data from an Array of any Size of Bytes](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/7_SPI_driver/Exercises/SPI_Exercise5_Function_Write_Read_ArrayData)
Wrote the following functions to allow to write a given array of n number of bytes starting at any address of the eeprom:
- void write_data( uint16 addr, uint8 *data, uint8 size );
- void read_data( uint16 addr, uint8 *data, uint8 size );

![SPI_Exercise5_Function_Write_Read_ArrayData_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/SPI_driver/SPI_Exercise5_Function_Write_Read_ArrayData_Terminal.png)

### <ins>CAN Driver Evidences<ins>

_Back to [Sample Evidences](#8-sample-evidences)_

* #### [CAN Example 3: Transmission using Interrupts (ISRs)](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver/Examples/CAN_Example3_Transmission_using_Interrupts)
Hardware board transmits (Tx) an 8-byte single message with ID 0x123 and specified Data payload: 01 02 03 04 05 06 11 12. Savvy CAN receiving (Rx) the data, everytime having byte 1 and 8 increased by value of 0x1 as per the example intentional behavior.

![CAN_Example3_Transmission_using_Interrupts.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example3_Transmission_using_Interrupts.png)

* #### [CAN_Example 4: Reception using Interrupts (ISRs), Dataset 1](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver/Examples/CAN_Example4_Reception_using_Interrupts)
Hardware board receives (Rx) an 8-byte single message with ID 0x010 and specified Data payload: 32 01 01 01 01 01 01 01. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CAN_Example4_Reception_using_Interrupts_Dataset1.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example4_Reception_using_Interrupts_Dataset1.png)

* #### [CAN_Example 4: Reception using Interrupts (ISRs), Dataset 2](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver/Examples/CAN_Example4_Reception_using_Interrupts)
Similar as previous, hardware board receives (Rx) an 8-byte single message with ID 0x010 and specified Data payload: 32 08 07 06 05 04 03 02. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CAN_Example4_Reception_using_Interrupts_Dataset2.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example4_Reception_using_Interrupts_Dataset2.png)

* #### [CAN Example 5: Transmission Mailboxes Buffers](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver/Examples/CAN_Example5_Transmission_Mailboxes_Buffers)
Hardware board transmits (Tx) three 8-byte messages with ID 0x123, 0x133 and 0x143, all having the same specified Data payload: 01 02 03 04 05 06 11 12. Savvy CAN receiving (Rx) the data, everytime having byte 1 and 8 increased by value of 0x1 as per the example intentional behavior.

![CAN_Example5_Transmission_Mailboxes_Buffers.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example5_Transmission_Mailboxes_Buffers.png)

* #### [CAN Example 6: Reception with Filters, ID 0x1EF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver/Examples/CAN_Example6_Reception_with_Filters)
Hardware board receives (Rx) every second an 8-byte single message with ID 0x1EF and specified Data payload: 32 00 00 00 01 02 03 04. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CAN_Example6_Reception_with_Filters_ID_0x1EF.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example6_Reception_with_Filters_ID_0x1EF.png)

* #### [CAN Example 6: Reception with Filters, ID 0x022](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver/Examples/CAN_Example6_Reception_with_Filters)
Hardware board receives (Rx) every second an 8-byte single message with ID 0x022 and specified Data payload: 32 00 00 00 05 06 07 08. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CAN_Example6_Reception_with_Filters_ID_0x022.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_Driver_examples_results_screenshots/CAN_Example6_Reception_with_Filters_ID_0x022.png)

* #### [CAN Exercise 3: Button Transmits Messages](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver/Exercises/CAN_Exercise3_Button_Tx_MsgID_01_02)
Program that, upon pressing the button on the board, transmits a message with identifier 0x001 to the CAN bus, and upon releasing it, transmits a message with an identifier of 0x002.
Hardware board transmits (Tx) two 8-byte messages with ID 0x001 and 0x002, all having the same specified Data payload: 01 02 03 04 05 06 11 12. Savvy CAN receiving (Rx) the data, everytime having byte 1 and 8 increased by value of 0x1 as per the exercise intentional behavior.

![CAN_Exercise3_Button_Tx_MsgID_01_02.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_driver/CAN_Exercise3_Button_Tx_MsgID_01_02.png)

* #### [CAN Exercise 4: Three Buttons, Transmits a Message with Three Different Datasets](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver/Exercises/CAN_Exercise4_3Buttons_Tx_1Msg_3Data)
A program that senses three buttons and, upon pressing each one, sends a message indicating which button was pressed. Interrupts used in this program.
Hardware board transmits (Tx) an 8-byte message with ID 0x154, having the default Data payload: 00 00 00 00 00 00 00 00 that then will have the last byte changed to 01, 02 or 03 depending on which button is pressed. Savvy CAN receiving (Rx) the data.

![CAN_Exercise4_3Buttons_Tx_1Msg_3Data.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_driver/CAN_Exercise4_3Buttons_Tx_1Msg_3Data.png)

* #### [CAN Exercise 5: Three Buttons, Transmits Three Message with Three Different Datasets](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver/Exercises/CAN_Exercise5_3Buttons_Tx_3Msg_3Data)
Previous program modified (Exercise 4) so that each message is sent with a different CAN-ID.
Hardware board transmits (Tx) three 8-byte messages with ID 0x154, ID 0x233 and ID 0x382, having all default Data payload: 00 00 00 00 00 00 00 00 that then will have the last byte changed to 01, 02 or 03 depending on which button is pressed. Savvy CAN receiving (Rx) the data.

![CAN_Exercise5_3Buttons_Tx_3Msg_3Data.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_driver/CAN_Exercise5_3Buttons_Tx_3Msg_3Data.png)

* #### [CAN Exercise 7: Three LEDs, Receives Three Message with Three Different Datasets](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/9_CAN_driver/Exercises/CAN_Exercise7_3LEDs_Rx_3Msg_3Data)
A program that receives three CAN messages, each with a different CAN-ID, and where the first 2 bytes (for two messages) and 3 bytes (for third message) indicate the time for an LED to blink. Use a separate LED for each message.
Hardware board receives (Rx) three 8-byte messages with ID 0x154, ID 0x233 and ID 0x382, having all default Data payload except for the first 2 to 3 bytes that change to an specific value that represents the time in ms for the LEDs to toggle. Savvy CAN transmits (Tx) the data, with each message configured in the Frame Sender window.

![CAN_Exercise7_3LEDs_Rx_3Msg_3Data.GIF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_driver/CAN_Exercise7_3LEDs_Rx_3Msg_3Data.GIF)

https://github.com/user-attachments/assets/0d01ac11-7a19-4fc8-977a-b5de0ad759e0

![CAN_Exercise7_3LEDs_Rx_3Msg_3Data_Terminal.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CAN_driver/CAN_Exercise7_3LEDs_Rx_3Msg_3Data_Terminal.png)

### <ins>CAN Interface (CANIF) Driver Evidences<ins>

_Back to [Sample Evidences](#8-sample-evidences)_

* #### [CANIF Example 1: Transmission single PDU](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/10_CANIF_driver/Examples/CANIF_Example1_Transmission_single_PDU)
Hardware board transmits (Tx) an 8-byte single message with ID 0x123 and specified Data payload: 01 02 03 04 05 06 11 12. Savvy CAN receiving (Rx) the data, everytime having byte 1 and 8 increased by value of 0x1 as per the example intentional behavior.

![CANIF_Example1_Transmission_single_PDU.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CANIF_Driver_examples_results_screenshots/CANIF_Example1_Transmission_single_PDU.png)

* #### [CANIF Example 2: Two PDUTx, one single HOH](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/10_CANIF_driver/Examples/CANIF_Example2_Two_PDU_Tx_one_single_HOH)
Hardware board transmits (Tx) two 8-byte messages with ID 0x123 and 0x124, all having the same specified Data payload: 01 02 03 04 05 06 11 12. Savvy CAN receiving (Rx) the data, everytime having byte 1 and 8 increased by value of 0x1 as per the example intentional behavior.

![CANIF_Example2_Two_PDU_Tx_one_single_HOH.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CANIF_Driver_examples_results_screenshots/CANIF_Example2_Two_PDU_Tx_one_single_HOH.png)

* #### [CANIF Example 3: Two PDUTx, Two HOH, Two Notifications](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/10_CANIF_driver/Examples/CANIF_Example3_2_PDU_Tx_2_HOH_2_Notif)
Hardware board transmits (Tx) two 8-byte messages with ID 0x123 and 0x124, all having the same specified Data payload: 01 02 03 04 05 06 11 12. Each message has its own interrupt callback function to indicate that the message was transmitted. Savvy CAN receiving (Rx) the data, everytime having byte 1 and 8 increased by value of 0x1 as per the example intentional behavior.

![CANIF_Example3_2_PDU_Tx_2_HOH_2_Notif.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CANIF_Driver_examples_results_screenshots/CANIF_Example3_2_PDU_Tx_2_HOH_2_Notif.png)

* #### [CANIF Example 4: Reception single PDU, single Hrh, ID 0x1EF](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/10_CANIF_driver/Examples/CANIF_Example4_Reception_single_PDU_single_Hrh)
Hardware board receives (Rx) every second an 8-byte single message with ID 0x1EF and specified Data payload: 32 00 00 00 01 02 03 04. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CANIF_Example4_Reception_single_PDU_single_Hrh_ID_0x1EF.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CANIF_Driver_examples_results_screenshots/CANIF_Example4_Reception_single_PDU_single_Hrh_ID_0x1EF.png)

* #### [CANIF Example 4: Reception single PDU, single Hrh, ID 0x010](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/10_CANIF_driver/Examples/CANIF_Example4_Reception_single_PDU_single_Hrh)
Hardware board receives (Rx) every second an 8-byte single message with ID 0x010 and specified Data payload: 32 08 07 06 05 04 03 02. Savvy CAN transmits (Tx) the data. Notice how in code we can establish a condition, in this case where the first byte must be 0x32 and once that is confirmed, can proceed and receive the rest of the data.

![CANIF_Example4_Reception_single_PDU_single_Hrh_ID_0x010.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/CANIF_Driver_examples_results_screenshots/CANIF_Example4_Reception_single_PDU_single_Hrh_ID_0x010.png)

* #### [CANIF Exercise 3: Button Transmits Messages](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/10_CANIF_driver/Exercises/CANIF_Exercise3_Button_Tx_MsgID_01_02)
Same exercise and output as [CAN Exercise 3: Button Transmits Messages](#can-exercise-3-button-transmits-messages) but this time configured and implemented using CAN Interface module from the Communication Hardware Abstraction layer.

* #### [CANIF Exercise 4: Three Buttons, Transmits a Message with Three Different Datasets](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/10_CANIF_driver/Exercises/CANIF_Exercise4_3Buttons_Tx_1Msg_3Data)
Same exercise and output as [CAN Exercise 4: Three Buttons, Transmits a Message with Three Different Datasets](#can-exercise-4-three-buttons-transmits-a-message-with-three-different-datasets) but this time configured and implemented using CAN Interface module from the Communication Hardware Abstraction layer.

* #### [CANIF Exercise 5: Three Buttons, Transmits Three Message with Three Different Datasets](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/10_CANIF_driver/Exercises/CANIF_Exercise5_3Buttons_Tx_3Msg_3Data)
Same exercise and output as [CAN Exercise 5: Three Buttons, Transmits Three Message with Three Different Datasets](#can-exercise-5-three-buttons-transmits-three-message-with-three-different-datasets) but this time configured and implemented using CAN Interface module from the Communication Hardware Abstraction layer.

* #### [CANIF Exercise 7: Three LEDs, Receives Three Message with Three Different Datasets](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/tree/main/Tresos_Workspace/10_CANIF_driver/Exercises/CANIF_Exercise7_3LEDs_Rx_3Msg_3Data)
Same exercise and output as [CAN Exercise 7: Three LEDs, Receives Three Message with Three Different Datasets](#can-exercise-7-three-leds-receives-three-message-with-three-different-datasets) but this time configured and implemented using CAN Interface module from the Communication Hardware Abstraction layer.
