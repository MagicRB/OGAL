#include "OGAL/vao.hpp"

OGAL::VAO::VAO() = default;

OGAL::VAO::~VAO() = default;

void OGAL::VAO::bind()
{
    glBindVertexArray(vao_id_);
}

void OGAL::VAO::init()
{
    glGenVertexArrays(1, &vao_id_);
}
