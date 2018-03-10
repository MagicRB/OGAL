//
// Created by Magic_RB on 3/8/2018.
//

#include "OGAL/texture_3d.hpp"

OGAL::Texture3D::Texture3D() = default;

OGAL::Texture3D::~Texture3D() = default;

void OGAL::Texture3D::bind()
{
    glBindTexture(GL_TEXTURE_3D, texture_id_);
}

void OGAL::Texture3D::add_data(unsigned char* data, int width, int height, int layers, int layer)
{
    bind();
    
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, layer, width, height, layers, GL_RGBA, GL_UNSIGNED_BYTE, data);
    
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
