#pragma once

#include <cstdint>
#include "jniUtils.h"

struct ListMapper {
  ListMapper(JNIEnv* env, dxfeed::OnCloseHandler onClose) {
    onClose_ = onClose;
    clazz_ = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("java/util/List")));
    idGet_ = env->GetMethodID(clazz_, "get", "(I)Ljava/lang/Object;");
  }

  ~ListMapper() {
    onClose_(clazz_);
  }

  jobject get(JNIEnv_* env, jobject object, size_t index) const {
    return env->CallObjectMethod(object, idGet_, index);
  }

private:
  jclass clazz_;
  jmethodID idGet_;
  dxfeed::OnCloseHandler onClose_;
};