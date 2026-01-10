//
// Created by rune-suy on 12/20/25.
//

#include "MainScene.h"

#include "../entities/opponent/Opponent.h"
#include "../entities/player/Player.h"
#include "../entities/ball/Ball.h"

MainScene::MainScene()
{
    auto* player = createSubNode<Player>();
    player->setGlobalPosition({-395, 0});
    auto* opponent = createSubNode<Opponent>();
    opponent->setGlobalPosition({395, 0});
    auto* ball = createSubNode<Ball>();
    ball->setGlobalPosition({0,0});
    camera.setGlobalPosition({0,0});
    setActiveCamera(&camera);
    opponent->linkBall(ball);
}
