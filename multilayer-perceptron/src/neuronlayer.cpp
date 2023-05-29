#include "../inc/multilayer-perceptron.hpp"

/*-------------------------------------------------------------------------------*/

neuronlayer::neuronlayer(std::vector<neuron> neurons) {

    this->_neurons = neurons;
}

neuronlayer::neuronlayer() {}

std::string neuronlayer::toString() {

    std::string str = "";

    for (size_t i = 0; i < this->_neurons.size(); i++)
        str += this->_neurons[i].toString();
    return str;
}

std::vector<double> neuronlayer::get_output_values() {

    std::vector<double> output_values;

    for (size_t i = 0; i < this->_neurons.size(); i++)
        output_values.push_back(this->_neurons[i].get_output());
    return output_values;
}

std::ostream &operator<<(std::ostream &out, neuronlayer &nl) {
    
    for (size_t i = 0; i < nl.get_neurons().size(); i++)
        out << nl.get_neurons()[i];
    return out;
}

/*------------------------------------- 42 --------------------------------------*/