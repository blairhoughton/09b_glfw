
#pragma once

#include "Vertex.h"

class Pyramid
{
protected:
    struct Vertex vertex[4]; // corners rel to body center at unit scale
    float c[3];              // center of mass rel to model space

    // triangular pyramid, initially lying on side, height in Z-direction,
    // base triangle pointed in -Y direction, height 1, center-mass at
    // body origin
    static constexpr const float right  = .612372f; // sqrt(3/8);
    static constexpr const float left   = -right;
    static constexpr const float lower  = -.707107f; // -1/sqrt(2.f);
    static constexpr const float upper  = -lower/2.f;
    static constexpr const float back   = -0.25f;
    static constexpr const float front  = 0.75f;
    static constexpr const float center = 0.f;
    static Vertex defaultShape[4];

    void drawTriangle( int a, int b, int c );
    void drawShape( void );

public:
    Pyramid( float x=0.f, float y=0.f, float z=0.f, float w=1.f );
    ~Pyramid() {};
};

