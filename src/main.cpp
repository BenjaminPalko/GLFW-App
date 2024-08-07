#include <fmt/core.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {

  if (!glfwInit()) {
    const char *description;
    int code = glfwGetError(&description);
    fmt::print("GLFW failed to init! {}", code);
    return -1;
  }
  GLFWwindow *window =
      glfwCreateWindow(640, 480, "HELLO WORLD!", glfwGetPrimaryMonitor(), NULL);

  if (!window) {
    glfwTerminate();
    fmt::print("Window or OpenGL context creation failed");
    return -1;
  }

  glfwMakeContextCurrent(window);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
