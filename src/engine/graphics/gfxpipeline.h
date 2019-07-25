#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Engine {
class GFXPipeline {
 private:
  // TODO: Likely have these in a separate camera class
  glm::mat4 projection;
  glm::mat4 view;

 public:
  // TODO: hardcoded values
  GFXPipeline() : projection{glm::perspective(glm::radians(45.f), 4.f / 3.f, 0.1f, 100.f)},
                  view{glm::lookAt(glm::vec3(4, 3, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0))} {}

  void configGLContext();
  void initGL();
  void draw();

  void precompileShaders();
};
} // namespace Engine