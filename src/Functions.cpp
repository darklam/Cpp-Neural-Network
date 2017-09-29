#include "Functions.h"
#include <vector>
#include <cmath>
#include <iostream>

// Basically just pretty-printing the vector
// Should use a template but too bored if anyone wants to add that they're more than welcome lol
void Functions::printVector(std::vector<float> in){
  std::cout << "{";
  for(int i = 0; i < in.size(); i++){
    if(i == in.size() - 1){
      std::cout << " " << in[i];
      continue;
    }
    std::cout << " " << in[i] << ",";
  }
  std::cout << " }" << std::endl;
}

float Functions::squaredError(std::vector<float> out, std::vector<float> tar){
  if(out.size() != tar.size()){
    return -1;
  }
  float sum = 0;
  for(int i = 0; i < out.size(); i++){
    sum += pow(out[i] - tar[i], 2);
  }
  sum *= 0.5;
  return sum;
}

float Functions::meanSquaredError(std::vector<std::vector<float> > out,
std::vector<std::vector<float> > tar){
  if(tar.size() != out.size()){
    return -1;
  }
  float err = 0;
  for(int i = 0; i < out.size(); i++){
    err += Functions::squaredError(out[i], tar[i]);
  }
  return err / out.size();
}

float Functions::sigmoid(float x){
  return 1 / (1 + exp(-x));
}

float Functions::sigmoidDerivative(float x){
  return Functions::sigmoid(x) * (1 - Functions::sigmoid(x));
}
