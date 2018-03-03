#include "shapes/line.hpp"

std::vector<OGAL::buffer_texture_pair2> OGAL::Line::return_buffer_texture_pairs()
{

}

void OGAL::Line::set_positions(GLfloat x, GLfloat y, GLfloat x2, GLfloat y2)
{
    position_ = glm::vec<4, float, (glm::qualifier)0>(x, y, x2, y2);
}

void OGAL::Line::set_positions(glm::vec<2, float, (glm::qualifier)0> position1, glm::vec<2, float, (glm::qualifier)0> position2)
{
    position_ = glm::vec<4, float, (glm::qualifier)0>(position1.x, position1.y, position2.x, position2.y);
}

void OGAL::Line::set_positions(glm::vec<4, float, (glm::qualifier)0> position)
{
    position_ = position;
}

glm::vec<4, float, (glm::qualifier)0> OGAL::Line::get_positions()
{
    return position_;
}

void OGAL::Line::set_color(glm::vec<4, float, (glm::qualifier)0> color)
{
    color_ = color;
}

void OGAL::Line::set_color(GLuint r, GLuint g, GLuint b, GLuint a)
{
    color_ = glm::vec<4, float, (glm::qualifier)0>(r, g, b, a);
}

glm::vec<4, float, (glm::qualifier)0> OGAL::Line::get_color()
{
    return color_;
}
