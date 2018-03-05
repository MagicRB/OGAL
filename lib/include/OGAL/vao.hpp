#ifndef VAO_HPP
#define VAO_HPP

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class VAO {
        public:
            VAO();
            ~VAO();

            /// Binds this VAO as the the current one
            void bind();

            /// ID of this VAO
            GLuint vao_id_;
        protected:

        private:
    };
}

#endif //VAO_HPP
