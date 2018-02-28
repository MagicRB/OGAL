#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "OGAL.hpp"
#include "shapes/equilateral_triangle.hpp"
#include "shapes/square.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>
#include <vector>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

void error_callback(int error, const char *description) {
    printf("%s", description);
}

int main(void) {
    if (!glfwInit()) {
        fprintf(stderr, "An error was encountered when trying to initialise GLFW.");
        exit(EXIT_FAILURE);
    }

    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window =
      glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OGAL", NULL, NULL);

    if (!window) {
        fprintf(stderr, "An error was encountered when trying to open a window.");
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, OGAL::key_callback);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "An error was encountered when trying to initialise GLEW.");
        exit(EXIT_FAILURE);
    }

    OGAL::Shader vertex_shader;
    OGAL::Shader fragment_shader;

    vertex_shader.load_shader(" #version 330 core\n\
                                layout(location = 0) in vec3 vertex_pos;\n\
                                layout(location = 1) in vec4 color;\n\
                                layout(location = 2) in vec2 uv;\n\
                                \n\
                                out vec4 colorV;\n\
                                out vec2 UV;\n\
                                \n\
                                uniform mat4 projection;\n\
                                uniform vec2 camera_pos;\n\
                                \n\
                                void main() {\n\
                                    UV = uv;\n\
                                    colorV = color;\n\
                                    gl_Position = projection * vec4(vertex_pos.x + camera_pos.x, vertex_pos.y + camera_pos.y, vertex_pos.z, 1);\n\
                                }\
                                ",
                            GL_VERTEX_SHADER);

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
                                ",
                              GL_FRAGMENT_SHADER);

    OGAL::Program main_program;

    main_program.load_program(vertex_shader.shader_id_, fragment_shader.shader_id_);

    glUseProgram(main_program.program_id_);

    OGAL::VAO vao;

    vao.bind();

    OGAL::Square square;
    OGAL::Square square2;

    square.set_color(glm::vec4(255.0f, 125.0f, 0.0f, 0.0f));
    square2.set_color(glm::vec4(0.0f, 125.0f, 255.0f, 0.0f));

    int width, height, bpp;
    unsigned char *rgb = stbi_load("image.png", &width, &height, &bpp, 4);

    square.texture_.set_data(rgb, width, height);
    square.set_dimensions(0, 20);

    square.enable_texture(true);
    square2.enable_texture(true);

    stbi_image_free(rgb);

    rgb = stbi_load("image2.png", &width, &height, &bpp, 4);
    square2.texture_.set_data(rgb, width, height);
    square2.set_position(0, 20);
    square2.set_dimensions(0, 20);

    //    OGAL::equilateral_triangle eq;
    //    eq.position.y = 50;
    //    eq.set_dimensions(1, 100);

    OGAL::render_list render_list;
    render_list.add_renderable(&square);
    render_list.add_renderable(&square2);
    // render_list.add_renderable(&eq);

    printf("%s\n", glGetString(GL_VERSION));

    glm::mat4 projection = glm::ortho(-50.0f, 50.0f, -50.0f, 50.0f);

    glm::vec2 camera_pos = glm::vec2(40, 0);

    while (!glfwWindowShouldClose(window)) {
    OGAL::event event = OGAL::poll_events();
    if (event.key_event_.key == GLFW_KEY_Q && event.key_event_.action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        OGAL::draw_render_list(render_list, main_program.program_id_, projection, camera_pos);

        glfwSwapBuffers(window);
    }

    exit(EXIT_SUCCESS);
}
