#ifndef LAYER_H
#define LAYER_H

class Layer{
protected:
  std::vector<Neuron *> neurons;
  int inputs;
  float momentum, learningConstant;

public:
  Layer(int, int, float, float);
  int getSize();
};

class HiddenLayer: public Layer{
  public HiddenLayer(int, int);
};


#endif
