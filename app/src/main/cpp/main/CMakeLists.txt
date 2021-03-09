project(main)

set(CMAKE_C_FLAGS ${GLOBAL_C_FLAGS})

include_directories(
    ${CMAKE_SOURCE_DIR}/SDL2/include
    )

add_library(main SHARED testgles.c)

target_link_libraries(main 
    SDL2
    GLESv1_CM
    z
    log
    )
