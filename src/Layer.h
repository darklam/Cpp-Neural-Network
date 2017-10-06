#ifndef LAYER_H
#define LAYER_H

class Layer{
protected:
  std::vector<Neuron *> neurons;
  int inputs;  // This is the amount of inputs each neuron takes

public:
  Layer(int, int);
  int getSize();  // Returns the number of neurons in the layer
  std::vector<float> feed(std::vector<float>);
};

class HiddenLayer: public Layer{
  public HiddenLayer(int, int);
};


#endif
