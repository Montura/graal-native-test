#pragma once

#include "api/TimeAndSale.h"
#include "jniUtils.h"

struct TimeAndSaleMapper {
  TimeAndSaleMapper(JNIEnv_* env, dxfeed::OnCloseHandler handler) {
    clazz_ = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("com/dxfeed/event/market/TimeAndSale")));
    onClose_ = handler;
    idGetEventSymbol_ = env->GetMethodID(clazz_, "getEventSymbol", "()Ljava/lang/String;");
    idGetEventTime_ = env->GetMethodID(clazz_, "getEventTime", "()J");
    idGetEventFlags_ = env->GetMethodID(clazz_, "getEventFlags", "()I");
    idGetTime_ = env->GetMethodID(clazz_, "getTime", "()J");
    idGetTimeNanos_ = env->GetMethodID(clazz_, "getTimeNanos", "()J");
    idGetTimeNanoPart_ = env->GetMethodID(clazz_, "getTimeNanoPart", "()I");
  }

  ~TimeAndSaleMapper() {
    onClose_(clazz_);
  }

  TimeAndSale toNative(JNIEnv_* env, jobject object) {
    TimeAndSale quote{};
    quote.eventSymbol = getEventSymbol(env, object);
    quote.eventTime = getEventTime(env, object);
    quote.flags = getEventFlags(env, object);
    quote.time = getTime(env, object);
    quote.timeNanos = getTimeNanos(env, object);
    quote.timeNanoPart = getTimeNanoPart(env, object);
    return quote;
  }

  std::string getEventSymbol(JNIEnv_* env, jobject object) {
    auto obj = reinterpret_cast<jstring>(env->CallObjectMethod(object, idGetEventSymbol_));
    auto cstr = env->GetStringUTFChars(obj, JNI_FALSE);
    auto str = std::string(cstr);
    env->ReleaseStringUTFChars(obj, cstr);
    return str;
  }

  std::int64_t getEventTime(JNIEnv_* env, jobject object) {
    return env->CallLongMethod(object, idGetEventTime_);
  }

  std::int32_t getEventFlags(JNIEnv_* env, jobject object) {
    return env->CallIntMethod(object, idGetEventFlags_);
  }

  std::int64_t getTime(JNIEnv_* env, jobject object) {
    return env->CallLongMethod(object, idGetTime_);
  }

  std::int64_t getTimeNanos(JNIEnv_* env, jobject object) {
    return env->CallLongMethod(object, idGetTimeNanos_);
  }

  std::int32_t getTimeNanoPart(JNIEnv_* env, jobject object) {
    return env->CallIntMethod(object, idGetTimeNanoPart_);
  }

private:
  jclass clazz_;
  jmethodID idGetEventSymbol_;
  jmethodID idGetEventTime_;
  jmethodID idGetEventFlags_;
  jmethodID idGetTime_;
  jmethodID idGetTimeNanos_;
  jmethodID idGetTimeNanoPart_;
  dxfeed::OnCloseHandler onClose_;
};