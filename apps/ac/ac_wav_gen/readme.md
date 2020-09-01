---
parent: Harmony 3 peripheral library application examples for PIC32CM JH01 family
title: AC PWM generation 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# AC PWM generation

This example application shows how to use the Analog Comparator Peripheral library to generate a 1KHz PWM waveform.

## Description

The AC peripheral is configured to generate analog PWM waveform by comparing the sine wave generated from the DAC with the reference voltage selected as a VDD scaler. The duty cycle of the analog PWM is changed by pressing a switch which changes the value of the VDD scaler.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_jh00_jh01) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/ac/ac_wav_gen/firmware** .

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

- Use a jumper wire to connect pin PB06 "Pin 4 of the EXT3 connector" and PA02 "Pin DAC_VOUT on the DAC Header"
- Use the Logic Analyzer/Oscilloscope and probe PB12 pin (Pin 7 of the EXT2 header) to observe the PWM output
- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Build and Program the application using its IDE
2. Observe the PWM waveform using the oscilloscope connected to the PWM output pin

    ![output_2](images/output_ac_wav_gen_2.png)

3. Press switch to change the duty cycle of PWM waveform

Refer to the following table for pwm output and switch details:

| Board | PWM output pin | Switch|
|------|----------------| ------ |
| [PIC32CM JH01 Curiosity Pro Evaluation Kit]() | PB12 pin (Pin 7 of the EXT2 header) | SW0 ||
|||
