#include "OGAL/shapes/square.hpp"

#define STB_IMAGE_IMPLEMENTATION

#include "OGAL/stb_image.h"

OGAL::Square::Square()
{
    position_.x = 0;
    position_.y = 0;
}

OGAL::Square::~Square() {}

void OGAL::Square::set_position(glm::vec<2, float, (glm::qualifier) 0> position)
{
    position_ = position;
    recalculate();
}

void OGAL::Square::set_position(float x, float y)
{
    position_ = glm::vec<2, float, (glm::qualifier) 0>(x, y);
    recalculate();
}

glm::vec<2, float, (glm::qualifier) 0> OGAL::Square::get_position()
{
    return position_;
}

void OGAL::Square::set_color(glm::vec<4, float, (glm::qualifier) 0> color)
{
    color_ = color;
    recalculate();
}

void OGAL::Square::set_color(GLuint r, GLuint g, GLuint b, GLuint a)
{
    color_ = glm::vec<4, float, (glm::qualifier) 0>(r, g, b, a);
    recalculate();
}

glm::vec<4, float, (glm::qualifier) 0> OGAL::Square::get_color()
{
    return color_;
}

std::vector<OGAL::buffer_texture_pair> OGAL::Square::return_buffer_texture_pairs()
{
    return std::vector<OGAL::buffer_texture_pair>(1, {GL_TRIANGLES, vertex_buffer_.vbo_id_, vertex_buffer_.size_ / 10,
                                                      texture_.texture_id_, texture3D_.texture_id_, use_texture_,
                                                      texture3D_.texture_id_});
}

void OGAL::Square::set_dimensions(short unsigned int type, GLfloat a)
{
    a_ = a;
    type_ = type;
    
    recalculate();
}

void OGAL::Square::enable_texture(bool use_texture)
{
    use_texture_ = use_texture;
}

void OGAL::Square::recalculate()
{
    std::vector<GLfloat> v;
    
    if (type_ == 0) {
        v = {position_.x - a_ / 2.0f, position_.y + a_ / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, 0.0f, 1.0f,
             0.0f,
             position_.x + a_ / 2.0f, position_.y + a_ / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, 1.0f, 1.0f,
             0.0f,
             position_.x - a_ / 2.0f, position_.y - a_ / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, 0.0f, 0.0f,
             0.0f,
             position_.x + a_ / 2.0f, position_.y + a_ / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, 1.0f, 1.0f,
             0.0f,
             position_.x + a_ / 2.0f, position_.y - a_ / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, 1.0f, 0.0f,
             0.0f,
             position_.x - a_ / 2.0f, position_.y - a_ / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, 0.0f, 0.0f,
             0.0f
        };
    }
    
    generated_vertex_buffer_ = v;
    
    vertex_buffer_.bind();
    
    vertex_buffer_.size_ = v.size();
    vertex_buffer_.set_data(v);
}

void OGAL::Square::load_texture_from_file(const char* file)
{
    int width, height, bpp;
    unsigned char* rgb = stbi_load(file, &width, &height, &bpp, 4);
    
    texture_.set_data(rgb, width, height);
}

void OGAL::Square::load_texture3d_from_file(const char* file, GLfloat layer)
{
    int width, height, bpp;
    unsigned char* rgb = stbi_load(file, &width, &height, &bpp, 4);
    
    texture3D_.add_data(rgb, width, height, 1, layer);
}

void OGAL::Square::enable_texture3d(bool use_texture3d)
{
    use_texture_ = use_texture3d;
    use_texture3d_ = 1;
}
