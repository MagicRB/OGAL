#include "OGAL/vao.hpp"

OGAL::VAO::VAO()
{
    glGenVertexArrays(1, &vao_id_);
}

OGAL::VAO::~VAO() = default;

void OGAL::VAO::bind()
{
    glBindVertexArray(vao_id_);
}
