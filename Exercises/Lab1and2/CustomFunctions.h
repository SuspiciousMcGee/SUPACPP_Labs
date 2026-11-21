#pragma once
#include <vector>
#include <string>

struct Data {
    std::vector<float> x_vals;
    std::vector<float> y_vals;
};

Data readFile(const char* filename);
void printData(const Data& data, int N);
std::vector<float> getMagnitude(const Data& data);
std::string fitLSQ(const Data& data);
