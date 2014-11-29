
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
#include <stdio.h>
#include "platform.h"
#include "uint128.h"
#include "softfloat.h"
#include "writeHex.h"

void writeHex_bool( bool a, char sepChar )
{

    fputc( a ? '1' : '0', stdout );
    if ( sepChar ) fputc( sepChar, stdout );

}

void writeHex_ui8( uint_fast8_t a, char sepChar )
{
    int digit;

    digit = a>>4 & 0xF;
    if ( 9 < digit ) digit += 'A' - ('0' + 10);
    fputc( '0' + digit, stdout );
    digit = a & 0xF;
    if ( 9 < digit ) digit += 'A' - ('0' + 10);
    fputc( '0' + digit, stdout );
    if ( sepChar ) fputc( sepChar, stdout );

}

static void writeHex_ui12( uint_fast16_t a, char sepChar )
{
    int digit;

    digit = a>>8 & 0xF;
    if ( 9 < digit ) digit += 'A' - ('0' + 10);
    fputc( '0' + digit, stdout );
    digit = a>>4 & 0xF;
    if ( 9 < digit ) digit += 'A' - ('0' + 10);
    fputc( '0' + digit, stdout );
    digit = a & 0xF;
    if ( 9 < digit ) digit += 'A' - ('0' + 10);
    fputc( '0' + digit, stdout );
    if ( sepChar ) fputc( sepChar, stdout );

}

void writeHex_ui16( uint_fast16_t a, char sepChar )
{
    int digit;

    digit = a>>12 & 0xF;
    if ( 9 < digit ) digit += 'A' - ('0' + 10);
    fputc( '0' + digit, stdout );
    digit = a>>8 & 0xF;
    if ( 9 < digit ) digit += 'A' - ('0' + 10);
    fputc( '0' + digit, stdout );
    digit = a>>4 & 0xF;
    if ( 9 < digit ) digit += 'A' - ('0' + 10);
    fputc( '0' + digit, stdout );
    digit = a & 0xF;
    if ( 9 < digit ) digit += 'A' - ('0' + 10);
    fputc( '0' + digit, stdout );
    if ( sepChar ) fputc( sepChar, stdout );

}

void writeHex_ui32( uint_fast32_t a, char sepChar )
{

    writeHex_ui16( a>>16, 0 );
    writeHex_ui16( a, sepChar );

}

void writeHex_ui64( uint_fast64_t a, char sepChar )
{

    writeHex_ui32( a>>32, 0 );
    writeHex_ui32( a, sepChar );

}

void writeHex_f32( float32_t a, char sepChar )
{
    union { uint32_t ui; float32_t f; } uA;
    uint_fast32_t uiA;

    uA.f = a;
    uiA = uA.ui;
    fputc( (0x80000000 <= uiA) ? '8' : '0', stdout );
    writeHex_ui8( uiA>>23, 0 );
    fputc( '.', stdout );
    writeHex_ui8( uiA>>16 & 0x7F, 0 );
    writeHex_ui16( uiA, sepChar );

}

void writeHex_f64( float64_t a, char sepChar )
{
    union { uint64_t ui; float64_t f; } uA;
    uint_fast64_t uiA;

    uA.f = a;
    uiA = uA.ui;
    writeHex_ui12( uiA>>52, 0 );
    fputc( '.', stdout );
    writeHex_ui12( uiA>>40, 0 );
    writeHex_ui8( uiA>>32, 0 );
    writeHex_ui32( uiA, sepChar );

}

#ifdef EXTFLOAT80

void writeHex_extF80M( const extFloat80_t *aPtr, char sepChar )
{
    const struct extFloat80M *aSPtr;

    aSPtr = (const struct extFloat80M *) aPtr;
    writeHex_ui16( aSPtr->signExp, 0 );
    fputc( '.', stdout );
    writeHex_ui64( aSPtr->signif, sepChar );

}

#endif

#ifdef FLOAT128

void writeHex_f128M( const float128_t *aPtr, char sepChar )
{
    const struct uint128 *uiAPtr;
    uint_fast64_t uiA64;

    uiAPtr = (const struct uint128 *) aPtr;
    uiA64 = uiAPtr->v64;
    writeHex_ui16( uiA64>>48, 0 );
    fputc( '.', stdout );
    writeHex_ui16( uiA64>>32, 0 );
    writeHex_ui32( uiA64, 0 );
    writeHex_ui64( uiAPtr->v0, sepChar );

}

#endif

void writeHex_softfloat_flags( uint_fast8_t flags, char sepChar )
{

    fputc( flags & softfloat_flag_invalid   ? 'v' : '.', stdout );
    fputc( flags & softfloat_flag_infinite  ? 'i' : '.', stdout );
    fputc( flags & softfloat_flag_overflow  ? 'o' : '.', stdout );
    fputc( flags & softfloat_flag_underflow ? 'u' : '.', stdout );
    fputc( flags & softfloat_flag_inexact   ? 'x' : '.', stdout );
    if ( sepChar ) fputc( sepChar, stdout );

}

