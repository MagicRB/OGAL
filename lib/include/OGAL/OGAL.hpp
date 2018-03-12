#include "program.hpp"
#include "renderable.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "vao.hpp"
#include "vbo.hpp"
#include "event.hpp"
#include <glm/glm.hpp>
#include <iostream>


namespace OGAL {
    
    /// A function which polls for events
    OGAL::event poll_events();
    
    /// A function to draw a specific renderable, to a specific window
    void
    draw(GLFWwindow* window, OGAL::Renderable* Renderable, GLuint program_id, glm::vec2 projection, glm::vec2 camera);
    
    /// Default window resize function, which enables OGAL window resize events to work
    void window_size_callback(GLFWwindow* window, int width, int height);
    
    /// Default key callback function, which enables OGAL key events to work
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    
    /// Default error callback function, which enables OGAL error events to work
    void error_callback(int error, const char* description);
    
    /// Default mouse button callback function, which enables OGAL mouse button events to work
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    
    /// Converts screen to world coordinates, assumes that scale is half of what is actually visible on screen and screen position is from 0 to whatever you window size is, centered at the top left corner
    glm::vec2
    screen_to_world_space(GLFWwindow* window, float scale, glm::vec2 camera_position, glm::vec2 screen_position);
    
    /// Initializes OGAL and all required libs
    GLFWwindow* init_ogal(int width, int height, const char* title, OGAL::Shader* vertex_shader,
                          OGAL::Program* program, OGAL::Shader* fragment_shader, OGAL::VAO* vao, bool setup_callbacks,
                          bool setup_shaders);
}
