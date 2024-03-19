#pragma once
#include <array>
#include <numeric>

namespace SDLGame {

    class FrameCounter {

        // used as a circular buffer
        static constexpr size_t frameTimesSize = 100;
        std::array<Uint64, frameTimesSize> frameTimes { };
        size_t frameTimeCurrentIndex = 0;

        // increments current index between 0 and frameTimesSize
        size_t GetNextIndex() const {
            return (frameTimeCurrentIndex + 1) % frameTimesSize;
        }

        Uint64 frameStartTick_ = 0;
        Uint64 frameEndTick = 0;

        public:

        const Uint64& frameStartTick = frameStartTick_;
        const size_t& bufferCapacity = frameTimesSize;

        void FrameStart() {
            frameStartTick_ = SDL_GetTicks64();
        }


        void FrameEnd() {
            frameEndTick = SDL_GetTicks64();
            const Uint64 timeDelta = frameEndTick - frameStartTick_;
            frameTimes[frameTimeCurrentIndex] = timeDelta;
            frameTimeCurrentIndex = GetNextIndex();
        }

        Uint64 FrameTimeCurrent() const {
            return SDL_GetTicks64() - frameStartTick_;
        }

        Uint64 FrameTimeLast() const {
            return frameTimes[frameTimeCurrentIndex];
        }

        Uint64 FrameTimeAverage() const {
            return std::accumulate( frameTimes.begin(), frameTimes.end(), 0.0 ) / frameTimesSize;
        }

        Uint64 FPSAverage() const {
            return 1000 / FrameTimeAverage();
        }


        Uint64 FPS() const {
            if (FrameTimeLast() == 0) return 0;
            return 1000 / FrameTimeLast();
        }

    };
}
