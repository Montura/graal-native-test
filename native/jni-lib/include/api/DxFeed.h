#pragma once

#include <string>
#include <memory>

#include "api/jni_wrapper/TimeAndSaleMapper.h"
#include "api/jni_wrapper/ListMapper.h"

extern "C" JNIEXPORT void JNICALL Java_com_dxfeed_api_JniTest_nOnQuoteEventListener(JNIEnv* env, jclass,
            jint size, jbyteArray eventList, jdoubleArray jDoubleData, jlong userCallback);

namespace dxfeed {
  struct Connection; // forward declaration

  extern JNIEnv* jniEnv;
  extern JavaVM* javaVM;

  static JNINativeMethod methods[] = {
    {"nOnQuoteEventListener", "(I[B[DJ)V", (void*) &Java_com_dxfeed_api_JniTest_nOnQuoteEventListener },
  };

  struct DxFeed final {
    static void initJavaVM(const char* javaHome);
    DxFeed(const DxFeed& other) = delete;
    DxFeed(DxFeed&& other) = delete;
    DxFeed& operator=(const DxFeed& other) = delete;
    DxFeed& operator=(DxFeed&& other) = delete;

    static DxFeed& getInstance();
    const TimeAndSaleMapper& getTimeAndSaleMapper();
    const ListMapper& getListMapper();
    jclass helperClass();
    jmethodID addEventListenerMethod();

    Connection* createConnection(const std::string &address);
  private:
    DxFeed();

    JNIEnv* env_;
    TimeAndSaleMapper timeAndSalesMapper_;
    const ListMapper listMapper_;
    jclass javaHelperClass;
    jmethodID addEventListenerHelperMethodId;

    static void onClose(jobject);
  };
}