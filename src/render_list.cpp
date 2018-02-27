#include "render_list.hpp"

#include <stdio.h>

void OGAL::draw_render_list(OGAL::render_list vrender_list, GLuint program_id, glm::mat4 projection)
{
    GLuint MatrixID = glGetUniformLocation(program_id, "projection");
    GLuint use_textureID = glGetUniformLocation(program_id, "use_texture");
    GLuint textureID = glGetUniformLocation(program_id, "uvtexture");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &projection[0][0]);
    glUniform1ui(use_textureID, 1);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    for (unsigned short int i; i < vrender_list.render_vector.size(); i++) {

        glBindBuffer(GL_ARRAY_BUFFER, vrender_list.render_vector.at(i).buffer_id);
        glActiveTexture(0);
        glBindTexture(GL_TEXTURE_2D, vrender_list.render_vector.at(i).texture_id);

        glUniform1i(textureID, 0);

        glVertexAttribPointer(
           0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
           3,                  // size
           GL_FLOAT,           // type
           GL_FALSE,           // normalized?
           9 * sizeof(float),                  // stride
           (void*)0            // array buffer offset
        );
        glVertexAttribPointer(
           1,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
           4,                  // size
           GL_FLOAT,           // type
           GL_FALSE,           // normalized?
           9 * sizeof(float),                  // stride
           (void*)(3 * sizeof(float))            // array buffer offset
        );
        glVertexAttribPointer(
           2,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
           2,                  // size
           GL_FLOAT,           // type
           GL_FALSE,           // normalized?
           9 * sizeof(float),                  // stride
           (void*)(7 * sizeof(float))            // array buffer offset
        );

        glDrawArrays(GL_TRIANGLES, 0, vrender_list.render_vector.at(i).buffer_size); // Starting from vertex 0; 3 vertices total -> 1 triangle
    }
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}

OGAL::render_list::render_list()
{}

OGAL::render_list::~render_list()
{}

unsigned int OGAL::render_list::add_renderable(OGAL::renderable* renderable)
{
    for (unsigned int i = 0; i < renderable->return_buffer_texture_pairs().size(); i++)
        render_vector.push_back({renderable->return_buffer_texture_pairs().at(i).buffer_id, renderable->return_buffer_texture_pairs().at(i).buffer_size, renderable->return_buffer_texture_pairs().at(i).texture_id});
}
