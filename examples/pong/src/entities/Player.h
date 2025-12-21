//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_PLAYER_H
#define INC_2XD2_ENGINE_PLAYER_H
#include "2XD2/framework/nodes/Rectangle2D.h"


class Player : public e2XD::framework::Rectangle2D
{
    float speed = 300.0f;
    static constexpr float minY = -280.0f;
    static constexpr float maxY = 280.0f;
public:
    Player();

protected:
    void onUpdate() override;
};


#endif //INC_2XD2_ENGINE_PLAYER_H