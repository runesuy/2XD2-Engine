// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by copilot on 1/24/26.
//

#include "2XD2/std_addon/nodes/Control.h"
#include <gtest/gtest.h>

namespace e2XD::std_addon {

    class ControlTest : public ::testing::Test {
    protected:
        Control control;
    };

    TEST_F(ControlTest, DefaultSize) {
        EXPECT_FLOAT_EQ(control.getSize().x, 0.0f);
        EXPECT_FLOAT_EQ(control.getSize().y, 0.0f);
    }

    TEST_F(ControlTest, SetSize) {
        control.setSize({100.0f, 50.0f});
        EXPECT_FLOAT_EQ(control.getWidth(), 100.0f);
        EXPECT_FLOAT_EQ(control.getHeight(), 50.0f);
    }

    TEST_F(ControlTest, SetWidth) {
        control.setWidth(150.0f);
        EXPECT_FLOAT_EQ(control.getWidth(), 150.0f);
    }

    TEST_F(ControlTest, SetHeight) {
        control.setHeight(75.0f);
        EXPECT_FLOAT_EQ(control.getHeight(), 75.0f);
    }

    TEST_F(ControlTest, SetMinSize) {
        control.setMinSize({50.0f, 25.0f});
        EXPECT_FLOAT_EQ(control.getMinSize().x, 50.0f);
        EXPECT_FLOAT_EQ(control.getMinSize().y, 25.0f);
    }

    TEST_F(ControlTest, SizeRespectsMinSize) {
        control.setMinSize({50.0f, 50.0f});
        control.setSize({30.0f, 30.0f}); // Try to set smaller than min
        EXPECT_FLOAT_EQ(control.getWidth(), 50.0f);
        EXPECT_FLOAT_EQ(control.getHeight(), 50.0f);
    }

    TEST_F(ControlTest, MinSizeUpdatesCurrentSize) {
        control.setSize({30.0f, 30.0f});
        control.setMinSize({50.0f, 50.0f}); // Setting min larger than current
        EXPECT_FLOAT_EQ(control.getWidth(), 50.0f);
        EXPECT_FLOAT_EQ(control.getHeight(), 50.0f);
    }

    TEST_F(ControlTest, GetCombinedMinSize) {
        control.setMinSize({100.0f, 75.0f});
        auto combined = control.getCombinedMinSize();
        EXPECT_FLOAT_EQ(combined.x, 100.0f);
        EXPECT_FLOAT_EQ(combined.y, 75.0f);
    }

} // namespace e2XD::std_addon
