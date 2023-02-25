#pragma once

#include <jni.h>
#include <iostream>

#include "../DxFeed.h"

namespace dxfeed::internal {
  struct JavaProperty {
    JavaProperty(jclass javaLangSystem, jmethodID getPropertyMethodId, const char* propName);
    ~JavaProperty();

    friend std::ostream& operator<<(std::ostream& os, const JavaProperty& prop) {
      os << prop._cstr;
      return os;
    }
  private:
    const char* _cstr;
    jstring _str;
  };
}