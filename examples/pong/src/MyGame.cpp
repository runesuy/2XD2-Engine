// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/13/26.
//

#include "MyGame.h"
#include "scenes/MainScene.h"


MyGame::MyGame(const IGameConfig& config) : Game(config)
{
    setWindowTitle("pong example");
    createActiveScene<MainScene>();
    GameOverScreen::restartPressed.connect(*this, [this]()
    {
        restartGame();
    });
}

void MyGame::restartGame()
{
    createActiveScene<MainScene>();
}
