#include "Layer.h"
#include <vector>

<<<<<<< HEAD
Layer::Layer(int neuronCount, int inputCount, float momentum, float learningConstant){
  this->neurons.resize(neuronCount + 1);
  this->inputs = inputCount;
  for(int i = 0; i < neuronCount; i++){
    this->neurons[i] = new Neuron(inputCount, learningConstant, momentum);
  }
  this->neurons[neuronCount] = new BiasNeuron();
=======
std::vector<float> Layer::feed(std::vector<float> in){
  std::vector<float> out;
  out.resize(this->getSize());
  for(int i = 0; i < this->getSize(); i++){
    out[i] = this->neurons[i]->feed(in);
  }
  return out;
}

int Layer::getSize(){
  return this->neurons.size();
>>>>>>> 7eab3207c2952ce164ca03e3d150afd35f0f458c
}
