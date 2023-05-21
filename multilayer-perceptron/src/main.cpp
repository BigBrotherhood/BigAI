#include "../inc/multilayer-perceptron.hpp"

void outputToFile(std::ostream &out, std::string path)
{
    std::ofstream file(path);
    file << out.rdbuf();
    file.close();
}

neuronlayer setInputLayer(dataset &data)
{
    std::vector<neuron> neurons;

    for(int i = 0; i < 30; i++)
    {
        std::vector<double> weights(1, rand() / (double)RAND_MAX);
        std::vector<double> input(1, data.get_norm(0, i));
        neurons.push_back(neuron(input, weights));
    }
    return (neuronlayer(neurons));
}

void training() {

    dataset data;
    neuronlayer input_layer;

    input_layer = setInputLayer(data);
    outputToFile(std::cout << input_layer << std::endl, "output3.txt");
    // double to_scale = 0.1184;

    // double scaled = 0.0;

    // scaled = (to_scale - 0.0) / (0.006399 - 0.0);
    // std::cout << "scaled = " << scaled << std::endl;

    
}

void predict() {
    
    std::cout << "work in progress" << std::endl;
}


int main() {

    int choice = 2;
    while (choice != 0 && choice != 1) {
        std::cout << "Please choose between training phase (0) and prediction phase (1): "; std::cin >> choice;
    }

    if (choice)
        predict();
    else
        training();
    // system("leaks multilayer-perceptron");
    return 0;
}