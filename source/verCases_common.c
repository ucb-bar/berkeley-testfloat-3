
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
#include <stdlib.h>
#include <stdio.h>
#include "platform.h"
#include "verCases.h"

const char *verCases_functionNamePtr;
uint_fast8_t verCases_roundingPrecision = 0;
int verCases_roundingCode = 0;
int verCases_tininessCode = 0;
bool verCases_usesExact = false;
bool verCases_exact;
bool verCases_checkNaNs = false;
uint_fast32_t verCases_maxErrorCount = 0;
bool verCases_errorStop = false;

volatile bool verCases_stop = false;

bool verCases_anyErrors = false;

void verCases_exitWithStatus( void )
{

    exit( verCases_anyErrors ? EXIT_FAILURE : EXIT_SUCCESS );

}

uint_fast32_t verCases_tenThousandsCount, verCases_errorCount;

void verCases_writeTestsPerformed( int count )
{

    if ( verCases_tenThousandsCount ) {
        fprintf(
            stderr,
            "\r%lu%04d tests performed",
            (unsigned long) verCases_tenThousandsCount,
            count
        );
    } else {
        fprintf( stderr, "\r%d tests performed", count );
    }
    if ( verCases_errorCount ) {
        fprintf(
            stderr,
            "; %lu error%s found.\n",
            (unsigned long) verCases_errorCount,
            (verCases_errorCount == 1) ? "" : "s"
        );
    } else {
        fputs( ".\n", stderr );
        if ( verCases_tenThousandsCount ) {
            fprintf(
                stdout,
                "In %lu%04d tests, no errors found in ",
                (unsigned long) verCases_tenThousandsCount,
                count
            );
        } else {
            fprintf( stdout, "In %d tests, no errors found in ", count );
        }
        verCases_writeFunctionName( stdout );
        fputs( ".\n", stdout );
        fflush( stdout );
    }

}

void verCases_perTenThousand( void )
{

    ++verCases_tenThousandsCount;
    if ( verCases_stop ) {
        verCases_writeTestsPerformed( 0 );
        verCases_exitWithStatus();
    }
    fprintf(
        stderr, "\r%3lu0000", (unsigned long) verCases_tenThousandsCount );

}

void verCases_writeErrorFound( int count )
{

    fputc( '\r', stderr );
    if ( verCases_errorCount == 1 ) {
        fputs( "Errors found in ", stdout );
        verCases_writeFunctionName( stdout );
        fputs( ":\n", stdout );
    }
    if ( verCases_stop ) {
        verCases_writeTestsPerformed( count );
        verCases_exitWithStatus();
    }
    verCases_anyErrors = true;

}

