/* 
 *  Copyright (c) 2008 Texas Instruments. All rights reserved. 
 *  This program and the accompanying materials are made available under the 
 *  terms of the Eclipse Public License v1.0 and Eclipse Distribution License
 *  v. 1.0 which accompanies this distribution. The Eclipse Public License is
 *  available at http://www.eclipse.org/legal/epl-v10.html and the Eclipse
 *  Distribution License is available at 
 *  http://www.eclipse.org/org/documents/edl-v10.php.
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 * */
 
/*
 *  ======== Semaphore.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/knl/ISemaphore.h>

#include "package/internal/Semaphore.xdc.h"

/*
 *  ======== Semaphore_pend ========
 */
Int Semaphore_pend(ISemaphore_Handle sem, UInt timeout, Error_Block *eb)
{
    return (Semaphore_Proxy_pend(sem, timeout, eb));
}

/*
 *  ======== Semaphore_post ========
 */
Bool Semaphore_post(ISemaphore_Handle sem, Error_Block *eb)
{
    return (Semaphore_Proxy_post(sem, eb));
}
/*
 *  @(#) xdc.runtime.knl; 1, 0, 0,0; 4-24-2015 12:34:17; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

