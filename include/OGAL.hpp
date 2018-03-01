#include "program.hpp"
#include "render_list.hpp"
#include "renderable.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "vao.hpp"
#include "vbo.hpp"
#include "event.hpp"


namespace OGAL {

    /// A function which polls for events
    OGAL::event poll_events();

    /// Default window resize function, which enables OGAL window resize events to work
    void window_size_callback(GLFWwindow* window, int width, int height);

    /// Default key callback function, which enables OGAL key events to work
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
}
