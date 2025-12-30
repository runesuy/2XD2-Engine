//
// Created by runes on 14/12/2025.
//

#include "2XD2/core/Node.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
namespace e2XD::framework {
    class MockNode : public Node {
    public:
        MOCK_METHOD(void, onCreate, (), (override));
        MOCK_METHOD(void, onDestroy, (), (override));
        MOCK_METHOD(void, onUpdate, (), (override));
        MOCK_METHOD(void, onDraw, (), (override));
    };


    class CORE_Node : public ::testing::Test {
    protected:
        Node node;
        [[nodiscard]] auto getNodesSize() const {return node.nodes.size();}

        [[nodiscard]] const auto& getNodes() const {return node.nodes;}

        void setMarkedForDeletion(bool mark) {node.markedForDeletion = mark;}

        static void setMarkedForDeletion(Node& n, bool mark) {n.markedForDeletion = mark;}

        void removeDestroyedSubNodes() {node.removeDestroyedSubNodes();}
    };

    TEST_F(CORE_Node, createSubNode) {
        node.createSubNode<testing::NiceMock<MockNode>>();
        ASSERT_EQ(getNodesSize(), 1);
    }

    TEST_F(CORE_Node, addSubNode) {
        auto mockNode = std::make_unique<testing::NiceMock<MockNode>>();
        auto* rawPtr = mockNode.get();
        EXPECT_CALL(*rawPtr,onCreate()).Times(1);
        node.addSubNode(std::move(mockNode));
        ASSERT_EQ(getNodesSize(), 1);
    }

    TEST_F(CORE_Node, removeDestroyedSubNodes) {
        auto mockNode1 = std::make_unique<testing::NiceMock<MockNode>>();
        auto mockNode2 = std::make_unique<testing::NiceMock<MockNode>>();
        node.addSubNode(std::move(mockNode1));
        node.addSubNode(std::move(mockNode2));
        ASSERT_EQ(getNodesSize(), 2);

        // Mark one node for deletion
        setMarkedForDeletion(*getNodes().front(), true);

        // Call the private method via a friend class
        removeDestroyedSubNodes();

        ASSERT_EQ(getNodesSize(), 1);
    }

    TEST_F(CORE_Node, destroyCallsOnDestroy) {
        auto mockNode = std::make_unique<testing::NiceMock<MockNode>>();
        auto* rawPtr = mockNode.get();
        node.addSubNode(std::move(mockNode));
        EXPECT_CALL(*rawPtr, onDestroy()).Times(1);
        node.destroy();
    }

    TEST_F(CORE_Node, createCallsOnCreate) {
        auto mockNode = std::make_unique<testing::NiceMock<MockNode>>();
        auto * rawPtr = mockNode.get();
        node.addSubNode(std::move(mockNode));
        EXPECT_CALL(*rawPtr, onCreate()).Times(1);
        node.create();
    }

    TEST_F(CORE_Node, updateCallsOnUpdate) {
        auto mockNode = std::make_unique<testing::NiceMock<MockNode>>();
        auto* rawPtr = mockNode.get();
        node.addSubNode(std::move(mockNode));
        EXPECT_CALL(*rawPtr, onUpdate()).Times(1);
        node.update();
    }

    TEST_F(CORE_Node, drawCallsOnDraw) {
        auto mockNode = std::make_unique<testing::NiceMock<MockNode>>();
        auto* rawPtr = mockNode.get();
        node.addSubNode(std::move(mockNode));
        EXPECT_CALL(*rawPtr, onDraw()).Times(1);
        node.draw();
    }

}