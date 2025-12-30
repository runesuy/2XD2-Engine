//
// Created by rune-suy on 12/29/25.
//

#ifndef INC_2XD2_ENGINE_COLLISIONS_H
#define INC_2XD2_ENGINE_COLLISIONS_H


namespace e2XD::framework
{
    class ICollisionBody;
    class Collisions
    {
        inline static class ICollisionHandler* _collision_handler;

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

        static void initialize(ICollisionHandler* collisionHandler);

        static void registerCollisionBody(ICollisionBody* body);

        static void removeCollisionBody(ICollisionBody* body);

        static void checkCollisions();
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_COLLISIONS_H
