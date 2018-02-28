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

            GLuint shader_id_;
            void load_shader(std::string shader_text, GLenum type);
        protected:
            GLint result_;
            int log_lenght_;
        private:

    };
}

#endif //SHADER_HPP
