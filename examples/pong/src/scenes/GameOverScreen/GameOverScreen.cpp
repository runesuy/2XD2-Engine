// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/11/26.
//

#include "GameOverScreen.h"

#include "2XD2/framework/drawing/Renderer.h"
#include "2XD2/framework/input/Input.h"

GameOverScreen::GameOverScreen()
{
    visible = false;
    renderLayer = RenderLayer::UI;

    label = createSubNode<Label>();
    label->setRenderLayer(RenderLayer::UI);
    label->setText("Game Over");
    label->setLocalPosition({0, -30});

    restartLabel = createSubNode<Label>();
    restartLabel->setRenderLayer(RenderLayer::UI);
    restartLabel->setText("Press R to Restart");

    processMode = ProcessMode::ALWAYS_RUNNING;
}

void GameOverScreen::onUpdate(double deltaTime)
{
    if (!visible) return;

    if (Input::isKeyJustPressed(Key::R))
    {
        restartPressed.emit();
    }
}

