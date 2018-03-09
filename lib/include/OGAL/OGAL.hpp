#include "program.hpp"
#include "renderable.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "texture_3d.hpp"
#include "vao.hpp"
#include "vbo.hpp"
#include "event.hpp"
#include <glm/glm.hpp>


namespace OGAL {
    
    /// A function which polls for events
    OGAL::event poll_events();
    
    /// A function to draw a specific renderable, to a specific window
    void
    draw(GLFWwindow* window, OGAL::Renderable* Renderable, GLuint program_id, glm::mat4 projection, glm::vec2 camera);
    
    /// Default window resize function, which enables OGAL window resize events to work
    void window_size_callback(GLFWwindow* window, int width, int height);
    
    /// Default key callback function, which enables OGAL key events to work
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    
    /// Initializes OGAL and all required libs
    GLFWwindow* init_ogal(int width, int height, const char* title, OGAL::Shader* vertex_shader,
                          OGAL::Program* program, OGAL::Shader* fragment_shader, OGAL::VAO* vao, bool setup_callbacks,
                          bool setup_shaders);
}
