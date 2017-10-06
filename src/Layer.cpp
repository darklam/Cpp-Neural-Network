#include "Layer.h"
#include <vector>

std::vector<float> Layer::feed(std::vector<float> in){
  std::vector<float> out;
  out.resize(this->getSize());
  for(int i = 0; i < this->getSize(); i++){
    out[i] = this->neurons[i]->feed(in);
  }
  return out;
}

int Layer::getSize(){
  return this->neurons.size();
}
