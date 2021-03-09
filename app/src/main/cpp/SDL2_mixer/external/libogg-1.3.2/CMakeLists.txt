project(ogg)

set(LIBOGG_SRC_FILES
    src/framing.c 
    src/bitwise.c
    )

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/android
    )

add_library(ogg STATIC ${LIBOGG_SRC_FILES})
target_link_libraries(ogg)
