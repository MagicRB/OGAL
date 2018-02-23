#include "vbo.hpp"

#include <stdio.h>

OGAL::vbo::vbo()
{
    glGenBuffers(1, &vbo_id);
    printf("%d\n", vbo_id);
}


OGAL::vbo::~vbo()
{
    glDeleteBuffers(1, &vbo_id);
}

void OGAL::vbo::set_data(std::vector<GLfloat> data)
{
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), &data[0], GL_STATIC_DRAW);
}

void OGAL::vbo::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
}
