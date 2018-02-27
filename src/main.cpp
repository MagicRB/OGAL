#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "event.hpp"
#include "shader.hpp"
#include "program.hpp"
#include "vao.hpp"
#include "vbo.hpp"
#include "render_list.hpp"
#include "shapes/square.hpp"
#include "shapes/equilateral_triangle.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <vector>
#include <stdio.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

std::vector<OGAL::event> events;

namespace OGAL {
    OGAL::event poll_events()
    {
        glfwPollEvents();
        if (events.size() != 0) {
            event tmp = events.at(events.size() - 1);
            events.pop_back();
            return tmp;
        } else
            return event();
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    OGAL::event new_event;
    new_event.key_event.window = window;
    new_event.key_event.key = key;
    new_event.key_event.scancode = scancode;
    new_event.key_event.action = action;
    new_event.key_event.mods = mods;

    events.push_back(new_event);
}

void error_callback(int error, const char* description)
{
    printf("%s", description);
}

int main(void)
{
    if (!glfwInit()) {
        fprintf(stderr, "An error was encountered when trying to initialise GLFW.");
        exit(EXIT_FAILURE);
    }

    glfwSetErrorCallback(error_callback);


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OGAL", NULL, NULL);

    if (!window) {
        fprintf(stderr, "An error was encountered when trying to open a window.");
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "An error was encountered when trying to initialise GLEW.");
        exit(EXIT_FAILURE);
    }

    OGAL::shader vertex_shader;
    OGAL::shader fragment_shader;

    vertex_shader.load_shader(" #version 330 core\n\
                                layout(location = 0) in vec3 vertex_pos;\n\
                                layout(location = 1) in vec4 color;\n\
                                layout(location = 2) in vec2 uv;\n\
                                \n\
                                out vec4 colorV;\n\
                                out vec2 UV;\n\
                                \n\
                                uniform mat4 projection;\n\
                                \n\
                                void main() {\n\
                                    UV = uv;\n\
                                    colorV = color;\n\
                                    gl_Position = projection * vec4(vertex_pos, 1);\n\
                                }\
                                ", GL_VERTEX_SHADER);

    fragment_shader.load_shader("#version 330 core\n\
                                \n\
                                uniform sampler2D uvtexture;\n\
                                uniform bool use_texture;\n\
                                \n\
                                in vec4 colorV;\n\
                                in vec2 UV;\n\
                                \n\
                                out vec4 colorF;\n\
                                \n\
                                void main(){\n\
                                    if (use_texture == true) {\n\
                                        colorF = texture(uvtexture, UV);\n\
                                    } else {\n\
                                        colorF = colorV;\n\
                                    }\n\
                                }\
                                ", GL_FRAGMENT_SHADER);

    OGAL::program main_program;

    main_program.load_program(vertex_shader.shader_id, fragment_shader.shader_id);

    glUseProgram(main_program.program_id);

    OGAL::vao vao;

    vao.bind();

    OGAL::square square;
    OGAL::square square2;

    int width, height, bpp;
    unsigned char* rgb = stbi_load( "image.png", &width, &height, &bpp, 4 );

    square.texture.set_data(rgb, width, height);
    square.set_dimensions(0, 20);

    stbi_image_free( rgb );

    rgb = stbi_load( "image2.png", &width, &height, &bpp, 4 );
    square2.texture.set_data(rgb, width, height);
    square2.position.y = 20;
    square2.set_dimensions(0, 20);

//    OGAL::equilateral_triangle eq;
//    eq.position.y = 50;
//    eq.set_dimensions(1, 100);

    OGAL::render_list render_list;
    render_list.add_renderable(&square);
    render_list.add_renderable(&square2);
    //render_list.add_renderable(&eq);

    printf("%s\n", glGetString(GL_VERSION));

    //glm::mat4 projection = glm::ortho(-(float)(WINDOW_WIDTH/2), (float)(WINDOW_WIDTH/2), -(float)(WINDOW_HEIGHT/2), (float)(WINDOW_HEIGHT/2));
    glm::mat4 projection = glm::ortho(-50.0f, 50.0f, -50.0f, 50.0f);

    while (!glfwWindowShouldClose(window)) {
        OGAL::event event = OGAL::poll_events();
        if (event.key_event.key == GLFW_KEY_Q && event.key_event.action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        OGAL::draw_render_list(render_list, main_program.program_id, projection);

        glfwSwapBuffers(window);

    }

    exit(EXIT_SUCCESS);
}
