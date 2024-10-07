#include "shader.hpp"

Shader::Shader(GLuint shader) { this->shader = shader; }
void Shader::SetSource(std::string source) { this->SetSource(source.c_str()); }
void Shader::SetSource(const char *source) {
  glShaderSource(shader, 1, &source, NULL);
}
void Shader::Compile() { glCompileShader(shader); }
void Shader::Attach(GLuint program) { glAttachShader(program, shader); }
VertexShader::VertexShader() : Shader(glCreateShader(GL_VERTEX_SHADER)) {}
FragmentShader::FragmentShader() : Shader(glCreateShader(GL_FRAGMENT_SHADER)) {}
