/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Application Functions and Variables
// *****************************************************************************
// *****************************************************************************

// Flash and Data Flash Addresses where data with error(s) will be stored
#define FLASH_WRITE_ADDR      0x9000
#define DATAFLASH_WRITE_ADDR  0x401000

uint8_t cmd = 0;
bool first_iteration = true;

uint8_t secout = 0;
uint8_t secin = 0;
uint8_t syndrome = 0;

uint32_t data [NVMCTRL_PAGE_SIZE] = {0};
uint32_t data_read [NVMCTRL_PAGE_SIZE] = {0};
uint32_t data_length = 32;
volatile uint32_t intFlag = 0;

enum
{
    SINGLE_FAULT_INJECTION = 'a',
    DOUBLE_FAULT_INJECTION = 'b'
} ECC_TESTING_MEMORY;

void display_menu (void)
{
    printf ("Select the test to launch: \n\r");
    printf ("a) Single Fault Injection on Writes\n\r");
    printf ("b) Double Fault Injection on Writes\n\r");
    printf ("Enter your choice: ");
    scanf ("%c", &cmd);
    printf("\n\n\r");
}

void NVMCTRL_EventHandler (uintptr_t context)
{
    intFlag = NVMCTRL_InterruptFlagGet();    
}

void fault_injection_routine ( uint32_t address )
{
    data[0] = 0xA5A5A5A5;
    data[1] = 0x12345678;
    
    // Page Buffer is filled with data values. Only the first two Page Buffer words are non-zero values
    NVMCTRL_PageBufferWrite (data, address);
    
    // Write filled Page Buffer at address (Flash or Data Flash address)
    NVMCTRL_PageBufferCommit (address);
    
    // Wait for INTFLAG.READY bit meaning NVMCTRL is ready to accept a new command
    while (NVMCTRL_IsBusy() == true)
    {
        
    }
    
    // Read physical value contained in Flash (or Data Flash) memory at defined address. This value is corrected on the fly as ECC feature is enabled.
    *((uint64_t*)&data_read[0]) = *(uint64_t*)address;
    
    if (intFlag & NVMCTRL_INTFLAG_SERR_Msk)
    {
        printf ("Single Fault Detected !\n\r");
        intFlag = 0;
    }
    
    printf ("Value Read at address 0x%X: 0x%X is corrected on the fly\n\r", (uint)(address), (uint)data_read[0]);
    printf ("Value Read at address 0x%X: 0x%X is corrected on the fly\n\r", (uint)(address + 4), (uint)data_read[1]);
    
    // Read updated SECIN value and display result on terminal (SECIN is the ECC read from memory. This was calculated on un-corrupted data and written upon a flash write operation)
    secin = NVMCTRL_ECC_SECIN_FaultParityGet();
    printf ("The computed SECIN is 0x%X\n\r", (uint)secin); 
    
    // Read updated SECOUT value and display result on terminal (SECOUT is the ECC calculated on the corrupted data upon a read operation)
    secout = NVMCTRL_ECC_SECOUT_FaultParityGet();
    printf ("The new computed SECOUT is 0x%X\n\r", (uint)secout);
    
    // Read updated Syndrome value and display result on terminal
    syndrome = NVMCTRL_ECC_FaultSyndromeGet();
    printf ("The syndrome is 0x%X\n\n\r", (uint)syndrome);      
    
    if (address == FLASH_WRITE_ADDR)
        NVMCTRL_ECC_MainArrayDisable();
    else
        NVMCTRL_ECC_DataFlashDisable();
    
    // Read physical value contained in Flash (or Data Flash) memory at defined address. This value is returned raw as ECC feature is disabled
    *((uint64_t*)&data_read[0]) = *(uint64_t*)address;
    
    printf ("Physical value at address 0x%X: 0x%X \n\r", (uint)(address), (uint)data_read[0]);
    printf ("Physical value at address 0x%X: 0x%X \n\n\r", (uint)(address + 4), (uint)data_read[1]);
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************


int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    printf ("\33[H\33[2J");
    printf ("************************************************\n\r");
    printf ("*** NVMCTRL ECC with Fault Injection Testing ***\n\r");
    printf ("************************************************\n\n\r");
    
    // Enable CallBack Register routine upon SERR or DERR interrupt for NVMCTRL 
    NVMCTRL_CallbackRegister (NVMCTRL_EventHandler, 0);
    
    display_menu ();
    
    
    
    while ( true )
    {
        
        if (first_iteration == true)
        {
            switch (cmd)
            {
                case (SINGLE_FAULT_INJECTION):
                    printf ("Single Fault Injection for Flash memory on writes\n\r");
                    // Configure NVMCTRL for ECC testing on writes for Flash memory
                    
                    // Erase the row to test
                    NVMCTRL_RowErase (FLASH_WRITE_ADDR);

                    NVMCTRL_ECC_SingleBitFaultInject(FLASH_WRITE_ADDR, 0x3, NVMCTRL_ECC_FLT_MODE_ON_WRITE);
                    
                    // Launch Single Fault Injection routine for Flash memory on writes
                    fault_injection_routine (FLASH_WRITE_ADDR);                 

                    printf ("Single Fault Injection for Data Flash memory on writes\n\r");
                    
                    NVMCTRL_DATA_FLASH_RowErase (DATAFLASH_WRITE_ADDR);
                    
                    // Configure NVMCTRL for ECC testing on writes for Flash memory
                    NVMCTRL_ECC_SingleBitFaultInject(DATAFLASH_WRITE_ADDR, 0x3, NVMCTRL_ECC_FLT_MODE_ON_WRITE);
                    
                    // Launch Single Fault Injection routine for Flash memory on writes
                    fault_injection_routine (DATAFLASH_WRITE_ADDR);

                    printf ("Please RESET the board as ECC feature cannot be re-enabled.\n\r");
                    first_iteration = false;
                    break;

                case (DOUBLE_FAULT_INJECTION):
                    printf ("Double Fault Injection for Flash memory on writes\n\r");
                    // Configure NVMCTRL for ECC testing on writes for Flash memory
                    NVMCTRL_ECC_DoubleBitFaultInject(FLASH_WRITE_ADDR, 0x3, 0x5, NVMCTRL_ECC_FLT_MODE_ON_WRITE);
                    // Launch Double Fault Injection routine for Flash memory on writes
                    fault_injection_routine (FLASH_WRITE_ADDR);
                    
                    first_iteration = false;
                    break;

                default:
                    printf ("The choice must be 'a' or 'b'. Please retry.\n\r");
                    display_menu ();
                    break;
            }
        }
        else
        {
            __NOP();
        }
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

