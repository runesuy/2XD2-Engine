//
// Created by rune-suy on 12/30/25.
//

#ifndef INC_2XD2_ENGINE_BALLHITBOX_H
#define INC_2XD2_ENGINE_BALLHITBOX_H
#include "2XD2/std_addon/CollisionRect2D.h"

class Ball;

class BallHitBox : public e2XD::std_addon::CollisionRect2D
{
    Ball* ball;
public:
    explicit BallHitBox(Ball* ball);

    void onCollisionEnter(ICollisionBody* other) override;
};


#endif //INC_2XD2_ENGINE_BALLHITBOX_H