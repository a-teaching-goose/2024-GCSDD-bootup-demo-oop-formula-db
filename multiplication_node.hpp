#include "operation_node.hpp"

class MultiplicationNode : public OperationNode {
public:
    double evaluate() override {
        double ret = 1;
        for (auto &node: nodes) {
            ret *= node->evaluate();
        }
        return ret;
    };

    MultiplicationNode(std::vector<Node *> nodes) : OperationNode(nodes) {}

    virtual ~MultiplicationNode() {
        for (auto node: nodes) {
            delete node;
        }
    }
};
