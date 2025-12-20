//
// Created by rune-suy on 12/20/25.
//

#include "Player.h"

#include "2XD2/core/Time.h"
#include "2XD2/framework/SFMLInputHandler.h"

Player::Player()
{
    setFillColor(sf::Color::White);
    setSize({10,40});
}

void Player::onUpdate()
{
    const auto* inputHandler = e2XD::framework::SFMLInputHandler::getInstance();
    e2XD::core::Vec2 velocity{0,0};
    if (inputHandler->isKeyPressed(Key::W))
    {
        velocity.y -= speed;
    }
    if (inputHandler->isKeyPressed(Key::S))
    {
        velocity.y += speed;
    }

    auto newPos = getGlobalPosition() + velocity * e2XD::core::Time::getDeltaTime();
    newPos.y = std::clamp(newPos.y, minY, maxY);
    setGlobalPosition(newPos);
}
