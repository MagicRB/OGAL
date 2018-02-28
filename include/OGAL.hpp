#include "program.hpp"
#include "render_list.hpp"
#include "renderable.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "vao.hpp"
#include "vbo.hpp"
#include "event.hpp"


namespace OGAL {
    OGAL::event poll_events();


    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
}
