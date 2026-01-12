//
// Created by rune-suy on 12/29/25.
//

#include "2XD2/framework/collisions/CollisionBody2D.h"

namespace e2XD::framework
{
    int CollisionBody2D::getCollisionLayer() const
    {
        return collisionLayer;
    }

    Collisions::CollisionType CollisionBody2D::getCollisionType() const
    {
        return collisionType;
    }

    void CollisionBody2D::_internal_onCreate()
    {
        Collisions::registerCollisionBody(this);
        Node2D::_internal_onCreate();
    }

    void CollisionBody2D::_internal_onDestroy()
    {
        Collisions::removeCollisionBody(this);
        Node2D::_internal_onDestroy();
    }
}
