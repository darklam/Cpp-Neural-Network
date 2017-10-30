#ifndef LAYER_H
#define LAYER_H

#include <string>
#include <vector>
#include "Neuron.h"

class Layer{
protected:
	std::vector<Neuron *> neurons;

	int inputs;  // This is the amount of inputs each neuron takes

	std::string functionUsed; // The activation function used by the network

public:
	Layer(int, int, float, float, std::string);
	~Layer();

	int getSize();  // Returns the number of neurons in the layer
	  
	std::vector<Neuron *> getNeurons();
	  
	virtual std::vector<float> feed(std::vector<float>&);
	  
};

class HiddenLayer: public Layer{
public:
	HiddenLayer(int, int, float, float, std::string);
	  
	std::vector<float> train(std::vector<float>&, Layer *, std::vector<float>&, std::vector<float>&);
	  
};

class OutputLayer: public Layer{
public:
	OutputLayer(int, int, float, float, std::string);
	  
  	std::vector<float> train(std::vector<float>&, std::vector<float>&, std::vector<float>&);
};

class InputLayer: public Layer{
public:
	InputLayer(int);
	  
  	std::vector<float> feed(std::vector<float>&);
};




#endif
