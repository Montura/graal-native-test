#pragma once

#include <string>
#include <memory>

#include "api/jni_wrapper/TimeAndSaleMapper.h"
#include "api/jni_wrapper/ListMapper.h"

namespace dxfeed {

  typedef void(SubscriptionListener)(const void* events, std::size_t count);

  struct DxFeed final {
    DxFeed(const DxFeed& other) = delete;
    DxFeed(DxFeed&& other) = delete;
    DxFeed& operator=(const DxFeed& other) = delete;
    DxFeed& operator=(DxFeed&& other) = delete;

    static DxFeed& getInstance(JNIEnv_* env);
    TimeAndSaleMapper& getTimeAndSaleMapper();
    ListMapper& getListMapper();

  private:
    DxFeed();

    JNIEnv* env_;
    TimeAndSaleMapper timeAndSalesMapper_;
    ListMapper listMapper_;

    static void onClose(jobject);
  };
}