// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/20/25.
//

#include "Opponent.h"

#include "OpponentHitBox.h"
#include "../ball/Ball.h"
#include "2XD2/framework/Time.h"

using namespace e2XD::framework;

Opponent::Opponent()
{
    setFillColor(sf::Color::Red);
    setSize(initialSize);
    auto* hitbox = createSubNode<OpponentHitBox>();
    hitbox->setHeight(initialSize.y);
    hitbox->setWidth(initialSize.x);
}

void Opponent::linkBall(Ball* ball)
{
    this->ball = ball;
}

void Opponent::onUpdate()
{
    if (!ball) return;

    if (ball->getGlobalPosition().y > getGlobalPosition().y + 5)
    {
        float newY = getGlobalPosition().y + speed * Time::getDeltaTime();
        if (newY > maxY) newY = maxY;
        setGlobalPosition({getGlobalPosition().x, newY});
    }
    else if (ball->getGlobalPosition().y < getGlobalPosition().y - 5)
    {
        float newY = getGlobalPosition().y - speed * Time::getDeltaTime();
        if (newY < minY) newY = minY;
        setGlobalPosition({getGlobalPosition().x, newY});
    }
}
