//
// Created by rune-suy on 12/22/25.
//

#ifndef INC_2XD2_ENGINE_COLLISIONBODY_H
#define INC_2XD2_ENGINE_COLLISIONBODY_H
#include "ICollisionHandler.h"
#include "ICollisionBody.h"
#include "2XD2/core/Node2D.h"


namespace e2XD::core
{
    /**
     * A collision body in 2D space.
     */
    class CollisionBody2D  : ICollisionBody<CollisionBody2D>, public Node2D
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
        ICollisionHandler::CollisionType collisionType = ICollisionHandler::CollisionType::DYNAMIC;
    public:
        CollisionBody2D() = default;
        ~CollisionBody2D() override = default;


        [[nodiscard]] ICollisionHandler::CollisionType getCollisionType() const override;
        [[nodiscard]] int getCollisionLayer() const override;
    };
} // core
// e2XD

#endif //INC_2XD2_ENGINE_COLLISIONBODY_H
