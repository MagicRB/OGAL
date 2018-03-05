#include "OGAL/OGAL.hpp"

std::vector<OGAL::event> events;

void OGAL::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    OGAL::event new_event;
    new_event.key_event_.window = window;
    new_event.key_event_.key = key;
    new_event.key_event_.scancode = scancode;
    new_event.key_event_.action = action;
    new_event.key_event_.mods = mods;
    new_event.type = 0;

    events.push_back(new_event);
}

void OGAL::window_size_callback(GLFWwindow* window, int width, int height)
{
    OGAL::event new_event;
    new_event.window_event_.window = window;
    new_event.window_event_.width = width;
    new_event.window_event_.height = height;
    new_event.type = 1;

    events.push_back(new_event);
}

OGAL::event OGAL::poll_events()
{
    glfwPollEvents();
    if (events.size() != 0) {
        OGAL::event tmp = events.at(events.size() - 1);
        events.pop_back();
        return tmp;
    } else
        return OGAL::event();
}

void OGAL::draw(GLFWwindow* window, OGAL::Renderable* renderable, GLuint program_id, glm::mat4 projection, glm::vec2 camera)
{
    std::vector<OGAL::buffer_texture_pair> buff = renderable->return_buffer_texture_pairs();

    GLuint MatrixID = glGetUniformLocation(program_id, "projection");
    GLuint use_textureID = glGetUniformLocation(program_id, "use_texture");
    GLuint textureID = glGetUniformLocation(program_id, "uvtexture");
    GLuint cameraID = glGetUniformLocation(program_id, "camera_pos");

    glUniform2f(cameraID, camera.x, camera.y);
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &projection[0][0]);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    for (OGAL::buffer_texture_pair data : buff) {
        glUniform1ui(use_textureID, data.use_texture);

        glBindBuffer(GL_ARRAY_BUFFER, data.buffer_id);
        glActiveTexture(0);
        glBindTexture(GL_TEXTURE_2D, data.texture_id);

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

        glDrawArrays(data.render_type, 0,  data.buffer_size); // Starting from vertex 0; 3 vertices total -> 1 triangle
    }
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}
