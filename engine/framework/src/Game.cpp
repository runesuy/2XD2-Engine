//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/Game.h"

#include "2XD2/core/Time.h"
#include "../include/2XD2/framework/input/SFMLInputHandler.h"
#include "2XD2/core/exceptions/NotInitializedException.h"
#include "2XD2/framework/input/Input.h"
#include "2XD2/framework/resource_manager/Animations.h"
#include "2XD2/framework/resource_manager/Resources.h"
#include "2XD2/framework/resource_manager/Textures.h"
#include "2XD2/renderer/Renderer.h"


namespace e2XD::framework
{
    Game::Game(IGameConfig& config)
    {
        auto inputHandler = config.getInputHandler();
        if (!inputHandler) throw NotInitializedException("GameConfig.getInputHandler()",
                                                         "Game::Game(IGameConfig& config)");
        config.getInputHandler()->initialize(&window);
        Input::initialize(config.getInputHandler());
        Resources::Textures::initialize(config.getTextureManager());
        Resources::Animations::initialize(config.getAnimationManager());
    }


    void Game::run()
    {
        running = true;
        window.setKeyRepeatEnabled(false);

        renderer::Renderer::getInstance()->initialize(&window);

        while (running && window.isOpen())
        {
            core::Time::tick();
            // Poll events
            Input::pollEvents();
            if (const auto& resized = Input::isWindowResized(); std::get<0>(resized))
            {
                sf::FloatRect visibleArea(0, 0, std::get<1>(resized), std::get<2>(resized));
                window.setView(sf::View(visibleArea));
            }

            if (Input::isWindowClosed()) window.close();

            if (activeScene)
            {
                activeScene->update();
                const auto& renderer = renderer::Renderer::getInstance();
                renderer->clearWindow();
                const auto& activeCamera = activeScene->getActiveCamera();
                core::Vec2f cameraPos = {0, 0};
                activeScene->draw();
            }
            renderer::Renderer::getInstance()->flush(activeScene ? activeScene->getActiveCamera() : nullptr);
            window.display();
            Input::newFrame();
        }
    }

    void Game::setWindowTitle(const std::string& title)
    {
        window.setTitle(title);
    }

    void Game::setActiveScene(std::unique_ptr<core::Scene>&& scene)
    {
        activeScene = std::move(scene);
        activeScene->create();
    }
}
