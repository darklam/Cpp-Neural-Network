HFILES=Neuron.h Functions.h RandomGen.h Layer.h Network.h
CPPFILES=$(HFILES:.h=.cpp) main.cpp
OFILES=$(CPPFILES:.cpp=.o)
CXX=g++
FLAGS=-std=c++11 -g3

all: $(OFILES)
	$(CXX) $(OFILES) $(FLAGS) -o prog

%.o:%.cpp
	$(CXX) -c $(FLAGS) $< -o $@

clean:
	rm *.o
	rm prog