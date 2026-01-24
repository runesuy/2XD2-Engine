// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 15/12/2025.
//

#include "2XD2/framework/scene/Camera.h"


namespace e2XD::framework
{
    float Camera::getZoom() const
    {
        return zoom;
    }

    void Camera::setZoom(const float newZoom)
    {
        zoom = newZoom;
    }

    const core::Vec2f& Camera::getSize() const
    {
        return size;
    }

    void Camera::setSize(const core::Vec2f& newSize)
    {
        size = newSize;
    }
} // core
// e2XD