#pragma once

#include "api/TimeAndSale.h"
#include "jniUtils.h"

inline std::string getStringFromJava(JNIEnv* env, jobject object, jmethodID jmethodId) {
  auto obj = reinterpret_cast<jstring>(env->CallObjectMethod(object, jmethodId));
  if (obj) {
    auto cstr = env->GetStringUTFChars(obj, JNI_FALSE);
    auto str = std::string(cstr);
    env->ReleaseStringUTFChars(obj, cstr);
    return str;
  }
  return "";
}

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
    idGetExchangeCode_ = env->GetMethodID(clazz_, "getExchangeCode", "()C");
    idGetPrice_ = env->GetMethodID(clazz_, "getPrice", "()D");
    idGetSize_ = env->GetMethodID(clazz_, "getSize", "()J");
    idGetBidPrice_ = env->GetMethodID(clazz_, "getBidPrice", "()D");
    idGetAskPrice_ = env->GetMethodID(clazz_, "getAskPrice", "()D");
    idGetExchangeSaleConditions_ = env->GetMethodID(clazz_, "getExchangeSaleConditions", "()Ljava/lang/String;");
    idGetFlags_ = env->GetMethodID(clazz_, "getFlags", "()I");
    idGetBuyer_ = env->GetMethodID(clazz_, "getBuyer", "()Ljava/lang/String;");
    idGetSeller_ = env->GetMethodID(clazz_, "getSeller", "()Ljava/lang/String;");
  }

  ~TimeAndSaleMapper() {
    onClose_(clazz_);
  }

  TimeAndSale toNative(JNIEnv_* env, jobject object) const {
    TimeAndSale quote{};
    quote.eventSymbol = getEventSymbol(env, object);
    quote.eventTime = getEventTime(env, object);
    quote.eventFlags = getEventFlags(env, object);
    quote.time = getTime(env, object);
    quote.timeNanos = getTimeNanos(env, object);
    quote.timeNanoPart = getTimeNanoPart(env, object);
    quote.exchangeCode = getExchangeCode(env, object);
    quote.price = getPrice(env, object);
    quote.size = getSize(env, object);
    quote.bidPrice = getBidPrice(env, object);
    quote.askPrice = getAskPrice(env, object);
    quote.exchangeSaleConditions = getExchangeSaleConditions(env, object);
    quote.flags = getFlags(env, object);
    quote.buyer = getBuyer(env, object);
    quote.seller = getSeller(env, object);
    return quote;
  }

  std::string getEventSymbol(JNIEnv_* env, jobject object) const {
    return getStringFromJava(env, object, idGetEventSymbol_);
  }

  std::int64_t getEventTime(JNIEnv_* env, jobject object) const {
    return env->CallLongMethod(object, idGetEventTime_);
  }

  std::int32_t getEventFlags(JNIEnv_* env, jobject object) const {
    return env->CallIntMethod(object, idGetEventFlags_);
  }

  std::int64_t getTime(JNIEnv_* env, jobject object) const {
    return env->CallLongMethod(object, idGetTime_);
  }

  std::int64_t getTimeNanos(JNIEnv_* env, jobject object) const {
    return env->CallLongMethod(object, idGetTimeNanos_);
  }

  std::int32_t getTimeNanoPart(JNIEnv_* env, jobject object) const {
    return env->CallIntMethod(object, idGetTimeNanoPart_);
  }

  std::uint16_t getExchangeCode(JNIEnv_* env, jobject object) const {
    static_assert(sizeof(char) == sizeof(jbyte), "sizeof(char) != sizeof(jbyte)");
    static_assert(sizeof(std::uint16_t) == sizeof(jchar), "sizeof(std::uint16_t) != sizeof(jchar)");
    return static_cast<std::uint16_t>(env->CallCharMethod(object, idGetExchangeCode_));
  }

  double getPrice(JNIEnv_* env, jobject object) const {
    return env->CallDoubleMethod(object, idGetPrice_);
  }

  std::int64_t getSize(JNIEnv_* env, jobject object) const {
    return env->CallLongMethod(object, idGetSize_);
  }

  double getBidPrice(JNIEnv_* env, jobject object) const {
    return env->CallDoubleMethod(object, idGetBidPrice_);
  }

  double getAskPrice(JNIEnv_* env, jobject object) const {
    return env->CallDoubleMethod(object, idGetAskPrice_);
  }

  std::string getExchangeSaleConditions(JNIEnv_* env, jobject object) const {
    return getStringFromJava(env, object, idGetExchangeSaleConditions_);
  }

  std::int32_t getFlags(JNIEnv_* env, jobject object) const {
    return env->CallIntMethod(object, idGetFlags_);
  }

  std::string getBuyer(JNIEnv_* env, jobject object) const {
    return getStringFromJava(env, object, idGetBuyer_);
  }

  std::string getSeller(JNIEnv_* env, jobject object) const {
    return getStringFromJava(env, object, idGetSeller_);
  }

private:
  jclass clazz_;
  jmethodID idGetEventSymbol_;
  jmethodID idGetEventTime_;
  jmethodID idGetEventFlags_;
  jmethodID idGetTime_;
  jmethodID idGetTimeNanos_;
  jmethodID idGetTimeNanoPart_;
  jmethodID idGetExchangeCode_;
  jmethodID idGetPrice_;
  jmethodID idGetSize_;
  jmethodID idGetBidPrice_;
  jmethodID idGetAskPrice_;
  jmethodID idGetExchangeSaleConditions_;
  jmethodID idGetFlags_;
  jmethodID idGetBuyer_;
  jmethodID idGetSeller_;
  dxfeed::OnCloseHandler onClose_;
};