#include <GL/glew.h>
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

#include <iostream>

#define WINDOW_WIDTH 500.0f
#define WINDOW_HEIGHT 600.0f

void error_callback(int error, const char *description)
{
    printf("%s", description);
}

int main()
{
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
    
    vertex_shader.load_shader("#version 330 core\n\
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
                                uniform sampler3D uvtexture3d;\n\
                                uniform bool use_3d;\
                                uniform bool use_texture;\n\
                                \n\
                                in vec4 colorV;\n\
                                in vec2 UV;\n\
                                \n\
                                out vec4 colorF;\n\
                                \n\
                                void main() {\n\
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
    
    printf("%s\n", glGetString(GL_VERSION));
    
    glm::mat4 projection = glm::ortho(-50.0f, 50.0f, -60.0f, 60.0f);
    
    glm::vec2 camera_pos = glm::vec2(0, 0);
    
    float scale = 50.0f;
    
    while (!glfwWindowShouldClose(window)) {
        OGAL::event event = OGAL::poll_events();
        if (event.type == 0) {
            if (event.key_event_.key == GLFW_KEY_Q && event.key_event_.action == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            } else if (event.key_event_.key == GLFW_KEY_Y && event.key_event_.action == GLFW_PRESS) {
            
            } else if (event.key_event_.key == GLFW_KEY_R && event.key_event_.action == GLFW_PRESS) {
                scale += 1;
                
                int width, height;
                glfwGetWindowSize(window, &width, &height);
                
                float aspect = scale * (float) height / (float) width;
                
                projection = glm::ortho(-scale, scale, -aspect, aspect);
                
            } else if (event.key_event_.key == GLFW_KEY_T && event.key_event_.action == GLFW_PRESS) {
                scale -= 1;
                
                int width, height;
                glfwGetWindowSize(window, &width, &height);
                
                float aspect = scale * (float) height / (float) width;
                
                projection = glm::ortho(-scale, scale, -aspect, aspect);
            }
        } else if (event.type == 1) {
            glViewport(0, 0, event.window_event_.width, event.window_event_.height);
            
            float aspect = scale * (float) event.window_event_.height / (float) event.window_event_.width;
            
            std::cout << scale << "\n";
            
            projection = glm::ortho(-scale, scale, -aspect, aspect);
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            camera_pos.x += 1;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            camera_pos.x -= 1;
        }
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            camera_pos.y -= 1;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            camera_pos.y += 1;
        }
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glfwSwapBuffers(window);
    }
    
    exit(EXIT_SUCCESS);
}
