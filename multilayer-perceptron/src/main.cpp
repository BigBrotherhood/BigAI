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

double neuronOutput(neuron &n, neuronlayer &last_layer)
{
    std::cout << "last_layer.get_outputs().size() " << last_layer.get_output_values().size() << std::endl;
    std::cout << "n.get_input().size() " << n.get_input().size() << std::endl;
    double output = 0.0;
    for (size_t i = 0; i < last_layer.get_neurons().size(); i++) {
        output += last_layer.get_neurons()[i].get_output() * n.get_weights() + n.get_bias();
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

neuronlayer setLayer(neuronlayer &last_layer, int nb_neurons)
{
    std::vector<neuron> neurons;
    for (int i = 0; i < nb_neurons; i++) {
        neuron n; // on recupere les valeurs de sortie de la couche precedente et on les stock dans le vecteur input du neuronne
        n.set_input(last_layer.get_output_values());
        n.set_output(neuronOutput(last_layer.get_neurons()[i], last_layer));
        neurons.push_back(n);
    }
    return neuronlayer(neurons);
}

neuronlayer setInputLayer(dataset &data, int index)
{
    std::vector<neuron> neurons;

    for(int i = 1; i < 31; i++) {
        std::vector<double> input(1, data.get_norm(index, i));
        neuron n(input);
        n.set_output(input[0]);
        neurons.push_back(neuron(input));
    }
    return neuronlayer(neurons);
}

void training() {

    dataset data;
    neuronlayer input_layer;
    neuronlayer hidden_layer;
    neuronlayer hideen_layer2;
    neuronlayer output_layer;
    double prediction_correctness; // 0 = incorrect, 1 = correct
    std::vector<double> softmaxvalues;
    
    for (int i = 0; i < 2; i++)
    {
        std::cout << "\n" << std::endl;
        input_layer = setInputLayer(data, i);
        hidden_layer = setLayer(input_layer, 15);
        hideen_layer2 = setLayer(hidden_layer, 15);
        output_layer = setLayer(hideen_layer2, 2);
        softmaxvalues = softmax(output_layer.get_output_values()); //[0] = malicieux, [1] = benin
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

    // system("leaks multilayer-perceptron");
    return 0;
}