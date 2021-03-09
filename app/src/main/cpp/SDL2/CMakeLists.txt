project(SDL2)

aux_source_directory(src LIBSDL2_SRC_FILES)
aux_source_directory(src/audio LIBSDL2_SRC_FILES)
aux_source_directory(src/audio/android LIBSDL2_SRC_FILES)
aux_source_directory(src/audio/dummy LIBSDL2_SRC_FILES)
aux_source_directory(src/audio/openslES LIBSDL2_SRC_FILES)
aux_source_directory(src/core/android LIBSDL2_SRC_FILES)
aux_source_directory(src/cpuinfo LIBSDL2_SRC_FILES)
aux_source_directory(src/dynapi LIBSDL2_SRC_FILES)
aux_source_directory(src/events LIBSDL2_SRC_FILES)

aux_source_directory(src/file LIBSDL2_SRC_FILES)
aux_source_directory(src/haptic LIBSDL2_SRC_FILES)
aux_source_directory(src/haptic/android LIBSDL2_SRC_FILES)
aux_source_directory(src/joystick LIBSDL2_SRC_FILES)
aux_source_directory(src/joystick/android LIBSDL2_SRC_FILES)
aux_source_directory(src/joystick/hidapi LIBSDL2_SRC_FILES)
aux_source_directory(src/loadso/dlopen LIBSDL2_SRC_FILES)
aux_source_directory(src/power LIBSDL2_SRC_FILES)
aux_source_directory(src/power/android LIBSDL2_SRC_FILES)
aux_source_directory(src/filesystem/android LIBSDL2_SRC_FILES)
aux_source_directory(src/sensor LIBSDL2_SRC_FILES)
aux_source_directory(src/sensor/android LIBSDL2_SRC_FILES)

aux_source_directory(src/render LIBSDL2_SRC_FILES)
aux_source_directory(src/render/direct3d LIBSDL2_SRC_FILES)
aux_source_directory(src/render/direct3d11 LIBSDL2_SRC_FILES)
aux_source_directory(src/render/metal LIBSDL2_SRC_FILES)
aux_source_directory(src/render/opengl LIBSDL2_SRC_FILES)
aux_source_directory(src/render/opengles LIBSDL2_SRC_FILES)
aux_source_directory(src/render/opengles2 LIBSDL2_SRC_FILES)
aux_source_directory(src/render/psp LIBSDL2_SRC_FILES)
aux_source_directory(src/render/software LIBSDL2_SRC_FILES)

aux_source_directory(src/stdlib LIBSDL2_SRC_FILES)
aux_source_directory(src/thread LIBSDL2_SRC_FILES)
aux_source_directory(src/thread/pthread LIBSDL2_SRC_FILES)
aux_source_directory(src/timer LIBSDL2_SRC_FILES)
aux_source_directory(src/timer/unix LIBSDL2_SRC_FILES)
aux_source_directory(src/video LIBSDL2_SRC_FILES)
aux_source_directory(src/video/android LIBSDL2_SRC_FILES)
aux_source_directory(src/video/yuv2rgb LIBSDL2_SRC_FILES)
aux_source_directory(src/atomic LIBSDL2_SRC_FILES)
aux_source_directory(src/test LIBSDL2_SRC_FILES)


set(CMAKE_C_FLAGS " \
    ${GLOBAL_C_FLAGS} \
    -Wextra \
	-Wdocumentation \
	-Wdocumentation-unknown-command \
	-Wmissing-prototypes \
	-Wunreachable-code-break \
	-Wunneeded-internal-declaration \
	-Wmissing-variable-declarations \
	-Wfloat-conversion \
	-Wshorten-64-to-32 \
	-Wunreachable-code-return \
	-Wshift-sign-overflow \
	-Wstrict-prototypes \
	-Wkeyword-macro \
	")

add_definitions(-DGL_GLEXT_PROTOTYPES)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

add_library(cpufeatures STATIC ${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c)

add_library(hidapi SHARED src/hidapi/android/hid.cpp)
target_link_libraries(hidapi log)

add_library(SDL2 SHARED ${LIBSDL2_SRC_FILES})
target_link_libraries(SDL2
    cpufeatures
    hidapi
    GLESv1_CM 
    GLESv2
    OpenSLES
    android
    dl
    log
    )
