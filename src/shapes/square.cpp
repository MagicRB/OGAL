#include "shapes/square.hpp"

OGAL::square::square()
{
    position.x = 0;
    position.y = 0;
}

OGAL::square::~square()
{}

std::vector<GLuint> OGAL::square::return_vertex_buffer_ids()
{
    return std::vector<GLuint>(1, vertex_buffer.vbo_id);
}

std::vector<GLuint> OGAL::square::return_vertex_buffer_sizes()
{
    return std::vector<GLuint> (1, vertex_buffer.size / 3);
}

void OGAL::square::set_dimensions(short unsigned int pType, GLfloat pA)
{
    std::vector<GLfloat> v;

    a = pA;
    type = pType;

    if (type == 0) {
        v = {   position.x - a / 2.0f, position.y + a / 2.0f, 0.0f,
                position.x + a / 2.0f, position.y + a / 2.0f, 0.0f,
                position.x - a / 2.0f, position.y - a / 2.0f, 0.0f,
                position.x + a / 2.0f, position.y + a / 2.0f, 0.0f,
                position.x + a / 2.0f, position.y - a / 2.0f, 0.0f,
                position.x - a / 2.0f, position.y - a / 2.0f, 0.0f,
        };
    }

    vertex_buffer.bind();

    vertex_buffer.size = v.size();
    vertex_buffer.set_data(v);
}
