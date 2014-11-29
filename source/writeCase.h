
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
#include "softfloat.h"

void writeCase_a_ui32( uint_fast32_t, const char * );
void writeCase_a_ui64( uint_fast64_t, const char * );
#define writeCase_a_i32 writeCase_a_ui32
#define writeCase_a_i64 writeCase_a_ui64
void writeCase_a_f32( float32_t, const char * );
void writeCase_ab_f32( float32_t, float32_t, const char * );
void writeCase_abc_f32( float32_t, float32_t, float32_t, const char * );
void writeCase_a_f64( float64_t, const char * );
void writeCase_ab_f64( float64_t, float64_t, const char * );
void writeCase_abc_f64( float64_t, float64_t, float64_t, const char * );
#ifdef EXTFLOAT80
void writeCase_a_extF80M( const extFloat80_t *, const char * );
void
 writeCase_ab_extF80M(
     const extFloat80_t *, const extFloat80_t *, const char * );
void
 writeCase_abc_extF80M(
     const extFloat80_t *,
     const extFloat80_t *,
     const extFloat80_t *,
     const char *
 );
#endif
#ifdef FLOAT128
void writeCase_a_f128M( const float128_t *, const char * );
void
 writeCase_ab_f128M( const float128_t *, const float128_t *, const char * );
void
 writeCase_abc_f128M(
     const float128_t *, const float128_t *, const float128_t *, const char *
 );
#endif

void writeCase_z_bool( bool, uint_fast8_t, bool, uint_fast8_t );
void
 writeCase_z_ui32( uint_fast32_t, uint_fast8_t, uint_fast32_t, uint_fast8_t );
void
 writeCase_z_ui64( uint_fast64_t, uint_fast8_t, uint_fast64_t, uint_fast8_t );
#define writeCase_z_i32 writeCase_z_ui32
#define writeCase_z_i64 writeCase_z_ui64
void writeCase_z_f32( float32_t, uint_fast8_t, float32_t, uint_fast8_t );
void writeCase_z_f64( float64_t, uint_fast8_t, float64_t, uint_fast8_t );
#ifdef EXTFLOAT80
void
 writeCase_z_extF80M(
     const extFloat80_t *, uint_fast8_t, const extFloat80_t *, uint_fast8_t );
#endif
#ifdef FLOAT128
void
 writeCase_z_f128M(
     const float128_t *, uint_fast8_t, const float128_t *, uint_fast8_t );
#endif

