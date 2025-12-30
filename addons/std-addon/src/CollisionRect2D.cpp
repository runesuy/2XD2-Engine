//
// Created by rune-suy on 12/29/25.
//

#include "../include/2XD2/std_addon/CollisionRect2D.h"


namespace e2XD::std_addon
{
    void CollisionRect2D::setWidth(const float width)
    {
        rectangle.width = width;
    }

    void CollisionRect2D::setHeight(const float height)
    {
        rectangle.height = height;
    }

    float CollisionRect2D::getWidth() const
    {
        return rectangle.width;
    }

    float CollisionRect2D::getHeight() const
    {
        return rectangle.height;
    }

    bool CollisionRect2D::areColliding(ICollisionBody* other) const
    {
        // Simple AABB collision detection for rectangular bodies
        if (const auto* otherRect = dynamic_cast<CollisionRect2D*>(other))
        {
            return rectangle.intersects(otherRect->rectangle);
        }
        return false;
    }

    void CollisionRect2D::setLocalPosition(const framework::Vec2f& position)
    {
        CollisionBody2D::setLocalPosition(position);
        rectangle.left = getGlobalPosition().x;
        rectangle.top = getGlobalPosition().y;
    }

    void CollisionRect2D::setGlobalPosition(const framework::Vec2f& position)
    {
        CollisionBody2D::setGlobalPosition(position);
        rectangle.left = position.x;
        rectangle.top = position.y;
    }
} // std_addon
// e2XD
