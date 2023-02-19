#pragma once

#include <cstdint>

namespace dxfeed::perf {
  struct Timer;

  struct TimerDiff {
    void restart() {}

    int64_t elapsedInSeconds() { return 0; };
  };

  class Diagnostic {
    const std::string diagnosticHeader = "SystemInfo";
    /* readonly Timer */   std::unique_ptr<Timer> _timer;

    /* readonly Stopwatch */ TimerDiff _timerDiff;
    /* readonly Stopwatch */ TimerDiff _runningDiff;

    /* long */ std::atomic <int64_t> _eventCounter;
    /* long */ std::atomic <int64_t> _listenerCounter;

    explicit Diagnostic();
    void TimerCallback();
    int64_t GetAndResetEventCounter();
    int64_t GetAndResetListenerCounter();
    double GetEventsPerSec();
    double GetListenerCallsPerSec();
  public:
    Diagnostic(int64_t measurementPeriodInSeconds);
    void AddEventCounter(int64_t value);
    void AddListenerCounter(int64_t value);
    void Dispose();
  };

  typedef void(Diagnostic::*TimerCallback)();

  struct Timer {
    Timer(TimerCallback callback, int32_t measurementInSeconds) {}
    void dispose() {}
  };
}