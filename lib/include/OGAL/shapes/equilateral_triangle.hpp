#ifndef EQUILATERAL_TRIANGLE_HPP
#define EQUILATERAL_TRIANGLE_HPP

#include "../renderable.hpp"
#include "../vbo.hpp"

#include <glm/glm.hpp>
#include <glm/detail/type_vec.hpp>

namespace OGAL {
    class EquilateralTriangle : public Renderable {
    public:
        
        EquilateralTriangle();
        
        ~EquilateralTriangle();
        
        /// Overrides Renderable::return_buffer_texture_pairs(), and is called by OGAL::draw in order to
        /// get the data it needs to render this triangle
        std::vector<OGAL::buffer_texture_pair> return_buffer_texture_pairs() override;
        
        /// Sets dimensions according to a which can be either a side or a height of the triangle,
        /// type of a depends on short unsigned int type which can be:
        ///         0 - height
        ///         1 - side
        void set_dimensions(short unsigned int type, GLfloat a);
        
        /// Getter and setter functions for the triangle's position
        void set_position(glm::vec<2, float, (glm::qualifier) 0> position);
        
        void set_position(float x, float y);
        
        glm::vec<2, float, (glm::qualifier) 0> get_position();
        
        /// Getter and setter functions for the triangle's color
        void set_color(glm::vec<4, float, (glm::qualifier) 0> color);
        
        void set_color(GLuint r, GLuint g, GLuint b, GLuint a);
        
        glm::vec<4, float, (glm::qualifier) 0> get_color();
        
        /// The vertex buffer that was generated, when either the dimensions, position, or color was changed
        std::vector<GLfloat> generated_vertex_buffer_;
    
    protected:
        
        short unsigned int type_;
        short unsigned int a_;
        
        void recalculate();
        
        glm::vec<2, float, (glm::qualifier) 0> position_;
        glm::vec<4, float, (glm::qualifier) 0> color_;
        glm::vec<2, float, (glm::qualifier) 0> uv_;
        
        OGAL::VBO vertex_buffer_;
    
    private:
    
    };
}

#endif //EQUILATERAL_TRIANGLE_HPP
