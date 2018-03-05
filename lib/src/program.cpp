#include "OGAL/program.hpp"

#include <vector>
#include <stdio.h>

OGAL::Program::Program()
{}

OGAL::Program::~Program()
{
    glDeleteProgram(program_id_);
}

void OGAL::Program::load_program(GLuint vertex_shader, GLuint fragment_shader)
{
    program_id_ = glCreateProgram();
	glAttachShader(program_id_, vertex_shader);
	glAttachShader(program_id_, fragment_shader);
	glLinkProgram(program_id_);

	glGetProgramiv(program_id_, GL_LINK_STATUS, &result_);
	glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &log_lenght_);
	if (log_lenght_ > 0) {
        std::vector<char> program_error_message(log_lenght_ + 1);
        glGetProgramInfoLog(program_id_, log_lenght_, NULL, &program_error_message[0]);
        printf("%s\n", &program_error_message[0]);
	}

    glDetachShader(program_id_, vertex_shader);
	glDetachShader(program_id_, fragment_shader);
}
