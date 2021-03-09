project(native_loader)

set(CMAKE_CXX_FLAGS ${GLOBAL_CXX_FLAGS})

include_directories(
    ${CMAKE_SOURCE_DIR}/config
    ${ANDROID_NDK}/sources/android/native_app_glue
    )

add_library(glue STATIC ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

add_library(native_loader SHARED native_loader.cpp)
target_link_libraries(native_loader 
    glue
    android
    log
    )
