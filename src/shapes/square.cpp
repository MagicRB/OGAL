#include "shapes/square.hpp"

OGAL::square::square()
{
    position.x = 0;
    position.y = 0;
}

OGAL::square::~square()
{}

std::vector<OGAL::buffer_texture_pair2> OGAL::square::return_buffer_texture_pairs()
{
     return std::vector<OGAL::buffer_texture_pair2>(1, {vertex_buffer.vbo_id, vertex_buffer.size / 9, texture.texture_id});
}

void OGAL::square::set_dimensions(short unsigned int pType, GLfloat pA)
{
    a = pA;
    type = pType;

    recalculate();
}

void OGAL::square::recalculate()
{
    std::vector<GLfloat> v;

    if (type == 0) {
        v = {   position.x - a / 2.0f, position.y + a / 2.0f, 0.0f, color.r, color.g, color.b, color.a, 0.0f, 1.0f,
                position.x + a / 2.0f, position.y + a / 2.0f, 0.0f, color.r, color.g, color.b, color.a, 1.0f, 1.0f,
                position.x - a / 2.0f, position.y - a / 2.0f, 0.0f, color.r, color.g, color.b, color.a, 0.0f, 0.0f,
                position.x + a / 2.0f, position.y + a / 2.0f, 0.0f, color.r, color.g, color.b, color.a, 1.0f, 1.0f,
                position.x + a / 2.0f, position.y - a / 2.0f, 0.0f, color.r, color.g, color.b, color.a, 1.0f, 0.0f,
                position.x - a / 2.0f, position.y - a / 2.0f, 0.0f, color.r, color.g, color.b, color.a, 0.0f, 0.0f
        };
    }

    vertex_buffer.bind();

    vertex_buffer.size = v.size();
    vertex_buffer.set_data(v);

}
