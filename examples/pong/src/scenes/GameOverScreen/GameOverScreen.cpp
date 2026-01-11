//
// Created by rune-suy on 1/11/26.
//

#include "GameOverScreen.h"

#include "2XD2/framework/drawing/Renderer.h"

GameOverScreen::GameOverScreen()
{
    visible = false;
    renderLayer = RenderLayer::UI;
    background = createSubNode<Rectangle2D>();
    background->setRenderLayer(RenderLayer::UI);
    background->setGlobalPosition({
        static_cast<float>(Renderer::getWindowSize().x) / 2, static_cast<float>(Renderer::getWindowSize().y) / 2
    });
    background->setFillColor(sf::Color(250, 0, 0, 150));
    background->setSize({1200.0f, 800.0f});

    label = createSubNode<Label>();
    label->setRenderLayer(RenderLayer::UI);
    label->setGlobalPosition({
        static_cast<float>(Renderer::getWindowSize().x) / 2, static_cast<float>(Renderer::getWindowSize().y) / 2
    });
    label->setText("Game Over");
}

void GameOverScreen::onDraw()
{
    background->setGlobalPosition({
        static_cast<float>(Renderer::getWindowSize().x) / 2, static_cast<float>(Renderer::getWindowSize().y) / 2
    });

    label->setGlobalPosition({
        static_cast<float>(Renderer::getWindowSize().x) / 2, static_cast<float>(Renderer::getWindowSize().y) / 2
    });
}
