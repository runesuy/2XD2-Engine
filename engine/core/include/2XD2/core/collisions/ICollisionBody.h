//
// Created by rune-suy on 12/22/25.
//

#ifndef INC_2XD2_ENGINE_ICOLLISIONBODY_H
#define INC_2XD2_ENGINE_ICOLLISIONBODY_H
#include "CollisionHandler.h"


namespace e2XD::core
{
    template<class Derived>
    class ICollisionBody
    {
    public:
        virtual ~ICollisionBody() = default;

        /**
         *
         * @param other
         * @return True if this body is colliding with the other body.
         */
        virtual bool areColliding(Derived* other)const =0;

        /**
         *
         * @return The collision type of this body.
         */
        [[nodiscard]] virtual CollisionHandler::CollisionType getCollisionType() const = 0;

        /**
         *
         * @return The collision layer of this body.
         */
        [[nodiscard]] virtual int getCollisionLayer() const = 0;

        /**
         * Called when this body starts colliding with another body.
         * @param other
         */
        virtual void onCollisionEnter(Derived* other) {}

        /**
         * Called when this body exits collision with another body.
         * @param other
         */
        virtual void onCollisionExit(Derived* other) {}
    };
} // core
// e2XD

#endif //INC_2XD2_ENGINE_ICOLLISIONBODY_H
