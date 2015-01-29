
#=============================================================================
#
# This Makefile is part of TestFloat, Release 3, a package of programs for
# testing the correctness of floating-point arithmetic complying with the IEEE
# Standard for Floating-Point, by John R. Hauser.
#
# Copyright 2011, 2012, 2013, 2014 The Regents of the University of California
# (Regents).  All Rights Reserved.  Redistribution and use in source and
# binary forms, with or without modification, are permitted provided that the
# following conditions are met:
#
# Redistributions of source code must retain the above copyright notice,
# this list of conditions, and the following two paragraphs of disclaimer.
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions, and the following two paragraphs of disclaimer in
# the documentation and/or other materials provided with the distribution.
# Neither the name of the Regents nor the names of its contributors may be
# used to endorse or promote products derived from this software without
# specific prior written permission.
#
# IN NO EVENT SHALL REGENTS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
# SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS,
# ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF
# REGENTS HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE.  THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED
# HEREUNDER IS PROVIDED "AS IS".  REGENTS HAS NO OBLIGATION TO PROVIDE
# MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
#
#=============================================================================

SOURCE_DIR = ../../source
SUBJ_SOURCE_DIR = $(SOURCE_DIR)/subj-C
SOFTFLOAT_DIR = ../../../berkeley-softfloat-3
SOFTFLOAT_INCLUDE_DIR = $(SOFTFLOAT_DIR)/source/include
PLATFORM = Win64-MinGW-w64

SOFTFLOAT_H = \
  $(SOFTFLOAT_INCLUDE_DIR)/softfloat_types.h \
  $(SOFTFLOAT_INCLUDE_DIR)/softfloat.h
SOFTFLOAT_LIB = $(SOFTFLOAT_DIR)/build/$(PLATFORM)/softfloat$(LIB)

TESTFLOAT_OPTS = -DEXTFLOAT80 -DFLOAT128 -DLONG_DOUBLE_IS_EXTFLOAT80

DELETE = rm -f
C_INCLUDES = \
  -I. -I$(SUBJ_SOURCE_DIR) -I$(SOURCE_DIR) -I$(SOFTFLOAT_INCLUDE_DIR)
COMPILE_C = \
  x86_64-w64-mingw32-gcc -c -Werror-implicit-function-declaration \
    $(TESTFLOAT_OPTS) $(C_INCLUDES) -O2 -o $@
COMPILE_SLOWFLOAT_C = \
  x86_64-w64-mingw32-gcc -c -Werror-implicit-function-declaration \
    $(TESTFLOAT_OPTS) $(C_INCLUDES) -O3 -o $@
MAKELIB = x86_64-w64-mingw32-ar crs $@
LINK = x86_64-w64-mingw32-gcc -lm -o $@

OBJ = .o
LIB = .a
EXE = .exe

.PHONY: all
all: \
  testsoftfloat$(EXE) \
  timesoftfloat$(EXE) \
  testfloat_gen$(EXE) \
  testfloat_ver$(EXE) \
  testfloat$(EXE) \

OBJS_GENCASES = \
  genCases_ui32$(OBJ) \
  genCases_ui64$(OBJ) \
  genCases_i32$(OBJ) \
  genCases_i64$(OBJ) \
  genCases_f32$(OBJ) \
  genCases_f64$(OBJ) \
  genCases_extF80$(OBJ) \
  genCases_f128$(OBJ) \

OBJS_WRITECASE = \
  writeCase_a_ui32$(OBJ) \
  writeCase_a_ui64$(OBJ) \
  writeCase_a_f32$(OBJ) \
  writeCase_ab_f32$(OBJ) \
  writeCase_abc_f32$(OBJ) \
  writeCase_a_f64$(OBJ) \
  writeCase_ab_f64$(OBJ) \
  writeCase_abc_f64$(OBJ) \
  writeCase_a_extF80M$(OBJ) \
  writeCase_ab_extF80M$(OBJ) \
  writeCase_abc_extF80M$(OBJ) \
  writeCase_a_f128M$(OBJ) \
  writeCase_ab_f128M$(OBJ) \
  writeCase_abc_f128M$(OBJ) \
  writeCase_z_bool$(OBJ) \
  writeCase_z_ui32$(OBJ) \
  writeCase_z_ui64$(OBJ) \
  writeCase_z_f32$(OBJ) \
  writeCase_z_f64$(OBJ) \
  writeCase_z_extF80M$(OBJ) \
  writeCase_z_f128M$(OBJ) \

OBJS_TEST = \
  test_a_ui32_z_f32$(OBJ) \
  test_a_ui32_z_f64$(OBJ) \
  test_a_ui32_z_extF80$(OBJ) \
  test_a_ui32_z_f128$(OBJ) \
  test_a_ui64_z_f32$(OBJ) \
  test_a_ui64_z_f64$(OBJ) \
  test_a_ui64_z_extF80$(OBJ) \
  test_a_ui64_z_f128$(OBJ) \
  test_a_i32_z_f32$(OBJ) \
  test_a_i32_z_f64$(OBJ) \
  test_a_i32_z_extF80$(OBJ) \
  test_a_i32_z_f128$(OBJ) \
  test_a_i64_z_f32$(OBJ) \
  test_a_i64_z_f64$(OBJ) \
  test_a_i64_z_extF80$(OBJ) \
  test_a_i64_z_f128$(OBJ) \
  test_a_f32_z_ui32_rx$(OBJ) \
  test_a_f32_z_ui64_rx$(OBJ) \
  test_a_f32_z_i32_rx$(OBJ) \
  test_a_f32_z_i64_rx$(OBJ) \
  test_a_f32_z_ui32_x$(OBJ) \
  test_a_f32_z_ui64_x$(OBJ) \
  test_a_f32_z_i32_x$(OBJ) \
  test_a_f32_z_i64_x$(OBJ) \
  test_a_f32_z_f64$(OBJ) \
  test_a_f32_z_extF80$(OBJ) \
  test_a_f32_z_f128$(OBJ) \
  test_az_f32$(OBJ) \
  test_az_f32_rx$(OBJ) \
  test_abz_f32$(OBJ) \
  test_abcz_f32$(OBJ) \
  test_ab_f32_z_bool$(OBJ) \
  test_a_f64_z_ui32_rx$(OBJ) \
  test_a_f64_z_ui64_rx$(OBJ) \
  test_a_f64_z_i32_rx$(OBJ) \
  test_a_f64_z_i64_rx$(OBJ) \
  test_a_f64_z_ui32_x$(OBJ) \
  test_a_f64_z_ui64_x$(OBJ) \
  test_a_f64_z_i32_x$(OBJ) \
  test_a_f64_z_i64_x$(OBJ) \
  test_a_f64_z_f32$(OBJ) \
  test_a_f64_z_extF80$(OBJ) \
  test_a_f64_z_f128$(OBJ) \
  test_az_f64$(OBJ) \
  test_az_f64_rx$(OBJ) \
  test_abz_f64$(OBJ) \
  test_abcz_f64$(OBJ) \
  test_ab_f64_z_bool$(OBJ) \
  test_a_extF80_z_ui32_rx$(OBJ) \
  test_a_extF80_z_ui64_rx$(OBJ) \
  test_a_extF80_z_i32_rx$(OBJ) \
  test_a_extF80_z_i64_rx$(OBJ) \
  test_a_extF80_z_ui32_x$(OBJ) \
  test_a_extF80_z_ui64_x$(OBJ) \
  test_a_extF80_z_i32_x$(OBJ) \
  test_a_extF80_z_i64_x$(OBJ) \
  test_a_extF80_z_f32$(OBJ) \
  test_a_extF80_z_f64$(OBJ) \
  test_a_extF80_z_f128$(OBJ) \
  test_az_extF80$(OBJ) \
  test_az_extF80_rx$(OBJ) \
  test_abz_extF80$(OBJ) \
  test_ab_extF80_z_bool$(OBJ) \
  test_a_f128_z_ui32_rx$(OBJ) \
  test_a_f128_z_ui64_rx$(OBJ) \
  test_a_f128_z_i32_rx$(OBJ) \
  test_a_f128_z_i64_rx$(OBJ) \
  test_a_f128_z_ui32_x$(OBJ) \
  test_a_f128_z_ui64_x$(OBJ) \
  test_a_f128_z_i32_x$(OBJ) \
  test_a_f128_z_i64_x$(OBJ) \
  test_a_f128_z_f32$(OBJ) \
  test_a_f128_z_f64$(OBJ) \
  test_a_f128_z_extF80$(OBJ) \
  test_az_f128$(OBJ) \
  test_az_f128_rx$(OBJ) \
  test_abz_f128$(OBJ) \
  test_abcz_f128$(OBJ) \
  test_ab_f128_z_bool$(OBJ) \

OBJS_LIB = \
  uint128$(OBJ) \
  fail$(OBJ) \
  functions_common$(OBJ) \
  functionInfos$(OBJ) \
  standardFunctionInfos$(OBJ) \
  random$(OBJ) \
  genCases_common$(OBJ) \
  $(OBJS_GENCASES) \
  genCases_writeTestsTotal$(OBJ) \
  verCases_common$(OBJ) \
  verCases_writeFunctionName$(OBJ) \
  readHex$(OBJ) \
  writeHex$(OBJ) \
  $(OBJS_WRITECASE) \
  testLoops_common$(OBJ) \
  $(OBJS_TEST) \

uint128$(OBJ): $(SOURCE_DIR)/uint128.h
fail$(OBJ): $(SOURCE_DIR)/fail.h
functions_common$(OBJ): $(SOFTFLOAT_H) $(SOURCE_DIR)/functions.h
functionInfos$(OBJ): $(SOURCE_DIR)/functions.h
standardFunctionInfos$(OBJ): $(SOURCE_DIR)/functions.h
random$(OBJ): $(SOURCE_DIR)/random.h
genCases_common$(OBJ): $(SOURCE_DIR)/fail.h $(SOURCE_DIR)/genCases.h
$(OBJS_GENCASES): \
  $(SOURCE_DIR)/random.h $(SOFTFLOAT_H) $(SOURCE_DIR)/genCases.h
genCases_f128$(OBJ): $(SOURCE_DIR)/uint128.h
genCases_writeTestsTotal$(OBJ): $(SOURCE_DIR)/genCases.h
verCases_common$(OBJ): $(SOURCE_DIR)/verCases.h
verCases_writeFunctionName$(OBJ): $(SOURCE_DIR)/verCases.h
readHex$(OBJ): $(SOURCE_DIR)/readHex.h
writeHex$(OBJ): $(SOURCE_DIR)/uint128.h $(SOFTFLOAT_H) $(SOURCE_DIR)/writeHex.h
$(OBJS_WRITECASE): \
  $(SOFTFLOAT_H) $(SOURCE_DIR)/writeHex.h $(SOURCE_DIR)/writeCase.h
testLoops_common$(OBJ): $(SOURCE_DIR)/testLoops.h
$(OBJS_TEST): \
  $(SOURCE_DIR)/uint128.h $(SOFTFLOAT_H) $(SOURCE_DIR)/genCases.h \
  $(SOURCE_DIR)/verCases.h $(SOURCE_DIR)/writeCase.h $(SOURCE_DIR)/testLoops.h
$(OBJS_LIB): %$(OBJ): platform.h $(SOURCE_DIR)/%.c
	$(COMPILE_C) $(SOURCE_DIR)/$*.c
testfloat$(LIB): $(OBJS_LIB)
	$(MAKELIB) $^

OBJS_TESTSOFTFLOAT = slowfloat$(OBJ) testsoftfloat$(OBJ)

slowfloat$(OBJ): \
  platform.h $(SOURCE_DIR)/uint128.h $(SOFTFLOAT_H) \
  $(SOURCE_DIR)/slowfloat.h $(SOURCE_DIR)/slowfloat.c
	$(COMPILE_SLOWFLOAT_C) $(SOURCE_DIR)/slowfloat.c
testsoftfloat$(OBJ): \
  platform.h $(SOURCE_DIR)/uint128.h $(SOURCE_DIR)/fail.h $(SOFTFLOAT_H) \
  $(SOURCE_DIR)/slowfloat.h $(SOURCE_DIR)/functions.h \
  $(SOURCE_DIR)/genCases.h $(SOURCE_DIR)/verCases.h $(SOURCE_DIR)/writeCase.h \
  $(SOURCE_DIR)/testLoops.h $(SOURCE_DIR)/testsoftfloat.c
	$(COMPILE_C) $(SOURCE_DIR)/testsoftfloat.c

testsoftfloat$(EXE): $(OBJS_TESTSOFTFLOAT) testfloat$(LIB) $(SOFTFLOAT_LIB)
	$(LINK) $^

OBJS_TIMESOFTFLOAT = timesoftfloat$(OBJ)

timesoftfloat$(OBJ): \
  platform.h $(SOURCE_DIR)/uint128.h $(SOURCE_DIR)/fail.h $(SOFTFLOAT_H) \
  $(SOURCE_DIR)/functions.h $(SOURCE_DIR)/timesoftfloat.c
	$(COMPILE_C) $(SOURCE_DIR)/timesoftfloat.c

timesoftfloat$(EXE): $(OBJS_TIMESOFTFLOAT) testfloat$(LIB) $(SOFTFLOAT_LIB)
	$(LINK) $^

OBJS_TESTFLOAT_GEN = genLoops$(OBJ) testfloat_gen$(OBJ)

genLoops$(OBJ): \
  platform.h $(SOURCE_DIR)/uint128.h $(SOURCE_DIR)/fail.h $(SOFTFLOAT_H) \
  $(SOURCE_DIR)/genCases.h $(SOURCE_DIR)/writeHex.h $(SOURCE_DIR)/genLoops.h \
  $(SOURCE_DIR)/genLoops.c
	$(COMPILE_C) $(SOURCE_DIR)/genLoops.c
testfloat_gen$(OBJ): \
  $(SOURCE_DIR)/fail.h $(SOFTFLOAT_H) $(SOURCE_DIR)/functions.h \
  $(SOURCE_DIR)/genCases.h $(SOURCE_DIR)/genLoops.h \
  $(SOURCE_DIR)/testfloat_gen.c
	$(COMPILE_C) $(SOURCE_DIR)/testfloat_gen.c

testfloat_gen$(EXE): $(OBJS_TESTFLOAT_GEN) testfloat$(LIB) $(SOFTFLOAT_LIB)
	$(LINK) $^

OBJS_TESTFLOAT_VER = verLoops$(OBJ) testfloat_ver$(OBJ)

verLoops$(OBJ): \
  platform.h $(SOURCE_DIR)/uint128.h $(SOURCE_DIR)/fail.h $(SOFTFLOAT_H) \
  $(SOURCE_DIR)/readHex.h $(SOURCE_DIR)/verCases.h $(SOURCE_DIR)/writeCase.h \
  $(SOURCE_DIR)/verLoops.h $(SOURCE_DIR)/verLoops.c
	$(COMPILE_C) $(SOURCE_DIR)/verLoops.c
testfloat_ver$(OBJ): \
  platform.h $(SOURCE_DIR)/uint128.h $(SOURCE_DIR)/fail.h $(SOFTFLOAT_H) \
  $(SOURCE_DIR)/functions.h $(SOURCE_DIR)/verCases.h \
  $(SOURCE_DIR)/writeCase.h $(SOURCE_DIR)/verLoops.h \
  $(SOURCE_DIR)/testfloat_ver.c
	$(COMPILE_C) $(SOURCE_DIR)/testfloat_ver.c

testfloat_ver$(EXE): $(OBJS_TESTFLOAT_VER) testfloat$(LIB) $(SOFTFLOAT_LIB)
	$(LINK) $^

OBJS_TESTFLOAT = subjfloat$(OBJ) subjfloat_functions$(OBJ) testfloat$(OBJ)

subjfloat$(OBJ): \
  platform.h $(SOFTFLOAT_H) $(SUBJ_SOURCE_DIR)/subjfloat_config.h \
  $(SOURCE_DIR)/subjfloat.h $(SUBJ_SOURCE_DIR)/subjfloat.c
	$(COMPILE_C) $(SUBJ_SOURCE_DIR)/subjfloat.c
subjfloat_functions$(OBJ): \
  platform.h $(SUBJ_SOURCE_DIR)/subjfloat_config.h $(SOURCE_DIR)/subjfloat.h \
  $(SOURCE_DIR)/functions.h $(SOURCE_DIR)/subjfloat_functions.c
	$(COMPILE_C) $(SOURCE_DIR)/subjfloat_functions.c
testfloat$(OBJ): \
  platform.h $(SOURCE_DIR)/uint128.h $(SOURCE_DIR)/fail.h $(SOFTFLOAT_H) \
  $(SUBJ_SOURCE_DIR)/subjfloat_config.h $(SOURCE_DIR)/subjfloat.h \
  $(SOURCE_DIR)/functions.h $(SOURCE_DIR)/genCases.h $(SOURCE_DIR)/verCases.h \
  $(SOURCE_DIR)/testLoops.h $(SOURCE_DIR)/testfloat.c
	$(COMPILE_C) $(SOURCE_DIR)/testfloat.c

testfloat$(EXE): $(OBJS_TESTFLOAT) testfloat$(LIB) $(SOFTFLOAT_LIB)
	$(LINK) $^

.PHONY: clean
clean:
	$(DELETE) $(OBJS_LIB) testfloat$(LIB)
	$(DELETE) $(OBJS_TESTSOFTFLOAT) testsoftfloat$(EXE)
	$(DELETE) $(OBJS_TIMESOFTFLOAT) timesoftfloat$(EXE)
	$(DELETE) $(OBJS_TESTFLOAT_GEN) testfloat_gen$(EXE)
	$(DELETE) $(OBJS_TESTFLOAT_VER) testfloat_ver$(EXE)
	$(DELETE) $(OBJS_TESTFLOAT) testfloat$(EXE)

