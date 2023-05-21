#pragma once

#include "multilayer-perceptron.hpp"

class neuron {

    private: 
        std::vector <double> weights;
        std::vector<double> input;

        double bias;
        double output;
        double error;
        double delta;

    public:
        /*--- CONSTRUCTOR ---*/
        neuron (std::vector<double> input, std::vector <double> weights);
        neuron (std::vector <double> weights);
        neuron ();
        /*--- SETTER ---*/
        void set_weights (std::vector <double> weights);
        void set_bias (double bias);
        void set_output (double output);
        void set_error (double error);
        void set_delta (double delta);
        void set_input (std::vector<double> input);

        /*--- GETTER ---*/
        std::vector <double> get_weights ();
        double get_bias ();
        double get_output ();
        double get_error ();
        double get_delta ();
        std::vector<double> get_input ();

        /*--- METHODS ---*/
        void calculate_output (std::vector <double> inputs);


};

std::ostream &operator<<(std::ostream &out, neuron &n)
{
    std::cout << "input: ";
    for (size_t i = 0; i < n.get_input().size(); i++)
        std::cout << n.get_input()[i] << " ";
    std::cout << "| weights: ";
    for (size_t i = 0; i < n.get_weights().size(); i++)
        std::cout << n.get_weights()[i] << " ";
    std::cout << "| bias: " << n.get_bias() << " | output: " << n.get_output() << " | error: " << n.get_error() << " | delta: " << n.get_delta() << std::endl;
    return out;
}