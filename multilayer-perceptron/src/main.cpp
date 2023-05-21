#include "../inc/multilayer-perceptron.hpp"

void training() {

    dataset data;
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