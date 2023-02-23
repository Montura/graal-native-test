#include <cstdint>
#include <chrono>
#include <iostream>

#include "api/utils/StopWatch.h"

// This class uses high-resolution performance counter if the installed
// hardware supports it. Otherwise, the class will fall back to DateTime
// and uses ticks as a measurement.

namespace dxfeed::perf {

  Stopwatch::Stopwatch() :
    _isRunning(false),
    _elapsed(0),
    _startTimeStamp(0)
  {
    reset();
  }

  void Stopwatch::start() {
    // Calling start on a running Stopwatch is a no-op.
    if (!_isRunning) {
      _startTimeStamp = getTimestamp();
      _isRunning = true;
    }
  }

  Stopwatch Stopwatch::StartNew() {
    Stopwatch s{};
    s.start();
    return s;
  }

  void Stopwatch::stop() {
    // Calling stop on a stopped Stopwatch is a no-op.
    if (_isRunning) {
      long endTimeStamp = getTimestamp();
      long elapsedThisPeriod = endTimeStamp - _startTimeStamp;
      _elapsed += elapsedThisPeriod;
      _isRunning = false;

      if (_elapsed < 0) {
        // When measuring small time periods the Stopwatch.Elapsed*
        // properties can return negative values.  This is due to
        // bugs in the basic input/output system (BIOS) or the hardware
        // abstraction layer (HAL) on machines with variable-speed CPUs
        // (e.g. Intel SpeedStep).

        _elapsed = 0;
      }
    }
  }

  void Stopwatch::reset() {
    _elapsed = 0;
    _isRunning = false;
    _startTimeStamp = 0;
  }

  // Convenience method for replacing {sw.Reset(); sw.Start();} with a single sw.Restart()
  void Stopwatch::restart() {
    _elapsed = 0;
    _startTimeStamp = getTimestamp();
    _isRunning = true;
  }

//  bool Stopwatch::isRunning() const {
//    return _isRunning;
//  }

  int64_t Stopwatch::elapsedInSeconds() const {
    return getElapsedDateTimeTicks() / TicksPerSecond;
  }
//
//  double Stopwatch::elapsedMilliseconds() {
//    return getElapsedDateTimeTicks() / TicksPerMillisecond;
//  }
//
//
//  int64_t Stopwatch::elapsedTicks() {
//    return getRawElapsedTicks();
//  }

  int64_t Stopwatch::getTimestamp() {
//      Debug.Assert(IsHighResolution);
    // todo: replace (long) Interop.Sys.GetTimestamp();
    const auto point = std::chrono::steady_clock::now();
    long long int count = std::chrono::duration_cast <std::chrono::seconds>(point.time_since_epoch()).count();
    std::cout << "getTimestamp(): " << count << std::endl;
    return count;
  }

  // Get the elapsed ticks.
  int64_t Stopwatch::getRawElapsedTicks() const {
    long timeElapsed = _elapsed;

    if (_isRunning) {
      // If the Stopwatch is running, add elapsed time since
      // the Stopwatch is started last time.
      long currentTimeStamp = getTimestamp();
      long elapsedUntilNow = currentTimeStamp - _startTimeStamp;
      timeElapsed += elapsedUntilNow;
    }
    return timeElapsed;
  }

  // Get the elapsed ticks.
  int64_t Stopwatch::getElapsedDateTimeTicks() const {
    // Debug.Assert(IsHighResolution);
    // convert high resolution perf counter to DateTime ticks
    int64_t i = getRawElapsedTicks();
    double d = i * s_tickFrequency;
    std::cout << "getElapsedDateTimeTicks():getRawElapsedTicks = " << i << std::endl;
    std::cout << "getElapsedDateTimeTicks():s_tickFrequency = " << s_tickFrequency << std::endl;
    std::cout << "getElapsedDateTimeTicks():d = " << d << std::endl;
    return d;
  }

}