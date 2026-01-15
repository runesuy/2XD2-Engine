// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_PLAYER_H
#define INC_2XD2_ENGINE_PLAYER_H
#include "2XD2/std_addon/CollisionRect2D.h"
#include "2XD2/std_addon/Rectangle2D.h"


class Player : public e2XD::std_addon::Rectangle2D
{
    float speed = 300.0f;
    static constexpr float minY = -280.0f;
    static constexpr float maxY = 280.0f;
public:
    Player();

protected:
    void onUpdate(double deltaTime) override;
};


#endif //INC_2XD2_ENGINE_PLAYER_H