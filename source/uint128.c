
/*============================================================================

This C source file is part of TestFloat, Release 3, a package of programs for
testing the correctness of floating-point arithmetic complying with the IEEE
Standard for Floating-Point, by John R. Hauser.

Copyright 2011, 2012, 2013, 2014 The Regents of the University of California
(Regents).  All Rights Reserved.  Redistribution and use in source and binary
forms, with or without modification, are permitted provided that the following
conditions are met:

Redistributions of source code must retain the above copyright notice,
this list of conditions, and the following two paragraphs of disclaimer.
Redistributions in binary form must reproduce the above copyright notice,
this list of conditions, and the following two paragraphs of disclaimer in the
documentation and/or other materials provided with the distribution.  Neither
the name of the Regents nor the names of its contributors may be used to
endorse or promote products derived from this software without specific prior
written permission.

IN NO EVENT SHALL REGENTS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING
OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF REGENTS HAS
BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE.  THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED
HEREUNDER IS PROVIDED "AS IS".  REGENTS HAS NO OBLIGATION TO PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

=============================================================================*/

#include <stdbool.h>
#include <stdint.h>
#include "platform.h"
#include "uint128.h"

struct uint128 shortShiftLeft128( struct uint128 a, int count )
{
    struct uint128 z;

    z.v64 = a.v64<<count | a.v0>>(-count & 63);
    z.v0 = a.v0<<count;
    return z;

}

struct uint128 shortShiftRight128( struct uint128 a, int count )
{
    struct uint128 z;

    z.v64 = a.v64>>count;
    z.v0 = a.v64<<(-count & 63) | a.v0>>count;
    return z;

}

struct uint128 shortShiftRightJam128( struct uint128 a, int count )
{
    int negCount;
    struct uint128 z;

    negCount = -count;
    z.v64 = a.v64>>count;
    z.v0 =
        a.v64<<(negCount & 63) | a.v0>>count
            | ((uint64_t) (a.v0<<(negCount & 63)) != 0);
    return z;

}

struct uint128 neg128( struct uint128 a )
{

    if ( a.v0 ) {
        a.v64 = ~a.v64;
        a.v0 = -a.v0;
    } else {
        a.v64 = -a.v64;
    }
    return a;

}

struct uint128 add128( struct uint128 a, struct uint128 b )
{
    struct uint128 z;

    z.v0 = a.v0 + b.v0;
    z.v64 = a.v64 + b.v64 + (z.v0 < a.v0);
    return z;

}

