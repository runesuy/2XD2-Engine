// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/29/25.
//

#include "2XD2/framework/collisions/Collisions.h"
#include "2XD2/core/exceptions/NotInitializedException.h"
#include "2XD2/framework/collisions/ICollisionHandler.h"


namespace e2XD::framework
{
    void Collisions::initialize(ICollisionHandler* collisionHandler)
    {
        _collision_handler = collisionHandler;
    }

    void Collisions::throwIfNotInitialized(const std::string& where)
    {
        if (!_collision_handler)
        {
            throw core::NotInitializedException("Collisions", where);
        }
    }

    void Collisions::checkCollisions()
    {
        throwIfNotInitialized("Collisions::checkCollisions()");
        _collision_handler->checkCollisions();
    }

    void Collisions::registerCollisionBody(ICollisionBody* body)
    {
        throwIfNotInitialized("Collisions::registerCollisionBody(ICollisionBody* body)");
        _collision_handler->registerCollisionBody(body);
    }

    void Collisions::removeCollisionBody(ICollisionBody* body)
    {
        throwIfNotInitialized("Collisions::removeCollisionBody(ICollisionBody* body)");
        _collision_handler->removeCollisionBody(body);
    }
} // framework
// e2XD
