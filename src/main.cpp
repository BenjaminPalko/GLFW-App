#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <fmt/core.h>

#include "systems/window-system.hpp"

void error_callback(int error_code, const char *description) {
  fmt::print("[ERROR - {}] {}\n", error_code, description);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods) {
  const char *key_name = glfwGetKeyName(key, scancode);
  if (key_name == NULL)
    return;
  fmt::print("Key pressed {}\n", key_name);
}

int main() {

  glfwSetErrorCallback(error_callback);

  int supported = glfwPlatformSupported(GLFW_PLATFORM_WAYLAND);
  fmt::print("Wayland support: {}\n", supported == GLFW_TRUE);

  if (!glfwInit()) {
    const char *description;
    int code = glfwGetError(&description);
    fmt::print("GLFW failed to init! {} - {}\n", code, description);
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(640, 480, "GLFW", NULL, NULL);
  if (!window) {
    glfwTerminate();
    fmt::print("Window or OpenGL context creation failed\n");
    return -1;
  }

  glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  /*  GLEW  */
  GLenum err = glewInit();
  if (err != GLEW_OK) {
    fmt::print("GLEW failed to init! {}\n", err);
    return -1;
  }

  ShaderSystem shaderSystem = ShaderSystem();
  WindowSystem program = WindowSystem(window, shaderSystem);

  program.Loop();

  glfwDestroyWindow(window);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}
