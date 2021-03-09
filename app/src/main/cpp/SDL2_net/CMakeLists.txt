project(SDL2_net)

set(LIBSDL2_NET_SRC_FILES
    SDLnet.c 
    SDLnetTCP.c 
    SDLnetUDP.c 
    SDLnetselect.c
    )

include_directories(
    ${CMAKE_SOURCE_DIR}/SDL2/include
    )

set(CMAKE_C_FLAGS ${GLOBAL_C_FLAGS})

add_library(SDL2_net SHARED ${LIBSDL2_NET_SRC_FILES})
target_link_libraries(SDL2_net SDL2)
