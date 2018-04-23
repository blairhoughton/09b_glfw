// creates a glfw window with a black background and a rotating triangle

// includes GL headers, plus the X11 and pthreads headers it needs
// (maybe; all the #includes in glfw3.h seem to be wrapped and
// require GLFW_INCLUDE_* to be defined to get the includes done;
// that's probably something that libglfw3 does in its build, and
// the 01glfw app only compiled because it only used glfw elements)
#include <GLFW/glfw3.h>

#include "Model.h"
#include "Window.h"
#include "KeyboardHandler.h"

int main(void)
{
    if (!glfwInit())
        return -1;

    Window window;  // defaults to 640x480, generic title and screen, no share

    window.setKeyboardHandler( KeyboardHandler::callback );

    // create model including all objects
    Model model;

    // loop until someting asks to close the window
    while ( !window.shouldClose() )
    {
        // after this, all things drawn will go to this window
        // and will appear in the window's perspective; needs
        // to be called each time through the loop because size
        // and aspect ratio may have changed
        window.applyContext();

        // don't need to tell the model what window to draw to because
        // everything it draws now goes to the current context
        model.render( glfwGetTime() );

        // could render from another model here, or
        // could apply another context and render another model

        window.swapBuffers();

        // one call handles all windows
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

