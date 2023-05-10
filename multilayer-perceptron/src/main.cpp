#include "../inc/multilayer-perceptron.hpp"

void training() {

    std::string path;

    std::cout << "Please enter path to database: "; std::cin >> path;
    
    dataset data(path);

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
    return 0;
}