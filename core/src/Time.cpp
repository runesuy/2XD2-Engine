//
// Created by runes on 14/12/2025.
//

#include "2XD2/core/Time.h"

namespace e2XD::core {
    double Time::deltaTime = 0.0;

    double Time::getDeltaTime() {
        return deltaTime;
    }
} // e2XD