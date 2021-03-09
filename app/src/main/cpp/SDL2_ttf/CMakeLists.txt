project(SDL2_ttf)

add_subdirectory(external/freetype-2.9.1)

set(CMAKE_C_FLAGS ${GLOBAL_C_FLAGS})

include_directories(
    ${CMAKE_SOURCE_DIR}/SDL2/include
    external/freetype-2.9.1/include
    )

add_library(SDL2_ttf SHARED SDL_ttf.c)
target_link_libraries(SDL2_ttf SDL2 freetype)
