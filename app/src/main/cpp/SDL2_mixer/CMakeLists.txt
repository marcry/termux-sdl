project(SDL2_mixer)

add_subdirectory(timidity)
add_subdirectory(external/flac-1.3.2)
add_subdirectory(external/libogg-1.3.2)
add_subdirectory(external/libmodplug-0.8.9.0)
add_subdirectory(external/mpg123-1.25.6)
add_subdirectory(external/libvorbisidec-1.2.1)

aux_source_directory(. LIBSDL2_MIXER_SRC_FILES)

# exclude playmus.c playwave.c
# list(REMOVE_ITEM <list> <value> [<value> ...])
# list(FILTER <list> <INCLUDE|EXCLUDE> REGEX <regular_expression>)
list(FILTER LIBSDL2_MIXER_SRC_FILES EXCLUDE REGEX ".*playmus.c$|.*playwave.c$")

set(CMAKE_C_FLAGS ${GLOBAL_C_FLAGS})

include_directories(
    ${CMAKE_SOURCE_DIR}/SDL2/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/libmodplug-0.8.9.0/src
    ${CMAKE_CURRENT_SOURCE_DIR}/external/flac-1.3.2/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/libogg-1.3.2/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/libogg-1.3.2/android
    ${CMAKE_CURRENT_SOURCE_DIR}/external/mpg123-1.25.6/android
    ${CMAKE_CURRENT_SOURCE_DIR}/external/mpg123-1.25.6/src
    ${CMAKE_CURRENT_SOURCE_DIR}/external/mpg123-1.25.6/src/compat
    ${CMAKE_CURRENT_SOURCE_DIR}/external/mpg123-1.25.6/src/libmpg123
    ${CMAKE_CURRENT_SOURCE_DIR}/external/libvorbisidec-1.2.1
    )

add_definitions(
    -DMUSIC_FLAC
    -DMUSIC_OGG -DOGG_USE_TREMOR -DOGG_HEADER="ivorbisfile.h"
    -DMUSIC_MP3_MPG123
    -DMUSIC_MOD_MODPLUG -DMODPLUG_HEADER="modplug.h"
    -DMUSIC_MID_TIMIDITY
    )

add_library(SDL2_mixer SHARED ${LIBSDL2_MIXER_SRC_FILES})
target_link_libraries(SDL2_mixer
    flac
    vorbisidec
    mpg123
    modplug
    ogg
    timidity
    SDL2
    )
