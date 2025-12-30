//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_GAME_H
#define INC_2XD2_ENGINE_GAME_H
#include <memory>

#include "2XD2/core/Scene.h"
#include <SFML/Graphics.hpp>
#include "IGameConfig.h"

namespace e2XD::framework
{
    class Game
    {
        std::unique_ptr<framework::Scene> activeScene;
        sf::RenderWindow window = {sf::VideoMode(800, 600), "2XD2 Game"};

        inline static bool running = false;

    public:
        explicit Game(IGameConfig& config);
        void run();

        void setWindowTitle(const std::string& title);

        void setActiveScene(std::unique_ptr<framework::Scene>&& scene);

        template <framework::IsScene T>
        T* createActiveScene();
    };

    template <framework::IsScene T>
    T* Game::createActiveScene()
    {
        auto scene = new T();
        auto uniqueScene = std::unique_ptr<T>(scene);
        setActiveScene(std::move(uniqueScene));
        return scene;
    }
}

#endif //INC_2XD2_ENGINE_GAME_H
