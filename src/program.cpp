#include "program.hpp"

#include <vector>
#include <stdio.h>

OGAL::program::program()
{}

OGAL::program::~program()
{
    glDeleteProgram(program_id);
}

void OGAL::program::load_program(GLuint vertex_shader, GLuint fragment_shader)
{
    program_id = glCreateProgram();
	glAttachShader(program_id, vertex_shader);
	glAttachShader(program_id, fragment_shader);
	glLinkProgram(program_id);

	glGetProgramiv(program_id, GL_LINK_STATUS, &result);
	glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &log_lenght);
	if (log_lenght > 0) {
        std::vector<char> program_error_message(log_lenght + 1);
        glGetProgramInfoLog(program_id, log_lenght, NULL, &program_error_message[0]);
        printf("%s\n", &program_error_message[0]);
	}

    glDetachShader(program_id, vertex_shader);
	glDetachShader(program_id, fragment_shader);
}
