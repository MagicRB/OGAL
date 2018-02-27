#ifndef EQUILATERAL_TRIANGLE_HPP
#define EQUILATERAL_TRIANGLE_HPP

#include "renderable.hpp"
#include "vbo.hpp"

#include <glm/glm.hpp>

namespace OGAL {
    class equilateral_triangle: public renderable {
        public:

            equilateral_triangle();
            ~equilateral_triangle();

            glm::vec<2, float, (glm::qualifier)0> position;
            glm::vec<4, float, (glm::qualifier)0> color;
            glm::vec<2, float, (glm::qualifier)0> uv;

            std::vector<GLuint> return_vertex_buffer_ids();
            std::vector<GLuint> return_vertex_buffer_sizes();

            void set_dimensions(short unsigned int pType, GLfloat pA);

        protected:

            short unsigned int type;
            short unsigned int a;

            void recalculate();

            OGAL::vbo vertex_buffer;

        private:

    };
}

#endif //EQUILATERAL_TRIANGLE_HPP
