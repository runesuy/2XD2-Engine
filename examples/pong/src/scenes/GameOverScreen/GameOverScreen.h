//
// Created by rune-suy on 1/11/26.
//

#ifndef INC_2XD2_ENGINE_GAMEOVERSCREEN_H
#define INC_2XD2_ENGINE_GAMEOVERSCREEN_H
#include "2XD2/framework/nodes/Node2D.h"
#include "2XD2/std_addon/Rectangle2D.h"
#include "2XD2/std_addon/Label.h"

using namespace e2XD::framework;
using namespace e2XD::std_addon;

class GameOverScreen : public Node2D
{
    Rectangle2D* background;
    Label* label;
public:
    GameOverScreen();

protected:
    void onDraw() override;
};


#endif //INC_2XD2_ENGINE_GAMEOVERSCREEN_H