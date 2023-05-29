#pragma once

#include "multilayer-perceptron.hpp"

/*-------------------------------------------------------------------------------*/

class neuron {

private:

    double bias;
    double error;
    double delta;
    double output;
    std::vector<double> input;
    double weights;

public:

    neuron();
    neuron(double weights);
    neuron(std::vector<double> input);
    neuron(std::vector<double> input, double weights);

    // setters and getters

    void set_bias (double bias) { this->bias = bias; }
    void set_error (double error) { this->error = error; }
    void set_delta (double delta) { this->delta = delta; }
    void set_input (std::vector <double>input) { this->input = input; }
    void set_output (double output) { this->output = output; }
    void set_weights (double weights) { this->weights = weights; }
    
    double get_bias () { return this->bias; }
    double get_error () { return this->error; }
    double get_delta () { return this->delta; }
    double get_output () { return this->output; }
    double get_weights () { return this->weights; }
    std::vector <double> get_input () { return this->input; }
    
    std::string toString();    
};

std::ostream &operator<<(std::ostream &out, neuron &n);

/*------------------------------------- 42 --------------------------------------*/