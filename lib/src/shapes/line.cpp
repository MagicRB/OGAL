#include "OGAL/shapes/line.hpp"

std::vector<OGAL::buffer_texture_pair> OGAL::Line::return_buffer_texture_pairs()
{
    return std::vector<OGAL::buffer_texture_pair>(1, {GL_LINES, vertex_buffer_.vbo_id_, vertex_buffer_.size_ / 9, 0, 0});
}

void OGAL::Line::set_positions(GLfloat x, GLfloat y, GLfloat x2, GLfloat y2)
{
    position_ = glm::vec<4, float, (glm::qualifier)0>(x, y, x2, y2);
    recalculate();
}

void OGAL::Line::set_positions(glm::vec<2, float, (glm::qualifier)0> position1, glm::vec<2, float, (glm::qualifier)0> position2)
{
    position_ = glm::vec<4, float, (glm::qualifier)0>(position1.x, position1.y, position2.x, position2.y);
    recalculate();
}

void OGAL::Line::set_positions(glm::vec<4, float, (glm::qualifier)0> position)
{
    position_ = position;
    recalculate();
}

glm::vec<4, float, (glm::qualifier)0> OGAL::Line::get_positions()
{
    return position_;
}

void OGAL::Line::set_color(glm::vec<4, float, (glm::qualifier)0> color)
{
    color_ = color;
    recalculate();
}

void OGAL::Line::set_color(GLuint r, GLuint g, GLuint b, GLuint a)
{
    color_ = glm::vec<4, float, (glm::qualifier)0>(r, g, b, a);
    recalculate();
}

glm::vec<4, float, (glm::qualifier)0> OGAL::Line::get_color()
{
    return color_;
}

void OGAL::Line::recalculate()
{
    std::vector<GLfloat> v = {  position_.x, position_.y, 0.0f, color_.r, color_.g, color_.b, color_.a, 0.0f, 0.0f,
                                position_.z, position_.w, 0.0f, color_.r, color_.g, color_.b, color_.a, 0.0f, 0.0f
                             };

    generated_vertex_buffer_ = v;


    vertex_buffer_.bind();

    vertex_buffer_.size_ = v.size();
    vertex_buffer_.set_data(v);
}
