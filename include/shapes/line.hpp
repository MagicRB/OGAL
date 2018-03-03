#ifndef LINE_HPP
#define LINE_HPP

#include "renderable.hpp"

#include <glm/glm.hpp>

namespace OGAL {
    class Line : public Renderable {
        public:
            /// Overrides Renderable::return_buffer_texture_pairs(), and is called by OGAL::draw in order to
            /// get the data it needs to render this square
            std::vector<OGAL::buffer_texture_pair2> return_buffer_texture_pairs() override;

            /// Sets the two points which are required to draw a line
            void set_positions(GLfloat x, GLfloat y, GLfloat x2, GLfloat y2);
            void set_positions(glm::vec<2, float, (glm::qualifier)0> position1, glm::vec<2, float, (glm::qualifier)0> position2);
            void set_positions(glm::vec<4, float, (glm::qualifier)0> position);

            /// Returns current positions
            glm::vec<4, float, (glm::qualifier)0> get_positions();

            /// Getter and setter functions for the square's color
            void set_color(glm::vec<4, float, (glm::qualifier)0> color);
            void set_color(GLuint r, GLuint g, GLuint b, GLuint a);

            glm::vec<4, float, (glm::qualifier)0> get_color();

        protected:

            glm::vec<4, float, (glm::qualifier)0> position_;
            glm::vec<4, float, (glm::qualifier)0> color_;

        private:

    };
}

#endif //LINE_HPP
