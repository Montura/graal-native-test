#pragma once

#include <jni.h>
#include <string>
#include <vector>

#include "EventTypes.h"

namespace dxfeed {
  struct Subscription final {
    typedef void(Listener)(const void* events, std::size_t count);

    Subscription(JNIEnv* env, jobject connection, EventType eventType);
    Subscription(const Subscription& other) = delete;
    Subscription(Subscription&& other) = delete;
    Subscription& operator=(const Subscription& other) = delete;
    Subscription& operator=(Subscription&& other) = delete;

//    void addListener(Listener listener) const;
//    void addSymbol(const std::string& symbol) const;
//    void addSymbols(const std::vector <std::string>& symbols) const;
    jobject getSub();

  private:
    jobject subscription_;
    JNIEnv* env_;
  };
}