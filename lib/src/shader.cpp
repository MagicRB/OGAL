#include "OGAL/shader.hpp"

#include <stdio.h>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GL/gl.h>

OGAL::Shader::Shader()
{}

OGAL::Shader::~Shader()
{
    glDeleteShader(shader_id_);
}

void OGAL::Shader::load_shader(std::string shader_text, GLenum type)
{
    char const * shader_text_pointer = shader_text.c_str();

    shader_id_ = glCreateShader(type);
    glShaderSource(shader_id_, 1, &shader_text_pointer, NULL);
    glCompileShader(shader_id_);

    glGetShaderiv(shader_id_, GL_COMPILE_STATUS, &result_);
    glGetShaderiv(shader_id_, GL_INFO_LOG_LENGTH, &log_lenght_);
    if (log_lenght_ > 0) {
        std::vector<char> shader_error_message(log_lenght_ + 1);
        glGetShaderInfoLog(shader_id_, log_lenght_, NULL, &shader_error_message[0]);
        fprintf(stderr, "%s\n", &shader_error_message[0]);
    }
}

