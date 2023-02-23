#include <cstdint>
#include "api/utils/StopWatch.h"

// This class uses high-resolution performance counter if the installed
// hardware supports it. Otherwise, the class will fall back to DateTime
// and uses ticks as a measurement.

namespace dxfeed::perf {

  class Stopwatch {
    constexpr static const long TicksPerMillisecond = 10000;
    constexpr static const long TicksPerSecond = TicksPerMillisecond * 1000;

    long _elapsed;
    long _startTimeStamp;
    bool _isRunning;


    // "Frequency" stores the frequency of the high-resolution performance counter,
    // if one exists. Otherwise it will store TicksPerSecond.
    // The frequency cannot change while the system is running,
    // so we only need to initialize it once.
    constexpr static const long Frequency = 1000000000; // SecondsToNanoSeconds from QueryPerformanceFrequency();
    constexpr static const bool IsHighResolution = true;

    // performance-counter frequency, in counts per ticks.
    // This can speed up conversion from high frequency performance-counter
    // to ticks.
    constexpr static const double s_tickFrequency = (double) TicksPerSecond / Frequency;

  public:
    explicit Stopwatch() {
      Reset();
    }

    void Start() {
      // Calling start on a running Stopwatch is a no-op.
      if (!_isRunning) {
        _startTimeStamp = GetTimestamp();
        _isRunning = true;
      }
    }

    static Stopwatch StartNew() {
      Stopwatch s{};
      s.Start();
      return s;
    }

    void Stop() {
      // Calling stop on a stopped Stopwatch is a no-op.
      if (_isRunning) {
        long endTimeStamp = GetTimestamp();
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

    void Reset() {
      _elapsed = 0;
      _isRunning = false;
      _startTimeStamp = 0;
    }

    // Convenience method for replacing {sw.Reset(); sw.Start();} with a single sw.Restart()
    void Restart() {
      _elapsed = 0;
      _startTimeStamp = GetTimestamp();
      _isRunning = true;
    }

    bool IsRunning() const {
      return _isRunning;
    }

    int64_t Elapsed() const {
      return GetElapsedDateTimeTicks();
    }

    long ElapsedMilliseconds() {
      return GetElapsedDateTimeTicks() / TicksPerMillisecond;
    }


    long ElapsedTicks() {
      return GetRawElapsedTicks();
    }

    static long GetTimestamp() {
//      Debug.Assert(IsHighResolution);
      return 1; // todo: replace (long) Interop.Sys.GetTimestamp();
    }

    // Get the elapsed ticks.
  private:
    int64_t GetRawElapsedTicks() const {
      long timeElapsed = _elapsed;

      if (_isRunning) {
        // If the Stopwatch is running, add elapsed time since
        // the Stopwatch is started last time.
        long currentTimeStamp = GetTimestamp();
        long elapsedUntilNow = currentTimeStamp - _startTimeStamp;
        timeElapsed += elapsedUntilNow;
      }
      return timeElapsed;
    }

    // Get the elapsed ticks.
    int64_t GetElapsedDateTimeTicks() const {
//      Debug.Assert(IsHighResolution);
      // convert high resolution perf counter to DateTime ticks
      return (reinterpret_cast<int64_t>(GetRawElapsedTicks()) * s_tickFrequency);
    }

//    static long QueryPerformanceFrequency() {
//      constexpr const long SecondsToNanoSeconds = 1000000000;
//      return SecondsToNanoSeconds;
//    }

//    static long QueryPerformanceCounter() {
//      return (long) Interop.Sys.GetTimestamp();
//    }
  };

}