//
// Created by runes on 15/12/2025.
//

#include "2XD2/core/Camera.h"


namespace e2XD::core
{
    float Camera::getZoom() const
    {
        return zoom;
    }

    void Camera::setZoom(const float newZoom)
    {
        zoom=newZoom;
    }


} // core
// e2XD
