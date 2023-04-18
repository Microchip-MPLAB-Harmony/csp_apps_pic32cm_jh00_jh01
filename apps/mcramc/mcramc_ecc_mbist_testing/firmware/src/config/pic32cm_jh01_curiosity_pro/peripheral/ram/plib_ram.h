/*******************************************************************************
  (RAM) PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ram.h

  Summary:
    RAM PLIB Header file

  Description:
    This file defines the interface to the RAM peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef PLIB_RAM_H
#define PLIB_RAM_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "device.h"
#include "interrupts.h"

#ifdef __cplusplus // Provide C++ Compatibility
extern "C" {
#endif


#define RAM_ECC_STATUS_NONE      0U
// Single Bit Error
#define RAM_ECC_STATUS_SERR      MCRAMC_INTSTA_SERR_Msk
// Double Bit Error
#define RAM_ECC_STATUS_DERR      MCRAMC_INTSTA_DERR_Msk

typedef uint32_t RAM_ECC_STATUS;

typedef void (*RAM_ECC_CALLBACK)(RAM_ECC_STATUS status, uintptr_t context);

typedef struct
{
    RAM_ECC_CALLBACK callback;
    uintptr_t context;
}RAM_ECC_CALLBACK_OBJ;

void RAM_ECC_Initialize(void);

void RAM_ECC_SingleBitFaultInject(uint32_t fltaddr, uint8_t fltBitPtr);

void RAM_ECC_DoubleBitFaultInject(uint32_t fltaddr, uint8_t flt1BitPtr, uint8_t flt2BitPtr);

void RAM_ECC_Enable(void);

void RAM_ECC_Disable(void);

void RAM_ECC_FaultEnable(void);

void RAM_ECC_FaultDisable(void);

uint32_t RAM_ECC_FaultCaptureAddrGet(void);

uint8_t RAM_ECC_FaultCaptureSyndromeGet(void);

uint8_t RAM_ECC_FaultCaptureParityGet(void);

void RAM_ECC_CallbackRegister (RAM_ECC_CALLBACK callback, uintptr_t context);


bool RAM_Read( uint32_t *data, uint32_t length, uint32_t address);

bool RAM_Write( uint32_t *data, uint32_t length, uint32_t address);

bool RAM_IsBusy(void);

#ifdef __cplusplus  // Provide C++ Compatibility
}
#endif

#endif /* PLIB_RAM_H */
