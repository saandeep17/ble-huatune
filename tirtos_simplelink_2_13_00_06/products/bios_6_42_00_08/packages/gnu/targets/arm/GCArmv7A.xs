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
 *  ======== GCArmv7A.getISAChain ========
 *  GCArmv7A implementation for ITarget.getISAChain()
 */
function getISAChain(isa)
{
    var myChain = [this.$package.GCArmv5T.isa, this.$package.GCArmv6.isa,
        this.isa];
    var isaIn = (isa == null ? this.isa : isa);

    for (var i = 0; i < myChain.length; i++) {
        if (myChain[i] == isaIn) {
            break;
        }
    }

    if (i == myChain.length) {
        return (null);
    }
    else {
        return (myChain.slice(0, i + 1));
    }
}

/*
 *  @(#) gnu.targets.arm; 1, 0, 0,5; 2-27-2015 12:11:22; /db/ztree/library/trees/xdctargets/xdctargets-i02/src/ xlibrary

 */

