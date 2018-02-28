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

std::vector<GLuint> OGAL::EquilateralTriangle::return_vertex_buffer_ids()
{
    return std::vector<GLuint> (1, vertex_buffer_.vbo_id_);
}

std::vector<GLuint> OGAL::EquilateralTriangle::return_vertex_buffer_sizes()
{
    return std::vector<GLuint> (1, vertex_buffer_.size_ / 3);
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

    vertex_buffer_.bind();

    vertex_buffer_.size_ = v.size();
    vertex_buffer_.set_data(v);
}
