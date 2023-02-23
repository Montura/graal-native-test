#include <iostream>
#include <memory>

#include "api/utils/Diagnostic.h"

namespace dxfeed::perf {
  void Diagnostic::TimerCallback() {
    auto eventsPerSec = GetEventsPerSec();
    auto listenerCallsPerSec = GetListenerCallsPerSec();

    std::cout << "\n";
    std::cout << diagnosticHeader << "\n";
    std::cout << "----------------------------------------------" << "\n";
    std::cout << "  Events                   : " << eventsPerSec << " (per/sec)" << "\n";
    std::cout << "  Listener Calls           : " << listenerCallsPerSec << " (per/sec)" << "\n";
    std::cout << "  Average Number of Events : " << eventsPerSec / listenerCallsPerSec << "\n";
    std::cout << "  Running Time             : " << _runningDiff.elapsedInSeconds() << "\n";

    _timerDiff.restart();
  }

  int64_t Diagnostic::GetAndResetEventCounter() {
    return _eventCounter.exchange(0);
  }

  int64_t Diagnostic::GetAndResetListenerCounter() {
    return _listenerCounter.exchange(0);
  }

  double Diagnostic::GetEventsPerSec() {
    return (double) GetAndResetEventCounter() / (double) _timerDiff.elapsedInSeconds();
  }

  double Diagnostic::GetListenerCallsPerSec() {
    return (double) GetAndResetListenerCounter() / (double) _timerDiff.elapsedInSeconds();
  }

  Diagnostic::Diagnostic(int64_t measurementPeriodInSeconds):
    _timer(new Timer(this, &Diagnostic::TimerCallback, measurementPeriodInSeconds))
  {
    _timerDiff.restart();
    _runningDiff.restart();
  }

  void Diagnostic::AddEventCounter(int64_t value) {
    _eventCounter += value;
  }

  void Diagnostic::AddListenerCounter(int64_t value) {
    _listenerCounter += value;
  }

  void Diagnostic::Dispose() {
    _timer->dispose();
    delete _timer;
  }
}