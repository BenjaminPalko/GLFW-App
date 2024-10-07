#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "shader-system.hpp"

class WindowSystem {
  GLFWwindow *window;
  ShaderSystem shaderSystem;

public:
  WindowSystem(GLFWwindow *window, class ShaderSystem shaderSystem);
  int Loop();
};
