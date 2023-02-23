#pragma once

namespace dxfeed::perf {
  class Stopwatch {
    constexpr static const long TicksPerMillisecond = 10000;
    constexpr static const long TicksPerSecond = TicksPerMillisecond * 1000; // 10,000,000

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
    static Stopwatch StartNew();
    explicit Stopwatch();

    void start();
    void stop();
    void reset();
    void restart();

//    bool isRunning() const;
    int64_t elapsedInSeconds() const;
//    double elapsedMilliseconds();
//    int64_t elapsedTicks();
    static int64_t getTimestamp();

  private:
    int64_t getRawElapsedTicks() const;
    int64_t getElapsedDateTimeTicks() const;

//    static long QueryPerformanceFrequency() {
//      constexpr const long SecondsToNanoSeconds = 1000000000;
//      return SecondsToNanoSeconds;
//    }

//    static long QueryPerformanceCounter() {
//      return (long) Interop.Sys.GetTimestamp();
//    }
  };
}


