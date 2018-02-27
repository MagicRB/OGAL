#include "texture.hpp"

OGAL::texture::texture()
{
    glGenTextures(1, &texture_id);
}

OGAL::texture::~texture()
{}

void OGAL::texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, texture_id);
}

void OGAL::texture::set_data(unsigned char* data, GLuint width, GLuint height)
{
    bind();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
