#pragma once

#include <string>
#include <memory>

#include "api/jni_wrapper/TimeAndSaleMapper.h"
#include "api/jni_wrapper/ListMapper.h"

namespace dxfeed {
  struct Connection; // forward declaration

  struct DxFeed final {
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
    void loadLibrary(const char* path);

    JNIEnv* env_;
    const TimeAndSaleMapper timeAndSalesMapper_;
    const ListMapper listMapper_;
    jclass javaHelperClass;
    jmethodID addEventListenerHelperMethodId;

    static void onClose(jobject);
  };
}