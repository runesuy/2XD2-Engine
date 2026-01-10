//
// Created by rune-suy on 12/20/25.
//

#include "Opponent.h"

#include "OpponentHitBox.h"
#include "../ball/Ball.h"
#include "../../../../../engine/framework/include/2XD2/framework/Time.h"

using namespace e2XD::framework;

Opponent::Opponent()
{
    setFillColor(sf::Color::Red);
    setSize({10,40});
    auto* hitbox = createSubNode<OpponentHitBox>();
    hitbox->setHeight(40);
    hitbox->setWidth(10);
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
        if (newY > 280) newY = 280;
        setGlobalPosition({getGlobalPosition().x, newY});
    }
    else if (ball->getGlobalPosition().y < getGlobalPosition().y - 5)
    {
        float newY = getGlobalPosition().y - speed * Time::getDeltaTime();
        if (newY < -280) newY = -280;
        setGlobalPosition({getGlobalPosition().x, newY});
    }
}
