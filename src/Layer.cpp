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

std::vector<Neuron *> Layer::getNeurons(){
  return this->neurons;
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

// The training function takes as arguments respectively: The deltas of the next layer in order, the pointer to the next layer, the
// activations of the current layer that is being trained and the activations of the previous layer in order
// The algorithm used for training as you may have already guessed is backpropagations
std::vector<float> HiddenLayer::train(std::vector<float> nextDeltas, Layer *next, std::vector<float> activation, std::vector<float> prevActivations){
  std::vector<Neuron *> nextLayer = next->getNeurons();
  std::vector<float> layerDeltas;
  layerDeltas.resize(this->count);
  for(int i = 0; i < this->count; i++){
    float sum = 0.0;
    for(int j = 0; j < nextLayer.size(); j++){
      sum += nextDeltas[j] * nextLayer[j]->getWeights()[i];
    }
    layerDeltas[i] = sum * Functions::getFunctionDerivative(activations[i], this->functionUsed);
    Neuron *current = this->neurons[i];
    std::vector<float> neuronDeltas;
    neuronDeltas.resize(prevActivations.size());
    for(int j = 0; j < prevActivations.size(); j++){
      neuronDeltas[i] = layerDeltas[i] * prevActivations[j];
    }
    current->train(neuronDeltas);
  }
  return layerDeltas;
}


