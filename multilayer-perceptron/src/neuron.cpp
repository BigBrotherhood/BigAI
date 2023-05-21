#include "../inc/neuron.hpp"

neuron::neuron (std::vector <double> weights) {

    this->weights = weights;
    this->bias = 0;
    this->output = 0;
    this->error = 0;
    this->delta = 0;
}

neuron::neuron (std::vector<double> input,std::vector <double> weights) {

    this->weights = weights;
    this->bias = 0;
    this->output = 0;
    this->error = 0;
    this->delta = 0;
    this->input = input;
}

neuron::neuron () {
    this->input = std::vector<double>();
    this->weights = std::vector<double>();
    this->bias = 0;
    this->output = 0;
    this->error = 0;
    this->delta = 0;
}

void neuron::set_weights (std::vector <double> weights) {

    this->weights = weights;
}

void neuron::set_bias (double bias) {

    this->bias = bias;
}

void neuron::set_output (double output) {

    this->output = output;
}

void neuron::set_error (double error) {

    this->error = error;
}

void neuron::set_delta (double delta) {

    this->delta = delta;
}

void neuron::set_input (std::vector<double> input) {

    this->input = input;
}

std::vector <double> neuron::get_weights () {

    return this->weights;
}

double neuron::get_bias () {

    return this->bias;
}

double neuron::get_output () {

    return this->output;
}

double neuron::get_error () {

    return this->error;
}

double neuron::get_delta () {

    return this->delta;
}

std::vector<double> neuron::get_input () {

    return this->input;
}

void neuron::calculate_output (std::vector <double> inputs) {
    (void)inputs;
}