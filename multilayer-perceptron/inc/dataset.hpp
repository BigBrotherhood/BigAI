#pragma once

#include "multilayer-perceptron.hpp"

/*-------------------------------------------------------------------------------*/

namespace ft {

    enum class mean {

        radius = 1,
        texture,
        perimeter,
        area,
        smoothness,
        compactness,
        concavity,
        concave_points,
        symetry,
        fractal_dimension
    };

    enum class error {

        radius = 11,
        texture,
        perimeter,
        area,
        smoothness,
        compactness,
        concavity,
        concave_points,
        symetry,
        fractal_dimension
    };

    enum class worst {

        radius = 21,
        texture,
        perimeter,
        area,
        smoothness,
        compactness,
        concavity,
        concave_points,
        symetry,
        fractal_dimension
    };
}

/*-------------------------------------------------------------------------------*/

class dataset {

private: 

    double _set[570][31];
    double _norm[570][31];
    double _mean[30] = {0.0};
    double _dev[30] = {0.0};

public:

    dataset();
    ~dataset();

    void init_set();
    void norm_mean_dev();
    void normalize(int id);
    void print_set(int id);
    void print_norm(int id);
    void process_line (std::string line, int id);
    void insert_features(int features, double number, int id);

    double get_dev(int feature) { return _dev[feature]; }
    double get_mean(int feature) { return _mean[feature]; }
    double get_set(int id, int feature) { return _set[id][feature]; }
    double get_norm(int id, int feature) { return _norm[id][feature]; }

};

/*------------------------------------- 42 --------------------------------------*/