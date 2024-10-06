#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "systems/shader-system.hpp"

class Program {
  GLFWwindow *window;
  ShaderSystem shaderSystem;

public:
  Program(GLFWwindow *window, class ShaderSystem shaderSystem);
  int Loop();
};
