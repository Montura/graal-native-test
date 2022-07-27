#pragma once

#include <jni.h>

void testSystemProperties(int argc, char** argv, graal_isolatethread_t* thread);

inline const char* STATIC_PROPERTY_KEY = "static_key";
inline const char* STATIC_PROPERTY_VALUE = "MY_STATIC_VALUE";
inline const char* DXFEED_ADDRESS_PROPERTY_KEY = "dxfeed.address";
inline const char* DXFEED_ADDRESS_PROPERTY_VALUE = "172.13.14.15";