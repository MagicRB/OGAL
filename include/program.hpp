#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class Program {
        public:
            Program();
            ~Program();

            GLuint program_id_;
            void load_program(GLuint vertex_shader, GLuint fragment_shader);
        protected:
            GLint result_;
            int log_lenght_;
        private:

    };
}
#endif //PROGRAM_HPP
