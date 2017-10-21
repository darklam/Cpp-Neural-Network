#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

namespace Functions{  // A namespace with useful functions used throughout the program
  extern std::string functionUsed;
  void setFunctionUsed(std::string); // Sets the function the user wants to work with
  float getFunction(float); // The chosen function
  float getFunctionDerivative(float); // The chosen function derivative
  float squaredError(std::vector<float>, std::vector<float>);
  float meanSquaredError(std::vector<std::vector<float> >, std::vector<std::vector<float> >);
  void printVector(std::vector<float>);
}
#endif
