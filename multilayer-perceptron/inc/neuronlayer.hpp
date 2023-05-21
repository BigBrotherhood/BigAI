#pragma once

#include "multilayer-perceptron.hpp"

class neuronlayer
{
    private:
        std::vector<neuron> neurons;

    public:
        neuronlayer (std::vector<neuron> neurons);
        neuronlayer ();
        std::vector<neuron> get_neurons ();
        void set_neurons (std::vector<neuron> neurons);

        std::string toString();
};

std::ostream &operator<<(std::ostream &out, neuronlayer &nl);