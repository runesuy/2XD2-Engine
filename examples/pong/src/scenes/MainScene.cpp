//
// Created by rune-suy on 12/20/25.
//

#include "MainScene.h"

#include "../entities/Opponent.h"
#include "../entities/Player.h"
#include "../entities/Ball.h"

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
}
