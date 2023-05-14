#pragma once

/*------------------------------------- 42 --------------------------------------*/

# include <map>
# include <fstream>
# include <iostream>

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

public:

    dataset();
    ~dataset();

};

/*-------------------------------------------------------------------------------*/