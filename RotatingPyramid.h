
#pragma once

#include "Pyramid.h"

// Pyramid class defines a unit-height equilateral triangular pyramid lying
// on its side with base facing viewer and one base point pointing down

class RotatingPyramid : Pyramid
{
    float thetadot;          // rate in deg/sec about vertical axis
    float phidot;            // rate in deg/sec about body height (horiz) axis
    float rot[3];            // rotation-axis vector

public:
    // takes position of centroid in model space, and w (1/scale) factor,
    // then the theta-rotation axis vector, then thetadot and phidot
    // (phi is rotation about body axis; theta is rotation around theta axis)
    RotatingPyramid( float cx=0.f, float cy=0.f, float cz=0.f, float cw=1.f,
                     float tx=0.f, float ty=0.f, float tz=1.f,
                     float td=360.f/5.f, float pd=360.f );
    ~RotatingPyramid() {};

    void draw( double t = 0.0f );
};

