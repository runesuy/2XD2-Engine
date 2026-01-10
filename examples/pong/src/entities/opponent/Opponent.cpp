//
// Created by rune-suy on 12/20/25.
//

#include "Opponent.h"

#include "OpponentHitBox.h"

Opponent::Opponent()
{
    setFillColor(sf::Color::Red);
    setSize({10,40});
    auto* hitbox = createSubNode<OpponentHitBox>();
    hitbox->setHeight(40);
    hitbox->setWidth(10);
}
