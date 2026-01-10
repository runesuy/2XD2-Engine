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
    template <typename T>
    concept IsScene = std::is_base_of_v<Scene, T>;

    /**
     * Scene node representing the root of a scene graph.
     */
    class Scene : public Node
    {
        const Camera* activeCamera = nullptr;

    public:
        Scene() = default;
        ~Scene() override = default;

        void setActiveCamera(const Camera* camera);
        [[nodiscard]] const Camera* getActiveCamera() const;
    };
} // e2XD

#endif //INC_2XD2_ENGINE_SCENE_H
