#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class program {
        public:
            program();
            ~program();

            GLuint program_id;
            void load_program(GLuint vertex_shader, GLuint fragment_shader);
        protected:
            GLint result;
            int log_lenght;
        private:

    };
}
#endif //PROGRAM_HPP
