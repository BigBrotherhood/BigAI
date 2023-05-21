#pragma once

#include <iostream>
#include <vector>

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
        std::string toString();
};

std::ostream &operator<<(std::ostream &out, neuron &n);