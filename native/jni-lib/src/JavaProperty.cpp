#pragma once

#include <jni.h>

#include "api/utils/JavaProperty.h"

namespace dxfeed::internal {
  JavaProperty::JavaProperty(jclass javaLangSystem, jmethodID getPropertyMethodId, const char* propName) {
    jstring property = jniEnv->NewStringUTF(propName);
    _str = (jstring)jniEnv->CallStaticObjectMethod(javaLangSystem, getPropertyMethodId, property);
    _cstr = jniEnv->GetStringUTFChars(_str, nullptr);
  }

  JavaProperty::~JavaProperty() {
      jniEnv->ReleaseStringUTFChars(_str, nullptr);
  }
}