project(libwebp)

set(CMAKE_ANDROID_ARM_MODE ON)

set(CFLAGS " \
     -DANDROID  \
     -DHAVE_MALLOC_H \
     -DHAVE_PTHREAD \
     -DWEBP_USE_THREAD \
     -fvisibility=hidden \
    ")
    
if(CMAKE_BUILD_TYPE STREQUAL Release)
    set(CFLAGS " \
    ${CFLAGS} \
    -finline-functions \
    -ffast-math \
    -ffunction-sections \
    -fdata-sections \
    -frename-registers -s \
    ")
endif()

if(ANDROID_ABI STREQUAL "armeabi-v7a")
    set(NEON c.neon)
    add_definitions(-DHAVE_CPU_FEATURES_H)
else()
    set(NEON c)
endif()

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS} ${CFLAGS}")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

set(dec_srcs
    src/dec/alpha_dec.c
    src/dec/buffer_dec.c
    src/dec/frame_dec.c
    src/dec/idec_dec.c
    src/dec/io_dec.c
    src/dec/quant_dec.c
    src/dec/tree_dec.c
    src/dec/vp8_dec.c
    src/dec/vp8l_dec.c
    src/dec/webp_dec.c
    )

set(demux_srcs
    src/demux/anim_decode.c
    src/demux/demux.c
    )

set(dsp_dec_srcs
    src/dsp/alpha_processing.c
    src/dsp/alpha_processing_mips_dsp_r2.c
    src/dsp/alpha_processing_neon.${NEON}
    src/dsp/alpha_processing_sse2.c
    src/dsp/alpha_processing_sse41.c
    src/dsp/cpu.c
    src/dsp/dec.c
    src/dsp/dec_clip_tables.c
    src/dsp/dec_mips32.c
    src/dsp/dec_mips_dsp_r2.c
    src/dsp/dec_msa.c
    src/dsp/dec_neon.${NEON}
    src/dsp/dec_sse2.c
    src/dsp/dec_sse41.c
    src/dsp/filters.c
    src/dsp/filters_mips_dsp_r2.c
    src/dsp/filters_msa.c
    src/dsp/filters_neon.${NEON}
    src/dsp/filters_sse2.c
    src/dsp/lossless.c
    src/dsp/lossless_mips_dsp_r2.c
    src/dsp/lossless_msa.c
    src/dsp/lossless_neon.${NEON}
    src/dsp/lossless_sse2.c
    src/dsp/rescaler.c
    src/dsp/rescaler_mips32.c
    src/dsp/rescaler_mips_dsp_r2.c
    src/dsp/rescaler_msa.c
    src/dsp/rescaler_neon.${NEON}
    src/dsp/rescaler_sse2.c
    src/dsp/upsampling.c
    src/dsp/upsampling_mips_dsp_r2.c
    src/dsp/upsampling_msa.c
    src/dsp/upsampling_neon.${NEON}
    src/dsp/upsampling_sse2.c
    src/dsp/upsampling_sse41.c
    src/dsp/yuv.c
    src/dsp/yuv_mips32.c
    src/dsp/yuv_mips_dsp_r2.c
    src/dsp/yuv_neon.${NEON}
    src/dsp/yuv_sse2.c
    src/dsp/yuv_sse41.c
    )

set(dsp_enc_srcs
    src/dsp/cost.c
    src/dsp/cost_mips32.c
    src/dsp/cost_mips_dsp_r2.c
    src/dsp/cost_neon.${NEON}
    src/dsp/cost_sse2.c
    src/dsp/enc.c
    src/dsp/enc_mips32.c
    src/dsp/enc_mips_dsp_r2.c
    src/dsp/enc_msa.c
    src/dsp/enc_neon.${NEON}
    src/dsp/enc_sse2.c
    src/dsp/enc_sse41.c
    src/dsp/lossless_enc.c
    src/dsp/lossless_enc_mips32.c
    src/dsp/lossless_enc_mips_dsp_r2.c
    src/dsp/lossless_enc_msa.c
    src/dsp/lossless_enc_neon.${NEON}
    src/dsp/lossless_enc_sse2.c
    src/dsp/lossless_enc_sse41.c
    src/dsp/ssim.c
    src/dsp/ssim_sse2.c
    )

set(enc_srcs
    src/enc/alpha_enc.c
    src/enc/analysis_enc.c
    src/enc/backward_references_cost_enc.c
    src/enc/backward_references_enc.c
    src/enc/config_enc.c
    src/enc/cost_enc.c
    src/enc/filter_enc.c
    src/enc/frame_enc.c
    src/enc/histogram_enc.c
    src/enc/iterator_enc.c
    src/enc/near_lossless_enc.c
    src/enc/picture_enc.c
    src/enc/picture_csp_enc.c
    src/enc/picture_psnr_enc.c
    src/enc/picture_rescale_enc.c
    src/enc/picture_tools_enc.c
    src/enc/predictor_enc.c
    src/enc/quant_enc.c
    src/enc/syntax_enc.c
    src/enc/token_enc.c
    src/enc/tree_enc.c
    src/enc/vp8l_enc.c
    src/enc/webp_enc.c
    )

set(mux_srcs
    src/mux/anim_encode.c
    src/mux/muxedit.c
    src/mux/muxinternal.c
    src/mux/muxread.c
    )

set(utils_dec_srcs
    src/utils/bit_reader_utils.c
    src/utils/color_cache_utils.c
    src/utils/filters_utils.c
    src/utils/huffman_utils.c
    src/utils/quant_levels_dec_utils.c
    src/utils/random_utils.c
    src/utils/rescaler_utils.c
    src/utils/thread_utils.c
    src/utils/utils.c
    )

set(utils_enc_srcs
    src/utils/bit_writer_utils.c
    src/utils/huffman_encode_utils.c
    src/utils/quant_levels_utils.c
    )

add_library(webpdecoder STATIC 
    ${dec_srcs}
    ${dsp_dec_srcs}
    ${utils_dec_srcs}
    )
target_link_libraries(webpdecoder)

add_library(webp STATIC 
    ${dsp_enc_srcs}
    ${enc_srcs}
    ${utils_enc_srcs}
    )
target_link_libraries(webp)

add_library(webpdemux STATIC ${demux_srcs})
target_link_libraries(webpdemux)

add_library(webpmux STATIC ${mux_srcs})
target_link_libraries(webpmux)


