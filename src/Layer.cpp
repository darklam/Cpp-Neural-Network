#include "Layer.h"
#include <vector>

Layer::Layer(int neuronCount, int inputCount, float momentum, float learningConstant){
  this->neurons.resize(neuronCount + 1);
  this->inputs = inputCount;
  for(int i = 0; i < neuronCount; i++){
    this->neurons[i] = new Neuron(inputCount, learningConstant, momentum);
  }
  this->neurons[neuronCount] = new BiasNeuron();
}
