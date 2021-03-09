project(jpeg-9b)

set(CMAKE_ANDROID_ARM_MODE ON)

set(LIBJPEG_SRC_FILES
    jaricom.c jcapimin.c jcapistd.c 
    jcarith.c jccoefct.c jccolor.c 
    jcdctmgr.c jchuff.c jcinit.c 
    jcmainct.c jcmarker.c jcmaster.c 
    jcomapi.c jcparam.c jcprepct.c 
    jcsample.c jctrans.c jdapimin.c 
    jdapistd.c jdarith.c jdatadst.c 
    jdatasrc.c jdcoefct.c jdcolor.c 
    jddctmgr.c jdhuff.c jdinput.c 
    jdmainct.c jdmarker.c jdmaster.c 
    jdmerge.c jdpostct.c jdsample.c 
    jdtrans.c jerror.c jfdctflt.c 
    jfdctfst.c jfdctint.c jidctflt.c jquant1.c 
    jquant2.c jutils.c jmemmgr.c 
	jmem-android.c
    )

add_definitions(-DAVOID_TABLES)

list(APPEND LIBJPEG_SRC_FILES jidctint.c)
if(ANDROID_ARM_MODE STREQUAL "arm")
    list(APPEND LIBJPEG_SRC_FILES jidctfst.S)
else()
    list(APPEND LIBJPEG_SRC_FILES jidctfst.c)
endif()

set(CMAKE_C_FLAGS " \
    ${GLOBAL_C_FLAGS} \
    -O3 \
    -fstrict-aliasing \
    -fprefetch-loop-arrays \
    ")

add_library(jpeg STATIC ${LIBJPEG_SRC_FILES})
target_link_libraries(jpeg)
