//
// Created by rune-suy on 12/30/25.
//

#ifndef INC_2XD2_ENGINE_DEFAULTCOLLISIONHANDLER_H
#define INC_2XD2_ENGINE_DEFAULTCOLLISIONHANDLER_H
#include <list>

#include "ICollisionHandler.h"


namespace e2XD::framework
{
    class DefaultCollisionHandler : public ICollisionHandler
    {
        // pair<ICollisionBody*, wasCollidingLastCheck>
        mutable std::list<std::pair<ICollisionBody*, bool>> _collision_bodies;
    public:
        void registerCollisionBody(ICollisionBody* body) override;

        void removeCollisionBody(ICollisionBody* body) override;

        void checkCollisions() const override;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_DEFAULTCOLLISIONHANDLER_H
