#pragma once

namespace dxfeed::perf {
  class Stopwatch {
    constexpr static const int64_t MillisPerSecond = 1000000; // 10 ^ 6
    constexpr static const int64_t NanosPerSecond = MillisPerSecond * 1000; // 10 ^ 9

    int64_t _elapsed;
    int64_t _startTimeStamp;
    bool _isRunning = false;

    // "Frequency" stores the frequency of the high-resolution performance counter,
    // if one exists. Otherwise it will store TicksPerSecond.
    // The frequency cannot change while the system is running,
    // so we only need to initialize it once.
//    constexpr static const long Frequency = 1000000000; // SecondsToNanoSeconds from QueryPerformanceFrequency();
//    constexpr static const bool IsHighResolution = true;

    // performance-counter frequency, in counts per ticks.
    // This can speed up conversion from high frequency performance-counter
    // to ticks.
//    constexpr static const double s_tickFrequency = 1; //(double) TicksPerSecond / Frequency;

  public:
    explicit Stopwatch();

    void start();
    void stop();
    void reset();
    void restart();

    double elapsedInSeconds() const;
  private:
    static int64_t getTimeStampInNanos();
    int64_t getElapsedTimeInNanos() const;
  };
}


