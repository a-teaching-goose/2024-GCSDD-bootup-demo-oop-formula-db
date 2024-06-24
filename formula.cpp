#include "formula.hpp"
#include <sstream>

bool containsAsterisk(const std::string &input) {
    return input.find('*') != std::string::npos;
}

void split_string(const std::string &str, char deliminator, std::vector<std::string> &items) {
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, deliminator)) {
        items.push_back(item);
    }
}

Formula::Formula(const std::string &formula_str) {
    std::vector<std::string> adders;
    split_string(formula_str, '+', adders);

    std::vector<Node *> adding_elements;
    for (std::string &adder: adders) {
        if (!containsAsterisk(adder)) {
            auto v = new ValueNode();
            variables.push_back(v);
            adding_elements.push_back(v);
            continue;
        }

        std::vector<std::string> items;
        split_string(adder, '*', items);
        std::vector<Node *> multiply_parameters;
        for (auto var: items) {
            auto v = new ValueNode();
            variables.push_back(v);
            multiply_parameters.push_back(v);
        }

        adding_elements.push_back(new MultiplicationNode(multiply_parameters));
    }
    formula = new AdditionNode(adding_elements);
}

double Formula::calculate(const std::vector<double> &values) {
    for (std::size_t i = 0; i < values.size(); i++) {
        variables[i]->setValue(values[i]);
    }
    return formula->evaluate();
}

Formula::~Formula() {
    delete formula;
}
