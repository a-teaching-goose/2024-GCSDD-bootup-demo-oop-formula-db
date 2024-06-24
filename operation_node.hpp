#pragma once

#include "node.hpp"

class OperationNode : public Node {
protected:
    std::vector<Node *> nodes;

public:
    double evaluate() override = 0;

    OperationNode(std::vector<Node *> &nodes) : nodes(nodes) {};

    virtual ~OperationNode() override = default;
};
