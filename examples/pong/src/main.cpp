// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/20/25.
//

#include "2XD2/framework/config/DefaultGameConfig.h"
#include "MyGame.h"
#include "scenes/MainScene.h"

using namespace e2XD::framework;

// This is a simple pong game example using the 2XD2 framework.


int main() {
    const DefaultGameConfig config;
    MyGame game{config};

    game.run();

    return 0;
}
