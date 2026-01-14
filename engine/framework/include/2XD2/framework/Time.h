// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 3/11/2025.
//

#ifndef INC_2XD2_ENGINE_STOPWATCH_H
#define INC_2XD2_ENGINE_STOPWATCH_H
#include "chrono"

namespace e2XD::framework
{
    using namespace std::chrono;

    /**
     * Calculates and holds the time in seconds between the last two ticks.
     */
    class Time
    {
        /**
         * Holds the previous tick timepoint.
         */
        inline static time_point<high_resolution_clock> _previous;

        /**
         * True if this is the first time tick is called.
         */
        inline static bool _firstTick = true;

        /**
         * The time between the last tick and the one before that. In seconds.
         */
        inline static float deltaTime = 0;

        Time() = default;

    public:
        /**
         *  Update the deltaTime
         *  Sets deltaTime to the gap in seconds between this and the previous tick.
         *  Returns zero first time tick() is called.
         */
        static void tick() noexcept;

        /**
         * @return The time between the previous two ticks in seconds. 0 if tick has only been called once.
         */
        [[nodiscard]] static float getDeltaTime() noexcept;
    };
}


#endif //INC_2XD2_ENGINE_STOPWATCH_H
