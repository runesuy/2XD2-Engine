//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/Game.h"

#include <filesystem>
#include <utility>

#include "../include/2XD2/framework/Time.h"
#include "../include/2XD2/framework/input/SFMLInputHandler.h"
#include "2XD2/core/exceptions/NotInitializedException.h"
#include "2XD2/framework/input/Input.h"
#include "2XD2/framework/resource_manager/Animations.h"
#include "2XD2/framework/resource_manager/Resources.h"
#include "2XD2/framework/resource_manager/Textures.h"
#include "../include/2XD2/framework/drawing/Renderer.h"
#include "2XD2/framework/resource_manager/Config.h"
#include "2XD2/framework/resource_manager/Fonts.h"


namespace e2XD::framework
{
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
        Resources::Config::closeConfig(CONFIG_FILE_PATH);
        Resources::Fonts::loadFont("<e2XD_default>", RESOURCES_PATH + "Roboto-VariableFont.ttf");
    }


    void Game::run()
    {
        running = true;
        window.setKeyRepeatEnabled(false);

        while (running && window.isOpen())
        {
            Time::tick();
            // Poll events
            Input::pollEvents();
            Collisions::checkCollisions();
            if (const auto& resized = Input::isWindowResized(); std::get<0>(resized))
            {
                sf::FloatRect visibleArea(0, 0, std::get<1>(resized), std::get<2>(resized));
                window.setView(sf::View(visibleArea));
            }

            if (Input::isWindowClosed()) window.close();
            const auto& windowResized = Input::isWindowResized();
            if (std::get<0>(windowResized))
            {
                Renderer::setWindowView(RenderLayer::UI, {std::get<1>(windowResized), std::get<2>(windowResized)});
                Renderer::setWindowView(RenderLayer::BACKGROUND, {
                                            std::get<1>(windowResized), std::get<2>(windowResized)
                                        });
                Renderer::setWindowView(RenderLayer::OVERLAY, {std::get<1>(windowResized), std::get<2>(windowResized)});
            }

            if (activeScene)
            {
                activeScene->update();
                Renderer::clearWindow();
                activeScene->draw();
            }
            if (activeScene)
            {
                if (const Camera* activeCamera = activeScene->getActiveCamera())
                {
                    Renderer::flush(activeCamera->getGlobalPosition(), activeCamera->getZoom());
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

    void Game::setActiveScene(std::unique_ptr<framework::Scene>&& scene)
    {
        activeScene = std::move(scene);
        activeScene->create();
    }
}
