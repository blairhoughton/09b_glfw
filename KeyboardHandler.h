
#pragma once
#include "GLFW/glfw3.h"

class KeyboardHandler
{
public:
    static void callback(GLFWwindow* window,
                         int key,
                         int scancode,
                         int action,
                         int mods);
};

