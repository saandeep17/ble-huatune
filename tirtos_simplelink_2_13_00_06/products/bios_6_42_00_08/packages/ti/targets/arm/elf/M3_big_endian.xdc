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

/*!
 *  ======== M3_big_endian.xdc ========
 *  Cortex M3 big endian thumb2 (ELF)
 */
metaonly module M3_big_endian inherits ti.targets.arm.elf.IM3_big_endian {
    override readonly config string name        = "M3_big_endian";
    override readonly config string suffix      = "em3e";
    override readonly config string rts         = "ti.targets.arm.rtsarm";

    override readonly config xdc.bld.ITarget2.Command cc = {
        cmd:  "armcl -c",
        opts: "--endian=big -mv7M3 --abi=eabi"
    };

    override readonly config xdc.bld.ITarget2.Command asm = {
        cmd:  "armcl -c",
        opts: "--endian=big -mv7M3 --abi=eabi"
    };
}
/*
 *  @(#) ti.targets.arm.elf; 1, 0, 0,5; 2-27-2015 12:11:34; /db/ztree/library/trees/xdctargets/xdctargets-i02/src/ xlibrary

 */

