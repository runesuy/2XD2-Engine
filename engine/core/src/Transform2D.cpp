// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 14/12/2025.
//

#include "2XD2/core/Transform2D.h"

namespace e2XD::core
{
    const Vec2f& Transform2D::getPosition() const
    {
        return position;
    }

    void Transform2D::setPosition(const Vec2f& position)
    {
        this->position = position;
    }

    double Transform2D::getRotation() const
    {
        return rotation;
    }

    void Transform2D::setRotation(double rotation)
    {
        this->rotation = rotation;
    }

    const Vec2f& Transform2D::getScale() const
    {
        return scale;
    }

    void Transform2D::setScale(const Vec2f& scale)
    {
        this->scale = scale;
    }
} // core