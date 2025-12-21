//
// Created by rune-suy on 12/21/25.
//

#ifndef INC_2XD2_ENGINE_BALL_H
#define INC_2XD2_ENGINE_BALL_H
#include "2XD2/std_addon/Circle2D.h"


class Ball final : public e2XD::std_addon::Circle2D
{
    const float radius=15;
    e2XD::core::Vec2f velocity{200.0f,0};
public:
    Ball();

protected:
    void onUpdate() override;
};


#endif //INC_2XD2_ENGINE_BALL_H