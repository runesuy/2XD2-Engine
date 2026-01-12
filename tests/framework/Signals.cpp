//
// Created by rune-suy on 1/11/26.
//
#include <gtest/gtest.h>

#include "2XD2/framework/signals/Signal.h"
#include "2XD2/framework/signals/SignalReceiver.h"


TEST(SignalConnectTest, ConnectAndEmit)
{
    using namespace e2XD::framework;

    class TestReceiver : public SignalReceiver {
    public:
        int value = 0;
        void onSignal(int v) {
            value = v;
        }
    };

    Signal<int> signal;
    auto receiver = std::make_shared<TestReceiver>();

    signal.connect(*receiver, [receiver](int v) { receiver->onSignal(v); });

    signal.emit(42);

    ASSERT_EQ(receiver->value, 42);
}

TEST(SignalConnectTest, ReceiverDestruction)
{
    using namespace e2XD::framework;

    class TestReceiver : public SignalReceiver {
    public:
        int value = 0;
        void onSignal(int v) {
            value = v;
        }
    };

    Signal<int> signal;
    auto receiver = new TestReceiver();

    signal.connect(*receiver, [receiver](int v) { receiver->onSignal(v); });

    // Destroy the receiver
    delete receiver;

    // Emit the signal
    signal.emit(42);

    // Since the receiver is destroyed, there's no way to check its value.
    // The test passes if no crash occurs.
    SUCCEED();
    // signal should not be called
    EXPECT_EQ(receiver->value, 0);
}