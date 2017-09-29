#ifndef BIASNEURON_H
#define BIASNEURON_H

#include "Neuron.h"

class BiasNeuron: public Neuron{
public:
  float feed(std::vector<float>); // No need to take inputs but for convenience's sake
  BiasNeuron();
};


#endif
