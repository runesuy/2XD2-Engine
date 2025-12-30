//
// Created by rune-suy on 12/21/25.
//

#include "Ball.h"

#include "2XD2/core/Time.h"

Ball::Ball()
{
    setRadius(radius);
}

void Ball::onUpdate()
{
    setGlobalPosition(getGlobalPosition() + velocity* e2XD::framework::Time::getDeltaTime());
}

