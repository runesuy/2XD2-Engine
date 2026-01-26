// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/25/26.
//

#ifndef INC_2XD2_ENGINE_NODEIDGENERATOR_H
#define INC_2XD2_ENGINE_NODEIDGENERATOR_H
#include "2XD2/core/IdManager.h"


namespace e2XD::framework
{
    class NodeIdManager
    {
        inline static core::IdManager _manager;
    public:
        using IdT = core::IdManager::IdT;

        static IdT getNextId();
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_NODEIDGENERATOR_H
