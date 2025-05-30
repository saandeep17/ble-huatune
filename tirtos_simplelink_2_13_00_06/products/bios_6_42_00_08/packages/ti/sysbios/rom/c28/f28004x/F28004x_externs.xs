/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


/*
 * functions referenced in the ROM but not in the ROM
 */

var ROM = xdc.useModule('ti.sysbios.rom.ROM');

ROM.generatedFuncs.$add("xdc_runtime_Startup_getState__I");
ROM.generatedFuncs.$add("xdc_runtime_System_SupportProxy_Module__startupDone__S");
ROM.generatedFuncs.$add("xdc_runtime_System_SupportProxy_abort__E");
ROM.generatedFuncs.$add("xdc_runtime_System_SupportProxy_exit__E");
ROM.generatedFuncs.$add("xdc_runtime_System_SupportProxy_flush__E");
ROM.generatedFuncs.$add("xdc_runtime_System_SupportProxy_putch__E");
ROM.generatedFuncs.$add("xdc_runtime_System_SupportProxy_ready__E");
ROM.generatedFuncs.$add("ti_sysbios_family_c28_Hwi_startup__E");
ROM.generatedFuncs.$add("ti_sysbios_family_c28_Hwi_enableIER__E");
ROM.generatedFuncs.$add("ti_sysbios_family_c28_Hwi_disableIER__E");
ROM.generatedFuncs.$add("ti_sysbios_family_c28_Hwi_restoreIER__E");

/* surgically excluded funcs */
ROM.excludedFuncs.$add("ti_sysbios_family_c28_Timer_setPeriodMicroSecs__E"); /* calls rts lib uldiv */
