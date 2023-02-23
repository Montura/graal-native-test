#pragma once

#include <cstdint>
#include <thread>
#include <iostream>

namespace dxfeed::perf {
  class Diagnostic;
  typedef void(Diagnostic::*TimerCallback)();

  struct Timer {
    Timer(Diagnostic* diagnostic, TimerCallback callback, int64_t measurementInSeconds);
    void start();
    void restart();
    void stop();
    void dispose();
  private:
    Diagnostic* _diagnostic;
    const TimerCallback m_func;   // Function to be executed after interval
    const long m_interval;        // Timer interval in milliseconds
    std::thread m_thread;         // Thread timer is running into
    bool m_running = false;       // Status if timer is running
  };

  struct TimerDiff {
    void restart() {}

    int64_t elapsedInSeconds() { return 1; }; // todo: calculate
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
}