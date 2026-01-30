// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

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
    // create and position entities
    // PLAYER
    auto* player = createSubNode<Player>();
    player->setGlobalPosition({leftBound+player->getRenderable().getWidth()/2, 0});

    // OPPONENT
    auto* opponent = createSubNode<Opponent>();
    opponent->setGlobalPosition({rightBound - opponent->getRenderable().getWidth()/2, 0});

    // BALL
    auto* ball = createSubNode<Ball>();
    ball->setGlobalPosition({0,0});

    // CAMERA
    camera.setGlobalPosition({0,0});
    setActiveCamera(&camera);


    opponent->linkBall(ball); // let opponent track the ball

    gameOverScreen = createSubNode<GameOverScreen>(); // create game over screen

    // Connect the ball out of bounds signal to the game over function
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

