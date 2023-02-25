#pragma once

#include <jni.h>
#include <string>
#include <vector>

#include "EventTypes.h"
#include "utils/Diagnostic.h"
#include "utils/TimeAndSaleFormatter.hpp"

template<class T>
constexpr inline void hash_combine(std::size_t& seed, const T& v) {
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<>
struct std::hash<TimeAndSale> {
  std::size_t operator()(const std::unique_ptr<TimeAndSale>& ptr) const noexcept {
    std::size_t h = 0;
    hash_combine(h, ptr->event_symbol);
    hash_combine(h, ptr->event_symbol);
    hash_combine(h, ptr->event_time);
    hash_combine(h, ptr->index);
    hash_combine(h, ptr->event_flags);
    hash_combine(h, ptr->time_nano_part);
    hash_combine(h, ptr->exchange_code);
    hash_combine(h, ptr->price);
    hash_combine(h, ptr->size);
    hash_combine(h, ptr->bid_price);
    hash_combine(h, ptr->ask_price);
    hash_combine(h, ptr->exchangeSaleConditions);
    hash_combine(h, ptr->flags);
    hash_combine(h, ptr->buyer);
    hash_combine(h, ptr->seller);
    return h;
  }
};

namespace dxfeed {
  namespace perf {
    static std::atomic<std::size_t> _blackHoleHashCode = 0;

    struct DiagnosticListener {
      explicit DiagnosticListener(Diagnostic* diagnostic) :
          _diagnostic(diagnostic) {}

      void operator()(const void* events, std::int64_t count) const {
        auto timeAndSaleList = reinterpret_cast<const TimeAndSale*>(events);
        _diagnostic->AddListenerCounter(1);
        _diagnostic->AddEventCounter(count);
        for (int i = 0; i < count; ++i) {
          auto quotePtr = std::make_unique<TimeAndSale>(timeAndSaleList[i]);
          _blackHoleHashCode += std::hash<TimeAndSale>()(quotePtr);
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