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
 *  ======== readFile ========
 */
function readFile(filename)
{
    var line, idx = 0;
    var lineArr = new Array();

    /* Open file */
    var file = new java.io.BufferedReader(new java.io.FileReader(filename));

    /* Read file */
    while ((line = file.readLine()) != null) {
        lineArr[idx++] = line;
    }

    return lineArr;
}

/*
 *  ======== writeFile ========
 */
function writeFile(filename, content)
{
    var idx = 0;

    /* Open/Create file */
    var file = new java.io.FileWriter(filename);

    for(idx = 0; idx < content.length; idx++) {
        file.write(content[idx] + "\n");
    }
    file.flush();
}

function main(args)
{
    var sourceFile = args[0];
    var destFile = args[1];
    var funcsFile = args[2];
    var funcs = String(args[3]);

    var funcsArr;
    var funcsRegEx;
    var srcArr;
    var srcLine;
    var matchIndex, funcType;
    var srcIdx, funcsIdx;
    var result;

    var mangle;

    srcArr = readFile(sourceFile);
    if (args[3] === undefined) {
        funcsArr = readFile(funcsFile);
        funcsRegEx = new RegExp(funcsArr.join("|"));
    }
    else {
        funcsRegEx = new RegExp(funcs.replace(/ /g, "|"));
    }
    
    for (srcIdx = 0; srcIdx < srcArr.length; srcIdx++) {
        srcLine = srcArr[srcIdx].toString();
        if ((srcLine.indexOf("extern") != 0) && (srcLine.indexOf(" ") != 0)){
            result = funcsRegEx.exec(srcLine);
            if (result != null) {
		/* mangle the function name so it won't be found in the sysbios lib */
		srcArr[srcIdx] = srcArr[srcIdx].replace(result[0], result[0]+"__mangled__");
//print("mangling " + result[0] + ": " + srcArr[srcIdx].toString());
	    }
        }
    }

    writeFile(destFile, srcArr);
}
