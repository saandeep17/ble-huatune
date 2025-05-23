/*
 * Copyright (c) 2014, Texas Instruments Incorporated
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
 *  ======== Seconds.xdc ========
 */

package ti.sysbios.hal;

import xdc.rov.ViewInfo;

/*!
 *  ======== Seconds ========
 *  Seconds Manager.
 *
 *  This module is a proxy to the device-specific Seconds module functions
 *  as defined in ISeconds.xdc.
 *
 *  This module generates a custom time() function in the
 *  configuration-generated .c file.  This time() function calls Seconds_get()
 *  to get the number of seconds since 1970 from a device-specific delegate
 *  function.
 *
 *  Note: For TI codegen tools, time() returns the number of seconds since
 *  1900. The generated time() function takes this into account, and adds the
 *  number of seconds from 1900 to 1970 to the value returned by Seconds_get().
 *  This allows functions such as localtime() to work correctly with TI tools.
 *
 *  The actual implementations of the Seconds module functions are
 *  provided by the Seconds module delegates.
 *
 *  Additional, family-specific Seconds module APIs may also be provided
 *  by the Seconds module delegates.
 *
 *  Follow the link below to determine which Seconds delegate is used
 *  for your Target/Device:
 *
 *      {@link ./../family/doc-files/delegates.html Delegate Mappings}
 *
 *  @p(html)
 *  <h3> Calling Context </h3>
 *  <table border="1" cellpadding="3">
 *    <colgroup span="1"></colgroup> <colgroup span="5" align="center">
 *    </colgroup>
 *
 *    <tr><th> Function                 </th><th>  Hwi   </th><th>  Swi   </th>
 *    <th>  Task  </th><th>  Main  </th><th>  Startup  </th></tr>
 *    <!--                                            -->
 *    <tr><td> {@link #get} </td><td>   Y    </td><td>   Y    </td>
 *    <td>   Y    </td><td>   Y    </td><td>   Y    </td></tr>
 *    <tr><td> {@link #set} </td><td>   N    </td><td>   N    </td>
 *    <td>   Y    </td><td>   Y    </td><td>   Y    </td></tr>
 *    <tr><td colspan="6"> Definitions: <br />
 *       <ul>
 *         <li> <b>Hwi</b>: API is callable from a Hwi thread. </li>
 *         <li> <b>Swi</b>: API is callable from a Swi thread. </li>
 *         <li> <b>Task</b>: API is callable from a Task thread. </li>
 *         <li> <b>Main</b>: API is callable during any of these phases: </li>
 *           <ul>
 *             <li> In your module startup after this module is started
 *    (e.g. Seconds_Module_startupDone() returns TRUE). </li>
 *             <li> During xdc.runtime.Startup.lastFxns. </li>
 *             <li> During main().</li>
 *             <li> During BIOS.startupFxns.</li>
 *           </ul>
 *         <li> <b>Startup</b>: API is callable during any of these phases:</li>
 *           <ul>
 *             <li> During xdc.runtime.Startup.firstFxns.</li>
 *             <li> In your module startup before this module is started
 *    (e.g. Seconds_Module_startupDone() returns FALSE).</li>
 *           </ul>
 *       </ul>
 *    </td></tr>
 *
 *  </table>
 *  @p
 *
 *  Usage example with run-time support library:
 *
 *  @p(code)
 *  #include <ti/sysbios/hal/Seconds.h>
 *  #include <time.h>
 *
 *  time_t t;
 *  struct tm *ltm;
 *  char *curTime;
 *
 *  Seconds_set(STARTTIME);
 *
 *  t = time(NULL);
 *  ltm = localtime(&t);
 *  curTime = asctime(ltm);
 *  System_printf("Time(GMT): %s\n", curTime);
 *  @p
 */

@Template("./Seconds.xdt")
module Seconds inherits ti.sysbios.interfaces.ISeconds
{
   /*!
    *  ======== generateTimeFuncton ========
    *  Generate time() function that will call Seconds_get() internally.
    *
    *  This generated function will override the compiler's RTS library's
    *  time() function.
    */
    metaonly config Bool generateTimeFunction = true;

    /*!
     *  ======== SecondsProxy ========
     *  Target/device-specific Seconds implementation
     */
    proxy SecondsProxy inherits ti.sysbios.interfaces.ISeconds;
}
