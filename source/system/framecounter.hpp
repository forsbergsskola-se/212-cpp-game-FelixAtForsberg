#pragma once
#include <array>
#include <chrono>
#include <iostream>
#include <numeric>
#include <thread>

using namespace std::chrono_literals;
using std::chrono::steady_clock;
using time_point = steady_clock::time_point;

class FrameCounter {

    using seconds      = std::chrono::seconds;
    using microseconds = std::chrono::microseconds;

    // used as a circular buffer
    static constexpr size_t frameTimesSize = 100;
    std::array<microseconds, frameTimesSize> frameTimes { };
    size_t frameTimeCurrentIndex = 0;
    bool frameTimesFilled        = false; // does all elements in the array have a value? (for average calculations)

    time_point frameStartTime;
    time_point frameEndTime;


    // Increments current index between 0 and frameTimesSize
    size_t GetNextIndex() const {
        return (frameTimeCurrentIndex + 1) % frameTimesSize;
    }


    // Helper functions

    static microseconds GetTimeDelta( const time_point& end, const time_point& start ) {
        return std::chrono::duration_cast<microseconds>( end - start );
    }


    // calculates delta from ::now()
    static microseconds GetTimeSince( const time_point& time ) {
        return GetTimeDelta( steady_clock::now(), time );
    }


    // template <typename T>
    // microseconds asMicroseconds(T&& duration)
    static microseconds asMicroseconds( uint64_t&& duration ) {
        return microseconds( duration );
    }

public:

    const time_point& FrameStartTime = frameStartTime;
    const size_t& BufferCapacity     = frameTimesSize;


    void FrameStart() {
        frameStartTime = steady_clock::now();
    }


    void FrameEnd() {
        frameEndTime                      = steady_clock::now();
        const auto timeDelta              = GetTimeDelta( frameEndTime, frameStartTime );
        frameTimes[frameTimeCurrentIndex] = timeDelta;

        frameTimeCurrentIndex = GetNextIndex();

        if(!frameTimesFilled && frameTimeCurrentIndex == frameTimesSize - 1) {
            frameTimesFilled = true;
        }
    }


    // Frame Time related 'getters'

    microseconds FrameTimeCurrent() const {
        return GetTimeSince( frameStartTime );
    }


    microseconds FrameTimeLast() const {
        return frameTimes[frameTimeCurrentIndex - 1];
    }


    microseconds FrameTimeAverage() const {

        // std::make_const_iterator() is c++23

        // end of array if filled (fully initialized), otherwise, use only the initialized subset
        const auto endIterator = frameTimesFilled ? frameTimes.cend() : frameTimes.cbegin() + frameTimeCurrentIndex;
        const auto currentFrameTimesSize = frameTimesFilled ? frameTimes.size() : frameTimeCurrentIndex;

        const int64_t frameTimeSum = std::accumulate(
                                                     frameTimes.cbegin(), endIterator,
                                                     0LL,
                                                     []( const int64_t sum, const microseconds& frameTime ) {
                                                         return sum + frameTime.count();
                                                     }
                                                    );

        return asMicroseconds( frameTimeSum / currentFrameTimesSize );
    }


    // FPS related 'getters'

    uint64_t FPSAverage() const {
        return seconds( 1 ) / FrameTimeAverage();
    }


    uint64_t FPS() const {
        if(FrameTimeLast().count() == 0LL) return 0;
        return seconds( 1 ) / FrameTimeLast();
    }

};