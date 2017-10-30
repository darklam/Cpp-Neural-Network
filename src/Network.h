#include "Neuron.h"
#include "Layer.h"
#include <map>
#include <string>
#include <vector>


class Network{
public:
    Network(std::map<std::string, std::string>);
    ~Network();

    std::vector<float> feed(std::vector<float> &);

    void train(std::vector<float> &, std::vector<float> &);

private:
    InputLayer *inputLayer;
    OutputLayer *outputLayer;

    std::vector<HiddenLayer *> hiddenLayers;

    std::vector<int> hiddenNeurons;

    std::string functionUsed = "nothing";

    int hiddenCount = -1, inputs = -1, outputs = -1;

    float momentum = -1, learningConstant = -1;

};