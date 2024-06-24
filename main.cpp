#include <iostream>
#include "formula.hpp"

double verify1(std::vector<double> &data);

double verify2(std::vector<double> &data);

double verify3(std::vector<double> &data);

double verify4(std::vector<double> &data);

int main() {
    auto f1 = new Formula("x1 + x2 * x3 + x4 * x5 * x6 + x7");
    std::vector<double> data1 = {1, 2, 3, 4, 5, 6, 7};
    printf("%f\n", f1->calculate(data1));
    printf("%f\n", verify1(data1));
    delete f1;

    auto f2 = new Formula("x1 + x2 + x3 + x4");
    std::vector<double> data2 = {1, 2, 3, 4};
    printf("%f\n", f2->calculate(data2));
    printf("%f\n", verify2(data2));
    delete f2;

    auto f3 = new Formula("x1 * x2 * x3 * x4");
    std::vector<double> data3 = {1, 2, 3, 4};
    printf("%f\n", f3->calculate(data3));
    printf("%f\n", verify3(data3));
    delete f3;

    auto f4 = new Formula("x1");
    std::vector<double> data4 = {4};
    printf("%f\n", f4->calculate(data4));
    printf("%f\n", verify4(data4));
    delete f4;
}

double verify1(std::vector<double> &data) {
    return data[0] + data[1] * data[2] + data[3] * data[4] * data[5] + data[6];
}

double verify2(std::vector<double> &data) {
    return data[0] + data[1] + data[2] + data[3];
}

double verify3(std::vector<double> &data) {
    return data[0] * data[1] * data[2] * data[3];
}

double verify4(std::vector<double> &data) {
    return data[0];
}
