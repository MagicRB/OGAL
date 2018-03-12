#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "../renderable.hpp"
#include "../vbo.hpp"
#include "../texture.hpp"

#include <glm/glm.hpp>

namespace OGAL {
    class Square : public Renderable {
    public:
        
        Square();
        
        ~Square();
        
        /// Overrides Renderable::return_buffer_texture_pairs(), and is called by OGAL::draw in order to
        /// get the data it needs to render this square
        std::vector<OGAL::buffer_texture_pair> return_buffer_texture_pairs() override;
        
        /// Sets dimensions according to a which can be either a side or a diagonal or the square,
        /// type of a depends on short unsigned int type which can be:
        ///         0 - side
        ///         1 - diagonal
        void set_dimensions(short unsigned int type, GLfloat a);
        
        /// Getter and setter functions for the square's position
        void set_position(glm::vec<2, float, (glm::qualifier) 0> position);
        
        void set_position(float x, float y);
        
        glm::vec<2, float, (glm::qualifier) 0> get_position();
        
        /// Getter and setter functions for the square's color
        void set_color(glm::vec<4, float, (glm::qualifier) 0> color);
        
        void set_color(GLuint r, GLuint g, GLuint b, GLuint a);
        
        glm::vec<4, float, (glm::qualifier) 0> get_color();
        
        /// Enables or disables texture, disabled means that plain color will be used, enabled means enabled...
        void enable_texture(bool use_texture);
        
        /// Texture of this square. This variable needs to be public because you have to set the texture using: texture_.set_data(unsigned char* data, GLuint width, GLuint height)
        OGAL::Texture texture_;
        
        /// The vertex buffer that was generated, when either the dimensions, position, or color was changed
        std::vector<GLfloat> generated_vertex_buffer_;
    
        void load_texture_from_file(const char* file);
    
    protected:
        
        short unsigned int type_;
        short unsigned int a_;
        
        GLuint use_texture_ = 0;
        
        void recalculate();
        
        glm::vec<2, float, (glm::qualifier) 0> position_;
        glm::vec<4, float, (glm::qualifier) 0> color_;
        
        OGAL::VBO vertex_buffer_;
    
    private:
    
    };
}

#endif //SQUARE_HPP
