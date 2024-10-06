#include "program.hpp"
#include <GLFW/glfw3.h>

Program::Program(GLFWwindow *window, class ShaderSystem shaderSystem) {
  this->window = window;
  this->shaderSystem = shaderSystem;
}

int Program::Loop() {
  while (!glfwWindowShouldClose(window)) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    shaderSystem.Draw(width, height, (float)glfwGetTime());
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  return -1;
}
