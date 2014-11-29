
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

#include <stdint.h>
#include <stdlib.h>
#include "platform.h"
#include "random.h"

uint_fast8_t random_ui8( void )
{

    return rand()>>4 & 0xFF;

}

uint_fast16_t random_ui16( void )
{

    return (rand() & 0x0FF0)<<4 | (rand()>>4 & 0xFF);

}

uint_fast32_t random_ui32( void )
{

    return
          (uint_fast32_t) (rand() & 0x0FF0)<<20
        | (uint_fast32_t) (rand() & 0x0FF0)<<12
        | (rand() & 0x0FF0)<<4
        | (rand()>>4 & 0xFF);

}

uint_fast64_t random_ui64( void )
{

    return (uint_fast64_t) random_ui32()<<32 | random_ui32();

}

uint_fast8_t randomN_ui8( uint_fast8_t N )
{
    uint_fast8_t scale, z;

    scale = 0;
    while ( N < 0x80 ) {
        ++scale;
        N <<= 1;
    }
    do {
        z = random_ui8();
    } while ( N <= z );
    return z>>scale;

}

uint_fast16_t randomN_ui16( uint_fast16_t N )
{
    uint_fast16_t scale, z;

    scale = 0;
    while ( N < 0x8000 ) {
        ++scale;
        N <<= 1;
    }
    do {
        z = random_ui16();
    } while ( N <= z );
    return z>>scale;

}

uint_fast32_t randomN_ui32( uint_fast32_t N )
{
    uint_fast32_t scale, z;

    scale = 0;
    while ( N < 0x8000 ) {
        ++scale;
        N <<= 1;
    }
    do {
        z = random_ui32();
    } while ( N <= z );
    return z>>scale;

}

uint_fast64_t randomN_ui64( uint_fast64_t N )
{
    uint_fast64_t scale, z;

    scale = 0;
    while ( N < 0x8000 ) {
        ++scale;
        N <<= 1;
    }
    do {
        z = random_ui64();
    } while ( N <= z );
    return z>>scale;

}

