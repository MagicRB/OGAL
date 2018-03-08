#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <GL/gl.h>

#include <string>

namespace OGAL {
    class Shader {
    public:
        Shader();
        
        ~Shader();
        
        /// ID of this shader
        GLuint shader_id_;
        
        /// Creates a new shader with code from shader_text, type should be either GL_FRAGMENT_SHADER or GL_VERTEX_SHADER
        void load_shader(std::string shader_text, GLenum type);
    
    protected:
        GLint result_;
        int log_lenght_;
    private:
    
    };
}

#endif //SHADER_HPP
