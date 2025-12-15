//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_GAME_H
#define INC_2XD2_ENGINE_GAME_H
#include <memory>

#include "2XD2/renderer/Renderer.h"
#include "2XD2/core/Scene.h"
#include <SFML/Graphics.hpp>

namespace e2XD::framework {
    class Game {
        renderer::Renderer renderer;
        std::unique_ptr<core::Scene> activeScene;
        sf::RenderWindow window = {sf::VideoMode(800, 600), "2XD2 Game"};

        inline static bool running = false;

    public:
        void run();
    };

}

#endif //INC_2XD2_ENGINE_GAME_H
