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
