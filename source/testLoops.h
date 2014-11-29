
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
#include "softfloat.h"

extern bool testLoops_forever;

extern uint_fast8_t *testLoops_trueFlagsPtr;
extern uint_fast8_t (*testLoops_subjFlagsFunction)( void );

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/
void test_a_ui32_z_f32( float32_t ( uint32_t ), float32_t ( uint32_t ) );
void test_a_ui32_z_f64( float64_t ( uint32_t ), float64_t ( uint32_t ) );
#ifdef EXTFLOAT80
void
 test_a_ui32_z_extF80(
     void ( uint32_t, extFloat80_t * ), void ( uint32_t, extFloat80_t * ) );
#endif
#ifdef FLOAT128
void
 test_a_ui32_z_f128(
     void ( uint32_t, float128_t * ), void ( uint32_t, float128_t * )
 );
#endif
void test_a_ui64_z_f32( float32_t ( uint64_t ), float32_t ( uint64_t ) );
void test_a_ui64_z_f64( float64_t ( uint64_t ), float64_t ( uint64_t ) );
#ifdef EXTFLOAT80
void
 test_a_ui64_z_extF80(
     void ( uint64_t, extFloat80_t * ), void ( uint64_t, extFloat80_t * ) );
#endif
#ifdef FLOAT128
void
 test_a_ui64_z_f128(
     void ( uint64_t, float128_t * ), void ( uint64_t, float128_t * ) );
#endif
void test_a_i32_z_f32( float32_t ( int32_t ), float32_t ( int32_t ) );
void test_a_i32_z_f64( float64_t ( int32_t ), float64_t ( int32_t ) );
#ifdef EXTFLOAT80
void
 test_a_i32_z_extF80(
     void ( int32_t, extFloat80_t * ), void ( int32_t, extFloat80_t * ) );
#endif
#ifdef FLOAT128
void
 test_a_i32_z_f128(
     void ( int32_t, float128_t * ), void ( int32_t, float128_t * ) );
#endif
void test_a_i64_z_f32( float32_t ( int64_t ), float32_t ( int64_t ) );
void test_a_i64_z_f64( float64_t ( int64_t ), float64_t ( int64_t ) );
#ifdef EXTFLOAT80
void
 test_a_i64_z_extF80(
     void ( int64_t, extFloat80_t * ), void ( int64_t, extFloat80_t * ) );
#endif
#ifdef FLOAT128
void
 test_a_i64_z_f128(
     void ( int64_t, float128_t * ), void ( int64_t, float128_t * ) );
#endif

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/
void
 test_a_f32_z_ui32_rx(
     uint_fast32_t ( float32_t, uint_fast8_t, bool ),
     uint_fast32_t ( float32_t, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f32_z_ui64_rx(
     uint_fast64_t ( float32_t, uint_fast8_t, bool ),
     uint_fast64_t ( float32_t, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f32_z_i32_rx(
     int_fast32_t ( float32_t, uint_fast8_t, bool ),
     int_fast32_t ( float32_t, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f32_z_i64_rx(
     int_fast64_t ( float32_t, uint_fast8_t, bool ),
     int_fast64_t ( float32_t, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f32_z_ui32_x(
     uint_fast32_t ( float32_t, bool ), uint_fast32_t ( float32_t, bool ), bool
 );
void
 test_a_f32_z_ui64_x(
     uint_fast64_t ( float32_t, bool ), uint_fast64_t ( float32_t, bool ), bool
 );
void
 test_a_f32_z_i32_x(
     int_fast32_t ( float32_t, bool ), int_fast32_t ( float32_t, bool ), bool
 );
void
 test_a_f32_z_i64_x(
     int_fast64_t ( float32_t, bool ), int_fast64_t ( float32_t, bool ), bool
 );
void test_a_f32_z_f64( float64_t ( float32_t ), float64_t ( float32_t ) );
#ifdef EXTFLOAT80
void
 test_a_f32_z_extF80(
     void ( float32_t, extFloat80_t * ), void ( float32_t, extFloat80_t * ) );
#endif
#ifdef FLOAT128
void
 test_a_f32_z_f128(
     void ( float32_t, float128_t * ), void ( float32_t, float128_t * ) );
#endif
void test_az_f32( float32_t ( float32_t ), float32_t ( float32_t ) );
void
 test_az_f32_rx(
     float32_t ( float32_t, uint_fast8_t, bool ),
     float32_t ( float32_t, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_abz_f32(
     float32_t ( float32_t, float32_t ), float32_t ( float32_t, float32_t ) );
void
 test_abcz_f32(
     float32_t ( float32_t, float32_t, float32_t ),
     float32_t ( float32_t, float32_t, float32_t )
 );
void
 test_ab_f32_z_bool(
     bool ( float32_t, float32_t ), bool ( float32_t, float32_t ) );

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/
void
 test_a_f64_z_ui32_rx(
     uint_fast32_t ( float64_t, uint_fast8_t, bool ),
     uint_fast32_t ( float64_t, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f64_z_ui64_rx(
     uint_fast64_t ( float64_t, uint_fast8_t, bool ),
     uint_fast64_t ( float64_t, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f64_z_i32_rx(
     int_fast32_t ( float64_t, uint_fast8_t, bool ),
     int_fast32_t ( float64_t, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f64_z_i64_rx(
     int_fast64_t ( float64_t, uint_fast8_t, bool ),
     int_fast64_t ( float64_t, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f64_z_ui32_x(
     uint_fast32_t ( float64_t, bool ), uint_fast32_t ( float64_t, bool ), bool
 );
void
 test_a_f64_z_ui64_x(
     uint_fast64_t ( float64_t, bool ), uint_fast64_t ( float64_t, bool ), bool
 );
void
 test_a_f64_z_i32_x(
     int_fast32_t ( float64_t, bool ), int_fast32_t ( float64_t, bool ), bool
 );
void
 test_a_f64_z_i64_x(
     int_fast64_t ( float64_t, bool ), int_fast64_t ( float64_t, bool ), bool
 );
void test_a_f64_z_f32( float32_t ( float64_t ), float32_t ( float64_t ) );
#ifdef EXTFLOAT80
void
 test_a_f64_z_extF80(
     void ( float64_t, extFloat80_t * ), void ( float64_t, extFloat80_t * ) );
#endif
#ifdef FLOAT128
void
 test_a_f64_z_f128(
     void ( float64_t, float128_t * ), void ( float64_t, float128_t * ) );
#endif
void test_az_f64( float64_t ( float64_t ), float64_t ( float64_t ) );
void
 test_az_f64_rx(
     float64_t ( float64_t, uint_fast8_t, bool ),
     float64_t ( float64_t, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_abz_f64(
     float64_t ( float64_t, float64_t ), float64_t ( float64_t, float64_t ) );
void
 test_abcz_f64(
     float64_t ( float64_t, float64_t, float64_t ),
     float64_t ( float64_t, float64_t, float64_t )
 );
void
 test_ab_f64_z_bool(
     bool ( float64_t, float64_t ), bool ( float64_t, float64_t ) );

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/
#ifdef EXTFLOAT80
void
 test_a_extF80_z_ui32_rx(
     uint_fast32_t ( const extFloat80_t *, uint_fast8_t, bool ),
     uint_fast32_t ( const extFloat80_t *, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_extF80_z_ui64_rx(
     uint_fast64_t ( const extFloat80_t *, uint_fast8_t, bool ),
     uint_fast64_t ( const extFloat80_t *, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_extF80_z_i32_rx(
     int_fast32_t ( const extFloat80_t *, uint_fast8_t, bool ),
     int_fast32_t ( const extFloat80_t *, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_extF80_z_i64_rx(
     int_fast64_t ( const extFloat80_t *, uint_fast8_t, bool ),
     int_fast64_t ( const extFloat80_t *, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_extF80_z_ui32_x(
     uint_fast32_t ( const extFloat80_t *, bool ),
     uint_fast32_t ( const extFloat80_t *, bool ),
     bool
 );
void
 test_a_extF80_z_ui64_x(
     uint_fast64_t ( const extFloat80_t *, bool ),
     uint_fast64_t ( const extFloat80_t *, bool ),
     bool
 );
void
 test_a_extF80_z_i32_x(
     int_fast32_t ( const extFloat80_t *, bool ),
     int_fast32_t ( const extFloat80_t *, bool ),
     bool
 );
void
 test_a_extF80_z_i64_x(
     int_fast64_t ( const extFloat80_t *, bool ),
     int_fast64_t ( const extFloat80_t *, bool ),
     bool
 );
void
 test_a_extF80_z_f32(
     float32_t ( const extFloat80_t * ), float32_t ( const extFloat80_t * ) );
void
 test_a_extF80_z_f64(
     float64_t ( const extFloat80_t * ), float64_t ( const extFloat80_t * ) );
#ifdef FLOAT128
void
 test_a_extF80_z_f128(
     void ( const extFloat80_t *, float128_t * ),
     void ( const extFloat80_t *, float128_t * )
 );
#endif
void
 test_az_extF80(
     void ( const extFloat80_t *, extFloat80_t * ),
     void ( const extFloat80_t *, extFloat80_t * )
 );
void
 test_az_extF80_rx(
     void ( const extFloat80_t *, uint_fast8_t, bool, extFloat80_t * ),
     void ( const extFloat80_t *, uint_fast8_t, bool, extFloat80_t * ),
     uint_fast8_t,
     bool
 );
void
 test_abz_extF80(
     void ( const extFloat80_t *, const extFloat80_t *, extFloat80_t * ),
     void ( const extFloat80_t *, const extFloat80_t *, extFloat80_t * )
 );
void
 test_abcz_extF80(
     void
      (
          const extFloat80_t,
          const extFloat80_t,
          const extFloat80_t,
          extFloat80_t *
      ),
     void
      (
          const extFloat80_t,
          const extFloat80_t,
          const extFloat80_t,
          extFloat80_t *
      )
 );
void
 test_ab_extF80_z_bool(
     bool ( const extFloat80_t *, const extFloat80_t * ),
     bool ( const extFloat80_t *, const extFloat80_t * )
 );
#endif

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/
#ifdef FLOAT128
void
 test_a_f128_z_ui32_rx(
     uint_fast32_t ( const float128_t *, uint_fast8_t, bool ),
     uint_fast32_t ( const float128_t *, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f128_z_ui64_rx(
     uint_fast64_t ( const float128_t *, uint_fast8_t, bool ),
     uint_fast64_t ( const float128_t *, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f128_z_i32_rx(
     int_fast32_t ( const float128_t *, uint_fast8_t, bool ),
     int_fast32_t ( const float128_t *, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f128_z_i64_rx(
     int_fast64_t ( const float128_t *, uint_fast8_t, bool ),
     int_fast64_t ( const float128_t *, uint_fast8_t, bool ),
     uint_fast8_t,
     bool
 );
void
 test_a_f128_z_ui32_x(
     uint_fast32_t ( const float128_t *, bool ),
     uint_fast32_t ( const float128_t *, bool ),
     bool
 );
void
 test_a_f128_z_ui64_x(
     uint_fast64_t ( const float128_t *, bool ),
     uint_fast64_t ( const float128_t *, bool ),
     bool
 );
void
 test_a_f128_z_i32_x(
     int_fast32_t ( const float128_t *, bool ),
     int_fast32_t ( const float128_t *, bool ),
     bool
 );
void
 test_a_f128_z_i64_x(
     int_fast64_t ( const float128_t *, bool ),
     int_fast64_t ( const float128_t *, bool ),
     bool
 );
void
 test_a_f128_z_f32(
     float32_t ( const float128_t * ), float32_t ( const float128_t * ) );
void
 test_a_f128_z_f64(
     float64_t ( const float128_t * ), float64_t ( const float128_t * ) );
#ifdef EXTFLOAT80
void
 test_a_f128_z_extF80(
     void ( const float128_t *, extFloat80_t * ),
     void ( const float128_t *, extFloat80_t * )
 );
#endif
void
 test_az_f128(
     void ( const float128_t *, float128_t * ),
     void ( const float128_t *, float128_t * )
 );
void
 test_az_f128_rx(
     void ( const float128_t *, uint_fast8_t, bool, float128_t * ),
     void ( const float128_t *, uint_fast8_t, bool, float128_t * ),
     uint_fast8_t,
     bool
 );
void
 test_abz_f128(
     void ( const float128_t *, const float128_t *, float128_t * ),
     void ( const float128_t *, const float128_t *, float128_t * )
 );
void
 test_abcz_f128(
     void
      ( const float128_t *,
        const float128_t *,
        const float128_t *,
        float128_t *
      ),
     void
      ( const float128_t *,
        const float128_t *,
        const float128_t *,
        float128_t *
      )
 );
void
 test_ab_f128_z_bool(
     bool ( const float128_t *, const float128_t * ),
     bool ( const float128_t *, const float128_t * )
 );
#endif

