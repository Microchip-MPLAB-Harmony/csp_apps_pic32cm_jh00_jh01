[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# TCC PWM generation

This example application shows how to use the TCC to generate a 2 or 3 phase PWM signals for motor control with dead time.

## Description

TCC module is configured to generate synchronous 2 or 3 phase PWM signals with dead time. The duty cycle of the PWM signals is updated in the period interrupt handler.

## Downloading and building the application

To download or clone this application from Github, go to the [top level of the repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32cm_jh00_jh01) and click

![clone](../../../docs/images/clone.png)

Path of the application within the repository is **apps/tcc/tcc_synchronous_pwm_channels/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_jh00_curiosity_pro.X  | MPLABX project for [PIC32CM JH00 Curiosity Pro Evaluation Kit]() |
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
2. Observe the high-side and low-side PWM waveforms on oscilloscope
3. Observe the dead time between the high side and the low side
4. Observe the pwm frequency to be 10 KHz

[PIC32CM JH00 Curiosity Pro Evaluation Kit]() pin details:

|Signal Name| Pad   | Pin |
|-----------|-------|-----|
| ch0-PWMH  | PA08  | Pin 3 of EXT2 connector |
| ch0-PWML  | PA22  | Pin 9 of EXT1 connector  |
| ch1-PWMH  | PA09  | Pin 4 of EXT2 connector |
| ch1-PWML  | PA23  | Pin 10 of EXT1 connector |
| ch2-PWMH  | PA10  | Pin 5 of EXT1 connector |
| ch2-PWML  | PA20  | Pin 5 of EXT2 connector |
||||


  ![output](images/output_tcc_synchronous_pwm_channels.png)
