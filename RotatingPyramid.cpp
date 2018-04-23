
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

#include "RotatingPyramid.h"

// does not overload base class draw(void), calls it instead.
void RotatingPyramid::draw( double t )
{
    // DONE: why do the effects of the matrix operations appear
    //       to be applied in reverse order? because they are.
    //       OpenGL uses postfix, column-major matrix operations,
    //       the reverse-polish-notation of linear algebra.

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(c[0], c[1], c[2]);
    // glScalef(scale, scale, scale); they're prescaled by w parameter
    glRotatef(t * thetadot, rot[0], rot[1], rot[2]); // rotate 2nd
    glRotatef(t * phidot, 0.f, 0.f, 1.f); // spin 1st (right-1st)

    drawShape(); // from parent
}

RotatingPyramid::RotatingPyramid( float cx, float cy, float cz, float cw,
                                  float tx, float ty, float tz,
                                  float td, float pd )
  : Pyramid(cx,cy,cz,cw),
    thetadot(td),
    phidot(pd)
{
    rot[0] = tx; // theta-rotation axis vector
    rot[1] = ty;
    rot[2] = tz;
}

