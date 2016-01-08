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
#include <pthread.h>
#define LOG_TAG "jni"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
/* 
 * Class:     com_jnimobile_www_myjnidemo_MainActivity 
 * Method:    getStringFromNative 
 * Signature: ()Ljava/lang/String; 
 */
void thread(void)
{
    int i;
//    for(i=0;i<3;i++)
        printf("This is a pthread.\n");

    int fd;
    int time;
    unsigned char buf[13];
    struct timeval tv;

    fd = open("/dev/input/event2", O_RDONLY);

    if(!fd){
        printf("Failed to open \"/dev/input/js1\"\n");
    }else{
        LOGI("xxx=%d",fd);
    }

    time = 1;

    while(time<20){
        time++;
        read(fd, buf, 12);
        LOGI("Button type = %d, X = %d, Y = %d\n", (buf[0] & 0x07), buf[1], buf[2]);
        sleep(1);
    }
    if(fd>0){
        close(fd);
    }
}

JNIEXPORT jstring JNICALL Java_kuan_com_myapplication_EventReader_getEventFromInput
        (JNIEnv * env, jobject obj){
//    int xx;
//    xx = open("/dev/input/event2",O_RDWR);
//    LOGI("xxx=%d",xx);
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




//#include <stdlib.h>
//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <sys/select.h>
//#include <sys/time.h>


//        int fd, retval;
//        int time;
//        unsigned char buf[13];
//        fd_set readfds;
//        struct timeval tv;
//
//        fd = open("/dev/input/event2", O_RDONLY);
//
//        if(!fd)
//        {
//            printf("Failed to open \"/dev/input/js1\"\n");
//            return -1;
//        }else{
//            LOGI("xxx=%d",fd);
//        }
//
//    time = 1;
//
//    while(time<100){
//        time++;
//        read(fd, buf, 12);
//        LOGI("Button type = %d, X = %d, Y = %d\n", (buf[0] & 0x07), buf[1], buf[2]);
//        sleep(1);
//    }





//    pthread_t id;
//    int i,ret;
//    ret=pthread_create(&id,NULL,(void *) thread,NULL);
//    if(ret!=0){
//        printf ("Create pthread error!\n");
////        exit (1);
//    }
////    for(i=0;i<3;i++)
//    printf("This is the main process.\n");
//    pthread_join(id,NULL);




//        while(1)
//        {
//            FD_ZERO(&readfds);
//            FD_SET(fd, &readfds);
//            tv.tv_sec = 5;
//            tv.tv_usec = 0;
//            if((retval = select(fd+1, &readfds, NULL, NULL, &tv)) == 1)
//            {
//                if(read(fd, buf, 12) <= 0)
//                {
//                    //printf("read fail ... \n");
//                    continue;
//                }
//                //printf("Button type = %d, X = %d, Y = %d\n", (buf[0] & 0x07), buf[1], buf[2]);
//                printf("0x%02x 0x%02x 0x%02x 0x%02x   0x%02x 0x%02x 0x%02x 0x%02x   0x%02x 0x%02x 0x%02x 0x%02x \n",
//                       buf[0], buf[1], buf[2],buf[3],buf[4], buf[5], buf[6],buf[7],buf[8], buf[9], buf[10],buf[11]);
//                //sleep(1);
//            }
//        }
//    if(fd>0){
//        close(fd);
//    }

    return (*env)->NewStringUTF(env,"I'm comes from to Native Function! in mac");
}

JNIEXPORT void JNICALL Java_kuan_com_myapplication_EventReader_showEvent
        (JNIEnv * env, jobject obj){
    int fd;
    unsigned char buf[13];

    fd = open("/dev/input/event2", O_RDONLY);

    if(!fd){
        printf("Failed to open \"/dev/input/js1\"\n");
    }else{
        LOGI("xxx=%d",fd);
        read(fd, buf, 12);
        LOGI("Button type = %d, X = %d, Y = %d\n", (buf[0] & 0x07), buf[1], buf[2]);
        close(fd);
    }
}