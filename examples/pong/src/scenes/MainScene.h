//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_MAINSCENE_H
#define INC_2XD2_ENGINE_MAINSCENE_H
#include "2XD2/framework/scene/Scene.h"
#include "2XD2/framework/scene/Camera.h"
#include "2XD2/framework/signals/SignalReceiver.h"

class MainScene : public e2XD::framework::Scene, public e2XD::framework::SignalReceiver
{
    public:
    e2XD::framework::Camera camera;
    MainScene();

    static constexpr float leftBound = -400.0f;
    static constexpr float rightBound = 400.0f;

    static void GameOver();
};


#endif //INC_2XD2_ENGINE_MAINSCENE_H