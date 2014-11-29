
SOURCE_DIR = ../../source
SUBJ_SOURCE_DIR = $(SOURCE_DIR)/subj-C
SOFTFLOAT_DIR = ../../../berkeley-softfloat-rc3
SOFTFLOAT_INCLUDE_DIR = $(SOFTFLOAT_DIR)/source/include
PLATFORM = Linux-386-GCC

SOFTFLOAT_H = \
  $(SOFTFLOAT_INCLUDE_DIR)/softfloat_types.h \
  $(SOFTFLOAT_INCLUDE_DIR)/softfloat.h
SOFTFLOAT_LIB = $(SOFTFLOAT_DIR)/build/$(PLATFORM)/softfloat$(LIB)

TYPE_OPTS = -DEXTFLOAT80 -DFLOAT128

DELETE = rm -f
C_INCLUDES = \
  -I. -I$(SUBJ_SOURCE_DIR) -I$(SOURCE_DIR) -I$(SOFTFLOAT_INCLUDE_DIR)
COMPILE_C = \
  gcc -c -Werror-implicit-function-declaration $(TYPE_OPTS) $(C_INCLUDES) -O2 \
    -o $@
COMPILE_SLOWFLOAT_C = \
  gcc -c -Werror-implicit-function-declaration $(TYPE_OPTS) $(C_INCLUDES) -O3 \
    -o $@
MAKELIB = ar crs $@
LINK = gcc -o $@

OBJ = .o
LIB = .a
EXE =

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
  standardFunctionInfos$(OBJ) \

#*** EVERYBODY SHOULD INCLUDE "platform.h", RIGHT?

uint128$(OBJ): platform.h $(SOURCE_DIR)/uint128.h
fail$(OBJ): $(SOURCE_DIR)/fail.h
functions_common$(OBJ): $(SOFTFLOAT_H) $(SOURCE_DIR)/functions.h
functionInfos$(OBJ): $(SOURCE_DIR)/functions.h
standardFunctionInfos$(OBJ): $(SOURCE_DIR)/functions.h
random$(OBJ): $(SOURCE_DIR)/random.h
genCases_common$(OBJ): $(SOURCE_DIR)/fail.h $(SOURCE_DIR)/genCases.h
$(OBJS_GENCASES): \
  $(SOURCE_DIR)/random.h $(SOFTFLOAT_H) $(SOURCE_DIR)/genCases.h
genCases_f128$(OBJ): platform.h $(SOURCE_DIR)/uint128.h
genCases_writeTestsTotal$(OBJ): $(SOURCE_DIR)/genCases.h
verCases_common$(OBJ): $(SOURCE_DIR)/verCases.h
verCases_writeFunctionName$(OBJ): $(SOURCE_DIR)/verCases.h
readHex$(OBJ): $(SOURCE_DIR)/readHex.h
writeHex$(OBJ): \
  platform.h $(SOURCE_DIR)/uint128.h $(SOFTFLOAT_H) $(SOURCE_DIR)/writeHex.h
writeCase_common$(OBJ): $(SOURCE_DIR)/writeCase.h
$(OBJS_WRITECASE): \
  $(SOFTFLOAT_H) $(SOURCE_DIR)/writeHex.h $(SOURCE_DIR)/writeCase.h
testLoops_common$(OBJ): $(SOURCE_DIR)/testLoops.h
$(OBJS_TEST): \
  platform.h $(SOURCE_DIR)/uint128.h $(SOFTFLOAT_H) \
  $(SOURCE_DIR)/genCases.h $(SOURCE_DIR)/verCases.h $(SOURCE_DIR)/writeCase.h \
  $(SOURCE_DIR)/testLoops.h
$(OBJS_LIB): %$(OBJ): $(SOURCE_DIR)/%.c
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
  $(SOFTFLOAT_H) $(SUBJ_SOURCE_DIR)/subjfloat_config.h \
  $(SOURCE_DIR)/subjfloat.h $(SUBJ_SOURCE_DIR)/subjfloat.c
	$(COMPILE_C) $(SUBJ_SOURCE_DIR)/subjfloat.c
subjfloat_functions$(OBJ): \
  $(SUBJ_SOURCE_DIR)/subjfloat_config.h $(SOURCE_DIR)/subjfloat.h \
  $(SOURCE_DIR)/functions.h $(SOURCE_DIR)/subjfloat_functions.c
	$(COMPILE_C) $(SOURCE_DIR)/subjfloat_functions.c
testfloat$(OBJ): \
  platform.h $(SOURCE_DIR)/uint128.h $(SOURCE_DIR)/fail.h $(SOFTFLOAT_H) \
  $(SUBJ_SOURCE_DIR)/subjfloat_config.h $(SOURCE_DIR)/subjfloat.h \
  $(SOURCE_DIR)/functions.h $(SOURCE_DIR)/genCases.h $(SOURCE_DIR)/verCases.h \
  $(SOURCE_DIR)/testLoops.h $(SOURCE_DIR)/testfloat.c
	$(COMPILE_C) $(SOURCE_DIR)/testfloat.c

testfloat$(EXE): $(OBJS_TESTFLOAT) testfloat$(LIB) $(SOFTFLOAT_LIB)
	$(LINK) $^ -lm

.PHONY: clean
clean:
	$(DELETE) $(OBJS_LIB) testfloat$(LIB)
	$(DELETE) $(OBJS_TESTSOFTFLOAT) testsoftfloat$(EXE)
	$(DELETE) $(OBJS_TIMESOFTFLOAT) timesoftfloat$(EXE)
	$(DELETE) $(OBJS_TESTFLOAT_GEN) testfloat_gen$(EXE)
	$(DELETE) $(OBJS_TESTFLOAT_VER) testfloat_ver$(EXE)
	$(DELETE) $(OBJS_TESTFLOAT) testfloat$(EXE)

