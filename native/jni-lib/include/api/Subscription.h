#pragma once

#include <jni.h>
#include <string>
#include <vector>

#include "EventTypes.h"
#include "utils/diagnostic.h"
#include "utils/TimeAndSaleFormatter.hpp"

namespace dxfeed {
  namespace perf {
    struct DiagnosticListener {
      explicit DiagnosticListener(Diagnostic* diagnostic) :
          _diagnostic(diagnostic) {}

      void operator()(const void* events, std::size_t count) const {
        auto timeAndSaleList = reinterpret_cast<const TimeAndSale*>(events);
        _diagnostic->AddListenerCounter(1);
        _diagnostic->AddEventCounter(count);
        for (int i = 0; i < count; ++i) {
          auto quote = std::make_shared<TimeAndSale>(timeAndSaleList[i]);
//          std::cout << dxfeed::TimeAndSaleFormatter::toString(quote.get()) << std::endl;
        }
      }

    private:
      Diagnostic* _diagnostic;
    };
  }

  struct Subscription final {
    typedef void(Listener)(const void* events, std::size_t count);

    Subscription(JNIEnv* env, jobject connection, EventType eventType);
    Subscription(const Subscription& other) = delete;
    Subscription(Subscription&& other) = delete;
    Subscription& operator=(const Subscription& other) = delete;
    Subscription& operator=(Subscription&& other) = delete;

    void addListener(Listener listener) const;
    void addSymbol(const std::string& symbol) const;
//    void addSymbols(const std::vector <std::string>& symbols) const;
    jobject getSub();


    // diagnostic
    void addDiagnosticListener(int64_t listener) const;
  private:
    jobject subscription_;
    JNIEnv* env_;
  };
}