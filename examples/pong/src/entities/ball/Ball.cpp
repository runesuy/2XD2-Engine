//
// Created by rune-suy on 12/21/25.
//

#include "Ball.h"

#include "BallHitBox.h"
#include "2XD2/framework/Time.h"
#include "../../scenes/MainScene.h"

Ball::Ball()
{
    setRadius(radius);
    auto hitbox = std::make_unique<BallHitBox>(this);
    hitbox->setHeight(radius*2);
    hitbox->setWidth(radius*2);
    Node::addSubNode(std::move(hitbox));
}

void Ball::onUpdate()
{
    setGlobalPosition(getGlobalPosition() + velocity* e2XD::framework::Time::getDeltaTime());

    // bottom and top wall collision
    if (getGlobalPosition().y + radius >= UPPERBOUND || getGlobalPosition().y - radius <= LOWERBOUND)
    {
        velocity.y = -velocity.y;
    }

    if (getGlobalPosition().x - radius < MainScene::leftBound ||
        getGlobalPosition().x + radius > MainScene::rightBound)
    {
        outOfBounds.emit();
    }
}

