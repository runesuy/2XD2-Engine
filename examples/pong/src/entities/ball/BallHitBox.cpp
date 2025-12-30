//
// Created by rune-suy on 12/30/25.
//

#include "BallHitBox.h"

#include "Ball.h"

void BallHitBox::onCollisionEnter(ICollisionBody* other)
{
    ball->velocity.x = -ball->velocity.x;
}

BallHitBox::BallHitBox(Ball* ball) : ball(ball)
{

}
