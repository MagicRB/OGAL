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

// @TODO This should purely theoretically work, but to actually draw using this special texture type, OGAL::draw needs to be altered to take into account if the shape uses a 2D or 3D texture and pass that to the vertex shader along with the layer, from where it needs to be passed down to the fragment shader, the layer should probably be a uniform because i don't think it will need to change in one mesh render.
void OGAL::Texture3D::set_data(unsigned char* data, int width, int height, int layer)
{
    bind();
    
    glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, width, height, layer, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}