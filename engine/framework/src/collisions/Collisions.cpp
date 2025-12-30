//
// Created by rune-suy on 12/29/25.
//

#include "2XD2/framework/collisions/Collisions.h"

#include "2XD2/framework/collisions/ICollisionHandler.h"


namespace e2XD::framework
{
    void Collisions::initialize(ICollisionHandler* collisionHandler)
    {
        _collision_handler = collisionHandler;
    }

    void Collisions::checkCollisions()
    {
        _collision_handler->checkCollisions();
    }

    void Collisions::registerCollisionBody(ICollisionBody* body)
    {
        _collision_handler->registerCollisionBody(body);
    }

    void Collisions::removeCollisionBody(ICollisionBody* body)
    {
        _collision_handler->removeCollisionBody(body);
    }
} // framework
// e2XD
