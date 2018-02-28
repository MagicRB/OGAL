#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "renderable.hpp"
#include "vbo.hpp"
#include "texture.hpp"

#include <glm/glm.hpp>

namespace OGAL {
    class Square: public Renderable {
        public:

            Square();
            ~Square();

            std::vector<OGAL::buffer_texture_pair2> return_buffer_texture_pairs();

            void set_dimensions(short unsigned int type, GLfloat a);

            void set_position(glm::vec<2, float, (glm::qualifier)0> position);
            void set_position(float x, float y);

            glm::vec<2, float, (glm::qualifier)0> get_position();

            void set_color(glm::vec<4, float, (glm::qualifier)0> color);
            void set_color(GLuint r, GLuint g, GLuint b, GLuint a);

            glm::vec<4, float, (glm::qualifier)0> get_color();

            void enable_texture(bool use_texture);

            OGAL::Texture texture_;

        protected:

            short unsigned int type_;
            short unsigned int a_;

            GLuint use_texture_ = 0;

            void recalculate();

            glm::vec<2, float, (glm::qualifier)0> position_;
            glm::vec<4, float, (glm::qualifier)0> color_;

            OGAL::VBO vertex_buffer_;

        private:

    };
}

#endif //SQUARE_HPP
