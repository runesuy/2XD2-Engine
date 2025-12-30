//
// Created by rune-suy on 12/21/25.
//

#include "Ball.h"

#include "BallHitBox.h"
#include "2XD2/core/Time.h"

Ball::Ball()
{
    setRadius(radius);
    auto* hitbox = new BallHitBox(this);
    hitbox->setHeight(radius*2);
    hitbox->setWidth(radius*2);
    addSubNode(std::unique_ptr<Node>(hitbox));
}

void Ball::onUpdate()
{
    setGlobalPosition(getGlobalPosition() + velocity* e2XD::framework::Time::getDeltaTime());
}

