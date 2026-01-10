//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_OPPONENT_H
#define INC_2XD2_ENGINE_OPPONENT_H
#include "2XD2/std_addon/Rectangle2D.h"


class Opponent : public  e2XD::std_addon::Rectangle2D
{
    class Ball* ball = nullptr;
    float speed = 250.0f;
public:
    Opponent();

    void linkBall(Ball* ball);

protected:
    void onUpdate() override;
};


#endif //INC_2XD2_ENGINE_OPPONENT_H