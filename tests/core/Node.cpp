//
// Created by runes on 14/12/2025.
//

#include "core/Node.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
namespace e2XD::core {
    class MockNode : public Node {
    public:
        MOCK_METHOD(void, onCreate, (), (override));
    };


    class CORE_Node : public ::testing::Test {
    protected:
        Node node;
        auto getNodesSize() const {return node.nodes.size();}

        const auto& getNodes() const {return node.nodes;}

        void setMarkedForDeletion(bool mark) {node.markedForDeletion = mark;}

        void setMarkedForDeletion(Node& n, bool mark) {n.markedForDeletion = mark;}

        void removeDestroyedSubNodes() {node.removeDestroyedSubNodes();}
    };

    TEST_F(CORE_Node, createSubNode) {
        node.createSubNode<testing::NiceMock<MockNode>>();
        ASSERT_EQ(getNodesSize(), 1);
    }

    TEST_F(CORE_Node, addSubNode) {
        auto mockNode = std::make_unique<testing::NiceMock<MockNode>>();
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


}