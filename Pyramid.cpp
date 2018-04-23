
// glfw3.h includes the GL headers, plus the X11 and pthreads headers it needs
// (maybe; all the #includes in glfw3.h seem to be wrapped and require
// GLFW_INCLUDE_* to be defined to get the includes done; that's probably
// something that libglfw3 does in its build, and the 01glfw app only compiled
// because it only used glfw elements)
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include <iostream>

#include "Pyramid.h"

// draws the triangle using the vertices in defaultShape
// (see defaultShape below for default vertex definitions)
void Pyramid::drawTriangle( int a, int b, int c )
{
    // funny syntax for typedef's sake
    glColor4fv(&vertex[a].color[0]);
    glVertex4fv(&vertex[a].vertex[0]);
    glColor4fv(&vertex[b].color[0]);
    glVertex4fv(&vertex[b].vertex[0]);
    glColor4fv(&vertex[c].color[0]);
    glVertex4fv(&vertex[c].vertex[0]);
}

void Pyramid::drawShape( void )
{
    // uses the model/view/projection matrices set by the caller

    glBegin(GL_TRIANGLES);
      drawTriangle(0,1,2); // rgb face
      drawTriangle(3,1,2); // wgb
      drawTriangle(0,3,2); // rwb
      drawTriangle(0,1,3); // rgw
    glEnd();
}

// note: back is facing the viewer (-z)
Vertex Pyramid::defaultShape[4] = {
    { { 1.f, 0.f, 0.f, 1.f },          // red point
      { right, upper, back, 1.f } },
    { { 0.f, 1.f, 0.f, 1.f },          // green point
      { left, upper, back, 1.f } },
    { { 0.f, 0.f, 1.f, 1.f },          // blue point
      { center, lower, back, 1.f } },
    { { 1.f, 1.f, 1.f, 1.f },          // white point
      { center, center, front, 1.f } }
};

Pyramid::Pyramid( float x, float y, float z, float w )
{
    // copy whole pyramid in default shape, colors, and scales
    memcpy(vertex, defaultShape, sizeof(vertex));

    // rescale
    vertex[0].vertex[3]
        = vertex[1].vertex[3]
        = vertex[2].vertex[3]
        = vertex[3].vertex[3]
        = w;

    // centroid position
    c[0] = x;
    c[1] = y;
    c[2] = z;
}

