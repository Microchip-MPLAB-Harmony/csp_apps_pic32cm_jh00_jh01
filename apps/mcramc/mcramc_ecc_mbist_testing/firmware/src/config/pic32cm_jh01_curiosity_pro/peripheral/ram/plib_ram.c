/*******************************************************************************
  RAM PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ram.c

  Summary:
    RAM PLIB Implementation file

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

#include <string.h>
#include "plib_ram.h"


volatile static RAM_ECC_CALLBACK_OBJ RAM_ECC_CallbackObject;


void RAM_ECC_Initialize(void)
{

    MCRAMC_REGS->MCRAMC_INTENSET = MCRAMC_INTENSET_SERREN_Msk | MCRAMC_INTENSET_DERREN_Msk;
}

void RAM_ECC_SingleBitFaultInject(uint32_t fltaddr, uint8_t fltBitPtr)
{
    /* Disable fault injection */
    MCRAMC_REGS->MCRAMC_FLTCTRL &= ~MCRAMC_FLTCTRL_FLTEN_Msk;

    // Dummy Read back for synchronization purpose
    while ((MCRAMC_REGS->MCRAMC_FLTCTRL & MCRAMC_FLTCTRL_FLTEN_Msk) != 0U)
    {
        /* Wait for read back to complete */
    }

    /* Set the fault address */
    MCRAMC_REGS->MCRAMC_FLTADR = MCRAMC_FLTADR_FLTADR (fltaddr);

    /* Set the fault bit position */
    MCRAMC_REGS->MCRAMC_FLTPTR = MCRAMC_FLTPTR_FLT1PTR (fltBitPtr);

    /* Set the single bit fault mode */
    MCRAMC_REGS->MCRAMC_FLTCTRL = (MCRAMC_REGS->MCRAMC_FLTCTRL & ~MCRAMC_FLTCTRL_FLTMD_Msk) | MCRAMC_FLTCTRL_FLTMD(0x1) | MCRAMC_FLTCTRL_FLTEN_Msk;

    // Dummy Read back for synchronization purpose
    while  (MCRAMC_REGS->MCRAMC_FLTCTRL != (MCRAMC_FLTCTRL_FLTMD(0x1) | MCRAMC_FLTCTRL_FLTEN_Msk))
    {
        /* Wait for read back to complete */
    }
}

void RAM_ECC_DoubleBitFaultInject(uint32_t fltaddr, uint8_t flt1BitPtr, uint8_t flt2BitPtr)
{
    /* Disable fault injection */
    MCRAMC_REGS->MCRAMC_FLTCTRL &= ~MCRAMC_FLTCTRL_FLTEN_Msk;

    // Dummy Read back for synchronization purpose
    while ((MCRAMC_REGS->MCRAMC_FLTCTRL & MCRAMC_FLTCTRL_FLTEN_Msk) != 0U)
    {
        /* Wait for read back to complete */
    }

    /* Set the fault address */
    MCRAMC_REGS->MCRAMC_FLTADR = MCRAMC_FLTADR_FLTADR (fltaddr);

    /* Set the fault bit position */
    MCRAMC_REGS->MCRAMC_FLTPTR = MCRAMC_FLTPTR_FLT1PTR (flt1BitPtr) | MCRAMC_FLTPTR_FLT2PTR (flt2BitPtr);

    /* Set the double bit fault mode */
    MCRAMC_REGS->MCRAMC_FLTCTRL = (MCRAMC_REGS->MCRAMC_FLTCTRL & ~MCRAMC_FLTCTRL_FLTMD_Msk) | MCRAMC_FLTCTRL_FLTMD(0x2) | MCRAMC_FLTCTRL_FLTEN_Msk;

    // Dummy Read back for synchronization purpose
    while  (MCRAMC_REGS->MCRAMC_FLTCTRL != (MCRAMC_FLTCTRL_FLTMD(0x2) | MCRAMC_FLTCTRL_FLTEN_Msk))
    {
        /* Wait for read back to complete */
    }
}

void RAM_ECC_Enable(void)
{
    MCRAMC_REGS->MCRAMC_CTRLA |= MCRAMC_CTRLA_ENABLE_Msk;
}

void RAM_ECC_Disable(void)
{
    MCRAMC_REGS->MCRAMC_CTRLA &= ~MCRAMC_CTRLA_ENABLE_Msk;
}

void RAM_ECC_FaultEnable(void)
{
    MCRAMC_REGS->MCRAMC_FLTCTRL |= MCRAMC_FLTCTRL_FLTEN_Msk;
}

void RAM_ECC_FaultDisable(void)
{
    MCRAMC_REGS->MCRAMC_FLTCTRL &= ~MCRAMC_FLTCTRL_FLTEN_Msk;
}

uint32_t RAM_ECC_FaultCaptureAddrGet(void)
{
    return MCRAMC_REGS->MCRAMC_ERRCADR;
}

uint8_t RAM_ECC_FaultCaptureSyndromeGet(void)
{
    return (uint8_t)(MCRAMC_REGS->MCRAMC_ERRCSYN & MCRAMC_ERRCSYN_ERCSYN_Msk);
}

uint8_t RAM_ECC_FaultCaptureParityGet(void)
{
    return (uint8_t)(MCRAMC_REGS->MCRAMC_ERRCPAR & MCRAMC_ERRCPAR_ERCPAR_Msk);
}

void RAM_ECC_CallbackRegister (RAM_ECC_CALLBACK callback, uintptr_t context)
{
    /* Register callback function */
    RAM_ECC_CallbackObject.callback = callback;
    RAM_ECC_CallbackObject.context = context;
}

void __attribute__((used)) RAM_ECC_InterruptHandler ( void )
{
    if (MCRAMC_REGS->MCRAMC_INTENSET != 0U)
    {
        RAM_ECC_STATUS status;
        status = MCRAMC_REGS->MCRAMC_INTSTA;

        /* Clear interrupt */
        MCRAMC_REGS->MCRAMC_INTSTA = status;
        while ((MCRAMC_REGS->MCRAMC_INTSTA & status) != 0U)
        {
            /* Wait for the interrupt status to clear */
        }
        if ((RAM_ECC_CallbackObject.callback != NULL) && (status != RAM_ECC_STATUS_NONE))
        {
            uintptr_t context = RAM_ECC_CallbackObject.context;
            RAM_ECC_CallbackObject.callback(status, context);
        }
    }
}

bool RAM_Read( uint32_t *data, uint32_t length, uint32_t address )
{
    uint32_t *p_address = (uint32_t*)address;
    (void) memcpy(data, p_address, length);
    return true;
}

bool RAM_Write( uint32_t *data, uint32_t length, uint32_t address )
{
    uint32_t *p_address = (uint32_t*)address;
    (void) memcpy(p_address, data, length);
    return true;
}

bool RAM_IsBusy(void)
{
    return false;
}