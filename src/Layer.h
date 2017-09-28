#ifndef LAYER_H
#define LAYER_H

class Layer{
protected:
  std::vector<Neuron *> neurons;
  int inputs;

public:
  Layer(int, int);
  int getSize();
};

class HiddenLayer: public Layer{
  public HiddenLayer(int, int);
};


#endif
