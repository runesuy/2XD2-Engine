//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_GAME_H
#define INC_2XD2_ENGINE_GAME_H
#include <memory>

#include "renderer/Renderer.h"
#include "core/Scene.h"

namespace e2XD::framework {
    class Game {
        renderer::Renderer renderer;
        std::unique_ptr<core::Scene> activeScene;

    };

    void run();
}

#endif //INC_2XD2_ENGINE_GAME_H
