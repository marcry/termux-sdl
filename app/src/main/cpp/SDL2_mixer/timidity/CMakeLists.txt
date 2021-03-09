project(timidity)

set(LIBTIMIDITY_SRC_FILES
    common.c 
    instrum.c 
    mix.c 
    output.c 
    playmidi.c
    readmidi.c 
    resample.c
    tables.c
    timidity.c
    )

include_directories(
    ${CMAKE_SOURCE_DIR}/SDL2/include
    )

add_library(timidity STATIC ${LIBTIMIDITY_SRC_FILES})
target_link_libraries(timidity)

