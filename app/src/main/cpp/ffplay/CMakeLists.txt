project(ffplay)

include_directories(
    ${CMAKE_SOURCE_DIR}/ffplay/include
    ${CMAKE_SOURCE_DIR}/SDL2/include
    ${CMAKE_SOURCE_DIR}/config
    ${CMAKE_SOURCE_DIR}/SDL2_ttf
    ${CMAKE_SOURCE_DIR}/SDL2_gfx
    )

link_directories(
    ${CMAKE_SOURCE_DIR}/ffplay/lib/static
    )

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS}")

add_library(ffplay SHARED cmdutils.c ffplay.c)

target_link_libraries(ffplay
    avformat 
    avdevice 
    avfilter 
    avcodec 
    swresample 
    swscale 
    avutil 
    postproc
    SDL2
    SDL2_ttf
    SDL2_gfx
    GLESv1_CM
    camera2ndk
    mediandk
    z
    log
    )

