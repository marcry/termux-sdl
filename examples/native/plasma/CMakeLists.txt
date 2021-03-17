cmake_minimum_required(VERSION 3.14.2)

project(plasma)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/../../include
    )

link_directories(
    ${CMAKE_SOURCE_DIR}/../../lib
    )

add_definitions(
    -D__ANDROID__
    -DANDROID
    )

set(CMAKE_C_FLAGS " \
    -Os \
    -Wall \
    -fPIC \
    -std=c11 \
    -Wno-unused \
    -Wno-unused-parameter \
    -fcolor-diagnostics \
    ")
    
set(CMAKE_SHARED_LINKER_FLAGS " \
     -Wl,--no-undefined \
     -Wl,-z,noexecstack \
    ")

# the library name is PROJECT_NAME
add_library(${PROJECT_NAME} SHARED 
    plasma.c
    android_native_app_glue.c
    )
target_link_libraries(${PROJECT_NAME} 
    android
    EGL 
    GLESv1_CM 
    m
    log
    )

# am start -S $(shell am 2>&1 | grep -q '\-\-user' && echo '--user 0') -n com.termux.sdl/.TermuxNativeActivity -e nativeApp /path/to/libxxx.so
# add custom target for make run
add_custom_target(run
    COMMAND am start -S \$\(shell am 2>&1 | grep -q '\\-\\-user' && echo '--user 0'\) -n com.termux.sdl/.TermuxNativeActivity -e nativeApp ${CMAKE_BINARY_DIR}/lib${PROJECT_NAME}.so
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS ${PROJECT_NAME}
    COMMENT "start running native app program ${PROJECT_NAME}"
    )
