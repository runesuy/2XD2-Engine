// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_MAINSCENE_H
#define INC_2XD2_ENGINE_MAINSCENE_H
#include "2XD2/framework/scene/Scene.h"
#include "2XD2/framework/scene/Camera.h"
#include "2XD2/framework/signals/SignalReceiver.h"
#include "GameOverScreen/GameOverScreen.h"

class MainScene : public Scene, public SignalReceiver
{
    public:
    Camera camera;
    MainScene();

    static constexpr float leftBound = -400.0f;
    static constexpr float rightBound = 400.0f;

    void GameOver();

    bool isGameOver = false;
    GameOverScreen* gameOverScreen = nullptr;

};


#endif //INC_2XD2_ENGINE_MAINSCENE_H