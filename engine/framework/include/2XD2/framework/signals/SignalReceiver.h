// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/11/26.
//

#ifndef INC_2XD2_ENGINE_SIGNALRECEIVER_H
#define INC_2XD2_ENGINE_SIGNALRECEIVER_H
#include <memory>

namespace e2XD::framework
{
    /**
     * Base class for objects that can receive signals.
     */
    class SignalReceiver
    {
        std::shared_ptr<int> _lifeTimeToken = std::make_shared<int>(0);

        template <typename... Args>
        friend class Signal;

    public:
        SignalReceiver() = default;
        virtual ~SignalReceiver()=default;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_SIGNALRECEIVER_H
