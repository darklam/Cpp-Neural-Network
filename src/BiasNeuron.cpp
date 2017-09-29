#include "BiasNeuron.h"

float BiasNeuron::feed(std::vector<float> in){
  return 1.0f;
}

BiasNeuron::BiasNeuron() : Neuron(0, 0, 0){

}
