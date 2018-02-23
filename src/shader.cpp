#include "shader.hpp"

#include <stdio.h>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GL/gl.h>

OGAL::shader::shader()
{}

OGAL::shader::~shader()
{
    glDeleteShader(shader_id);
}

void OGAL::shader::load_shader(std::string shader_text, GLenum type)
{
    char const * shader_text_pointer = shader_text.c_str();

    shader_id = glCreateShader(type);
    glShaderSource(shader_id, 1, &shader_text_pointer, NULL);
    glCompileShader(shader_id);

    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &log_lenght);
    if (log_lenght > 0) {
        std::vector<char> shader_error_message(log_lenght + 1);
        glGetShaderInfoLog(shader_id, log_lenght, NULL, &shader_error_message[0]);
        fprintf(stderr, "%s\n", &shader_error_message[0]);
    }
}

