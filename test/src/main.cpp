#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "OGAL/OGAL.hpp"
#include "OGAL/shapes/equilateral_triangle.hpp"
#include "OGAL/shapes/square.hpp"
#include "OGAL/shapes/line.hpp"
#include "OGAL/shapes/curve.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "OGAL/stb_image.h"

#include <stdio.h>
#include <vector>
#include <iostream>

#define WINDOW_WIDTH 500.0f
#define WINDOW_HEIGHT 600.0f

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

    glfwSwapInterval(1);

    glfwSetFramebufferSizeCallback(window, OGAL::window_size_callback);

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
    OGAL::EquilateralTriangle eq;
    OGAL::Line line;
    OGAL::Curve curve;

    std::vector<glm::vec<2, float, (glm::qualifier)0>> curve_vector = {   glm::vec2(0.0f, 0.0f), glm::vec2(20.0f, 0.0f), glm::vec2(20.0f, 20.0f), glm::vec2(40.0f, 40.0f)
                                                                        };

    curve.set_positions(curve_vector);
    curve.set_color(255.0f, 0.0f, 0.0f, 0.0f);

    line.set_color(255.0f, 0.0f, 0.0f, 0.0f);
    line.set_positions(50.0f, 0.0f, 0.0f, 50.0f);

    square.set_color(glm::vec4(255.0f, 125.0f, 0.0f, 0.0f));
    square2.set_color(glm::vec4(0.0f, 125.0f, 255.0f, 0.0f));

    square2.set_position(45, square2.get_position().y);

    int width, height, bpp;
    unsigned char *rgb = stbi_load("image.png", &width, &height, &bpp, 4);

    square.texture_.set_data(rgb, width, height);
    square.set_dimensions(0, 20);

    square.enable_texture(true);
    square2.enable_texture(false);

    stbi_image_free(rgb);

    rgb = stbi_load("image2.png", &width, &height, &bpp, 4);
    square2.texture_.set_data(rgb, width, height);
    square2.set_position(0, 20);
    square2.set_dimensions(0, 20);

    eq.set_position(50, 50);
    eq.set_color(255.0f, 0.0f, 0.0f, 0.0f);
    eq.set_dimensions(0, 100);

    printf("%s\n", glGetString(GL_VERSION));

    glm::mat4 projection = glm::ortho(-50.0f, 50.0f, -60.0f, 60.0f);

    glm::vec2 camera_pos = glm::vec2(0, 0);

    float scale = 50.0f;

    GLuint texture_enabled;

    while (!glfwWindowShouldClose(window)) {
        OGAL::event event = OGAL::poll_events();
        if (event.type == 0) {
            if (event.key_event_.key == GLFW_KEY_Q && event.key_event_.action == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            } else if (event.key_event_.key == GLFW_KEY_Y && event.key_event_.action == GLFW_PRESS) {
                square.enable_texture(!texture_enabled);
                texture_enabled = !texture_enabled;
            } else if (event.key_event_.key == GLFW_KEY_R && event.key_event_.action == GLFW_PRESS) {
                scale += 1;

                int width, height;
                glfwGetWindowSize(window, &width, &height);

                float aspect = scale * (float)height/(float)width;

                projection = glm::ortho(-scale, scale, -aspect, aspect);

            } else if (event.key_event_.key == GLFW_KEY_T && event.key_event_.action == GLFW_PRESS) {
                scale -= 1;

                int width, height;
                glfwGetWindowSize(window, &width, &height);

                float aspect = scale * (float)height/(float)width;

                projection = glm::ortho(-scale, scale, -aspect, aspect);
            }
        } else if (event.type == 1) {
            glViewport(0,0, event.window_event_.width, event.window_event_.height);

            float aspect = scale * (float)event.window_event_.height/(float)event.window_event_.width;

            std::cout << scale << "\n";

            projection = glm::ortho(-scale, scale, -aspect, aspect);
        } if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            camera_pos.x += 1;
        } if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            camera_pos.x -= 1;
        } if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            camera_pos.y -= 1;
        } if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            camera_pos.y += 1;
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //OGAL::draw(window, &square, main_program.program_id_, projection, camera_pos);
        //OGAL::draw(window, &square2, main_program.program_id_, projection, camera_pos);
        //OGAL::draw(window, &eq, main_program.program_id_, projection, camera_pos);
        //OGAL::draw(window, &line, main_program.program_id_, projection, camera_pos);
        OGAL::draw(window, &curve, main_program.program_id_, projection, camera_pos);

        glfwSwapBuffers(window);
    }

    exit(EXIT_SUCCESS);
}
