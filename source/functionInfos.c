
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
#include "functions.h"

#define ARG_1      FUNC_ARG_UNARY
#define ARG_2      FUNC_ARG_BINARY
#define ARG_R      FUNC_ARG_ROUNDINGMODE
#define ARG_E      FUNC_ARG_EXACT
#define EFF_P      FUNC_EFF_ROUNDINGPRECISION
#define EFF_R      FUNC_EFF_ROUNDINGMODE
#define EFF_T      FUNC_EFF_TININESSMODE
#define EFF_T_REDP FUNC_EFF_TININESSMODE_REDUCEDPREC

/*----------------------------------------------------------------------------
| Warning:  This array must match the functions names defined in
| "functions.h".
*----------------------------------------------------------------------------*/
const struct functionInfo functionInfos[NUM_FUNCTIONS] = {
    { 0, 0 },
    /*------------------------------------------------------------------------
    *------------------------------------------------------------------------*/
    { "ui32_to_f32",    ARG_1 | EFF_R },
    { "ui32_to_f64",    ARG_1         },
#ifdef EXTFLOAT80
    { "ui32_to_extF80", ARG_1         },
#endif
#ifdef FLOAT128
    { "ui32_to_f128",   ARG_1         },
#endif
    { "ui64_to_f32",    ARG_1 | EFF_R },
    { "ui64_to_f64",    ARG_1 | EFF_R },
#ifdef EXTFLOAT80
    { "ui64_to_extF80", ARG_1         },
#endif
#ifdef FLOAT128
    { "ui64_to_f128",   ARG_1         },
#endif
    { "i32_to_f32",     ARG_1 | EFF_R },
    { "i32_to_f64",     ARG_1         },
#ifdef EXTFLOAT80
    { "i32_to_extF80",  ARG_1         },
#endif
#ifdef FLOAT128
    { "i32_to_f128",    ARG_1         },
#endif
    { "i64_to_f32",     ARG_1 | EFF_R },
    { "i64_to_f64",     ARG_1 | EFF_R },
#ifdef EXTFLOAT80
    { "i64_to_extF80",  ARG_1         },
#endif
#ifdef FLOAT128
    { "i64_to_f128",    ARG_1         },
#endif
    /*------------------------------------------------------------------------
    *------------------------------------------------------------------------*/
    { "f32_to_ui32", ARG_1 | ARG_R | ARG_E },
    { "f32_to_ui64", ARG_1 | ARG_R | ARG_E },
    { "f32_to_i32",  ARG_1 | ARG_R | ARG_E },
    { "f32_to_i64",  ARG_1 | ARG_R | ARG_E },
    { "f32_to_ui32_r_minMag", ARG_1 | ARG_E },
    { "f32_to_ui64_r_minMag", ARG_1 | ARG_E },
    { "f32_to_i32_r_minMag",  ARG_1 | ARG_E },
    { "f32_to_i64_r_minMag",  ARG_1 | ARG_E },
    { "f32_to_f64",    ARG_1 },
#ifdef EXTFLOAT80
    { "f32_to_extF80", ARG_1 },
#endif
#ifdef FLOAT128
    { "f32_to_f128",   ARG_1 },
#endif
    { "f32_roundToInt", ARG_1 | ARG_R | ARG_E },
    { "f32_add",          ARG_2 | EFF_R         },
    { "f32_sub",          ARG_2 | EFF_R         },
    { "f32_mul",          ARG_2 | EFF_R | EFF_T },
    { "f32_mulAdd",               EFF_R | EFF_T },
    { "f32_div",          ARG_2 | EFF_R         },
    { "f32_rem",          ARG_2                 },
    { "f32_sqrt",         ARG_1 | EFF_R         },
    { "f32_eq",           ARG_2                 },
    { "f32_le",           ARG_2                 },
    { "f32_lt",           ARG_2                 },
    { "f32_eq_signaling", ARG_2                 },
    { "f32_le_quiet",     ARG_2                 },
    { "f32_lt_quiet",     ARG_2                 },
    /*------------------------------------------------------------------------
    *------------------------------------------------------------------------*/
    { "f64_to_ui32", ARG_1 | ARG_R | ARG_E },
    { "f64_to_ui64", ARG_1 | ARG_R | ARG_E },
    { "f64_to_i32",  ARG_1 | ARG_R | ARG_E },
    { "f64_to_i64",  ARG_1 | ARG_R | ARG_E },
    { "f64_to_ui32_r_minMag", ARG_1 | ARG_E },
    { "f64_to_ui64_r_minMag", ARG_1 | ARG_E },
    { "f64_to_i32_r_minMag",  ARG_1 | ARG_E },
    { "f64_to_i64_r_minMag",  ARG_1 | ARG_E },
    { "f64_to_f32",  ARG_1 | EFF_R | EFF_T },
#ifdef EXTFLOAT80
    { "f64_to_extF80", ARG_1 },
#endif
#ifdef FLOAT128
    { "f64_to_f128",   ARG_1 },
#endif
    { "f64_roundToInt", ARG_1 | ARG_R | ARG_E },
    { "f64_add",          ARG_2 | EFF_R         },
    { "f64_sub",          ARG_2 | EFF_R         },
    { "f64_mul",          ARG_2 | EFF_R | EFF_T },
    { "f64_mulAdd",               EFF_R | EFF_T },
    { "f64_div",          ARG_2 | EFF_R         },
    { "f64_rem",          ARG_2                 },
    { "f64_sqrt",         ARG_1 | EFF_R         },
    { "f64_eq",           ARG_2                 },
    { "f64_le",           ARG_2                 },
    { "f64_lt",           ARG_2                 },
    { "f64_eq_signaling", ARG_2                 },
    { "f64_le_quiet",     ARG_2                 },
    { "f64_lt_quiet",     ARG_2                 },
    /*------------------------------------------------------------------------
    *------------------------------------------------------------------------*/
#ifdef EXTFLOAT80
    { "extF80_to_ui32", ARG_1 | ARG_R | ARG_E },
    { "extF80_to_ui64", ARG_1 | ARG_R | ARG_E },
    { "extF80_to_i32",  ARG_1 | ARG_R | ARG_E },
    { "extF80_to_i64",  ARG_1 | ARG_R | ARG_E },
    { "extF80_to_ui32_r_minMag", ARG_1 | ARG_E },
    { "extF80_to_ui64_r_minMag", ARG_1 | ARG_E },
    { "extF80_to_i32_r_minMag",  ARG_1 | ARG_E },
    { "extF80_to_i64_r_minMag",  ARG_1 | ARG_E },
    { "extF80_to_f32",  ARG_1 | EFF_R | EFF_T },
    { "extF80_to_f64",  ARG_1 | EFF_R | EFF_T },
#ifdef FLOAT128
    { "extF80_to_f128", ARG_1 },
#endif
    { "extF80_roundToInt", ARG_1 | ARG_R | ARG_E },
    { "extF80_add",          ARG_2 | EFF_P | EFF_R         | EFF_T_REDP },
    { "extF80_sub",          ARG_2 | EFF_P | EFF_R         | EFF_T_REDP },
    { "extF80_mul",          ARG_2 | EFF_P | EFF_R | EFF_T | EFF_T_REDP },
    { "extF80_div",          ARG_2 | EFF_P | EFF_R         | EFF_T_REDP },
    { "extF80_rem",          ARG_2                                      },
    { "extF80_sqrt",         ARG_1 | EFF_P | EFF_R                      },
    { "extF80_eq",           ARG_2                                      },
    { "extF80_le",           ARG_2                                      },
    { "extF80_lt",           ARG_2                                      },
    { "extF80_eq_signaling", ARG_2                                      },
    { "extF80_le_quiet",     ARG_2                                      },
    { "extF80_lt_quiet",     ARG_2                                      },
#endif
    /*------------------------------------------------------------------------
    *------------------------------------------------------------------------*/
#ifdef FLOAT128
    { "f128_to_ui32", ARG_1 | ARG_R | ARG_E },
    { "f128_to_ui64", ARG_1 | ARG_R | ARG_E },
    { "f128_to_i32",  ARG_1 | ARG_R | ARG_E },
    { "f128_to_i64",  ARG_1 | ARG_R | ARG_E },
    { "f128_to_ui32_r_minMag", ARG_1 | ARG_E },
    { "f128_to_ui64_r_minMag", ARG_1 | ARG_E },
    { "f128_to_i32_r_minMag",  ARG_1 | ARG_E },
    { "f128_to_i64_r_minMag",  ARG_1 | ARG_E },
    { "f128_to_f32",  ARG_1 | EFF_R | EFF_T },
    { "f128_to_f64",  ARG_1 | EFF_R | EFF_T },
#ifdef EXTFLOAT80
    { "f128_to_extF80", ARG_1 | EFF_R | EFF_T },
#endif
    { "f128_roundToInt", ARG_1 | ARG_R | ARG_E },
    { "f128_add",          ARG_2 | EFF_R         },
    { "f128_sub",          ARG_2 | EFF_R         },
    { "f128_mul",          ARG_2 | EFF_R | EFF_T },
    { "f128_mulAdd",               EFF_R | EFF_T },
    { "f128_div",          ARG_2 | EFF_R         },
    { "f128_rem",          ARG_2                 },
    { "f128_sqrt",         ARG_1 | EFF_R         },
    { "f128_eq",           ARG_2                 },
    { "f128_le",           ARG_2                 },
    { "f128_lt",           ARG_2                 },
    { "f128_eq_signaling", ARG_2                 },
    { "f128_le_quiet",     ARG_2                 },
    { "f128_lt_quiet",     ARG_2                 },
#endif
};

