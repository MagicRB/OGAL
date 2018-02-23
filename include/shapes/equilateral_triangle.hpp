#ifndef EQUILATERAL_TRIANGLE_HPP
#define EQUILATERAL_TRIANGLE_HPP

#include "renderable.hpp"
#include "vbo.hpp"

namespace OGAL {
    class equilateral_triangle: public renderable {
        public:

            equilateral_triangle();
            ~equilateral_triangle();

            std::vector<GLuint> return_vertex_buffer_ids();

            void set_height(GLfloat h);

        protected:

            OGAL::vbo vertex_buffer;

        private:

    };
}

#endif //EQUILATERAL_TRIANGLE_HPP
