//
// Created by rune-suy on 12/29/25.
//

#include "2XD2/framework/collisions/CollisionBody2D.h"

namespace e2XD::core
{
    int CollisionBody2D::getCollisionLayer() const
    {
        return collisionLayer;
    }

    ICollisionHandler::CollisionType CollisionBody2D::getCollisionType() const
    {
        return collisionType;
    }
} // core