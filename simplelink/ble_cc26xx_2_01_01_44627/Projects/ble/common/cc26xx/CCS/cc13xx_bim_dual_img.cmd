//*****************************************************************************
//! @file       cc26xx_ble_app.cmd
//! @brief      CC2650F128 linker configuration file for TI-RTOS with
//!             Code Composer Studio.
//!
//! Revised     $Date$
//! Revision    $Revision$
//
//  Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
//
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//
//    Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//****************************************************************************/

/* Retain interrupt vector table variable                                    */
--retain=g_pfnVectors
/* Override default entry point.                                             */
/*--entry_point ResetISR                                                     */
/* Suppress warnings and errors:                                             */
/* - 10063: Warning about entry point not being _c_int00                     */
/* - 16011, 16012: 8-byte alignment errors. Observed when linking in object  */ 
/*   files compiled using Keil (ARM compiler)                                */
--diag_suppress=10063,16011,16012

/* The following command line options are set as part of the CCS project.    */
	/* If you are building using the command line, or for some reason want to    */
/* define them here, you can uncomment and modify these lines as needed.     */
/* If you are using CCS for building, it is probably better to make any such */
/* modifications in your CCS project and leave this file alone.              */
/*                                                                           */
/* --heap_size=0                                                             */
/* --stack_size=256                                                          */
/* --library=rtsv7M3_T_le_eabi.lib                                           */

/* The starting address of the application.  Normally the interrupt vectors  */
/* must be located at the beginning of the application.                      */
#define FLASH_BASE              0x00000000
#define BIM_BASE                0x0001F000
#define PAGE_SIZE               0x1000
#define RAM_BASE                0x20000000
#define RAM_SIZE                0x5000


/* System memory map */

MEMORY
{
    /* EDITOR'S NOTE:
     * the FLASH and SRAM lengths can be changed by defining
     * ICALL_STACK0_ADDR or ICALL_RAM0_ADDR in
     * Properties->ARM Linker->Advanced Options->Command File Preprocessing.
     */

    IVEC_FLASH (RX) : origin = FLASH_BASE, length = PAGE_SIZE

    /* BIM stored in and executes from internal flash */
    /* Flash Size 4 KB */
    FLASH (RX) : origin = BIM_BASE, length = PAGE_SIZE

    // CCFG Page, contains .ccfg code section and some application code.
    //FLASH_LAST_PAGE (RX) :  origin = FLASH_SIZE - 0x1000, length = 0x1000

    /* Application uses internal RAM for data */
    /* RAM Size 16 KB */
    SRAM (RWX) : origin = RAM_BASE, length = 0x00002CFF
}

/* Section allocation in memory */

SECTIONS
{
    .resetVecs      :   > IVEC_FLASH
    .intvecs        :   > IVEC_FLASH
    .text           :   > FLASH
    .const          :   > FLASH
    .constdata      :   > FLASH
    .rodata         :   > FLASH
    .cinit          :   > FLASH
    .pinit          :   > FLASH
    .init_array     :   > FLASH
    .emb_text       :   > FLASH
    .ccfg           :   > FLASH (HIGH)

    .vtable         :   > SRAM
    .vtable_ram     :   > SRAM
     vtable_ram     :   > SRAM
    .data           :   > SRAM
    .bss            :   > SRAM
    .sysmem         :   > SRAM
    .stack          :   > SRAM (HIGH)
    .nonretenvar    :   > SRAM
}

/* Create global constant that points to top of stack */
/* CCS: Change stack size under Project Properties    */
__STACK_TOP = __stack + __STACK_SIZE;

/* Allow main() to take args */
/*--args 0x8*/
