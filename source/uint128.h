
/*============================================================================

This C header file is part of TestFloat, Release 3, a package of programs for
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

#ifndef uint128_h
#define uint128_h 1

#include <stdbool.h>
#include <stdint.h>

#ifdef LITTLEENDIAN
struct uint128 { uint64_t v0, v64; };
#else
struct uint128 { uint64_t v64, v0; };
#endif

INLINE bool eq128( struct uint128 a, struct uint128 b )
    { return (a.v64 == b.v64) && (a.v0 == b.v0); }

INLINE bool le128( struct uint128 a, struct uint128 b )
    { return (a.v64 < b.v64) || ((a.v64 == b.v64) && (a.v0 <= b.v0)); }

INLINE bool lt128( struct uint128 a, struct uint128 b )
    { return (a.v64 < b.v64) || ((a.v64 == b.v64) && (a.v0 < b.v0)); }

struct uint128 shortShiftLeft128( struct uint128, int );
struct uint128 shortShiftRight128( struct uint128, int );
struct uint128 shortShiftRightJam128( struct uint128, int );
struct uint128 neg128( struct uint128 );
struct uint128 add128( struct uint128, struct uint128 );

#endif

