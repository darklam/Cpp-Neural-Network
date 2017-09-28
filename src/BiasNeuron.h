#ifndef BIASNEURON_H
#define BIASNEURON_H

#include "Neuron.h"

class BiasNeuron: protected Neuron{
public:
  float feed(std::vector<float>); // No need to take inputs but for convenience's sake
};


#endif
