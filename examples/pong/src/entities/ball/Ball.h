//
// Created by rune-suy on 12/21/25.
//

#ifndef INC_2XD2_ENGINE_BALL_H
#define INC_2XD2_ENGINE_BALL_H
#include "2XD2/framework/signals/Signal.h"
#include "2XD2/std_addon/Circle2D.h"

using namespace e2XD::framework;

class Ball final : public e2XD::std_addon::Circle2D
{
    const float radius=15;
    friend class BallHitBox;
    static constexpr float SPEED = 350.0f;
    static constexpr float UPPERBOUND = 300.0f;
    static constexpr float LOWERBOUND = -300.0f;
    e2XD::core::Vec2f velocity{2*SPEED/3,SPEED/3};
    bool boundHit = false;
public:
    Ball();

    Signal<> outOfBounds;

protected:
    void onUpdate() override;
};


#endif //INC_2XD2_ENGINE_BALL_H