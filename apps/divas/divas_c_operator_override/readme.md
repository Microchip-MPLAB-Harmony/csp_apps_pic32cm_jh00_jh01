---
parent: Harmony 3 peripheral library application examples for PIC32CM JH01 family
title: DIVAS override C division operator 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# DIVAS override C division operator

This example application demonstrates how to override C division operator and modulus operator to use the DIVAS accelerator.

## Description

The Divide and Square Root Accelerator (DIVAS) is a programmable 32-bit signed or unsigned hardware divider and a 32-bit unsigned square root hardware engine. The DIVAS takes dividend and divisor values and returns the quotient and remainder when it is used as divider. A simpler way of using the DIVAS is making it invisible to the programmer. This example application shows how to use the DIVAS Peripheral library to override C division and modulus operator. When compiler compiles the statements containing division operator ('/') and modulus operator ('%'), it uses DIVAS APIs instead of C Library. Unfortunately, it is not possible for square root because square root does not have a C intrinsic operator.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_jh01) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/divas/divas_c_operator_override/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_jh01_curiosity_pro.X | MPLABX project for [PIC32CM JH01 Curiosity Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/) |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_jh01_curiosity_pro.X | [PIC32CM JH01 Curiosity Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/)
|||

### Setting up [PIC32CM JH01 Curiosity Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/)

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
4. Observe output message in console as follows:

    ![output](images/output_divas_c_operator_overide.png)
