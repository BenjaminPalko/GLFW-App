#include <GL/glew.h>
#include <linmath.h>

class ShaderSystem {
  GLuint vertex_buffer;
  GLuint vertex_shader;
  GLuint fragment_shader;
  GLuint program;
  GLint mvp_location;
  GLint vpos_location;
  GLint vcol_location;
  GLuint vertex_array;

public:
  ShaderSystem();
  int Draw(int width, int height, float time);
};
