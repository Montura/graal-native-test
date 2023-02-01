#pragma once

extern "C" {

void* dxfeed_get_instance();
void* dxfeed_create_connection(void* feed, const char* address);
void* dxfeed_create_subscription(void* connection, int eventType);

}