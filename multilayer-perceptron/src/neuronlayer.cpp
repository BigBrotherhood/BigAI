#include "../inc/multilayer-perceptron.hpp"

/*-------------------------------------------------------------------------------*/

neuronlayer::neuronlayer(std::vector<neuron> neurons) {

    this->neurons = neurons;
}

neuronlayer::neuronlayer() {}

std::string neuronlayer::toString() {

    std::string str = "";

    for (size_t i = 0; i < this->neurons.size(); i++)
        str += this->neurons[i].toString();
    return str;
}

std::ostream &operator<<(std::ostream &out, neuronlayer &nl)
{
    for (size_t i = 0; i < nl.get_neurons().size(); i++)
        out << nl.get_neurons()[i];
    return out;
}

/*------------------------------------- 42 --------------------------------------*/