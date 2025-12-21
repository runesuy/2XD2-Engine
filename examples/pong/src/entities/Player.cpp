//
// Created by rune-suy on 12/20/25.
//

#include "Player.h"

#include "2XD2/core/Time.h"
#include "../../../../framework/include/2XD2/framework/input/SFMLInputHandler.h"
#include "2XD2/framework/input/Input.h"

using namespace e2XD::framework;

Player::Player()
{
    setFillColor(sf::Color::White);
    setSize({10,40});
}

void Player::onUpdate()
{
    e2XD::core::Vec2 velocity{0,0};
    if (Input::isKeyPressed(Key::W))
    {
        velocity.y -= speed;
    }
    if (Input::isKeyPressed(Key::S))
    {
        velocity.y += speed;
    }

    auto newPos = getGlobalPosition() + velocity * e2XD::core::Time::getDeltaTime();
    newPos.y = std::clamp(newPos.y, minY, maxY);
    setGlobalPosition(newPos);
}
