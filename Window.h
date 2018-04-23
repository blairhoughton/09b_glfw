
#pragma once

#include "GLFW/glfw3.h"

class Window
{
    GLFWwindow* window;
public:
    Window( int w = 640,
            int h = 480,
            const char*  title   = "",
            GLFWmonitor* monitor = nullptr,
            GLFWwindow*  share   = nullptr );
    ~Window() { glfwDestroyWindow( window ); }

    inline GLFWwindow* getWindow( void ) { return window; }
    inline int shouldClose( void ) {
        return glfwWindowShouldClose( window );
    };
    inline void swapBuffers( void ) { glfwSwapBuffers( window ); }

    GLFWkeyfun setKeyboardHandler( GLFWkeyfun handler );
    void applyContext( void );
};

