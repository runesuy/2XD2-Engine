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
    ball->outOfBounds.connect(*this, &GameOver);
}

void MainScene::GameOver()
{
    std::cout << "Game Over!" << std::endl;
}
