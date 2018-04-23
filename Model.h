
#pragma once

#include "RotatingPyramid.h"

class Model
{
    RotatingPyramid** objects; // used as array
    int count;
public:
    Model( int n_objects = 1700 );
    ~Model();
//n_objects = 8000; // a little choppy, pegs one cpu
//n_objects = 5000; // smoother, still pegs cpu
//n_objects = 1000; // about 60% on one CPU

    void render( double t = 0.0 );
};

