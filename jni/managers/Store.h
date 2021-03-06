/*
 * Store.h
 *
 *  Created on: 16.01.2013
 *      Author: Denis
 */

#ifndef STORE_H_
#define STORE_H_

#include <stdlib.h>
#include <stdio.h>
#include <jni.h>

#include "log.h"

class Store {
public:
	static void init(JNIEnv* env, jobject _storeManager);

	static void saveBool(const char* name, bool value);
	static bool loadBool(const char* name, bool defValue);
	static void saveInt(const char* name, int value);
	static int loadInt(const char* name, int defValue);

private:
	static JavaVM* javaVM;
	static jobject storeManager;
	static jclass storeManagerClass;
	static jmethodID saveBoolId;
	static jmethodID loadBoolId;
	static jmethodID saveIntId;
	static jmethodID loadIntId;

	static JNIEnv* getJNIEnv(JavaVM* jvm);

};

#endif /* STORE_H_ */
