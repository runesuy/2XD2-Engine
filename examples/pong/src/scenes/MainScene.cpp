//
// Created by rune-suy on 12/20/25.
//

#include "MainScene.h"

#include <iostream>

#include "../entities/opponent/Opponent.h"
#include "../entities/player/Player.h"
#include "../entities/ball/Ball.h"

MainScene::MainScene()
{
    auto* player = createSubNode<Player>();
    player->setGlobalPosition({leftBound+player->getWidth()/2, 0});
    auto* opponent = createSubNode<Opponent>();
    opponent->setGlobalPosition({rightBound - opponent->getWidth()/2, 0});
    auto* ball = createSubNode<Ball>();
    ball->setGlobalPosition({0,0});
    camera.setGlobalPosition({0,0});
    setActiveCamera(&camera);
    opponent->linkBall(ball);
    gameOverScreen = createSubNode<GameOverScreen>();
    ball->outOfBounds.connect(*this, [this]()
    {
        GameOver();
    });
}

void MainScene::GameOver()
{
    isGameOver = true;
    setPaused(true);
    gameOverScreen->setVisible(true);
}

