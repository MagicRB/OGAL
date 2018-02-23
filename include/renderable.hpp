#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <vector>
#include <GL/glew.h>
#include <GL/gl.h>

#include "vbo.hpp"

namespace OGAL {
    class renderable {
        public:
            renderable();
            ~renderable();

            virtual std::vector<GLuint> return_vertex_buffer_ids() = 0;

        protected:

        private:

    };
}

#endif //RENDERABLE_HPP
