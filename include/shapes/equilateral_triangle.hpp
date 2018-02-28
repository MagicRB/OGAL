#ifndef EQUILATERAL_TRIANGLE_HPP
#define EQUILATERAL_TRIANGLE_HPP

#include "renderable.hpp"
#include "vbo.hpp"

#include <glm/glm.hpp>

namespace OGAL {
    class EquilateralTriangle: public Renderable {
        public:

            EquilateralTriangle();
            ~EquilateralTriangle();

            glm::vec<2, float, (glm::qualifier)0> position_;
            glm::vec<4, float, (glm::qualifier)0> color_;
            glm::vec<2, float, (glm::qualifier)0> uv_;

            std::vector<GLuint> return_vertex_buffer_ids();
            std::vector<GLuint> return_vertex_buffer_sizes();

            void set_dimensions(short unsigned int type, GLfloat a);

        protected:

            short unsigned int type_;
            short unsigned int a_;

            void recalculate();

            OGAL::VBO vertex_buffer_;

        private:

    };
}

#endif //EQUILATERAL_TRIANGLE_HPP
