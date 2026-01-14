// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/scene/Scene.h"

namespace e2XD::framework
{
    const Camera* Scene::getActiveCamera() const
    {
        return activeCamera;
    }

    void Scene::setActiveCamera(const Camera* camera)
    {
        activeCamera = camera;
    }
} // e2XD