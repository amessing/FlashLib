/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class edu_flash3388_flashlib_hal_DIOJNI */

#ifndef _Included_edu_flash3388_flashlib_hal_DIOJNI
#define _Included_edu_flash3388_flashlib_hal_DIOJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     edu_flash3388_flashlib_hal_DIOJNI
 * Method:    checkPortDigitalInput
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_edu_flash3388_flashlib_hal_DIOJNI_checkPortDigitalInput
  (JNIEnv *, jclass, jint);

/*
 * Class:     edu_flash3388_flashlib_hal_DIOJNI
 * Method:    checkPortDigitalOutput
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_edu_flash3388_flashlib_hal_DIOJNI_checkPortDigitalOutput
  (JNIEnv *, jclass, jint);

/*
 * Class:     edu_flash3388_flashlib_hal_DIOJNI
 * Method:    initializeDigitalInput
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_edu_flash3388_flashlib_hal_DIOJNI_initializeDigitalInput
  (JNIEnv *, jclass, jint);

/*
 * Class:     edu_flash3388_flashlib_hal_DIOJNI
 * Method:    initializeDigitalOutput
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_edu_flash3388_flashlib_hal_DIOJNI_initializeDigitalOutput
  (JNIEnv *, jclass, jint);

/*
 * Class:     edu_flash3388_flashlib_hal_DIOJNI
 * Method:    freeDigitalInput
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_edu_flash3388_flashlib_hal_DIOJNI_freeDigitalInput
  (JNIEnv *, jclass, jint);

/*
 * Class:     edu_flash3388_flashlib_hal_DIOJNI
 * Method:    freeDigitalOutput
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_edu_flash3388_flashlib_hal_DIOJNI_freeDigitalOutput
  (JNIEnv *, jclass, jint);

/*
 * Class:     edu_flash3388_flashlib_hal_DIOJNI
 * Method:    get
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_edu_flash3388_flashlib_hal_DIOJNI_get
  (JNIEnv *, jclass, jint);

/*
 * Class:     edu_flash3388_flashlib_hal_DIOJNI
 * Method:    set
 * Signature: (IZ)V
 */
JNIEXPORT void JNICALL Java_edu_flash3388_flashlib_hal_DIOJNI_set
  (JNIEnv *, jclass, jint, jboolean);

/*
 * Class:     edu_flash3388_flashlib_hal_DIOJNI
 * Method:    pulseOut
 * Signature: (ID)V
 */
JNIEXPORT void JNICALL Java_edu_flash3388_flashlib_hal_DIOJNI_pulseOut
  (JNIEnv *, jclass, jint, jfloat);

#ifdef __cplusplus
}
#endif
#endif
