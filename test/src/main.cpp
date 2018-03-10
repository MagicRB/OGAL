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

#define WIDTH 250.0f
#define HEIGHT 500.0f

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
    
    float scale = 11.0f;
    
    glm::vec2 projection{scale, (HEIGHT - WIDTH) / (WIDTH / scale) + scale};
    
    glm::vec2 camera_pos{0, 0};
    
    OGAL::Square sq;
    sq.load_texture3d_from_file("youtube.png", 2);
    sq.set_dimensions(0, 20);
    sq.set_position(0, 0);
    sq.set_color(255, 0, 0, 0);
    sq.enable_texture3d(true);
    
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
    
                projection = {scale, (height - width) / (width / scale) + scale};
            } else if (event.key_event_.key == GLFW_KEY_T && event.key_event_.action == GLFW_PRESS) {
                scale -= 1;
                
                int width, height;
                glfwGetWindowSize(window, &width, &height);
    
                projection = {scale, (height - width) / (width / scale) + scale};
            }
        } else if (event.type == 1) {
            glViewport(0, 0, event.window_event_.width, event.window_event_.height);
    
            projection = {scale, (event.window_event_.height - event.window_event_.width) /
                                 (event.window_event_.width / scale) + scale};
    
        } else if (event.type == 2) {
    
            double cursor_x, cursor_y;
    
            glfwGetCursorPos(window, &cursor_x, &cursor_y);
    
            glm::vec2 world_position = OGAL::screen_to_world_space(window, scale, camera_pos,
                                                                   glm::vec2 {cursor_x, cursor_y});
    
            if (event.mouse_button_event_.button == GLFW_MOUSE_BUTTON_LEFT &&
                event.mouse_button_event_.action == GLFW_PRESS) {
        
            }
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
    
        OGAL::draw(window, &sq, program.program_id_, projection, camera_pos);
        
        glfwSwapBuffers(window);
    }
    
    exit(EXIT_SUCCESS);
}
