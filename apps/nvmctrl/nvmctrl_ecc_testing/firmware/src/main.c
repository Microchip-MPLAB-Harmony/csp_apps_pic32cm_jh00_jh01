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

void NVMCTRL_InterruptRoutine (uintptr_t context)
{
    NVMCTRL_REGS->NVMCTRL_INTENCLR = NVMCTRL_INTENCLR_Msk;
    
    if (NVMCTRL_REGS->NVMCTRL_INTFLAG & NVMCTRL_INTFLAG_SERR_Msk)
    {        
        LED0_Toggle ();
    }
    else if (NVMCTRL_REGS->NVMCTRL_INTFLAG & NVMCTRL_INTFLAG_DERR_Msk)
    {
        printf ("Please RESET the device by pressing the RESET button\n\r");
    }
}

void configure_nvmctrl_for_ecc_testing ( uint32_t address, uint8_t fault_injection_type )
{
    // Erase the row to test
    if (address == FLASH_WRITE_ADDR)
        NVMCTRL_RowErase (FLASH_WRITE_ADDR);
    else
        NVMCTRL_DATA_FLASH_RowErase (DATAFLASH_WRITE_ADDR);
    
    // Reset ECC Fault Injection Control Register
    NVMCTRL_REGS->NVMCTRL_FLTCTRL = (uint32_t)(NVMCTRL_FLTCTRL_FLTRST_Msk);
    
    /* ECC Fault Injection Pointer configuration
     * FLT1PTR = 0x3 - Fault is injected for DATA[0]
     * FLT2PTR = 0x5 - Fault is injected for DATA[1] */
    NVMCTRL_REGS->NVMCTRL_FFLTPTR = (uint32_t)(NVMCTRL_FFLTPTR_FLT1PTR (0x3) | NVMCTRL_FFLTPTR_FLT2PTR (0x5));
    
    // Defines where fault injection will be applied
    NVMCTRL_REGS->NVMCTRL_FFLTADR = (uint32_t)(NVMCTRL_FFLTADR_FLTADR (address));
    
    /* ECC Fault Injection Control configuration
     * FLTMD = 0x6 - Single Fault Injection (at bit selected in FLT1PTR) upon Writes
     * FLTEN = 0x1 - Fault Injection Enable */
    if (fault_injection_type == SINGLE_FAULT_INJECTION)
    {
        NVMCTRL_REGS->NVMCTRL_FLTCTRL = (uint32_t)(NVMCTRL_FLTCTRL_FLTMD (0x6) | NVMCTRL_FLTCTRL_FLTEN_En);
        // Dummy Read back for synchronization purpose
        while (NVMCTRL_REGS->NVMCTRL_FLTCTRL != (NVMCTRL_FLTCTRL_FLTMD(0x6) | NVMCTRL_FLTCTRL_FLTEN_En));
    }
    /* ECC Fault Injection Control configuration
     * FLTMD = 0x7 - Double Fault Injection (at bit selected in FLT1PTR and FLT2PTR) upon Writes
     * FLTEN = 0x1 - Fault Injection Enable */
    else if (fault_injection_type == DOUBLE_FAULT_INJECTION)
    {
        NVMCTRL_REGS->NVMCTRL_FLTCTRL = (uint32_t)(NVMCTRL_FLTCTRL_FLTMD (0x7) | NVMCTRL_FLTCTRL_FLTEN_En);
        // Dummy Read back for synchronization purpose
        while (NVMCTRL_REGS->NVMCTRL_FLTCTRL != (NVMCTRL_FLTCTRL_FLTMD(0x7) | NVMCTRL_FLTCTRL_FLTEN_En));
    }
    /* ECC Fault Injection Control configuration
     * FLTMD = 0x6 - Single Fault Injection (at bit selected in FLT1PTR) upon Writes
     * FLTEN = 0x1 - Fault Injection Enable */
    else
    {
        printf ("The entered value does not match. Single Fault Injection is selected by default.\n\r");
        NVMCTRL_REGS->NVMCTRL_FLTCTRL = (uint32_t)(NVMCTRL_FLTCTRL_FLTMD (0x6) | NVMCTRL_FLTCTRL_FLTEN_En);
        // Dummy Read back for synchronization purpose
        while (NVMCTRL_REGS->NVMCTRL_FLTCTRL != (NVMCTRL_FLTCTRL_FLTMD(0x6) | NVMCTRL_FLTCTRL_FLTEN_En));
    }
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
    while ((NVMCTRL_REGS->NVMCTRL_INTFLAG & NVMCTRL_INTFLAG_READY_Msk) != 1);
    
    if (cmd == DOUBLE_FAULT_INJECTION)
        printf ("Programming Error Fault due to Double Fault Injection will occur. Please RESET the device by pressing the RESET button\n\n\r");
    
    // Read physical value contained in Flash (or Data Flash) memory at defined address. This value is corrected on the fly as ECC feature is enabled.
    NVMCTRL_Read (data_read, data_length, address);
    
    printf ("Value Read at address 0x%X: 0x%X is corrected on the fly\n\r", (uint)(address), (uint)data_read[0]);
    printf ("Value Read at address 0x%X: 0x%X is corrected on the fly\n\r", (uint)(address + 4), (uint)data_read[1]);
    
    // Read updated SECIN value and display result on terminal
    secin = NVMCTRL_REGS->NVMCTRL_FFLTPAR & NVMCTRL_FFLTPAR_SECIN_Msk;
    printf ("The computed SECIN is 0x%X\n\r", (uint)secin); 
    
    // Read updated SECOUT value and display result on terminal
    secout = (NVMCTRL_REGS->NVMCTRL_FFLTPAR & NVMCTRL_FFLTPAR_SECOUT_Msk) >> 16;
    printf ("The new computed SECOUT is 0x%X\n\r", (uint)secout);
    
    // Read updated Syndrome value and display result on terminal
    syndrome = NVMCTRL_REGS->NVMCTRL_FFLTSYN & NVMCTRL_FFLTSYN_SECSYN_Msk;
    printf ("The syndrome is 0x%X\n\n\r", (uint)syndrome);
    
    // Write INTFLAG.SERR bit to clear the flag
    NVMCTRL_REGS->NVMCTRL_INTFLAG = (uint32_t)(NVMCTRL_INTFLAG_SERR_Msk);
    
    if (address == FLASH_WRITE_ADDR)
        NVMCTRL_REGS->NVMCTRL_ECCCTRL = (uint32_t)(NVMCTRL_ECCCTRL_SECCNT (0x0) | NVMCTRL_ECCCTRL_ECCDIS_Dis);
    else
        NVMCTRL_REGS->NVMCTRL_ECCCTRL = (uint32_t)(NVMCTRL_ECCCTRL_SECCNT (0x0) | NVMCTRL_ECCCTRL_ECCDFDIS_Dis);
    
    // Read physical value contained in Flash (or Data Flash) memory at defined address. This value is returned raw as ECC feature is disabled
    NVMCTRL_Read (data_read, data_length, address);
    
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
    
    /* ECC Control configuration
     * SECCNT = 0x0
     * ECCDFDIS = 0x1 - Data Flash ECC is enabled 
     * ECCDIS = 0x1 - Flash main array ECC is enabled */
    NVMCTRL_REGS->NVMCTRL_ECCCTRL = (uint32_t)(NVMCTRL_ECCCTRL_SECCNT (0x0) | NVMCTRL_ECCCTRL_ECCDFDIS_En | NVMCTRL_ECCCTRL_ECCDIS_En);
    
    // Enable CallBack Register routine upon SERR or DERR interrupt for NVMCTRL 
    NVMCTRL_CallbackRegister (NVMCTRL_InterruptRoutine, 0);
    NVMCTRL_REGS->NVMCTRL_INTENSET = NVMCTRL_INTENSET_SERR_Msk | NVMCTRL_INTENSET_DERR_Msk;
    
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
                    configure_nvmctrl_for_ecc_testing (FLASH_WRITE_ADDR, cmd);
                    // Launch Single Fault Injection routine for Flash memory on writes
                    fault_injection_routine (FLASH_WRITE_ADDR);                 

                    printf ("Single Fault Injection for Data Flash memory on writes\n\r");
                    // Configure NVMCTRL for ECC testing on writes for Flash memory
                    configure_nvmctrl_for_ecc_testing (DATAFLASH_WRITE_ADDR, cmd);
                    // Launch Single Fault Injection routine for Flash memory on writes
                    fault_injection_routine (DATAFLASH_WRITE_ADDR);

                    printf ("Please RESET the board as ECC feature cannot be re-enabled.\n\r");
                    first_iteration = false;
                    break;

                case (DOUBLE_FAULT_INJECTION):
                    printf ("Double Fault Injection for Flash memory on writes\n\r");
                    // Configure NVMCTRL for ECC testing on writes for Flash memory
                    configure_nvmctrl_for_ecc_testing (FLASH_WRITE_ADDR, cmd);
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

