#pragma once

# include <map>
# include <fstream>
# include <iostream>
# include <fixed.hpp>

class data {

private:

    std::map<std::string, Fixed> _mean;
    std::map<std::string, Fixed> _error;
    std::map<std::string, Fixed> _worst;

public:

    data(std::string);
    ~data();
};

class dataset {

private:

    std::map<std::string, data *> _set;

public:

    dataset(std::fstream stream);
    ~dataset();

};