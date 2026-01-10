//
// Created by rune-suy on 12/22/25.
//

#ifndef INC_2XD2_ENGINE_COLLISIONBODY_H
#define INC_2XD2_ENGINE_COLLISIONBODY_H
#include "Collisions.h"
#include "ICollisionBody.h"
#include "../nodes/Node2D.h"


namespace e2XD::framework
{
    /**
     * A collision body in 2D space.
     */
    class CollisionBody2D  : public ICollisionBody, public Node2D
    {
    protected:
        /**
         * The layer this collision body belongs to. Used for collision filtering.
         */
        int collisionLayer=0;

        /**
         * The type of collision body.
         * @see CollisionHandler::CollisionType
         */
        Collisions::CollisionType collisionType = Collisions::CollisionType::DYNAMIC;
    public:
        CollisionBody2D() = default;
        ~CollisionBody2D() override = default;


        [[nodiscard]] Collisions::CollisionType getCollisionType() const override;
        [[nodiscard]] int getCollisionLayer() const override;

    protected:
        void _internal_onCreate() override;

        void _internal_onDestroy() override;
    };
} // core
// e2XD

#endif //INC_2XD2_ENGINE_COLLISIONBODY_H
