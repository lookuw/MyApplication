#include "kuan_com_myapplication_EventReader.h"
/* 
 * Class:     com_jnimobile_www_myjnidemo_MainActivity 
 * Method:    getStringFromNative 
 * Signature: ()Ljava/lang/String; 
 */
JNIEXPORT jstring JNICALL Java_kuan_com_myapplication_EventReader_getEventFromInput
        (JNIEnv * env, jobject obj){
    return (*env)->NewStringUTF(env,"I'm comes from to Native Function!");
}