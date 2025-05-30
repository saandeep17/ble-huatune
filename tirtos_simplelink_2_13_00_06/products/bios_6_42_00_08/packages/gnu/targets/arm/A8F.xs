/* 
 *  Copyright (c) 2012 Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 *
 * */

var A8F;

/*
 *  ======== A8.getISAChain ========
 *  A8 implementation for ITarget.getISAChain()
 */
function getISAChain (isa)
{
    var myChain = ["v7A", this.isa];
    var isaIn = (isa == null ? this.isa : isa)

    /* Check if 'isa' belongs to v7A family */
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
 *  ======== module$meta$init ========
 */
function module$meta$init()
{
    A8F = this;
}

/*
 *  ======== A8F.compile ========
 */
function compile(goal) {
    if (A8F.targetPkgPath == null) {
        A8F.targetPkgPath = this.$package.packageBase;
    }

    goal.opts.copts += " -I" + A8F.targetPkgPath +
        "/libs/install-native/$(GCCTARG)/include ";

    goal.opts.cfgcopts += " -I" + A8F.targetPkgPath +
        "/libs/install-native/$(GCCTARG)/include ";

    return (this.$super.compile(goal));
}

/*
 *  ======== A8F.link ========
 */
function link(goal)
{
    if (A8F.targetPkgPath == null) {
        A8F.targetPkgPath = this.$package.packageBase;
    }

    goal.opts += " -L" + A8F.targetPkgPath +
        "/libs/install-native/$(GCCTARG)/lib/fpu ";

    return(this.$super.link(goal));
}
/*
 *  @(#) gnu.targets.arm; 1, 0, 0,5; 2-27-2015 12:11:21; /db/ztree/library/trees/xdctargets/xdctargets-i02/src/ xlibrary

 */

