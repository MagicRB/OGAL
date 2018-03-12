#include "OGAL/OGAL.hpp"

std::vector<OGAL::event> events;

void OGAL::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    OGAL::event new_event{};
    new_event.key_event_.window = window;
    new_event.key_event_.key = key;
    new_event.key_event_.scancode = scancode;
    new_event.key_event_.action = action;
    new_event.key_event_.mods = mods;
    new_event.type = 0;
    
    events.push_back(new_event);
}

void OGAL::window_size_callback(GLFWwindow* window, int width, int height)
{
    OGAL::event new_event{};
    new_event.window_event_.window = window;
    new_event.window_event_.width = width;
    new_event.window_event_.height = height;
    new_event.type = 1;
    
    events.push_back(new_event);
}

void OGAL::error_callback(int error, const char* description)
{
    std::cout << "An GLFW error was encountered: [" << description << "]\n";
}

void OGAL::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    OGAL::event new_event{};
    new_event.mouse_button_event_.window = window;
    new_event.mouse_button_event_.button = button;
    new_event.mouse_button_event_.action = action;
    new_event.mouse_button_event_.mods = mods;
    new_event.type = 2;
    
    events.push_back(new_event);
}

OGAL::event OGAL::poll_events()
{
    glfwPollEvents();
    if (!events.empty()) {
        OGAL::event tmp = events.at(events.size() - 1);
        events.pop_back();
        return tmp;
    } else
        return OGAL::event{};
}

void
OGAL::draw(GLFWwindow* window, OGAL::Renderable* renderable, GLuint program_id, glm::vec2 projection, glm::vec2 camera)
{
    std::vector<OGAL::buffer_texture_pair> buff = renderable->return_buffer_texture_pairs();
    
    GLint MatrixID = glGetUniformLocation(program_id, "projection");
    GLint use_textureID = glGetUniformLocation(program_id, "use_texture");
    GLint textureID = glGetUniformLocation(program_id, "uvtexture");
    GLint cameraID = glGetUniformLocation(program_id, "camera_pos");
    
    glUniform2f(cameraID, camera.x, camera.y);
    glUniform2f(MatrixID, projection.x, projection.y);
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    
    for (OGAL::buffer_texture_pair data : buff) {
        glUniform1ui(use_textureID, data.use_texture);
        
        glBindBuffer(GL_ARRAY_BUFFER, data.buffer_id);
        glActiveTexture(GL_TEXTURE0);
    
        glUniform1i(textureID, 0);
        glBindTexture(GL_TEXTURE_2D, data.texture_id);
        
        glVertexAttribPointer(
                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                9 * sizeof(float),                  // stride
                nullptr             // array buffer offset
        );
        glVertexAttribPointer(
                1,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
                4,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                9 * sizeof(float),                  // stride
                (void*) (3 * sizeof(float))            // array buffer offset
        );
        glVertexAttribPointer(
                2,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
                2,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                9 * sizeof(float),                  // stride
                (void*) (7 * sizeof(float))            // array buffer offset
        );
        
        glDrawArrays(data.render_type, 0, data.buffer_size); // Starting from vertex 0; 3 vertices total -> 1 triangle
    }
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}

GLFWwindow* OGAL::init_ogal(int width, int height, const char* title, OGAL::Shader* vertex_shader,
                            OGAL::Program* program, OGAL::Shader* fragment_shader, OGAL::VAO* vao, bool setup_callbacks,
                            bool setup_shaders)
{
    GLFWwindow* window;
    if (!glfwInit()) {
        fprintf(stderr, "An error was encountered when trying to initialise GLFW.");
        return nullptr;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    
    if (!window) {
        std::cout << "An error was encountered when trying to open a window.\n";
        return nullptr;
    }
    
    glfwMakeContextCurrent(window);
    
    glfwSwapInterval(1);
    
    if (setup_callbacks) {
        glfwSetFramebufferSizeCallback(window, OGAL::window_size_callback);
        glfwSetKeyCallback(window, OGAL::key_callback);
        glfwSetErrorCallback(OGAL::error_callback);
        glfwSetMouseButtonCallback(window, OGAL::mouse_button_callback);
    }

#ifdef __GLEW_H__
    glewExperimental = GL_TRUE;
    
    if (glewInit() != GLEW_OK) {
        std::cout << "An error was encountered when trying to initialise GLEW.\n";
        exit(EXIT_FAILURE);
    }
#else
#warning "No library used to provide newest OpenGL!"
#endif
    
    if (setup_shaders) {
        
        vertex_shader->load_shader("#version 330 core\n\
                              layout(location = 0) in vec3 vertex_pos;\n\
                              layout(location = 1) in vec4 color;\n\
                              layout(location = 2) in vec2 uv;\n\
                              \n\
                              out vec4 colorV;\n\
                              out vec2 UV;\n\
                              \n\
                              uniform vec2 projection;\n\
                              uniform vec2 camera_pos;\n\
                              \n\
                              void main() {\n\
                                    UV = uv;\n\
                                    colorV = color;\n\
                                    gl_Position.xy = vec2(vertex_pos.x + camera_pos.x, vertex_pos.y + camera_pos.y) / projection;\n\
                              }\
                              ",
                                   GL_VERTEX_SHADER);
        
        fragment_shader->load_shader("#version 330 core\n\
                                \n\
                                uniform sampler2D uvtexture;\n\
                                uniform bool use_texture;\n\
                                uniform bool use_3Dtexture;\n\
                                uniform sampler3D texture3;\n\
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
        
        program->load_program(vertex_shader->shader_id_, fragment_shader->shader_id_);
        
        glUseProgram(program->program_id_);
    }
    
    vao->init();
    vao->bind();
    
    return window;
}

glm::vec2
OGAL::screen_to_world_space(GLFWwindow* window, float scale, glm::vec2 camera_position, glm::vec2 screen_position)
{
    
    int window_width, window_height;
    glfwGetWindowSize(window, &window_width, &window_height);
    
    float scale_y = (window_height - window_width) / (window_width / scale) + scale;
    
    float ratio_x = scale / (window_width / 2);
    float ratio_y = scale_y / (window_height / 2);
    
    float pos_x = ratio_x * (screen_position.x - (window_width / 2)) - camera_position.x;
    float pos_y = ratio_y * (screen_position.y - (window_height / 2)) + camera_position.y;
    
    return glm::vec2 {pos_x, pos_y};
}
