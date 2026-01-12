//
// Created by rune-suy on 12/29/25.
//

#ifndef INC_2XD2_ENGINE_COLLISIONS_H
#define INC_2XD2_ENGINE_COLLISIONS_H
#include <string>


namespace e2XD::framework
{
    class ICollisionBody;
    class Collisions
    {
        inline static class ICollisionHandler* _collision_handler;

        static void throwIfNotInitialized(const std::string& where);

    public:
        /**
         * Collision types for collision bodies.
         * STATIC: does not move, used for environment
         * DYNAMIC: can move, used for characters and objects
         */
        enum class CollisionType
        {
            STATIC,
            DYNAMIC
        };

        /**
         * Initialize the collision system with a collision handler.
         * @param collisionHandler
         */
        static void initialize(ICollisionHandler* collisionHandler);

        /**
         * Register a collision body to the collision system.
         * After registering, the body will be checked for collisions.
         * onCollision events will be triggered when collisions occur.
         * @param body
         */
        static void registerCollisionBody(ICollisionBody* body);

        /**
         * Remove a collision body from the collision system.
         * After removing, the body will no longer be checked for collisions.
         * @param body
         */
        static void removeCollisionBody(ICollisionBody* body);

        /**
         * Check for collisions between registered collision bodies.
         * This method should be called every frame to detect collisions.
         */
        static void checkCollisions();
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_COLLISIONS_H
