/**
 * \brief Header file for PIC32CM5164JH00100
 *
 * Copyright (c) 2020 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2020-06-10T15:07:50Z */
#ifndef _PIC32CM5164JH00100_H_
#define _PIC32CM5164JH00100_H_

// Header version uses Semantic Versioning 2.0.0 (https://semver.org/)
#define HEADER_FORMAT_VERSION "2.0.0"

#define HEADER_FORMAT_VERSION_MAJOR (2)
#define HEADER_FORMAT_VERSION_MINOR (0)

/** \addtogroup PIC32CM5164JH00100_definitions PIC32CM5164JH00100 definitions
  This file defines all structures and symbols for PIC32CM5164JH00100:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
 *  @{
 */

#ifdef __cplusplus
 extern "C" {
#endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  include <stdint.h>
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !defined(SKIP_INTEGER_LITERALS)
#  if defined(_U_) || defined(_L_) || defined(_UL_)
#    error "Integer Literals macros already defined elsewhere"
#  endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Macros that deal with adding suffixes to integer literal constants for C/C++ */
#  define _U_(x) (x ## U)    /**< C code: Unsigned integer literal constant value */
#  define _L_(x) (x ## L)    /**< C code: Long integer literal constant value */
#  define _UL_(x) (x ## UL)  /**< C code: Unsigned Long integer literal constant value */

#else /* Assembler */

#  define _U_(x) x    /**< Assembler: Unsigned integer literal constant value */
#  define _L_(x) x    /**< Assembler: Long integer literal constant value */
#  define _UL_(x) x   /**< Assembler: Unsigned Long integer literal constant value */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* SKIP_INTEGER_LITERALS */
/** @}  end of Atmel Global Defines */

/* ************************************************************************** */
/*   CMSIS DEFINITIONS FOR PIC32CM5164JH00100                                 */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M0PLUS Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /**< -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn       = -14, /**< -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn            = -13, /**< -13 Hard Fault, all classes of Fault    */
  SVCall_IRQn               =  -5, /**< -5  System Service Call via SVC instruction */
  PendSV_IRQn               =  -2, /**< -2  Pendable request for system service */
  SysTick_IRQn              =  -1, /**< -1  System Tick Timer                   */
/******  PIC32CM5164JH00100 specific Interrupt Numbers ***********************************/
  OSC32KCTRL_IRQn           =   0, /**< 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (OSC32KCTRL) */
  OSCCTRL_IRQn              =   0, /**< 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (OSCCTRL) */
  MCLK_IRQn                 =   0, /**< 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (MCLK) */
  PAC_IRQn                  =   0, /**< 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (PAC) */
  SUPC_IRQn                 =   0, /**< 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (SUPC) */
  PM_IRQn                   =   0, /**< 0   Shared between MCLK OSCCTRL OSC32KCTRL PAC PM SUPC (PM) */
  WDT_IRQn                  =   1, /**< 1   Watchdog Timer (WDT)                */
  RTC_IRQn                  =   2, /**< 2   Real-Time Counter (RTC)             */
  EIC_IRQn                  =   3, /**< 3   External Interrupt Controller (EIC) */
  FREQM_IRQn                =   4, /**< 4   Frequency Meter (FREQM)             */
  MCRAMC_IRQn               =   5, /**< 5   Multi-Channel RAM Controller (MCRAMC) */
  NVMCTRL_IRQn              =   6, /**< 6   Non-Volatile Memory Controller (NVMCTRL) */
  DMAC_IRQn                 =   7, /**< 7   Direct Memory Access Controller (DMAC) */
  EVSYS_IRQn                =   8, /**< 8   Event System Interface (EVSYS)      */
  SERCOM6_IRQn              =   9, /**< 9   Shared between SERCOM0 SERCOM6 (SERCOM6) */
  SERCOM0_IRQn              =   9, /**< 9   Shared between SERCOM0 SERCOM6 (SERCOM0) */
  SERCOM7_IRQn              =  10, /**< 10  Shared between SERCOM1 SERCOM7 (SERCOM7) */
  SERCOM1_IRQn              =  10, /**< 10  Shared between SERCOM1 SERCOM7 (SERCOM1) */
  SERCOM2_IRQn              =  11, /**< 11  Serial Communication Interface (SERCOM2) */
  SERCOM3_IRQn              =  12, /**< 12  Serial Communication Interface (SERCOM3) */
  SERCOM4_IRQn              =  13, /**< 13  Serial Communication Interface (SERCOM4) */
  SERCOM5_IRQn              =  14, /**< 14  Serial Communication Interface (SERCOM5) */
  TCC0_IRQn                 =  17, /**< 17  Timer Counter for Control Applications (TCC0) */
  TCC1_IRQn                 =  18, /**< 18  Timer Counter for Control Applications (TCC1) */
  TCC2_IRQn                 =  19, /**< 19  Timer Counter for Control Applications (TCC2) */
  TC5_IRQn                  =  20, /**< 20  Shared between TC0 TC5 (TC5)        */
  TC0_IRQn                  =  20, /**< 20  Shared between TC0 TC5 (TC0)        */
  TC6_IRQn                  =  21, /**< 21  Shared between TC1 TC6 (TC6)        */
  TC1_IRQn                  =  21, /**< 21  Shared between TC1 TC6 (TC1)        */
  TC7_IRQn                  =  22, /**< 22  Shared between TC2 TC7 (TC7)        */
  TC2_IRQn                  =  22, /**< 22  Shared between TC2 TC7 (TC2)        */
  TC3_IRQn                  =  23, /**< 23  Basic Timer Counter (TC3)           */
  TC4_IRQn                  =  24, /**< 24  Basic Timer Counter (TC4)           */
  ADC0_IRQn                 =  25, /**< 25  Analog Digital Converter (ADC0)     */
  ADC1_IRQn                 =  26, /**< 26  Analog Digital Converter (ADC1)     */
  AC_IRQn                   =  27, /**< 27  Analog Comparators (AC)             */
  DAC_IRQn                  =  28, /**< 28  Digital Analog Converter (DAC)      */
  PDEC_IRQn                 =  29, /**< 29  Quadrature Decodeur (PDEC)          */
  PTC_IRQn                  =  30, /**< 30  Peripheral Touch Controller (PTC)   */
  ICM_IRQn                  =  31, /**< 31  Integrity Check Monitor (ICM)       */

  PERIPH_MAX_IRQn           =  31  /**< Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* Cortex-M handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault */
  void* pvReservedC12;
  void* pvReservedC11;
  void* pvReservedC10;
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction */
  void* pvReservedC4;
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer */

  /* Peripheral handlers */
  void* pfnSYSTEM_Handler;                       /*   0 System peripherals shared interrupt (MCLK OSCCTRL OSC32KCTRL PAC PM SUPC) */
  void* pfnWDT_Handler;                          /*   1 Watchdog Timer (WDT) */
  void* pfnRTC_Handler;                          /*   2 Real-Time Counter (RTC) */
  void* pfnEIC_Handler;                          /*   3 External Interrupt Controller (EIC) */
  void* pfnFREQM_Handler;                        /*   4 Frequency Meter (FREQM) */
  void* pfnMCRAMC_Handler;                       /*   5 Multi-Channel RAM Controller (MCRAMC) */
  void* pfnNVMCTRL_Handler;                      /*   6 Non-Volatile Memory Controller (NVMCTRL) */
  void* pfnDMAC_Handler;                         /*   7 Direct Memory Access Controller (DMAC) */
  void* pfnEVSYS_Handler;                        /*   8 Event System Interface (EVSYS) */
  void* pfnSERCOM0_6_Handler;                    /*   9 Serial Communication Interface 0_6 (SERCOM0 SERCOM6) */
  void* pfnSERCOM1_7_Handler;                    /*  10 Serial Communication Interface 1_7 (SERCOM1 SERCOM7) */
  void* pfnSERCOM2_Handler;                      /*  11 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM3_Handler;                      /*  12 Serial Communication Interface (SERCOM3) */
  void* pfnSERCOM4_Handler;                      /*  13 Serial Communication Interface (SERCOM4) */
  void* pfnSERCOM5_Handler;                      /*  14 Serial Communication Interface (SERCOM5) */
  void* pvReserved15;
  void* pvReserved16;
  void* pfnTCC0_Handler;                         /*  17 Timer Counter for Control Applications (TCC0) */
  void* pfnTCC1_Handler;                         /*  18 Timer Counter for Control Applications (TCC1) */
  void* pfnTCC2_Handler;                         /*  19 Timer Counter for Control Applications (TCC2) */
  void* pfnTC0_5_Handler;                        /*  20 Timer/Counter 0_5 (TC0 TC5) */
  void* pfnTC1_6_Handler;                        /*  21 Timer/Counter 1_6 (TC1 TC6) */
  void* pfnTC2_7_Handler;                        /*  22 Timer/Counter 2_7 (TC2 TC7) */
  void* pfnTC3_Handler;                          /*  23 Basic Timer Counter (TC3) */
  void* pfnTC4_Handler;                          /*  24 Basic Timer Counter (TC4) */
  void* pfnADC0_Handler;                         /*  25 Analog Digital Converter (ADC0) */
  void* pfnADC1_Handler;                         /*  26 Analog Digital Converter (ADC1) */
  void* pfnAC_Handler;                           /*  27 Analog Comparators (AC) */
  void* pfnDAC_Handler;                          /*  28 Digital Analog Converter (DAC) */
  void* pfnPDEC_Handler;                         /*  29 Quadrature Decodeur (PDEC) */
  void* pfnPTC_Handler;                          /*  30 Peripheral Touch Controller (PTC) */
  void* pfnICM_Handler;                          /*  31 Integrity Check Monitor (ICM) */
} DeviceVectors;

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if !defined DONT_USE_PREDEFINED_CORE_HANDLERS
/* CORTEX-M0PLUS exception handlers */
void Reset_Handler                 ( void );
void NonMaskableInt_Handler        ( void );
void HardFault_Handler             ( void );
void SVCall_Handler                ( void );
void PendSV_Handler                ( void );
void SysTick_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_CORE_HANDLERS */

#if !defined DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS
/* Peripherals interrupt handlers */
void SYSTEM_Handler                ( void );
void WDT_Handler                   ( void );
void RTC_Handler                   ( void );
void EIC_Handler                   ( void );
void FREQM_Handler                 ( void );
void MCRAMC_Handler                ( void );
void NVMCTRL_Handler               ( void );
void DMAC_Handler                  ( void );
void EVSYS_Handler                 ( void );
void SERCOM0_6_Handler             ( void );
void SERCOM1_7_Handler             ( void );
void SERCOM2_Handler               ( void );
void SERCOM3_Handler               ( void );
void SERCOM4_Handler               ( void );
void SERCOM5_Handler               ( void );
void TCC0_Handler                  ( void );
void TCC1_Handler                  ( void );
void TCC2_Handler                  ( void );
void TC0_5_Handler                 ( void );
void TC1_6_Handler                 ( void );
void TC2_7_Handler                 ( void );
void TC3_Handler                   ( void );
void TC4_Handler                   ( void );
void ADC0_Handler                  ( void );
void ADC1_Handler                  ( void );
void AC_Handler                    ( void );
void DAC_Handler                   ( void );
void PDEC_Handler                  ( void );
void PTC_Handler                   ( void );
void ICM_Handler                   ( void );
#endif /* DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/*
 * \brief Configuration of the CORTEX-M0PLUS Processor and Core Peripherals
 */
#define __MPU_PRESENT                  1 /**< MPU present or not                                                        */
#define __NVIC_PRIO_BITS               2 /**< Number of Bits used for Priority Levels                                   */
#define __VTOR_PRESENT                 1 /**< Vector Table Offset Register present or not                               */
#define __Vendor_SysTickConfig         0 /**< Set to 1 if different SysTick Config is used                              */
#define __ARCH_ARM                     1
#define __ARCH_ARM_CORTEX_M            1

/*
 * \brief CMSIS includes
 */
#include "core_cm0plus.h"
#if defined USE_CMSIS_INIT
#include "system_pic32cmjh00.h"
#endif /* USE_CMSIS_INIT */

/** \defgroup PIC32CM5164JH00100_api Peripheral Software API
 *  @{
 */

/* ************************************************************************** */
/**  SOFTWARE PERIPHERAL API DEFINITION FOR PIC32CM5164JH00100                */
/* ************************************************************************** */
#include "component/ac.h"
#include "component/adc.h"
#include "component/ccl.h"
#include "component/dac.h"
#include "component/divas.h"
#include "component/dmac.h"
#include "component/dsu.h"
#include "component/eic.h"
#include "component/evsys.h"
#include "component/freqm.h"
#include "component/gclk.h"
#include "component/icm.h"
#include "component/mclk.h"
#include "component/mcramc.h"
#include "component/mtb.h"
#include "component/nvmctrl.h"
#include "component/osc32kctrl.h"
#include "component/oscctrl.h"
#include "component/pac.h"
#include "component/pdec.h"
#include "component/pm.h"
#include "component/port.h"
#include "component/ptc.h"
#include "component/rstc.h"
#include "component/rtc.h"
#include "component/sercom.h"
#include "component/smbist.h"
#include "component/supc.h"
#include "component/tc.h"
#include "component/tcc.h"
#include "component/wdt.h"
/** @}  end of Peripheral Software API */

/** \addtogroup PIC32CM5164JH00100_id Peripheral Ids Definitions
 *  @{
 */

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR PIC32CM5164JH00100                          */
/* ************************************************************************** */
#define ID_PAC           (  0) /**< \brief Instance index for PAC (PAC) */
#define ID_PM            (  1) /**< \brief Instance index for PM (PM) */
#define ID_MCLK          (  2) /**< \brief Instance index for MCLK (MCLK) */
#define ID_RSTC          (  3) /**< \brief Instance index for RSTC (RSTC) */
#define ID_OSCCTRL       (  4) /**< \brief Instance index for OSCCTRL (OSCCTRL) */
#define ID_OSC32KCTRL    (  5) /**< \brief Instance index for OSC32KCTRL (OSC32KCTRL) */
#define ID_SUPC          (  6) /**< \brief Instance index for SUPC (SUPC) */
#define ID_GCLK          (  7) /**< \brief Instance index for GCLK (GCLK) */
#define ID_WDT           (  8) /**< \brief Instance index for WDT (WDT) */
#define ID_RTC           (  9) /**< \brief Instance index for RTC (RTC) */
#define ID_EIC           ( 10) /**< \brief Instance index for EIC (EIC) */
#define ID_FREQM         ( 11) /**< \brief Instance index for FREQM (FREQM) */
#define ID_MCRAMC        ( 12) /**< \brief Instance index for MCRAMC (MCRAMC) */
#define ID_PORT          ( 32) /**< \brief Instance index for PORT (PORT) */
#define ID_DSU           ( 33) /**< \brief Instance index for DSU (DSU) */
#define ID_NVMCTRL       ( 34) /**< \brief Instance index for NVMCTRL (NVMCTRL) */
#define ID_DMAC          ( 35) /**< \brief Instance index for DMAC (DMAC) */
#define ID_MTB           ( 36) /**< \brief Instance index for MTB (MTB) */
#define ID_EVSYS         ( 64) /**< \brief Instance index for EVSYS (EVSYS) */
#define ID_SERCOM0       ( 65) /**< \brief Instance index for SERCOM0 (SERCOM0) */
#define ID_SERCOM1       ( 66) /**< \brief Instance index for SERCOM1 (SERCOM1) */
#define ID_SERCOM2       ( 67) /**< \brief Instance index for SERCOM2 (SERCOM2) */
#define ID_SERCOM3       ( 68) /**< \brief Instance index for SERCOM3 (SERCOM3) */
#define ID_SERCOM4       ( 69) /**< \brief Instance index for SERCOM4 (SERCOM4) */
#define ID_SERCOM5       ( 70) /**< \brief Instance index for SERCOM5 (SERCOM5) */
#define ID_TCC0          ( 73) /**< \brief Instance index for TCC0 (TCC0) */
#define ID_TCC1          ( 74) /**< \brief Instance index for TCC1 (TCC1) */
#define ID_TCC2          ( 75) /**< \brief Instance index for TCC2 (TCC2) */
#define ID_TC0           ( 76) /**< \brief Instance index for TC0 (TC0) */
#define ID_TC1           ( 77) /**< \brief Instance index for TC1 (TC1) */
#define ID_TC2           ( 78) /**< \brief Instance index for TC2 (TC2) */
#define ID_TC3           ( 79) /**< \brief Instance index for TC3 (TC3) */
#define ID_TC4           ( 80) /**< \brief Instance index for TC4 (TC4) */
#define ID_ADC0          ( 81) /**< \brief Instance index for ADC0 (ADC0) */
#define ID_ADC1          ( 82) /**< \brief Instance index for ADC1 (ADC1) */
#define ID_AC            ( 83) /**< \brief Instance index for AC (AC) */
#define ID_DAC           ( 84) /**< \brief Instance index for DAC (DAC) */
#define ID_PTC           ( 85) /**< \brief Instance index for PTC (PTC) */
#define ID_CCL           ( 86) /**< \brief Instance index for CCL (CCL) */
#define ID_ICM           ( 89) /**< \brief Instance index for ICM (ICM) */
#define ID_PDEC          ( 90) /**< \brief Instance index for PDEC (PDEC) */
#define ID_SMBIST        ( 91) /**< \brief Instance index for SMBIST. (SMBIST) */
#define ID_SERCOM6       ( 96) /**< \brief Instance index for SERCOM6 (SERCOM6) */
#define ID_SERCOM7       ( 97) /**< \brief Instance index for SERCOM7 (SERCOM7) */
#define ID_TC5           ( 98) /**< \brief Instance index for TC5 (TC5) */
#define ID_TC6           ( 99) /**< \brief Instance index for TC6 (TC6) */
#define ID_TC7           (100) /**< \brief Instance index for TC7 (TC7) */

#define ID_PERIPH_MAX    (100) /**< \brief Number of peripheral IDs */
/** @}  end of Peripheral Ids Definitions */

/** \addtogroup PIC32CM5164JH00100_base Peripheral Base Address Definitions
 *  @{
 */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR PIC32CM5164JH00100            */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define AC_REGS                          ((ac_registers_t*)0x42004c00)                 /**< \brief AC Registers Address         */
#define ADC0_REGS                        ((adc_registers_t*)0x42004400)                /**< \brief ADC0 Registers Address       */
#define ADC1_REGS                        ((adc_registers_t*)0x42004800)                /**< \brief ADC1 Registers Address       */
#define CCL_REGS                         ((ccl_registers_t*)0x42005800)                /**< \brief CCL Registers Address        */
#define DAC_REGS                         ((dac_registers_t*)0x42005000)                /**< \brief DAC Registers Address        */
#define DIVAS_REGS                       ((divas_registers_t*)0x48000000)              /**< \brief DIVAS Registers Address      */
#define DIVAS_IOBUS_REGS                 ((divas_registers_t*)0x60000200)              /**< \brief DIVAS Registers Address      */
#define DMAC_REGS                        ((dmac_registers_t*)0x41006000)               /**< \brief DMAC Registers Address       */
#define DSU_REGS                         ((dsu_registers_t*)0x41002000)                /**< \brief DSU Registers Address        */
#define DSU_EXT_REGS                     ((dsu_registers_t*)0x41002100)                /**< \brief DSU Registers Address        */
#define EIC_REGS                         ((eic_registers_t*)0x40002800)                /**< \brief EIC Registers Address        */
#define EVSYS_REGS                       ((evsys_registers_t*)0x42000000)              /**< \brief EVSYS Registers Address      */
#define FREQM_REGS                       ((freqm_registers_t*)0x40002c00)              /**< \brief FREQM Registers Address      */
#define GCLK_REGS                        ((gclk_registers_t*)0x40001c00)               /**< \brief GCLK Registers Address       */
#define ICM_REGS                         ((icm_registers_t*)0x42006400)                /**< \brief ICM Registers Address        */
#define SMBIST_REGS                      ((smbist_registers_t*)0x42006c00)             /**< \brief SMBIST Registers Address     */
#define MCLK_REGS                        ((mclk_registers_t*)0x40000800)               /**< \brief MCLK Registers Address       */
#define MCRAMC_REGS                      ((mcramc_registers_t*)0x40003000)             /**< \brief MCRAMC Registers Address     */
#define MTB_REGS                         ((mtb_registers_t*)0x41008000)                /**< \brief MTB Registers Address        */
#define NVMCTRL_REGS                     ((nvmctrl_registers_t*)0x41004000)            /**< \brief NVMCTRL Registers Address    */
#define OSC32KCTRL_REGS                  ((osc32kctrl_registers_t*)0x40001400)         /**< \brief OSC32KCTRL Registers Address */
#define OSCCTRL_REGS                     ((oscctrl_registers_t*)0x40001000)            /**< \brief OSCCTRL Registers Address    */
#define PAC_REGS                         ((pac_registers_t*)0x40000000)                /**< \brief PAC Registers Address        */
#define PDEC_REGS                        ((pdec_registers_t*)0x42006800)               /**< \brief PDEC Registers Address       */
#define PM_REGS                          ((pm_registers_t*)0x40000400)                 /**< \brief PM Registers Address         */
#define PORT_REGS                        ((port_registers_t*)0x41000000)               /**< \brief PORT Registers Address       */
#define PORT_IOBUS_REGS                  ((port_registers_t*)0x60000000)               /**< \brief PORT Registers Address       */
#define PTC_REGS                         ((ptc_registers_t*)0x42005400)                /**< \brief PTC Registers Address        */
#define RSTC_REGS                        ((rstc_registers_t*)0x40000c00)               /**< \brief RSTC Registers Address       */
#define RTC_REGS                         ((rtc_registers_t*)0x40002400)                /**< \brief RTC Registers Address        */
#define SERCOM0_REGS                     ((sercom_registers_t*)0x42000400)             /**< \brief SERCOM0 Registers Address    */
#define SERCOM1_REGS                     ((sercom_registers_t*)0x42000800)             /**< \brief SERCOM1 Registers Address    */
#define SERCOM2_REGS                     ((sercom_registers_t*)0x42000c00)             /**< \brief SERCOM2 Registers Address    */
#define SERCOM3_REGS                     ((sercom_registers_t*)0x42001000)             /**< \brief SERCOM3 Registers Address    */
#define SERCOM4_REGS                     ((sercom_registers_t*)0x42001400)             /**< \brief SERCOM4 Registers Address    */
#define SERCOM5_REGS                     ((sercom_registers_t*)0x42001800)             /**< \brief SERCOM5 Registers Address    */
#define SERCOM6_REGS                     ((sercom_registers_t*)0x43000000)             /**< \brief SERCOM6 Registers Address    */
#define SERCOM7_REGS                     ((sercom_registers_t*)0x43000400)             /**< \brief SERCOM7 Registers Address    */
#define SUPC_REGS                        ((supc_registers_t*)0x40001800)               /**< \brief SUPC Registers Address       */
#define TC0_REGS                         ((tc_registers_t*)0x42003000)                 /**< \brief TC0 Registers Address        */
#define TC1_REGS                         ((tc_registers_t*)0x42003400)                 /**< \brief TC1 Registers Address        */
#define TC2_REGS                         ((tc_registers_t*)0x42003800)                 /**< \brief TC2 Registers Address        */
#define TC3_REGS                         ((tc_registers_t*)0x42003c00)                 /**< \brief TC3 Registers Address        */
#define TC4_REGS                         ((tc_registers_t*)0x42004000)                 /**< \brief TC4 Registers Address        */
#define TC5_REGS                         ((tc_registers_t*)0x43000800)                 /**< \brief TC5 Registers Address        */
#define TC6_REGS                         ((tc_registers_t*)0x43000c00)                 /**< \brief TC6 Registers Address        */
#define TC7_REGS                         ((tc_registers_t*)0x43001000)                 /**< \brief TC7 Registers Address        */
#define TCC0_REGS                        ((tcc_registers_t*)0x42002400)                /**< \brief TCC0 Registers Address       */
#define TCC1_REGS                        ((tcc_registers_t*)0x42002800)                /**< \brief TCC1 Registers Address       */
#define TCC2_REGS                        ((tcc_registers_t*)0x42002c00)                /**< \brief TCC2 Registers Address       */
#define WDT_REGS                         ((wdt_registers_t*)0x40002000)                /**< \brief WDT Registers Address        */
#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Peripheral Base Address Definitions */

/** \addtogroup PIC32CM5164JH00100_base Peripheral Base Address Definitions
 *  @{
 */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR PIC32CM5164JH00100                          */
/* ************************************************************************** */
#define AC_BASE_ADDRESS                  _UL_(0x42004c00)                              /**< \brief AC Base Address */
#define ADC0_BASE_ADDRESS                _UL_(0x42004400)                              /**< \brief ADC0 Base Address */
#define ADC1_BASE_ADDRESS                _UL_(0x42004800)                              /**< \brief ADC1 Base Address */
#define CCL_BASE_ADDRESS                 _UL_(0x42005800)                              /**< \brief CCL Base Address */
#define DAC_BASE_ADDRESS                 _UL_(0x42005000)                              /**< \brief DAC Base Address */
#define DIVAS_BASE_ADDRESS               _UL_(0x48000000)                              /**< \brief DIVAS Base Address */
#define DIVAS_IOBUS_BASE_ADDRESS         _UL_(0x60000200)                              /**< \brief DIVAS Base Address */
#define DMAC_BASE_ADDRESS                _UL_(0x41006000)                              /**< \brief DMAC Base Address */
#define DSU_BASE_ADDRESS                 _UL_(0x41002000)                              /**< \brief DSU Base Address */
#define DSU_EXT_BASE_ADDRESS             _UL_(0x41002100)                              /**< \brief DSU Base Address */
#define EIC_BASE_ADDRESS                 _UL_(0x40002800)                              /**< \brief EIC Base Address */
#define EVSYS_BASE_ADDRESS               _UL_(0x42000000)                              /**< \brief EVSYS Base Address */
#define FREQM_BASE_ADDRESS               _UL_(0x40002c00)                              /**< \brief FREQM Base Address */
#define GCLK_BASE_ADDRESS                _UL_(0x40001c00)                              /**< \brief GCLK Base Address */
#define ICM_BASE_ADDRESS                 _UL_(0x42006400)                              /**< \brief ICM Base Address */
#define SMBIST_BASE_ADDRESS              _UL_(0x42006c00)                              /**< \brief SMBIST Base Address */
#define MCLK_BASE_ADDRESS                _UL_(0x40000800)                              /**< \brief MCLK Base Address */
#define MCRAMC_BASE_ADDRESS              _UL_(0x40003000)                              /**< \brief MCRAMC Base Address */
#define MTB_BASE_ADDRESS                 _UL_(0x41008000)                              /**< \brief MTB Base Address */
#define NVMCTRL_BASE_ADDRESS             _UL_(0x41004000)                              /**< \brief NVMCTRL Base Address */
#define OSC32KCTRL_BASE_ADDRESS          _UL_(0x40001400)                              /**< \brief OSC32KCTRL Base Address */
#define OSCCTRL_BASE_ADDRESS             _UL_(0x40001000)                              /**< \brief OSCCTRL Base Address */
#define PAC_BASE_ADDRESS                 _UL_(0x40000000)                              /**< \brief PAC Base Address */
#define PDEC_BASE_ADDRESS                _UL_(0x42006800)                              /**< \brief PDEC Base Address */
#define PM_BASE_ADDRESS                  _UL_(0x40000400)                              /**< \brief PM Base Address */
#define PORT_BASE_ADDRESS                _UL_(0x41000000)                              /**< \brief PORT Base Address */
#define PORT_IOBUS_BASE_ADDRESS          _UL_(0x60000000)                              /**< \brief PORT Base Address */
#define PTC_BASE_ADDRESS                 _UL_(0x42005400)                              /**< \brief PTC Base Address */
#define RSTC_BASE_ADDRESS                _UL_(0x40000c00)                              /**< \brief RSTC Base Address */
#define RTC_BASE_ADDRESS                 _UL_(0x40002400)                              /**< \brief RTC Base Address */
#define SERCOM0_BASE_ADDRESS             _UL_(0x42000400)                              /**< \brief SERCOM0 Base Address */
#define SERCOM1_BASE_ADDRESS             _UL_(0x42000800)                              /**< \brief SERCOM1 Base Address */
#define SERCOM2_BASE_ADDRESS             _UL_(0x42000c00)                              /**< \brief SERCOM2 Base Address */
#define SERCOM3_BASE_ADDRESS             _UL_(0x42001000)                              /**< \brief SERCOM3 Base Address */
#define SERCOM4_BASE_ADDRESS             _UL_(0x42001400)                              /**< \brief SERCOM4 Base Address */
#define SERCOM5_BASE_ADDRESS             _UL_(0x42001800)                              /**< \brief SERCOM5 Base Address */
#define SERCOM6_BASE_ADDRESS             _UL_(0x43000000)                              /**< \brief SERCOM6 Base Address */
#define SERCOM7_BASE_ADDRESS             _UL_(0x43000400)                              /**< \brief SERCOM7 Base Address */
#define SUPC_BASE_ADDRESS                _UL_(0x40001800)                              /**< \brief SUPC Base Address */
#define TC0_BASE_ADDRESS                 _UL_(0x42003000)                              /**< \brief TC0 Base Address */
#define TC1_BASE_ADDRESS                 _UL_(0x42003400)                              /**< \brief TC1 Base Address */
#define TC2_BASE_ADDRESS                 _UL_(0x42003800)                              /**< \brief TC2 Base Address */
#define TC3_BASE_ADDRESS                 _UL_(0x42003c00)                              /**< \brief TC3 Base Address */
#define TC4_BASE_ADDRESS                 _UL_(0x42004000)                              /**< \brief TC4 Base Address */
#define TC5_BASE_ADDRESS                 _UL_(0x43000800)                              /**< \brief TC5 Base Address */
#define TC6_BASE_ADDRESS                 _UL_(0x43000c00)                              /**< \brief TC6 Base Address */
#define TC7_BASE_ADDRESS                 _UL_(0x43001000)                              /**< \brief TC7 Base Address */
#define TCC0_BASE_ADDRESS                _UL_(0x42002400)                              /**< \brief TCC0 Base Address */
#define TCC1_BASE_ADDRESS                _UL_(0x42002800)                              /**< \brief TCC1 Base Address */
#define TCC2_BASE_ADDRESS                _UL_(0x42002c00)                              /**< \brief TCC2 Base Address */
#define WDT_BASE_ADDRESS                 _UL_(0x40002000)                              /**< \brief WDT Base Address */
/** @}  end of Peripheral Base Address Definitions */

/** \addtogroup PIC32CM5164JH00100_pio Peripheral Pio Definitions
 *  @{
 */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR PIC32CM5164JH00100                                   */
/* ************************************************************************** */
#include "pio/pic32cm5164jh00100.h"
/** @}  end of Peripheral Pio Definitions */

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR PIC32CM5164JH00100                        */
/* ************************************************************************** */

#define FLASH_SIZE                     _UL_(0x00080000)    /*  512kB Memory segment type: flash */
#define FLASH_PAGE_SIZE                _UL_(        64)
#define FLASH_NB_OF_PAGES              _UL_(      8192)

#define CAL_SIZE                       _UL_(0x00000008)    /*    0kB Memory segment type: fuses */
#define LOCKBIT_SIZE                   _UL_(0x00000004)    /*    0kB Memory segment type: fuses */
#define OTP1_SIZE                      _UL_(0x00000008)    /*    0kB Memory segment type: fuses */
#define OTP2_SIZE                      _UL_(0x00000008)    /*    0kB Memory segment type: fuses */
#define OTP3_SIZE                      _UL_(0x00000008)    /*    0kB Memory segment type: fuses */
#define OTP4_SIZE                      _UL_(0x00000008)    /*    0kB Memory segment type: fuses */
#define OTP5_SIZE                      _UL_(0x00000008)    /*    0kB Memory segment type: fuses */
#define TEMP_LOG_SIZE                  _UL_(0x00000008)    /*    0kB Memory segment type: fuses */
#define USER_PAGE_SIZE                 _UL_(0x00000100)    /*    0kB Memory segment type: user_page */
#define USER_PAGE_PAGE_SIZE            _UL_(        64)
#define USER_PAGE_NB_OF_PAGES          _UL_(         4)

#define DATAFLASH_SIZE                 _UL_(0x00002000)    /*    8kB Memory segment type: flash */
#define DATAFLASH_PAGE_SIZE            _UL_(        64)
#define DATAFLASH_NB_OF_PAGES          _UL_(       128)

#define DRAM_SIZE                      _UL_(0x00010000)    /*   64kB Memory segment type: ram */
#define HPB0_SIZE                      _UL_(0x00004000)    /*   16kB Memory segment type: io */
#define HPB1_SIZE                      _UL_(0x00010000)    /*   64kB Memory segment type: io */
#define HPB2_SIZE                      _UL_(0x00008000)    /*   32kB Memory segment type: io */
#define HPB3_SIZE                      _UL_(0x00001800)    /*    6kB Memory segment type: io */
#define DIVAS_SIZE                     _UL_(0x00000020)    /*    0kB Memory segment type: io */
#define PPB_SIZE                       _UL_(0x00100000)    /* 1024kB Memory segment type: io */

#define FLASH_ADDR                     _UL_(0x00000000)    /**< FLASH base address (type: flash)*/
#define CAL_ADDR                       _UL_(0x00800000)    /**< CAL base address (type: fuses)*/
#define LOCKBIT_ADDR                   _UL_(0x00802000)    /**< LOCKBIT base address (type: fuses)*/
#define OTP1_ADDR                      _UL_(0x00806000)    /**< OTP1 base address (type: fuses)*/
#define OTP2_ADDR                      _UL_(0x00806008)    /**< OTP2 base address (type: fuses)*/
#define OTP3_ADDR                      _UL_(0x00806010)    /**< OTP3 base address (type: fuses)*/
#define OTP4_ADDR                      _UL_(0x00806018)    /**< OTP4 base address (type: fuses)*/
#define OTP5_ADDR                      _UL_(0x00806020)    /**< OTP5 base address (type: fuses)*/
#define TEMP_LOG_ADDR                  _UL_(0x00806030)    /**< TEMP_LOG base address (type: fuses)*/
#define USER_PAGE_ADDR                 _UL_(0x00804000)    /**< USER_PAGE base address (type: user_page)*/
#define DATAFLASH_ADDR                 _UL_(0x00400000)    /**< DATAFLASH base address (type: flash)*/
#define DRAM_ADDR                      _UL_(0x20000000)    /**< DRAM base address (type: ram)*/
#define HPB0_ADDR                      _UL_(0x40000000)    /**< HPB0 base address (type: io)*/
#define HPB1_ADDR                      _UL_(0x41000000)    /**< HPB1 base address (type: io)*/
#define HPB2_ADDR                      _UL_(0x42000000)    /**< HPB2 base address (type: io)*/
#define HPB3_ADDR                      _UL_(0x43000000)    /**< HPB3 base address (type: io)*/
#define DIVAS_ADDR                     _UL_(0x48000000)    /**< DIVAS base address (type: io)*/
#define PPB_ADDR                       _UL_(0xe0000000)    /**< PPB base address (type: io)*/

/* ************************************************************************** */
/**  DEVICE SIGNATURES FOR PIC32CM5164JH00100                                 */
/* ************************************************************************** */
#define CHIP_DSU_DID                   _UL_(0X1106000E)

/* ************************************************************************** */
/**  ELECTRICAL DEFINITIONS FOR PIC32CM5164JH00100                            */
/* ************************************************************************** */

/* ************************************************************************** */
/** Event Generator IDs for C32CM5164JH00100 */
/* ************************************************************************** */
#define EVENT_ID_GEN_RTC_PERD                             1 /**< ID for RTC event generator PERD */
#define EVENT_ID_GEN_OSCCTRL_XOSC_FAIL                    3 /**< ID for OSCCTRL event generator XOSC_FAIL */
#define EVENT_ID_GEN_OSC32KCTRL_XOSC32K_FAIL              4 /**< ID for OSC32KCTRL event generator XOSC32K_FAIL */
#define EVENT_ID_GEN_RTC_CMP_0                            5 /**< ID for RTC event generator CMP_0 */
#define EVENT_ID_GEN_RTC_CMP_1                            6 /**< ID for RTC event generator CMP_1 */
#define EVENT_ID_GEN_RTC_OVF                              7 /**< ID for RTC event generator OVF */
#define EVENT_ID_GEN_RTC_PER_0                            8 /**< ID for RTC event generator PER_0 */
#define EVENT_ID_GEN_RTC_PER_1                            9 /**< ID for RTC event generator PER_1 */
#define EVENT_ID_GEN_RTC_PER_2                           10 /**< ID for RTC event generator PER_2 */
#define EVENT_ID_GEN_RTC_PER_3                           11 /**< ID for RTC event generator PER_3 */
#define EVENT_ID_GEN_RTC_PER_4                           12 /**< ID for RTC event generator PER_4 */
#define EVENT_ID_GEN_RTC_PER_5                           13 /**< ID for RTC event generator PER_5 */
#define EVENT_ID_GEN_RTC_PER_6                           14 /**< ID for RTC event generator PER_6 */
#define EVENT_ID_GEN_RTC_PER_7                           15 /**< ID for RTC event generator PER_7 */
#define EVENT_ID_GEN_EIC_EXTINT_0                        16 /**< ID for EIC event generator EXTINT_0 */
#define EVENT_ID_GEN_EIC_EXTINT_1                        17 /**< ID for EIC event generator EXTINT_1 */
#define EVENT_ID_GEN_EIC_EXTINT_2                        18 /**< ID for EIC event generator EXTINT_2 */
#define EVENT_ID_GEN_EIC_EXTINT_3                        19 /**< ID for EIC event generator EXTINT_3 */
#define EVENT_ID_GEN_EIC_EXTINT_4                        20 /**< ID for EIC event generator EXTINT_4 */
#define EVENT_ID_GEN_EIC_EXTINT_5                        21 /**< ID for EIC event generator EXTINT_5 */
#define EVENT_ID_GEN_EIC_EXTINT_6                        22 /**< ID for EIC event generator EXTINT_6 */
#define EVENT_ID_GEN_EIC_EXTINT_7                        23 /**< ID for EIC event generator EXTINT_7 */
#define EVENT_ID_GEN_EIC_EXTINT_8                        24 /**< ID for EIC event generator EXTINT_8 */
#define EVENT_ID_GEN_EIC_EXTINT_9                        25 /**< ID for EIC event generator EXTINT_9 */
#define EVENT_ID_GEN_EIC_EXTINT_10                       26 /**< ID for EIC event generator EXTINT_10 */
#define EVENT_ID_GEN_EIC_EXTINT_11                       27 /**< ID for EIC event generator EXTINT_11 */
#define EVENT_ID_GEN_EIC_EXTINT_12                       28 /**< ID for EIC event generator EXTINT_12 */
#define EVENT_ID_GEN_EIC_EXTINT_13                       29 /**< ID for EIC event generator EXTINT_13 */
#define EVENT_ID_GEN_EIC_EXTINT_14                       30 /**< ID for EIC event generator EXTINT_14 */
#define EVENT_ID_GEN_EIC_EXTINT_15                       31 /**< ID for EIC event generator EXTINT_15 */
#define EVENT_ID_GEN_DMAC_CH_0                           32 /**< ID for DMAC event generator CH_0 */
#define EVENT_ID_GEN_DMAC_CH_1                           33 /**< ID for DMAC event generator CH_1 */
#define EVENT_ID_GEN_DMAC_CH_2                           34 /**< ID for DMAC event generator CH_2 */
#define EVENT_ID_GEN_DMAC_CH_3                           35 /**< ID for DMAC event generator CH_3 */
#define EVENT_ID_GEN_TCC0_OVF                            36 /**< ID for TCC0 event generator OVF */
#define EVENT_ID_GEN_TCC0_TRG                            37 /**< ID for TCC0 event generator TRG */
#define EVENT_ID_GEN_TCC0_CNT                            38 /**< ID for TCC0 event generator CNT */
#define EVENT_ID_GEN_TCC0_MC_0                           39 /**< ID for TCC0 event generator MC_0 */
#define EVENT_ID_GEN_TCC0_MC_1                           40 /**< ID for TCC0 event generator MC_1 */
#define EVENT_ID_GEN_TCC0_MC_2                           41 /**< ID for TCC0 event generator MC_2 */
#define EVENT_ID_GEN_TCC0_MC_3                           42 /**< ID for TCC0 event generator MC_3 */
#define EVENT_ID_GEN_TCC1_OVF                            43 /**< ID for TCC1 event generator OVF */
#define EVENT_ID_GEN_TCC1_TRG                            44 /**< ID for TCC1 event generator TRG */
#define EVENT_ID_GEN_TCC1_CNT                            45 /**< ID for TCC1 event generator CNT */
#define EVENT_ID_GEN_TCC1_MC_0                           46 /**< ID for TCC1 event generator MC_0 */
#define EVENT_ID_GEN_TCC1_MC_1                           47 /**< ID for TCC1 event generator MC_1 */
#define EVENT_ID_GEN_TCC2_OVF                            48 /**< ID for TCC2 event generator OVF */
#define EVENT_ID_GEN_TCC2_TRG                            49 /**< ID for TCC2 event generator TRG */
#define EVENT_ID_GEN_TCC2_CNT                            50 /**< ID for TCC2 event generator CNT */
#define EVENT_ID_GEN_TCC2_MC_0                           51 /**< ID for TCC2 event generator MC_0 */
#define EVENT_ID_GEN_TCC2_MC_1                           52 /**< ID for TCC2 event generator MC_1 */
#define EVENT_ID_GEN_TC0_OVF                             53 /**< ID for TC0 event generator OVF */
#define EVENT_ID_GEN_TC0_MC_0                            54 /**< ID for TC0 event generator MC_0 */
#define EVENT_ID_GEN_TC0_MC_1                            55 /**< ID for TC0 event generator MC_1 */
#define EVENT_ID_GEN_TC1_OVF                             56 /**< ID for TC1 event generator OVF */
#define EVENT_ID_GEN_TC1_MC_0                            57 /**< ID for TC1 event generator MC_0 */
#define EVENT_ID_GEN_TC1_MC_1                            58 /**< ID for TC1 event generator MC_1 */
#define EVENT_ID_GEN_TC2_OVF                             59 /**< ID for TC2 event generator OVF */
#define EVENT_ID_GEN_TC2_MC_0                            60 /**< ID for TC2 event generator MC_0 */
#define EVENT_ID_GEN_TC2_MC_1                            61 /**< ID for TC2 event generator MC_1 */
#define EVENT_ID_GEN_TC3_OVF                             62 /**< ID for TC3 event generator OVF */
#define EVENT_ID_GEN_TC3_MC_0                            63 /**< ID for TC3 event generator MC_0 */
#define EVENT_ID_GEN_TC3_MC_1                            64 /**< ID for TC3 event generator MC_1 */
#define EVENT_ID_GEN_TC4_OVF                             65 /**< ID for TC4 event generator OVF */
#define EVENT_ID_GEN_TC4_MC_0                            66 /**< ID for TC4 event generator MC_0 */
#define EVENT_ID_GEN_TC4_MC_1                            67 /**< ID for TC4 event generator MC_1 */
#define EVENT_ID_GEN_ADC0_RESRDY                         68 /**< ID for ADC0 event generator RESRDY */
#define EVENT_ID_GEN_ADC0_WINMON                         69 /**< ID for ADC0 event generator WINMON */
#define EVENT_ID_GEN_ADC1_RESRDY                         70 /**< ID for ADC1 event generator RESRDY */
#define EVENT_ID_GEN_ADC1_WINMON                         71 /**< ID for ADC1 event generator WINMON */
#define EVENT_ID_GEN_AC_COMP_0                           72 /**< ID for AC event generator COMP_0 */
#define EVENT_ID_GEN_AC_COMP_1                           73 /**< ID for AC event generator COMP_1 */
#define EVENT_ID_GEN_AC_COMP_2                           74 /**< ID for AC event generator COMP_2 */
#define EVENT_ID_GEN_AC_COMP_3                           75 /**< ID for AC event generator COMP_3 */
#define EVENT_ID_GEN_AC_WIN_0                            76 /**< ID for AC event generator WIN_0 */
#define EVENT_ID_GEN_AC_WIN_1                            77 /**< ID for AC event generator WIN_1 */
#define EVENT_ID_GEN_DAC_EMPTY                           78 /**< ID for DAC event generator EMPTY */
#define EVENT_ID_GEN_PTC_EOC                             79 /**< ID for PTC event generator EOC */
#define EVENT_ID_GEN_PTC_WCOMP                           80 /**< ID for PTC event generator WCOMP */
#define EVENT_ID_GEN_CCL_LUTOUT_0                        81 /**< ID for CCL event generator LUTOUT_0 */
#define EVENT_ID_GEN_CCL_LUTOUT_1                        82 /**< ID for CCL event generator LUTOUT_1 */
#define EVENT_ID_GEN_CCL_LUTOUT_2                        83 /**< ID for CCL event generator LUTOUT_2 */
#define EVENT_ID_GEN_CCL_LUTOUT_3                        84 /**< ID for CCL event generator LUTOUT_3 */
#define EVENT_ID_GEN_PAC_ACCERR                          85 /**< ID for PAC event generator ACCERR */
#define EVENT_ID_GEN_TC5_OVF                             87 /**< ID for TC5 event generator OVF */
#define EVENT_ID_GEN_TC5_MC_0                            88 /**< ID for TC5 event generator MC_0 */
#define EVENT_ID_GEN_TC5_MC_1                            89 /**< ID for TC5 event generator MC_1 */
#define EVENT_ID_GEN_TC6_OVF                             90 /**< ID for TC6 event generator OVF */
#define EVENT_ID_GEN_TC6_MC_0                            91 /**< ID for TC6 event generator MC_0 */
#define EVENT_ID_GEN_TC6_MC_1                            92 /**< ID for TC6 event generator MC_1 */
#define EVENT_ID_GEN_TC7_OVF                             93 /**< ID for TC7 event generator OVF */
#define EVENT_ID_GEN_TC7_MC_0                            94 /**< ID for TC7 event generator MC_0 */
#define EVENT_ID_GEN_TC7_MC_1                            95 /**< ID for TC7 event generator MC_1 */
#define EVENT_ID_GEN_PDEC_OVF                            96 /**< ID for PDEC event generator OVF */
#define EVENT_ID_GEN_PDEC_ERR                            97 /**< ID for PDEC event generator ERR */
#define EVENT_ID_GEN_PDEC_DIR                            98 /**< ID for PDEC event generator DIR */
#define EVENT_ID_GEN_PDEC_VLC                            99 /**< ID for PDEC event generator VLC */
#define EVENT_ID_GEN_PDEC_MC_0                          100 /**< ID for PDEC event generator MC_0 */
#define EVENT_ID_GEN_PDEC_MC_1                          101 /**< ID for PDEC event generator MC_1 */

/* ************************************************************************** */
/** Event User IDs for C32CM5164JH00100 */
/* ************************************************************************** */
#define EVENT_ID_USER_PORT_EV_0                           1 /**< ID for PORT event user EV_0 */
#define EVENT_ID_USER_PORT_EV_1                           2 /**< ID for PORT event user EV_1 */
#define EVENT_ID_USER_PORT_EV_2                           3 /**< ID for PORT event user EV_2 */
#define EVENT_ID_USER_PORT_EV_3                           4 /**< ID for PORT event user EV_3 */
#define EVENT_ID_USER_DMAC_CH_0                           5 /**< ID for DMAC event user CH_0 */
#define EVENT_ID_USER_DMAC_CH_1                           6 /**< ID for DMAC event user CH_1 */
#define EVENT_ID_USER_DMAC_CH_2                           7 /**< ID for DMAC event user CH_2 */
#define EVENT_ID_USER_DMAC_CH_3                           8 /**< ID for DMAC event user CH_3 */
#define EVENT_ID_USER_TCC0_EV_0                           9 /**< ID for TCC0 event user EV_0 */
#define EVENT_ID_USER_TCC0_EV_1                          10 /**< ID for TCC0 event user EV_1 */
#define EVENT_ID_USER_TCC0_MC_0                          11 /**< ID for TCC0 event user MC_0 */
#define EVENT_ID_USER_TCC0_MC_1                          12 /**< ID for TCC0 event user MC_1 */
#define EVENT_ID_USER_TCC0_MC_2                          13 /**< ID for TCC0 event user MC_2 */
#define EVENT_ID_USER_TCC0_MC_3                          14 /**< ID for TCC0 event user MC_3 */
#define EVENT_ID_USER_TCC1_EV_0                          15 /**< ID for TCC1 event user EV_0 */
#define EVENT_ID_USER_TCC1_EV_1                          16 /**< ID for TCC1 event user EV_1 */
#define EVENT_ID_USER_TCC1_MC_0                          17 /**< ID for TCC1 event user MC_0 */
#define EVENT_ID_USER_TCC1_MC_1                          18 /**< ID for TCC1 event user MC_1 */
#define EVENT_ID_USER_TCC2_EV_0                          19 /**< ID for TCC2 event user EV_0 */
#define EVENT_ID_USER_TCC2_EV_1                          20 /**< ID for TCC2 event user EV_1 */
#define EVENT_ID_USER_TCC2_MC_0                          21 /**< ID for TCC2 event user MC_0 */
#define EVENT_ID_USER_TCC2_MC_1                          22 /**< ID for TCC2 event user MC_1 */
#define EVENT_ID_USER_TC0_EVU                            23 /**< ID for TC0 event user EVU */
#define EVENT_ID_USER_TC1_EVU                            24 /**< ID for TC1 event user EVU */
#define EVENT_ID_USER_TC2_EVU                            25 /**< ID for TC2 event user EVU */
#define EVENT_ID_USER_TC3_EVU                            26 /**< ID for TC3 event user EVU */
#define EVENT_ID_USER_TC4_EVU                            27 /**< ID for TC4 event user EVU */
#define EVENT_ID_USER_ADC0_START                         28 /**< ID for ADC0 event user START */
#define EVENT_ID_USER_ADC0_SYNC                          29 /**< ID for ADC0 event user SYNC */
#define EVENT_ID_USER_ADC1_START                         30 /**< ID for ADC1 event user START */
#define EVENT_ID_USER_ADC1_SYNC                          31 /**< ID for ADC1 event user SYNC */
#define EVENT_ID_USER_AC_SOC_0                           32 /**< ID for AC event user SOC_0 */
#define EVENT_ID_USER_AC_SOC_1                           33 /**< ID for AC event user SOC_1 */
#define EVENT_ID_USER_AC_SOC_2                           34 /**< ID for AC event user SOC_2 */
#define EVENT_ID_USER_AC_SOC_3                           35 /**< ID for AC event user SOC_3 */
#define EVENT_ID_USER_DAC_START                          36 /**< ID for DAC event user START */
#define EVENT_ID_USER_PTC_STCONV                         37 /**< ID for DAC event user PTC_STCONV */
#define EVENT_ID_USER_CCL_LUTIN_0                        38 /**< ID for CCL event user LUTIN_0 */
#define EVENT_ID_USER_CCL_LUTIN_1                        39 /**< ID for CCL event user LUTIN_1 */
#define EVENT_ID_USER_CCL_LUTIN_2                        40 /**< ID for CCL event user LUTIN_2 */
#define EVENT_ID_USER_CCL_LUTIN_3                        41 /**< ID for CCL event user LUTIN_3 */
#define EVENT_ID_USER_MTB_START                          43 /**< ID for MTB event user START */
#define EVENT_ID_USER_MTB_STOP                           44 /**< ID for MTB event user STOP */
#define EVENT_ID_USER_TC5_EVU                            45 /**< ID for TC5 event user EVU */
#define EVENT_ID_USER_TC6_EVU                            46 /**< ID for TC6 event user EVU */
#define EVENT_ID_USER_TC7_EVU                            47 /**< ID for TC7 event user EVU */
#define EVENT_ID_USER_PDEC_EVU_0                         48 /**< ID for PDEC event user EVU_0 */
#define EVENT_ID_USER_PDEC_EVU_1                         49 /**< ID for PDEC event user EVU_1 */
#define EVENT_ID_USER_PDEC_EVU_2                         50 /**< ID for PDEC event user EVU_2 */

#ifdef __cplusplus
}
#endif

/** @}  end of PIC32CM5164JH00100 definitions */


#endif /* _PIC32CM5164JH00100_H_ */

