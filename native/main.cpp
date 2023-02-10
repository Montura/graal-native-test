#include <iostream>

#include "include/api/TimeAndSale.h"
#include "include/api/Api.h"
#include "include/api/Subscription.h"
#include "include/api/utils/TimeAndSaleFormatter.hpp"

int main(int argc, char** argv) {
  if (argc != 3) {
    throw std::logic_error("Expect 2 args: <address:port, symbol>");
  }
  const auto address = argv[1];
  std::cout << "Connection to address:" << address << std::endl;
  const auto symbol = argv[2];
  void* dxFeed = dxfeed_get_instance();
  auto connection = dxfeed_create_connection(dxFeed, address);
  auto subscription = dxfeed_create_subscription(connection, 0);
  std::cout << "dx subscription wrapper: " << static_cast<dxfeed::Subscription*>(subscription) << std::endl;
  std::cout << "dx subscription jobject: " << static_cast<dxfeed::Subscription*>(subscription)->getSub() << std::endl;

  dxfeed_add_listener(subscription, [](const void *events, int count) {
    auto timeAndSaleList = reinterpret_cast<const TimeAndSale*>(events);
    for (int i = 0; i < count; ++i) {
      auto quote = std::make_shared<TimeAndSale>(timeAndSaleList[i]);
      std::cout << dxfeed::TimeAndSaleFormatter::toString(quote.get()) << std::endl;
    }
  });
  dxfeed_add_symbol(subscription, symbol);
  std::cout << "Subscribe to symbol:" << symbol << std::endl;
  while (true) {}
}

//void callMainMethod(JNIEnv* env) {
//  jclass pJclass = env->FindClass("com/dxfeed/api/JniTest");
//  jmethodID methodId = env->GetStaticMethodID(pJclass, "main", "([Ljava/lang/String;)V");
//  if (methodId != nullptr) {
//    jstring hello = env->NewStringUTF("ETH/USD:GDAX");
//    jclass clazz = env->FindClass("Ljava/lang/String;");
//    jobjectArray pArray = env->NewObjectArray(1, clazz, nullptr);
//    env->SetObjectArrayElement(pArray, 0, hello);
//    env->CallStaticVoidMethod(pJclass, methodId, pArray);
//  }
//}