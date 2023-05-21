#pragma once

#include "neuron.hpp"

class neuronlayer
{
    private:
        std::vector<neuron> neurons;

    public:
        neuronlayer (std::vector<neuron> neurons);
        neuronlayer ();
        std::vector<neuron> get_neurons ();
        void set_neurons (std::vector<neuron> neurons);
};

std::ostream &operator<<(std::ostream &out, neuronlayer &nl)
{
    for (size_t i = 0; i < nl.get_neurons().size(); i++)
        std::cout << nl.get_neurons()[i];
    return out;
}