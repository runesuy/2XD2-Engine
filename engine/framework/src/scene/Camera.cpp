//
// Created by runes on 15/12/2025.
//

#include "../../include/2XD2/framework/scene/Camera.h"


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
} // core
// e2XD