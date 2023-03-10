#include <jni.h>
#include <vector>
#include <iostream>

#include "headers/com_dxfeed_api_JniTest.h"
#include "api/DxFeed.h"
#include "api/jni_wrapper/TimeAndSaleMapper.h"
#include "api/Subscription.h"

int8_t readByte(char** pData);
int32_t readInt(char** pData);
int64_t readLong(char** pData);
double readDouble(double** pData);

extern "C" {

// https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/invocation.html#JNJI_OnLoad
// -> register native method in created JNEEnv of VM when JNI lib is loaded
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
  JNIEnv* env;
  jint flag = vm->GetEnv((void**)&env, JNI_VERSION_1_8);
  if (flag == JNI_ERR) {
    throw std::runtime_error("Error getting JNIEnv. Exiting...n");
  }
  std::cout << "JNI_OnLoad, env = " << env << ", res = " << flag << std::endl;
  return JNI_VERSION_1_8;
}

void JNI_OnUnload(JavaVM *vm, void *reserved) {
  std::cout << "JNI_OnUnload" << std::endl;
}

JNIEXPORT
jlong JNICALL Java_com_dxfeed_api_JniTest_nCreateDxFeedSubscription(JNIEnv*, jclass, jobject dxFeedSub) {
//  std::cout << "Java_com_dxfeed_api_JniTest_nCreateDxFeedSubscription" << std::endl;
  return 1;
}

JNIEXPORT
void JNICALL Java_com_dxfeed_api_JniTest_nOnQuoteEventListenerOld(JNIEnv* env, jclass, jlong dxFeedSub, jint size,
                                                               jobject eventList, jlong userCallback)
{
//  std::cout << "Java_com_dxfeed_api_JniTest_nOnQuoteEventListener" << std::endl;
//  dxfeed::DxFeed& feed = dxfeed::DxFeed::getInstance();
//  auto& listMapping = feed.getListMapper();
//  auto& timeAndSaleMapper = feed.getTimeAndSaleMapper();
//  std::vector<TimeAndSale> events;
//  events.reserve(size);
//  for (std::size_t i = 0; i < size; ++i) {
//    events.emplace_back(timeAndSaleMapper.toNative(env, listMapping.get(eventList, i)));
//  }
//  reinterpret_cast<dxfeed::Subscription::Listener *>(userCallback)(events.data(), size);
}

JNIEXPORT
void JNICALL Java_com_dxfeed_api_JniTest_nOnQuoteEventListener(JNIEnv* env, jclass, jint size,
                                                               jbyteArray jBytes, jdoubleArray jDoubles, jlong userCallback)
{
  dxfeed::DxFeed& feed = dxfeed::DxFeed::getInstance();
  auto& listMapping = feed.getListMapper();
  auto& timeAndSaleMapper = feed.getTimeAndSaleMapper();
  std::vector<TimeAndSale> events;
  events.reserve(size);
  auto pByteData = (char *)env->GetPrimitiveArrayCritical(jBytes, nullptr);
  auto pDoubleData = (double *)env->GetPrimitiveArrayCritical(jDoubles, nullptr);

  for (int i = 0; i < size; ++i) {
    TimeAndSale quote{};
    int strSize = readByte(&pByteData);
    quote.event_symbol = pByteData;
    pByteData += strSize;
    quote.event_time = readLong(&pByteData);
    quote.index = readLong(&pByteData);
    quote.event_flags = readInt(&pByteData);
    quote.time_nano_part = readInt(&pByteData);
    quote.exchange_code = readByte(&pByteData);
    quote.size = readLong(&pByteData);

    strSize = readByte(&pByteData);
    quote.exchangeSaleConditions = pByteData;
    pByteData += strSize;

    strSize = readByte(&pByteData);
    quote.buyer = pByteData;
    pByteData += strSize;

    strSize = readByte(&pByteData);
    quote.seller = pByteData;
    pByteData += strSize;

    quote.price = readDouble(&pDoubleData);
    quote.bid_price = readDouble(&pDoubleData);
    quote.ask_price = readDouble(&pDoubleData);

    events.emplace_back(quote);
  }

  const auto pListener = reinterpret_cast<dxfeed::perf::DiagnosticListener*>(userCallback);
  pListener->operator()(events.data(), size);
  env->ReleasePrimitiveArrayCritical(jDoubles, pDoubleData, 0);
  env->ReleasePrimitiveArrayCritical(jBytes, pByteData, 0);
}

//JNIEXPORT
//void JNICALL JavaCritical_com_dxfeed_api_JniTest_nOnQuoteEventListener(jint size, jbyte* eventList, jlong userCallback) {
//  std::cout << "JavaCritical_com_dxfeed_api_JniTest_nOnQuoteEventListener" << std::endl;
//  dxfeed::DxFeed& feed = dxfeed::DxFeed::getInstance();
//  JNIEnv* env = nullptr;
//  int flag = dxfeed::javaVM->GetEnv((void**)&env, JNI_VERSION_1_8);
//  auto& listMapping = feed.getListMapper(env);
//  auto& timeAndSaleMapper = feed.getTimeAndSaleMapper(env);
//  std::vector<TimeAndSale> events;
//  events.reserve(size);
//  for (std::size_t i = 0; i < size; ++i) {
//    events.emplace_back(timeAndSaleMapper.toNative( listMapping.get((jobject)eventList, i)));
//  }
//  const auto pListener = reinterpret_cast<dxfeed::perf::DiagnosticListener*>(userCallback);
//  pListener->operator()(events.data(), size);
//}
}