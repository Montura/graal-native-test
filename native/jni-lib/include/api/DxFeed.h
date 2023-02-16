#pragma once

#include <string>
#include <memory>

#include "api/jni_wrapper/TimeAndSaleMapper.h"
#include "api/jni_wrapper/ListMapper.h"

namespace dxfeed {
  struct Connection; // forward declaration

  extern JNIEnv* jniEnv;
  extern JavaVM* javaVM;

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

    static void loadVm(const char*);
    void loadLibrary(const char* path);

    JNIEnv* env_;
    const TimeAndSaleMapper timeAndSalesMapper_;
    const ListMapper listMapper_;
    jclass javaHelperClass;
    jmethodID addEventListenerHelperMethodId;

    static void onClose(jobject);
  };
}