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

uint32_t data [MCRAMC_SRAM_PAGESIZE] = {0};
uint32_t data_read [MCRAMC_SRAM_PAGESIZE] = {0};

uint32_t data_length = 32;
uint8_t syndrome = 0;
uint8_t parity_bits = 0;
uint8_t mbist_test_result = 0;

enum
{
    SINGLE_FAULT_INJECTION = 'a',
    DOUBLE_FAULT_INJECTION = 'b'    
} ECC_TESTING_MEMORY;

void display_menu ( void )
{
    printf ("Select the test to launch: \n\r");
    printf ("a) Single Fault Injection\n\r");
    printf ("b) Double Fault Injection\n\r");
    printf ("Enter your choice: ");
    scanf ("%c", &cmd);
    printf("\n\n\r");
}

void MCRAMC_CallbackRoutine (MCRAMC_STATUS status, uintptr_t context)
{
    MCRAMC_REGS->MCRAMC_INTENCLR = MCRAMC_INTENCLR_Msk;
    
    if (status & MCRAMC_STATUS_SERR)
    {
        LED0_Toggle ();
    }
}

void configure_mcramc_for_ecc_testing ( uint32_t address, uint8_t fault_injection_type )
{
    // Software Rest on MCRAMC ECC for testing
    MCRAMC_REGS->MCRAMC_CTRLA = (uint32_t) MCRAMC_CTRLA_SWRST_Msk;
    
    // Disable ECC for MCRAMC
    MCRAMC_REGS->MCRAMC_CTRLA &= ~MCRAMC_CTRLA_ENABLE_Msk;
    
    /* ECC Fault Injection Pointer configuration
     * FLT1PTR = 0x0 - Fault is injected for DATA[0] 
     * FLT2PTR = 0x1 - Fault is injected for DATA[1] */
    MCRAMC_REGS->MCRAMC_FLTPTR = (uint32_t)(MCRAMC_FLTPTR_FLT1PTR (0x0) | MCRAMC_FLTPTR_FLT2PTR (0x1));
    
    MCRAMC_REGS->MCRAMC_FLTADR = (uint32_t)(MCRAMC_FLTADR_FLTADR (address));
    
    /* ECC Fault Injection Control configuration
     * FLTMD = 0x1 - Single Fault Injection (at bit selected in FLT1PTR) for Writes
     * FLTEN = 0x1 - Fault Injection Enable */
    if (fault_injection_type == SINGLE_FAULT_INJECTION)
    {
        // Enable Single Fault Injection
        MCRAMC_REGS->MCRAMC_FLTCTRL = (uint32_t)(MCRAMC_FLTCTRL_FLTMD (0x1) | MCRAMC_FLTCTRL_FLTEN_Msk);
        // Dummy Read back for synchronization purpose
        while  (MCRAMC_REGS->MCRAMC_FLTCTRL != (MCRAMC_FLTCTRL_FLTMD_SINGLE | MCRAMC_FLTCTRL_FLTEN_Msk));        
    }
    /* ECC Fault Injection Control configuration
     * FLTMD = 0x2 - Double Fault Injection (at bit selected in FLT1PTR and FLT2PTR) for Writes
     * FLTEN = 0x1 - Fault Injection Enable */
    else if (fault_injection_type == DOUBLE_FAULT_INJECTION)
    {
        // Enable Double Fault Injection
        MCRAMC_REGS->MCRAMC_FLTCTRL = (uint32_t)(MCRAMC_FLTCTRL_FLTMD (0x2) | MCRAMC_FLTCTRL_FLTEN_Msk);
        // Dummy Read back for synchronization purpose
        while  (MCRAMC_REGS->MCRAMC_FLTCTRL != (MCRAMC_FLTCTRL_FLTMD_DOUBLE | MCRAMC_FLTCTRL_FLTEN_Msk));
    }
    /* ECC Fault Injection Control configuration
     * FLTMD = 0x1 - Single Fault Injection (at bit selected in FLT1PTR) for Writes
     * FLTEN = 0x1 - Fault Injection Enable */
    else
    {
        printf ("The entered value does not match. Single Fault Injection will be chosen by default.\n\r");
        // Enable Single Fault Injection
        MCRAMC_REGS->MCRAMC_FLTCTRL = (uint32_t)(MCRAMC_FLTCTRL_FLTMD (0x1) | MCRAMC_FLTCTRL_FLTEN_Msk);
        // Dummy Read back for synchronization purpose
        while  (MCRAMC_REGS->MCRAMC_FLTCTRL != (MCRAMC_FLTCTRL_FLTMD_SINGLE | MCRAMC_FLTCTRL_FLTEN_Msk));
    }
    
    // Enable ECC for MCRAMC
    MCRAMC_REGS->MCRAMC_CTRLA = (uint32_t) MCRAMC_CTRLA_ENABLE_Msk;
}

void fault_injection_routine ( uint32_t address )
{
    data[0] = 0xA5A5A5A5;
    
    if (address < 0x20000000)
        address = 0x20000000 + address;
    
    // Write RAM memory with data at address
    RAM_Write (data, data_length, address);
    
    // Read physical value contained in SRAM memory at defined address. The value is corrected on the fly as ECC feature is enabled
    RAM_Read (data_read, data_length, address);    
    
    printf ("Value Read from SRAM at address 0x%X: 0x%X is corrected on the fly\n\r", (uint)(address), (uint)data_read[0]);
    
    // Read parity bit 
    parity_bits = (MCRAMC_REGS->MCRAMC_ERRCPAR & MCRAMC_ERRCPAR_ERCPAR_Msk);
    printf ("The parity bits are 0x%X\n\r", (uint)parity_bits);

    // Read syndrome value
    syndrome = (MCRAMC_REGS->MCRAMC_ERRCSYN & MCRAMC_ERRCSYN_ERCSYN_Msk);
    printf ("The syndrome is 0x%X\n\n\r", (uint)syndrome);
    
    // Clear MCRAMC INTSTA register bits
    MCRAMC_REGS->MCRAMC_INTSTA = (uint32_t)(MCRAMC_INTSTA_Msk);
    
    // Disable MCRAMC ECC feature
    MCRAMC_REGS->MCRAMC_CTRLA = (uint32_t)(MCRAMC_CTRLA_ENABLE_0);
    
    // Read physical value contained in SRAM memory at defined address. The value is given raw as ECC feature is disabled
    RAM_Read (data_read, data_length, address);    
    
    printf ("Physical value contained in SRAM at address 0x%X: 0x%X\n\n\r", (uint)(address), (uint)data_read[0]);
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
    
    // Enable SERR and DERR interrupts
    MCRAMC_CallbackRegister (MCRAMC_CallbackRoutine, 0);
    MCRAMC_REGS->MCRAMC_INTENSET = (uint32_t)(MCRAMC_INTENSET_SERREN_Msk | MCRAMC_INTENSET_DERREN_Msk);
    
    display_menu ();

    while ( true )
    {
        switch (cmd)
        {
            case (SINGLE_FAULT_INJECTION):
                printf ("Single Fault Injection for SRAM memory\n\r");
                // Configures MCRAMC for ECC testing for RAM
                configure_mcramc_for_ecc_testing (MCRAMC_PAGE_ADDR, cmd);
                // Launch Single Fault Injection routine for SRAM memory
                fault_injection_routine (MCRAMC_PAGE_ADDR);

                display_menu ();
                break;

            case (DOUBLE_FAULT_INJECTION):
                printf ("Double Fault Injection for SRAM memory\n\r");
                // Configure SRAM for ECC testing for SRAM memory
                configure_mcramc_for_ecc_testing (MCRAMC_PAGE_ADDR, cmd);
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

