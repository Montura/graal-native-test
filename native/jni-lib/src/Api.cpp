#include "api/DxFeed.h"

void* dxfeed_get_instance(JNIEnv_* env) {
  auto& feed = dxfeed::DxFeed::getInstance(env);
  return &feed;
}
