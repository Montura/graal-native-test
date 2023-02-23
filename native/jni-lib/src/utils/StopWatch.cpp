#include <cstdint>
#include "api/utils/StopWatch.h"

// This class uses high-resolution performance counter if the installed
// hardware supports it. Otherwise, the class will fall back to DateTime
// and uses ticks as a measurement.

namespace dxfeed::perf {

  Stopwatch::Stopwatch() {
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

  bool Stopwatch::isRunning() const {
    return _isRunning;
  }

  int64_t Stopwatch::elapsedInSeconds() const {
    return getElapsedDateTimeTicks() / TicksPerSecond;
  }

  int64_t Stopwatch::elapsedMilliseconds() {
    return getElapsedDateTimeTicks() / TicksPerMillisecond;
  }


  int64_t Stopwatch::elapsedTicks() {
    return getRawElapsedTicks();
  }

  long Stopwatch::getTimestamp() {
//      Debug.Assert(IsHighResolution);
    return 1; // todo: replace (long) Interop.Sys.GetTimestamp();
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
    return (reinterpret_cast<int64_t>(getRawElapsedTicks()) * s_tickFrequency);
  }

}