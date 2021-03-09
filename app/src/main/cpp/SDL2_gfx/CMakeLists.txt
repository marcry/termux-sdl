project(SDL2_gfx)

set(LIBSDL2_GFX_SRC_FILES
    SDL2_framerate.c
    SDL2_gfxPrimitives.c
    SDL2_imageFilter.c
    SDL2_rotozoom.c
    )

include_directories(
    ${CMAKE_SOURCE_DIR}/SDL2/include
    )

set(CMAKE_C_FLAGS ${GLOBAL_C_FLAGS})

add_library(SDL2_gfx SHARED ${LIBSDL2_GFX_SRC_FILES})
target_link_libraries(SDL2_gfx
    SDL2
    GLESv1_CM
    log
    )
