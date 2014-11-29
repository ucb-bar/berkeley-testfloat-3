
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

extern uint_fast8_t slowfloat_roundingMode;
extern uint_fast8_t slowfloat_detectTininess;
extern uint_fast8_t slowfloat_exceptionFlags;
#ifdef EXTFLOAT80
extern uint_fast8_t slow_extF80_roundingPrecision;
#endif

float32_t slow_ui32_to_f32( uint32_t );
float64_t slow_ui32_to_f64( uint32_t );
#ifdef EXTFLOAT80
void slow_ui32_to_extF80M( uint32_t, extFloat80_t * );
#endif
#ifdef FLOAT128
void slow_ui32_to_f128M( uint32_t, float128_t * );
#endif
float32_t slow_ui64_to_f32( uint64_t );
float64_t slow_ui64_to_f64( uint64_t );
#ifdef EXTFLOAT80
void slow_ui64_to_extF80M( uint64_t, extFloat80_t * );
#endif
#ifdef FLOAT128
void slow_ui64_to_f128M( uint64_t, float128_t * );
#endif
float32_t slow_i32_to_f32( int32_t );
float64_t slow_i32_to_f64( int32_t );
#ifdef EXTFLOAT80
void slow_i32_to_extF80M( int32_t, extFloat80_t * );
#endif
#ifdef FLOAT128
void slow_i32_to_f128M( int32_t, float128_t * );
#endif
float32_t slow_i64_to_f32( int64_t );
float64_t slow_i64_to_f64( int64_t );
#ifdef EXTFLOAT80
void slow_i64_to_extF80M( int64_t, extFloat80_t * );
#endif
#ifdef FLOAT128
void slow_i64_to_f128M( int64_t, float128_t * );
#endif

uint_fast32_t slow_f32_to_ui32( float32_t, uint_fast8_t, bool );
uint_fast64_t slow_f32_to_ui64( float32_t, uint_fast8_t, bool );
int_fast32_t slow_f32_to_i32( float32_t, uint_fast8_t, bool );
int_fast64_t slow_f32_to_i64( float32_t, uint_fast8_t, bool );
uint_fast32_t slow_f32_to_ui32_r_minMag( float32_t, bool );
uint_fast64_t slow_f32_to_ui64_r_minMag( float32_t, bool );
int_fast32_t slow_f32_to_i32_r_minMag( float32_t, bool );
int_fast64_t slow_f32_to_i64_r_minMag( float32_t, bool );
float64_t slow_f32_to_f64( float32_t );
#ifdef EXTFLOAT80
void slow_f32_to_extF80M( float32_t, extFloat80_t * );
#endif
#ifdef FLOAT128
void slow_f32_to_f128M( float32_t, float128_t * );
#endif
float32_t slow_f32_roundToInt( float32_t, uint_fast8_t, bool );
float32_t slow_f32_add( float32_t, float32_t );
float32_t slow_f32_sub( float32_t, float32_t );
float32_t slow_f32_mul( float32_t, float32_t );
float32_t slow_f32_mulAdd( float32_t, float32_t, float32_t );
float32_t slow_f32_div( float32_t, float32_t );
float32_t slow_f32_rem( float32_t, float32_t );
float32_t slow_f32_sqrt( float32_t );
bool slow_f32_eq( float32_t, float32_t );
bool slow_f32_le( float32_t, float32_t );
bool slow_f32_lt( float32_t, float32_t );
bool slow_f32_eq_signaling( float32_t, float32_t );
bool slow_f32_le_quiet( float32_t, float32_t );
bool slow_f32_lt_quiet( float32_t, float32_t );

uint_fast32_t slow_f64_to_ui32( float64_t, uint_fast8_t, bool );
uint_fast64_t slow_f64_to_ui64( float64_t, uint_fast8_t, bool );
int_fast32_t slow_f64_to_i32( float64_t, uint_fast8_t, bool );
int_fast64_t slow_f64_to_i64( float64_t, uint_fast8_t, bool );
uint_fast32_t slow_f64_to_ui32_r_minMag( float64_t, bool );
uint_fast64_t slow_f64_to_ui64_r_minMag( float64_t, bool );
int_fast32_t slow_f64_to_i32_r_minMag( float64_t, bool );
int_fast64_t slow_f64_to_i64_r_minMag( float64_t, bool );
float32_t slow_f64_to_f32( float64_t );
#ifdef EXTFLOAT80
void slow_f64_to_extF80M( float64_t, extFloat80_t * );
#endif
#ifdef FLOAT128
void slow_f64_to_f128M( float64_t, float128_t * );
#endif
float64_t slow_f64_roundToInt( float64_t, uint_fast8_t, bool );
float64_t slow_f64_add( float64_t, float64_t );
float64_t slow_f64_sub( float64_t, float64_t );
float64_t slow_f64_mul( float64_t, float64_t );
float64_t slow_f64_mulAdd( float64_t, float64_t, float64_t );
float64_t slow_f64_div( float64_t, float64_t );
float64_t slow_f64_rem( float64_t, float64_t );
float64_t slow_f64_sqrt( float64_t );
bool slow_f64_eq( float64_t, float64_t );
bool slow_f64_le( float64_t, float64_t );
bool slow_f64_lt( float64_t, float64_t );
bool slow_f64_eq_signaling( float64_t, float64_t );
bool slow_f64_le_quiet( float64_t, float64_t );
bool slow_f64_lt_quiet( float64_t, float64_t );

#ifdef EXTFLOAT80
uint_fast32_t slow_extF80M_to_ui32( const extFloat80_t *, uint_fast8_t, bool );
uint_fast64_t slow_extF80M_to_ui64( const extFloat80_t *, uint_fast8_t, bool );
int_fast32_t slow_extF80M_to_i32( const extFloat80_t *, uint_fast8_t, bool );
int_fast64_t slow_extF80M_to_i64( const extFloat80_t *, uint_fast8_t, bool );
uint_fast32_t slow_extF80M_to_ui32_r_minMag( const extFloat80_t *, bool );
uint_fast64_t slow_extF80M_to_ui64_r_minMag( const extFloat80_t *, bool );
int_fast32_t slow_extF80M_to_i32_r_minMag( const extFloat80_t *, bool );
int_fast64_t slow_extF80M_to_i64_r_minMag( const extFloat80_t *, bool );
float32_t slow_extF80M_to_f32( const extFloat80_t * );
float64_t slow_extF80M_to_f64( const extFloat80_t * );
#ifdef FLOAT128
void slow_extF80M_to_f128M( const extFloat80_t *, float128_t * );
#endif
void
 slow_extF80M_roundToInt(
     const extFloat80_t *, uint_fast8_t, bool, extFloat80_t * );
void
 slow_extF80M_add(
     const extFloat80_t *, const extFloat80_t *, extFloat80_t * );
void
 slow_extF80M_sub(
     const extFloat80_t *, const extFloat80_t *, extFloat80_t * );
void
 slow_extF80M_mul(
     const extFloat80_t *, const extFloat80_t *, extFloat80_t * );
void
 slow_extF80M_mulAdd(
     const extFloat80_t *,
     const extFloat80_t *,
     const extFloat80_t *,
     extFloat80_t *
 );
void
 slow_extF80M_div(
     const extFloat80_t *, const extFloat80_t *, extFloat80_t * );
void
 slow_extF80M_rem(
     const extFloat80_t *, const extFloat80_t *, extFloat80_t * );
void slow_extF80M_sqrt( const extFloat80_t *, extFloat80_t * );
bool slow_extF80M_eq( const extFloat80_t *, const extFloat80_t * );
bool slow_extF80M_le( const extFloat80_t *, const extFloat80_t * );
bool slow_extF80M_lt( const extFloat80_t *, const extFloat80_t * );
bool slow_extF80M_eq_signaling( const extFloat80_t *, const extFloat80_t * );
bool slow_extF80M_le_quiet( const extFloat80_t *, const extFloat80_t * );
bool slow_extF80M_lt_quiet( const extFloat80_t *, const extFloat80_t * );
#endif

#ifdef FLOAT128
uint_fast32_t slow_f128M_to_ui32( const float128_t *, uint_fast8_t, bool );
uint_fast64_t slow_f128M_to_ui64( const float128_t *, uint_fast8_t, bool );
int_fast32_t slow_f128M_to_i32( const float128_t *, uint_fast8_t, bool );
int_fast64_t slow_f128M_to_i64( const float128_t *, uint_fast8_t, bool );
uint_fast32_t slow_f128M_to_ui32_r_minMag( const float128_t *, bool );
uint_fast64_t slow_f128M_to_ui64_r_minMag( const float128_t *, bool );
int_fast32_t slow_f128M_to_i32_r_minMag( const float128_t *, bool );
int_fast64_t slow_f128M_to_i64_r_minMag( const float128_t *, bool );
float32_t slow_f128M_to_f32( const float128_t * );
float64_t slow_f128M_to_f64( const float128_t * );
#ifdef EXTFLOAT80
void slow_f128M_to_extF80M( const float128_t *, extFloat80_t * );
#endif
void
 slow_f128M_roundToInt( const float128_t *, uint_fast8_t, bool, float128_t * );
void slow_f128M_add( const float128_t *, const float128_t *, float128_t * );
void slow_f128M_sub( const float128_t *, const float128_t *, float128_t * );
void slow_f128M_mul( const float128_t *, const float128_t *, float128_t * );
void
 slow_f128M_mulAdd(
     const float128_t *, const float128_t *, const float128_t *, float128_t *
 );
void slow_f128M_div( const float128_t *, const float128_t *, float128_t * );
void slow_f128M_rem( const float128_t *, const float128_t *, float128_t * );
void slow_f128M_sqrt( const float128_t *, float128_t * );
bool slow_f128M_eq( const float128_t *, const float128_t * );
bool slow_f128M_le( const float128_t *, const float128_t * );
bool slow_f128M_lt( const float128_t *, const float128_t * );
bool slow_f128M_eq_signaling( const float128_t *, const float128_t * );
bool slow_f128M_le_quiet( const float128_t *, const float128_t * );
bool slow_f128M_lt_quiet( const float128_t *, const float128_t * );
#endif

