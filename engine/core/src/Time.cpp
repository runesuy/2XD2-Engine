//
// Created by runes on 3/11/2025.
//

#include "2XD2/core/Time.h"

using namespace std::chrono;

namespace e2XD::core
{
    void Time::tick() noexcept
    {
        time_point<high_resolution_clock, high_resolution_clock::duration> newTime = high_resolution_clock::now();

        if (_firstTick)
        {
            _firstTick = false;
            _previous = newTime;
            return;
        }
        using DoubleSeconds = std::chrono::duration<float>;
        const auto elapsed_duration = newTime - _previous;
        deltaTime = std::chrono::duration_cast<DoubleSeconds>(elapsed_duration).count();
        _previous = newTime;
    }

    float Time::getDeltaTime() noexcept
    {
        return deltaTime;
    }
}
