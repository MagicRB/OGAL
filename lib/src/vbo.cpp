#include "OGAL/vbo.hpp"

#include <stdio.h>

OGAL::VBO::VBO()
{
    glGenBuffers(1, &vbo_id_);
}


OGAL::VBO::~VBO()
{
    glDeleteBuffers(1, &vbo_id_);
}

void OGAL::VBO::set_data(std::vector<GLfloat> data)
{
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), &data[0], GL_STATIC_DRAW);
}

void OGAL::VBO::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);
}
