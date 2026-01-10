//
// Created by rune-suy on 12/29/25.
//

#ifndef INC_2XD2_ENGINE_COLLISIONHANDLER_H
#define INC_2XD2_ENGINE_COLLISIONHANDLER_H
#include "ICollisionBody.h"


namespace e2XD::framework
{

    class ICollisionHandler
    {
    public:
        virtual ~ICollisionHandler() = default;

        virtual void registerCollisionBody(ICollisionBody* body) = 0;

        virtual void removeCollisionBody(ICollisionBody* body) = 0;

        virtual void checkCollisions() = 0;

    };
}
// e2XD

#endif //INC_2XD2_ENGINE_COLLISIONHANDLER_H
