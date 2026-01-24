// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/11/26.
//

#ifndef INC_2XD2_ENGINE_SIGNAL_H
#define INC_2XD2_ENGINE_SIGNAL_H
#include <functional>
#include <vector>
#include <algorithm>
#include "SignalReceiver.h"

namespace e2XD::framework
{
    /**
     * A signal that can be emitted to notify connected receivers.
     * Given arguments are forwarded to the connected callbacks.
     * @tparam Args
     */
    template <typename... Args>
    class Signal
    {
    public:
        using CallBack = std::function<void(Args...)>;

    private:
        // {receiver, lifeTimeToken, callback}
        std::vector<std::tuple<SignalReceiver*, std::weak_ptr<int>, CallBack>> _callbacks;

        friend class SignalReceiver;

    public:
        Signal() = default;
        virtual ~Signal() = default;

        /**
         * Emit the signal, calling all connected callbacks with the given arguments.
         * @param args
         */
        void emit(Args... args);

        /**
         * Connect a receiver's callback to this signal.
         * @param receiver
         * @param callback
         */
        void connect(SignalReceiver& receiver, const CallBack& callback);

        /**
         * Disconnect all callbacks associated with the given receiver.
         * @param receiver
         */
        void disconnect(SignalReceiver& receiver);
    };

    // Implementation

    template <typename... Args>
    void Signal<Args...>::connect(SignalReceiver& receiver, const CallBack& callback)
    {
        _callbacks.push_back({&receiver, receiver._lifeTimeToken, callback});
    }

    template <typename... Args>
    void Signal<Args...>::disconnect(SignalReceiver& receiver)
    {
        _callbacks.erase(std::remove_if(_callbacks.begin(), _callbacks.end(), [receiver](auto& pair)
        {
            return pair.first.lock().get() == &receiver;
        }));
    }

    template <typename... Args>
    void Signal<Args...>::emit(Args... args)
    {
        for (auto it = _callbacks.begin(); it != _callbacks.end();)
        {
            if (auto& lifeTimeToken = std::get<1>(*it); lifeTimeToken.expired())
            {
                it = _callbacks.erase(it); // Remove expired receivers
            }
            else
            {
                std::get<2>(*it)(args...); // Call the callback
                ++it;
            }
        }
    }
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_SIGNAL_H
