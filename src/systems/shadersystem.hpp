#ifndef SHADERSYSTEM_HPP
#define SHADERSYSTEM_HPP

#include <GL/glew.h>
#include <linmath.h>

class ShaderSystem {
  GLuint vertex_buffer;
  GLuint program;
  GLint mvp_location;
  GLint vpos_location;
  GLint vcol_location;
  GLuint vertex_array;

public:
  ShaderSystem();
  int Draw(int width, int height, float time);
  GLuint *CreateBuffer();
};

#endif // SHADERSYSTEM_HPP
