cmake_minimum_required(VERSION 3.14.2)

project(CXX)

enable_language(ASM)

set(GLOBAL_C_FLAGS " \
    -std=c11 \
    -fPIC \
    -Wall \
    -Wno-unused \
    -Wno-unused-parameter \
    -Wno-sign-compare \
    -fcolor-diagnostics \
    -Wno-unused-command-line-argument \
    ")

set(GLOBAL_CXX_FLAGS " \
    -std=c++11 \
    -fPIC \
    -Wall \
    -Wno-unused \
    -Wno-unused-parameter \
    -Wno-sign-compare \
    -fcolor-diagnostics \
    -Wno-unused-command-line-argument \
    ")

add_definitions(-D__ANDROID__)

add_subdirectory(SDL2)
add_subdirectory(SDL2_image)
add_subdirectory(SDL2_ttf)
add_subdirectory(SDL2_gfx)
add_subdirectory(SDL2_net)
add_subdirectory(SDL2_mixer)
add_subdirectory(main)
add_subdirectory(config)
add_subdirectory(ffplay)
add_subdirectory(native_loader)


