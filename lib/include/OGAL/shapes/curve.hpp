#ifndef CURVE_HPP
#define CURVE_HPP

#include "../renderable.hpp"

#include <glm/glm.hpp>

namespace OGAL {
    class Curve : public Renderable {
    public:
        /// Overrides Renderable::return_buffer_texture_pairs(), and is called by OGAL::draw in order to
        /// get the data it needs to render this square
        std::vector<OGAL::buffer_texture_pair> return_buffer_texture_pairs() override;
    
        /// Sets the list of all points on a curve
        void set_positions(std::vector<glm::vec<2, float, (glm::qualifier) 0>> positions);
    
        /// Returns all positions
        std::vector<glm::vec<2, float, (glm::qualifier) 0>> get_positions();
    
        /// Getter and setter functions for the square's color
        void set_color(glm::vec<4, float, (glm::qualifier) 0> color);
    
        void set_color(GLuint r, GLuint g, GLuint b, GLuint a);
    
        glm::vec<4, float, (glm::qualifier) 0> get_color();
    
        /// The vertex buffer that was generated, when either the positions, or color was changed
        std::vector<GLfloat> generated_vertex_buffer_;

    protected:
    
        void recalculate();
    
        std::vector<glm::vec<2, float, (glm::qualifier) 0>> positions_;
        glm::vec<4, float, (glm::qualifier) 0> color_;
    
        OGAL::VBO vertex_buffer_;

    private:
    
    };
}

#endif //CURVE_HPP
