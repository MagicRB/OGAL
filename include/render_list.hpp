#ifndef RENDER_LIST_HPP
#define RENDER_LIST_HPP

#include "renderable.hpp"

#include <vector>
#include <GL/glew.h>
#include <GL/gl.h>

#include <glm/glm.hpp>

namespace OGAL {

    class render_list;

    void draw_render_list(render_list vrender_list, GLuint program_id, glm::mat4 projection);

    struct buffer_texture_pair {
        GLuint buffer_id;
        GLuint texture_id;
    };

    class render_list {
        public:
            render_list();
            ~render_list();

            unsigned int add_renderable(OGAL::renderable* renderable);

            std::vector<buffer_texture_pair> render_vector;

        protected:

        private:

    };
}

#endif //RENDER_LIST_HpP
