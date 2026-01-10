//
// Created by rune-suy on 12/30/25.
//

#include "BallHitBox.h"

#include <cmath>

#include "Ball.h"
#include "2XD2/std_addon/Rectangle2D.h"

void BallHitBox::onCollisionEnter(ICollisionBody* other)
{
    ball->velocity.x = -ball->velocity.x;

}

BallHitBox::BallHitBox(Ball* ball) : ball(ball)
{

}
