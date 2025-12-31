//
// Created by runes on 14/12/2025.
//

#include "2XD2/core/Scene.h"

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

    void Scene::addSubNode(std::unique_ptr<Node> node)
    {
        Node::addSubNode(std::move(node));
        for (const auto& n : getSubNodes())
        {
            n->create();
        }
    }
} // e2XD