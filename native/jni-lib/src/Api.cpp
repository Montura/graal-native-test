#include "api/Api.h"
#include "api/DxFeed.h"
#include "api/Connection.h"

void* dxfeed_get_instance() {
  auto& feed = dxfeed::DxFeed::getInstance();
  return &feed;
}

void* dxfeed_create_connection(void* feed, const char* address) {
  return reinterpret_cast<dxfeed::DxFeed*>(feed)->createConnection(address);
}

void* dxfeed_create_subscription(void* connection, int eventType) {
  return reinterpret_cast<dxfeed::Connection*>(connection)->createSubscription(static_cast<EventType>(eventType));
}

void dxfeed_add_symbol(void *subscription, const char *symbol) {
  reinterpret_cast<dxfeed::Subscription *>(subscription)->addSymbol(symbol);
}

void dxfeed_add_listener(void *subscription, dx_feed_listener listener) {
  reinterpret_cast<dxfeed::Subscription *>(subscription)->addListener(reinterpret_cast<void (*)(const void *,
                                                                                                size_t)>(listener));
}