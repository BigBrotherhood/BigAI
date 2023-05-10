#pragma once

# include <map>
# include <experimental/fixed_point>

class data {

private:

    std::map<std::string, double> _mean;
    std::map<std::string, >


    data();
    ~data();
};

class dataset {

private:

    std::map<int, data> _dataset;

public:

    dataset();
    ~dataset();


};