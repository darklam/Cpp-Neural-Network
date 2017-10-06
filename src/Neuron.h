#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron{
protected:
  std::vector<float> weights, lastDeltas;
  float learningConstant, momentum;

public:
  Neuron(int, float, float);
  std::vector<float> getWeights();
  int getInputs();
  void loadWeightsFromVector(std::vector<float>);
  virtual float feed(std::vector<float>);
  void train(std::vector<float>);
};

class BiasNeuron: public Neuron{
public:
  float feed(std::vector<float>); // No need to take inputs but for convenience's sake
  BiasNeuron();
};

#endif
