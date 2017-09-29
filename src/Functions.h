#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

namespace Functions{  // A namespace with useful functions used throughout the program
  float sigmoid(float); // The sigmoid function 1 / (1 + e^(-x))
  float sigmoidDerivative(float); // The sigmoid derivative
  float squaredError(std::vector<float>, std::vector<float>);
  float meanSquaredError(std::vector<std::vector<float> >, std::vector<std::vector<float> >);
  void printVector(std::vector<float>);
}
#endif
