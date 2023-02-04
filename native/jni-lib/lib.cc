#include <jni.h>
#include <vector>

#include "api/DxFeed.h"
#include "api/jni_wrapper/TimeAndSaleMapper.h"
#include "api/Subscription.h"

extern "C" {

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
  dxfeed::DxFeed& feed = dxfeed::DxFeed::getInstance();
  auto& listMapping = feed.getListMapper();
  auto& timeAndSaleMapper = feed.getTimeAndSaleMapper();
  std::vector<TimeAndSale> events;
  events.reserve(size);
  for (std::size_t i = 0; i < size; ++i) {
    events.emplace_back(timeAndSaleMapper.toNative(env, listMapping.get(env, eventList, i)));
  }
  reinterpret_cast<dxfeed::Subscription::Listener *>(userCallback)(events.data(), size);
}

JNIEXPORT
void JNICALL Java_com_dxfeed_api_JniTest_nOnQuoteEventListener(JNIEnv* env, jclass, jint size,
                                                               jobject eventList, jlong userCallback)
{
//  std::cout << "Java_com_dxfeed_api_JniTest_nOnQuoteEventListener" << std::endl;
  dxfeed::DxFeed& feed = dxfeed::DxFeed::getInstance();
  auto& listMapping = feed.getListMapper();
  auto& timeAndSaleMapper = feed.getTimeAndSaleMapper();
  std::vector<TimeAndSale> events;
  events.reserve(size);
  for (std::size_t i = 0; i < size; ++i) {
    events.emplace_back(timeAndSaleMapper.toNative(env, listMapping.get(env, eventList, i)));
  }
  reinterpret_cast<dxfeed::Subscription::Listener *>(userCallback)(events.data(), size);
}
}