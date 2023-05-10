#pragma once

# include <map>
# include <fstream>
# include <iostream>
# include "fixed.hpp"

class data {

private:

    std::map<std::string, fixed> _mean;
    std::map<std::string, fixed> _error;
    std::map<std::string, fixed> _worst;

public:

    data(std::string);
    ~data();
};

class dataset {

private:

    std::map<std::string, data *> _set;

public:

    dataset(std::string path);
    ~dataset();

};