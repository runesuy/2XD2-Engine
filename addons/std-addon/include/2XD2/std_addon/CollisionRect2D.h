//
// Created by rune-suy on 12/29/25.
//

#ifndef INC_2XD2_ENGINE_COLLISIONRECT2D_H
#define INC_2XD2_ENGINE_COLLISIONRECT2D_H
#include <SFML/Graphics/Rect.hpp>

#include "2XD2/framework/collisions/CollisionBody2D.h"


namespace e2XD::std_addon
{
    /**
     * A rectangular collision body in 2D space.
     */
    class CollisionRect2D : public framework::CollisionBody2D
    {
        sf::Rect<float> rectangle;
    public:
        CollisionRect2D() = default;
        ~CollisionRect2D() override = default;

        void setWidth(float width);
        void setHeight(float height);
        [[nodiscard]] float getWidth() const;
        [[nodiscard]] float getHeight() const;

        bool areColliding(ICollisionBody* other) const override;
        void setGlobalPosition(const framework::Vec2f& position) override;
        void setLocalPosition(const framework::Vec2f& position) override;
    };
} // std_addon
// e2XD

#endif //INC_2XD2_ENGINE_COLLISIONRECT2D_H
