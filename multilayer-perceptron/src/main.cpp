#include "../inc/multilayer-perceptron.hpp"

void outputToFile(std::string out, std::string path)
{
    std::ofstream outputFile(path, std::ios::app);
    if (!outputFile.is_open()) {

        std::cout << "Error: could not open file" << std::endl;
        exit(1);
    }
    outputFile << out << std::endl;
    outputFile.close();
}

double sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

double neuronOutput(neuron &n)
{
    double output = 0.0;
    for (size_t i = 0; i < n.get_input().size(); i++) {
        output += n.get_input()[i] * n.get_weights() + n.get_bias();
    }
    return sigmoid(output);
}

double log_loss(std::vector<double> softmaxvalues, int real_value)
{
    double sum = 0.0;
    for (size_t i = 0; i <  1; i++) { // 1 car on entraine sur un seul exemple a la fois
            sum += real_value * log(softmaxvalues[real_value]) + (1 - real_value) * log(1 - softmaxvalues[real_value]);
    }
    return -1/1 * sum; // 1 en denominateur car on entraine toujours sur un seul exemple a la fois
}

std::vector<double> softmax (std::vector<double> allvalues)
{
    std::vector<double> softmaxvalues; //EGAL A Z DANS LE COURS
    double sum = 0.0;
    for (size_t i = 0; i < allvalues.size(); i++) { //SOMME DE TOUS LES EXPONENTIELS DE TOUTES LES VALEURS OUTPUT DE LA COUCHE
        sum += exp(allvalues[i]);
    }
    for (size_t i = 0; i < allvalues.size(); i++) { //EXPONENTIEL DE LA VALEUR DU NEURONNE PRECEDANT I / SOMME
        softmaxvalues.push_back(exp(allvalues[i]) / sum);
    }
    return softmaxvalues;
}

void processLayerOutput(neuronlayer &layer)
{
    for (size_t i = 0; i < layer.get_neurons().size(); i++) {
        layer.get_neurons()[i].set_output(neuronOutput(layer.get_neurons()[i]));
    }
}

neuronlayer initLayer(int nb_neurons)
{
    std::vector<neuron> neurons;
    for (int i = 0; i < nb_neurons; i++) {
        neurons.push_back(neuron());
    }
    return neuronlayer(neurons);
}

void setLayerInput(neuronlayer &layer, neuronlayer &input_layer)
{
    for (size_t i = 0; i < layer.get_neurons().size(); i++) {
        layer.get_neurons()[i].set_input(input_layer.getAllOutput());
    }
}

void setLayerInputFromData(neuronlayer &layer , dataset &data, int index)
{
    for (int i = 0; i < 30; i++) {
        layer.get_neurons()[i].set_input(std::vector<double>(1, data.get_norm(index, i + 1)));
    }

    
}

void processLayer(neuronlayer &layer, neuronlayer &last_layer)
{
    setLayerInput(layer, last_layer);
    processLayerOutput(layer);
}


void processGradientDescentToLayer(std::vector<neuronlayer> &layers, double prediction_correctness, double learning_rate, std::vector<double> softmaxvalues, int real_value)
{
    for (int i = 1; i < layers.size(); i++) {
        for (size_t j = 0; j < layers[i].get_neurons().size(); j++) { // for each neuron in current layer
            for (size_t k = 0; k < layers[i].get_neurons()[j].get_input().size(); k++) { // for each input to the current neuron
                // Calculate the gradient of the loss with respect to the weight
                double gradient = prediction_correctness * softmaxvalues[real_value] * (1 - softmaxvalues[real_value]) * layers[i].get_neurons()[j].get_input()[k];

                // Update the weight
                layers[i].get_neurons()[j].get_weights()[k] -= learning_rate * gradient;
            }
            // Update bias
            layers[i].get_neurons()[i].set_bias(layers[i].get_neurons()[j].get_bias() - learning_rate * prediction_correctness * softmaxvalues[real_value] * (1 - softmaxvalues[real_value]));
        }
    }
}

void training() {

    dataset data;
    std::vector<neuronlayer> layers;
    layers[0] = initLayer(30);
    layers[1] = initLayer(15);
    layers[2] = initLayer(15);
    layers[3] = initLayer(2);
    double learning_rate = 0.01;
    double prediction_correctness; // 0 = incorrect, 1 = correct
    std::vector<double> softmaxvalues;
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "\n" << std::endl;

        setLayerInputFromData(layers[0], data, i);
        processLayerOutput(layers[0]);
        processLayer(layers[1], layers[0]);
        processLayer(layers[2], layers[1]);
        processLayer(layers[3], layers[2]);
        softmaxvalues = softmax(layers[3].getAllOutput()); //[0] = malicieux, [1] = benin
        prediction_correctness = log_loss(softmaxvalues, data.get_set(i,0));

        // outputToFile(input_layer.toString(), "output3.txt");
        std::cout << "Malicieux (0) = " << softmaxvalues[0] * 100 << "%" << std::endl;
        std::cout << "Benin (1) = " << softmaxvalues[1] * 100 << "%" <<std::endl;
        std::cout << "Dataset = " << data.get_set(i,0) << std::endl;
        std::cout << "Reussite = " << prediction_correctness * 100 << "%" << std::endl;
    }
    
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
    std::cout << "SEGFAULT" << std::endl;

    // system("leaks multilayer-perceptron");
    return 0;
}