#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "renderable.hpp"
#include "vbo.hpp"

#include <glm/glm.hpp>

namespace OGAL {
    class square: public renderable {
        public:

            square();
            ~square();

            glm::vec<2, float, (glm::qualifier)0> position;

            std::vector<GLuint> return_vertex_buffer_ids();
            std::vector<GLuint> return_vertex_buffer_sizes();

            void set_dimensions(short unsigned int pType, GLfloat pA);

        protected:

            short unsigned int type;
            short unsigned int a;

            OGAL::vbo vertex_buffer;

        private:

    };
}

#endif //SQUARE_HPP
