#include "operation_node.hpp"

class AdditionNode : public OperationNode {
public:
    double evaluate() override {
        double ret = 0;
        for (auto &node: nodes) {
            ret += node->evaluate();

        }
        return ret;
    };

    // TODO: std::vector<Node *> &nodes as dangling reference
    explicit AdditionNode(std::vector<Node *> nodes) : OperationNode(nodes) {}

    virtual ~AdditionNode() override {
        for (auto node: nodes) {
            delete node;
        }
    }
};