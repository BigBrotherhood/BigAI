#include "../inc/multilayer-perceptron.hpp"

void training() {

    dataset data;

    
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