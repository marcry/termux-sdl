#/bin/bash

NDK_TOOLCHAIN=$HOME/android/android-ndk-r22/toolchains/llvm/prebuilt/linux-aarch64

ANDROID_API=21

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
        --arch=arm64 \
        --cpu=armv8-a \
        --prefix=$HOME/ffmpeg \
        --disable-ffmpeg \
        --disable-ffplay \
        --disable-ffprobe \
        --disable-doc \
        --disable-symver \
        --disable-debug \
        --enable-gpl \
        --enable-small \
        --enable-neon \
        --enable-nonfree \
        --enable-mediacodec \
        --enable-decoder=h264_mediacodec \
        --enable-pic \
        --enable-jni \
        --enable-cross-compile \
        --target-os=android \
        --cross-prefix=$CROSS_PREFIX \
        --sysroot=$SYSROOT \
        --extra-cflags="-Os -fpic -march=armv8-a" \
        $BUILD_CONFIG
}

# static or shared
build_ffmpeg_android "static"

