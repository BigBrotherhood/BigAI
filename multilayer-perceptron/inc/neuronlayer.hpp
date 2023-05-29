#pragma once

#include "multilayer-perceptron.hpp"

/*-------------------------------------------------------------------------------*/

class neuronlayer {

private:

    std::vector<neuron> _neurons;

public:

    neuronlayer ();
    neuronlayer (std::vector<neuron> neurons);

    std::vector<neuron> &get_neurons () { return this->_neurons; }
    void set_neurons (std::vector<neuron> neurons) { this->_neurons = neurons; }


    
    std::vector<double> getAllOutput ();
    std::string toString();
};

std::ostream &operator<<(std::ostream &out, neuronlayer &nl);

/*------------------------------------- 42 --------------------------------------*/