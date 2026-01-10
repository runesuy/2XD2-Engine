//
// Created by rune-suy on 12/20/25.
//

#include "Player.h"

#include "PlayerHitBox.h"
#include "2XD2/core/Time.h"
#include "2XD2/framework/input/SFMLInputHandler.h"
#include "2XD2/framework/input/Input.h"

using namespace e2XD::framework;

Player::Player()
{
    setFillColor(sf::Color::White);
    setSize({10,40});
    auto* hitbox = createSubNode<PlayerHitBox>();
    hitbox->setHeight(40);
    hitbox->setWidth(10);
}

void Player::onUpdate()
{
    Vec2f velocity{0,0};
    if (Input::isKeyPressed(Key::W))
    {
        velocity.y -= speed;
    }
    if (Input::isKeyPressed(Key::S))
    {
        velocity.y += speed;
    }

    auto newPos = getGlobalPosition() + velocity * Time::getDeltaTime();
    newPos.y = std::clamp(newPos.y, minY, maxY);
    setGlobalPosition(newPos);
}
