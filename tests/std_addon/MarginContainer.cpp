// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by copilot on 1/24/26.
//

#include "2XD2/std_addon/nodes/MarginContainer.h"
#include <gtest/gtest.h>

namespace e2XD::std_addon {

    class MarginContainerTest : public ::testing::Test {
    protected:
        MarginContainer container;
    };

    TEST_F(MarginContainerTest, DefaultMargins) {
        auto margins = container.getMargins();
        EXPECT_FLOAT_EQ(margins.left, 0.0f);
        EXPECT_FLOAT_EQ(margins.right, 0.0f);
        EXPECT_FLOAT_EQ(margins.top, 0.0f);
        EXPECT_FLOAT_EQ(margins.bottom, 0.0f);
    }

    TEST_F(MarginContainerTest, SetAllMarginsSame) {
        container.setMargins(10.0f);
        auto margins = container.getMargins();
        EXPECT_FLOAT_EQ(margins.left, 10.0f);
        EXPECT_FLOAT_EQ(margins.right, 10.0f);
        EXPECT_FLOAT_EQ(margins.top, 10.0f);
        EXPECT_FLOAT_EQ(margins.bottom, 10.0f);
    }

    TEST_F(MarginContainerTest, SetMarginsHorizontalVertical) {
        container.setMargins(15.0f, 20.0f);
        auto margins = container.getMargins();
        EXPECT_FLOAT_EQ(margins.left, 15.0f);
        EXPECT_FLOAT_EQ(margins.right, 15.0f);
        EXPECT_FLOAT_EQ(margins.top, 20.0f);
        EXPECT_FLOAT_EQ(margins.bottom, 20.0f);
    }

    TEST_F(MarginContainerTest, SetMarginsStruct) {
        MarginContainer::Margins m{5.0f, 10.0f, 15.0f, 20.0f};
        container.setMargins(m);
        auto margins = container.getMargins();
        EXPECT_FLOAT_EQ(margins.left, 5.0f);
        EXPECT_FLOAT_EQ(margins.right, 10.0f);
        EXPECT_FLOAT_EQ(margins.top, 15.0f);
        EXPECT_FLOAT_EQ(margins.bottom, 20.0f);
    }

    TEST_F(MarginContainerTest, SetIndividualMargins) {
        container.setMarginLeft(5.0f);
        container.setMarginRight(10.0f);
        container.setMarginTop(15.0f);
        container.setMarginBottom(20.0f);
        
        EXPECT_FLOAT_EQ(container.getMarginLeft(), 5.0f);
        EXPECT_FLOAT_EQ(container.getMarginRight(), 10.0f);
        EXPECT_FLOAT_EQ(container.getMarginTop(), 15.0f);
        EXPECT_FLOAT_EQ(container.getMarginBottom(), 20.0f);
    }

    TEST_F(MarginContainerTest, InnerSize) {
        container.setSize({100.0f, 80.0f});
        container.setMargins({10.0f, 15.0f, 5.0f, 10.0f}); // left, right, top, bottom
        
        EXPECT_FLOAT_EQ(container.getInnerWidth(), 75.0f); // 100 - 10 - 15
        EXPECT_FLOAT_EQ(container.getInnerHeight(), 65.0f); // 80 - 5 - 10
        
        auto innerSize = container.getInnerSize();
        EXPECT_FLOAT_EQ(innerSize.x, 75.0f);
        EXPECT_FLOAT_EQ(innerSize.y, 65.0f);
    }

    TEST_F(MarginContainerTest, InnerSizeCannotBeNegative) {
        container.setSize({10.0f, 10.0f});
        container.setMargins(50.0f); // Margins larger than size
        
        EXPECT_FLOAT_EQ(container.getInnerWidth(), 0.0f);
        EXPECT_FLOAT_EQ(container.getInnerHeight(), 0.0f);
    }

    TEST_F(MarginContainerTest, GetCombinedMinSizeIncludesMargins) {
        container.setMinSize({50.0f, 40.0f});
        container.setMargins({10.0f, 15.0f, 5.0f, 10.0f}); // left, right, top, bottom
        
        auto combined = container.getCombinedMinSize();
        EXPECT_FLOAT_EQ(combined.x, 75.0f); // 50 + 10 + 15
        EXPECT_FLOAT_EQ(combined.y, 55.0f); // 40 + 5 + 10
    }

} // namespace e2XD::std_addon
