// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/30/25.
//

#include "BallHitBox.h"

#include <cmath>

#include "Ball.h"
#include "../../../../../addons/std-addon/include/2XD2/std_addon/nodes/Rectangle2D.h"

void BallHitBox::onCollisionEnter(ICollisionBody* other)
{
    ball->velocity.x = -ball->velocity.x;

}

BallHitBox::BallHitBox(Ball* ball) : ball(ball)
{

}
