//
// Created by rune-suy on 1/13/26.
//

#ifndef INC_2XD2_ENGINE_MYGAME_H
#define INC_2XD2_ENGINE_MYGAME_H
#include "2XD2/framework/Game.h"
#include "2XD2/framework/signals/SignalReceiver.h"


class MyGame : public e2XD::framework::Game, public e2XD::framework::SignalReceiver
{
public:
    explicit MyGame(const e2XD::framework::IGameConfig& config);

    void restartGame();
};


#endif //INC_2XD2_ENGINE_MYGAME_H
