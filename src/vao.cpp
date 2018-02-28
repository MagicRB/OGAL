#include "vao.hpp"

OGAL::VAO::VAO()
{
    glGenVertexArrays(1, &vao_id_);
}

OGAL::VAO::~VAO()
{}

void OGAL::VAO::bind()
{
    glBindVertexArray(vao_id_);
}
