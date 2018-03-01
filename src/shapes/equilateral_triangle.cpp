#include "shapes/equilateral_triangle.hpp"

#include <math.h>
#include <stdio.h>

OGAL::EquilateralTriangle::EquilateralTriangle()
{
    position_.x = 0;
    position_.y = 0;
}

OGAL::EquilateralTriangle::~EquilateralTriangle()
{}

std::vector<OGAL::buffer_texture_pair2> OGAL::EquilateralTriangle::return_buffer_texture_pairs()
{
     return std::vector<OGAL::buffer_texture_pair2>(1, {vertex_buffer_.vbo_id_, vertex_buffer_.size_ / 9, 0, 0});
}

void OGAL::EquilateralTriangle::set_position(glm::vec<2, float, (glm::qualifier)0> position)
{
    position_ = position;
    recalculate();
}

void OGAL::EquilateralTriangle::set_position(float x, float y)
{
    position_ = glm::vec<2, float, (glm::qualifier)0>(x, y);
    recalculate();
}

glm::vec<2, float, (glm::qualifier)0> OGAL::EquilateralTriangle::get_position()
{
    return position_;
}

void OGAL::EquilateralTriangle::set_color(glm::vec<4, float, (glm::qualifier)0> color)
{
    color_ = color;
    recalculate();
}

void OGAL::EquilateralTriangle::set_color(GLuint r, GLuint g, GLuint b, GLuint a)
{
    color_ = glm::vec<4, float, (glm::qualifier)0>(r, g, b, a);
    recalculate();
}

glm::vec<4, float, (glm::qualifier)0> OGAL::EquilateralTriangle::get_color()
{
    return color_;
}

void OGAL::EquilateralTriangle::set_dimensions(short unsigned int type, GLfloat a)
{
    a_ = a;
    type_ = type;

    recalculate();
}

void OGAL::EquilateralTriangle::recalculate()
{
    std::vector<GLfloat> v;


    if (type_ == 0) {
        v = {   position_.x                                  , position_.y  + a_ / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, uv_.x, uv_.y,
                position_.x - (2.0f * a_ / sqrt(3.0f) / 2.0f), position_.y  - a_ / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, uv_.x, uv_.y,
                position_.x + (2.0f * a_ / sqrt(3.0f) / 2.0f), position_.y  - a_ / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, uv_.x, uv_.y
        };
    } else if (type_ == 1) {
        v = {   position_.x            , position_.y + (a_ / 2.0f * sqrt(3.0f)) / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, uv_.x, uv_.y,
                position_.x - a_ / 2.0f, position_.y - (a_ / 2.0f * sqrt(3.0f)) / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, uv_.x, uv_.y,
                position_.x + a_ / 2.0f, position_.y - (a_ / 2.0f * sqrt(3.0f)) / 2.0f, 0.0f, color_.r, color_.g, color_.b, color_.a, uv_.x, uv_.y
        };
    }

    generated_vertex_buffer_ = v;

    vertex_buffer_.bind();

    vertex_buffer_.size_ = v.size();
    vertex_buffer_.set_data(v);
}
