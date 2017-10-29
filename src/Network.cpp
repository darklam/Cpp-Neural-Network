#include "Network.h"
#include <map>
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

        this->hiddenNeurons = this->getHiddenModel(options["hiddenModel"]);
        
    }

    // Cehcking if some values are not initialized and use the default values

    if(this->functionUsed == "nothing"){

        this->functionUsed = "sigmoid";

    }else if(this->momentum < 0){

        this->momentum = 0.3;

    }else if(this->learningConstant < 0){

        this->learningConstant = 0.03;

    }else if(this->hiddenCount < 0){

        this->hiddenCount = 1;

        this->hiddenNeurons = {50};

    }else if(this->inputs < 0){
        
        this->inputs = 1;

    }else if(this->outputs < 0){

        this->outputs = 1;

    }



}