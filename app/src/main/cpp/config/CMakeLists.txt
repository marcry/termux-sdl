project(config)

include_directories(
    ${CMAKE_SOURCE_DIR}/SDL2/include
    ${CMAKE_SOURCE_DIR}/SDL2_image
    ${CMAKE_SOURCE_DIR}/SDL2_mixer
    ${CMAKE_SOURCE_DIR}/SDL2_net
    ${CMAKE_SOURCE_DIR}/SDL2_ttf
    ${CMAKE_SOURCE_DIR}/SDL2_gfx
    ${CMAKE_SOURCE_DIR}/ffplay/include/libavutil
    )

add_library(config SHARED config.cpp)
target_link_libraries(config 
    SDL2 
    SDL2_image 
    SDL2_mixer 
    SDL2_net 
    SDL2_ttf 
    SDL2_gfx
    z
    log
    )
