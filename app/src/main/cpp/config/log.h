#ifndef __LOG_H__
#define __LOG_H__

// for android log 
#include <android/log.h>

// default enable debug
#define DEBUG 1

// Log.d(TAG, ...)
#define LOGD(TAG, ...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__) 
 
// Log.f(TAG, ...)
#define LOGF(TAG, ...) __android_log_print(ANDROID_LOG_FATAL, TAG, __VA_ARGS__) 

// Log.i(TAG, ...)
#define LOGI(TAG, fmt, ...) \
    do { \
        if(DEBUG) { \
            __android_log_print(ANDROID_LOG_INFO, TAG, \
            "[%s:%d (%s)]\e[0;35m " fmt, \
            __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);\
        } \
    } while(0)

    
    
// Log.w(TAG, ...)
#define LOGW(TAG, fmt, ...) \
    do { \
        __android_log_print(ANDROID_LOG_WARN, TAG, \
        "[%s:%d (%s)] " fmt, \
        __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);\
    } while(0)
    
    
    
// Log.e(TAG, ...)
#define LOGE(TAG, fmt, ...) \
    do { \
        __android_log_print(ANDROID_LOG_ERROR, TAG, \
        "[%s:%d (%s)] " fmt, \
        __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);\
    } while(0)
    
#endif // __LOG_H__ 
