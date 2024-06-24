#pragma once

class Node {
public:
    virtual double evaluate() = 0;
    virtual ~Node() = default;
};
