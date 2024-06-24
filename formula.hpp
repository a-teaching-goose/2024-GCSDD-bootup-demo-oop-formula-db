#pragma once

#include <string>
#include <vector>
#include "node.hpp"
#include "value_node.hpp"
#include "multiplication_node.hpp"
#include "addition_node.hpp"

class Formula {
private:
    Node *formula;
    std::vector<ValueNode *> variables;

public:
    Formula(const std::string &formula_str);

    ~Formula();

    double calculate(const std::vector<double> &values);
};