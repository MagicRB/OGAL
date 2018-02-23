#include "vao.hpp"

OGAL::vao::vao()
{
    glGenVertexArrays(1, &vao_id);
}

OGAL::vao::~vao()
{}

void OGAL::vao::bind()
{
    glBindVertexArray(vao_id);
}
