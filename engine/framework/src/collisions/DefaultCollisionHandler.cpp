//
// Created by rune-suy on 12/30/25.
//

#include "2XD2/framework/collisions/DefaultCollisionHandler.h"

namespace e2XD::framework
{
    void DefaultCollisionHandler::registerCollisionBody(ICollisionBody* body)
    {
        _collision_bodies.emplace_back(body, false);
    }

    void DefaultCollisionHandler::removeCollisionBody(ICollisionBody* body)
    {
        _collision_bodies.remove_if([body](const auto& pair){ return pair.first == body; });
    }

    void DefaultCollisionHandler::checkCollisions() const
    {
        for (auto itA = _collision_bodies.begin(); itA != _collision_bodies.end(); ++itA)
        {
            for (auto itB = std::next(itA); itB != _collision_bodies.end(); ++itB)
            {
                auto& bodyA = *itA;
                auto& bodyB = *itB;

                if (bodyA.first->areColliding(bodyB.first))
                {
                    if (!bodyA.second)
                    {
                        bodyA.first->onCollisionEnter(bodyB.first);
                        bodyA.second = true;
                    }
                    if (!bodyB.second)
                    {
                        bodyB.first->onCollisionEnter(bodyA.first);
                        bodyB.second = true;
                    }
                }
                else
                {
                    if (bodyA.second)
                    {
                        bodyA.first->onCollisionExit(bodyB.first);
                        bodyA.second = false;
                    }
                    if (bodyB.second)
                    {
                        bodyB.first->onCollisionExit(bodyA.first);
                        bodyB.second = false;
                    }
                }
            }
        }
    }
}
