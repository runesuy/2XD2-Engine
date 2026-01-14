// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/29/25.
//

#ifndef INC_2XD2_ENGINE_COLLISIONHANDLER_H
#define INC_2XD2_ENGINE_COLLISIONHANDLER_H
#include "ICollisionBody.h"


namespace e2XD::framework
{
    /**
     * Collision handler interface.
     * Handles registration, removal, and collision checking of collision bodies.
     * Calls onCollision events on collision bodies when collisions occur.
     *
     * Can be implemented and injected into the Collisions system.
     */
    class ICollisionHandler
    {
    public:
        virtual ~ICollisionHandler() = default;

        /**
         * Register a collision body to the collision system.
         * After registering, the body will be checked for collisions.
         * onCollision events will be triggered when collisions occur.
         * @param body
         */
        virtual void registerCollisionBody(ICollisionBody* body) = 0;

        /**
         * Remove a collision body from the collision system.
         * After removing, the body will no longer be checked for collisions.
         * @param body
         */
        virtual void removeCollisionBody(ICollisionBody* body) = 0;

        /**
         * Check for collisions between registered collision bodies.
         * This method should be called every frame to detect collisions.
         */
        virtual void checkCollisions() = 0;

    };
}
// e2XD

#endif //INC_2XD2_ENGINE_COLLISIONHANDLER_H
