// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/30/25.
//

#include "2XD2/framework/collisions/DefaultCollisionHandler.h"

#include <algorithm>

namespace e2XD::framework
{
    void DefaultCollisionHandler::registerCollisionBody(ICollisionBody* body)
    {
        _collision_bodies.emplace_back(body);
    }

    void DefaultCollisionHandler::removeCollisionBody(ICollisionBody* body)
    {
        _collision_bodies.remove_if([body](const auto& pair) { return pair == body; });
    }

    void DefaultCollisionHandler::checkCollisions()
    {
        for (auto itA = _collision_bodies.begin(); itA != _collision_bodies.end(); ++itA)
        {
            for (auto itB = std::next(itA); itB != _collision_bodies.end(); ++itB)
            {
                auto& bodyA = *itA;
                auto& bodyB = *itB;

                if (bodyA->getCollisionLayer() != bodyB->getCollisionLayer()) continue; // Skip if layers do not match
                if (bodyA->getCollisionType()==Collisions::CollisionType::STATIC &&
                    bodyB->getCollisionType()==Collisions::CollisionType::STATIC) continue; // Skip static-static collisions

                if (bodyA->areColliding(bodyB))
                {
                    if (bodyA < bodyB) _collisions_this_frame.emplace_back(bodyA, bodyB);
                    else _collisions_this_frame.emplace_back(bodyB, bodyA);
                }
            }
        }

        // check for collision enter/exit events
        for (const auto& collision : _collisions_this_frame)
        {
            if (std::ranges::find(_collisions_last_frame, collision) == _collisions_last_frame.end())
            {
                collision.first->onCollisionEnter(collision.second);
                collision.second->onCollisionEnter(collision.first);
            }
        }

        for (const auto& collision : _collisions_last_frame)
        {
            if (std::ranges::find(_collisions_this_frame, collision) == _collisions_this_frame.end())
            {
                collision.first->onCollisionExit(collision.second);
                collision.second->onCollisionExit(collision.first);
            }
        }

        _collisions_last_frame = std::move(_collisions_this_frame);
        _collisions_this_frame.clear();
        // Reserve space to avoid frequent reallocations
        _collisions_this_frame.reserve(_collisions_last_frame.size());
    }
}
