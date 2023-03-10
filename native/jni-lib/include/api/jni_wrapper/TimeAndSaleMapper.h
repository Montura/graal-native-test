#pragma once

#include <iostream>

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

inline int8_t readByte(char** pData) {
  int8_t value = **pData;
  ++(*pData);
  return value;
}

inline int32_t readInt(char** pData) {
  int32_t value = 0;
  for (int n = 0; n < sizeof(int32_t); ++n) {
    value = (value << 8) + **pData;
    ++(*pData);
  }
  return value;
}

inline int64_t readLong(char** pData) {
  int64_t value = 0;
  for (int n = 0; n < sizeof(int64_t); ++n) {
    value = (value << 8) + **pData;
    ++(*pData);
  }
  return value;
}

struct TimeAndSaleMapper {
  explicit TimeAndSaleMapper() {}

  TimeAndSaleMapper(JNIEnv_* env, jclass helperClazz, dxfeed::OnCloseHandler handler) {
    helperClazz_ = helperClazz;
    idGetToNative_ = env->GetStaticMethodID(helperClazz, "toNative", "(Lcom/dxfeed/event/market/TimeAndSale;)[B");

    clazz_ = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass("Lcom/dxfeed/event/market/TimeAndSale;")));
    onClose_ = handler;
    idGetEventSymbol_ = env->GetMethodID(clazz_, "getEventSymbol", "()Ljava/lang/String;");
    idGetEventTime_ = env->GetMethodID(clazz_, "getEventTime", "()J");
    idGetIndex_ = env->GetMethodID(clazz_, "getIndex", "()J");
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
    auto pJobject = (jbyteArray) env->CallStaticObjectMethod(helperClazz_, idGetToNative_, object);
    if (pJobject) {
      auto pData = (char*) env->GetPrimitiveArrayCritical(pJobject, nullptr);
      int size = readByte(&pData);
      quote.event_symbol = pData;
      pData += size;
      quote.event_time = readLong(&pData);
      quote.index = readLong(&pData);
      quote.event_flags = readInt(&pData);
      quote.time_nano_part = readInt(&pData);
      quote.exchange_code = readByte(&pData);
      env->ReleasePrimitiveArrayCritical(pJobject, pData, 0);
    }
//    quote.event_symbol = getEventSymbol(env, object);
//    quote.event_time = getEventTime(env, object);
//    quote.index = getIndex(env, object);
//    quote.event_flags = getEventFlags(env, object);
//    quote.time_nano_part = getTimeNanoPart(env, object);
//    quote.exchange_code = getExchangeCode(env, object);
//    quote.price = getPrice(env, object);
//    quote.size = getSize(env, object);
//    quote.bid_price = getBidPrice(env, object);
//    quote.ask_price = getAskPrice(env, object);
//    quote.exchangeSaleConditions = getExchangeSaleConditions(env, object);
//    quote.buyer = getBuyer(env, object);
//    quote.seller = getSeller(env, object);
    return quote;
  }

  std::string getEventSymbol(JNIEnv_* env, jobject object) const {
    return getStringFromJava(env, object, idGetEventSymbol_);
  }

  std::int64_t getEventTime(JNIEnv_* env, jobject object) const {
    return env->CallLongMethod(object, idGetEventTime_);
  }

  std::int64_t getIndex(JNIEnv_* env, jobject object) const {
    return env->CallLongMethod(object, idGetIndex_);
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
  jclass helperClazz_;
  jmethodID idGetEventSymbol_;
  jmethodID idGetIndex_;
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
  jmethodID idGetToNative_;
  dxfeed::OnCloseHandler onClose_;
};