#include "../inc/neuronlayer.hpp"

neuronlayer::neuronlayer (std::vector<neuron> neurons) {

    this->neurons = neurons;
}

neuronlayer::neuronlayer () {

}

std::vector<neuron> neuronlayer::get_neurons () {

    return this->neurons;
}

void neuronlayer::set_neurons (std::vector<neuron> neurons) {

    this->neurons = neurons;
}