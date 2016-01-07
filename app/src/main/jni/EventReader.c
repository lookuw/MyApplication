#include "kuan_com_myapplication_EventReader.h"
#include <string.h>
#include <jni.h>
#include <stdint.h>
#include <linux/input.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <android/log.h>
#define LOG_TAG "jni"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
/* 
 * Class:     com_jnimobile_www_myjnidemo_MainActivity 
 * Method:    getStringFromNative 
 * Signature: ()Ljava/lang/String; 
 */
JNIEXPORT jstring JNICALL Java_kuan_com_myapplication_EventReader_getEventFromInput
        (JNIEnv * env, jobject obj){
    int xx;
    xx = open("/dev/input/event2",O_RDWR);
//	LOGI("hello world=%d",xx);
    LOGI("xxx=%d",xx);
//	xx=open("/dev/input/event2", O_RDWR);
//	debug("xx="+xx);
//	 int fd_kb, aux;
//	 char szDev ="/dev/input/event0";
//	    fd_kb = open(szDev, O_RDWR);
//	    if (fd_kb < 0){
//		        debug("Can't open input device:%s(%d)", szDev,fd_kb);
//		        // Leo: Can't open input device:/dev/input/event0(-1)
//		        return -1;
//		    }else{
//			  debug("Can open input device:%s(%d)", szDev,fd_kb);
//		}


    return (*env)->NewStringUTF(env,"I'm comes from to Native Function!");
}