project(flac)

set(LIBFLAC_SRC_FILES
    src/libFLAC/bitmath.c
    src/libFLAC/bitreader.c
    src/libFLAC/bitwriter.c
    src/libFLAC/cpu.c
    src/libFLAC/crc.c
    src/libFLAC/fixed.c
    src/libFLAC/fixed_intrin_sse2.c
    src/libFLAC/fixed_intrin_ssse3.c
    src/libFLAC/float.c
    src/libFLAC/format.c
    src/libFLAC/lpc.c
    src/libFLAC/lpc_intrin_sse.c
    src/libFLAC/lpc_intrin_sse2.c
    src/libFLAC/lpc_intrin_sse41.c
    src/libFLAC/lpc_intrin_avx2.c
    src/libFLAC/md5.c
    src/libFLAC/memory.c
    src/libFLAC/metadata_iterators.c
    src/libFLAC/metadata_object.c
    src/libFLAC/stream_decoder.c
    src/libFLAC/stream_encoder.c
    src/libFLAC/stream_encoder_intrin_sse2.c
    src/libFLAC/stream_encoder_intrin_ssse3.c
    src/libFLAC/stream_encoder_intrin_avx2.c
    src/libFLAC/stream_encoder_framing.c
    src/libFLAC/window.c
    src/libFLAC/ogg_decoder_aspect.c
    src/libFLAC/ogg_encoder_aspect.c
    src/libFLAC/ogg_helper.c
    src/libFLAC/ogg_mapping.c
    )

set(LIBOGG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libogg-1.3.2)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libFLAC/include
    ${LIBOGG_DIR}/include
    ${LIBOGG_DIR}/android
    )

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS} -include android/config.h")

add_library(flac STATIC ${LIBFLAC_SRC_FILES})
target_link_libraries(flac)
