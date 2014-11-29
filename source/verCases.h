
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

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "uint128.h"
#include "softfloat.h"

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/

extern const char *verCases_functionNamePtr;
extern uint_fast8_t verCases_roundingPrecision;
extern int verCases_roundingCode;
extern int verCases_tininessCode;
extern bool verCases_usesExact, verCases_exact;
extern bool verCases_checkNaNs;
extern uint_fast32_t verCases_maxErrorCount;
extern bool verCases_errorStop;

void verCases_writeFunctionName( FILE * );

extern volatile bool verCases_stop;

extern bool verCases_anyErrors;

void verCases_exitWithStatus( void );

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/

INLINE bool f32_same( float32_t a, float32_t b )
{
    union { uint32_t ui; float32_t f; } uA, uB;
    uA.f = a;
    uB.f = b;
    return (uA.ui == uB.ui);
}

INLINE bool f32_isNaN( float32_t a )
{
    union { uint32_t ui; float32_t f; } uA;
    uA.f = a;
    return 0x7F800000 < (uA.ui & 0x7FFFFFFF);
}

INLINE bool f64_same( float64_t a, float64_t b )
{
    union { uint64_t ui; float64_t f; } uA, uB;
    uA.f = a;
    uB.f = b;
    return (uA.ui == uB.ui);
}

INLINE bool f64_isNaN( float64_t a )
{
    union { uint64_t ui; float64_t f; } uA;
    uA.f = a;
    return
        UINT64_C( 0x7FF0000000000000 )
            < (uA.ui & UINT64_C( 0x7FFFFFFFFFFFFFFF ));
}

#ifdef EXTFLOAT80

INLINE bool extF80M_same( const extFloat80_t *aPtr, const extFloat80_t *bPtr )
{
    const struct extFloat80M *aSPtr = (const struct extFloat80M *) aPtr;
    const struct extFloat80M *bSPtr = (const struct extFloat80M *) bPtr;
    return
        (aSPtr->signExp == bSPtr->signExp) && (aSPtr->signif == bSPtr->signif);
}

INLINE bool extF80M_isNaN( const extFloat80_t *aPtr )
{
    const struct extFloat80M *aSPtr = (const struct extFloat80M *) aPtr;
    return
        ((aSPtr->signExp & 0x7FFF) == 0x7FFF)
            && (aSPtr->signif & UINT64_C( 0x7FFFFFFFFFFFFFFF ));
}

#endif

#ifdef FLOAT128

INLINE bool f128M_same( const float128_t *aPtr, const float128_t *bPtr )
{
    const struct uint128 *uiAPtr = (const struct uint128 *) aPtr;
    const struct uint128 *uiBPtr = (const struct uint128 *) bPtr;
    return (uiAPtr->v64 == uiBPtr->v64) && (uiAPtr->v0 == uiBPtr->v0);
}

INLINE bool f128M_isNaN( const float128_t *aPtr )
{
    const struct uint128 *uiAPtr = (const struct uint128 *) aPtr;
    uint_fast64_t absA64 = uiAPtr->v64 & UINT64_C( 0x7FFFFFFFFFFFFFFF );
    return
        (UINT64_C( 0x7FFF000000000000 ) < absA64)
            || ((absA64 == UINT64_C( 0x7FFF000000000000 )) && uiAPtr->v0);
}

#endif

extern uint_fast32_t verCases_tenThousandsCount, verCases_errorCount;

void verCases_writeTestsPerformed( int );
void verCases_perTenThousand( void );
void verCases_writeErrorFound( int );

