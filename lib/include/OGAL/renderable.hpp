#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <vector>
#include <GL/glew.h>
#include <GL/gl.h>

#include "vbo.hpp"

namespace OGAL {

    struct buffer_texture_pair {
        GLuint render_type;
        GLuint buffer_id;
        GLuint buffer_size;
        GLuint texture_id;
        GLuint use_texture;
    };

    class Renderable {
        public:
            Renderable();
            ~Renderable();

            /// Function which returns everything needed to render a mesh
            virtual std::vector<OGAL::buffer_texture_pair> return_buffer_texture_pairs();

        protected:

        private:

    };
}

#endif //RENDERABLE_HPP
