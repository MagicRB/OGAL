#ifndef RENDER_LIST_HPP
#define RENDER_LIST_HPP

#include "renderable.hpp"

#include <vector>
#include <GL/glew.h>
#include <GL/gl.h>

#include <glm/glm.hpp>

namespace OGAL {

    class render_list;

    /// Draws everything added to the render list provided
    void draw_render_list(render_list vrender_list, GLuint program_id, glm::mat4 projection, glm::vec2 camera_pos);

    struct buffer_texture_pair {
        GLuint buffer_id;
        GLuint buffer_size;
        GLuint texture_id;
        GLuint use_texture;
    };

    class render_list {
        public:
            render_list();
            ~render_list();


            /// Adds a renderable to this render_list, renderables can be added to multiple render list at the same time
            unsigned int add_renderable(OGAL::Renderable* renderable);

            /// Vector of all the mesh data required to render a mesh
            std::vector<buffer_texture_pair> render_vector_;

        protected:

        private:

    };
}

#endif //RENDER_LIST_HpP
