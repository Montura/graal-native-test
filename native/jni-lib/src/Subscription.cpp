#include <jni.h>

#include "api/Subscription.h"
#include "api/DxFeed.h"

namespace dxfeed {
  const char* getEventClassType(EventType eventType) {
    switch (eventType) {
      case EventType::TimeAndSale:
        return "Lcom/dxfeed/event/market/TimeAndSale;";
    }
  }

  jobject DxFeedCApi_createSubscription(JNIEnv* env, jobject dxFeed, EventType eventType) {
    jclass dxFeedClass = env->GetObjectClass(dxFeed);
    const char* className = getEventClassType(eventType);
    jclass eventTypeClass = env->FindClass(className);
    jmethodID connectMethodId = env->GetMethodID(dxFeedClass, "createSubscription",
                                                 "(Ljava/lang/Class;)Lcom/dxfeed/api/DXFeedSubscription;");
    return env->CallObjectMethod(dxFeed, connectMethodId, eventTypeClass);
  }

  Subscription::Subscription(JNIEnv* env, jobject dxFeed, EventType eventType) :
    env_{env},
    subscription_{env->NewGlobalRef(DxFeedCApi_createSubscription(env, dxFeed, eventType))} {
  }

  jobject Subscription::getSub() {
    return subscription_;
  }

  void Subscription::addListener(Listener listener) const {
    auto& feed = dxfeed::DxFeed::getInstance();
    env_->CallStaticVoidMethod(feed.helperClass(), feed.addEventListenerMethod(),
                               subscription_, reinterpret_cast<jlong>(listener));
  }

  void Subscription::addSymbol(const std::string& symbol) const {
    jclass dxFeedSubscription = env_->GetObjectClass(subscription_);
    jmethodID addSymbolsMethodId = env_->GetMethodID(dxFeedSubscription, "addSymbols", "(Ljava/lang/Object;)V");
    jstring pSymbol = env_->NewStringUTF(symbol.c_str());
    env_->CallVoidMethod(subscription_, addSymbolsMethodId, pSymbol);
  }

  void Subscription::addDiagnosticListener(int64_t listener) const {
    auto& feed = dxfeed::DxFeed::getInstance();
    env_->CallStaticVoidMethod(feed.helperClass(), feed.addEventListenerMethod(),
                               subscription_, static_cast<jlong>(listener));
  }
}