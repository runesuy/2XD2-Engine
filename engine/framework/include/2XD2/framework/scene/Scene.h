// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_SCENE_H
#define INC_2XD2_ENGINE_SCENE_H

#include "2XD2/framework/scene/Camera.h"
#include "2XD2/framework/nodes/Node.h"

namespace e2XD::framework
{
    class Scene;
    class DrawTarget;
    template <typename T>
    concept IsScene = std::is_base_of_v<Scene, T>;

    /**
     * Scene node representing the root of a scene graph.
     */
    class Scene : public Node
    {
        const Camera* activeCamera = nullptr;
        DrawTarget* drawTarget = nullptr;

    public:
        Scene();
        ~Scene() override = default;

        void setActiveCamera(const Camera* camera);
        [[nodiscard]] const Camera* getActiveCamera() const;

        void addSubNode(std::unique_ptr<Node> node) override;
    };
} // e2XD

#endif //INC_2XD2_ENGINE_SCENE_H
