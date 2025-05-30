/* 
 *  Copyright (c) 2008 Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 *
 * */
/*
 *  ======== C64T.xdc ========
 *
 */

import xdc.bld.ITarget2;

/*!
 *  ======== C64T ========
 *  TI C64T default runtime model (little endian)
 */
metaonly module C64T inherits ti.targets.ITarget {
    override readonly config string name                 = "C64T";
    override readonly config string suffix               = "64T";
    override readonly config string isa                  = "64T";
    override readonly config xdc.bld.ITarget.Model model = {
        endian: "little"
    };
    override readonly config xdc.bld.ITarget.Module base = ti.targets.C64P;

    override readonly config string rts = "ti.targets.rts6000";
    override config string platform     = "ti.platforms.sdp4430";
    override readonly config string stdInclude = "ti/targets/std.h";

    override readonly config ITarget2.Command ar = {
        cmd: "ar6x",
        opts: "rq"
    };

    override readonly config ITarget2.Command cc = {
        cmd: "cl6x -c",
        opts: "-mv=tesla --abi=coffabi"
    };

    override readonly config ITarget2.Command vers = {
        cmd: "cl6x",
        opts: "--compiler_revision"
    };

    override readonly config ITarget2.Command asm = {
        cmd: "cl6x -c",
        opts: "-mv=tesla --abi=coffabi"
    };

    override readonly config ITarget2.Command lnk = {
        cmd: "lnk6x",
        opts: "--abi=coffabi"
    };

    /*!
     *  ======== asmOpts ========
     *  User configurable assembler options.
     *
     *  Defaults:
     *  @p(dlist)
     *      -`-qq`
     *          super quiet mode
     */
    override config ITarget2.Options asmOpts = {
        prefix: "-qq",
        suffix: ""
    };

    /*!
     *  ======== ccOpts ========
     *  User configurable compiler options.
     *
     *  Defaults:
     *  @p(dlist)
     *      -`-qq`
     *          super quiet mode
     *      -`-pdsw225`
     *          generate a warning for implicitly declared functions; i.e.,
     *          functions without prototypes
     */
    override config ITarget2.Options ccOpts = {
        prefix: "-qq -pdsw225",
        suffix: ""
    };

    /*!
     *  ======== ccConfigOpts ========
     *  User configurable compiler options for the generated config C file.
     *
     *  -mo places all functions into subsections
     *  --no_compress helps with compile time with no real difference in
     *  code size since the generated config.c is mostly data and small
     *  function stubs.
     */
    override config ITarget2.Options ccConfigOpts = {
        prefix: "$(ccOpts.prefix) -mo --no_compress",
        suffix: "$(ccOpts.suffix)"
    };

    override config string includeOpts = "-I$(rootDir)/include";

    final override readonly config string sectMap[string] =
        ti.targets.C64P.sectMap;

    final override readonly config Bool splitMap[string] =
        ti.targets.C64P.splitMap;

    override readonly config xdc.bld.ITarget.StdTypes stdTypes = 
        ti.targets.C64P.stdTypes;

    override readonly config Int bitsPerChar =
        ti.targets.C64P.bitsPerChar;
}
/*
 *  @(#) ti.targets; 1, 0, 3,5; 2-27-2015 12:11:32; /db/ztree/library/trees/xdctargets/xdctargets-i02/src/ xlibrary

 */

