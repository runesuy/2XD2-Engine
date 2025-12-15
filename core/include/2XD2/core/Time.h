//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_TIME_H
#define INC_2XD2_ENGINE_TIME_H

namespace e2XD::core {
    class Time {
        static double deltaTime;
    public:
        static double getDeltaTime();
    };
} // e2XD


#endif //INC_2XD2_ENGINE_TIME_H