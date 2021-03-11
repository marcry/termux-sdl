#/bin/bash

NDK_TOOLCHAIN=$HOME/android/android-ndk-r22/toolchains/llvm/prebuilt/linux-aarch64

ANDROID_API=24

CC=$NDK_TOOLCHAIN/bin/aarch64-linux-android$ANDROID_API-clang
CXX=$NDK_TOOLCHAIN/bin/aarch64-linux-android$ANDROID_API-clang++

CROSS_PREFIX=$NDK_TOOLCHAIN/bin/aarch64-linux-android-
SYSROOT=$NDK_TOOLCHAIN/sysroot

function build_ffmpeg_android() {
    
    BUILD_LIB_TYPE=$@

    # dangerous relocation: unsupported relocation R_AARCH64_ADR_PREL_PG_HI21 against symbol... 
    # add --disable-asm disable all assembly optimizations for android static link 
    if [ $BUILD_LIB_TYPE == "static" ];then
        BUILD_CONFIG='--enable-static --disable-shared --disable-asm'
    else
        BUILD_CONFIG='--enable-shared --disable-static'
    fi

    ../configure \
        --cc=$CC \
        --cxx=$CXX \
        --arch=aarch64 \
        --cpu=armv8-a \
        --prefix=$HOME/ffmpeg \
        --disable-doc \
        --disable-symver \
        --disable-debug \
        --enable-indev=lavfi \
        --enable-gpl \
        --enable-small \
        --enable-neon \
        --enable-nonfree \
        --enable-mediacodec \
        --enable-decoder=h264_mediacodec \
        --enable-pic \
        --enable-jni \
        --enable-cross-compile \
        --cross-prefix=$CROSS_PREFIX \
        --sysroot=$SYSROOT \
        --extra-cflags="-Os -fPIC -march=armv8-a" \
        --target-os=android \
        $BUILD_CONFIG
    
    make install -j16
}

# static or shared
build_ffmpeg_android "static"

