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
#include "definitions.h"                // SYS function prototypes

#define MCRAMC_PAGE_ADDR 0x4000

uint8_t cmd = 0;

uint32_t data = 0;
uint32_t data_read = 0;

uint8_t syndrome = 0;
uint8_t parity_bits = 0;
uint8_t mbist_test_result = 0;

enum
{
    SINGLE_FAULT_INJECTION = 'a',
    DOUBLE_FAULT_INJECTION = 'b'    
} ECC_TESTING_MEMORY;

/* Optional application-provided functions */
extern void _on_reset(void)
{
    // SMBIST is no longer PAC secure to perform SMBIST Test
    PAC_REGS->PAC_WRCTRL = (uint32_t)(PAC_WRCTRL_KEY_CLR | PAC_WRCTRL_PERID (91));
    
    // Clear SMBIST Status Flags
    SMBIST_REGS->SMBIST_STATUS = (uint32_t) SMBIST_STATUS_Msk;
    // Launch the MBIST Test on SRAM
    SMBIST_REGS->SMBIST_CTRL = (uint32_t)(SMBIST_CTRL_SMBISTP1_Msk | SMBIST_CTRL_SMBISTP2_Msk);
    // Wait for Test to Finish
    while ((SMBIST_REGS->SMBIST_STATUS & SMBIST_STATUS_DONE_Msk) == 0);
}

void display_menu ( void )
{
    printf ("Select the test to launch: \n\r");
    printf ("a) Single Fault Injection\n\r");
    printf ("b) Double Fault Injection\n\r");
    printf ("Enter your choice: ");
    scanf ("%c", &cmd);
    printf("\n\n\r");
}

void RAM_CallbackRoutine (RAM_ECC_STATUS status, uintptr_t context)
{   
    if (status & RAM_ECC_STATUS_SERR)
    {
        LED0_Toggle ();
    }
}

void fault_injection_routine ( uint32_t address )
{    

    data = 0xA5A5A5A5;
    
    if (address < 0x20000000)
        address = 0x20000000 + address;
    
    printf("Injecting Fault at address 0x%X\r\n", (uint)address);
    
    // Write RAM memory with data at address
    *((uint32_t*)address) = data;
    
    // Disable ECC for MCRAMC
    RAM_ECC_Disable();
    
    printf("ECC Decoding Disabled ..\r\n");
    
    // Read physical value contained in SRAM memory at defined address. This should read corrupted value as ECC decoding is disabled.
    data_read = *((uint32_t*)address);
    
    printf ("Value Read from SRAM at address 0x%X is 0x%X\n\n\r", (uint)(address), (uint)data_read);
    
    // Enabling ECC for MCRAMC
    RAM_ECC_Enable();
    
    // Disabling fault injection
    RAM_ECC_FaultDisable();
    
    printf("ECC Decoding enabled ..\r\n");
    
    // Read physical value contained in SRAM memory at defined address. The should read corrected value as ECC decoding is enabled.
    data_read = *((uint32_t*)address);   
    
    printf ("Value Read from SRAM at address 0x%X is 0x%X, corrected on the fly\n\r", (uint)(address), (uint)data_read); 
    
    // Read parity bit 
    parity_bits = RAM_ECC_FaultCaptureParityGet();
    printf ("The parity bits are 0x%X\n\r", (uint)parity_bits);

    // Read syndrome value
    syndrome = RAM_ECC_FaultCaptureSyndromeGet();
    printf ("The syndrome is 0x%X\n\n\r", (uint)syndrome);       
    
           
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
    printf ("***********************************************\n\r");
    printf ("*** MCRAMC ECC with Fault Injection Testing ***\n\r");
    printf ("***********************************************\n\n\r");
    
    mbist_test_result = (SMBIST_REGS->SMBIST_STATUS & SMBIST_STATUS_FAIL_Msk);
    
    if (mbist_test_result)
        printf ("MBIST Test on SRAM failed.\n\n\r");
    else
        printf ("MBIST Test on SRAM succeeded.\n\n\r");
    
    // Disable ECC for MCRAMC (It is enabled by default on POR)
    RAM_ECC_Disable();
    
    // Enable SERR and DERR interrupts
    RAM_ECC_CallbackRegister (RAM_CallbackRoutine, 0);    
    
    display_menu ();

    while ( true )
    {
        switch (cmd)
        {
            case (SINGLE_FAULT_INJECTION):                                
                printf ("Single Fault Injection for SRAM memory\n\r");
                // Configures MCRAMC for ECC testing for RAM
                RAM_ECC_SingleBitFaultInject(MCRAMC_PAGE_ADDR, 0);
                // Launch Single Fault Injection routine for SRAM memory
                fault_injection_routine (MCRAMC_PAGE_ADDR);

                display_menu ();
                break;

            case (DOUBLE_FAULT_INJECTION):
                printf ("Double Fault Injection for SRAM memory\n\r");
                // Configure SRAM for ECC testing for SRAM memory
                RAM_ECC_DoubleBitFaultInject(MCRAMC_PAGE_ADDR, 0, 1);
                // Launch Double Fault Injection routine for SRAM memory
                fault_injection_routine (MCRAMC_PAGE_ADDR);

                display_menu ();
                break;

            default:
                printf ("The choice must be 'a' or 'b'. Please retry\n\r");

                display_menu ();
                break;
        }  
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

