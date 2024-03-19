#pragma once
#include <array>
#include <chrono>
#include <numeric>

    using namespace std::chrono_literals;
    using std::chrono::steady_clock;
    using time_point = steady_clock::time_point;


namespace SDLGame {


    class FrameCounter {

        using seconds = std::chrono::seconds;
        using nanoseconds = std::chrono::nanoseconds;

        // used as a circular buffer
        static constexpr size_t frameTimesSize = 100;
        std::array<nanoseconds, frameTimesSize> frameTimes { };
        size_t frameTimeCurrentIndex = 0;

        time_point frameStartTime;
        time_point frameEndTime;


        // increments current index between 0 and frameTimesSize
        size_t GetNextIndex() const {
            return (frameTimeCurrentIndex + 1) % frameTimesSize;
        }

        // Helper functions

        static nanoseconds GetTimeDelta(const time_point& t2, const time_point& t1) {
            return std::chrono::nanoseconds(t2 - t1);
        }

        // calculates delta from ::now()
        static nanoseconds GetTimeDelta(const time_point& time) {
            return GetTimeDelta( steady_clock::now(), time);
        }

        // template <typename T>
        // nanoseconds asNanoseconds(T&& duration) const
        static nanoseconds asNanoseconds(int64_t&& duration) {
            return nanoseconds(duration);
        }


        public:

        const time_point& FrameStartTime = frameStartTime;
        const size_t&     BufferCapacity = frameTimesSize;

        void FrameStart() {
            frameStartTime = steady_clock::now();
        }


        void FrameEnd() {
            frameEndTime         = steady_clock::now();
            const auto timeDelta = GetTimeDelta(frameStartTime, frameEndTime);
            frameTimes[frameTimeCurrentIndex] = timeDelta;
            frameTimeCurrentIndex = GetNextIndex();
        }

        // Frame Time related 'getters'

        nanoseconds FrameTimeCurrent() const {
            return GetTimeDelta( frameStartTime );
        }

        nanoseconds FrameTimeLast() const {
            return frameTimes[frameTimeCurrentIndex];
        }

        nanoseconds FrameTimeAverage() const {
            const int64_t frameTimeSum = std::accumulate(
                frameTimes.begin(), frameTimes.end(),
                0LL,
                [](const int64_t sum, const nanoseconds& frameTime) {
                    return sum + frameTime.count();
                }
            );

            return asNanoseconds( frameTimeSum / frameTimesSize );

        }

        // FPS related 'getters'

        uint64_t FPSAverage() const {
            return seconds(1) / FrameTimeAverage();
        }


        uint64_t FPS() const {
            if (FrameTimeLast().count() == 0LL) return 0;
            return seconds(1) / FrameTimeLast();
        }

    };
}
