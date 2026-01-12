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