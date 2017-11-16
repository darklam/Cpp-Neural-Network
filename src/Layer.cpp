#include "Layer.h"
#include "Neuron.h"
#include "Functions.h"
#include <vector>
#include <iostream>

Layer::Layer(int neuronCount, int inputCount, float momentum, float learningConstant, std::string functionUsed){

	this->neurons.resize(neuronCount + 1);
	this->inputs = inputCount;
	this->functionUsed = functionUsed;

	for(int i = 0; i < neuronCount; i++){

		this->neurons[i] = new Neuron(inputCount, learningConstant, momentum);

	}

	this->neurons[neuronCount] = new BiasNeuron();
}

Layer::~Layer(){

	for(int i = 0; i < this->getSize(); i++){

		delete this->neurons[i];

	}

}

std::vector<float> Layer::feed(std::vector<float> &in){

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

	this->neurons.pop_back();
	this->inputs--;

}

HiddenLayer::HiddenLayer(int neuronCount, int inputCount, float momentum, float learningConstant, std::string functionUsed):
  Layer(neuronCount, inputCount, momentum, learningConstant, functionUsed){

}

InputLayer::InputLayer(int neuronCount): Layer(neuronCount, 1, 0, 0, "sigmoid"){
	this->neurons.pop_back();
	this->inputs--;
}

std::vector<float> InputLayer::feed(std::vector<float> &in){

  	return in;

}

// The training function takes as arguments respectively: The deltas of the next layer in order, the pointer to the next layer, the
// activations of the current layer that is being trained and the activations of the previous layer in order
// The algorithm used for training as you may have already guessed is backpropagation
std::vector<float> HiddenLayer::train(std::vector<float> &nextDeltas, Layer *next, std::vector<float> &activations, std::vector<float> &prevActivations){

	std::vector<Neuron *> nextLayer = next->getNeurons();
	std::vector<float> layerDeltas;
	layerDeltas.resize(this->getSize());

	for(int i = 0; i < this->getSize(); i++){

		float sum = 0.0;

		std::vector<float> neuronDeltas;
		for(int j = 0; j < nextLayer.size(); j++){
			
			if(!nextLayer[j]->getWeights().empty())
				sum += nextDeltas[j] * nextLayer[j]->getWeights()[i];

		}

		layerDeltas[i] = sum * Functions::getFunctionDerivative(activations[i], this->functionUsed);
		Neuron *current = this->neurons[i];
		neuronDeltas.resize(prevActivations.size());

		for(int j = 0; j < prevActivations.size(); j++){

			neuronDeltas[j] = layerDeltas[i] * prevActivations[j];

		}
		
		current->train(neuronDeltas);
	}
	return layerDeltas;
}


std::vector<float> OutputLayer::train(std::vector<float> &target,
std::vector<float> &activations,
std::vector<float> &prevActivations){

	std::vector<float> layerDeltas;
	layerDeltas.resize(this->getSize());

	for(int i = 0; i < this->getSize(); i++){

		Neuron *current = this->neurons[i];
		layerDeltas[i]  = (activations[i] - target[i] * Functions::getFunctionDerivative(activations[i], this->functionUsed));
		std::vector<float> deltas;
		deltas.resize(prevActivations.size());

		for(int j = 0; j < prevActivations.size(); j++){

			deltas[j] = prevActivations[j] * layerDeltas[i];

		}

		current->train(deltas);
	}
	return layerDeltas;
}
