#include <jni.h>
#include <vector>
#include <iostream>

#include "api/DxFeed.h"
#include "api/jni_wrapper/TimeAndSaleMapper.h"
#include "api/Subscription.h"

int8_t readByte(char** pData);
int32_t readInt(char** pData);
int64_t readLong(char** pData);

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
                                                               jbyteArray eventList, jlong userCallback)
{
  dxfeed::DxFeed& feed = dxfeed::DxFeed::getInstance();
  auto& listMapping = feed.getListMapper();
  auto& timeAndSaleMapper = feed.getTimeAndSaleMapper();
  std::vector<TimeAndSale> events;
  events.reserve(size);
  auto pData = (char *)env->GetPrimitiveArrayCritical(eventList, nullptr);

  for (std::size_t i = 0; i < size; ++i) {
    TimeAndSale quote{};
    int strSize = readByte(&pData);
    quote.event_symbol = pData;
    pData += strSize;
    quote.event_time = readLong(&pData);
    quote.index = readLong(&pData);
    quote.event_flags = readInt(&pData);
    quote.time_nano_part = readInt(&pData);
    quote.exchange_code = readByte(&pData);
    events.emplace_back(quote);
  }

  env->ReleasePrimitiveArrayCritical(eventList, pData, 0);
  const auto pListener = reinterpret_cast<dxfeed::perf::DiagnosticListener*>(userCallback);
  pListener->operator()(events.data(), size);
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