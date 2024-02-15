
/*============================================================================

This C source file is part of TestFloat, Release 3e, a package of programs for
testing the correctness of floating-point arithmetic complying with the IEEE
Standard for Floating-Point, by John R. Hauser.

Copyright 2011, 2012, 2013, 2014 The Regents of the University of California.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions, and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions, and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 3. Neither the name of the University nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS", AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "platform.h"
#include "random.h"
#include "softfloat.h"
#include "genCases.h"

#ifdef BFLOAT16

struct sequence {
    int expNum, term1Num, term2Num;
    bool done;
};

union ui16_bf16 { uint16_t ui; bfloat16_t f; };

enum {
    bf16NumQIn  = 22,
    bf16NumQOut = 50,
    bf16NumP1   =  4,
    bf16NumP2   = 25
};
static const uint16_t bf16QIn[bf16NumQIn] = {
    0x0000,    /* positive, subnormal       */
    0x0080,    /* positive, -126            */
    0x3380,    /* positive,  -24            */
    0x3E80,    /* positive,   -2            */
    0x3F00,    /* positive,   -1            */
    0x3F80,    /* positive,    0            */
    0x4000,    /* positive,    1            */
    0x4080,    /* positive,    2            */
    0x4B80,    /* positive,   24            */
    0x7F00,    /* positive,  127            */
    0x7F80,    /* positive, infinity or NaN */
    0x8000,    /* negative, subnormal       */
    0x8080,    /* negative, -126            */
    0xB380,    /* negative,  -24            */
    0xBE80,    /* negative,   -2            */
    0xBF00,    /* negative,   -1            */
    0xBF80,    /* negative,    0            */
    0xC000,    /* negative,    1            */
    0xC080,    /* negative,    2            */
    0xCB80,    /* negative,   24            */
    0xFE80,    /* negative,  126            */
    0xFF80     /* negative, infinity or NaN */
};
static const uint16_t bf16QOut[bf16NumQOut] = {
    0x0000,    /* positive, subnormal       */
    0x0080,    /* positive, -126            */
    0x0100,    /* positive, -125            */
    0x3380,    /* positive,  -24            */
    0x3D80,    /* positive,   -4            */
    0x3E00,    /* positive,   -3            */
    0x3E80,    /* positive,   -2            */
    0x3F00,    /* positive,   -1            */
    0x3F80,    /* positive,    0            */
    0x4000,    /* positive,    1            */
    0x4080,    /* positive,    2            */
    0x4100,    /* positive,    3            */
    0x4180,    /* positive,    4            */
    0x4B80,    /* positive,   24            */
    0x4E00,    /* positive,   29            */
    0x4E80,    /* positive,   30            */
    0x4F00,    /* positive,   31            */
    0x4F80,    /* positive,   32            */
    0x5E00,    /* positive,   61            */
    0x5E80,    /* positive,   62            */
    0x5F00,    /* positive,   63            */
    0x5F80,    /* positive,   64            */
    0x7E80,    /* positive,  126            */
    0x7F00,    /* positive,  127            */
    0x7F80,    /* positive, infinity or NaN */
    0x8000,    /* negative, subnormal       */
    0x8080,    /* negative, -126            */
    0x8100,    /* negative, -125            */
    0xB380,    /* negative,  -24            */
    0xBD80,    /* negative,   -4            */
    0xBE00,    /* negative,   -3            */
    0xBE80,    /* negative,   -2            */
    0xBF00,    /* negative,   -1            */
    0xBF80,    /* negative,    0            */
    0xC000,    /* negative,    1            */
    0xC080,    /* negative,    2            */
    0xC100,    /* negative,    3            */
    0xC180,    /* negative,    4            */
    0xCB80,    /* negative,   24            */
    0xCE00,    /* negative,   29            */
    0xCE80,    /* negative,   30            */
    0xCF00,    /* negative,   31            */
    0xCF80,    /* negative,   32            */
    0xDE00,    /* negative,   61            */
    0xDE80,    /* negative,   62            */
    0xDF00,    /* negative,   63            */
    0xDF80,    /* negative,   64            */
    0xFE80,    /* negative,  126            */
    0xFF00,    /* negative,  127            */
    0xFF80     /* negative, infinity or NaN */
};
static const uint16_t bf16P1[bf16NumP1] = {
    0x0000,
    0x0001,
    0x007F,
    0x007E
};
static const uint16_t bf16P2[bf16NumP2] = {
    0x0000,
    0x0001,
    0x0002,
    0x0004,
    0x0008,
    0x0010,
    0x0020,
    0x0040,
    0x0060,
    0x0070,
    0x0078,
    0x007C,
    0x007E,
    0x007F,
    0x007E,
    0x007D,
    0x007B,
    0x0077,
    0x006F,
    0x005F,
    0x003F,
    0x001F,
    0x000F,
    0x0007,
    0x0003,
};

static const uint_fast64_t bf16NumQInP1 = bf16NumQIn * bf16NumP1;
static const uint_fast64_t bf16NumQOutP1 = bf16NumQOut * bf16NumP1;

static bfloat16_t bf16NextQInP1( struct sequence *sequencePtr )
{
    int expNum, sigNum;
    union ui16_bf16 uZ;

    expNum = sequencePtr->expNum;
    sigNum = sequencePtr->term1Num;
    uZ.ui = bf16QIn[expNum] | bf16P1[sigNum];
    ++sigNum;
    if ( bf16NumP1 <= sigNum ) {
        sigNum = 0;
        ++expNum;
        if ( bf16NumQIn <= expNum ) {
            expNum = 0;
            sequencePtr->done = true;
        }
        sequencePtr->expNum = expNum;
    }
    sequencePtr->term1Num = sigNum;
    return uZ.f;

}

static bfloat16_t bf16NextQOutP1( struct sequence *sequencePtr )
{
    int expNum, sigNum;
    union ui16_bf16 uZ;

    expNum = sequencePtr->expNum;
    sigNum = sequencePtr->term1Num;
    uZ.ui = bf16QOut[expNum] | bf16P1[sigNum];
    ++sigNum;
    if ( bf16NumP1 <= sigNum ) {
        sigNum = 0;
        ++expNum;
        if ( bf16NumQOut <= expNum ) {
            expNum = 0;
            sequencePtr->done = true;
        }
        sequencePtr->expNum = expNum;
    }
    sequencePtr->term1Num = sigNum;
    return uZ.f;

}

static const uint_fast64_t bf16NumQInP2 = bf16NumQIn * bf16NumP2;
static const uint_fast64_t bf16NumQOutP2 = bf16NumQOut * bf16NumP2;

static bfloat16_t bf16NextQInP2( struct sequence *sequencePtr )
{
    int expNum, sigNum;
    union ui16_bf16 uZ;

    expNum = sequencePtr->expNum;
    sigNum = sequencePtr->term1Num;
    uZ.ui = bf16QIn[expNum] | bf16P2[sigNum];
    ++sigNum;
    if ( bf16NumP2 <= sigNum ) {
        sigNum = 0;
        ++expNum;
        if ( bf16NumQIn <= expNum ) {
            expNum = 0;
            sequencePtr->done = true;
        }
        sequencePtr->expNum = expNum;
    }
    sequencePtr->term1Num = sigNum;
    return uZ.f;

}

static bfloat16_t bf16NextQOutP2( struct sequence *sequencePtr )
{
    int expNum, sigNum;
    union ui16_bf16 uZ;

    expNum = sequencePtr->expNum;
    sigNum = sequencePtr->term1Num;
    uZ.ui = bf16QOut[expNum] | bf16P2[sigNum];
    ++sigNum;
    if ( bf16NumP2 <= sigNum ) {
        sigNum = 0;
        ++expNum;
        if ( bf16NumQOut <= expNum ) {
            expNum = 0;
            sequencePtr->done = true;
        }
        sequencePtr->expNum = expNum;
    }
    sequencePtr->term1Num = sigNum;
    return uZ.f;

}

static bfloat16_t bf16RandomQOutP3( void )
{
    union ui16_bf16 uZ;

    uZ.ui =
          bf16QOut[randomN_ui8( bf16NumQOut )]
        | ((bf16P2[randomN_ui8( bf16NumP2 )] + bf16P2[randomN_ui8( bf16NumP2 )])
               & 0x007F);
    return uZ.f;

}

static bfloat16_t bf16RandomQOutPInf( void )
{
    union ui16_bf16 uZ;

    uZ.ui = bf16QOut[randomN_ui8( bf16NumQOut )] | (random_ui16() & 0x007F);
    return uZ.f;

}

enum { bf16NumQInfWeightMasks = 7 };
static const uint16_t bf16QInfWeightMasks[bf16NumQInfWeightMasks] = {
    0xFF80,
    0xFF80,
    0xBF80,
    0x9F80,
    0x8F80,
    0x8780,
    0x8380
};
static const uint16_t bf16QInfWeightOffsets[bf16NumQInfWeightMasks] = {
    0x0000,
    0x0000,
    0x2000,
    0x3000,
    0x3800,
    0x3C00,
    0x3E00
};

static bfloat16_t bf16RandomQInfP3( void )
{
    int weightMaskNum;
    union ui16_bf16 uZ;

    weightMaskNum = randomN_ui8( bf16NumQInfWeightMasks );
    // TODO: to be checked
    uZ.ui =
          (((uint_fast32_t) random_ui16()
                & bf16QInfWeightMasks[weightMaskNum])
               + bf16QInfWeightOffsets[weightMaskNum])
        | ((bf16P2[randomN_ui8( bf16NumP2 )] + bf16P2[randomN_ui8( bf16NumP2 )])
               & 0x007F);
    return uZ.f;

}

static bfloat16_t bf16RandomQInfPInf( void )
{
    int weightMaskNum;
    union ui16_bf16 uZ;

    weightMaskNum = randomN_ui8( bf16NumQInfWeightMasks );
    uZ.ui =
        (random_ui16() & (bf16QInfWeightMasks[weightMaskNum] | 0x007F))
            + bf16QInfWeightOffsets[weightMaskNum];
    return uZ.f;

}

static bfloat16_t bf16Random( void )
{

    switch ( random_ui8() & 7 ) {
     case 0:
     case 1:
     case 2:
        return bf16RandomQOutP3();
     case 3:
        return bf16RandomQOutPInf();
     case 4:
     case 5:
     case 6:
        return bf16RandomQInfP3();
     case 7:
        return bf16RandomQInfPInf();
     default:
        abort();
    }

}

static struct sequence sequenceA, sequenceB, sequenceC;
static bfloat16_t currentA, currentB, currentC;
static int subcase;

bfloat16_t genCases_bf16_a, genCases_bf16_b, genCases_bf16_c;

void genCases_bf16_a_init( void )
{

    sequenceA.expNum = 0;
    sequenceA.term1Num = 0;
    sequenceA.term2Num = 0;
    sequenceA.done = false;
    subcase = 0;
    genCases_total =
        (genCases_level == 1) ? 3 * bf16NumQOutP1 : 2 * bf16NumQOutP2;
    genCases_done = false;

}

void genCases_bf16_a_next( void )
{

    if ( genCases_level == 1 ) {
        switch ( subcase ) {
         case 0:
         case 1:
            genCases_bf16_a = bf16Random();
            break;
         case 2:
            genCases_bf16_a = bf16NextQOutP1( &sequenceA );
            genCases_done = sequenceA.done;
            subcase = -1;
            break;
        }
    } else {
        switch ( subcase ) {
         case 0:
            genCases_bf16_a = bf16Random();
            break;
         case 1:
            genCases_bf16_a = bf16NextQOutP2( &sequenceA );
            genCases_done = sequenceA.done;
            subcase = -1;
            break;
        }
    }
    ++subcase;

}

void genCases_bf16_ab_init( void )
{

    sequenceA.expNum = 0;
    sequenceA.term1Num = 0;
    sequenceA.term2Num = 0;
    sequenceA.done = false;
    sequenceB.expNum = 0;
    sequenceB.term1Num = 0;
    sequenceB.term2Num = 0;
    sequenceB.done = false;
    subcase = 0;
    if ( genCases_level == 1 ) {
        genCases_total = 6 * bf16NumQInP1 * bf16NumQInP1;
        currentA = bf16NextQInP1( &sequenceA );
    } else {
        genCases_total = 2 * bf16NumQInP2 * bf16NumQInP2;
        currentA = bf16NextQInP2( &sequenceA );
    }
    genCases_done = false;

}

void genCases_bf16_ab_next( void )
{

    if ( genCases_level == 1 ) {
        switch ( subcase ) {
         case 0:
            if ( sequenceB.done ) {
                sequenceB.done = false;
                currentA = bf16NextQInP1( &sequenceA );
            }
            currentB = bf16NextQInP1( &sequenceB );
         case 2:
         case 4:
            genCases_bf16_a = bf16Random();
            genCases_bf16_b = bf16Random();
            break;
         case 1:
            genCases_bf16_a = currentA;
            genCases_bf16_b = bf16Random();
            break;
         case 3:
            genCases_bf16_a = bf16Random();
            genCases_bf16_b = currentB;
            break;
         case 5:
            genCases_bf16_a = currentA;
            genCases_bf16_b = currentB;
            genCases_done = sequenceA.done & sequenceB.done;
            subcase = -1;
            break;
        }
    } else {
        switch ( subcase ) {
         case 0:
            genCases_bf16_a = bf16Random();
            genCases_bf16_b = bf16Random();
            break;
         case 1:
            if ( sequenceB.done ) {
                sequenceB.done = false;
                currentA = bf16NextQInP2( &sequenceA );
            }
            genCases_bf16_a = currentA;
            genCases_bf16_b = bf16NextQInP2( &sequenceB );
            genCases_done = sequenceA.done & sequenceB.done;
            subcase = -1;
            break;
        }
    }
    ++subcase;

}

void genCases_bf16_abc_init( void )
{

    sequenceA.expNum = 0;
    sequenceA.term1Num = 0;
    sequenceA.term2Num = 0;
    sequenceA.done = false;
    sequenceB.expNum = 0;
    sequenceB.term1Num = 0;
    sequenceB.term2Num = 0;
    sequenceB.done = false;
    sequenceC.expNum = 0;
    sequenceC.term1Num = 0;
    sequenceC.term2Num = 0;
    sequenceC.done = false;
    subcase = 0;
    if ( genCases_level == 1 ) {
        genCases_total = 9 * bf16NumQInP1 * bf16NumQInP1 * bf16NumQInP1;
        currentA = bf16NextQInP1( &sequenceA );
        currentB = bf16NextQInP1( &sequenceB );
    } else {
        genCases_total = 2 * bf16NumQInP2 * bf16NumQInP2 * bf16NumQInP2;
        currentA = bf16NextQInP2( &sequenceA );
        currentB = bf16NextQInP2( &sequenceB );
    }
    genCases_done = false;

}

void genCases_bf16_abc_next( void )
{

    if ( genCases_level == 1 ) {
        switch ( subcase ) {
         case 0:
            if ( sequenceC.done ) {
                sequenceC.done = false;
                if ( sequenceB.done ) {
                    sequenceB.done = false;
                    currentA = bf16NextQInP1( &sequenceA );
                }
                currentB = bf16NextQInP1( &sequenceB );
            }
            currentC = bf16NextQInP1( &sequenceC );
            genCases_bf16_a = bf16Random();
            genCases_bf16_b = bf16Random();
            genCases_bf16_c = currentC;
            break;
         case 1:
            genCases_bf16_a = currentA;
            genCases_bf16_b = currentB;
            genCases_bf16_c = bf16Random();
            break;
         case 2:
            genCases_bf16_a = bf16Random();
            genCases_bf16_b = bf16Random();
            genCases_bf16_c = bf16Random();
            break;
         case 3:
            genCases_bf16_a = bf16Random();
            genCases_bf16_b = currentB;
            genCases_bf16_c = currentC;
            break;
         case 4:
            genCases_bf16_a = currentA;
            genCases_bf16_b = bf16Random();
            genCases_bf16_c = bf16Random();
            break;
         case 5:
            genCases_bf16_a = bf16Random();
            genCases_bf16_b = currentB;
            genCases_bf16_c = bf16Random();
            break;
         case 6:
            genCases_bf16_a = currentA;
            genCases_bf16_b = bf16Random();
            genCases_bf16_c = currentC;
            break;
         case 7:
            genCases_bf16_a = bf16Random();
            genCases_bf16_b = bf16Random();
            genCases_bf16_c = bf16Random();
            break;
         case 8:
            genCases_bf16_a = currentA;
            genCases_bf16_b = currentB;
            genCases_bf16_c = currentC;
            genCases_done = sequenceA.done & sequenceB.done & sequenceC.done;
            subcase = -1;
            break;
        }
    } else {
        switch ( subcase ) {
         case 0:
            genCases_bf16_a = bf16Random();
            genCases_bf16_b = bf16Random();
            genCases_bf16_c = bf16Random();
            break;
         case 1:
            if ( sequenceC.done ) {
                sequenceC.done = false;
                if ( sequenceB.done ) {
                    sequenceB.done = false;
                    currentA = bf16NextQInP2( &sequenceA );
                }
                currentB = bf16NextQInP2( &sequenceB );
            }
            genCases_bf16_a = currentA;
            genCases_bf16_b = currentB;
            genCases_bf16_c = bf16NextQInP2( &sequenceC );
            genCases_done = sequenceA.done & sequenceB.done & sequenceC.done;
            subcase = -1;
            break;
        }
    }
    ++subcase;

}

#endif
