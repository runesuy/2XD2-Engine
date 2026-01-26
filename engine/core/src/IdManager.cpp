// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/25/26.
//

#include "2XD2/core/IdManager.h"


namespace e2XD::core
{
    unsigned int IdManager::getNextId()
    {
        return ++currentId;
    }
} // core
// e2XD
