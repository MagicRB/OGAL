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

#define WIDTH 500.0f
#define HEIGHT 600.0f

int main()
{
    GLFWwindow* window;
    
    OGAL::Shader vertex_shader;
    OGAL::Shader fragment_shader;
    OGAL::Program program;
    
    std::string title = "OGAL";
    
    OGAL::VAO vao;
    
    window = OGAL::init_ogal((int) WIDTH, (int) HEIGHT, title.c_str(), &vertex_shader, &program, &fragment_shader, &vao,
                             true,
                             true);
    
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
