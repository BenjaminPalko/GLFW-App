#include <GLFW/glfw3.h>
#include <fmt/core.h>

int main() {

  int supported = glfwPlatformSupported(GLFW_PLATFORM_WAYLAND);
  fmt::print("Wayland support: {}\n", supported == GLFW_TRUE);

  if (!glfwInit()) {
    const char *description;
    int code = glfwGetError(&description);
    fmt::print("GLFW failed to init! {} - {}\n", code, description);
    return -1;
  }
  GLFWwindow *window =
      glfwCreateWindow(640, 480, "GLFW", glfwGetPrimaryMonitor(), NULL);

  if (!window) {
    glfwTerminate();
    fmt::print("Window or OpenGL context creation failed\n");
    return -1;
  }

  glfwMakeContextCurrent(window);
  glClearColor(0.4f, 0.3f, 0.4f, 0.0f);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
