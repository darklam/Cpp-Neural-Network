#include "Layer.h"
#include <vector>

Layer::Layer(int neuronCount, int inputCount, float momentum, float learningConstant, std::string functionUsed){
  this->neurons.resize(neuronCount + 1);
  this->inputs = inputCount;
  this->functionUsed = functionUsed;
  for(int i = 0; i < neuronCount; i++){
    this->neurons[i] = new Neuron(inputCount, learningConstant, momentum);
  }
  this->neurons[neuronCount] = new BiasNeuron();
}

std::vector<float> Layer::feed(std::vector<float> in){
  std::vector<float> out;
  out.resize(this->getSize());
  for(int i = 0; i < this->getSize(); i++){
    out[i] = this->neurons[i]->feed(in, this->functionUsed);
  }
  return out;
}

int Layer::getSize(){
  return this->neurons.size();
}

OutputLayer::OutputLayer(int neuronCount, int inputCount, float momentum, float learningConstant, std::string functionUsed) :
 Layer(neuronCount, inputCount, momentum, learningConstant, functionUsed){

 }

 HiddenLayer::HiddenLayer(int neuronCount, int inputCount, float momentum, float learningConstant, std::string functionUsed):
  Layer(neuronCount, inputCount, momentum, learningConstant, functionUsed){

}

InputLayer::InputLayer(int neuronCount): Layer(neuronCount, 1, 0, 0, "sigmoid"){

}

std::vector<float> InputLayer::feed(std::vector<float> in){
  return in;
}

std::vector<float> Layer::trainOutput(std::vector<float> target,
std::vector<float> activations,
std::vector<float> prevActivations){
  Functions f;
  std::vector<float> layerDeltas;
  layerDeltas.resize(this->count);
  for(int i = 0; i < this->count; i++){
    Neuron *current = this->neurons[i];
    layerDeltas[i]  = (activations[i] - target[i] * f.getFunctionDerivative(activations[i],this->functionUsed));
    std::vector<float> deltas;
    for(int j = 0; j <prevActivations.size(); j++){
      deltas.push_back(prevActivations[j] * layerDeltas[i]);
    }
    current->train(deltas);
  }
  return layerDeltas;
}
