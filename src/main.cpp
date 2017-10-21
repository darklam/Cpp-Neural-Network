#include "Neuron.h"
#include "Functions.h"
#include <iostream>

int main(){
  Neuron n(2, 0.2, 0.5);
  BiasNeuron b;
  std::vector<float> v = {2.3, 0.4};
  std::cout << n.feed(v, "sigmoid") << std::endl;
  std::cout << b.feed(v, "sigmoid") << std::endl;
  return 0;
}
