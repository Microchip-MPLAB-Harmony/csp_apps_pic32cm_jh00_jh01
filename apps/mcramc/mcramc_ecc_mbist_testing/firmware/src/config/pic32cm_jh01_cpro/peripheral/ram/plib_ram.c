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

static MCRAMC_CALLBACK_OBJ MCRAMC_CallbackObject;

bool RAM_Read( uint32_t *data, uint32_t length, const uint32_t address )
{
    memcpy((void *)data, (void *)address, length);
    
    return true;
}

bool RAM_Write( uint32_t *data, uint32_t length, uint32_t address )
{
    memcpy((void *)address, (void *)data, length);
    
    return true;
}

bool RAM_IsBusy(void)
{
    return false;
}

void MCRAMC_CallbackRegister (MCRAMC_CALLBACK callback, uintptr_t context)
{
    // Register callback function
    MCRAMC_CallbackObject.callback = callback;
    MCRAMC_CallbackObject.context = context;
}

void MCRAMC_InterruptHandler ( void )
{
    if (MCRAMC_REGS->MCRAMC_INTENSET != 0U)
    {
        MCRAMC_STATUS status;
        status = MCRAMC_REGS->MCRAMC_INTSTA;
        
        // Clear interrupt
        MCRAMC_REGS->MCRAMC_INTSTA = (uint32_t)MCRAMC_INTSTA_Msk;
        if ((status != MCRAMC_STATUS_NONE) && MCRAMC_CallbackObject.callback != NULL)
            MCRAMC_CallbackObject.callback(status, MCRAMC_CallbackObject.context);
    }
}
