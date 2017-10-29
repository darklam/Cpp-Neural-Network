HFILES=Neuron.h Functions.h RandomGen.h
CPPFILES=$(HFILES:.h=.cpp) main.cpp
OFILES=$(CPPFILES:.cpp=.o)
CXX=g++
FLAGS=-std=c++11

all: $(OFILES)
	$(CXX) $(OFILES) $(FLAGS) -o prog

%.o:%.cpp
	$(CXX) -c $(FLAGS) $< -o $@

clean:
	rm *.o
	rm prog