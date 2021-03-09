project(mpg123)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/android
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compat
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libmpg123
    )

set(DECODER_CFLAGS_NEON "-DOPT_NEON -DREAL_IS_FLOAT")

set(DECODER_SRC_NEON
    src/libmpg123/stringbuf.c
    src/libmpg123/icy.c
    src/libmpg123/icy2utf8.c
    src/libmpg123/ntom.c
    src/libmpg123/synth.c
    src/libmpg123/synth_8bit.c
    src/libmpg123/layer1.c
    src/libmpg123/layer2.c
    src/libmpg123/layer3.c
    src/libmpg123/dct36_neon.S
    src/libmpg123/dct64_neon_float.S
    src/libmpg123/synth_neon_float.S
    src/libmpg123/synth_neon_s32.S
    src/libmpg123/synth_stereo_neon_float.S
    src/libmpg123/synth_stereo_neon_s32.S
    src/libmpg123/dct64_neon.S
    src/libmpg123/synth_neon.S
    src/libmpg123/synth_stereo_neon.S
    src/libmpg123/synth_s32.c
    src/libmpg123/synth_real.c
    src/libmpg123/feature.c
    )

set(DECODER_CFLAGS_NEON64 "-DOPT_MULTI -DOPT_GENERIC -DOPT_GENERIC_DITHER -DOPT_NEON64 -DREAL_IS_FLOAT")

set(DECODER_SRC_NEON64
    src/libmpg123/stringbuf.c
    src/libmpg123/icy.c
    src/libmpg123/icy2utf8.c
    src/libmpg123/ntom.c
    src/libmpg123/synth.c
    src/libmpg123/synth_8bit.c
    src/libmpg123/layer1.c
    src/libmpg123/layer2.c
    src/libmpg123/layer3.c
    src/libmpg123/dct36_neon64.S
    src/libmpg123/dct64_neon64_float.S
    src/libmpg123/synth_neon64_float.S
    src/libmpg123/synth_neon64_s32.S
    src/libmpg123/synth_stereo_neon64_float.S
    src/libmpg123/synth_stereo_neon64_s32.S
    src/libmpg123/dct64_neon64.S
    src/libmpg123/synth_neon64.S
    src/libmpg123/synth_stereo_neon64.S
    src/libmpg123/synth_s32.c
    src/libmpg123/synth_real.c
    src/libmpg123/dither.c
    src/libmpg123/getcpuflags_arm.c
    src/libmpg123/check_neon.S
    src/libmpg123/feature.c
    )

# Unfortunately the assembly isn't relocatable so doesn't work on modern
# Android devices
set(DECODER_CFLAGS_X86 "-DOPT_GENERIC -DREAL_IS_FLOAT")
set(DECODER_CFLAGS_X86_ASM "-DOPT_MULTI -DOPT_GENERIC -DOPT_GENERIC_DITHER -DOPT_I386 -DOPT_I586 -DOPT_I586_DITHER -DOPT_MMX -DOPT_3DNOW -DOPT_3DNOW_VINTAGE -DOPT_3DNOWEXT -DOPT_3DNOWEXT_VINTAGE -DOPT_SSE -DOPT_SSE_VINTAGE -DREAL_IS_FLOAT")

set(DECODER_SRC_X86
    src/libmpg123/feature.c
    src/libmpg123/icy2utf8.c
    src/libmpg123/icy.c
    src/libmpg123/layer1.c
    src/libmpg123/layer2.c
    src/libmpg123/layer3.c
    src/libmpg123/ntom.c
    src/libmpg123/stringbuf.c
    src/libmpg123/synth_8bit.c
    src/libmpg123/synth.c
    src/libmpg123/synth_real.c
    src/libmpg123/synth_s32.c
    src/libmpg123/dither.c
    )

set(DECODER_SRC_X86_ASM
    src/libmpg123/stringbuf.c
    src/libmpg123/icy.c
    src/libmpg123/icy2utf8.c
    src/libmpg123/ntom.c
    src/libmpg123/synth.c
    src/libmpg123/synth_8bit.c
    src/libmpg123/layer1.c
    src/libmpg123/layer2.c
    src/libmpg123/layer3.c
    src/libmpg123/synth_s32.c
    src/libmpg123/synth_real.c
    src/libmpg123/dct64_i386.c
    src/libmpg123/synth_i586.S
    src/libmpg123/synth_i586_dither.S
    src/libmpg123/dct64_mmx.S
    src/libmpg123/tabinit_mmx.S
    src/libmpg123/synth_mmx.S
    src/libmpg123/synth_3dnow.S
    src/libmpg123/dct64_3dnow.S
    src/libmpg123/equalizer_3dnow.S
    src/libmpg123/dct36_3dnow.S
    src/libmpg123/dct64_3dnowext.S
    src/libmpg123/synth_3dnowext.S
    src/libmpg123/dct36_3dnowext.S
    src/libmpg123/dct64_sse_float.S
    src/libmpg123/synth_sse_float.S
    src/libmpg123/synth_stereo_sse_float.S
    src/libmpg123/synth_sse_s32.S
    src/libmpg123/synth_stereo_sse_s32.S
    src/libmpg123/dct36_sse.S
    src/libmpg123/dct64_sse.S
    src/libmpg123/synth_sse.S
    src/libmpg123/getcpuflags.S
    src/libmpg123/dither.c
    src/libmpg123/feature.c
    )

set(DECODER_CFLAGS_X64 "-DOPT_MULTI -DOPT_X86_64 -DOPT_GENERIC -DOPT_GENERIC_DITHER -DREAL_IS_FLOAT -DOPT_AVX")

set(DECODER_SRC_X64
    src/libmpg123/stringbuf.c
    src/libmpg123/icy.c
    src/libmpg123/icy.h
    src/libmpg123/icy2utf8.c
    src/libmpg123/icy2utf8.h
    src/libmpg123/ntom.c
    src/libmpg123/synth.c
    src/libmpg123/synth.h
    src/libmpg123/synth_8bit.c
    src/libmpg123/synth_8bit.h
    src/libmpg123/layer1.c
    src/libmpg123/layer2.c
    src/libmpg123/layer3.c
    src/libmpg123/synth_s32.c
    src/libmpg123/synth_real.c
    src/libmpg123/dct36_x86_64.S
    src/libmpg123/dct64_x86_64_float.S
    src/libmpg123/synth_x86_64_float.S
    src/libmpg123/synth_x86_64_s32.S
    src/libmpg123/synth_stereo_x86_64_float.S
    src/libmpg123/synth_stereo_x86_64_s32.S
    src/libmpg123/synth_x86_64.S
    src/libmpg123/dct64_x86_64.S
    src/libmpg123/synth_stereo_x86_64.S
    src/libmpg123/dither.c
    src/libmpg123/dither.h
    src/libmpg123/getcpuflags_x86_64.S
    src/libmpg123/dct36_avx.S
    src/libmpg123/dct64_avx_float.S
    src/libmpg123/synth_stereo_avx_float.S
    src/libmpg123/synth_stereo_avx_s32.S
    src/libmpg123/dct64_avx.S
    src/libmpg123/synth_stereo_avx.S
    src/libmpg123/feature.c
    )

set(DECODER_CFLAGS_MIPS "-DOPT_GENERIC -DREAL_IS_FLOAT")

set(DECODER_SRC_MIPS
    src/libmpg123/stringbuf.c
    src/libmpg123/icy.c
    src/libmpg123/icy2utf8.c
    src/libmpg123/ntom.c
    src/libmpg123/synth.c
    src/libmpg123/synth_8bit.c
    src/libmpg123/layer1.c
    src/libmpg123/layer2.c
    src/libmpg123/layer3.c
    src/libmpg123/synth_s32.c
    src/libmpg123/synth_real.c
    src/libmpg123/feature.c
    )

if(ANDROID_ABI STREQUAL armeabi-v7a OR ANDROID_ABI STREQUAL armeabi)
    set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS} ${DECODER_CFLAGS_NEON}")
    set(DECODER_SRC_FILES ${DECODER_SRC_NEON})
elseif(ANDROID_ABI STREQUAL arm64-v8a)
    set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS} ${DECODER_CFLAGS_NEON64}")                             
    set(DECODER_SRC_FILES ${DECODER_SRC_NEON64})
    #message(FATAL_ERROR "ANDROID_ARCH=arm64-v8a")
endif()

set(LIBMPG123_SRC_FILES
    ${DECODER_SRC_FILES}
    src/libmpg123/parse.c
    src/libmpg123/frame.c
    src/libmpg123/format.c
    src/libmpg123/dct64.c
    src/libmpg123/equalizer.c
    src/libmpg123/id3.c
    src/libmpg123/optimize.c
    src/libmpg123/readers.c
    src/libmpg123/tabinit.c
    src/libmpg123/libmpg123.c
    src/libmpg123/index.c
    src/compat/compat_str.c
    src/compat/compat.c
    )

set(LIBOGG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libogg-1.3.2)

include_directories(
    ${LIBOGG_DIR}/include
    ${LIBOGG_DIR}/android
    )

add_library(mpg123 STATIC ${LIBMPG123_SRC_FILES})
target_link_libraries(mpg123)
