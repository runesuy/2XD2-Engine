// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

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
        std::unique_ptr<Scene> newActiveScene = nullptr;
        sf::RenderWindow window = {sf::VideoMode(800, 600), "2XD2 Game"};

        const std::string CONFIG_FILE_PATH;
        std::string RESOURCES_PATH;

        int _physicsTicksPerSecond = 120;
        bool _useVSync = true;

    public:
        inline static const std::string DEFAULT_FONT_NAME = "__e2XD_default__";

    private:
        // Relative from engine resource folder
        inline static const std::string DEFAULT_FONT_DEFAULT_PATH = "Roboto-VariableFont.ttf";

        inline static bool running = false;

    public:
        explicit Game(const IGameConfig& config, std::string configFilePath = "2xd_config.json");

        void run();

        void setWindowTitle(const std::string& title);

        /**
         * Set the number of physics ticks (updates) per second.
         * A higher number results in more frequent physics updates, leading to smoother and more accurate physics simulations,
         * but may increase CPU usage. A lower number reduces CPU load but may result in less accurate physics behavior.
         * The default value is 120 ticks per second.
         * @param ticksPerSecond The desired number of physics ticks per second.
         */
        void setPhysicsTicksPerSecond(int ticksPerSecond);

        /**
         * Enable vertical synchronization (VSync) for the game window.
         * This synchronizes the frame rate of the game with the refresh rate of the monitor,
         * reducing screen tearing and providing a smoother visual experience.
         * This also includes the drawing and update.
         * Does not influence the physics update rate.
         */
        void enableVSync();

        /**
         * Disable vertical synchronization (VSync) for the game window.
         * This allows the game to run at an uncapped frame rate, which may lead to screen tearing
         * but can improve performance on some systems.
         * Does not influence the physics update rate.
         */
        void disableVSync();

        /**
         * Set the active scene for the game.
         * If the game is currently running, the new scene will be activated at the start of the next frame
         * to avoid destroying the current scene while it's still in use.
         * @param scene
         */
        void setActiveScene(std::unique_ptr<Scene>&& scene);

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
