#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <GL/gl.h>

#include <string>

namespace OGAL {
    class shader {
        public:
            shader();
            ~shader();

            GLuint shader_id;
            void load_shader(std::string shader_text, GLenum type);
        protected:
            GLint result;
            int log_lenght;
        private:

    };
}

#endif //SHADER_HPP
