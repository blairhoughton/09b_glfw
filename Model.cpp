
#include <GLFW/glfw3.h>
#include <assert.h>
#include <new>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include "Model.h"

Model::Model( int n )
  : count( n )
{
    objects = new (std::nothrow) RotatingPyramid*[count];
    assert(objects);

    srand48(getpid());

    for ( int i = 0; i < count; i++ )
    {
        // random placement and size;
        // scale is inverse of the factor, so largest will be 1/4 height. 
        // centroid is 3/4ths of height from white point, so at least that
        // much room must be between the centroid and the model bounding box
        // to prevent clipping; boundary is +-1 in z, window height in y,
        // and window width in x; x and y will both scale with height and
        // ignore width changes, so x will show black border if aspect ratio
        // is widened by window resize;
        float x = 1.33f*(1.f-2.f*drand48()); // x
        float y = 1.f - 2.f*drand48();       // y
        float z = 0.75f*(1.f-2.f*drand48()); // z
        float w = 4.f+20.f*drand48();        // 1/scale

        // rotation axis vector is same as position vector, 
        // rotation rates are defaults
        objects[i] = new (std::nothrow) RotatingPyramid(x,y,z,w, x,y,z);
        assert(objects[i]);
    }
}

Model::~Model()
{
    delete objects; // calls destructor on each element 
}

void
Model::render( double t )
{
    for ( int i = 0; i < count; i++ )
        objects[i]->draw( t );
}

