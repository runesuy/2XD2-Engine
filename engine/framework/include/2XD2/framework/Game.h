//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_GAME_H
#define INC_2XD2_ENGINE_GAME_H
#include <memory>

#include "scene/Scene.h"
#include <SFML/Graphics.hpp>
#include "config/IGameConfig.h"

namespace e2XD::framework
{
    class Game
    {
        std::unique_ptr<Scene> activeScene;
        sf::RenderWindow window = {sf::VideoMode(800, 600), "2XD2 Game"};

        const std::string CONFIG_FILE_PATH;
        std::string RESOURCES_PATH;

    public:
        inline static const std::string DEFAULT_FONT_NAME = "<e2XD_default>";

    private:
        // Relative from engine resource folder
        inline static const std::string DEFAULT_FONT_DEFAULT_PATH = "Roboto-VariableFont.ttf";

        inline static bool running = false;

    public:
        explicit Game(const IGameConfig& config, std::string configFilePath = "2xd_config.json");

        void run();

        void setWindowTitle(const std::string& title);

        void setActiveScene(std::unique_ptr<framework::Scene>&& scene);

        template <IsScene T>
        T* createActiveScene();
    };

    template <IsScene T>
    T* Game::createActiveScene()
    {
        auto scene = new T();
        auto uniqueScene = std::unique_ptr<T>(scene);
        setActiveScene(std::move(uniqueScene));
        return scene;
    }
}

#endif //INC_2XD2_ENGINE_GAME_H
