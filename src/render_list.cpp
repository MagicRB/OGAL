#include "render_list.hpp"

#include <stdio.h>

void OGAL::draw_render_list(OGAL::render_list vrender_list, GLuint program_id, glm::mat4 projection)
{
    GLuint MatrixID = glGetUniformLocation(program_id, "projection");


    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &projection[0][0]);

    glEnableVertexAttribArray(0);
    for (unsigned short int i; i < vrender_list.render_vector.size(); i++) {

        glBindBuffer(GL_ARRAY_BUFFER, vrender_list.render_vector.at(i).buffer_id);
        glVertexAttribPointer(
           0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
           3,                  // size
           GL_FLOAT,           // type
           GL_FALSE,           // normalized?
           0,                  // stride
           (void*)0            // array buffer offset
        );
        glDrawArrays(GL_TRIANGLES, 0, vrender_list.render_vector.at(i).buffer_size); // Starting from vertex 0; 3 vertices total -> 1 triangle
    }
    glDisableVertexAttribArray(0);
}

OGAL::render_list::render_list()
{}

OGAL::render_list::~render_list()
{}

unsigned int OGAL::render_list::add_renderable(OGAL::renderable* renderable)
{
    for (unsigned int i = 0; i < renderable->return_vertex_buffer_ids().size(); i++)
        render_vector.push_back({renderable->return_vertex_buffer_ids().at(i), renderable->return_vertex_buffer_sizes().at(i), 0});
}
