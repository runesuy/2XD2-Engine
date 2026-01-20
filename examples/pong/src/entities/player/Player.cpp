// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/20/25.
//

#include "Player.h"

#include "PlayerHitBox.h"
#include "../../../../../engine/framework/include/2XD2/framework/Time.h"
#include "2XD2/framework/input/SFMLInputHandler.h"
#include "2XD2/framework/input/Input.h"

using namespace e2XD::framework;

Player::Player()
{
    getRenderable().setFillColor(sf::Color::White);
    getRenderable().setSize({10,40});
    auto* hitbox = createSubNode<PlayerHitBox>();
    hitbox->setHeight(40);
    hitbox->setWidth(10);
}

void Player::onUpdate(double deltaTime)
{
    e2XD::core::Vec2f velocity{0,0};
    if (Input::isKeyPressed(Key::W))
    {
        velocity.y -= speed;
    }
    if (Input::isKeyPressed(Key::S))
    {
        velocity.y += speed;
    }

    auto newPos = getGlobalPosition() + velocity * deltaTime;
    newPos.y = std::clamp(newPos.y, minY, maxY);
    setGlobalPosition(newPos);
}
