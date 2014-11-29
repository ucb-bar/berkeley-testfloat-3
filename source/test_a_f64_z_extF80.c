
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
#include "platform.h"
#include "softfloat.h"
#include "genCases.h"
#include "verCases.h"
#include "writeCase.h"
#include "testLoops.h"

#ifdef EXTFLOAT80

#pragma STDC FENV_ACCESS ON

void
 test_a_f64_z_extF80(
     void trueFunction( float64_t, extFloat80_t * ),
     void subjFunction( float64_t, extFloat80_t * )
 )
{
    int count;
    extFloat80_t trueZ;
    uint_fast8_t trueFlags;
    extFloat80_t subjZ;
    uint_fast8_t subjFlags;

    genCases_f64_a_init();
    genCases_writeTestsTotal( testLoops_forever );
    verCases_errorCount = 0;
    verCases_tenThousandsCount = 0;
    count = 10000;
    while ( ! genCases_done || testLoops_forever ) {
        genCases_f64_a_next();
        *testLoops_trueFlagsPtr = 0;
        trueFunction( genCases_f64_a, &trueZ );
        trueFlags = *testLoops_trueFlagsPtr;
        testLoops_subjFlagsFunction();
        subjFunction( genCases_f64_a, &subjZ );
        subjFlags = testLoops_subjFlagsFunction();
        --count;
        if ( ! count ) {
            verCases_perTenThousand();
            count = 10000;
        }
        if ( ! extF80M_same( &trueZ, &subjZ ) || (trueFlags != subjFlags) ) {
            if (
                ! verCases_checkNaNs && f64_isSignalingNaN( genCases_f64_a )
            ) {
                trueFlags |= softfloat_flag_invalid;
            }
            if (
                   verCases_checkNaNs
                || ! extF80M_isNaN( &trueZ )
                || ! extF80M_isNaN( &subjZ )
                || extF80M_isSignalingNaN( &subjZ )
                || (trueFlags != subjFlags)
            ) {
                ++verCases_errorCount;
                verCases_writeErrorFound( 10000 - count );
                writeCase_a_f64( genCases_f64_a, "  " );
                writeCase_z_extF80M( &trueZ, trueFlags, &subjZ, subjFlags );
                if ( verCases_errorCount == verCases_maxErrorCount ) break;
            }
        }
    }
    verCases_writeTestsPerformed( 10000 - count );

}

#endif

