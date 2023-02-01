#include <jni.h>

#include "api/Subscription.h"

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
    subscription_{env->NewGlobalRef(DxFeedCApi_createSubscription(env, dxFeed, eventType))}
  {
  }

  jobject Subscription::getSub() {
    return subscription_;
  }
}