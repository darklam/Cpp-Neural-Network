#include "Network.h"
#include <map>
#include <string>
#include <sstream>
#include "Layer.h"
#include "Neuron.h"

Network::Network(std::map<std::string, std::string> options){
    for(auto &x: options){
        // Setting the values for the network

        if(x.first == "hiddenCount"){

            this->hiddenCount = std::stoi(x.second);

            this->hiddenLayers.resize(this->hiddenCount);

        }else if(x.first == "function"){

            this->functionUsed == x.second;

        }else if(x.first == "inputs"){

            this->inputs = std::stoi(x.second);

            this->inputLayer = new InputLayer(this->inputs);

        }else if(x.first == "outputs"){

            this->outputs = std::stoi(x.second);

        }else if(x.first == "momentum"){

            this->momentum = std::stof(x.second);

        }else if(x.first == "learningConstant"){

            this->learningConstant = std::stof(x.second);

        }

    }

    if(this->hiddenCount > 0){
        std::string model = options["hiddenModel"];
        std::stringstream ss(model);
        int n;
        std::vector<int> modelArr;
        while(ss >> n){
            modelArr.push_back(n);
        }
        this->hiddenNeurons = modelArr;
    }
    
    // Checking if some values are not initialized and use the default values

    if(this->functionUsed == "nothing"){

        this->functionUsed = "sigmoid";

    }

    if(this-> momentum < 0){

        this->momentum = 0.3;

    }

    if(this->learningConstant < 0){

        this->learningConstant = 0.03;

    }
    
    if(this->hiddenCount < 0){

        this->hiddenCount = 1;
        this->hiddenLayers.resize(this->hiddenCount);
        this->hiddenNeurons = {50};
    }
    
    if(this->inputs < 0){
        
        this->inputs = 1;

    }
    
    if(this->outputs < 0){

        this->outputs = 1;

    }

    this->inputLayer = new InputLayer(this->inputs);

    this->outputLayer = new OutputLayer(this->outputs, this->hiddenNeurons[this->hiddenCount - 1], this->momentum, this->learningConstant, this->functionUsed);

    for(int i = 0; i < this->hiddenCount; i++){

        if(i != 0){

            this->hiddenLayers[i] = new HiddenLayer(this->hiddenNeurons[i], this->hiddenNeurons[i - 1], this->momentum, this->learningConstant, this->functionUsed);

        }else{

            this->hiddenLayers[0] = new HiddenLayer(this->hiddenNeurons[0], this->inputs, this->momentum, this->learningConstant, this->functionUsed);

        }
    }

}

Network::~Network(){
    delete this->inputLayer;
    delete this->outputLayer;

    for(int i = 0; i < this->hiddenCount; i++){
        delete this->hiddenLayers[i];
    }
}

std::vector<float> Network::feed(std::vector<float> &in){
    std::vector<float> out;
    out = this->inputLayer->feed(in);   // Does nothing for now, will implement normalization later

    for(int i = 0; i < this->hiddenCount; i++){

        out = this->hiddenLayers[i]->feed(out);

    }

    out = this->outputLayer->feed(out);
    return out;
}

void Network::train(std::vector<float> &in, std::vector<float> &target){

    std::vector<float> inputLayerOutputs;
    inputLayerOutputs = this->inputLayer->feed(in);

    std::vector<float> outputLayerOutputs;

    std::vector< std::vector<float> > hiddenLayerOutputs;
    hiddenLayerOutputs.resize(this->hiddenCount);

    for(int i = 0; i < this->hiddenCount; i++){

        hiddenLayerOutputs.resize(this->hiddenNeurons[i]);

        if(i == 0){

            hiddenLayerOutputs[i] = this->hiddenLayers[i]->feed(inputLayerOutputs);

        }else{
            hiddenLayerOutputs[i] = this->hiddenLayers[i]->feed(hiddenLayerOutputs[i - 1]);
        }



    }

    outputLayerOutputs = this->outputLayer->feed(hiddenLayerOutputs[this->hiddenCount - 1]);

    std::vector<float> deltas;
    deltas = this->outputLayer->train(target, outputLayerOutputs, hiddenLayerOutputs[this->hiddenCount - 1]);

    for(int i = this->hiddenCount - 1; i >= 0; i--){

        if(i == this->hiddenCount - 1){

            deltas = this->hiddenLayers[i]->train(deltas, this->outputLayer, hiddenLayerOutputs[i], hiddenLayerOutputs[i - 1]);

        }else if(i == 0){

            deltas = this->hiddenLayers[i]->train(deltas, this->hiddenLayers[i + 1], hiddenLayerOutputs[i], inputLayerOutputs);

        }else{

            deltas = this->hiddenLayers[i]->train(deltas, this->hiddenLayers[i + 1], hiddenLayerOutputs[i], hiddenLayerOutputs[i - 1]);

        }

    }
}