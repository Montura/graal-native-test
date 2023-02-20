#pragma once

#include <cstdint>
#include <thread>
#include <iostream>

#include "include/api/TimeAndSale.h"
#include "include/api/utils/TimeAndSaleFormatter.hpp"

namespace dxfeed::perf {
  class Diagnostic;
  typedef void(Diagnostic::*TimerCallback)();

  struct Timer {
    Timer(TimerCallback callback, int64_t measurementInSeconds);
    void start();
    void restart();
    void stop();
    void dispose();
  private:
    const TimerCallback m_func;   // Function to be executed fater interval
    const long m_interval;        // Timer interval in milliseconds
    std::thread m_thread;         // Thread timer is running into
    bool m_running = false;       // Status if timer is running
  };

  struct TimerDiff {
    void restart() {}

    int64_t elapsedInSeconds() { return 0; };
  };

  class Diagnostic {
    const std::string diagnosticHeader = "SystemInfo";
    /* readonly Timer */  Timer* _timer;

    /* readonly Stopwatch */ TimerDiff _timerDiff;
    /* readonly Stopwatch */ TimerDiff _runningDiff;

    /* long */ std::atomic <int64_t> _eventCounter;
    /* long */ std::atomic <int64_t> _listenerCounter;

    void TimerCallback();
    int64_t GetAndResetEventCounter();
    int64_t GetAndResetListenerCounter();
    double GetEventsPerSec();
    double GetListenerCallsPerSec();
  public:
    explicit Diagnostic(int64_t measurementPeriodInSeconds);
    void AddEventCounter(int64_t value);
    void AddListenerCounter(int64_t value);
    void Dispose();
  };


  struct Listener {
    explicit Listener(const Diagnostic* diagnostic):
      _diagnostic(diagnostic)
    {}

    void operator()(const void* events, std::size_t count) const {
      auto timeAndSaleList = reinterpret_cast<const TimeAndSale*>(events);
      for (int i = 0; i < count; ++i) {
        auto quote = std::make_shared<TimeAndSale>(timeAndSaleList[i]);
        std::cout << dxfeed::TimeAndSaleFormatter::toString(quote.get()) << std::endl;
      }
    }
  private:
    const Diagnostic* _diagnostic;
  };
}