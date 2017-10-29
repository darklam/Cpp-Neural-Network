#include "Neuron.h"
#include "Layer.h"
#include <map>
#include <string>
#include <vector>


class Network{
public:
    Network(std::map<std::string, std::string>);

    std::vector<float> feed(std::vector<float>);

private:
    Layer *inputLayer, *outputLayer;

    std::vector<Layer *> hiddenLayers;

    std::vector<int> hiddenNeurons;

    std::string functionUsed = "nothing";

    int hiddenCount = -1, inputs = -1, outputs = -1;

    float momentum = -1, learningConstant = -1;

    std::vector<int> getHiddenModel(std::string);

};