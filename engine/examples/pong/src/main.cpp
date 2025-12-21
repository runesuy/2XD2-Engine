//
// Created by rune-suy on 12/20/25.
//

#include "2XD2/framework/DefaultGameConfig.h"
#include "2XD2/framework/Game.h"
#include "scenes/MainScene.h"

using namespace e2XD::framework;

// This is a simple pong game example using the 2XD2 framework.


int main() {
    DefaultGameConfig config;
    Game game{config};

    game.setWindowTitle("pong example");
    game.createActiveScene<MainScene>();

    game.run();

    return 0;
}
