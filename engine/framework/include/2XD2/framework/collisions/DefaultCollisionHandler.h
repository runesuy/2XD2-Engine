//
// Created by rune-suy on 12/30/25.
//

#ifndef INC_2XD2_ENGINE_DEFAULTCOLLISIONHANDLER_H
#define INC_2XD2_ENGINE_DEFAULTCOLLISIONHANDLER_H
#include <list>
#include <vector>

#include "ICollisionHandler.h"


namespace e2XD::framework
{
    class DefaultCollisionHandler : public ICollisionHandler
    {
        // pair<ICollisionBody*, wasCollidingLastCheck>
        mutable std::list<ICollisionBody*> _collision_bodies;
        mutable std::vector<std::pair<ICollisionBody*, ICollisionBody*>> _collisions_this_frame;
        mutable std::vector<std::pair<ICollisionBody*, ICollisionBody*>> _collisions_last_frame;
    public:
        void registerCollisionBody(ICollisionBody* body) override;

        void removeCollisionBody(ICollisionBody* body) override;

        void checkCollisions() const override;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_DEFAULTCOLLISIONHANDLER_H
