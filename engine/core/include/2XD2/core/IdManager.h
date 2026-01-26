// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/25/26.
//

#ifndef INC_2XD2_ENGINE_IDMANAGER_H
#define INC_2XD2_ENGINE_IDMANAGER_H


namespace e2XD::core
{
    class IdManager
    {
        unsigned int currentId = 0;
    public:
        using IdT = unsigned int;
        static constexpr IdT INVALID_ID = 0;

        /**
         * Get the next unique ID.
         * @return The next unique ID.
         */
        IdT getNextId();
    };
} // core
// e2XD

#endif //INC_2XD2_ENGINE_IDMANAGER_H
