#include "Network.h"
#include "Functions.h"
#include <map>
#include <string>
#include <iostream>
#include <vector>

int main(){

	std::map<std::string, std::string> options ={
		{"hiddenCount", "2"},
		{"function", "sigmoid"},
		{"inputs", "2"},
		{"outputs", "1"},
		{"momentum", "0.4"},
		{"learningConstant", "0.01"},
		{"hiddenModel", "4 8"}
	};

	Network n(options);

	std::vector< std::vector<float> > in = {
		{1, 1},
		{1, 0},
		{0, 1},
		{0,0}
	};

	std::vector< std::vector<float> > targets = {
		{0},
		{1},
		{1},
		{0}
	};

	for(int i = 0; i < in.size(); i++){
		n.train(in[i], targets[i]);
	}

	for(int i = 0; i < in.size(); i++){
		Functions::printVector(n.feed(in[i]));
	}

	return 0;
}
