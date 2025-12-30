//
// Created by rune-suy on 12/30/25.
//

#include "2XD2/framework/collisions/DefaultCollisionHandler.h"

namespace e2XD::framework
{
    void DefaultCollisionHandler::registerCollisionBody(ICollisionBody* body)
    {
        _collision_bodies.push_back({body, false});
    }

    void DefaultCollisionHandler::removeCollisionBody(ICollisionBody* body)
    {
        _collision_bodies.remove_if([body](const auto& pair){ return pair.first == body; });
    }

    void DefaultCollisionHandler::checkCollisions() const
    {
        for (auto& bodyA : _collision_bodies)
        {
            for (auto& bodyB : _collision_bodies)
            {
                if (bodyA.first == bodyB.first)
                    continue;

                if (bodyA.first->areColliding(bodyB.first) && !bodyA.second)
                {
                    bodyA.first->onCollisionEnter(bodyB.first);
                    bodyA.second = true;
                }
                else if (bodyB.second)
                {
                    bodyA.first->onCollisionExit(bodyB.first);
                    bodyA.second = false;
                }
            }
        }
    }
}
