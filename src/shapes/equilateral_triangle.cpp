#include "shapes/equilateral_triangle.hpp"

#include <math.h>
#include <stdio.h>

OGAL::equilateral_triangle::equilateral_triangle()
{}

OGAL::equilateral_triangle::~equilateral_triangle()
{}

std::vector<GLuint> OGAL::equilateral_triangle::return_vertex_buffer_ids()
{
    return std::vector<GLuint> (1, vertex_buffer.vbo_id);
}

void OGAL::equilateral_triangle::set_height(GLfloat h)
{
    std::vector<GLfloat> v = {  0.0f                            , 0.0f  + h/2.0f, 0.0f,
                                0.0f - (h/(sqrt(3.0f)/2.0f))    , 0.0f  - h/2.0f, 0.0f,
                                0.0f + (h/(sqrt(3.0f)/2.0f))    , 0.0f  - h/2.0f, 0.0f
    };

    vertex_buffer.bind();

    vertex_buffer.set_data(v);
}
