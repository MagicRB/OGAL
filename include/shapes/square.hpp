#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "renderable.hpp"
#include "vbo.hpp"
#include "texture.hpp"

#include <glm/glm.hpp>

namespace OGAL {
    class square: public renderable {
        public:

            square();
            ~square();

            glm::vec<2, float, (glm::qualifier)0> position;
            glm::vec<4, float, (glm::qualifier)0> color;
            glm::vec<2, float, (glm::qualifier)0> uv;

            std::vector<OGAL::buffer_texture_pair2> return_buffer_texture_pairs();

            void set_dimensions(short unsigned int pType, GLfloat pA);

            OGAL::texture texture;

        protected:

            short unsigned int type;
            short unsigned int a;

            void recalculate();

            OGAL::vbo vertex_buffer;

        private:

    };
}

#endif //SQUARE_HPP
