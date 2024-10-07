#ifndef WINDOWSYSTEM_HPP
#define WINDOWSYSTEM_HPP

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "shadersystem.hpp"

class WindowSystem {
  GLFWwindow *window;
  ShaderSystem shaderSystem;

public:
  WindowSystem(GLFWwindow *window, class ShaderSystem shaderSystem);
  int Loop();
};

#endif // WINDOWSYSTEM_HPP
