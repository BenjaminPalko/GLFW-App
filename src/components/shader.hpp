#include <GL/glew.h>
#include <string>

class Shader {
public:
  Shader(GLuint shader);

protected:
  GLuint shader;

public:
  void SetSource(std::string source);
  void SetSource(const char *source);
  void Compile();
  void Attach(GLuint program);
};

class VertexShader : public Shader {
public:
  VertexShader();
};

class FragmentShader : public Shader {
public:
  FragmentShader();
};
