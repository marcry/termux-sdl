#!/bin/bash

$HOME/android/android-ndk-r22/toolchains/llvm/prebuilt/linux-aarch64/bin/aarch64-linux-android21-clang -pie -fpic -shared -Wl,--whole-archive *.a -Wl,--no-whole-archive -o libffmpeg.so
