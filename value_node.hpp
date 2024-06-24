#pragma once

#include "node.hpp"

class ValueNode : public Node {
private:
    double value;

public:
    double evaluate() override {
        return value;
    };

    explicit ValueNode(double value) : value(value){};

    ValueNode() : value(0) {};

    void setValue(double value) {
        this->value = value;
    }
};
