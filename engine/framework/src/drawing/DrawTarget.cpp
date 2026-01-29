// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/25/26.
//

#include "../../include/2XD2/framework/drawing/DrawTarget.h"

#include "2XD2/framework/drawing/Renderer.h"

namespace e2XD::framework
{
    void DrawTarget::setSize(const unsigned int width, const unsigned int height)
    {
        if (size.x != width || size.y != height)
        {
            size.x = width;
            size.y = height;
            onSizeChanged.emit();
        }
    }

    const core::Vec2<unsigned int>& DrawTarget::getSize() const
    {
        return size;
    }

    void DrawTarget::setActiveCamera(const Camera* camera)
    {
        if (activeCamera != camera)
        {
            activeCamera = camera;
            onActiveCameraChanged.emit();
        }
        else activeCamera = camera;
    }

    const Camera* DrawTarget::getActiveCamera() const
    {
        return activeCamera;
    }

    void DrawTarget::_internal_onCreate()
    {
        Renderer::registerDrawTarget(this);
        Node::_internal_onCreate();
    }
}
