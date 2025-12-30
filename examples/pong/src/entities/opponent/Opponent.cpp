//
// Created by rune-suy on 12/20/25.
//

#include "Opponent.h"

#include "OpponentHitBox.h"

Opponent::Opponent()
{
    setFillColor(sf::Color::Red);
    setSize({10,40});
    auto* hitbox = new OpponentHitBox();
    hitbox->setHeight(40);
    hitbox->setWidth(10);
    addSubNode(std::unique_ptr<Node>(hitbox));
}
