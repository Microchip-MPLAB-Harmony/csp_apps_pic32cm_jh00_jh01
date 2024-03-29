---
parent: Harmony 3 peripheral library application examples for PIC32CM JH01 family
title: ADC window sleepwalking
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# ADC window sleepwalking

This application shows how to configure ADC in a sleepwalking operation, where input voltage is measured at a fixed interval, but device is not woken from sleep until the measured value is below a given threshold.

## Description

This example application shows how to use the ADC Peripheral library to perform sleepwalking.
The ADC peripheral is configured to operate in window mode. The ADC conversion is triggered by RTC compare 0 event. On every trigger, window detection operation is performed in standby sleep. The window interrupt is generated when the input voltage falls below the window upper threshold and the CPU is woken up by this interrupt. ADC window upper threshold is configured as 1/4 th of the reference voltage.

| Board | ADC window upper threshold |
| ----- | -------------------------- |
| [PIC32CM JH00 Curiosity Pro]() | 0.825 V |
|||

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_jh00_jh01) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/adc/adc_window_sleepwalking/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_jh01_curiosity_pro.X | MPLABX project for [PIC32CM JH01 Curiosity Pro Evaluation Kit]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_jh01_curiosity_pro.X | [PIC32CM JH01 Curiosity Pro Evaluation Kit]()
|||

### Setting up [PIC32CM JH01 Curiosity Pro Evaluation Kit]()

- Connect a voltage below the selected ADC reference voltage (VDDANA) to pin A4 of J803 (PA10 – ADC0_AIN10)
- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Open the Terminal application (Ex.:Tera term) on the computer
2. Connect to the EDBG Virtual COM port and configure the serial settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None
3. Build and Program the application using its IDE
4. Console displays ADC Window Detected when ADC input is lower than 1/4 th of the reference
voltage (i.e below 0.825 V):

    ![output](images/output_adc_window_sleepwalking.png)
