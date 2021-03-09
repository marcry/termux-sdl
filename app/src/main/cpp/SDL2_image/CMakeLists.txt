project(SDL2_image)

add_subdirectory(external/jpeg-9b)
add_subdirectory(external/libpng-1.6.37)
add_subdirectory(external/libwebp-1.0.2)

set(LIBSDL2_IMAGE_SRC_FILES
    IMG.c           
    IMG_bmp.c       
    IMG_gif.c       
    IMG_jpg.c       
    IMG_lbm.c       
    IMG_pcx.c       
    IMG_png.c       
    IMG_pnm.c       
    IMG_svg.c       
    IMG_tga.c       
    IMG_tif.c       
    IMG_webp.c      
    IMG_WIC.c       
    IMG_xcf.c       
    IMG_xpm.c
    IMG_xv.c
    IMG_xxx.c
    )
    
set(CMAKE_C_FLAGS ${GLOBAL_C_FLAGS})

add_definitions(
    -DLOAD_BMP 
    -DLOAD_GIF 
    -DLOAD_LBM 
    -DLOAD_PCX 
    -DLOAD_PNM 
    -DLOAD_SVG 
    -DLOAD_TGA 
    -DLOAD_XCF 
    -DLOAD_XPM 
    -DLOAD_XV 
    -DLOAD_JPG
    -DLOAD_PNG
    -DLOAD_WEBP
    )

include_directories(
    ${CMAKE_SOURCE_DIR}/SDL2/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/libwebp-1.0.2/src
    ${CMAKE_CURRENT_SOURCE_DIR}/external/libpng-1.6.37
    ${CMAKE_CURRENT_SOURCE_DIR}/external/jpeg-9b
    )

add_library(SDL2_image SHARED ${LIBSDL2_IMAGE_SRC_FILES})
target_link_libraries(SDL2_image
    SDL2
    jpeg
    png
    webp
    webpdecoder
    z
    )

