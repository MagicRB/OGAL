#include "shapes/equilateral_triangle.hpp"

#include <math.h>
#include <stdio.h>

OGAL::equilateral_triangle::equilateral_triangle()
{
    position.x = 0;
    position.y = 0;
}

OGAL::equilateral_triangle::~equilateral_triangle()
{}

std::vector<GLuint> OGAL::equilateral_triangle::return_vertex_buffer_ids()
{
    return std::vector<GLuint> (1, vertex_buffer.vbo_id);
}

std::vector<GLuint> OGAL::equilateral_triangle::return_vertex_buffer_sizes()
{
    return std::vector<GLuint> (1, vertex_buffer.size / 3);
}

void OGAL::equilateral_triangle::set_dimensions(short unsigned int pType, GLfloat pA)
{
    a = pA;
    type = pType;

    recalculate();
}

void OGAL::equilateral_triangle::recalculate()
{
    std::vector<GLfloat> v;


    if (type == 0) {
        v = {   position.x                                 , position.y  + a/2.0f, 0.0f, color.r, color.g, color.b, color.a, uv.x, uv.y,
                position.x - (2.0f * a / sqrt(3.0f) / 2.0f), position.y  - a/2.0f, 0.0f, color.r, color.g, color.b, color.a, uv.x, uv.y,
                position.x + (2.0f * a / sqrt(3.0f) / 2.0f), position.y  - a/2.0f, 0.0f, color.r, color.g, color.b, color.a, uv.x, uv.y
        };
    } else if (type == 1) {
        v = {   position.x           , position.y + (a / 2.0f * sqrt(3.0f)) / 2.0f, 0.0f, color.r, color.g, color.b, color.a, uv.x, uv.y,
                position.x - a / 2.0f, position.y - (a / 2.0f * sqrt(3.0f)) / 2.0f, 0.0f, color.r, color.g, color.b, color.a, uv.x, uv.y,
                position.x + a / 2.0f, position.y - (a / 2.0f * sqrt(3.0f)) / 2.0f, 0.0f, color.r, color.g, color.b, color.a, uv.x, uv.y
        };
    }

    vertex_buffer.bind();

    vertex_buffer.size = v.size();
    vertex_buffer.set_data(v);
}
