
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
#include "platform.h"
#include "subjfloat_config.h"
#include "subjfloat.h"
#include "functions.h"

typedef void genericFuncType();

/*----------------------------------------------------------------------------
| WARNING:
| This file should not normally be modified.  See "subjfloat_config.h"
| instead.
|   The order of these array entries must match the order in the array
| `standardFunctionInfos'.  Be careful about making changes.
*----------------------------------------------------------------------------*/

genericFuncType *const subjfloat_functions[] = {
    /*------------------------------------------------------------------------
    *------------------------------------------------------------------------*/
#ifdef SUBJ_UI32_TO_F32
    (genericFuncType *) subj_ui32_to_f32,
#else
    0,
#endif
#ifdef SUBJ_UI32_TO_F64
    (genericFuncType *) subj_ui32_to_f64,
#else
    0,
#endif
#ifdef EXTFLOAT80
#ifdef SUBJ_UI32_TO_EXTF80
    (genericFuncType *) subj_ui32_to_extF80M,
#else
    0,
#endif
#endif
#ifdef FLOAT128
#ifdef SUBJ_UI32_TO_F128
    (genericFuncType *) subj_ui32_to_f128M,
#else
    0,
#endif
#endif
#ifdef SUBJ_UI64_TO_F32
    (genericFuncType *) subj_ui64_to_f32,
#else
    0,
#endif
#ifdef SUBJ_UI64_TO_F64
    (genericFuncType *) subj_ui64_to_f64,
#else
    0,
#endif
#ifdef EXTFLOAT80
#ifdef SUBJ_UI64_TO_EXTF80
    (genericFuncType *) subj_ui64_to_extF80M,
#else
    0,
#endif
#endif
#ifdef FLOAT128
#ifdef SUBJ_UI64_TO_F128
    (genericFuncType *) subj_ui64_to_f128M,
#else
    0,
#endif
#endif
#ifdef SUBJ_I32_TO_F32
    (genericFuncType *) subj_i32_to_f32,
#else
    0,
#endif
#ifdef SUBJ_I32_TO_F64
    (genericFuncType *) subj_i32_to_f64,
#else
    0,
#endif
#ifdef EXTFLOAT80
#ifdef SUBJ_I32_TO_EXTF80
    (genericFuncType *) subj_i32_to_extF80M,
#else
    0,
#endif
#endif
#ifdef FLOAT128
#ifdef SUBJ_I32_TO_F128
    (genericFuncType *) subj_i32_to_f128M,
#else
    0,
#endif
#endif
#ifdef SUBJ_I64_TO_F32
    (genericFuncType *) subj_i64_to_f32,
#else
    0,
#endif
#ifdef SUBJ_I64_TO_F64
    (genericFuncType *) subj_i64_to_f64,
#else
    0,
#endif
#ifdef EXTFLOAT80
#ifdef SUBJ_I64_TO_EXTF80
    (genericFuncType *) subj_i64_to_extF80M,
#else
    0,
#endif
#endif
#ifdef FLOAT128
#ifdef SUBJ_I64_TO_F128
    (genericFuncType *) subj_i64_to_f128M,
#else
    0,
#endif
#endif
    /*------------------------------------------------------------------------
    *------------------------------------------------------------------------*/
#ifdef SUBJ_F32_TO_UI32_R_NEAR_EVEN
    (genericFuncType *) subj_f32_to_ui32_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI32_R_MINMAG
    (genericFuncType *) subj_f32_to_ui32_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI32_R_MIN
    (genericFuncType *) subj_f32_to_ui32_r_min,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI32_R_MAX
    (genericFuncType *) subj_f32_to_ui32_r_max,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI32_R_NEAR_MAXMAG
    (genericFuncType *) subj_f32_to_ui32_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI64_R_NEAR_EVEN
    (genericFuncType *) subj_f32_to_ui64_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI64_R_MINMAG
    (genericFuncType *) subj_f32_to_ui64_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI64_R_MIN
    (genericFuncType *) subj_f32_to_ui64_r_min,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI64_R_MAX
    (genericFuncType *) subj_f32_to_ui64_r_max,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI64_R_NEAR_MAXMAG
    (genericFuncType *) subj_f32_to_ui64_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I32_R_NEAR_EVEN
    (genericFuncType *) subj_f32_to_i32_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I32_R_MINMAG
    (genericFuncType *) subj_f32_to_i32_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I32_R_MIN
    (genericFuncType *) subj_f32_to_i32_r_min,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I32_R_MAX
    (genericFuncType *) subj_f32_to_i32_r_max,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I32_R_NEAR_MAXMAG
    (genericFuncType *) subj_f32_to_i32_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I64_R_NEAR_EVEN
    (genericFuncType *) subj_f32_to_i64_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I64_R_MINMAG
    (genericFuncType *) subj_f32_to_i64_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I64_R_MIN
    (genericFuncType *) subj_f32_to_i64_r_min,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I64_R_MAX
    (genericFuncType *) subj_f32_to_i64_r_max,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I64_R_NEAR_MAXMAG
    (genericFuncType *) subj_f32_to_i64_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI32_RX_NEAR_EVEN
    (genericFuncType *) subj_f32_to_ui32_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI32_RX_MINMAG
    (genericFuncType *) subj_f32_to_ui32_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI32_RX_MIN
    (genericFuncType *) subj_f32_to_ui32_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI32_RX_MAX
    (genericFuncType *) subj_f32_to_ui32_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI32_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f32_to_ui32_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI64_RX_NEAR_EVEN
    (genericFuncType *) subj_f32_to_ui64_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI64_RX_MINMAG
    (genericFuncType *) subj_f32_to_ui64_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI64_RX_MIN
    (genericFuncType *) subj_f32_to_ui64_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI64_RX_MAX
    (genericFuncType *) subj_f32_to_ui64_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_UI64_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f32_to_ui64_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I32_RX_NEAR_EVEN
    (genericFuncType *) subj_f32_to_i32_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I32_RX_MINMAG
    (genericFuncType *) subj_f32_to_i32_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I32_RX_MIN
    (genericFuncType *) subj_f32_to_i32_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I32_RX_MAX
    (genericFuncType *) subj_f32_to_i32_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I32_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f32_to_i32_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I64_RX_NEAR_EVEN
    (genericFuncType *) subj_f32_to_i64_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I64_RX_MINMAG
    (genericFuncType *) subj_f32_to_i64_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I64_RX_MIN
    (genericFuncType *) subj_f32_to_i64_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I64_RX_MAX
    (genericFuncType *) subj_f32_to_i64_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_I64_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f32_to_i64_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F32_TO_F64
    (genericFuncType *) subj_f32_to_f64,
#else
    0,
#endif
#ifdef EXTFLOAT80
#ifdef SUBJ_F32_TO_EXTF80
    (genericFuncType *) subj_f32_to_extF80M,
#else
    0,
#endif
#endif
#ifdef FLOAT128
#ifdef SUBJ_F32_TO_F128
    (genericFuncType *) subj_f32_to_f128M,
#else
    0,
#endif
#endif
#ifdef SUBJ_F32_ROUNDTOINT_R_NEAR_EVEN
    (genericFuncType *) subj_f32_roundToInt_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F32_ROUNDTOINT_R_MINMAG
    (genericFuncType *) subj_f32_roundToInt_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F32_ROUNDTOINT_R_MIN
    (genericFuncType *) subj_f32_roundToInt_r_min,
#else
    0,
#endif
#ifdef SUBJ_F32_ROUNDTOINT_R_MAX
    (genericFuncType *) subj_f32_roundToInt_r_max,
#else
    0,
#endif
#ifdef SUBJ_F32_ROUNDTOINT_R_NEAR_MAXMAG
    (genericFuncType *) subj_f32_roundToInt_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F32_ROUNDTOINT_X
    (genericFuncType *) subj_f32_roundToInt_x,
#else
    0,
#endif
#ifdef SUBJ_F32_ADD
    (genericFuncType *) subj_f32_add,
#else
    0,
#endif
#ifdef SUBJ_F32_SUB
    (genericFuncType *) subj_f32_sub,
#else
    0,
#endif
#ifdef SUBJ_F32_MUL
    (genericFuncType *) subj_f32_mul,
#else
    0,
#endif
#ifdef SUBJ_F32_MULADD
    (genericFuncType *) subj_f32_mulAdd,
#else
    0,
#endif
#ifdef SUBJ_F32_DIV
    (genericFuncType *) subj_f32_div,
#else
    0,
#endif
#ifdef SUBJ_F32_REM
    (genericFuncType *) subj_f32_rem,
#else
    0,
#endif
#ifdef SUBJ_F32_SQRT
    (genericFuncType *) subj_f32_sqrt,
#else
    0,
#endif
#ifdef SUBJ_F32_EQ
    (genericFuncType *) subj_f32_eq,
#else
    0,
#endif
#ifdef SUBJ_F32_LE
    (genericFuncType *) subj_f32_le,
#else
    0,
#endif
#ifdef SUBJ_F32_LT
    (genericFuncType *) subj_f32_lt,
#else
    0,
#endif
#ifdef SUBJ_F32_EQ_SIGNALING
    (genericFuncType *) subj_f32_eq_signaling,
#else
    0,
#endif
#ifdef SUBJ_F32_LE_QUIET
    (genericFuncType *) subj_f32_le_quiet,
#else
    0,
#endif
#ifdef SUBJ_F32_LT_QUIET
    (genericFuncType *) subj_f32_lt_quiet,
#else
    0,
#endif
    /*------------------------------------------------------------------------
    *------------------------------------------------------------------------*/
#ifdef SUBJ_F64_TO_UI32_R_NEAR_EVEN
    (genericFuncType *) subj_f64_to_ui32_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI32_R_MINMAG
    (genericFuncType *) subj_f64_to_ui32_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI32_R_MIN
    (genericFuncType *) subj_f64_to_ui32_r_min,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI32_R_MAX
    (genericFuncType *) subj_f64_to_ui32_r_max,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI32_R_NEAR_MAXMAG
    (genericFuncType *) subj_f64_to_ui32_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI64_R_NEAR_EVEN
    (genericFuncType *) subj_f64_to_ui64_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI64_R_MINMAG
    (genericFuncType *) subj_f64_to_ui64_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI64_R_MIN
    (genericFuncType *) subj_f64_to_ui64_r_min,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI64_R_MAX
    (genericFuncType *) subj_f64_to_ui64_r_max,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI64_R_NEAR_MAXMAG
    (genericFuncType *) subj_f64_to_ui64_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I32_R_NEAR_EVEN
    (genericFuncType *) subj_f64_to_i32_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I32_R_MINMAG
    (genericFuncType *) subj_f64_to_i32_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I32_R_MIN
    (genericFuncType *) subj_f64_to_i32_r_min,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I32_R_MAX
    (genericFuncType *) subj_f64_to_i32_r_max,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I32_R_NEAR_MAXMAG
    (genericFuncType *) subj_f64_to_i32_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I64_R_NEAR_EVEN
    (genericFuncType *) subj_f64_to_i64_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I64_R_MINMAG
    (genericFuncType *) subj_f64_to_i64_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I64_R_MIN
    (genericFuncType *) subj_f64_to_i64_r_min,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I64_R_MAX
    (genericFuncType *) subj_f64_to_i64_r_max,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I64_R_NEAR_MAXMAG
    (genericFuncType *) subj_f64_to_i64_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI32_RX_NEAR_EVEN
    (genericFuncType *) subj_f64_to_ui32_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI32_RX_MINMAG
    (genericFuncType *) subj_f64_to_ui32_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI32_RX_MIN
    (genericFuncType *) subj_f64_to_ui32_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI32_RX_MAX
    (genericFuncType *) subj_f64_to_ui32_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI32_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f64_to_ui32_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI64_RX_NEAR_EVEN
    (genericFuncType *) subj_f64_to_ui64_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI64_RX_MINMAG
    (genericFuncType *) subj_f64_to_ui64_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI64_RX_MIN
    (genericFuncType *) subj_f64_to_ui64_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI64_RX_MAX
    (genericFuncType *) subj_f64_to_ui64_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_UI64_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f64_to_ui64_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I32_RX_NEAR_EVEN
    (genericFuncType *) subj_f64_to_i32_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I32_RX_MINMAG
    (genericFuncType *) subj_f64_to_i32_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I32_RX_MIN
    (genericFuncType *) subj_f64_to_i32_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I32_RX_MAX
    (genericFuncType *) subj_f64_to_i32_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I32_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f64_to_i32_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I64_RX_NEAR_EVEN
    (genericFuncType *) subj_f64_to_i64_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I64_RX_MINMAG
    (genericFuncType *) subj_f64_to_i64_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I64_RX_MIN
    (genericFuncType *) subj_f64_to_i64_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I64_RX_MAX
    (genericFuncType *) subj_f64_to_i64_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_I64_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f64_to_i64_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F64_TO_F32
    (genericFuncType *) subj_f64_to_f32,
#else
    0,
#endif
#ifdef EXTFLOAT80
#ifdef SUBJ_F64_TO_EXTF80
    (genericFuncType *) subj_f64_to_extF80M,
#else
    0,
#endif
#endif
#ifdef FLOAT128
#ifdef SUBJ_F64_TO_F128
    (genericFuncType *) subj_f64_to_f128M,
#else
    0,
#endif
#endif
#ifdef SUBJ_F64_ROUNDTOINT_R_NEAR_EVEN
    (genericFuncType *) subj_f64_roundToInt_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F64_ROUNDTOINT_R_MINMAG
    (genericFuncType *) subj_f64_roundToInt_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F64_ROUNDTOINT_R_MIN
    (genericFuncType *) subj_f64_roundToInt_r_min,
#else
    0,
#endif
#ifdef SUBJ_F64_ROUNDTOINT_R_MAX
    (genericFuncType *) subj_f64_roundToInt_r_max,
#else
    0,
#endif
#ifdef SUBJ_F64_ROUNDTOINT_R_NEAR_MAXMAG
    (genericFuncType *) subj_f64_roundToInt_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F64_ROUNDTOINT_X
    (genericFuncType *) subj_f64_roundToInt_x,
#else
    0,
#endif
#ifdef SUBJ_F64_ADD
    (genericFuncType *) subj_f64_add,
#else
    0,
#endif
#ifdef SUBJ_F64_SUB
    (genericFuncType *) subj_f64_sub,
#else
    0,
#endif
#ifdef SUBJ_F64_MUL
    (genericFuncType *) subj_f64_mul,
#else
    0,
#endif
#ifdef SUBJ_F64_MULADD
    (genericFuncType *) subj_f64_mulAdd,
#else
    0,
#endif
#ifdef SUBJ_F64_DIV
    (genericFuncType *) subj_f64_div,
#else
    0,
#endif
#ifdef SUBJ_F64_REM
    (genericFuncType *) subj_f64_rem,
#else
    0,
#endif
#ifdef SUBJ_F64_SQRT
    (genericFuncType *) subj_f64_sqrt,
#else
    0,
#endif
#ifdef SUBJ_F64_EQ
    (genericFuncType *) subj_f64_eq,
#else
    0,
#endif
#ifdef SUBJ_F64_LE
    (genericFuncType *) subj_f64_le,
#else
    0,
#endif
#ifdef SUBJ_F64_LT
    (genericFuncType *) subj_f64_lt,
#else
    0,
#endif
#ifdef SUBJ_F64_EQ_SIGNALING
    (genericFuncType *) subj_f64_eq_signaling,
#else
    0,
#endif
#ifdef SUBJ_F64_LE_QUIET
    (genericFuncType *) subj_f64_le_quiet,
#else
    0,
#endif
#ifdef SUBJ_F64_LT_QUIET
    (genericFuncType *) subj_f64_lt_quiet,
#else
    0,
#endif
    /*------------------------------------------------------------------------
    *------------------------------------------------------------------------*/
#ifdef EXTFLOAT80
#ifdef SUBJ_EXTF80_TO_UI32_R_NEAR_EVEN
    (genericFuncType *) subj_extF80M_to_ui32_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI32_R_MINMAG
    (genericFuncType *) subj_extF80M_to_ui32_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI32_R_MIN
    (genericFuncType *) subj_extF80M_to_ui32_r_min,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI32_R_MAX
    (genericFuncType *) subj_extF80M_to_ui32_r_max,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI32_R_NEAR_MAXMAG
    (genericFuncType *) subj_extF80M_to_ui32_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI64_R_NEAR_EVEN
    (genericFuncType *) subj_extF80M_to_ui64_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI64_R_MINMAG
    (genericFuncType *) subj_extF80M_to_ui64_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI64_R_MIN
    (genericFuncType *) subj_extF80M_to_ui64_r_min,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI64_R_MAX
    (genericFuncType *) subj_extF80M_to_ui64_r_max,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI64_R_NEAR_MAXMAG
    (genericFuncType *) subj_extF80M_to_ui64_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I32_R_NEAR_EVEN
    (genericFuncType *) subj_extF80M_to_i32_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I32_R_MINMAG
    (genericFuncType *) subj_extF80M_to_i32_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I32_R_MIN
    (genericFuncType *) subj_extF80M_to_i32_r_min,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I32_R_MAX
    (genericFuncType *) subj_extF80M_to_i32_r_max,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I32_R_NEAR_MAXMAG
    (genericFuncType *) subj_extF80M_to_i32_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I64_R_NEAR_EVEN
    (genericFuncType *) subj_extF80M_to_i64_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I64_R_MINMAG
    (genericFuncType *) subj_extF80M_to_i64_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I64_R_MIN
    (genericFuncType *) subj_extF80M_to_i64_r_min,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I64_R_MAX
    (genericFuncType *) subj_extF80M_to_i64_r_max,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I64_R_NEAR_MAXMAG
    (genericFuncType *) subj_extF80M_to_i64_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI32_RX_NEAR_EVEN
    (genericFuncType *) subj_extF80M_to_ui32_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI32_RX_MINMAG
    (genericFuncType *) subj_extF80M_to_ui32_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI32_RX_MIN
    (genericFuncType *) subj_extF80M_to_ui32_rx_min,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI32_RX_MAX
    (genericFuncType *) subj_extF80M_to_ui32_rx_max,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI32_RX_NEAR_MAXMAG
    (genericFuncType *) subj_extF80M_to_ui32_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI64_RX_NEAR_EVEN
    (genericFuncType *) subj_extF80M_to_ui64_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI64_RX_MINMAG
    (genericFuncType *) subj_extF80M_to_ui64_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI64_RX_MIN
    (genericFuncType *) subj_extF80M_to_ui64_rx_min,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI64_RX_MAX
    (genericFuncType *) subj_extF80M_to_ui64_rx_max,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_UI64_RX_NEAR_MAXMAG
    (genericFuncType *) subj_extF80M_to_ui64_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I32_RX_NEAR_EVEN
    (genericFuncType *) subj_extF80M_to_i32_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I32_RX_MINMAG
    (genericFuncType *) subj_extF80M_to_i32_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I32_RX_MIN
    (genericFuncType *) subj_extF80M_to_i32_rx_min,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I32_RX_MAX
    (genericFuncType *) subj_extF80M_to_i32_rx_max,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I32_RX_NEAR_MAXMAG
    (genericFuncType *) subj_extF80M_to_i32_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I64_RX_NEAR_EVEN
    (genericFuncType *) subj_extF80M_to_i64_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I64_RX_MINMAG
    (genericFuncType *) subj_extF80M_to_i64_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I64_RX_MIN
    (genericFuncType *) subj_extF80M_to_i64_rx_min,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I64_RX_MAX
    (genericFuncType *) subj_extF80M_to_i64_rx_max,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_I64_RX_NEAR_MAXMAG
    (genericFuncType *) subj_extF80M_to_i64_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_F32
    (genericFuncType *) subj_extF80M_to_f32,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_TO_F64
    (genericFuncType *) subj_extF80M_to_f64,
#else
    0,
#endif
#ifdef FLOAT128
#ifdef SUBJ_EXTF80_TO_F128
    (genericFuncType *) subj_extF80M_to_f128M,
#else
    0,
#endif
#endif
#ifdef SUBJ_EXTF80_ROUNDTOINT_R_NEAR_EVEN
    (genericFuncType *) subj_extF80M_roundToInt_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_ROUNDTOINT_R_MINMAG
    (genericFuncType *) subj_extF80M_roundToInt_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_ROUNDTOINT_R_MIN
    (genericFuncType *) subj_extF80M_roundToInt_r_min,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_ROUNDTOINT_R_MAX
    (genericFuncType *) subj_extF80M_roundToInt_r_max,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_ROUNDTOINT_R_NEAR_MAXMAG
    (genericFuncType *) subj_extF80M_roundToInt_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_ROUNDTOINT_X
    (genericFuncType *) subj_extF80M_roundToInt_x,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_ADD
    (genericFuncType *) subj_extF80M_add,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_SUB
    (genericFuncType *) subj_extF80M_sub,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_MUL
    (genericFuncType *) subj_extF80M_mul,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_DIV
    (genericFuncType *) subj_extF80M_div,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_REM
    (genericFuncType *) subj_extF80M_rem,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_SQRT
    (genericFuncType *) subj_extF80M_sqrt,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_EQ
    (genericFuncType *) subj_extF80M_eq,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_LE
    (genericFuncType *) subj_extF80M_le,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_LT
    (genericFuncType *) subj_extF80M_lt,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_EQ_SIGNALING
    (genericFuncType *) subj_extF80M_eq_signaling,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_LE_QUIET
    (genericFuncType *) subj_extF80M_le_quiet,
#else
    0,
#endif
#ifdef SUBJ_EXTF80_LT_QUIET
    (genericFuncType *) subj_extF80M_lt_quiet,
#else
    0,
#endif
#endif
    /*------------------------------------------------------------------------
    *------------------------------------------------------------------------*/
#ifdef FLOAT128
#ifdef SUBJ_F128_TO_UI32_R_NEAR_EVEN
    (genericFuncType *) subj_f128M_to_ui32_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI32_R_MINMAG
    (genericFuncType *) subj_f128M_to_ui32_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI32_R_MIN
    (genericFuncType *) subj_f128M_to_ui32_r_min,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI32_R_MAX
    (genericFuncType *) subj_f128M_to_ui32_r_max,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI32_R_NEAR_MAXMAG
    (genericFuncType *) subj_f128M_to_ui32_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI64_R_NEAR_EVEN
    (genericFuncType *) subj_f128M_to_ui64_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI64_R_MINMAG
    (genericFuncType *) subj_f128M_to_ui64_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI64_R_MIN
    (genericFuncType *) subj_f128M_to_ui64_r_min,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI64_R_MAX
    (genericFuncType *) subj_f128M_to_ui64_r_max,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI64_R_NEAR_MAXMAG
    (genericFuncType *) subj_f128M_to_ui64_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I32_R_NEAR_EVEN
    (genericFuncType *) subj_f128M_to_i32_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I32_R_MINMAG
    (genericFuncType *) subj_f128M_to_i32_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I32_R_MIN
    (genericFuncType *) subj_f128M_to_i32_r_min,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I32_R_MAX
    (genericFuncType *) subj_f128M_to_i32_r_max,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I32_R_NEAR_MAXMAG
    (genericFuncType *) subj_f128M_to_i32_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I64_R_NEAR_EVEN
    (genericFuncType *) subj_f128M_to_i64_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I64_R_MINMAG
    (genericFuncType *) subj_f128M_to_i64_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I64_R_MIN
    (genericFuncType *) subj_f128M_to_i64_r_min,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I64_R_MAX
    (genericFuncType *) subj_f128M_to_i64_r_max,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I64_R_NEAR_MAXMAG
    (genericFuncType *) subj_f128M_to_i64_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI32_RX_NEAR_EVEN
    (genericFuncType *) subj_f128M_to_ui32_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI32_RX_MINMAG
    (genericFuncType *) subj_f128M_to_ui32_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI32_RX_MIN
    (genericFuncType *) subj_f128M_to_ui32_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI32_RX_MAX
    (genericFuncType *) subj_f128M_to_ui32_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI32_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f128M_to_ui32_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI64_RX_NEAR_EVEN
    (genericFuncType *) subj_f128M_to_ui64_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI64_RX_MINMAG
    (genericFuncType *) subj_f128M_to_ui64_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI64_RX_MIN
    (genericFuncType *) subj_f128M_to_ui64_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI64_RX_MAX
    (genericFuncType *) subj_f128M_to_ui64_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_UI64_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f128M_to_ui64_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I32_RX_NEAR_EVEN
    (genericFuncType *) subj_f128M_to_i32_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I32_RX_MINMAG
    (genericFuncType *) subj_f128M_to_i32_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I32_RX_MIN
    (genericFuncType *) subj_f128M_to_i32_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I32_RX_MAX
    (genericFuncType *) subj_f128M_to_i32_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I32_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f128M_to_i32_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I64_RX_NEAR_EVEN
    (genericFuncType *) subj_f128M_to_i64_rx_near_even,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I64_RX_MINMAG
    (genericFuncType *) subj_f128M_to_i64_rx_minMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I64_RX_MIN
    (genericFuncType *) subj_f128M_to_i64_rx_min,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I64_RX_MAX
    (genericFuncType *) subj_f128M_to_i64_rx_max,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_I64_RX_NEAR_MAXMAG
    (genericFuncType *) subj_f128M_to_i64_rx_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_F32
    (genericFuncType *) subj_f128M_to_f32,
#else
    0,
#endif
#ifdef SUBJ_F128_TO_F64
    (genericFuncType *) subj_f128M_to_f64,
#else
    0,
#endif
#ifdef EXTFLOAT80
#ifdef SUBJ_F128_TO_EXTF80
    (genericFuncType *) subj_f128M_to_extF80M,
#else
    0,
#endif
#endif
#ifdef SUBJ_F128_ROUNDTOINT_R_NEAR_EVEN
    (genericFuncType *) subj_f128M_roundToInt_r_near_even,
#else
    0,
#endif
#ifdef SUBJ_F128_ROUNDTOINT_R_MINMAG
    (genericFuncType *) subj_f128M_roundToInt_r_minMag,
#else
    0,
#endif
#ifdef SUBJ_F128_ROUNDTOINT_R_MIN
    (genericFuncType *) subj_f128M_roundToInt_r_min,
#else
    0,
#endif
#ifdef SUBJ_F128_ROUNDTOINT_R_MAX
    (genericFuncType *) subj_f128M_roundToInt_r_max,
#else
    0,
#endif
#ifdef SUBJ_F128_ROUNDTOINT_R_NEAR_MAXMAG
    (genericFuncType *) subj_f128M_roundToInt_r_near_maxMag,
#else
    0,
#endif
#ifdef SUBJ_F128_ROUNDTOINT_X
    (genericFuncType *) subj_f128M_roundToInt_x,
#else
    0,
#endif
#ifdef SUBJ_F128_ADD
    (genericFuncType *) subj_f128M_add,
#else
    0,
#endif
#ifdef SUBJ_F128_SUB
    (genericFuncType *) subj_f128M_sub,
#else
    0,
#endif
#ifdef SUBJ_F128_MUL
    (genericFuncType *) subj_f128M_mul,
#else
    0,
#endif
#ifdef SUBJ_F128_MULADD
    (genericFuncType *) subj_f128M_mulAdd,
#else
    0,
#endif
#ifdef SUBJ_F128_DIV
    (genericFuncType *) subj_f128M_div,
#else
    0,
#endif
#ifdef SUBJ_F128_REM
    (genericFuncType *) subj_f128M_rem,
#else
    0,
#endif
#ifdef SUBJ_F128_SQRT
    (genericFuncType *) subj_f128M_sqrt,
#else
    0,
#endif
#ifdef SUBJ_F128_EQ
    (genericFuncType *) subj_f128M_eq,
#else
    0,
#endif
#ifdef SUBJ_F128_LE
    (genericFuncType *) subj_f128M_le,
#else
    0,
#endif
#ifdef SUBJ_F128_LT
    (genericFuncType *) subj_f128M_lt,
#else
    0,
#endif
#ifdef SUBJ_F128_EQ_SIGNALING
    (genericFuncType *) subj_f128M_eq_signaling,
#else
    0,
#endif
#ifdef SUBJ_F128_LE_QUIET
    (genericFuncType *) subj_f128M_le_quiet,
#else
    0,
#endif
#ifdef SUBJ_F128_LT_QUIET
    (genericFuncType *) subj_f128M_lt_quiet,
#else
    0,
#endif
#endif
};

