
#include "Window.h"

Window::Window( int w,
                int h,
                const char*  title,
                GLFWmonitor* monitor,
                GLFWwindow*  share )
{
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow( w, h, title, nullptr, nullptr );

    if ( window )
    {
        /* Make the window's context current */
        glfwMakeContextCurrent( window );

        // set swap rate to HW frame refresh rate (probably superfluous;
        // measurements show it has no effect on actual loop rate; default
        // and 1 both run about 60 fps.
        // setting it to 0 will make some piece of the hardware whine aloud
        // but not change anything visible; so it's probably really bad mojo.
        // setting it to 2 adds visible stuttering.
        glfwSwapInterval( 1 );

        // make it so that things in front occlude things behind them
        glEnable( GL_DEPTH_TEST );
    }
    else
    {
        glfwTerminate();
    }
}

GLFWkeyfun
Window::setKeyboardHandler( GLFWkeyfun handler )
{
    // set callback to handle keyboard events seen by glfwPollEvents
    // returns 0 on first call, old handler on subsequent calls
    return glfwSetKeyCallback( window, handler );
}

void
Window::applyContext( void )
{
    glfwMakeContextCurrent( window );

    // TODO: viewport setting probably belongs in a size-change handler
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = width / (float) height;
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
}

