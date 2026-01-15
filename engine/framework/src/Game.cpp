// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/Game.h"
#include <utility>
#include "2XD2/framework/Time.h"
#include "2XD2/framework/input/SFMLInputHandler.h"
#include "2XD2/core/exceptions/NotInitializedException.h"
#include "2XD2/framework/input/Input.h"
#include "2XD2/framework/resource_manager/Animations.h"
#include "2XD2/framework/resource_manager/Resources.h"
#include "2XD2/framework/resource_manager/Textures.h"
#include "2XD2/framework/drawing/Renderer.h"
#include "2XD2/framework/resource_manager/Config.h"
#include "2XD2/framework/resource_manager/Fonts.h"


namespace e2XD::framework
{
    using internal::Time;

    Game::Game(const IGameConfig& config, std::string configFilePath)
        : CONFIG_FILE_PATH(std::move(configFilePath))
    {
        if (const auto inputHandler = config.getInputHandler(); !inputHandler)
            throw core::NotInitializedException("GameConfig.getInputHandler()",
                                                "Game::Game(IGameConfig& config)");
        config.getInputHandler()->initialize(&window);
        Input::initialize(config.getInputHandler());
        Resources::Textures::initialize(config.getTextureManager());
        Resources::Animations::initialize(config.getAnimationManager());
        Collisions::initialize(config.getCollisionHandler());
        Renderer::initialize(config.getRenderer());
        Renderer::initialize(&window);
        Resources::Fonts::initialize(config.getFontManager());
        Resources::Config::initialize(config.getConfigManager());

        // load resources
        auto json = Resources::Config::loadConfig(CONFIG_FILE_PATH);
        RESOURCES_PATH = json.at("engine-resources").get<std::string>();
        if (json.contains("default-font"))
        {
            const auto& defaultFontPath = json.at("default-font").get<std::string>();
            Resources::Fonts::loadFont(DEFAULT_FONT_NAME, defaultFontPath);
        }
        else Resources::Fonts::loadFont(DEFAULT_FONT_NAME, RESOURCES_PATH + DEFAULT_FONT_DEFAULT_PATH);
        Resources::Config::closeConfig(CONFIG_FILE_PATH);
    }


    void Game::run()
    {
        running = true;
        window.setKeyRepeatEnabled(false);
        window.setVerticalSyncEnabled(_useVSync);

        double accumulator = 0.0; // For fixed timestep logic

        while (running && window.isOpen())
        {
            // If there's a new active scene, switch to it
            if (newActiveScene)
            {
                activeScene = std::move(newActiveScene);
                activeScene->create();
                newActiveScene = nullptr;
            }

            Time::tick();
            accumulator += Time::getDeltaTime();

            Collisions::checkCollisions();
            if (const auto& resized = Input::isWindowResized(); std::get<0>(resized))
            {
                sf::FloatRect visibleArea(0, 0, std::get<1>(resized), std::get<2>(resized));
                window.setView(sf::View(visibleArea));
            }

            if (Input::isWindowClosed()) window.close();

            if (activeScene)
            {
                // Fixed timestep physics update
                const double physicsDeltaTime = 1.0 / _physicsTicksPerSecond;
                while (accumulator >= physicsDeltaTime)
                {
                    // Poll events
                    Input::pollEvents();
                    activeScene->physicsUpdate(physicsDeltaTime);
                    accumulator -= physicsDeltaTime;
                }

                // Variable timestep update
                activeScene->update(Time::getDeltaTime());
                // Variable timestep drawing (maybe vSynced)
                Renderer::clearWindow();
                activeScene->draw();
            }
            if (activeScene)
            {
                if (const Camera* activeCamera = activeScene->getActiveCamera())
                {
                    Renderer::flush(activeCamera->getGlobalPosition(), activeCamera->getSize(), activeCamera->getZoom());
                }
            }
            window.display();
            Input::newFrame();
        }
    }

    void Game::setWindowTitle(const std::string& title)
    {
        window.setTitle(title);
    }

    void Game::setActiveScene(std::unique_ptr<Scene>&& scene)
    {
        // If the game is running, set the new scene to be activated at the start of the next frame
        // This is to avoid the destruction of the current scene while it's still being used
        if (!running)
        {
            activeScene = std::move(scene);
            activeScene->create();
        }
        else
        {
            newActiveScene = std::move(scene);
        }
    }

    void Game::enableVSync()
    {
        _useVSync = true;
        window.setVerticalSyncEnabled(true);
    }

    void Game::disableVSync()
    {
        _useVSync = false;
        window.setVerticalSyncEnabled(false);
    }

    void Game::setPhysicsTicksPerSecond(int ticksPerSecond)
    {
        _physicsTicksPerSecond = ticksPerSecond;
    }
}
