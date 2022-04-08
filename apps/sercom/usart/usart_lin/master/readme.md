---
parent: Harmony 3 peripheral library application examples for PIC32CM JH01 family
title: SERCOM USART LIN Master
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# SERCOM USART LIN Master

This example application demonstrates how to use the SERCOM USART peripheral in LIN Master mode

## Description

In this example, the LIN Master reads LED0 and SW0 status of the LIN Slave every 250 milliseconds by sending a LIN receive command containing three fields: break, sync and indentifier (ID). The LIN Slave responds with 1 byte data containing the SW0 status (Bit[0]) and LED0 status (Bit[1]) followed by the Checksum byte. 

Upon receiving the response, LIN Master checks if the SW0 status is in pressed or released state. If the SW0 is pressed, the LIN Master toggles the state of receieved LED0 status and asks the LIN Slave to set the LED0 to the new state (set LED0 to OFF state if LED0 was previously ON and vice-versa) by sending a LIN transmit command.

For this example, the checksum algorithm is defined as enhanced meaning it is calculated by summing and data bytes along with the Protected ID (PID).

- PID for reading LED0 and SW0 status - 0x80 (Frame ID - 0x00).
- PID for writing LED0 status - 0xC1 (Frame ID - 0x01).

The example uses enhanced checksum.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_jh00_jh01) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/sercom/usart/usart_lin/master/firmware****.

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_jh01_curiosity_pro.X | MPLABX project for [PIC32CM JH01 Curiosity Pro Evaluation Kit] |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_jh01_curiosity_pro.X  | [PIC32CM JH01 Curiosity Pro Evaluation Kit]()
|||

Hardware setup requires two boards, one acting as the LIN Master and the other as the LIN slave.

### Setting up [PIC32CM JH01 Curiosity Pro Evaluation Kit]()

- Enable Master node pull-up by mounting the jumper on J501 connector
- Mount the jumper on J500 connector to power the LIN transceiver from the on board VCC.
- Connect a wire from "LIN" on J503 on LIN Master board to "LIN" on J503 on LIN slave board
- Connect a wire from "GND" on J503 on LIN Master board to "GND" on J503 on LIN slave board
- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Build and Program LIN master and LIN slave applications using its IDE. Path of the LIN Slave application within the repository is **apps/sercom/usart/usart_lin/slave/firmware**.
2. Press SW0 on LIN Master board to start the communication. LIN Master will start reading LED0 and SW0 status from the LIN slave every 250 milliseconds.
3. Press SW0 on the LIN Slave board. The LED0 on the LIN Slave board will toggle if the SW0 is pressed.
4. The following table provides the LED0 and SW0 names

| Board| LED0 name|
|------|---------|
| [PIC32CM JH01 Curiosity Pro Evaluation Kit]() | LED0 | SW0 |
|||
