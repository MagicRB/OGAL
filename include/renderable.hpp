#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <vector>
#include <GL/glew.h>
#include <GL/gl.h>

#include "vbo.hpp"

namespace OGAL {

    struct buffer_texture_pair2 {
        GLuint buffer_id;
        GLuint buffer_size;
        GLuint texture_id;
    };

    class renderable {
        public:
            renderable();
            ~renderable();

            virtual std::vector<OGAL::buffer_texture_pair2> return_buffer_texture_pairs() = 0;

        protected:

        private:

    };
}

#endif //RENDERABLE_HPP
