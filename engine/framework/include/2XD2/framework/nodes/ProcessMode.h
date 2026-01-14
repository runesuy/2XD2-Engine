// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/11/26.
//

#ifndef INC_2XD2_ENGINE_PROCESSMODE_H
#define INC_2XD2_ENGINE_PROCESSMODE_H


namespace e2XD::framework
{
    enum class ProcessMode
    {

        /**
         * Use the node's standard processing behavior: inherit pause state
         * and process mode from the parent unless explicitly overridden.
         * The node reacts normally to pause changes in its parent.
         */
        DEFAULT,

        /**
         * Always inherit the process mode from the parent node.
         */
        ALWAYS_INHERIT,

        /**
         * Does not react to pause changes in parent nodes.
         */
        STUBBORN,

        /**
         * Always call update on this node, regardless of its visibility or state.
         */
        ALWAYS_RUNNING
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_PROCESSMODE_H
