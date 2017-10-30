#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

namespace Functions{  // A namespace with useful functions used throughout the program
    float getFunction(float, std::string); // The chosen function
    float getFunctionDerivative(float, std::string); // The chosen function derivative
    float squaredError(std::vector<float>, std::vector<float>);
    float meanSquaredError(std::vector<std::vector<float> >, std::vector<std::vector<float> >);
    void printVector(std::vector<float>);
}
#endif
