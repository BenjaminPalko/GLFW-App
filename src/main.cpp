#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <fmt/core.h>
#include <linmath.h>

typedef struct Vertex {
  vec2 pos;
  vec3 col;
} Vertex;

static const Vertex vertices[3] = {{{-0.6f, -0.4f}, {1.f, 0.f, 0.f}},
                                   {{0.6f, -0.4f}, {0.f, 1.f, 0.f}},
                                   {{0.f, 0.6f}, {0.f, 0.f, 1.f}}};

static const char *vertex_shader_text =
    "#version 330\n"
    "uniform mat4 MVP;\n"
    "in vec3 vCol;\n"
    "in vec2 vPos;\n"
    "out vec3 color;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
    "    color = vCol;\n"
    "}\n";

static const char *fragment_shader_text = "#version 330\n"
                                          "in vec3 color;\n"
                                          "out vec4 fragment;\n"
                                          "void main()\n"
                                          "{\n"
                                          "    fragment = vec4(color, 1.0);\n"
                                          "}\n";

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

  /*  GLEW  */
  GLenum code = glewInit();
  if (code != GLEW_OK) {
    fmt::print("GLEW failed to init! {} - {}\n", code,
               glewGetErrorString(code));
    return -1;
  }

  glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

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
