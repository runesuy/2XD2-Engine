//
// Created by rune-suy on 12/29/25.
//

#ifndef INC_2XD2_ENGINE_COLLISIONHANDLER_H
#define INC_2XD2_ENGINE_COLLISIONHANDLER_H


namespace e2XD::core
{
    class CollisionHandler
    {
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
    };
} // core
// e2XD

#endif //INC_2XD2_ENGINE_COLLISIONHANDLER_H
