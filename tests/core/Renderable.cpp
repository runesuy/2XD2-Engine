//
// Created by runes on 21/12/2025.
//

#include "2XD2/core/Renderable.h"
#include <gtest/gtest.h>
#include <vector>

using namespace e2XD::core;

class TestRenderable : public Renderable {
public:
    std::vector<std::string> calls;
    void _internal_onDraw() override { calls.emplace_back("internal"); }
    void onDraw() override { calls.emplace_back("user"); }
};

TEST(CORE_Renderable, DrawInvokesInternalThenUser) {
    TestRenderable r;
    r.draw();
    ASSERT_EQ(r.calls.size(), 2u);
    EXPECT_EQ(r.calls[0], "internal");
    EXPECT_EQ(r.calls[1], "user");
}
