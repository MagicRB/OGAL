#include "OGAL/shapes/curve.hpp"

std::vector<OGAL::buffer_texture_pair> OGAL::Curve::return_buffer_texture_pairs()
{
    return std::vector<OGAL::buffer_texture_pair>(1,
                                                  {GL_LINE_STRIP, vertex_buffer_.vbo_id_, vertex_buffer_.size_ / 9, 0,
                                                   0});
}

void OGAL::Curve::set_positions(std::vector<glm::vec<2, float, (glm::qualifier) 0>> positions)
{
    positions_ = positions;
    recalculate();
}

std::vector<glm::vec<2, float, (glm::qualifier) 0>> OGAL::Curve::get_positions()
{
    return positions_;
}

void OGAL::Curve::set_color(glm::vec<4, float, (glm::qualifier) 0> color)
{
    color_ = color;
    recalculate();
}

void OGAL::Curve::set_color(GLuint r, GLuint g, GLuint b, GLuint a)
{
    color_ = glm::vec<4, float, (glm::qualifier) 0>(r, g, b, a);
    recalculate();
}

glm::vec<4, float, (glm::qualifier) 0> OGAL::Curve::get_color()
{
    return color_;
}

void OGAL::Curve::recalculate()
{
    std::vector<GLfloat> v;
    v.reserve(v.size() * 9);
    for (auto &position : positions_) {
        v.push_back(position.x);
        v.push_back(position.y);
        v.push_back(0.0f);
        v.push_back(color_.r);
        v.push_back(color_.g);
        v.push_back(color_.b);
        v.push_back(color_.a);
        v.push_back(0.0f);
        v.push_back(0.0f);
    }
    
    generated_vertex_buffer_ = v;
    
    vertex_buffer_.bind();
    
    vertex_buffer_.size_ = v.size();
    vertex_buffer_.set_data(v);
}
