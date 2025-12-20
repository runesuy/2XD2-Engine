//
// Created by rune-suy on 12/20/25.
//

#include "MainScene.h"

#include "../entities/Opponent.h"
#include "../entities/Player.h"

MainScene::MainScene()
{
    auto* player = createSubNode<Player>();
    player->setGlobalPosition({-395, 0});
    auto* opponent = createSubNode<Opponent>();
    opponent->setGlobalPosition({395, 0});
    camera.setGlobalPosition({0,0});
    setActiveCamera(&camera);
}
