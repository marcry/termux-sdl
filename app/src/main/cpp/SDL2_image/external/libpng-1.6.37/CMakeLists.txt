project(libpng)

set(LIBPNG_SRC_FILES
    png.c 
    pngerror.c
	pngget.c 
    pngmem.c 
    pngpread.c 
    pngread.c 
    pngrio.c 
    pngrtran.c 
    pngrutil.c
	pngset.c 
    pngtrans.c 
    pngwio.c 
    pngwrite.c 
    pngwtran.c 
    pngwutil.c
    )

if(ANDROID_ABI STREQUAL "armeabi" OR ANDROID_ABI STREQUAL "armeabi-v7a" OR ANDROID_ABI STREQUAL "arm64-v8a")
    list(APPEND LIBPNG_SRC_FILES
    arm/arm_init.c 
    arm/filter_neon.S 
    arm/filter_neon_intrinsics.c 
    arm/palette_neon_intrinsics.c
    )
endif()

set(CMAKE_C_FLAGS ${GLOBAL_C_FLAGS})

add_library(png STATIC ${LIBPNG_SRC_FILES})
target_link_libraries(png)
