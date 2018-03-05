#include "OGAL/texture.hpp"

OGAL::Texture::Texture()
{
    glGenTextures(1, &texture_id_);
}

OGAL::Texture::~Texture()
{}

void OGAL::Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, texture_id_);
}

void OGAL::Texture::set_data(unsigned char* data, GLuint width, GLuint height)
{
    bind();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
