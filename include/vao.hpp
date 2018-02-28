#ifndef VAO_HPP
#define VAO_HPP

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class VAO {
        public:
            VAO();
            ~VAO();

            void bind();

            GLuint vao_id_;
        protected:

        private:
    };
}

#endif //VAO_HPP
