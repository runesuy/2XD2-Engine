// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/13/26.
//

#include "PongGame.h"
#include "scenes/MainScene.h"
#include "scenes/GameOverScreen/GameOverScreen.h"


PongGame::PongGame(const IGameConfig& config) : Game(config)
{
    setWindowTitle("pong example");

    // In order fot the game to draw or simulate,
    // we first need to create and assign a scene
    createActiveScene<MainScene>();

    // Bind restart signal
    GameOverScreen::restartPressed.connect(*this, [this]()
    {
        restartGame();
    });
}

void PongGame::restartGame()
{
    createActiveScene<MainScene>();
}
