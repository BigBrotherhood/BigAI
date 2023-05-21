#pragma once

/*------------------------------------- 42 --------------------------------------*/

# include <map>
# include <fstream>
# include <iostream>
# include <vector>
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
    void normalize(int id);
    void norm_mean_dev();
    void init_set();
    void print_norm(int id);
    void print_set(int id);
    void insert_features(int features, double number, int id);
    void process_line (std::string line, int id);

    double get_set(int id, int feature);
    double get_norm(int id, int feature);
    double get_mean(int feature);
    double get_dev(int feature);

};

/*-------------------------------------------------------------------------------*/