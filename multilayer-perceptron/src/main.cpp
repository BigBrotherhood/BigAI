#include "../inc/multilayer-perceptron.hpp"

int main() {

    std::string path;

    std::cout << "Please enter path to database: "; std::cin >> path;

    dataset data(path);

    return 0;
}