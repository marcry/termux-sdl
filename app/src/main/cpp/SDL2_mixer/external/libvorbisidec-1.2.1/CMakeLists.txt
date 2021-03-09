project(vorbisidec)

set(LIBVORBISIDEC_SRC_FILES
    mdct.c
    block.c
    window.c
    synthesis.c
    info.c
    floor1.c
    floor0.c
    vorbisfile.c
    res012.c
    mapping0.c
    registry.c
    codebook.c
    sharedbook.c
    )

#set(CMAKE_ANDROID_ARM_MODE ON)

if(CMAKE_ANDROID_ARCH STREQUAL arm)
    add_definitions(-D_ARM_ASSEM_)
endif()

set(LIBOGG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libogg-1.3.2)

include_directories(
    ${LIBOGG_DIR}/include
    ${LIBOGG_DIR}/android
    )

add_library(vorbisidec STATIC ${LIBVORBISIDEC_SRC_FILES})
target_link_libraries(vorbisidec)
