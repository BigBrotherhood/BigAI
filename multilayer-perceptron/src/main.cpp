#include "../inc/multilayer-perceptron.hpp"

void outputToFile(std::string out, std::string path)
{
    std::ofstream outputFile(path);
    if (!outputFile.is_open()) {

        std::cout << "Error: could not open file" << std::endl;
        exit(1);
    }
    outputFile << out;
    outputFile.close();
}

neuronlayer setInputLayer(dataset &data)
{
    std::vector<neuron> neurons;

    for(int i = 1; i < 31; i++) {
        std::vector<double> input(1, data.get_norm(0, i));
        neurons.push_back(neuron(input));
    }
    return neuronlayer(neurons);
}

neuronlayer setHiddenLayer(neuronlayer &input_layer)
{
    std::vector<neuron> neurons;
    (void)input_layer;
    for (int i = 0; i < 15; i++) {
        
    }
    return neuronlayer(neurons);
}

void training() {

    dataset data;
    neuronlayer input_layer;
    neuronlayer hidden_layer;
    neuronlayer hideen_layer2;
    neuronlayer output_layer;

    input_layer = setInputLayer(data);
    outputToFile(input_layer.toString(), "output3.txt");
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

    while (choice != 0 && choice != 1)
    {
        std::cout << "Please choose between training phase (0) and prediction phase (1): ";
        std::cin >> choice;
    }

    if (choice)
        predict();
    else
        training();

    // system("leaks multilayer-perceptron");
    return 0;
}