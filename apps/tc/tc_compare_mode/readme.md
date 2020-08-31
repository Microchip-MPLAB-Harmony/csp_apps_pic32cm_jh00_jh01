---
parent: Harmony 3 peripheral library application examples for PIC32CM JH01 family
title: TC compare mode 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# TC compare mode

This example shows how to use the TC module in compare mode to generate an active low, active high, and toggle output on compare match.

## Description

Three TC channels are configured in compare mode. Each channel generates different output waveform depending upon configured action on compare match and period match.

**Active low output**: Output is set high on compare 1 match and is
set low on compare 0 match.

**Active high output**: Output is set low on compare 1 match and is
set high on compare 0 match.

**Toggle output**: Output toggles on compare 0 match.

## Downloading and building the application

To download or clone this application from Github, go to the [top level of the repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_jh00_ls00) and click

![clone](../../../docs/images/clone.png)

Path of the application within the repository is **apps/tc/tc_compare_mode/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ------------------- | ---------------------------------------------- |
| pic32cm_jh00_curiosity_pro.X | MPLABX project for [PIC32CM JH00 Curiosity Pro Evaluation Kit]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_jh00_curiosity_pro.X | [PIC32CM JH00 Curiosity Pro Evaluation Kit]()
|||

### Setting up [PIC32CM JH00 Curiosity Pro Evaluation Kit]()

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Build and Program the application using its IDE
2. Observe generated waveforms on the oscilloscope

| Timer Channel   | Pin      | Observable characteristic of the waveform
| ----------------| ---------| -----------------------------------------|
| TC0_WO1 | PB09 (Pin 3 of EXT1)  | Active low ouptut with 75 Hz frequency |
| TC2_WO1 | PB03 (Pin 15 of EXT2)  | Active high output with 75 Hz frequency |
| TC3_WO0 | PB00 (Pin 16 of EXT2)  | Toggle output with 37.5 Hz frequency |
||||
