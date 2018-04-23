
#include "KeyboardHandler.h"

void KeyboardHandler::callback(GLFWwindow* window,
                               int key,
                               int scancode,
                               int action,
                               int mods)
{
    switch ( key )
    {
        case GLFW_KEY_Q:
            if ( action == GLFW_PRESS)
            {
                // close on press of q or Q;
                // can't just terminate here because of restrictions
                // against using glfwTerminate in callbacks;
                // no need to find object to call set method on it,
                // this will get the message to it
                glfwSetWindowShouldClose(window, GL_TRUE);
            }
            break;
    }
}

