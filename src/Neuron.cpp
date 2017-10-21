#include "Neuron.h"
#include "Functions.h"
#include "RandomGen.h"

Neuron::Neuron(int inputs, float learningConstant, float momentum){
  this->momentum = momentum;
  this->learningConstant = learningConstant;
  this->weights.resize(inputs);
  for(int i = 0; i < inputs; i++){
    this->weights[i] = RandomGen::randomDouble();
  }
}

int Neuron::getInputs(){
  return this->weights.size();
}

float Neuron::feed(std::vector<float> in, std::string functionUsed){
  float sum = 0;
  for(int i = 0; i < this->getInputs(); i++){
    sum += this->weights[i] * in[i];
  }
  return Functions::getFunction(sum, functionUsed);
}

void Neuron::loadWeightsFromVector(std::vector<float> weights){
  if(this->getInputs() != weights.size()){
    return;
  }
  for(int i = 0; i < this->getInputs(); i++){
    this->weights[i] = weights[i];
  }
}

void Neuron::train(std::vector<float> deltas){
  if(this->lastDeltas.empty()){
    this->lastDeltas.resize(this->getInputs());
    for(int i = 0; i < this->getInputs(); i++){
      this->lastDeltas[i] = deltas[i];
      this->weights[i] -= this->lastDeltas[i] * this->learningConstant;
    }
  }else{
    for(int i = 0; i < this->getInputs(); i++){
      double delta = (1 - this->momentum) * deltas[i] + momentum * this->lastDeltas[i];
      this->lastDeltas[i] = delta;
      this->weights[i] -= delta * this->learningConstant;
    }
  }
}

std::vector<float> Neuron::getWeights(){
  return this->weights;
}

float BiasNeuron::feed(std::vector<float> in, std::string functionUsed){
  return 1.0f;
}

BiasNeuron::BiasNeuron() : Neuron(0, 0, 0){

}
