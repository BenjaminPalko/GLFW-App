#include "shader-system.hpp"

typedef struct Vertex {
  vec2 pos;
  vec3 col;
} Vertex;

static const Vertex vertices[3] = {{{-0.6f, -0.4f}, {1.f, 0.f, 0.f}},
                                   {{0.6f, -0.4f}, {0.f, 1.f, 0.f}},
                                   {{0.f, 0.6f}, {0.f, 0.f, 1.f}}};

static const std::string vertex_shader_text = R"(
  #version 330
  uniform mat4 MVP;
  in vec3 vCol;
  in vec2 vPos;
  out vec3 color;
  void main()
  {
    gl_Position = MVP * vec4(vPos, 0.0, 1.0);
    color = vCol;
  }
)";

static const std::string fragment_shader_text = R"(
  #version 330
  in vec3 color;
  out vec4 fragment;
  void main()
  {
    fragment = vec4(color, 1.0);
  }
)";

ShaderSystem::ShaderSystem() {
  glGenBuffers(1, &vertex_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  VertexShader vertex_shader = VertexShader();
  vertex_shader.SetSource(vertex_shader_text);
  vertex_shader.Compile();

  FragmentShader fragment_shader = FragmentShader();
  fragment_shader.SetSource(fragment_shader_text);
  fragment_shader.Compile();

  program = glCreateProgram();
  vertex_shader.Attach(program);
  fragment_shader.Attach(program);
  glLinkProgram(program);

  mvp_location = glGetUniformLocation(program, "MVP");
  vpos_location = glGetAttribLocation(program, "vPos");
  vcol_location = glGetAttribLocation(program, "vCol");

  glGenVertexArrays(1, &vertex_array);
  glBindVertexArray(vertex_array);
  glEnableVertexAttribArray(vpos_location);
  glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void *)offsetof(Vertex, pos));
  glEnableVertexAttribArray(vcol_location);
  glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void *)offsetof(Vertex, col));
}

int ShaderSystem::Draw(int width, int height, float time) {
  const float ratio = width / (float)height;

  glViewport(0, 0, width, height);
  glClear(GL_COLOR_BUFFER_BIT);

  mat4x4 m, p, mvp;
  mat4x4_identity(m);
  mat4x4_rotate_Z(m, m, time);
  mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
  mat4x4_mul(mvp, p, m);

  glUseProgram(program);
  glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat *)&mvp);
  glBindVertexArray(vertex_array);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  return 0;
}
