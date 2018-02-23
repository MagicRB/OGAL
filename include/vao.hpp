#ifndef VAO_HPP
#define VAO_HPP

#include <GL/glew.h>
#include <GL/gl.h>

namespace OGAL {
    class vao {
        public:
            vao();
            ~vao();

            void bind();

            GLuint vao_id;
        protected:

        private:
    };
}

#endif //VAO_HPP
